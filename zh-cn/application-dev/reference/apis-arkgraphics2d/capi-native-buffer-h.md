# native_buffer.h

## 概述

定义获取和使用NativeBuffer的相关函数。

**引用文件：** <native_buffer/native_buffer.h>

**库：** libnative_buffer.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9

**相关模块：** [OH_NativeBuffer](capi-oh-nativebuffer.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_NativeBuffer_Config](capi-oh-nativebuffer-config.md) | OH_NativeBuffer_Config | OH_NativeBuffer的属性配置，用于申请新的OH_NativeBuffer实例或查询现有实例的相关属性。 |
| [OH_NativeBuffer_Plane](capi-oh-nativebuffer-plane.md) | OH_NativeBuffer_Plane | 单个图像平面格式信息。 |
| [OH_NativeBuffer_Planes](capi-oh-nativebuffer-planes.md) | OH_NativeBuffer_Planes | OH_NativeBuffer的图像平面格式信息。 |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) | OH_NativeBuffer | 提供OH_NativeBuffer结构体声明。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_NativeBuffer_Usage](#oh_nativebuffer_usage) | OH_NativeBuffer_Usage | OH_NativeBuffer的用途。 |
| [OH_NativeBuffer_Format](#oh_nativebuffer_format) | OH_NativeBuffer_Format | OH_NativeBuffer的格式。 |
| [OH_NativeBuffer_TransformType](#oh_nativebuffer_transformtype) | OH_NativeBuffer_TransformType | OH_NativeBuffer的转换类型。 |
| [OH_NativeBuffer_ColorGamut](#oh_nativebuffer_colorgamut) | OH_NativeBuffer_ColorGamut | OH_NativeBuffer的色域。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_NativeBuffer* OH_NativeBuffer_Alloc(const OH_NativeBuffer_Config* config)](#oh_nativebuffer_alloc) | 通过OH_NativeBuffer_Config创建OH_NativeBuffer实例，每次调用都会产生一个新的OH_NativeBuffer实例。<br>本接口需要与[OH_NativeBuffer_Unreference](capi-native-buffer-h.md#oh_nativebuffer_unreference)接口配合使用，否则会存在内存泄露。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeBuffer_Reference(OH_NativeBuffer *buffer)](#oh_nativebuffer_reference) | 将OH_NativeBuffer对象的引用计数加1。<br>本接口需要与[OH_NativeBuffer_Unreference](capi-native-buffer-h.md#oh_nativebuffer_unreference)接口配合使用，否则会存在内存泄露。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeBuffer_Unreference(OH_NativeBuffer *buffer)](#oh_nativebuffer_unreference) | 将OH_NativeBuffer对象的引用计数减1，当引用计数为0的时候，该NativeBuffer对象会被析构掉。<br>本接口为非线程安全类型接口。 |
| [void OH_NativeBuffer_GetConfig(OH_NativeBuffer *buffer, OH_NativeBuffer_Config* config)](#oh_nativebuffer_getconfig) | 用于获取OH_NativeBuffer的属性。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeBuffer_Map(OH_NativeBuffer *buffer, void **virAddr)](#oh_nativebuffer_map) | 将OH_NativeBuffer对应的ION内存映射到进程空间。<br>本接口需要与[OH_NativeBuffer_Unmap](capi-native-buffer-h.md#oh_nativebuffer_unmap)接口配合使用。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeBuffer_Unmap(OH_NativeBuffer *buffer)](#oh_nativebuffer_unmap) | 将OH_NativeBuffer对应的ION内存从进程空间移除。<br>本接口为非线程安全类型接口。 |
| [uint32_t OH_NativeBuffer_GetSeqNum(OH_NativeBuffer *buffer)](#oh_nativebuffer_getseqnum) | 获取OH_NativeBuffer的序列号。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeBuffer_SetColorSpace(OH_NativeBuffer *buffer, OH_NativeBuffer_ColorSpace colorSpace)](#oh_nativebuffer_setcolorspace) | 为OH_NativeBuffer设置颜色空间属性。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeBuffer_MapPlanes(OH_NativeBuffer *buffer, void **virAddr, OH_NativeBuffer_Planes *outPlanes)](#oh_nativebuffer_mapplanes) | 将OH_NativeBuffer对应的多通道ION内存映射到进程空间。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeBuffer_FromNativeWindowBuffer(OHNativeWindowBuffer *nativeWindowBuffer, OH_NativeBuffer **buffer)](#oh_nativebuffer_fromnativewindowbuffer) | 将OHNativeWindowBuffer实例转换为OH_NativeBuffer实例。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeBuffer_GetColorSpace(OH_NativeBuffer *buffer, OH_NativeBuffer_ColorSpace *colorSpace)](#oh_nativebuffer_getcolorspace) | 获取OH_NativeBuffer颜色空间属性。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeBuffer_SetMetadataValue(OH_NativeBuffer *buffer, OH_NativeBuffer_MetadataKey metadataKey,int32_t size, uint8_t *metadata)](#oh_nativebuffer_setmetadatavalue) | 为OH_NativeBuffer设置元数据属性值。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeBuffer_GetMetadataValue(OH_NativeBuffer *buffer, OH_NativeBuffer_MetadataKey metadataKey,int32_t *size, uint8_t **metadata)](#oh_nativebuffer_getmetadatavalue) | 获取OH_NativeBuffer元数据属性值。<br>本接口为非线程安全类型接口。 |

## 枚举类型说明

### OH_NativeBuffer_Usage

```
enum OH_NativeBuffer_Usage
```

**描述**

OH_NativeBuffer的用途。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| NATIVEBUFFER_USAGE_CPU_READ = (1ULL << 0) | CPU可读。 |
| NATIVEBUFFER_USAGE_CPU_WRITE = (1ULL << 1) | CPU可写。 |
| NATIVEBUFFER_USAGE_MEM_DMA = (1ULL << 3) | 直接内存访问缓冲区。 |
| NATIVEBUFFER_USAGE_MEM_MMZ_CACHE = (1ULL << 5) | 媒体内存区域缓存。<br/>**起始版本：** 20 |
| NATIVEBUFFER_USAGE_HW_RENDER = (1ULL << 8) |  GPU可写。<br/>**起始版本：** 12 |
| NATIVEBUFFER_USAGE_HW_TEXTURE = (1ULL << 9) | GPU可读。<br/>**起始版本：** 12 |
| NATIVEBUFFER_USAGE_CPU_READ_OFTEN = (1ULL << 16) | CPU可直接映射。<br/>**起始版本：** 12 |
| NATIVEBUFFER_USAGE_ALIGNMENT_512 = (1ULL << 18) | 512字节对齐。<br/>**起始版本：** 12 |

### OH_NativeBuffer_Format

```
enum OH_NativeBuffer_Format
```

**描述**

OH_NativeBuffer的格式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| NATIVEBUFFER_PIXEL_FMT_CLUT8 = 0 | CLUT8格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_CLUT1 | CLUT1格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_CLUT4 | CLUT4格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_RGB_565 = 3 | RGB565格式。 |
| NATIVEBUFFER_PIXEL_FMT_RGBA_5658 | RGBA5658格式。 |
| NATIVEBUFFER_PIXEL_FMT_RGBX_4444 | RGBX4444格式。 |
| NATIVEBUFFER_PIXEL_FMT_RGBA_4444 | RGBA4444格式。 |
| NATIVEBUFFER_PIXEL_FMT_RGB_444 | RGB444格式。 |
| NATIVEBUFFER_PIXEL_FMT_RGBX_5551 | RGBX5551格式。 |
| NATIVEBUFFER_PIXEL_FMT_RGBA_5551 | RGBA5551格式。 |
| NATIVEBUFFER_PIXEL_FMT_RGB_555 | RGB555格式。 |
| NATIVEBUFFER_PIXEL_FMT_RGBX_8888 | RGBX8888格式。 |
| NATIVEBUFFER_PIXEL_FMT_RGBA_8888 | RGBA8888格式。 |
| NATIVEBUFFER_PIXEL_FMT_RGB_888 | RGB888格式。 |
| NATIVEBUFFER_PIXEL_FMT_BGR_565 | BGR565格式。 |
| NATIVEBUFFER_PIXEL_FMT_BGRX_4444 | BGRX4444格式。 |
| NATIVEBUFFER_PIXEL_FMT_BGRA_4444 | BGRA4444格式。 |
| NATIVEBUFFER_PIXEL_FMT_BGRX_5551 | BGRX5551格式。 |
| NATIVEBUFFER_PIXEL_FMT_BGRA_5551 | BGRA5551格式。 |
| NATIVEBUFFER_PIXEL_FMT_BGRX_8888 | BGRX8888格式。 |
| NATIVEBUFFER_PIXEL_FMT_BGRA_8888 | BGRA8888格式。 |
| NATIVEBUFFER_PIXEL_FMT_YUV_422_I | YUV422 interleaved 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_YCBCR_422_SP | YCBCR422 semi-planar 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_YCRCB_422_SP | YCRCB422 semi-planar 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_YCBCR_420_SP | YCBCR420 semi-planar 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_YCRCB_420_SP | YCRCB420 semi-planar 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_YCBCR_422_P | YCBCR422 planar 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_YCRCB_422_P | YCRCB422 planar 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_YCBCR_420_P | YCBCR420 planar 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_YCRCB_420_P | YCRCB420 planar 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_YUYV_422_PKG | YUYV422 packed 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_UYVY_422_PKG | UYVY422 packed 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_YVYU_422_PKG | YVYU422 packed 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_VYUY_422_PKG | VYUY422 packed 格式。<br/>**起始版本：** 12 |
| NATIVEBUFFER_PIXEL_FMT_RGBA_1010102 | RGBA_1010102 packed 格式。 |
| NATIVEBUFFER_PIXEL_FMT_YCBCR_P010 | YCBCR420 semi-planar 10bit packed 格式。 |
| NATIVEBUFFER_PIXEL_FMT_YCRCB_P010 | YCRCB420 semi-planar 10bit packed 格式。 |
| NATIVEBUFFER_PIXEL_FMT_RAW10 | Raw 10bit packed 格式。 |
| NATIVEBUFFER_PIXEL_FMT_BLOB | BLOB格式。<br/>**起始版本：** 15 |
| NATIVEBUFFER_PIXEL_FMT_RGBA16_FLOAT | RGBA16 float格式。<br/>**起始版本：** 15 |
| NATIVEBUFFER_PIXEL_FMT_Y8 = 40 | Y8格式。<br/>**起始版本：** 20 |
| NATIVEBUFFER_PIXEL_FMT_Y16 = 41 | Y16格式。<br/>**起始版本：** 20 |
| NATIVEBUFFER_PIXEL_FMT_VENDER_MASK = 0X7FFF0000 | vender mask 格式。<br/>**起始版本：** 12|
| NATIVEBUFFER_PIXEL_FMT_BUTT = 0X7FFFFFFF | 无效格式。 |

### OH_NativeBuffer_TransformType

```
enum OH_NativeBuffer_TransformType
```

**描述**

OH_NativeBuffer的转换类型。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| NATIVEBUFFER_ROTATE_NONE = 0 | 不旋转。 |
| NATIVEBUFFER_ROTATE_90 | 旋转90度。 |
| NATIVEBUFFER_ROTATE_180 | 旋转180度。 |
| NATIVEBUFFER_ROTATE_270 | 旋转270度。 |
| NATIVEBUFFER_FLIP_H | 水平翻转。 |
| NATIVEBUFFER_FLIP_V | 垂直翻转。 |
| NATIVEBUFFER_FLIP_H_ROT90 | 水平翻转并旋转90度。 |
| NATIVEBUFFER_FLIP_V_ROT90 | 垂直翻转并旋转90度。 |
| NATIVEBUFFER_FLIP_H_ROT180 | 水平翻转并旋转180度。 |
| NATIVEBUFFER_FLIP_V_ROT180 | 垂直翻转并旋转180度。 |
| NATIVEBUFFER_FLIP_H_ROT270 | 水平翻转并旋转270度。 |
| NATIVEBUFFER_FLIP_V_ROT270 | 垂直翻转并旋转270度。 |

### OH_NativeBuffer_ColorGamut

```
enum OH_NativeBuffer_ColorGamut
```

**描述**

OH_NativeBuffer的色域。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| NATIVEBUFFER_COLOR_GAMUT_NATIVE = 0 | 默认色域格式。 |
| NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT601 = 1 | Standard BT601色域格式。 |
| NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT709 = 2 | Standard BT709色域格式。 |
| NATIVEBUFFER_COLOR_GAMUT_DCI_P3 = 3 | DCI P3色域格式。 |
| NATIVEBUFFER_COLOR_GAMUT_SRGB = 4 | SRGB色域格式。 |
| NATIVEBUFFER_COLOR_GAMUT_ADOBE_RGB = 5 | Adobe RGB色域格式。 |
| NATIVEBUFFER_COLOR_GAMUT_DISPLAY_P3 = 6 | Display P3色域格式。 |
| NATIVEBUFFER_COLOR_GAMUT_BT2020 = 7 | BT2020色域格式。 |
| NATIVEBUFFER_COLOR_GAMUT_BT2100_PQ = 8 | BT2100 PQ色域格式。 |
| NATIVEBUFFER_COLOR_GAMUT_BT2100_HLG = 9 | BT2100 HLG色域格式。 |
| NATIVEBUFFER_COLOR_GAMUT_DISPLAY_BT2020 = 10 | Display BT2020色域格式。 |


## 函数说明

### OH_NativeBuffer_Alloc()

```
OH_NativeBuffer* OH_NativeBuffer_Alloc(const OH_NativeBuffer_Config* config)
```

**描述**

通过OH_NativeBuffer_Config创建OH_NativeBuffer实例，每次调用都会产生一个新的OH_NativeBuffer实例。<br>本接口需要与[OH_NativeBuffer_Unreference](capi-native-buffer-h.md#oh_nativebuffer_unreference)接口配合使用，否则会存在内存泄露。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_NativeBuffer_Config](capi-oh-nativebuffer-config.md)* config | 一个指向OH_NativeBuffer_Config类型的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_NativeBuffer* | 创建成功则返回一个指向OH_NativeBuffer结构体实例的指针，否则返回NULL。 |

### OH_NativeBuffer_Reference()

```
int32_t OH_NativeBuffer_Reference(OH_NativeBuffer *buffer)
```

**描述**

将OH_NativeBuffer对象的引用计数加1。<br>本接口需要与[OH_NativeBuffer_Unreference](capi-native-buffer-h.md#oh_nativebuffer_unreference)接口配合使用，否则会存在内存泄露。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) *buffer | 一个指向OH_NativeBuffer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeBuffer_Unreference()

```
int32_t OH_NativeBuffer_Unreference(OH_NativeBuffer *buffer)
```

**描述**

将OH_NativeBuffer对象的引用计数减1，当引用计数为0的时候，该NativeBuffer对象会被析构掉。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) *buffer | 一个指向OH_NativeBuffer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeBuffer_GetConfig()

```
void OH_NativeBuffer_GetConfig(OH_NativeBuffer *buffer, OH_NativeBuffer_Config* config)
```

**描述**

用于获取OH_NativeBuffer的属性。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) *buffer | 一个指向OH_NativeBuffer实例的指针。 |
| [OH_NativeBuffer_Config](capi-oh-nativebuffer-config.md)* config | 一个指向OH_NativeBuffer_Config的指针，用于接收OH_NativeBuffer的属性。 |

### OH_NativeBuffer_Map()

```
int32_t OH_NativeBuffer_Map(OH_NativeBuffer *buffer, void **virAddr)
```

**描述**

将OH_NativeBuffer对应的ION内存映射到进程空间。<br>本接口需要与[OH_NativeBuffer_Unmap](capi-native-buffer-h.md#oh_nativebuffer_unmap)接口配合使用。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) *buffer | 一个指向OH_NativeBuffer实例的指针。 |
| void **virAddr | 一个二级指针，二级指针指向映射到当前进程的虚拟内存的地址。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeBuffer_Unmap()

```
int32_t OH_NativeBuffer_Unmap(OH_NativeBuffer *buffer)
```

**描述**

将OH_NativeBuffer对应的ION内存从进程空间移除。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) *buffer | 一个指向OH_NativeBuffer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeBuffer_GetSeqNum()

```
uint32_t OH_NativeBuffer_GetSeqNum(OH_NativeBuffer *buffer)
```

**描述**

获取OH_NativeBuffer的序列号。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) *buffer | 一个指向OH_NativeBuffer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回对应OH_NativeBuffer的唯一序列号。 |

### OH_NativeBuffer_SetColorSpace()

```
int32_t OH_NativeBuffer_SetColorSpace(OH_NativeBuffer *buffer, OH_NativeBuffer_ColorSpace colorSpace)
```

**描述**

为OH_NativeBuffer设置颜色空间属性。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) *buffer | 一个指向OH_NativeBuffer实例的指针。 |
| [OH_NativeBuffer_ColorSpace](capi-buffer-common-h.md#oh_nativebuffer_colorspace) colorSpace | 为OH_NativeBuffer设置的颜色空间，其值从[OH_NativeBuffer_ColorSpace](capi-buffer-common-h.md#oh_nativebuffer_colorspace)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeBuffer_MapPlanes()

```
int32_t OH_NativeBuffer_MapPlanes(OH_NativeBuffer *buffer, void **virAddr, OH_NativeBuffer_Planes *outPlanes)
```

**描述**

将OH_NativeBuffer对应的多通道ION内存映射到进程空间。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) *buffer | 一个指向OH_NativeBuffer实例的指针。 |
| void **virAddr | 一个二级指针，二级指针指向映射到当前进程的虚拟内存的地址。 |
| [OH_NativeBuffer_Planes](capi-oh-nativebuffer-planes.md) *outPlanes | 一个指向所有图像平面格式信息的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeBuffer_FromNativeWindowBuffer()

```
int32_t OH_NativeBuffer_FromNativeWindowBuffer(OHNativeWindowBuffer *nativeWindowBuffer, OH_NativeBuffer **buffer)
```

**描述**

将OHNativeWindowBuffer实例转换为OH_NativeBuffer实例。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindowBuffer](capi-nativewindowbuffer.md) *nativeWindowBuffer | 一个指向[OHNativeWindowBuffer](capi-nativewindowbuffer.md)实例的指针。 |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) **buffer | 一个指向OH_NativeBuffer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeBuffer_GetColorSpace()

```
int32_t OH_NativeBuffer_GetColorSpace(OH_NativeBuffer *buffer, OH_NativeBuffer_ColorSpace *colorSpace)
```

**描述**

获取OH_NativeBuffer颜色空间属性。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) *buffer | 一个指向OH_NativeBuffer实例的指针。 |
| [OH_NativeBuffer_ColorSpace](capi-buffer-common-h.md#oh_nativebuffer_colorspace) *colorSpace | 为[OH_NativeBuffer](capi-oh-nativebuffer.md)设置的颜色空间，其值从[OH_NativeBuffer_ColorSpace](capi-buffer-common-h.md#oh_nativebuffer_colorspace)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeBuffer_SetMetadataValue()

```
int32_t OH_NativeBuffer_SetMetadataValue(OH_NativeBuffer *buffer, OH_NativeBuffer_MetadataKey metadataKey,int32_t size, uint8_t *metadata)
```

**描述**

为OH_NativeBuffer设置元数据属性值。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) *buffer | 一个指向OH_NativeBuffer实例的指针。 |
| [OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey) metadataKey | [OH_NativeBuffer](capi-oh-nativebuffer.md)的元数据类型，其值从[OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey)获取。 |
| int32_t size | uint8_t向量的大小，其取值范围参考[OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey)。 |
| metaData |  指向uint8_t向量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeBuffer_GetMetadataValue()

```
int32_t OH_NativeBuffer_GetMetadataValue(OH_NativeBuffer *buffer, OH_NativeBuffer_MetadataKey metadataKey,int32_t *size, uint8_t **metadata)
```

**描述**

获取OH_NativeBuffer元数据属性值。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) *buffer | 一个指向OH_NativeBuffer实例的指针。 |
| [OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey) metadataKey | [OH_NativeBuffer](capi-oh-nativebuffer.md)的元数据类型，其值从[OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey)获取。 |
| int32_t *size | uint8_t向量的大小，其取值范围参考[OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey)。 |
| metaData |  指向uint8_t向量的二级指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |


