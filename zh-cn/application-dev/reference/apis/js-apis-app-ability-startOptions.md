# @ohos.app.ability.StartOptions (StartOptions)

StartOptions可以作为[startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1)的入参，用于指定目标Ability的窗口模式。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import StartOptions from '@ohos.app.ability.StartOptions';
```

## 属性


**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| [windowMode](js-apis-application-abilityConstant.md#abilityconstantwindowmode) | number | 否 | 窗口模式。 |
| displayId | number | 否 | 屏幕ID。默认是0，表示当前屏幕。 |
