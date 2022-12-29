# WantAgentInfo

The **WantAgentInfo** module defines the information required for triggering the WantAgent.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name          | Type                           | Mandatory| Description                  |
| -------------- | ------------------------------- | ---- | ---------------------- |
| wants          | Array\<Want\>                   | Yes  | Array of all **Want** objects.    |
| operationType  | wantAgent.OperationType         | Yes  | Operation type.              |
| requestCode    | number                          | Yes  | Request code defined by the user.|
| wantAgentFlags | Array<[wantAgent.WantAgentFlags](js-apis-wantAgent.md#WantAgentFlags)> | No  | Array of flags for using the **WantAgent** object.          |
| extraInfo      | {[key: string]: any}            | No  | Extra information.              |

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
wantAgent.getWantAgent(wantAgentInfo).then((data) =>{
    console.info("getWantAgent data: " + JSON.stringify(data));
}).catch((err) => {
    console.error("getWantAgent err: " + JSON.stringify(err));
})
```
