# buffer_common.h


## 概述

提供NativeBuffer模块的公共类型定义。

部分类型定义从native_buffer.h移动至此头文件统一呈现，对于此类类型，API version 12版本之前即支持使用，各版本均可正常使用。

**库：** libnative_buffer.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

**相关模块：**[OH_NativeBuffer](_o_h___native_buffer.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| struct  [OH_NativeBuffer_ColorXY](_o_h___native_buffer___color_x_y.md) | 表示基色的X和Y坐标。  |
| struct  [OH_NativeBuffer_Smpte2086](_o_h___native_buffer___smpte2086.md) | 表示smpte2086静态元数据。  |
| struct  [OH_NativeBuffer_Cta861](_o_h___native_buffer___cta861.md) | 表示CTA-861.3静态元数据。  |
| struct  [OH_NativeBuffer_StaticMetadata](_o_h___native_buffer___static_metadata.md) | 表示HDR静态元数据。  |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace)  [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace) | OH_NativeBuffer的颜色空间。由native_buffer.h移动至此头文件统一呈现。  |
| typedef enum [OH_NativeBuffer_MetadataType](_o_h___native_buffer.md#oh_nativebuffer_metadatatype)  [OH_NativeBuffer_MetadataType](_o_h___native_buffer.md#oh_nativebuffer_metadatatype) | OH_NativeBuffer的图像标准。  |
| typedef struct [OH_NativeBuffer_ColorXY](_o_h___native_buffer___color_x_y.md)  [OH_NativeBuffer_ColorXY](_o_h___native_buffer.md#oh_nativebuffer_colorxy) | 表示基色的X和Y坐标。  |
| typedef struct [OH_NativeBuffer_Smpte2086](_o_h___native_buffer___smpte2086.md)  [OH_NativeBuffer_Smpte2086](_o_h___native_buffer.md#oh_nativebuffer_smpte2086) | 表示smpte2086静态元数据。  |
| typedef struct [OH_NativeBuffer_Cta861](_o_h___native_buffer___cta861.md)  [OH_NativeBuffer_Cta861](_o_h___native_buffer.md#oh_nativebuffer_cta861) | 表示CTA-861.3静态元数据。  |
| typedef struct [OH_NativeBuffer_StaticMetadata](_o_h___native_buffer___static_metadata.md)  [OH_NativeBuffer_StaticMetadata](_o_h___native_buffer.md#oh_nativebuffer_staticmetadata) | 表示HDR静态元数据。  |
| typedef enum [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey)  [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey) | 表示OH_NativeBuffer的HDR元数据种类的键值。  |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace-1) {<br/>OH_COLORSPACE_NONE, OH_COLORSPACE_BT601_EBU_FULL, OH_COLORSPACE_BT601_SMPTE_C_FULL, OH_COLORSPACE_BT709_FULL,<br/>OH_COLORSPACE_BT2020_HLG_FULL, OH_COLORSPACE_BT2020_PQ_FULL, OH_COLORSPACE_BT601_EBU_LIMIT, OH_COLORSPACE_BT601_SMPTE_C_LIMIT,<br/>OH_COLORSPACE_BT709_LIMIT, OH_COLORSPACE_BT2020_HLG_LIMIT, OH_COLORSPACE_BT2020_PQ_LIMIT, OH_COLORSPACE_SRGB_FULL,<br/>OH_COLORSPACE_P3_FULL, OH_COLORSPACE_P3_HLG_FULL, OH_COLORSPACE_P3_PQ_FULL, OH_COLORSPACE_ADOBERGB_FULL,<br/>OH_COLORSPACE_SRGB_LIMIT, OH_COLORSPACE_P3_LIMIT, OH_COLORSPACE_P3_HLG_LIMIT, OH_COLORSPACE_P3_PQ_LIMIT,<br/>OH_COLORSPACE_ADOBERGB_LIMIT, OH_COLORSPACE_LINEAR_SRGB, OH_COLORSPACE_LINEAR_BT709, OH_COLORSPACE_LINEAR_P3,<br/>OH_COLORSPACE_LINEAR_BT2020, OH_COLORSPACE_DISPLAY_SRGB, OH_COLORSPACE_DISPLAY_P3_SRGB, OH_COLORSPACE_DISPLAY_P3_HLG,<br/>OH_COLORSPACE_DISPLAY_P3_PQ, OH_COLORSPACE_DISPLAY_BT2020_SRGB, OH_COLORSPACE_DISPLAY_BT2020_HLG, OH_COLORSPACE_DISPLAY_BT2020_PQ<br/>} | OH_NativeBuffer的颜色空间。由native_buffer.h移动至此头文件统一呈现。  |
| [OH_NativeBuffer_MetadataType](_o_h___native_buffer.md#oh_nativebuffer_metadatatype-1) { OH_VIDEO_HDR_HLG, OH_VIDEO_HDR_HDR10, OH_VIDEO_HDR_VIVID, OH_VIDEO_NONE = -1 } | OH_NativeBuffer的图像标准。  |
| [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey-1) { OH_HDR_METADATA_TYPE, OH_HDR_STATIC_METADATA, OH_HDR_DYNAMIC_METADATA } | 表示OH_NativeBuffer的HDR元数据种类的键值。  |
