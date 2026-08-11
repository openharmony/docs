# Class (JfifMetadata)

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T03:55:22.046Z pushedAt=2026-08-04T03:23:23.669Z -->

JfifMetadata.

JFIF image metadata class, which is used to store image metadata.

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
| densityUnit | number | Yes  | Yes  | Physical unit of measurement for **Xdensity** (horizontal pixel density) and **Ydensity** (vertical pixel density).<br>- **0**: no units (pixel aspect ratio only)<br>- **1**: pixels per inch (DPI)<br>- **2**: pixels per centimeter (DPC)<br>The value is a positive integer.|
| xDensity | number | Yes  | Yes  | Pixel density in the X direction of the JFIF image.<br>The value is a positive integer.|
| yDensity | number | Yes  | Yes  | Pixel density in the Y direction of the JFIF image.<br>The value is a positive integer.|
| isProgressive | boolean | Yes  | Yes  | Whether the image uses progressive encoding, that is, the image gradually improves in clarity through multiple scans during loading. The value **true** indicates yes, and the value **false** indicates no.|
| version | number[] | Yes  | Yes  | JFIF image version.|