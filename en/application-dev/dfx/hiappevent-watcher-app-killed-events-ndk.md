# Subscribing to Application Killed Events (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @shead-master-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## Event Specifications

For details, see [Application Killed Event Overview](./hiappevent-watcher-app-killed-events.md).

## Available APIs

For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [HiAppEvent](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md).

**Subscription APIs**

| Name                                                      | Description                                        |
| ------------------------------------------------------------ | -------------------------------------------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher *watcher)   | Adds a watcher to listen for application events.|
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher *watcher) | Removes a watcher for the specified application events.|

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
   # Add the **jsoncpp.cpp** file, which is used to parse the JSON strings in the subscription events.
   add_library(entry SHARED napi_init.cpp jsoncpp.cpp)
   # Add **libhiappevent_ndk.z.so** and **libhilog_ndk.z.so** (log output).
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libhiappevent_ndk.z.so)
   ```

3. Import the dependencies to the **napi_init.cpp** file, and define **LOG_TAG**.

   ```c++
   #include "napi/native_api.h"
   #include "json/json.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"
   #include "hiappevent/hiappevent_event.h"
   #include <thread>
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

4. Subscribe to system events.

    - Watcher of the **onReceive** type.

      In the **napi_init.cpp** file, define the methods related to the watcher of the **onReceive** type and add the native memory leak method.

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
                      strcmp(appEventGroups[i].appEventInfos[j].name, EVENT_APP_KILLED) == 0) {
                      Json::Value params;
                      Json::Reader reader(Json::Features::strictMode());
                      Json::FastWriter writer;
                      if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                          auto time = params["time"].asInt64();
                          auto reason = params["reason"].asString();
                          auto foreground = params["foreground"].asString();
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.reason=%{public}s",
                                      reason.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}s",
                                      foreground.c_str());
                      }
                  }
              }
          }
      }
      
      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent RegisterWatcher");
          // Set the watcher name. The system identifies different watchers based on their names.
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
          // Set the event to watch to EVENT_APP_KILLED.
          const char *names[] = {EVENT_APP_KILLED};
          // Add the events to watch, for example, system events.
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // Set the implemented callback. After receiving the event, the watcher immediately triggers the OnReceive callback.
          OH_HiAppEvent_SetWatcherOnReceive(systemEventWatcher, OnReceive);
          // Add a watcher to listen for the specified event.
          OH_HiAppEvent_AddWatcher(systemEventWatcher);
          return {};
      }
      ```

5. Implement the **Leak** API. (This API is used only for fault injection and self-verification and does not need to be integrated into the service logic.)

   ```c++
   static void NativeLeak()
   {
       constexpr int leak_size_per_time = 500000;
       while (true) {
           char *p = (char *)malloc(leak_size_per_time + 1);
           if (!p) {
               break;
           }
           memset(p, 'a', leak_size_per_time);
           std::this_thread::sleep_for(std::chrono::milliseconds(10));
       }
   }
   
   static napi_value Leak(napi_env env, napi_callback_info info) {
   	std::thread t1(NativeLeak);
   	t1.detach();
       return {};
   }
   ```

6. In the **napi_init.cpp** file, register **RegisterWatcher** and **Leak** as ArkTS APIs.

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "registerWatcher", nullptr, RegisterWatcher, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "leak", nullptr, Leak, nullptr, nullptr, nullptr, napi_default, nullptr },
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```
   
   In the **index.d.ts** file, define the ArkTS API.

   ```typescript
   export const registerWatcher: () => void;
   export const leak: () => void;
   ```
   
7. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, add the following interface invocation to **onCreate()**.

   ```typescript
   // Import the dependent module.
   import testNapi from 'libentry.so';
   
   // Add the API to onCreate().
   // Register the system event watcher at startup.
   testNapi.registerWatcher();
   
   // Trigger a leak when the button is operated or started.
   testNapi.leak();
   ```

8. Click the **Run** button in DevEco Studio to run the project. After the leak is triggered, wait for 2 to 3 minutes and the application exits.

9. After the application is killed, open the application again. The killed event is reported, and the system calls **onReceive()**. You can view the following event information in the **Log** window.

    ```text
      HiAppEvent eventInfo.domain=OS
      HiAppEvent eventInfo.name=APP_KILLED
      HiAppEvent eventInfo.eventType=2
      HiAppEvent eventInfo.params.time=1717597063727
      HiAppEvent eventInfo.params.reason="RssThresholdKiller"
      HiAppEvent eventInfo.params.foreground=true
    ```

    > **NOTE**
    >
    > Based on the error log information, you can check the [specific cause of the killed event](./hiappevent-watcher-app-killed-events.md).

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
