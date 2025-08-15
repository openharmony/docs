# Interfaces (Others)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## PositionArea<sup>7+</sup>

Describes area information in an image.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name  | Type              | Read Only|  Optional| Description                                                        |
| ------ | ------------------ | ---| -----|------------------------------------------------------- |
| pixels | ArrayBuffer        | No|   No | Pixels of the image. Only pixel data in BGRA_8888 format is supported.|
| offset | number             | No|   No |  Offset for data reading, in bytes.                                                    |
| stride | number             | No|   No | Number of bytes from one row of pixels in memory to the next row of pixels in memory. The value of **stride** must be greater than or equal to the value of **region.size.width** multiplied by 4.                  |
| region | [Region](#region8) | No|   No |Region to read or write. The width of the region to write plus the X coordinate cannot be greater than the width of the original image. The height of the region to write plus the Y coordinate cannot be greater than the height of the original image.|

## ImageInfo

Describes image information.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Type         | Read Only| Optional| Description      |
| ---- | ------------- | --- |-----|---------- |
| size<sup>6+</sup> | [Size](#size) | No|  No |Image size.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| density<sup>9+</sup> | number | No | No|Pixel density, in ppi.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| stride<sup>11+</sup> | number | No | No | Number of bytes from one row of pixels in memory to the next row of pixels in memory.stride >= region.size.width*4 <br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| pixelFormat<sup>12+</sup> | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | No |  No| Pixel format.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| alphaType<sup>12+</sup> | [AlphaType](arkts-apis-image-e.md#alphatype9)  | No |  No |Alpha type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| mimeType<sup>12+</sup> | string  |  No |   No |Actual image format (MIME type). |
| isHdr<sup>12+</sup> | boolean  |  No | No | Whether the image is an HDR image. The value **true** means an HDR image, and **false** means an SDR image. For [ImageSource](arkts-apis-image-ImageSource.md), this parameter specifies whether the source image is in HDR format. For [PixelMap](arkts-apis-image-PixelMap.md), this parameter specifies whether the decoded PixelMap is in HDR format.|

## Size

Describes the size of an image.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name  | Type  | Read Only|  Optional |Description          |
| ------ | ------ | -- |-----| -------------- |
| height | number | No |  No |Image height, in px.|
| width  | number | No |  No| Image width, in px.|

## AuxiliaryPictureInfo<sup>13+</sup>

Describes the auxiliary picture information.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                     | Type                                                        | Read Only| Optional| Description                                                        |
| ------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| auxiliaryPictureType      | [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13)              | No  | No  | Auxiliary picture type.                                          |
| size         | [Size](#size)                                                | No  | No  | Image size.|
| rowStride                 | number                                                       | No  | No  | Row stride.                                                      |
| pixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7)                           | No  | No  | Pixel format.|
| colorSpace                | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | No  | No  | Color space.                                              |

## SourceOptions<sup>9+</sup>

Defines image source initialization options.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Type                              | Read Only| Optional| Description              |
| ----------------- | ---------------------------------- | ---- | ---- | ------------------ |
| sourceDensity     | number                             | No  | No  | Pixel density of the image resource, in ppi.<br>If **desiredSize** is not set in [DecodingOptions](#decodingoptions7) and **SourceOptions.sourceDensity** and **DecodingOptions.fitDensity** are not 0, the PixelMap output after decoding will be scaled.<br>The formula for calculating the width after scaling is as follows (the same applies to the height): (width * fitDensity + (sourceDensity >> 1)) / sourceDensity.|
| sourcePixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | No  | Yes  | Image pixel format. The default value is **UNKNOWN**.    |
| sourceSize        | [Size](#size)                      | No  | Yes  | Image pixel size. The default value is null.    |

## InitializationOptions<sup>8+</sup>

Defines PixelMap initialization options.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                    | Type                              | Read Only|Optional|  Description          |
| ------------------------ | ---------------------------------- | ----| -----|  -------------- |
| alphaType<sup>9+</sup>   | [AlphaType](arkts-apis-image-e.md#alphatype9)           | No  | Yes| Alpha type. The default value is **IMAGE_ALPHA_TYPE_PREMUL**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.     |
| editable                 | boolean                            | No  | Yes| Whether the image is editable. The value **true** means that the image is editable, and **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| srcPixelFormat<sup>12+</sup>  | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | No| Yes| Pixel format of the passed-in buffer data. The default value is **BGRA_8888**.|
| pixelFormat              | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | No| Yes| Pixel format of the generated PixelMap. The default value is **RGBA_8888**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.    |
| scaleMode<sup>9+</sup>   | [ScaleMode](arkts-apis-image-e.md#scalemode9)           | No | Yes| Scale mode. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.      |
| size                     | [Size](#size)                      | No | No|Image size.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|

## DecodingOptions<sup>7+</sup>

Describes the image decoding options.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name              | Type                              | Read Only| Optional| Description            |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | No  | Yes  | Sampling size of the thumbnail. The default value is **1**. Currently, the value can only be **1**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| rotate             | number                             | No  | Yes  | Rotation angle. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.      |
| editable           | boolean                            | No  | Yes  | Whether the image is editable. The value **true** means that the image is editable, and **false** means the opposite. The default value is **false**. If this option is set to **false**, the image cannot be edited again, and operations such as writing pixels will fail.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12. |
| desiredSize        | [Size](#size)                      | No  | Yes  | Expected output size. The value must be a positive integer and defaults to the original image size. If the output size is different from the original size, the output is stretched or scaled to the specified size.<br>Note: If both **desiredSize** and **desiredRegion** are passed to the decoding API, you must also include **cropAndScaleStrategy** to determine whether to crop or scale first. **CROP_FIRST** is recommended.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| desiredRegion      | [Region](#region8)                 | No  | Yes  | Rectangle specified by **Region** in the decoded image. When the original image is large and only a specific part of the image is required, you can set this parameter to improve performance. The default value is the original image size.<br>Note: If both **desiredSize** and **desiredRegion** are passed to the decoding API, you must also include **cropAndScaleStrategy** to determine whether to crop or scale first. **CROP_FIRST** is recommended.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.      |
| desiredPixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | No  | Yes  | Pixel format for decoding. The default value is **RGBA_8888**. Only RGBA_8888, BGRA_8888, and RGB_565 are supported. RGB_565 is not supported for images with alpha channels, such as PNG, GIF, ICO, and WEBP.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| index              | number                             | No  | Yes  | Index of the image to decode. The default value is **0**, indicating the first image. If this parameter is set to N, the (N+1)th image is used. For single-frame images, the value is always **0**. For multi-frame images such as animations, the value ranges from 0 to (Number of frames – 1).<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| fitDensity<sup>9+</sup> | number                        | No  | Yes  | Pixel density, in ppi. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| desiredColorSpace<sup>11+</sup> | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | No  | Yes  | Target color space. The default value is **UNKNOWN**.|
| desiredDynamicRange<sup>12+</sup> | [DecodingDynamicRange](arkts-apis-image-e.md#decodingdynamicrange12) | No  | Yes  | Desired dynamic range. The default value is **SDR**.<br>This property cannot be set for an image source created using [CreateIncrementalSource](arkts-apis-image-f.md#imagecreateincrementalsource9). By default, the image source is decoded as SDR content.<br>If the platform does not support HDR, the setting is invalid and the content is decoded as SDR content by default.|
| cropAndScaleStrategy<sup>18+</sup> | [CropAndScaleStrategy](arkts-apis-image-e.md#cropandscalestrategy18) | No  | Yes  | If **desiredRegion** and **desiredSize** are both specified, the order of cropping and scaling is determined.<br>Only **SCALE_FIRST** and **CROP_FIRST** are supported.|

## DecodingOptionsForPicture<sup>13+</sup>

Describes the image decoding options.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name                    | Type                                                   | Read Only| Optional| Description                                                        |
| ------------------------ | ------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| desiredAuxiliaryPictures | Array\<[AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13)> | No  | No  | Auxiliary picture type. By default, all auxiliary picture types are decoded.|

## Region<sup>8+</sup>

Describes the region information.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Type         | Read Only| Optional| Description        |
| ---- | ------------- | ---- | ---- | ------------ |
| size<sup>7+</sup> | [Size](#size) | No  | No  | Region size.  |
| x<sup>7+</sup>    | number        | No  | No | X coordinate of the upper left corner of the region, in px.|
| y<sup>7+</sup>    | number        | No | No | Y coordinate of the upper left corner of the region, in px.|

## PackingOption

Describes the options for image encoding.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

| Name   | Type  | Read Only| Optional| Description                                               |
| ------- | ------ | ---- | ---- | --------------------------------------------------- |
| format  | string | No  | No  | Format of the packed image.<br>Currently, only the following formats are supported: image/jpeg, image/webp, image/png, image/heic (or image/heif)<sup>12+</sup>, image/sdr_astc_4x4<sup>18+</sup>, image/sdr_sut_superfast_4x4<sup>18+</sup> (depending on the hardware), and image/hdr_astc_4x4<sup>20+</sup>.<br>**NOTE**: The JPEG format does not support the alpha channel. If the JPEG format with the alpha channel is used for data encoding, the transparent color turns black.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| quality | number | No  | No  | Quality of the output image set. This parameter takes effect only for JPEG and HEIF images. The value range is [0, 100]. The value **0** means the lowest quality, and **100** means the highest quality. The higher the quality, the larger the space occupied by the generated image. WebP and PNG images are lossless.<br>In the case of sdr_astc_4x4 encoding, the parameter can be set to **92** and **85**.<br>In the case of sut encoding, the parameter can be set to **92**.<br>(Available since API version 20) In the case of hdr_astc_4x4 encoding, the parameter can be set to **85**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| bufferSize<sup>9+</sup> | number | No  | Yes  | Size of the buffer for receiving the encoded data, in bytes. If this parameter is not set, the default value 25 MB is used. If the size of an image exceeds 25 MB, you must specify the size. The value of **bufferSize** must be greater than the size of the encoded image. The use of [packToFile](arkts-apis-image-ImagePacker.md#packtofile11) is not restricted by this parameter.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| desiredDynamicRange<sup>12+</sup> | [PackingDynamicRange](arkts-apis-image-e.md#packingdynamicrange12) | No  | Yes  | Desired dynamic range. The default value is **SDR**.|
| needsPackProperties<sup>12+</sup> | boolean | No  | Yes  | Whether to encode image property information, for example, EXIF. The value **true** means to encode image property information, and **false** means the opposite. The default value is **false**.|

## PackingOptionsForSequence<sup>18+</sup>

Defines the options for encoding animated images.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

| Name         | Type          | Read Only| Optional| Description                                                        |
| ------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| frameCount    | number         | No  | No  | Number of frames specified in GIF encoding.                                       |
| delayTimeList | Array\<number> | No  | No  | Delay time of each frame in GIF encoding. The value must be greater than 0.<br>The unit is 10 milliseconds. For example, if this parameter is set to 10, the actual delay per frame is 100 ms.<br>If the array length is less than **frameCount**, the last value in the array will be used for the remaining frames.|
| disposalTypes | Array\<number> | No  | Yes  | Array that defines how each image frame transitions. If the array length is less than **frameCount**, the last value in the array will be used for the remaining frames. The values can be:<br>- **0**: No operation is required.<br>- **1**: Keeps the image unchanged.<br>- **2**: Restores the background color.<br>- **3**: Restores to the previous state.|
| loopCount     | number         | No  | Yes  | Number of times that the output image in GIF encoding loops. The value range is [0, 65535].<br>The value **0** means an infinite loop. If this field is not carried, loop playback is not performed.|

## ImagePropertyOptions<sup>11+</sup>

Describes the image properties.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name        | Type  | Read Only| Optional| Description        |
| ------------ | ------ | ---- | ---- | ------------ |
| index        | number | No  | Yes  | Index of the image. The default value is **0**.  |
| defaultValue | string | No  | Yes  | Default property value. The default value is null.|

## Component<sup>9+</sup>

Describes the color components of an image.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Type                            | Read Only| Optional| Description        |
| ------------- | -------------------------------- | ---- | ---- | ------------ |
| componentType | [ComponentType](arkts-apis-image-e.md#componenttype9) | Yes  | No  | Color component type.  |
| rowStride     | number                           | Yes  | No  | Row stride. The camera preview stream data needs to be read by stride. For details, see [Solution to Screen Artifacts During Camera Preview](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-deal-stride-solution).      |
| pixelStride   | number                           | Yes  | No  | Pixel stride.  |
| byteBuffer    | ArrayBuffer                      | Yes  | No  | Component buffer.|

## HdrStaticMetadata<sup>12+</sup>

Describes the static metadata keys, that is, the values available for **HDR_STATIC_METADATA** in [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12).

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Type      | Read Only| Optional| Description        |
| ------------- | ----------| -- | -- | ------------ |
| displayPrimariesX     | Array\<number>  | No| No| X coordinate of the three primary colors of the display device after normalization. The array length is 3. The unit is 0.00002. The value range is [0.0, 1.0]. |
| displayPrimariesY     | Array\<number>  | No| No| Y coordinate of the three primary colors of the display device after normalization. The array length is 3. The unit is 0.00002. The value range is [0.0, 1.0]. |
| whitePointX  | number  | No| No| X coordinate of the white point after normalization. The unit is 0.00002. The value range is [0.0, 1.0].  |
| whitePointY  | number   | No| No| Y coordinate of the white point after normalization. The unit is 0.00002. The value range is [0.0, 1.0].  |
| maxLuminance  | number  | No| No| Maximum luminance of the main monitor. The unit is 1, and the maximum value is 65535.  |
| minLuminance  | number   | No| No| Minimum luminance of the main monitor. The unit is 0.0001, and the maximum value is 6.55535.  |
| maxContentLightLevel  | number  | No| No| Maximum luminance of the displayed content. The unit is 1, and the maximum value is 65535.  |
| maxFrameAverageLightLevel  | number  | No| No| Maximum average luminance of the displayed content. The unit is 1, and the maximum value is 65535.|

## GainmapChannel<sup>12+</sup>

Describes the data content of a single channel of the gain map. For details, see ISO 21496-1.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Type      | Read Only| Optional| Description        |
| ------------- | ----------| -- | -- | ------------ |
| gainmapMax     | number   | No| No| Maximum value of the gain map. For details, see ISO 21496-1. |
| gainmapMin     | number   | No| No| Minimum value of the gain map. For details, see ISO 21496-1. |
| gamma  | number    | No| No| Gamma. For details, see ISO 21496-1.  |
| baseOffset  | number     | No| No| Offset of the base graphic. For details, see ISO 21496-1.  |
| alternateOffset  | number    | No| No| Offset of the alternative graphic that can be extracted. For details, see ISO 21496-1.   |

## HdrGainmapMetadata<sup>12+</sup>

Describes the metadata keys used by a gain map, that is, the values available for **HDR_GAINMAP_METADATA** in [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12). For details, see ISO 21496-1.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Type      | Read Only| Optional| Description        |
| ------------- | ----------| -- | -- | ------------ |
| writerVersion     | number   | No| No| Version used by the metadata editor. |
| miniVersion     | number   | No| No| Minimum version that needs to be understood for metadata parsing. |
| gainmapChannelCount  | number    | No| No| Number of color channels of the gain map. When the value is 3, the metadata values of the RGB channels are different. When the value is 1, the metadata values of the RGB channels are the same. For details, see ISO 21496-1. |
| useBaseColorFlag  | boolean     | No| No| Whether to use the color space of the base graphic. For details, see ISO 21496-1. The value **true** means to use the color space of the base graphic, and **false** means the opposite.  |
| baseHeadroom  | number    | No| No|  Headroom of the base graphic, which means the additional brightness that can be added to the base graphic. For details, see ISO 21496-1.  |
| alternateHeadroom  | number     | No| No|  Headroom of the alternate graphic. For details, see ISO 21496-1. |
| channels  | Array<[GainmapChannel](#gainmapchannel12)> | No| No| Number of channels. The length is 3. For details, see ISO 21496-1.|

## GetImagePropertyOptions<sup>(deprecated)</sup>

Describes the image properties.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [ImagePropertyOptions](#imagepropertyoptions11).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name        | Type  | Read Only| Optional| Description        |
| ------------ | ------ | ---- | ---- | ------------ |
| index        | number | No  | Yes  | Index of the image. The default value is **0**.  |
| defaultValue | string | No  | Yes  | Default property value. The default value is null.|
