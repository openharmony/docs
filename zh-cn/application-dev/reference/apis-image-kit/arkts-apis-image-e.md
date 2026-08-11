# Enums
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

Image Kit提供的枚举类型集合，涵盖图片像素格式、图片格式、透明度类型、图片元数据、图片属性信息（Exif及各格式图片属性）、辅助图类型、缩放模式、裁剪与缩放策略、动态范围、HDR元数据、内存分配、插值算法、图片方向、焦点模式、颜色模式、XMP标签类型等，用于在图片编解码、处理和显示场景中指定各类配置参数。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## PixelMapFormat<sup>7+</sup>

表示图片像素格式的枚举，包含像素数据的颜色通道排列和位深信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                   |   值   | 说明              |
| ---------------------- | ------ | ----------------- |
| UNKNOWN                | 0      | 未知格式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。        |
| ARGB_8888<sup>18+</sup> | 1 | 颜色信息由透明度（Alpha）与R（Red）、G（Green）、B（Blue）四部分组成，每个部分占8位，总共占32位，按照从高位到低位的顺序存储。该格式当前仅支持PixelMap的接口。|
| RGB_565                | 2      | 颜色信息由R（Red）、G（Green）、B（Blue）三部分组成，R占5位，G占6位，B占5位，总共占16位，按照从高位到低位的顺序存储。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。     |
| RGBA_8888              | 3      | 颜色信息由R（Red）、G（Green）、B（Blue）与透明度（Alpha）四部分组成，每个部分占8位，总共占32位，按照从高位到低位的顺序存储。对应[相机服务CameraFormat中的CAMERA_FORMAT_RGBA_8888](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| BGRA_8888<sup>9+</sup> | 4      | 颜色信息由B（Blue）、G（Green）、R（Red）与透明度（Alpha）四部分组成，每个部分占8位，总共占32位，按照从高位到低位的顺序存储。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| RGB_888<sup>9+</sup>   | 5      | 颜色信息由R（Red）、G（Green）、B（Blue）三部分组成，每个部分占8位，总共占24位，按照从高位到低位的顺序存储。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。   |
| ALPHA_8<sup>9+</sup>   | 6      | 颜色信息仅包含透明度（Alpha），每个像素占8位，按照从高位到低位的顺序存储。一个或多个像素组成一行像素，每行像素数据按4字节对齐，如果一行像素所占的字节数不是4的整数倍，则在行末填充空白字节以满足对齐要求。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。   |
| RGBA_F16<sup>9+</sup>  | 7      | 颜色信息由R（Red）、G（Green）、B（Blue）与透明度（Alpha）四部分组成，每个部分占16位，总共占64位，按照从高位到低位的顺序以FP16半精度浮点数的形式存储。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。  |
| NV21<sup>9+</sup>      | 8      | YVU像素排列，V分量在U分量之前。颜色信息由亮度分量Y和交错排列的色度分量V和U组成，其中Y分量占8位，UV分量因4:2:0采样平均占4位，总共平均占12位，按照从高位到低位的顺序存储。对应[相机服务CameraFormat中的CAMERA_FORMAT_YUV_420_SP](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。      |
| NV12<sup>9+</sup>      | 9      | YUV像素排列，U分量在V分量之前。颜色信息由亮度分量Y和交错排列的色度分量U和V组成，其中Y分量占8位，UV分量因4:2:0采样平均占4位，总共平均占12位，按照从高位到低位的顺序存储。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。      |
| RGBA_1010102<sup>12+</sup> | 10 | 颜色信息由R（Red）、G（Green）、B（Blue）与透明度（Alpha）四部分组成，其中R、G、B分别占10位，透明度占2位，总共占32位，按照从高位到低位的顺序存储。 |
| YCBCR_P010<sup>12+</sup> | 11 | 颜色信息由亮度分量Y和色度分量Cb与Cr组成，每个分量有效10位，实际存储时，Y平面每个像素占16位数据（10位有效），UV平面交错排列，每4个像素占32位数据（每色度分量10位有效），平均有效占15位，按照从高位到低位的顺序存储。对应[相机服务CameraFormat中的CAMERA_FORMAT_YCBCR_P010](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat)。  |
| YCRCB_P010<sup>12+</sup> | 12 | 颜色信息由亮度分量Y和色度分量Cr与Cb组成，每个分量有效10位，实际存储时，Y平面每个像素占16位数据（10位有效），UV平面交错排列，每4个像素占32位数据（每色度分量10位有效），平均有效占15位，按照从高位到低位的顺序存储。对应[相机服务CameraFormat中的CAMERA_FORMAT_YCRCB_P010](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat)。  |
| Y8 | 14 | 仅包含Y平面（亮度）的单通道灰度格式，每个像素占8位，按照从高位到低位的顺序存储。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。  |
| ALPHA_U8 | 15 | 颜色信息仅包含透明度（Alpha），每个像素占8位，按照从高位到低位的顺序存储。所有像素紧密排列，不进行对齐。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。  |
| ALPHA_F16 | 16 | 颜色信息仅包含透明度（Alpha），每个像素占16位，按照从高位到低位的顺序以FP16半精度浮点数的形式存储。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。  |
| ASTC_4x4<sup>18+</sup> | 102 | 存储格式为ASTC 4x4格式，内存使用量仅为RGBA_8888的1/4。该格式仅用于直接显示场景，不支持像素访问或后期处理编辑，不支持仿射变换级联使用。  |

## AlphaType<sup>9+</sup>

表示图像的透明度类型的枚举。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称     |   值   | 说明                    |
| -------- | ------ | ----------------------- |
| UNKNOWN  | 0      | 未知透明度类型。            |
| OPAQUE   | 1      | 没有Alpha通道或图片不透明。 |
| PREMUL   | 2      | RGB通道预乘Alpha值。         |
| UNPREMUL | 3      | RGB通道非预乘Alpha值。       |

## AuxiliaryPictureType<sup>13+</sup>

表示辅助图的图像类型的枚举。

辅助图不直接参与图片显示，且并非所有图片中都含有辅助图。

在获取和使用特定辅助图前，应首先调用Picture的[getAuxiliaryPicture](./arkts-apis-image-Picture.md#getauxiliarypicture13)方法尝试获取该辅助图。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值   | 说明         |
| ------------- | ---- | ------------ |
| GAINMAP       | 1    | 增益图（Gain Map）。<br>用于更准确地生成HDR图像。<br>HDR合成通常需要同时使用SDR主图、增益图和HDR元数据（[getMetadata](./arkts-apis-image-PixelMap.md#getmetadata12)）共同计算亮度映射关系。 |
| DEPTH_MAP     | 2    | 深度图（Depth Map）。<br>用于存储每个像素与摄像头之间的距离信息，提供场景的三维结构。<br>可用于3D重建、背景分离和场景理解等任务。     |
| UNREFOCUS_MAP | 3    | 未重对焦原图（UnReFocus Map）。<br>用于保存拍摄时未重对焦的图片像素内容。<br>可用于人像虚化等后期处理，便于用户自由选择焦点区域。  |
| LINEAR_MAP    | 4    | 线性图（Linear Map）。<br>以线性方式记录光照、颜色或其他视觉要素，为图像处理提供补充信息。<br>可用于视觉效果增强与色彩后期处理。  |
| FRAGMENT_MAP  | 5    | 水印裁剪图（Fragment Map）。<br>记录原图中被水印遮挡的区域，可能是从原图裁剪得到，也可能只是填充特定数值的像素数据作为占位符。<br>可用于水印移除、原图恢复等场景。 |
| LHDR_GAINMAP  | 10    | 特殊增益图（LHDR Gain Map）。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。|

## MetadataType<sup>13+</sup>

表示图片元数据类型的枚举。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 值   | 说明               |
| ----------------- | ---- | ------------------ |
| EXIF_METADATA     | 1    | exif数据。         |
| FRAGMENT_METADATA | 2    | 水印裁剪图元数据。 |
| GIF_METADATA<sup>20+</sup> | 5    | GIF图片元数据。 |
| HEIFS_METADATA<sup>23+</sup> | 15    | HEIF序列图片元数据。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| DNG_METADATA<sup>24+</sup> | 16    | DNG图片元数据。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| WEBP_METADATA<sup>24+</sup> | 17    | WebP图片元数据。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| PNG_METADATA | 19    | PNG图片元数据。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**起始版本：** 26.0.0 |
| JFIF_METADATA | 20    | JFIF图片元数据。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**起始版本：** 26.0.0 |
| TIFF_METADATA | 21    | TIFF图片元数据。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**起始版本：** 26.0.0 |
| XMP_METADATA | 22    | XMP图片元数据。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**起始版本：** 26.0.0 |
| AVIS_METADATA | 23    | AVIS图片元数据。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**起始版本：** 26.0.0 |

## ScaleMode<sup>9+</sup>

表示图像的缩放模式的枚举。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称            |   值   | 说明                                               |
| --------------- | ------ | -------------------------------------------------- |
| CENTER_CROP     | 1      | 中心裁剪模式。表示将图像等比缩放至刚好铺满目标区域的尺寸（短边对齐），然后居中裁剪超出区域的部分。 |
| FIT_TARGET_SIZE | 0      | 适配目标尺寸模式。表示将图像等比缩放至完全容纳于目标区域的尺寸内（长边对齐），不足的区域留黑边或透明。 |

## PropertyKey<sup>7+</sup>

表示Exif（Exchangeable image file format）图像信息的枚举。



- 格式示例中的key为：image.PropertyKey.XXX（XXX为枚举的名称，如：image.PropertyKey.NEW_SUBFILE_TYPE） 。
- 格式示例仅用于说明修改传值和读取结果的格式。具体接口使用方法请参考：[modifyImageProperty](arkts-apis-image-ImageSource.md#modifyimageproperty11)（修改单个Exif字段）、[modifyImageProperties](arkts-apis-image-ImageSource.md#modifyimageproperties12)（修改多个Exif字段）、[getImageProperty](arkts-apis-image-ImageSource.md#getimageproperty11)（读取单个Exif字段）、[getImageProperties](arkts-apis-image-ImageSource.md#getimageproperties12)（读取多个Exif字段）。

> **说明：**
>
> 应用通过[PhotoAccessHelper](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md)查询媒体库图片，读取GPS相关字段（如GPS_LATITUDE、GPS_LONGITUDE、GPS_ALTITUDE、GPS_TIME_STAMP和GPS_DATE_STAMP）前，应先声明并向用户申请[ohos.permission.MEDIA_LOCATION](../../security/AccessToken/permissions-for-all-user.md#ohospermissionmedia_location)权限。如果上述字段返回全为0或为空，请先检查该权限是否已获授权，并确认原始图片是否包含GPS信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称               |   值                    |   说明                    |   格式示例               |
| ----------------- | ----------------------- | ----------------------- | ----------------------- |
| NEW_SUBFILE_TYPE<sup>12+</sup>           | "NewSubfileType"            | 在Exif中，"NewSubfileType"字段用于标识子文件的数据类型，如全分辨率图像、缩略图或多帧图像的一部分。其值是位掩码，0代表全分辨率图像，1代表缩略图，2代表多帧图像的一部分。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0');`<br />或`imageSource.modifyImageProperty(key,'Primary image');`<br />**读取结果示例：** "0" |
| SUBFILE_TYPE<sup>12+</sup>               | "SubfileType"               | 此标签指示此子文件中的数据类型。标签已弃用，请使用NewSubfileType替代。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'Full-resolution image data');`<br />**读取结果示例：** "1" |
| IMAGE_WIDTH                               | "ImageWidth"                | 图片宽度。单位：像素（px）。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'4096');`<br />**读取结果示例：** "4096" |
| IMAGE_LENGTH                              | "ImageLength"               | 图片长度。单位：像素（px）。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'3072');`<br />**读取结果示例：** "3072" |
| BITS_PER_SAMPLE                           | "BitsPerSample"             | 像素各分量的位数，如RGB，3分量，格式是8,8,8。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 三个非负整数字符串，空格或者英文逗号隔开。<br />**修改示例：**`imageSource.modifyImageProperty(key,'8 8 8');`<br />或`imageSource.modifyImageProperty(key,'8,8,8');`<br />**读取结果示例：** "8,8,8" |
| COMPRESSION<sup>12+</sup>                | "Compression"               | 图像压缩方案。<br/> 1："Uncompressed"。<br/> 2："CCITT RLE"。<br/> 3："T4/Group 3 Fax"。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br/>**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'Uncompressed');`<br />**读取结果示例：** "Uncompressed" |
| PHOTOMETRIC_INTERPRETATION<sup>12+</sup> | "PhotometricInterpretation" | 像素构成，例如RGB或YCbCr。<br/> 0："Reversed mono"。<br/> 1："Normal mono"。<br/> 2："RGB"。<br/> 3："Palette"。<br/> 5："CMYK"。<br/> 6："YCbCr"。<br/> 8："CieLAB"。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br/>**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'Normal mono');`<br />**读取结果示例：** "Normal mono" |
| IMAGE_DESCRIPTION<sup>10+</sup>           | "ImageDescription"          | 图像信息描述。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Image description info');`<br />**读取结果示例：** "Image description info" |
| MAKE<sup>10+</sup>                        | "Make"                      | 生产商。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Make');`<br />**读取结果示例：** "Make" |
| MODEL<sup>10+</sup>                       | "Model"                     | 设备型号。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Model');`<br />**读取结果示例：** "Model" |
| STRIP_OFFSETS<sup>12+</sup>              | "StripOffsets"              | 每个strip的字节偏移量。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'100');`<br />**读取结果示例：** "100" |
| ORIENTATION                               | "Orientation"               | 图片方向。<br/> 1："Top-left"，图像未旋转。<br/> 2："Top-right"，镜像水平翻转。<br/> 3："Bottom-right"，图像旋转180°。<br/>4："Bottom-left"，镜像垂直翻转。<br/> 5："Left-top"，镜像水平翻转再顺时针旋转270°。<br/> 6："Right-top"，顺时针旋转90°。<br/> 7："Right-bottom"，镜像水平翻转再顺时针旋转90°。<br/>8："Left-bottom"，顺时针旋转270°。<br/> 如果读到未定义值x会返回"Unknown Value x"。获取该属性时会以字符串的形式返回。修改该属性时既可以以数字形式指定，也可以以字符串形式指定。<br/> 更多关于图片旋转角度的说明可参考：[如何获取图片的旋转角度信息](../../media/image/image-faqs/image-rotate-faq.md)。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'Top-left');`<br />**读取结果示例：** "Top-left" |
| SAMPLES_PER_PIXEL<sup>12+</sup>          | "SamplesPerPixel"           | 每个像素的分量数。由于该标准适用于RGB和YCbCr图像，因此该标签的值设置为 3。在JPEG压缩数据中，使用JPEG标记代替该标签。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'3');`<br />**读取结果示例：** "3" |
| ROWS_PER_STRIP<sup>12+</sup>             | "RowsPerStrip"              | 每个strip的图像数据行数。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'10');`<br />**读取结果示例：** "10" |
| STRIP_BYTE_COUNTS<sup>12+</sup>          | "StripByteCounts"           | 每个图像数据带的总字节数。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1024');`<br />**读取结果示例：** "1024" |
| X_RESOLUTION<sup>12+</sup>               | "XResolution"               | 图像宽度方向的分辨率。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'72');`<br />**读取结果示例：** "72" |
| Y_RESOLUTION<sup>12+</sup>               | "YResolution"               | 图像高度方向的分辨率。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'72');`<br />**读取结果示例：** "72" |
| PLANAR_CONFIGURATION<sup>12+</sup>       | "PlanarConfiguration"       | 表示像素组件的记录格式，chunky格式或是planar格式。<br/>1："Chunky format"，chunky格式。<br/>2："Planar format"，planar格式。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'Chunky format');`<br />**读取结果示例：** "Chunky format" |
| RESOLUTION_UNIT<sup>12+</sup>            | "ResolutionUnit"            | 用于测量XResolution和YResolution的单位，英寸或者厘米。<br/>2："Inch"，英寸。<br/>3："Centimeter"，厘米。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'2');`<br />或`imageSource.modifyImageProperty(key,'Inch');`<br />**读取结果示例：** "Inch" |
| TRANSFER_FUNCTION<sup>12+</sup>          | "TransferFunction"          | 图像的传递函数，通常用于颜色校正。<br/>**读写能力：** 可读写。<br> | 该字段为特有格式，虽然支持读写，但目前版本不做解析。 |
| SOFTWARE<sup>12+</sup>                   | "Software"                  | 用于生成图像的软件名称和版本。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Software name and version');`<br />**读取结果示例：** "Software name and version" |
| DATE_TIME<sup>10+</sup>                   | "DateTime"                  | 日期时间。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 有两种格式，YYYY:MM:DD或者YYYY:MM:DD HH:MM:SS<br />**修改示例：**`imageSource.modifyImageProperty(key,'2024:07:07 13:45:59');`<br />或`imageSource.modifyImageProperty(key,'2024:07:07');`<br />**读取结果示例：** "2024:07:07 13:45:59"或"2024:07:07" |
| ARTIST<sup>12+</sup>                     | "Artist"                    | 创建图像的用户名称。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'User name');`<br />**读取结果示例：** "User name" |
| WHITE_POINT<sup>12+</sup>                | "WhitePoint"                | 用于指定图像的白点（white point）色度坐标，即图像颜色空间中被认为是“白色”的参考点。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 两个非负有理数字符串，空格或者英文逗号隔开。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1,2');`<br />或`imageSource.modifyImageProperty(key,'1 2');`<br />**读取结果示例：** "1,2" |
| PRIMARY_CHROMATICITIES<sup>12+</sup>     | "PrimaryChromaticities"     | 图像的主要颜色的色度。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'2/1');`<br />**读取结果示例：** "0.5" |
| PHOTO_MODE<sup>10+</sup>                  | "PhotoMode"                 | 拍照模式。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />**读取结果示例：** "1" |
| JPEG_INTERCHANGE_FORMAT<sup>12+</sup>    | "JPEGInterchangeFormat"     | JPEG压缩缩略图数据开始字节（SOI）的偏移。<br />**读写能力：** 只读。<br> | **读取结果示例：** "1024" |
| JPEG_INTERCHANGE_FORMAT_LENGTH<sup>12+</sup> | "JPEGInterchangeFormatLength" | JPEG压缩缩略图数据的字节数。<br />**读写能力：** 只读。<br> | **读取结果示例：** "1024" |
| YCBCR_COEFFICIENTS<sup>12+</sup>         | "YCbCrCoefficients"         | 从RGB到YCbCr图像数据的转换矩阵系数，RGB→YCbCr转换时的加权系数。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 三个非负有理数字符串，和为1。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0.299, 0.587, 0.114');`<br />**读取结果示例：** "0.299, 0.587, 0.114" |
| YCBCR_SUB_SAMPLING<sup>12+</sup>         | "YCbCrSubSampling"          | 色度分量与亮度分量的采样比率。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 两个非负整数字符串，空格或者逗号分隔。<br />**修改示例：**`imageSource.modifyImageProperty(key,'2,2');`<br />或`imageSource.modifyImageProperty(key,'2 2');`<br />**读取结果示例：** "2,2" |
| YCBCR_POSITIONING<sup>12+</sup>          | "YCbCrPositioning"          | 色度分量相对于亮度分量的位置。<br/>1："Centered"，中心对齐（Centered），Cb/Cr分量的采样点相对于亮度像素点是居中对齐（常见）。<br/>2："Co-sited"，左上对齐（Co-sited）Cb/Cr分量和 Y 分量的采样点对齐在左上角。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。 <br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'Centered');`<br />**读取结果示例：** "Centered" |
| REFERENCE_BLACK_WHITE<sup>12+</sup>      | "ReferenceBlackWhite"       | 参考黑点值和白点值。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />**读取结果示例：** "1,255, 0,255, 0,255" |
| COPYRIGHT<sup>12+</sup>                  | "Copyright"                 | 图像的版权信息。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'desc');`<br />**读取结果示例：** "desc (Photographer) - [None] (Editor)" |
| EXPOSURE_TIME<sup>9+</sup>                | "ExposureTime"              | 曝光时间。单位：秒（s）。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'1/2');`<br />**读取结果示例：** "1/33 sec." |
| F_NUMBER<sup>9+</sup>                     | "FNumber"                   | 光圈值，例如f/1.8。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'1/2');`<br />**读取结果示例：** "f/1.0" |
| EXPOSURE_PROGRAM<sup>12+</sup>           | "ExposureProgram"           | 拍照时相机用来设置曝光的程序的类别。<br />0："Not defined"。<br />1："Manual"。  <br />2："Normal program"。<br/>3："Aperture priority"。<br />4："Shutter priority"。<br />5："Creative program (biased toward depth of field)"。<br/>6："Creative program (biased toward fast shutter speed)"。<br/>7："Portrait mode (for closeup photos with the background out of focus)"。<br/>8："Landscape mode (for landscape photos with the background in focus)"。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0');`<br />或`imageSource.modifyImageProperty(key,'Not defined');`<br />**读取结果示例：** "Not defined" |
| SPECTRAL_SENSITIVITY<sup>12+</sup>       | "SpectralSensitivity"       | 表示所用相机的每个通道的光谱灵敏度。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'SpectralSensitivity');`<br />**读取结果示例：** "SpectralSensitivity" |
| GPS_VERSION_ID<sup>12+</sup>             | "GPSVersionID"              | GPS信息版本号。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 四个以小数点分隔的非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'2.3.0.0');`<br />**读取结果示例：** "2.3.0.0" |
| GPS_LATITUDE_REF                          | "GPSLatitudeRef"            | 用于标识图像拍摄地点的纬度方向（北半球或南半球）。<br/>78："North"。<br />83："South"。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：**  修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'78');`<br />或`imageSource.modifyImageProperty(key,'North');`<br />**读取结果示例：** "N"或"78" |
| GPS_LATITUDE                              | "GPSLatitude"               | 图片纬度。修改时应按"度，分，秒"格式传入，如"39，54，7.542"<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 三个非负有理数字符串，逗号隔开。<br />**修改示例：**`imageSource.modifyImageProperty(key,'39,54,7.542');`<br />**读取结果示例：** "39,54,7.542" |
| GPS_LONGITUDE_REF                         | "GPSLongitudeRef"           | 经度引用，例如W或E， 用于标识图像拍摄地点的经度方向（东半球或西半球）。<br/>69："East"。<br />87："West"。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：**  修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'69');`<br />或`imageSource.modifyImageProperty(key,'East');`<br />**读取结果示例：** "69"或"E" |
| GPS_LONGITUDE                             | "GPSLongitude"              | 图片经度。修改时应按"度，分，秒"格式传入，如"116，19，42.16"<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 三个非负有理数字符串，逗号隔开。<br />**修改示例：**`imageSource.modifyImageProperty(key,'116,19,42.16');`<br />**读取结果示例：** "116,19,42.16" |
| GPS_ALTITUDE_REF<sup>12+</sup>           | "GPSAltitudeRef"            | 用于GPS高度的参照高度。<br/>0："Sea level"，海平面以上（Above Sea Level）。<br/>1："Sea level reference"，海平面以下（Below Sea Level）。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：**  修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0');`<br />或`imageSource.modifyImageProperty(key,'Sea level');`<br />**读取结果示例：** "Sea level" |
| GPS_ALTITUDE<sup>12+</sup>               | "GPSAltitude"               | 基于GPSAltitudeRef的高度。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'123.45');`<br />**读取结果示例：** "123.45" |
| GPS_TIME_STAMP<sup>10+</sup>              | "GPSTimeStamp"              | GPS时间戳。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 格式为"HH:mm:ss.ddd"。<br />**修改示例：**`imageSource.modifyImageProperty(key,'12:30:30.123');`<br />**读取结果示例：** "12:30:30.123" |
| GPS_SATELLITES<sup>12+</sup>             | "GPSSatellites"             | 用于测量的GPS卫星。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'GPS Satellites');`<br />**读取结果示例：** "GPSSatellites" |
| GPS_STATUS<sup>12+</sup>                 | "GPSStatus"                 | 录制图像时GPS接收器的状态。<br/>  'A'："Measurement in progress"，GPS有效，已成功锁定卫星信号，位置数据可信；<br />'V'："Measurement interrupted"，GPS无效，当前未能定位，位置数据可能为空或不准。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：**  修改时传入对应的字母或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'A');`<br />或`imageSource.modifyImageProperty(key,'Measurement in progress');`<br />**读取结果示例：** "A" |
| GPS_MEASURE_MODE<sup>12+</sup>           | "GPSMeasureMode"            | GPS测量模式。用于表示图像拍摄时GPS定位使用的测量模式，即是使用2D（平面）定位还是3D（含高度）定位。<br/>2："2-dimensional measurement"，2D测量（纬度+经度）。<br/>3："3-dimensional measurement"，3D测量（纬度+经度+高度）。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'2');`<br />或`imageSource.modifyImageProperty(key,'2-dimensional measurement');`<br />**读取结果示例：** "2" |
| GPS_DOP<sup>12+</sup>                    | "GPSDOP"                    | GPS DOP（数据精度等级），用于表示拍摄时GPS测量结果的定位精度水平。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1.5');`<br />**读取结果示例：** "1.5" |
| GPS_SPEED_REF<sup>12+</sup>              | "GPSSpeedRef"               | 用来表示GPS接收器移动速度的单位。<br/>'K'："km/h"。<br />'M'："mph"。<br />'N'："knots"。<br />**读写能力：** 可读写。 | **修改传参格式说明：** 修改时传入对应的字母或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'K');`<br />或`imageSource.modifyImageProperty(key,'km/h');`<br />**读取结果示例：** "K" |
| GPS_SPEED<sup>12+</sup>                  | "GPSSpeed"                  | GPS接收器的移动速度。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串<br />**修改示例：**`imageSource.modifyImageProperty(key,'123');`<br />或`imageSource.modifyImageProperty(key,'123.45');`<br />**读取结果示例：** "123.45" |
| GPS_TRACK_REF<sup>12+</sup>              | "GPSTrackRef"               | GPS接收机移动方向的参照，用于说明这个角度是以哪个“北”为参考。<br/> 'T'："True direction"，真北：地理极点方向，适合地图、导航。<br />'M'："Magnetic direction"， 磁北：受地磁影响，磁偏角因地区和时间不同而变化。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入对应的字母或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'T');`<br />或`imageSource.modifyImageProperty(key,'True direction');`<br />**读取结果示例：** "T" |
| GPS_TRACK<sup>12+</sup>                  | "GPSTrack"                  | GPS接收机的移动方向。用于记录拍摄设备在拍照时的移动方向（行进方向），单位是角度（deg）<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'180');`<br />**读取结果示例：** "180" |
| GPS_IMG_DIRECTION_REF<sup>12+</sup>      | "GPSImgDirectionRef"        | 图像方向的参照。<br/> 'T'："True direction"，真北：地理极点方向，适合地图、导航。<br />'M'："Magnetic direction"， 磁北：受地磁影响，磁偏角因地区和时间不同而变化。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入对应的字母或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'T');`<br />或`imageSource.modifyImageProperty(key,'True direction');`<br />**读取结果示例：** "T" |
| GPS_IMG_DIRECTION<sup>12+</sup>          | "GPSImgDirection"           | 拍摄时图像的方向。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'120');`<br />**读取结果示例：** "120" |
| GPS_MAP_DATUM<sup>12+</sup>              | "GPSMapDatum"               | GPS接收器使用的大地测量数据。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'GPS Map Datum');`<br />**读取结果示例：** "GPS Map Datum" |
| GPS_DEST_LATITUDE_REF<sup>12+</sup>      | "GPSDestLatitudeRef"        | 目的地点的纬度参照。<br/>78："North"。<br />83："South"。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'78');`<br />或`imageSource.modifyImageProperty(key,'North');`<br />**读取结果示例：** "78" |
| GPS_DEST_LATITUDE<sup>12+</sup>          | "GPSDestLatitude"           | 目的地点的纬度。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 三个非负整数字符串，空格或者英文逗号隔开。<br />**修改示例：**`imageSource.modifyImageProperty(key,'39,54,7');`<br />或`imageSource.modifyImageProperty(key,'39 54 7');`<br />**读取结果示例：** "39,54,7" |
| GPS_DEST_LONGITUDE_REF<sup>12+</sup>     | "GPSDestLongitudeRef"       | 目的地点的经度参照。<br/>69："East"。<br />87："West"。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'69');`<br />或`imageSource.modifyImageProperty(key,'East');`<br />**读取结果示例：** "69" |
| GPS_DEST_LONGITUDE<sup>12+</sup>         | "GPSDestLongitude"          | 目的地点的经度。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 三个非负整数字符串，空格或者英文逗号隔开。<br />**修改示例：**`imageSource.modifyImageProperty(key,'116,19,42');`<br />或`imageSource.modifyImageProperty(key,'116 19 42');`<br />**读取结果示例：** "116,19,42" |
| GPS_DEST_BEARING_REF<sup>12+</sup>       | "GPSDestBearingRef"         | 指向目的地点的方位参照。<br/> 'T'："True direction"，真北：地理极点方向，适合地图、导航。<br />'M'："Magnetic direction"，磁北：受地磁影响，磁偏角因地区和时间不同而变化。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入对应的字母或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'T');`<br />或`imageSource.modifyImageProperty(key,'True direction');`<br />**读取结果示例：** "T" |
| GPS_DEST_BEARING<sup>12+</sup>           | "GPSDestBearing"            | 目的地方位。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'120');`<br />**读取结果示例：** "120" |
| GPS_DEST_DISTANCE_REF<sup>12+</sup>      | "GPSDestDistanceRef"        | 目标点距离的测量单位。<br/>'K'："km"，公里。<br/>'M'："miles"，英里。<br/>'N'："nautical miles"，海里。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入对应的字母或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'K');`<br />或`imageSource.modifyImageProperty(key,'km');`<br />**读取结果示例：** "K" |
| GPS_DEST_DISTANCE<sup>12+</sup>          | "GPSDestDistance"           | 到目的地点的距离。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'100');`<br />**读取结果示例：** "100" |
| GPS_PROCESSING_METHOD<sup>12+</sup>      | "GPSProcessingMethod" |记录定位方法名的字符串。<br/>**读写能力：** 可读写。<br/>|**修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'GPS Processing Method');`<br />**读取结果示例：** "GPS Processing Method"|
| GPS_AREA_INFORMATION<sup>12+</sup>       | "GPSAreaInformation"   | 记录GPS区域名的字符串。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'GPS Area Information');`<br />**读取结果示例：** "GPS Area Information" |
| GPS_DATE_STAMP<sup>10+</sup>              | "GPSDateStamp"         | GPS日期戳。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 格式为“YY:MM:DD”。<br />**修改示例：**`imageSource.modifyImageProperty(key,'2020:07:07');`<br />**读取结果示例：** "2020:07:07" |
| GPS_DIFFERENTIAL<sup>12+</sup>           | "GPSDifferential"      | 此字段表示GPS数据是否应用了差分校正，对于精确的位置准确性至关重要。<br/>  0："Without correction"，没有使用差分校正。<br/> 1："Correction applied"，使用差分校正。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0');`<br />或`imageSource.modifyImageProperty(key,'Without correction');`<br />**读取结果示例：** "0" |
| GPS_H_POSITIONING_ERROR<sup>12+</sup>    | "GPSHPositioningError" | 此标签指示水平定位误差。单位：米（m）。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'100');`<br />**读取结果示例：** "100" |
| ISO_SPEED_RATINGS<sup>9+</sup>            | "ISOSpeedRatings"           | ISO感光度，例如400。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'3200');`<br />**读取结果示例：** "3200" |
| PHOTOGRAPHIC_SENSITIVITY<sup>12+</sup>   | "PhotographicSensitivity" | 用于表示图像拍摄时所用的感光度值（ISO 值），也叫ISO Speed。该字段是Exif 2.3后的推荐字段，ISOSpeedRatings（Tag 0x8827）是早期使用的字段，类型和含义相同，若两个字段都存在，以`PhotographicSensitivity` 为主。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'3200');`<br />**读取结果示例：** "3200" |
| OECF<sup>12+</sup>                       | "OECF"                      | 表示ISO 14524中规定的光电转换函数（OECF）。<br/>**读写能力：** 可读写。<br> | 该字段为特有格式，虽然支持读写，但目前版本不做解析。 |
| SENSITIVITY_TYPE<sup>10+</sup>            | "SensitivityType"      | 灵敏度类型。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'Standard output sensitivity (SOS)');`<br />**读取结果示例：** "Standard output sensitivity (SOS)" |
| STANDARD_OUTPUT_SENSITIVITY<sup>10+</sup> | "StandardOutputSensitivity" | 标准输出灵敏度。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'400');`<br />**读取结果示例：** "400" |
| RECOMMENDED_EXPOSURE_INDEX<sup>10+</sup>  | "RecommendedExposureIndex" | 推荐曝光指数。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'3200');`<br />**读取结果示例：** "3200" |
| ISO_SPEED<sup>10+</sup>                   | "ISOSpeedRatings"           | ISO速度等级。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'3200');`<br />**读取结果示例：** "3200" |
| ISO_SPEED_LATITUDE_YYY<sup>12+</sup>     | "ISOSpeedLatitudeyyy"  | 该标签指示摄像机或输入设备的ISO速度纬度yyy值，该值在ISO 12232中定义。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'3200');`<br />**读取结果示例：** "3200" |
| ISO_SPEED_LATITUDE_ZZZ<sup>12+</sup>     | "ISOSpeedLatitudezzz"  | 该标签指示摄像机或输入设备的ISO速度纬度zzz值，该值在ISO 12232中定义。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'3200');`<br />**读取结果示例：** "3200" |
| EXIF_VERSION<sup>12+</sup>               | "ExifVersion"               | 支持的Exif标准版本。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串，小数点分隔。<br />**修改示例：**`imageSource.modifyImageProperty(key,'2.3');`<br />**读取结果示例：** "Exif Version 2.3" |
| DATE_TIME_ORIGINAL<sup>9+</sup>           | "DateTimeOriginal"          | 拍摄时间，例如2022:09:06 15:48:00。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 格式为“YY:MM:DD HH:mm:ss”或“YY:MM:DD”。<br />**修改示例：**`imageSource.modifyImageProperty(key,'2024:07:07 13:45:59');`<br />或`imageSource.modifyImageProperty(key,'2024:07:07');`<br />**读取结果示例：** "2024:07:07"或"2024:07:07 13:45:59" |
| DATE_TIME_DIGITIZED<sup>12+</sup>        | "DateTimeDigitized"         | 图像作为数字数据存储的日期和时间，格式为YYYY:MM:DD HH:mm:ss。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 格式为“YY:MM:DD HH:mm:ss”或“YY:MM:DD”。<br />**修改示例：**`imageSource.modifyImageProperty(key,'2024:07:07 13:45:59');`<br />或`imageSource.modifyImageProperty(key,'2024:07:07');`<br />**读取结果示例：** "2024:07:07"或"2024:07:07 13:45:59" |
| OFFSET_TIME<sup>12+</sup>                | "OffsetTime"          | 在Exif中，OffsetTime字段表示与UTC（协调世界时）的时间偏移，用于确定照片拍摄的本地时间。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 格式为“YY:MM:DD HH:mm:ss”或“YY:MM:DD”。<br />**修改示例：**`imageSource.modifyImageProperty(key,'2024:07:07 13:45:59');`<br />或`imageSource.modifyImageProperty(key,'2024:07:07');`<br />**读取结果示例：** "2024:07:07"或"2024:07:07 13:45:59" |
| OFFSET_TIME_ORIGINAL<sup>12+</sup>       | "OffsetTimeOriginal"  | 此标签记录原始图像创建时的UTC偏移量，对于时间敏感的应用至关重要。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Offset Time Original');`<br />**读取结果示例：** "Offset Time Original" |
| OFFSET_TIME_DIGITIZED<sup>12+</sup>      | "OffsetTimeDigitized" | 此标签记录图像数字化时的UTC偏移量，有助于准确调整时间戳。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Offset Time Digitized');`<br />**读取结果示例：** "Offset Time Digitized" |
| COMPONENTS_CONFIGURATION<sup>12+</sup>   | "ComponentsConfiguration"   | 压缩数据的特定信息。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** "Y Cb Cr -"。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Y Cb Cr -');`<br />**读取结果示例：** "Y Cb Cr -" |
| COMPRESSED_BITS_PER_PIXEL<sup>12+</sup>  | "CompressedBitsPerPixel"    | 用于压缩图像的压缩模式。单位：每像素位数（bit/px）。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0.95');`<br />**读取结果示例：** "0.95" |
| SHUTTER_SPEED<sup>12+</sup>              | "ShutterSpeedValue"         | 快门速度，以APEX（摄影曝光的加法系统）值表示。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />**读取结果示例：** "1.00 EV (1/2 sec.)" |
| APERTURE_VALUE<sup>10+</sup>              | "ApertureValue"             | 光圈值。格式如4/1。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'5.6');`<br />**读取结果示例：** "5.60 EV (f/7.0)" |
| BRIGHTNESS_VALUE<sup>12+</sup>           | "BrightnessValue"           | 图像的亮度值，以APEX单位表示。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'2');`<br />**读取结果示例：** "2.00 EV (13.71 cd/m^2)" |
| EXPOSURE_BIAS_VALUE<sup>10+</sup>         | "ExposureBiasValue"         | 曝光偏差值。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />**读取结果示例：** 1.00 EV |
| MAX_APERTURE_VALUE<sup>12+</sup>         | "MaxApertureValue"          | 最小F数镜头。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />**读取结果示例：** "1.00 EV (f/1.4)" |
| SUBJECT_DISTANCE<sup>12+</sup>           | "SubjectDistance"           | 测量单位为米的主体距离。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'100');`<br />**读取结果示例：** "100.0 m" |
| METERING_MODE<sup>10+</sup>               | "MeteringMode"              | 测光模式。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'Average');`<br />**读取结果示例：** "Average" |
| LIGHT_SOURCE<sup>10+</sup>                | "LightSource"               | 光源。例如Fluorescent。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'Daylight');`<br />**读取结果示例：** "Daylight" |
| FLASH<sup>10+</sup>                      | "Flash"                     | 闪光灯，记录闪光灯状态。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0x00');`<br />或`imageSource.modifyImageProperty(key,'Flash did not fire');`<br />**读取结果示例：** "Flash did not fire" |
| FOCAL_LENGTH<sup>10+</sup>               | "FocalLength"               | 焦距。单位：毫米（mm）。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'50');`<br />或`imageSource.modifyImageProperty(key,'50/1');`<br />**读取结果示例：** "50.0 mm" |
| SUBJECT_AREA<sup>12+</sup>               | "SubjectArea"          | 该标签指示整个场景中主要主体的位置和区域。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 两个非负有理数字符串，空格或者英文逗号隔开。<br />**修改示例：**`imageSource.modifyImageProperty(key,'50 50');`<br />或`imageSource.modifyImageProperty(key,'50,50');`<br />**读取结果示例：** "(x,y) = (50,50)" |
| MAKER_NOTE<sup>12+</sup>                 | "MakerNote"                 | Exif/DCF制造商使用的标签，用于记录任何所需信息。<br/>在API version 12-19，该字段为只读；从API version 20开始，该字段可读写。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Maker Note');`<br />**读取结果示例：** "Maker Note" |
| USER_COMMENT<sup>10+</sup>               | "UserComment"               | 用户注释。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'User Comment');`<br />**读取结果示例：** "User Comment" |
| SUBSEC_TIME<sup>12+</sup>                | "SubsecTime"                | 用于为DateTime标签记录秒的分数的标签。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'629000');`<br />**读取结果示例：** "629000" |
| SUBSEC_TIME_ORIGINAL<sup>12+</sup>       | "SubsecTimeOriginal"        | 用于为DateTimeOriginal标签记录秒的分数的标签。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'629000');`<br />**读取结果示例：** "629000" |
| SUBSEC_TIME_DIGITIZED<sup>12+</sup>      | "SubsecTimeDigitized"       | 用于为DateTimeDigitized标签记录秒的分数的标签。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'62900');`<br />**读取结果示例：** "62900" |
| FLASHPIX_VERSION<sup>12+</sup>           | "FlashpixVersion"           | 该标签表示FPXR文件支持的Flashpix格式版本，增强了设备兼容性。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 版本号格式“1.0”。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1.0');`<br />**读取结果示例：** "FlashPix Version 1.0" |
| COLOR_SPACE<sup>12+</sup>                | "ColorSpace"                | 色彩空间信息标签，通常记录为色彩空间指定符。<br/>1："sRGB"，sRGB标准色彩空间（常见默认值）。<br/>2："Adobe RGB"，exif中未定义，但大量相机使用。<br/>0xffff："Uncalibrated"，表示未校准，颜色空间不明确。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'sRGB');`<br />**读取结果示例：** "sRGB" |
| PIXEL_X_DIMENSION<sup>10+</sup>          | "PixelXDimension"           | 像素X尺寸。单位：像素（px）。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'4096');`<br />**读取结果示例：** "4096" |
| PIXEL_Y_DIMENSION<sup>10+</sup>           | "PixelYDimension"           | 像素Y尺寸。单位：像素（px）。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'3072');`<br />**读取结果示例：** "3072" |
| RELATED_SOUND_FILE<sup>12+</sup>         | "RelatedSoundFile"          | 与图像数据相关的音频文件的名称。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Related Sound File');`<br />**读取结果示例：** "Related Sound File" |
| FLASH_ENERGY<sup>12+</sup>               | "FlashEnergy"               | 图像捕获时的闪光能量，以BCPS表示。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'5.0');`<br />或`imageSource.modifyImageProperty(key,'5/1');`<br />**读取结果示例：** "5" |
| SPATIAL_FREQUENCY_RESPONSE<sup>12+</sup> | "SpatialFrequencyResponse"  | 相机或输入设备的空间频率表。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Spatial Frequency Response');`<br />**读取结果示例：** "Spatial Frequency Response" |
| FOCAL_PLANE_X_RESOLUTION<sup>12+</sup>   | "FocalPlaneXResolution"     | 图像宽度中每FocalPlaneResolutionUnit的像素。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'500');`<br />或`imageSource.modifyImageProperty(key,'500.0');`<br />**读取结果示例：** "500" |
| FOCAL_PLANE_Y_RESOLUTION<sup>12+</sup>   | "FocalPlaneYResolution"     | 图像高度中每FocalPlaneResolutionUnit的像素。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'500');`<br />或`imageSource.modifyImageProperty(key,'500.0');`<br />**读取结果示例：** "500" |
| FOCAL_PLANE_RESOLUTION_UNIT<sup>12+</sup> | "FocalPlaneResolutionUnit"  | 测量FocalPlaneXResolution和FocalPlaneYResolution的单位。<br/>2："Inch"，英寸。<br/>3："Centimeter"，厘米。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'2');`<br />或`imageSource.modifyImageProperty(key,'Inch');`<br />**读取结果示例：** "Inch" |
| SUBJECT_LOCATION<sup>12+</sup>           | "SubjectLocation"           | 主要对象相对于左边缘的位置。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 两个非负整数字符串，空格或者英文逗号隔开。<br />**修改示例：**`imageSource.modifyImageProperty(key,'123 456');`<br />或`imageSource.modifyImageProperty(key,'123,456');`<br />**读取结果示例：** "123,456" |
| EXPOSURE_INDEX<sup>12+</sup>             | "ExposureIndex"             | 捕获时选定的曝光指数。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />**读取结果示例：** "1" |
| SENSING_METHOD<sup>12+</sup>             | "SensingMethod"             | 相机上的图像传感器类型。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'2');`<br />或`imageSource.modifyImageProperty(key,'One-chip color area sensor');`<br />**读取结果示例：** "One-chip color area sensor" |
| FILE_SOURCE<sup>12+</sup>                | "FileSource"                | 表明图像来源。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'DSC');`<br />**读取结果示例：** "DSC" |
| SCENE_TYPE<sup>9+</sup>                   | "SceneType"                 | 拍摄场景模式，例如人像、风光、运动、夜景等。<br/>1："Directly photographed"，图像传感器直接拍摄。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'Directly photographed');`<br />**读取结果示例：** "Directly photographed" |
| CFA_PATTERN<sup>12+</sup>                | "CFAPattern"                | 图像传感器的色彩滤光片（CFA）几何图案。<br/>**读写能力：** 可读写。<br> | 该字段为特有格式，虽然支持读写，但目前版本不做解析。 |
| CUSTOM_RENDERED<sup>12+</sup>            | "CustomRendered"       | 指示图像数据上的特殊处理。<br/>0："Normal process"，正常处理（未自定义渲染）。<br/>1："Custom process"，自定义处理（如艺术效果、美颜、HDR）。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'Custom process');`<br />**读取结果示例：** "Custom process" |
| EXPOSURE_MODE<sup>12+</sup>              | "ExposureMode"         | 拍摄时设置的曝光模式。<br/>0："Auto exposure"，自动曝光（Auto）。<br/>1："Manual exposure"，手动曝光（Manual）。<br/>2："Auto bracket"，自动曝光优先（Auto bracket）。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0');`<br />或`imageSource.modifyImageProperty(key,'Auto exposure');`<br />**读取结果示例：** "Auto exposure" |
| WHITE_BALANCE<sup>10+</sup>              | "WhiteBalance"         | 白平衡。<br/>0："Auto white balance"，自动白平衡。<br/>1："Manual white balance"，手动白平衡。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0');`<br />或`imageSource.modifyImageProperty(key,'Auto white balance');`<br />**读取结果示例：** "Auto white balance" |
| DIGITAL_ZOOM_RATIO<sup>12+</sup>         | "DigitalZoomRatio"     | 捕获时的数字变焦比率。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1/2');`<br />**读取结果示例：** "0.5" |
| FOCAL_LENGTH_IN_35_MM_FILM<sup>10+</sup> | "FocalLengthIn35mmFilm" | 换算成35mm等效焦距。单位：毫米（mm）。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负整数字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'50');`<br />**读取结果示例：** "50" |
| SCENE_CAPTURE_TYPE<sup>12+</sup>         | "SceneCaptureType"     | 捕获的场景类型。<br/>0："Standard"，标准。<br/>1："Landscape"，风景。<br/>2："Portrait"，人像。<br/>3："Night scene"，夜景。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：**  修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0');`<br />或`imageSource.modifyImageProperty(key,'Standard');`<br />**读取结果示例：** "Standard" |
| GAIN_CONTROL<sup>12+</sup>               | "GainControl"          | 整体图像增益调整的程度。<br/>0："Normal"，无增益控制。<br />1："Low gain up"，低增益提升。<br />2："High gain up"，高增益提升。<br/>3："Low gain down"， 低增益降低。<br />4："High gain down"，高增益降低。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：**  修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0');`<br />或`imageSource.modifyImageProperty(key,'Normal');`<br />**读取结果示例：** "Normal" |
| CONTRAST<sup>12+</sup>                   | "Contrast"             | 相机应用的对比度处理方向。<br/>0："Normal"，正常对比度。<br/>1："Soft"，软对比度。<br/>2："Hard"，硬对比度。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0');`<br />或`imageSource.modifyImageProperty(key,'Normal');`<br />**读取结果示例：** "Normal" |
| SATURATION<sup>12+</sup>                 | "Saturation"           | 相机应用的饱和度处理方向。<br/>0："Normal"，正常。<br/>1："Low saturation"，低饱和度。<br/>2："High saturation"，高饱和度。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0');`<br />或`imageSource.modifyImageProperty(key,'Normal');`<br />**读取结果示例：** "Normal" |
| SHARPNESS<sup>12+</sup>                  | "Sharpness"            | 相机应用的锐度处理方向。<br/>0："Normal"，正常（Normal）。<br/>1："Soft"，柔和（Soft）。<br/>2："Hard"，硬（Hard）。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'0');`<br />或`imageSource.modifyImageProperty(key,'Normal');`<br />**读取结果示例：** "Normal" |
| DEVICE_SETTING_DESCRIPTION<sup>12+</sup> | "DeviceSettingDescription" | 特定相机模型的拍照条件信息。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Device Setting Description');`<br />**读取结果示例：** "Device Setting Description" |
| SUBJECT_DISTANCE_RANGE<sup>12+</sup>     | "SubjectDistanceRange" | 表示主体到相机的距离范围。<br/>0："Unknown"，未知。<br/>1："Macro"，宏观。<br/>2："Close view"，近景。<br/>3："Distant view"，远景。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 修改时传入相应的数字或者字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'Macro');`<br />**读取结果示例：** "Macro" |
| IMAGE_UNIQUE_ID<sup>12+</sup>            | "ImageUniqueID"        | 为每张图片唯一分配的标识符。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Image Unique ID');`<br />**读取结果示例：** "Image Unique ID" |
| CAMERA_OWNER_NAME<sup>12+</sup>          | "CameraOwnerName"      | 相机所有者的姓名。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Camera Owner Name');`<br />**读取结果示例：** "Camera Owner Name" |
| BODY_SERIAL_NUMBER<sup>12+</sup>         | "BodySerialNumber"     | 相机机身的序列号。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Body Serial Number');`<br />**读取结果示例：** "Body Serial Number" |
| LENS_SPECIFICATION<sup>12+</sup>         | "LensSpecification"    | 使用的镜头规格。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 四个非负有理数字符串，空格或者英文逗号隔开。<br />**修改示例：**`imageSource.modifyImageProperty(key,'12 12 12 12');`或`imageSource.modifyImageProperty(key,'12,12,12,12');`<br />**读取结果示例：** "12,12,12,12" |
| LENS_MAKE<sup>12+</sup>                  | "LensMake"             | 镜头的制造商。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Lens Make');`<br />**读取结果示例：** "Lens Make" |
| LENS_MODEL<sup>12+</sup>                 | "LensModel"            | 镜头的型号名称。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Lens Model');`<br />**读取结果示例：** "Lens Model" |
| LENS_SERIAL_NUMBER<sup>12+</sup>         | "LensSerialNumber"     | 镜头的序列号。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Lens Serial Number');`<br />**读取结果示例：** "Lens Serial Number" |
| COMPOSITE_IMAGE<sup>12+</sup>            | "CompositeImage"      | 表示图像是否为合成图像。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1');`<br />或`imageSource.modifyImageProperty(key,'NonComposite');`<br />**读取结果示例：** "1" |
| SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE<sup>12+</sup>   | "SourceImageNumberOfCompositeImage" | 用于合成图像的源图像数量。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 两个非负整数字符串，空格或者英文逗号隔开。<br />**修改示例：**`imageSource.modifyImageProperty(key,'1 5');`<br />或`imageSource.modifyImageProperty(key,'1,5');`<br />**读取结果示例：** "1,5" |
| SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE<sup>12+</sup> | "SourceExposureTimesOfCompositeImage" | 合成图像的源图像曝光时间。<br/>**读写能力：** 可读写。<br> | **修改传参格式说明：** 字符串。<br />**修改示例：**`imageSource.modifyImageProperty(key,'Source Exposure Times Of CompositeImage');`<br />**读取结果示例：** "Source Exposure Times Of CompositeImage" |
| GAMMA<sup>12+</sup>                      | "Gamma"                | 表示系数伽马的值。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 非负有理数字符串。<br />**修改示例：**<br />`imageSource.modifyImageProperty(key,'1');`<br />**读取结果示例：** "1" |
| DNG_VERSION<sup>12+</sup>                | "DNGVersion"                | DNG版本标签编码了符合DNG规范的四级版本号。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 四个非负整数字符串，空格或者英文逗号隔开。<br />**修改示例：**<br />`imageSource.modifyImageProperty(key,'1 1 1 1');`<br />或`imageSource.modifyImageProperty(key,'1,1,1,1');`<br />**读取结果示例：** "1,1,1,1" |
| DEFAULT_CROP_SIZE<sup>12+</sup>          | "DefaultCropSize"           | DefaultCropSize指定了原始坐标中的最终图像大小，考虑了额外的边缘像素。单位：像素（px）。<br />**读写能力：** 可读写。<br> | **修改传参格式说明：** 两个非负整数字符串，空格或者英文逗号隔开。<br />**修改示例：**`imageSource.modifyImageProperty(key,'400 400');`<br />或`imageSource.modifyImageProperty(key,'400,400');`<br />**读取结果示例：** "400,400" |
| GIF_LOOP_COUNT<sup>12+</sup>             | "GIFLoopCount"              | GIF图片循环次数。0表示无限循环，其他值表示循环次数。<br />**读写能力：** 只读。<br> | _ |
| IS_XMAGE_SUPPORTED<sup>12+</sup> | "HwMnoteIsXmageSupported" | 是否支持XMAGE。<br />**读写能力：** 可读写。<br> | _ |
| XMAGE_MODE<sup>12+</sup> | "HwMnoteXmageMode" | XMAGE水印模式。<br />**读写能力：** 可读写。<br> | _ |
| XMAGE_LEFT<sup>12+</sup> | "HwMnoteXmageLeft" | 水印区域X1坐标。<br />**读写能力：** 可读写。<br> | _ |
| XMAGE_TOP<sup>12+</sup> | "HwMnoteXmageTop" | 水印区域Y1坐标。<br />**读写能力：** 可读写。<br> | _ |
| XMAGE_RIGHT<sup>12+</sup> | "HwMnoteXmageRight" | 水印区域X2坐标。<br />**读写能力：** 可读写。<br> | _ |
| XMAGE_BOTTOM<sup>12+</sup> | "HwMnoteXmageBottom" | 水印区域Y2坐标。<br />**读写能力：** 可读写。<br> | _ |
| CLOUD_ENHANCEMENT_MODE<sup>12+</sup> | "HwMnoteCloudEnhancementMode" | 云增强模式。<br />**读写能力：** 可读写。<br> | _ |
| WIND_SNAPSHOT_MODE<sup>12+</sup> | "HwMnoteWindSnapshotMode" | 运动快拍模式。<br />**读写能力：** 只读。<br> | _ |
| SCENE_POINTER<sup>12+</sup> | "HwMnoteScenePointer" | 场景指针。<br />**读写能力：** 只读。<br> | _ |
| SCENE_VERSION<sup>12+</sup> | "HwMnoteSceneVersion" | 场景算法版本信息。<br />**读写能力：** 只读。<br> | _ |
| SCENE_FOOD_CONF<sup>11+</sup> | "HwMnoteSceneFoodConf" | 拍照场景：食物。<br />**读写能力：** 只读。<br> | _ |
| SCENE_STAGE_CONF<sup>11+</sup> | "HwMnoteSceneStageConf" | 拍照场景：舞台。<br />**读写能力：** 只读。<br> | _ |
| SCENE_BLUE_SKY_CONF<sup>11+</sup> | "HwMnoteSceneBlueSkyConf" | 拍照场景：蓝天。<br />**读写能力：** 只读。<br> | _ |
| SCENE_GREEN_PLANT_CONF<sup>11+</sup> | "HwMnoteSceneGreenPlantConf" | 拍照场景：绿植。<br />**读写能力：** 只读。<br> | _ |
| SCENE_BEACH_CONF<sup>11+</sup> | "HwMnoteSceneBeachConf" | 拍照场景：沙滩。<br />**读写能力：** 只读。<br> | _ |
| SCENE_SNOW_CONF<sup>11+</sup> | "HwMnoteSceneSnowConf" | 拍照场景：下雪。<br />**读写能力：** 只读。<br> | _ |
| SCENE_SUNSET_CONF<sup>11+</sup> | "HwMnoteSceneSunsetConf" | 拍照场景：日落。<br />**读写能力：** 只读。<br> | _ |
| SCENE_FLOWERS_CONF<sup>11+</sup> | "HwMnoteSceneFlowersConf" | 拍照场景：花。<br />**读写能力：** 只读。<br> | _ |
| SCENE_NIGHT_CONF<sup>11+</sup> | "HwMnoteSceneNightConf" | 拍照场景：夜晚。<br />**读写能力：** 只读。<br> | _ |
| SCENE_TEXT_CONF<sup>11+</sup> | "HwMnoteSceneTextConf" | 拍照场景：文本。<br />**读写能力：** 只读。<br> | _ |
| FACE_POINTER<sup>12+</sup> | "HwMnoteFacePointer" | 脸部指针。<br />**读写能力：** 只读。<br> | _ |
| FACE_VERSION<sup>12+</sup> | "HwMnoteFaceVersion" | 人脸算法版本信息。<br />**读写能力：** 只读。<br> | _ |
| FACE_COUNT<sup>11+</sup> | "HwMnoteFaceCount" | 人脸数量。<br />**读写能力：** 只读。<br> | _ |
| FACE_CONF<sup>12+</sup> | "HwMnoteFaceConf" | 人脸置信度。<br />**读写能力：** 只读。<br> | _ |
| FACE_SMILE_SCORE<sup>12+</sup> | "HwMnoteFaceSmileScore" | FaceCount张人脸的笑脸分数。<br />**读写能力：** 只读。<br> | _ |
| FACE_RECT<sup>12+</sup> | "HwMnoteFaceRect" | 脸部矩形。<br />**读写能力：** 只读。<br> | _ |
| FACE_LEYE_CENTER<sup>12+</sup> | "HwMnoteFaceLeyeCenter" | 左眼中心。<br />**读写能力：** 只读。<br> | _ |
| FACE_REYE_CENTER<sup>12+</sup> | "HwMnoteFaceReyeCenter" | 右眼中心。<br />**读写能力：** 只读。<br> | _ |
| FACE_MOUTH_CENTER<sup>12+</sup> | "HwMnoteFaceMouthCenter" | 嘴中心。<br />**读写能力：** 只读。<br> | _ |
| CAPTURE_MODE<sup>10+</sup> | "HwMnoteCaptureMode" | 捕获模式。<br />**读写能力：** 可读写。<br> | _ |
| BURST_NUMBER<sup>12+</sup> | "HwMnoteBurstNumber" | 连拍次数。<br />**读写能力：** 只读。<br> | _ |
| FRONT_CAMERA<sup>12+</sup> | "HwMnoteFrontCamera" | 是否是前置相机自拍。<br />**读写能力：** 只读。<br> | _ |
| ROLL_ANGLE<sup>11+</sup> | "HwMnoteRollAngle" | 滚动角度。<br />**读写能力：** 只读。<br> | _ |
| PITCH_ANGLE<sup>11+</sup> | "HwMnotePitchAngle" | 俯仰角度。<br />**读写能力：** 只读。<br> | _ |
| PHYSICAL_APERTURE<sup>10+</sup> | "HwMnotePhysicalAperture" | 物理孔径，光圈大小。单位：毫米（mm）。<br />**读写能力：** 只读。<br> | _ |
| FOCUS_MODE<sup>11+</sup> | "HwMnoteFocusMode" | 对焦模式。<br />**读写能力：** 只读。<br> | _ |

