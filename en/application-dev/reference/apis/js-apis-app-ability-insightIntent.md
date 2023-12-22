# @ohos.app.ability.insightIntent (insightIntent)

The **insightIntent** module provides APIs for InsightIntent calls.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import insightIntent from '@ohos.app.ability.insightIntent';
```

## ExecuteMode

Enumerates the InsightIntent call execution modes.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| UI_ABILITY_FOREGROUND | 0 | Display a UIAbility in the foreground.|
| UI_ABILITY_BACKGROUND | 1 | Start a UIAbility in the background.|
| UI_EXTENSION_ABILITY | 2 | Start a UIExtensionAbility.|
| SERVICE_EXTENSION_ABILITY | 3 | Start a ServiceExtensionAbility.<br>**System API**: This is a system API.|

## ExecuteResult

Defines the InsightIntent call execution result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| code | number | Yes| Error code returned.|
| result | Record<string, Object> | Yes| Execution result returned.|
