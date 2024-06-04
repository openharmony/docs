# Subscribing to System Events (Resource Leak Events)

HiAppEvent provides APIs for subscribing to resource leak events.

## Available APIs

For details about how to use APIs, see [@ohos.hiviewdfx.hiAppEvent (Application Event Logging)](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

| API                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds an event watcher to subscribe to expected application events.|
| removeWatcher(watcher: Watcher): void               | Removes an event watcher to unsubscribe from expected application events.|

The following describes the attributes in the resource leak event.

**params attributes**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| time     | number | Event triggering time, in milliseconds.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of the application.|
| uid | number | User ID of the application.|
| resource_type | string | Resource type. For details, see the description of **resource_type** attributes.|
| memory | object | Memory information. For details, see the description of **memory** attributes.|

**resource_type attributes**

| Value   | Description                      |
| ------- | ------------------------- |
| pss_memory | PSS memory leak.|
| js_memory | JS memory leak.|
| fd | FD resources leak.|
| thread | Thread leak.|

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

The following describes how to subscribe to resource leak events generated in the memory leak scenario.

1. In the Project window, choose **entry** > **src** > **main** > **ets** >** entryability**, and double-click **EntryAbility.ets**. Then, add an event watcher to **onCreate** to subscribe to system events. The complete sample code is as follows: 

   ```ts
    hiAppEvent.addWatcher({
      // Set the watcher name. The system identifies different watchers based on their names.
      name: "watcher3",
      // Add the system events to watch, for example, resource leak events.
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.RESOURCE_OVERLIMIT]
        }
      ],
      // Implement a real-time subscription callback on your own so that you can apply custom processing to the events obtained through subscription.
      onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
        hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
        for (const eventGroup of appEventGroups) {
          // Distinguish system events based on the event names in the event set.
          hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
          for (const eventInfo of eventGroup.appEventInfos) {
            // Obtain the memory information logged when the resource leak event occurs.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.memory=${JSON.stringify(eventInfo)}`);
          }
        }
      }
    });
   ```

2. Run **hdc shell param set hiview.memleak.test enable** to enable the memory leak detection test. The memory leak detection period is 5s (200s by default) when enabled.

   Run **hdc shell killall hiview** to stop the hiview process. Then start hiview again for the memory leak detection test to take effect.

3. Click the Run button in DevEco Studio to run the project. If hiview detects that the application memory exceeds the baseline (RSS exceeds 1,228,800 KB) for five consecutive times, an application memory leak event is reported.
   For the same application, at most one memory leak event can be reported within 5 hours. To enable a second reporting within the time frame, restart hiview.

4. After a memory leak event is reported, the system calls back the **onReceive** function of the application. You can view the system event processing log in the **Log** window.

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=RESOURCE_OVERLIMIT
   HiAppEvent eventInfo={"domain":"OS","name":"RESOURCE_OVERLIMIT","eventType":1,"params":{"bundle_name":"com.example.myapplication","bundle_version"::"1.0.0","memory":{"pss":2100257,"rss":1352644,"sys_avail_mem":250272,"sys_free_mem":60004,"sys_total_mem":1992340,"vss":2462936},"pid":20731,"resource_type":"pss_memory","time":1502348798106,"uid":20010044}}
   ```
