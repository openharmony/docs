# Subscribing to Resource Leak Events (C/C++)

## Available APIs

For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [HiAppEvent](../reference/apis-performance-analysis-kit/_hi_app_event.md#hiappevent).

**Subscription APIs**

| API                                                        | Description                                        |
|-------------------------------------------------------------| -------------------------------------------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher *watcher)   | Adds a watcher to listen for application events.|
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher *watcher) | Removes a watcher to unsubscribe from the application events.|

## How to Develop

1. Create a native C++ project and import the **jsoncpp** file to the project. The directory structure is as follows:

   ```yml
   entry:
     src:
       main:
         cpp:
           - json:
               - json.h
               - json-forwards.h
           - types:
               libentry:
                 - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
           - jsoncpp.cpp
         ets:
           - entryability:
               - EntryAbility.ets
           - pages:
               - Index.ets
   ```

2. In the **CMakeLists.txt** file, add the source file and dynamic libraries.

   ```cmake
   # Add the jsoncpp.cpp file, which is used to parse the JSON strings in the subscription events.
   add_library(entry SHARED napi_init.cpp jsoncpp.cpp)
   # Add libhiappevent_ndk.z.so and libhilog_ndk.z.so (log output). 
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libhiappevent_ndk.z.so)
   ```

3. Import the dependency files to the **napi_init.cpp** file, and define **LOG_TAG**.

   ```c++
   #include "napi/native_api.h"
   #include "json/json.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

4. Subscribe to system events.

    - Watcher of the onReceive type:

      In the **napi_init.cpp** file, define the methods related to the watcher of the onReceive type.

      ```c++
      // Define a variable to cache the pointer to the created watcher.
      static HiAppEvent_Watcher *systemEventWatcher; 
      
      static void OnReceive(const char *domain, const struct HiAppEvent_AppEventGroup *appEventGroups, uint32_t groupLen) {
          for (int i = 0; i < groupLen; ++i) {
              for (int j = 0; j < appEventGroups[i].infoLen; ++j) {
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", appEventGroups[i].appEventInfos[j].domain);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", appEventGroups[i].appEventInfos[j].name);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", appEventGroups[i].appEventInfos[j].type);
                  if (strcmp(appEventGroups[i].appEventInfos[j].domain, DOMAIN_OS) == 0 && 
                      strcmp(appEventGroups[i].appEventInfos[j].name, EVENT_RESOURCE_OVERLIMIT) == 0) {
                      Json::Value params;
                      Json::Reader reader(Json::Features::strictMode());
                      Json::FastWriter writer;
                      if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                          auto time = params["time"].asInt64();
                          auto pid = params["pid"].asInt();
                          auto uid = params["uid"].asInt();
                          auto resourceType = params["resourceType"].asString();
                          auto bundleName = params["bundle_name"].asString();
                          auto bundleVersion = params["bundle_version"].asString();
                          auto memory = writer.write(params["memory"]);
                          auto externalLog = writer.write(params["external_log"]);
                          std::string logOverLimit = params["log_over_limit"].asBool() ? "true":"false";
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.resource_type=%{public}s", resourceType.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d", logOverLimit.c_str());
                      }
                  }
              }
          }
      }
      
      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          // Set the watcher name. The system identifies different watchers based on their names.
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
          // Set the event to watch to EVENT_RESOURCE_OVERLIMIT.
          const char *names[] = {EVENT_RESOURCE_OVERLIMIT};
          // Add the events to watch, for example, system events.
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // Set the implemented callback. After receiving the event, the watcher immediately triggers the OnReceive callback.
          OH_HiAppEvent_SetWatcherOnReceive(systemEventWatcher, OnReceive);
          // Add a watcher to listen for the specified event.
          OH_HiAppEvent_AddWatcher(systemEventWatcher);
          return {};
      }
      ```
      
    - Watcher of the onTrigger type:
    
      In the **napi_init.cpp** file, define the methods related to the watcher of the OnTrigger type.
    
      ```c++
      // Define a variable to cache the pointer to the created watcher.
      static HiAppEvent_Watcher *systemEventWatcher; 
      
      // Implement the callback function used to return the listened events. The content pointed to by the events pointer is valid only in this function.
      static void OnTake(const char *const *events, uint32_t eventLen) {
          Json::Reader reader(Json::Features::strictMode());
          Json::FastWriter writer;
          for (int i = 0; i < eventLen; ++i) {
              Json::Value eventInfo;
              if (reader.parse(events[i], eventInfo)) {
                  auto domain =  eventInfo["domain_"].asString();
                  auto name = eventInfo["name_"].asString();
                  auto type = eventInfo["type_"].asInt();
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", domain.c_str());
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", name.c_str());
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", type);
                  if (domain ==  DOMAIN_OS && name == EVENT_RESOURCE_OVERLIMIT) {
                      auto time = eventInfo["time"].asInt64();
                      auto pid = eventInfo["pid"].asInt();
                      auto uid = eventInfo["uid"].asInt();
                      auto resourceType = eventInfo["resourceType"].asString();
                      auto bundleName = eventInfo["bundle_name"].asString();
                      auto bundleVersion = eventInfo["bundle_version"].asString();
                      auto memory = writer.write(eventInfo["memory"]);
                      auto externalLog = writer.write(eventInfo["external_log"]);
                      std::string logOverLimit = eventInfo["log_over_limit"].asBool() ? "true":"false";
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.resource_type=%{public}s", resourceType.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d", logOverLimit.c_str());
                  }
              }
          }
      }
      
      // Implement the subscription callback function to apply custom processing to the obtained event logging data.
      static void OnTrigger(int row, int size) {
          // After the callback is received, obtain the specified number of received events.
          OH_HiAppEvent_TakeWatcherData(systemEventWatcher, row, OnTake);
      }
      
      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          // Set the watcher name. The system identifies different watchers based on their names.
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onTriggerWatcher");
          // Set the event to watch to EVENT_RESOURCE_OVERLIMIT.
          const char *names[] = {EVENT_RESOURCE_OVERLIMIT};
          // Add the events to watch, for example, system events.
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // Set the implemented callback function. The callback function will be triggered when the conditions set by OH_HiAppEvent_SetTriggerCondition are met.
          OH_HiAppEvent_SetWatcherOnTrigger(systemEventWatcher, OnTrigger);
          // Set the conditions for triggering the subscription callback. For example, trigger this onTrigger callback when the number of new event logs is 2.
          OH_HiAppEvent_SetTriggerCondition(systemEventWatcher, 1, 0, 0);
          // Add a watcher to listen for the specified event.
          OH_HiAppEvent_AddWatcher(systemEventWatcher);
          return {};
      }
      ```
    
5. Register **RegisterWatcher** as an ArkTS API.

   In the **napi_init.cpp** file, register **RegisterWatcher** as an ArkTS API.

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "registerWatcher", nullptr, RegisterWatcher, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

   In the **index.d.ts** file, define the ArkTS API.

   ```typescript
   export const registerWatcher: () => void;
   ```

6. In the **EntryAbility.ets** file, add the following interface invocation to **onCreate()**.

   ```typescript
   import testNapi from 'libentry.so'
   import hidebug from '@kit.PerformanceAnalysisKit'
   export default class EntryAbility extends UIAbility {
     onCreate(want, launchParam) {
       // Register the system event watcher at startup.
       testNapi.registerWatcher();
     }
   }
   ```

7. In the **entry/src/main/ets/pages/index.ets** file, add the **memoryleak** button and construct a scenario for triggering a resource leak event in **onClick()**.
   You can use [hidebug.setAppResourceLimit](../reference/apis-performance-analysis-kit/js-apis-hidebug.md#hidebugsetappresourcelimit12) to set the application's memory limit to construct a memory leak event and trigger a resource leak event report. You are advised not to use this API in the production environment.
To obtain profiler logs, enable **System resource leak log** in **Developer options**. (You need to restart the device to enable or disable this functionality.)

   <!--RP1-->
   For details about how to locate resource leak errors, see [Memory Leak Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-insight-session-snapshot).
   <!--RP1End-->

   The sample code is as follows:

   ```ts
    import hidebug from "@ohos.hidebug";

    @Entry
    @Component
    struct Index {
      @State leakedArray: string[][] = [];

      build() {
        Column() {
          Row() {
            Column() {
              Button("pss leak")
                .onClick(() => {
                  hidebug.setAppResourceLimit("pss_memory", 1024, true);
                  for (let i = 0; i < 20 * 1024; i++) {
                    this.leakedArray.push(new Array(1).fill("leak"));
                  }
                })
            }
          }
          .height('100%')
          .width('100%')
        }
      }
    }
   ```

8. Click the **Run** button in DevEco Studio to run the project, click the **pss leak** button, and then a memory leak event will be reported after 15 to 30 minutes.
   For the same application, the memory leak event can be reported at most once within 24 hours. If the memory leak needs to be reported again within a shorter time, restart the device.

9. After the memory leak event is reported, you can view the following event information in the **Log** window.

   ```text
   08-07 03:53:35.314 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.domain=OS
   08-07 03:53:35.314 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.name=RESOURCE_OVERLIMIT
   08-07 03:53:35.314 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.eventType=1
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.time=1502049167732
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.pid=1587
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.uid=20010043
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.resource_type=pss_memory
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.bundle_version=1.0.0
   08-07 03:53:35.350 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.memory={"pss":2100257,"rss":1352644,"sys_avail_mem":250272,"sys_free_mem":60004,"sys_total_mem":1992340,"vss":2462936}
   08-07 03:53:35.350 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572401_6808.log","/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572412_6808.log"]
   08-07 03:53:35.350 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.log_over_limit=false
   ```

10. Remove the event watcher.

    ```c++
    static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
        // Remove the watcher.
        OH_HiAppEvent_RemoveWatcher(systemEventWatcher);
        return {};
    }
    ```

11. Destroy the event watcher.

    ```c++
    static napi_value DestroyWatcher(napi_env env, napi_callback_info info) {
        // Destroy the created watcher and set systemEventWatcher to nullptr.
        OH_HiAppEvent_DestroyWatcher(systemEventWatcher);
        systemEventWatcher = nullptr;
        return {};
    }
    ```
