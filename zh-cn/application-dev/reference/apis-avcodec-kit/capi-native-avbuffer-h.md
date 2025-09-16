# native_avbuffer.h

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

## 概述

声明了媒体数据结构AVBuffer的函数接口。

**引用文件：** <multimedia/player_framework/native_avbuffer.h>

**库：** libnative_media_core.so

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

**相关模块：** [Core](capi-core.md)

**相关示例：** [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) | OH_AVBuffer | 为媒体内存接口定义native层对象。 |
| [OH_NativeBuffer](capi-core-oh-nativebuffer.md) | OH_NativeBuffer | 为图形内存接口定义native层对象。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_AVBuffer *OH_AVBuffer_Create(int32_t capacity)](#oh_avbuffer_create) | 创建OH_AVBuffer实例。需要注意的是，返回值指向的创建OH_AVBuffer的实例需要开发者主动调用接口释放，请参阅[OH_AVBuffer_Destroy](#oh_avbuffer_destroy)。 |
| [OH_AVErrCode OH_AVBuffer_Destroy(OH_AVBuffer *buffer)](#oh_avbuffer_destroy) | 释放OH_AVBuffer实例指针的资源，同一个buffer不允许重复销毁。 |
| [OH_AVErrCode OH_AVBuffer_GetBufferAttr(OH_AVBuffer *buffer, OH_AVCodecBufferAttr *attr)](#oh_avbuffer_getbufferattr) | 获取数据缓冲区的pts、size、offset、flags高频属性参数。 |
| [OH_AVErrCode OH_AVBuffer_SetBufferAttr(OH_AVBuffer *buffer, const OH_AVCodecBufferAttr *attr)](#oh_avbuffer_setbufferattr) | 设置数据缓冲区的pts、size、offset、flags高频属性参数。 |
| [OH_AVFormat *OH_AVBuffer_GetParameter(OH_AVBuffer *buffer)](#oh_avbuffer_getparameter) | 获取除基础属性外的其他参数，信息在OH_AVFormat中承载。需要注意的是，返回值指向的创建OH_AVFormat的实例需要开发者主动释放，请参阅[OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy)。 |
| [OH_AVErrCode OH_AVBuffer_SetParameter(OH_AVBuffer *buffer, const OH_AVFormat *format)](#oh_avbuffer_setparameter) | 设置除基础属性外的其他参数，信息在OH_AVFormat中承载。 |
| [uint8_t *OH_AVBuffer_GetAddr(OH_AVBuffer *buffer)](#oh_avbuffer_getaddr) | 获取数据缓冲区的虚拟地址。 |
| [int32_t OH_AVBuffer_GetCapacity(OH_AVBuffer *buffer)](#oh_avbuffer_getcapacity) | 获取数据缓冲区的容量（字节数）。 |
| [OH_NativeBuffer *OH_AVBuffer_GetNativeBuffer(OH_AVBuffer *buffer)](#oh_avbuffer_getnativebuffer) | 获取OH_NativeBuffer实例的指针。需要注意的是，返回值指向的创建OH_NativeBuffer的实例需要开发者主动调用接口释放，请参阅{@link OH_NativeBuffer_Unreference}。 |

## 函数说明

### OH_AVBuffer_Create()

```
OH_AVBuffer *OH_AVBuffer_Create(int32_t capacity)
```

**描述**

创建OH_AVBuffer实例。需要注意的是，返回值指向的创建OH_AVBuffer的实例需要开发者主动调用接口释放，请参阅[OH_AVBuffer_Destroy](#oh_avbuffer_destroy)。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t capacity | 创建内存的大小，单位字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) * | 如果创建成功，则返回OH_AVBuffer实例的指针，如果失败，则返回NULL。<br> 可能的失败原因：<br> 1.capacity <= 0。<br> 2.出现内部错误，系统没有资源等。 |

### OH_AVBuffer_Destroy()

```
OH_AVErrCode OH_AVBuffer_Destroy(OH_AVBuffer *buffer)
```

**描述**

释放OH_AVBuffer实例指针的资源，同一个buffer不允许重复销毁。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | 指向OH_AVBuffer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：操作成功。<br> AV_ERR_INVALID_VAL：输入的buffer为空指针或者buffer格式校验失败。<br> AV_ERR_OPERATE_NOT_PERMIT：输入的buffer不是用户创建的。 |

### OH_AVBuffer_GetBufferAttr()

```
OH_AVErrCode OH_AVBuffer_GetBufferAttr(OH_AVBuffer *buffer, OH_AVCodecBufferAttr *attr)
```

**描述**

获取数据缓冲区的pts、size、offset、flags高频属性参数。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | 指向OH_AVBuffer实例的指针。 |
| [OH_AVCodecBufferAttr](capi-core-oh-avcodecbufferattr.md) *attr | 指向OH_AVCodecBufferAttr实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：操作成功。<br> AV_ERR_INVALID_VAL：可能的原因：<br> 1. 输入的buffer或attr为空指针。<br> 2. buffer结构校验失败。 |

### OH_AVBuffer_SetBufferAttr()

```
OH_AVErrCode OH_AVBuffer_SetBufferAttr(OH_AVBuffer *buffer, const OH_AVCodecBufferAttr *attr)
```

**描述**

设置数据缓冲区的pts、size、offset、flags高频属性参数。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | 指向OH_AVBuffer实例的指针。 |
| [const OH_AVCodecBufferAttr](capi-core-oh-avcodecbufferattr.md) *attr | 指向OH_AVCodecBufferAttr实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：操作成功。<br> AV_ERR_INVALID_VAL：可能的原因：<br> 1. 输入的buffer或attr为空指针。<br> 2. buffer结构校验失败。<br> 3. 输入buffer中内存的size或offset是无效值。 |

### OH_AVBuffer_GetParameter()

```
OH_AVFormat *OH_AVBuffer_GetParameter(OH_AVBuffer *buffer)
```

**描述**

获取除基础属性外的其他参数，信息在OH_AVFormat中承载。需要注意的是，返回值指向的创建OH_AVFormat的实例需要开发者主动释放，请参阅[OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy)。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | 指向OH_AVBuffer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | AV_ERR_OK：操作成功。<br> AV_ERR_INVALID_VAL：可能的原因：<br> 1. 输入的buffer为空指针。<br> 2. 输入buffer的meta为空指针。<br> 3. buffer结构校验失败。 |

### OH_AVBuffer_SetParameter()

```
OH_AVErrCode OH_AVBuffer_SetParameter(OH_AVBuffer *buffer, const OH_AVFormat *format)
```

**描述**

设置除基础属性外的其他参数，信息在OH_AVFormat中承载。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | 指向OH_AVBuffer实例的指针。 |
| [const OH_AVFormat](capi-core-oh-avformat.md) *format | 指向OH_AVFormat实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：操作成功。<br> AV_ERR_INVALID_VAL：可能的原因：<br> 1. 输入的buffer或format为空指针。<br> 2. 输入buffer的meta为空指针。<br> 3. buffer结构校验失败。 |

### OH_AVBuffer_GetAddr()

```
uint8_t *OH_AVBuffer_GetAddr(OH_AVBuffer *buffer)
```

**描述**

获取数据缓冲区的虚拟地址。

不同场景下，对是否可以获取虚拟地址的支持情况不同，请见表格：

**编码：**

| 模式 | 填充数据的方式 |  是否可以获取虚拟地址 |
| --------------- | -------- | -------- |
| Surface模式 | OnNeedInputBuffer输入  | × |
| Surface模式 | OnNewOutputBuffer输出  | √ |
| Buffer模式  | OnNeedInputBuffer输入  | √ |
| Buffer模式  | OnNewOutputBuffer输出  | √ |

**解码：**

| 模式 | 填充数据的方式 |  是否可以获取虚拟地址 |
| --------------- | -------- | -------- |
| Surface模式 | OnNeedInputBuffer输入  | √ |
| Surface模式 | OnNewOutputBuffer输出  | × |
| Buffer模式  | OnNeedInputBuffer输入  | √ |
| Buffer模式  | OnNewOutputBuffer输出  | √ |

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | 指向OH_AVBuffer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint8_t * | 如果成功，则返回数据缓冲区的虚拟地址，如果失败，则返回NULL。<br> 可能的失败原因：<br> 1.输入的buffer为空指针。<br> 2.OH_AVBuffer结构校验失败。<br> 3.出现内部错误。 |

### OH_AVBuffer_GetCapacity()

```
int32_t OH_AVBuffer_GetCapacity(OH_AVBuffer *buffer)
```

**描述**

获取数据缓冲区的容量（字节数）。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | 指向OH_AVBuffer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果成功，则返回数据缓冲区的容量，如果失败，则返回-1。<br> 可能的失败原因：<br> 1.输入的buffer为空指针。<br> 2.OH_AVBuffer结构校验失败。<br> 3.出现内部错误。 |

### OH_AVBuffer_GetNativeBuffer()

```
OH_NativeBuffer *OH_AVBuffer_GetNativeBuffer(OH_AVBuffer *buffer)
```

**描述**

获取OH_NativeBuffer实例的指针。需要注意的是，返回值指向的创建OH_NativeBuffer的实例需要开发者主动调用接口释放，请参阅[OH_NativeBuffer_Unreference](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_unreference)。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | 指向OH_AVBuffer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NativeBuffer](capi-core-oh-nativebuffer.md) * | 如果成功，则返回OH_NativeBuffer实例的指针，如果失败，则返回NULL。<br> 可能的失败原因：<br> 1.输入的buffer为空指针。<br> 2.OH_AVBuffer结构校验失败。<br> 3.出现内部错误。 |


