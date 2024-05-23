# image_common.h


## 概述

声明图像接口使用的公共枚举和结构体。

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 12

**相关模块：**[Image_NativeModule](_image___native_module.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [Image_Size](_image___size.md) | 图像大小结构体。 | 
| struct  [Image_Region](_image___region.md) | 待解码的图像源区域结构体。 | 
| struct  [Image_String](_image___string.md) | 字符串结构。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Image_Size](_image___size.md) [Image_Size](_image___native_module.md#image_size) | 声明图像大小结构。 | 
| typedef struct [Image_Region](_image___region.md) [Image_Region](_image___native_module.md#image_region) | 声明要解码的图像源区域结构体类型名称。 | 
| typedef struct [Image_String](_image___string.md) [Image_String](_image___native_module.md#image_string) | 声明字符串结构的名称。 | 
| typedef struct [Image_String](_image___string.md) [Image_MimeType](_image___native_module.md#image_mimetype) | 声明一个图片格式类型的名称。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) {<br/>IMAGE_SUCCESS = 0,<br/>IMAGE_BAD_PARAMETER = 401,<br/>IMAGE_UNSUPPORTED_MIME_TYPE = 7600101,<br/>IMAGE_UNKNOWN_MIME_TYPE = 7600102,<br/>IMAGE_TOO_LARGE = 7600103,<br/>IMAGE_UNSUPPORTED_OPERATION = 7600201,<br/>IMAGE_UNSUPPORTED_METADATA = 7600202,<br/>IMAGE_UNSUPPORTED_CONVERSION = 7600203,<br/>IMAGE_INVALID_REGION = 7600204,<br/>IMAGE_ALLOC_FAILED = 7600301,<br/>IMAGE_COPY_FAILED = 7600302,<br/>IMAGE_UNKNOWN_ERROR = 7600901,<br/>IMAGE_BAD_SOURCE = 7700101,<br/>IMAGE_DECODE_FAILED = 7700301,<br/>IMAGE_ENCODE_FAILED = 7800301<br/>} | 错误码。 | 
