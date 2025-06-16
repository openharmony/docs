# Subscribing to Crash Events (ArkTS)

## Introduction

The following describes how to subscribe to application crash events by using the ArkTS APIs provided by HiAppEvent. For details about how to use the APIs (such as parameter restrictions and value ranges), see [@ohos.hiviewdfx.hiAppEvent (Application Event Logging)](../reference/apis-performance-analysis-kit/_hi_app_event.md#hiappevent).

> **NOTE**
>
> The ArkTS APIs can be used to subscribe to JsError and NativeCrash events.

### The API for Setting Custom Parameters

| API                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| setEventParam(params: Record&lt;string, ParamType&gt;, domain: string, name?: string): Promise&lt;void&gt; | Sets custom event parameters.|

### Subscription APIs

| API                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to listen for application events.|
| removeWatcher(watcher: Watcher): void               | Removes a watcher to unsubscribe from application events.|

## How to Develop

### Adding an Event Watcher

The following describes how to subscribe to the crash event triggered by a button click.

1. Create an ArkTS application project. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, import the dependent modules. The sample code is as follows:

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, set the custom parameters in **onCreate()**. The sample code is as follows:

   ```ts
    // Assign a value to params, which is a key-value pair
    let params: Record<string, hiAppEvent.ParamType> = {
      "test_data": 100,
    };
    // Set custom parameters for the crash event.
    hiAppEvent.setEventParam(params, hiAppEvent.domain.OS, hiAppEvent.event.APP_CRASH).then(() => {
      hilog.info(0x0000, 'testTag', `HiAppEvent success to set event param`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
    });
   ```

3. In the **entry/src/main/ets/entryability/EntryAbility.ets** file of the project, add a watcher in **onCreate()** to subscribe to system events. The sample code is as follows:

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
            // Obtain the error log file about the crash event.
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

4. In the **entry/src/main/ets/pages/index.ets** file, add the **appCrash** button and construct a scenario for triggering a crash event in **onClick()**. The sample code is as follows:

   ```ts
    Button("appCrash").onClick(()=>{
      // Construct a scenario in onClick() to trigger a crash event.
      let result: object = JSON.parse("");
    })
   ```

5. In DevEco Studio, click the **Run** button to run the project. Then, click the **appCrash** button to trigger a crash event. The system generates crash logs based on the crash type (**JsError** or **NativeCrash**) and executes callback.

**JsError** is collected within the process and triggers a callback quickly. **NativeCrash** is collected outside the process and typically takes about 2 seconds on average to trigger a callback. The time required depends on the number of service threads and the time needed for inter-process communication. The collected fault information is reported asynchronously, which does not block the current service.

### Checking Whether a Watcher Subscribes to Crash Events

Depending on whether an application proactively captures crash events, callbacks are triggered for the events at different times. You need to check whether crash events are subscribed to at these different times.

#### Application Not Proactively Capturing Crash Events

If an application does not proactively capture the crash event, the application exits after the system crashes. When the application is restarted, HiAppEvent reports the crash event to the registered watcher.

#### Application Proactively Capturing Crash Events

If an application proactively captures the crash event, a callback is triggered before the application exits. The following are examples:

1. The application does not exit during exception handling.
When [errorManager.on](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror) is used to capture the **JsError** crash event, a callback is triggered before the application exits. When the application proactively registers the [crash signal](cppcrash-guidelines.md#signals-that-generate-cppcrash-logs) processing function but does not proactively exit, the **NativeCrash** crash event triggers a callback before the application exits.

2. Exception handling takes a long time, and the application exit time is delayed.

In the development and debugging phase, after HiAppEvent reports a crash event, you can view the event information in the **HiLog** window of DevEco Studio.

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

### Removing and Destroying an Event Watcher

  ```ts
  // Remove the event watcher to unsubscribe from events.
  hiAppEvent.removeWatcher(watcher);
  ```
<!--RP1-->
<!--RP1End-->
