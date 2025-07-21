# @ohos.app.ability.insightIntent (Basic Capability for Intent Calls)

The module provides basic capabilities for intent calls.

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

Enumerates the intent call execution modes.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| UI_ABILITY_FOREGROUND | 0 | Display a UIAbility in the foreground.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| UI_ABILITY_BACKGROUND | 1 | Start a UIAbility in the background.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| UI_EXTENSION_ABILITY | 2 | Start a UIExtensionAbility.|

## ExecuteResult

Defines the intent call execution result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| code | number | No| No| Error code returned.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| result | Record<string, Object> | No| Yes| Execution result returned.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| uris<sup>18+</sup> | Array&lt;string&gt; | No| Yes| List of URIs authorized by the intent executor to the intent caller during the call.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| flags<sup>18+</sup> | number | No| Yes| [Flags](js-apis-app-ability-wantConstant.md#flags) of the URIs authorized by the intent executor to the intent caller during the call.<br>**Atomic service API**: This API can be used in atomic services since API version 18.<br>**NOTE**<br>This parameter supports only **FLAG_AUTH_READ_URI_PERMISSION**, **FLAG_AUTH_WRITE_URI_PERMISSION**, and FLAG_AUTH_READ_URI_PERMISSION\|FLAG_AUTH_WRITE_URI_PERMISSION.|

## IntentEntity<sup>20+<sup>

Base class of the [@InsightIntentEntity](./js-apis-app-ability-InsightIntentDecorator.md#insightintententity) decorator. It is used to define intent entities.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| entityId | string | No| No| ID of the intent entity.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## IntentResult\<T><sup>20+<sup>

Describes the result returned after an intent is executed.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| code | number | No| No| Error code returned.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| result | T | No| Yes| Execution result returned.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
