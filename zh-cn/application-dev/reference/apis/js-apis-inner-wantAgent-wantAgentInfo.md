# WantAgentInfo

定义触发WantAgent所需要的的信息

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称           | 类型                            | 必填 | 说明                   |
| -------------- | ------------------------------- | ---- | ---------------------- |
| wants          | Array\<Want\>                   | 是   | 将被执行的动作列表。     |
| operationType  | wantAgent.OperationType         | 是   | 动作类型。               |
| requestCode    | number                          | 是   | 使用者定义的一个私有值。 |
| wantAgentFlags | Array<[wantAgent.WantAgentFlags](js-apis-wantAgent.md#WantAgentFlags)> | 否   | 动作执行属性。           |
| extraInfo      | {[key: string]: any}            | 否   | 额外数据。               |

**示例：**
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