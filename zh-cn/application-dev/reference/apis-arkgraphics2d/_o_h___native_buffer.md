# OH_NativeBuffer

## 概述

提供NativeBuffer功能，通过提供的接口，可以实现共享内存的申请、使用、属性查询、释放等操作。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_buffer.h](native__buffer_8h.md) | 定义获取和使用NativeBuffer的相关函数。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) | OH_NativeBuffer的属性配置，用于申请新的OH_NativeBuffer实例或查询现有实例的相关属性 | 
| struct  [OH_NativeBuffer_Plane](_o_h___native_buffer___plane.md) | 单个图像平面格式信息。 | 
| struct  [OH_NativeBuffer_Planes](_o_h___native_buffer___planes.md) | OH_NativeBuffer的图像平面格式信息。 | 
| struct  [OH_NativeBuffer_ColorXY](_o_h___native_buffer___color_x_y.md) | 表示基色的X和Y坐标。 | 
| struct  [OH_NativeBuffer_Smpte2086](_o_h___native_buffer___smpte2086.md) | 表示smpte2086静态元数据。 | 
| struct  [OH_NativeBuffer_Cta861](_o_h___native_buffer___cta861.md) | 表示CTA-861.3静态元数据。 | 
| struct  [OH_NativeBuffer_StaticMetadata](_o_h___native_buffer___static_metadata.md) | 表示HDR静态元数据。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_NativeBuffer](#oh_nativebuffer)  [OH_NativeBuffer](#oh_nativebuffer) | 提供OH_NativeBuffer结构体声明 | 
| typedef enum [OH_NativeBuffer_Usage](#oh_nativebuffer_usage)  [OH_NativeBuffer_Usage](#oh_nativebuffer_usage) | OH_NativeBuffer的用途。 | 
| typedef enum [OH_NativeBuffer_Format](#oh_nativebuffer_format)  [OH_NativeBuffer_Format](#oh_nativebuffer_format) | OH_NativeBuffer的格式。 | 
| typedef enum [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace)  [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace) | OH_NativeBuffer的颜色空间 | 
| typedef enum [OH_NativeBuffer_TransformType](#oh_nativebuffer_transformtype)  [OH_NativeBuffer_TransformType](#oh_nativebuffer_transformtype) | OH_NativeBuffer的转换类型。 | 
| typedef enum [OH_NativeBuffer_ColorGamut](#oh_nativebuffer_colorgamut)  [OH_NativeBuffer_ColorGamut](#oh_nativebuffer_colorgamut) | OH_NativeBuffer的色域。 | 
| typedef enum [OHNativeErrorCode](_native_window.md#ohnativeerrorcode)  [OHNativeErrorCode](#ohnativeerrorcode) | 接口错误码说明（仅用于查询）。 | 
| typedef struct [OH_NativeBuffer_Config](_o_h___native_buffer___config.md)  [OH_NativeBuffer_Config](#oh_nativebuffer_config) | OH_NativeBuffer的属性配置，用于申请新的OH_NativeBuffer实例或查询现有实例的相关属性 | 
| typedef struct [OH_NativeBuffer_Plane](_o_h___native_buffer___plane.md)  [OH_NativeBuffer_Plane](#oh_nativebuffer_plane) | 单个图像平面格式信息。 | 
| typedef struct [OH_NativeBuffer_Planes](_o_h___native_buffer___planes.md)  [OH_NativeBuffer_Planes](#oh_nativebuffer_planes) | OH_NativeBuffer的图像平面格式信息。 | 
| typedef enum [OH_NativeBuffer_MetadataType](#oh_nativebuffer_metadatatype)  [OH_NativeBuffer_MetadataType](#oh_nativebuffer_metadatatype) | OH_NativeBuffer的图像标准。 | 
| typedef struct [OH_NativeBuffer_ColorXY](_o_h___native_buffer___color_x_y.md)  [OH_NativeBuffer_ColorXY](#oh_nativebuffer_colorxy) | 表示基色的X和Y坐标。 | 
| typedef struct [OH_NativeBuffer_Smpte2086](_o_h___native_buffer___smpte2086.md)  [OH_NativeBuffer_Smpte2086](#oh_nativebuffer_smpte2086) | 表示smpte2086静态元数据。 | 
| typedef struct [OH_NativeBuffer_Cta861](_o_h___native_buffer___cta861.md)  [OH_NativeBuffer_Cta861](#oh_nativebuffer_cta861) | 表示CTA-861.3静态元数据。 | 
| typedef struct [OH_NativeBuffer_StaticMetadata](_o_h___native_buffer___static_metadata.md)  [OH_NativeBuffer_StaticMetadata](#oh_nativebuffer_staticmetadata) | 表示HDR静态元数据。 | 
| typedef enum [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey)  [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey) | 表示OH_NativeBuffer的HDR元数据种类的键值。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NativeBuffer_Usage](#oh_nativebuffer_usage-1) {<br/>NATIVEBUFFER_USAGE_CPU_READ = (1ULL &lt;&lt; 0), NATIVEBUFFER_USAGE_CPU_WRITE = (1ULL &lt;&lt; 1), NATIVEBUFFER_USAGE_MEM_DMA = (1ULL &lt;&lt; 3), NATIVEBUFFER_USAGE_HW_RENDER = (1ULL &lt;&lt; 8),<br/>NATIVEBUFFER_USAGE_HW_TEXTURE = (1ULL &lt;&lt; 9), NATIVEBUFFER_USAGE_CPU_READ_OFTEN = (1ULL &lt;&lt; 16), NATIVEBUFFER_USAGE_ALIGNMENT_512 = (1ULL &lt;&lt; 18)<br/>} | OH_NativeBuffer的用途。 | 
| [OH_NativeBuffer_Format](#oh_nativebuffer_format-1) {<br/>NATIVEBUFFER_PIXEL_FMT_CLUT8 = 0, NATIVEBUFFER_PIXEL_FMT_CLUT1, NATIVEBUFFER_PIXEL_FMT_CLUT4, NATIVEBUFFER_PIXEL_FMT_RGB_565 = 3,<br/>NATIVEBUFFER_PIXEL_FMT_RGBA_5658, NATIVEBUFFER_PIXEL_FMT_RGBX_4444, NATIVEBUFFER_PIXEL_FMT_RGBA_4444, NATIVEBUFFER_PIXEL_FMT_RGB_444,<br/>NATIVEBUFFER_PIXEL_FMT_RGBX_5551, NATIVEBUFFER_PIXEL_FMT_RGBA_5551, NATIVEBUFFER_PIXEL_FMT_RGB_555, NATIVEBUFFER_PIXEL_FMT_RGBX_8888,<br/>NATIVEBUFFER_PIXEL_FMT_RGBA_8888, NATIVEBUFFER_PIXEL_FMT_RGB_888, NATIVEBUFFER_PIXEL_FMT_BGR_565, NATIVEBUFFER_PIXEL_FMT_BGRX_4444,<br/>NATIVEBUFFER_PIXEL_FMT_BGRA_4444, NATIVEBUFFER_PIXEL_FMT_BGRX_5551, NATIVEBUFFER_PIXEL_FMT_BGRA_5551, NATIVEBUFFER_PIXEL_FMT_BGRX_8888,<br/>NATIVEBUFFER_PIXEL_FMT_BGRA_8888, NATIVEBUFFER_PIXEL_FMT_YUV_422_I, NATIVEBUFFER_PIXEL_FMT_YCBCR_422_SP, NATIVEBUFFER_PIXEL_FMT_YCRCB_422_SP,<br/>NATIVEBUFFER_PIXEL_FMT_YCBCR_420_SP, NATIVEBUFFER_PIXEL_FMT_YCRCB_420_SP, NATIVEBUFFER_PIXEL_FMT_YCBCR_422_P, NATIVEBUFFER_PIXEL_FMT_YCRCB_422_P,<br/>NATIVEBUFFER_PIXEL_FMT_YCBCR_420_P, NATIVEBUFFER_PIXEL_FMT_YCRCB_420_P, NATIVEBUFFER_PIXEL_FMT_YUYV_422_PKG, NATIVEBUFFER_PIXEL_FMT_UYVY_422_PKG,<br/>NATIVEBUFFER_PIXEL_FMT_YVYU_422_PKG, NATIVEBUFFER_PIXEL_FMT_VYUY_422_PKG, NATIVEBUFFER_PIXEL_FMT_RGBA_1010102, NATIVEBUFFER_PIXEL_FMT_YCBCR_P010,<br/>NATIVEBUFFER_PIXEL_FMT_YCRCB_P010, NATIVEBUFFER_PIXEL_FMT_RAW10, NATIVEBUFFER_PIXEL_FMT_VENDER_MASK = 0X7FFF0000, NATIVEBUFFER_PIXEL_FMT_BUTT = 0X7FFFFFFF<br/>} | OH_NativeBuffer的格式。 | 
| [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace-1) {<br/>OH_COLORSPACE_NONE, OH_COLORSPACE_BT601_EBU_FULL, OH_COLORSPACE_BT601_SMPTE_C_FULL, OH_COLORSPACE_BT709_FULL,<br/>OH_COLORSPACE_BT2020_HLG_FULL, OH_COLORSPACE_BT2020_PQ_FULL, OH_COLORSPACE_BT601_EBU_LIMIT, OH_COLORSPACE_BT601_SMPTE_C_LIMIT,<br/>OH_COLORSPACE_BT709_LIMIT, OH_COLORSPACE_BT2020_HLG_LIMIT, OH_COLORSPACE_BT2020_PQ_LIMIT, OH_COLORSPACE_SRGB_FULL,<br/>OH_COLORSPACE_P3_FULL, OH_COLORSPACE_P3_HLG_FULL, OH_COLORSPACE_P3_PQ_FULL, OH_COLORSPACE_ADOBERGB_FULL,<br/>OH_COLORSPACE_SRGB_LIMIT, OH_COLORSPACE_P3_LIMIT, OH_COLORSPACE_P3_HLG_LIMIT, OH_COLORSPACE_P3_PQ_LIMIT,<br/>OH_COLORSPACE_ADOBERGB_LIMIT, OH_COLORSPACE_LINEAR_SRGB, OH_COLORSPACE_LINEAR_BT709, OH_COLORSPACE_LINEAR_P3,<br/>OH_COLORSPACE_LINEAR_BT2020, OH_COLORSPACE_DISPLAY_SRGB, OH_COLORSPACE_DISPLAY_P3_SRGB, OH_COLORSPACE_DISPLAY_P3_HLG,<br/>OH_COLORSPACE_DISPLAY_P3_PQ, OH_COLORSPACE_DISPLAY_BT2020_SRGB, OH_COLORSPACE_DISPLAY_BT2020_HLG, OH_COLORSPACE_DISPLAY_BT2020_PQ<br/>} | OH_NativeBuffer的颜色空间 | 
| [OH_NativeBuffer_TransformType](#oh_nativebuffer_transformtype-1) {<br/>NATIVEBUFFER_ROTATE_NONE = 0, NATIVEBUFFER_ROTATE_90, NATIVEBUFFER_ROTATE_180, NATIVEBUFFER_ROTATE_270,<br/>NATIVEBUFFER_FLIP_H, NATIVEBUFFER_FLIP_V, NATIVEBUFFER_FLIP_H_ROT90, NATIVEBUFFER_FLIP_V_ROT90,<br/>NATIVEBUFFER_FLIP_H_ROT180, NATIVEBUFFER_FLIP_V_ROT180, NATIVEBUFFER_FLIP_H_ROT270, NATIVEBUFFER_FLIP_V_ROT270<br/>} | OH_NativeBuffer的转换类型。 | 
| [OH_NativeBuffer_ColorGamut](#oh_nativebuffer_colorgamut-1) {<br/>NATIVEBUFFER_COLOR_GAMUT_NATIVE = 0, NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT601 = 1, NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT709 = 2, NATIVEBUFFER_COLOR_GAMUT_DCI_P3 = 3,<br/>NATIVEBUFFER_COLOR_GAMUT_SRGB = 4, NATIVEBUFFER_COLOR_GAMUT_ADOBE_RGB = 5, NATIVEBUFFER_COLOR_GAMUT_DISPLAY_P3 = 6, NATIVEBUFFER_COLOR_GAMUT_BT2020 = 7,<br/>NATIVEBUFFER_COLOR_GAMUT_BT2100_PQ = 8, NATIVEBUFFER_COLOR_GAMUT_BT2100_HLG = 9, NATIVEBUFFER_COLOR_GAMUT_DISPLAY_BT2020 = 10<br/>} | OH_NativeBuffer的色域。 | 
| [OHNativeErrorCode](#ohnativeerrorcode-1) {<br/>NATIVE_ERROR_OK = 0, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br/>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br/>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000,NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000, NATIVE_ERROR_UNSUPPORTED = 50102000,<br/>NATIVE_ERROR_UNKNOWN = 50002000,NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000, NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br/>} | 接口错误码说明（仅用于查询）。  | 
| [OH_NativeBuffer_MetadataType](#oh_nativebuffer_metadatatype-1) { OH_VIDEO_HDR_HLG, OH_VIDEO_HDR_HDR10, OH_VIDEO_HDR_VIVID } | OH_NativeBuffer的图像标准。 | 
| [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey-1) { OH_HDR_METADATA_TYPE, OH_HDR_STATIC_METADATA, OH_HDR_DYNAMIC_METADATA } | 表示OH_NativeBuffer的HDR元数据种类的键值。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NativeBuffer](#oh_nativebuffer) \* [OH_NativeBuffer_Alloc](#oh_nativebuffer_alloc) (const [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | 通过OH_NativeBuffer_Config创建OH_NativeBuffer实例，每次调用都会产生一个新的OH_NativeBuffer实例 | 
| int32_t [OH_NativeBuffer_Reference](#oh_nativebuffer_reference) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | 将OH_NativeBuffer对象的引用计数加1 | 
| int32_t [OH_NativeBuffer_Unreference](#oh_nativebuffer_unreference) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | 将OH_NativeBuffer对象的引用计数减1，当引用计数为0的时候，该NativeBuffer对象会被析构掉 | 
| void [OH_NativeBuffer_GetConfig](#oh_nativebuffer_getconfig) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | 用于获取OH_NativeBuffer的属性 | 
| int32_t [OH_NativeBuffer_Map](#oh_nativebuffer_map) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, void \*\*virAddr) | 将OH_NativeBuffer对应的ION内存映射到进程空间 | 
| int32_t [OH_NativeBuffer_Unmap](#oh_nativebuffer_unmap) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | 将OH_NativeBuffer对应的ION内存从进程空间移除 | 
| uint32_t [OH_NativeBuffer_GetSeqNum](#oh_nativebuffer_getseqnum) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | 获取OH_NativeBuffer的序列号 | 
| int32_t [OH_NativeBuffer_SetColorSpace](#oh_nativebuffer_setcolorspace) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace) colorSpace) | 为OH_NativeBuffer设置颜色空间属性。 | 
| int32_t [OH_NativeBuffer_MapPlanes](#oh_nativebuffer_mapplanes) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, void \*\*virAddr, [OH_NativeBuffer_Planes](_o_h___native_buffer___planes.md) \*outPlanes) | 将OH_NativeBuffer对应的多通道ION内存映射到进程空间。 | 
| int32_t [OH_NativeBuffer_FromNativeWindowBuffer](#oh_nativebuffer_fromnativewindowbuffer) ([OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*nativeWindowBuffer, [OH_NativeBuffer](#oh_nativebuffer) \*\*buffer) | 将OHNativeWindowBuffer实例转换为OH_NativeBuffer实例。 | 
| int32_t [OH_NativeBuffer_GetColorSpace](#oh_nativebuffer_getcolorspace) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace) \*colorSpace) | 获取OH_NativeBuffer颜色空间属性。 | 
| int32_t [OH_NativeBuffer_SetMetadataValue](#oh_nativebuffer_setmetadatavalue) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey) metadataKey, int32_t size, uint8_t \*metaData) | 为OH_NativeBuffer设置元数据属性值。 | 
| int32_t [OH_NativeBuffer_GetMetadataValue](#oh_nativebuffer_getmetadatavalue) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey) metadataKey, int32_t \*size, uint8_t \*\*metaData) | 获取OH_NativeBuffer元数据属性值。 | 


## 类型定义说明


### OH_NativeBuffer

```
typedef struct OH_NativeBuffer OH_NativeBuffer
```

**描述**

提供OH_NativeBuffer结构体声明

**起始版本：** 9


### OH_NativeBuffer_ColorGamut

```
typedef enum OH_NativeBuffer_ColorGamut OH_NativeBuffer_ColorGamut
```

**描述**

OH_NativeBuffer的色域。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


### OH_NativeBuffer_ColorSpace

```
typedef enum OH_NativeBuffer_ColorSpace OH_NativeBuffer_ColorSpace
```

**描述**

OH_NativeBuffer的颜色空间

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 11


### OH_NativeBuffer_ColorXY

```
typedef struct OH_NativeBuffer_ColorXY OH_NativeBuffer_ColorXY
```

**描述**

表示基色的X和Y坐标。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


### OH_NativeBuffer_Config

```
typedef struct OH_NativeBuffer_Config OH_NativeBuffer_Config
```

**描述**

OH_NativeBuffer的属性配置，用于申请新的OH_NativeBuffer实例或查询现有实例的相关属性

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9


### OH_NativeBuffer_Cta861

```
typedef struct OH_NativeBuffer_Cta861 OH_NativeBuffer_Cta861
```

**描述**

表示CTA-861.3静态元数据。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


### OH_NativeBuffer_Format

```
typedef enum OH_NativeBuffer_Format OH_NativeBuffer_Format
```

**描述**

OH_NativeBuffer的格式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 10


### OH_NativeBuffer_MetadataKey

```
typedef enum OH_NativeBuffer_MetadataKey OH_NativeBuffer_MetadataKey
```

**描述**

表示OH_NativeBuffer的HDR元数据种类的键值。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


### OH_NativeBuffer_MetadataType

```
typedef enum OH_NativeBuffer_MetadataType OH_NativeBuffer_MetadataType
```

**描述**

OH_NativeBuffer的图像标准。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


### OH_NativeBuffer_Plane

```
typedef struct OH_NativeBuffer_Plane OH_NativeBuffer_Plane
```

**描述**

单个图像平面格式信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


### OH_NativeBuffer_Planes

```
typedef struct OH_NativeBuffer_Planes OH_NativeBuffer_Planes
```

**描述**

OH_NativeBuffer的图像平面格式信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


### OH_NativeBuffer_Smpte2086

```
typedef struct OH_NativeBuffer_Smpte2086 OH_NativeBuffer_Smpte2086
```

**描述**

表示smpte2086静态元数据。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


### OH_NativeBuffer_StaticMetadata

```
typedef struct OH_NativeBuffer_StaticMetadata OH_NativeBuffer_StaticMetadata
```

**描述**

表示HDR静态元数据。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


### OH_NativeBuffer_TransformType

```
typedef enum OH_NativeBuffer_TransformType OH_NativeBuffer_TransformType
```

**描述**

OH_NativeBuffer的转换类型。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


### OH_NativeBuffer_Usage

```
typedef enum OH_NativeBuffer_Usage OH_NativeBuffer_Usage
```

**描述**

OH_NativeBuffer的用途。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 10


### OHNativeErrorCode

```
typedef enum OHNativeErrorCodeOHNativeErrorCode
```

**描述**

接口错误码说明（仅用于查询）。

**起始版本：** 12


## 枚举类型说明


### OH_NativeBuffer_ColorGamut

```
enum OH_NativeBuffer_ColorGamut
```

**描述**

OH_NativeBuffer的色域。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NATIVEBUFFER_COLOR_GAMUT_NATIVE | 默认色域格式 | 
| NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT601 | Standard BT601 色域格式 | 
| NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT709 | Standard BT709 色域格式 | 
| NATIVEBUFFER_COLOR_GAMUT_DCI_P3 | DCI P3 色域格式 | 
| NATIVEBUFFER_COLOR_GAMUT_SRGB | SRGB 色域格式 | 
| NATIVEBUFFER_COLOR_GAMUT_ADOBE_RGB | Adobe RGB 色域格式 | 
| NATIVEBUFFER_COLOR_GAMUT_DISPLAY_P3 | Display P3 色域格式 | 
| NATIVEBUFFER_COLOR_GAMUT_BT2020 | BT2020 色域格式 | 
| NATIVEBUFFER_COLOR_GAMUT_BT2100_PQ | BT2100 PQ 色域格式 | 
| NATIVEBUFFER_COLOR_GAMUT_BT2100_HLG | BT2100 HLG 色域格式 | 
| NATIVEBUFFER_COLOR_GAMUT_DISPLAY_BT2020 | Display BT2020 色域格式 | 


### OH_NativeBuffer_ColorSpace

```
enum OH_NativeBuffer_ColorSpace
```

**描述**

OH_NativeBuffer的颜色空间

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_COLORSPACE_NONE | 无颜色空间 | 
| OH_COLORSPACE_BT601_EBU_FULL | 色域范围为BT601_P， 传递函数为BT709， 转换矩阵为BT601_P， 数据范围为RANGE_FULL | 
| OH_COLORSPACE_BT601_SMPTE_C_FULL | 色域范围为BT601_N， 传递函数为BT709， 转换矩阵为BT601_N， 数据范围为RANGE_FULL | 
| OH_COLORSPACE_BT709_FULL | 色域范围为BT709， 传递函数为BT709， 转换矩阵为BT709， 数据范围为RANGE_FULL | 
| OH_COLORSPACE_BT2020_HLG_FULL | 色域范围为BT2020， 传递函数为HLG， 转换矩阵为BT2020， 数据范围为RANGE_FULL | 
| OH_COLORSPACE_BT2020_PQ_FULL | 色域范围为BT2020， 传递函数为PQ， 转换矩阵为BT2020， 数据范围为RANGE_FULL | 
| OH_COLORSPACE_BT601_EBU_LIMIT | 色域范围为BT601_P， 传递函数为BT709， 转换矩阵为BT601_P， 数据范围为RANGE_LIMITED | 
| OH_COLORSPACE_BT601_SMPTE_C_LIMIT | 色域范围为BT601_N， 传递函数为BT709， 转换矩阵为BT601_N， 数据范围为RANGE_LIMITED | 
| OH_COLORSPACE_BT709_LIMIT | 色域范围为BT709， 传递函数为BT709， 转换矩阵为BT709， 数据范围为RANGE_LIMITED | 
| OH_COLORSPACE_BT2020_HLG_LIMIT | 色域范围为BT2020， 传递函数为HLG， 转换矩阵为BT2020， 数据范围为RANGE_LIMITED | 
| OH_COLORSPACE_BT2020_PQ_LIMIT | 色域范围为BT2020， 传递函数为PQ， 转换矩阵为BT2020， 数据范围为RANGE_LIMITED | 
| OH_COLORSPACE_SRGB_FULL | 色域范围为SRGB， 传递函数为SRGB， 转换矩阵为BT601_N， 数据范围为RANGE_FULL | 
| OH_COLORSPACE_P3_FULL | 色域范围为P3_D65， 传递函数为SRGB， 转换矩阵为P3， 数据范围为RANGE_FULL | 
| OH_COLORSPACE_P3_HLG_FULL | 色域范围为P3_D65， 传递函数为HLG， 转换矩阵为P3， 数据范围为RANGE_FULL | 
| OH_COLORSPACE_P3_PQ_FULL | 色域范围为P3_D65， 传递函数为PQ， 转换矩阵为P3， 数据范围为RANGE_FULL | 
| OH_COLORSPACE_ADOBERGB_FULL | 色域范围为ADOBERGB， 传递函数为ADOBERGB， 转换矩阵为ADOBERGB， 数据范围为RANGE_FULL | 
| OH_COLORSPACE_SRGB_LIMIT | 色域范围为SRGB， 传递函数为SRGB， 转换矩阵为BT601_N， 数据范围为RANGE_LIMITED | 
| OH_COLORSPACE_P3_LIMIT | 色域范围为P3_D65， 传递函数为SRGB， 转换矩阵为P3， 数据范围为RANGE_LIMITED | 
| OH_COLORSPACE_P3_HLG_LIMIT | 色域范围为P3_D65， 传递函数为HLG， 转换矩阵为P3， 数据范围为RANGE_LIMITED | 
| OH_COLORSPACE_P3_PQ_LIMIT | 色域范围为P3_D65， 传递函数为PQ， 转换矩阵为P3， 数据范围为RANGE_LIMITED | 
| OH_COLORSPACE_ADOBERGB_LIMIT | 色域范围为ADOBERGB， 传递函数为ADOBERGB， 转换矩阵为ADOBERGB， 数据范围为RANGE_LIMITED | 
| OH_COLORSPACE_LINEAR_SRGB | 色域范围为SRGB， 传递函数为LINEAR | 
| OH_COLORSPACE_LINEAR_BT709 | 等同于 OH_COLORSPACE_LINEAR_SRGB | 
| OH_COLORSPACE_LINEAR_P3 | 色域范围为P3_D65， 传递函数为LINEAR | 
| OH_COLORSPACE_LINEAR_BT2020 | 色域范围为BT2020， 传递函数为LINEAR | 
| OH_COLORSPACE_DISPLAY_SRGB | 等同于 OH_COLORSPACE_SRGB_FULL | 
| OH_COLORSPACE_DISPLAY_P3_SRGB | 等同于 OH_COLORSPACE_P3_FULL | 
| OH_COLORSPACE_DISPLAY_P3_HLG | 等同于 OH_COLORSPACE_P3_HLG_FULL | 
| OH_COLORSPACE_DISPLAY_P3_PQ | 等同于 OH_COLORSPACE_P3_PQ_FULL | 
| OH_COLORSPACE_DISPLAY_BT2020_SRGB | 色域范围为BT2020， 传递函数为SRGB， 转换矩阵为BT2020， 数据范围为RANGE_FULL | 
| OH_COLORSPACE_DISPLAY_BT2020_HLG | 等同于 OH_COLORSPACE_BT2020_HLG_FULL | 
| OH_COLORSPACE_DISPLAY_BT2020_PQ | 等同于 OH_COLORSPACE_BT2020_PQ_FULL | 


### OH_NativeBuffer_Format

```
enum OH_NativeBuffer_Format
```

**描述**

OH_NativeBuffer的格式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| NATIVEBUFFER_PIXEL_FMT_CLUT8<sup>12+</sup> | CLUT8格式 | 
| NATIVEBUFFER_PIXEL_FMT_CLUT1<sup>12+</sup> | CLUT1格式 | 
| NATIVEBUFFER_PIXEL_FMT_CLUT4<sup>12+</sup> | CLUT4格式 | 
| NATIVEBUFFER_PIXEL_FMT_RGB_565 | RGB565格式 | 
| NATIVEBUFFER_PIXEL_FMT_RGBA_5658 | RGBA5658格式 | 
| NATIVEBUFFER_PIXEL_FMT_RGBX_4444 | RGBX4444格式 | 
| NATIVEBUFFER_PIXEL_FMT_RGBA_4444 | RGBA4444格式 | 
| NATIVEBUFFER_PIXEL_FMT_RGB_444 | RGB444格式 | 
| NATIVEBUFFER_PIXEL_FMT_RGBX_5551 | RGBX5551格式 | 
| NATIVEBUFFER_PIXEL_FMT_RGBA_5551 | RGBA5551格式 | 
| NATIVEBUFFER_PIXEL_FMT_RGB_555 | RGB555格式 | 
| NATIVEBUFFER_PIXEL_FMT_RGBX_8888 | RGBX8888格式 | 
| NATIVEBUFFER_PIXEL_FMT_RGBA_8888 | RGBA8888格式 | 
| NATIVEBUFFER_PIXEL_FMT_RGB_888 | RGB888格式 | 
| NATIVEBUFFER_PIXEL_FMT_BGR_565 | BGR565格式 | 
| NATIVEBUFFER_PIXEL_FMT_BGRX_4444 | BGRX4444格式 | 
| NATIVEBUFFER_PIXEL_FMT_BGRA_4444 | BGRA4444格式 | 
| NATIVEBUFFER_PIXEL_FMT_BGRX_5551 | BGRX5551格式 | 
| NATIVEBUFFER_PIXEL_FMT_BGRA_5551 | BGRA5551格式 | 
| NATIVEBUFFER_PIXEL_FMT_BGRX_8888 | BGRX8888格式 | 
| NATIVEBUFFER_PIXEL_FMT_BGRA_8888 | BGRA8888格式 | 
| NATIVEBUFFER_PIXEL_FMT_YUV_422_I<sup>12+</sup> | YUV422 interleaved 格式 | 
| NATIVEBUFFER_PIXEL_FMT_YCBCR_422_SP<sup>12+</sup> | YCBCR422 semi-plannar 格式 | 
| NATIVEBUFFER_PIXEL_FMT_YCRCB_422_SP<sup>12+</sup> | YCRCB422 semi-plannar 格式 | 
| NATIVEBUFFER_PIXEL_FMT_YCBCR_420_SP<sup>12+</sup> | YCBCR420 semi-plannar 格式 | 
| NATIVEBUFFER_PIXEL_FMT_YCRCB_420_SP<sup>12+</sup> | YCRCB420 semi-plannar 格式 | 
| NATIVEBUFFER_PIXEL_FMT_YCBCR_422_P<sup>12+</sup> | YCBCR422 plannar 格式 | 
| NATIVEBUFFER_PIXEL_FMT_YCRCB_422_P<sup>12+</sup> | YCRCB422 plannar 格式 | 
| NATIVEBUFFER_PIXEL_FMT_YCBCR_420_P<sup>12+</sup> | YCBCR420 plannar 格式 | 
| NATIVEBUFFER_PIXEL_FMT_YCRCB_420_P<sup>12+</sup> | YCRCB420 plannar 格式 | 
| NATIVEBUFFER_PIXEL_FMT_YUYV_422_PKG<sup>12+</sup> | YUYV422 packed 格式 | 
| NATIVEBUFFER_PIXEL_FMT_UYVY_422_PKG<sup>12+</sup> | UYVY422 packed 格式 | 
| NATIVEBUFFER_PIXEL_FMT_YVYU_422_PKG<sup>12+</sup> | YVYU422 packed 格式 | 
| NATIVEBUFFER_PIXEL_FMT_VYUY_422_PKG<sup>12+</sup> | VYUY422 packed 格式 | 
| NATIVEBUFFER_PIXEL_FMT_RGBA_1010102<sup>12+</sup> | RGBA_1010102 packed 格式 | 
| NATIVEBUFFER_PIXEL_FMT_YCBCR_P010<sup>12+</sup> | YCBCR420 semi-planar 10bit packed 格式 | 
| NATIVEBUFFER_PIXEL_FMT_YCRCB_P010<sup>12+</sup> | YCRCB420 semi-planar 10bit packed 格式 | 
| NATIVEBUFFER_PIXEL_FMT_RAW10<sup>12+</sup> | Raw 10bit packed 格式 | 
| NATIVEBUFFER_PIXEL_FMT_VENDER_MASK<sup>12+</sup> | vender mask 格式 | 
| NATIVEBUFFER_PIXEL_FMT_BUTT | 无效格式 | 


### OH_NativeBuffer_MetadataKey

```
enum OH_NativeBuffer_MetadataKey
```

**描述**

表示OH_NativeBuffer的HDR元数据种类的键值。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_HDR_METADATA_TYPE | 元数据类型，其值见[OH_NativeBuffer_MetadataType](#oh_nativebuffer_metadatatype)，size为OH_NativeBuffer_MetadataType大小。 | 
| OH_HDR_STATIC_METADATA | 静态元数据，其值见[OH_NativeBuffer_StaticMetadata](_o_h___native_buffer___static_metadata.md)，size为OH_NativeBuffer_StaticMetadata大小。 | 
| OH_HDR_DYNAMIC_METADATA | 动态元数据，其值见视频流中SEI的字节流，size的取值范围为1-3000。 | 


### OH_NativeBuffer_MetadataType

```
enum OH_NativeBuffer_MetadataType
```

**描述**

OH_NativeBuffer的图像标准。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_VIDEO_HDR_HLG | 视频HLG。 | 
| OH_VIDEO_HDR_HDR10 | 视频HDR10。 | 
| OH_VIDEO_HDR_VIVID | 视频HDR VIVID。 | 


### OH_NativeBuffer_TransformType

```
enum OH_NativeBuffer_TransformType
```

**描述**

OH_NativeBuffer的转换类型。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NATIVEBUFFER_ROTATE_NONE | 不旋转 | 
| NATIVEBUFFER_ROTATE_90 | 旋转90度 | 
| NATIVEBUFFER_ROTATE_180 | 旋转180度 | 
| NATIVEBUFFER_ROTATE_270 | 旋转270度 | 
| NATIVEBUFFER_FLIP_H | 水平翻转 | 
| NATIVEBUFFER_FLIP_V | 垂直翻转 | 
| NATIVEBUFFER_FLIP_H_ROT90 | 水平翻转并旋转90度 | 
| NATIVEBUFFER_FLIP_V_ROT90 | 垂直翻转并旋转90度 | 
| NATIVEBUFFER_FLIP_H_ROT180 | 水平翻转并旋转180度 | 
| NATIVEBUFFER_FLIP_V_ROT180 | 垂直翻转并旋转180度 | 
| NATIVEBUFFER_FLIP_H_ROT270 | 水平翻转并旋转270度 | 
| NATIVEBUFFER_FLIP_V_ROT270 | 垂直翻转并旋转270度 | 


### OH_NativeBuffer_Usage

```
enum OH_NativeBuffer_Usage
```

**描述**

OH_NativeBuffer的用途。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| NATIVEBUFFER_USAGE_CPU_READ | CPU可读 | 
| NATIVEBUFFER_USAGE_CPU_WRITE | CPU可写 | 
| NATIVEBUFFER_USAGE_MEM_DMA | 直接内存访问缓冲区 | 
| NATIVEBUFFER_USAGE_HW_RENDER<sup>12+</sup> | GPU可写 | 
| NATIVEBUFFER_USAGE_HW_TEXTURE<sup>12+</sup> | GPU可读 | 
| NATIVEBUFFER_USAGE_CPU_READ_OFTEN<sup>12+</sup> | CPU可直接映射 | 
| NATIVEBUFFER_USAGE_ALIGNMENT_512<sup>12+</sup> | 512字节对齐 | 


### OHNativeErrorCode

```
enum OHNativeErrorCode
```

**描述**

接口错误码说明（仅用于查询）。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NATIVE_ERROR_OK | 成功 | 
| NATIVE_ERROR_INVALID_ARGUMENTS | 入参无效 | 
| NATIVE_ERROR_NO_PERMISSION | 无权限操作 | 
| NATIVE_ERROR_NO_BUFFER | 无空闲可用的buffer | 
| NATIVE_ERROR_NO_CONSUMER | 消费端不存在 | 
| NATIVE_ERROR_NOT_INIT | 未初始化 | 
| NATIVE_ERROR_CONSUMER_CONNECTED | 消费端已经被连接 | 
| NATIVE_ERROR_BUFFER_STATE_INVALID | buffer状态不符合预期 | 
| NATIVE_ERROR_BUFFER_IN_CACHE | buffer已在缓存队列中 | 
| NATIVE_ERROR_BUFFER_QUEUE_FULL | 队列已满 | 
| NATIVE_ERROR_BUFFER_NOT_IN_CACHE | buffer不在缓存队列中 |
| NATIVE_ERROR_CONSUMER_DISCONNECTED | 消费端已经被断开连接 |
| NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED | 消费端未注册listener回调函数 |
| NATIVE_ERROR_UNSUPPORTED | 当前设备或平台不支持 | 
| NATIVE_ERROR_UNKNOWN | 未知错误，请查看日志 | 
| NATIVE_ERROR_HDI_ERROR  | HDI接口调用失败   | 
| NATIVE_ERROR_BINDER_ERROR  | 跨进程通信失败   | 
| NATIVE_ERROR_EGL_STATE_UNKNOWN | egl环境状态异常 | 
| NATIVE_ERROR_EGL_API_FAILED | egl接口调用失败 | 


## 函数说明


### OH_NativeBuffer_Alloc()

```
OH_NativeBuffer* OH_NativeBuffer_Alloc (const OH_NativeBuffer_Config* config)
```

**描述**

通过OH_NativeBuffer_Config创建OH_NativeBuffer实例，每次调用都会产生一个新的OH_NativeBuffer实例。
本接口需要与OH_NativeBuffer_Unreference接口配合使用，否则会存在内存泄露。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 一个指向OH_NativeBuffer_Config类型的指针 | 

**返回：**

创建成功则返回一个指向OH_NativeBuffer结构体实例的指针，否则返回NULL


### OH_NativeBuffer_FromNativeWindowBuffer()

```
int32_t OH_NativeBuffer_FromNativeWindowBuffer (OHNativeWindowBuffer *nativeWindowBuffer, OH_NativeBuffer **buffer )
```

**描述**

将OHNativeWindowBuffer实例转换为OH_NativeBuffer实例。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| nativeWindowBuffer | 一个指向OHNativeWindowBuffer实例的指针。 | 
| buffer | 一个指向OH_NativeBuffer实例的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeBuffer_GetColorSpace()

```
int32_t OH_NativeBuffer_GetColorSpace (OH_NativeBuffer *buffer, OH_NativeBuffer_ColorSpace *colorSpace )
```

**描述**

获取OH_NativeBuffer颜色空间属性。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针。 | 
| colorSpace | OH_NativeBuffer的颜色空间，其值从[OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace)获取。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeBuffer_GetConfig()

```
void OH_NativeBuffer_GetConfig (OH_NativeBuffer *buffer, OH_NativeBuffer_Config* config )
```

**描述**

用于获取OH_NativeBuffer的属性。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针 | 
| config | 一个指向OH_NativeBuffer_Config的指针，用于接收OH_NativeBuffer的属性 | 


### OH_NativeBuffer_GetMetadataValue()

```
int32_t OH_NativeBuffer_GetMetadataValue (OH_NativeBuffer *buffer, OH_NativeBuffer_MetadataKey metadataKey, int32_t *size, uint8_t **metaData )
```

**描述**

获取OH_NativeBuffer元数据属性值。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针。 | 
| metadataKey | OH_NativeBuffer的元数据类型，其值从[OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey)获取。 | 
| size | uint8_t向量的大小，其取值范围见[OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey)。 | 
| metaDate | 指向uint8_t向量的二级指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeBuffer_GetSeqNum()

```
uint32_t OH_NativeBuffer_GetSeqNum (OH_NativeBuffer *buffer)
```

**描述**

获取OH_NativeBuffer的序列号。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针 | 

**返回：**

返回对应OH_NativeBuffer的唯一序列号


### OH_NativeBuffer_Map()

```
int32_t OH_NativeBuffer_Map (OH_NativeBuffer *buffer, void **virAddr )
```

**描述**

将OH_NativeBuffer对应的ION内存映射到进程空间。
本接口需要与OH_NativeBuffer_Unmap接口配合使用。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针 | 
| virAddr | 一个二级指针，二级指针指向映射到当前进程的虚拟内存的地址 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeBuffer_MapPlanes()

```
int32_t OH_NativeBuffer_MapPlanes (OH_NativeBuffer *buffer, void **virAddr, OH_NativeBuffer_Planes *outPlanes )
```

**描述**

将OH_NativeBuffer对应的多通道ION内存映射到进程空间。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针。 | 
| virAddr | 一个二级指针，二级指针指向映射到当前进程的虚拟内存的地址。 | 
| outPlanes | 一个指向所有图像平面格式信息的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeBuffer_Reference()

```
int32_t OH_NativeBuffer_Reference (OH_NativeBuffer *buffer)
```

**描述**

将OH_NativeBuffer对象的引用计数加1。
本接口需要与OH_NativeBuffer_Unreference接口配合使用，否则会存在内存泄露。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeBuffer_SetColorSpace()

```
int32_t OH_NativeBuffer_SetColorSpace (OH_NativeBuffer *buffer, OH_NativeBuffer_ColorSpace colorSpace )
```

**描述**

为OH_NativeBuffer设置颜色空间属性。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针。 | 
| colorSpace | 为OH_NativeBuffer设置的颜色空间，其值从[OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace)获取。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeBuffer_SetMetadataValue()

```
int32_t OH_NativeBuffer_SetMetadataValue (OH_NativeBuffer *buffer, OH_NativeBuffer_MetadataKey metadataKey, int32_t size, uint8_t *metaData )
```

**描述**

为OH_NativeBuffer设置元数据属性值。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针。 | 
| metadataKey | OH_NativeBuffer的元数据类型，其值从[OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey)获取。 | 
| size | uint8_t向量的大小，其取值范围见[OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey)。 | 
| metaDate | 指向uint8_t向量的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeBuffer_Unmap()

```
int32_t OH_NativeBuffer_Unmap (OH_NativeBuffer *buffer)
```

**描述**

将OH_NativeBuffer对应的ION内存从进程空间移除。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeBuffer_Unreference()

```
int32_t OH_NativeBuffer_Unreference (OH_NativeBuffer *buffer)
```

**描述**

将OH_NativeBuffer对象的引用计数减1，当引用计数为0的时候，该NativeBuffer对象会被析构掉。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。
