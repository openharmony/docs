# image_receiver_mdk.h

## 概述

声明从native层获取图片数据的方法。需要链接 <b>libimagendk.z.so</b>和<b>libimage_receiverndk.z.so</b>。

**库：** libimage_receiver_ndk.z.so

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 10

**相关模块：** [Image](capi-image.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OhosImageReceiverInfo](capi-ohosimagereceiverinfo.md) | - | 定义<b>ImageReceiver</b>的相关信息。 |
| [ImageReceiverNative_](capi-imagereceivernative-.md) | ImageReceiverNative | 用于定义ImageReceiverNative数据类型名称。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_Image_Receiver_On_Callback)()](#oh_image_receiver_on_callback) | OH_Image_Receiver_On_Callback | 定义native层图片的回调方法。 |
| [ImageReceiverNative* OH_Image_Receiver_InitImageReceiverNative(napi_env env, napi_value source)](#oh_image_receiver_initimagereceivernative) | - | 通过应用层<b>ImageReceiver</b>对象初始化native层{@link ImageReceiverNative}对象。 |
| [int32_t OH_Image_Receiver_GetReceivingSurfaceId(const ImageReceiverNative* native, char* id, size_t len)](#oh_image_receiver_getreceivingsurfaceid) | - | 通过{@link ImageReceiverNative}获取receiver的id。 |
| [int32_t OH_Image_Receiver_ReadLatestImage(const ImageReceiverNative* native, napi_value* image)](#oh_image_receiver_readlatestimage) | - | 通过{@link ImageReceiverNative}获取最新的一张图片。 |
| [int32_t OH_Image_Receiver_ReadNextImage(const ImageReceiverNative* native, napi_value* image)](#oh_image_receiver_readnextimage) | - | 通过{@link ImageReceiverNative}获取下一张图片。 |
| [int32_t OH_Image_Receiver_On(const ImageReceiverNative* native, OH_Image_Receiver_On_Callback callback)](#oh_image_receiver_on) | - | 注册一个[OH_Image_Receiver_On_Callback](capi-image-receiver-mdk-h.md#oh_image_receiver_on_callback)回调事件。每当接收新图片，该回调事件就会响应。 |
| [int32_t OH_Image_Receiver_GetCapacity(const ImageReceiverNative* native, int32_t* capacity)](#oh_image_receiver_getcapacity) | - | 通过{@link ImageReceiverNative}获取<b>ImageReceiver</b>的容量。 |
| [int32_t OH_Image_Receiver_GetFormat(const ImageReceiverNative* native, int32_t* format)](#oh_image_receiver_getformat) | - | 通过{@link ImageReceiverNative}获取<b>ImageReceiver</b>的格式。 |
| [int32_t OH_Image_Receiver_Release(ImageReceiverNative* native)](#oh_image_receiver_release) | - | 释放native层 {@link ImageReceiverNative} 对象。注意: 此方法不能释放应用层<b>ImageReceiver</b>对象。 |

## 函数说明

### OH_Image_Receiver_On_Callback()

```
typedef void (*OH_Image_Receiver_On_Callback)()
```

**描述**

定义native层图片的回调方法。

**起始版本：** 10

### OH_Image_Receiver_InitImageReceiverNative()

```
ImageReceiverNative* OH_Image_Receiver_InitImageReceiverNative(napi_env env, napi_value source)
```

**描述**

通过应用层<b>ImageReceiver</b>对象初始化native层{@link ImageReceiverNative}对象。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value source | napi的 <b>ImageReceiver</b> 对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| ImageReceiverNative* | 操作成功则返回 {@link ImageReceiverNative} 指针；如果操作失败，则返回nullptr。 |

**参考：**

ImageReceiverNative, OH_Image_Receiver_Release

### OH_Image_Receiver_GetReceivingSurfaceId()

```
int32_t OH_Image_Receiver_GetReceivingSurfaceId(const ImageReceiverNative* native, char* id, size_t len)
```

**描述**

通过{@link ImageReceiverNative}获取receiver的id。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ImageReceiverNative* native | native层的{@link ImageReceiverNative}指针。 |
| char* id | 指向字符缓冲区的指针，用于获取字符串的id。 |
| size_t len | <b>id</b>所对应的字符缓冲区的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果从surface获取参数失败返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果获取surface失败则返回 IMAGE_RESULT_GET_SURFACE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像类型不支持失败则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果媒体类型不支持失败则返回 IMAGE_RESULT_MEDIA_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

ImageReceiverNative

### OH_Image_Receiver_ReadLatestImage()

```
int32_t OH_Image_Receiver_ReadLatestImage(const ImageReceiverNative* native, napi_value* image)
```

**描述**

通过{@link ImageReceiverNative}获取最新的一张图片。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ImageReceiverNative* native | native层的{@link ImageReceiverNative}指针。 |
| napi_value* image | 获取到的应用层的 <b>Image</b> 指针对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果从surface获取参数失败返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建surface失败则返回 IMAGE_RESULT_CREATE_SURFACE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果surface分配内存失败则返回 IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果获取surface失败则返回 IMAGE_RESULT_GET_SURFACE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果媒体rtsp surface不支持则返回 IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像类型不支持失败则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果媒体类型不支持失败则返回 IMAGE_RESULT_MEDIA_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

ImageReceiverNative

### OH_Image_Receiver_ReadNextImage()

```
int32_t OH_Image_Receiver_ReadNextImage(const ImageReceiverNative* native, napi_value* image)
```

**描述**

通过{@link ImageReceiverNative}获取下一张图片。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ImageReceiverNative* native | native层的{@link ImageReceiverNative}指针。 |
| napi_value* image | 读取到的应用层的 <b>Image</b> 指针对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果从surface获取参数失败返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果创建surface失败则返回 IMAGE_RESULT_CREATE_SURFACE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果surface分配内存失败则返回 IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果获取surface失败则返回 IMAGE_RESULT_GET_SURFACE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果媒体rtsp surface不支持则返回 IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像类型不支持失败则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果媒体类型不支持失败则返回 IMAGE_RESULT_MEDIA_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

ImageReceiverNative

### OH_Image_Receiver_On()

```
int32_t OH_Image_Receiver_On(const ImageReceiverNative* native, OH_Image_Receiver_On_Callback callback)
```

**描述**

注册一个[OH_Image_Receiver_On_Callback](capi-image-receiver-mdk-h.md#oh_image_receiver_on_callback)回调事件。每当接收新图片，该回调事件就会响应。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ImageReceiverNative* native | native层的{@link ImageReceiverNative}指针。 |
| [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback | [OH_Image_Receiver_On_Callback](capi-image-receiver-mdk-h.md#oh_image_receiver_on_callback)事件的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果从surface获取参数失败返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果获取surface失败则返回 IMAGE_RESULT_GET_SURFACE_FAILED [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像类型不支持失败则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果媒体类型不支持失败则返回 IMAGE_RESULT_MEDIA_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

ImageReceiverNative

### OH_Image_Receiver_GetCapacity()

```
int32_t OH_Image_Receiver_GetCapacity(const ImageReceiverNative* native, int32_t* capacity)
```

**描述**

通过{@link ImageReceiverNative}获取<b>ImageReceiver</b>的容量。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ImageReceiverNative* native | native层的{@link ImageReceiverNative}指针。 |
| int32_t* capacity | 作为结果的指向容量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像类型不支持失败则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

ImageReceiverNative, OhosImageSize

### OH_Image_Receiver_GetFormat()

```
int32_t OH_Image_Receiver_GetFormat(const ImageReceiverNative* native, int32_t* format)
```

**描述**

通过{@link ImageReceiverNative}获取<b>ImageReceiver</b>的格式。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ImageReceiverNative* native | native层的{@link ImageReceiverNative}指针。 |
| int32_t* format | 作为结果的指向格式的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果JNI环境异常则返回 IMAGE_RESULT_JNI_ENV_ABNORMAL [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像类型不支持失败则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

ImageReceiverNative

### OH_Image_Receiver_Release()

```
int32_t OH_Image_Receiver_Release(ImageReceiverNative* native)
```

**描述**

释放native层 {@link ImageReceiverNative} 对象。注意: 此方法不能释放应用层<b>ImageReceiver</b>对象。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ImageReceiverNative](capi-imagereceivernative-.md)* native | native层的{@link ImageReceiverNative}指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功则返回 IMAGE_RESULT_SUCCESS [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数错误则返回 IMAGE_RESULT_BAD_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果参数无效则返回 IMAGE_RESULT_INVALID_PARAMETER [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)；<br> 如果图像类型不支持失败则返回 IMAGE_RESULT_DATA_UNSUPPORT [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode)。 |

**参考：**

ImageReceiverNative


