# Subscribing to Task Execution Timeout Events (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=f319e3e62d6356bf78f31e2e8f7ba3927caddf1e translatedAt=2026-07-29T10:50:43.764Z pushedAt=2026-07-29T12:40:37.025Z -->

## Overview

This section describes how to use the C/C++ APIs provided by HiAppEvent to subscribe to task execution timeout events. For detailed API usage instructions (parameter constraints, value ranges, etc.), refer to [hiappevent.h](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md).

## Available APIs

| API| Description|
| -------- | -------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher \*watcher) | Adds a watcher to listen for application events.|
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher \*watcher) | Removes a watcher for the specified application events.|

## How to Develop

### Adding an Event Watcher

The following describes how to subscribe to the freeze event triggered by a button click.

1. Obtain the **jsoncpp** file on which the sample project depends. Click [HiAppEvent Sample Project EventSub](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub) and **click Download the directory** to download the EventSub project file.

2. In DevEco Studio, create a Native C++ project. Copy the jsoncpp library files (the **entry/libs** and **entry/src/main/cpp/thirdparty** folders) from the extracted EventSub project to the new project. The directory structure of the new project is as follows:

   ```yml
   entry:
     libs:    // Folder for storing the third-party library associated with jsoncpp.
     src:
       main:
         cpp:
           thirdparty:
             jsoncpp:    // Folder for storing the third-party library associated with jsoncpp.
           types:
             libentry:
               - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
         ets:
           entryability:
             - EntryAbility.ets
           pages:
             - Index.ets
   ```