## FragmentMapPropertyKey<sup>13+</sup>

表示水印裁剪图图片信息的枚举。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值                    | 说明                                |
| ------------- | --------------------- | ----------------------------------- |
| X_IN_ORIGINAL | "XInOriginal"         | 水印裁剪图左上角在原始图中的X坐标。 |
| Y_IN_ORIGINAL | "YInOriginal"         | 水印裁剪图左上角在原始图中的Y坐标。 |
| WIDTH         | "FragmentImageWidth"  | 水印裁剪图的宽。单位：像素（px）。                    |
| HEIGHT        | "FragmentImageHeight" | 水印裁剪图的高。单位：像素（px）。                    |

## GifPropertyKey<sup>20+</sup>

表示GIF图片信息的枚举。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 值                | 说明                   |
| ----------------- | ----------------- | --------------------- |
| GIF_DELAY_TIME    | 'GifDelayTime'    | GIF图片钳制后的帧延迟时长。钳制范围为[100, 65535]。<br>单位：毫秒（ms）。 |
| GIF_DISPOSAL_TYPE | 'GifDisposalType' | GIF图片的每帧处置方式。<br>- 0表示未指定。<br>- 1表示不处置。<br>- 2表示还原为背景色。<br>- 3表示还原为前一帧。<br>该值为正整数。 |
| GIF_HAS_GLOBAL_COLOR_MAP | 'GifHasGlobalColorMap' | GIF图像是否包含全局调色板。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| GIF_CANVAS_WIDTH | 'GifCanvasWidth' | GIF图像的画布宽度。<br>单位：像素（px）。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| GIF_CANVAS_HEIGHT | 'GifCanvasHeight' | GIF图像的画布高度。<br>单位：像素（px）。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| GIF_LOOP_COUNT | 'GifLoopCount' | GIF图片循环次数。<br>取值为0或正整数。0表示无限循环，其他值表示实际循环次数。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| GIF_UNCLAMPED_DELAY_TIME | 'GifUnclampedDelayTime' | GIF图片未钳制的帧延迟时间。<br>单位：毫秒（ms）。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## HeifsPropertyKey<sup>23+</sup>

