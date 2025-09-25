# @ohos.multimedia.image (Image Processing) (System API)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

The module provides APIs for image processing. You can use the APIs to create a PixelMap object with specified properties or read image pixel data (even in an area).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.multimedia.image (Image Processing)](arkts-apis-image.md).

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## DecodingOptions<sup>12+</sup>

Describes the image decoding options.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

## image.createPictureByHdrAndSdrPixelMap<sup>20+</sup>

createPictureByHdrAndSdrPixelMap(hdrPixelMap: PixelMap, sdrPixelMap: PixelMap): Promise\<Picture>

Creates a Picture object based on an HDR PixelMap and an SDR PixelMap. The system uses the HDR PixelMap and SDR PixelMap to generate a gainmap. The returned Picture object contains the SDR PixelMap and the generated gainmap, both in RGBA8888 format. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type               | Mandatory| Description            |
| ------------ | ------------------- | ---- | ---------------- |
| hdrPixelMap | [PixelMap](arkts-apis-image-PixelMap.md) | Yes  | HDR PixelMap, with 16-bit or 10-bit depth, in FP16/RGBA1010102/YCBCR_P010 format, and BT2020_HLG color space.|
| sdrPixelMap | [PixelMap](arkts-apis-image-PixelMap.md) | Yes  | SDR PixelMap, with 8-bit depth, in RGBA8888/NV21 format, and P3 color space.|

**Returns**

| Type              | Description             |
| ------------------ | ----------------- |
|Promise\<[Picture](arkts-apis-image-Picture.md)> | Picture object that contains the SDR PixelMap and gainmap, both in RGBA8888 format.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| Error Code| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 7600201      | Unsupported operation. HdrPixelMap's PixelMapFormat is not RGBA_F16\RGBA_1010102\YCBCR_P010, or its color space is not BT2020_HLG. Or sdrPixelMap's PixelMapFormat is not RGBA_8888\NV21\NV12, or its color space is not P3. |

**Example**

```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePictureTest(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("test.jpg"); // SDR
  let imageSource: image.ImageSource = image.createImageSource(rawFile);
  let options1: image.DecodingOptions = {
    desiredDynamicRange : image.DecodingDynamicRange.SDR,
  }
  let options2: image.DecodingOptions = {
    desiredDynamicRange : image.DecodingDynamicRange.HDR, // Decode an SDR PixelMap into an HDR PixelMap using AIHDR.
  }
  let sdrPixelMap = await imageSource.createPixelMap(options1);
  let hdrPixelMap = await imageSource.createPixelMap(options2);

  // Obtain the gainmap generated and encode the gainmap.
  let picture: image.Picture = await image.createPictureByHdrAndSdrPixelMap(hdrPixelMap, sdrPixelMap);
  if (picture != null) {
    console.info('Create picture succeeded');
  } else {
    console.error('Create picture failed');
  }
  const imagePackerObj = image.createImagePacker();
  let packOpts : image.PackingOption = { format : "image/jpeg", quality: 98};
  packOpts.desiredDynamicRange = image.PackingDynamicRange.AUTO;
  const path: string = context.filesDir + "/hdr-test.jpg";
  let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  imagePackerObj.packToFile(picture, file.fd, packOpts).then(() => {
  }).catch((error : BusinessError) => {
    console.error('Failed to pack the image. And the error is: ' + error);
  })
}
```
