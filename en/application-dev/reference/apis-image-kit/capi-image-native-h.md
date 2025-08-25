# image_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## Overview

The file declares the cropping rectangle, size, and component data of an image.

**Library**: libohimage.so

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) | OH_ImageNative | Describes the alias for an image object at the native layer.|

### Functions

| Name| Description|
| -- | -- |
| [Image_ErrorCode OH_ImageNative_GetImageSize(OH_ImageNative *image, Image_Size *size)](#oh_imagenative_getimagesize) | Obtains the [Image_Size](capi-image-nativemodule-image-size.md) information of an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.|
| [Image_ErrorCode OH_ImageNative_GetComponentTypes(OH_ImageNative *image,uint32_t **types, size_t *typeSize)](#oh_imagenative_getcomponenttypes) | Obtains the component types of an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.|
| [Image_ErrorCode OH_ImageNative_GetByteBuffer(OH_ImageNative *image,uint32_t componentType, OH_NativeBuffer **nativeBuffer)](#oh_imagenative_getbytebuffer) | Obtains the buffer corresponding to a component type in an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.|
| [Image_ErrorCode OH_ImageNative_GetBufferSize(OH_ImageNative *image,uint32_t componentType, size_t *size)](#oh_imagenative_getbuffersize) | Obtains the size of the buffer corresponding to a component type in an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.|
| [Image_ErrorCode OH_ImageNative_GetRowStride(OH_ImageNative *image,uint32_t componentType, int32_t *rowStride)](#oh_imagenative_getrowstride) | Obtains the row stride corresponding to a component type in an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.|
| [Image_ErrorCode OH_ImageNative_GetPixelStride(OH_ImageNative *image,uint32_t componentType, int32_t *pixelStride)](#oh_imagenative_getpixelstride) | Obtains the pixel stride corresponding to a component type in an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.|
| [Image_ErrorCode OH_ImageNative_GetTimestamp(OH_ImageNative *image, int64_t *timestamp)](#oh_imagenative_gettimestamp) | Obtains the timestamp of an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.|
| [Image_ErrorCode OH_ImageNative_Release(OH_ImageNative *image)](#oh_imagenative_release) | Releases an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.|

## Function Description

### OH_ImageNative_GetImageSize()

```
Image_ErrorCode OH_ImageNative_GetImageSize(OH_ImageNative *image, Image_Size *size)
```

**Description**

Obtains the [Image_Size](capi-image-nativemodule-image-size.md) information of an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.

If the OH_ImageNative object stores the camera preview stream data (YUV image data), the width and height in **Image_Size** obtained correspond to those of the YUV image. If the OH_ImageNative object stores the camera photo stream data (JPEG image data, which is already encoded), the width in **Image_Size** obtained is the JPEG data size, and the height is 1.

The type of data stored in the OH_ImageNative object depends on whether the application passes the surface ID in the receiver to a previewOutput or captureOutput object of the camera. For details about the best practices of camera preview and photo capture, see [Secondary Processing of Preview Streams (C/C++)](../../media/camera/native-camera-preview-imageReceiver.md) and [Photo Capture (C/C++)](../../media/camera/native-camera-shooting.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | Pointer to an OH_ImageNative object.|
| [Image_Size](capi-image-nativemodule-image-size.md) *size | Pointer to the Image_Size object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_ImageNative_GetComponentTypes()

```
Image_ErrorCode OH_ImageNative_GetComponentTypes(OH_ImageNative *image,uint32_t **types, size_t *typeSize)
```

**Description**

Obtains the component types of an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | Pointer to an OH_ImageNative object.|
| uint32_t **types | Double pointer to the component types obtained.|
| size_t *typeSize | Pointer to the number of component types obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageNative_GetByteBuffer()

```
Image_ErrorCode OH_ImageNative_GetByteBuffer(OH_ImageNative *image,uint32_t componentType, OH_NativeBuffer **nativeBuffer)
```

**Description**

Obtains the buffer corresponding to a component type in an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | Pointer to an OH_ImageNative object.|
| uint32_t componentType | Component type.|
| [OH_NativeBuffer](../apis-arkgraphics2d/capi-oh-nativebuffer-oh-nativebuffer.md) **nativeBuffer | Double pointer to the buffer, which is an OH_NativeBuffer object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageNative_GetBufferSize()

```
Image_ErrorCode OH_ImageNative_GetBufferSize(OH_ImageNative *image,uint32_t componentType, size_t *size)
```

**Description**

Obtains the size of the buffer corresponding to a component type in an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | Pointer to an OH_ImageNative object.|
| uint32_t componentType | Component type.|
| size_t *size | Pointer to the size of the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageNative_GetRowStride()

```
Image_ErrorCode OH_ImageNative_GetRowStride(OH_ImageNative *image,uint32_t componentType, int32_t *rowStride)
```

**Description**

Obtains the row stride corresponding to a component type in an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.

Camera preview stream data must be read based on the stride. For details, see [Secondary Processing of Preview Streams (C/C++)](../../media/camera/native-camera-preview-imageReceiver.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | Pointer to an OH_ImageNative object.|
| uint32_t componentType | Component type.|
| int32_t *rowStride | Pointer to the row stride obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageNative_GetPixelStride()

```
Image_ErrorCode OH_ImageNative_GetPixelStride(OH_ImageNative *image,uint32_t componentType, int32_t *pixelStride)
	
```

**Description**

Obtains the pixel stride corresponding to a component type in an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | Pointer to an OH_ImageNative object.|
| uint32_t componentType | Component type.|
| int32_t *pixelStride | Pointer to the pixel stride obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageNative_GetTimestamp()

```
Image_ErrorCode OH_ImageNative_GetTimestamp(OH_ImageNative *image, int64_t *timestamp)
```

**Description**

Obtains the timestamp of an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object. Timestamps, measured in nanoseconds, are usually monotonically increasing.

The specific meaning and baseline of these timestamps are determined by the image producer, which is the camera in the camera preview and photo scenarios. As a result, images from different producers may carry timestamps with distinct meanings and baselines, making direct comparison between them infeasible.

To obtain the generation time of a photo, you can use [OH_ImageSourceNative_GetImageProperty](capi-image-source-native-h.md#oh_imagesourcenative_getimageproperty) to read the related EXIF information.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | Pointer to an OH_ImageNative object.|
| int64_t *timestamp | Pointer to the timestamp.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageNative_Release()

```
Image_ErrorCode OH_ImageNative_Release(OH_ImageNative *image)
```

**Description**

Releases an [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | Pointer to an OH_ImageNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|
<!--no_check-->