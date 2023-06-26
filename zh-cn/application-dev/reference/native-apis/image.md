# Image


提供获取pixelmap的数据和信息的接口方法。

@Syscap SystemCapability.Multimedia.Image


**起始版本：**


8


## 汇总


### 文件

| 文件名称 | 描述 |
| -------- | -------- |
| [image_pixel_map_napi.h](image__pixel__map__napi_8h.md) | 声明可以锁定并访问pixelmap数据的方法，声明解锁的方法。 <br>**引用文件**：<multimedia/image_framework/image_pixel_map_napi.h> <br>**库**：libpixelmap_ndk.z.so|


### 结构体

| 结构体名称 | 描述 |
| -------- | -------- |
| [OhosPixelMapInfo](_ohos_pixel_map_info.md) | 用于定义 pixel map 的相关信息。 |
| [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) | 用于定义创建 pixel map 设置选项的相关信息。|


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [NativePixelMap](#nativepixelmap) | 用于定义NativePixelMap数据类型名称。|


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| { OHOS_IMAGE_RESULT_SUCCESS = 0, OHOS_IMAGE_RESULT_BAD_PARAMETER = -1 } | 函数方法返回值的错误码的枚举。|
| { OHOS_PIXEL_MAP_FORMAT_NONE = 0, OHOS_PIXEL_MAP_FORMAT_RGBA_8888 = 3, OHOS_PIXEL_MAP_FORMAT_RGB_565 = 2 } | pixel 格式的枚举。|
| { OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN = 0, OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE = 1, OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL = 2, OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL = 3 } | PixelMap alpha 类型的枚举。|
| { OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE = 0, OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP = 1 } | PixelMap 缩放类型的枚举。|
| { OHOS_PIXEL_MAP_READ_ONLY = 0, OHOS_PIXEL_MAP_EDITABLE = 1 } | PixelMap 编辑类型的枚举。|


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_GetImageInfo](#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_ohos_pixel_map_info.md) \*info) | 获取 **PixelMap** 的信息，并记录信息到[OhosPixelMapInfo](_ohos_pixel_map_info.md)结构中。|
| [OH_AccessPixels](#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | 获取**PixelMap**对象数据的内存地址，并锁定该内存。|
| [OH_UnAccessPixels](#oh_unaccesspixels) (napi_env env, napi_value value) | 释放**PixelMap**对象数据的内存锁, 用于匹配方法[OH_AccessPixels](#oh_accesspixels)。|
| [OH_PixelMap_CreatePixelMap](#oh_pixelmap_createpixelmap) (napi_env env, [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) info, void \*buf, size_t len, napi_value \*res) | 创建**PixelMap**对象。|
| [OH_PixelMap_CreateAlphaPixelMap](#oh_pixelmap_createalphapixelmap) (napi_env env, napi_value source, napi_value \*alpha) | 根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的**PixelMap**对象。|
| [OH_PixelMap_InitNativePixelMap](#oh_pixelmap_initnativepixelmap) (napi_env env, napi_value source) | 初始化**PixelMap**对象数据。|
| [OH_PixelMap_GetBytesNumberPerRow](#oh_pixelmap_getbytesnumberperrow) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*num) | 获取**PixelMap**对象每行字节数。|
| [OH_PixelMap_GetIsEditable](#oh_pixelmap_getiseditable) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*[editable](image__pixel__map__napi_8h.md#editable)) | 获取**PixelMap**对象是否可编辑的状态。|
| [OH_PixelMap_IsSupportAlpha](#oh_pixelmap_issupportalpha) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*alpha) | 获取**PixelMap**对象是否支持Alpha通道。|
| [OH_PixelMap_SetAlphaAble](#oh_pixelmap_setalphaable) (const [NativePixelMap](#nativepixelmap) \*native, int32_t alpha) | 设置**PixelMap**对象的Alpha通道。|
| [OH_PixelMap_GetDensity](#oh_pixelmap_getdensity) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*density) | 获取**PixelMap**对象像素密度。|
| [OH_PixelMap_SetDensity](#oh_pixelmap_setdensity) (const [NativePixelMap](#nativepixelmap) \*native, int32_t density) | 设置**PixelMap**对象像素密度。|
| [OH_PixelMap_SetOpacity](#oh_pixelmap_setopacity) (const [NativePixelMap](#nativepixelmap) \*native, float opacity) | 设置**PixelMap**对象的透明度。|
| [OH_PixelMap_Scale](#oh_pixelmap_scale) (const [NativePixelMap](#nativepixelmap) \*native, float x, float y) | 设置**PixelMap**对象的缩放。|
| [OH_PixelMap_Translate](#oh_pixelmap_translate) (const [NativePixelMap](#nativepixelmap) \*native, float x, float y) | 设置**PixelMap**对象的偏移。|
| [OH_PixelMap_Rotate](#oh_pixelmap_rotate) (const [NativePixelMap](#nativepixelmap) \*native, float angle) | 设置**PixelMap**对象的旋转。|
| [OH_PixelMap_Flip](#oh_pixelmap_flip) (const [NativePixelMap](#nativepixelmap) \*native, int32_t x, int32_t y) | 设置**PixelMap**对象的翻转。|
| [OH_PixelMap_Crop](#oh_pixelmap_crop) (const [NativePixelMap](#nativepixelmap) \*native, int32_t x, int32_t y, int32_t [width](image__pixel__map__napi_8h.md#width), int32_t [height](image__pixel__map__napi_8h.md#height)) | 设置**PixelMap**对象的裁剪。|


## 类型定义说明


### NativePixelMap

  
```
typedef struct NativePixelMap
```
**描述:**
用于定义NativePixelMap数据类型名称。

**起始版本：** 
10


## 枚举类型说明


### anonymous enum

  
```
anonymous enum
```
**描述:**
函数方法返回值的错误码的枚举。

| 枚举值 | 描述 | 
| -------- | -------- |
| OHOS_IMAGE_RESULT_SUCCESS| 成功的结果 | 
| OHOS_IMAGE_RESULT_BAD_PARAMETER| 无效值 | 

**起始版本：**
8

### anonymous enum

  
```
anonymous enum
```
**描述:**
pixel 格式的枚举。

| 枚举值 | 描述 | 
| -------- | -------- |
| OHOS_PIXEL_MAP_FORMAT_NONE| 未知的格式 | 
| OHOS_PIXEL_MAP_FORMAT_RGBA_8888| 32-bit RGBA。 由 R, G, B组成，包括 A 都需要占用 8 bits。存储顺序是从高位到低位。 | 
| OHOS_PIXEL_MAP_FORMAT_RGB_565| 16-bit RGB。 仅由 R, G, B 组成. 存储顺序是从高位到低位: 红色占用5 bits,绿色占用6 bits,蓝色占用5 bits。 | 

**起始版本：**
8

### anonymous enum

  
```
anonymous enum
```
**描述:**
PixelMap alpha 类型的枚举。

| 枚举值 | 描述 | 
| -------- | -------- |
| OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN| 未知的格式 | 
| OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE| 不透明的格式 | 
| OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL| 预乘的格式 | 
| OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL| 预除的格式 | 

**起始版本：** 
10

### anonymous enum

  
```
anonymous enum
```
**描述:**
PixelMap 缩放类型的枚举。

| 枚举值 | 描述 | 
| -------- | -------- |
| OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE| 适应目标图片大小的格式 | 
| OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP| 以中心进行缩放的格式 | 

**起始版本：** 
10


### anonymous enum

  
```
anonymous enum
```
**描述:**
PixelMap 编辑类型的枚举。

| 枚举值 | 描述 | 
| -------- | -------- |
| OHOS_PIXEL_MAP_READ_ONLY| 只读的格式 | 
| OHOS_PIXEL_MAP_EDITABLE| 可编辑的格式 | 

**起始版本：** 
10


## 函数说明


### OH_AccessPixels()

  
```
int32_t OH_AccessPixels (napi_env env, napi_value value, void ** addrPtr )
```
**描述:**
获取**PixelMap**对象数据的内存地址，并锁定该内存。

函数执行成功后，**\*addrPtr**就是获取的待访问的内存地址. 访问操作完成后,必须要使用[OH_UnAccessPixels](#oh_unaccesspixels)来释放锁, 否则的话资源无法被释放. 待解锁后，内存地址就不可以再被访问和操作。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。|
| value | 应用层的 **PixelMap** 对象。|
| addrPtr | 用于指向的内存地址的双指针对象。|

**参见:**

UnAccessPixels

**返回:**

操作成功则返回 OHOS_IMAGE_RESULT_SUCCESS; 如果操作失败，则返回错误码。

**起始版本：**
8


### OH_GetImageInfo()

  
```
struct OhosPixelMapCreateOps OH_GetImageInfo (napi_env env, napi_value value, OhosPixelMapInfo * info )
```
**描述:**
获取 **PixelMap** 的信息，并记录信息到[OhosPixelMapInfo](_ohos_pixel_map_info.md)结构中。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。|
| value | 应用层的 **PixelMap** 对象。|
| info | 用于保存信息的指针对象. 更多细节, 参看 [OhosPixelMapInfo](_ohos_pixel_map_info.md)。|

**返回:**

如果获取并保存信息成功，则返回**0**; 如果操作失败，则返回错误码。

**参见:**

[OhosPixelMapInfo](_ohos_pixel_map_info.md)

**起始版本：**
8


### OH_PixelMap_CreateAlphaPixelMap()

  
```
int32_t OH_PixelMap_CreateAlphaPixelMap (napi_env env, napi_value source, napi_value * alpha )
```
**描述:**
根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的**PixelMap**对象。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。|
| source | **PixelMap**数据设置项。|
| alpha | alpha通道的指针。|

**返回:**

操作成功则返回 **PixelMap** 对象; 如果操作失败，则返回错误码。

**参见:**

CreateAlphaPixelMap

**起始版本：** 
10


### OH_PixelMap_CreatePixelMap()

  
```
int32_t OH_PixelMap_CreatePixelMap (napi_env env, OhosPixelMapCreateOps info, void * buf, size_t len, napi_value * res )
```
**描述:**
创建**PixelMap**对象.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。|
| info | pixel map 数据设置项。|
| buf | 图片的buffer数据。|
| len | 图片大小信息。|
| res | 应用层的 **PixelMap** 对象的指针。|

**返回:**

操作成功则返回 **PixelMap** 对象; 如果操作失败，则返回错误码。

**参见:**

CreatePixelMap

**起始版本：** 
10


### OH_PixelMap_Crop()

  
```
int32_t OH_PixelMap_Crop (const NativePixelMap * native, int32_t x, int32_t y, int32_t width, int32_t height )
```
**描述:**
设置**PixelMap**对象的裁剪.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。|
| x | 目标图片左上角的x坐标。|
| y | 目标图片左上角的y坐标。|
| width | 裁剪区域的宽度。|
| height | 裁剪区域的高度。|

**返回:**

操作成功则返回**0**; 如果操作失败，则返回错误码。

**参见:**

Crop

**起始版本：** 
10


### OH_PixelMap_Flip()

  
```
int32_t OH_PixelMap_Flip (const NativePixelMap * native, int32_t x, int32_t y )
```
**描述:**
设置**PixelMap**对象的翻转.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。|
| x | 根据水平方向x轴进行图片翻转。|
| y | 根据垂直方向y轴进行图片翻转。|

**返回:**

操作成功则返回**0**; 如果操作失败，则返回错误码。

**参见:**

Flip

**起始版本：** 
10


### OH_PixelMap_GetBytesNumberPerRow()

  
```
int32_t OH_PixelMap_GetBytesNumberPerRow (const NativePixelMap * native, int32_t * num )
```
**描述:**
获取**PixelMap**对象每行字节数.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。|
| num | **PixelMap**对象的每行字节数指针。|

**返回:**

操作成功则返回 **PixelMap** 对象每行字节数; 如果操作失败，则返回错误码。

**参见:**

GetBytesNumberPerRow

**起始版本：** 
10

### OH_PixelMap_GetDensity()

  
```
int32_t OH_PixelMap_GetDensity (const NativePixelMap * native, int32_t * density )
```
**描述:**
获取**PixelMap**对象像素密度.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。|
| density | 像素密度指针。|

**返回:**

操作成功则返回像素密度; 如果操作失败，则返回错误码。

**参见:**

GetDensity

**起始版本：** 
10


### OH_PixelMap_GetIsEditable()

  
```
int32_t OH_PixelMap_GetIsEditable (const NativePixelMap * native, int32_t * editable )
```
**描述:**
获取**PixelMap**对象是否可编辑的状态.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。|
| editable | **PixelMap** 对象是否可编辑的指针。|

**返回:**

操作成功则返回编辑类型的枚举值; 如果操作失败，则返回错误码。

**参见:**

GetIsEditable

**起始版本：** 
10


### OH_PixelMap_InitNativePixelMap()

  
```
NativePixelMap* OH_PixelMap_InitNativePixelMap (napi_env env, napi_value source )
```
**描述:**
初始化**PixelMap**对象数据.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。|
| source | **PixelMap** 数据设置项。|

**返回:**

操作成功则返回NativePixelMap的指针; 如果操作失败，则返回错误码。

**参见:**

InitNativePixelMap

**起始版本：** 
10


### OH_PixelMap_IsSupportAlpha()

  
```
int32_t OH_PixelMap_IsSupportAlpha (const NativePixelMap * native, int32_t * alpha )
```
**描述:**
获取**PixelMap**对象是否支持Alpha通道.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。|
| alpha | 是否支持Alpha的指针。|

**返回:**

操作成功则返回**0**; 如果操作失败，则返回错误码。

**参见:**

IsSupportAlpha

**起始版本：** 
10



### OH_PixelMap_Rotate()

  
```
int32_t OH_PixelMap_Rotate (const NativePixelMap * native, float angle )
```
**描述:**
设置**PixelMap**对象的旋转.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。|
| angle | 旋转角度。|

**返回:**

操作成功则返回**0**; 如果操作失败，则返回错误码。

**参见:**

Rotate

**起始版本：** 
10


### OH_PixelMap_Scale()

  
```
int32_t OH_PixelMap_Scale (const NativePixelMap * native, float x, float y )
```
**描述:**
设置**PixelMap**对象的缩放.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。|
| x | 缩放宽度。|
| y | 缩放高度。|

**返回:**

操作成功则返回**0**; 如果操作失败，则返回错误码。

**参见:**

Scale

**起始版本：** 
10


### OH_PixelMap_SetAlphaAble()

  
```
int32_t OH_PixelMap_SetAlphaAble (const NativePixelMap * native, int32_t alpha )
```
**描述:**
设置**PixelMap**对象的Alpha通道.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。|
| alpha | Alpha通道。|

**返回:**

操作成功则返回**0**; 如果操作失败，则返回错误码。

**参见:**

SetAlphaAble

**起始版本：** 
10


### OH_PixelMap_SetDensity()

  
```
int32_t OH_PixelMap_SetDensity (const NativePixelMap * native, int32_t density )
```
**描述:**
设置**PixelMap**对象像素密度.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。|
| density | 像素密度。|

**返回:**

操作成功则返回**0**; 如果操作失败，则返回错误码。

**参见:**

GetDensity

**起始版本：** 
10


### OH_PixelMap_SetOpacity()

  
```
int32_t OH_PixelMap_SetOpacity (const NativePixelMap * native, float opacity )
```
**描述:**
设置**PixelMap**对象的透明度.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。|
| opacity | 透明度。|

**返回:**

操作成功则返回**0**; 如果操作失败，则返回错误码。

**参见:**

SetOpacity

**起始版本：** 
10


### OH_PixelMap_Translate()

  
```
int32_t OH_PixelMap_Translate (const NativePixelMap * native, float x, float y )
```
**描述:**
设置**PixelMap**对象的偏移.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。|
| x | 水平偏移量。|
| y | 垂直偏移量。|

**返回:**

操作成功则返回**0**; 如果操作失败，则返回错误码。

**参见:**

Translate

**起始版本：** 
10


### OH_UnAccessPixels()

  
```
int32_t OH_UnAccessPixels (napi_env env, napi_value value )
```
**描述:**
释放**PixelMap**对象数据的内存锁, 用于匹配方法[OH_AccessPixels](#oh_accesspixels).

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。|
| value | 应用层的 **PixelMap** 对象。|

**返回:**

操作成功则返回 OHOS_IMAGE_RESULT_SUCCESS; 如果操作失败，则返回错误码。

**参见:**

AccessPixels

**起始版本：** 
8
