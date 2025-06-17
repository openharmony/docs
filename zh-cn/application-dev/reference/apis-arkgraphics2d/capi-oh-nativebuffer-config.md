# OH_NativeBuffer_Config

## 概述

OH_NativeBuffer的属性配置，用于申请新的OH_NativeBuffer实例或查询现有实例的相关属性。

**起始版本：** 9

**相关模块：** [OH_NativeBuffer](capi-oh-nativebuffer.md)

**所在头文件：** [native_buffer.h](capi-native-buffer-h.md)

## 汇总

### 成员变量

| 名称           | 描述                                                         |
| -------------- | ------------------------------------------------------------ |
| int32_t width  | 宽度（像素）。                                               |
| int32_t height | 高度（像素）。                                               |
| int32_t format | 像素格式，具体可参见[OH_NativeBuffer_Format](capi-native-buffer-h.md#oh_nativebuffer_format)枚举。 |
| int32_t usage  | buffer的用途说明，具体可参见[OH_NativeBuffer_Usage](capi-native-buffer-h.md#oh_nativebuffer_usage)枚举。 |
| int32_t stride | 输出参数。本地窗口缓冲区步幅，单位为Byte。<br/>**起始版本：** 10 |

