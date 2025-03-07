# image_pixel_map_mdk.h


## 概述

声明可以锁定并访问PixelMap数据的方法，声明解锁的方法。

**库**：libpixelmap_ndk.z.so

**引用文件**：&lt;multimedia/image_framework/image_pixel_map_mdk.h&gt;

**起始版本：** 10

**相关模块：** [Image](image.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OhosPixelMapInfos](_ohos_pixel_map_infos.md) | 用于定义PixelMap的相关信息。  | 
| struct  [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) | 用于定义创建PixelMap设置选项的相关信息。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct NativePixelMap_ [NativePixelMap](image.md#nativepixelmap) | 定义native层PixelMap数据类型名称。  | 
| typedef struct [OhosPixelMapInfos](_ohos_pixel_map_infos.md) [OhosPixelMapInfos](image.md#ohospixelmapinfos) | 用于定义PixelMap的相关信息。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| { [OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN](image.md#pixelmap透明度类型) = 0,<br/>[OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE](image.md#pixelmap透明度类型) = 1,<br/>[OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL](image.md#pixelmap透明度类型) = 2,<br/>[OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL](image.md#pixelmap透明度类型) = 3 } | PixelMap透明度类型的枚举。 | 
| { [OHOS_PIXEL_MAP_READ_ONLY](image.md#pixelmap-编辑类型) = 0,<br/>[OHOS_PIXEL_MAP_EDITABLE](image.md#pixelmap-编辑类型) = 1 } | PixelMap编辑类型的枚举。 | 
| [OH_PixelMap_AntiAliasingLevel](image.md#oh_pixelmap_antialiasinglevel) { <br/>OH_PixelMap_AntiAliasing_NONE = 0, <br/>OH_PixelMap_AntiAliasing_LOW = 1, <br/>OH_PixelMap_AntiAliasing_MEDIUM = 2, <br/>OH_PixelMap_AntiAliasing_HIGH = 3 <br/>} | Pixelmap缩放时采用的缩放算法。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_PixelMap_CreatePixelMap](image.md#oh_pixelmap_createpixelmap) (napi_env env, [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) info, void \*buf, size_t len, napi_value \*res) | 创建**PixelMap**对象。  | 
| int32_t [OH_PixelMap_CreatePixelMapWithStride](image.md#oh_pixelmap_createpixelmapwithstride) (napi_env env, [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) info, void \*buf, size_t len, int32_t rowStride, napi_value \*res) | 创建**PixelMap**对象。当前只支持输入流为BGRA格式的流。PixelMap内存在RGBA格式下，默认为DMA内存（图片512\*512以上）。  | 
| int32_t [OH_PixelMap_CreateAlphaPixelMap](image.md#oh_pixelmap_createalphapixelmap) (napi_env env, napi_value source, napi_value \*alpha) | 根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的**PixelMap**对象。  | 
| [NativePixelMap](image.md#nativepixelmap) \* [OH_PixelMap_InitNativePixelMap](image.md#oh_pixelmap_initnativepixelmap) (napi_env env, napi_value source) | 初始化**NativePixelMap**对象。  | 
| int32_t [OH_PixelMap_GetBytesNumberPerRow](image.md#oh_pixelmap_getbytesnumberperrow) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*num) | 获取**PixelMap**对象每行字节数。  | 
| int32_t [OH_PixelMap_GetIsEditable](image.md#oh_pixelmap_getiseditable) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*editable) | 获取**PixelMap**对象是否可编辑的状态。  | 
| int32_t [OH_PixelMap_IsSupportAlpha](image.md#oh_pixelmap_issupportalpha) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*alpha) | 获取**PixelMap**对象是否支持Alpha通道。  | 
| int32_t [OH_PixelMap_SetAlphaAble](image.md#oh_pixelmap_setalphaable) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t alpha) | 设置**PixelMap**对象的Alpha通道。  | 
| int32_t [OH_PixelMap_GetDensity](image.md#oh_pixelmap_getdensity) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*density) | 获取**PixelMap**对象像素密度。  | 
| int32_t [OH_PixelMap_SetDensity](image.md#oh_pixelmap_setdensity) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t density) | 设置**PixelMap**对象像素密度。  | 
| int32_t [OH_PixelMap_SetOpacity](image.md#oh_pixelmap_setopacity) (const [NativePixelMap](image.md#nativepixelmap) \*native, float opacity) | 设置**PixelMap**对象的透明度。  | 
| int32_t [OH_PixelMap_Scale](image.md#oh_pixelmap_scale) (const [NativePixelMap](image.md#nativepixelmap) \*native, float x, float y) | 设置**PixelMap**对象的缩放。  | 
| int32_t [OH_PixelMap_ScaleWithAntiAliasing](image.md#oh_pixelmap_scalewithantialiasing) (const [NativePixelMap](image.md#nativepixelmap) \*native, float x, float y, [OH_PixelMap_AntiAliasingLevel](image.md#oh_pixelmap_antialiasinglevel) level) | 根据指定的缩放算法和输入的宽高对图片进行缩放。  | 
| int32_t [OH_PixelMap_Translate](image.md#oh_pixelmap_translate) (const [NativePixelMap](image.md#nativepixelmap) \*native, float x, float y) | 设置**PixelMap**对象的偏移。  | 
| int32_t [OH_PixelMap_Rotate](image.md#oh_pixelmap_rotate) (const [NativePixelMap](image.md#nativepixelmap) \*native, float angle) | 设置**PixelMap**对象的旋转。  | 
| int32_t [OH_PixelMap_Flip](image.md#oh_pixelmap_flip) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t x, int32_t y) | 设置**PixelMap**对象的翻转。  | 
| int32_t [OH_PixelMap_Crop](image.md#oh_pixelmap_crop) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t x, int32_t y, int32_t width, int32_t height) | 设置**PixelMap**对象的裁剪。  | 
| int32_t [OH_PixelMap_GetImageInfo](image.md#oh_pixelmap_getimageinfo) (const [NativePixelMap](image.md#nativepixelmap) \*native, [OhosPixelMapInfos](_ohos_pixel_map_infos.md) \*info) | 获取**PixelMap**对象图像信息。  | 
| int32_t [OH_PixelMap_AccessPixels](image.md#oh_pixelmap_accesspixels) (const [NativePixelMap](image.md#nativepixelmap) \*native, void \*\*addr) | 获取native **PixelMap** 对象数据的内存地址，并锁定该内存。  | 
| int32_t [OH_PixelMap_UnAccessPixels](image.md#oh_pixelmap_unaccesspixels) (const [NativePixelMap](image.md#nativepixelmap) \*native) | 释放native **PixelMap**对象数据的内存锁，用于匹配方法[OH_PixelMap_AccessPixels](image.md#oh_pixelmap_accesspixels)。  | 
