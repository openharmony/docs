# Event Subscription (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--Designer: @junjie_shi-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

HiAppEvent provides APIs for subscribing to application events.

## Available APIs

For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [@ohos.hiviewdfx.hiAppEvent (Application Event Logging)](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

**Subscription APIs**

| API| Description|
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to listen for application events.|
| removeWatcher(watcher: Watcher): void | Removes a watcher to unsubscribe from application events.|

**Event Logging APIs**

| API| Description|
| -------- | -------- |
| write(info: AppEventInfo, callback: AsyncCallback&lt;void>): void | Writes events to the event file through **AppEventInfo** objects. This API uses an asynchronous callback to return the result.|
| write(info: AppEventInfo): Promise&lt;void> | Writes events to the event file through **AppEventInfo** objects. This API uses a promise to return the result.|

## How to Develop

The following describes how to subscribe to a crash event (system event) and a button click event (application event).

1. Create an ArkTS application project. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, import the dependent modules.

   ```ts
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, add the subscription to the crash event and button click event in the **onCreate** function.

   Subscribe to the crash event using **OnReceive**. After receiving the event, the watcher immediately triggers the **OnReceive** callback. In the **EntryAbility.ets** file, define the methods related to the watcher of the **OnReceive** type.

   ```ts
   hiAppEvent.addWatcher({
     // Set the watcher name. The system identifies different watchers based on their names.
     name: "AppCrashWatcher",
     // Set the subscription filters. For example, subscribe to the crash event of the system event.
     appEventFilters: [
       {
         domain: hiAppEvent.domain.OS,
         names: [hiAppEvent.event.APP_CRASH]
       }
     ],
     // Implement the onReceive callback, which is called in real time after an event is detected.
     onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
       hilog.info(0x0000, 'testTag', `domain=${domain}`);
       for (const eventGroup of appEventGroups) {
         hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
         for (const eventInfo of eventGroup.appEventInfos) {
           // Obtain the timestamp of the crash event.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${JSON.stringify(eventInfo.params['time'])}`);
           // Obtain the bundle name of the crashed application.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${JSON.stringify(eventInfo.params['bundle_name'])}`);
           // Obtain the error log file about the crash event.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
         }
       }
     }
   });
   ```

   Subscribe to the button click event using **OnTrigger**. The **OnTrigger()** callback can be triggered only when the conditions specified by **OnTrigger()** are met. In the **napi_init.cpp** file, define the methods related to **OnTrigger()**.

   ```ts
   hiAppEvent.addWatcher({
     // Set the watcher name. The system identifies different watchers based on their names.
     name: "ButtonClickWatcher",
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
       // Fetch the subscription event package based on the specified threshold (1 event by default) until all subscription event data is fetched.
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
   ```

3. In the **entry/src/main/ets/pages/Index.ets** file, import the dependent modules.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

4. In the **entry/src/main/ets/pages/Index.ets** file, add the **appCrash** button to trigger a crash event and add the **buttonClick** button to log events in the button click function. The sample code is as follows:

   Trigger a crash event.

   ```ts
     Button("appCrash")
       .onClick(()=>{
         // Construct a scenario in onClick() to trigger a crash event.
         let result: object = JSON.parse("");
       })
       .position({ x: 50, y: 100 }) // Set the button position.
   ```

   Log events in the button click function.

   ```ts
     Button("buttonClick")
       .onClick(()=>{
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
           params: eventParams
         };
         hiAppEvent.write(eventInfo).then(() => {
           hilog.info(0x0000, 'testTag', `HiAppEvent success to write event`);
         }).catch((err: BusinessError) => {
           hilog.error(0x0000, 'testTag', `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`);
         });
         hilog.info(0x0000, 'testTag', `HiAppEvent write event`);
       })
       .position({ x: 50, y: 200 }) // Set the button position.
   ```

## Debugging and Verification

1. Click the **Run** button in DevEco Studio to run the project. Then, click the **appCrash** button to trigger a crash event. After the application exits, restart it.

2. Search for the keyword **HiAppEvent** in the **HiLog** window to view logs of crash event processing.

   ```text
   HiAppEvent eventName=APP_CRASH
   HiAppEvent eventInfo.params.time=1750747995874
   HiAppEvent eventInfo.params.bundle_name="com.example.txxxxx"
   HiAppEvent eventInfo.params.external_log=
   ["/data/storage/el2/log/hiappevent/APP_CRASH_1750747996042_28962.log"]
   ```

3. Click the **Run** button in DevEco Studio to run the project. Then, click the **buttonClick** button to trigger a button click event and perform logging.

4. Search for the keyword **HiAppEvent** in the **HiLog** window to view logs of button click event processing.

   ```text
   HiAppEvent write event
   HiAppEvent onTrigger: curRow=1, curSize=121
   HiAppEvent eventPkg.packageId=0
   HiAppEvent eventPkg.row=1
   HiAppEvent eventPkg.size=121
   HiAppEvent eventPkg.info={"domain_":"button","name_":"click","type_":4,"time_":1750754529033,"tz_":"","pid_":40664,"tid_":40664,"click_time":100}
   HiAppEvent success to write event
   ```
