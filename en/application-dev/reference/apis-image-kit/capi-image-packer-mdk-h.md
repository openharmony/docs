# image_packer_mdk.h

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1a9fd5f0ccee234fe1c8d19ee00da4a54d4f14a1 translatedAt=2026-08-03T04:04:50.694Z pushedAt=2026-08-04T02:42:24.066Z -->

## Overview

The file declares the APIs used to pack an image or a PixelMap into a buffer or file.

The packing process is as follows:

Create an encoder object using **OH_ImagePacker_Create**.

Convert the encoder object to a native encoder object using **OH_ImagePacker_InitNative**.

Call **OH_ImagePacker_PackToData** or OH_ImagePacker_PackToFile to pack the source into the target area with the specified packing options.

Release the encoder object using **OH_ImagePacker_Release**.

**File to include**: <multimedia/image_framework/image_packer_mdk.h>

**Library**: libimage_packer_ndk.z.so

**System capability:** SystemCapability.Multimedia.Image.ImagePacker

**Since**: 11

**Related module**: [Image](capi-image.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ImagePacker_Opts_](capi-image-imagepacker-opts-.md) | ImagePacker_Opts | Describes the image packing options.|
| [ImagePacker_Native_](capi-image-imagepacker-native-.md) | ImagePacker_Native | Describes the ImagePacker instance at the native layer.|

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_ImagePacker_Create(napi_env env, napi_value *res)](#oh_imagepacker_create) | Obtains an ImagePacker object at the JavaScript native layer.|
| [ImagePacker_Native* OH_ImagePacker_InitNative(napi_env env, napi_value packer)](#oh_imagepacker_initnative) | Converts an ImagePacker object at the JavaScript native layer into an ImagePacker_Native object.|
| [int32_t OH_ImagePacker_PackToData(ImagePacker_Native* native, napi_value source,ImagePacker_Opts* opts, uint8_t* outData, size_t* size)](#oh_imagepacker_packtodata) | Packs a PixelMap object or an ImagePacker object at the JavaScript native layer to a buffer (defined by **outData**) based on the specified ImagePacker_Opts struct.|
| [int32_t OH_ImagePacker_PackToFile(ImagePacker_Native* native, napi_value source, ImagePacker_Opts* opts, int fd)](#oh_imagepacker_packtofile) | Packs a PixelMap object or an ImagePacker object at the JavaScript native layer to a file based on the specified ImagePacker_Opts struct.|
| [int32_t OH_ImagePacker_Release(ImagePacker_Native* native)](#oh_imagepacker_release) | Releases an [ImagePacker_Native](capi-image-imagepacker-native-.md) object.<br>It is not used to release the ImagePacker object at the JavaScript native layer.|

## Function Description

### OH_ImagePacker_Create()

```c
int32_t OH_ImagePacker_Create(napi_env env, napi_value *res)
```

**Description**

Obtains an ImagePacker object at the JavaScript native layer.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the JNI environment.|
| napi_value *res | Pointer to an ImagePacker object at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.|

### OH_ImagePacker_InitNative()

```c
ImagePacker_Native* OH_ImagePacker_InitNative(napi_env env, napi_value packer)
```

**Description**

Converts an ImagePacker object at the JavaScript native layer into an ImagePacker_Native object.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the JNI environment.|
| napi_value packer | ImagePacker object at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| [ImagePacker_Native](capi-image-imagepacker-native-.md)* | Pointer to an ImagePacker_Native object. If the operation fails, a null pointer is returned.|

**See also**

[OH_ImagePacker_Release](#oh_imagepacker_release)

### OH_ImagePacker_PackToData()

```c
int32_t OH_ImagePacker_PackToData(ImagePacker_Native* native, napi_value source,ImagePacker_Opts* opts, uint8_t* outData, size_t* size)
```

**Description**

Packs a PixelMap object or an ImagePacker object at the JavaScript native layer to a buffer (defined by **outData**) based on the specified ImagePacker_Opts struct.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [ImagePacker_Native](capi-image-imagepacker-native-.md)* native | Pointer to an ImagePacker_Native object.|
| napi_value source | PixelMap object or ImageSource object at the JavaScript native layer.|
| [ImagePacker_Opts](capi-image-imagepacker-opts-.md)* opts | Pointer to the packing options.|
| uint8_t* outData | Pointer to the output buffer.|
| size_t* size | Pointer to the size of the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>  **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **ERR_IMAGE_DATA_ABNORMAL**: The output buffer is abnormal.<br>  **ERR_IMAGE_MISMATCHED_FORMAT**: The format is incorrect.<br>  **ERR_IMAGE_MALLOC_ABNORMAL**: An error occurs in the malloc internal buffer.<br>  **ERR_IMAGE_DECODE_ABNORMAL**: An internal error occurs during codec initialization.<br>**ERR_IMAGE_ENCODE_FAILED**: An error occurs during encoding.|

**See also**

[OH_ImagePacker_PackToFile](#oh_imagepacker_packtofile)

### OH_ImagePacker_PackToFile()

```c
int32_t OH_ImagePacker_PackToFile(ImagePacker_Native* native, napi_value source,ImagePacker_Opts* opts, int fd)
```

**Description**

Packs a PixelMap object or an ImagePacker object at the JavaScript native layer to a file based on the specified ImagePacker_Opts struct.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [ImagePacker_Native](capi-image-imagepacker-native-.md)* native | Pointer to an ImagePacker_Native object.|
| napi_value source | PixelMap object or ImageSource object at the JavaScript native layer.|
| [ImagePacker_Opts](capi-image-imagepacker-opts-.md)* opts | Pointer to the packing options.|
| int fd | File descriptor of the output file.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>  **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **ERR_IMAGE_DATA_ABNORMAL**: The output buffer is abnormal.<br>  **ERR_IMAGE_MISMATCHED_FORMAT**: The format is incorrect.<br>  **ERR_IMAGE_MALLOC_ABNORMAL**: An error occurs in the malloc internal buffer.<br>  **ERR_IMAGE_DECODE_ABNORMAL**: An internal error occurs during codec initialization.<br>**ERR_IMAGE_ENCODE_FAILED**: An error occurs during encoding.|

**See also**

[OH_ImagePacker_PackToData](#oh_imagepacker_packtodata)

### OH_ImagePacker_Release()

```c
int32_t OH_ImagePacker_Release(ImagePacker_Native* native)
```

**Description**

Releases an [ImagePacker_Native](capi-image-imagepacker-native-.md) object.

It is not used to release the ImagePacker object at the JavaScript native layer.

It is parsed by calling [OH_ImagePacker_InitNative](#oh_imagepacker_initnative).

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [ImagePacker_Native](capi-image-imagepacker-native-.md)* native | Pointer to an ImagePacker_Native object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.|

**See also**

[OH_ImagePacker_InitNative](#oh_imagepacker_initnative)