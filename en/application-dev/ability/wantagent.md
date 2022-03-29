# WantAgent Development
### Introduction
The **WantAgent** class encapsulates a **Want** object that specifies a particular action. To trigger a **WantAgent**, you can either call **wantAgent.trigger** to trigger it directly or add it to a notification so that it will be triggered when users tap the notification.

You can use a **WantAgent** in a notification to start an ability or publish a common event.

### When to Use
Start another ability through a **WantAgent**.

### Available APIs
| API                                                                                         | Description|
| ---------------------------------------------------------------------------------------------- | ----------- |
| wantAgent.getWantAgentInfo(info: WantAgentInfo, callback: AsyncCallback\<WantAgent\>) | Creates a **WantAgent** object. This API uses an asynchronous callback to return the result.|
| wantAgent.getWantAgent(info: WantAgentInfo): Promise\<WantAgent\>; | Creates a **WantAgent** object. This API uses a promise to return the result.|
| commonEvent.trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback\<CompleteData\>) | Triggers a **WantAgent**.|

### How to Develop
1. Import the **WantAgent** module.

```javascript
import wantAgent from '@ohos.wantAgent';
```

2. Create a **WantAgentInfo** object. For details about the data types and parameters of **WantAgentInfo**, see [WantAgent Module](../reference/apis/js-apis-wantAgent.md#wantagentinfo).

```javascript
private wantAgentObj = null	// Save the WantAgent object created. It will be used to complete the trigger operations.

//wantAgentInfo
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
    operationType: OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.CONSTANT_FLAG]
}
```

3. Create a **WantAgent** object and save the returned **wantAgentObj** for subsequent trigger operations.

```javascript
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

4. Trigger the **WantAgent**.

```
// Trigger the WantAgent.
var triggerInfo = {
    code:0
}
wantAgent.trigger(wantAgentObj, triggerInfo, (completeData) => {
    console.log("[WantAgent]getWantAgent success, completeData: ",  + JSON.stringify(completeData))
})
```
