# Subscribing to Application Events (C/C++)

HiAppEvent provides APIs for subscribing to application events.

## Available APIs
For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [HiAppEvent](../reference/apis-performance-analysis-kit/_hi_app_event.md#hiappevent).

**Event Logging APIs**

| API                                                      | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| int OH_HiAppEvent_Write(const char \*domain, const char \*name, enum EventType type, const ParamList list) | Logs application events whose parameters are of the list type.|

**Subscription APIs**

| API                                                      | Description                                        |
| ------------------------------------------------------------ | -------------------------------------------- |
| int OH_HiAppEvent_AddWatcher (HiAppEvent_Watcher \*watcher)  | Adds a watcher to listen for application events.|
| int OH_HiAppEvent_RemoveWatcher (HiAppEvent_Watcher \*watcher) | Removes a watcher to unsubscribe from application events.|

## How to Develop

The following describes how to log and subscribe to button onclick events.

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
   
   # undef LOG_TAG
   # define LOG_TAG "testTag"
   ```

4. Subscribe to application events.

   - Watcher of the onReceive type:

     In the **napi_init.cpp** file, define the methods related to the watcher of the onReceive type.

     ```c++
     static HiAppEvent_Watcher *appEventWatcher;
     
     static void OnReceive(const char *domain, const struct HiAppEvent_AppEventGroup *appEventGroups, uint32_t groupLen) {
         for (int i = 0; i < groupLen; ++i) {
             for (int j = 0; j < appEventGroups[i].infoLen; ++j) {
                 OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", appEventGroups[i].appEventInfos[j].domain);
                 OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", appEventGroups[i].appEventInfos[j].name);
                 OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", appEventGroups[i].appEventInfos[j].type);
                 if (strcmp(appEventGroups[i].appEventInfos[j].domain, "button") == 0 &&
                     strcmp(appEventGroups[i].appEventInfos[j].name, "click") == 0) {
                     Json::Value params;
                     Json::Reader reader(Json::Features::strictMode());
                     if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                         auto time = params["click_time"].asInt64();
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.click_time=%{public}lld", time);
                     }
                 }
             }
         }
     }
     
     static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
         // Set the watcher name. The system identifies different watchers based on their names.
         appEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
         // Set the name of the subscribed event to click.
         const char *names[] = {"click"};
         // Add the system events to watch, for example, events related to button.
         OH_HiAppEvent_SetAppEventFilter(appEventWatcher, "button", 0, names, 1);
         // Set the implemented callback. After receiving the event, the watcher immediately triggers the OnReceive callback.
         OH_HiAppEvent_SetWatcherOnReceive(appEventWatcher, OnReceive);
         // Add a watcher to listen for the specified event.
         OH_HiAppEvent_AddWatcher(appEventWatcher);
         return {};
     }
     ```

   - Watcher of the onTrigger type:

     In the **napi_init.cpp** file, define the methods related to the watcher of the OnTrigger type.

     ```c++
     // Define a variable to cache the pointer to the created watcher.
     static HiAppEvent_Watcher *appEventWatcher;
     
     // Implement the callback function used to return the listened events. The content pointed to by the events pointer is valid only in this function.
     static void OnTake(const char *const *events, uint32_t eventLen) {
         Json::Reader reader(Json::Features::strictMode());
         for (int i = 0; i < eventLen; ++i) {
             OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo=%{public}s", events[i]);
             Json::Value eventInfo;
             if (reader.parse(events[i], eventInfo)) {
                 auto domain = eventInfo["domain_"].asString();
                 auto name = eventInfo["name_"].asString();
                 auto type = eventInfo["type_"].asInt();
                 OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", domain.c_str());
                 OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", name.c_str());
                 OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", type);
                 if (domain == "button" && name == "click") {
                     auto clickTime = eventInfo["click_time"].asInt64();
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.click_time=%{public}lld", clickTime);
                 }
             }
         }
     }
     
     // Implement the subscription callback function to apply custom processing to the obtained event logging data.
     static void OnTrigger(int row, int size) {
         // After the callback is received, obtain the specified number of received events.
         OH_HiAppEvent_TakeWatcherData(appEventWatcher, row, OnTake);
     }
     
     static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
         // Set the watcher name. The system identifies different watchers based on their names.
         appEventWatcher = OH_HiAppEvent_CreateWatcher("onTriggerWatcher");
         // Set the name of the subscribed event to click.
         const char *names[] = {"click"};
         // Add the system events to watch, for example, events related to button.
         OH_HiAppEvent_SetAppEventFilter(appEventWatcher, "button", 0, names, 1);
         // Set the implemented callback function. The callback function will be triggered when the conditions set by OH_HiAppEvent_SetTriggerCondition are met.
         OH_HiAppEvent_SetWatcherOnTrigger(appEventWatcher, OnTrigger);
         // Set the conditions for triggering the subscription callback. For example, trigger this onTrigger callback when the number of new event logs is 1.
         OH_HiAppEvent_SetTriggerCondition(appEventWatcher, 1, 0, 0);
         // Add a watcher to listen for the specified event.
         OH_HiAppEvent_AddWatcher(appEventWatcher);
         return {};
     }
     ```

5. In the **napi_init.cpp** file, add an API for logging button onclick events.

   ```c++
   static napi_value WriteAppEvent(napi_env env, napi_callback_info info) {
       auto params = OH_HiAppEvent_CreateParamList();
       OH_HiAppEvent_AddInt64Param(params, "click_time", time(nullptr));
       OH_HiAppEvent_Write("button", "click", EventType::BEHAVIOR, params);
       OH_HiAppEvent_DestroyParamList(params);
       return {};
   }
   ```

6. In the **napi_init.cpp** file, register **RegisterWatcher** and **WriteAppEvent** as ArkTS APIs.

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           {"registerWatcher", nullptr, RegisterWatcher, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"writeAppEvent", nullptr, WriteAppEvent, nullptr, nullptr, nullptr, napi_default, nullptr}
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

   In the **index.d.ts** file, define ArkTS APIs.

   ```typescript
   export const registerWatcher: () => void;
   export const writeAppEvent: () => void;
   ```

7. In the **EntryAbility.ets** file, add the following interface invocation to **onCreate()**.

   ```typescript
   // Import the dependent module.
   import testNapi from 'libentry.so'

   // Add the interface invocation to onCreate().
   // Register the application event watcher at startup.
   testNapi.registerWatcher();
   ```

8. In the **Index.ets** file, add a button to trigger the button onclick event.

   ```typescript
   import testNapi from 'libentry.so'

   Button("button_click").onClick(() => {
     testNapi.writeAppEvent();
   })
   ```

9. You can view the processing logs of application event data in the **Log** window.

   ```text
   HiAppEvent eventInfo.domain=button
   HiAppEvent eventInfo.name=click
   HiAppEvent eventInfo.eventType=4
   HiAppEvent eventInfo.params.click_time=1502031843
   ```

10. Remove the application event watcher.

    ```c++
    static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
        // Remove the watcher.
        OH_HiAppEvent_RemoveWatcher(appEventWatcher);
        return {};
    }
    ```

11. Destroy the application event watcher.

    ```c++
    static napi_value DestroyWatcher(napi_env env, napi_callback_info info) {
        // Destroy the created watcher and set appEventWatcher to nullptr.
        OH_HiAppEvent_DestroyWatcher(appEventWatcher);
        appEventWatcher = nullptr;
        return {};
    }
    ```

<!--no_check-->