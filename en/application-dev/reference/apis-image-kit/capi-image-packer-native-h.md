# image_packer_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## Overview

The file declares the APIs for image encoding.

**File to include**: <multimedia/image_framework/image/image_packer_native.h>

**Library**: libimage_packer.so

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) | OH_ImagePackerNative | Describes the image packer, which is used to perform operations related to an image packer.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) | OH_PackingOptions | OH_PackingOptions is an image encoding option struct encapsulated at the native layer. It cannot be manipulated directly; instead, functions shall be called to create and release the struct, and operate on its specific fields.|
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) | OH_PackingOptionsForSequence | OH_PackingOptionsForSequence is an image sequence encoding option struct encapsulated at the native layer. It cannot be manipulated directly; instead, functions shall be called to create and release the struct, and operate on its specific fields.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range) | IMAGE_PACKER_DYNAMIC_RANGE | Enumerates the dynamic range for encoding.|

### Functions

| Name| Description|
| -- | -- |
| [Image_ErrorCode OH_PackingOptions_Create(OH_PackingOptions **options)](#oh_packingoptions_create) | Creates the pointer to an OH_PackingOptions struct.|
| [Image_ErrorCode OH_PackingOptions_GetMimeType(OH_PackingOptions *options, Image_MimeType *format)](#oh_packingoptions_getmimetype) | Obtains the MIME type in the encoding parameters. **format.data** obtained through this API lacks the string terminator **\0**. Please use it with caution.|
| [Image_ErrorCode OH_PackingOptions_GetMimeTypeWithNull(OH_PackingOptions *options, Image_MimeType *format)](#oh_packingoptions_getmimetypewithnull) | Obtains the MIME type in the encoding parameters. **format.data** obtained by this API ends with the string terminator **\0**.|
| [Image_ErrorCode OH_PackingOptions_SetMimeType(OH_PackingOptions *options, Image_MimeType *format)](#oh_packingoptions_setmimetype) | Sets the MIME type.|
| [Image_ErrorCode OH_PackingOptions_GetQuality(OH_PackingOptions *options, uint32_t *quality)](#oh_packingoptions_getquality) | Obtains the encoding quality.|
| [Image_ErrorCode OH_PackingOptions_SetQuality(OH_PackingOptions *options, uint32_t quality)](#oh_packingoptions_setquality) | Sets the encoding quality.|
| [ Image_ErrorCode OH_PackingOptions_GetNeedsPackProperties(OH_PackingOptions *options, bool *needsPackProperties)](#oh_packingoptions_getneedspackproperties) | Obtains the **needsPackProperties** parameter in the OH_PackingOptions struct.|
| [Image_ErrorCode OH_PackingOptions_SetNeedsPackProperties(OH_PackingOptions *options, bool needsPackProperties)](#oh_packingoptions_setneedspackproperties) | Sets the **needsPackProperties** parameter in the OH_PackingOptions struct.|
| <!--DelRow--> [Image_ErrorCode OH_PackingOptions_GetNeedsPackDfxData(OH_PackingOptions *options, bool *needsPackDfxData)](#oh_packingoptions_getneedspackdfxdata) | Obtains the **needsPackDfxData** parameter in the OH_PackingOptions struct.|
| <!--DelRow--> [Image_ErrorCode OH_PackingOptions_SetNeedsPackDfxData(OH_PackingOptions *options, bool needsPackDfxData)](#oh_packingoptions_setneedspackdfxdata) | Obtains the **needsPackDfxData** parameter in the OH_PackingOptions struct.|
| [Image_ErrorCode OH_PackingOptions_GetDesiredDynamicRange(OH_PackingOptions *options, int32_t* desiredDynamicRange)](#oh_packingoptions_getdesireddynamicrange) | Obtains the desired dynamic range during encoding.|
| [Image_ErrorCode OH_PackingOptions_SetDesiredDynamicRange(OH_PackingOptions *options, int32_t desiredDynamicRange)](#oh_packingoptions_setdesireddynamicrange) | Sets the desired dynamic range during encoding.|
| [Image_ErrorCode OH_PackingOptions_Release(OH_PackingOptions *options)](#oh_packingoptions_release) | Releases the pointer to an OH_PackingOptions struct.|
| [Image_ErrorCode OH_PackingOptionsForSequence_Create(OH_PackingOptionsForSequence **options)](#oh_packingoptionsforsequence_create) | Creates the pointer to an OH_PackingOptionsForSequence struct.|
| [Image_ErrorCode OH_PackingOptionsForSequence_SetFrameCount(OH_PackingOptionsForSequence *options, uint32_t frameCount)](#oh_packingoptionsforsequence_setframecount) | Sets the number of frames for image sequence encoding.|
| [Image_ErrorCode OH_PackingOptionsForSequence_GetFrameCount(OH_PackingOptionsForSequence *options, uint32_t *frameCount)](#oh_packingoptionsforsequence_getframecount) | Obtains the number of frames for image sequence encoding.|
| [Image_ErrorCode OH_PackingOptionsForSequence_SetDelayTimeList(OH_PackingOptionsForSequence *options, int32_t *delayTimeList, size_t delayTimeListLength)](#oh_packingoptionsforsequence_setdelaytimelist) | Sets the delay time array for image sequence encoding.|
| [Image_ErrorCode OH_PackingOptionsForSequence_GetDelayTimeList(OH_PackingOptionsForSequence *options, int32_t *delayTimeList, size_t delayTimeListLength)](#oh_packingoptionsforsequence_getdelaytimelist) | Obtains the delay time array for image sequence encoding.|
| [Image_ErrorCode OH_PackingOptionsForSequence_SetDisposalTypes(OH_PackingOptionsForSequence *options, uint32_t *disposalTypes, size_t disposalTypesLength)](#oh_packingoptionsforsequence_setdisposaltypes) | Sets the disposal type array for image sequence encoding.|
| [Image_ErrorCode OH_PackingOptionsForSequence_GetDisposalTypes(OH_PackingOptionsForSequence *options, uint32_t *disposalTypes, size_t disposalTypesLength)](#oh_packingoptionsforsequence_getdisposaltypes) | Obtains the disposal type array for image sequence encoding.|
| [Image_ErrorCode OH_PackingOptionsForSequence_SetLoopCount(OH_PackingOptionsForSequence *options, uint32_t loopCount)](#oh_packingoptionsforsequence_setloopcount) | Sets the number of loops for image sequence encoding. The value range is [0, 65535], where **0** means an infinite loop. If this field is not carried, loop playback is not performed.|
| [Image_ErrorCode OH_PackingOptionsForSequence_GetLoopCount(OH_PackingOptionsForSequence *options, uint32_t *loopCount)](#oh_packingoptionsforsequence_getloopcount) | Obtains the number of loops for image sequence encoding.|
| [Image_ErrorCode OH_PackingOptionsForSequence_Release(OH_PackingOptionsForSequence *options)](#oh_packingoptionsforsequence_release) | Releases the pointer to an OH_PackingOptionsForSequence struct.|
| [Image_ErrorCode OH_ImagePackerNative_Create(OH_ImagePackerNative **imagePacker)](#oh_imagepackernative_create) | Creates the pointer to an OH_ImagePackerNative struct.|
| [Image_ErrorCode OH_ImagePackerNative_PackToDataFromImageSource(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_ImageSourceNative *imageSource, uint8_t *outData, size_t *size)](#oh_imagepackernative_packtodatafromimagesource) | Encodes an image source into data in a given format.|
| [Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmap(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_PixelmapNative *pixelmap, uint8_t *outData, size_t *size)](#oh_imagepackernative_packtodatafrompixelmap) | Encodes a PixelMap into data in a given format.|
| [Image_ErrorCode OH_ImagePackerNative_PackToDataFromPicture(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_PictureNative *picture, uint8_t *outData, size_t *size)](#oh_imagepackernative_packtodatafrompicture) | Encodes a picture into data in a given format.|
| [Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmapSequence(OH_ImagePackerNative *imagePacker, OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence,size_t sequenceLength, uint8_t *outData, size_t *outDataSize)](#oh_imagepackernative_packtodatafrompixelmapsequence) | Encodes a PixelMap sequence into data.|
| [Image_ErrorCode OH_ImagePackerNative_PackToFileFromImageSource(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_ImageSourceNative *imageSource, int32_t fd)](#oh_imagepackernative_packtofilefromimagesource) | Encodes an image source into a file.|
| [Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmap(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_PixelmapNative *pixelmap, int32_t fd)](#oh_imagepackernative_packtofilefrompixelmap) | Encodes a PixelMap into a file.|
| [Image_ErrorCode OH_ImagePackerNative_PackToFileFromPicture(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_PictureNative *picture, int32_t fd)](#oh_imagepackernative_packtofilefrompicture) | Encodes a picture into a file.|
| [Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmapSequence(OH_ImagePackerNative *imagePacker, OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence, size_t sequenceLength, int32_t fd)](#oh_imagepackernative_packtofilefrompixelmapsequence) | Encodes a PixelMap sequence into a file.|
| [Image_ErrorCode OH_ImagePackerNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)](#oh_imagepackernative_getsupportedformats) | Obtains the supported image formats that can be encoded.|
| [Image_ErrorCode OH_ImagePackerNative_Release(OH_ImagePackerNative *imagePacker)](#oh_imagepackernative_release) | Releases the pointer to an OH_ImagePackerNative struct.|

## Enum Description

### IMAGE_PACKER_DYNAMIC_RANGE

```c
enum IMAGE_PACKER_DYNAMIC_RANGE
```

**Description**

Enumerates the dynamic range for encoding.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| IMAGE_PACKER_DYNAMIC_RANGE_AUTO = 0 | Adaptive processing.|
| IMAGE_PACKER_DYNAMIC_RANGE_SDR = 1 | Standard dynamic range (SDR).|


## Function Description

### OH_PackingOptions_Create()

```c
Image_ErrorCode OH_PackingOptions_Create(OH_PackingOptions **options)
```

**Description**

Creates the pointer to an OH_PackingOptions struct.

Restrictions: **options** cannot be a null pointer. If the API returns a failure, the output parameter content should not be used.

Resource management: The OH_PackingOptions object returned by the API is managed by the caller and must be released using [OH_PackingOptions_Release](#oh_packingoptions_release) after use.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) **options | Double pointer to the OH_PackingOptions struct created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_GetMimeType()

```c
Image_ErrorCode OH_PackingOptions_GetMimeType(OH_PackingOptions *options,Image_MimeType *format)
```

**Description**

Obtains the MIME type in the encoding parameters. **format.data** obtained through this API lacks the string terminator **\0**. Please use it with caution.

Restrictions: **options** and **format** cannot be null pointers. If **format->size** is not **0** before the API is called, **format->size** must be greater than or equal to the length of the current MIME type. If the API returns a failure, **format.data** should not be read.

Resource management: After the API is successfully executed, **format.data** is allocated by the API. The caller needs to use **free[]** to release it after use. **format.data** returned by this API is not null-terminated with the string terminator '\0'. If it needs to be handled as a C string, you are advised to use [OH_PackingOptions_GetMimeTypeWithNull](#oh_packingoptions_getmimetypewithnull).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [Image_MimeType](capi-image-nativemodule-image-string.md) *format | Pointer to the image format. The format does not need to be manually initialized, and the system will allocate memory. However, you must deallocate the memory after use.<br>**format.data** obtained through this API lacks the string terminator **\0**. You need to check whether the actual data length exceeds the length of the allocated buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_GetMimeTypeWithNull()

```c
Image_ErrorCode OH_PackingOptions_GetMimeTypeWithNull(OH_PackingOptions *options,Image_MimeType *format)
```

**Description**

Obtains the MIME type in the encoding parameters. **format.data** obtained by this API ends with the string terminator **\0**.

Usage scenario: This API is suitable for reading the MIME type in string format. Different from [OH_PackingOptions_GetMimeType](#oh_packingoptions_getmimetype), this API returns **format.data** that ends with **\0**, making it more suitable for direct handling as a C string.

Restrictions: **options** and **format** cannot be null pointers. If **format->size** is not **0** before the API is called, **format->size** must be greater than or equal to the length of the current MIME type. If the API returns a failure, **format.data** should not be read.

Resource management: After the API is successfully executed, **format.data** is allocated by the API. The caller needs to use **free[]** to release it after use.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [Image_MimeType](capi-image-nativemodule-image-string.md) *format | Pointer to the MIME type.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_PACKER_INVALID_PARAMETER**: The **options** or **format** parameter is a null pointer.|

### OH_PackingOptions_SetMimeType()

```c
Image_ErrorCode OH_PackingOptions_SetMimeType(OH_PackingOptions *options,Image_MimeType *format)
```

**Description**

Sets the MIME type.

Application scenario: You can use this API to set the target encoding format for OH_PackingOptions. Before using OH_PackingOptions to encode an ImageSource, PixelMap, or Picture, you must call this API to set the MIME type. If the MIME type is not set, the encoding API returns a parameter error.

Restrictions: **options**, **format**, and **format->data** cannot be null pointers, and **format->size** must be greater than 0. **format** must be a MIME type that supports encoding. You can call [OH_ImagePackerNative_GetSupportedFormats](#oh_imagepackernative_getsupportedformats) to query the image formats that support encoding.

Resource management: The API copies the input MIME type data and does not hold the **format->data** pointer passed by the caller. After the API returns, the caller still needs to manage the lifecycle of **format**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [Image_MimeType](capi-image-nativemodule-image-string.md) *format | Target encoding format.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_GetQuality()

```c
Image_ErrorCode OH_PackingOptions_GetQuality(OH_PackingOptions *options,uint32_t *quality)
```

**Description**

Obtains the encoding quality.

Restrictions: **options** and **quality** cannot be null pointers. If the API returns a failure, the output parameter content should not be used.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| uint32_t *quality | Pointer to the encoding quality.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_SetQuality()

```c
Image_ErrorCode OH_PackingOptions_SetQuality(OH_PackingOptions *options,uint32_t quality)
```

**Description**

Sets the encoding quality.

Restrictions: **options** cannot be a null pointer. The value range of **quality** is [0, 100]. After OH_PackingOptions is created, the default value of **quality** is **0**. You are advised to set **quality** to a value greater than or equal to 80. The actual effect of **quality** depends on the target encoding format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| uint32_t quality | Encoding quality. The value ranges from 0 to 100 and the default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_GetNeedsPackProperties()

```c
 Image_ErrorCode OH_PackingOptions_GetNeedsPackProperties(OH_PackingOptions *options,bool *needsPackProperties)
```

**Description**

Obtains the **needsPackProperties** parameter in the OH_PackingOptions struct.

Restrictions: **options** and **needsPackProperties** cannot be null pointers. If the API returns a failure, the output parameter content should not be used.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| bool *needsPackProperties | Whether to encode image property information (for example, Exif). The values include **true** (yes) and **false** (no).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_SetNeedsPackProperties()

```c
Image_ErrorCode OH_PackingOptions_SetNeedsPackProperties(OH_PackingOptions *options,bool needsPackProperties)
```

**Description**

Sets the **needsPackProperties** parameter in the OH_PackingOptions struct.

Usage scenario: When you need to retain or write image property information (such as Exif information) into the encoding output, set **needsPackProperties** to **true**. Set **needsPackProperties** to **false** if you are only concerned about pixel content or want to reduce the size of the output data, or if the target format does not require the property information.

Restrictions: **options** cannot be a null pointer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| bool needsPackProperties | Whether to encode image property information (for example, Exif). The values include **true** (yes) and **false** (no). The default value is **false**.<br>If the raw image does not have Exif data, the output file will not contain these properties even if **needsPackProperties** is set to **true**.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|
<!--Del-->
### OH_PackingOptions_GetNeedsPackDfxData()

```c
Image_ErrorCode OH_PackingOptions_GetNeedsPackDfxData(OH_PackingOptions *options, bool *needsPackDfxData)
```

**Description**

Obtains the **needsPackDfxData** parameter in the OH_PackingOptions struct.

**Since:** 26.0.0

**System API**: This is a system API.

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to the OH_PackingOptions struct.|
| bool *needsPackDfxData | Whether the image DFX data needs to be encoded. The value **true** indicates yes, and the value **false** indicates no.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**202**: This API is called by a non-system application.</li><br>         <li>**IMAGE_PACKER_INVALID_PARAMETER**: **options** or **needsPackDfxData** is a null pointer.</li><br>         </ul> |

### OH_PackingOptions_SetNeedsPackDfxData()

```c
Image_ErrorCode OH_PackingOptions_SetNeedsPackDfxData(OH_PackingOptions *options, bool needsPackDfxData)
```

**Description**

Obtains the **needsPackDfxData** parameter in the OH_PackingOptions struct.

**Since:** 26.0.0

**System API**: This is a system API.

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to the OH_PackingOptions struct.|
| bool needsPackDfxData | Whether the image DFX data needs to be encoded. The value **true** indicates yes, and the value **false** indicates no.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**202**: This API is called by a non-system application.</li><br>         <li>**IMAGE_PACKER_INVALID_PARAMETER**: **options** is a null pointer.</li><br>         </ul> |
<!--DelEnd-->
### OH_PackingOptions_GetDesiredDynamicRange()

```c
Image_ErrorCode OH_PackingOptions_GetDesiredDynamicRange(OH_PackingOptions *options, int32_t* desiredDynamicRange)
```

**Description**

Obtains the desired dynamic range during encoding.

Restrictions: **options** and **desiredDynamicRange** cannot be null pointers. If the API returns a failure, the content of the output parameter should not be used.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| int32_t* desiredDynamicRange | Desired dynamic range. For details, see [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_SetDesiredDynamicRange()

```c
Image_ErrorCode OH_PackingOptions_SetDesiredDynamicRange(OH_PackingOptions *options, int32_t desiredDynamicRange)
```

**Description**

Sets the desired dynamic range during encoding.

Restrictions: **options** cannot be a null pointer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| int32_t desiredDynamicRange | Desired dynamic range. For details, see [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range). The default value is **IMAGE_PACKER_DYNAMIC_RANGE_SDR**.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_Release()

```c
Image_ErrorCode OH_PackingOptions_Release(OH_PackingOptions *options)
```

**Description**

Releases the pointer to an OH_PackingOptions struct.

Restrictions: **options** cannot be a null pointer.

Resource management: This API must be called to release objects successfully created by [OH_PackingOptions_Create](#oh_packingoptions_create) after encoding is complete. Releasing OH_PackingOptions does not affect the completed encoding output or release the OH_ImagePackerNative object. After this API is called, the OH_PackingOptions object to which **options** points is released and should not be used anymore.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_Create()

```c
Image_ErrorCode OH_PackingOptionsForSequence_Create(OH_PackingOptionsForSequence **options)
```

**Description**

Creates the pointer to an OH_PackingOptionsForSequence struct.

Restrictions: **options** cannot be a null pointer. If the API returns a failure, the content of the output parameter should not be used.

Resource management: The OH_PackingOptionsForSequence object returned by the API is managed by the caller and must be released using [OH_PackingOptionsForSequence_Release](#oh_packingoptionsforsequence_release) after use.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) **options | Double pointer to OH_PackingOptionsForSequence.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_SetFrameCount()

```c
Image_ErrorCode OH_PackingOptionsForSequence_SetFrameCount(OH_PackingOptionsForSequence *options,uint32_t frameCount)
```

**Description**

Sets the number of frames for image sequence encoding.

Restrictions: **options** cannot be a null pointer.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to OH_PackingOptionsForSequence.|
| uint32_t frameCount | Number of frames.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_GetFrameCount()

```c
Image_ErrorCode OH_PackingOptionsForSequence_GetFrameCount(OH_PackingOptionsForSequence *options,uint32_t *frameCount)
```

**Description**

Obtains the number of frames for image sequence encoding.

Restrictions: **options** and **frameCount** cannot be null pointers. If the API returns a failure, the content of the output parameter should not be used.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to OH_PackingOptionsForSequence.|
| uint32_t *frameCount | Pointer to the number of frames.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_SetDelayTimeList()

```c
Image_ErrorCode OH_PackingOptionsForSequence_SetDelayTimeList(OH_PackingOptionsForSequence *options,int32_t *delayTimeList, size_t delayTimeListLength)
```

**Description**

Sets the delay time array for image sequence encoding.

Restrictions: **options** cannot be a null pointer.

Resource management: The API saves the input **delayTimeList** pointer and does not copy the array content. The caller must ensure that the data pointed to by **delayTimeList** is valid when the OH_PackingOptionsForSequence object is used. When this API is called for multiple times, the new **delayTimeList** pointer replaces the previously saved pointer.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to OH_PackingOptionsForSequence.|
| int32_t *delayTimeList | Pointer to the delay time array. The unit of the delay time is 10 ms.|
| size_t delayTimeListLength | Length of the delay time array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_GetDelayTimeList()

```c
Image_ErrorCode OH_PackingOptionsForSequence_GetDelayTimeList(OH_PackingOptionsForSequence *options,int32_t *delayTimeList, size_t delayTimeListLength)
```

**Description**

Obtains the delay time array for image sequence encoding.

Restrictions: **options** and **delayTimeList** cannot be null pointers, and **delayTimeListLength** must be greater than 0. The API copies the configured delay time array to the **delayTimeList** buffer passed by the caller. If the API returns a failure, the output buffer content should not be used.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to OH_PackingOptionsForSequence.|
| int32_t *delayTimeList | Pointer to the delay time array.|
| size_t delayTimeListLength | Length of the delay time array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_SetDisposalTypes()

```c
Image_ErrorCode OH_PackingOptionsForSequence_SetDisposalTypes(OH_PackingOptionsForSequence *options,uint32_t *disposalTypes, size_t disposalTypesLength)
```

**Description**

Sets the disposal type array for image sequence encoding.

Restrictions: **options** cannot be a null pointer.

Resource management: The API saves the input **disposalTypes** pointer and does not copy the array content. The caller must ensure that the data pointed to by **disposalTypes** is valid when the OH_PackingOptionsForSequence object is used. When this API is called for multiple times, the new **disposalTypes** pointer replaces the previously saved pointer.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to OH_PackingOptionsForSequence.|
| uint32_t *disposalTypes | Pointer to an array that defines how each image frame transitions. If the array length is less than **frameCount**, the last value in the array will be used for the remaining frames. The values can be:<br>**0**: No operation is required.<br>**1**: Keeps the image unchanged.<br>**2**: Restores the background color.<br>**3**: Restores to the previous state.|
| size_t disposalTypesLength | Length of the disposal type array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_GetDisposalTypes()

```c
Image_ErrorCode OH_PackingOptionsForSequence_GetDisposalTypes(OH_PackingOptionsForSequence *options,uint32_t *disposalTypes, size_t disposalTypesLength)
```

**Description**

Obtains the disposal type array for image sequence encoding.

Restrictions: **options** and **disposalTypes** cannot be null pointers, and **disposalTypesLength** must be greater than 0. The API copies the configured disposal type array to the **disposalTypes** buffer passed by the caller. If the API returns a failure, the output buffer content should not be used.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to OH_PackingOptionsForSequence.|
| uint32_t *disposalTypes | Pointer to the disposal type array.|
| size_t disposalTypesLength | Length of the disposal type array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_SetLoopCount()

```c
Image_ErrorCode OH_PackingOptionsForSequence_SetLoopCount(OH_PackingOptionsForSequence *options, uint32_t loopCount)
```

**Description**

Sets the number of loops for image sequence encoding. The value range is [0, 65535], where **0** means an infinite loop. If this field is not carried, loop playback is not performed.

Restrictions: **options** cannot be a null pointer. This API saves only the input **loopCount**. If the value of **loopCount** is greater than 65535, this API returns success. However, a parameter error is returned when [OH_ImagePackerNative_PackToDataFromPixelmapSequence](#oh_imagepackernative_packtodatafrompixelmapsequence) or [OH_ImagePackerNative_PackToFileFromPixelmapSequence](#oh_imagepackernative_packtofilefrompixelmapsequence) is called for encoding.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to OH_PackingOptionsForSequence.|
| uint32_t loopCount | Number of loops.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_GetLoopCount()

```c
Image_ErrorCode OH_PackingOptionsForSequence_GetLoopCount(OH_PackingOptionsForSequence *options, uint32_t *loopCount)
```

**Description**

Obtains the number of loops for image sequence encoding.

Restrictions: **options** and **loopCount** cannot be null pointers. If the API returns a failure, the content of the output parameter should not be used.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to OH_PackingOptionsForSequence.|
| uint32_t *loopCount | Pointer to the number of loops.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_Release()

```c
Image_ErrorCode OH_PackingOptionsForSequence_Release(OH_PackingOptionsForSequence *options)
```

**Description**

Releases the pointer to an OH_PackingOptionsForSequence struct.

Restrictions: **options** cannot be a null pointer.

Resource management: After this API is called, the OH_PackingOptionsForSequence object pointed to by **options** is released and should not be used any more. Releasing the OH_PackingOptionsForSequence object does not release the array passed through [OH_PackingOptionsForSequence_SetDelayTimeList](#oh_packingoptionsforsequence_setdelaytimelist) or [OH_PackingOptionsForSequence_SetDisposalTypes](#oh_packingoptionsforsequence_setdisposaltypes).

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to OH_PackingOptionsForSequence.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImagePackerNative_Create()

```c
Image_ErrorCode OH_ImagePackerNative_Create(OH_ImagePackerNative **imagePacker)
```

**Description**

Creates the pointer to an OH_ImagePackerNative struct.

Usage scenario: This API is applicable for encoding ImageSource, PixelMap, Picture, or PixelMap sequence into data or files in formats such as JPEG, PNG, and WebP. After ImagePacker is created, you need to set parameters such as the encoding format, quality, and whether to retain image properties using OH_PackingOptions or OH_PackingOptionsForSequence.

Restrictions: **imagePacker** cannot be a null pointer. If the API returns a failure, the content of the output parameter should not be used.

Resource management: The successfully created OH_ImagePackerNative object is held by the caller and must be released using [OH_ImagePackerNative_Release](#oh_imagepackernative_release) after use. The Packer does not take over the lifecycle of the input ImageSource, PixelMap, Picture, or encoding parameter object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) **imagePacker | Double pointer to OH_ImagePackerNative.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImagePackerNative_PackToDataFromImageSource()

```c
Image_ErrorCode OH_ImagePackerNative_PackToDataFromImageSource(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_ImageSourceNative *imageSource, uint8_t *outData, size_t *size)
```

**Description**

Encodes an image source into data in a given format.

Application scenario: This API is applicable for transcoding an existing ImageSource to another image format, or re-outputting it as in-memory data after modifying image properties.

Restrictions: **imagePacker**, **options**, **imageSource**, **outData**, and **size** cannot be null pointers. Before calling this API, set ***size** to the capacity of **outData**. If the API returns a failure, the content in **outData** or the output value of **size** should not be used.

Resource management: The caller allocates and releases **outData**. Before calling this API, *set **size** to the size of the **outData** writable buffer. After this API is called successfully*, the value of **size** is updated to the actual length of the encoded data. The lifecycle of **imagePacker**, **options**, and **imageSource** is still managed by the caller. This API does not release these objects.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to OH_ImagePackerNative.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *imageSource | Pointer to the image source to encode.|
| uint8_t *outData | Pointer to the buffer used to store the output data.|
| size_t *size | Pointer to the size of the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.<br>**IMAGE_ALLOC_FAILED**: Memory allocation fails.<br> **IMAGE_TOO_LARGE**: The data or image is too large.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_ImagePackerNative_PackToDataFromPixelmap()

```c
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmap(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PixelmapNative *pixelmap, uint8_t *outData, size_t *size)
```

**Description**

Encodes a PixelMap into data in a given format.

Usage scenario: This API is applicable for encoding a PixelMap that has been decoded, edited, drawn, or algorithmically processed into in-memory data in formats such as JPEG, PNG, or WebP, for purposes such as uploading, caching, or further writing to a file.

Restrictions: **imagePacker**, **options**, **pixelmap**, **outData**, and **size** cannot be null pointers. Before calling this API, set ***size** to the capacity of **outData**. If the API returns a failure, do not use the content in **outData** or the output value of **size**.

Resource management: The caller allocates and releases **outData**. Before calling this API, *set **size** to the size of the **outData** writable buffer. After this API is called successfully*, the value of **size** is updated to the actual length of the encoded data. The lifecycle of **imagePacker**, **options**, and **pixelmap** is still managed by the caller. This API does not release these objects.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to OH_ImagePackerNative.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the PixelMap to encode.|
| uint8_t *outData | Pointer to the buffer used to store the output data.|
| size_t *size | Pointer to the size of the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.<br>**IMAGE_ALLOC_FAILED**: Memory allocation fails.<br> **IMAGE_TOO_LARGE**: The data or image is too large.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_ImagePackerNative_PackToDataFromPicture()

```c
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPicture(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PictureNative *picture, uint8_t *outData, size_t *size)
```

**Description**

Encodes a picture into data in a given format.

Restrictions: **imagePacker**, **options**, **picture**, **outData**, and **size** cannot be null pointers. Before calling this API, set ***size** to the capacity of **outData**. If the API returns a failure, the content in **outData** or the output value of **size** should not be used.

Resource management: The caller allocates and releases **outData**. Before calling this API, *set **size** to the size of the **outData** writable buffer. After this API is called successfully*, the value of **size** is updated to the actual length of the encoded data. The lifecycle of **imagePacker**, **options**, and **picture** is still managed by the caller. This API does not release these objects.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to OH_ImagePackerNative.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to the picture to encode.|
| uint8_t *outData | Pointer to the buffer used to store the output data.|
| size_t *size | Pointer to the size of the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.|

### OH_ImagePackerNative_PackToDataFromPixelmapSequence()

```c
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmapSequence(OH_ImagePackerNative *imagePacker,OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence,size_t sequenceLength, uint8_t *outData, size_t *outDataSize)
```

**Description**

Encodes a PixelMap sequence into data.

Usage scenario: This API is applicable for encoding multiple PixelMap frames into an animated image or other image formats that support sequential frames. Before encoding, use OH_PackingOptionsForSequence to set parameters such as the number of frames, delay time, and number of loops.

Restrictions: If the API returns a failure, the content in **outData** or the output value of **outDataSize** should not be used.

Resource management: The caller allocates and releases **outData**. The lifecycle of **imagePacker**, **options**, and the PixelMap object in pixelmapSequence is still managed by the caller. This API does not release these objects.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to an OH_ImagePackerNative object. It must not be NULL.|
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Encoding option parameter, which cannot be NULL. The value of **frameCount** must be greater than 0. A valid **delayTimeList** must be set. The value range of **loopCount** is [0, 65535]. Each delay time in **delayTimeList** must be greater than 0 and less than or equal to 65535. The unit is 10 ms. Each value in **disposalTypes** must be less than or equal to 3.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmapSequence | Pointer to the PixelMap sequence to encode. It cannot be NULL. The PixelMap pointer used for encoding in the array cannot be NULL.|
| size_t sequenceLength | Length of the PixelMap sequence to encode. The value must be greater than 0.|
| uint8_t *outData | Pointer to the buffer used to store the image output data after encoding. It cannot be NULL.|
| size_t *outDataSize | Pointer to the size of the buffer used to store the image output data after encoding. It cannot be NULL. Before calling this API, *set **outDataSize** to the size of the **outData** writable buffer. After this API is called successfully*, the value of **outDataSize** is updated to the actual length of the encoded data.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.|

### OH_ImagePackerNative_PackToFileFromImageSource()

```c
Image_ErrorCode OH_ImagePackerNative_PackToFileFromImageSource(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_ImageSourceNative *imageSource, int32_t fd)
```

**Description**

Encodes an image source into a file.

Usage scenario: This API is applicable for transcoding an ImageSource and directly writing it to a file descriptor, eliminating the need for the caller to manage the encoded in-memory buffer.

Restrictions: **imagePacker**, **options**, and **imageSource** cannot be null pointers. **fd** must be a writable file descriptor.

Resource management: **fd** must be a writable file descriptor. The caller is responsible for opening and closing the file descriptor. The API does not release **imagePacker**, **options**, or **imageSource**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to OH_ImagePackerNative.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *imageSource | Pointer to the image source to encode.|
| int32_t fd | File descriptor, which is writable.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_ImagePackerNative_PackToFileFromPixelmap()

```c
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmap(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PixelmapNative *pixelmap, int32_t fd)
```

**Description**

Encodes a PixelMap into a file.

Usage scenario: This API is applicable for directly saving a processed PixelMap as a file. Compared with PackToDataFromPixelmap, this API does not require the caller to pre-allocate an output data buffer.

Restrictions: **imagePacker**, **options**, and **pixelmap** cannot be null pointers. **fd** must be a writable file descriptor.

Resource management: **fd** must be a writable file descriptor. The caller is responsible for opening and closing the file descriptor. The API does not release **imagePacker**, **options**, or **pixelmap**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to OH_ImagePackerNative.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the PixelMap to encode.|
| int32_t fd | File descriptor, which is writable.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_ImagePackerNative_PackToFileFromPicture()

```c
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPicture(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PictureNative *picture, int32_t fd)
```

**Description**

Encodes a picture into a file.

Restrictions: **imagePacker**, **options**, and **picture** cannot be null pointers. **fd** must be a writable file descriptor.

Resource management: The caller is responsible for opening and closing the file descriptor (fd). The API does not release **imagePacker**, **options**, or **picture**.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to OH_ImagePackerNative.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to the picture to encode.|
| int32_t fd | File descriptor, which is writable.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_ImagePackerNative_PackToFileFromPixelmapSequence()

```c
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmapSequence(OH_ImagePackerNative *imagePacker,OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence, size_t sequenceLength, int32_t fd)
```

**Description**

Encodes a PixelMap sequence into a file.

Restrictions: If the API returns a failure, the content in the target file should not be used.

Resource management: The caller is responsible for opening and closing the file descriptor (fd). The API does not release **imagePacker**, **options**, or the PixelMap object in pixelmapSequence.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to an OH_ImagePackerNative object. It must not be NULL.|
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Encoding option parameter, which cannot be NULL. The value of **frameCount** must be greater than 0. A valid **delayTimeList** must be set. The value range of **loopCount** is [0, 65535]. Each delay time in **delayTimeList** must be greater than 0 and less than or equal to 65535. Each value in **disposalTypes** must be less than or equal to 3.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmapSequence | Pointer to the PixelMap sequence to encode. It cannot be NULL. The PixelMap pointer used for encoding in the array cannot be NULL.|
| size_t sequenceLength | Length of the PixelMap sequence used for encoding. The value must be greater than 0.|
| int32_t fd | File descriptor, which must be writable.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.|

### OH_ImagePackerNative_GetSupportedFormats()

```c
Image_ErrorCode OH_ImagePackerNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)
```

**Description**

Obtains the supported image formats that can be encoded.

Application scenario: This API is applicable for dynamically querying the target formats supported by the current system before encoding, and setting the MIME type accordingly via OH_PackingOptions_SetMimeType.

Restrictions: **supportedFormats** and **length** cannot be null pointers. If the API returns a failure, the content of the output parameter should not be used.

Resource management: The **supportedFormats** array returned by the API is managed by the system. The caller does not need to and should not release or modify it. If long-term storage is required, copy the array content by yourself.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Image_MimeType](capi-image-nativemodule-image-string.md) **supportedFormats | Double pointer to the supported image formats.|
| size_t *length | Pointer to the size of the array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_PACKER_INVALID_PARAMETER**: The **supportedFormats** or **length** parameter is a null pointer.|

### OH_ImagePackerNative_Release()

```c
Image_ErrorCode OH_ImagePackerNative_Release(OH_ImagePackerNative *imagePacker)
```

**Description**

Releases the pointer to an OH_ImagePackerNative struct.

Restrictions: **imagePacker** cannot be a null pointer.

Resource management: The objects successfully created through [OH_ImagePackerNative_Create](#oh_imagepackernative_create) must be released using this API after use. Releasing a packer does not release the OH_PackingOptions, OH_PackingOptionsForSequence, OH_ImageSourceNative, OH_PixelmapNative, or OH_PictureNative object. Resource management: After this API is called, the OH_ImagePackerNative object pointed to by **imagePacker** is released and should not be used any more.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to OH_ImagePackerNative.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|
