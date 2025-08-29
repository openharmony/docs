# Subscribing to Address Sanitizer Events (C/C++)
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @mlkgeek-->
<!--Designer: @StevenLai1994-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## **Available APIs**

For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [hiappevent.h](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md).

**Subscription APIs**

| **API**| **Description**|
| -------- | -------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher \*watcher) | Adds a watcher to listen for application events.|
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher \*watcher) | Removes a watcher for the specified application events.|

## **How to Develop**

The following describes how to subscribe an address sanitizer event for an array bounds write.

### Step 1: Creating a Project

1. Obtain the **jsoncpp.cpp**, **json.h**, and **json-forwards.h** files by referring to **Using JsonCpp in your project** in [JsonCpp]((https://github.com/open-source-parsers/jsoncpp).

2. Create a native C++ project and import the preceding files to the project. The directory structure is as follows:

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

3. In the **CMakeLists.txt** file, add the source file and dynamic libraries.

   ```cmake
   # Add the **jsoncpp.cpp** file, which is used to parse the JSON strings in the subscription events.
   add_library(entry SHARED napi_init.cpp jsoncpp.cpp)
   # Add **libhiappevent_ndk.z.so** and **libhilog_ndk.z.so** (log output). 
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libhiappevent_ndk.z.so)
   ```

4. Import the dependencies to the **napi_init.cpp** file, and define **LOG_TAG**.

   ```c++
   #include "napi/native_api.h"
   #include "json/json.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

### Step 2: Subscribing to Address Sanitizer Events

1. Subscribe to system events.

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
                      strcmp(appEventGroups[i].appEventInfos[j].name, EVENT_ADDRESS_SANITIZER) == 0) {
                      Json::Value params;
                      Json::Reader reader(Json::Features::strictMode());
                      Json::FastWriter writer;
                      if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                          auto time = params["time"].asInt64();
                          auto bundleVersion = params["bundle_version"].asString();
                          auto bundleName = params["bundle_name"].asString();
                          auto pid = params["pid"].asInt();
                          auto uid = params["uid"].asInt();
                          auto type = params["type"].asString();
                          std::string logOverLimit = params["log_over_limit"].asBool() ? "true" : "false";
                          auto externalLog = writer.write(params["external_log"]);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.type=%{public}s", type.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}s", logOverLimit.c_str());
                      }
                  }
              }
          }
      }
      
      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          // Set the watcher name. The system identifies different watchers based on their names.
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
          // Set the event to subscribe to EVENT_ADDRESS_SANITIZER.
          const char *names[] = {EVENT_ADDRESS_SANITIZER};
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
      
      // Implement the callback function used to return the listened events. The content pointed by the events pointer is valid only in this function.
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
                  if (domain ==  DOMAIN_OS && name == EVENT_ADDRESS_SANITIZER) {
                      auto time = eventInfo["time"].asInt64();
                      auto bundleVersion = eventInfo["bundle_version"].asString();
                      auto bundleName = eventInfo["bundle_name"].asString();
                      auto pid = eventInfo["pid"].asInt();
                      auto uid = eventInfo["uid"].asInt();
                      auto asanType = eventInfo["type"].asString();
                      auto externalLog = writer.write(eventInfo["external_log"]);
                      std::string logOverLimit = eventInfo["log_over_limit"].asBool() ? "true" : "false";
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.crash_type=%{public}s", asanType.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}s", logOverLimit.c_str());
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
          // Set the event to subscribe to EVENT_ADDRESS_SANITIZER.
          const char *names[] = {EVENT_ADDRESS_SANITIZER};
          // Add the events to watch, for example, system events.
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // Set the implemented callback function. The callback function will be triggered when the conditions set by OH_HiAppEvent_SetTriggerCondition are met.
          OH_HiAppEvent_SetWatcherOnTrigger(systemEventWatcher, OnTrigger);
          // Set the conditions for triggering the subscription callback. For example, trigger this onTrigger callback when the number of new event logs is 1.
          OH_HiAppEvent_SetTriggerCondition(systemEventWatcher, 1, 0, 0);
          // Add a watcher to listen for the specified event.
          OH_HiAppEvent_AddWatcher(systemEventWatcher);
          return {};
      }
      ```

### Step 3: Constructing an Address Sanitizer Error

1. In the **napi_init.cpp** file, define a **Test** method to perform out-of-bounds access on an integer array.

   ```c++
   static napi_value Test(napi_env env, napi_callback_info info)
   {
       int a[10];
       a[10] = 1;
       return {};
   }
   ```

2. In the **napi_init.cpp** file, register **RegisterWatcher** and **Test** as ArkTS APIs.

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "registerWatcher", nullptr, RegisterWatcher, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "test", nullptr, Test, nullptr, nullptr, nullptr, napi_default, nullptr}
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

   In the **index.d.ts** file, define ArkTS APIs.

   ```typescript
   export const registerWatcher: () => void;
   export const test: () => void;
   ```

3. In the **EntryAbility.ets** file, add the following interface invocation to **onCreate()**.

   ```typescript
   // Import the dependent module.
   import testNapi from 'libentry.so';
   
   // Add the interface invocation to onCreate().
   // Register the system event watcher at startup.
   testNapi.registerWatcher();
   ```

4. In the **entry > src > main > ets > pages > Index.ets** file, add a button to trigger an address sanitizer event.

   ```ts
   import testNapi from 'libentry.so';
   
   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         Column() {
           Button("address-sanitizer").onClick(() => {
             testNapi.test();
           })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

5. In DevEco Studio, choose **entry**, click **Edit Configurations**, click **Diagnostics**, select **Address Sanitizer**, and click **OK**. Click the **Run** button to run the project. Then, click the **address-sanitizer** button to trigger an address sanitizer event. The application crashes. After restarting the application, you can view the following event information in the **Log** window.

   ```text
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=ADDRESS_SANITIZER
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1713148093326
   HiAppEvent eventInfo.params.bundle_version=1.0.0
   HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
   HiAppEvent eventInfo.params.pid=3378
   HiAppEvent eventInfo.params.uid=20020140
   HiAppEvent eventInfo.params.type="stack-buffer-overflow"
   HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/ADDRESS_SANITIZER_1713148093326_3378.log"]
   HiAppEvent eventInfo.params.log_over_limit=false
   ```

### Step 4: Destroying an Event Observer

1. Remove the event watcher.

   ```c++
   static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
       // Remove the watcher.
       OH_HiAppEvent_RemoveWatcher(systemEventWatcher);
       return {};
   }
   ```

2. Destroy the event watcher.

   ```c++
   static napi_value DestroyWatcher(napi_env env, napi_callback_info info) {
       // Destroy the created watcher and set systemEventWatcher to nullptr.
       OH_HiAppEvent_DestroyWatcher(systemEventWatcher);
       systemEventWatcher = nullptr;
       return {};
   }
   ```
