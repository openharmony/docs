# Subscribing to Crash Events (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @chenshi51-->
<!--Designer: @Maplestory91-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=e045b2c3e44ea3985eed61bc2f7a3828310d8c76 translatedAt=2026-07-31T01:25:56.948Z pushedAt=2026-07-31T02:43:51.981Z -->

## Overview

This section describes how to use the C/C++ APIs provided by HiAppEvent to subscribe to app crash events. For detailed usage instructions, refer to [hiappevent.h](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md).

> **NOTE**
>
> Use the C/C++ APIs to subscribe to the **JsError** and **NativeCrash** events.

## Available APIs

| API| Description|
| -------- | -------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher \*watcher) | Adds a watcher to listen for application events.|
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher \*watcher) | Removes a watcher to unsubscribe from application events.|

## How to Develop

### Adding an Event Watcher

After the application starts, add an event watcher before any service logic runs to ensure subscription to crash events. Otherwise, a crash may cause the application to exit, leaving the subscription uncompleted.

The following example describes how to subscribe to a crash event triggered by button clicking.

1. Obtain the **jsoncpp** file on which the sample project depends. Click [HiAppEvent Sample Project EventSub](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub) and **click Download the directory** to download the EventSub project file.

2. Create a Native C++ template project in DevEco Studio, and import the above files into the new project. The directory structure is as follows.

   ```yml
   entry:
     libs:    // Folder for storing the third-party library associated with jsoncpp.
     src:
       main:
         cpp:
           - thirdparty:
               jsoncpp:    // Folder for storing the third-party library associated with jsoncpp.
           - types:
               libentry:
                 - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
         ets:
           - entryability:
               - EntryAbility.ets
           - pages:
               - Index.ets
   ```

   The source code corresponding to the jsoncpp library file in this sample project is derived from [the third-party open-source library JsonCpp](https://codeload.github.com/open-source-parsers/jsoncpp/tar.gz/refs/tags/1.9.6).

3. In the **CMakeLists.txt** file, add the source file and dynamic libraries.

   ```cmake
   add_library(entry SHARED napi_init.cpp)
   # Add libhiappevent_ndk.z.so and libhilog_ndk.z.so (log output). 
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libhiappevent_ndk.z.so)
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

4. In the **napi_init.cpp** file, import the dependency files and define **LOG_TAG**.

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

   - Watcher of the onReceive type:

      In the **napi_init.cpp** file, define **onReceive()** as follows:

      <!-- @[Sys_Crash_Crash_OnReceive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

      ``` C++
      static void OnReceiveCrashEvent(const char *domain, const struct HiAppEvent_AppEventGroup *appEventGroups,
          uint32_t groupLen)
      {
          for (int i = 0; i < groupLen; ++i) {
              for (int j = 0; j < appEventGroups[i].infoLen; ++j) {
                  const struct HiAppEvent_AppEventInfo &appEventInfo = appEventGroups[i].appEventInfos[j];
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", appEventInfo.domain);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", appEventInfo.name);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", appEventInfo.type);
                  if (strcmp(appEventInfo.domain, DOMAIN_OS) != 0 || strcmp(appEventInfo.name, EVENT_APP_CRASH) != 0) {
                      continue;
                  }
                  Json::Value params;
                  Json::Reader reader(Json::Features::strictMode());
                  Json::FastWriter writer;
                  if (reader.parse(appEventInfo.params, params)) {
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld",
                          params["time"].asInt64());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.crash_type=%{public}s",
                          params["crash_type"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d",
                          params["foreground"].asBool());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.release_type=%{public}s",
                          params["release_type"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.cpu_abi=%{public}s",
                          params["cpu_abi"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.app_running_unique_id=%{public}s",
                          params["app_running_unique_id"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s",
                          params["bundle_version"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s",
                          params["bundle_name"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", params["pid"].asInt());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", params["uid"].asInt());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uuid=%{public}s",
                          params["uuid"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s",
                          writer.write(params["exception"]).c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d",
                          params["hilog"].size());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.process_life_time=%{public}d",
                          params["process_life_time"].asInt());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s",
                          writer.write(params["memory"]).c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s",
                          writer.write(params["external_log"]).c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d",
                          params["log_over_limit"].asBool());
                  }
              }
          }
      }
      
      // Define a variable to cache the pointer to the created watcher.
      static HiAppEvent_Watcher *systemEventWatcherR;
      
      static napi_value RegisterWatcherCrashEvent(napi_env env, napi_callback_info info)
      {
          // Set the watcher name. The system identifies different watchers based on their names.
          systemEventWatcherR = OH_HiAppEvent_CreateWatcher("AppCrashWatcherR");
          // Set the event name for subscription to EVENT_APP_CRASH (the crash event).
          const char *names[] = {EVENT_APP_CRASH};
          // Add the events to watch, for example, system events.
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcherR, DOMAIN_OS, 0, names, 1);
          // Set the implemented callback. After receiving the event, the watcher immediately triggers the OnReceiveCrashEvent callback.
          OH_HiAppEvent_SetWatcherOnReceive(systemEventWatcherR, OnReceiveCrashEvent);
          // Add a watcher to listen for the specified event.
          OH_HiAppEvent_AddWatcher(systemEventWatcherR);
      
          // 1. Create the configuration object.
          HiAppEvent_Config* config = OH_HiAppEvent_CreateConfig();
      
          // 2. Set configuration parameters.
          // Enable extended register memory printing.
          OH_HiAppEvent_SetConfigItem(config, OH_APP_CRASH_PARAM_EXTEND_PC_LR_PRINTING, "true");
      
          // Set the log truncation size to 2 MB.
          OH_HiAppEvent_SetConfigItem(config, OH_APP_CRASH_PARAM_LOG_FILE_CUTOFF_SZ_BYTES, "2097152");
      
          // Enable simplified VMA mapping information printing.
          OH_HiAppEvent_SetConfigItem(config, OH_APP_CRASH_PARAM_SIMPLIFY_VMA_PRINTING, "true");
      
          // Enable app log concatenation.
          OH_HiAppEvent_SetConfigItem(config, OH_APP_CRASH_PARAM_MERGE_CPPCRASH_APP_LOG, "true");
      
          // Enable minidump for native crash scenarios.
          OH_HiAppEvent_SetConfigItem(config, OH_APP_CRASH_PARAM_COLLECT_MINIDUMP, "true");
      
          // 3. Apply the configuration to the EVENT_APP_CRASH event.
          int ret = OH_HiAppEvent_SetEventConfig(EVENT_APP_CRASH, config);
          if (ret == HIAPPEVENT_SUCCESS) {
              OH_LOG_INFO(LogType::LOG_APP, "Successfully set APP_CRASH event configurations.");
          }
      
          // 4. Destroy the configuration object.
          OH_HiAppEvent_DestroyConfig(config);
      
          return {};
      }
      ```

   - Watcher of the **onTrigger** type:

      Define **OnTrigger()** in the **napi_init.cpp** file.

      <!-- @[Sys_Crash_Event_OnTrigger](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

      ``` C++
      // Implement the callback function used to return the listened events. The content pointed to by the events pointer is valid only in this function.
      static void OnTakeCrash(const char *const *events, uint32_t eventLen)
      {
          Json::Reader reader(Json::Features::strictMode());
          Json::FastWriter writer;
          for (int i = 0; i < eventLen; ++i) {
              Json::Value eventInfo;
              if (reader.parse(events[i], eventInfo)) {
                  auto domain =  eventInfo["domain_"].asString();
                  auto name = eventInfo["name_"].asString();
                  auto type = eventInfo["type_"].asInt();
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.WatcherType=OnTrigger");
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", domain.c_str());
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", name.c_str());
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", type);
                  if (domain ==  DOMAIN_OS && name == EVENT_APP_CRASH) {
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld",
                          eventInfo["time"].asInt64());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.crash_type=%{public}s",
                          eventInfo["crash_type"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d",
                          eventInfo["foreground"].asBool());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.release_type=%{public}s",
                          eventInfo["release_type"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.cpu_abi=%{public}s",
                          eventInfo["cpu_abi"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.app_running_unique_id=%{public}s",
                          eventInfo["app_running_unique_id"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s",
                          eventInfo["bundle_version"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s",
                          eventInfo["bundle_name"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", eventInfo["pid"].asInt());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", eventInfo["uid"].asInt());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uuid=%{public}s",
                          eventInfo["uuid"].asString().c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s",
                          writer.write(eventInfo["exception"]).c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d",
                          eventInfo["hilog"].size());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.process_life_time=%{public}d",
                          eventInfo["process_life_time"].asInt());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s",
                          writer.write(eventInfo["memory"]).c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s",
                          writer.write(eventInfo["external_log"]).c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d",
                          eventInfo["log_over_limit"].asBool());
                  }
              }
          }
      }
      
      // Define a variable to cache the pointer to the created watcher.
      static HiAppEvent_Watcher *systemEventWatcherT;
      
      // Implement the subscription callback function to apply custom processing to the obtained event logging data.
      static void OnTriggerCrash(int row, int size)
      {
          // After the callback is received, obtain the specified number of received events.
          OH_HiAppEvent_TakeWatcherData(systemEventWatcherT, row, OnTakeCrash);
      }
      
      static napi_value RegisterWatcherClickCrash(napi_env env, napi_callback_info info)
      {
          // Set the watcher name. The system identifies different watchers based on their names.
          systemEventWatcherT = OH_HiAppEvent_CreateWatcher("AppCrashWatcherT");
          // Set the event to watch to EVENT_APP_CRASH.
          const char *names[] = {EVENT_APP_CRASH};
          // Add the events to watch, for example, system events.
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcherT, DOMAIN_OS, 0, names, 1);
          // Set the implemented callback function. The callback function will be triggered when the conditions set by OH_HiAppEvent_SetTriggerCondition are met.
          OH_HiAppEvent_SetWatcherOnTrigger(systemEventWatcherT, OnTriggerCrash);
          // Set the conditions for triggering the subscription callback. For example, trigger this OnTriggerCrash callback when the number of new event logs is 1.
          OH_HiAppEvent_SetTriggerCondition(systemEventWatcherT, 1, 0, 0);
          // Add a watcher to listen for the specified event.
          OH_HiAppEvent_AddWatcher(systemEventWatcherT);
          return {};
      }
      ```

6. Register **RegisterWatcher** as an ArkTS API.

   In the **napi_init.cpp** file, register **RegisterWatcher** as an ArkTS API.

    <!-- @[Sys_Crash_Event_C++_Init](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

    ``` C++
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            // ···
            { "registerWatcherCrashEvent", nullptr, RegisterWatcherCrashEvent, nullptr, nullptr, nullptr, napi_default,
                nullptr },
            { "registerWatcherClickCrash", nullptr, RegisterWatcherClickCrash, nullptr, nullptr, nullptr, napi_default,
                nullptr },
            // ···
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    ```

   Define the ArkTS API in the **index.d.ts** file.

    <!-- @[Sys_Crash_Event_C++_Index.d.ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/types/libentry/Index.d.ts) -->

    ``` TypeScript
    export const registerWatcherClickCrash: () => void;
    export const registerWatcherCrashEvent: () => void;
    ```

7. In the **EntryAbility.ets** file, add the following API to **onCreate()**.

    <!-- @[Sys_Crash_Event_Call_Capi_Function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/ets/entryability/EntryAbility.ets) -->

    ``` TypeScript
    // Add the C API call in onCreate().
    // Register the crash event watcher at startup.
    testNapi.registerWatcherClickCrash();
    // Register the button click event watcher at startup.
    testNapi.registerWatcherCrashEvent();
    ```

8. In the **Index.ets** file, add a button to trigger a crash event.

    - Construct a **JsError**

    <!-- @[JsError_CrashEvent_Button](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    Button('JsError')
      .type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .backgroundColor('#0D9FFB')
      .width('80%')
      .height('5%')
      .onClick(() => {
        // Construct a scenario in onClick() to trigger a crash event.
        JSON.parse('');
      })
    ```

    - Construct a crash of the MergeLogNativeCrash type that merges app logs

      In the **entry/src/main/ets/pages/Index.ets** file, import the dependent modules. The sample code is as follows:

      <!-- @[Native_CrashEvent_Log_Header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/ets/pages/Index.ets) -->

      ``` TypeScript
      import { fileIo } from '@kit.CoreFileKit';
      ```

      In the **entry/src/main/ets/pages/index.ets** file, add the **appCrash** button and construct a scenario for triggering a crash event in **onClick()**. The sample code is as follows:

      <!-- @[Native_CrashEvent_Log](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/ets/pages/Index.ets) -->

      ``` TypeScript
      Button('MergeLogNativeCrash')
        .type(ButtonType.Capsule)
        .margin({
          top: 20
        })
        .backgroundColor('#0D9FFB')
        .width('80%')
        .height('5%')
        .onClick(() => {
          // Simulate creating an applog, assuming the app package name is com.samples.eventsub.
          let filePath: string = "/data/storage/el2/log/com.samples.eventsub_CppCrash_AppMerge.log";
          let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
          let str: string = "only test for merge app log!";
      
          let writeLen = fileIo.writeSync(file.fd, str);
          console.info("hiappevent write data to file succeed and size is:" + writeLen);
          fileIo.closeSync(file);
      
          // Construct a crash scenario in the button click function to trigger an app crash event.
          testNapi.testNullptr();
        })
      ```

