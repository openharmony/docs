# TriggerInfo

定义触发WantAgent所需要的的信息

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称       | 可读 | 可写 | 类型                 | 必填 | 说明        |
| ---------- | --- | ---- | -------------------- | ---- | ----------- |
| code       | 是  | 是  | number               | 是   | result code。 |
| want       | 是  | 是  | Want                 | 否   | Want。        |
| permission | 是  | 是  | string               | 否   | 权限定义。    |
| extraInfo  | 是  | 是  | {[key: string]: any} | 否   | 额外数据。    |

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