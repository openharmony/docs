# Subscribing to Crash Events (ArkTS)
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @chenshi51-->
<!--Designer: @Maplestory-->
<!--Tester: @yufeifei-->
<!--Adviser: @foryourself-->

## Overview

The following describes how to subscribe to application crash events by using the ArkTS APIs provided by HiAppEvent. For details about how to use the APIs (such as parameter restrictions and value ranges), see [@ohos.hiviewdfx.hiAppEvent (Application Event Logging)](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

> **NOTE**
>
> The ArkTS APIs can be used to subscribe to the **JsError** and **NativeCrash** events.

## Available APIs

| API| Description|
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to listen for application events.|
| removeWatcher(watcher: Watcher): void | Removes a watcher to unsubscribe from application events.|

## How to Develop

### Adding an Event Watcher

To subscribe to the crash event successfully, you are advised to add an event watcher after the application starts and before the service logic is executed.

The following describes how to subscribe to the crash event triggered by a button click.

1. Create a native C++ project in DevEco Studio. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, import the dependent modules. The sample code is as follows:

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   import testNapi from 'libentry.so';
   ```

2. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, set the [custom parameters of the crash event](hiappevent-watcher-crash-events.md#customizing-crash-event-parameters) and [custom parameters of the crash log specifications](hiappevent-watcher-crash-events.md#customizing-crash-log-specifications) in **onCreate()**.

   ```ts
    // Build custom parameters for the crash event.
    let params: Record<string, hiAppEvent.ParamType> = {
      "test_data": 100,
    };
    // Set custom parameters for the crash event.
    hiAppEvent.setEventParam(params, hiAppEvent.domain.OS, hiAppEvent.event.APP_CRASH).then(() => {
      hilog.info(0x0000, 'testTag', `HiAppEvent success to set event param`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
    });
   
    // Build custom parameters for crash log specifications.
    let configParams: Record<string, hiAppEvent.ParamType> = {
      "extend_pc_lr_printing": true, // Enable the functionality of printing the memory values near the PC and LR.
      "log_file_cutoff_sz_bytes": 102400, // Truncate the crash log to 100 KB.
      "simplify_vma_printing": true // Enable simplified printing of maps.
    };
   
    // Set the crash log configuration parameters.
    hiAppEvent.setEventConfig(hiAppEvent.event.APP_CRASH, configParams).then(() => {
      hilog.info(0x0000, 'testTag', `HiAppEvent success to set event config.`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
    });
   ```

3. In the **entry/src/main/ets/entryability/EntryAbility.ets** file of the project, add the system event subscription to **onCreate()**. The sample code is as follows:

   ```ts
    let watcher: hiAppEvent.Watcher = {
      // Set the watcher name. The system identifies different watchers based on their names.
      name: "watcher",
      // Add the system events to watch, for example, crash events.
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.APP_CRASH]
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
            // Obtain the timestamp of the crash event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
            // Obtain the type of the crash event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.crash_type=${eventInfo.params['crash_type']}`);
            // Obtain the foreground and background status of the crashed application.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params['foreground']}`);
            // Obtain the version information of the crashed application.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params['bundle_version']}`);
            // Obtain the bundle name of the crashed application.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${eventInfo.params['bundle_name']}`);
            // Obtain the process ID of the crashed application.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params['pid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uuid=${eventInfo.params['uuid']}`);
            // Obtain the exception type, cause, and call stack of the crash event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.exception=${JSON.stringify(eventInfo.params['exception'])}`);
            // Obtain the log information about the crash event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.hilog.size=${eventInfo.params['hilog'].length}`);
            // Obtain the crash log file about the crash event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.log_over_limit=${eventInfo.params['log_over_limit']}`);
            // Obtain the custom test_data of the crash event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.test_data=${eventInfo.params['test_data']}`);
          }
        }
      }
    };
    hiAppEvent.addWatcher(watcher);
   ```

4. Construct a crash scenario.

    - Construct a **NativeCrash**

      In the **entry/src/main/cpp/napi_init.cpp** file, add the following code to the **Add** method:

      ```cpp
      int *p = nullptr;
      int a = *p; // Null pointer dereference. The program crashes.
      ```

       In the **entry/src/main/ets/pages/index.ets** file, add the **appCrash** button and construct a scenario for triggering a crash event in **onClick()**. The sample code is as follows:

      ```ts
      Button("NativeCrash").onClick(()=>{
        // In the onClick() function, call the Add method of napi_init.cpp to trigger the NativeCrash event.
        testNapi.add(2, 3);
      })
      ```

    - Construct a **JsError**

      In the **entry/src/main/ets/pages/index.ets** file, add the **appCrash** button and construct a scenario for triggering a crash event in **onClick()**. The sample code is as follows:

      ```ts
      Button("JsError").onClick(()=>{
        // Construct a JsError in the button click function to trigger an application crash event.
        let result: object = JSON.parse("");
      })
      ```

5. In DevEco Studio, click the **Run** button to run the project. Tap the **NativeCrash** or **JsError** button on the application screen to trigger a crash event. The system generates logs based on the crash type and triggers the callback.

> **NOTE**
>
> **JsError** collects fault information in process and triggers the callback almost instantly. **NativeCrash** collects it out of process, taking roughly 2s on average; the exact time depends on the number of service threads and IPC overhead. The collected fault information is reported asynchronously, which does not block the current service.

### Checking Whether a Watcher Subscribes to Crash Events

Depending on whether an application proactively captures crash events, callbacks are triggered for the crash events at different times. You need to check whether crash events are subscribed to at different times.

**Application not proactively captures crash events**

If the application does not proactively capture the crash exception, the application will exit after the system handles the crash. When the application restarts, HiAppEvent reports the crash event to the registered watcher to complete the callback.

**Application proactively captures crash events**

If an application proactively captures the crash event, a callback is triggered before the application exits. The following are examples:

1. The application does not exit during exception handling.

   When [errorManager.on](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror) is used to capture the **JsError** event, a callback is triggered before the application exits. If the application registers the [crash signal](cppcrash-guidelines.md#crash-signals) processing function but does not exit, the **NativeCrash** event triggers a callback before the application exits.

2. If the exception handling takes a long time, the application exits with a delay.

In the development and debugging phase, after HiAppEvent reports a crash event and completes the callback, you can view the **JsError** event information in the **HiLog** window of DevEco Studio. The content of the **NativeCrash** event is different. For details, see [Event Fields](hiappevent-watcher-crash-events.md#fields). The following is an example of a **JsError** event:

```text
HiAppEvent onReceive: domain=OS
HiAppEvent eventName=APP_CRASH
HiAppEvent eventInfo.domain=OS
HiAppEvent eventInfo.name=APP_CRASH
HiAppEvent eventInfo.eventType=1
HiAppEvent eventInfo.params.time=1711440614001
HiAppEvent eventInfo.params.crash_type=JsError
HiAppEvent eventInfo.params.foreground=true
HiAppEvent eventInfo.params.bundle_version=1.0.0
HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
HiAppEvent eventInfo.params.pid=2043
HiAppEvent eventInfo.params.uid=20010043
HiAppEvent eventInfo.params.uuid=b1e953ba0022c112e4502e28e8b3ad6d95cf3c87bae74068038f03b38ce7f66a
HiAppEvent eventInfo.params.exception={"message":"Unexpected Text in JSON","name":"SyntaxError","stack":"at anonymous (entry/src/main/ets/pages/Index.ets:55:34)"}
HiAppEvent eventInfo.params.hilog.size=90
HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_CRASH_1711440614112_2043.log"]
HiAppEvent eventInfo.params.log_over_limit=false
HiAppEvent eventInfo.params.test_data=100
```

### Removing an Event Watcher

```ts
// Remove the event watcher to unsubscribe from events.
hiAppEvent.removeWatcher(watcher);
```
<!--RP1-->
<!--RP1End-->
