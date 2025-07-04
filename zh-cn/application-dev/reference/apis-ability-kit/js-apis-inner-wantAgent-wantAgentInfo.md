# WantAgentInfo

定义触发WantAgent所需要的信息。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { wantAgent as abilityWantAgent } from '@kit.AbilityKit';
```

## WantAgentInfo

定义触发WantAgent所需要的信息，可以作为[getWantAgent](js-apis-app-ability-wantAgent.md#wantagentgetwantagent)的入参创建指定的WantAgent对象。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称           | 类型                            | 只读 | 可选 | 说明                   |
| -------------- | ------------------------------ | ---- | ---- |---------------------- |
| wants          | Array\<[Want](js-apis-app-ability-want.md)\>                   | 否 | 否 | 将被执行的动作列表。wants数组为预留能力，当前只支持一个want。传入多个时只取wants数组的第一个成员。    |
| operationType<sup>(deprecated)</sup>  | [wantAgent.OperationType](js-apis-wantAgent.md#operationtype)         | 否 | 是 | 动作类型。 <br/>从API version 7 开始支持，从API version 11 开始废弃，建议使用actionType<sup>11+</sup>替代。               |
| actionType<sup>11+</sup> | [abilityWantAgent.OperationType](js-apis-app-ability-wantAgent.md#operationtype)         | 否 | 是 | 动作类型。               |
| requestCode    | number                          | 否 | 否 | 开发者自定义的请求码，用于标识将被执行的动作。 |
| wantAgentFlags<sup>(deprecated)</sup> | Array<[wantAgent.WantAgentFlags](js-apis-wantAgent.md#wantagentflags)> | 否 | 是 | 动作执行属性。<br/>从API version 7 开始支持，从API version 11 开始废弃，建议使用actionFlags<sup>11+</sup>替代。           |
| actionFlags<sup>11+</sup> | Array<[abilityWantAgent.WantAgentFlags](js-apis-app-ability-wantAgent.md#wantagentflags)> | 否 | 是 | 动作执行属性。           |
| extraInfo      | { [key: string]: any }            | 否 | 是 | 额外数据。               |
| extraInfos<sup>11+</sup> | Record\<string, Object>            | 否 | 是 | 额外数据。推荐使用该属性替代extraInfo，设置该属性后，extraInfo不再生效。               |
