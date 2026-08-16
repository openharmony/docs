# image_span.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Zhang-Dong-hui-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=9d935c682ca66fcb6cb6ddce38110a22b9819131 translatedAt=2026-08-11T09:08:34.599Z pushedAt=2026-08-12T02:04:23.232Z -->

## Overview

Defines enumerations related to **ImageSpan**, which are used to embed images in rich text and control the alignment between images and text. Multiple alignment modes are supported for mixed image-text layout scenarios, enabling precise alignment of images with text and improving the display of rich text.

**File to include:** <arkui/node_attributes/image_span.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 12

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample:** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## Summary

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_ImageSpanAlignment](#arkui_imagespanalignment) | ArkUI_ImageSpanAlignment | Enumerates image alignment modes based on text. |

## Enum Description

### ArkUI_ImageSpanAlignment

```c
enum ArkUI_ImageSpanAlignment
```

**Description**

Enumerates image alignment modes based on text.

**Since:** 12

| Enum Value | Description |
| -- | -- |
| ARKUI_IMAGE_SPAN_ALIGNMENT_BASELINE = 0 | The image is bottom aligned with the text baseline. |
| ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM = 1 | The image is bottom aligned with the text. |
| ARKUI_IMAGE_SPAN_ALIGNMENT_CENTER = 2 | The image is center aligned with the text. |
| ARKUI_IMAGE_SPAN_ALIGNMENT_TOP = 3 | The image is top aligned with the text. |
| ARKUI_IMAGE_SPAN_ALIGNMENT_FOLLOW_PARAGRAPH = 4 | The image alignment mode follows the text component's alignment mode.<br>**Since:** 20 |