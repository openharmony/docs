# native_buffer.h


## 概述

定义获取和使用NativeBuffer的相关函数

**起始版本:**

9

**相关模块:**

[OH_NativeBuffer](_o_h___native_buffer.md)


## 汇总


### 结构体

| 结构体名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) | OH_NativeBuffer的属性配置，用于申请新的OH_NativeBuffer实例或查询现有实例的相关属性 |


### 类型定义

| 类型名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) | 提供OH_NativeBuffer结构体声明 |

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer_Usage](_o_h___native_buffer.md#oh_nativebuffer_usage) { NATIVEBUFFER_USAGE_CPU_READ = (1ULL &lt;&lt; 0), NATIVEBUFFER_USAGE_CPU_WRITE = (1ULL &lt;&lt; 1), NATIVEBUFFER_USAGE_MEM_DMA = (1ULL &lt;&lt; 3) } | OH_NativeBuffer的用途。 |
| [OH_NativeBuffer_Format](_o_h___native_buffer.md#oh_nativebuffer_format) {<br/>NATIVEBUFFER_PIXEL_FMT_RGB_565 = 3, NATIVEBUFFER_PIXEL_FMT_RGBA_5658, NATIVEBUFFER_PIXEL_FMT_RGBX_4444, NATIVEBUFFER_PIXEL_FMT_RGBA_4444,<br/>NATIVEBUFFER_PIXEL_FMT_RGB_444, NATIVEBUFFER_PIXEL_FMT_RGBX_5551, NATIVEBUFFER_PIXEL_FMT_RGBA_5551, NATIVEBUFFER_PIXEL_FMT_RGB_555,<br/>NATIVEBUFFER_PIXEL_FMT_RGBX_8888, NATIVEBUFFER_PIXEL_FMT_RGBA_8888, NATIVEBUFFER_PIXEL_FMT_RGB_888, NATIVEBUFFER_PIXEL_FMT_BGR_565,<br/>NATIVEBUFFER_PIXEL_FMT_BGRX_4444, NATIVEBUFFER_PIXEL_FMT_BGRA_4444, NATIVEBUFFER_PIXEL_FMT_BGRX_5551, NATIVEBUFFER_PIXEL_FMT_BGRA_5551,<br/>NATIVEBUFFER_PIXEL_FMT_BGRX_8888, NATIVEBUFFER_PIXEL_FMT_BGRA_8888, NATIVEBUFFER_PIXEL_FMT_BUTT = 0X7FFFFFFF<br/>} | OH_NativeBuffer的格式。 |

### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer_Alloc](_o_h___native_buffer.md#oh_nativebuffer_alloc) (const OH_NativeBuffer_Config \*config) | 通过OH_NativeBuffer_Config创建OH_NativeBuffer实例，每次调用都会产生一个新的OH_NativeBuffer实例 |
| [OH_NativeBuffer_Reference](_o_h___native_buffer.md#oh_nativebuffer_reference) (OH_NativeBuffer \*buffer) | 将OH_NativeBuffer对象的引用计数加1 |
| [OH_NativeBuffer_Unreference](_o_h___native_buffer.md#oh_nativebuffer_unreference) (OH_NativeBuffer \*buffer) | 将OH_NativeBuffer对象的引用计数减1，当引用计数为0的时候，该NativeBuffer对象会被析构掉 |
| [OH_NativeBuffer_GetConfig](_o_h___native_buffer.md#oh_nativebuffer_getconfig) (OH_NativeBuffer \*buffer, OH_NativeBuffer_Config \*config) | 用于获取OH_NativeBuffer的属性 |
| [OH_NativeBuffer_Map](_o_h___native_buffer.md#oh_nativebuffer_map) (OH_NativeBuffer \*buffer, void \*\*virAddr) | 将OH_NativeBuffer对应的ION内存映射到进程空间 |
| [OH_NativeBuffer_Unmap](_o_h___native_buffer.md#oh_nativebuffer_unmap) (OH_NativeBuffer \*buffer) | 将OH_NativeBuffer对应的ION内存从进程空间移除 |
| [OH_NativeBuffer_GetSeqNum](_o_h___native_buffer.md#oh_nativebuffer_getseqnum) (OH_NativeBuffer \*buffer) | 获取OH_NativeBuffer的序列号 |
