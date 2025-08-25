# image_receiver_mdk.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 概述

声明从native层获取图片数据的方法。

**库：** libimage_receiver_ndk.z.so

**引用文件：** <multimedia/image_framework/image_receiver_mdk.h>

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 10

**相关模块：** [Image](capi-image.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OhosImageReceiverInfo](capi-image-ohosimagereceiverinfo.md) | - | 定义ImageReceiver的相关信息。 |
| [ImageReceiverNative_](capi-image-imagereceivernative-.md) | ImageReceiverNative | 用于定义ImageReceiverNative数据类型名称。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_Image_Receiver_On_Callback)()](#oh_image_receiver_on_callback) | OH_Image_Receiver_On_Callback | 定义native层图片的回调方法。 |
| [int32_t OH_Image_Receiver_CreateImageReceiver(napi_env env, struct OhosImageReceiverInfo info, napi_value* res)](#oh_image_receiver_createimagereceiver) | - | 创建应用层ImageReceiver对象。 |
| [ImageReceiverNative* OH_Image_Receiver_InitImageReceiverNative(napi_env env, napi_value source)](#oh_image_receiver_initimagereceivernative) | - | 通过应用层ImageReceiver对象初始化native层[ImageReceiverNative](capi-image-imagereceivernative-.md)对象。 |
| [int32_t OH_Image_Receiver_GetReceivingSurfaceId(const ImageReceiverNative* native, char* id, size_t len)](#oh_image_receiver_getreceivingsurfaceid) | - | 通过[ImageReceiverNative](capi-image-imagereceivernative-.md)获取receiver的id。 |
| [int32_t OH_Image_Receiver_ReadLatestImage(const ImageReceiverNative* native, napi_value* image)](#oh_image_receiver_readlatestimage) | - | 通过[ImageReceiverNative](capi-image-imagereceivernative-.md)获取最新的一张图片。 |
| [int32_t OH_Image_Receiver_ReadNextImage(const ImageReceiverNative* native, napi_value* image)](#oh_image_receiver_readnextimage) | - | 通过[ImageReceiverNative](capi-image-imagereceivernative-.md)获取下一张图片。 |
| [int32_t OH_Image_Receiver_On(const ImageReceiverNative* native, OH_Image_Receiver_On_Callback callback)](#oh_image_receiver_on) | - | 注册一个[OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)回调事件。每当接收新图片，该回调事件就会响应。 |
| [int32_t OH_Image_Receiver_GetSize(const ImageReceiverNative* native, struct OhosImageSize* size)](#oh_image_receiver_getsize) | - | 通过[ImageReceiverNative](capi-image-imagereceivernative-.md)获取ImageReceiver的大小。 |
| [int32_t OH_Image_Receiver_GetCapacity(const ImageReceiverNative* native, int32_t* capacity)](#oh_image_receiver_getcapacity) | - | 通过[ImageReceiverNative](capi-image-imagereceivernative-.md)获取ImageReceiver的容量。 |
| [int32_t OH_Image_Receiver_GetFormat(const ImageReceiverNative* native, int32_t* format)](#oh_image_receiver_getformat) | - | 通过[ImageReceiverNative](capi-image-imagereceivernative-.md)获取ImageReceiver的格式。 |
| [int32_t OH_Image_Receiver_Release(ImageReceiverNative* native)](#oh_image_receiver_release) | - | 释放native层[ImageReceiverNative](capi-image-imagereceivernative-.md)对象。<br>注意，此方法不能释放应用层ImageReceiver对象。 |

## 函数说明

### OH_Image_Receiver_On_Callback()

```
typedef void (*OH_Image_Receiver_On_Callback)()
```

**描述**

定义native层图片的回调方法。

**起始版本：** 10

### OH_Image_Receiver_CreateImageReceiver()

```
int32_t OH_Image_Receiver_CreateImageReceiver(napi_env env, struct OhosImageReceiverInfo info, napi_value* res)
```

**描述**

创建应用层ImageReceiver对象。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| struct [OhosImageReceiverInfo](capi-image-ohosimagereceiverinfo.md) info | ImageReceiver数据设置项。 |
| napi_value* res | 应用层的ImageReceiver对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)：<br> IMAGE_RESULT_SUCCESS：操作成功。<br> IMAGE_RESULT_BAD_PARAMETER：参数错误。<br> IMAGE_RESULT_JNI_ENV_ABNORMAL：JNI环境异常。<br>IMAGE_RESULT_INVALID_PARAMETER：参数无效。<br> IMAGE_RESULT_INVALID_PARAMETER：从surface获取参数失败。<br> IMAGE_RESULT_CREATE_SURFACE_FAILED：创建surface失败。<br> IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED：surface分配内存失败。<br> IMAGE_RESULT_GET_SURFACE_FAILED：获取surface失败。<br> IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT：媒体rtsp surface不支持。<br> IMAGE_RESULT_DATA_UNSUPPORT：图像类型不支持。<br> IMAGE_RESULT_MEDIA_DATA_UNSUPPORT：媒体类型不支持。 |

### OH_Image_Receiver_InitImageReceiverNative()

```
ImageReceiverNative* OH_Image_Receiver_InitImageReceiverNative(napi_env env, napi_value source)
```

**描述**

通过应用层ImageReceiver对象初始化native层[ImageReceiverNative](capi-image-imagereceivernative-.md)对象。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value source | napi的ImageReceiver对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageReceiverNative](capi-image-imagereceivernative-.md)* | 操作成功则返回ImageReceiverNative指针；如果操作失败，则返回nullptr。 |

**参考：**

[OH_Image_Receiver_Release](#oh_image_receiver_release)

### OH_Image_Receiver_GetReceivingSurfaceId()

```
int32_t OH_Image_Receiver_GetReceivingSurfaceId(const ImageReceiverNative* native, char* id, size_t len)
```

**描述**

通过[ImageReceiverNative](capi-image-imagereceivernative-.md)获取receiver的id。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | native层的ImageReceiverNative指针。 |
| char* id | 指向字符缓冲区的指针，用于获取字符串的id。 |
| size_t len | id所对应的字符缓冲区的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)：<br>IMAGE_RESULT_SUCCESS：操作成功。<br> IMAGE_RESULT_BAD_PARAMETER：参数错误。<br>IMAGE_RESULT_JNI_ENV_ABNORMAL：JNI环境异常。<br> IMAGE_RESULT_INVALID_PARAMETER：参数无效。<br> IMAGE_RESULT_INVALID_PARAMETER：从surface获取参数失败。<br> IMAGE_RESULT_GET_SURFACE_FAILED：获取surface失败。<br> IMAGE_RESULT_DATA_UNSUPPORT：图像类型不支持。<br> IMAGE_RESULT_MEDIA_DATA_UNSUPPORT：媒体类型不支持。 |

### OH_Image_Receiver_ReadLatestImage()

```
int32_t OH_Image_Receiver_ReadLatestImage(const ImageReceiverNative* native, napi_value* image)
```

**描述**

通过[ImageReceiverNative](capi-image-imagereceivernative-.md)获取最新的一张图片。

注意，此接口需要在[OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)回调后调用，才能正常的接收到数据。并且使用此接口返回Image对象创建的[ImageNative](capi-image-imagenative-.md)使用完毕后需要调用[OH_Image_Release](capi-image-mdk-h.md#oh_image_release)方法释放，释放后才可以继续接收新的数据。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | native层的ImageReceiverNative指针。 |
| napi_value* image | 获取到的应用层的Image指针对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)：<br>IMAGE_RESULT_SUCCESS：操作成功。<br> IMAGE_RESULT_BAD_PARAMETER：参数错误。<br>IMAGE_RESULT_JNI_ENV_ABNORMAL：JNI环境异常。<br> IMAGE_RESULT_INVALID_PARAMETER：参数无效。<br> IMAGE_RESULT_INVALID_PARAMETER：从surface获取参数失败。<br> IMAGE_RESULT_CREATE_SURFACE_FAILED：创建surface失败。<br> IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED：surface分配内存失败。<br> IMAGE_RESULT_GET_SURFACE_FAILED：获取surface失败。<br> IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT：媒体rtsp surface不支持。<br> IMAGE_RESULT_DATA_UNSUPPORT：图像类型不支持。<br> IMAGE_RESULT_MEDIA_DATA_UNSUPPORT：媒体类型不支持。 |

### OH_Image_Receiver_ReadNextImage()

```
int32_t OH_Image_Receiver_ReadNextImage(const ImageReceiverNative* native, napi_value* image)
```

**描述**

通过[ImageReceiverNative](capi-image-imagereceivernative-.md)获取下一张图片。

注意，此接口需要在[OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)回调后调用，才能正常的接收到数据。并且使用此接口返回Image对象创建的[ImageNative](capi-image-imagenative-.md)使用完毕后需要调用[OH_Image_Release](capi-image-mdk-h.md#oh_image_release)方法释放，释放后才可以继续接收新的数据。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | native层的ImageReceiverNative指针。 |
| napi_value* image | 读取到的应用层的Image指针对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)：<br>IMAGE_RESULT_SUCCESS：操作成功。<br> IMAGE_RESULT_BAD_PARAMETER：参数错误。<br>IMAGE_RESULT_JNI_ENV_ABNORMAL：JNI环境异常。<br> IMAGE_RESULT_INVALID_PARAMETER：参数无效。<br> IMAGE_RESULT_INVALID_PARAMETER：从surface获取参数失败。<br> IMAGE_RESULT_CREATE_SURFACE_FAILED：创建surface失败。<br> IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED：surface分配内存失败。<br> IMAGE_RESULT_GET_SURFACE_FAILED：获取surface失败。<br> IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT：媒体rtsp surface不支持。<br> IMAGE_RESULT_DATA_UNSUPPORT：图像类型不支持。<br> IMAGE_RESULT_MEDIA_DATA_UNSUPPORT：媒体类型不支持。 |

### OH_Image_Receiver_On()

```
int32_t OH_Image_Receiver_On(const ImageReceiverNative* native, OH_Image_Receiver_On_Callback callback)
```

**描述**

注册一个[OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)回调事件。每当接收新图片，该回调事件就会响应。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | native层的ImageReceiverNative指针。 |
| [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback | [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)事件的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)：<br>IMAGE_RESULT_SUCCESS：操作成功。<br> IMAGE_RESULT_BAD_PARAMETER：参数错误。<br>IMAGE_RESULT_JNI_ENV_ABNORMAL：JNI环境异常。<br> IMAGE_RESULT_INVALID_PARAMETER：参数无效。<br> IMAGE_RESULT_INVALID_PARAMETER：从surface获取参数失败。<br> IMAGE_RESULT_GET_SURFACE_FAILED：获取surface失败。<br> IMAGE_RESULT_DATA_UNSUPPORT：图像类型不支持。<br> IMAGE_RESULT_MEDIA_DATA_UNSUPPORT：媒体类型不支持。 |

### OH_Image_Receiver_GetSize()


```
int32_t OH_Image_Receiver_GetSize(const ImageReceiverNative* native, struct OhosImageSize* size)
```

**描述**

通过[ImageReceiverNative](capi-image-imagereceivernative-.md)获取ImageReceiver的大小。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | native层的ImageReceiverNative指针。 |
| struct [OhosImageSize](capi-image-ohosimagesize.md)* size | 作为结果的OhosImageSize指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)：<br>IMAGE_RESULT_SUCCESS：操作成功。<br> IMAGE_RESULT_BAD_PARAMETER：参数错误。<br>IMAGE_RESULT_JNI_ENV_ABNORMAL：JNI环境异常。<br> IMAGE_RESULT_INVALID_PARAMETER：参数无效。<br> IMAGE_RESULT_DATA_UNSUPPORT：图像类型不支持。 |

### OH_Image_Receiver_GetCapacity()

```
int32_t OH_Image_Receiver_GetCapacity(const ImageReceiverNative* native, int32_t* capacity)
```

**描述**

通过[ImageReceiverNative](capi-image-imagereceivernative-.md)获取ImageReceiver的容量。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | native层的ImageReceiverNative指针。 |
| int32_t* capacity | 作为结果的指向容量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)：<br>IMAGE_RESULT_SUCCESS：操作成功。<br> IMAGE_RESULT_BAD_PARAMETER：参数错误。<br>IMAGE_RESULT_JNI_ENV_ABNORMAL：JNI环境异常。<br> IMAGE_RESULT_INVALID_PARAMETER：参数无效。<br> IMAGE_RESULT_DATA_UNSUPPORT：图像类型不支持。 |

### OH_Image_Receiver_GetFormat()

```
int32_t OH_Image_Receiver_GetFormat(const ImageReceiverNative* native, int32_t* format)
```

**描述**

通过[ImageReceiverNative](capi-image-imagereceivernative-.md)获取ImageReceiver的格式。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | native层的ImageReceiverNative指针。 |
| int32_t* format | 作为结果的指向格式的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)：<br>IMAGE_RESULT_SUCCESS：操作成功。<br> IMAGE_RESULT_BAD_PARAMETER：参数错误。<br>IMAGE_RESULT_JNI_ENV_ABNORMAL：JNI环境异常。<br> IMAGE_RESULT_INVALID_PARAMETER：参数无效。<br> IMAGE_RESULT_DATA_UNSUPPORT：图像类型不支持。 |

### OH_Image_Receiver_Release()

```
int32_t OH_Image_Receiver_Release(ImageReceiverNative* native)
```

**描述**

释放native层[ImageReceiverNative](capi-image-imagereceivernative-.md)对象。

注意，此方法不能释放应用层ImageReceiver对象。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | native层的ImageReceiverNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)：<br>IMAGE_RESULT_SUCCESS：操作成功。<br> IMAGE_RESULT_BAD_PARAMETER：参数错误。<br> IMAGE_RESULT_INVALID_PARAMETER：参数无效。<br> IMAGE_RESULT_DATA_UNSUPPORT：图像类型不支持。 |