表示HEIF序列图片信息的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 值                | 说明                   |
| ----------------- | ----------------- | --------------------- |
| HEIFS_DELAY_TIME    | 'HeifsDelayTime'    | HEIF序列图片的每帧延迟时长。<br>单位：毫秒（ms）。 |
| HEIFS_UNCLAMPED_DELAY_TIME | 'HeifsUnclampedDelayTime' | HEIF序列图片未钳制的帧延迟时长。<br>单位：毫秒（ms）。<br>**起始版本：** 26.0.0 |
| HEIFS_CANVAS_HEIGHT | 'HeifsCanvasHeight' | HEIF序列图片的画布高度。<br>单位：像素（px）。<br>**起始版本：** 26.0.0 |
| HEIFS_CANVAS_WIDTH | 'HeifsCanvasWidth' | HEIF序列图片的画布宽度。<br>单位：像素（px）。<br>**起始版本：** 26.0.0 |

## WebPPropertyKey<sup>24+</sup>

表示WebP图片信息的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 值                | 说明                   |
| ----------------- | ----------------- | --------------------- |
| CANVAS_WIDTH    | 'WebPCanvasWidth'    | WebP图片的画布像素宽度。<br>单位：像素（px）。 |
| CANVAS_HEIGHT    | 'WebPCanvasHeight'    | WebP图片的画布像素高度。<br>单位：像素（px）。 |
| DELAY_TIME    | 'WebPDelayTime'    | WebP图片钳制后的帧延迟时长。钳制范围为[100, 65535]。<br>单位：毫秒（ms）。 |
| UNCLAMPED_DELAY_TIME    | 'WebPUnclampedDelayTime'    | WebP图片未钳制的帧延迟时长。<br>单位：毫秒（ms）。 |
| LOOP_COUNT    | 'WebPLoopCount'    | WebP图片动画循环的次数。如果取值为0，则表示不限次数。 |

