# image_pixel_map_mdk.h


## 概述

声明可以锁定并访问pixelmap数据的方法，声明解锁的方法。 Need link **libpixelmapndk.z.so**

**起始版本：**

10

**相关模块：**

[Image](image.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OhosPixelMapInfos](_ohos_pixel_map_infos.md) | 用于定义 pixel map 的相关信息。 | 
| [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) | 用于定义创建 pixel map 设置选项的相关信息。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [NativePixelMap](image.md#nativepixelmap) | 定义native层pixelmap数据类型名称。 | 
| [OhosPixelMapInfos](image.md#ohospixelmapinfos) | 用于定义 pixel map 的相关信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| { [OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN](image.md#anonymous-enum-23) = 0,<br/>[OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE](image.md#anonymous-enum-23) = 1,<br/>[OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL](image.md#anonymous-enum-23) = 2,<br/>[OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL](image.md#anonymous-enum-23) = 3 } | PixelMap 透明度类型的枚举。 | 
| { [OHOS_PIXEL_MAP_READ_ONLY](image.md#anonymous-enum-23-1) = 0,<br/>[OHOS_PIXEL_MAP_EDITABLE](image.md#anonymous-enum-23-1) = 1 } | PixelMap 编辑类型的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_PixelMap_CreatePixelMap](image.md#oh_pixelmap_createpixelmap) (napi_env env, [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) info, void \*buf, size_t len, napi_value \*res) | 创建**PixelMap**对象。 | 
| [OH_PixelMap_CreateAlphaPixelMap](image.md#oh_pixelmap_createalphapixelmap) (napi_env env, napi_value source, napi_value \*alpha) | 根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的**PixelMap**对象。 | 
| [OH_PixelMap_InitNativePixelMap](image.md#oh_pixelmap_initnativepixelmap) (napi_env env, napi_value source) | 初始化**PixelMap**对象数据。 | 
| [OH_PixelMap_GetBytesNumberPerRow](image.md#oh_pixelmap_getbytesnumberperrow) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*num) | 获取**PixelMap**对象每行字节数。 | 
| [OH_PixelMap_GetIsEditable](image.md#oh_pixelmap_getiseditable) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*editable) | 获取**PixelMap**对象是否可编辑的状态。 | 
| [OH_PixelMap_IsSupportAlpha](image.md#oh_pixelmap_issupportalpha) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*alpha) | 获取**PixelMap**对象是否支持Alpha通道。 | 
| [OH_PixelMap_SetAlphaAble](image.md#oh_pixelmap_setalphaable) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t alpha) | 设置**PixelMap**对象的Alpha通道。 | 
| [OH_PixelMap_GetDensity](image.md#oh_pixelmap_getdensity) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*density) | 获取**PixelMap**对象像素密度。 | 
| [OH_PixelMap_SetDensity](image.md#oh_pixelmap_setdensity) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t density) | 设置**PixelMap**对象像素密度。 | 
| [OH_PixelMap_SetOpacity](image.md#oh_pixelmap_setopacity) (const [NativePixelMap](image.md#nativepixelmap) \*native, float opacity) | 设置**PixelMap**对象的透明度。 | 
| [OH_PixelMap_Scale](image.md#oh_pixelmap_scale) (const [NativePixelMap](image.md#nativepixelmap) \*native, float x, float y) | 设置**PixelMap**对象的缩放。 | 
| [OH_PixelMap_Translate](image.md#oh_pixelmap_translate) (const [NativePixelMap](image.md#nativepixelmap) \*native, float x, float y) | 设置**PixelMap**对象的偏移。 | 
| [OH_PixelMap_Rotate](image.md#oh_pixelmap_rotate) (const [NativePixelMap](image.md#nativepixelmap) \*native, float angle) | 设置**PixelMap**对象的旋转。 | 
| [OH_PixelMap_Flip](image.md#oh_pixelmap_flip) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t x, int32_t y) | 设置**PixelMap**对象的翻转。 | 
| [OH_PixelMap_Crop](image.md#oh_pixelmap_crop) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t x, int32_t y, int32_t width, int32_t height) | 设置**PixelMap**对象的裁剪。 | 
| [OH_PixelMap_GetImageInfo](image.md#oh_pixelmap_getimageinfo) (const [NativePixelMap](image.md#nativepixelmap) \*native, [OhosPixelMapInfos](_ohos_pixel_map_infos.md) \*info) | 获取**PixelMap**对象图像信息。 | 
| [OH_PixelMap_AccessPixels](image.md#oh_pixelmap_accesspixels) (const [NativePixelMap](image.md#nativepixelmap) \*native, void \*\*addr) | 获取native **PixelMap** 对象数据的内存地址，并锁定该内存。 | 
| [OH_PixelMap_UnAccessPixels](image.md#oh_pixelmap_unaccesspixels) (const [NativePixelMap](image.md#nativepixelmap) \*native) | 释放native **PixelMap**对象数据的内存锁，用于匹配方法 [OH_PixelMap_AccessPixels](image.md#oh_pixelmap_accesspixels)。 | 
<!--no_check-->
