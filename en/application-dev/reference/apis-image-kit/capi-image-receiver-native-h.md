# image_receiver_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the APIs used to obtain image data from the native layer.

**File to include**: <multimedia/image_framework/image/image_receiver_native.h>

**Library**: libimage_receiver.so

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_ImageReceiverNative](capi-image-nativemodule-oh-imagereceivernative.md) | OH_ImageReceiverNative | Describes the image receiver, which is encapsulated at the native layer. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.|
| [OH_ImageReceiverOptions](capi-image-nativemodule-oh-imagereceiveroptions.md) | OH_ImageReceiverOptions | Describes the data type name of the image receiver options.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_ImageReceiver_OnCallback)(OH_ImageReceiverNative *receiver)](#oh_imagereceiver_oncallback) | OH_ImageReceiver_OnCallback | Defines the callbacks for the image receiver at the native layer.|
| [typedef void (\*OH_ImageReceiver_ImageArriveCallback)(OH_ImageReceiverNative *receiver, void *userData)](#oh_imagereceiver_imagearrivecallback) | OH_ImageReceiver_ImageArriveCallback | Defines the callback for the ImageArrive event.|
| [Image_ErrorCode OH_ImageReceiverOptions_Create(OH_ImageReceiverOptions **options)](#oh_imagereceiveroptions_create) | - | Creates an OH_ImageReceiverOptions object at the application layer.|
| [Image_ErrorCode OH_ImageReceiverOptions_GetSize(OH_ImageReceiverOptions* options, Image_Size* size)](#oh_imagereceiveroptions_getsize) | - | Obtains the image size of an OH_ImageReceiverOptions object.|
| [Image_ErrorCode OH_ImageReceiverOptions_SetSize(OH_ImageReceiverOptions* options, Image_Size size)](#oh_imagereceiveroptions_setsize) | - | Sets the image size for an OH_ImageReceiverOptions object.|
| [Image_ErrorCode OH_ImageReceiverOptions_GetCapacity(OH_ImageReceiverOptions* options, int32_t* capacity)](#oh_imagereceiveroptions_getcapacity) | - | Obtains the capacity of an OH_ImageReceiverOptions object.|
| [Image_ErrorCode OH_ImageReceiverOptions_SetCapacity(OH_ImageReceiverOptions* options, int32_t capacity)](#oh_imagereceiveroptions_setcapacity) | - | Sets the capacity for an OH_ImageReceiverOptions object.|
| [Image_ErrorCode OH_ImageReceiverOptions_Release(OH_ImageReceiverOptions* options)](#oh_imagereceiveroptions_release) | - | Releases an OH_ImageReceiverOptions object.|
| [Image_ErrorCode OH_ImageReceiverNative_Create(OH_ImageReceiverOptions* options, OH_ImageReceiverNative** receiver)](#oh_imagereceivernative_create) | - | Creates an OH_ImageReceiverNative object at the application layer.|
| [Image_ErrorCode OH_ImageReceiverNative_GetReceivingSurfaceId(OH_ImageReceiverNative* receiver, uint64_t* surfaceId)](#oh_imagereceivernative_getreceivingsurfaceid) | - | Obtains the surface ID through an OH_ImageReceiverNative object. |
| [Image_ErrorCode OH_ImageReceiverNative_ReadLatestImage(OH_ImageReceiverNative* receiver, OH_ImageNative** image)](#oh_imagereceivernative_readlatestimage) | - | Obtains the latest image through an OH_ImageReceiverNative object.<br>This function can be called to receive data only after the [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback is triggered. When the OH_ImageNative object returned by this function is no longer needed, call [OH_ImageNative_Release](capi-image-native-h.md#oh_imagenative_release) to release the object. New data can be received only after the release.|
| [Image_ErrorCode OH_ImageReceiverNative_ReadNextImage(OH_ImageReceiverNative* receiver, OH_ImageNative** image)](#oh_imagereceivernative_readnextimage) | - | Obtains the next image through an OH_ImageReceiverNative object.<br>This function can be called to receive data only after the [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback is triggered. When the OH_ImageNative object returned by this function is no longer needed, call [OH_ImageNative_Release](capi-image-native-h.md#oh_imagenative_release) to release the object. New data can be received only after the release.|
| [Image_ErrorCode OH_ImageReceiverNative_On(OH_ImageReceiverNative* receiver, OH_ImageReceiver_OnCallback callback)](#oh_imagereceivernative_on) | - | Registers the [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback.<br>This callback is triggered whenever a new image is received.|
| [Image_ErrorCode OH_ImageReceiverNative_Off(OH_ImageReceiverNative* receiver)](#oh_imagereceivernative_off) | - | Unregisters the [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback.<br>The callback is registered by calling [OH_ImageReceiverNative_On](#oh_imagereceivernative_on).|
| [Image_ErrorCode OH_ImageReceiverNative_GetSize(OH_ImageReceiverNative* receiver, Image_Size* size)](#oh_imagereceivernative_getsize) | - | Obtains the size of an **OH_ImageReceiverNative**.|
| [Image_ErrorCode OH_ImageReceiverNative_GetCapacity(OH_ImageReceiverNative* receiver, int32_t* capacity)](#oh_imagereceivernative_getcapacity) | - | Obtains the capacity of an **OH_ImageReceiverNative**.|
| [Image_ErrorCode OH_ImageReceiverNative_Release(OH_ImageReceiverNative* receiver)](#oh_imagereceivernative_release) | - | Releases an OH_ImageReceiverNative object.|
| [Image_ErrorCode OH_ImageReceiverNative_OnImageArrive(OH_ImageReceiverNative *receiver, OH_ImageReceiver_ImageArriveCallback callback, void *userData)](#oh_imagereceivernative_onimagearrive) | - | Registers the [OH_ImageReceiver_ImageArriveCallback](#oh_imagereceiver_imagearrivecallback) callback.|
| [Image_ErrorCode OH_ImageReceiverNative_OffImageArrive(OH_ImageReceiverNative *receiver, OH_ImageReceiver_ImageArriveCallback callback)](#oh_imagereceivernative_offimagearrive) | - | Unregisters the [OH_ImageReceiver_ImageArriveCallback](#oh_imagereceiver_imagearrivecallback) callback.|

## Function Description

### OH_ImageReceiver_OnCallback()

```
typedef void (*OH_ImageReceiver_OnCallback)(OH_ImageReceiverNative *receiver)
```

**Description**

Defines the callbacks for the image receiver at the native layer.

**Since**: 12

### OH_ImageReceiver_ImageArriveCallback()

```
typedef void (*OH_ImageReceiver_ImageArriveCallback)(OH_ImageReceiverNative *receiver, void *userData)
```

**Description**

Defines the callback for the ImageArrive event.

**Since**: 20

### OH_ImageReceiverOptions_Create()

```
Image_ErrorCode OH_ImageReceiverOptions_Create(OH_ImageReceiverOptions **options)
```

**Description**

Creates an OH_ImageReceiverOptions object at the application layer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverOptions](capi-image-nativemodule-oh-imagereceiveroptions.md) **options | Double pointer to the OH_ImageReceiverOptions object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br> **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_ALLOC_FAILED**: Memory allocation fails.|

### OH_ImageReceiverOptions_GetSize()

```
Image_ErrorCode OH_ImageReceiverOptions_GetSize(OH_ImageReceiverOptions* options, Image_Size* size)
```

**Description**

Obtains the image size of an OH_ImageReceiverOptions object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverOptions](capi-image-nativemodule-oh-imagereceiveroptions.md)* options | Pointer to an OH_ImageReceiverOptions object.|
| [Image_Size](capi-image-nativemodule-image-size.md)* size | Pointer to the Image_Size object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageReceiverOptions_SetSize()

```
Image_ErrorCode OH_ImageReceiverOptions_SetSize(OH_ImageReceiverOptions* options, Image_Size size)
```

**Description**

Sets the image size for an OH_ImageReceiverOptions object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverOptions](capi-image-nativemodule-oh-imagereceiveroptions.md)* options| Pointer to an OH_ImageReceiverOptions object.|
| [Image_Size](capi-image-nativemodule-image-size.md) size | Image_Size object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageReceiverOptions_GetCapacity()

```
Image_ErrorCode OH_ImageReceiverOptions_GetCapacity(OH_ImageReceiverOptions* options, int32_t* capacity)
```

**Description**

Obtains the capacity of an OH_ImageReceiverOptions object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverOptions](capi-image-nativemodule-oh-imagereceiveroptions.md)* options| Pointer to an OH_ImageReceiverOptions object.|
| int32_t* capacity | Pointer to the capacity obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageReceiverOptions_SetCapacity()

```
Image_ErrorCode OH_ImageReceiverOptions_SetCapacity(OH_ImageReceiverOptions* options, int32_t capacity)
```

**Description**

Sets the capacity for an OH_ImageReceiverOptions object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverOptions](capi-image-nativemodule-oh-imagereceiveroptions.md)* options| Pointer to an OH_ImageReceiverOptions object.|
| int32_t capacity | Capacity.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageReceiverOptions_Release()

```
Image_ErrorCode OH_ImageReceiverOptions_Release(OH_ImageReceiverOptions* options)
```

**Description**

Releases an OH_ImageReceiverOptions object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverOptions](capi-image-nativemodule-oh-imagereceiveroptions.md)* options| Pointer to an OH_ImageReceiverOptions object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageReceiverNative_Create()

```
Image_ErrorCode OH_ImageReceiverNative_Create(OH_ImageReceiverOptions* options, OH_ImageReceiverNative** receiver)
```

**Description**

Creates an OH_ImageReceiverNative object at the application layer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverOptions](capi-image-nativemodule-oh-imagereceiveroptions.md)* options| Pointer to an OH_ImageReceiverOptions object.|
| [OH_ImageReceiverNative](capi-image-nativemodule-oh-imagereceivernative.md)** receiver | Double pointer to the OH_ImageReceiverNative object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br> **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_ALLOC_FAILED**: Memory allocation fails.|

### OH_ImageReceiverNative_GetReceivingSurfaceId()

```
Image_ErrorCode OH_ImageReceiverNative_GetReceivingSurfaceId(OH_ImageReceiverNative* receiver, uint64_t* surfaceId)
```

**Description**

Obtains the surface ID through an OH_ImageReceiverNative object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverNative](capi-image-nativemodule-oh-imagereceivernative.md)* receiver | Pointer to an OH_ImageReceiverNative object.|
| uint64_t* surfaceId | Pointer to the surface ID obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br> **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_ImageReceiverNative_ReadLatestImage()

```
Image_ErrorCode OH_ImageReceiverNative_ReadLatestImage(OH_ImageReceiverNative* receiver, OH_ImageNative** image)
```

**Description**

Obtains the latest image through an OH_ImageReceiverNative object.

This function can be called to receive data only after the [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback is triggered. When the OH_ImageNative object returned by this function is no longer needed, call [OH_ImageNative_Release](capi-image-native-h.md#oh_imagenative_release) to release the object. New data can be received only after the release.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverNative](capi-image-nativemodule-oh-imagereceivernative.md)* receiver | Pointer to an OH_ImageReceiverNative object.|
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)** image | Double pointer to the image obtained, which is an OH_ImageNative object at the application layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br> **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.<br> **IMAGE_ALLOC_FAILED**: Memory allocation fails.|

### OH_ImageReceiverNative_ReadNextImage()

```
Image_ErrorCode OH_ImageReceiverNative_ReadNextImage(OH_ImageReceiverNative* receiver, OH_ImageNative** image)
```

**Description**

Obtains the next image through an OH_ImageReceiverNative object.

This function can be called to receive data only after the [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback is triggered. When the OH_ImageNative object returned by this function is no longer needed, call [OH_ImageNative_Release](capi-image-native-h.md#oh_imagenative_release) to release the object. New data can be received only after the release.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverNative](capi-image-nativemodule-oh-imagereceivernative.md)* receiver | Pointer to an OH_ImageReceiverNative object.|
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)** image | Double pointer to the image obtained, which is an OH_ImageNative object at the application layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br> **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.<br> **IMAGE_ALLOC_FAILED**: Memory allocation fails.|

### OH_ImageReceiverNative_On()

```
Image_ErrorCode OH_ImageReceiverNative_On(OH_ImageReceiverNative* receiver, OH_ImageReceiver_OnCallback callback)
```

**Description**

Registers the [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback.

This callback is triggered whenever a new image is received.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverNative](capi-image-nativemodule-oh-imagereceivernative.md)* receiver | Pointer to an OH_ImageReceiverNative object.|
| [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback | Callback to register.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageReceiverNative_Off()

```
Image_ErrorCode OH_ImageReceiverNative_Off(OH_ImageReceiverNative* receiver)
```

**Description**

Unregisters the [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback.

The callback is registered by calling [OH_ImageReceiverNative_On](#oh_imagereceivernative_on).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverNative](capi-image-nativemodule-oh-imagereceivernative.md)* receiver | Pointer to an OH_ImageReceiverNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageReceiverNative_GetSize()

```
Image_ErrorCode OH_ImageReceiverNative_GetSize(OH_ImageReceiverNative* receiver, Image_Size* size)
```

**Description**

Obtains the size of an **OH_ImageReceiverNative**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverNative](capi-image-nativemodule-oh-imagereceivernative.md)* receiver | Pointer to an OH_ImageReceiverNative object.|
| [Image_Size](capi-image-nativemodule-image-size.md)* size | Pointer to the Image_Size object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageReceiverNative_GetCapacity()

```
Image_ErrorCode OH_ImageReceiverNative_GetCapacity(OH_ImageReceiverNative* receiver, int32_t* capacity)
```

**Description**

Obtains the capacity of an **OH_ImageReceiverNative**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverNative](capi-image-nativemodule-oh-imagereceivernative.md)* receiver | Pointer to an OH_ImageReceiverNative object.|
| int32_t* capacity | Pointer to the capacity obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageReceiverNative_Release()

```
Image_ErrorCode OH_ImageReceiverNative_Release(OH_ImageReceiverNative* receiver)
```

**Description**

Releases an OH_ImageReceiverNative object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverNative](capi-image-nativemodule-oh-imagereceivernative.md)* receiver | Pointer to an OH_ImageReceiverNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageReceiverNative_OnImageArrive()

```
Image_ErrorCode OH_ImageReceiverNative_OnImageArrive(OH_ImageReceiverNative *receiver,OH_ImageReceiver_ImageArriveCallback callback, void *userData)
```

**Description**

Registers the [OH_ImageReceiver_ImageArriveCallback](#oh_imagereceiver_imagearrivecallback) callback.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverNative](capi-image-nativemodule-oh-imagereceivernative.md) *receiver | Pointer to an OH_ImageReceiverNative object that processes the callback.|
| [OH_ImageReceiver_ImageArriveCallback](#oh_imagereceiver_imagearrivecallback) callback | Callback to register.|
| void *userData | Pointer to user data.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_RECEIVER_INVALID_PARAMETER**: A parameter is incorrect.|

### OH_ImageReceiverNative_OffImageArrive()

```
Image_ErrorCode OH_ImageReceiverNative_OffImageArrive(OH_ImageReceiverNative *receiver,OH_ImageReceiver_ImageArriveCallback callback)
```

**Description**

Unregisters the [OH_ImageReceiver_ImageArriveCallback](#oh_imagereceiver_imagearrivecallback) callback.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageReceiverNative](capi-image-nativemodule-oh-imagereceivernative.md) *receiver | Pointer to an OH_ImageReceiverNative object that processes the callback.|
| [OH_ImageReceiver_ImageArriveCallback](#oh_imagereceiver_imagearrivecallback) callback | Callback to unregister.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) |**IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_RECEIVER_INVALID_PARAMETER**: The **receiver** or **callback** parameter is not registered.|
