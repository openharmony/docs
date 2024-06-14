# Subscribing to Resource Leak Events (ArkTS)

## Available APIs

For details about how to use the APIs (such as parameter usage constraints and value ranges), see [Application Event Logging](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

| API                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to listen for application events.|
| removeWatcher(watcher: Watcher): void               | Removes a watcher to unsubscribe from application events.|

## How to Develop

The following describes how to subscribe to a memory leak event.

1. Create an ArkTS application project. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, import the dependent modules.

   ```ts
   import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent';
   import hilog from '@ohos.hilog';
   ```

2. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, add a watcher in **onCreate()** to subscribe to system events. The sample code is as follows:

   ```ts
    hiAppEvent.addWatcher({
      // Set the watcher name. The system identifies different watchers based on their names.
      name: "watcher",
      // Add the system events to watch, for example, the resource leak event.
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.RESOURCE_OVERLIMIT]
        }
      ],
      // Implement a callback for the registered system event so that you can apply custom processing to the event data obtained.
      onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
        hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
        for (const eventGroup of appEventGroups) {
          // The event name uniquely identifies a system event.
          hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
          for (const eventInfo of eventGroup.appEventInfos) {
            // You can obtain the memory information when the resource leak event occurs.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.memory=${JSON.stringify(eventInfo)}`);
          }
        }
      }
    });
   ```

3. Run **hdc shell param set hiview.memleak.test enable** to enable the memory leak detection test. The original memory leak detection period is 200s. After the memory leak detection test is enabled, the period is 5s.

   Run **hdc shell killall hiview** to restart HiView. Then, the memory detection test is enabled.

4. In DevEco Studio, click the **Run** button to run the project. If HiView detects that the application memory exceeds the baseline (**RSS** exceeds 1228800 KB) for five consecutive times, a memory leak event is reported.
   For the same application, the memory leak event can be reported at most once within 5 hours. If the memory leak needs to be reported again within a shorter time, restart HiView.

5. After a memory leak event is reported, the system calls **onReceive()**. You can view the following event information in the **Log** window.

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=RESOURCE_OVERLIMIT
   HiAppEvent eventInfo={"domain":"OS","name":"RESOURCE_OVERLIMIT","eventType":1,"params":{"bundle_name":"com.example.myapplication","bundle_version"::"1.0.0","memory":{"pss":2100257,"rss":1352644,"sys_avail_mem":250272,"sys_free_mem":60004,"sys_total_mem":1992340,"vss":2462936},"pid":20731,"resource_type":"pss_memory","time":1502348798106,"uid":20010044}}
   ```
