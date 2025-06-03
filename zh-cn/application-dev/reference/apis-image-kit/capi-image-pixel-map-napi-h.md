# image_pixel_map_napi.h

## 概述

声明可以锁定并访问pixelmap数据的方法，声明解锁的方法。

**起始版本：** 8

**相关模块：** [Image](capi-image.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OhosPixelMapInfo](capi-ohospixelmapinfo.md) | - | 用于定义 pixel map 的相关信息。 |

### 枚举

| 名称 | 描述 |
| -- | -- |
| [anonymous enum](#anonymous enum) | 函数方法返回值的错误码的枚举。 |
| [anonymous enum](#anonymous enum) | pixel 格式的枚举。 |
| [anonymous enum](#anonymous enum) | PixelMap 缩放类型的枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_GetImageInfo(napi_env env, napi_value value, OhosPixelMapInfo *info)](#oh_getimageinfo) | 获取 <b>PixelMap</b> 的信息，并记录信息到[OhosPixelMapInfo](capi-ohospixelmapinfo.md)结构中。 |
| [int32_t OH_AccessPixels(napi_env env, napi_value value, void** addrPtr)](#oh_accesspixels) | 获取<b>PixelMap</b>对象数据的内存地址，并锁定该内存。函数执行成功后，<b>addrPtr</b>就是获取的待访问的内存地址。访问操作完成后，必须要使用[OH_UnAccessPixels](capi-image-pixel-map-napi-h.md#oh_unaccesspixels)来释放锁，否则的话资源无法被释放。待解锁后，内存地址就不可以再被访问和操作。 |
| [int32_t OH_UnAccessPixels(napi_env env, napi_value value)](#oh_unaccesspixels) | 释放<b>PixelMap</b>对象数据的内存锁, 用于匹配方法[OH_AccessPixels](capi-image-pixel-map-napi-h.md#oh_accesspixels)。 |

## 枚举类型说明

### anonymous enum

```
enum anonymous enum
```

**描述**

函数方法返回值的错误码的枚举。

**起始版本：** 8

**废弃版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OHOS_IMAGE_RESULT_SUCCESS = 0 | 成功的结果 |
| OHOS_IMAGE_RESULT_BAD_PARAMETER = -1 | 无效值 |

### anonymous enum

```
enum anonymous enum
```

**描述**

pixel 格式的枚举。

**起始版本：** 8

**废弃版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OHOS_PIXEL_MAP_FORMAT_NONE = 0 | 未知的格式 |
| OHOS_PIXEL_MAP_FORMAT_RGBA_8888 = 3 | 32-bit RGBA. 由 R, G, B组成，包括 A 都需要占用 8 bits。存储顺序是从高位到低位。 |
| OHOS_PIXEL_MAP_FORMAT_RGB_565 = 2 | 16-bit RGB. 仅由 R, G, B 组成。存储顺序是从高位到低位: 红色占用5 bits，绿色占用6 bits，蓝色占用5 bits。 |

### anonymous enum

```
enum anonymous enum
```

**描述**

PixelMap 缩放类型的枚举。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE = 0 | 适应目标图片大小的格式 |
| OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP = 1 | 以中心进行缩放的格式 |


## 函数说明

### OH_GetImageInfo()

```
int32_t OH_GetImageInfo(napi_env env, napi_value value, OhosPixelMapInfo *info)
```

**描述**

获取 <b>PixelMap</b> 的信息，并记录信息到[OhosPixelMapInfo](capi-ohospixelmapinfo.md)结构中。

**起始版本：** 8

**废弃版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value value | 应用层的 <b>PixelMap</b> 对象。 |
| [OhosPixelMapInfo](capi-ohospixelmapinfo.md) *info | 用于保存信息的指针对象。 更多细节, 参看 [OhosPixelMapInfo](capi-ohospixelmapinfo.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果获取并保存信息成功，则返回<b>0</b>; 如果操作失败，则返回错误码。 |

**参考：**

OhosPixelMapInfo

### OH_AccessPixels()

```
int32_t OH_AccessPixels(napi_env env, napi_value value, void** addrPtr)
```

**描述**

获取<b>PixelMap</b>对象数据的内存地址，并锁定该内存。函数执行成功后，<b>addrPtr</b>就是获取的待访问的内存地址。访问操作完成后，必须要使用[OH_UnAccessPixels](capi-image-pixel-map-napi-h.md#oh_unaccesspixels)来释放锁，否则的话资源无法被释放。待解锁后，内存地址就不可以再被访问和操作。

**起始版本：** 8

**废弃版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value value | 应用层的 <b>PixelMap</b> 对象。 |
| void** addrPtr | 用于指向的内存地址的双指针对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 操作成功则返回 [OHOS_IMAGE_RESULT_SUCCESS](capi-image-pixel-map-napi-h.md#anonymous enum)；如果操作失败，则返回错误码。 |

**参考：**

UnAccessPixels

### OH_UnAccessPixels()

```
int32_t OH_UnAccessPixels(napi_env env, napi_value value)
```

**描述**

释放<b>PixelMap</b>对象数据的内存锁, 用于匹配方法[OH_AccessPixels](capi-image-pixel-map-napi-h.md#oh_accesspixels)。

**起始版本：** 8

**废弃版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value value | 应用层的 <b>PixelMap</b> 对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 操作成功则返回 [OHOS_IMAGE_RESULT_SUCCESS](capi-image-pixel-map-napi-h.md#anonymous enum)；如果操作失败，则返回错误码。 |

**参考：**

AccessPixels


