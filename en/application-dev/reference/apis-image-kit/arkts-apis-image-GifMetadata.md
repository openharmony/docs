# Class (GifMetadata)

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T03:54:34.830Z pushedAt=2026-08-04T03:29:24.488Z -->

GifMetadata.

GIF image metadata class, which is used to store image metadata.

**Since**: 26.0.0

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## Properties

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                        | Type  | Read-Only| Optional| Description                                      |
| ---------------------------- | ------ | ---- | ---- | ------------------------------------------ |
| delayTime | number | Yes  | Yes  | Frame delay of a GIF image after clamping. The clamp range is [100, 65535].<br>The unit is milliseconds.<br>The value is a positive integer.|
| unclampedDelayTime | number | Yes  | Yes  | Frame delay of a GIF image without clamping.<br>The unit is milliseconds.<br>The value is a positive integer.|
| hasGlobalColorMap | boolean | Yes  | Yes  | Whether the global color table is contained.<br>The value **true** indicates yes, and the value **false** indicates no.|
| loopCount | number | Yes  | Yes  | Number of GIF loops.<br>The value can be **0** or a positive integer. The value **0** indicates infinite looping, and another value indicates the actual number of loops.|
| disposalType | number | Yes  | Yes  | Disposal type for each frame of a GIF image.<br>- **0**: Unspecified.<br>- **1**: Do not dispose.<br>- **2**: Restore to the background color.<br>- **3**: Restore to the previous frame.<br>The value is a positive integer.|
| canvasHeight | number | Yes  | Yes  | Canvas height of a GIF image.<br>The unit is px.|
| canvasWidth | number | Yes  | Yes  | Canvas width of a GIF image.<br>The unit is px.|