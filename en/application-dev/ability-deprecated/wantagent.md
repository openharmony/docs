# WantAgent Development
## When to Use
The **WantAgent** class encapsulates want information that specifies a particular action, which can be starting an ability or publishing a common event. You can either call **wantAgent.trigger** to trigger a **WantAgent** directly or add a **WantAgent** to a notification so that it will be triggered when users tap the notification.

## Available APIs
| API                                                                                         | Description|
| ---------------------------------------------------------------------------------------------- | ----------- |
| getWantAgentInfo(info: WantAgentInfo, callback: AsyncCallback\<WantAgent\>) | Creates a **WantAgent** object. This API uses an asynchronous callback to return the result.|
| getWantAgent(info: WantAgentInfo): Promise\<WantAgent\> | Creates a **WantAgent** object. This API uses a promise to return the result.|
| trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback\<CompleteData\>) | Triggers a **WantAgent** object.|

## How to Develop
1. Import the **WantAgent** module.

   ```
   import wantAgent from '@ohos.wantAgent';
   ```
   
2. Create a **WantAgentInfo** object that will be used for starting an ability. For details about the data types and parameters of **WantAgentInfo**, see [WantAgent](../reference/apis/js-apis-wantAgent.md#wantagentinfo).

   ```
   private wantAgentObj = null // Save the WantAgent object created. It will be used to complete the trigger operations.
   
   // wantAgentInfo
   var wantAgentInfo = {
       wants: [
           {
               deviceId: "",
               bundleName: "com.example.test",
               abilityName: "com.example.test.MainAbility",
               action: "",
               entities: [],
               uri: "",
               parameters: {}
           }
       ],
       operationType: wantAgent.OperationType.START_ABILITY,
       requestCode: 0,
       wantAgentFlags:[wantAgent.WantAgentFlags.CONSTANT_FLAG]
   }
   ```

3. Create a **WantAgentInfo** object for publishing a common event.

   ```
   private wantAgentObj = null // Save the WantAgent object created. It will be used to complete the trigger operations.
   
   // wantAgentInfo
   var wantAgentInfo = {
       wants: [
           {
               action: "event_name", // Set the action name.
               parameters: {}
           }
       ],
       operationType: wantAgent.OperationType.SEND_COMMON_EVENT,
       requestCode: 0,
       wantAgentFlags:[wantAgent.WantAgentFlags.CONSTANT_FLAG]
   }
   ```

4. Create a **WantAgent** object and save the returned **wantAgentObj** for subsequent trigger operations.

   ```
   // Create a WantAgent object.
   wantAgent.getWantAgent(wantAgentInfo, (err, wantAgentObj) => {
       if (err.code) {
           console.error("[WantAgent]getWantAgent err=" + JSON.stringify(err))
       } else {
           console.log("[WantAgent]getWantAgent success")
           this.wantAgentObj = wantAgentObj
       }
   })
   ```

5. Trigger the **WantAgent** object.

   ```
   // Trigger the WantAgent object.
   var triggerInfo = {
       code:0
   }
   wantAgent.trigger(wantAgentObj, triggerInfo, (completeData) => {
       console.log("[WantAgent]getWantAgent success, completeData: ",  + JSON.stringify(completeData))
   })
   ```
