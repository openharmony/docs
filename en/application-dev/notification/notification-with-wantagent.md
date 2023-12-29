# Adding a WantAgent Object to a Notification

A [WantAgent](../reference/apis/js-apis-app-ability-wantAgent.md) object encapsulates an intention to start a specified ability, release a common event, and more. A **WantAgent** object can be passed in a notification from the publisher to the subscriber, so as to trigger the intention specified. For example, you may want the user to start a specific ability by touching the notification published by your application. In this case, you can add a **WantAgent** object that encapsulates such an action to the notification. After receiving the **WantAgent** object, the system triggers it once the user touches the notification from the notification panel, starting the specified ability.

Below you can see the process of adding a **WantAgent** object to a notification. The notification publisher requests a **WantAgent** object from the Ability Manager Service (AMS), and then sends a notification carrying the **WantAgent** object to the home screen. When the user touches the notification from the notification panel on the home screen, the **WantAgent** object is triggered.

**Figure 1** Publishing a notification with a WantAgent object

![notification-with-wantagent](figures/notification-with-wantagent.png)


## Available APIs

For details about the APIs, see [@ohos.app.ability.wantAgent](../reference/apis/js-apis-app-ability-wantAgent.md).

| API | Description|
| -------- | -------- |
| getWantAgent(info: WantAgentInfo, callback: AsyncCallback&lt;WantAgent&gt;): void | Creates a **WantAgent** object.|
| trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback&lt;CompleteData&gt;): void | Triggers a **WantAgent** object.|
| cancel(agent: WantAgent, callback: AsyncCallback&lt;void&gt;): void | Cancels a **WantAgent** object.|
| getWant(agent: WantAgent, callback: AsyncCallback&lt;Want&gt;): void | Obtains a **WantAgent** object.|
| equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback&lt;boolean&gt;): void | Checks whether two **WantAgent** objects are equal.|


## How to Develop

1. [Enable notification](notification-enable.md). An application can use the notification feature only after being authorized by the user.

2. Import the modules.

   ```typescript
   import notificationManager from '@ohos.notificationManager';
   import wantAgent from '@ohos.app.ability.wantAgent';
   import { WantAgent } from '@ohos.app.ability.wantAgent';
   import Base from '@ohos.base';
   ```

3. Create a **WantAgentInfo** object.

   Scenario 1: Create a [WantAgentInfo](../reference/apis/js-apis-inner-wantAgent-wantAgentInfo.md) object for starting a UIAbility component.

   ```typescript
   let wantAgentObj:WantAgent; // Save the created WantAgent object for completing the trigger operations at a later time.
   
   // Set the action type through operationType of WantAgentInfo.
   let wantAgentInfo:wantAgent.WantAgentInfo = {
     wants: [
       {
         deviceId: '',
         bundleName: 'com.example.myapplication',
         abilityName: 'EntryAbility',
         action: '',
         entities: [],
         uri: '',
         parameters: {}
       }
     ],
     operationType: wantAgent.OperationType.START_ABILITY,
     requestCode: 0,
     wantAgentFlags:[wantAgent.WantAgentFlags.CONSTANT_FLAG]
   };
   ```

   Scenario 2: Create a [WantAgentInfo](../reference/apis/js-apis-inner-wantAgent-wantAgentInfo.md) object for publishing a [common event](../application-models/common-event-overview.md).

   ```typescript
   let wantAgentObj:WantAgent; // Save the created WantAgent object for completing the trigger operations at a later time.
   
   // Set the action type through operationType of WantAgentInfo.
   let wantAgentInfo:wantAgent.WantAgentInfo = {
     wants: [
       {
         action: 'event_name', // Set the action name.
         parameters: {},
       }
     ],
     operationType: wantAgent.OperationType.SEND_COMMON_EVENT,
     requestCode: 0,
     wantAgentFlags: [wantAgent.WantAgentFlags.CONSTANT_FLAG],
   };
   ```

4. Invoke the [getWantAgent()](../reference/apis/js-apis-app-ability-wantAgent.md#wantagentgetwantagent) API to create a **WantAgent** object.

   ```typescript
   // Create a WantAgent object.
   wantAgent.getWantAgent(wantAgentInfo, (err:Base.BusinessError, data:WantAgent) => {
     if (err) {
       console.error(`Failed to get want agent. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     console.info('Succeeded in geting want agent.');
     wantAgentObj = data;
   });
   ```

5. Create a **NotificationRequest** object and publish a notification that carries the **WantAgent** object.

   ```typescript
   // Create a NotificationRequest object.
   let notificationRequest: notificationManager.NotificationRequest = {
     content: {
       contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
       normal: {
         title: 'Test_Title',
         text: 'Test_Text',
         additionalText: 'Test_AdditionalText',
       },
     },
     id: 1,
     label: 'TEST',
     wantAgent: wantAgentObj,
   }
   
   notificationManager.publish(notificationRequest, (err:Base.BusinessError) => {
     if (err) {
       console.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     console.info('Succeeded in publishing notification.');
   });
   ```

6. When the user touches the notification from the notification panel, the system automatically triggers the action specified in the **WantAgent** object.
