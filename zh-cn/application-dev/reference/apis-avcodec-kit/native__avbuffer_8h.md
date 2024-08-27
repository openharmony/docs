# native_avbuffer.h


## 概述

声明了媒体数据结构AVBuffer的函数接口。

**库：** libnative_media_core.so

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

**相关模块：**[Core](_core.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVBuffer](_core.md#oh_avbuffer) [OH_AVBuffer](_core.md#oh_avbuffer) | 为媒体内存接口定义native层对象。  | 
| typedef struct [OH_NativeBuffer](_core.md#oh_nativebuffer) [OH_NativeBuffer](_core.md#oh_nativebuffer) | 为图形内存接口定义native层对象。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| OH_AVBuffer \* [OH_AVBuffer_Create](_core.md#oh_avbuffer_create) (int32_t capacity) | 创建OH_AVBuffer实例。 需要注意的是，返回值指向的创建OH_AVBuffer的实例需要调用者手动释放，请参阅[OH_AVBuffer_Destroy](_core.md#oh_avbuffer_destroy)。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVBuffer_Destroy](_core.md#oh_avbuffer_destroy) (OH_AVBuffer \*buffer) | 释放OH_AVBuffer实例指针的资源。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVBuffer_GetBufferAttr](_core.md#oh_avbuffer_getbufferattr) (OH_AVBuffer \*buffer, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr) | 获取数据缓冲区的pts、size、offset、flags高频属性参数。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVBuffer_SetBufferAttr](_core.md#oh_avbuffer_setbufferattr) (OH_AVBuffer \*buffer, const [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr) | 设置数据缓冲区的pts、size、offset、flags高频属性参数。 | 
| OH_AVFormat \* [OH_AVBuffer_GetParameter](_core.md#oh_avbuffer_getparameter) (OH_AVBuffer \*buffer) | 获取除基础属性外的其他参数，信息在OH_AVFormat中承载。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVBuffer_SetParameter](_core.md#oh_avbuffer_setparameter) (OH_AVBuffer \*buffer, const OH_AVFormat \*format) | 设置除基础属性外的其他参数，信息在OH_AVFormat中承载。 | 
| uint8_t \* [OH_AVBuffer_GetAddr](_core.md#oh_avbuffer_getaddr) (OH_AVBuffer \*buffer) | 获取数据缓冲区的虚拟地址。 | 
| int32_t [OH_AVBuffer_GetCapacity](_core.md#oh_avbuffer_getcapacity) (OH_AVBuffer \*buffer) | 获取数据缓冲区的容量（字节数）。 | 
| OH_NativeBuffer \* [OH_AVBuffer_GetNativeBuffer](_core.md#oh_avbuffer_getnativebuffer) (OH_AVBuffer \*buffer) | 获取OH_NativeBuffer实例的指针。 | 
