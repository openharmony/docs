# Class (TiffMetadata)

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T03:56:41.412Z pushedAt=2026-08-04T03:14:39.345Z -->

TiffMetadata.

TIFF image metadata class, which is used to store image metadata.

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
| primaryChromaticities | number[] | Yes  | Yes  | Chromaticity coordinates of the RGB primaries in an image.|
| tileWidth | number | Yes  | Yes  | Width of each image tile.<br>The unit is px.<br>The value is a positive integer.|
| tileLength | number | Yes  | Yes  | Height of each image tile.<br>The unit is px.<br>The value is a positive integer.|
| dateTime | string | Yes  | Yes  | Date and time associated with an image (usually the last modification time).|
| make | string | Yes  | Yes  | Capture device manufacturer.|
| photometricInterpretation | number | Yes  | Yes  | Interpretation mode of TIFF image pixel colors (such as RGB or grayscale).<br>The value is a positive integer.|
| whitePoint | number[] | Yes  | Yes  | Chromaticity coordinates of the reference white point.|
| documentName | string | Yes  | Yes  | Document or image name.|
| imageDescription | string | Yes  | Yes  | Image content description.|
| software | string | Yes  | Yes  | Software used to create or process images.|
| xResolution | number | Yes  | Yes  | Horizontal resolution (number of pixels per resolution unit).|
| yResolution | number | Yes  | Yes  | Vertical resolution (number of pixels per resolution unit).|
| hostComputer | string | Yes  | Yes  | Host or system used for image processing.|
| transferFunction | string | Yes  | Yes  | Tone transfer curve.|
| artist | string | Yes  | Yes  | Name of the image creator or artist.|
| orientation | [Orientation](arkts-apis-image-e.md#orientation23) | Yes  | Yes  | Image orientation.|
| model | string | Yes  | Yes  | Capture device model name or ID.|
| resolutionUnit | number | Yes  | Yes  | Unit of **XResolution** (horizontal resolution) and **YResolution** (vertical resolution). The value can be inch or centimeter.<br>The value is a positive integer.|
| compression | number | Yes  | Yes  | Compression scheme used for TIFF image data.<br>- **1**: no compression.<br>- **5**: LZW (dictionary-based lossless compression algorithm)<br>- **7**: JPEG baseline.<br>- **8**: DEFLATE (lossless compression algorithm based on LZ77 and Huffman)<br>The value is a positive integer.|
| copyright | string | Yes  | Yes  | Copyright notice of the image.|