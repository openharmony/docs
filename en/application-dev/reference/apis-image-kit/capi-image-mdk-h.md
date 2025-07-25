# image_mdk.h

## Overview

The **image_mdk.h** file declares the APIs used to access the image rectangle, size, format, and component data.

**Library**: libimage_ndk.z.so

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](capi-image.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OhosImageRect](capi-image-ohosimagerect.md) | - | Describes the information about an image rectangle.|
| [ImageNative_](capi-image-imagenative-.md) | ImageNative | Describes an image object at the native layer.|
| [OhosImageComponent](capi-image-ohosimagecomponent.md) | - | Describes the information about an image component.|

### Enums

| Name| Description|
| -- | -- |
| [Image Formats](#image-formats)| Enumerates the image formats.|
| [Image Color Channel Types](#image-color-channel-types)| Enumerates the image color channel types.|

### Functions

| Name| Description|
| -- | -- |
| [ImageNative* OH_Image_InitImageNative(napi_env env, napi_value source)](#oh_image_initimagenative) | Converts an Image object at the JavaScript native layer into an ImageNative object.|
| [int32_t OH_Image_ClipRect(const ImageNative* native, struct OhosImageRect* rect)](#oh_image_cliprect) | Obtains OhosImageRect of an ImageNative object.|
| [int32_t OH_Image_Size(const ImageNative* native, struct OhosImageSize* size)](#oh_image_size) | Obtains OhosImageSize of an ImageNative object.|
| [int32_t OH_Image_Format(const ImageNative* native, int32_t* format)](#oh_image_format) | Obtains the format of an ImageNative object.|
| [int32_t OH_Image_GetComponent(const ImageNative* native, int32_t componentType, struct OhosImageComponent* componentNative)](#oh_image_getcomponent) |  Obtains OhosImageComponent of an ImageNative object.|
| [int32_t OH_Image_Release(ImageNative* native)](#oh_image_release) | Releases an ImageNative object.<br>This function is not used to release an Image object at the JavaScript native API. It is used to release an ImageNative object parsed by calling [OH_Image_InitImageNative](capi-image-mdk-h.md#oh_image_initimagenative).|

## Enum Description

### Image Formats

```
enum anonymous enum
```

**Description**

Enumerates the image formats.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| OHOS_IMAGE_FORMAT_YCBCR_422_SP = 1000 | YCbCr422 semi-planar format.|
| OHOS_IMAGE_FORMAT_JPEG = 2000 | JPEG encoding format.|

### Image Color Channel Types

```
enum anonymous enum
```

**Description**

Enumerates the image color channel types.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| OHOS_IMAGE_COMPONENT_FORMAT_YUV_Y = 1 | Luminance component.|
| OHOS_IMAGE_COMPONENT_FORMAT_YUV_U = 2 | Chrominance component - blue projection.|
| OHOS_IMAGE_COMPONENT_FORMAT_YUV_V = 3 | Chrominance component - red projection.|
| OHOS_IMAGE_COMPONENT_FORMAT_JPEG = 4 | JPEG format.|


## Function Description

### OH_Image_InitImageNative()

```
ImageNative* OH_Image_InitImageNative(napi_env env, napi_value source)
```

**Description**

Parses an ImageNative object from an Image object at the JavaScript native layer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the JNI environment.|
| napi_value source | Image object at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageNative](capi-image-imagenative-.md)* | Pointer to the ImageNative object. If the operation fails, a null pointer is returned.|

**See also**

[OH_Image_Release](#oh_image_release)

### OH_Image_ClipRect()

```
int32_t OH_Image_ClipRect(const ImageNative* native, struct OhosImageRect* rect)
```

**Description**

Obtains OhosImageRect of an ImageNative object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageNative](capi-image-imagenative-.md)* native | Pointer to an ImageNative object.|
| struct [OhosImageRect](capi-image-ohosimagerect.md)* rect | Pointer to the OhosImageRect object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br>**IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED**: Obtaining parameters from the surface fails.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.|

### OH_Image_Size()

```
int32_t OH_Image_Size(const ImageNative* native, struct OhosImageSize* size)
```

**Description**

Obtains OhosImageSize of an ImageNative object.

If the ImageNative object stores the camera preview stream data (YUV image data), the width and height in **OhosImageSize** obtained correspond to those of the YUV image. If the ImageNative object stores the camera photo stream data (JPEG image data, which is already encoded), the width in **OhosImageSize** obtained is the JPEG data size, and the height is 1.

The type of data stored in the ImageNative object depends on whether the application passes the surface ID in the receiver to a previewOutput or captureOutput object of the camera. For details about the best practices of camera preview and photo capture, see [Secondary Processing of Preview Streams (C/C++)](../../media/camera/native-camera-preview-imageReceiver.md) and [Photo Capture (C/C++)](../../media/camera/native-camera-shooting.md).

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageNative](capi-image-imagenative-.md)* native | Pointer to an ImageNative object.|
| struct [OhosImageSize](capi-image-ohosimagesize.md)* size | Pointer to the OhosImageSize object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br>**IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED**: Obtaining parameters from the surface fails.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.|

### OH_Image_Format()

```
int32_t OH_Image_Format(const ImageNative* native, int32_t* format)
```

**Description**

Obtains the format of an ImageNative object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageNative](capi-image-imagenative-.md)* native | Pointer to an ImageNative object.|
| int32_t* format | Pointer to the image format obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br>**IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED**: Obtaining parameters from the surface fails.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.|

### OH_Image_GetComponent()

```
int32_t OH_Image_GetComponent(const ImageNative* native, int32_t componentType, struct OhosImageComponent* componentNative)
```

**Description**

Obtains OhosImageComponent of an ImageNative object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageNative](capi-image-imagenative-.md)* native | Pointer to an ImageNative object.|
| int32_t componentType | Type of the component.|
| struct [OhosImageComponent](capi-image-ohosimagecomponent.md)* componentNative | Pointer to the OhosImageComponent object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br>**IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED**: Obtaining parameters from the surface fails.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.|

### OH_Image_Release()

```
int32_t OH_Image_Release(ImageNative* native)
```

**Description**

Releases an ImageNative object.

This function is not used to release an Image object at the JavaScript native API. It is used to release an ImageNative object parsed by calling [OH_Image_InitImageNative](capi-image-mdk-h.md#oh_image_initimagenative).

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ImageNative](capi-image-imagenative-.md)* native | Pointer to an ImageNative object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.|

**See also**

[OH_Image_InitImageNative](#oh_image_initimagenative)
