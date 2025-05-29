# Subscribing to Main Thread Jank Events (ArkTS)

## Main Thread Jank Event Specifications

For details, see [Main Thread Jank Event Overview](./hiappevent-watcher-mainthreadjank-events.md).

## Available APIs

For details about how to use the APIs, see [Application Event Logging](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

| API                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to listen for application events.|
| removeWatcher(watcher: Watcher): void               | Removes a watcher to unsubscribe from application events.|

## How to Develop

The following describes how to subscribe to the main thread jank event in sampling stack, which is reported when a task running in the main thread times out.

1. Create an ArkTS application project. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, import the dependent modules.

   ```ts
   import { hiAppEvent } from '@kit.PerformanceAnalysisKit';
   ```

2. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, add a watcher in **onForeground()** to subscribe to system events. The sample code is as follows:

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
            // Obtain the error log file generated when the main thread jank event occurs.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.log_over_limit=${eventInfo.params['log_over_limit']}`);
            // Obtain the start time of the task when the main thread jank event occurs.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.app_start_jiffies_time=${JSON.stringify(eventInfo.params['app_start_jiffies_time'])}`);
            // Obtain the call stack that is printed most frequently in the generated log file.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.heaviest_stack=${eventInfo.params['heaviest_stack']}`);
          }
        }
      }
    });
   ```

3. (Optional) Simulate a main thread jank event.
    Edit the **entry > src > main > ets > pages> Index.ets** file in the project.

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

4. (Optional) Simulate the scenario where the custom sampling stack parameters are used and the main thread jank event is triggered.

   Edit the **entry > src > main > ets > pages> Index.ets** file in the project. In this example, a **customSample** button component is configured in **onClick()** to implement the custom sampling stack parameters. The sample code is as follows:

    ```ts
      import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
      import { BusinessError } from '@kit.BasicServicesKit';

      // Simulate a main thread jank event.
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
              // Set the button for setting custom sampling stack parameters.
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
                    "report_times_per_app": "3",
                  };
                  hiAppEvent.setEventConfig(hiAppEvent.event.MAIN_THREAD_JANK, params).then(() => {
                    hilog.info(0x0000, 'testTag', `HiAppEvent success to set event params.`)
                  }).catch((err: BusinessError) => {
                    hilog.error(0x0000, 'testTag', `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`)
                  });
                })
              // The button for triggering the event that times out for 150 ms.
              Button("timeOut150", { stateEffect:true, type: ButtonType.Capsule})
                .width('75%')
                .height(50)
                .margin(15)
                .fontSize(20)
                .fontWeight(FontWeight.Bold)
                .onClick(() => {
                  wait150ms();
                })
              // The button for triggering the event that times out for 500 ms.
              Button("timeOut500", { stateEffect:true, type: ButtonType.Capsule})
                .width('75%')
                .height(50)
                .margin(15)
                .fontSize(20)
                .fontWeight(FontWeight.Bold)
                .onClick(() => {
                  wait500ms();
                })
            }.width('100%')
          }
          .height('100%')
          .width('100%')
        }
      }
    ```

5. In DevEco Studio, click the **Run** button to run the application project. Click the button twice consecutively to trigger a main thread jank event.

6. After the main thread jank event is reported, the system calls **onReceive()**. You can view the following event information in the **Log** window.

   Tracing data of the main thread jank event is as follows:

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
     HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/watchdog/MAIN_THREAD_JANK_20240613211739_40986.txt"]
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
