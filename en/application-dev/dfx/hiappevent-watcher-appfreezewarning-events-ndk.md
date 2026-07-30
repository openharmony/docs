# Subscribing to App Freeze Warning Events (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=f319e3e62d6356bf78f31e2e8f7ba3927caddf1e translatedAt=2026-07-29T10:49:31.104Z pushedAt=2026-07-29T12:37:47.664Z -->

## Overview

This section describes how to use the C/C++ APIs provided by HiAppEvent to subscribe to app freeze warning events. For detailed API usage instructions (parameter constraints, value ranges, etc.), refer to [hiappevent.h](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md).

## Available APIs

| Name | Description |
| -------- | -------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher \*watcher) | Adds an app event watcher to subscribe to app events. |
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher \*watcher) | Removes an app event watcher to unsubscribe from app events. |

## How to Develop

### Adding an Event Watcher

The following uses subscribing to app freeze warning events as an example to illustrate the development procedure.

1. Obtain the **jsoncpp** files required by this sample project. Download the source code package from the [third-party open-source library jsoncpp repository](https://github.com/open-source-parsers/jsoncpp), and follow the steps described in the **Amalgamated source** section of the README to obtain the **jsoncpp.cpp**, **json.h**, and **json-forwards.h** files.

2. Create a Native C++ project and import **jsoncpp** into the project. The directory structure is as follows.

   ```yml
   entry:
     src:
       main:
         cpp:
           json:
             - json.h
             - json-forwards.h
           types:
             libentry:
               - index.d.ts
           - CMakeLists.txt
           - jsoncpp.cpp
           - napi_init.cpp
         ets:
           entryability:
             - EntryAbility.ets
           pages:
             - Index.ets
   ```

3. Edit the **CMakeLists.txt** file to add the source file and dynamic libraries.

   ```cmake
   # Add the jsoncpp.cpp source file (for parsing JSON strings in subscribed events).
   add_library(entry SHARED napi_init.cpp jsoncpp.cpp)
   # Add dynamic library dependencies libhiappevent_ndk.z.so and libhilog_ndk.z.so (for log output).
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libhiappevent_ndk.z.so)
   ```

4. Edit the **napi_init.cpp** file to import the required header files and define **LOG_TAG**.

   ```c++
   #include "napi/native_api.h"
   #include "json/json.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

5. Subscribe to system events.

   - **onReceive** watcher

      Edit the **napi_init.cpp** file to define methods related to the **onReceive** watcher:

      ```c++
      // Define a variable to cache the pointer of the created watcher.
      static HiAppEvent_Watcher *systemEventWatcher; 
      
      static void OnReceive(const char *domain, const struct HiAppEvent_AppEventGroup *appEventGroups, uint32_t groupLen) {
          for (int i = 0; i < groupLen; ++i) {
              for (int j = 0; j < appEventGroups[i].infoLen; ++j) {
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", appEventGroups[i].appEventInfos[j].domain);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", appEventGroups[i].appEventInfos[j].name);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", appEventGroups[i].appEventInfos[j].type);
                  if (strcmp(appEventGroups[i].appEventInfos[j].domain, DOMAIN_OS) == 0 && 
                      strcmp(appEventGroups[i].appEventInfos[j].name, OH_EVENT_APP_FREEZE_WARNING) == 0) {
                      Json::Value params;
                      Json::Reader reader(Json::Features::strictMode());
                      Json::FastWriter writer;
                      if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                          auto time = params["time"].asInt64();
                          auto foreground = params["foreground"].asBool();
                          auto appRunningUniqueId = params["app_running_unique_id"].asString();
                          auto bundleVersion = params["bundle_version"].asString();
                          auto bundle_version_code = params["bundle_version_code"].asInt();
                          auto bundleName = params["bundle_name"].asString();
                          auto processName = params["process_name"].asString();
                          auto pid = params["pid"].asInt();
                          auto uid = params["uid"].asInt();
                          auto exception = writer.write(params["exception"]);
                          auto hilogSize = params["hilog"].size();
                          auto handleSize = params["event_handler"].size();
                          auto peerBindSize = params["peer_binder"].size();
                          auto threadSize = params["threads"].size();
                          auto memory = writer.write(params["memory"]);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d", foreground);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.app_running_unique_id=%{public}s", appRunningUniqueId.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version_code=%{public}d", bundle_version_code);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.process_name=%{public}s", processName.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s", exception.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d", hilogSize);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.event_handler.size=%{public}d", handleSize);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.peer_binder.size=%{public}d", peerBindSize);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.threads.size=%{public}d", threadSize);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
                      }
                  }
              }
          }
      }
      
      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          // Define a custom watcher name. The system identifies different watchers by their names.
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
          // Set the subscribed event to OH_EVENT_APP_FREEZE_WARNING.
          const char *names[] = {OH_EVENT_APP_FREEZE_WARNING};
          // Subscribe to the events of interest. A system event is subscribed here.
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // Set the implemented callback function. The OnReceive callback is triggered immediately after the watcher receives an event.
          OH_HiAppEvent_SetWatcherOnReceive(systemEventWatcher, OnReceive);
          // Enable the watcher to start listening for subscribed events.
          OH_HiAppEvent_AddWatcher(systemEventWatcher);
          return {};
      }
      ```

   - **onTrigger** watcher

      Edit the **napi_init.cpp** file to define methods related to the **onTrigger** watcher:

      ```c++
      // Define a variable to cache the pointer of the created watcher.
      static HiAppEvent_Watcher *systemEventWatcher;
      
      // Implement a callback to obtain monitored events. The content pointed to by the events pointer is valid only within this function.
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
                  if (domain ==  DOMAIN_OS && name == OH_EVENT_APP_FREEZE_WARNING) {
                      auto time = eventInfo["time"].asInt64();
                      auto foreground = eventInfo["foreground"].asBool();
                      auto appRunningUniqueId = eventInfo["app_running_unique_id"].asString();
                      auto bundleVersion = eventInfo["bundle_version"].asString();
                      auto bundle_version_code = eventInfo["bundle_version_code"].asInt();
                      auto bundleName = eventInfo["bundle_name"].asString();
                      auto processName = eventInfo["process_name"].asString();
                      auto pid = eventInfo["pid"].asInt();
                      auto uid = eventInfo["uid"].asInt();
                      auto exception = writer.write(eventInfo["exception"]);
                      auto hilogSize = eventInfo["hilog"].size();
                      auto handleSize =  eventInfo["event_handler"].size();
                      auto peerBindSize =  eventInfo["peer_binder"].size();
                      auto threadSize =  eventInfo["threads"].size();
                      auto memory =  writer.write(eventInfo["memory"]);
                      auto process_life_time = eventInfo["process_life_time"].asString();
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d", foreground);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.app_running_unique_id=%{public}s", appRunningUniqueId.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version_code=%{public}d", bundle_version_code);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.process_name=%{public}s", processName.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s", exception.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d", hilogSize);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.event_handler.size=%{public}d", handleSize);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.peer_binder.size=%{public}d", peerBindSize);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.threads.size=%{public}d", threadSize);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.process_life_time=%{public}s", process_life_time.c_str());
                  }
              }
          }
      }
      
      // Implement a subscription callback to perform custom processing on the obtained event data.
      static void OnTrigger(int row, int size) {
          // After receiving the callback, obtain the specified number of received events.
          OH_HiAppEvent_TakeWatcherData(systemEventWatcher, row, OnTake);
      }
      
      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          // Define a custom watcher name. The system identifies different watchers by their names.
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onTriggerWatcher");
          // Set the subscribed event to OH_EVENT_APP_FREEZE_WARNING.
          const char *names[] = {OH_EVENT_APP_FREEZE_WARNING};
          // Subscribe to events of interest. Here, a system event is subscribed to.
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // Set the implemented callback function. The callback is triggered only when the conditions set by OH_HiAppEvent_SetTriggerCondition are met.
          OH_HiAppEvent_SetWatcherOnTrigger(systemEventWatcher, OnTrigger);
          // Set the conditions for triggering the subscription callback. Here, the onTrigger callback is triggered when the number of new event records reaches 1.
          OH_HiAppEvent_SetTriggerCondition(systemEventWatcher, 1, 0, 0);
          // Start listening for subscribed events with the watcher.
          OH_HiAppEvent_AddWatcher(systemEventWatcher);
          return {};
      }
      ```

6. Register **RegisterWatcher** as an ArkTS API.

   Edit the **napi_init.cpp** file to register **RegisterWatcher** as an ArkTS API:

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

   Edit the **index.d.ts** file to define the ArkTS API:

   ```ts
   export const registerWatcher: () => void;
   ```

7. Edit the **EntryAbility.ets** file to add the API call to the **onCreate()** function.

   ```ts
   // Import the dependent module.
   import testNapi from 'libentry.so'
   
   // Add the API call in the onCreate() function.
   // Register the system event watcher at startup.
   testNapi.registerWatcher();
   ```

8. Edit the **Index.ets** file under **entry > src > main > ets > pages** in the project to add a button that triggers the app freeze warning event. The sample code is as follows:

   ```ts
     @Entry
     @Component
     struct Index {
       build() {
         RelativeContainer() {
           Column() {
             Button("appFreezeWarning", { stateEffect:true, type: ButtonType.Capsule})
               .width('75%')
               .height(50)
               .margin(15)
               .fontSize(20)
               .fontWeight(FontWeight.Bold)
               .onClick(() => {
                // Construct an appFreezeWarning scenario in the button click function to trigger an App Freeze warning event.
                 const t = Date.now();
                 while (Date.now() - t <= 6500) {}
               })
           }.width('100%')
         }
         .height('100%')
         .width('100%')
       }
     }
   ```

9. Run the app project in DevEco Studio, and then click the **appFreezeWarning** button in the app UI to trigger an app freeze warning event.

### Verifying That the Observer Has Received App Freeze Warning Events

After about one minute, the **Log** window displays the logs generated when the system event data is processed:

```text
HiAppEvent eventInfo.domain=OS
HiAppEvent eventInfo.name=APPFREEZE_WARNING
HiAppEvent eventInfo.eventType=1
HiAppEvent eventInfo.params.time=1776946769389
HiAppEvent eventInfo.params.foreground=1
HiAppEvent eventInfo.params.app_running_unique_id=382145346984526931478
HiAppEvent eventInfo.params.bundle_version=1.0.0
HiAppEvent eventInfo.params.bundle_version_code=1000000
HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
HiAppEvent eventInfo.params.process_name=com.example.myapplication
HiAppEvent eventInfo.params.pid=1587
HiAppEvent eventInfo.params.uid=20010043
HiAppEvent eventInfo.params.exception={""message":"App main thread is not response!Main handler dump start time: 2026-04-23 20:19:28.903","name":"THREAD_BLOCK_3S"}
HiAppEvent eventInfo.params.hilog.size=6
HiAppEvent eventInfo.params.event_handler.size=16
HiAppEvent eventInfo.params.peer_binder.size=0
HiAppEvent eventInfo.params.threads.size=28
HiAppEvent eventInfo.params.memory={"rss":161080,"sys_avail_mem":1361464,"sys_free_mem":796232,"sys_total_mem":1992340,"vm_heap_total_size":"9961472","vm_heap_used_size":"7596424","vss":56960692}
HiAppEvent eventInfo.params.process_life_time=18
```

### Removing and Destroying the Event Watcher

1. Remove the event watcher.

   ```c++
   static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
       // Stop the watcher from listening for events.
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