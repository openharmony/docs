# Subscribing to Application Events (ArkTS)

HiAppEvent provides APIs for subscribing to application events.

## Available APIs

For details about how to use the APIs (such as parameter usage constraints and value ranges), see [Application Event Logging](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

**Event Logging APIs**

| API                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| write(info: AppEventInfo, callback: AsyncCallback\<void>): void | Writes events to the event file through **AppEventInfo** objects. This API uses an asynchronous callback to return the result.|
| write(info: AppEventInfo): Promise\<void>               | Writes events to the event file through **AppEventInfo** objects. This API uses a promise to return the result.|

**Subscription APIs**

| API                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to listen for application events.|
| removeWatcher(watcher: Watcher): void               | Removes a watcher to unsubscribe from application events.|

## How to Develop

The following describes how to log and subscribe to button onclick events.

1. Create an ArkTS application project. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, import the dependent modules.

   ```ts
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, add a watcher in **onCreate()** to subscribe to button onclick events. The sample code is as follows:

   ```ts
    hiAppEvent.addWatcher({
      // Set the watcher name. The system identifies different watchers based on their names.
      name: "watcher1",
      // Add the application events to watch, for example, button onclick events.
      appEventFilters: [{ domain: "button" }],
      // Set the subscription callback trigger condition. For example, trigger a callback when one event is logged.
      triggerCondition: { row: 1 },
      // Implement the subscription callback function to apply custom processing to the obtained event logging data.
      onTrigger: (curRow: number, curSize: number, holder: hiAppEvent.AppEventPackageHolder) => {
        // If the holder object is null, return after the error is recorded.
        if (holder == null) {
          hilog.error(0x0000, 'testTag', "HiAppEvent holder is null");
          return;
        }
        hilog.info(0x0000, 'testTag', `HiAppEvent onTrigger: curRow=%{public}d, curSize=%{public}d`, curRow, curSize);
        let eventPkg: hiAppEvent.AppEventPackage | null = null;
        // Fetch the subscription event package based on the specified threshold (512 KB by default) until all subscription event data is fetched.
        // If all subscription event data is fetched, return a null event package to end this subscription callback.
        while ((eventPkg = holder.takeNext()) != null) {
          // Apply custom processing to the event logging data obtained, for example, print the event logging data in the log.
          hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.packageId=%{public}d`, eventPkg.packageId);
          hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.row=%{public}d`, eventPkg.row);
          hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.size=%{public}d`, eventPkg.size);
          for (const eventInfo of eventPkg.data) {
            hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.info=%{public}s`, eventInfo);
          }
        }
      }
    });

3. In the **entry/src/main/ets/pages/Index.ets** file, import the dependent modules.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

4. In the **entry/src/main/ets/pages/index.ets** file, add the **writeTest** button with **onClick()** to enable an event to be logged when the button is clicked. The sample code is as follows: 

   ```ts
     Button("writeTest").onClick(()=>{
       // In onClick(), use hiAppEvent.write() to log an event when the button is clicked.
       let eventParams: Record<string, number> = { 'click_time': 100 };
       let eventInfo: hiAppEvent.AppEventInfo = {
         // Define the event domain.
         domain: "button",
         // Define the event name.
         name: "click",
         // Define the event type.
         eventType: hiAppEvent.EventType.BEHAVIOR,
         // Define the event parameters.
         params: eventParams,
       };
       hiAppEvent.write(eventInfo).then(() => {
         hilog.info(0x0000, 'testTag', `HiAppEvent success to write event`)
       }).catch((err: BusinessError) => {
         hilog.error(0x0000, 'testTag', `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`)
       });
     })
   ```

5. In DevEco Studio, click the **Run** button to run the project. Then, click the **writeTest** button to trigger logging of a button onclick event.

6. In the **Log** window, you can view the event logging information and the processing of the logging data after the callback is invoked.

   ```text
   HiAppEvent success to write event
   HiAppEvent eventPkg.packageId=0
   HiAppEvent eventPkg.row=1
   HiAppEvent eventPkg.size=124
   HiAppEvent eventPkg.info={"domain_":"button","name_":"click","type_":4,"time_":1670268234523,"tz_":"+0800","pid_":3295,"tid_":3309,"click_time":100}
   ```
