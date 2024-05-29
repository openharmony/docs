# @ohos.app.ability.insightIntent (insightIntent)(系统接口)

本模块提供意图调用基础能力。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.insightIntent (insightIntent)](js-apis-app-ability-insightIntent.md)。

## 导入模块

```ts
import { insightIntent } from '@kit.AbilityKit';
```

## ExecuteMode

意图调用执行模式。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| SERVICE_EXTENSION_ABILITY | 3 | 拉起ServiceExtensionAbility。<br/>**系统接口：** 该接口为系统接口。|
