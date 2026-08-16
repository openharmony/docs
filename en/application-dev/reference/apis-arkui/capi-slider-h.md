# slider.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyi0309-->
<!--Designer: @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=cd8f2bd738cececf58335cdd1d5503bc64cf2541 translatedAt=2026-08-11T09:10:26.293Z pushedAt=2026-08-12T06:27:33.357Z -->

## Overview

Defines **Slider** node types for **NativeNode** APIs.

**File to include:** <arkui/node_attributes/slider.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 12

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample:** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## Summary

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_SliderBlockStyle](#arkui_sliderblockstyle) | ArkUI_SliderBlockStyle | Enumerates the slider block styles. |
| [ArkUI_SliderDirection](#arkui_sliderdirection) | ArkUI_SliderDirection | Enumerates the scroll directions of the slider. |
| [ArkUI_SliderStyle](#arkui_sliderstyle) | ArkUI_SliderStyle | Enumerates the display styles of the slider block and track. |

## Enum Description

### ArkUI_SliderBlockStyle

```c
enum ArkUI_SliderBlockStyle
```

**Description**

Enumerates the slider block styles.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_SLIDER_BLOCK_STYLE_DEFAULT = 0 | Uses the default slider (circle). |
| ARKUI_SLIDER_BLOCK_STYLE_IMAGE = 1 | Uses an image resource as the slider. |
| ARKUI_SLIDER_BLOCK_STYLE_SHAPE = 2 | Uses a custom shape as the slider. |

### ArkUI_SliderDirection

```c
enum ArkUI_SliderDirection
```

**Description**

Enumerates the scroll directions of the slider.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_SLIDER_DIRECTION_VERTICAL = 0 | Vertical. |
| ARKUI_SLIDER_DIRECTION_HORIZONTAL = 1 | Horizontal. |

### ArkUI_SliderStyle

```c
enum ArkUI_SliderStyle
```

**Description**

Enumerates the display styles of the slider and track.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_SLIDER_STYLE_OUT_SET = 0 | The slider is on the track. |
| ARKUI_SLIDER_STYLE_IN_SET = 1 | The slider is in the track. |
| ARKUI_SLIDER_STYLE_NONE = 2 | There is no slider. |