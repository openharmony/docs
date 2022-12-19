# WantAgentInfo

定义触发WantAgent所需要的信息，可以作为[getWantAgent](js-apis-app-ability-wantAgent.md#wantagentgetwantagent)的入参创建指定的WantAgent对象。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称           | 类型                            | 必填 | 说明                   |
| -------------- | ------------------------------- | ---- | ---------------------- |
| wants          | Array\<Want\>                   | 是   | 将被执行的动作列表。     |
| operationType  | wantAgent.OperationType         | 是   | 动作类型。               |
| requestCode    | number                          | 是   | 使用者定义的一个私有值。 |
| wantAgentFlags | Array<[wantAgent.WantAgentFlags](js-apis-wantAgent.md#WantAgentFlags)> | 否   | 动作执行属性。           |
| extraInfo      | {[key: string]: any}            | 否   | 额外数据。               |
