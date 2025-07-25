# image_receiver_mdk.h

## Overview

The **image_receiver_native.h** file declares the APIs used to obtain image data from the native layer.

**Library**: libimage_receiver_ndk.z.so

**File to include**: <multimedia/image_framework/image_receiver_mdk.h>

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](capi-image.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OhosImageReceiverInfo](capi-image-ohosimagereceiverinfo.md) | - | Describes the information about an image receiver.|
| [ImageReceiverNative_](capi-image-imagereceivernative-.md) | ImageReceiverNative | Defines the data type name of the image receiver at the native layer.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_Image_Receiver_On_Callback)()](#oh_image_receiver_on_callback) | OH_Image_Receiver_On_Callback | Defines the callbacks for the image receiver at the native layer.|
| [int32_t OH_Image_Receiver_CreateImageReceiver(napi_env env, struct OhosImageReceiverInfo info, napi_value* res)](#oh_image_receiver_createimagereceiver) | - | Creates an ImageReceiver object at the application layer.|
| [ImageReceiverNative* OH_Image_Receiver_InitImageReceiverNative(napi_env env, napi_value source)](#oh_image_receiver_initimagereceivernative) | - | Initializes an [ImageReceiverNative](capi-image-imagereceivernative-.md) object through an ImageReceiver object.|
| [int32_t OH_Image_Receiver_GetReceivingSurfaceId(const ImageReceiverNative* native, char* id, size_t len)](#oh_image_receiver_getreceivingsurfaceid) | - | Obtains the receiver ID through an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.|
| [int32_t OH_Image_Receiver_ReadLatestImage(const ImageReceiverNative* native, napi_value* image)](#oh_image_receiver_readlatestimage) | - | Obtains the latest image through an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.|
| [int32_t OH_Image_Receiver_ReadNextImage(const ImageReceiverNative* native, napi_value* image)](#oh_image_receiver_readnextimage) | - | Obtains the next image through an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.|
| [int32_t OH_Image_Receiver_On(const ImageReceiverNative* native, OH_Image_Receiver_On_Callback callback)](#oh_image_receiver_on) | - | Registers an [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback. This callback is triggered whenever a new image is received.|
| [int32_t OH_Image_Receiver_GetSize(const ImageReceiverNative* native, struct OhosImageSize* size)](#oh_image_receiver_getsize) | - | Obtains the size of the image receiver through an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.|
| [int32_t OH_Image_Receiver_GetCapacity(const ImageReceiverNative* native, int32_t* capacity)](#oh_image_receiver_getcapacity) | - | Obtains the capacity of the image receiver through an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.|
| [int32_t OH_Image_Receiver_GetFormat(const ImageReceiverNative* native, int32_t* format)](#oh_image_receiver_getformat) | - | Obtains the format of the image receiver through an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.|
| [int32_t OH_Image_Receiver_Release(ImageReceiverNative* native)](#oh_image_receiver_release) | - | Releases an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.<br>This function is not used to release an ImageReceiver object.|

## Function Description

### OH_Image_Receiver_On_Callback()

```
typedef void (*OH_Image_Receiver_On_Callback)()
```

**Description**

Defines the callbacks for the image receiver at the native layer.

**Since**: 10

### OH_Image_Receiver_CreateImageReceiver()

```
int32_t OH_Image_Receiver_CreateImageReceiver(napi_env env, struct OhosImageReceiverInfo info, napi_value* res)
```

**Description**

Creates an ImageReceiver object at the application layer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the NAPI environment.|
| struct [OhosImageReceiverInfo](capi-image-ohosimagereceiverinfo.md) info | Options for setting the ImageReceiver object.|
| napi_value* res | Pointer to the ImageReceiver object at the application layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br> **IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br>**IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_INVALID_PARAMETER**: Obtaining parameters from the surface fails.<br> **IMAGE_RESULT_CREATE_SURFACE_FAILED**: The surface fails to be created.<br> **IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED**: The buffer fails to be allocated to the surface.<br> **IMAGE_RESULT_GET_SURFACE_FAILED**: The surface fails to be obtained.<br> **IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT**: The media RTSP surface is not supported.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image type is not supported.<br> **IMAGE_RESULT_MEDIA_DATA_UNSUPPORT**: The media type is not supported.|

### OH_Image_Receiver_InitImageReceiverNative()

```
ImageReceiverNative* OH_Image_Receiver_InitImageReceiverNative(napi_env env, napi_value source)
```

**Description**

Initializes an [ImageReceiverNative](capi-image-imagereceivernative-.md) object through an ImageReceiver object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the NAPI environment.|
| napi_value source | ImageReceiver object.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageReceiverNative](capi-image-imagereceivernative-.md)* | Pointer to the ImageReceiverNative object obtained. If the operation fails, a null pointer is returned.|

**See also**

[OH_Image_Receiver_Release](#oh_image_receiver_release)

### OH_Image_Receiver_GetReceivingSurfaceId()

```
int32_t OH_Image_Receiver_GetReceivingSurfaceId(const ImageReceiverNative* native, char* id, size_t len)
```

**Description**

Obtains the receiver ID through an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | Pointer to an ImageReceiverNative object.|
| char* id | Pointer to the buffer that stores the ID string obtained.|
| size_t len | Size of the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_INVALID_PARAMETER**: Obtaining parameters from the surface fails.<br> **IMAGE_RESULT_GET_SURFACE_FAILED**: The surface fails to be obtained.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image type is not supported.<br> **IMAGE_RESULT_MEDIA_DATA_UNSUPPORT**: The media type is not supported.|

### OH_Image_Receiver_ReadLatestImage()

```
int32_t OH_Image_Receiver_ReadLatestImage(const ImageReceiverNative* native, napi_value* image)
```

**Description**

Obtains the latest image through an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.

This function can be called to receive data only after the [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback is triggered. When the [ImageNative](capi-image-imagenative-.md) object created by the Image object returned by this function is no longer needed, call [OH_Image_Release](capi-image-mdk-h.md#oh_image_release) to release the object. New data can be received only after the release.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | Pointer to an ImageReceiverNative object.|
| napi_value* image | Pointer to an Image object at the application layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_INVALID_PARAMETER**: Obtaining parameters from the surface fails.<br> **IMAGE_RESULT_CREATE_SURFACE_FAILED**: The surface fails to be created.<br> **IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED**: The buffer fails to be allocated to the surface.<br> **IMAGE_RESULT_GET_SURFACE_FAILED**: The surface fails to be obtained.<br> **IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT**: The media RTSP surface is not supported.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image type is not supported.<br> **IMAGE_RESULT_MEDIA_DATA_UNSUPPORT**: The media type is not supported.|

### OH_Image_Receiver_ReadNextImage()

```
int32_t OH_Image_Receiver_ReadNextImage(const ImageReceiverNative* native, napi_value* image)
```

**Description**

Obtains the next image through an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.

This function can be called to receive data only after the [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback is triggered. When the [ImageNative](capi-image-imagenative-.md) object created by the Image object returned by this function is no longer needed, call [OH_Image_Release](capi-image-mdk-h.md#oh_image_release) to release the object. New data can be received only after the release.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | Pointer to an ImageReceiverNative object.|
| napi_value* image | Pointer to an Image object at the application layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_INVALID_PARAMETER**: Obtaining parameters from the surface fails.<br> **IMAGE_RESULT_CREATE_SURFACE_FAILED**: The surface fails to be created.<br> **IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED**: The buffer fails to be allocated to the surface.<br> **IMAGE_RESULT_GET_SURFACE_FAILED**: The surface fails to be obtained.<br> **IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT**: The media RTSP surface is not supported.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image type is not supported.<br> **IMAGE_RESULT_MEDIA_DATA_UNSUPPORT**: The media type is not supported.|

### OH_Image_Receiver_On()

```
int32_t OH_Image_Receiver_On(const ImageReceiverNative* native, OH_Image_Receiver_On_Callback callback)
```

**Description**

Registers an [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback. This callback is triggered whenever a new image is received.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | Pointer to an ImageReceiverNative object.|
| [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback | [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback to register.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_INVALID_PARAMETER**: Obtaining parameters from the surface fails.<br> **IMAGE_RESULT_GET_SURFACE_FAILED**: The surface fails to be obtained.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image type is not supported.<br> **IMAGE_RESULT_MEDIA_DATA_UNSUPPORT**: The media type is not supported.|

### OH_Image_Receiver_GetSize()


```
int32_t OH_Image_Receiver_GetSize(const ImageReceiverNative* native, struct OhosImageSize* size)
```

**Description**

Obtains the size of the image receiver through an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | Pointer to an ImageReceiverNative object.|
| struct [OhosImageSize](capi-image-ohosimagesize.md)* size | Pointer to the OhosImageSize object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image type is not supported.|

### OH_Image_Receiver_GetCapacity()

```
int32_t OH_Image_Receiver_GetCapacity(const ImageReceiverNative* native, int32_t* capacity)
```

**Description**

Obtains the capacity of the image receiver through an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | Pointer to an ImageReceiverNative object.|
| int32_t* capacity | Pointer to the capacity obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image type is not supported.|

### OH_Image_Receiver_GetFormat()

```
int32_t OH_Image_Receiver_GetFormat(const ImageReceiverNative* native, int32_t* format)
```

**Description**

Obtains the format of the image receiver through an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | Pointer to an ImageReceiverNative object.|
| int32_t* format | Pointer to the format obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image type is not supported.|

### OH_Image_Receiver_Release()

```
int32_t OH_Image_Receiver_Release(ImageReceiverNative* native)
```

**Description**

Releases an [ImageReceiverNative](capi-image-imagereceivernative-.md) object.

This function is not used to release an ImageReceiver object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ImageReceiverNative](capi-image-imagereceivernative-.md)* native | Pointer to an ImageReceiverNative object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image type is not supported.|
