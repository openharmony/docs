# Subscribing to Main Thread Jank Events (C/C++)

## Available APIs

For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [HiAppEvent](../reference/apis-performance-analysis-kit/_hi_app_event.md#hiappevent).

**Subscription APIs**

| API                                                      | Description                                        |
| ------------------------------------------------------------ | -------------------------------------------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher *watcher)   | Adds a watcher to listen for application events.|
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher *watcher)| Removes a watcher to unsubscribe from application events.|

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

3. Import the dependencies to the **napi_init.cpp** file, and define **LOG_TAG**.

   ```c++
   # include "json/json.h"
   # include "hilog/log.h"
   # include "hiappevent/hiappevent.h"
   # include "hiappevent/hiappevent_event.h"
   # undef LOG_TAG
   # define LOG_TAG "testTag"
   ```

4. Subscribe to application events.

    - Watcher of the onReceive type.

      In the **napi_init.cpp** file, define the methods related to the watcher of the onReceive type.

      ```c++
      // Define a variable to cache the pointer to the created watcher.
      static HiAppEvent_Watcher *systemEventWatcher; 

      static void OnReceive(const char *domain, const struct HiAppEvent_AppEventGroup *appEventGroups, uint32_t groupLen) {
          for (int i = 0; i < groupLen; ++i) {
              for (int j = 0; j < appEventGroups[i].infoLen; ++j) {
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s",
                              appEventGroups[i].appEventInfos[j].domain);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s",
                              appEventGroups[i].appEventInfos[j].name);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d",
                              appEventGroups[i].appEventInfos[j].type);
                  if (strcmp(appEventGroups[i].appEventInfos[j].domain, DOMAIN_OS) == 0 &&
                      strcmp(appEventGroups[i].appEventInfos[j].name, EVENT_MAIN_THREAD_JANK) == 0) {
                      Json::Value params;
                      Json::Reader reader(Json::Features::strictMode());
                      Json::FastWriter writer;
                      if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                          auto time = params["time"].asInt64();
                          auto pid = params["pid"].asInt();
                          auto uid = params["uid"].asInt();
                          auto bundleName = params["bundle_name"].asString();
                          auto bundleVersion = params["bundle_version"].asString();
                          auto beginTime = params["begin_time"].asInt64();
                          auto endTime = params["end_time"].asInt64();
                          auto externalLogSize = params["external_log"].size();
                          auto logOverLimit = params["logOverLimit"].asBool();
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s",
                                      bundleName.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s",
                                      bundleVersion.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.begin_time=%{public}lld", beginTime);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.end_time=%{public}lld", endTime);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}d",
                                      externalLogSize);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d",
                                      logOverLimit);
                      }
                  }
              }
          }
      }

      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent RegisterWatcher");
          // Set the watcher name. The system identifies different watchers based on their names.
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
          // Set the event type to EVENT_MAIN_THREAD_JANK.
          const char *names[] = {EVENT_MAIN_THREAD_JANK};
          // Add the events to watch, for example, system events.
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // Set the implemented callback. After receiving the event, the watcher immediately triggers the OnReceive callback.
          OH_HiAppEvent_SetWatcherOnReceive(systemEventWatcher, OnReceive);
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

6. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, add the following interface invocation to **onCreate()**.

   ```typescript
   // Import the dependent module.
   import testNapi from 'libentry.so'

   // Add the interface invocation to onCreate().
   // Register the system event watcher at startup.
   testNapi.registerWatcher();
   ```

7. In the **entry/src/main/ets/pages/Index.ets** file, add the **timeOut500** button with **onClick()** to trigger a main thread jank event when the button is clicked. The sample code is as follows:
   ```typescript
      Button("timeOut350")
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .onClick(() => {
          let t = Date.now();
          while (Date.now() - t <= 350){
          
          }
      })
   ```

8. If the nolog version is used and the developer mode is disabled, the main thread checker will collect tracing data when a task times out.

9. In DevEco Studio, click the **Run** button to run the application project. Click the **timeOut350** button twice consecutively to trigger a main thread jank event.

10. After the main thread jank event is reported, you can view the following event information in the **Log** window.

    ```text
      HiAppEvent eventInfo.domain=OS
      HiAppEvent eventInfo.name=MAIN_THREAD_JANK
      HiAppEvent eventInfo.eventType=1
      HiAppEvent eventInfo.params.time=1717597063727
      HiAppEvent eventInfo.params.pid=45572
      HiAppEvent eventInfo.params.uid=20020151
      HiAppEvent eventInfo.params.bundle_name=com.example.nativemainthread
      HiAppEvent eventInfo.params.bundle_version=1.0.0
      HiAppEvent eventInfo.params.begin_time=1717597063225
      HiAppEvent eventInfo.params.end_time=1717597063727
      HiAppEvent eventInfo.params.external_log=1
      HiAppEvent eventInfo.params.log_over_limit=0
    ```

    > **NOTE**
    > For details, see [Main Thread Jank Event Time Specifications](./hiappevent-watcher-mainthreadjank-events-arkts.md#main-thread-jank-event-time-specifications) and [Main Thread Jank Event Specifications](./hiappevent-watcher-mainthreadjank-events-arkts.md#main-thread-jank-event-specifications).

11. Remove the application event watcher.

    ```c++
    static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
        // Remove the watcher.
        OH_HiAppEvent_RemoveWatcher(systemEventWatcher);
        return {};
    }
    ```

12. Destroy the application event watcher.

    ```c++
    static napi_value DestroyWatcher(napi_env env, napi_callback_info info) {
        // Destroy the created watcher and set systemEventWatcher to nullptr.
        OH_HiAppEvent_DestroyWatcher(systemEventWatcher);
        systemEventWatcher = nullptr;
        return {};
    }
    ```

<!--no_check-->