# image_source_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the APIs for image decoding.

**File to include**: <multimedia/image_framework/image/image_source_native.h>

**Library**: libimage_source.so

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) | OH_ImageSourceNative | Describes the image source, which is encapsulated at the native layer and is used to create image data.|
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) | OH_ImageSource_Info | Describes the image source information, which is encapsulated at the native layer. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.|
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) | OH_DecodingOptionsForPicture | Describes the decoding options for pictures. They are obtained by calling [OH_DecodingOptionsForPicture_Create](#oh_decodingoptionsforpicture_create).|
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) | OH_DecodingOptions | Describes the decoding options, which are encapsulated at the native layer. The struct is used to set decoding options and is passed in as an input parameter for creating a PixelMap. For details, see [OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap).|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [IMAGE_DYNAMIC_RANGE](#image_dynamic_range) | IMAGE_DYNAMIC_RANGE | Enumerates the desired dynamic range for decoding.|
| [IMAGE_ALLOCATOR_TYPE](#image_allocator_type) | IMAGE_ALLOCATOR_TYPE | Enumerates the types of allocators used to allocate PixelMap memory.|
| [Image_CropAndScaleStrategy](#image_cropandscalestrategy) | Image_CropAndScaleStrategy | Enumerates the cropping and scaling strategies when **desiredSize** and **desiredRegion** are both specified.|

### Functions

| Name| Description|
| -- | -- |
| [Image_ErrorCode OH_ImageSourceInfo_Create(OH_ImageSource_Info **info)](#oh_imagesourceinfo_create) | Creates the pointer to an OH_ImageSource_Info object.|
| [Image_ErrorCode OH_ImageSourceInfo_GetWidth(OH_ImageSource_Info *info, uint32_t *width)](#oh_imagesourceinfo_getwidth) | Obtains the image width.|
| [Image_ErrorCode OH_ImageSourceInfo_GetHeight(OH_ImageSource_Info *info, uint32_t *height)](#oh_imagesourceinfo_getheight) | Obtains the image height.|
| [Image_ErrorCode OH_ImageSourceInfo_GetDynamicRange(OH_ImageSource_Info *info, bool *isHdr)](#oh_imagesourceinfo_getdynamicrange) | Obtains the dynamic range of an image.|
| [Image_ErrorCode OH_ImageSourceInfo_GetMimetype(OH_ImageSource_Info *info, Image_MimeType *mimetype)](#oh_imagesourceinfo_getmimetype) | Obtains the MIME type of an image.|
| [Image_ErrorCode OH_ImageSourceInfo_Release(OH_ImageSource_Info *info)](#oh_imagesourceinfo_release) | Releases the pointer to an OH_ImageSource_Info object.|
| [Image_ErrorCode OH_DecodingOptions_Create(OH_DecodingOptions **options)](#oh_decodingoptions_create) | Creates the pointer to an OH_DecodingOptions object.|
| [Image_ErrorCode OH_DecodingOptions_GetPixelFormat(OH_DecodingOptions *options, int32_t *pixelFormat)](#oh_decodingoptions_getpixelformat) | Obtains the pixel format.|
| [Image_ErrorCode OH_DecodingOptions_SetPixelFormat(OH_DecodingOptions *options, int32_t pixelFormat)](#oh_decodingoptions_setpixelformat) | Sets the pixel format.|
| [Image_ErrorCode OH_DecodingOptions_GetIndex(OH_DecodingOptions *options, uint32_t *index)](#oh_decodingoptions_getindex) | Obtains the index of an image.|
| [Image_ErrorCode OH_DecodingOptions_SetIndex(OH_DecodingOptions *options, uint32_t index)](#oh_decodingoptions_setindex) | Sets the index for an image.|
| [Image_ErrorCode OH_DecodingOptions_GetRotate(OH_DecodingOptions *options, float *rotate)](#oh_decodingoptions_getrotate) | Obtains the rotation degree.|
| [Image_ErrorCode OH_DecodingOptions_SetRotate(OH_DecodingOptions *options, float rotate)](#oh_decodingoptions_setrotate) | Sets the rotation angle.|
| [Image_ErrorCode OH_DecodingOptions_GetDesiredSize(OH_DecodingOptions *options, Image_Size *desiredSize)](#oh_decodingoptions_getdesiredsize) | Obtains the desired output size.|
| [Image_ErrorCode OH_DecodingOptions_SetDesiredSize(OH_DecodingOptions *options, Image_Size *desiredSize)](#oh_decodingoptions_setdesiredsize) | Sets the desired output size.|
| [Image_ErrorCode OH_DecodingOptions_GetDesiredRegion(OH_DecodingOptions *options, Image_Region *desiredRegion)](#oh_decodingoptions_getdesiredregion) | Obtains the region to decode.<br> Since the corresponding **SetDesiredRegion** function cannot meet the regional decoding requirements, starting from API 19, you are advised to use [OH_DecodingOptions_GetCropRegion](#oh_decodingoptions_getcropregion) instead.|
| [Image_ErrorCode OH_DecodingOptions_SetDesiredRegion(OH_DecodingOptions *options, Image_Region *desiredRegion)](#oh_decodingoptions_setdesiredregion) | Sets the region to decode.<br> The actual decoding will process the entire original image, without any regional decoding effect. Starting from API 19, you are advised to use [OH_DecodingOptions_SetCropRegion](#oh_decodingoptions_setcropregion) instead.|
| [Image_ErrorCode OH_DecodingOptions_GetDesiredDynamicRange(OH_DecodingOptions *options, int32_t *desiredDynamicRange)](#oh_decodingoptions_getdesireddynamicrange) | Obtains the desired dynamic range configured during decoding.|
| [Image_ErrorCode OH_DecodingOptions_SetDesiredDynamicRange(OH_DecodingOptions *options, int32_t desiredDynamicRange)](#oh_decodingoptions_setdesireddynamicrange) | Sets the desired dynamic range during decoding.|
| [Image_ErrorCode OH_DecodingOptions_GetDesiredColorSpace(OH_DecodingOptions *options, int32_t *colorSpace)](#oh_decodingoptions_getdesiredcolorspace) | Obtains the color space set in the decoding options.|
| [Image_ErrorCode OH_DecodingOptions_SetDesiredColorSpace(OH_DecodingOptions *options, int32_t colorSpace)](#oh_decodingoptions_setdesiredcolorspace) | Sets the desired color space for the decoding options.|
| [Image_ErrorCode OH_DecodingOptions_SetCropAndScaleStrategy(OH_DecodingOptions *options, int32_t cropAndScaleStrategy)](#oh_decodingoptions_setcropandscalestrategy) | Sets the cropping and scaling strategy used during decoding.|
| [Image_ErrorCode OH_DecodingOptions_GetCropAndScaleStrategy(OH_DecodingOptions *options, int32_t *cropAndScaleStrategy)](#oh_decodingoptions_getcropandscalestrategy) | Obtains the cropping and scaling strategy used during decoding.|
| [Image_ErrorCode OH_DecodingOptions_GetCropRegion(OH_DecodingOptions *options, Image_Region *cropRegion)](#oh_decodingoptions_getcropregion) | Obtains the cropping region in the decoding options.|
| [Image_ErrorCode OH_DecodingOptions_SetCropRegion(OH_DecodingOptions *options, Image_Region *cropRegion)](#oh_decodingoptions_setcropregion) | Sets the cropping region in the decoding options.|
| [Image_ErrorCode OH_DecodingOptions_Release(OH_DecodingOptions *options)](#oh_decodingoptions_release) | Releases the pointer to an OH_DecodingOptions object.|
| [Image_ErrorCode OH_ImageSourceNative_CreateFromUri(char *uri, size_t uriSize, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromuri) | Creates the pointer to an OH_ImageSourceNative object based on a URI.|
| [Image_ErrorCode OH_ImageSourceNative_CreateFromFd(int32_t fd, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromfd) | Creates the pointer to an OH_ImageSourceNative object based on a file descriptor.|
| [Image_ErrorCode OH_ImageSourceNative_CreateFromData(uint8_t *data, size_t dataSize, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromdata) | Creates the pointer to an OH_ImageSourceNative object based on buffer data.<br> The buffer data must be undecoded. Do not pass the pixel buffer data such as RBGA and YUV. If you want to create a PixelMap based on the pixel buffer data, call [OH_PixelmapNative_CreatePixelmap](capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap).|
| [Image_ErrorCode OH_ImageSourceNative_CreateFromDataWithUserBuffer(uint8_t *data, size_t datalength, OH_ImageSourceNative **imageSource)](#oh_imagesourcenative_createfromdatawithuserbuffer) | Creates an image source from data buffer. The data buffer is directly accessed by the image source object, and therefore the data buffer must remain accessible within the lifecycle of the image source object.|
| [Image_ErrorCode OH_ImageSourceNative_CreateFromRawFile(RawFileDescriptor *rawFile, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromrawfile) | Creates the pointer to an OH_ImageSourceNative object by using the raw file descriptor of an image resource file.|
| [Image_ErrorCode OH_ImageSourceNative_CreatePixelmap(OH_ImageSourceNative *source, OH_DecodingOptions *options, OH_PixelmapNative **pixelmap)](#oh_imagesourcenative_createpixelmap) | Creates the pointer to an OH_PixelmapNative object based on decoding options.|
| [Image_ErrorCode OH_ImageSourceNative_CreatePixelmapUsingAllocator(OH_ImageSourceNative *source, OH_DecodingOptions *options, IMAGE_ALLOCATOR_TYPE allocator, OH_PixelmapNative **pixelmap)](#oh_imagesourcenative_createpixelmapusingallocator) | Creates an OH_PixelmapNative object based on decoding options and memory type, where **allocatorType** specifies the memory type of the PixelMap.<br> By default, the system selects an appropriate memory type based on the image type, image size, and platform capability. When processing the returned PixelMap object, consider the impact of stride.|
| [Image_ErrorCode OH_ImageSourceNative_CreatePixelmapList(OH_ImageSourceNative *source, OH_DecodingOptions *options, OH_PixelmapNative *resVecPixMap[], size_t size)](#oh_imagesourcenative_createpixelmaplist) | Creates an array of OH_PixelmapNative objects based on decoding options.<br> This function decodes all frames at once. If the number of frames is high or the size of individual frames is large, it can lead to significant memory usage. In these cases, you are advised to use the **Image** component for displaying animations. The **Image** component decodes frames one by one, which uses less memory than this function.|
| [Image_ErrorCode OH_ImageSourceNative_CreatePicture(OH_ImageSourceNative *source, OH_DecodingOptionsForPicture *options, OH_PictureNative **picture)](#oh_imagesourcenative_createpicture) | Creates the pointer to an OH_PictureNative object based on decoding options.|
| [Image_ErrorCode OH_ImageSourceNative_CreatePictureAtIndex(OH_ImageSourceNative *source, uint32_t index, OH_PictureNative **picture)](#oh_imagesourcenative_createpictureatindex) | Creates the pointer to an OH_PictureNative object at the specified index.|
| [Image_ErrorCode OH_ImageSourceNative_GetDelayTimeList(OH_ImageSourceNative *source, int32_t *delayTimeList, size_t size)](#oh_imagesourcenative_getdelaytimelist) | Obtains the image delay time list.|
| [Image_ErrorCode OH_ImageSourceNative_GetImageInfo(OH_ImageSourceNative *source, int32_t index, OH_ImageSource_Info *info)](#oh_imagesourcenative_getimageinfo) | Obtains the information about an image with a given index.|
| [Image_ErrorCode OH_ImageSourceNative_GetImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)](#oh_imagesourcenative_getimageproperty) | Obtains the value of an image property.|
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyWithNull(OH_ImageSourceNative *source, Image_String *key, Image_String *value)](#oh_imagesourcenative_getimagepropertywithnull) | Obtains the value of an image property. The output **value.data** is terminated with a string terminator.|
| [Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)](#oh_imagesourcenative_modifyimageproperty) | Modifies the value of an image property.|
| [Image_ErrorCode OH_ImageSourceNative_GetFrameCount(OH_ImageSourceNative *source, uint32_t *frameCount)](#oh_imagesourcenative_getframecount) | Obtains the number of image frames.|
| [Image_ErrorCode OH_ImageSourceNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)](#oh_imagesourcenative_getsupportedformats) | Obtains the supported image formats that can be decoded.|
| [Image_ErrorCode OH_ImageSourceNative_Release(OH_ImageSourceNative *source)](#oh_imagesourcenative_release) | Releases the pointer to an OH_ImageSourceNative object.|
| [Image_ErrorCode OH_DecodingOptionsForPicture_Create(OH_DecodingOptionsForPicture **options)](#oh_decodingoptionsforpicture_create) | Creates the pointer to an OH_DecodingOptionsForPicture object.|
| [Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options, Image_AuxiliaryPictureType **desiredAuxiliaryPictures, size_t *length)](#oh_decodingoptionsforpicture_getdesiredauxiliarypictures) | Obtains desired auxiliary pictures in the decoding options (auxiliary pictures contained in **picture** expected to be decoded.)|
| [Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options, Image_AuxiliaryPictureType *desiredAuxiliaryPictures, size_t length)](#oh_decodingoptionsforpicture_setdesiredauxiliarypictures) | Sets desired auxiliary pictures in the decoding options.|
| [Image_ErrorCode OH_DecodingOptionsForPicture_Release(OH_DecodingOptionsForPicture *options)](#oh_decodingoptionsforpicture_release) | Releases the pointer to an OH_DecodingOptionsForPicture object.|

## Enum Description

### IMAGE_DYNAMIC_RANGE

```
enum IMAGE_DYNAMIC_RANGE
```

**Description**

Enumerates the desired dynamic range for decoding.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| IMAGE_DYNAMIC_RANGE_AUTO = 0 | Adaptive processing.|
| IMAGE_DYNAMIC_RANGE_SDR = 1 | Standard dynamic range (SDR).|
| IMAGE_DYNAMIC_RANGE_HDR = 2 | High dynamic range (HDR).|

### IMAGE_ALLOCATOR_TYPE

```
enum IMAGE_ALLOCATOR_TYPE
```

**Description**

Enumerates the types of allocators used to allocate PixelMap memory.

**Since**: 15

| Enum Item| Description|
| -- | -- |
| IMAGE_ALLOCATOR_TYPE_AUTO = 0 | The system determines whether to use DMA memory or shared memory to create a PixelMap.|
| IMAGE_ALLOCATOR_TYPE_DMA = 1 | DMA memory is used to create a PixelMap.|
| IMAGE_ALLOCATOR_TYPE_SHARE_MEMORY = 2 | Shared memory is used to create a PixelMap.|

### Image_CropAndScaleStrategy

```
enum Image_CropAndScaleStrategy
```

**Description**

Enumerates the cropping and scaling strategies when **desiredSize** and **desiredRegion** are both specified.<br> If the **ImageCropAndScaleStrategy** parameter is not specified in [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) and both **desiredRegion** and **desiredSize** are set, the final decoding result may vary slightly due to differences in decoding algorithms used for different image formats.<br> For example, if the original image size is 200x200, and you specify **desiredSize:{width: 150, height: 150}, desiredRegion:{x: 0, y: 0, width: 100, height: 100}**, the expectation is to decode the top-left 1/4 region of the original image and then scale the pixelMap size to 150x150.<br> For JPEG and WebP images (as well as some DNG images that decode a JPEG preview within the file and therefore are treated as JPEG format), the system first performs downsampling. For instance, it might downsample by 7/8 and then crop the region based on a 175x175 image size. As a result, the final cropped region will be slightly larger than the top-left 1/4 of the original image.<br> For SVG images, which are vector-based and can be scaled without losing clarity, the system scales the image based on the ratio of **desiredSize** to the original image size and then crops the region. This results in a decoded region that may differ from the exact 1/4 region of the original image.<br> To ensure consistent results when both **desiredRegion** and **desiredSize** are set, set the **ImageCropAndScaleStrategy** parameter to **CROP_FIRST**.

**Since**: 18

| Enum Item| Description|
| -- | -- |
| IMAGE_CROP_AND_SCALE_STRATEGY_SCALE_FIRST = 1 | Crops and then scales the image.|
| IMAGE_CROP_AND_SCALE_STRATEGY_CROP_FIRST = 2 | Scales and then crops the image.|


## Function Description

### OH_ImageSourceInfo_Create()

```
Image_ErrorCode OH_ImageSourceInfo_Create(OH_ImageSource_Info **info)
```

**Description**

Creates the pointer to an OH_ImageSource_Info object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) **info | Double pointer to the OH_ImageSource_Info object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceInfo_GetWidth()

```
Image_ErrorCode OH_ImageSourceInfo_GetWidth(OH_ImageSource_Info *info, uint32_t *width)
```

**Description**

Obtains the image width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | Pointer to an OH_ImageSource_Info object.|
| uint32_t *width | Pointer to the image width, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceInfo_GetHeight()

```
Image_ErrorCode OH_ImageSourceInfo_GetHeight(OH_ImageSource_Info *info, uint32_t *height)
```

**Description**

Obtains the image height.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | Pointer to an OH_ImageSource_Info object.|
| uint32_t *height | Pointer to the image height, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceInfo_GetDynamicRange()

```
Image_ErrorCode OH_ImageSourceInfo_GetDynamicRange(OH_ImageSource_Info *info, bool *isHdr)
```

**Description**

Obtains the dynamic range of an image.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | Pointer to an OH_ImageSource_Info object.|
| bool *isHdr | Pointer to a Boolean that specifies whether the HDR is used.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceInfo_GetMimetype()

```
Image_ErrorCode OH_ImageSourceInfo_GetMimetype(OH_ImageSource_Info *info, Image_MimeType *mimetype)
```

**Description**

Obtains the MIME type of an image.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | Pointer to an OH_ImageSource_Info object.|
| [Image_MimeType](capi-image-nativemodule-image-string.md) *mimetype | Pointer to the MIME type.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: A parameter is incorrect. The **info** or **mimetype** parameter is a null pointer.|

### OH_ImageSourceInfo_Release()

```
Image_ErrorCode OH_ImageSourceInfo_Release(OH_ImageSource_Info *info)
```

**Description**

Releases the pointer to an OH_ImageSource_Info object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | Pointer to an OH_ImageSource_Info object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_Create()

```
Image_ErrorCode OH_DecodingOptions_Create(OH_DecodingOptions **options)
```

**Description**

Creates the pointer to an OH_DecodingOptions object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) **options | Double pointer to the OH_DecodingOptions object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetPixelFormat()

```
Image_ErrorCode OH_DecodingOptions_GetPixelFormat(OH_DecodingOptions *options,int32_t *pixelFormat)
```

**Description**

Obtains the pixel format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| int32_t *pixelFormat | Pointer to the pixel format. For details about the available options, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_SetPixelFormat()

```
Image_ErrorCode OH_DecodingOptions_SetPixelFormat(OH_DecodingOptions *options,int32_t pixelFormat)
```

**Description**

Sets the pixel format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| int32_t pixelFormat | Pixel format. For details about the available options, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetIndex()

```
Image_ErrorCode OH_DecodingOptions_GetIndex(OH_DecodingOptions *options, uint32_t *index)
```

**Description**

Obtains the index of an image.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| uint32_t *index | Pointer to the index of the image.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_SetIndex()

```
Image_ErrorCode OH_DecodingOptions_SetIndex(OH_DecodingOptions *options, uint32_t index)
```

**Description**

Sets the index for an image.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| uint32_t index | Index of the image.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetRotate()

```
Image_ErrorCode OH_DecodingOptions_GetRotate(OH_DecodingOptions *options, float *rotate)
```

**Description**

Obtains the rotation degree.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| float *rotate | Pointer to the angle to rotate, in degrees.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_SetRotate()

```
Image_ErrorCode OH_DecodingOptions_SetRotate(OH_DecodingOptions *options, float rotate)
```

**Description**

Sets the rotation angle.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| float rotate | Angle to rotate, in degrees.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetDesiredSize()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredSize(OH_DecodingOptions *options,Image_Size *desiredSize)
```

**Description**

Obtains the desired output size.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| [Image_Size](capi-image-nativemodule-image-size.md) *desiredSize | Pointer to the desired output size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_SetDesiredSize()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredSize(OH_DecodingOptions *options,Image_Size *desiredSize)
```

**Description**

Sets the desired output size.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| [Image_Size](capi-image-nativemodule-image-size.md) *desiredSize | Pointer to the desired output size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetDesiredRegion()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredRegion(OH_DecodingOptions *options,Image_Region *desiredRegion)
```

**Description**

Obtains the region to decode.<br> Since the corresponding **SetDesiredRegion** function cannot meet the regional decoding requirements, starting from API 19, you are advised to use [OH_DecodingOptions_GetCropRegion](#oh_decodingoptions_getcropregion) instead.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| [Image_Region](capi-image-nativemodule-image-region.md) *desiredRegion | Pointer to the region to decode.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_SetDesiredRegion()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredRegion(OH_DecodingOptions *options,Image_Region *desiredRegion)
```

**Description**

Sets the region to decode.<br> The actual decoding will process the entire original image, without any regional decoding effect. Starting from API 19, you are advised to use [OH_DecodingOptions_SetCropRegion](#oh_decodingoptions_setcropregion) instead.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| [Image_Region](capi-image-nativemodule-image-region.md) *desiredRegion | Pointer to the region to decode.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetDesiredDynamicRange()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredDynamicRange(OH_DecodingOptions *options,int32_t *desiredDynamicRange)
```

**Description**

Obtains the desired dynamic range configured during decoding.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| int32_t *desiredDynamicRange | Pointer to the desired dynamic range. For details about the available options, see [IMAGE_DYNAMIC_RANGE](#image_dynamic_range).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_SetDesiredDynamicRange()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredDynamicRange(OH_DecodingOptions *options,int32_t desiredDynamicRange)
```

**Description**

Sets the desired dynamic range during decoding.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| int32_t desiredDynamicRange | Desired dynamic range. For details about the available options, see [IMAGE_DYNAMIC_RANGE](#image_dynamic_range).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetDesiredColorSpace()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredColorSpace(OH_DecodingOptions *options, int32_t *colorSpace)
```

**Description**

Obtains the color space set in the decoding options.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to the decoding options.|
| int32_t *colorSpace | Pointer to the color space. For details, see [ColorSpaceName](../apis-arkgraphics2d/capi-native-color-space-manager-h.md#colorspacename).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: A parameter is incorrect. The **options** or **colorSpace** parameter is a null pointer.|

### OH_DecodingOptions_SetDesiredColorSpace()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredColorSpace(OH_DecodingOptions *options, int32_t colorSpace)
```

**Description**

Sets the desired color space for the decoding options.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to the decoding options.|
| int32_t colorSpace | Color space. For details, see [ColorSpaceName](../apis-arkgraphics2d/capi-native-color-space-manager-h.md#colorspacename).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: A parameter is incorrect. The **options** parameter is a null pointer or the value of **colorSpace** is not supported.|

### OH_DecodingOptions_SetCropAndScaleStrategy()

```
Image_ErrorCode OH_DecodingOptions_SetCropAndScaleStrategy(OH_DecodingOptions *options,int32_t cropAndScaleStrategy)
```

**Description**

Sets the cropping and scaling strategy used during decoding.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| int32_t cropAndScaleStrategy | Cropping and scaling strategy that is executed when **desiredSize** and **desiredRegion** are both specified.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: The **options** parameter is a null pointer or the value of **cropAndScaleStrategy** is not within an enumerated value defined by **Image_CropAndScaleStrategy**.|

### OH_DecodingOptions_GetCropAndScaleStrategy()

```
Image_ErrorCode OH_DecodingOptions_GetCropAndScaleStrategy(OH_DecodingOptions *options,int32_t *cropAndScaleStrategy)
```

**Description**

Obtains the cropping and scaling strategy used during decoding.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| int32_t *cropAndScaleStrategy | Pointer to the cropping and scaling strategy that is executed when **desiredSize** and **desiredRegion** are both specified.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: The **options** or **cropAndScaleStrategy** parameter is a null pointer.|

### OH_DecodingOptions_GetCropRegion()

```
Image_ErrorCode OH_DecodingOptions_GetCropRegion(OH_DecodingOptions *options, Image_Region *cropRegion)
```

**Description**

Obtains the cropping region in the decoding options.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to the decoding options.|
| [Image_Region](capi-image-nativemodule-image-region.md) *cropRegion | Pointer to the cropping region.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: The **options** or **cropRegion** parameter is a null pointer.|

### OH_DecodingOptions_SetCropRegion()

```
Image_ErrorCode OH_DecodingOptions_SetCropRegion(OH_DecodingOptions *options, Image_Region *cropRegion)
```

**Description**

Sets the cropping region in the decoding options.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to the decoding options.|
| [Image_Region](capi-image-nativemodule-image-region.md) *cropRegion | Pointer to the cropping region.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: The **options** or **cropRegion** parameter is a null pointer.|

### OH_DecodingOptions_Release()

```
Image_ErrorCode OH_DecodingOptions_Release(OH_DecodingOptions *options)
```

**Description**

Releases the pointer to an OH_DecodingOptions object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_CreateFromUri()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromUri(char *uri, size_t uriSize, OH_ImageSourceNative **res)
```

**Description**

Creates the pointer to an OH_ImageSourceNative object based on a URI.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char *uri | Pointer to the URI of the image source. Only file URIs or Base64 URIs are accepted. Currently, only absolute paths are supported.|
| size_t uriSize | URI length.|
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) **res | Double pointer to the OH_ImageSourceNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_BAD_SOURCE**: The decoding data source is abnormal.|

### OH_ImageSourceNative_CreateFromFd()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromFd(int32_t fd, OH_ImageSourceNative **res)
```

**Description**

Creates the pointer to an OH_ImageSourceNative object based on a file descriptor.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| int32_t fd | File descriptor.|
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) **res | Double pointer to the OH_ImageSourceNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_CreateFromData()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromData(uint8_t *data, size_t dataSize, OH_ImageSourceNative **res)
```

**Description**

Creates the pointer to an OH_ImageSourceNative object based on buffer data.<br> The buffer data must be undecoded. Do not pass the pixel buffer data such as RBGA and YUV. If you want to create a PixelMap based on the pixel buffer data, call [OH_PixelmapNative_CreatePixelmap](capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| uint8_t *data | Pointer to the buffer data.|
| size_t dataSize | Size of the buffer.|
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) **res | Double pointer to the OH_ImageSourceNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_BAD_SOURCE**: The decoding data source is abnormal.|

### OH_ImageSourceNative_CreateFromDataWithUserBuffer()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromDataWithUserBuffer(uint8_t *data, size_t datalength,OH_ImageSourceNative **imageSource)
```

**Description**

Creates an image source from data buffer. The data buffer is directly accessed by the image source object, and therefore the data buffer must remain accessible within the lifecycle of the image source object.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| uint8_t *data | Pointer to the data buffer.|
| size_t datalength | Size of the data buffer.|
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) **imageSource | Double pointer to the image source.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: The **data** or **imageSource** parameter is a null pointer or the **datalength** parameter is **0**.|

### OH_ImageSourceNative_CreateFromRawFile()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromRawFile(RawFileDescriptor *rawFile, OH_ImageSourceNative **res)
```

**Description**

Creates the pointer to an OH_ImageSourceNative object by using the raw file descriptor of an image resource file.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [RawFileDescriptor](../apis-localization-kit/capi-rawfile-rawfiledescriptor.md) *rawFile | Pointer to the file descriptor of the raw file.|
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) **res | Double pointer to the OH_ImageSourceNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_CreatePixelmap()

```
Image_ErrorCode OH_ImageSourceNative_CreatePixelmap(OH_ImageSourceNative *source, OH_DecodingOptions *options,OH_PixelmapNative **pixelmap)
```

**Description**

Creates the pointer to an OH_PixelmapNative object based on decoding options.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | Pointer to an OH_ImageSourceNative object.|
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to the decoding options.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the OH_PixelmapNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_CreatePixelmapUsingAllocator()

```
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapUsingAllocator(OH_ImageSourceNative *source,OH_DecodingOptions *options, IMAGE_ALLOCATOR_TYPE allocator, OH_PixelmapNative **pixelmap)
```

**Description**

Creates an OH_PixelmapNative object based on decoding options and memory type, where **allocatorType** specifies the memory type of the PixelMap.<br> By default, the system selects an appropriate memory type based on the image type, image size, and platform capability. When processing the returned PixelMap object, consider the impact of stride.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | Pointer to an OH_ImageSourceNative object.|
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to the decoding options.|
| [IMAGE_ALLOCATOR_TYPE](#image_allocator_type) allocator | Memory type used by the returned PixelMap.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the OH_PixelmapNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_BAD_SOURCE**: The data source is abnormal.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: The MIME type is not supported.<br>         **IMAGE_SOURCE_TOO_LARGE**: The image is too large.<br>         **IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE**: The allocator type is not supported. For example, decoding HDR images using shared memory is not supported because only DMA supports HDR metadata.<br>         **IMAGE_SOURCE_UNSUPPORTED_OPTIONS**: The options are not supported. For example, an image cannot be converted into the required pixel format.<br>         **IMAGE_DECODE_FAILED**: Decoding fails.<br>         **IMAGE_SOURCE_ALLOC_FAILED**: The memory allocation fails.|

### OH_ImageSourceNative_CreatePixelmapList()

```
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapList(OH_ImageSourceNative *source, OH_DecodingOptions *options,OH_PixelmapNative *resVecPixMap[], size_t size)
```

**Description**

Creates an array of OH_PixelmapNative objects based on decoding options.<br> This function decodes all frames at once. If the number of frames is high or the size of individual frames is large, it can lead to significant memory usage. In these cases, you are advised to use the **Image** component for displaying animations. The **Image** component decodes frames one by one, which uses less memory than this function.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | Pointer to an OH_ImageSourceNative object.|
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to the decoding options.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *resVecPixMap[] | Pointer to an array of OH_PixelmapNative objects created at the C++ local layer.|
| size_t size | Size of the array. You can use [OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount) to obtain the size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported.|

### OH_ImageSourceNative_CreatePicture()

```
Image_ErrorCode OH_ImageSourceNative_CreatePicture(OH_ImageSourceNative *source, OH_DecodingOptionsForPicture *options,OH_PictureNative **picture)
```

**Description**

Creates the pointer to an OH_PictureNative object based on decoding options.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | Pointer to an OH_ImageSourceNative object.|
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | Pointer to the decoding options.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **picture | Double pointer to the OH_PictureNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_DECODE_FAILED**: Decoding fails.|

### OH_ImageSourceNative_CreatePictureAtIndex()

```
Image_ErrorCode OH_ImageSourceNative_CreatePictureAtIndex(OH_ImageSourceNative *source, uint32_t index,OH_PictureNative **picture)
```

**Description**

Creates the pointer to an OH_PictureNative object at the specified index.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to an OH_ImageSourceNative object.|
| uint32_t index | Index of the image.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **picture | Double pointer to the OH_PictureNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_SOURCE**: The data source is abnormal.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: The MIME type is not supported.<br>         **IMAGE_SOURCE_TOO_LARGE**: The image is too large.<br>         **IMAGE_SOURCE_UNSUPPORTED_OPTIONS**: The options are not supported. For example, an invalid image ID.<br>         **IMAGE_DECODE_FAILED**: Decoding fails.|

### OH_ImageSourceNative_GetDelayTimeList()

```
Image_ErrorCode OH_ImageSourceNative_GetDelayTimeList(OH_ImageSourceNative *source, int32_t *delayTimeList, size_t size)
```

**Description**

Obtains the image delay time list.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | Pointer to an OH_ImageSourceNative object.|
| int32_t *delayTimeList | Pointer to the delay time list obtained. It cannot be a null pointer.|
| size_t size | Size of the delay time list. You can use [OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount) to obtain the size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_GetImageInfo()

```
Image_ErrorCode OH_ImageSourceNative_GetImageInfo(OH_ImageSourceNative *source, int32_t index,OH_ImageSource_Info *info)
```

**Description**

Obtains the information about an image with a given index.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | Pointer to an OH_ImageSourceNative object.|
| int32_t index | Index of an image. For a GIF image, the value range is [0, N-1], where N indicates the number of GIF frames. For an image with only one frame, you can pass in **0**.|
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | Pointer to the image information obtained, which is an OH_ImageSource_Info struct.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_GetImageProperty()

```
Image_ErrorCode OH_ImageSourceNative_GetImageProperty(OH_ImageSourceNative *source, Image_String *key,Image_String *value)
```

**Description**

Obtains the value of an image property.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | Pointer to an OH_ImageSourceNative object.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property key. For details, see [Image_String](capi-image-nativemodule-image-string.md). For details about the value range of **key**, see the definition of [OHOS_IMAGE_PROPERTY_XXX](capi-image-common-h.md#variables). The memory must be released after the image source is used. For details, see [OH_ImageSourceNative_Release](#oh_imagesourcenative_release).|
| [Image_String](capi-image-nativemodule-image-string.md) *value | Pointer to the value obtained. You can pass in a null pointer with the size set to zero. In this case, the system will allocate memory, but you must release the memory after use.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_GetImagePropertyWithNull()

```
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyWithNull(OH_ImageSourceNative *source, Image_String *key,Image_String *value)
```

**Description**

Obtains the value of an image property. The output **value.data** is terminated with a string terminator.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | Pointer to an OH_ImageSourceNative object.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property key.|
| [Image_String](capi-image-nativemodule-image-string.md) *value | Pointer to the value obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: The **source**, **key**, or **value** parameter is a null pointer.|

### OH_ImageSourceNative_ModifyImageProperty()

```
Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty(OH_ImageSourceNative *source, Image_String *key,Image_String *value)
```

**Description**

Modifies the value of an image property.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | Pointer to an OH_ImageSourceNative object.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property key. For details, see [Image_String](capi-image-nativemodule-image-string.md). **key** is an EXIF constant. The memory must be released after the image source is used. For details, see [OH_ImageSourceNative_Release](#oh_imagesourcenative_release).|
| [Image_String](capi-image-nativemodule-image-string.md) *value | Pointer to the new value.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_GetFrameCount()

```
Image_ErrorCode OH_ImageSourceNative_GetFrameCount(OH_ImageSourceNative *source, uint32_t *frameCount)
```

**Description**

Obtains the number of image frames.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | Pointer to an OH_ImageSourceNative object.|
| uint32_t *frameCount | Pointer to the number of frames obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_GetSupportedFormats()

```
Image_ErrorCode OH_ImageSourceNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)
```

**Description**

Obtains the supported image formats that can be decoded.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Image_MimeType](capi-image-nativemodule-image-string.md) **supportedFormats | Double pointer to the supported image formats.|
| size_t *length | Pointer to the size of the array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: The **supportedFormats** or **length** parameter is a null pointer.|

### OH_ImageSourceNative_Release()

```
Image_ErrorCode OH_ImageSourceNative_Release(OH_ImageSourceNative *source)
```

**Description**

Releases the pointer to an OH_ImageSourceNative object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | Pointer to an OH_ImageSourceNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptionsForPicture_Create()

```
Image_ErrorCode OH_DecodingOptionsForPicture_Create(OH_DecodingOptionsForPicture **options)
```

**Description**

Creates the pointer to an OH_DecodingOptionsForPicture object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) **options | Double pointer to the OH_DecodingOptionsForPicture object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures()

```
Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options,Image_AuxiliaryPictureType **desiredAuxiliaryPictures, size_t *length)
```

**Description**

Obtains desired auxiliary pictures in the decoding options (auxiliary pictures contained in **picture** expected to be decoded.)

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | Pointer to an OH_DecodingOptionsForPicture object.|
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) **desiredAuxiliaryPictures | Double pointer to the desired auxiliary pictures.|
| size_t *length | Length of the desired auxiliary pictures.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures()

```
Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options,Image_AuxiliaryPictureType *desiredAuxiliaryPictures, size_t length)
```

**Description**

Sets desired auxiliary pictures in the decoding options.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | Pointer to an OH_DecodingOptionsForPicture object.|
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) *desiredAuxiliaryPictures | Pointer to the desired auxiliary pictures.|
| size_t length | Length of the desired auxiliary pictures.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptionsForPicture_Release()

```
Image_ErrorCode OH_DecodingOptionsForPicture_Release(OH_DecodingOptionsForPicture *options)
```

**Description**

Releases the pointer to an OH_DecodingOptionsForPicture object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | Pointer to an OH_DecodingOptionsForPicture object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

<!--no_check-->