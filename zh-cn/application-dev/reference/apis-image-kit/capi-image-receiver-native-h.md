# image_receiver_native.h

## 概述

声明从native层获取图片数据的方法。

**库：** libimage_receiver.so

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) | OH_ImageReceiverNative | 用于定义OH_ImageReceiverNative数据类型名称。 |
| [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) | OH_ImageReceiverOptions | 用于定义OH_ImageReceiverOptions数据类型名称。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_ImageReceiver_OnCallback)(OH_ImageReceiverNative *receiver)](#oh_imagereceiver_oncallback) | OH_ImageReceiver_OnCallback | 定义native层图片的回调方法。 |
| [typedef void (\*OH_ImageReceiver_ImageArriveCallback)(OH_ImageReceiverNative *receiver, void *userData)](#oh_imagereceiver_imagearrivecallback) | OH_ImageReceiver_ImageArriveCallback | ImageArrive事件的回调方法。 |
| [Image_ErrorCode OH_ImageReceiverOptions_Create(OH_ImageReceiverOptions **options)](#oh_imagereceiveroptions_create) | - | 创建应用层 OH_ImageReceiverOptions 对象。 |
| [Image_ErrorCode OH_ImageReceiverOptions_GetSize(OH_ImageReceiverOptions* options, Image_Size* size)](#oh_imagereceiveroptions_getsize) | - | 获取 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的 {@link Image_Size} 信息。 |
| [Image_ErrorCode OH_ImageReceiverOptions_SetSize(OH_ImageReceiverOptions* options, Image_Size size)](#oh_imagereceiveroptions_setsize) | - | 设置 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的 {@link Image_Size} 信息。 |
| [Image_ErrorCode OH_ImageReceiverOptions_GetCapacity(OH_ImageReceiverOptions* options, int32_t* capacity)](#oh_imagereceiveroptions_getcapacity) | - | 获取 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的图片缓存容量的信息。 |
| [Image_ErrorCode OH_ImageReceiverOptions_SetCapacity(OH_ImageReceiverOptions* options, int32_t capacity)](#oh_imagereceiveroptions_setcapacity) | - | 设置 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的图片缓存容量的信息。 |
| [Image_ErrorCode OH_ImageReceiverOptions_Release(OH_ImageReceiverOptions* options)](#oh_imagereceiveroptions_release) | - | 释放 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象。 |
| [Image_ErrorCode OH_ImageReceiverNative_Create(OH_ImageReceiverOptions* options, OH_ImageReceiverNative** receiver)](#oh_imagereceivernative_create) | - | 创建应用层 OH_ImageReceiverNative 对象。 |
| [Image_ErrorCode OH_ImageReceiverNative_GetReceivingSurfaceId(OH_ImageReceiverNative* receiver, uint64_t* surfaceId)](#oh_imagereceivernative_getreceivingsurfaceid) | - | 通过[OH_ImageReceiverNative](capi-oh-imagereceivernative.md)获取SurfaceId。 |
| [Image_ErrorCode OH_ImageReceiverNative_ReadLatestImage(OH_ImageReceiverNative* receiver, OH_ImageNative** image)](#oh_imagereceivernative_readlatestimage) | - | 通过[OH_ImageReceiverNative](capi-oh-imagereceivernative.md)获取最新的一张图片。 |
| [Image_ErrorCode OH_ImageReceiverNative_ReadNextImage(OH_ImageReceiverNative* receiver, OH_ImageNative** image)](#oh_imagereceivernative_readnextimage) | - | 通过[OH_ImageReceiverNative](capi-oh-imagereceivernative.md)获取下一张图片。 |
| [Image_ErrorCode OH_ImageReceiverNative_On(OH_ImageReceiverNative* receiver, OH_ImageReceiver_OnCallback callback)](#oh_imagereceivernative_on) | - | 注册一个[OH_ImageReceiver_OnCallback](capi-image-receiver-native-h.md#oh_imagereceiver_oncallback)回调事件。每当接收到新的图片，该回调事件就会响应。 |
| [Image_ErrorCode OH_ImageReceiverNative_Off(OH_ImageReceiverNative* receiver)](#oh_imagereceivernative_off) | - | 关闭[OH_ImageReceiver_OnCallback](capi-image-receiver-native-h.md#oh_imagereceiver_oncallback)回调事件。关闭被 [OH_ImageReceiverNative_On](capi-image-receiver-native-h.md#oh_imagereceivernative_on) 开启的回调事件。 |
| [Image_ErrorCode OH_ImageReceiverNative_GetSize(OH_ImageReceiverNative* receiver, Image_Size* size)](#oh_imagereceivernative_getsize) | - | 通过[OH_ImageReceiverNative](capi-oh-imagereceivernative.md)获取ImageReceiver的大小。 |
| [Image_ErrorCode OH_ImageReceiverNative_GetCapacity(OH_ImageReceiverNative* receiver, int32_t* capacity)](#oh_imagereceivernative_getcapacity) | - | 通过[OH_ImageReceiverNative](capi-oh-imagereceivernative.md)获取ImageReceiver的容量。 |
| [Image_ErrorCode OH_ImageReceiverNative_Release(OH_ImageReceiverNative* receiver)](#oh_imagereceivernative_release) | - | 释放native [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) 对象。 |
| [Image_ErrorCode OH_ImageReceiverNative_OnImageArrive(OH_ImageReceiverNative *receiver,OH_ImageReceiver_ImageArriveCallback callback, void *userData)](#oh_imagereceivernative_onimagearrive) | - | 注册[OH_ImageReceiver_ImageArriveCallback](capi-image-receiver-native-h.md#oh_imagereceiver_imagearrivecallback) 回调。 |
| [Image_ErrorCode OH_ImageReceiverNative_OffImageArrive(OH_ImageReceiverNative *receiver,OH_ImageReceiver_ImageArriveCallback callback)](#oh_imagereceivernative_offimagearrive) | - | 去注册[OH_ImageReceiver_ImageArriveCallback](capi-image-receiver-native-h.md#oh_imagereceiver_imagearrivecallback) 回调。 |

## 函数说明

### OH_ImageReceiver_OnCallback()

```
typedef void (*OH_ImageReceiver_OnCallback)(OH_ImageReceiverNative *receiver)
```

**描述**

定义native层图片的回调方法。

**起始版本：** 12

### OH_ImageReceiver_ImageArriveCallback()

```
typedef void (*OH_ImageReceiver_ImageArriveCallback)(OH_ImageReceiverNative *receiver, void *userData)
```

**描述**

ImageArrive事件的回调方法。

**起始版本：** 20

### OH_ImageReceiverOptions_Create()

```
Image_ErrorCode OH_ImageReceiverOptions_Create(OH_ImageReceiverOptions **options)
```

**描述**

创建应用层 OH_ImageReceiverOptions 对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) **options | 表示作为获取结果的 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 如果申请内存失败返回 IMAGE_ALLOC_FAILED；<br> 具体释义参考{@link Image_ErrorCode}。 |

### OH_ImageReceiverOptions_GetSize()

```
Image_ErrorCode OH_ImageReceiverOptions_GetSize(OH_ImageReceiverOptions* options, Image_Size* size)
```

**描述**

获取 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的 {@link Image_Size} 信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md)* options | 表示 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的指针。 |
| Image_Size* size | 表示作为获取结果的 {@link Image_Size} 对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考{@link Image_ErrorCode}。 |

### OH_ImageReceiverOptions_SetSize()

```
Image_ErrorCode OH_ImageReceiverOptions_SetSize(OH_ImageReceiverOptions* options, Image_Size size)
```

**描述**

设置 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的 {@link Image_Size} 信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md)* options | 表示 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的指针。 |
| Image_Size size | 表示 {@link Image_Size} 对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考{@link Image_ErrorCode}。 |

### OH_ImageReceiverOptions_GetCapacity()

```
Image_ErrorCode OH_ImageReceiverOptions_GetCapacity(OH_ImageReceiverOptions* options, int32_t* capacity)
```

**描述**

获取 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的图片缓存容量的信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md)* options | 表示 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的指针。 |
| int32_t* capacity | 表示作为获取结果的图片缓存容量对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考{@link Image_ErrorCode}。 |

### OH_ImageReceiverOptions_SetCapacity()

```
Image_ErrorCode OH_ImageReceiverOptions_SetCapacity(OH_ImageReceiverOptions* options, int32_t capacity)
```

**描述**

设置 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的图片缓存容量的信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md)* options | 表示 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的指针。 |
| int32_t capacity | 表示图片缓存容量对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考{@link Image_ErrorCode}。 |

### OH_ImageReceiverOptions_Release()

```
Image_ErrorCode OH_ImageReceiverOptions_Release(OH_ImageReceiverOptions* options)
```

**描述**

释放 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md)* options | 表示 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考{@link Image_ErrorCode}。 |

**参考：**

OH_ImageReceiverOptions

### OH_ImageReceiverNative_Create()

```
Image_ErrorCode OH_ImageReceiverNative_Create(OH_ImageReceiverOptions* options, OH_ImageReceiverNative** receiver)
```

**描述**

创建应用层 OH_ImageReceiverNative 对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md)* options | 表示 [OH_ImageReceiverOptions](capi-oh-imagereceiveroptions.md) 对象的指针。 |
| [OH_ImageReceiverNative](capi-oh-imagereceivernative.md)** receiver | 表示作为获取结果的 [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) 对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 如果申请内存失败返回 IMAGE_ALLOC_FAILED；<br> 具体释义参考{@link Image_ErrorCode}。 |

### OH_ImageReceiverNative_GetReceivingSurfaceId()

```
Image_ErrorCode OH_ImageReceiverNative_GetReceivingSurfaceId(OH_ImageReceiverNative* receiver, uint64_t* surfaceId)
```

**描述**

通过[OH_ImageReceiverNative](capi-oh-imagereceivernative.md)获取SurfaceId。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverNative](capi-oh-imagereceivernative.md)* receiver | 表示 [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) 对象的指针。 |
| uint64_t* surfaceId | 表示作为获取结果的id对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 如果未知原因错误返回 IMAGE_UNKNOWN_ERROR；<br> 具体释义参考{@link Image_ErrorCode}。 |

**参考：**

OH_ImageReceiverNative

### OH_ImageReceiverNative_ReadLatestImage()

```
Image_ErrorCode OH_ImageReceiverNative_ReadLatestImage(OH_ImageReceiverNative* receiver, OH_ImageNative** image)
```

**描述**

通过[OH_ImageReceiverNative](capi-oh-imagereceivernative.md)获取最新的一张图片。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverNative](capi-oh-imagereceivernative.md)* receiver | 表示 [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) 对象的指针。 |
| [OH_ImageNative](capi-oh-imagenative.md)** image | 获取到的应用层的 OH_ImageNative 指针对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 如果未知原因错误返回 IMAGE_UNKNOWN_ERROR；<br> 如果申请内存失败返回 IMAGE_ALLOC_FAILED；<br> 具体释义参考{@link Image_ErrorCode}。 |

**参考：**

OH_ImageReceiverNative, OH_ImageNative

### OH_ImageReceiverNative_ReadNextImage()

```
Image_ErrorCode OH_ImageReceiverNative_ReadNextImage(OH_ImageReceiverNative* receiver, OH_ImageNative** image)
```

**描述**

通过[OH_ImageReceiverNative](capi-oh-imagereceivernative.md)获取下一张图片。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverNative](capi-oh-imagereceivernative.md)* receiver | 表示 [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) 对象的指针。 |
| [OH_ImageNative](capi-oh-imagenative.md)** image | 获取到的应用层的 OH_ImageNative 指针对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 如果未知原因错误返回 IMAGE_UNKNOWN_ERROR；<br> 如果申请内存失败返回 IMAGE_ALLOC_FAILED；<br> 具体释义参考{@link Image_ErrorCode}。 |

**参考：**

OH_ImageReceiverNative, OH_ImageNative

### OH_ImageReceiverNative_On()

```
Image_ErrorCode OH_ImageReceiverNative_On(OH_ImageReceiverNative* receiver, OH_ImageReceiver_OnCallback callback)
```

**描述**

注册一个[OH_ImageReceiver_OnCallback](capi-image-receiver-native-h.md#oh_imagereceiver_oncallback)回调事件。每当接收到新的图片，该回调事件就会响应。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverNative](capi-oh-imagereceivernative.md)* receiver | 表示 [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) 对象的指针。 |
| [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback | 表示 [OH_ImageReceiver_OnCallback](capi-image-receiver-native-h.md#oh_imagereceiver_oncallback) 事件的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考{@link Image_ErrorCode}。 |

**参考：**

OH_ImageReceiverNative, OH_ImageReceiver_OnCallback

### OH_ImageReceiverNative_Off()

```
Image_ErrorCode OH_ImageReceiverNative_Off(OH_ImageReceiverNative* receiver)
```

**描述**

关闭[OH_ImageReceiver_OnCallback](capi-image-receiver-native-h.md#oh_imagereceiver_oncallback)回调事件。关闭被 [OH_ImageReceiverNative_On](capi-image-receiver-native-h.md#oh_imagereceivernative_on) 开启的回调事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverNative](capi-oh-imagereceivernative.md)* receiver | 表示 [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) 对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考{@link Image_ErrorCode}。 |

**参考：**

OH_ImageReceiverNative, OH_ImageReceiverNative_On

### OH_ImageReceiverNative_GetSize()

```
Image_ErrorCode OH_ImageReceiverNative_GetSize(OH_ImageReceiverNative* receiver, Image_Size* size)
```

**描述**

通过[OH_ImageReceiverNative](capi-oh-imagereceivernative.md)获取ImageReceiver的大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverNative](capi-oh-imagereceivernative.md)* receiver | 表示 [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) 对象的指针。 |
| Image_Size* size | 表示作为获取结果的 {@link Image_Size} 对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考{@link Image_ErrorCode}。 |

**参考：**

OH_ImageReceiverNative, Image_Size

### OH_ImageReceiverNative_GetCapacity()

```
Image_ErrorCode OH_ImageReceiverNative_GetCapacity(OH_ImageReceiverNative* receiver, int32_t* capacity)
```

**描述**

通过[OH_ImageReceiverNative](capi-oh-imagereceivernative.md)获取ImageReceiver的容量。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverNative](capi-oh-imagereceivernative.md)* receiver | 表示 [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) 对象的指针。 |
| int32_t* capacity | 表示作为获取结果的图片缓存容量对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考{@link Image_ErrorCode}。 |

**参考：**

OH_ImageReceiverNative

### OH_ImageReceiverNative_Release()

```
Image_ErrorCode OH_ImageReceiverNative_Release(OH_ImageReceiverNative* receiver)
```

**描述**

释放native [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) 对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverNative](capi-oh-imagereceivernative.md)* receiver | 表示 [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) 对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考{@link Image_ErrorCode}。 |

**参考：**

OH_ImageReceiverNative

### OH_ImageReceiverNative_OnImageArrive()

```
Image_ErrorCode OH_ImageReceiverNative_OnImageArrive(OH_ImageReceiverNative *receiver,OH_ImageReceiver_ImageArriveCallback callback, void *userData)
```

**描述**

注册[OH_ImageReceiver_ImageArriveCallback](capi-image-receiver-native-h.md#oh_imagereceiver_imagearrivecallback) 回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) *receiver | 处理回调的OH_ImageReceiverNative对象。 |
| [OH_ImageReceiver_ImageArriveCallback](#oh_imagereceiver_imagearrivecallback) callback | 要注册的OH_ImageReceiver_ImageArriveCallback回调方法。 |
| void *userData | 用户自定义数据指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | {@link Image_ErrorCode}：<br>         IMAGE_SUCCESS = 0 ：操作成功。<br>         IMAGE_RECEIVER_INVALID_PARAMETER = 7900201 ：参数错误。 |

### OH_ImageReceiverNative_OffImageArrive()

```
Image_ErrorCode OH_ImageReceiverNative_OffImageArrive(OH_ImageReceiverNative *receiver,OH_ImageReceiver_ImageArriveCallback callback)
```

**描述**

去注册[OH_ImageReceiver_ImageArriveCallback](capi-image-receiver-native-h.md#oh_imagereceiver_imagearrivecallback) 回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageReceiverNative](capi-oh-imagereceivernative.md) *receiver | 处理回调的OH_ImageReceiverNative对象。 |
| [OH_ImageReceiver_ImageArriveCallback](#oh_imagereceiver_imagearrivecallback) callback | 要注册的OH_ImageReceiver_ImageArriveCallback回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| Image_ErrorCode | {@link Image_ErrorCode}：<br>         IMAGE_SUCCESS = 0 ：操作成功。<br>         IMAGE_RECEIVER_INVALID_PARAMETER = 7900201 ： 参数错误，receiver或callback未注册。 |


