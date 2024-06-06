# Subscribing to System Events (Crash Events)

HiAppEvent provides APIs for subscribing to crash events.

## Available APIs

For details about how to use APIs, see [@ohos.hiviewdfx.hiAppEvent (Application Event Logging)](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

| API                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds an event watcher to subscribe to expected application events.|
| removeWatcher(watcher: Watcher): void               | Removes an event watcher to unsubscribe from expected application events.|

The following describes the attributes in the crash event.

**params attributes**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| time     | number | Event triggering time, in milliseconds.|
| crash_type | string | Crash type. The value can be **JsError** or **NativeCrash**.|
| foreground | boolean | Whether the application is in the foreground.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of the application.|
| uid | number | User ID of the application.|
| uuid | string | Fault ID.|
| exception | object | Exception information. For details about JsError events, see the description of **exception** attributes (JsError). For details about NativeCrash events, see the description of **exception** attributes (NativeCrash).|
| hilog | string[] | Log information.|
| threads | object[] | Full thread call stack. For details, see the description of **thread** attributes. This field applies only to NativeCrash events.|

**exception attributes (JsError)**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| name | string | Exception type.|
| message | string | Exception cause.|
| stack | string | Abnormal call stack.|

**exception attributes (NativeCrash)**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| message | string | Exception cause.|
| signal | object | Signal information. For details, see the description of **signal** attributes.|
| thread_name | string | Thread name.|
| tid | number | Thread ID.|
| frames | object[] | Thread call stack. For details, see the description of **frame** attributes.|

**signal attributes**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| signo | number | Signal value.|
| code | number | Signal error code.|

**thread attributes**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| thread_name | string | Thread name.|
| tid | number | Thread ID.|
| frames | object[] | Thread call stack. For details, see the description of **frame** attributes.|

**frame attributes**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| symbol | string | Function name.|
| file | string | File name.|
| buildId | string | Unique file ID.|
| pc | string | PC register address.|
| offset | number | Function offset.|

## How to Develop

The following describes how to subscribe to the crash event generated when a user clicks the button to trigger an application crash.

1. In the Project window, choose **entry** > **src** > **main** > **ets** > **entryability**, and double-click **EntryAbility.ets**. Then, add an event watcher to **onCreate** to subscribe to system events. The complete sample code is as follows: 

   ```ts
    hiAppEvent.addWatcher({
      // Set the watcher name. The system identifies different watchers based on their names.
      name: "watcher2",
      // Subscribe to application events you are interested in, for example, crash events.
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.APP_CRASH]
        }
      ],
      // Implement a real-time subscription callback on your own so that you can apply custom processing to the events obtained through subscription.
      onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
        hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
        for (const eventGroup of appEventGroups) {
          // Distinguish system events based on the event names in the event set.
          hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
          for (const eventInfo of eventGroup.appEventInfos) {
            // Apply custom processing to the event data in the event set, for example, print the event data in the log.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.domain=${eventInfo.domain}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.name=${eventInfo.name}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.eventType=${eventInfo.eventType}`);
            // Obtain the timestamp of the crash event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
            // Obtain the crash type of the crash event.
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
          }
        }
      }
    });
   ```

2. Choose **entry** > **src** > **main** > **ets** > **pages**, and double-click **Index.ets**. Then, add a button, and construct a crash scenario in its onClick function for triggering a crash event. The complete sample code is as follows: 

   ```ts
    Button("appCrash").onClick(()=>{
      // Construct a crash scenario in the onClick function for triggering a crash event.
      let result: object = JSON.parse("");
    })
   ```

3. Click the Run button in DevEco Studio to run the project. Then, touch the appCrash button to trigger an application crash. The application breaks down and exits.

4. After you run the application again, view the system event processing log in the **Log** window.

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=APP_CRASH
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_CRASH
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1701836127566
   HiAppEvent eventInfo.params.crash_type=JsError
   HiAppEvent eventInfo.params.foreground=true
   HiAppEvent eventInfo.params.bundle_version=1.0.0
   HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
   HiAppEvent eventInfo.params.pid=2027
   HiAppEvent eventInfo.params.uid=20010043
   HiAppEvent eventInfo.params.uuid=...
   HiAppEvent eventInfo.params.exception={"message":"Unexpected Text in JSON\\n","name":"SyntaxError\\n","stack":"\\n    at anonymous (entry/src/main/ets/pages/Index.ets:60:34)\\n"}
   HiAppEvent eventInfo.params.hilog.size=100
   ```
