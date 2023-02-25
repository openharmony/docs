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
| [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) | 用于定义创建 pixel map 设置选项的相关信息。 | 

### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [NativePixelMap](image.md#nativepixelmap) | 用于定义NativePixelMap数据类型名称。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| { OHOS_IMAGE_RESULT_SUCCESS = 0, OHOS_IMAGE_RESULT_BAD_PARAMETER = -1 } | 函数方法返回值的错误码的枚举。  | 
| { OHOS_PIXEL_MAP_FORMAT_NONE = 0, OHOS_PIXEL_MAP_FORMAT_RGBA_8888 = 3, OHOS_PIXEL_MAP_FORMAT_RGB_565 = 2 } | pixel 格式的枚举。 | 
| { OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN = 0, OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE = 1, OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL = 2, OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL = 3 } | PixelMap alpha 类型的枚举。 | 
| { OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE = 0, OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP = 1 } | PixelMap 缩放类型的枚举。 | 
| { OHOS_PIXEL_MAP_READ_ONLY = 0, OHOS_PIXEL_MAP_EDITABLE = 1 } | PixelMap 编辑类型的枚举。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_GetImageInfo](image.md#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_ohos_pixel_map_info.md) \*info) | 获取 **PixelMap** 的信息，并记录信息到[OhosPixelMapInfo](_ohos_pixel_map_info.md)结构中。  | 
| [OH_AccessPixels](image.md#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | 获取**PixelMap**对象数据的内存地址，并锁定该内存。  | 
| [OH_UnAccessPixels](image.md#oh_unaccesspixels) (napi_env env, napi_value value) | 释放**PixelMap**对象数据的内存锁, 用于匹配方法[OH_AccessPixels](image.md#oh_accesspixels)。  | 
| [OH_PixelMap_CreatePixelMap](image.md#oh_pixelmap_createpixelmap) (napi_env env, [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) info, void \*buf, size_t len, napi_value \*res) | 创建**PixelMap**对象。 | 
| [OH_PixelMap_CreateAlphaPixelMap](image.md#oh_pixelmap_createalphapixelmap) (napi_env env, napi_value source, napi_value \*alpha) | 根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的**PixelMap**对象。  | 
| [OH_PixelMap_InitNativePixelMap](image.md#oh_pixelmap_initnativepixelmap) (napi_env env, napi_value source) | 初始化**PixelMap**对象数据。  | 
| [OH_PixelMap_GetBytesNumberPerRow](image.md#oh_pixelmap_getbytesnumberperrow) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*num) | 获取**PixelMap**对象每行字节数。  | 
| [OH_PixelMap_GetIsEditable](image.md#oh_pixelmap_getiseditable) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*[editable](#editable)) | 获取**PixelMap**对象是否可编辑的状态。 | 
| [OH_PixelMap_IsSupportAlpha](image.md#oh_pixelmap_issupportalpha) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*alpha) | 获取**PixelMap**对象是否支持Alpha通道。 | 
| [OH_PixelMap_SetAlphaAble](image.md#oh_pixelmap_setalphaable) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t alpha) | 设置**PixelMap**对象的Alpha通道。  | 
| [OH_PixelMap_GetDensity](image.md#oh_pixelmap_getdensity) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*density) | 获取**PixelMap**对象像素密度。  | 
| [OH_PixelMap_SetDensity](image.md#oh_pixelmap_setdensity) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t density) | 设置**PixelMap**对象像素密度。  | 
| [OH_PixelMap_SetOpacity](image.md#oh_pixelmap_setopacity) (const [NativePixelMap](image.md#nativepixelmap) \*native, float opacity) | 设置**PixelMap**对象的透明度。  | 
| [OH_PixelMap_Scale](image.md#oh_pixelmap_scale) (const [NativePixelMap](image.md#nativepixelmap) \*native, float x, float y) | 设置**PixelMap**对象的缩放。  | 
| [OH_PixelMap_Translate](image.md#oh_pixelmap_translate) (const [NativePixelMap](image.md#nativepixelmap) \*native, float x, float y) | 设置**PixelMap**对象的偏移。  | 
| [OH_PixelMap_Rotate](image.md#oh_pixelmap_rotate) (const [NativePixelMap](image.md#nativepixelmap) \*native, float angle) | 设置**PixelMap**对象的旋转。 | 
| [OH_PixelMap_Flip](image.md#oh_pixelmap_flip) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t x, int32_t y) | 设置**PixelMap**对象的翻转。 | 
| [OH_PixelMap_Crop](image.md#oh_pixelmap_crop) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t x, int32_t y, int32_t [width](#width), int32_t [height](#height)) | 设置**PixelMap**对象的裁剪。 | 

### 变量

| 名称 | 描述 | 
| -------- | -------- |
| [width](#width) | 图片的宽, 用pixels表示。|
| [height](#height) | 图片的高, 用pixels表示。|
| [pixelFormat](#pixelformat) | 图片的格式。|
| [editable](#editable) | 图片的编辑类型。|
| [alphaType](#alphatype) | 图片的alpha类型。|
| [scaleMode](#scalemode) | 图片的缩放类型。|

## 变量说明


### alphaType

  
```
uint32_t alphaType
```
**描述:**
图片的alpha类型。


### editable

  
```
uint32_t editable
```
**描述:**
图片的编辑类型。


### height

  
```
uint32_t height
```
**描述:**
图片的高, 用pixels表示。


### pixelFormat

  
```
int32_t pixelFormat
```
**描述:**
图片的格式。


### scaleMode

  
```
uint32_t scaleMode
```
**描述:**
图片的缩放类型。


### width

  
```
uint32_t width
```
**描述:**
图片的宽, 用pixels表示。

