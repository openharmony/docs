# @ohos.app.ability.insightIntent (意图框架基础定义)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhangyafei-echo; @linjunjie6-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

本模块提供[意图框架](../../application-models/insight-intent-overview.md)基础定义。

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

意图执行模式。表示系统入口触发意图执行时传递的执行模式，每个意图支持的执行模式在意图开发时定义。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| UI_ABILITY_FOREGROUND | 0 | 将UIAbility在前台显示。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| UI_ABILITY_BACKGROUND | 1 | 将UIAbility在后台拉起。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| UI_EXTENSION_ABILITY | 2 | 拉起UIExtensionAbility。 |

## ExecuteResult

意图执行的返回结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| code | number | 否 | 否 | 意图执行返回的错误码，由开发者定义。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| result | Record<string, Object> | 否 | 是 | 意图执行返回的结果，通常会包含需要返回给系统入口的数据。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| uris<sup>18+</sup> | Array&lt;string&gt; | 否 | 是 | 意图执行返回的URI列表。该字段需要与flags字段配合使用，根据URI列表将flags字段的相应权限授权给系统入口。<br/>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。 |
| flags<sup>18+</sup> | number | 否 | 是 | 意图执行返回给系统入口的URI列表的授权权限。<br/>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。 <br/>**说明：**<br/>该参数仅支持FLAG_AUTH_READ_URI_PERMISSION、FLAG_AUTH_WRITE_URI_PERMISSION、FLAG_AUTH_READ_URI_PERMISSION\|FLAG_AUTH_WRITE_URI_PERMISSION。权限介绍见[Flags](js-apis-app-ability-wantConstant.md#flags)。 |

## IntentEntity<sup>20+<sup>

意图实体结构体定义，用于定义意图执行过程中涉及的关键信息对象，包括意图参数和意图执行结果等。

开发者通过继承该类来定义意图实体，继承类需使用[@InsightIntentEntity](./js-apis-app-ability-InsightIntentDecorator.md#insightintententity)装饰。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| entityId | string | 否 | 否 | 意图实体的ID。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |

## IntentResult\<T><sup>20+<sup>

意图执行的返回结果，支持[泛型类型](../../quick-start/introduction-to-arkts.md#泛型类和接口)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| code | number | 否 | 否 | 意图执行返回的错误码，由开发者定义。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |
| result | T | 否 | 是 | 意图执行返回的结果，通常会包含需要返回给系统入口的数据。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |
