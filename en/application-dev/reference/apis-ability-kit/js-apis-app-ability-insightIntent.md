# @ohos.app.ability.insightIntent (Basic Definitions of InsightIntent Framework)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @linjunjie6-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

This module provides basic definitions of the [InsightIntent framework](../../application-models/insight-intent-overview.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { insightIntent } from '@kit.AbilityKit';
```

## ExecuteMode

Enumerates the intent execution modes. It specifies the mode of execution passed when the intent is triggered by a system entry point. The supported execution modes for each intent are defined during intent development.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| UI_ABILITY_FOREGROUND | 0 | Display a UIAbility in the foreground.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| UI_ABILITY_BACKGROUND | 1 | Start a UIAbility in the background.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| UI_EXTENSION_ABILITY | 2 | Start a UIExtensionAbility.|

## ExecuteResult

Enumerates the return results of intent execution.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| code | number | No| No| Error code returned by the intent execution, defined by the developer.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| result | Record<string, Object> | No| Yes| Result data returned by the intent execution, typically containing information to be passed back to the system entry point.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| uris<sup>18+</sup> | Array&lt;string&gt; | No| Yes| List of URIs returned by the intent execution. This field must be used together with the **flags** field to grant the corresponding permissions for the URI list to the system entry point.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| flags<sup>18+</sup> | number | No| Yes| Permissions to be granted to the system entry point for the URI list returned by the intent execution.<br>**Atomic service API**: This API can be used in atomic services since API version 18.<br>**NOTE**<br>This parameter supports only FLAG_AUTH_READ_URI_PERMISSION, FLAG_AUTH_WRITE_URI_PERMISSION, and FLAG_AUTH_READ_URI_PERMISSION\|FLAG_AUTH_WRITE_URI_PERMISSION. For details about the permissions, see [Flags](js-apis-app-ability-wantConstant.md#flags).|

## IntentEntity<sup>20+</sup>

Defines the struct of an intent entity. It represents key information objects involved during intent execution, including intent parameters and execution results.

You can define intent entities by inheriting this class. The child class must be decorated with [@InsightIntentEntity](./js-apis-app-ability-InsightIntentDecorator.md#insightintententity).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| entityId | string | No| No| ID of the intent entity.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## IntentResult\<T><sup>20+</sup>

Defines the return result of intent execution. The [generic type] is supported.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| code | number | No| No| Error code returned by the intent execution, defined by the developer.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| result | T | No| Yes| Result data returned by the intent execution, typically containing information to be passed back to the system entry point.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## ReturnMode<sup>23+</sup>

Enumerates the modes that define how the execution result of an intent is returned to the intent initiator.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| CALLBACK | 0 | The intent execution result is returned through the [onExecuteInUIAbilityForegroundMode](./js-apis-app-ability-insightIntentExecutor.md#onexecuteinuiabilityforegroundmode) or [onExecuteInUIExtensionAbility](./js-apis-app-ability-insightIntentExecutor.md#onexecuteinuiextensionability) API in the [intent execution base class](./js-apis-app-ability-insightIntentExecutor.md).<br>**Atomic service API**: This API can be used in atomic services since API version 23.|
| FUNCTION | 1 | The intent execution result is returned after the [sendExecuteResult](./js-apis-app-ability-insightIntentProvider.md#insightintentprovidersendexecuteresult) or [sendIntentResult](./js-apis-app-ability-insightIntentProvider.md#insightintentprovidersendintentresult) API in [intent provider management](./js-apis-app-ability-insightIntentProvider.md) is called.<br>**Atomic service API**: This API can be used in atomic services since API version 23.|
