# image_pixel_map_napi.h


## 概述

声明可以锁定并访问pixelmap数据的方法，声明解锁的方法。

**起始版本：**

8

**相关模块：**

[Image](image.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OHOS::Media::OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) | 用于定义 pixel map 的相关信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| { [OHOS::Media::OHOS_IMAGE_RESULT_SUCCESS](image.md#anonymous-enum-33) = 0,<br/>[OHOS::Media::OHOS_IMAGE_RESULT_BAD_PARAMETER](image.md#anonymous-enum-33) = -1 } | 函数方法返回值的错误码的枚举。 | 
| { [OHOS::Media::OHOS_PIXEL_MAP_FORMAT_NONE](image.md#anonymous-enum-33-1) = 0,<br/>[OHOS::Media::OHOS_PIXEL_MAP_FORMAT_RGBA_8888](image.md#anonymous-enum-33-1) = 3,<br/>[OHOS::Media::OHOS_PIXEL_MAP_FORMAT_RGB_565](image.md#anonymous-enum-33-1) = 2 } | pixel 格式的枚举。 | 
| { [OHOS::Media::OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE](image.md#anonymous-enum) = 0,<br/>[OHOS::Media::OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP](image.md#anonymous-enum) = 1 } | PixelMap 缩放类型的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OHOS::Media::OH_GetImageInfo](image.md#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) \*info) | 获取 **PixelMap** 的信息，并记录信息到[OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md)结构中。 | 
| [OHOS::Media::OH_AccessPixels](image.md#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | 获取**PixelMap**对象数据的内存地址，并锁定该内存。 | 
| [OHOS::Media::OH_UnAccessPixels](image.md#oh_unaccesspixels) (napi_env env, napi_value value) | 释放**PixelMap**对象数据的内存锁, 用于匹配方法**OH_AccessPixels**。 | 
<!--no_check-->