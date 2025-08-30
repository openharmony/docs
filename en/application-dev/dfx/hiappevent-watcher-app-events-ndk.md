# Event Subscription (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--Designer: @junjie_shi-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

HiAppEvent provides APIs for subscribing to application events.

## Available APIs

For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [hiappevent.h](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md).

**Subscription APIs**

| API| Description|
| -------- | -------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher \* watcher) | Adds a watcher to listen for application events.|
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher \* watcher) | Removes a watcher for the specified application events.|

**Event Logging APIs**

| API| Description|
| -------- | -------- |
| int OH_HiAppEvent_Write(const char \* domain, const char \* name, enum EventType type, const ParamList list) | Logs application events whose parameters are of the list type.|

## How to Develop

The following describes how to subscribe to a crash event (system event) and a button click event (application event).

### Step 1: Creating a Project and Configuring Compilation Options

1. Obtain the **jsoncpp** file on which the sample project depends.
   Specifically, download the source code package from [JsonCpp](https://github.com/open-source-parsers/jsoncpp) and obtain the **jsoncpp.cpp**, **json.h**, and **json-forwards.h** files by following the procedure described in **Amalgamated source**.
   Create a native C++ project and import the **jsoncpp** file to the project. The directory structure is as follows:

   ```text
   entry
   └── src
       └── main
           ├── cpp
           │   ├── CMakeLists.txt
           │   ├── json
           │   │   ├── json-forwards.h
           │   │   └── json.h
           │   ├── jsoncpp.cpp
           │   ├── napi_init.cpp
           │   └── types
           │       └── libentry
           │           ├── Index.d.ts
           │           └── oh-package.json5
           └── ets
               ├── entryability
               │   └── EntryAbility.ets
               └── pages
                   └── Index.ets
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
   #include "napi/native_api.h"
   #include "json/json.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

### Step 2: Subscribing to an Event

1. Subscribe to the events using **OnReceive** and **OnTrigger**, respectively.
   - Subscribe to the crash event (system event) using **OnReceive**. After receiving the event, the watcher immediately triggers the **OnReceive** callback. In the **napi_init.cpp** file, define the methods related to the watcher of the **OnReceive** type.

      ```c++
      // Define a variable to cache the pointer to the created watcher.
      static HiAppEvent_Watcher *onReceiverWatcher;
      
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
                          // Obtain the timestamp of the crash event.
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", params["time"].asInt64());
                          // Obtain the bundle name of the crashed application.
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", params["bundle_name"].asString().c_str());
                          auto external_log = writer.write(params["external_log"]);
                          // Obtain the error log file about the crash event.
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", external_log.c_str());
                      }
                  }
              }
          }
      }
      static napi_value RegisterWatcherCrash(napi_env env, napi_callback_info info) {
          // Set the watcher name. The system identifies different watchers based on their names.
          onReceiverWatcher = OH_HiAppEvent_CreateWatcher("AppCrashWatcher");
          // Set the event name for subscription to EVENT_APP_CRASH (the crash event).
          const char *names[] = {EVENT_APP_CRASH};
          // Add the events to watch, for example, system events.
          OH_HiAppEvent_SetAppEventFilter(onReceiverWatcher, DOMAIN_OS, 0, names, 1);
          // Set the implemented callback. After receiving the event, the watcher immediately triggers the OnReceive callback.
          OH_HiAppEvent_SetWatcherOnReceive(onReceiverWatcher, OnReceive);
          // Add a watcher to listen for the specified event.
          OH_HiAppEvent_AddWatcher(onReceiverWatcher);
          return {};
      }
      ```

   - Subscribes to the button click event (application event) using **OnTrigger**. The **OnTrigger()** callback can be triggered only when the conditions specified by **OH_HiAppEvent_SetTriggerCondition()** are met. In the **napi_init.cpp** file, define the methods related to the watcher of the **OnTrigger** type.

      ```c++
      // Define a variable to cache the pointer to the created watcher.
      static HiAppEvent_Watcher *onTriggerWatcher;
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
          OH_HiAppEvent_TakeWatcherData(onTriggerWatcher, row, OnTake);
      }
      
      static napi_value RegisterWatcherClick(napi_env env, napi_callback_info info) {
          // Set the watcher name. The system identifies different watchers based on their names.
          onTriggerWatcher = OH_HiAppEvent_CreateWatcher("ButtonClickWatcher");
          // Set the name of the subscribed event to click.
          const char *names[] = {"click"};
          // Add the system events to watch, for example, events related to button.
          OH_HiAppEvent_SetAppEventFilter(onTriggerWatcher, "button", 0, names, 1);
          // Set the implemented callback function. The callback function will be triggered when the conditions set by OH_HiAppEvent_SetTriggerCondition are met.
          OH_HiAppEvent_SetWatcherOnTrigger(onTriggerWatcher, OnTrigger);
          // Set the conditions for triggering the subscription callback. For example, trigger this onTrigger callback when the number of new event logs is 1.
          OH_HiAppEvent_SetTriggerCondition(onTriggerWatcher, 1, 0, 0);
          // Add a watcher to listen for the specified event.
          OH_HiAppEvent_AddWatcher(onTriggerWatcher);
          return {};
      }
      ```

2. In the **napi_init.cpp** file, add the logging API for the button click event.

   ```c++
   static napi_value WriteAppEvent(napi_env env, napi_callback_info info) {
       auto params = OH_HiAppEvent_CreateParamList();
       OH_HiAppEvent_AddInt64Param(params, "click_time", time(nullptr));
       OH_HiAppEvent_Write("button", "click", EventType::BEHAVIOR, params);
       OH_HiAppEvent_DestroyParamList(params);
       return {};
   }
   ```

3. In the **napi_init.cpp** file, register **RegisterWatcherCrash()** (crash event subscription), **RegisterWatcherClick()** (button click event subscription), and **WriteAppEvent()** (button click event logging) as ArkTS APIs.

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "registerWatcherCrash", nullptr, RegisterWatcherCrash, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "registerWatcherClick", nullptr, RegisterWatcherClick, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "writeAppEvent", nullptr, WriteAppEvent, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

4. In the **index.d.ts** file, define the ArkTS API.

   ```ts
   export const registerWatcherCrash: () => void;
   export const registerWatcherClick: () => void;
   export const writeAppEvent: () => void;
   ```

5. In the **EntryAbility.ets** file, add the following API to **onCreate()**.

   ```ts
   // Import the dependent module.
   import testNapi from 'libentry.so';
   
   // Add the API call to onCreate().
   // Register the crash event watcher at startup.
   testNapi.registerWatcherCrash();
   // Register the button click event watcher at startup.
   testNapi.registerWatcherClick();
   ```

### Step 3: Triggering an Event

In the **Index.ets** file, add the **appCrash** button to trigger the crash event, and add the **buttonClick** button to log events in the button click function. The sample code is as follows:

```ts
// Import the dependent module.
import testNapi from 'libentry.so';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button("appCrash")
          .onClick(() => {
            // Construct a scenario in onClick() to trigger a crash event.
            let result: object = JSON.parse("");
          })
          .position({ x: 100, y: 100 }) // Set the button position.

        Button("buttonClick")
          .onClick(() => {
            // Log a button click event when the button is clicked.
            testNapi.writeAppEvent();
          })
          .position({ x: 100, y: 200 }) // Set the button position.
        }
      .width('100%')
    }
    .height('100%')
  }
}
```

## Debugging and Verification

1. Click the **Run** button in DevEco Studio to run the project. Then, click the **appCrash** button to trigger a crash event. After the application exits, restart it.

2. Search for the keyword **HiAppEvent** in the HiLog window to view the logs of the crash event processing.

   ```text
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_CRASH
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1750946685473
   HiAppEvent eventInfo.params.bundle_name=com.example.cxxxx
   HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_CRASH_1750946685805_64003.log"]
   ```

3. Click the **buttonClick** button to trigger the button click event. Search for the keyword **HiAppEvent** in the HiLog window to view the logs of the button click event processing.

   ```text
   HiAppEvent eventInfo={"domain_":"button","name_":"click","type_":4,"time_":1750947007108,"tz_":"","pid_":64750,"tid_":64750,"click_time":1750947007}
   HiAppEvent eventInfo.domain=button
   HiAppEvent eventInfo.name=click
   HiAppEvent eventInfo.eventType=4
   HiAppEvent eventInfo.params.click_time=1750947007
   ```

4. Remove the application event watcher.

   ```c++
   static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
       // Remove the watcher.
       OH_HiAppEvent_RemoveWatcher(appEventWatcher);
       return {};
   }
   ```

5. Destroy the application event watcher.

   ```c++
   static napi_value DestroyWatcher(napi_env env, napi_callback_info info) {
       // Destroy the created watcher and set appEventWatcher to nullptr.
       OH_HiAppEvent_DestroyWatcher(appEventWatcher);
       appEventWatcher = nullptr;
       return {};
   }
   ```
