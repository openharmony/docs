# AutoFillPopupConfig (System API)

The module describes the size and position information of an auto-fill pop-up.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## AutoFillPopupConfig

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name   | Type          | Mandatory| Description                                      |
| --------- | -------------- | ---- | ------------------------------------------ |
| popupSize | [PopupSize](#popupsize)      | No  | Width and height of the auto-fill pop-up. If this parameter is not set, the width and height are not updated.|
| placement | [PopupPlacement](#popupplacement) | No  | Position of the auto-fill pop-up. If this parameter is not set, the position is not updated.|

## PopupSize

Describes the width and height of the auto-fill pop-up.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| width  | number | Yes  | Width of the auto-fill pop-up.|
| height | number | Yes  | Height of the auto-fill pop-up.|

## PopupPlacement

Enumerates the positions of an auto-fill pop-up.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name        | Value | Description                              |
| ------------ | --- | --------------------------------- |
| LEFT         |  0  |The popup is on the left of the component and aligned with the left center of the component.|
| RIGHT        |  1  |The popup is on the right of the component and aligned with the right center of the component.|
| TOP          |  2  |The popup is at the top of the component and aligned with the top center of the component.|
| BOTTOM       |  3  |The popup is at the bottom of the component and aligned with the bottom center of the component.|
| TOP_LEFT     |  4  |The popup is at the top of the component and aligned with the left edge of the component.|
| TOP_RIGHT    |  5  |The popup is at the top of the component and aligned with the right edge of the component.|
| BOTTOM_LEFT  |  6  |The popup is at the bottom of the component and aligned with the left edge of the component.|
| BOTTOM_RIGHT |  7  |The popup is at the bottom of the component and aligned with the right edge of the component.|
| LEFT_TOP     |  8  |The popup is on the left of the component and aligned with the top edge of the component.|
| LEFT_BOTTOM  |  9  |The popup is on the left of the component and aligned with the bottom edge of the component.|
| RIGHT_TOP    |  10 |The popup is on the right of the component and aligned with the top edge of the component.|
| RIGHT_BOTTOM |  11 |The popup is on the right of the component and aligned with the bottom edge of the component.|
| NONE         |  12 |The position is unspecified.                               |
