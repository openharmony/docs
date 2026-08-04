# Subscribing to Main Thread Jank Events (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=f319e3e62d6356bf78f31e2e8f7ba3927caddf1e translatedAt=2026-07-31T01:26:41.945Z pushedAt=2026-07-31T03:55:25.951Z -->

## Overview

This document describes how to use the ArkTS APIs provided by HiAppEvent to subscribe to main thread timeout events. For detailed usage instructions (parameter constraints, value ranges, etc.) of the APIs, see [@ohos.hiviewdfx.hiAppEvent](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

## Available APIs

| API| Description|
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to listen for application events.|
| removeWatcher(watcher: Watcher): void | Removes a watcher to unsubscribe from application events.|

## How to Develop

### Adding an Event Watcher

The following walks you through on how to subscribe to the main thread jank event.

1. In DevEco Studio, create an ArkTS app project, edit the **entry > src > main > ets > entryability > EntryAbility.ets** file in the project, and import the dependent modules. The sample code is as follows:

   ```ts
    import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
    import { buffer, util } from '@kit.ArkTS'
    import { fileIo } from '@kit.CoreFileKit';
   ```

2. In the **entry/src/main/ets/entryability/EntryAbility.ets** file of the project, add a watcher in lifecycle APIs such as **onCreate()** and **onForeground()** at a proper position. The sample code is as follows:

   ```ts
    hiAppEvent.addWatcher({
      // Set the watcher name. The system identifies different watchers based on their names.
      name: "watcher",
      // Add the system events to watch, for example, the main thread jank event.
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.MAIN_THREAD_JANK]
        }
      ],
      // Implement a callback for the registered system event so that you can apply custom processing to the event data obtained.
      onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
        hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
        for (const eventGroup of appEventGroups) {
          // The event name uniquely identifies a system event.
          hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
          for (const eventInfo of eventGroup.appEventInfos) {
            // Apply custom processing to the event data obtained, for example, print the event data in the log.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.domain=${eventInfo.domain}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.name=${eventInfo.name}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.eventType=${eventInfo.eventType}`);
            // Obtain the timestamp when the main thread jank event occurs.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
            // Obtain the version information of the application.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params['bundle_version']}`);
            // Obtain the bundle name of the application.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${eventInfo.params['bundle_name']}`);
            // Obtain the PID and UID of the application.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params['pid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uid']}`);
            // Obtain the begin time and end time on the main thread.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.begin_time=${eventInfo.params['begin_time']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.end_time=${eventInfo.params['end_time']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.log_over_limit=${eventInfo.params['log_over_limit']}`);
            // Obtain the start time of the task when the main thread jank event occurs. (Parameter of the main thread timeout event collection stack.)
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.app_start_jiffies_time=${JSON.stringify(eventInfo.params['app_start_jiffies_time'])}`);
            // Obtain the call stack that is printed most frequently in the generated log file. (Parameter of the main thread timeout event collection stack.)
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.heaviest_stack=${eventInfo.params['heaviest_stack']}`);

            // Obtain the error log file generated when the main thread jank event occurs.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
            // Move the file to a new directory.
            let path: string = String(eventInfo.params['external_log']);
            // Customize the new storage path.
            let targetPath: string = "";
            if (path.endsWith(".txt")) {
              targetPath= "/data/storage/el2/base/mainThreadJank.txt";
            } else if (path.endsWith(".trace")) {
              targetPath= "/data/storage/el2/base/mainThreadJank.trace";
            }
            fileIo.copyFileSync(path.toString(), targetPath.toString());
          }
        }
      }
    });
   ```

3. Simulate a main thread timeout stack sampling event.

   Edit the **entry/src/main/ets/pages/Index.ets** file. The sample code is as follows:

   ```ts
     @Entry
     @Component
     struct Index {
       build() {
         RelativeContainer() {
           Column() {
             Button("timeOut350", { stateEffect:true, type: ButtonType.Capsule})
               .width('75%')
               .height(50)
               .margin(15)
               .fontSize(20)
               .fontWeight(FontWeight.Bold)
               .onClick(() => {
                 let t = Date.now();
                 while (Date.now() - t <= 350) {}
               })
           }.width('100%')
         }
         .height('100%')
         .width('100%')
       }
     }
   ```

4. (Optional) Simulate the customization of the main thread timeout parameter and trigger the main thread jank event.

   Edit the **entry > src > main > ets > pages> Index.ets** file in the project. In this example, a **customSample** button component is configured in **onClick()** to implement the custom sampling stack parameters. The sample code is as follows:

   ```ts
     import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
     import { BusinessError } from '@kit.BasicServicesKit';
   
     // Function definition for simulating timeout events. Sample code:
     function wait150ms() {
       let t = Date.now();
       while (Date.now() - t <= 150){
       }
     }
   
     function wait500ms() {
       let t = Date.now();
       while (Date.now() - t <= 500){
       }
     }
   
     @Entry
     @Component
     struct Index {
       build() {
         RelativeContainer() {
           Column() {
             // Button for customizing sample stack parameters
             Button("customSample", { stateEffect:true, type: ButtonType.Capsule})
               .width('75%')
               .height(50)
               .margin(15)
               .fontSize(20)
               .fontWeight(FontWeight.Bold)
               .onClick(() => {
                 // Log a button onclick event when the button is clicked.
                 let params: Record<string, hiAppEvent.ParamType> = {
                   // The log type. The value 0 indicates the default value. The value 1 indicates that only the stack is sampled. The value 2 indicates that only the trace is collected.
                   "log_type": "1",
                   // The sampling interval.
                   "sample_interval": "100",
                   // The startup time to be ignored.
                   "ignore_startup_time": "11",
                   // Sampling count.
                   "sample_count": "21",
                   // The number of event reporting times.
                   "report_times_per_app": "3"
                 };
                 hiAppEvent.setEventConfig(hiAppEvent.event.MAIN_THREAD_JANK, params).then(() => {
                   hilog.info(0x0000, 'testTag', `HiAppEvent success to set event params.`)
                 }).catch((err: BusinessError) => {
                   hilog.error(0x0000, 'testTag', `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`)
                 });
               })
             // Button for triggering a 150 ms timeout event
             Button("timeOut150", { stateEffect:true, type: ButtonType.Capsule})
               .width('75%')
               .height(50)
               .margin(15)
               .fontSize(20)
               .fontWeight(FontWeight.Bold)
               .onClick(() => {
                 wait150ms();
               })
           }.width('100%')
         }
         .height('100%')
         .width('100%')
       }
     }
   ```

5. Simulate a main thread timeout trace sampling event.

   In the **entry/src/main/ets/pages/Index.ets** file of the project, add a button in **onClick()** to trigger the timeout trace capture. The sample code is as follows:

   > **NOTE**
   >
   > Before starting the timeout trace capture of the main thread, ensure that you use the [nolog version](performance-analysis-kit-terminology.md#nolog-version) and disable **Developer options**.

   ```ts
     @Entry
     @Component
     struct Index {
       build() {
         RelativeContainer() {
           Column() {
             Button("timeOut500", { stateEffect:true, type: ButtonType.Capsule})
               .width('75%')
               .height(50)
               .margin(15)
               .fontSize(20)
               .fontWeight(FontWeight.Bold)
               .onClick(() => {
                 let t = Date.now();
                 while (Date.now() - t <= 500) {}
               })
           }.width('100%')
         }
         .height('100%')
         .width('100%')
       }
     }
   ```

6. Click the **Run** button in DevEco Studio to run the project.

   > **NOTE**
   >
   > By default, the system starts main thread jank event detection 10 seconds after the application is launched because the application startup process is time-consuming.
   >
   > If you use the **setEventConfig** API to set sampling stack parameters, the system starts main thread jank event detection after the time specified by **ignore_startup_time**.

   The main thread jank event is triggered when two consecutive timeout events are detected within the interval of the detection task.

   You can quickly click the timeout button for two or three times (for example, **timeOut350**, **timeOut150**, or **timeOut500**) to trigger the main thread jank event.

### Verifying the Subscription

1. After the main thread jank event is reported, the system calls **onReceive()**. You can view the following event information in the **Log** window.

   Trace data of the main thread jank event is as follows:

   ```text
    HiAppEvent eventInfo.domain=OS
    HiAppEvent eventInfo.name=MAIN_THREAD_JANK
    HiAppEvent eventInfo.eventType=1
    HiAppEvent eventInfo.params.time=1717593620518
    HiAppEvent eventInfo.params.bundle_version=1.0.0
    HiAppEvent eventInfo.params.bundle_name=com.example.main_thread_jank
    HiAppEvent eventInfo.params.pid=40986
    HiAppEvent eventInfo.params.uid=20020150
    HiAppEvent eventInfo.params.begin_time=1717593620016
    HiAppEvent eventInfo.params.end_time=1717593620518
    HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/watchdog/MAIN_THREAD_JANK_20240613211739_40986.XXX"]
    HiAppEvent eventInfo.params.log_over_limit=false
    HiAppEvent eventInfo.params.app_start_jiffies_time=XXXX
    HiAppEvent eventInfo.params.heaviest_stack=XXXX
   ```

   The sampling stack of the main thread jank event is similar to the trace result. The differences are as follows:

   ```text
   Stack:
     The app_start_jiffies_time and heaviest_stack parameters are added to the sampling stack.
     external_log=["/data/storage/el2/log/watchdog/MAIN_THREAD_JANK_yyyyMMDDHHmmss_xxxx.txt"]. xxxx indicates the process ID.
   
   Trace:
     external_log=[""/data/storage/el2/log/watchdog/MAIN_THREAD_JANK_unix timestamp_xxxx.trace"]. xxxx indicates the process ID.
   ```