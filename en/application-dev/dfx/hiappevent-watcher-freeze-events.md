# Subscribing to System Events (Freeze Events)

HiAppEvent provides APIs for subscribing to freeze events.

## Available APIs

For details about how to use APIs, see [@ohos.hiviewdfx.hiAppEvent (Application Event Logging)](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

| API                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds an event watcher to subscribe to expected application events.|
| removeWatcher(watcher: Watcher): void               | Removes an event watcher to unsubscribe from expected application events.|

The following describes the attributes in the freeze event.

**params attributes**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| time     | number | Event triggering time, in milliseconds.|
| foreground | boolean | Whether the application is in the foreground.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| process_name | string | Process name of the application.|
| pid | number | Process ID of the application.|
| uid | number | User ID of the application.|
| uuid | string | Fault ID.|
| exception | object | Exception information. For details, see the description of **exception** attributes.|
| hilog | string[] | Log information.|
| event_handler | string[] | Number of events not yet handled by the main thread.|
| event_handler_size_3s | string | Number of tasks in the task stack when the THREAD_BLOCK event lasts for 3s.|
| event_handler_size_6s | string | Number of tasks in the task stack when the THREAD_BLOCK event lasts for 6s.|
| peer_binder | string[] | Binder call information.|
| threads | object[] | Full thread call stack. For details, see the description of **thread** attributes.|
| memory | object | Memory information. For details, see the description of **memory** attributes.|

**exception attributes**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| name | string | Exception type.|
| message | string | Exception cause.|

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

**memory attributes**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| rss | number | Size of the memory actually occupied by the process, in KB.|
| vss | number | Size of the virtual memory allocated to the process by the system, in KB.|
| pss | number | Size of the physical memory actually used by the process, in KB.|
| sys_free_mem | number | Size of free memory, in MB.|
| sys_avail_mem | number | Size of available memory, in KB.|
| sys_total_mem | number | Total memory size, in KB.|

## How to Develop

The following describes how to subscribe to the freeze event generated when a user clicks the button to trigger an application freeze.

1. In the Project window, choose **entry** > **src** > **main** > **ets** > **entryability**, and double-click **EntryAbility.ets**. Then, add an event watcher to **onCreate** to subscribe to system events. The complete sample code is as follows: 

   ```ts
    hiAppEvent.addWatcher({
      // Set the watcher name. The system identifies different watchers based on their names.
      name: "watcher3",
      // Subscribe to application events you are interested in, for example, freeze events.
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.APP_FREEZE]
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
            // Obtain the timestamp of the freeze event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
            // Obtain the foreground and background status of the freeze application.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params['foreground']}`);
            // Obtain the version information of the freeze application.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params['bundle_version']}`);
            // Obtain the bundle name of the freeze application.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${eventInfo.params['bundle_name']}`);
            // Obtain the process name of the freeze application.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.process_name=${eventInfo.params['process_name']}`);
            // Obtain the process ID of the freeze application.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params['pid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uuid=${eventInfo.params['uuid']}`);
            // Obtain the exception type and cause of the freeze event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.exception=${JSON.stringify(eventInfo.params['exception'])}`);
            // Obtain the log information about the freeze event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.hilog.size=${eventInfo.params['hilog'].length}`);
            // Obtain the number of messages that are not yet processed by the main thread when the freeze event occurs.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler.size=${eventInfo.params['event_handler'].length}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler_size_3s=${eventInfo.params['event_handler_size_3s']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler_size_6s=${eventInfo.params['event_handler_size_6s']}`);
            // Obtain the synchronous binder call information logged when the freeze event occurs.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.peer_binder.size=${eventInfo.params['peer_binder'].length}`);
            // Obtain the full thread call stack logged when the freeze event occurs.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.threads.size=${eventInfo.params['threads'].length}`);
            // Obtain the memory information logged when the freeze event occurs.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.memory=${JSON.stringify(eventInfo.params['memory'])}`);
          }
        }
      }
    });
   ```

2. Choose **entry** > **src** > **main** > **ets** > **pages**, and double-click **Index.ets**. Then, add a button, and construct a freeze scenario in its **onClick** function for triggering a freeze event. The complete sample code is as follows: 

   ```ts
    Button("appFreeze").onClick(()=>{
      // Construct a freeze scenario in the onClick function for triggering a freeze event.
      setTimeout(() => {
        while (true) {}
      }, 1000)
    })
   ```

3. Click the Run button in DevEco Studio to run the project. Then, touch the **appFreeze** button on the application screen to trigger an application freeze.

4. After the application recovers, view the system event processing log in the **Log** window.

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=APP_FREEZE
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_FREEZE
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1702553728887
   HiAppEvent eventInfo.params.foreground=true
   HiAppEvent eventInfo.params.bundle_version=1.0.0
   HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
   HiAppEvent eventInfo.params.process_name=com.example.myapplication
   HiAppEvent eventInfo.params.pid=2978
   HiAppEvent eventInfo.params.uid=20010043
   HiAppEvent eventInfo.params.uuid=...
   HiAppEvent eventInfo.params.exception={"message":"App main thread is not response!","name":"THREAD_BLOCK_6S"}
   HiAppEvent eventInfo.params.hilog.size=7
   HiAppEvent eventInfo.params.event_handler.size=3
   HiAppEvent eventInfo.params.event_handler_size_3s=2
   HiAppEvent eventInfo.params.event_handler_size_6s=3
   HiAppEvent eventInfo.params.peer_binder.size=0
   HiAppEvent eventInfo.params.threads.size=22
   HiAppEvent eventInfo.params.memory={"pss":0,"rss":0,"sys_avail_mem":947700,"sys_free_mem":441064,"sys_total_mem":1992724,"vss":0}
   ```
