# Subscribing to Crash Events (C/C++)

## Available APIs

For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [HiAppEvent](../reference/apis-performance-analysis-kit/_hi_app_event.md#hiappevent).

**Subscription APIs**

| API                                                      | Description                                        |
| ------------------------------------------------------------ | -------------------------------------------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher \*watcher)   | Adds a watcher to listen for application events.|
| int OH_HiAppEvent_RemoveWatcher (HiAppEvent_Watcher \*watcher) | Removes a watcher to unsubscribe from application events.|

## How to Develop

The following describes how to subscribe to the crash event triggered by a button click.

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
   # include "json/json.h"
   # include "hilog/log.h"
   # include "hiappevent/hiappevent.h"
   
   # undef LOG_TAG
   # define LOG_TAG "testTag"
   ```

4. Subscribe to application events.

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
                     strcmp(appEventGroups[i].appEventInfos[j].name, EVENT_APP_CRASH) == 0) {
                     Json::Value params;
                     Json::Reader reader(Json::Features::strictMode());
                     Json::FastWriter writer;
                     if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                         auto time = params["time"].asInt64();
                         auto crashType = params["crash_type"].asString();
                         auto foreground = params["foreground"].asBool();
                         auto bundleVersion = params["bundle_version"].asString();
                         auto bundleName = params["bundle_name"].asString();
                         auto pid = params["pid"].asInt();
                         auto uid = params["uid"].asInt();
                         auto uuid = params["uuid"].asString();
                         auto exception = writer.write(params["exception"]);
                         auto hilogSize = params["hilog"].size();
                         auto externalLog = writer.write(params["external_log"]);
                         auto logOverLimit = params["log_over_limit"].asBool();
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.crash_type=%{public}s", crashType.c_str());
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d", foreground);
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uuid=%{public}s", uuid.c_str());
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s", exception.c_str());
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d", hilogSize);
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d", logOverLimit);
                     }
                 }
             }
         }
     }
     
     static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
         // Set the watcher name. The system identifies different watchers based on their names.
         systemEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
         // Set the event type to EVENT_APP_CRASH.
         const char *names[] = {EVENT_APP_CRASH};
         // Add the system events to watch, for example, system events.
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
                 if (domain ==  DOMAIN_OS && name == EVENT_APP_CRASH) {
                     auto time = eventInfo["time"].asInt64();
                     auto crashType = eventInfo["crash_type"].asString();
                     auto foreground = eventInfo["foreground"].asBool();
                     auto bundleVersion = eventInfo["bundle_version"].asString();
                     auto bundleName = eventInfo["bundle_name"].asString();
                     auto pid = eventInfo["pid"].asInt();
                     auto uid = eventInfo["uid"].asInt();
                     auto uuid = eventInfo["uuid"].asString();
                     auto exception = writer.write(eventInfo["exception"]);
                     auto hilogSize = eventInfo["hilog"].size();
                     auto externalLog = writer.write(eventInfo["external_log"]);
                     auto logOverLimit = eventInfo["log_over_limit"].asBool();
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.crash_type=%{public}s", crashType.c_str());
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d", foreground);
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uuid=%{public}s", uuid.c_str());
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s", exception.c_str());
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d", hilogSize);
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d", logOverLimit);
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
         // Set the event type to EVENT_APP_CRASH.
         const char *names[] = {EVENT_APP_CRASH};
         // Add the system events to watch, for example, system events.
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

   In the **index.d.ts** file, define ArkTS APIs.

   ```typescript
   export const registerWatcher: () => void;
   ```

6. In the **EntryAbility.ets** file, add the following interface to **onCreate()**.

   ```typescript
   // Import the dependent module.
   import testNapi from 'libentry.so'

   // Add the interface to onCreate().
   // Register the system event watcher at startup.
   testNapi.registerWatcher();
   ```

7. In the **Index.ets** file, add a button to trigger the crash event.

   ```typescript
   Button("appCrash").onClick(() => {
     JSON.parse("");
   })
   ```

8. In DevEco Studio, click the **Run** button to run the project. Then, click the **appCrash** button to trigger a crash event. 

9. The application crashes. After restarting the application, you can view the following event information in the **Log** window.

   ```text
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_CRASH
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1502032265088
   HiAppEvent eventInfo.params.crash_type=JsError
   HiAppEvent eventInfo.params.foreground=1
   HiAppEvent eventInfo.params.bundle_version=1.0.0
   HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
   HiAppEvent eventInfo.params.pid=19237
   HiAppEvent eventInfo.params.uid=20010043
   HiAppEvent eventInfo.params.uuid=cc0f062e1b28c1fd2c817fafab5e8ca3207925b4bdd87c43ed23c60029659e01
   HiAppEvent eventInfo.params.exception={"message":"Unexpected Text in JSON","name":"SyntaxError","stack":"at anonymous (entry/src/main/ets/pages/Index.ets:16:11)"}
   HiAppEvent eventInfo.params.hilog.size=110
   HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_CRASH_1502032265211_19237.log"]
   HiAppEvent eventInfo.params.log_over_limit=0
   ```

10. Remove the application event watcher.

    ```c++
    static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
        // Remove the watcher.
        OH_HiAppEvent_RemoveWatcher(systemEventWatcher);
        return {};
    }
    ```

11. Destroy the application event watcher.

    ```c++
    static napi_value DestroyWatcher(napi_env env, napi_callback_info info) {
        // Destroy the created watcher and set systemEventWatcher to nullptr.
        OH_HiAppEvent_DestroyWatcher(systemEventWatcher);
        systemEventWatcher = nullptr;
        return {};
    }
    ```

<!--no_check-->