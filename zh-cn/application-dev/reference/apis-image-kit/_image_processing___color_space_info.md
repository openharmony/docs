# ImageProcessing_ColorSpaceInfo


## 概述

色彩空间信息，用于色彩空间转换能力查询。

可参考：

[OH_ImageProcessing_IsColorSpaceConversionSupported](_image_processing.md#oh_imageprocessing_iscolorspaceconversionsupported)

[OH_ImageProcessing_IsCompositionSupported](_image_processing.md#oh_imageprocessing_iscompositionsupported)

[OH_ImageProcessing_IsDecompositionSupported](_image_processing.md#oh_imageprocessing_isdecompositionsupported)

**起始版本：** 13

**相关模块：**[ImageProcessing](_image_processing.md)

**所在头文件：**[image_processing_types.h](image__processing__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [metadataType](#metadatatype) | 定义元数据类型[OH_Pixelmap_HdrMetadataKey](../apis-image-kit/_image___native_module.md#oh_pixelmap_hdrmetadatakey)。 | 
| int32_t [colorSpace](#colorspace) | 定义色彩空间[ColorSpaceName](../apis-arkgraphics2d/capi-native-color-space-manager-h.md#colorspacename)。 | 
| int32_t [pixelFormat](#pixelformat) | 定义像素格式[PIXEL_FORMAT](../apis-image-kit/_image___native_module.md#pixel_format)。 | 


## 结构体成员变量说明


### colorSpace

```
int32_t ImageProcessing_ColorSpaceInfo::colorSpace
```

**描述**

定义色彩空间[ColorSpaceName](../apis-arkgraphics2d/capi-native-color-space-manager-h.md#colorspacename)。


### metadataType

```
int32_t ImageProcessing_ColorSpaceInfo::metadataType
```

**描述**

定义元数据类型[OH_Pixelmap_HdrMetadataKey](../apis-image-kit/_image___native_module.md#oh_pixelmap_hdrmetadatakey)。


### pixelFormat

```
int32_t ImageProcessing_ColorSpaceInfo::pixelFormat
```

**描述**

定义像素格式[PIXEL_FORMAT](../apis-image-kit/_image___native_module.md#pixel_format)。
