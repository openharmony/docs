# @ohos.app.ability.insightIntent (insightIntent)

本模块提供意图调用基础能力。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import insightIntent from '@ohos.app.ability.insightIntent';
```

## ExecuteMode

意图调用执行模式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| UI_ABILITY_FOREGROUND | 0 | 将UIAbility在前台显示。 |
| UI_ABILITY_BACKGROUND | 1 | 将UIAbility在后台拉起。 |
| UI_EXTENSION_ABILITY | 2 | 拉起UIExtensionAbility。 |

## ExecuteResult

意图调用的返回结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| code | number | 是 | 意图调用返回的错误码。 |
| result | Record<string, Object> | 是 | 意图调用返回的结果。 |
