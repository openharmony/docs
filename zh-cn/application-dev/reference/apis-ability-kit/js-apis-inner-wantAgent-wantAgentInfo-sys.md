# WantAgentInfo

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @linjunjie6-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

定义触发WantAgent所需要的信息。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 当前页面仅包含本模块的系统接口，其他公开接口参见[WantAgentInfo](js-apis-inner-wantAgent-wantAgentInfo.md)。

## 导入模块

```ts
import { wantAgent as abilityWantAgent } from '@kit.AbilityKit';
```

## LocalWantAgentInfo<sup>20+</sup>

定义触发本地WantAgent所需要的信息，可以作为[createLocalWantAgent](js-apis-app-ability-wantAgent-sys.md#wantagentcreatelocalwantagent20)的入参创建指定的本地WantAgent对象。 

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**模型约束**：此接口仅可在Stage模型下使用。

| 名称           | 类型                            | 只读  | 可选  | 说明                   |
| -------------- | ------------------------------- | --- | ---- | ---------------------- |
| wants          | Array\<[Want](js-apis-app-ability-want.md)\>                          | 否   | 否   | 将被执行的动作列表。当前只支持一个want。传入多个时只取wants数组的第一个成员。    |
| operationType  | [abilityWantAgent.OperationType](js-apis-app-ability-wantAgent.md#operationtype)        | 否   | 是   | 将被执行的动作类型。      |
| requestCode    | number                          | 否   | 否   | 开发者自定义的请求码，用于标识将被执行的动作。 |