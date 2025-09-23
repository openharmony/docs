# Subscribing to Task Execution Timeout Events (C/C++)

## Overview

This topic describes how to use the C/C++ APIs provided by HiAppEvent to subscribe to task execution timeout events. For details (such as parameter restrictions and value ranges), see [hiappevent.h](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md).

## Available APIs

| API| Description|
| -------- | -------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher \*watcher) | Adds a watcher to listen for application events.|
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher \*watcher) | Removes a watcher for the specified application events.|

## How to Develop

### Adding an Event Watcher

The following describes how to subscribe to the freeze event triggered by a button click.

1. Obtain the **jsoncpp.cpp**, **json.h**, and **json-forwards.h** files by referring to **Using JsonCpp in your project** in [the third-party open-source library JsonCpp](https://github.com/open-source-parsers/jsoncpp).

2. Create a native C++ project and import the preceding files to the project. The directory structure is as follows:

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

3. In the **CMakeLists.txt** file, add the source file and dynamic libraries.

   ```cmake
   # Add the jsoncpp.cpp file, which is used to parse the JSON strings in the subscription events.
   add_library(entry SHARED napi_init.cpp jsoncpp.cpp)
   # Add **libhiappevent_ndk.z.so**, **libhilog_ndk.z.so** (log output), and **libohhicollie.so** (HiCollie detection).
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so libhiappevent_ndk.z.so)
   ```

4. Import the dependencies to the **napi_init.cpp** file, and define **LOG_TAG**.

   ```c++
   #include "napi/native_api.h"
   #include "json/json.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"
   #include <thread>
   #include <unistd.h>
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

5. Subscribe to system events.

   - Watcher of the **onReceive** type.

   In the **napi_init.cpp** file, define the functions related to the watcher of the **onReceive** type.

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
                   strcmp(appEventGroups[i].appEventInfos[j].name, EVENT_APP_HICOLLIE) == 0) {
                   Json::Value params;
                   Json::Reader reader(Json::Features::strictMode());
                   Json::FastWriter writer;
                   if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                       auto time = params["time"].asInt64();
                       auto foreground = params["foreground"].asBool();
                       auto bundleVersion = params["bundle_version"].asString();
                       auto processName = params["process_name"].asString();
                       auto pid = params["pid"].asInt();
                       auto uid = params["uid"].asInt();
                       auto uuid = params["uuid"].asString();
                       auto exception = writer.write(params["exception"]);
                       auto hilogSize = params["hilog"].size();
                       auto peerBindSize =  params["peer_binder"].size();
                       auto memory =  writer.write(params["memory"]);
                       auto externalLog = writer.write(params["external_log"]);
                       auto logOverLimit = params["log_over_limit"].asBool();
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d", foreground);
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.process_name=%{public}s", processName.c_str());
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uuid=%{public}s", uuid.c_str());
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s", exception.c_str());
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d", hilogSize);
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.peer_binder.size=%{public}d", peerBindSize);
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
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
       // Set the event to watch to EVENT_APP_HICOLLIE.
       const char *names[] = {EVENT_APP_HICOLLIE};
       // Add the events to watch, for example, system events.
       OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
       // Set the implemented callback. After receiving the event, the watcher immediately triggers the OnReceive callback.
       OH_HiAppEvent_SetWatcherOnReceive(systemEventWatcher, OnReceive);
       // Add a watcher to listen for the specified event.
       OH_HiAppEvent_AddWatcher(systemEventWatcher);
       return {};
   }
   ```

   - Watcher of the **onTrigger** type:

   In the **napi_init.cpp** file, define the functions related to the watcher of the **OnTrigger** type.

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
               if (domain ==  DOMAIN_OS && name == EVENT_APP_HICOLLIE) {
                   auto time = eventInfo["time"].asInt64();
                   auto foreground = eventInfo["foreground"].asBool();
                   auto bundleVersion = eventInfo["bundle_version"].asString();
                   auto processName = eventInfo["process_name"].asString();
                   auto pid = eventInfo["pid"].asInt();
                   auto uid = eventInfo["uid"].asInt();
                   auto uuid = eventInfo["uuid"].asString();
                   auto exception = writer.write(eventInfo["exception"]);
                   auto hilogSize = eventInfo["hilog"].size();
                   auto peerBindSize =  eventInfo["peer_binder"].size();
                   auto memory =  writer.write(eventInfo["memory"]);
                   auto externalLog = writer.write(eventInfo["external_log"]);
                   auto logOverLimit = eventInfo["log_over_limit"].asBool();
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d", foreground);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.process_name=%{public}s", processName.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uuid=%{public}s", uuid.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s", exception.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d", hilogSize);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.peer_binder.size=%{public}d", peerBindSize);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
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
        // Set the event to watch to EVENT_APP_HICOLLIE.
        const char *names[] = {EVENT_APP_HICOLLIE};
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

6. Add the **TestHiCollieTimerNdk** function.

   In the **napi_init.cpp** file, add the **TestHiCollieTimerNdk** function to construct a task execution timeout event.

   ```c++
   // Import the hicollie.h file.
   #include "hicollie/hicollie.h"
   static napi_value TestHiCollieTimerNdk(napi_env env, napi_callback_info exports)
   {
       // Define the task execution timeout ID.
       int id;  
       // Define the task timeout detection parameters. When a task times out for 1s, logs are generated.
       HiCollie_SetTimerParam param = {"testTimer", 1, nullptr, nullptr, HiCollie_Flag::HICOLLIE_FLAG_LOG};
       // Set the detection.
       HiCollie_ErrorCode errorCode = OH_HiCollie_SetTimer(param, &id);
       if (errorCode == HICOLLIE_SUCCESS) {
           OH_LOG_INFO(LogType::LOG_APP, "Timer Id is %{public}d", id);
           // Construct a timeout interval of 2s.
           sleep(2);
           OH_HiCollie_CancelTimer(id);
       }
       return nullptr; 
   }
   ```

7. In the **napi_init.cpp** file, register **RegisterWatcher** and **TestHiCollieTimerNdk** as ArkTS APIs.

    

   ```c++
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "RegisterWatcher", nullptr, RegisterWatcher, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "TestHiCollieTimerNdk", nullptr, TestHiCollieTimerNdk, nullptr, nullptr, nullptr, napi_default, nullptr },
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END
   static napi_module demoModule = {
       .nm_version = 1,
       .nm_flags = 0,
       .nm_filename = nullptr,
       .nm_register_func = Init,
       .nm_modname = "entry",
       .nm_priv = ((void*)0),
       .reserved = { 0 },
   };
   extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
   {
       napi_module_register(&demoModule);
   }
   ```

   In the **index.d.ts** file, define the ArkTS API.

   ```typescript
   export const RegisterWatcher: () => void;
   export const TestHiCollieTimerNdk: () => void;
   ```

8. In the **EntryAbility.ets** file, add the following API to **onCreate()**.

   ```typescript
   // Import the dependent module.
   import testNapi from 'libentry.so'
   
   // Add the API to onCreate().
   // Register the system event watcher at startup.
   testNapi.RegisterWatcher();
   ```

9. In the **Index.ets** file, add a button to trigger the task execution timeout event.

   ```typescript
   import testNapi from 'libentry.so';
   @Entry
     @Component
     struct Index {
       @State message: string = 'Hello World';
      
       build() {
         Row() {
           Column() {
             Button("TestHiCollieTimerNdk")
               .fontSize(50)
               .fontWeight(FontWeight.Bold)
               .onClick(testNapi.TestHiCollieTimerNdk);  // Add a click event to trigger the TestHiCollieTimerNdk method.
           }
           .width('100%')
         }
         .height('100%')
       }
   }
   ```

10. In DevEco Studio, click the **Run** button to run the project. Then, click the **testHiCollieTimerNdk** button to trigger a task execution timeout event.

### Verifying the Subscription

1. The application crashes. After restarting the application, you can view the following event information in the **Log** window.

   ```text
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_HICOLLIE
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1740993639620
   HiAppEvent eventInfo.params.foreground=1
   HiAppEvent eventInfo.params.bundle_version=1.0.0
   HiAppEvent eventInfo.params.process_name=com.example.myapplication
   HiAppEvent eventInfo.params.pid=26251
   HiAppEvent eventInfo.params.uid=20020172
   HiAppEvent eventInfo.params.uuid=4e5d7d0e18f5d6d84cf4f0c9e80d66d0b646c1cc2343d3595f07abb0d3547feb
   HiAppEvent eventInfo.params.exception={"message":"","name":"APP_HICOLLIE"}
   HiAppEvent eventInfo.params.hilog.size=77
   HiAppEvent eventInfo.params.peer_binder.size=18
   HiAppEvent eventInfo.params.threads.size=28
   HiAppEvent eventInfo.params.memory={"pss":0,"rss":124668,"sys_avail_mem":2220032,"sys_free_mem":526680,"sys_total_mem":11692576,"vss":4238700}
   HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_HICOLLIE_1740993644458_26215.log"]
   HiAppEvent eventInfo.params.log_over_limit=0
   ```

### Removing and Destroying an Event Watcher

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
