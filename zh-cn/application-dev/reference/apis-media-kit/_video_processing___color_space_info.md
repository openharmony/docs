# VideoProcessing_ColorSpaceInfo


## 概述

视频颜色空间信息数据结构。

**参见：**[OH_VideoProcessing_IsColorSpaceConversionSupported](_video_processing.md#oh_videoprocessing_iscolorspaceconversionsupported)

**起始版本：** 12

**相关模块：**[VideoProcessing](_video_processing.md)

**所在头文件：**[video_processing_types.h](video__processing__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [metadataType](#metadatatype) | 视频元数据类型，参阅[OH_NativeBuffer_MetadataType](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_metadatatype)。 | 
| int32_t [colorSpace](#colorspace) | 视频颜色空间类型，参阅[OH_NativeBuffer_ColorSpace](..apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace)。 | 
| int32_t [pixelFormat](#pixelformat) | 视频像素格式，参阅[OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_format-1)。 | 


## 结构体成员变量说明


### colorSpace

```
int32_t VideoProcessing_ColorSpaceInfo::colorSpace
```

**描述**

视频颜色空间类型，参阅[OH_NativeBuffer_ColorSpace](..apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace)。


### metadataType

```
int32_t VideoProcessing_ColorSpaceInfo::metadataType
```

**描述**

视频元数据类型，参阅[OH_NativeBuffer_MetadataType](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_metadatatype)。


### pixelFormat

```
int32_t VideoProcessing_ColorSpaceInfo::pixelFormat
```

**描述**

视频像素格式，参阅[OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_format-1)。
