# @ohos.app.ability.insightIntent (insightIntent)

本模块提供意图调用基础能力。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { insightIntent } from '@kit.AbilityKit';
```

## ExecuteMode

意图调用执行模式。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| UI_ABILITY_FOREGROUND | 0 | 将UIAbility在前台显示。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| UI_ABILITY_BACKGROUND | 1 | 将UIAbility在后台拉起。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| UI_EXTENSION_ABILITY | 2 | 拉起UIExtensionAbility。 |

## ExecuteResult

意图调用的返回结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| code | number | 否 | 否 | 意图调用返回的错误码。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| result | Record<string, Object> | 否 | 是 | 意图调用返回的结果。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| uris<sup>18+</sup> | Array&lt;string&gt; | 否 | 是 | 意图调用时，意图执行方给意图调用方授权的URI列表。<br/>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。 |
| flags<sup>18+</sup> | number | 否 | 是 | 意图调用时，意图执行方给意图调用方授权的uris的[flags](js-apis-app-ability-wantConstant.md#flags)。<br/>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。 <br/>**说明：**<br/>该参数仅支持FLAG_AUTH_READ_URI_PERMISSION、FLAG_AUTH_WRITE_URI_PERMISSION、FLAG_AUTH_READ_URI_PERMISSION\|FLAG_AUTH_WRITE_URI_PERMISSION。|

## IntentResult\<T><sup>20+<sup>

用于定义意图执行返回结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| code | number | 否 | 否 | 意图调用返回的错误码。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |
| result | T | 否 | 是 | 意图调用返回的结果。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |