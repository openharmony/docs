# TriggerInfo

作为[trigger](js-apis-app-ability-wantAgent.md#wantagenttrigger)的入参定义触发WantAgent所需要的的信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称       | 类型                 | 必填 | 说明        |
| ---------- | --- |-------------------- | ----------- |
| code       | number               | 是   | 提供给目标wantAgent的自定义结果码。 |
| want       | Want                 | 否   | Want。        |
| permission | string               | 否   | 权限定义。    |
| extraInfo  | {[key: string]: any} | 否   | 额外数据。    |
