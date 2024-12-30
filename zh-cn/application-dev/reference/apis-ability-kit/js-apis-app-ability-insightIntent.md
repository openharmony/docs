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
| UI_ABILITY_FOREGROUND | 0 | 将UIAbility在前台显示。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| UI_ABILITY_BACKGROUND | 1 | 将UIAbility在后台拉起。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| UI_EXTENSION_ABILITY | 2 | 拉起UIExtensionAbility。 |

## ExecuteResult

意图调用的返回结果。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| code | number | 否 | 否 | 意图调用返回的错误码。 |
| result | Record<string, Object> | 否 | 是 | 意图调用返回的结果。 |
| uris<sup>16+</sup> | Array&lt;string&gt; | 否 | 是 | （API16及之后版本支持）意图调用时，意图执行方给意图调用方授权的URI列表。 |
| flags<sup>16+</sup> | number | 否 | 是 | （API16及之后版本支持）意图调用时，意图执行方给意图调用方授权的uris的标志位[insightIntent.ExecuteResult.flags](js-apis-app-ability-insightIntent.md#ExecuteResult.flags)。 |

## ExecuteResult.flags<sup>16+</sup>

flags说明。（API16及之后版本支持）用于表示处理意图拉起回调时，执行方给调用方授予的URI列表权限。

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称                                                           | 值         | 说明                           |
| ---------------------------------------------------------------| ---------- | ------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION                                  | 0x00000001 | 读取权限。                      |
| FLAG_AUTH_WRITE_URI_PERMISSION                                 | 0x00000002 | 写入权限。                      |
| [FLAG_AUTH_WRITE_URI_PERMISSION | FLAG_AUTH_READ_URI_PERMISSION]   | 0x00000003 | 读写权限。                      |
