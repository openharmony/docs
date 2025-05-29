# image_pixel_map_napi.h


## 概述

声明可以锁定、访问、解锁PixelMap数据的方法。

**库**：libpixelmap_ndk.z.so

**引用文件**：&lt;multimedia/image_framework/image_pixel_map_napi.h&gt;

**起始版本：** 8

**废弃版本：** 10

**废弃替代：** [image_pixel_map_mdk.h](image__pixel__map__mdk_8h.md)

**相关模块：** [Image](image.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) | 用于定义 pixel map 的相关信息。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| { [OHOS_IMAGE_RESULT_SUCCESS](image.md#方法返回的错误码) = 0,<br/>[OHOS_IMAGE_RESULT_BAD_PARAMETER](image.md#方法返回的错误码) = -1 } | 函数方法返回值的错误码的枚举。 | 
| { [OHOS_PIXEL_MAP_FORMAT_NONE](image.md#像素格式) = 0,<br/>[OHOS_PIXEL_MAP_FORMAT_RGBA_8888](image.md#像素格式) = 3,<br/>[OHOS_PIXEL_MAP_FORMAT_RGB_565](image.md#像素格式) = 2 } | Pixel格式的枚举。 | 
| { [OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE](image.md#anonymous-enum) = 0,<br/>[OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP](image.md#anonymous-enum) = 1 } | PixelMap缩放类型的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_GetImageInfo](image.md#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) \*info) | 获取 **PixelMap** 的信息，并记录信息到[OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md)结构中。  | 
| int32_t [OH_AccessPixels](image.md#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | 获取**PixelMap**对象数据的内存地址，并锁定该内存。  | 
| int32_t [OH_UnAccessPixels](image.md#oh_unaccesspixels) (napi_env env, napi_value value) | 释放**PixelMap**对象数据的内存锁，用于匹配方法**OH_AccessPixels**。  | 
