# image_packer_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

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
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) | OH_PackingOptions | Describes the image packing options, which are encapsulated at the native layer. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.|
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) | OH_PackingOptionsForSequence | Describes the image sequence encoding parameters.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range) | IMAGE_PACKER_DYNAMIC_RANGE | Enumerates the dynamic range for encoding.|

### Functions

| Name| Description|
| -- | -- |
| [Image_ErrorCode OH_PackingOptions_Create(OH_PackingOptions **options)](#oh_packingoptions_create) | Creates the pointer to an OH_PackingOptions struct.|
| [Image_ErrorCode OH_PackingOptions_GetMimeType(OH_PackingOptions *options, Image_MimeType *format)](#oh_packingoptions_getmimetype) | Obtains the MIME type.|
| [Image_ErrorCode OH_PackingOptions_GetMimeTypeWithNull(OH_PackingOptions *options, Image_MimeType *format)](#oh_packingoptions_getmimetypewithnull) | Obtains the MIME type in the packing options. The output **format.data** is terminated with a string terminator.|
| [Image_ErrorCode OH_PackingOptions_SetMimeType(OH_PackingOptions *options, Image_MimeType *format)](#oh_packingoptions_setmimetype) | Sets the MIME type.|
| [Image_ErrorCode OH_PackingOptions_GetQuality(OH_PackingOptions *options, uint32_t *quality)](#oh_packingoptions_getquality) | Obtains the encoding quality.|
| [Image_ErrorCode OH_PackingOptions_SetQuality(OH_PackingOptions *options, uint32_t quality)](#oh_packingoptions_setquality) | Sets the encoding quality.|
| [ Image_ErrorCode OH_PackingOptions_GetNeedsPackProperties(OH_PackingOptions *options, bool *needsPackProperties)](#oh_packingoptions_getneedspackproperties) | Obtains the **needsPackProperties** parameter in the OH_PackingOptions struct.|
| [Image_ErrorCode OH_PackingOptions_SetNeedsPackProperties(OH_PackingOptions *options, bool needsPackProperties)](#oh_packingoptions_setneedspackproperties) | Sets the **needsPackProperties** parameter in the OH_PackingOptions struct.|
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

```
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

```
Image_ErrorCode OH_PackingOptions_Create(OH_PackingOptions **options)
```

**Description**

Creates the pointer to an OH_PackingOptions struct.

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

```
Image_ErrorCode OH_PackingOptions_GetMimeType(OH_PackingOptions *options,Image_MimeType *format)
```

**Description**

Obtains the MIME type.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [Image_MimeType](capi-image-nativemodule-image-string.md) *format | Pointer to the image format. You can pass in a null pointer with the size set to zero. In this case, the system will allocate memory, but you must release the memory after use.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_GetMimeTypeWithNull()

```
Image_ErrorCode OH_PackingOptions_GetMimeTypeWithNull(OH_PackingOptions *options,Image_MimeType *format)
```

**Description**

Obtains the MIME type in the packing options. The output **format.data** is terminated with a string terminator.

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

```
Image_ErrorCode OH_PackingOptions_SetMimeType(OH_PackingOptions *options,Image_MimeType *format)
```

**Description**

Sets the MIME type.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [Image_MimeType](capi-image-nativemodule-image-string.md) *format | Pointer to the image format.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_GetQuality()

```
Image_ErrorCode OH_PackingOptions_GetQuality(OH_PackingOptions *options,uint32_t *quality)
```

**Description**

Obtains the encoding quality.

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

```
Image_ErrorCode OH_PackingOptions_SetQuality(OH_PackingOptions *options,uint32_t quality)
```

**Description**

Sets the encoding quality.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| uint32_t quality | Encoding quality.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_GetNeedsPackProperties()

```
 Image_ErrorCode OH_PackingOptions_GetNeedsPackProperties(OH_PackingOptions *options,bool *needsPackProperties)
```

**Description**

Obtains the **needsPackProperties** parameter in the OH_PackingOptions struct.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| bool *needsPackProperties | Pointer to the parameter that specifies whether to encode image property information, for example, EXIF.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_SetNeedsPackProperties()

```
Image_ErrorCode OH_PackingOptions_SetNeedsPackProperties(OH_PackingOptions *options,bool needsPackProperties)
```

**Description**

Sets the **needsPackProperties** parameter in the OH_PackingOptions struct.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| bool needsPackProperties | Whether to encode image property information, for example, EXIF.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_GetDesiredDynamicRange()

```
Image_ErrorCode OH_PackingOptions_GetDesiredDynamicRange(OH_PackingOptions *options, int32_t* desiredDynamicRange)
```

**Description**

Obtains the desired dynamic range during encoding.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| int32_t* desiredDynamicRange | Pointer to the desired dynamic range. For details about the available options, see [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_SetDesiredDynamicRange()

```
Image_ErrorCode OH_PackingOptions_SetDesiredDynamicRange(OH_PackingOptions *options, int32_t desiredDynamicRange)
```

**Description**

Sets the desired dynamic range during encoding.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| int32_t desiredDynamicRange | Desired dynamic range. For details about the available options, see [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptions_Release()

```
Image_ErrorCode OH_PackingOptions_Release(OH_PackingOptions *options)
```

**Description**

Releases the pointer to an OH_PackingOptions struct.

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

```
Image_ErrorCode OH_PackingOptionsForSequence_Create(OH_PackingOptionsForSequence **options)
```

**Description**

Creates the pointer to an OH_PackingOptionsForSequence struct.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) **options | Double pointer to the OH_PackingOptionsForSequence struct created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_SetFrameCount()

```
Image_ErrorCode OH_PackingOptionsForSequence_SetFrameCount(OH_PackingOptionsForSequence *options,uint32_t frameCount)
```

**Description**

Sets the number of frames for image sequence encoding.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to an OH_PackingOptionsForSequence struct.|
| uint32_t frameCount | Number of frames.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_GetFrameCount()

```
Image_ErrorCode OH_PackingOptionsForSequence_GetFrameCount(OH_PackingOptionsForSequence *options,uint32_t *frameCount)
```

**Description**

Obtains the number of frames for image sequence encoding.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to an OH_PackingOptionsForSequence struct.|
| uint32_t *frameCount | Pointer to the number of frames.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_SetDelayTimeList()

```
Image_ErrorCode OH_PackingOptionsForSequence_SetDelayTimeList(OH_PackingOptionsForSequence *options,int32_t *delayTimeList, size_t delayTimeListLength)
```

**Description**

Sets the delay time array for image sequence encoding.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to an OH_PackingOptionsForSequence struct.|
| int32_t *delayTimeList | Pointer to the delay time array.|
| size_t delayTimeListLength | Length of the delay time array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_GetDelayTimeList()

```
Image_ErrorCode OH_PackingOptionsForSequence_GetDelayTimeList(OH_PackingOptionsForSequence *options,int32_t *delayTimeList, size_t delayTimeListLength)
```

**Description**

Obtains the delay time array for image sequence encoding.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to an OH_PackingOptionsForSequence struct.|
| int32_t *delayTimeList | Pointer to the delay time array.|
| size_t delayTimeListLength | Length of the delay time array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_SetDisposalTypes()

```
Image_ErrorCode OH_PackingOptionsForSequence_SetDisposalTypes(OH_PackingOptionsForSequence *options,uint32_t *disposalTypes, size_t disposalTypesLength)
```

**Description**

Sets the disposal type array for image sequence encoding.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to an OH_PackingOptionsForSequence struct.|
| uint32_t *disposalTypes | Pointer to an array that defines how each image frame transitions. If the array length is less than **frameCount**, the last value in the array will be used for the remaining frames. The values can be:<br>**0**: No operation is required.<br>**1**: Keeps the image unchanged.<br>**2**: Restores the background color.<br>**3**: Restores to the previous state.|
| size_t disposalTypesLength | Length of the disposal type array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_GetDisposalTypes()

```
Image_ErrorCode OH_PackingOptionsForSequence_GetDisposalTypes(OH_PackingOptionsForSequence *options,uint32_t *disposalTypes, size_t disposalTypesLength)
```

**Description**

Obtains the disposal type array for image sequence encoding.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to an OH_PackingOptionsForSequence struct.|
| uint32_t *disposalTypes | Pointer to the disposal type array.|
| size_t disposalTypesLength | Length of the disposal type array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_SetLoopCount()

```
Image_ErrorCode OH_PackingOptionsForSequence_SetLoopCount(OH_PackingOptionsForSequence *options, uint32_t loopCount)
```

**Description**

Sets the number of loops for image sequence encoding. The value range is [0, 65535], where **0** means an infinite loop. If this field is not carried, loop playback is not performed.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to an OH_PackingOptionsForSequence struct.|
| uint32_t loopCount | Number of loops.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_GetLoopCount()

```
Image_ErrorCode OH_PackingOptionsForSequence_GetLoopCount(OH_PackingOptionsForSequence *options, uint32_t *loopCount)
```

**Description**

Obtains the number of loops for image sequence encoding.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to an OH_PackingOptionsForSequence struct.|
| uint32_t *loopCount | Pointer to the number of loops.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PackingOptionsForSequence_Release()

```
Image_ErrorCode OH_PackingOptionsForSequence_Release(OH_PackingOptionsForSequence *options)
```

**Description**

Releases the pointer to an OH_PackingOptionsForSequence struct.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to an OH_PackingOptionsForSequence struct.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImagePackerNative_Create()

```
Image_ErrorCode OH_ImagePackerNative_Create(OH_ImagePackerNative **imagePacker)
```

**Description**

Creates the pointer to an OH_ImagePackerNative struct.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) **imagePacker | Double pointer to the OH_ImagePackerNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImagePackerNative_PackToDataFromImageSource()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromImageSource(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_ImageSourceNative *imageSource, uint8_t *outData, size_t *size)
```

**Description**

Encodes an image source into data in a given format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to an OH_ImagePackerNative object.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *imageSource | Pointer to the image source to encode.|
| uint8_t *outData | Pointer to the buffer used to store the output data.|
| size_t *size | Pointer to the size of the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.<br>**IMAGE_ALLOC_FAILED**: Memory allocation fails.<br> **IMAGE_TOO_LARGE**: The data or image is too large.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_ImagePackerNative_PackToDataFromPixelmap()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmap(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PixelmapNative *pixelmap, uint8_t *outData, size_t *size)
```

**Description**

Encodes a PixelMap into data in a given format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to an OH_ImagePackerNative object.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the PixelMap to encode.|
| uint8_t *outData | Pointer to the buffer used to store the output data.|
| size_t *size | Pointer to the size of the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.<br>**IMAGE_ALLOC_FAILED**: Memory allocation fails.<br> **IMAGE_TOO_LARGE**: The data or image is too large.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_ImagePackerNative_PackToDataFromPicture()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPicture(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PictureNative *picture, uint8_t *outData, size_t *size)
```

**Description**

Encodes a picture into data in a given format.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to an OH_ImagePackerNative object.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to the picture to encode.|
| uint8_t *outData | Pointer to the buffer used to store the output data.|
| size_t *size | Pointer to the size of the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.|

### OH_ImagePackerNative_PackToDataFromPixelmapSequence()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmapSequence(OH_ImagePackerNative *imagePacker,OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence,size_t sequenceLength, uint8_t *outData, size_t *outDataSize)
```

**Description**

Encodes a PixelMap sequence into data.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to an OH_ImagePackerNative object.|
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to an [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) struct.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmapSequence | Double pointer to the PixelMap sequence to encode.|
| size_t sequenceLength | Length of the PixelMap sequence.|
| uint8_t *outData | Pointer to the buffer used to store the output data.|
| size_t *outDataSize | Pointer to the size of the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.|

### OH_ImagePackerNative_PackToFileFromImageSource()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromImageSource(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_ImageSourceNative *imageSource, int32_t fd)
```

**Description**

Encodes an image source into a file.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to an OH_ImagePackerNative object.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *imageSource | Pointer to the image source to encode.|
| int32_t fd | File descriptor, which is writable.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_ImagePackerNative_PackToFileFromPixelmap()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmap(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PixelmapNative *pixelmap, int32_t fd)
```

**Description**

Encodes a PixelMap into a file.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to an OH_ImagePackerNative object.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the PixelMap to encode.|
| int32_t fd | File descriptor, which is writable.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_ImagePackerNative_PackToFileFromPicture()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPicture(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PictureNative *picture, int32_t fd)
```

**Description**

Encodes a picture into a file.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to an OH_ImagePackerNative object.|
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | Pointer to an OH_PackingOptions struct.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to the picture to encode.|
| int32_t fd | File descriptor, which is writable.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.<br>**IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_ImagePackerNative_PackToFileFromPixelmapSequence()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmapSequence(OH_ImagePackerNative *imagePacker,OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence, size_t sequenceLength, int32_t fd)
```

**Description**

Encodes a PixelMap sequence into a file.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to an OH_ImagePackerNative object.|
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | Pointer to an [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) struct.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmapSequence | Double pointer to the PixelMap sequence to encode.|
| size_t sequenceLength | Length of the PixelMap sequence.|
| int32_t fd | File descriptor, which is writable.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_DECODE_FAILED**: Decoding fails.|

### OH_ImagePackerNative_GetSupportedFormats()

```
Image_ErrorCode OH_ImagePackerNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)
```

**Description**

Obtains the supported image formats that can be encoded.

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

```
Image_ErrorCode OH_ImagePackerNative_Release(OH_ImagePackerNative *imagePacker)
```

**Description**

Releases the pointer to an OH_ImagePackerNative struct.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | Pointer to an OH_ImagePackerNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|
