# Enums

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## PixelMapFormat<sup>7+</sup>

枚举，图片像素格式。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                   |   值   | 说明              |
| ---------------------- | ------ | ----------------- |
| UNKNOWN                | 0      | 未知格式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。        |
| ARGB_8888<sup>18+</sup> | 1 | 颜色信息由透明度（Alpha）与R（Red），G（Green），B（Blue）四部分组成，每个部分占8位，总共占32位。 该格式当前仅支持PixelMap的接口。|
| RGB_565                | 2      | 颜色信息由R（Red），G（Green），B（Blue）三部分组成，R占5位，G占6位，B占5位，总共占16位。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。     |
| RGBA_8888              | 3      | 颜色信息由R（Red），G（Green），B（Blue）与透明度（Alpha）四部分组成，每个部分占8位，总共占32位。对应[相机服务CameraFormat中的CAMERA_FORMAT_RGBA_8888](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| BGRA_8888<sup>9+</sup> | 4      | 颜色信息由B（Blue），G（Green），R（Red）与透明度（Alpha）四部分组成，每个部分占8位，总共占32位。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| RGB_888<sup>9+</sup>   | 5      | 颜色信息由R（Red），G（Green），B（Blue）三部分组成，每个部分占8位，总共占24位。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。   |
| ALPHA_8<sup>9+</sup>   | 6      | 颜色信息仅包含透明度（Alpha），每个像素占8位。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。   |
| RGBA_F16<sup>9+</sup>  | 7      | 颜色信息由R（Red），G（Green），B（Blue）与透明度（Alpha）四部分组成，每个部分占16位，总共占64位。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。  |
| NV21<sup>9+</sup>      | 8      | YVU像素排列，V分量在U分量之前。颜色信息由亮度分量Y和交错排列的色度分量V和U组成，其中Y分量占8位，UV分量因4：2：0采样平均占4位，总共平均占12位。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。      |
| NV12<sup>9+</sup>      | 9      | YUV像素排列，U分量在V分量之前。颜色信息由亮度分量Y和交错排列的色度分量U和V组成，其中Y分量占8位，UV分量因4：2：0采样平均占4位，总共平均占12位。对应[相机服务CameraFormat中的CAMERA_FORMAT_YUV_420_SP](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。      |
| RGBA_1010102<sup>12+</sup> | 10 | 颜色信息由R（Red），G（Green），B（Blue）与透明度（Alpha）四部分组成，其中R、G、B分别占10位，透明度占2位，总共占32位。 |
| YCBCR_P010<sup>12+</sup> | 11 | 颜色信息由亮度分量Y和色度分量Cb与Cr组成，每个分量有效10位，实际存储时，Y平面每个像素占16位数据（10位有效），UV平面交错排列，每4个像素占32位数据（每色度分量10位有效），平均有效占15位。对应[相机服务CameraFormat中的CAMERA_FORMAT_YCBCR_P010](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat)。  |
| YCRCB_P010<sup>12+</sup> | 12 | 颜色信息由亮度分量Y和色度分量Cr与Cb组成，每个分量有效10位，实际存储时，Y平面每个像素占16位数据（10位有效），UV平面交错排列，每4个像素占32位数据（每色度分量10位有效），平均有效占15位。对应[相机服务CameraFormat中的CAMERA_FORMAT_YCRCB_P010](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat)。  |
| ASTC_4x4<sup>18+</sup> | 102 | 存储格式为ASTC 4x4格式，内存使用量仅为RGBA_8888的1/4。该格式仅用于直接显示场景，不支持像素访问或后期处理编辑，不支持仿射变换级联使用。  |

## AlphaType<sup>9+</sup>

枚举，图像的透明度类型。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称     |   值   | 说明                    |
| -------- | ------ | ----------------------- |
| UNKNOWN  | 0      | 未知透明度。            |
| OPAQUE   | 1      | 没有alpha或图片不透明。 |
| PREMUL   | 2      | RGB预乘alpha。         |
| UNPREMUL | 3      | RGB非预乘alpha。       |

## AuxiliaryPictureType<sup>13+</sup>

枚举，辅助图的图像类型。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值   | 说明         |
| ------------- | ---- | ------------ |
| GAINMAP       | 1    | 增益图，代表了一种增强SDR图像以产生具有可变显示调整能力的HDR图像的机制。它是一组描述如何应用gainmap元数据的组合。     |
| DEPTH_MAP     | 2    | 深度图，储存图像的深度数据，通过捕捉每个像素与摄像机之间的距离，提供场景的三维结构信息，通常用于3D重建和场景理解。     |
| UNREFOCUS_MAP | 3    | 人像未对焦的原图，提供了一种在人像拍摄中突出背景模糊效果的方式，能够帮助用户在后期处理中选择焦点区域，增加创作自由度。   |
| LINEAR_MAP    | 4    | 线性图，用于提供额外的数据视角或补充信息，通常用于视觉效果的增强，它可以包含场景中光照、颜色或其他视觉元素的线性表示。     |
| FRAGMENT_MAP  | 5    | 水印裁剪图，表示在原图中被水印覆盖的区域，该图像用于修复或移除水印影响，恢复图像的完整性和可视性。 |

## MetadataType<sup>13+</sup>

枚举，图片元数据类型。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 值   | 说明               |
| ----------------- | ---- | ------------------ |
| EXIF_METADATA     | 1    | exif数据。         |
| FRAGMENT_METADATA | 2    | 水印裁剪图元数据。 |
| GIF_METADATA<sup>20+</sup> | 5    | GIF图片元数据。 |

## ScaleMode<sup>9+</sup>

枚举，图像的缩放模式。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称            |   值   | 说明                                               |
| --------------- | ------ | -------------------------------------------------- |
| CENTER_CROP     | 1      | 缩放图像以填充目标图像区域并居中裁剪区域外的效果。 |
| FIT_TARGET_SIZE | 0      | 图像适合目标尺寸的效果。                           |

## PropertyKey<sup>7+</sup>

枚举，Exif（Exchangeable image file format）图片信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称               |   值                    |   说明                    |
| ----------------- | ----------------------- |---------------------------|
| NEW_SUBFILE_TYPE <sup>12+</sup>           | "NewSubfileType"            | **读写能力：** 可读写<br> 在Exif中，"NewSubfileType"字段用于标识子文件的数据类型，如全分辨率图像、缩略图或多帧图像的一部分。其值是位掩码，0代表全分辨率图像，1代表缩略图，2代表多帧图像的一部分。|
| SUBFILE_TYPE <sup>12+</sup>               | "SubfileType"               | **读写能力：** 可读写<br> 此标签指示此子文件中的数据类型。标签已弃用，请使用NewSubfileType替代。|
| IMAGE_WIDTH                               | "ImageWidth"                | **读写能力：** 可读写<br> 图片宽度。|
| IMAGE_LENGTH                              | "ImageLength"               | **读写能力：** 可读写<br> 图片长度。|
| BITS_PER_SAMPLE                           | "BitsPerSample"             | **读写能力：** 可读写<br> 像素各分量的位数，如RGB，3分量，格式是8, 8, 8。|
| COMPRESSION <sup>12+</sup>                | "Compression"               | **读写能力：** 可读写<br> 图像压缩方案。|
| PHOTOMETRIC_INTERPRETATION <sup>12+</sup> | "PhotometricInterpretation" | **读写能力：** 可读写<br> 像素构成，例如 RGB 或 YCbCr。|
| IMAGE_DESCRIPTION<sup>10+</sup>           | "ImageDescription"          | **读写能力：** 可读写<br> 图像信息描述。|
| MAKE<sup>10+</sup>                        | "Make"                      | **读写能力：** 可读写<br> 生产商。|
| MODEL<sup>10+</sup>                       | "Model"                     | **读写能力：** 可读写<br> 设备型号。|
| STRIP_OFFSETS <sup>12+</sup>              | "StripOffsets"              | **读写能力：** 可读写<br> 每个strip的字节偏移量。|
| ORIENTATION                               | "Orientation"               | **读写能力：** 可读写<br> 图片方向。<br/> 1："Top-left"，图像未旋转。<br/> 2："Top-right"，镜像水平翻转。<br/> 3："Bottom-right"，图像旋转180°。<br/> 4："Bottom-left"，镜像垂直翻转。<br/> 5："Left-top"，镜像水平翻转再顺时针旋转270°。<br/> 6："Right-top"，顺时针旋转90°。<br/> 7："Right-bottom"，镜像水平翻转再顺时针旋转90°。<br/> 8："Left-bottom"，顺时针旋转270°。<br/> 如果读到未定义值会返回"Unknown Value 0"。获取该属性时会以字符串的形式返回。修改该属性时既可以以数字形式指定，也可以以字符串形式指定。|
| SAMPLES_PER_PIXEL <sup>12+</sup>          | "SamplesPerPixel"           | **读写能力：** 可读写<br> 每个像素的分量数。由于该标准适用于 RGB 和 YCbCr 图像，因此该标签的值设置为 3。在 JPEG 压缩数据中，使用 JPEG 标记代替该标签。|
| ROWS_PER_STRIP <sup>12+</sup>             | "RowsPerStrip"              | **读写能力：** 可读写<br> 每个strip的图像数据行数。|
| STRIP_BYTE_COUNTS <sup>12+</sup>          | "StripByteCounts"           | **读写能力：** 可读写<br> 每个图像数据带的总字节数。|
| X_RESOLUTION <sup>12+</sup>               | "XResolution"               | **读写能力：** 可读写<br> 图像宽度方向的分辨率。|
| Y_RESOLUTION <sup>12+</sup>               | "YResolution"               | **读写能力：** 可读写<br> 图像高度方向的分辨率。|
| PLANAR_CONFIGURATION <sup>12+</sup>       | "PlanarConfiguration"       | **读写能力：** 可读写<br> 表示像素组件的记录格式，chunky格式或是planar格式。|
| RESOLUTION_UNIT <sup>12+</sup>            | "ResolutionUnit"            | **读写能力：** 可读写<br> 用于测量XResolution和YResolution的单位。|
| TRANSFER_FUNCTION <sup>12+</sup>          | "TransferFunction"          | **读写能力：** 可读写<br> 图像的传递函数，通常用于颜色校正。|
| SOFTWARE <sup>12+</sup>                   | "Software"                  | **读写能力：** 可读写<br> 用于生成图像的软件的名称和版本。|
| DATE_TIME<sup>10+</sup>                   | "DateTime"                  | **读写能力：** 可读写<br> 日期时间。格式如2024:01:25 05:51:34。|
| ARTIST <sup>12+</sup>                     | "Artist"                    | **读写能力：** 可读写<br> 创建图像的用户名称。|
| WHITE_POINT <sup>12+</sup>                | "WhitePoint"                | **读写能力：** 可读写<br> 图像的白点色度。|
| PRIMARY_CHROMATICITIES <sup>12+</sup>     | "PrimaryChromaticities"     | **读写能力：** 可读写<br> 图像的主要颜色的色度。|
| PHOTO_MODE<sup>10+</sup>                  | "PhotoMode"                 | **读写能力：** 可读写<br> 拍照模式。|
| JPEG_INTERCHANGE_FORMAT <sup>12+</sup>    | "JPEGInterchangeFormat"     | **读写能力：** 只读<br> JPEG压缩缩略图数据开始字节（SOI）的偏移。|
| JPEG_INTERCHANGE_FORMAT_LENGTH <sup>12+</sup> | "JPEGInterchangeFormatLength" | **读写能力：** 只读<br> JPEG压缩缩略图数据的字节数。|
| YCBCR_COEFFICIENTS <sup>12+</sup>         | "YCbCrCoefficients"         | **读写能力：** 可读写<br> 从RGB到YCbCr图像数据的转换矩阵系数。|
| YCBCR_SUB_SAMPLING <sup>12+</sup>         | "YCbCrSubSampling"          | **读写能力：** 可读写<br> 色度分量与亮度分量的采样比率。|
| YCBCR_POSITIONING <sup>12+</sup>          | "YCbCrPositioning"          | **读写能力：** 可读写<br> 色度分量相对于亮度分量的位置。|
| REFERENCE_BLACK_WHITE <sup>12+</sup>      | "ReferenceBlackWhite"       | **读写能力：** 可读写<br> 参考黑点值和参考白点值。|
| COPYRIGHT <sup>12+</sup>                  | "Copyright"                 | **读写能力：** 可读写<br> 图像的版权信息。|
| EXPOSURE_TIME<sup>9+</sup>                | "ExposureTime"              | **读写能力：** 可读写<br> 曝光时间，例如1/33 sec。|
| F_NUMBER<sup>9+</sup>                     | "FNumber"                   | **读写能力：** 可读写<br> 光圈值，例如f/1.8。|
| EXPOSURE_PROGRAM <sup>12+</sup>           | "ExposureProgram"           | **读写能力：** 可读写<br> 拍照时相机用来设置曝光的程序的类别。|
| SPECTRAL_SENSITIVITY <sup>12+</sup>       | "SpectralSensitivity"       | **读写能力：** 可读写<br> 表示所用相机的每个通道的光谱灵敏度。|
| GPS_VERSION_ID <sup>12+</sup>             | "GPSVersionID"              | **读写能力：** 可读写<br> GPSInfoIFD的版本。|
| GPS_LATITUDE_REF                          | "GPSLatitudeRef"            | **读写能力：** 可读写<br> 纬度引用，例如N或S。|
| GPS_LATITUDE                              | "GPSLatitude"               | **读写能力：** 可读写<br> 图片纬度。修改时应按"度,分,秒"格式传入，如"39,54,7.542"|
| GPS_LONGITUDE_REF                         | "GPSLongitudeRef"           | **读写能力：** 可读写<br> 经度引用，例如W或E。|
| GPS_LONGITUDE                             | "GPSLongitude"              | **读写能力：** 可读写<br> 图片经度。修改时应按"度,分,秒"格式传入，如"116,19,42.16"|
| GPS_ALTITUDE_REF <sup>12+</sup>           | "GPSAltitudeRef"            | **读写能力：** 可读写<br> 用于GPS高度的参照高度。|
| GPS_ALTITUDE <sup>12+</sup>               | "GPSAltitude"               | **读写能力：** 可读写<br> 基于GPSAltitudeRef的高度。|
| GPS_TIME_STAMP<sup>10+</sup>              | "GPSTimeStamp"              | **读写能力：** 可读写<br> GPS时间戳。|
| GPS_SATELLITES <sup>12+</sup>             | "GPSSatellites"             | **读写能力：** 可读写<br> 用于测量的GPS卫星。|
| GPS_STATUS <sup>12+</sup>                 | "GPSStatus"                 | **读写能力：** 可读写<br> 录制图像时GPS接收器的状态。|
| GPS_MEASURE_MODE <sup>12+</sup>           | "GPSMeasureMode"            | **读写能力：** 可读写<br> GPS测量模式。|
| GPS_DOP <sup>12+</sup>                    | "GPSDOP"                    | **读写能力：** 可读写<br> GPS DOP（数据精度等级）。|
| GPS_SPEED_REF <sup>12+</sup>              | "GPSSpeedRef"               | **读写能力：** 可读写<br> 用来表示GPS接收器移动速度的单位。|
| GPS_SPEED <sup>12+</sup>                  | "GPSSpeed"                  | **读写能力：** 可读写<br> GPS接收器的移动速度。|
| GPS_TRACK_REF <sup>12+</sup>              | "GPSTrackRef"               | **读写能力：** 可读写<br> GPS接收机移动方向的参照。|
| GPS_TRACK <sup>12+</sup>                  | "GPSTrack"                  | **读写能力：** 可读写<br> GPS接收机的移动方向。|
| GPS_IMG_DIRECTION_REF <sup>12+</sup>      | "GPSImgDirectionRef"        | **读写能力：** 可读写<br> 图像方向的参照。|
| GPS_IMG_DIRECTION <sup>12+</sup>          | "GPSImgDirection"           | **读写能力：** 可读写<br> 拍摄时图像的方向。|
| GPS_MAP_DATUM <sup>12+</sup>              | "GPSMapDatum"               | **读写能力：** 可读写<br> GPS接收器使用的大地测量数据。|
| GPS_DEST_LATITUDE_REF <sup>12+</sup>      | "GPSDestLatitudeRef"        | **读写能力：** 可读写<br> 目的地点的纬度参照。|
| GPS_DEST_LATITUDE <sup>12+</sup>          | "GPSDestLatitude"           | **读写能力：** 可读写<br> 目的地点的纬度。|
| GPS_DEST_LONGITUDE_REF <sup>12+</sup>     | "GPSDestLongitudeRef"       | **读写能力：** 可读写<br> 目的地点的经度参照。|
| GPS_DEST_LONGITUDE <sup>12+</sup>         | "GPSDestLongitude"          | **读写能力：** 可读写<br> 目的地点的经度。|
| GPS_DEST_BEARING_REF <sup>12+</sup>       | "GPSDestBearingRef"         | **读写能力：** 可读写<br> 指向目的地点的方位参照。|
| GPS_DEST_BEARING <sup>12+</sup>           | "GPSDestBearing"            | **读写能力：** 可读写<br> 目的地方位。|
| GPS_DEST_DISTANCE_REF <sup>12+</sup>      | "GPSDestDistanceRef"        | **读写能力：** 可读写<br> 目标点距离的测量单位。|
| GPS_DEST_DISTANCE <sup>12+</sup>          | "GPSDestDistance"           | **读写能力：** 可读写<br> 到目的地点的距离。|
| GPS_PROCESSING_METHOD <sup>12+</sup>      | "GPSProcessingMethod"       | **读写能力：** 可读写<br> 记录定位方法名的字符字符串。|
| GPS_AREA_INFORMATION <sup>12+</sup>       | "GPSAreaInformation"        | **读写能力：** 可读写<br> 记录GPS区域名的字符字符串。|
| GPS_DATE_STAMP<sup>10+</sup>              | "GPSDateStamp"              | **读写能力：** 可读写<br> GPS日期戳。|
| GPS_DIFFERENTIAL <sup>12+</sup>           | "GPSDifferential"           | **读写能力：** 可读写<br> 此字段表示GPS数据是否应用了差分校正，对于精确的位置准确性至关重要。|
| GPS_H_POSITIONING_ERROR <sup>12+</sup>    | "GPSHPositioningError"      | **读写能力：** 可读写<br> 此标签指示水平定位误差，单位为米。|
| ISO_SPEED_RATINGS<sup>9+</sup>            | "ISOSpeedRatings"           | **读写能力：** 可读写<br> ISO感光度，例如400。|
| PHOTOGRAPHIC_SENSITIVITY <sup>12+</sup>   | "PhotographicSensitivity"   | **读写能力：** 可读写<br> 此标签指示拍摄图像时相机或输入设备的灵敏度。|
| OECF <sup>12+</sup>                       | "OECF"                      | **读写能力：** 可读写<br> 表示ISO 14524中规定的光电转换函数（OECF）。|
| SENSITIVITY_TYPE<sup>10+</sup>            | "SensitivityType"           | **读写能力：** 可读写<br> 灵敏度类型。|
| STANDARD_OUTPUT_SENSITIVITY<sup>10+</sup> | "StandardOutputSensitivity" | **读写能力：** 可读写<br> 标准输出灵敏度。|
| RECOMMENDED_EXPOSURE_INDEX<sup>10+</sup>  | "RecommendedExposureIndex"  | **读写能力：** 可读写<br> 推荐曝光指数。|
| ISO_SPEED<sup>10+</sup>                   | "ISOSpeedRatings"           | **读写能力：** 可读写<br> ISO速度等级。|
| ISO_SPEED_LATITUDE_YYY <sup>12+</sup>     | "ISOSpeedLatitudeyyy"       | **读写能力：** 可读写<br> 该标签指示摄像机或输入设备的ISO速度纬度yyy值，该值在ISO 12232中定义。|
| ISO_SPEED_LATITUDE_ZZZ <sup>12+</sup>     | "ISOSpeedLatitudezzz"       | **读写能力：** 可读写<br> 该标签指示摄像机或输入设备的ISO速度纬度zzz值，该值在ISO 12232中定义。|
| EXIF_VERSION <sup>12+</sup>               | "ExifVersion"               | **读写能力：** 可读写<br> 支持的Exif标准版本。|
| DATE_TIME_ORIGINAL<sup>9+</sup>           | "DateTimeOriginal"          | **读写能力：** 可读写<br> 拍摄时间，例如2022:09:06 15:48:00。|
| DATE_TIME_DIGITIZED <sup>12+</sup>        | "DateTimeDigitized"         | **读写能力：** 可读写<br> 图像作为数字数据存储的日期和时间，格式为YYYY:MM:DD HH:MM:SS|
| OFFSET_TIME <sup>12+</sup>                | "OffsetTime"                | **读写能力：** 可读写<br> 在Exif中，OffsetTime字段表示与UTC（协调世界时）的时间偏移，格式为±HH:MM，用于确定照片拍摄的本地时间。|
| OFFSET_TIME_ORIGINAL <sup>12+</sup>       | "OffsetTimeOriginal"        | **读写能力：** 可读写<br> 此标签记录原始图像创建时的UTC偏移量，对于时间敏感的应用至关重要。|
| OFFSET_TIME_DIGITIZED <sup>12+</sup>      | "OffsetTimeDigitized"       | **读写能力：** 可读写<br> 此标签记录图像数字化时的UTC偏移量，有助于准确调整时间戳。|
| COMPONENTS_CONFIGURATION <sup>12+</sup>   | "ComponentsConfiguration"   | **读写能力：** 可读写<br> 压缩数据的特定信息。|
| COMPRESSED_BITS_PER_PIXEL <sup>12+</sup>  | "CompressedBitsPerPixel"    | **读写能力：** 可读写<br> 用于压缩图像的压缩模式，单位为每像素位数。|
| SHUTTER_SPEED <sup>12+</sup>              | "ShutterSpeedValue"         | **读写能力：** 可读写<br> 快门速度，以APEX（摄影曝光的加法系统）值表示。|
| APERTURE_VALUE<sup>10+</sup>              | "ApertureValue"             | **读写能力：** 可读写<br> 光圈值。格式如4/1。|
| BRIGHTNESS_VALUE <sup>12+</sup>           | "BrightnessValue"           | **读写能力：** 可读写<br> 图像的亮度值，以APEX单位表示。|
| EXPOSURE_BIAS_VALUE<sup>10+</sup>         | "ExposureBiasValue"         | **读写能力：** 可读写<br> 曝光偏差值。|
| MAX_APERTURE_VALUE <sup>12+</sup>         | "MaxApertureValue"          | **读写能力：** 可读写<br> 最小F数镜头。|
| SUBJECT_DISTANCE <sup>12+</sup>           | "SubjectDistance"           | **读写能力：** 可读写<br> 测量单位为米的主体距离。|
| METERING_MODE<sup>10+</sup>               | "MeteringMode"              | **读写能力：** 可读写<br> 测光模式。|
| LIGHT_SOURCE<sup>10+</sup>                | "LightSource"               | **读写能力：** 可读写<br> 光源。例如Fluorescent。|
| FLASH <sup>10+</sup>                      | "Flash"                     | **读写能力：** 可读写<br> 闪光灯,记录闪光灯状态。|
| FOCAL_LENGTH <sup>10+</sup>               | "FocalLength"               | **读写能力：** 可读写<br> 焦距。|
| SUBJECT_AREA <sup>12+</sup>               | "SubjectArea"               | **读写能力：** 可读写<br> 该标签指示整个场景中主要主体的位置和区域。|
| MAKER_NOTE <sup>12+</sup>                 | "MakerNote"                 | **读写能力：** 可读写<br> Exif/DCF制造商使用的标签，用于记录任何所需信息。<br>在API 12-19，该字段为只读；从API 20开始，该字段可读写。|
| SCENE_POINTER <sup>12+</sup>              | "HwMnoteScenePointer"       | **读写能力：** 只读<br> 场景指针。|
| SCENE_VERSION <sup>12+</sup>              | "HwMnoteSceneVersion"       | **读写能力：** 只读<br> 场景算法版本信息。|
| SCENE_FOOD_CONF<sup>11+</sup>             | "HwMnoteSceneFoodConf"      | **读写能力：** 只读<br> 拍照场景：食物。|
| SCENE_STAGE_CONF<sup>11+</sup>            | "HwMnoteSceneStageConf"     | **读写能力：** 只读<br> 拍照场景：舞台。|
| SCENE_BLUE_SKY_CONF<sup>11+</sup>         | "HwMnoteSceneBlueSkyConf"   | **读写能力：** 只读<br> 拍照场景：蓝天。|
| SCENE_GREEN_PLANT_CONF<sup>11+</sup>      | "HwMnoteSceneGreenPlantConf" | **读写能力：** 只读<br> 拍照场景：绿植。|
| SCENE_BEACH_CONF<sup>11+</sup>            | "HwMnoteSceneBeachConf"     | **读写能力：** 只读<br> 拍照场景：沙滩。|
| SCENE_SNOW_CONF<sup>11+</sup>             | "HwMnoteSceneSnowConf"      | **读写能力：** 只读<br> 拍照场景：下雪。|
| SCENE_SUNSET_CONF<sup>11+</sup>           | "HwMnoteSceneSunsetConf"    | **读写能力：** 只读<br> 拍照场景：日落。|
| SCENE_FLOWERS_CONF<sup>11+</sup>          | "HwMnoteSceneFlowersConf"   | **读写能力：** 只读<br> 拍照场景：花。|
| SCENE_NIGHT_CONF<sup>11+</sup>            | "HwMnoteSceneNightConf"     | **读写能力：** 只读<br> 拍照场景：夜晚。|
| SCENE_TEXT_CONF<sup>11+</sup>             | "HwMnoteSceneTextConf"      | **读写能力：** 只读<br> 拍照场景：文本。|
| FACE_POINTER <sup>12+</sup>               | "HwMnoteFacePointer"        | **读写能力：** 只读<br> 脸部指针。|
| FACE_VERSION <sup>12+</sup>               | "HwMnoteFaceVersion"        | **读写能力：** 只读<br> 人脸算法版本信息。|
| FACE_COUNT<sup>11+</sup>                  | "HwMnoteFaceCount"          | **读写能力：** 只读<br> 人脸数量。|
| FACE_CONF <sup>12+</sup>                  | "HwMnoteFaceConf"           | **读写能力：** 只读<br> 人脸置信度。|
| FACE_SMILE_SCORE <sup>12+</sup>           | "HwMnoteFaceSmileScore"     | **读写能力：** 只读<br> FaceCount张人脸的笑脸分数。|
| FACE_RECT <sup>12+</sup>                  | "HwMnoteFaceRect"           | **读写能力：** 只读<br> 脸部矩形。|
| FACE_LEYE_CENTER <sup>12+</sup>           | "HwMnoteFaceLeyeCenter"     | **读写能力：** 只读<br> 左眼中心。|
| FACE_REYE_CENTER <sup>12+</sup>           | "HwMnoteFaceReyeCenter"     | **读写能力：** 只读<br> 右眼中心。|
| FACE_MOUTH_CENTER <sup>12+</sup>          | "HwMnoteFaceMouthCenter"    | **读写能力：** 只读<br> 嘴中心。|
| CAPTURE_MODE <sup>10+</sup>               | "HwMnoteCaptureMode"        | **读写能力：** 可读写<br> 捕获模式。|
| BURST_NUMBER <sup>12+</sup>               | "HwMnoteBurstNumber"        | **读写能力：** 只读<br> 连拍次数。|
| FRONT_CAMERA <sup>12+</sup>               | "HwMnoteFrontCamera"        | **读写能力：** 只读<br> 是否是前置相机自拍。|
| ROLL_ANGLE <sup>11+</sup>                 | "HwMnoteRollAngle"          | **读写能力：** 只读<br> 滚动角度。|
| PITCH_ANGLE<sup>11+</sup>                 | "HwMnotePitchAngle"         | **读写能力：** 只读<br> 俯仰角度。|
| PHYSICAL_APERTURE <sup>10+</sup>          | "HwMnotePhysicalAperture"   | **读写能力：** 只读<br> 物理孔径，光圈大小。|
| FOCUS_MODE<sup>11+</sup>                  | "HwMnoteFocusMode"          | **读写能力：** 只读<br> 对焦模式。|
| USER_COMMENT <sup>10+</sup>               | "UserComment"               | **读写能力：** 可读写<br> 用户注释。|
| SUBSEC_TIME <sup>12+</sup>                | "SubsecTime"                | **读写能力：** 可读写<br> 用于为DateTime标签记录秒的分数的标签。|
| SUBSEC_TIME_ORIGINAL <sup>12+</sup>       | "SubsecTimeOriginal"        | **读写能力：** 可读写<br> 用于为DateTimeOriginal标签记录秒的分数的标签。|
| SUBSEC_TIME_DIGITIZED <sup>12+</sup>      | "SubsecTimeDigitized"       | **读写能力：** 可读写<br> 用于为DateTimeDigitized标签记录秒的分数的标签。|
| FLASHPIX_VERSION <sup>12+</sup>           | "FlashpixVersion"           | **读写能力：** 可读写<br> 该标签表示FPXR文件支持的Flashpix格式版本，增强了设备兼容性。|
| COLOR_SPACE <sup>12+</sup>                | "ColorSpace"                | **读写能力：** 可读写<br> 色彩空间信息标签，通常记录为色彩空间指定符。|
| PIXEL_X_DIMENSION <sup>10+</sup>          | "PixelXDimension"           | **读写能力：** 可读写<br> 像素X尺寸。|
| PIXEL_Y_DIMENSION<sup>10+</sup>           | "PixelYDimension"           | **读写能力：** 可读写<br> 像素Y尺寸。|
| RELATED_SOUND_FILE <sup>12+</sup>         | "RelatedSoundFile"          | **读写能力：** 可读写<br> 与图像数据相关的音频文件的名称。|
| FLASH_ENERGY <sup>12+</sup>               | "FlashEnergy"               | **读写能力：** 可读写<br> 图像捕获时的闪光能量，以BCPS表示。|
| SPATIAL_FREQUENCY_RESPONSE <sup>12+</sup> | "SpatialFrequencyResponse"  | **读写能力：** 可读写<br> 相机或输入设备的空间频率表。|
| FOCAL_PLANE_X_RESOLUTION <sup>12+</sup>   | "FocalPlaneXResolution"     | **读写能力：** 可读写<br> 图像宽度中每FocalPlaneResolutionUnit的像素。|
| FOCAL_PLANE_Y_RESOLUTION <sup>12+</sup>   | "FocalPlaneYResolution"     | **读写能力：** 可读写<br> 图像高度中每FocalPlaneResolutionUnit的像素。|
| FOCAL_PLANE_RESOLUTION_UNIT <sup>12+</sup> | "FocalPlaneResolutionUnit"  | **读写能力：** 可读写<br> 测量FocalPlaneXResolution和FocalPlaneYResolution的单位。|
| SUBJECT_LOCATION <sup>12+</sup>           | "SubjectLocation"           | **读写能力：** 可读写<br> 主要对象相对于左边缘的位置。|
| EXPOSURE_INDEX <sup>12+</sup>             | "ExposureIndex"             | **读写能力：** 可读写<br> 捕获时选定的曝光指数。|
| SENSING_METHOD <sup>12+</sup>             | "SensingMethod"             | **读写能力：** 可读写<br> 相机上的图像传感器类型。|
| FILE_SOURCE <sup>12+</sup>                | "FileSource"                | **读写能力：** 可读写<br> 表明图像来源。|
| SCENE_TYPE<sup>9+</sup>                   | "SceneType"                 | **读写能力：** 可读写<br> 拍摄场景模式，例如人像、风光、运动、夜景等。|
| CFA_PATTERN <sup>12+</sup>                | "CFAPattern"                | **读写能力：** 可读写<br> 图像传感器的色彩滤光片（CFA）几何图案。|
| CUSTOM_RENDERED <sup>12+</sup>            | "CustomRendered"            | **读写能力：** 可读写<br> 指示图像数据上的特殊处理。|
| EXPOSURE_MODE <sup>12+</sup>              | "ExposureMode"              | **读写能力：** 可读写<br> 拍摄时设置的曝光模式。|
| WHITE_BALANCE <sup>10+</sup>              | "WhiteBalance"              | **读写能力：** 可读写<br> 白平衡。|
| DIGITAL_ZOOM_RATIO <sup>12+</sup>         | "DigitalZoomRatio"          | **读写能力：** 可读写<br> 捕获时的数字变焦比率。|
| FOCAL_LENGTH_IN_35_MM_FILM <sup>10+</sup> | "FocalLengthIn35mmFilm"     | **读写能力：** 可读写<br> 焦距35毫米胶片。|
| SCENE_CAPTURE_TYPE <sup>12+</sup>         | "SceneCaptureType"          | **读写能力：** 可读写<br> 捕获的场景类型。|
| GAIN_CONTROL <sup>12+</sup>               | "GainControl"               | **读写能力：** 可读写<br> 整体图像增益调整的程度。|
| CONTRAST <sup>12+</sup>                   | "Contrast"                  | **读写能力：** 可读写<br> 相机应用的对比度处理方向。|
| SATURATION <sup>12+</sup>                 | "Saturation"                | **读写能力：** 可读写<br> 相机应用的饱和度处理方向。|
| SHARPNESS <sup>12+</sup>                  | "Sharpness"                 | **读写能力：** 可读写<br> 相机应用的锐度处理方向。|
| DEVICE_SETTING_DESCRIPTION <sup>12+</sup> | "DeviceSettingDescription"  | **读写能力：** 可读写<br> 特定相机模型的拍照条件信息。|
| SUBJECT_DISTANCE_RANGE <sup>12+</sup>     | "SubjectDistanceRange"      | **读写能力：** 可读写<br> 表示主体到相机的距离范围。|
| IMAGE_UNIQUE_ID <sup>12+</sup>            | "ImageUniqueID"             | **读写能力：** 可读写<br> 为每张图片唯一分配的标识符。|
| CAMERA_OWNER_NAME <sup>12+</sup>          | "CameraOwnerName"           | **读写能力：** 可读写<br> 相机所有者的姓名。|
| BODY_SERIAL_NUMBER <sup>12+</sup>         | "BodySerialNumber"          | **读写能力：** 可读写<br> 相机机身的序列号。|
| LENS_SPECIFICATION <sup>12+</sup>         | "LensSpecification"         | **读写能力：** 可读写<br> 使用的镜头规格。|
| LENS_MAKE <sup>12+</sup>                  | "LensMake"                  | **读写能力：** 可读写<br> 镜头的制造商。|
| LENS_MODEL <sup>12+</sup>                 | "LensModel"                 | **读写能力：** 可读写<br> 镜头的型号名称。|
| LENS_SERIAL_NUMBER <sup>12+</sup>         | "LensSerialNumber"          | **读写能力：** 可读写<br> 镜头的序列号。|
| COMPOSITE_IMAGE <sup>12+</sup>            | "CompositeImage"            | **读写能力：** 可读写<br> 表示图像是否为合成图像。|
| SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE <sup>12+</sup>   | "SourceImageNumberOfCompositeImage"       | **读写能力：** 可读写<br> 用于合成图像的源图像数量。|
| SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE <sup>12+</sup> | "SourceExposureTimesOfCompositeImage"     | **读写能力：** 可读写<br> 合成图像的源图像曝光时间。|
| GAMMA <sup>12+</sup>                      | "Gamma"                     | **读写能力：** 可读写<br> 表示系数伽马的值。|
| DNG_VERSION <sup>12+</sup>                | "DNGVersion"                | **读写能力：** 可读写<br> DNG版本标签编码了符合DNG规范的四级版本号。|
| DEFAULT_CROP_SIZE <sup>12+</sup>          | "DefaultCropSize"           | **读写能力：** 可读写<br> DefaultCropSize指定了原始坐标中的最终图像大小，考虑了额外的边缘像素。|
| GIF_LOOP_COUNT <sup>12+</sup>             | "GIFLoopCount"              | **读写能力：** 只读<br> GIF图片循环次数。0表示无限循环，其他值表示循环次数。|
| IS_XMAGE_SUPPORTED <sup>12+</sup> | "HwMnoteIsXmageSupported" | **读写能力：** 可读写<br>是否支持XMAGE。 |
| XMAGE_MODE <sup>12+</sup> | "HwMnoteXmageMode" | **读写能力：** 可读写<br>XMAGE水印模式。 |
| XMAGE_LEFT <sup>12+</sup> | "HwMnoteXmageLeft" | **读写能力：** 可读写<br>水印区域X1坐标。 |
| XMAGE_TOP <sup>12+</sup> | "HwMnoteXmageTop" | **读写能力：** 可读写<br>水印区域Y1坐标。 |
| XMAGE_RIGHT <sup>12+</sup> | "HwMnoteXmageRight" | **读写能力：** 可读写<br>水印区域X2坐标。 |
| XMAGE_BOTTOM <sup>12+</sup> | "HwMnoteXmageBottom" | **读写能力：** 可读写<br>水印区域Y2坐标。 |
| CLOUD_ENHANCEMENT_MODE <sup>12+</sup> | "HwMnoteCloudEnhancementMode" | **读写能力：** 可读写<br>云增强模式。 |
| WIND_SNAPSHOT_MODE <sup>12+</sup> | "HwMnoteWindSnapshotMode" | **读写能力：** 只读<br>运动快拍模式。 |

## FragmentMapPropertyKey<sup>13+</sup>

枚举，水印裁剪图图片信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值                    | 说明                                |
| ------------- | --------------------- | ----------------------------------- |
| X_IN_ORIGINAL | "XInOriginal"         | 水印裁剪图左上角在原始图中的X坐标。 |
| Y_IN_ORIGINAL | "YInOriginal"         | 水印裁剪图左上角在原始图中的Y坐标。 |
| WIDTH         | "FragmentImageWidth"  | 水印裁剪图的宽。                    |
| HEIGHT        | "FragmentImageHeight" | 水印裁剪图的高。                    |

## GifPropertyKey<sup>20+</sup>

枚举，GIF图片信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 值                | 说明                   |
| ----------------- | ----------------- | --------------------- |
| GIF_DELAY_TIME    | "GifDelayTime"    | GIF图片的每帧播放时长（单位为毫秒）。 |
| GIF_DISPOSAL_TYPE | "GifDisposalType" | GIF图片每帧的帧过渡模式。 |

## ImageFormat<sup>9+</sup>

枚举，图片格式。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称         |   值   | 说明                 |
| ------------ | ------ | -------------------- |
| YCBCR_422_SP | 1000   | YCBCR422半平面格式。 |
| JPEG         | 2000   | JPEG编码格式。       |

## ComponentType<sup>9+</sup>

枚举，图像的组件类型。

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
| AUTO          | 0    | 自适应，根据图片信息处理。即如果图片本身为HDR图片，则会按照HDR内容解码；反之按照SDR内容解码。通过[CreateIncrementalSource](arkts-apis-image-f.md#imagecreateincrementalsource9)创建的imagesource会解码为SDR内容。  |
| SDR           | 1    | 按照标准动态范围处理图片。   |
| HDR           | 2    | 按照高动态范围处理图片。通过[CreateIncrementalSource](arkts-apis-image-f.md#imagecreateincrementalsource9)创建的imagesource会解码为SDR内容。     |

## PackingDynamicRange<sup>12+</sup>

描述编码时期望的图像动态范围。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值       | 说明         |
| ------------- | ----------| ------------ |
| AUTO          | 0    | 自适应，根据[pixelmap](arkts-apis-image-PixelMap.md)内容处理。即如果pixelmap本身为HDR，则会按照HDR内容进行编码；反之按照SDR内容编码。  |
| SDR           | 1    | 按照标准动态范围处理图片。   |

## CropAndScaleStrategy<sup>18+</sup>

枚举，裁剪与缩放的先后策略。

如果在配置解码选项[DecodingOptions](arkts-apis-image-i.md#decodingoptions7)时，未填入参数cropAndScaleStrategy，并且同时设置了参数desiredRegion和desiredSize，由于系统对于不同图片格式采用的解码算法不同，最终解码效果将略有差异。

例如原始图片大小为200x200，传入desiredSize:{width: 150, height: 150}，desiredRegion:{x: 0, y: 0, width: 100, height: 100}，即预期解码原图左上角1/4区域，最终将pixelMap大小缩放至150x150返回。

对于jpeg、webp图片（部分dng图片解码时会优先解码图片中的jpeg预览图，在此场景下也会被视为jpeg图片格式）会先进行下采样，例如按照7/8下采样，再基于175x175的图片大小进行区域裁剪，因此最终的区域内容稍大于原图的左上角1/4区域。

对于svg图片，由于是矢量图，可以任意缩放不损失清晰度，在解码时会根据desiredSize与原图Size的比例选择缩放比例，在基于缩放后的图片大小进行区域裁剪，因此最终返回的解码区域会有所差异。

针对该场景，建议在解码选项同时设置了desiredRegion与desiredSize时，参数cropAndScaleStrategy应传入CROP_FIRST保证效果一致。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值       | 说明         |
| ------------- | ----------| ------------ |
| SCALE_FIRST   | 1    | 解码参数如果同时设置desiredRegion与desiredSize，先根据desiredSize进行缩放，再根据desiredRegion进行区域裁剪。     |
| CROP_FIRST    | 2    | 解码参数如果同时设置desiredRegion与desiredSize，先根据desiredRegion进行区域裁剪，再根据desiredSize进行缩放。     |

## HdrMetadataKey<sup>12+</sup>

枚举，[pixelmap](arkts-apis-image-PixelMap.md)使用的HDR相关元数据信息的关键字。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值       | 说明         |
| ------------- | ----------| ------------ |
| HDR_METADATA_TYPE    | 0    | [pixelmap](arkts-apis-image-PixelMap.md)使用的元数据类型。  |
| HDR_STATIC_METADATA  | 1    | 静态元数据。   |
| HDR_DYNAMIC_METADATA | 2    | 动态元数据。   |
| HDR_GAINMAP_METADATA | 3    | Gainmap使用的元数据。   |

## HdrMetadataType<sup>12+</sup>

枚举，[HdrMetadataKey](#hdrmetadatakey12)中HDR_METADATA_TYPE关键字对应的值。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 值       | 说明         |
| ------------- | ----------| ------------ |
| NONE     | 0    | 无元数据内容。  |
| BASE     | 1    | 表示用于基础图的元数据。   |
| GAINMAP  | 2    | 表示用于Gainmap图的元数据。   |
| ALTERNATE| 3    | 表示用于合成后HDR图的元数据。   |

## AntiAliasingLevel<sup>12+</sup>

缩放时的缩放算法。

**原子化服务API**：从API version 14 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                   |   值   | 说明              |
| ---------------------- | ------ | ----------------- |
| NONE                | 0      | 最近邻插值算法。   |
| LOW                 | 1      | 双线性插值算法。   |
| MEDIUM              | 2      | 双线性插值算法，同时开启Mipmap。缩小图片时建议使用。   |
| HIGH                | 3      | 三次插值算法。   |

## AllocatorType<sup>15+</sup>

枚举，用于图像解码的内存类型。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称         | 值   | 说明                               |
| ------------ | ---- | ---------------------------------- |
| AUTO         | 0    | 系统决定内存申请方式。     |
| DMA          | 1    | 使用DMA内存申请方式。            |
| SHARE_MEMORY | 2    | 使用SHARE_MEMORY的内存申请方式。 |
