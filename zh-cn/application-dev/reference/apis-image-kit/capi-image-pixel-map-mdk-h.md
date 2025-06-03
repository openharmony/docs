# image_pixel_map_mdk.h

## 概述

声明可以锁定并访问pixelmap数据的方法，声明解锁的方法。Need link <b>libpixelmapndk.z.so</b>

**起始版本：** 10

**相关模块：** [Image](capi-image.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OhosPixelMapInfos](capi-ohospixelmapinfos.md) | OhosPixelMapInfos | 用于定义 pixel map 的相关信息。 |
| [NativePixelMap_](capi-nativepixelmap-.md) | NativePixelMap | 定义native层pixelmap数据类型名称。 |
| [OhosPixelMapCreateOps](capi-ohospixelmapcreateops.md) | - | 用于定义创建 pixel map 设置选项的相关信息。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [anonymous enum](#anonymous enum) | - | PixelMap 透明度类型的枚举。 |
| [anonymous enum](#anonymous enum) | - | PixelMap 编辑类型的枚举。 |
| [OH_PixelMap_AntiAliasingLevel](#oh_pixelmap_antialiasinglevel) | OH_PixelMap_AntiAliasingLevel | Pixelmap缩放时采用的缩放算法。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_PixelMap_CreatePixelMap(napi_env env, OhosPixelMapCreateOps info,void* buf, size_t len, napi_value* res)](#oh_pixelmap_createpixelmap) | 创建<b>PixelMap</b>对象。 |
| [int32_t OH_PixelMap_CreatePixelMapWithStride(napi_env env, OhosPixelMapCreateOps info,void* buf, size_t len, int32_t rowStride, napi_value* res)](#oh_pixelmap_createpixelmapwithstride) | 创建<b>PixelMap</b>对象。当前只支持输入流为BGRA格式的流。pixelmap内存在RGBA格式下，默认为DMA内存（图片512512以上）。 |
| [int32_t OH_PixelMap_CreateAlphaPixelMap(napi_env env, napi_value source, napi_value* alpha)](#oh_pixelmap_createalphapixelmap) | 根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的<b>PixelMap</b>对象。 |
| [NativePixelMap* OH_PixelMap_InitNativePixelMap(napi_env env, napi_value source)](#oh_pixelmap_initnativepixelmap) | 初始化<b>PixelMap</b>对象数据。 |
| [int32_t OH_PixelMap_GetBytesNumberPerRow(const NativePixelMap* native, int32_t* num)](#oh_pixelmap_getbytesnumberperrow) | 获取<b>PixelMap</b>对象每行字节数。 |
| [int32_t OH_PixelMap_GetIsEditable(const NativePixelMap* native, int32_t* editable)](#oh_pixelmap_getiseditable) | 获取<b>PixelMap</b>对象是否可编辑的状态。 |
| [int32_t OH_PixelMap_IsSupportAlpha(const NativePixelMap* native, int32_t* alpha)](#oh_pixelmap_issupportalpha) | 获取<b>PixelMap</b>对象是否支持Alpha通道。 |
| [int32_t OH_PixelMap_SetAlphaAble(const NativePixelMap* native, int32_t alpha)](#oh_pixelmap_setalphaable) | 设置<b>PixelMap</b>对象的Alpha通道。 |
| [int32_t OH_PixelMap_GetDensity(const NativePixelMap* native, int32_t* density)](#oh_pixelmap_getdensity) | 获取<b>PixelMap</b>对象像素密度。 |
| [int32_t OH_PixelMap_SetDensity(const NativePixelMap* native, int32_t density)](#oh_pixelmap_setdensity) | 设置<b>PixelMap</b>对象像素密度。 |
| [int32_t OH_PixelMap_SetOpacity(const NativePixelMap* native, float opacity)](#oh_pixelmap_setopacity) | 设置<b>PixelMap</b>对象的透明度。 |
| [int32_t OH_PixelMap_Scale(const NativePixelMap* native, float x, float y)](#oh_pixelmap_scale) | 设置<b>PixelMap</b>对象的缩放。 |
| [int32_t OH_PixelMap_ScaleWithAntiAliasing(const NativePixelMap* native, float x, float y,OH_PixelMap_AntiAliasingLevel level)](#oh_pixelmap_scalewithantialiasing) | 根据指定的缩放算法和输入的宽高对图片进行缩放。 |
| [int32_t OH_PixelMap_Translate(const NativePixelMap* native, float x, float y)](#oh_pixelmap_translate) | 设置<b>PixelMap</b>对象的偏移。 |
| [int32_t OH_PixelMap_Rotate(const NativePixelMap* native, float angle)](#oh_pixelmap_rotate) | 设置<b>PixelMap</b>对象的旋转。 |
| [int32_t OH_PixelMap_Flip(const NativePixelMap* native, int32_t x, int32_t y)](#oh_pixelmap_flip) | 设置<b>PixelMap</b>对象的翻转。 |
| [int32_t OH_PixelMap_Crop(const NativePixelMap* native, int32_t x, int32_t y, int32_t width, int32_t height)](#oh_pixelmap_crop) | 设置<b>PixelMap</b>对象的裁剪。 |
| [int32_t OH_PixelMap_GetImageInfo(const NativePixelMap* native, OhosPixelMapInfos *info)](#oh_pixelmap_getimageinfo) | 获取<b>PixelMap</b>对象图像信息。 |
| [int32_t OH_PixelMap_AccessPixels(const NativePixelMap* native, void** addr)](#oh_pixelmap_accesspixels) | 获取native <b>PixelMap</b> 对象数据的内存地址，并锁定该内存。 |
| [int32_t OH_PixelMap_UnAccessPixels(const NativePixelMap* native)](#oh_pixelmap_unaccesspixels) | 释放native <b>PixelMap</b>对象数据的内存锁，用于匹配方法[OH_PixelMap_AccessPixels](capi-image-pixel-map-mdk-h.md#oh_pixelmap_accesspixels)。 |

## 枚举类型说明

### anonymous enum

```
enum anonymous enum
```

**描述**

PixelMap 透明度类型的枚举。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN = 0 | 未知的格式 |
| OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE = 1 | 不透明的格式 |
| OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL = 2 | 预乘的格式 |
| OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL = 3 | 预除的格式 |

### anonymous enum

```
enum anonymous enum
```

**描述**

PixelMap 编辑类型的枚举。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OHOS_PIXEL_MAP_READ_ONLY = 0 | 只读的格式 |
| OHOS_PIXEL_MAP_EDITABLE = 1 | 可编辑的格式 |

### OH_PixelMap_AntiAliasingLevel

```
enum OH_PixelMap_AntiAliasingLevel
```

**描述**

Pixelmap缩放时采用的缩放算法。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OH_PixelMap_AntiAliasing_NONE = 0 | 最近邻缩放算法。 |
| OH_PixelMap_AntiAliasing_LOW = 1 | 双线性缩放算法。 |
| OH_PixelMap_AntiAliasing_MEDIUM = 2 | 双线性缩放算法，同时开启mipmap。 |
| OH_PixelMap_AntiAliasing_HIGH = 3 | cubic缩放算法。 |


## 函数说明

### OH_PixelMap_CreatePixelMap()

```
int32_t OH_PixelMap_CreatePixelMap(napi_env env, OhosPixelMapCreateOps info,void* buf, size_t len, napi_value* res)
```

**描述**

创建<b>PixelMap</b>对象。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| [OhosPixelMapCreateOps](capi-ohospixelmapcreateops.md) info | pixel map 数据设置项。 |
| void* buf | 图片的buffer数据。 |
| size_t len | 图片大小信息。 |
| napi_value* res | 应用层的 <b>PixelMap</b> 对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像获取数据失败则返回 IMAGE_RESULT_GET_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果解码失败则返回 IMAGE_RESULT_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像头解码失败则返回 IMAGE_RESULT_DECODE_HEAD_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建解码器失败则返回 IMAGE_RESULT_CREATE_DECODER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建编码器失败则返回 IMAGE_RESULT_CREATE_ENCODER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果检查格式失败则返回 IMAGE_RESULT_CHECK_FORMAT_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果skia能力失败则返回 IMAGE_RESULT_THIRDPART_SKIA_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存失败则返回 IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存数据错误则返回 IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像解码失败则返回 IMAGE_RESULT_DECODE_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果解码失败则返回 IMAGE_RESULT_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像分配内存失败则返回 IMAGE_RESULT_MALLOC_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像数据不支持则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像初始化失败则返回 IMAGE_RESULT_INIT_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果裁剪失败失败则返回 IMAGE_RESULT_CROP [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像格式未知则返回 IMAGE_RESULT_UNKNOWN_FORMAT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果注册插件失败失败则返回 IMAGE_RESULT_PLUGIN_REGISTER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建插件失败失败则返回 IMAGE_RESULT_PLUGIN_CREATE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像添加像素位图失败则返回 IMAGE_RESULT_ENCODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像不支持硬件解码则返回 IMAGE_RESULT_HW_DECODE_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果硬件解码失败则返回 IMAGE_RESULT_HW_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果ipc失败则返回 IMAGE_RESULT_INDEX_INVALID [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果透明度类型错误则返回 IMAGE_RESULT_ALPHA_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果内存分配类型错误则返回 IMAGE_RESULT_ALLOCATER_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

CreatePixelMap

### OH_PixelMap_CreatePixelMapWithStride()

```
int32_t OH_PixelMap_CreatePixelMapWithStride(napi_env env, OhosPixelMapCreateOps info,void* buf, size_t len, int32_t rowStride, napi_value* res)
```

**描述**

创建<b>PixelMap</b>对象。当前只支持输入流为BGRA格式的流。pixelmap内存在RGBA格式下，默认为DMA内存（图片512512以上）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| [OhosPixelMapCreateOps](capi-ohospixelmapcreateops.md) info | PixelMap数据设置项。 |
| void* buf | 图片的buffer数据。 |
| size_t len | 图片buffer大小信息。 |
| int32_t rowStride | 图片跨距信息。 跨距，图像每行占用的真实内存大小，单位为字节。跨距 = width单位像素字节数 + padding，padding为每行为内存对齐做的填充区域。 |
| napi_value* res | 应用层的 PixelMap 对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回IMAGE_RESULT_SUCCESS;<br> 如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER;<br> 如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL;<br> 如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL;<br> 如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR;<br> 如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL;<br> 如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL;<br> 如果属性无效或图像数据不支持则返回IMAGE_RESULT_DATA_UNSUPPORT;<br> 如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT; |

**参考：**

CreatePixelMapWithStride

### OH_PixelMap_CreateAlphaPixelMap()

```
int32_t OH_PixelMap_CreateAlphaPixelMap(napi_env env, napi_value source, napi_value* alpha)
```

**描述**

根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的<b>PixelMap</b>对象。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value source | <b>PixelMap</b>数据设置项。 |
| napi_value* alpha | alpha通道的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像获取数据失败则返回 IMAGE_RESULT_GET_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果解码失败则返回 IMAGE_RESULT_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像头解码失败则返回 IMAGE_RESULT_DECODE_HEAD_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建解码器失败则返回 IMAGE_RESULT_CREATE_DECODER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建编码器失败则返回 IMAGE_RESULT_CREATE_ENCODER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果检查格式失败则返回 IMAGE_RESULT_CHECK_FORMAT_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果skia能力失败则返回 IMAGE_RESULT_THIRDPART_SKIA_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存失败则返回 IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存数据错误则返回 IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像解码失败则返回 IMAGE_RESULT_DECODE_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像分配内存失败则返回 IMAGE_RESULT_MALLOC_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像数据不支持则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像初始化失败则返回 IMAGE_RESULT_INIT_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果裁剪失败失败则返回 IMAGE_RESULT_CROP [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像格式未知则返回 IMAGE_RESULT_UNKNOWN_FORMAT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果注册插件失败失败则返回 IMAGE_RESULT_PLUGIN_REGISTER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建插件失败失败则返回 IMAGE_RESULT_PLUGIN_CREATE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像添加像素位图失败则返回 IMAGE_RESULT_ENCODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像不支持硬件解码则返回 IMAGE_RESULT_HW_DECODE_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果硬件解码失败则返回 IMAGE_RESULT_HW_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果ipc失败则返回 IMAGE_RESULT_INDEX_INVALID [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果透明度类型错误则返回 IMAGE_RESULT_ALPHA_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果内存分配类型错误则返回 IMAGE_RESULT_ALLOCATER_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

CreateAlphaPixelMap

### OH_PixelMap_InitNativePixelMap()

```
NativePixelMap* OH_PixelMap_InitNativePixelMap(napi_env env, napi_value source)
```

**描述**

初始化<b>PixelMap</b>对象数据。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value source | <b>PixelMap</b> 数据设置项。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| NativePixelMap* | 操作成功则返回NativePixelMap的指针；如果操作失败，则返回错误码。 |

**参考：**

InitNativePixelMap

### OH_PixelMap_GetBytesNumberPerRow()

```
int32_t OH_PixelMap_GetBytesNumberPerRow(const NativePixelMap* native, int32_t* num)
```

**描述**

获取<b>PixelMap</b>对象每行字节数。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| int32_t* num | <b>PixelMap</b>对象的每行字节数指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

GetBytesNumberPerRow

### OH_PixelMap_GetIsEditable()

```
int32_t OH_PixelMap_GetIsEditable(const NativePixelMap* native, int32_t* editable)
```

**描述**

获取<b>PixelMap</b>对象是否可编辑的状态。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| int32_t* editable | <b>PixelMap</b> 对象是否可编辑的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

GetIsEditable

### OH_PixelMap_IsSupportAlpha()

```
int32_t OH_PixelMap_IsSupportAlpha(const NativePixelMap* native, int32_t* alpha)
```

**描述**

获取<b>PixelMap</b>对象是否支持Alpha通道。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| int32_t* alpha | 是否支持Alpha的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

IsSupportAlpha

### OH_PixelMap_SetAlphaAble()

```
int32_t OH_PixelMap_SetAlphaAble(const NativePixelMap* native, int32_t alpha)
```

**描述**

设置<b>PixelMap</b>对象的Alpha通道。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| int32_t alpha | Alpha通道。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

SetAlphaAble

### OH_PixelMap_GetDensity()

```
int32_t OH_PixelMap_GetDensity(const NativePixelMap* native, int32_t* density)
```

**描述**

获取<b>PixelMap</b>对象像素密度。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| int32_t* density | 像素密度指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

GetDensity

### OH_PixelMap_SetDensity()

```
int32_t OH_PixelMap_SetDensity(const NativePixelMap* native, int32_t density)
```

**描述**

设置<b>PixelMap</b>对象像素密度。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| int32_t density | 像素密度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

GetDensity

### OH_PixelMap_SetOpacity()

```
int32_t OH_PixelMap_SetOpacity(const NativePixelMap* native, float opacity)
```

**描述**

设置<b>PixelMap</b>对象的透明度。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| float opacity | 透明度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

SetOpacity

### OH_PixelMap_Scale()

```
int32_t OH_PixelMap_Scale(const NativePixelMap* native, float x, float y)
```

**描述**

设置<b>PixelMap</b>对象的缩放。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| float x | 宽度的缩放比例。 |
| float y | 高度的缩放比例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像获取数据失败则返回 IMAGE_RESULT_GET_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果解码失败则返回 IMAGE_RESULT_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果检查格式失败则返回 IMAGE_RESULT_CHECK_FORMAT_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果skia能力失败则返回 IMAGE_RESULT_THIRDPART_SKIA_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存失败则返回 IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存数据错误则返回 IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像分配内存失败则返回 IMAGE_RESULT_MALLOC_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像数据不支持则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像初始化失败则返回 IMAGE_RESULT_INIT_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果裁剪失败失败则返回 IMAGE_RESULT_CROP [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像格式未知则返回 IMAGE_RESULT_UNKNOWN_FORMAT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果注册插件失败失败则返回 IMAGE_RESULT_PLUGIN_REGISTER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建插件失败失败则返回 IMAGE_RESULT_PLUGIN_CREATE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果透明度类型错误则返回 IMAGE_RESULT_ALPHA_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果内存分配类型错误则返回 IMAGE_RESULT_ALLOCATER_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

Scale

### OH_PixelMap_ScaleWithAntiAliasing()

```
int32_t OH_PixelMap_ScaleWithAntiAliasing(const NativePixelMap* native, float x, float y,OH_PixelMap_AntiAliasingLevel level)
```

**描述**

根据指定的缩放算法和输入的宽高对图片进行缩放。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| float x | 宽度的缩放比例。 |
| float y | 高度的缩放比例。 |
| [OH_PixelMap_AntiAliasingLevel](#oh_pixelmap_antialiasinglevel) level | 缩放算法。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回IMAGE_RESULT_SUCCESS;<br> 如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL;<br> 如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER;<br> 如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL;<br> 如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR;<br> 如果skia能力失败则返回IMAGE_RESULT_THIRDPART_SKIA_ERROR;<br> 如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL;<br> 如果图像分配内存失败则返回IMAGE_RESULT_MALLOC_ABNORMAL;<br> 如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT; |

**参考：**

ScaleWithAntiAliasing

### OH_PixelMap_Translate()

```
int32_t OH_PixelMap_Translate(const NativePixelMap* native, float x, float y)
```

**描述**

设置<b>PixelMap</b>对象的偏移。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| float x | 水平偏移量。 |
| float y | 垂直偏移量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像获取数据失败则返回 IMAGE_RESULT_GET_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果解码失败则返回 IMAGE_RESULT_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果检查格式失败则返回 IMAGE_RESULT_CHECK_FORMAT_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果skia能力失败则返回 IMAGE_RESULT_THIRDPART_SKIA_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存失败则返回 IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存数据错误则返回 IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像分配内存失败则返回 IMAGE_RESULT_MALLOC_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像数据不支持则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果裁剪失败失败则返回 IMAGE_RESULT_CROP [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像格式未知则返回 IMAGE_RESULT_UNKNOWN_FORMAT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果注册插件失败失败则返回 IMAGE_RESULT_PLUGIN_REGISTER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建插件失败失败则返回 IMAGE_RESULT_PLUGIN_CREATE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果透明度类型错误则返回 IMAGE_RESULT_ALPHA_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果内存分配类型错误则返回 IMAGE_RESULT_ALLOCATER_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

Translate

### OH_PixelMap_Rotate()

```
int32_t OH_PixelMap_Rotate(const NativePixelMap* native, float angle)
```

**描述**

设置<b>PixelMap</b>对象的旋转。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| float angle | 旋转角度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像获取数据失败则返回 IMAGE_RESULT_GET_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果解码失败则返回 IMAGE_RESULT_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果检查格式失败则返回 IMAGE_RESULT_CHECK_FORMAT_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果skia能力失败则返回 IMAGE_RESULT_THIRDPART_SKIA_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存失败则返回 IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存数据错误则返回 IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像分配内存失败则返回 IMAGE_RESULT_MALLOC_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像数据不支持则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果裁剪失败失败则返回 IMAGE_RESULT_CROP [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像格式未知则返回 IMAGE_RESULT_UNKNOWN_FORMAT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果注册插件失败失败则返回 IMAGE_RESULT_PLUGIN_REGISTER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建插件失败失败则返回 IMAGE_RESULT_PLUGIN_CREATE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果透明度类型错误则返回 IMAGE_RESULT_ALPHA_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果内存分配类型错误则返回 IMAGE_RESULT_ALLOCATER_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

Rotate

### OH_PixelMap_Flip()

```
int32_t OH_PixelMap_Flip(const NativePixelMap* native, int32_t x, int32_t y)
```

**描述**

设置<b>PixelMap</b>对象的翻转。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| int32_t x | 根据水平方向x轴进行图片翻转。 |
| int32_t y | 根据垂直方向y轴进行图片翻转。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像获取数据失败则返回 IMAGE_RESULT_GET_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果解码失败则返回 IMAGE_RESULT_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果检查格式失败则返回 IMAGE_RESULT_CHECK_FORMAT_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果skia能力失败则返回 IMAGE_RESULT_THIRDPART_SKIA_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存失败则返回 IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存数据错误则返回 IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像分配内存失败则返回 IMAGE_RESULT_MALLOC_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像数据不支持则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果裁剪失败失败则返回 IMAGE_RESULT_CROP [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像格式未知则返回 IMAGE_RESULT_UNKNOWN_FORMAT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果注册插件失败失败则返回 IMAGE_RESULT_PLUGIN_REGISTER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建插件失败失败则返回 IMAGE_RESULT_PLUGIN_CREATE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果透明度类型错误则返回 IMAGE_RESULT_ALPHA_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果内存分配类型错误则返回 IMAGE_RESULT_ALLOCATER_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

Flip

### OH_PixelMap_Crop()

```
int32_t OH_PixelMap_Crop(const NativePixelMap* native, int32_t x, int32_t y, int32_t width, int32_t height)
```

**描述**

设置<b>PixelMap</b>对象的裁剪。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| int32_t x | 目标图片左上角的x坐标。 |
| int32_t y | 目标图片左上角的y坐标。 |
| int32_t width | 裁剪区域的宽度。 |
| int32_t height | 裁剪区域的高度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像获取数据失败则返回 IMAGE_RESULT_GET_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果解码失败则返回 IMAGE_RESULT_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果检查格式失败则返回 IMAGE_RESULT_CHECK_FORMAT_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果skia能力失败则返回 IMAGE_RESULT_THIRDPART_SKIA_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存失败则返回 IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存数据错误则返回 IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像分配内存失败则返回 IMAGE_RESULT_MALLOC_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像数据不支持则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果裁剪失败失败则返回 IMAGE_RESULT_CROP [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像格式未知则返回 IMAGE_RESULT_UNKNOWN_FORMAT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果注册插件失败失败则返回 IMAGE_RESULT_PLUGIN_REGISTER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建插件失败失败则返回 IMAGE_RESULT_PLUGIN_CREATE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果透明度类型错误则返回 IMAGE_RESULT_ALPHA_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果内存分配类型错误则返回 IMAGE_RESULT_ALLOCATER_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

Crop

### OH_PixelMap_GetImageInfo()

```
int32_t OH_PixelMap_GetImageInfo(const NativePixelMap* native, OhosPixelMapInfos *info)
```

**描述**

获取<b>PixelMap</b>对象图像信息。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| [OhosPixelMapInfos](capi-ohospixelmapinfos.md) *info | 图像信息指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像获取数据失败则返回 IMAGE_RESULT_GET_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果解码失败则返回 IMAGE_RESULT_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果检查格式失败则返回 IMAGE_RESULT_CHECK_FORMAT_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果skia能力失败则返回 IMAGE_RESULT_THIRDPART_SKIA_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存失败则返回 IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存数据错误则返回 IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像分配内存失败则返回 IMAGE_RESULT_MALLOC_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像数据不支持则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果裁剪失败失败则返回 IMAGE_RESULT_CROP [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像格式未知则返回 IMAGE_RESULT_UNKNOWN_FORMAT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果注册插件失败失败则返回 IMAGE_RESULT_PLUGIN_REGISTER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建插件失败失败则返回 IMAGE_RESULT_PLUGIN_CREATE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果透明度类型错误则返回 IMAGE_RESULT_ALPHA_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果内存分配类型错误则返回 IMAGE_RESULT_ALLOCATER_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

OhosPixelMapInfos

### OH_PixelMap_AccessPixels()

```
int32_t OH_PixelMap_AccessPixels(const NativePixelMap* native, void** addr)
```

**描述**

获取native <b>PixelMap</b> 对象数据的内存地址，并锁定该内存。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |
| void** addr | 用于指向的内存地址的双指针对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像获取数据失败则返回 IMAGE_RESULT_GET_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果解码失败则返回 IMAGE_RESULT_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果检查格式失败则返回 IMAGE_RESULT_CHECK_FORMAT_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果skia能力失败则返回 IMAGE_RESULT_THIRDPART_SKIA_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存失败则返回 IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存数据错误则返回 IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像分配内存失败则返回 IMAGE_RESULT_MALLOC_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像数据不支持则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果裁剪失败失败则返回 IMAGE_RESULT_CROP [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像格式未知则返回 IMAGE_RESULT_UNKNOWN_FORMAT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果注册插件失败失败则返回 IMAGE_RESULT_PLUGIN_REGISTER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建插件失败失败则返回 IMAGE_RESULT_PLUGIN_CREATE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果透明度类型错误则返回 IMAGE_RESULT_ALPHA_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果内存分配类型错误则返回 IMAGE_RESULT_ALLOCATER_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

AccessPixels

### OH_PixelMap_UnAccessPixels()

```
int32_t OH_PixelMap_UnAccessPixels(const NativePixelMap* native)
```

**描述**

释放native <b>PixelMap</b>对象数据的内存锁，用于匹配方法[OH_PixelMap_AccessPixels](capi-image-pixel-map-mdk-h.md#oh_pixelmap_accesspixels)。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const NativePixelMap* native | NativePixelMap的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像获取数据失败则返回 IMAGE_RESULT_GET_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果解码失败则返回 IMAGE_RESULT_DECODE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果检查格式失败则返回 IMAGE_RESULT_CHECK_FORMAT_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果skia能力失败则返回 IMAGE_RESULT_THIRDPART_SKIA_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像输入数据失败则返回 IMAGE_RESULT_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存失败则返回 IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果共享内存数据错误则返回 IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像分配内存失败则返回 IMAGE_RESULT_MALLOC_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像数据不支持则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果裁剪失败失败则返回 IMAGE_RESULT_CROP [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像格式未知则返回 IMAGE_RESULT_UNKNOWN_FORMAT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果注册插件失败失败则返回 IMAGE_RESULT_PLUGIN_REGISTER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建插件失败失败则返回 IMAGE_RESULT_PLUGIN_CREATE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果属性无效则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果透明度类型错误则返回 IMAGE_RESULT_ALPHA_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果内存分配类型错误则返回 IMAGE_RESULT_ALLOCATER_TYPE_ERROR [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

UnAccessPixels


