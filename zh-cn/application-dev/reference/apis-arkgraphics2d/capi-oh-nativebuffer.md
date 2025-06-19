# OH_NativeBuffer

## 概述

提供NativeBuffer功能，通过提供的接口，可以实现共享内存的申请、使用、属性查询、释放等操作。

**起始版本：** 9

## 文件汇总

| 名称                                       | 描述                                                         |
| ------------------------------------------ | ------------------------------------------------------------ |
| [buffer_common.h](capi-buffer-common-h.md) | 提供NativeBuffer模块的公共类型定义。<br>从API version 12开始，部分类型定义从native_buffer.h移动至此头文件统一呈现，对于此类类型，API version 12之前即支持使用，各版本均可正常使用。<br>引用文件：<native_buffer/buffer_common.h> |
| [native_buffer.h](capi-native-buffer-h.md) | 定义获取和使用NativeBuffer的相关函数。<br/>引用文件：<native_buffer/native_buffer.h> |