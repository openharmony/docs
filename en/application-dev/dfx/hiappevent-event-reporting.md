# Event Reporting

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--Designer: @jiangwenhao-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=592c7fbb76a6d10f1234d8c0e8928fce60796f0e translatedAt=2026-07-29T10:47:24.484Z pushedAt=2026-07-29T11:13:54.006Z -->

HiAppEvent provides APIs for reporting events.

## Available APIs

For details about API usage (parameter usage restrictions, specific value ranges, and so on), refer to [@ohos.hiviewdfx.hiAppEvent](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

**Data Processor APIs**

| API                                   | Description                                            |
| ----------------------------------------- | ------------------------------------------------ |
| addProcessor(processor: Processor): number | Adds a data processor for reporting events.|
| removeProcessor(id: number): void          | Removes a data processor.            |

**User ID APIs**

| API                                    | Description                                        |
| ------------------------------------------ | -------------------------------------------- |
| setUserId(name: string, value: string): void | Sets a user ID. The data processor can carry the user ID when reporting an event.|
| getUserId(name: string): string               | Obtains a user ID that has been set.                          |

**User Property APIs**

| API                                          | Description                                            |
| ------------------------------------------------ | ------------------------------------------------ |
| setUserProperty(name: string, value: string): void | Sets a user property. The data processor can carry user properties when reporting events.|
| getUserProperty(name: string): string               | Obtains a user property.                           |

## How to Develop

The following describes how to develop event logging and reporting for the button click behavior.

1. In the **entry/src/main/ets/ pages/Index.ets** file, add the **addprocessorTest** button with **Onclick()** to add the data processor. **analytics_demo** is the data processor library preset in the device.<!--Del--> For details, see [HiAppEvent Data Processor Library](../../device-dev/subsystems/subsys-dfx-hiappevent-extend-so.md).<!--DelEnd--> The sample code is as follows:

   <!-- @[EventEsc_Header_And_Add_Processor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventEsc/entry/src/main/ets/pages/Index.ets) -->    

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   
   @Entry
   @Component
   struct Index {
     processorId: number = -1; // Initialize processorId to -1.
   
     build() {
       Row() {
         Column() {
           Button('addProcessorTest')
             .type(ButtonType.Capsule)
             .margin({
               top: 20
             })
             .backgroundColor('#0D9FFB')
             .width('50%')
             .height('5%')
             .onClick(() => {
               // In Onclick(), add a data processor.
               let eventConfig: hiAppEvent.AppEventReportConfig = {
                 domain: 'button',
                 name: 'click',
                 isRealTime: true
               };
               let processor: hiAppEvent.Processor = {
                 name: 'analytics_demo',
                 debugMode: true,
                 routeInfo: 'CN',
                 onStartReport: true,
                 onBackgroundReport: true,
                 periodReport: 10,
                 batchReport: 5,
                 userIds: ['testUserIdName'],
                 userProperties: ['testUserPropertyName'],
                 eventConfigs: [eventConfig]
               };
               this.processorId = hiAppEvent.addProcessor(processor);
             })
           // ...
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

2. In the **entry/src/main/ets/pages/index.ets** file, add a button with **onClick()** to add and view the user ID. The sample code is as follows:

   <!-- @[Button_Add_ID](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventEsc/entry/src/main/ets/pages/Index.ets) -->    

   ``` TypeScript
   Button('userIdTest')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('40%')
     .height('5%')
     .onClick(() => {
       // Set the user ID in onClick().
       hiAppEvent.setUserId('testUserIdName', '123456');
   
       // Obtain the user ID set in onClick().
       let userId = hiAppEvent.getUserId('testUserIdName');
       hilog.info(0x0000, 'testTag', `userId: ${userId}`)
     })
   ```

3. In the **entry/src/main/ets/pages/index.ets** file, add a button with **onClick()** to add and view the user property. The sample code is as follows:

   <!-- @[Button_Add_Property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventEsc/entry/src/main/ets/pages/Index.ets) -->    

   ``` TypeScript
   Button('userPropertyTest')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('50%')
     .height('5%')
     .onClick(() => {
       // Set the user property in onClick().
       hiAppEvent.setUserProperty('testUserPropertyName', '123456');
   
       // Obtain the user property in onClick().
       let userProperty = hiAppEvent.getUserProperty('testUserPropertyName');
       hilog.info(0x0000, 'testTag', `userProperty: ${userProperty}`)
     })
   ```

4. In the **entry/src/main/ets/pages/index.ets** file, add a button with **onClick()** to log the button click event. The sample code is as follows:

   <!-- @[Button_Add_Event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventEsc/entry/src/main/ets/pages/Index.ets) -->    

   ``` TypeScript
   Button('writeTest')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('40%')
     .height('5%')
     .onClick(() => {
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

5. Edit the **entry > src > main > ets > pages > Index.ets** file in the project, add a button, and remove the data processor in its **onClick** function (the data processor was added in step 2). The complete example code is as follows:

   <!-- @[Button_Remove_Processor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventEsc/entry/src/main/ets/pages/Index.ets) -->    

   ``` TypeScript
   Button('removeProcessorTest')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('60%')
     .height('5%')
     .onClick(() => {
       // Remove the data processor in onClick().
       hiAppEvent.removeProcessor(this.processorId);
     })
   ```

6. Click the **Run** button in DevEco Studio to run the project. Then, click the **addProcessorTest**, **userIdTest**, **userPropertyTest**, **writeTest**, and **removeProcessorTest** buttons one by one to trigger an event reporting.

Finally, the data processor successfully receives the event data, and the following log indicating successful event logging for the button click appears in the Log window:

   ```text
   HiAppEvent success to write event
   ```