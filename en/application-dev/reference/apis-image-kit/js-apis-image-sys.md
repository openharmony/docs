# @ohos.multimedia.image (Image Processing) (System API)

The module provides APIs for image processing. You can use the APIs to create a PixelMap object with specified properties or read image pixel data (even in an area).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.multimedia.image (Image Processing)](arkts-apis-image.md).

## Modules to Import

```ts
import image from '@ohos.multimedia.image';
```

## DecodingOptions<sup>12+</sup>

Describes the image decoding options.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name              | Type             | Read-Only| Optional| Description            |
| ----------------- | ----------------- | ---- | ---- | ---------------- |
| resolutionQuality | [ResolutionQuality](#resolutionquality12) | No  | Yes  | Image quality.|

## ResolutionQuality<sup>12+</sup>

Enumerates the image quality levels.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                        | Value     | Description      |
| ---------------------------- | ------ | ---------- |
| LOW     | 1     | Low image quality, requiring a short decoding time.<br>This is a system API.|
| MEDIUM             | 2    | Medium image quality, requiring a medium decoding time<br>This is a system API.|
| HIGH             | 3    | High image quality, requiring a long decoding time.<br>This is a system API.|
