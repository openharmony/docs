# Subscribing to Application Events

HiAppEvent provides event subscription APIs for obtaining application events locally.

## Available APIs

For details about how to use APIs, see [@ohos.hiviewdfx.hiAppEvent (Application Event Logging)](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

**Event Logging APIs**

| API                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds an event watcher to subscribe to expected application events.|
| removeWatcher(watcher: Watcher): void               | Removes an event watcher to unsubscribe from expected application events.|

**Subscription APIs**

| API                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds an event watcher to subscribe to expected application events.|
| removeWatcher(watcher: Watcher): void               | Removes an event watcher to unsubscribe from expected application events.|

## How to Develop

The following example illustrates how to log and subscribe to button touch events of users.

1. Create an ArkTS application project. In the Project window, choose **entry** > **src** > **main** > **ets** > **entryability**, and double-click **EntryAbility.ets**. Then, add an event watcher to **onCreate** to subscribe to button touch events. The complete sample code is as follows: 

   ```ts
   import AbilityConstant from '@ohos.app.ability.AbilityConstant';
   import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent';
   import hilog from '@ohos.hilog';
   import UIAbility from '@ohos.app.ability.UIAbility';
   import Want from '@ohos.app.ability.Want';
   import window from '@ohos.window';
   
   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
   
       hiAppEvent.addWatcher({
         // Set the watcher name. The system identifies different watchers based on their names.
         name: "watcher1",
         // Subscribe to application events you are interested in, for example, button touch events.
         appEventFilters: [{ domain: "button" }],
         // Set the subscription callback trigger condition. In this example, a callback is triggered if one event is logged.
         triggerCondition: { row: 1 },
         // Implement the subscription callback function to apply custom processing to the event logging data obtained through subscription.
         onTrigger: (curRow: number, curSize: number, holder: hiAppEvent.AppEventPackageHolder) => {
           // If the watcher incurs an error while it is working, return a null holder object after recording the error in the log.
           if (holder == null) {
             hilog.error(0x0000, 'testTag', "HiAppEvent holder is null");
             return;
           }
           hilog.info(0x0000, 'testTag', `HiAppEvent onTrigger: curRow=%{public}d, curSize=%{public}d`, curRow, curSize);
           let eventPkg: hiAppEvent.AppEventPackage | null = null;
           // Fetch the subscription event package based on the specified threshold (512 KB by default) until all subscription event data is fetched.
           // If all subscription event data is fetched, return a null event package object. The subscription callback process is ended.
           while ((eventPkg = holder.takeNext()) != null) {
             // Apply custom processing to the event logging data in the event package, for example, print the event logging data in the log.
             hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.packageId=%{public}d`, eventPkg.packageId);
             hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.row=%{public}d`, eventPkg.row);
             hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.size=%{public}d`, eventPkg.size);
             for (const eventInfo of eventPkg.data) {
               hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.info=%{public}s`, eventInfo);
             }
           }
         }
       });
     }
   }

2. Choose **entry** > **src** > **main** > **ets** > **pages**, and double-click **Index.ets**. Then, add a button, and enable logging of button touch events in its **onClick** function. The complete sample code is as follows: 

   ```ts
     Button("writeTest").onClick(()=>{
       // Enable event logging in the onClick function to log button touch events.
       let eventParams: Record<string, number> = { 'click_time': 100 };
       let eventInfo: hiAppEvent.AppEventInfo = {
         // Define the event domain.
         domain: "button",
         // Define the event name.
         name: "click",
         // Define the event type.
         eventType: hiAppEvent.EventType.BEHAVIOR,
         // Define event parameters.
         params: eventParams,
       };
       hiAppEvent.write(eventInfo).then(() => {
         hilog.info(0x0000, 'testTag', `HiAppEvent success to write event`)
       }).catch((err: BusinessError) => {
         hilog.error(0x0000, 'testTag', `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`)
       });
     })
   ```

3. Click the Run button in DevEco Studio to run the project. Then, touch the **writeTest** button on the application screen to trigger logging of the button touch event.

4. View the information printed in the **Log** window. If logging of the button touch event is successful, you will see a message indicating successful event logging as well as the log information specific to processing of the event logging data in the subscription callback.

   ```text
   HiAppEvent success to write event
   HiAppEvent eventPkg.packageId=0
   HiAppEvent eventPkg.row=1
   HiAppEvent eventPkg.size=124
   HiAppEvent eventPkg.info={"domain_":"button","name_":"click","type_":4,"time_":1670268234523,"tz_":"+0800","pid_":3295,"tid_":3309,"click_time":100}
   ```