9. Click the **Run** button to start the app project. In the app UI, tap the **JsError** or **MergeLogNativeCrash** button to trigger a crash event. The system generates crash logs and triggers the callback.

> **NOTE**
>
> **JsError** triggers callback by collecting fault information in the process, which is fast. **NativeCrash** collects fault information outside the process. The average time is about 2 seconds, depending on the number of service threads and inter-process communication. After the crash event is subscribed, the fault information is reported asynchronously after the collection is complete, and the current service is not blocked.

### Verifying the Subscription

The callback time of a crash event varies depending on whether the crash exception is captured by the application proactively. You need to verify whether the crash event is subscribed to in different scenarios.

**Application not proactively captures crash events**

If the application does not proactively capture the crash exception, the application will exit after the system handles the crash. When the application restarts, HiAppEvent reports the crash event to the registered watcher to complete the callback.

Since API version 21, if the application fails to start or remains unstarted for a long time, you can delay the event notification by referring to [Using FaultLogExtensionAbility to Subscribe to Events](./fault-log-extension-app-events-arkts.md).

**Application proactively captures crash events**

If the application proactively captures the crash exception, HiAppEvent will trigger the callback before the application exits. For example:

1. The application does not exit during exception handling.

   When [errorManager.on](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror) is used to capture the **JsError** crash event, a callback is triggered before the application exits. If the application registers the [crash signal](cppcrash-guidelines.md#crash-signals) processing function but does not exit, the NativeCrash event triggers a callback before the application exits.

2. If the exception handling takes a long time, the application exits with a delay.

In the development and debugging phase, after HiAppEvent reports a crash event and completes the callback, you can view the event information in the **HiLog** window of DevEco Studio.

```text
HiAppEvent eventInfo.domain=OS
HiAppEvent eventInfo.name=APP_CRASH
HiAppEvent eventInfo.eventType=1
HiAppEvent eventInfo.params.time=1503045716054
HiAppEvent eventInfo.params.crash_type=JsError
HiAppEvent eventInfo.params.foreground=1
HiAppEvent eventInfo.params.release_type=debug
HiAppEvent eventInfo.params.cpu_abi=armeabi-v7a
HiAppEvent eventInfo.params.app_running_unique_id=365426736245712514
HiAppEvent eventInfo.params.bundle_version=1.0.0
HiAppEvent eventInfo.params.bundle_name=com.samples.eventsub
HiAppEvent eventInfo.params.pid=2610
HiAppEvent eventInfo.params.uid=20010044
HiAppEvent eventInfo.params.uuid=7c3b1579c8ca8629af3858f8145254c2867ee402dc16ee18034337aae258620b
HiAppEvent eventInfo.params.exception={"message":"Unexpected Text in JSON: Empty Text","name":"SyntaxError","stack":"    at anonymous (entry|entry|1.0.0|src/main/ets/pages/Index.ts:163:22)\n","thread_name":"amples.eventsub"}
HiAppEvent eventInfo.params.hilog.size=100
HiAppEvent eventInfo.params.process_life_time=25
HiAppEvent eventInfo.params.memory={"rss":181964,"sys_avail_mem":1230456,"sys_free_mem":676940,"sys_total_mem":2001932}
HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_CRASH_1503045716408_2610.log"]
HiAppEvent eventInfo.params.log_over_limit=0
```

### Removing and Destroying an Event Watcher

1. Remove the event watcher.

    <!-- @[Sys_Crash_Event_C++_RemoveWatcher](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

    ``` C++
    static napi_value RemoveWatcherCrash(napi_env env, napi_callback_info info)
    {
        // Remove the watcher.
        OH_HiAppEvent_RemoveWatcher(systemEventWatcherR);
        OH_HiAppEvent_RemoveWatcher(systemEventWatcherT);
        return {};
    }
    ```

2. Destroy the event watcher.

    <!-- @[Sys_Crash_Event_C++_DestroyWatcher](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

    ``` C++
    static napi_value DestroyWatcherCrash(napi_env env, napi_callback_info info)
    {
        // Destroy the created watcher and set eventWatcher to nullptr.
        OH_HiAppEvent_DestroyWatcher(systemEventWatcherR);
        OH_HiAppEvent_DestroyWatcher(systemEventWatcherT);
        systemEventWatcherR = nullptr;
        systemEventWatcherT = nullptr;
        return {};
    }
    ```