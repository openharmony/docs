# @ohos.graphics.hdrCapability (HDR Capability)

The hdrCapability module provides enums related to the High Dynamic Range (HDR) capability.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { hdrCapability } from '@kit.ArkGraphics2D';
```

## HDRFormat

Enumerates the HDR formats.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

| Name                        | Value    | Description                   |
| --------------------------- | ------ | ----------------------- |
| NONE                         | 0      | Unsupported HDR type.|
| VIDEO_HLG                    | 1      | Videos in Hybrid Log-Gamma (HLG) format. |
| VIDEO_HDR10                  | 2      | Videos in HDR10 format. |
| VIDEO_HDR_VIVID              | 3      | Videos in HDR_VIVID format. |
| IMAGE_HDR_VIVID_DUAL         | 4      | Images in HDR_VIVID format, stored in dual JPEG format. |
| IMAGE_HDR_VIVID_SINGLE       | 5      | Images in HDR_VIVID format, stored in single HEIF format. |
| IMAGE_HDR_ISO_DUAL           | 6      | Images in HDR_ISO format, stored in dual JPEG format. |
| IMAGE_HDR_ISO_SINGLE         | 7      | Images in HDR_ISO format, stored in single HEIF format. |
