# ImageProcessing_ColorSpaceInfo

## 概述

色彩空间信息，用于色彩空间转换能力查询。

**参考：**

[OH_ImageProcessing_IsColorSpaceConversionSupported](capi-image-processing-h.md#oh_imageprocessing_iscolorspaceconversionsupported), [OH_ImageProcessing_IsCompositionSupported](capi-image-processing-h.md#oh_imageprocessing_iscompositionsupported), [OH_ImageProcessing_IsDecompositionSupported](capi-image-processing-h.md#oh_imageprocessing_isdecompositionsupported)

**起始版本：** 13

**相关模块：** [ImageProcessing](capi-imageprocessing.md)

**所在头文件：** [image_processing_types.h](capi-image-processing-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t metadataType | 定义元数据类型，参考[OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey)。 |
| int32_t colorSpace | 定义色彩空间，参考[ColorSpaceName](../apis-arkgraphics2d/capi-native-color-space-manager-h.md#colorspacename)。 |
| int32_t pixelFormat | 定义像素格式，参考[PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format)。 |