The source code corresponding to the jsoncpp library file in this sample project is derived from [the third-party open-source library JsonCpp](https://codeload.github.com/open-source-parsers/jsoncpp/tar.gz/refs/tags/1.9.6).

3. Edit the **CMakeLists.txt** file under **entry > src > main > cpp** in the project to add the required source files and dynamic libraries.

   ```cmake
   add_library(entry SHARED napi_init.cpp)
   # Add **libhiappevent_ndk.z.so**, **libhilog_ndk.z.so** (log output), and **libohhicollie.so** (HiCollie detection).
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so libhiappevent_ndk.z.so)

   set(GZ_FILE "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/jsoncpp/src/jsoncpp-1.9.6.tar.gz")
   set(DEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../build")
   # Check whether the entry/build directory exists.
   execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${DEST_DIR})
   # Decompress jsoncpp-1.9.6.tar.gz to entry/build to obtain the directory of the jsoncpp header file.
   execute_process(COMMAND tar -xzf ${GZ_FILE} -C ${DEST_DIR}
       WORKING_DIRECTORY ${DEST_DIR})

   # Add the third-party library libjsoncpp.so (used to parse JSON strings in subscription events).
   target_link_libraries(entry PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/jsoncpp/${OHOS_ARCH}/lib/libjsoncpp.so)
   target_include_directories(entry PRIVATE ${DEST_DIR}/jsoncpp-1.9.6/include/json)
   ```

4. Edit the **napi_init.cpp** file under **entry > src > main > cpp** in the project to import the required header files and define `LOG_TAG`.

   <!-- @[EventSub_napi_Header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->     

   ``` C++
   #include "napi/native_api.h"
   // Adapt the path for referencing json.h based on the location of the third-party library jsoncpp in the project.
   #include "../../../build/jsoncpp-1.9.6/include/json/json.h"
   #include "hiappevent/hiappevent.h"
   #include "hiappevent/hiappevent_param.h"
   #include "hilog/log.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

5. Subscribe to system events.

   - Watcher of the **onReceive** type.

Edit the **napi_init.cpp** file under **entry > src > main > cpp** in the project to define the functions related to the watcher of the **onReceive** type:

   <!-- @[App_Hicollie_Watcher_R_ptr](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   // Define a variable to cache the pointer to the created watcher.
   static HiAppEvent_Watcher *appHicollieWatcherR;
   ```

   <!-- @[App_Hicollie_OnReceive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) --> 

   ``` C++
   static void OnReceiveAppHicollie(const struct HiAppEvent_AppEventGroup *appEventGroups, int i, int j)
   {
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
               auto externalCallbackLog = params["external_callback_log"].asString();
               OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
               OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d", foreground);
               OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s",
                   bundleVersion.c_str());
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
               OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_callback_log=%{public}s",
                   externalCallbackLog.c_str());
           }
       }
   }
   
   static void AppHicollieOnReceive(const char *domain, const struct HiAppEvent_AppEventGroup *appEventGroups,
       uint32_t groupLen)
   {
       for (int i = 0; i < groupLen; ++i) {
           for (int j = 0; j < appEventGroups[i].infoLen; ++j) {
               OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s",
                   appEventGroups[i].appEventInfos[j].domain);
               OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s",
                   appEventGroups[i].appEventInfos[j].name);
               OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d",
                   appEventGroups[i].appEventInfos[j].type);
               OnReceiveAppHicollie(appEventGroups, i, j);
           }
       }
   }
   
   static napi_value RegisterAppHicollieWatcherR(napi_env env, napi_callback_info info)
   {
       // Set the watcher name. The system identifies different watchers based on their names.
       appHicollieWatcherR = OH_HiAppEvent_CreateWatcher("appHicollieWatcherR");
       // Set the event to watch to EVENT_APP_HICOLLIE.
       const char *names[] = {EVENT_APP_HICOLLIE};
       // Add the events to watch, for example, system events.
       OH_HiAppEvent_SetAppEventFilter(appHicollieWatcherR, DOMAIN_OS, 0, names, 1);
       // Set the implemented callback. After receiving the event, the watcher immediately triggers the OnReceive callback.
       OH_HiAppEvent_SetWatcherOnReceive(appHicollieWatcherR, AppHicollieOnReceive);
       // Add a watcher to listen for the specified event.
       OH_HiAppEvent_AddWatcher(appHicollieWatcherR);
       return {};
   }
   ```

   - Watcher of the **onTrigger** type:

Edit the **napi_init.cpp** file under **entry > src > main > cpp** in the project to define the functions related to the watcher of the **onTrigger** type:

   <!-- @[App_Hicollie_Watcher_T_ptr](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   // Define a variable to cache the pointer to the created watcher.
   static HiAppEvent_Watcher *appHicollieWatcherT;
   ```

   <!-- @[App_Hicollie_Trigger](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) --> 

   ``` C++
   // Implement the callback function used to return the listened events. The content pointed to by the events pointer is valid only in this function.
   static void AppHicollieOnTake(const char *const *events, uint32_t eventLen)
   {
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
                   auto externalCallbackLog = eventInfo["external_callback_log"].asString();
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d", foreground);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s",
                       bundleVersion.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.process_name=%{public}s",
                       processName.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uuid=%{public}s", uuid.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s", exception.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d", hilogSize);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.peer_binder.size=%{public}d", peerBindSize);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s",
                       externalLog.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d", logOverLimit);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_callback_log=%{public}s",
                       externalCallbackLog.c_str());
               }
           }
       }
   }
   
   // Implement the subscription callback function to apply custom processing to the obtained event logging data.
   static void AppHicollieOnTrigger(int row, int size)
   {
       // After the callback is received, obtain the specified number of received events.
       OH_HiAppEvent_TakeWatcherData(appHicollieWatcherT, row, AppHicollieOnTake);
   }
   
   static napi_value RegisterAppHicollieWatcherT(napi_env env, napi_callback_info info)
   {
       // Set the watcher name. The system identifies different watchers based on their names.
       appHicollieWatcherT = OH_HiAppEvent_CreateWatcher("appHicollieWatcherT");
       // Set the event to watch to EVENT_APP_HICOLLIE.
       const char *names[] = {EVENT_APP_HICOLLIE};
       // Add the events to watch, for example, system events.
       OH_HiAppEvent_SetAppEventFilter(appHicollieWatcherT, DOMAIN_OS, 0, names, 1);
       // Set the implemented callback function. The callback function will be triggered when the conditions set by OH_HiAppEvent_SetTriggerCondition are met.
       OH_HiAppEvent_SetWatcherOnTrigger(appHicollieWatcherT, AppHicollieOnTrigger);
       // Set the conditions for triggering the subscription callback. For example, trigger this onTrigger callback when the number of new event logs is 1.
       OH_HiAppEvent_SetTriggerCondition(appHicollieWatcherT, 1, 0, 0);
       // Add a watcher to listen for the specified event.
       OH_HiAppEvent_AddWatcher(appHicollieWatcherT);
       return {};
   }
   ```

6. Add the **TestHiCollieTimerNdk** function.

Edit the **napi_init.cpp** file under **entry > src > main > cpp** in the project to add the `TestHiCollieTimerNdk` function, which constructs a task execution timeout event:

   <!-- @[Hicollie_Set_Timer_h](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   #include <unistd.h>
   #include "hicollie/hicollie.h"
   ```

   <!-- @[Hicollie_Set_Timer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   // Define the callback function.
   void CallBack(void*)
   {
       OH_LOG_INFO(LogType::LOG_APP, "HiCollieTimerNdk CallBack");  // Logs are printed in the callback.
   }
   
   static napi_value TestHiCollieTimerNdk(napi_env env, napi_callback_info info)
   {
       int id;
       // Set HiCollieTimer parameters (timer task name, timeout interval, callback, callback parameters, and behavior after timeout).
       HiCollie_SetTimerParam param = {"testTimer", 1, CallBack, nullptr, HiCollie_Flag::HICOLLIE_FLAG_LOG};
       HiCollie_ErrorCode errorCode = OH_HiCollie_SetTimer(param, &id);  // Register a HiCollieTimer function to execute a one-off timeout detection task.
       if (errorCode == HICOLLIE_SUCCESS) {  // The HiCollieTimer task is successfully registered.
           OH_LOG_INFO(LogType::LOG_APP, "HiCollieTimer taskId: %{public}d", id); // Print the task ID.
           sleep (2); // Simulate a time-consuming function to block the thread for 2s.
           OH_HiCollie_CancelTimer (id); // Cancel the registered timer based on the ID.
       }
       return nullptr;
   }
   ```

7. In the **napi_init.cpp** file, register **RegisterWatcher** and **TestHiCollieTimerNdk** as ArkTS APIs.

Edit the **napi_init.cpp** file under **entry > src > main > cpp** in the project. In the `desc[]` array within the `Init` function, register `TestHiCollieTimerNdk`, `RegisterAppHicollieWatcherR`, and `RegisterAppHicollieWatcherT` as ArkTS APIs.

   <!-- @[test_hicollie_timer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   // Register TestHiCollieTimerNdk as an ArkTS API.
   { "TestHiCollieTimerNdk", nullptr, TestHiCollieTimerNdk, nullptr, nullptr, nullptr, napi_default, nullptr },
   ```

   <!-- @[register_app_hicollie_watcherR](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   { "RegisterAppHicollieWatcherR", nullptr, RegisterAppHicollieWatcherR, nullptr, nullptr, nullptr,
       napi_default, nullptr },
   ```

   <!-- @[register_app_hicollie_watcherT](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   { "RegisterAppHicollieWatcherT", nullptr, RegisterAppHicollieWatcherT, nullptr, nullptr, nullptr,
       napi_default, nullptr },
   ```

Edit the **Index.ets** file under **entry > src > main > cpp > types > libentry** in the project to define the ArkTS APIs:

   <!-- @[test_hicollie_timer_Index.d.ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/types/libentry/Index.d.ts) -->

   ``` TypeScript
   export const TestHiCollieTimerNdk: () => void;
   ```

   <!-- @[Register_AppHicollie_WatcherR.d.ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/types/libentry/Index.d.ts) -->

   ``` TypeScript
   export const RegisterAppHicollieWatcherR: () => void;
   ```

   <!-- @[Register_AppHicollie_WatcherT.d.ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/types/libentry/Index.d.ts) -->

   ``` TypeScript
   export const RegisterAppHicollieWatcherT: () => void;
   ```

8. Edit the **EntryAbility.ets** file under **entry > src > main > ets > entryability** in the project to add API calls in the `onCreate()` function.

   <!-- @[EventSub_Capi_Header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/ets/entryability/EntryAbility.ets) -->

   ``` TypeScript
   import testNapi from 'libentry.so';
   ```

   <!-- @[Register_AppHicollie_WatcherR](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/ets/entryability/EntryAbility.ets) -->

   ``` TypeScript
   // Add an API in onCreate() to register the system event watcher R during startup.
   testNapi.RegisterAppHicollieWatcherR();
   ```

   <!-- @[Register_AppHicollie_WatcherT](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/ets/entryability/EntryAbility.ets) -->

   ``` TypeScript
   // Add an API in onCreate() to register the system event watcher T during startup.
   testNapi.RegisterAppHicollieWatcherT();
   ```

9. Edit the **Index.ets** file under **entry > src > main > ets > pages** in the project to add a button that triggers the task execution timeout event.

   <!-- @[EventSub_Index_Capi_Header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import testNapi from 'libentry.so';
   ```

Edit the **Index.ets** file under **entry > src > main > ets > pages** in the project to add a button on the page that triggers the `TestHiCollieTimerNdk` method.

   <!-- @[hicollie_timer_ndk_Button](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Add a click event to trigger the TestHiCollieTimerNdk method.
   Button('TestHiCollieTimerNdk')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('80%')
     .height('5%')
     .onClick(() => {
       testNapi.TestHiCollieTimerNdk();
     })
   ```

10. In DevEco Studio, click the **Run** button to run the project. Then, click the **TestHiCollieTimerNdk** button to trigger a task execution timeout event.

### Verifying the Subscription

The application crashes. After restarting the application, you can view the following event information in the **Log** window.

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
   HiAppEvent eventInfo.params.memory={"pss":0,"rss":124668,"sys_avail_mem":2220032,"sys_free_mem":526680,"sys_total_mem":11692576,"vss":4238700}
   HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_HICOLLIE_1740993644458_26215.log"]
   HiAppEvent eventInfo.params.log_over_limit=0
   HiAppEvent eventInfo.params.external_callback_log=THREAD_BLOCK_3S:log3s THREAD_BLOCK_6S:log6s
   ```

### Removing and Destroying an Event Watcher

1. Remove the event watcher.

   <!-- @[APP_Hicollie_RemoveWatcher](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) --> 

   ``` C++
   static napi_value RemoveWatcher(napi_env env, napi_callback_info info)
   {
       // Remove the watcher.
       // ···
       OH_HiAppEvent_RemoveWatcher(appHicollieWatcherR);
       OH_HiAppEvent_RemoveWatcher(appHicollieWatcherT);
       // ···
       return {};
   }
   ```

2. Destroy the event watcher.

   <!-- @[APP_Hicollie_DestroyWatcher](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) --> 

   ``` C++
   static napi_value DestroyWatcher(napi_env env, napi_callback_info info)
   {
       // Destroy the created watcher and set eventWatcher to nullptr.
       // ···
       OH_HiAppEvent_DestroyWatcher(appHicollieWatcherR);
       OH_HiAppEvent_DestroyWatcher(appHicollieWatcherT);
       appHicollieWatcherR = nullptr;
       appHicollieWatcherT = nullptr;
       // ···
       return {};
   }
   ```