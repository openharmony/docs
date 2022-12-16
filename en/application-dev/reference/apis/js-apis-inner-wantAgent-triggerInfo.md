# TriggerInfo

The **TriggerInfo** module defines the information required for triggering the WantAgent.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name      | Type                | Mandatory| Description       |
| ---------- | --- |-------------------- | ----------- |
| code       | number               | Yes  | Result code.|
| want       | Want                 | No  | Want.       |
| permission | string               | No  | Permission.   |
| extraInfo  | {[key: string]: any} | No  | Extra information.   |

**Example**
```ts
import wantAgent from '@ohos.wantAgent';

let wantAgentInfo = {
    wants: [
        {
            deviceId: "",
            bundleName: "com.example.apicoverhaptest",
            abilityName: "com.example.apicoverhaptest.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true.true,false}",
            parameters: {
                myKey0: 2222
            }
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG],
    extraInfo:{
        "key": "value"
    }
}

let triggerInfo = {
    code: 0,
    want: {
        deviceId: "",
        bundleName: "com.example.apicoverhaptest",
        abilityName: "com.example.apicoverhaptest.MainAbility",
        action: "action1",
        entities: ["entity1"],
        type: "MIMETYPE",
        uri: "key={true.true,false}",
        parameters: {
            myKey0: 2222
        }
    },
    permission: ""
    extraInfo:{
        "key": "value"
    }
}

wantAgent.trigger(wantAgentInfo, triggerInfo).then((data) =>{
    console.info("trigger data: " + JSON.stringify(data));
}).catch((err) => {
    console.error("trigger err: " + JSON.stringify(err));
})
```
