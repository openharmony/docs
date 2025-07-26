# TriggerInfo(系统接口)

作为[trigger](js-apis-app-ability-wantAgent.md#wantagenttrigger)的入参定义触发WantAgent所需要的信息。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[TriggerInfo](js-apis-inner-wantAgent-triggerInfo.md)。

## 导入模块

```ts
import { wantAgent } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称       | 类型                 | 只读 | 可选 | 说明        |
| ---------- | ------------------- | ---- | ---- | ----------- |
| startOptions<sup>12+<sup>|[StartOptions](js-apis-app-ability-startOptions.md)         | 否 | 是 | 触发启动Ability的wantAgent时，由该属性指定启动参数。 |