# VideoProcessing_ColorSpaceInfo
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 概述

视频颜色空间信息数据结构。

**参考：** [OH_VideoProcessing_IsColorSpaceConversionSupported](capi-video-processing-h.md#oh_videoprocessing_iscolorspaceconversionsupported)

**起始版本：** 12

**相关模块：** [VideoProcessing](capi-videoprocessing.md)

**所在头文件：** [video_processing_types.h](capi-video-processing-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t metadataType | 视频元数据类型，参考[OH_NativeBuffer_MetadataType](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_metadatatype)。 |
| int32_t colorSpace | 视频颜色空间类型，参考[OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace)。 |
| int32_t pixelFormat | 视频像素格式，参考[OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_format)。 |


