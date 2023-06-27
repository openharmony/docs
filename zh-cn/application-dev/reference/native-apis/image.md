# Image


提供获取pixelmap的数据和信息的接口方法。

使用该文件下接口，需要依赖：libpixelmap_ndk.z.so

@Syscap SystemCapability.Multimedia.Image


**起始版本：**


8


## 汇总


### 文件

| 文件名称 | 描述 |
| -------- | -------- |
| [image_pixel_map_napi.h](image__pixel__map__napi_8h.md) | 声明可以锁定并访问pixelmap数据的方法，声明解锁的方法。 <br>引用文件：<multimedia/image_framework/image_pixel_map_napi.h>|


### 结构体

| 结构体名称 | 描述 |
| -------- | -------- |
| [OhosPixelMapInfo](_ohos_pixel_map_info.md) | 用于定义 pixel map 的相关信息。 |


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| { OHOS_IMAGE_RESULT_SUCCESS = 0, OHOS_IMAGE_RESULT_BAD_PARAMETER = -1 } | 函数方法返回值的错误码的枚举。|
| { OHOS_PIXEL_MAP_FORMAT_NONE = 0, OHOS_PIXEL_MAP_FORMAT_RGBA_8888 = 3, OHOS_PIXEL_MAP_FORMAT_RGB_565 = 2 } | pixel 格式的枚举。|


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_GetImageInfo](#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_ohos_pixel_map_info.md) \*info) | 获取 **PixelMap** 的信息，并记录信息到[OhosPixelMapInfo](_ohos_pixel_map_info.md)结构中。|
| [OH_AccessPixels](#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | 获取**PixelMap**对象数据的内存地址，并锁定该内存。|
| [OH_UnAccessPixels](#oh_unaccesspixels) (napi_env env, napi_value value) | 释放**PixelMap**对象数据的内存锁, 用于匹配方法[OH_AccessPixels](#oh_accesspixels)。|


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
