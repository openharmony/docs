# Class (WebPMetadata)

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9684f4c91c960456589583b38b0c172c143553da translatedAt=2026-08-03T03:56:56.745Z pushedAt=2026-08-04T03:14:31.311Z -->

WebPMetadata

WebP image metadata class, which is used to store image metadata.

> **NOTE**
>
> The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## Attributes

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                        | Type  | Read-Only| Optional| Description                                      |
| ---------------------------- | ------ | ---- | ---- | ------------------------------------------ |
| canvasWidth | number | Yes  | Yes  | Canvas width of a WebP image,<br>in pixels.|
| canvasHeight | number | Yes  | Yes  | Canvas height of a WebP image,<br>in pixels.|
| delayTime | number | Yes  | Yes  | Frame delay of a WebP image after clamping. The clamp range is [100, 65535].<br>The unit is milliseconds.|
| unclampedDelayTime | number | Yes  | Yes  | Frame delay of a WebP image without clamping.<br>The unit is milliseconds.|
| loopCount | number | Yes  | Yes  | Number of times the WebP image animation loops. If it is set to **0**, the number of animation loops is not limited.|