## DngPropertyKey<sup>24+</sup>

表示DNG图片信息的枚举。

> **说明：**
>
> - 关于字段的更详细描述请参考DNG协议文档DNG Specification 1.4.0.0。
> - 返回字段类型具体参考[DngMetadata](arkts-apis-image-i.md#dngmetadata24)。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 值                | 说明                   |
| ----------------- | ----------------- | --------------------- |
| DNG_VERSION    | 'DNGVersion' | DNG图片的版本号。 |
| DNG_BACKWARD_VERSION | 'DNGBackwardVersion' | DNG文件向后兼容的最低版本号。 |
| UNIQUE_CAMERA_MODEL | 'UniqueCameraModel' | 相机的唯一型号标识，用于区分不同设备。 |
| LOCALIZED_CAMERA_MODEL | 'LocalizedCameraModel' | 本地化后的相机型号名称。 |
| CFA_PLANE_COLOR | 'CFAPlaneColor' | CFA各平面的颜色通道定义。 |
| CFA_LAYOUT | 'CFALayout' | CFA布局类型，如RGGB、BGGR等。 |
| LINEARIZATION_TABLE | 'LinearizationTable' | 线性化查找表，用于将原始传感器值映射为线性光强度。 |
| BLACK_LEVEL_REPEAT_DIM | 'BlackLevelRepeatDim' | 黑电平重复维度。 |
| BLACK_LEVEL | 'BlackLevel' | 零光照下的编码电平，按CFA平面顺序排列。 |
| BLACK_LEVEL_DELTA_H | 'BlackLevelDeltaH' | 水平方向黑电平校正增量。 |
| BLACK_LEVEL_DELTA_V | 'BlackLevelDeltaV' | 垂直方向黑电平校正增量。 |
| WHITE_LEVEL | 'WhiteLevel' | 白电平，表示传感器最大有效输出。 |
| DEFAULT_SCALE | 'DefaultScale' | 默认缩放比例。 |
| DEFAULT_CROP_ORIGIN | 'DefaultCropOrigin' | 默认裁剪区域的左上角坐标（x, y）。 |
| DEFAULT_CROP_SIZE | 'DefaultCropSize' | 默认裁剪区域的宽度和高度。 |
| COLOR_MATRIX1 | 'ColorMatrix1' | 第一校准光源下的色彩变换矩阵。 |
| COLOR_MATRIX2 | 'ColorMatrix2' | 第二校准光源下的色彩变换矩阵。 |
| CAMERA_CALIBRATION1 | 'CameraCalibration1' | 第一校准光源下的相机校准矩阵。 |
| CAMERA_CALIBRATION2 | 'CameraCalibration2' | 第二校准光源下的相机校准矩阵。 |
| REDUCTION_MATRIX1 | 'ReductionMatrix1' | 第一校准光源下的降维矩阵。 |
| REDUCTION_MATRIX2 | 'ReductionMatrix2' | 第二校准光源下的降维矩阵。 |
| ANALOG_BALANCE | 'AnalogBalance' | 模拟增益平衡系数。 |
| AS_SHOT_NEUTRAL | 'AsShotNeutral' | 拍摄时的中性白点。 |
| AS_SHOT_WHITEXY | 'AsShotWhiteXY' | 拍摄时白点的CIE x-y色度坐标。 |
| BASELINE_EXPOSURE | 'BaselineExposure' | 基准曝光补偿值，单位：EV。 |
| BASELINE_NOISE | 'BaselineNoise' | 基准噪声水平。 |
| BASELINE_SHARPNESS | 'BaselineSharpness' | 基准锐度增益。 |
| BAYER_GREEN_SPLIT | 'BayerGreenSplit' | Bayer图像中两个绿色通道的分离程度。 |
| LINEAR_RESPONSE_LIMIT | 'LinearResponseLimit' | 线性响应上限，有效值范围为[0.0, 1.0]。 |
| CAMERA_SERIAL_NUMBER | 'CameraSerialNumber' | 相机序列号。 |
| LENS_INFO | 'LensInfo' | 镜头信息。 |
| CHROMA_BLUR_RADIUS | 'ChromaBlurRadius' | 色度模糊半径。单位：像素（px）。 |
| ANTI_ALIAS_STRENGTH | 'AntiAliasStrength' | 抗锯齿滤波器强度。 |
| SHADOW_SCALE | 'ShadowScale' | 阴影区域缩放因子。 |
| DNG_PRIVATE_DATA | 'DNGPrivateData' | 厂商私有数据块。 |
| MAKER_NOTE_SAFETY | 'MakerNoteSafety' | EXIF MakerNote 是否安全可保留。0：不安全，1：安全 |
| CALIBRATION_ILLUMINANT1 | 'CalibrationIlluminant1' | 第一校准光源类型。 |
| CALIBRATION_ILLUMINANT2 | 'CalibrationIlluminant2' | 第二校准光源类型。 |
| BEST_QUALITY_SCALE | 'BestQualityScale' | 最佳画质缩放比例。 |
| RAW_DATA_UNIQUE_ID | 'RawDataUniqueID' | 原始图像数据的唯一标识符。 |
| ORIGINAL_RAW_FILE_NAME | 'OriginalRawFileName' | 原始RAW文件名。 |
| ORIGINAL_RAW_FILE_DATA | 'OriginalRawFileData' | 原始RAW文件的完整数据。 |
| ACTIVE_AREA | 'ActiveArea' | 有效图像区域。 |
| MASKED_AREAS | 'MaskedAreas' | 被遮蔽区域列表。 |
| AS_SHOT_ICC_PROFILE | 'AsShotICCProfile' | 拍摄时使用的ICC色彩配置文件。 |
| AS_SHOT_PRE_PROFILE_MATRIX | 'AsShotPreProfileMatrix' | 应用ICC配置文件前的预变换矩阵。 |
| CURRENT_ICC_PROFILE | 'CurrentICCProfile' | 当前使用的ICC色彩配置文件。 |
| CURRENT_PRE_PROFILE_MATRIX | 'CurrentPreProfileMatrix' | 当前ICC配置文件前的预变换矩阵。 |
| COLORIMETRIC_REFERENCE | 'ColorimetricReference' | 色度参考标准。 |
| CAMERA_CALIBRATION_SIGNATURE | 'CameraCalibrationSignature' | 相机校准签名。 |
| PROFILE_CALIBRATION_SIGNATURE | 'ProfileCalibrationSignature' | 配置文件校准签名。 |
| EXTRA_CAMERA_PROFILES | 'ExtraCameraProfiles' | 额外相机配置文件索引列表。 |
| AS_SHOT_PROFILE_NAME | 'AsShotProfileName' | 拍摄时使用的配置文件名称。 |
| NOISE_REDUCTION_APPLIED | 'NoiseReductionApplied' | 已应用的降噪强度级别。 |
| PROFILE_NAME | 'ProfileName' | 色彩配置文件名称。 |
| PROFILE_HUE_SAT_MAP_DIMS | 'ProfileHueSatMapDims' | 色调/饱和度映射表维度。 |
| PROFILE_HUE_SAT_MAP_DATA1 | 'ProfileHueSatMapData1' | 第一组色调/饱和度映射表数据。 |
| PROFILE_HUE_SAT_MAP_DATA2 | 'ProfileHueSatMapData2' | 第二组色调/饱和度映射表数据。 |
| PROFILE_TONE_CURVE | 'ProfileToneCurve' | 配置文件色调曲线。 |
| PROFILE_EMBED_POLICY | 'ProfileEmbedPolicy' | 配置文件嵌入策略。 |
| PROFILE_COPYRIGHT | 'ProfileCopyright' | 配置文件版权信息。 |
| FORWARD_MATRIX1 | 'ForwardMatrix1' | 第一前向变换矩阵。 |
| FORWARD_MATRIX2 | 'ForwardMatrix2' | 第二前向变换矩阵。 |
| PREVIEW_APPLICATION_NAME | 'PreviewApplicationName' | 预览图生成应用程序名称。 |
| PREVIEW_APPLICATION_VERSION | 'PreviewApplicationVersion' | 预览图生成应用程序版本。 |
| PREVIEW_SETTINGS_NAME | 'PreviewSettingsName' | 预览图处理设置名称。 |
| PREVIEW_SETTINGS_DIGEST | 'PreviewSettingsDigest' | 预览图设置的MD5摘要。 |
| PREVIEW_COLOR_SPACE | 'PreviewColorSpace' | 预览图色彩空间。 |
| PREVIEW_DATE_TIME | 'PreviewDateTime' | 预览图生成时间。 |
| RAW_IMAGE_DIGEST | 'RawImageDigest' | 原始图像数据的MD5摘要。 |
| ORIGINAL_RAW_FILE_DIGEST | 'OriginalRawFileDigest' | 原始RAW文件数据的MD5摘要。 |
| SUB_TILE_BLOCK_SIZE | 'SubTileBlockSize' | 图像分块存储，定义块的长和宽。 |
| ROW_INTERLEAVE_FACTOR | 'RowInterleaveFactor' | 行交织因子。 |
| PROFILE_LOOK_TABLE_DIMS | 'ProfileLookTableDims' | ProfileLookTableData的维度。 |
| PROFILE_LOOK_TABLE_DATA | 'ProfileLookTableData' | 色彩表数据。 |
| OPCODE_LIST1 | 'OpcodeList1' | 第一操作码列表。 |
| OPCODE_LIST2 | 'OpcodeList2' | 第二操作码列表。 |
| OPCODE_LIST3 | 'OpcodeList3' | 第三操作码列表。 |
| NOISE_PROFILE | 'NoiseProfile' | 噪声剖面参数。 |
| ORIGINAL_DEFAULT_FINAL_SIZE | 'OriginalDefaultFinalSize' | 原始默认最终输出尺寸（宽, 高）。 |
| ORIGINAL_BEST_QUALITY_FINAL_SIZE | 'OriginalBestQualityFinalSize' | 原始最佳画质输出尺寸（宽, 高）。 |
| ORIGINAL_DEFAULT_CROP_SIZE | 'OriginalDefaultCropSize' | 原始默认裁剪尺寸（宽, 高）。 |
| PROFILE_HUE_SAT_MAP_ENCODING | 'ProfileHueSatMapEncoding' | 色调/饱和度映射表编码方式。 |
| PROFILE_LOOK_TABLE_ENCODING | 'ProfileLookTableEncoding' | 色彩表编码方式。 |
| BASELINE_EXPOSURE_OFFSET | 'BaselineExposureOffset' | 基准曝光偏移量，单位：EV。 |
| DEFAULT_BLACK_RENDER | 'DefaultBlackRender' | 默认黑场渲染方式。 |
| NEW_RAW_IMAGE_DIGEST | 'NewRawImageDigest' | 修改后原始图像数据的新MD5摘要。 |
| RAW_TO_PREVIEW_GAIN | 'RawToPreviewGain' | 主RAW图与预览图之间的增益比。 |
| DEFAULT_USER_CROP | 'DefaultUserCrop' | 默认用户裁剪区域。 |

## PngPropertyKey

表示PNG图片信息的枚举。

> **说明：**
>
> 返回字段类型具体参考[PngMetadata](arkts-apis-image-PngMetadata.md)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称 | 值 | 说明 |
| ---- | -- | ---- |
| X_PIXELS_PER_METER | 'PngXPixelsPerMeter' | PNG图像X方向每米像素数。 |
| MODIFICATION_TIME | 'PngModificationTime' | PNG图像的最后一次修改的时间。 |
| SOFTWARE | 'PngSoftware' | 用于生成PNG图像的软件名称和版本。 |
| COPYRIGHT | 'PngCopyright' | PNG图像的版权信息。 |
| CREATION_TIME | 'PngCreationTime' | PNG图像的创建时间。 |
| SRGB_INTENT | 'PngSRGBIntent' | PNG图像的sRGB（standard Red Green Blue，标准红绿蓝）渲染意图。<br>- 0表示感知意图。<br>- 1表示相对比色意图。<br>- 2表示饱和度意图。<br>- 3绝对色度意图。 |
| AUTHOR | 'PngAuthor' | PNG图像的作者。 |
| INTERLACE_TYPE | 'PngInterlaceType' | PNG图像的交错模式。<br>- 0表示无交错模式（图像按照从上到下、从左到右的顺序加载）。<br>- 1表示交错模式（通过多次扫描逐步显示图像，图像在加载过程中逐渐清晰）。 |
| WARNING | 'PngWarning' | PNG图像的警告信息。 |
| Y_PIXELS_PER_METER | 'PngYPixelsPerMeter' | PNG图像Y方向每米像素数。 |
| GAMMA | 'PngGamma' | PNG图像的系数伽马的值。 |
| CHROMATICITIES | 'PngChromaticities' | PNG图像的原色与白点色度坐标cHRM（primary chromaticities and white point）。该信息可用于与设备无关的色彩校正。 |
| DESCRIPTION | 'PngDescription' | PNG图像的描述。 |
| TITLE | 'PngTitle' | PNG图像的标题。 |
| COMMENT | 'PngComment' | PNG图像的注释。 |
| DISCLAIMER | 'PngDisclaimer' | PNG图像的免责声明。 |

## JfifPropertyKey

表示JFIF图片信息的枚举。

> **说明：**
>
> 返回字段类型具体参考[JfifMetadata](arkts-apis-image-JfifMetadata.md)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称 | 值 | 说明 |
| ---- | -- | ---- |
| DENSITY_UNIT | 'JfifDensityUnit' | 用于定义JfifXDensity（水平像素密度）和JfifYDensity（垂直像素密度）的物理度量单位。<br>- 0表示无单位（仅像素宽高比）。<br>- 1表示每英寸像素数（DPI）。<br>- 2表示每厘米像素数（DPC）。<br>该值为正整数。 |
| X_DENSITY | 'JfifXDensity' | JFIF图像X方向密度。 |
| Y_DENSITY | 'JfifYDensity' | JFIF图像Y方向密度。 |
| VERSION | 'JfifVersion' | JFIF图像版本。 |
| IS_PROGRESSIVE | 'JfifIsProgressive' | 图像是否采用渐进式编码，即图像在加载过程中按多次扫描逐步提升清晰度。true表示采用，false表示不采用。 |

## TiffPropertyKey

表示TIFF图片信息的枚举。

> **说明：**
>
> 返回字段类型具体参考[TiffMetadata](arkts-apis-image-TiffMetadata.md)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称 | 值 | 说明 |
| ---- | -- | ---- |
| DOCUMENT_NAME | 'TiffDocumentName' | 文档或图像的名称。 |
| PHOTOMETRIC_INTERPRETATION | 'TiffPhotometricInterpretation' | 定义像素颜色的解释方式（如RGB、灰度）。 |
| ORIENTATION | 'TiffOrientation' | 图像方向。<br/>- 1表示"Top-left"，图像未旋转。<br/>- 2表示"Top-right"，镜像水平翻转。<br/>- 3表示"Bottom-right"，图像旋转180°。<br/>- 4表示"Bottom-left"，镜像垂直翻转。<br/>- 5表示"Left-top"，镜像水平翻转后再顺时针旋转270°。<br/>- 6表示"Right-top"，顺时针旋转90°。<br/>- 7表示"Right-bottom"，镜像水平翻转后再顺时针旋转90°。<br/>- 8表示"Left-bottom"，顺时针旋转270°。<br/>若读到未定义值，会返回 `Unknown Value x`，其中 `x` 表示该标签的原始取值。 |
| RESOLUTION_UNIT | 'TiffResolutionUnit' | XResolution（水平分辨率）和YResolution（垂直分辨率）的单位，取值为英寸（Inch）或厘米（Centimeter）。 |
| COPYRIGHT | 'TiffCopyright' | 图像的版权信息。 |
| DATE_TIME | 'TiffDateTime' | 与图像关联的日期和时间（通常为最后修改时间）。 |
| IMAGE_DESCRIPTION | 'TiffImageDescription' | 图像信息描述。 |
| Y_RESOLUTION | 'TiffYResolution' | 垂直方向分辨率（每分辨率单位的像素数）。 |
| X_RESOLUTION | 'TiffXResolution' | 水平方向分辨率（每分辨率单位的像素数）。 |
| WHITE_POINT | 'TiffWhitePoint' | 用于指定图像的白点（white point）色度坐标，即图像颜色空间中被认为是“白色”的参考点。 |
| TILE_LENGTH | 'TiffTileLength' | 每个图像分块的高度。单位：像素（px）。 |
| TRANSFER_FUNCTION | 'TiffTransferFunction' | 图像的传递函数，通常用于颜色校正。 |
| TILE_WIDTH | 'TiffTileWidth' | 每个图像分块的宽度。单位：像素（px）。 |
| MAKE | 'TiffMake' | 拍摄设备制造商。 |
| MODEL | 'TiffModel' | 拍摄设备型号名称或编号。 |
| HOST_COMPUTER | 'TiffHostComputer' | 用于图像处理的主机或系统。 |
| COMPRESSION | 'TiffCompression' | TIFF图像数据所用的压缩方案。<br>- 1表示无压缩。<br>- 5表示LZW（基于字典的无损压缩算法）。<br>- 7表示JPEG基线。<br>- 8表示Deflate（基于LZ77+Huffman的无损压缩算法） |
| SOFTWARE | 'TiffSoftware' | 用于生成图像的软件名称和版本。 |
| PRIMARY_CHROMATICITIES | 'TiffPrimaryChromaticities' | 图像中RGB三原色的色度坐标。 |
| ARTIST | 'TiffArtist' | 创建图像的用户名称。 |

## AvisPropertyKey

表示AVIS图片信息的枚举。

> **说明：**
>
> 返回字段类型具体参考[AvisMetadata](arkts-apis-image-AvisMetadata.md)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 值                | 说明                   |
| ----------------- | ----------------- | --------------------- |
| DELAY_TIME    | 'AvisDelayTime'    | AVIS图片的每帧播放时长。<br>单位：毫秒（ms）。 |

## ImageFormat<sup>9+</sup>

表示图片格式的枚举。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称         |   值   | 说明                 |
| ------------ | ------ | -------------------- |
| YCBCR_422_SP | 1000   | YCBCR422半平面格式。 |
| JPEG         | 2000   | JPEG编码格式。       |

## ComponentType<sup>9+</sup>

表示图像的组件类型的枚举。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

| 名称  |   值   | 说明        |
| ----- | ------ | ----------- |
| YUV_Y | 1      | 亮度信息。  |
| YUV_U | 2      | 色度信息。  |
| YUV_V | 3      | 色度信息。  |
| JPEG  | 4      | JPEG 类型。 |

## DecodingDynamicRange<sup>12+</sup>

描述解码时期望的图像动态范围。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值       | 说明         |
| ------------- | ----------| ------------ |
| AUTO          | 0    | 自适应，根据图片信息处理。即如果图片本身为HDR图片，则会按照HDR内容解码；反之按照SDR内容解码。通过[CreateIncrementalSource](arkts-apis-image-f.md#imagecreateincrementalsource9)创建的ImageSource会解码为SDR内容。  |
| SDR           | 1    | 按照标准动态范围处理图片。   |
| HDR           | 2    | 按照高动态范围处理图片。通过[CreateIncrementalSource](arkts-apis-image-f.md#imagecreateincrementalsource9)创建的ImageSource会解码为SDR内容。     |

## PackingDynamicRange<sup>12+</sup>

描述编码时期望的图像动态范围。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值       | 说明         |
| ------------- | ----------| ------------ |
| AUTO          | 0    | 自适应，根据[pixelmap](arkts-apis-image-PixelMap.md)内容处理。即如果pixelmap本身为HDR，则会按照HDR内容进行编码；反之按照SDR内容编码。  |
| SDR           | 1    | 按照标准动态范围处理图片。   |

## CropAndScaleStrategy<sup>18+</sup>

表示裁剪与缩放的先后策略的枚举。

如果在配置解码选项[DecodingOptions](arkts-apis-image-i.md#decodingoptions7)时，未填入参数cropAndScaleStrategy，并且同时设置了参数desiredRegion和desiredSize，由于系统对于不同图片格式采用的解码算法不同，最终解码效果将略有差异。

例如原始图片大小为200x200，传入desiredSize:{width: 150, height: 150}，desiredRegion:{x: 0, y: 0, width: 100, height: 100}，即预期解码原图左上角1/4区域，最终将pixelMap大小缩放至150x150返回。

对于jpeg、webp图片（部分dng图片解码时会优先解码图片中的jpeg预览图，在此场景下也会被视为jpeg图片格式）会先进行下采样，例如按照7/8下采样，再基于175x175的图片大小进行区域裁剪，因此最终的区域内容稍大于原图的左上角1/4区域。

对于svg图片，由于是矢量图，可以任意缩放不损失清晰度，在解码时会根据desiredSize与原图Size的比例选择缩放比例，再基于缩放后的图片大小进行区域裁剪，因此最终返回的解码区域会有所差异。

针对该场景，建议在解码选项同时设置了desiredRegion与desiredSize时，参数cropAndScaleStrategy应传入CROP_FIRST保证效果一致。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值       | 说明         |
| ------------- | ----------| ------------ |
| SCALE_FIRST   | 1    | 解码参数如果同时设置desiredRegion与desiredSize，先根据desiredSize进行缩放，再根据desiredRegion进行区域裁剪。     |
| CROP_FIRST    | 2    | 解码参数如果同时设置desiredRegion与desiredSize，先根据desiredRegion进行区域裁剪，再根据desiredSize进行缩放。     |

## HdrMetadataKey<sup>12+</sup>

表示[PixelMap](arkts-apis-image-PixelMap.md)使用的HDR相关元数据信息的关键字的枚举。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值       | 说明         |
| ------------- | ----------| ------------ |
| HDR_METADATA_TYPE    | 0    | [PixelMap](arkts-apis-image-PixelMap.md)使用的元数据类型。  |
| HDR_STATIC_METADATA  | 1    | 静态元数据。   |
| HDR_DYNAMIC_METADATA | 2    | 动态元数据。   |
| HDR_GAINMAP_METADATA | 3    | 增益图使用的元数据。   |

## HdrMetadataType<sup>12+</sup>

表示[HdrMetadataKey](#hdrmetadatakey12)中HDR_METADATA_TYPE关键字对应的值的枚举。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值  | 说明         |
| ------------- | --- | ------------ |
| NONE          | 0   | 无元数据内容。  |
| BASE          | 1   | 表示用于基础图的元数据。   |
| GAINMAP       | 2   | 表示用于增益图的元数据。   |
| ALTERNATE     | 3   | 表示用于合成后HDR图的元数据。   |

## AntiAliasingLevel<sup>12+</sup>

缩放时的插值算法。可根据缩放质量和性能需求选择合适的级别。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                   |   值   | 说明              |
| ---------------------- | ------ | ----------------- |
| NONE                | 0      | 最近邻插值算法。<br>速度最快，放大时会有明显的马赛克/锯齿感，适合对性能要求高、对画质要求低的快速缩放场景。 |
| LOW                 | 1      | 双线性插值算法。<br>适合一般缩放场景。   |
| MEDIUM              | 2      | 双线性插值算法，同时开启Mipmap。<br>适合缩小图片的场景，能极好地消除大幅缩小时的混叠与纹理闪烁。   |
| HIGH                | 3      | 三次卷积插值算法。<br>适合对画质要求较高的放大场景。   |

## AllocatorType<sup>15+</sup>

表示用于图像解码的内存类型的枚举。开发者可根据场景选择合适的内存申请类型。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称         | 值   | 说明                               |
| ------------ | ---- | ---------------------------------- |
| AUTO         | 0    | 系统决定内存申请类型。     |
| DMA          | 1    | 使用DMA（Direct Memory Access，直接内存访问）的内存类型，适用于对解码及渲染性能有较高要求的场景。根据设备硬件的差异可能会在每行像素的末尾产生用于内存对齐的空白填充字节。            |
| SHARE_MEMORY | 2    | 使用共享内存（Share Memory）的内存类型。 |

## Orientation<sup>23+</sup>

表示图像方向类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称         | 值   | 说明                                |
| ------------ | ---- | ----------------------------------- |
| TOP_LEFT     | 1    | 图像未旋转。                        |
| TOP_RIGHT    | 2    | 图像是水平镜像的。                  |
| BOTTOM_RIGHT | 3    | 图像旋转180度。                   |
| BOTTOM_LEFT  | 4    | 图像垂直镜像。                      |
| LEFT_TOP     | 5    | 图像水平镜像，然后顺时针旋转270度。 |
| RIGHT_TOP    | 6    | 图像顺时针旋转90度。                |
| RIGHT_BOTTOM | 7    | 图像水平镜像，然后顺时针旋转90度。  |
| LEFT_BOTTOM  | 8    | 图像顺时针旋转270度。               |

## FocusMode<sup>23+</sup>

表示焦点模式类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称 | 值   | 说明           |
| ---- | ---- | -------------- |
| AF_A | 0    | 自动对焦。     |
| AF_S | 1    | 单次自动对焦。 |
| AF_C | 2    | 连续自动对焦。 |
| MF   | 3    | 手动对焦。     |

## XmageColorMode<sup>23+</sup>

表示XMAGE颜色模式类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称   | 值   | 说明       |
| ------ | ---- | ---------- |
| NORMAL | 0    | 标准模式。 |
| BRIGHT | 1    | 明亮模式。 |
| SOFT   | 2    | 柔焦模式。 |
| MONO   | 3    | 黑白模式。 |

## XMPTagType

表示XMP标签类型的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称            | 值   | 说明                                                                 |
| --------------- | ---- | ------------------------------------------------------------------- |
| UNKNOWN         | 0    | 未知类型。                                                           |
| STRING          | 1    | 字符串类型。                                                         |
| UNORDERED_ARRAY | 2    | 无序数组类型。序列化时，此类型在XMP元数据中的格式为\<rdf:Bag>。          |
| ORDERED_ARRAY   | 3    | 有序数组类型。序列化时，此类型在XMP元数据中的格式为\<rdf:Seq>。          |
| ALTERNATE_ARRAY | 4    | 备选数组类型。序列化时，此类型在XMP元数据中的格式为\<rdf:Alt>。          |
| ALTERNATE_TEXT  | 5    | 多语言文本类型。序列化时，此类型为XMP格式的xml:lang限定符组成的备选数组。 |
| STRUCTURE       | 6    | 结构体类型。不同于数组元素，结构体字段可以属于不同的命名空间。            |
