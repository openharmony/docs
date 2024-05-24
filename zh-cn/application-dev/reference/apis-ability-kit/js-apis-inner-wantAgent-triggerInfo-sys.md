# TriggerInfo

作为[trigger](js-apis-app-ability-wantAgent.md#wantagenttrigger)的入参定义触发WantAgent所需要的信息。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口为系统接口。

## 导入模块

```ts
import wantAgent from '@ohos.app.ability.wantAgent';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称       | 类型                 | 必填 | 说明        |
| ---------- | --- |-------------------- | ----------- |
| startOptions<sup>12+<sup> | [StartOptions](js-apis-app-ability-startOptions.md)         | 否  | 触发启动Ability的wantAgent时，由该属性指定启动参数。 |