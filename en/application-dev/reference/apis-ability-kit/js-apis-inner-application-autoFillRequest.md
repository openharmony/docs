# AutoFillRequest

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=0dd5abdb86dc8faf6072b7e90ffea179b52ea3b4 translatedAt=2026-08-13T13:21:56.254Z pushedAt=2026-08-17T03:55:16.811Z -->

This module provides the page data in auto-fill and auto-save scenarios, as well as the result returned when auto-fill fails.

**Since**: 26.0.0

## Modules to Import

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## FillRequest

Auto-fill request information.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Name        | Type                                                                    | Read-Only | Optional | Description           |
| ----------- | ----------------------------------------------------------------------- | ---- | ---- | ------------- |
| type        | [AutoFillType](js-apis-inner-application-autoFillType.md)               | No   | No   | Auto-fill type. |
| viewData    | [ViewData](js-apis-inner-application-viewData.md)                       | No   | No   | Page data. |
| triggerType | [AutoFillTriggerType](js-apis-inner-application-autoFillTriggerType.md) | No   | Yes  | Trigger type of the auto-fill service. |

## SaveRequest

Auto-save request information.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction:** This API can be used only in the stage model.

| Name     | Type                                              | Read-Only | Optional | Description |
| -------- | ------------------------------------------------- | --------- | -------- | ----------- |
| viewData | [ViewData](js-apis-inner-application-viewData.md) | No        | No       | Page data.  |

## FillFailureResult

Auto-fill failure result.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction:** This API can be used only in the stage model.

| Name    | Type   | Read-Only | Optional | Description |
| ------- | ------ | --------- | -------- | ----------- |
| errCode | number | No        | No       | Error code. |