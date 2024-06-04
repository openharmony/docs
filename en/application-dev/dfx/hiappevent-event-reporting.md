# Reporting Events

HiAppEvent provides APIs for reporting events.

## Available APIs

For details about how to use APIs, see [@ohos.hiviewdfx.hiAppEvent (Application Event Logging)](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

**Data Processor APIs**

| API                                   | Description                                            |
| ----------------------------------------- | ------------------------------------------------ |
| addProcessor(processor: Processor): number | Adds a data processor for reporting events.|
| removeProcessor(id: number): void          | Removes a data processor.            |

**User ID APIs**

| API                                    | Description                                        |
| ------------------------------------------ | -------------------------------------------- |
| setUserId(name: string, value: string): void | Sets a user ID. The data processor can carry the user ID when reporting an event.|
| getUserId(name: string): string               | Obtains the user ID that has been set.                          |

**User Property APIs**

| API                                          | Description                                            |
| ------------------------------------------------ | ------------------------------------------------ |
| setUserProperty(name: string, value: string): void | Sets user properties. The data processor can carry user properties when reporting events.|
| getUserProperty(name: string): string               | Obtains the user properties that have been set.                           |

## How to Develop

The following describes how to log a user click event and enable the data processor to report the event.

1. Choose **entry** > **src** > **main** > **ets** > **pages**, and double-click **Index.ets**. Then, add a button, and enable addition of a data processor in its** onClick** function. **analytics_demo** is the data processor library preset in the device.  For details, see [HiAppEvent Data Processor Library](../../device-dev/subsystems/subsys-dfx-hiappevent-extend-so.md). The complete sample code is as follows:

   ```ts
   import { BusinessError } from '@ohos.base'
   import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent'
   import hilog from '@ohos.hilog'
   
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
             // Enable addition of a data processor in the onClick function.
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

2. Choose **entry** > **src** > **main** > **ets** > **pages**, and double-click **Index.ets**. Then, add a button, and enable addition and viewing of user IDs to its **onClick** function. The complete sample code is as follows:

   ```ts
     Button("userIdTest").onClick(()=>{
       // Set the user ID in the onClick function.
       hiAppEvent.setUserId('testUserIdName', '123456');

       // Obtain the user ID set in the onClick function.
       let userId = hiAppEvent.getUserId('testUserIdName');
       hilog.info(0x0000, 'testTag', `userId: ${userId}`)
     })
   ```

3. Choose **entry** > **src** > **main** > **ets** > **pages**, and double-click **Index.ets**. Then, add a button, and enable addition and viewing of user properties to its **onClick** function. The complete sample code is as follows:

   ```ts
     Button("userPropertyTest").onClick(()=>{
       // Set the user ID in the onClick function.
       hiAppEvent.setUserProperty('testUserPropertyName', '123456');

       // Obtain the user ID set in the onClick function.
       let userProperty = hiAppEvent.getUserProperty('testUserPropertyName');
       hilog.info(0x0000, 'testTag', `userProperty: ${userProperty}`)
     })
   ```

4. Choose **entry** > **src** > **main** > **ets** > **pages**, and double-click **Index.ets**. Then, add a button, and enable logging of button touch events in its **onClick** function. The complete sample code is as follows: 

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

5. Choose **entry** > **src** > **main** > **ets** > **pages**, and double-click **Index.ets**. Then, add a button, and enable removal of the data processor (the one created in step 2) in its **onClick** function. The complete sample code is as follows:

   ```ts
     Button("removeProcessorTest").onClick(()=>{
       // Enable removal of the data processor in the onClick function.
       hiAppEvent.removeProcessor(this.processorId);
     })
   ```

6. Click the Run button in DevEco Studio to run the project. Then, touch the **addProcessorTest**, **userIdTest**, **userPropertyTest**, **writeTest**, and **removeProcessorTest** buttons one by one to trigger event reporting.

   Once the event handler receives the event data, you can view the user click event log information in the **Log** window.

   ```text
   HiAppEvent success to write event
   ```
