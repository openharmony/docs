# Interfaces (其他)

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## PositionArea<sup>7+</sup>

表示图片指定区域内的数据。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称   | 类型               | 只读|  可选| 说明                                                         |
| ------ | ------------------ | ---| -----|------------------------------------------------------- |
| pixels | ArrayBuffer        | 否 |   否  | 像素。仅支持BGRA_8888格式的图像像素数据。 |
| offset | number             | 否 |   否  |  偏移量。单位：字节。                                                     |
| stride | number             | 否 |   否  | 跨距，内存中每行像素所占的空间。stride >= region.size.width*4。                   |
| region | [Region](#region8) | 否 |   否  |区域，按照区域读写。写入的区域宽度加X坐标不能大于原图的宽度，写入的区域高度加Y坐标不能大于原图的高度。 |

## ImageInfo

表示图片信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称 | 类型          | 只读 | 可选 | 说明       |
| ---- | ------------- | --- |-----|---------- |
| size<sup>6+</sup> | [Size](#size) | 否 |  否  |图片大小。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| density<sup>9+</sup> | number | 否  | 否 |像素密度，单位为ppi。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| stride<sup>11+</sup> | number | 否  | 否  | 跨距，内存中每行像素所占的空间。stride >= region.size.width*4 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| pixelFormat<sup>12+</sup> | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 否  |  否 | 像素格式。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| alphaType<sup>12+</sup> | [AlphaType](arkts-apis-image-e.md#alphatype9)  | 否  |  否  |透明度。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| mimeType<sup>12+</sup> | string  |  否  |   否  |图片真实格式（MIME type）。  |
| isHdr<sup>12+</sup> | boolean  |  否  | 否  | true表示图片为高动态范围（HDR），false表示图片非高动态范围（SDR）。对于[ImageSource](arkts-apis-image-ImageSource.md)，代表源图片是否为HDR；对于[PixelMap](arkts-apis-image-PixelMap.md)，代表解码后的pixelmap是否为HDR。 |

## Size

表示图片尺寸。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称   | 类型   | 只读 |  可选  |说明           |
| ------ | ------ | -- |-----| -------------- |
| height | number | 否  |  否  |输出图片的高，单位：像素。 |
| width  | number | 否  |  否 | 输出图片的宽，单位：像素。 |

## AuxiliaryPictureInfo<sup>13+</sup>

表示辅助图图像信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                      | 类型                                                         | 只读 | 可选 | 说明                                                         |
| ------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| auxiliaryPictureType      | [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13)              | 否   | 否   | 辅助图的图像类型。                                           |
| size         | [Size](#size)                                                | 否   | 否   | 图片大小。 |
| rowStride                 | number                                                       | 否   | 否   | 行距。                                                       |
| pixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7)                           | 否   | 否   | 像素格式。 |
| colorSpace                | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | 否   | 否   | 目标色彩空间。                                               |

## SourceOptions<sup>9+</sup>

ImageSource的初始化选项。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 类型                               | 只读 | 可选 | 说明               |
| ----------------- | ---------------------------------- | ---- | ---- | ------------------ |
| sourceDensity     | number                             | 否   | 否   | 图片资源像素密度，单位为ppi。<br>在解码参数[DecodingOptions](#decodingoptions7)未设置desiredSize的前提下，当前参数SourceOptions.sourceDensity与DecodingOptions.fitDensity非零时将对解码输出的pixelmap进行缩放。<br>缩放后宽计算公式如下(高同理)：(width * fitDensity + (sourceDensity >> 1)) / sourceDensity。|
| sourcePixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 否   | 是   | 图片像素格式，默认值为UNKNOWN。     |
| sourceSize        | [Size](#size)                      | 否   | 是   | 图像像素大小，默认值为空。     |

## InitializationOptions<sup>8+</sup>

PixelMap的初始化选项。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                     | 类型                               | 只读 |可选 |  说明           |
| ------------------------ | ---------------------------------- | ----| -----|  -------------- |
| alphaType<sup>9+</sup>   | [AlphaType](arkts-apis-image-e.md#alphatype9)           | 否   | 是| 透明度。默认值为IMAGE_ALPHA_TYPE_PREMUL。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。      |
| editable                 | boolean                            | 否   | 是| true表示可编辑，false表示不可编辑。默认值为false。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。|
| srcPixelFormat<sup>12+</sup>  | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 否 | 是 | 传入的buffer数据的像素格式。默认值为BGRA_8888。|
| pixelFormat              | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 否 | 是| 生成的pixelMap的像素格式。默认值为RGBA_8888。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。     |
| scaleMode<sup>9+</sup>   | [ScaleMode](arkts-apis-image-e.md#scalemode9)           | 否  | 是 | 缩略值。默认值为0。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。       |
| size                     | [Size](#size)                      | 否  | 否|创建图片大小。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |

## DecodingOptions<sup>7+</sup>

图像解码设置选项。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称               | 类型                               | 只读 | 可选 | 说明             |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | 否   | 是   | 缩略图采样大小，默认值为1。当前只能取1。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| rotate             | number                             | 否   | 是   | 旋转角度。默认值为0。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。       |
| editable           | boolean                            | 否   | 是   | true表示可编辑，false表示不可编辑。默认值为false。当取值为false时，图片不可二次编辑，如writepixels操作将失败。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。  |
| desiredSize        | [Size](#size)                      | 否   | 是   | 期望输出大小，必须为正整数，若与原尺寸比例不一致，则会进行拉伸/缩放到指定尺寸，默认为原始尺寸。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。   |
| desiredRegion      | [Region](#region8)                 | 否   | 是   | 解码图像中由Region指定的矩形区域，当原始图像很大而只需要解码图像的一部分时，可以设置该参数，有助于提升性能，默认为原始大小。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。       |
| desiredPixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 否   | 是   | 解码的像素格式。默认值为RGBA_8888。仅支持设置：RGBA_8888、BGRA_8888和RGB_565。有透明通道图片格式不支持设置RGB_565，如PNG、GIF、ICO和WEBP。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| index              | number                             | 否   | 是   | 解码图片序号。默认值为0，表示第一张图片。当取值为N时，表示第N-1张图片。单帧图片场景中取值只能为0，动图等多帧图片场景中取值范围为：0~（帧数-1）。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。   |
| fitDensity<sup>9+</sup> | number                        | 否   | 是   | 图像像素密度，单位为ppi。默认值为0。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。   |
| desiredColorSpace<sup>11+</sup> | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | 否   | 是   | 目标色彩空间。默认值为UNKNOWN。 |
| desiredDynamicRange<sup>12+</sup> | [DecodingDynamicRange](arkts-apis-image-e.md#decodingdynamicrange12) | 否   | 是   | 目标动态范围，默认值为SDR。<br>通过[CreateIncrementalSource](arkts-apis-image-f.md#imagecreateincrementalsource9)创建的imagesource不支持设置此属性，默认解码为SDR内容。<br>如果平台不支持HDR，设置无效，默认解码为SDR内容。 |
| cropAndScaleStrategy<sup>18+</sup> | [CropAndScaleStrategy](arkts-apis-image-e.md#cropandscalestrategy18) | 否   | 是   | 解码参数如果同时设置desiredRegion与desiredSize，由此决定裁剪与缩放操作的先后策略。<br>仅支持设置：SCALE_FIRST、CROP_FIRST。 |

## DecodingOptionsForPicture<sup>13+</sup>

图像解码设置选项。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称                     | 类型                                                    | 只读 | 可选 | 说明                                                         |
| ------------------------ | ------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| desiredAuxiliaryPictures | Array\<[AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13)> | 否   | 否   | 设置AuxiliaryPicture类型，默认解码所有AuxiliaryPicture类型。 |

## Region<sup>8+</sup>

表示区域信息。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称 | 类型          | 只读 | 可选| 说明         |
| ---- | ------------- | ---- | ---- | ------------ |
| size<sup>7+</sup> | [Size](#size) | 否   | 否   | 区域大小。   |
| x<sup>7+</sup>    | number        | 否   | 否  | 区域左上角横坐标。单位：像素。 |
| y<sup>7+</sup>    | number        | 否  | 否  | 区域左上角纵坐标。单位：像素。 |

## PackingOption

表示图片编码选项。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

| 名称    | 类型   | 只读 | 可选 | 说明                                                |
| ------- | ------ | ---- | ---- | --------------------------------------------------- |
| format  | string | 否   | 否   | 目标格式。</br>当前只支持"image/jpeg"、"image/webp"、"image/png"和"image/heic(或者image/heif)"<sup>12+</sup>、"image/sdr_astc_4x4"<sup>18+</sup>、"image/sdr_sut_superfast_4x4"<sup>18+</sup>（不同硬件设备支持情况不同）。<br>**说明：** 因为jpeg不支持透明通道，若使用带透明通道的数据编码jpeg格式，透明色将变为黑色。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| quality | number | 否   | 否   | 1. 编码中设定输出图片质量的参数，该参数仅对JPEG图片和HEIF图片生效。取值范围为0-100。0质量最低，100质量最高，质量越高生成图片所占空间越大。WebP、PNG等图片均为无损编码。<br> 2.sdr_astc_4x4编码中，可以设定输出图片质量的参数，可选参数：92、85。<br>3. sut编码中，设定输出图片质量可选参数：92。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| bufferSize<sup>9+</sup> | number | 否   | 是   | 接收编码数据的缓冲区大小，单位为Byte。如果不设置大小，默认为25M。如果编码图片超过25M，需要指定大小。bufferSize需大于编码后图片大小。使用[packToFile](arkts-apis-image-ImagePacker.md#packtofile11)不受此参数限制。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| desiredDynamicRange<sup>12+</sup> | [PackingDynamicRange](arkts-apis-image-e.md#packingdynamicrange12) | 否   | 是   | 目标动态范围。默认值为SDR。 |
| needsPackProperties<sup>12+</sup> | boolean | 否   | 是   | 是否需要编码图片属性信息，例如EXIF。true表示需要，false表示不需要。默认值为false。 |

## PackingOptionsForSequence<sup>18+</sup>

描述动图编码参数的选项。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

| 名称          | 类型           | 只读 | 可选 | 说明                                                         |
| ------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| frameCount    | number         | 否   | 否   | GIF编码中指定的帧数。                                        |
| delayTimeList | Array\<number> | 否   | 否   | GIF编码中设定每帧输出图像的延迟时间，取值需大于0。<br>- 单位为10毫秒。例如，取值为10时，实际单帧延迟是100毫秒。<br>- 如果长度小于frameCount，不足的部分将使用delayTimeList中的最后一个值进行填充。 |
| disposalTypes | Array\<number> | 否   | 是   | GIF编码中设定每帧输出图像的帧过渡模式，如果长度小于frameCount，不足的部分将使用disposalTypes中的最后一个值进行填充，可取值如下：<br>- 0：不需要任何操作。<br>- 1：保持图形不变。<br>- 2：恢复背景色。<br>- 3：恢复到之前的状态。 |
| loopCount     | number         | 否   | 是   | 表示在GIF编码中输出图片循环播放次数，取值范围为[0，65535]。<br>0表示无限循环；若无此字段，则表示不循环播放。 |

## ImagePropertyOptions<sup>11+</sup>

表示查询图片属性的索引。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称         | 类型   | 只读 | 可选 | 说明         |
| ------------ | ------ | ---- | ---- | ------------ |
| index        | number | 否   | 是   | 图片序号。默认值为0。   |
| defaultValue | string | 否   | 是   | 默认属性值。默认值为空。 |

## Component<sup>9+</sup>

描述图像颜色分量。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 类型                             | 只读 | 可选 | 说明         |
| ------------- | -------------------------------- | ---- | ---- | ------------ |
| componentType | [ComponentType](arkts-apis-image-e.md#componenttype9) | 是   | 否   | 组件类型。   |
| rowStride     | number                           | 是   | 否   | 行距。读取相机预览流数据时，需要按stride进行读取，使用详情请参考[相机预览花屏解决方案](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-deal-stride-solution)。       |
| pixelStride   | number                           | 是   | 否   | 像素间距。   |
| byteBuffer    | ArrayBuffer                      | 是   | 否   | 组件缓冲区。 |

## HdrStaticMetadata<sup>12+</sup>

静态元数据值，[HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12)中HDR_STATIC_METADATA关键字对应的值。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 类型       | 只读 | 可选 | 说明         |
| ------------- | ----------| -- | -- | ------------ |
| displayPrimariesX     | Array\<number>  | 否 | 否 | 归一化后显示设备三基色的X坐标，数组的长度为3，以0.00002为单位，范围[0.0, 1.0]。  |
| displayPrimariesY     | Array\<number>  | 否 | 否 | 归一化后显示设备三基色的Y坐标，数组的长度为3，以0.00002为单位，范围[0.0, 1.0]。  |
| whitePointX  | number  | 否 | 否 | 归一化后白点值的X坐标，以0.00002为单位，范围[0.0, 1.0]。   |
| whitePointY  | number   | 否 | 否 | 归一化后白点值的Y坐标，以0.00002为单位，范围[0.0, 1.0]。   |
| maxLuminance  | number  | 否 | 否 | 图像主监视器最大亮度。以1为单位，最大值为65535。   |
| minLuminance  | number   | 否 | 否 | 图像主监视器最小亮度。以0.0001为单位，最大值6.55535。   |
| maxContentLightLevel  | number  | 否 | 否 | 显示内容的最大亮度。以1为单位，最大值为65535。   |
| maxFrameAverageLightLevel  | number  | 否 | 否 | 显示内容的最大平均亮度，以1为单位，最大值为65535。 |

## GainmapChannel<sup>12+</sup>

Gainmap图单个通道的数据内容，参考ISO 21496-1。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 类型       | 只读 | 可选 | 说明         |
| ------------- | ----------| -- | -- | ------------ |
| gainmapMax     | number   | 否 | 否 | 增强图像的最大值，参考ISO 21496-1。  |
| gainmapMin     | number   | 否 | 否 | 增强图像的最小值，参考ISO 21496-1。  |
| gamma  | number    | 否 | 否 | gamma值，参考ISO 21496-1。   |
| baseOffset  | number     | 否 | 否 | 基础图的偏移，参考ISO 21496-1。   |
| alternateOffset  | number    | 否 | 否 | 提取的可选择图像偏移量，参考ISO 21496-1。    |

## HdrGainmapMetadata<sup>12+</sup>

Gainmap使用的元数据值，[HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12)中HDR_GAINMAP_METADATA关键字对应的值，参考ISO 21496-1。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 类型       | 只读 | 可选 | 说明         |
| ------------- | ----------| -- | -- | ------------ |
| writerVersion     | number   | 否 | 否 | 元数据编写器使用的版本。  |
| miniVersion     | number   | 否 | 否 | 元数据解析需要理解的最小版本。  |
| gainmapChannelCount  | number    | 否 | 否 | Gainmap的颜色通道数，值为3时RGB通道的元数据值不同，值为1时各通道元数据值相同，参考ISO 21496-1。  |
| useBaseColorFlag  | boolean     | 否 | 否 | 是否使用基础图的色彩空间，参考ISO 21496-1。true表示是，false表示否。   |
| baseHeadroom  | number    | 否 | 否 |  基础图提亮比，参考ISO 21496-1。   |
| alternateHeadroom  | number     | 否 | 否 |  提取的可选择图像提亮比，参考ISO 21496-1。  |
| channels  | Array<[GainmapChannel](#gainmapchannel12)> | 否 | 否 | 各通道的数据，长度为3，参考ISO 21496-1。 |

## GetImagePropertyOptions<sup>(deprecated)</sup>

表示查询图片属性的索引。

> **说明：**
>
> 从API version 11开始不再维护，建议使用[ImagePropertyOptions](#imagepropertyoptions11)代替。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称         | 类型   | 只读 | 可选 | 说明         |
| ------------ | ------ | ---- | ---- | ------------ |
| index        | number | 否   | 是   | 图片序号。默认值为0。   |
| defaultValue | string | 否   | 是   | 默认属性值。默认值为空。 |
