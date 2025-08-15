# image_source_mdk.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## Overview

The file declares the APIs used to decode an image source into a PixelMap.

**Library**: libimage_source_ndk.z.so

**File to include**: <multimedia/image_framework/image_source_mdk.h>

**Since**: 10

**Related module**: [Image](capi-image.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OhosImageRegion](capi-image-ohosimageregion.md) | - | Describes the region of an image source to decode. It is a member variable of [OhosImageDecodingOps](capi-image-ohosimagedecodingops.md).|
| [ImageSourceNative_](capi-image-imagesourcenative-.md) | ImageSourceNative | Describes an image source object at the native layer.|
| [OhosImageSourceOps](capi-image-ohosimagesourceops.md) | - | Describes the image source options. It is used in [OH_ImageSource_Create](#oh_imagesource_create) and [OH_ImageSource_CreateIncremental](#oh_imagesource_createincremental).|
| [OhosImageDecodingOps](capi-image-ohosimagedecodingops.md) | - | Describes the options for decoding an image source. It is used in [OH_ImageSource_CreatePixelMap](#oh_imagesource_createpixelmap) and [OH_ImageSource_CreatePixelMapList](#oh_imagesource_createpixelmaplist).|
| [OhosImageSourceInfo](capi-image-ohosimagesourceinfo.md) | - | Describes the image source information, which is obtained by calling [OH_ImageSource_GetImageInfo](#oh_imagesource_getimageinfo).|
| [OhosImageSource](capi-image-ohosimagesource.md) | - | Describes the input resource of an image source. Only one type of resource is accepted at a time. The image source is obtained by calling [OH_ImageSource_Create](#oh_imagesource_create).|
| [OhosImageSourceDelayTimeList](capi-image-ohosimagesourcedelaytimelist.md) | - | Describes the delay time list of an image source. The delay time list is obtained by calling [OH_ImageSource_GetDelayTime](#oh_imagesource_getdelaytime).|
| [OhosImageSourceSupportedFormat](capi-image-ohosimagesourcesupportedformat.md) | - | Describes the format string supported by an image source. It is used in [OhosImageSourceSupportedFormatList](capi-image-ohosimagesourcesupportedformatlist.md) and [OH_ImageSource_GetSupportedFormats](#oh_imagesource_getsupportedformats).|
| [OhosImageSourceSupportedFormatList](capi-image-ohosimagesourcesupportedformatlist.md) | - | Describes the format string list supported by an image source. It is obtained by calling [OH_ImageSource_GetSupportedFormats](#oh_imagesource_getsupportedformats).|
| [OhosImageSourceProperty](capi-image-ohosimagesourceproperty.md) | - | Describes the property string (in key-value format) of an image source. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).|
| [OhosImageSourceUpdateData](capi-image-ohosimagesourceupdatedata.md) | - | Describes the update data option of the image source. It is obtained by calling [OH_ImageSource_UpdateData](#oh_imagesource_updatedata).|

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_ImageSource_Create(napi_env env, struct OhosImageSource* src, struct OhosImageSourceOps* ops, napi_value *res)](#oh_imagesource_create) | Creates an ImageSource object at the JavaScript native layer based on the specified OhosImageSource and OhosImageSourceOps structs.|
| [int32_t OH_ImageSource_CreateFromUri(napi_env env, char* uri, size_t size,struct OhosImageSourceOps* ops, napi_value *res)](#oh_imagesource_createfromuri) | Creates an ImageSource object at the JavaScript native layer based on the specified URI and [OhosImageSourceOps](capi-image-ohosimagesourceops.md) struct.|
| [int32_t OH_ImageSource_CreateFromFd(napi_env env, int32_t fd,struct OhosImageSourceOps* ops, napi_value *res)](#oh_imagesource_createfromfd) | Creates an ImageSource object at the JavaScript native layer based on the specified file descriptor and [OhosImageSourceOps](capi-image-ohosimagesourceops.md) struct.|
| [int32_t OH_ImageSource_CreateFromData(napi_env env, uint8_t* data, size_t dataSize,struct OhosImageSourceOps* ops, napi_value *res)](#oh_imagesource_createfromdata) | Creates an ImageSource object at the JavaScript native layer based on the specified image source buffer (defined by **data**) and [OhosImageSourceOps](capi-image-ohosimagesourceops.md) struct.|
| [int32_t OH_ImageSource_CreateFromRawFile(napi_env env, RawFileDescriptor rawFile,struct OhosImageSourceOps* ops, napi_value *res)](#oh_imagesource_createfromrawfile) | Creates an ImageSource object at the JavaScript native layer based on the specified [RawFileDescriptor](../apis-localization-kit/capi-rawfile-rawfiledescriptor.md) and [OhosImageSourceOps](capi-image-ohosimagesourceops.md) structs.|
| [int32_t OH_ImageSource_CreateIncremental(napi_env env, struct OhosImageSource* source, struct OhosImageSourceOps* ops, napi_value *res)](#oh_imagesource_createincremental) | Creates an ImageSource object at the JavaScript native layer based on the specified [OhosImageSource](capi-image-ohosimagesource.md) and [OhosImageSourceOps](capi-image-ohosimagesourceops.md) structs. The image source data will be updated through [OH_ImageSource_UpdateData](#oh_imagesource_updatedata).|
| [int32_t OH_ImageSource_CreateIncrementalFromData(napi_env env, uint8_t* data, size_t dataSize,struct OhosImageSourceOps* ops, napi_value *res)](#oh_imagesource_createincrementalfromdata) | Creates an ImageSource object of the incremental type at the JavaScript native layer based on the specified image source buffer (defined by **data**) and [OhosImageSourceOps](capi-image-ohosimagesourceops.md) struct. The image data is updated through [OH_ImageSource_UpdateData](#oh_imagesource_updatedata).|
| [int32_t OH_ImageSource_GetSupportedFormats(struct OhosImageSourceSupportedFormatList* res)](#oh_imagesource_getsupportedformats) | Obtains all supported decoding formats.|
| [ImageSourceNative* OH_ImageSource_InitNative(napi_env env, napi_value source)](#oh_imagesource_initnative) | Converts an ImageSource object at the JavaScript native layer into an [ImageSourceNative](capi-image-imagesourcenative-.md) object.|
| [int32_t OH_ImageSource_CreatePixelMap(const ImageSourceNative* native,struct OhosImageDecodingOps* ops, napi_value *res)](#oh_imagesource_createpixelmap) | Decodes an ImageSourceNative object to obtain a PixelMap object at the JavaScript native layer based on the specified [OhosImageDecodingOps](capi-image-ohosimagedecodingops.md) struct.|
| [int32_t OH_ImageSource_CreatePixelMapList(const ImageSourceNative* native,struct OhosImageDecodingOps* ops, napi_value *res)](#oh_imagesource_createpixelmaplist) | Decodes an ImageSourceNative object to obtain all PixelMap objects at the JavaScript native layer based on the specified [OhosImageDecodingOps](capi-image-ohosimagedecodingops.md) struct.|
| [int32_t OH_ImageSource_GetDelayTime(const ImageSourceNative* native,struct OhosImageSourceDelayTimeList* res)](#oh_imagesource_getdelaytime) | Obtains the delay time list from an ImageSourceNative object (such as GIF image source).|
| [int32_t OH_ImageSource_GetFrameCount(const ImageSourceNative* native, uint32_t *res)](#oh_imagesource_getframecount) | Obtains the number of frames from an ImageSourceNative object.|
| [int32_t OH_ImageSource_GetImageInfo(const ImageSourceNative* native, int32_t index,struct OhosImageSourceInfo* info)](#oh_imagesource_getimageinfo) | Obtains image source information from an ImageSourceNative object by index.|
| [int32_t OH_ImageSource_GetImageProperty(const ImageSourceNative* native, struct OhosImageSourceProperty* key, struct OhosImageSourceProperty* value)](#oh_imagesource_getimageproperty) | Obtains the value of an image property from an ImageSourceNative object.|
| [int32_t OH_ImageSource_UpdateData(const ImageSourceNative* native, struct OhosImageSourceUpdateData* data)](#oh_imagesource_updatedata) | Updates the data of an ImageSourceNative object.|
| [int32_t OH_ImageSource_Release(ImageSourceNative* native)](#oh_imagesource_release) | Releases an ImageSourceNative object.|

### Variables

| Name| Description|
| -- | -- |
| const char* OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE = "BitsPerSample" | Pointer to bits per sample, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_ORIENTATION = "Orientation" | Pointer to the orientation, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_IMAGE_LENGTH = "ImageLength" | Pointer to the image length, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_IMAGE_WIDTH = "ImageWidth" | Pointer to the image width, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE = "GPSLatitude" | Pointer to the GPS latitude, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE = "GPSLongitude" | Pointer to the GPS longitude, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF = "GPSLatitudeRef" | Pointer to the GPS latitude reference information, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF = "GPSLongitudeRef" | Pointer to the GPS longitude reference information, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL = "DateTimeOriginal" | Pointer to the created date and time, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_EXPOSURE_TIME = "ExposureTime" | Pointer to the exposure time, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_SCENE_TYPE = "SceneType" | Pointer to the scene type, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS = "ISOSpeedRatings" | Pointer to the ISO speed ratings, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_F_NUMBER = "FNumber" | Pointer to the f-number of the image, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|
| const char* OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL = "CompressedBitsPerPixel" | Pointer to the compressed bits per pixel, one of the image properties.<br>It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).<br>**Since**: 10|

## Function Description

### OH_ImageSource_Create()

```
int32_t OH_ImageSource_Create(napi_env env, struct OhosImageSource* src, struct OhosImageSourceOps* ops, napi_value *res)
```

**Description**

Creates an ImageSource object at the JavaScript native layer based on the specified OhosImageSource and OhosImageSourceOps structs.

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_ImageSource_CreateFromUri](#oh_imagesource_createfromuri), [OH_ImageSource_CreateFromFd](#oh_imagesource_createfromfd), and [OH_ImageSource_CreateFromData](#oh_imagesource_createfromdata)

**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the JNI environment.|
| struct OhosImageSource* src | Pointer to the input resource of the image source.|
| struct [OhosImageSourceOps](capi-image-ohosimagesourceops.md)* ops | Pointer to the options for creating the image source.|
| napi_value *res | Pointer to an ImageSource object at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br>**IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br>**IMAGE_RESULT_SOURCE_DATA_INCOMPLETE**: The image source data is incomplete.<br>**IMAGE_RESULT_SOURCE_DATA**: The image source data is incorrect.<br>IMAGE_RESULT_GET_DATA_ABNORMAL: An error occurs during image data retrieval.<br>**IMAGE_RESULT_TOO_LARGE**: The image data is too large.<br>**IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br>**IMAGE_RESULT_DECODE_HEAD_ABNORMAL**: An error occurs during decoding of the image header.<br>**IMAGE_RESULT_DECODE_EXIF_UNSUPPORT**: EXIF is not supported for image decoding.<br>**IMAGE_RESULT_PROPERTY_NOT_EXIST**: The image property does not exist.<br>**IMAGE_RESULT_FILE_DAMAGED**: The file is damaged.<br>**IMAGE_RESULT_FILE_FD_ERROR**: The file descriptor is incorrect.<br>**IMAGE_RESULT_STREAM_SIZE_ERROR**: The data stream is incorrect.<br>**IMAGE_RESULT_SEEK_FAILED**: Seeking the file fails.<br>**IMAGE_RESULT_PEEK_FAILED**: Peeking the file fails.<br>**IMAGE_RESULT_FREAD_FAILED**: Reading the file fails.|

### OH_ImageSource_CreateFromUri()

```
int32_t OH_ImageSource_CreateFromUri(napi_env env, char* uri, size_t size,struct OhosImageSourceOps* ops, napi_value *res)
```

**Description**

Creates an ImageSource object at the JavaScript native layer based on the specified URI and [OhosImageSourceOps](capi-image-ohosimagesourceops.md) struct.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the JNI environment.|
| char* uri | Pointer to the image source URI. Only a file URI or Base64 URI is accepted. Currently, only absolute paths are supported.|
| size_t size | Length of the image source URI.|
| struct [OhosImageSourceOps](capi-image-ohosimagesourceops.md)* ops | Pointer to the options for creating the image source.|
| napi_value *res | Pointer to an ImageSource object at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.|

### OH_ImageSource_CreateFromFd()

```
int32_t OH_ImageSource_CreateFromFd(napi_env env, int32_t fd,struct OhosImageSourceOps* ops, napi_value *res)
```

**Description**

Creates an ImageSource object at the JavaScript native layer based on the specified file descriptor and [OhosImageSourceOps](capi-image-ohosimagesourceops.md) struct.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the JNI environment.|
| int32_t fd | Descriptor of the image source.|
| struct [OhosImageSourceOps](capi-image-ohosimagesourceops.md)* ops | Pointer to the options for creating the image source.|
| napi_value *res | Pointer to an ImageSource object at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.|

### OH_ImageSource_CreateFromData()

```
int32_t OH_ImageSource_CreateFromData(napi_env env, uint8_t* data, size_t dataSize,struct OhosImageSourceOps* ops, napi_value *res)
```

**Description**

Creates an ImageSource object at the JavaScript native layer based on the specified image source buffer (defined by **data**) and [OhosImageSourceOps](capi-image-ohosimagesourceops.md) struct.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the JNI environment.|
| uint8_t* data | Pointer to the image source buffer. Only a formatted packet buffer or Base64 buffer is accepted.|
| size_t dataSize | Size of the image source buffer.|
| struct [OhosImageSourceOps](capi-image-ohosimagesourceops.md)* ops | Pointer to the options for creating the image source.|
| napi_value *res | Pointer to an ImageSource object at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.|

### OH_ImageSource_CreateFromRawFile()

```
int32_t OH_ImageSource_CreateFromRawFile(napi_env env, RawFileDescriptor rawFile,struct OhosImageSourceOps* ops, napi_value *res)
```

**Description**

Creates an ImageSource object at the JavaScript native layer based on the specified [RawFileDescriptor](../apis-localization-kit/capi-rawfile-rawfiledescriptor.md) and [OhosImageSourceOps](capi-image-ohosimagesourceops.md) structs.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the JNI environment.|
| [RawFileDescriptor](../apis-localization-kit/capi-rawfile-rawfiledescriptor.md) rawFile | Descriptor of the image source resource.|
| struct [OhosImageSourceOps](capi-image-ohosimagesourceops.md)* ops | Pointer to the options for creating the image source.|
| napi_value *res | Pointer to an ImageSource object at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.|


### OH_ImageSource_CreateIncremental()

```
int32_t OH_ImageSource_CreateIncremental(napi_env env, struct OhosImageSource* source, struct OhosImageSourceOps* ops, napi_value *res)
```

**Description**

Creates an ImageSource object at the JavaScript native layer based on the specified [OhosImageSource](capi-image-ohosimagesource.md) and [OhosImageSourceOps](capi-image-ohosimagesourceops.md) structs. The image source data will be updated through [OH_ImageSource_UpdateData](#oh_imagesource_updatedata).

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_ImageSource_CreateIncrementalFromData](#oh_imagesource_createincrementalfromdata)


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the JNI environment.|
| struct [OhosImageSource](capi-image-ohosimagesource.md)* source | Pointer to the input resource of the image source. Only the buffer type is accepted.|
| struct [OhosImageSourceOps](capi-image-ohosimagesourceops.md)* ops | Pointer to the options for creating the image source.|
| napi_value *res | Pointer to an ImageSource object at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.|

### OH_ImageSource_CreateIncrementalFromData()

```
int32_t OH_ImageSource_CreateIncrementalFromData(napi_env env, uint8_t* data, size_t dataSize,struct OhosImageSourceOps* ops, napi_value *res)
```

**Description**

Creates an ImageSource object of the incremental type at the JavaScript native layer based on the specified image source buffer (defined by **data**) and [OhosImageSourceOps](capi-image-ohosimagesourceops.md) struct. The image data is updated through [OH_ImageSource_UpdateData](#oh_imagesource_updatedata).

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the JNI environment.|
| uint8_t* data | Pointer to the image source buffer. Only a formatted packet buffer or Base64 buffer is accepted.|
| size_t dataSize | Size of the image source buffer.|
| struct [OhosImageSourceOps](capi-image-ohosimagesourceops.md)* ops | Pointer to the options for creating the image source.|
| napi_value *res | Pointer to an ImageSource object at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.|

### OH_ImageSource_GetSupportedFormats()

```
int32_t OH_ImageSource_GetSupportedFormats(struct OhosImageSourceSupportedFormatList* res)
```

**Description**

Obtains all supported decoding formats.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| struct OhosImageSourceSupportedFormatList* res | Pointer to the [OhosImageSourceSupportedFormatList](capi-image-ohosimagesourcesupportedformatlist.md) struct.<br>If the input **supportedFormatList** is a null pointer and **size** is 0, the size of the supported formats is returned through **ressize**.<br>To obtain all formats, a space larger than **size** is required. In addition, sufficient space must be reserved for each format supported.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The check format is incorrect.|

### OH_ImageSource_InitNative()

```
ImageSourceNative* OH_ImageSource_InitNative(napi_env env, napi_value source)
```

**Description**

Converts an ImageSource object at the JavaScript native layer into an [ImageSourceNative](capi-image-imagesourcenative-.md) object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the JNI environment.|
| napi_value source | Pointer to an ImageSource object at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageSourceNative](capi-image-imagesourcenative-.md)* | Pointer to the [ImageSourceNative](capi-image-imagesourcenative-.md) object. If the operation fails, a null pointer is returned.|

**See also**

[OH_ImageSource_Release](#oh_imagesource_release)

### OH_ImageSource_CreatePixelMap()

```
int32_t OH_ImageSource_CreatePixelMap(const ImageSourceNative* native,struct OhosImageDecodingOps* ops, napi_value *res)
```

**Description**

Decodes an ImageSourceNative object to obtain a PixelMap object at the JavaScript native layer based on the specified [OhosImageDecodingOps](capi-image-ohosimagedecodingops.md) struct.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageSourceNative](capi-image-imagesourcenative-.md)* native | Pointer to an ImageSourceNative object.|
| struct [OhosImageDecodingOps](capi-image-ohosimagedecodingops.md)* ops | Pointer to the options for decoding the image source.|
| napi_value *res | Pointer to a PixelMap object at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: Failed to obtain image data.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_DECODE_HEAD_ABNORMAL**: An error occurs during decoding of the image header.<br> **IMAGE_RESULT_CREATE_DECODER_FAILED**: Failed to create the decoder.<br> **IMAGE_RESULT_CREATE_ENCODER_FAILED**: Failed to create the encoder.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The check format is incorrect.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia error.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The input image data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: The shared memory does not exist.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is abnormal.<br> **IMAGE_RESULT_DECODE_ABNORMAL**: Image decoding fails.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: The image is incorrect.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: Image initialization error.<br> **IMAGE_RESULT_INIT_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_CROP**: An error occurs during image cropping.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: Failed to register the plugin.<br> **IMAGE_RESULT_PLUGIN_CREATE_FAILED**: Failed to create the plugin.<br> **IMAGE_RESULT_ENCODE_FAILED**: Failed to add the PixelMap.<br> **IMAGE_RESULT_HW_DECODE_UNSUPPORT**: Image hardware decoding is not supported.<br> **IMAGE_RESULT_HW_DECODE_FAILED**: Hardware decoding fails.<br>**IMAGE_RESULT_ERR_IPC**: IPC fails.<br> **IMAGE_RESULT_INDEX_INVALID**: The index is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: Hardware decoding fails.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: Hardware decoding fails.|

### OH_ImageSource_CreatePixelMapList()

```
int32_t OH_ImageSource_CreatePixelMapList(const ImageSourceNative* native,struct OhosImageDecodingOps* ops, napi_value *res)
```

**Description**

Decodes an ImageSourceNative object to obtain all PixelMap objects at the JavaScript native layer based on the specified [OhosImageDecodingOps](capi-image-ohosimagedecodingops.md) struct.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageSourceNative](capi-image-imagesourcenative-.md)* native | Pointer to an ImageSourceNative object.|
| struct [OhosImageDecodingOps](capi-image-ohosimagedecodingops.md)* ops | Pointer to the options for decoding the image source.|
| napi_value *res | Pointer to PixelMap objects at the JavaScript native layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: Failed to obtain image data.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_DECODE_HEAD_ABNORMAL**: An error occurs during decoding of the image header.<br> **IMAGE_RESULT_CREATE_DECODER_FAILED**: Failed to create the decoder.<br> **IMAGE_RESULT_CREATE_ENCODER_FAILED**: Failed to create the encoder.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The check format is incorrect.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia error.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The input image data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: The shared memory does not exist.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is abnormal.<br> **IMAGE_RESULT_DECODE_ABNORMAL**: Image decoding fails.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: The image is incorrect.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: Image initialization error.<br> **IMAGE_RESULT_INIT_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_CROP**: An error occurs during image cropping.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: Failed to register the plugin.<br> **IMAGE_RESULT_PLUGIN_CREATE_FAILED**: Failed to create the plugin.<br> **IMAGE_RESULT_ENCODE_FAILED**: Failed to add the PixelMap.<br> **IMAGE_RESULT_HW_DECODE_UNSUPPORT**: Image hardware decoding is not supported.<br> **IMAGE_RESULT_HW_DECODE_FAILED**: Hardware decoding fails.<br>**IMAGE_RESULT_ERR_IPC**: IPC fails.<br> **IMAGE_RESULT_INDEX_INVALID**: The index is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: Hardware decoding fails.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: Hardware decoding fails.<br> **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT**: EXIF is not supported for image decoding.<br> **IMAGE_RESULT_PROPERTY_NOT_EXIST**: The image property does not exist.|

### OH_ImageSource_GetDelayTime()

```
int32_t OH_ImageSource_GetDelayTime(const ImageSourceNative* native,struct OhosImageSourceDelayTimeList* res)
```

**Description**

Obtains the delay time list from an ImageSourceNative object (such as GIF image source).

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageSourceNative](capi-image-imagesourcenative-.md)* native | Pointer to an ImageSourceNative object.|
| struct [OhosImageSourceDelayTimeList](capi-image-ohosimagesourcedelaytimelist.md)* res | Pointer to the OhosImageSourceDelayTimeList object obtained.<br>When the input **delayTimeList** is a null pointer and **size** is **0**, the size of the delay time list is returned through **size** in **res**. To obtain the complete delay time list, a space greater than **size** is required.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: Failed to obtain image data.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_DECODE_HEAD_ABNORMAL**: An error occurs during decoding of the image header.<br> **IMAGE_RESULT_CREATE_DECODER_FAILED**: Failed to create the decoder.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia error.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The input image data is incorrect.<br> **IMAGE_RESULT_DECODE_ABNORMAL**: Image decoding fails.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: Image initialization error.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: Failed to register the plugin.<br> **IMAGE_RESULT_PLUGIN_CREATE_FAILED**: Failed to create the plugin.<br> **IMAGE_RESULT_INDEX_INVALID**: The index is invalid.<br> **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT**: EXIF is not supported for image decoding.<br> **IMAGE_RESULT_PROPERTY_NOT_EXIST**: The image property does not exist.|

### OH_ImageSource_GetFrameCount()

```
int32_t OH_ImageSource_GetFrameCount(const ImageSourceNative* native, uint32_t *res)
```

**Description**

Obtains the number of frames from an ImageSourceNative object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageSourceNative](capi-image-imagesourcenative-.md)* native | Pointer to an ImageSourceNative object.|
| uint32_t *res | Pointer to the frame count.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: Failed to obtain image data.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_DECODE_HEAD_ABNORMAL**: An error occurs during decoding of the image header.<br> **IMAGE_RESULT_CREATE_DECODER_FAILED**: Failed to create the decoder.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia error.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The input image data is incorrect.<br> **IMAGE_RESULT_DECODE_ABNORMAL**: Image decoding fails.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: Image initialization error.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: Failed to register the plugin.<br> **IMAGE_RESULT_PLUGIN_CREATE_FAILED**: Failed to create the plugin.<br> **IMAGE_RESULT_INDEX_INVALID**: The index is invalid.<br> **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT**: EXIF is not supported for image decoding.<br> **IMAGE_RESULT_PROPERTY_NOT_EXIST**: The image property does not exist.|

### OH_ImageSource_GetImageInfo()

```
int32_t OH_ImageSource_GetImageInfo(const ImageSourceNative* native, int32_t index,struct OhosImageSourceInfo* info)
```

**Description**

Obtains image source information from an ImageSourceNative object by index.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageSourceNative](capi-image-imagesourcenative-.md)* native | Pointer to an ImageSourceNative object.|
| int32_t index | Index.|
| struct [OhosImageSourceInfo](capi-image-ohosimagesourceinfo.md)* info | Pointer to the OhosImageSourceInfo object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: Failed to obtain image data.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_DECODE_HEAD_ABNORMAL**: An error occurs during decoding of the image header.<br> **IMAGE_RESULT_CREATE_DECODER_FAILED**: Failed to create the decoder.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia error.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The input image data is incorrect.<br> **IMAGE_RESULT_DECODE_ABNORMAL**: Image decoding fails.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: Image initialization error.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: Failed to register the plugin.<br> **IMAGE_RESULT_PLUGIN_CREATE_FAILED**: Failed to create the plugin.<br> **IMAGE_RESULT_INDEX_INVALID**: The index is invalid.<br> **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT**: EXIF is not supported for image decoding.<br> **IMAGE_RESULT_PROPERTY_NOT_EXIST**: The image property does not exist.|

### OH_ImageSource_GetImageProperty()

```
int32_t OH_ImageSource_GetImageProperty(const ImageSourceNative* native, struct OhosImageSourceProperty* key, struct OhosImageSourceProperty* value)
```

**Description**

Obtains the value of an image property from an ImageSourceNative object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageSourceNative](capi-image-imagesourcenative-.md)* native | Pointer to an ImageSourceNative object.|
| struct [OhosImageSourceProperty](capi-image-ohosimagesourceproperty.md)* key | Pointer to the property. For details, see **OhosImageSourceProperty**.|
| struct [OhosImageSourceProperty](capi-image-ohosimagesourceproperty.md)* value | Pointer to the OhosImageSourceProperty object obtained. If the input **value** is a null pointer and **size** is **0**, the size of the property value is returned through **size** in **value**. To obtain the complete property value, a space greater than **size** is required.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br> **OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: Failed to obtain image data.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_DECODE_HEAD_ABNORMAL**: An error occurs during decoding of the image header.<br> **IMAGE_RESULT_CREATE_DECODER_FAILED**: Failed to create the decoder.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia error.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The input image data is incorrect.<br> **IMAGE_RESULT_DECODE_ABNORMAL**: Image decoding fails.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: Image initialization error.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: Failed to register the plugin.<br> **IMAGE_RESULT_PLUGIN_CREATE_FAILED**: Failed to create the plugin.<br> **IMAGE_RESULT_INDEX_INVALID**: The index is invalid.<br> **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT**: EXIF is not supported for image decoding.<br> **IMAGE_RESULT_PROPERTY_NOT_EXIST**: The image property does not exist.|

### OH_ImageSource_ModifyImageProperty()

```
int32_t OH_ImageSource_ModifyImageProperty(const ImageSourceNative* native, struct OhosImageSourceProperty* key, struct OhosImageSourceProperty* value)
```

**Description**

Modifies the value of an image property of an ImageSourceNative object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageSourceNative](capi-image-imagesourcenative-.md)* native | Pointer to an ImageSourceNative object.|
| struct [OhosImageSourceProperty](capi-image-ohosimagesourceproperty.md)* key | Pointer to the property. For details, see **OhosImageSourceProperty**.|
| struct [OhosImageSourceProperty](capi-image-ohosimagesourceproperty.md)* value | Pointer to the new value of the property.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br> **OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: Failed to obtain image data.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_DECODE_HEAD_ABNORMAL**: An error occurs during decoding of the image header.<br> **IMAGE_RESULT_CREATE_DECODER_FAILED**: Failed to create the decoder.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia error.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The input image data is incorrect.<br> **IMAGE_RESULT_DECODE_ABNORMAL**: Image decoding fails.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: Image initialization error.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: Failed to register the plugin.<br> **IMAGE_RESULT_PLUGIN_CREATE_FAILED**: Failed to create the plugin.<br> **IMAGE_RESULT_INDEX_INVALID**: The index is invalid.<br> **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT**: EXIF is not supported for image decoding.<br> **IMAGE_RESULT_PROPERTY_NOT_EXIST**: The image property does not exist.|

### OH_ImageSource_UpdateData()

```
int32_t OH_ImageSource_UpdateData(const ImageSourceNative* native, struct OhosImageSourceUpdateData* data)
```

**Description**

Updates the data of an ImageSourceNative object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageSourceNative](capi-image-imagesourcenative-.md)* native | Pointer to an ImageSourceNative object.|
| struct [OhosImageSourceUpdateData](capi-image-ohosimagesourceupdatedata.md)* data | Pointer to the update data. For details, see **OhosImageSourceUpdateData**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br> **OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: Failed to obtain image data.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_DECODE_HEAD_ABNORMAL**: An error occurs during decoding of the image header.<br> **IMAGE_RESULT_CREATE_DECODER_FAILED**: Failed to create the decoder.<br> **IMAGE_RESULT_CREATE_ENCODER_FAILED**: Failed to create the encoder.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The check format is incorrect.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: An error occurs in the Skia third-party library.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The input image data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: The shared memory does not exist.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is abnormal.<br> **IMAGE_RESULT_DECODE_ABNORMAL**: Image decoding fails.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: An error occurs during memory allocation.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: Image initialization error.<br> **IMAGE_RESULT_INIT_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_CROP**: An error occurs during image cropping.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: Failed to register the plugin.<br> **IMAGE_RESULT_PLUGIN_CREATE_FAILED**: Failed to create the plugin.<br> **IMAGE_RESULT_ENCODE_FAILED**: Failed to add the PixelMap.<br> **IMAGE_RESULT_HW_DECODE_UNSUPPORT**: Image hardware decoding is not supported.<br> **IMAGE_RESULT_HW_DECODE_FAILED**: Hardware decoding fails.<br> **IMAGE_RESULT_ERR_IPC**: IPC fails.<br> **IMAGE_RESULT_INDEX_INVALID**: The index is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: The alpha type is incorrect.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: The memory allocator type is incorrect.|

### OH_ImageSource_Release()

```
int32_t OH_ImageSource_Release(ImageSourceNative* native)
```

**Description**

Releases an ImageSourceNative object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ImageSourceNative](capi-image-imagesourcenative-.md)* native | Pointer to an ImageSourceNative object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br> **OHOS_IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: Failed to obtain image data.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The input image data is incorrect.|

**See also**

[OH_ImageSource_Create](#oh_imagesource_create), [OH_ImageSource_CreateIncremental](#oh_imagesource_createincremental)
