# @ohos.app.ability.insightIntent (insightIntent)

The **insightIntent** module provides APIs for InsightIntent calls.

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

Enumerates the InsightIntent call execution modes.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| UI_ABILITY_FOREGROUND | 0 | Display a UIAbility in the foreground.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| UI_ABILITY_BACKGROUND | 1 | Start a UIAbility in the background.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| UI_EXTENSION_ABILITY | 2 | Start a UIExtensionAbility.|

## ExecuteResult

Defines the InsightIntent call execution result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| code | number | No| No| Error code returned.|
| result | Record<string, Object> | No| Yes| Execution result returned.|
