# button.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyi0309-->
<!--Designer: @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=cd8f2bd738cececf58335cdd1d5503bc64cf2541 translatedAt=2026-08-11T09:08:34.891Z pushedAt=2026-08-12T01:01:13.811Z -->

## Overview

Defines **Button** node types for **NativeNode** APIs.

**File to include:** <arkui/node_attributes/button.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 12

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample:** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## Summary

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_ButtonType](#arkui_buttontype) | ArkUI_ButtonType | Enumerates the button types. |

## Enum Description

### ArkUI_ButtonType

```c
enum ArkUI_ButtonType
```

**Description**

Enumerates the button types.

**Since:** 12

| Value | Description |
| -- |-------------------------|
| ARKUI_BUTTON_TYPE_NORMAL = 0 | Normal button (without rounded corners by default). |
| ARKUI_BUTTON_TYPE_CAPSULE = 1 | Capsule-type button (the round corner is half of the height by default). |
| ARKUI_BUTTON_TYPE_CIRCLE = 2 | Circle button. |
| ARKUI_BUTTON_ROUNDED_RECTANGLE = 8 | Rounded rectangle button.<br>**Since:** 19 |