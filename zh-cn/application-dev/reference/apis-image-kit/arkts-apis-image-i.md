# Interfaces (其他)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

本模块提供图片处理相关的多种接口，涵盖图片区域数据访问、图片信息查询、图像解码与编码配置、元数据管理、HDR合成等能力，适用于图片解码、编码、元数据查询和HDR图像处理等场景。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## PositionArea<sup>7+</sup>

表示图片指定区域内的数据。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称   | 类型               | 只读|  可选| 说明                                                    |
| ------ | ------------------ | ---| -----|------------------------------------------------------- |
| pixels | ArrayBuffer        | 否 |   否  | 像素数据缓冲区。                                        |
| offset | number             | 否 |   否  | 偏移量。单位：字节（Byte）。                             |
| stride | number             | 否 |   否  | 跨距，内存中每行像素所占的空间。单位：字节（Byte）。       |
| region | [Region](#region8) | 否 |   否  | 区域信息，用于按区域进行图像数据的读写。指定的区域宽度加X坐标不能大于原图的宽度，指定的区域高度加Y坐标不能大于原图的高度。 |

## ImageInfo

表示图像的基本信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称 | 类型          | 只读 | 可选 | 说明       |
| ---- | ------------- | --- |-----|---------- |
| size | [Size](#size) | 否 |  否  | 图像尺寸。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| density<sup>9+</sup> | number | 否  | 否 | 像素密度。单位：ppi（像素/英寸）。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| stride<sup>11+</sup> | number | 否  | 否  | 跨距（行跨距），内存中每行像素所占的空间。单位：字节（Byte）。跨距 >= 图像宽度 * 每像素字节数。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| pixelFormat<sup>12+</sup> | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 否  |  否 | 像素格式。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| alphaType<sup>12+</sup> | [AlphaType](arkts-apis-image-e.md#alphatype9)  | 否  |  否  | 透明度类型。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| mimeType<sup>12+</sup> | string  |  否  |   否  | 图片真实格式（MIME type）。<br>图片解码和图片编码支持格式的范围不同，请避免直接将解码得到的图片真实格式作为图片编码时[PackingOption](#packingoption)的format。<br>可以使用ImageSource[属性](arkts-apis-image-ImageSource.md#属性)中的supportedFormats和ImagePacker[属性](arkts-apis-image-ImagePacker.md#属性)中的supportedFormats查看解码和编码支持的格式范围。  |
| isHdr<sup>12+</sup> | boolean  |  否  | 否  | true表示图像为高动态范围（HDR），false表示图像非高动态范围（SDR）。对于[ImageSource](arkts-apis-image-ImageSource.md)，代表源图片是否为HDR；对于[PixelMap](arkts-apis-image-PixelMap.md)，代表解码后的PixelMap是否为HDR。 |

## Size

表示图像尺寸。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称   | 类型   | 只读 |  可选  | 说明           |
| ------ | ------ | -- |-----| -------------- |
| height | number | 否  | 否 | 图像或区域的高度。单位：像素（px）。取值范围是正整数。 |
| width  | number | 否  | 否 | 图像或区域的宽度。单位：像素（px）。取值范围是正整数。 |

## HdrComposeOptions<sup>23+</sup>

Picture合成HDR时可配置的参数选项。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称         | 类型   | 只读 | 可选 | 说明         |
| ------------ | ------ | ---- | ---- | ------------ |
| desiredPixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7)  | 否   | 是   | 用于合成图像的像素格式，支持RGBA_1010102、YCBCR_P010和YCRCB_P010格式。 |

## AuxiliaryPictureInfo<sup>13+</sup>

表示辅助图的图像信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                      | 类型                                                         | 只读 | 可选 | 说明                                                         |
| ------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| auxiliaryPictureType      | [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13)              | 否   | 否   | 辅助图的图像类型。                                           |
| size         | [Size](#size)                                                | 否   | 否   | 图片大小。 |
| rowStride                 | number                                                       | 否   | 否   | 行跨距。单位：字节（Byte）。应大于或等于图像每行像素数据所占的字节数，不满足时数据读取异常。                                                       |
| pixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7)                           | 否   | 否   | 像素格式。 |
| colorSpace                | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | 否   | 否   | 目标色彩空间。                                               |

## SourceOptions<sup>9+</sup>

ImageSource的初始化选项。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 类型                               | 只读 | 可选 | 说明               |
| ----------------- | ---------------------------------- | ---- | ---- | ------------------ |
| sourceDensity     | number                             | 否   | 否   | 图片资源像素密度。单位：ppi（像素/英寸）。<br>在解码参数[DecodingOptions](#decodingoptions7)未设置desiredSize的前提下，当前参数SourceOptions.sourceDensity与DecodingOptions.fitDensity非零时将对解码输出的pixelmap进行缩放。<br>缩放后宽计算公式如下(高同理)：(width * fitDensity + (sourceDensity >> 1)) / sourceDensity。|
| sourcePixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 否   | 是   | 图片像素格式，默认值为UNKNOWN。     |
| sourceSize        | [Size](#size)                      | 否   | 是   | 图像像素大小，默认值为空。     |

## InitializationOptions<sup>8+</sup>

PixelMap的初始化选项。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                     | 类型                               | 只读 |可选 |  说明           |
| ------------------------ | ---------------------------------- | ----| -----|  -------------- |
| alphaType<sup>9+</sup>   | [AlphaType](arkts-apis-image-e.md#alphatype9)           | 否   | 是 | 透明度类型。默认值为IMAGE_ALPHA_TYPE_PREMUL。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。      |
| editable                 | boolean                            | 否   | 是 | 图像像素是否可被编辑。true表示可被编辑，false表示不可被编辑。设为false时，可提升图像的渲染和传输性能，但是图像不可被二次编辑，例如，writePixels操作将失败。默认值为false。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。|
| srcPixelFormat<sup>12+</sup>  | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 否 | 是 | 传入的缓冲区数据的像素格式。默认值为BGRA_8888。 |
| pixelFormat              | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 否 | 是| 生成的PixelMap的像素格式。默认值为RGBA_8888。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。     |
| scaleMode<sup>9+</sup>   | [ScaleMode](arkts-apis-image-e.md#scalemode9)           | 否  | 是 | 缩放模式。默认值为FIT_TARGET_SIZE。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。       |
| size                     | [Size](#size)                      | 否  | 否 | 创建的图像尺寸，宽高值必须为正整数。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |

## DecodingOptions<sup>7+</sup>

图像解码设置选项。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称               | 类型                               | 只读 | 可选 | 说明             |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | 否   | 是   | 缩略图采样大小，默认值为1。当前只能取1。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| rotate             | number                             | 否   | 是   | 旋转角度。单位：角度（deg）。默认值为0。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。       |
| editable           | boolean                            | 否   | 是   | 图像像素是否可被编辑。true表示可被编辑，false表示不可被编辑，默认值为false。<br>当取值为false时，可提升图像的渲染和传输性能，但是图像不可被二次编辑。例如，writePixels操作将失败。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。  |
| desiredSize        | [Size](#size)                      | 否   | 是   | 期望输出大小，必须为正整数，若与原尺寸比例不一致，则会进行拉伸/缩放到指定尺寸，默认为原始尺寸。<br>注意：若解码接口同时传入了desiredSize参数与desiredRegion参数，需进一步传入cropAndScaleStrategy参数指定缩放与裁剪的先后顺序，推荐设置CROP_FIRST。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。   |
| desiredRegion      | [Region](#region8)                 | 否   | 是   | 解码图像中由Region指定的矩形区域，当原始图像很大而只需要解码图像的一部分时，可以设置该参数，有助于提升性能，默认为原始大小。<br>注意：若解码接口同时传入了desiredSize参数与desiredRegion参数，需进一步传入cropAndScaleStrategy参数指定缩放与裁剪的先后顺序，推荐设置CROP_FIRST。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。       |
| desiredPixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 否   | 是   | 解码的像素格式。默认值为RGBA_8888。具体支持的目标像素格式与输入图片格式、desiredDynamicRange及设备能力有关，详见[设置解码输出像素格式](../../media/image/image-decoding.md#设置解码输出像素格式)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| index              | number                             | 否   | 是   | 解码图片序号。默认值为0，表示第一张图片。当取值为N时，表示第N+1张图片。单帧图片场景中index取值只能为0，动图等多帧图片场景中index的取值范围为：[0, (帧数-1)]。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。   |
| fitDensity<sup>9+</sup> | number                        | 否   | 是   | 图像像素密度。单位：ppi（像素/英寸）。默认值为0。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。   |
| desiredColorSpace<sup>11+</sup> | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | 否   | 是   | 目标色彩空间。默认值为UNKNOWN。 |
| desiredDynamicRange<sup>12+</sup> | [DecodingDynamicRange](arkts-apis-image-e.md#decodingdynamicrange12) | 否   | 是   | 目标动态范围，默认值为SDR。<br>通过[CreateIncrementalSource](arkts-apis-image-f.md#imagecreateincrementalsource9)创建的ImageSource不支持设置此属性，默认解码为SDR内容。<br>如果平台不支持HDR，设置无效，默认解码为SDR内容。 |
| cropAndScaleStrategy<sup>18+</sup> | [CropAndScaleStrategy](arkts-apis-image-e.md#cropandscalestrategy18) | 否   | 是   | 解码参数如果同时设置desiredRegion与desiredSize，由此决定裁剪与缩放操作的先后策略。<br>仅支持设置：SCALE_FIRST、CROP_FIRST。 |

## DecodingOptionsForPicture<sup>13+</sup>

图像解码设置选项。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称                     | 类型                                                    | 只读 | 可选 | 说明                                                         |
| ------------------------ | ------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| desiredAuxiliaryPictures | Array\<[AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13)> | 否   | 否   | 设置AuxiliaryPicture类型，当未指定或传入空的Array时，系统会解码所有可用的AuxiliaryPicture类型。 <br>如果不希望解码任何辅助图，可以直接解码为PixelMap，使用PixelMap创建仅包含主图的Picture。|
| desiredSizeForMainPixelMap<sup>24+</sup> | [Size](#size) | 否   | 是   | 期望输出主图大小（必须为正整数），默认为主图原始尺寸。单位：像素（px）。<br>若主图原始尺寸与指定尺寸不一致，则会进行拉伸/缩放到指定尺寸。<br>辅助图的宽度与高度均与主图按照同比例进行相应拉伸/缩放。<br>**模型约束：** 此接口仅可在Stage模型下使用。|
| desiredPixelFormat<sup>24+</sup> | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 否   | 是   | 解码的像素格式。默认值为RGBA_8888。<br>仅支持设置：RGBA_8888、BGRA_8888、RGB_565、NV12及NV21。<br>当设置其他不支持的像素格式时，返回解码失败。<br>**模型约束：** 此接口仅可在Stage模型下使用。|

## DecodingOptionsForThumbnail

缩略图解码参数选项。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称                      | 类型    | 只读 | 可选 | 说明                                                         |
| ------------------------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| generateThumbnailIfAbsent | boolean | 否   | 是   | 指定图像无缩略图时是否生成缩略图。true表示生成，false表示不生成。默认值为true。<br>当图片文件中无缩略图且generateThumbnailIfAbsent为false时，返回undefined（抛出错误码[7700303 图片不包含缩略图数据](errorcode-image.md#7700303-图片不包含缩略图数据)）。 |
| maxGeneratedPixelDimension | number  | 否   | 是   | 用于指定生成缩略图的最大边长（宽和高中较大的那一边），较短的一边会根据长边的缩放比例进行缩放。此参数仅在generateThumbnailIfAbsent设置为true时生效。<br>该值应为整数，默认值为512。生成后的缩略图，宽和高都会限制在maxGeneratedPixelDimension以内。<br>若按该参数计算后，缩略图的宽或高小于1像素（取整后为0），则不会生成缩略图。<br>单位：像素（px）。 |

## Region<sup>8+</sup>

表示区域信息。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称 | 类型          | 只读 | 可选| 说明         |
| ---- | ------------- | ---- | ---- | ------------ |
| size | [Size](#size) | 否   | 否   | 区域尺寸。    |
| x    | number        | 否   | 否  | 区域左上角像素的横坐标（X坐标）。单位：像素（px）。 |
| y    | number        | 否  | 否  | 区域左上角像素的纵坐标（Y坐标）。单位：像素（px）。 |

## PackingSizeLimit

图片编码的大小限制。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

| 名称 | 类型          | 只读 | 可选| 说明         |
| ---- | ------------- | ---- | ---- | ------------ |
| maxSize | [Size](#size) | 否   | 否   |  最大编码尺寸。<br>当指定的width或者height大于0时，原图尺寸超过限制将保持原宽高比进行缩放，确保图像尺寸不超过该边界。<br>默认值为{width: 0, height: 0}，表示不限制编码尺寸。<br>单位：像素（px）。 |
| level    | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 否   | 否  | 缩放时采用的缩放算法。默认值是AntiAliasingLevel.NONE。 |

## PackingOption

表示图片编码选项。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

| 名称    | 类型   | 只读 | 可选 | 说明                                                |
| ------- | ------ | ---- | ---- | --------------------------------------------------- |
| format  | string | 否   | 否   | 目标格式。</br>- 当[输入为ImageSource或PixelMap](../../media/image/image-encoding.md)时，支持"image/jpeg"、"image/webp"、"image/png"和"image/heic（或者image/heif）"<sup>12+</sup>、"image/sdr_astc_4x4"<sup>18+</sup>、"image/sdr_sut_superfast_4x4"<sup>18+</sup>（不同硬件设备支持情况不同）、"image/hdr_astc_4x4"<sup>20+</sup>。<br>- 当[输入为Picture](../../media/image/image-picture-encoding.md)时，仅支持"image/jpeg"和"image/heic（或者image/heif）"<sup>12+</sup>。<br>- gif图片编码需要输入多个PixelMap，并指定format为"image/gif"，使用[packToDataFromPixelmapSequence](./arkts-apis-image-ImagePacker.md#packtodatafrompixelmapsequence18)或[packToFileFromPixelmapSequence](./arkts-apis-image-ImagePacker.md#packtofilefrompixelmapsequence18)接口进行编码。<br>**说明：** 因为jpeg不支持透明通道，若使用带透明通道的数据编码jpeg格式，透明色将变为黑色。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| quality | number | 否   | 否   | 1. 编码中设定输出图片质量的参数，该参数仅对JPEG图片和HEIF图片生效。取值范围：[0, 100]。0质量最低，100质量最高，质量越高生成图片所占空间越大。WebP、PNG等图片均为无损编码。<br> 2.sdr_astc_4x4编码中，可以设定输出图片质量的参数，可选参数：92、85。<br>3. sut编码中，设定输出图片质量可选参数：92。<br>4. （API version 20支持）hdr_astc_4x4编码中，可以设定输出图片质量的参数，可选参数：85。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| bufferSize<sup>9+</sup> | number | 否   | 是   | 接收编码数据的缓冲区大小。单位：字节（Byte）。如果不设置大小，默认为25MB。如果编码图片超过25MB，需要指定大小。bufferSize需大于编码后图片大小。使用[packToFile](arkts-apis-image-ImagePacker.md#packtofile11)不受此参数限制。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| desiredDynamicRange<sup>12+</sup> | [PackingDynamicRange](arkts-apis-image-e.md#packingdynamicrange12) | 否   | 是   | 目标动态范围。默认值为SDR。 |
| needsPackProperties<sup>12+</sup> | boolean | 否   | 是   | 是否需要编码图片属性信息，例如EXIF。true表示需要，false表示不需要。默认值为false。 |
| maxEmbedThumbnailDimension | number | 否 | 是 | 用于指定编码过程中生成缩略图的最大边长（宽和高中较大的那一边），较短的一边会根据长边的缩放比例进行缩放。此参数仅在needsPackProperties设置为true时有效。<br>该值应为整数，默认值为0。<br>若未指定此参数，或根据该尺寸计算出生成的缩略图宽/高为0，则编码过程中不会生成缩略图。<br>单位：像素（px）。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| tiffPackingOptions | [PackingOptionsForTiff](#packingoptionsfortiff) | 否 | 是 | TIFF图像编码选项。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| backgroundColor | number | 否   | 是   | 用于指定编码过程中透明区域填充的背景颜色。<br>当图片像素为RGBA_8888，且编码的目标格式不支持透明度（如"image/jpeg"或"image/heif"）时，透明区域将填充为指定背景颜色（格式：0xRRGGBB），默认值为 0（黑色）。<br>PNG、WebP等支持透明度的格式会忽略此参数。<br>颜色范围：0x000000 - 0xFFFFFF<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| sizeLimit | PackingSizeLimit | 否   | 是   | 用于指定编码输出图像的最大尺寸限制。<br>当原图宽度或高度超过最大尺寸maxSize的限制时，保持宽高比不变进行等比例缩小，确保输出图像尺寸不超过指定边界。缩放过程由level参数控制采用的缩放算法。<br>若未指定此参数，或根据最大尺寸计算的输出图宽/高为0，则按原图尺寸编码。<br>单位：像素（px）。<br>参数规则：<br>- maxSize = {0, 0}：不限制最大编码尺寸，按原图尺寸编码<br>- maxSize.width > 0而maxSize.height <= 0：限制最大宽度，高度不限（使用原图高度）<br>- maxSize.width <= 0而maxSize.height > 0：限制最大高度，宽度不限（使用原图宽度）<br>- maxSize.width > 0且maxSize.height > 0：宽高同时限制，选择较小的缩放比例<br>默认值：{maxSize: {width: 0, height: 0}, level: AntiAliasingLevel.NONE}<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| needsPackGPS | boolean | 否   | 是   | 是否在编码过程中保留GPS隐私信息。<br>true表示保留GPS信息，不进行隐私处理。false表示移除GPS信息（仅在源图像包含EXIF且needsPackProperties设置为true时生效）。默认值为true。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## PackingOptionsForSequence<sup>18+</sup>

描述动图编码参数的选项。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

| 名称          | 类型           | 只读 | 可选 | 说明                                                         |
| ------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| frameCount    | number         | 否   | 否   | GIF编码中指定的帧数。                                        |
| delayTimeList | Array\<number> | 否   | 否   | GIF编码中设定每帧输出图像的延迟时间，取值需大于0。<br>- 单位：10毫秒（ms）。例如，取值为10时，实际单帧延迟是100毫秒。<br>- 如果长度小于frameCount，不足的部分将使用delayTimeList中的最后一个值进行填充。 |
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
| rowStride     | number                           | 是   | 否   | 行距。单位：字节（Byte）。读取相机预览流数据时，需要按stride进行读取，使用详情请参考[相机预览花屏解决方案](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-deal-stride-solution)。       |
| pixelStride   | number                           | 是   | 否   | 像素间距。单位：字节（Byte）。   |
| byteBuffer    | ArrayBuffer                      | 是   | 否   | 组件缓冲区。 |

## HdrStaticMetadata<sup>12+</sup>

静态元数据值，[HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12)中HDR_STATIC_METADATA关键字对应的值。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 类型       | 只读 | 可选 | 说明         |
| ------------- | ----------| -- | -- | ------------ |
| displayPrimariesX     | Array\<number>  | 否 | 否 | 归一化后显示设备三基色的X坐标。数组的长度为3，按R、G、B顺序存储，以0.00002为单位，取值范围是[0.0, 0.99998]。 |
| displayPrimariesY     | Array\<number>  | 否 | 否 | 归一化后显示设备三基色的Y坐标。数组的长度为3，按R、G、B顺序存储，以0.00002为单位，取值范围是[0.0, 0.99998]。 |
| whitePointX  | number  | 否 | 否 | 归一化后白点值的X坐标。以0.00002为单位，取值范围是[0.0, 0.99998]。 |
| whitePointY  | number   | 否 | 否 | 归一化后白点值的Y坐标。以0.00002为单位，取值范围是[0.0, 0.99998]。 |
| maxLuminance  | number  | 否 | 否 | 图像主监视器最大亮度。浮点数，以1为单位，取值范围是[0, 65535]。单位：尼特（nit）。 |
| minLuminance  | number   | 否 | 否 | 图像主监视器最小亮度。以0.0001为单位，取值范围是[0, 6.5535]。单位：尼特（nit）。 |
| maxContentLightLevel  | number  | 否 | 否 | 显示内容的最大亮度。浮点数，以1为单位，取值范围是[0, 65535]。单位：尼特（nit）。   |
| maxFrameAverageLightLevel  | number  | 否 | 否 | 显示内容的最大平均亮度。浮点数，以1为单位，取值范围是[0, 65535]。单位：尼特（nit）。 |

## GainmapChannel<sup>12+</sup>

HDR增益图单个通道的数据内容，参考ISO 21496-1。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 类型       | 只读 | 可选 | 说明         |
| ------------- | ----------| -- | -- | ------------ |
| gainmapMax     | number   | 否 | 否 | 增益图的最大值。浮点数，取值范围是(0, +∞)且必须大于gainmapMin，参考ISO 21496-1。  |
| gainmapMin     | number   | 否 | 否 | 增益图的最小值。浮点数，取值可以为0或负值但必须小于gainmapMax，参考ISO 21496-1。  |
| gamma  | number    | 否 | 否 | 增益曲线的Gamma校正值。浮点数，取值范围是(0, +∞)，参考ISO 21496-1。   |
| baseOffset  | number     | 否 | 否 | 基础图的偏移量。浮点数，参考ISO 21496-1。   |
| alternateOffset  | number    | 否 | 否 | 可选择图像的偏移量。浮点数，参考ISO 21496-1。    |

## ImageMetadata<sup>23+</sup>

图像的元数据集。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                    | 类型                    | 只读 | 可选 | 说明                            |
| ----------------------- | ----------------------- | ---- | ---- | ------------------------------- |
| exifMetadata            | [ExifMetadata](arkts-apis-image-ExifMetadata.md) | 否   | 是   | Exif元数据。                    |
| makerNoteHuaweiMetadata | [MakerNoteHuaweiMetadata](arkts-apis-image-MakerNoteHuaweiMetadata.md) | 否   | 是   | 来自Huawei相机的照片元数据。 |
| heifsMetadata | [HeifsMetadata](arkts-apis-image-HeifsMetadata.md) | 否   | 是   | HEIF序列图像元数据类，用于存储图像的元数据。 |
| webPMetadata<sup>24+</sup> | [WebPMetadata](arkts-apis-image-WebPMetadata.md) | 否   | 是   | WebP图像元数据类，用于存储图像的元数据。 |
| dngMetadata<sup>24+</sup> | [DngMetadata](#dngmetadata24) | 否   | 是   | DNG图像元数据。 |
| gifMetadata | [GifMetadata](arkts-apis-image-GifMetadata.md) | 否   | 是   | GIF图像元数据。<br>**起始版本：** 26.0.0 |
| tiffMetadata | [TiffMetadata](arkts-apis-image-TiffMetadata.md) | 否   | 是   | TIFF图像元数据。<br>**起始版本：** 26.0.0 |
| jfifMetadata | [JfifMetadata](arkts-apis-image-JfifMetadata.md) | 否   | 是   | JFIF图像元数据。<br>**起始版本：** 26.0.0 |
| pngMetadata | [PngMetadata](arkts-apis-image-PngMetadata.md) | 否   | 是   | PNG图像元数据。<br>**起始版本：** 26.0.0 |
| xmpMetadata | [XMPMetadata](arkts-apis-image-XMPMetadata.md) | 否   | 是   | XMP元数据。<br>**起始版本：** 26.0.0 |
| avisMetadata | [AvisMetadata](arkts-apis-image-AvisMetadata.md) | 否   | 是   | AVIS图像元数据。<br>**起始版本：** 26.0.0 |

## DngMetadata<sup>24+</sup>

Dng图像元数据类，用于存储图像的元数据。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                         | 类型 | 只读 | 可选 | 说明                                       |
| ---------------------------- | ------ | ---- | ---- | ------------------------------------------ |
| dngVersion | number[] | 是   | 是 | DNG图片的版本号。 |
| dngBackwardVersion | number[] | 是 | 是   | DNG文件向后兼容的最低版本号。 |
| uniqueCameraModel | string | 是 | 是 | 相机的唯一型号标识，用于区分不同设备。 |
| localizedCameraModel | string | 是 | 是 | 本地化后的相机型号名称。 |
| cfaPlaneColor | number[] | 是 | 是 | CFA（Color Filter Array）各平面的颜色通道定义。 |
| cfaLayout | number | 是 | 是 | CFA（Color Filter Array）布局类型。 |
| linearizationTable | number[] | 是 | 是 | 线性化查找表，用于将原始传感器值映射为线性光强度。 |
| blackLevelRepeatDim | number[] | 是 | 是 | 黑电平重复维度。 |
| blackLevel | number[] | 是 | 是 | 零光照下的编码电平。 |
| blackLevelDeltaH | number[] | 是 | 是 | 水平方向黑电平校正增量。 |
| blackLevelDeltaV | number[] | 是 | 是 | 垂直方向黑电平校正增量。 |
| whiteLevel | number[] | 是 | 是 | 白电平，表示传感器最大有效输出。 |
| defaultScale | number[] | 是 | 是 | 默认缩放比例。格式为[水平缩放比例, 垂直缩放比例]。 |
| defaultCropOrigin | number[] | 是 | 是 | 默认裁剪区域的左上角坐标（x, y）。 |
| defaultCropSize | number[] | 是 | 是 | 默认裁剪区域的宽度和高度。 |
| colorMatrix1 | number[] | 是 | 是 | 第一校准光源下的色彩变换矩阵。 |
| colorMatrix2 | number[] | 是 | 是 | 第二校准光源下的色彩变换矩阵。 |
| cameraCalibration1 | number[] | 是 | 是 | 第一校准光源下的相机校准矩阵。 |
| cameraCalibration2 | number[] | 是 | 是 | 第二校准光源下的相机校准矩阵。 |
| reductionMatrix1 | number[] | 是 | 是 | 第一校准光源下的降维矩阵。 |
| reductionMatrix2 | number[] | 是 | 是 | 第二校准光源下的降维矩阵。 |
| analogBalance | number[] | 是 | 是 | 模拟增益平衡系数。 |
| asShotNeutral | number[] | 是 | 是 | 拍摄时的中性白点。 |
| asShotWhiteXY | number[] | 是 | 是 | 拍摄时白点的CIE（1931色彩空间） x-y色度坐标。 |
| baselineExposure | number | 是 | 是 | 基准曝光补偿值，单位：EV。 |
| baselineNoise | number | 是 | 是 | 基准噪声水平。 |
| baselineSharpness | number | 是 | 是 | 基准锐度增益。 |
| bayerGreenSplit | number | 是 | 是 | Bayer图像中两个绿色通道的分离程度。 |
| linearResponseLimit | number | 是 | 是 | 线性响应上限。 |
| cameraSerialNumber | string | 是 | 是 | 相机序列号。 |
| lensInfo | number[] | 是 | 是 | 镜头信息。 |
| chromaBlurRadius | number | 是 | 是 | 色度模糊半径。单位：像素（px）。 |
| antiAliasStrength | number | 是 | 是 | 抗锯齿滤波器强度。 |
| shadowScale | number | 是 | 是 | 阴影区域缩放因子。 |
| dngPrivateData | ArrayBuffer | 是 | 是 | 厂商私有数据块。 |
| makerNoteSafety | boolean | 是 | 是 | EXIF MakerNote是否安全可保留。true表示安全，false表示不安全。 |
| calibrationIlluminant1 | number | 是 | 是 | 第一校准光源类型。 |
| calibrationIlluminant2 | number | 是 | 是 | 第二校准光源类型。 |
| bestQualityScale | number | 是 | 是 | 最佳画质缩放比例。 |
| rawDataUniqueID | string | 是 | 是 | 原始图像数据的唯一标识符。 |
| originalRawFileName | string | 是 | 是 | 原始RAW文件名。 |
| originalRawFileData | ArrayBuffer | 是 | 是 | 原始RAW文件的完整数据。 |
| activeArea | number[] | 是 | 是 | 有效图像区域。 |
| maskedAreas | number[] | 是 | 是 | 被遮蔽区域列表。 |
| asShotICCProfile | ArrayBuffer | 是 | 是 | 拍摄时使用的ICC色彩配置文件。 |
| asShotPreProfileMatrix | number[] | 是 | 是 | 应用ICC配置文件前的预变换矩阵。 |
| currentICCProfile | ArrayBuffer | 是 | 是 | 当前使用的ICC色彩配置文件。 |
| currentPreProfileMatrix | number[] | 是 | 是 | 当前ICC配置文件前的预变换矩阵。 |
| colorimetricReference | number | 是 | 是 | 色度参考标准。 |
| cameraCalibrationSignature | string | 是 | 是 | 相机校准签名。 |
| profileCalibrationSignature | string | 是 | 是 | 配置文件校准签名。 |
| extraCameraProfiles | number[] | 是 | 是 | 额外相机配置文件索引列表。 |
| asShotProfileName | string | 是 | 是 | 拍摄时使用的配置文件名称。 |
| noiseReductionApplied | number | 是 | 是 | 已应用的降噪强度级别。 |
| profileName | string | 是 | 是 | 色彩配置文件名称。 |
| profileHueSatMapDims | number[] | 是 | 是 | 色调/饱和度映射表维度。 |
| profileHueSatMapData1 | number[] | 是 | 是 | 第一组色调/饱和度映射表数据。 |
| profileHueSatMapData2 | number[] | 是 | 是 | 第二组色调/饱和度映射表数据。 |
| profileToneCurve | number[] | 是 | 是 | 配置文件色调曲线。 |
| profileEmbedPolicy | number | 是 | 是 | 配置文件嵌入策略。 |
| profileCopyright | string | 是 | 是 | 配置文件版权信息。 |
| forwardMatrix1 | number[] | 是 | 是 | 第一前向变换矩阵。 |
| forwardMatrix2 | number[] | 是 | 是 | 第二前向变换矩阵。 |
| previewApplicationName | string | 是 | 是 | 预览图生成应用程序名称。 |
| previewApplicationVersion | string | 是 | 是 | 预览图生成应用程序版本。 |
| previewSettingsName | string | 是 | 是 | 预览图处理设置名称。 |
| previewSettingsDigest | string | 是 | 是 | 预览图设置的MD5摘要。 |
| previewColorSpace | number | 是 | 是 | 预览图色彩空间。 |
| previewDateTime | string | 是 | 是 | 预览图生成时间。 |
| rawImageDigest | string | 是 | 是 | 原始图像数据的MD5摘要。 |
| originalRawFileDigest | string | 是 | 是 | 原始RAW文件数据的MD5摘要。 |
| subTileBlockSize | number[] | 是 | 是 | 图像分块存储，定义块的长和宽。 |
| rowInterleaveFactor | number | 是 | 是 | 行交织因子。 |
| profileLookTableDims | number[] | 是 | 是 | ProfileLookTableData的维度。 |
| profileLookTableData | number[] | 是 | 是 | 色彩表数据。 |
| opcodeList1 | ArrayBuffer | 是 | 是 | 第一操作码列表。 |
| opcodeList2 | ArrayBuffer | 是 | 是 | 第二操作码列表。 |
| opcodeList3 | ArrayBuffer | 是 | 是 | 第三操作码列表。 |
| noiseProfile | number[] | 是 | 是 | 噪声剖面参数。 |
| originalDefaultFinalSize | number[] | 是 | 是 | 原始默认最终输出尺寸。 |
| originalBestQualityFinalSize | number[] | 是 | 是 | 原始最佳画质输出尺寸。 |
| originalDefaultCropSize | number[] | 是 | 是 | 原始默认裁剪尺寸。 |
| profileHueSatMapEncoding | number | 是 | 是 | 色调/饱和度映射表编码方式。 |
| profileLookTableEncoding | number | 是 | 是 | 色彩表编码方式。 |
| baselineExposureOffset | number | 是 | 是 | 基准曝光偏移量，单位：EV。 |
| defaultBlackRender | number | 是 | 是 | 默认黑场渲染方式。 |
| newRawImageDigest | string | 是 | 是 | 修改后原始图像数据的新MD5摘要。 |
| rawToPreviewGain | number | 是 | 是 | 主RAW图与预览图之间的增益比。 |
| defaultUserCrop | number[] | 是 | 是 | 默认用户裁剪区域。 |

## HdrGainmapMetadata<sup>12+</sup>

增益图使用的元数据值，[HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12)中HDR_GAINMAP_METADATA关键字对应的值，参考ISO 21496-1。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 类型       | 只读 | 可选 | 说明         |
| ------------- | ----------| -- | -- | ------------ |
| writerVersion     | number   | 否 | 否 | 元数据编写器的版本。  |
| miniVersion     | number   | 否 | 否 | 元数据解析所需的最小版本。  |
| gainmapChannelCount  | number    | 否 | 否 | 增益图的颜色通道数。取值为1或3，值为3时RGB通道的元数据值不同，值为1时各通道元数据值相同，参考ISO 21496-1。  |
| useBaseColorFlag  | boolean     | 否 | 否 | 是否使用基础图的色彩空间。true表示使用，false表示不使用，参考ISO 21496-1。 |
| baseHeadroom  | number    | 否 | 否 | 基础图的提亮比。取值范围是[1.0, +∞)，参考ISO 21496-1。   |
| alternateHeadroom  | number     | 否 | 否 | 可选择图像的提亮比。取值范围是[1.0, +∞)，参考ISO 21496-1。  |
| channels  | Array\<[GainmapChannel](#gainmapchannel12)> | 否 | 否 | 各通道的数据，长度为3，按R、G、B三通道存储，参考ISO 21496-1。 |

## ImageReceiverOptions<sup>23+</sup>

ImageReceiver的初始化选项。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

| 名称              | 类型                               | 只读 | 可选 | 说明               |
| ----------------- | ---------------------------------- | ---- | ---- | ------------------ |
| size     | [Size](#size) | 否   | 是   | 图像的大小，包括宽与高，且值都大于0。单位：像素（px）。<br>该参数不会影响接收到的图片大小，实际返回大小由生产者决定，如相机。|
| capacity | number | 否   | 是   | 可同时访问的最大图像数量。该值必须为正整数，且小于或等于64张。<br>该参数仅作为期望值，实际capacity由设备硬件决定。     |

## ImageBufferData<sup>23+</sup>

保存图像缓冲区数据的指针、不同颜色分量的行间距与像素间距信息。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 类型              | 只读 | 可选 | 说明               |
| ----------------- | ----------------- | ---- | ---- | ------------------ |
| rowStride   | number[]  | 是   | 否   | 颜色分量的行跨距。单位：字节（Byte）。<br>对于编码后的图片如JPEG，该属性无意义。<br>读取相机预览流数据时，需要按rowStride进行读取，使用详情请参考[相机预览花屏解决方案](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-deal-stride-solution)。|
| pixelStride | number[]  | 是   | 否   | 颜色分量的像素间距。单位：字节（Byte）。<br>对于编码后的图片如JPEG，该属性无意义。     |
| byteBuffer  | ArrayBuffer | 是   | 否   | 图像缓冲区。     |

## ImageRawData<sup>24+</sup>

图像的RAW数据。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称              | 类型              | 只读 | 可选 | 说明               |
| ----------------- | ----------------- | ---- | ---- | ------------------ |
| buffer  | ArrayBuffer | 否   | 否   | 图像缓冲区。     |
| bitsPerPixel | number  | 否   | 否   | 每个像素在缓冲区数据中实际占用的位数。单位：比特（bit）。     |

## XMPTag

表示XMP标签信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 类型                                              | 只读 | 可选 | 说明              |
| ------------- | ------------------------------------------------ | ---- | ---- | ---------------- |
| xmpNamespace  | [XMPNamespace](#xmpnamespace)                    | 否   | 否   | XMP命名空间。     |
| name          | string                                           | 否   | 否   | XMP标签名称。     |
| type          | [XMPTagType](arkts-apis-image-e.md#xmptagtype)   | 否   | 否   | XMP标签类型。     |
| value         | string                                           | 否   | 是   | XMP标签值。       |

## XMPNamespace

表示XMP命名空间。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称   | 类型    | 只读 | 可选 | 说明             |
| ------ | ------ | ---- | ---- | --------------- |
| uri    | string | 否   | 否   | XMP命名空间URI。 |
| prefix | string | 否   | 否   | XMP命名空间前缀。 |

## XMPEnumerateOptions

表示XMP枚举选项。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 类型     | 只读 | 可选 | 说明                   |
| ------------- | ------- | ---- | ---- | --------------------- |
| isRecursive   | boolean | 否   | 是   | 表示是否进行递归遍历。<br>true表示进行递归遍历。false表示仅遍历直接子节点。默认为false。 |
| onlyQualifier | boolean | 否   | 是   | 表示是否仅遍历限定符节点。<br>true表示仅遍历限定符节点。false表示遍历所有节点。默认为false。 |

## BinaryBufferInfo

描述二值图像缓冲区内的信息及数据。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| size | [Size](#size) | 否 | 否 | 图像尺寸，包含宽度和高度。 |
| data | ArrayBuffer | 否 | 否 | 图像数据缓冲区，包含二值图像数据。 |
| bytesPerRow | number | 否 | 是 | 每行字节数。若未指定，将按(width + 7) / 8计算。该值应为整数。 |

## PackingOptionsForTiff

描述TIFF图像编码参数的选项。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| compression | number | 否 | 是 | 该值应为整数，目前仅支持取3、4、5，分别对应压缩算法类型：3（CCITT G3）、4（CCITT G4）、5（LZW）。<br>- 对于二值图像：必须为3（G3）或4（G4），自动使用4（G4）。<br>- 对于Y8/RGB_888格式：自动使用LZW（5），不支持指定其他压缩算法。 |
| orientation | [Orientation](arkts-apis-image-e.md#orientation23) | 否 | 是 | 图像方向。默认值为TOP_LEFT。 |
| xResolution | number | 否 | 是 | 水平分辨率。该值必须大于0。 |
| yResolution | number | 否 | 是 | 垂直分辨率。该值必须大于0。 |
| resolutionUnit | number | 否 | 是 | 分辨率单位：1（无单位）、2（英寸）、3（厘米）。目前仅支持1、2、3。 |

## GetImagePropertyOptions<sup>(deprecated)</sup>

表示查询图片属性的索引。

> **说明：**
>
> 从API version 7开始支持，从API version 11开始废弃，建议使用[ImagePropertyOptions](#imagepropertyoptions11)代替。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称         | 类型   | 只读 | 可选 | 说明         |
| ------------ | ------ | ---- | ---- | ------------ |
| index        | number | 否   | 是   | 图片序号。默认值为0。   |
| defaultValue | string | 否   | 是   | 默认属性值。默认值为空。 |
