# buffer_common.h

## 概述

提供NativeBuffer模块的公共类型定义。<br>从API version 12开始，部分类型定义从native_buffer.h移动至此头文件统一呈现，对于此类类型，API version 12之前即支持使用，各版本均可正常使用。

**引用文件：** <native_buffer/buffer_common.h>

**库：** libnative_buffer.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

**相关模块：** [OH_NativeBuffer](capi-oh-nativebuffer.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_NativeBuffer_ColorXY](capi-oh-nativebuffer-colorxy.md) | OH_NativeBuffer_ColorXY | 表示基色的X和Y坐标。 |
| [OH_NativeBuffer_Smpte2086](capi-oh-nativebuffer-smpte2086.md) | OH_NativeBuffer_Smpte2086 | 表示smpte2086静态元数据。 |
| [OH_NativeBuffer_Cta861](capi-oh-nativebuffer-cta861.md) | OH_NativeBuffer_Cta861 | 表示CTA-861.3静态元数据。 |
| [OH_NativeBuffer_StaticMetadata](capi-oh-nativebuffer-staticmetadata.md) | OH_NativeBuffer_StaticMetadata | 表示HDR静态元数据。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace) | OH_NativeBuffer_ColorSpace | OH_NativeBuffer的颜色空间。由native_buffer.h移动至此头文件统一呈现。 |
| [OH_NativeBuffer_MetadataType](#oh_nativebuffer_metadatatype) | OH_NativeBuffer_MetadataType | OH_NativeBuffer的图像标准。 |
| [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey) | OH_NativeBuffer_MetadataKey | 表示OH_NativeBuffer的HDR元数据种类的键值。 |

## 枚举类型说明

### OH_NativeBuffer_ColorSpace

```
enum OH_NativeBuffer_ColorSpace
```

**描述**

OH_NativeBuffer的颜色空间。由native_buffer.h移动至此头文件统一呈现。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| OH_COLORSPACE_NONE | 无颜色空间。 |
| OH_COLORSPACE_BT601_EBU_FULL | 色域范围为BT601_P，传递函数为BT709，转换矩阵为BT601_P，数据范围为RANGE_FULL。 |
| OH_COLORSPACE_BT601_SMPTE_C_FULL | 色域范围为BT601_N，传递函数为BT709，转换矩阵为BT601_N，数据范围为RANGE_FULL。 |
| OH_COLORSPACE_BT709_FULL | 色域范围为BT709，传递函数为BT709，转换矩阵为BT709，数据范围为RANGE_FULL。 |
| OH_COLORSPACE_BT2020_HLG_FULL | 色域范围为BT2020，传递函数为HLG，转换矩阵为BT2020，数据范围为RANGE_FULL。 |
| OH_COLORSPACE_BT2020_PQ_FULL | 色域范围为BT2020，传递函数为PQ，转换矩阵为BT2020，数据范围为RANGE_FULL。 |
| OH_COLORSPACE_BT601_EBU_LIMIT | 色域范围为BT601_P，传递函数为BT709，转换矩阵为BT601_P，数据范围为RANGE_LIMITED。 |
| OH_COLORSPACE_BT601_SMPTE_C_LIMIT | 色域范围为BT601_N，传递函数为BT709，转换矩阵为BT601_N，数据范围为RANGE_LIMITED。 |
| OH_COLORSPACE_BT709_LIMIT | 色域范围为BT709，传递函数为BT709，转换矩阵为BT709，数据范围为RANGE_LIMITED。 |
| OH_COLORSPACE_BT2020_HLG_LIMIT | 色域范围为BT2020，传递函数为HLG，转换矩阵为BT2020，数据范围为RANGE_LIMITED。 |
| OH_COLORSPACE_BT2020_PQ_LIMIT | 色域范围为BT2020，传递函数为PQ，转换矩阵为BT2020，数据范围为RANGE_LIMITED。 |
| OH_COLORSPACE_SRGB_FULL | 色域范围为SRGB，传递函数为SRGB，转换矩阵为BT601_N，数据范围为RANGE_FULL。 |
| OH_COLORSPACE_P3_FULL | 色域范围为P3_D65，传递函数为SRGB，转换矩阵为P3，数据范围为RANGE_FULL。 |
| OH_COLORSPACE_P3_HLG_FULL | 色域范围为P3_D65，传递函数为HLG，转换矩阵为P3，数据范围为RANGE_FULL。 |
| OH_COLORSPACE_P3_PQ_FULL | 色域范围为P3_D65，传递函数为PQ，转换矩阵为P3，数据范围为RANGE_FULL。 |
| OH_COLORSPACE_ADOBERGB_FULL | 色域范围为ADOBERGB，传递函数为ADOBERGB，转换矩阵为ADOBERGB，数据范围为RANGE_FULL。 |
| OH_COLORSPACE_SRGB_LIMIT | 色域范围为SRGB，传递函数为SRGB，转换矩阵为BT601_N，数据范围为RANGE_LIMITED。 |
| OH_COLORSPACE_P3_LIMIT | 色域范围为P3_D65，传递函数为SRGB，转换矩阵为P3，数据范围为RANGE_LIMITED。 |
| OH_COLORSPACE_P3_HLG_LIMIT | 色域范围为P3_D65，传递函数为HLG，转换矩阵为P3，数据范围为RANGE_LIMITED。 |
| OH_COLORSPACE_P3_PQ_LIMIT | 色域范围为P3_D65，传递函数为PQ，转换矩阵为P3，数据范围为RANGE_LIMITED。 |
| OH_COLORSPACE_ADOBERGB_LIMIT | 色域范围为ADOBERGB，传递函数为ADOBERGB，转换矩阵为ADOBERGB，数据范围为RANGE_LIMITED。 |
| OH_COLORSPACE_LINEAR_SRGB | 色域范围为SRGB，传递函数为LINEAR。 |
| OH_COLORSPACE_LINEAR_BT709 | 等同于 OH_COLORSPACE_LINEAR_SRGB。 |
| OH_COLORSPACE_LINEAR_P3 | 色域范围为P3_D65，传递函数为LINEAR。 |
| OH_COLORSPACE_LINEAR_BT2020 | 色域范围为BT2020，传递函数为LINEAR。 |
| OH_COLORSPACE_DISPLAY_SRGB | 等同于OH_COLORSPACE_SRGB_FULL。 |
| OH_COLORSPACE_DISPLAY_P3_SRGB | 等同于OH_COLORSPACE_P3_FULL。 |
| OH_COLORSPACE_DISPLAY_P3_HLG | 等同于OH_COLORSPACE_P3_HLG_FULL。 |
| OH_COLORSPACE_DISPLAY_P3_PQ | 等同于OH_COLORSPACE_P3_PQ_FULL。 |
| OH_COLORSPACE_DISPLAY_BT2020_SRGB | 色域范围为BT2020，传递函数为SRGB，转换矩阵为BT2020，数据范围为RANGE_FULL。 |
| OH_COLORSPACE_DISPLAY_BT2020_HLG | 等同于 OH_COLORSPACE_BT2020_HLG_FULL。 |
| OH_COLORSPACE_DISPLAY_BT2020_PQ | 等同于OH_COLORSPACE_BT2020_PQ_FULL。 |

### OH_NativeBuffer_MetadataType

```
enum OH_NativeBuffer_MetadataType
```

**描述**

OH_NativeBuffer的图像标准。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OH_VIDEO_HDR_HLG | 视频HLG。 |
| OH_VIDEO_HDR_HDR10 | 视频HDR10。 |
| OH_VIDEO_HDR_VIVID | 视频HDR VIVID。 |
| OH_VIDEO_NONE = -1 |  无元数据。<br/>**起始版本：** 13 |

### OH_NativeBuffer_MetadataKey

```
enum OH_NativeBuffer_MetadataKey
```

**描述**

表示OH_NativeBuffer的HDR元数据种类的键值。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OH_HDR_METADATA_TYPE | 元数据类型，其值见[OH_NativeBuffer_MetadataType](capi-buffer-common-h.md#oh_nativebuffer_metadatatype)，size为OH_NativeBuffer_MetadataType大小。 |
| OH_HDR_STATIC_METADATA | 静态元数据，其值见[OH_NativeBuffer_StaticMetadata](capi-oh-nativebuffer-staticmetadata.md)，size为OH_NativeBuffer_StaticMetadata大小。 |
| OH_HDR_DYNAMIC_METADATA | 动态元数据，其值见视频流中SEI的字节流，size的取值范围为1-3000。 |


