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
| [OhosPixelMapInfo](_ohos_pixel_map_info.md) | 用于定义 pixel map 的相关信息。 |


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| { OHOS_IMAGE_RESULT_SUCCESS = 0, OHOS_IMAGE_RESULT_BAD_PARAMETER = -1 } | 函数方法返回值的错误码的枚举。  | 
| { OHOS_PIXEL_MAP_FORMAT_NONE = 0, OHOS_PIXEL_MAP_FORMAT_RGBA_8888 = 3, OHOS_PIXEL_MAP_FORMAT_RGB_565 = 2 } | pixel 格式的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_GetImageInfo](image.md#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_ohos_pixel_map_info.md) \*info) | 获取 **PixelMap** 的信息，并记录信息到[OhosPixelMapInfo](_ohos_pixel_map_info.md)结构中。  | 
| [OH_AccessPixels](image.md#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | 获取**PixelMap**对象数据的内存地址，并锁定该内存。  | 
| [OH_UnAccessPixels](image.md#oh_unaccesspixels) (napi_env env, napi_value value) | 释放**PixelMap**对象数据的内存锁, 用于匹配方法[OH_AccessPixels](image.md#oh_accesspixels)。  | 

