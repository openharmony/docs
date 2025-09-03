# Subscribing to Task Execution Timeout Events (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @rr_cn-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## Overview

Since API version 21, the ArkTS APIs are supported to subscribe to task execution timeout events. This topic describes how to use the ArkTS APIs provided by HiAppEvent to subscribe to task execution timeout events. For details about how to use the APIs (such as parameter restrictions and value ranges), see [@ohos.hiviewdfx.hiAppEvent (Application Event Logging)](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

## Available APIs

| Name| Description|
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to listen for application events.|
| removeWatcher(watcher: Watcher): void | Removes a watcher to unsubscribe from application events.|

## How to Develop

### Adding an Event Watcher

To ensure that event callbacks can be successfully received in the development phase, you are advised to create a native C++ project, implement subscription in the ArkTs code, and use C++ code to construct fault injection to trigger task execution timeout events.

1. Create a native C++ project. The directory structure is as follows:

   ```yml
   entry:
     src:
       main:
         cpp:
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

2. In the **CMakeLists.txt** file, add the source file and dynamic libraries.

   ```cmake
   # Add **libhilog_ndk.z.so** (log output) and **libohhicollie.so** (HiCollie detection).
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so)
   ```

3. In the **EntryAbility.ets** file, import the dependent modules. The sample code is as follows:

   ```ts
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

4. Subscribe to system events. In the **EntryAbility.ets** file, add the subscription code to the **onCreate** function. The sample code is as follows:

   ```ts
   hiAppEvent.addWatcher({
     // Set the watcher name. The system identifies different watchers based on their names.
     name: "watcher",
     // Add the system events to watch, for example, the task execution timeout event.
     appEventFilters: [
       {
         domain: hiAppEvent.domain.OS,
         names: [hiAppEvent.event.APP_HICOLLIE]
       }
     ],
     // Implement a callback for the registered system event so that you can apply custom processing to the event data obtained.
     onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
       hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
       for (const eventGroup of appEventGroups) {
         hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
         for (const eventInfo of eventGroup.appEventInfos) {
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.domain=${eventInfo.domain}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.name=${eventInfo.name}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.eventType=${eventInfo.eventType}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params['foreground']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params['bundle_version']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.process_name=${eventInfo.params['process_name']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params['pid']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uid']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uuid']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.exception=${eventInfo.params['exception']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.hilog.size=${eventInfo.params['hilog'].length}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.peer_binder.size=${JSON.stringify(eventInfo.params['peer_binder'].length)}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.memory=${eventInfo.params['memory']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.log_over_limit=${eventInfo.params['log_over_limit']}`);
         }
       }
     }
   });
   hiAppEvent.addWatcher(watcher);
   ```

5. Add the **TestHiCollieTimerNdk** function.

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

6. Register **TestHiCollieTimerNdk** as an ArkTS API.

   In the **napi_init.cpp** file, register **TestHiCollieTimerNdk** as an ArkTS API.

   ```c++
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "TestHiCollieTimerNdk", nullptr, TestHiCollieTimerNdk, nullptr, nullptr, nullptr, napi_default, nullptr }
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
   export const TestHiCollieTimerNdk: () => void;
   ```

7. In the **Index.ets** file, add a button to trigger the task execution timeout event.

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

8. In DevEco Studio, click the **Run** button to run the project. Then, click the **testHiCollieTimerNdk** button to trigger a task execution timeout event.

### Verifying the Subscription

After the project crashes and exits, restart it. You can view the system event data processing logs in the **Log** window.

   ```text
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_HICOLLIE
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1754914806680
   HiAppEvent eventInfo.params.foreground=true
   HiAppEvent eventInfo.params.bundle_version=1.0.0
   HiAppEvent eventInfo.params.process_name=com.example.myapplication
   HiAppEvent eventInfo.params.pid=20317
   HiAppEvent eventInfo.params.uid=20020198
   HiAppEvent eventInfo.params.uuid=4asd360e18f5d6d84cf4f0c9e80d66we5786c1cc2343d9632e07abb0d3552asd
   HiAppEvent eventInfo.params.exception={"message":"","name":"APP_HICOLLIE"}
   HiAppEvent eventInfo.params.hilog.size=28
   HiAppEvent eventInfo.params.peer_binder.size=0
   HiAppEvent eventInfo.params.memory={"pss":0,"rss":150748,"sys_avail_mem":5387264,"sys_free_mem":218902,"sys_total_mem":11679236,"vss":38306936}
   HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_HICOLLIE_1754914811140_20317.log"]
   HiAppEvent eventInfo.params.log_over_limit=false
   ```

### Removing an Event Watcher

1. Remove the event watcher.

```ts
// Remove the event watcher to unsubscribe from events.
hiAppEvent.removeWatcher(watcher);
```
