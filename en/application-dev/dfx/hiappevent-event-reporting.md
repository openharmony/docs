# Event Reporting

HiAppEvent provides APIs for reporting events.

## Available APIs

For details about how to use the APIs, see [Application Event Logging](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

**Data Processor APIs**

| API                                   | Description                                            |
| ----------------------------------------- | ------------------------------------------------ |
| addProcessor(processor: Processor): number | Adds a data processor for reporting events. |
| removeProcessor(id: number): void          | Removes a data processor.            |

**User ID APIs**

| API                                    | Description                                        |
| ------------------------------------------ | -------------------------------------------- |
| setUserId(name: string, value: string): void | Sets a user ID. The data processor can carry the user ID when reporting an event. |
| getUserId(name: string): string               | Obtains a user ID that has been set.                          |

**User Property APIs**

| API                                          | Description                                            |
| ------------------------------------------------ | ------------------------------------------------ |
| setUserProperty(name: string, value: string): void | Sets a user property. The data processor can carry user properties when reporting events. |
| getUserProperty(name: string): string               | Obtains a user property.                           |

## How to Develop

The following describes how to log a button onclick event and enable the data processor to report the event.

1. In the **entry/src/main/ets/ pages/Index.ets** file, add the **addprocessorTest** button with **Onclick()** to add the data processor. **analytics_demo** is the data processor library preset in the device.<!--Del--> For details, see [HiAppEvent Data Processor Library](../../device-dev/subsystems/subsys-dfx-hiappevent-extend-so.md).<!--DelEnd--> The sample code is as follows:

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World'

     processorId: number = -1
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
   
           Button("addProcessorTest").onClick(()=>{
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
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

2. In the **entry/src/main/ets/ pages/Index.ets** file, add the **userIdTest** button with **onClick()** to obtain the user ID. The sample code is as follows:

   ```ts
     Button("userIdTest").onClick(()=>{
       // Set the user ID in onClick().
       hiAppEvent.setUserId('testUserIdName', '123456');

       // Obtain the user ID set in onClick().
       let userId = hiAppEvent.getUserId('testUserIdName');
       hilog.info(0x0000, 'testTag', `userId: ${userId}`)
     })
   ```

3. In the **entry/src/main/ets/pages/Index.ets** file, add the **userPropertyTest** button with **onClick()** to obtain the user property. The sample code is as follows:

   ```ts
     Button("userPropertyTest").onClick(()=>{
       // Set the user property in onClick().
       hiAppEvent.setUserProperty('testUserPropertyName', '123456');

       // Obtain the user property in onClick().
       let userProperty = hiAppEvent.getUserProperty('testUserPropertyName');
       hilog.info(0x0000, 'testTag', `userProperty: ${userProperty}`)
     })
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

5. In the **entry/src/main/ets/pages/index.ets** file, add the **removeProcessorTest** button with **onClick()** to remove the data processor (the one added in step 2). The sample code is as follows:

   ```ts
     Button("removeProcessorTest").onClick(()=>{
       // In Onclick(), add removeProcessor().
       hiAppEvent.removeProcessor(this.processorId);
     })
   ```

6. Click the **Run** button in DevEco Studio to run the project. Then, click the **addProcessorTest**, **userIdTest**, **userPropertyTest**, **writeTest**, and **removeProcessorTest** buttons one by one to trigger an event reporting.

   Once the event handler receives the event data, you can view the following information in the **Log** window:

   ```text
   HiAppEvent success to write event
   ```
