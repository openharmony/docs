# image_source_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## Overview

The file declares the APIs for image decoding.

**File to include**: <multimedia/image_framework/image/image_source_native.h>

**Library**: libimage_source.so

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Related development guidelines:** [Using Image_NativeModule to Decode Images](../../media/image/image-source-c.md), [Image Region Decoding and Downsampling (C/C++)](../../media/image/image-region-and-downsampling-c.md), [Decoding Animated Images Using Image_NativeModule](../../media/image/image-animated-decoding-c.md), [Decoding HDR Images Using Image_NativeModule](../../media/image/image-hdr-decoding-c.md), and [Using Image_NativeModule to Decode Pictures](../../media/image/image-source-picture-c.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) | OH_ImageSourceNative | Describes the image source, which is encapsulated at the native layer and is used to create image data.|
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) | OH_ImageSource_Info | Describes the image source information, which is encapsulated at the native layer. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.|
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) | OH_DecodingOptionsForPicture | Describes the decoding options for pictures. They are obtained by calling [OH_DecodingOptionsForPicture_Create](#oh_decodingoptionsforpicture_create).|
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) | OH_DecodingOptions | Describes the decoding options, which are encapsulated at the native layer. The struct is used to set decoding options and is passed in as an input parameter for creating a PixelMap. For details, see [OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap).|
| [OH_ImageRawData](capi-image-nativemodule-oh-imagerawdata.md) | OH_ImageRawData | Describes the raw data in an image, which is obtained through [OH_ImageSourceNative_CreateImageRawData](capi-image-source-native-h.md#oh_imagesourcenative_createimagerawdata).|

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
| [Image_ErrorCode OH_ImageSourceInfo_GetWidth(OH_ImageSource_Info *info, uint32_t *width)](#oh_imagesourceinfo_getwidth) | Obtains the image width. For an SVG image without the width property, the default value **0** is returned.|
| [Image_ErrorCode OH_ImageSourceInfo_GetHeight(OH_ImageSource_Info *info, uint32_t *height)](#oh_imagesourceinfo_getheight) | Obtains the image height. For an SVG image without the height property, the default value **0** is returned.|
| [Image_ErrorCode OH_ImageSourceInfo_GetDynamicRange(OH_ImageSource_Info *info, bool *isHdr)](#oh_imagesourceinfo_getdynamicrange) | Check whether an image is HDR.|
| [Image_ErrorCode OH_ImageSourceInfo_GetMimeType(OH_ImageSource_Info *info, Image_MimeType *mimetype)](#oh_imagesourceinfo_getmimetype) | Obtains the MIME type of an image.|
| [Image_ErrorCode OH_ImageSourceInfo_Release(OH_ImageSource_Info *info)](#oh_imagesourceinfo_release) | Releases the pointer to an OH_ImageSource_Info object. After this API is called, **mimeType.data** obtained via **OH_ImageSourceInfo_GetMimeType()** becomes invalid. If you need to use the MIME type data after the release, perform a deep copy before the release.|
| [Image_ErrorCode OH_DecodingOptions_Create(OH_DecodingOptions **options)](#oh_decodingoptions_create) | Creates the pointer to an OH_DecodingOptions object.|
| [Image_ErrorCode OH_DecodingOptions_GetPixelFormat(OH_DecodingOptions *options, int32_t *pixelFormat)](#oh_decodingoptions_getpixelformat) | Obtains the pixel format.|
| [Image_ErrorCode OH_DecodingOptions_SetPixelFormat(OH_DecodingOptions *options, int32_t pixelFormat)](#oh_decodingoptions_setpixelformat) | Sets the pixel format.|
| [Image_ErrorCode OH_DecodingOptions_GetIndex(OH_DecodingOptions *options, uint32_t *index)](#oh_decodingoptions_getindex) | Obtains the index of an image.|
| [Image_ErrorCode OH_DecodingOptions_SetIndex(OH_DecodingOptions *options, uint32_t index)](#oh_decodingoptions_setindex) | Sets the index for an image.|
| [Image_ErrorCode OH_DecodingOptions_GetRotate(OH_DecodingOptions *options, float *rotate)](#oh_decodingoptions_getrotate) | Obtains the rotation degree.|
| [Image_ErrorCode OH_DecodingOptions_SetRotate(OH_DecodingOptions *options, float rotate)](#oh_decodingoptions_setrotate) | Sets the rotation angle.|
| [Image_ErrorCode OH_DecodingOptions_GetDesiredSize(OH_DecodingOptions *options, Image_Size *desiredSize)](#oh_decodingoptions_getdesiredsize) | Obtains the desired output dimensions.|
| [Image_ErrorCode OH_DecodingOptions_SetDesiredSize(OH_DecodingOptions *options, Image_Size *desiredSize)](#oh_decodingoptions_setdesiredsize) | Sets the desired output dimensions. The **desiredSize** parameter determines the dimensions of the PixelMap obtained after decoding, where both the width and height must be positive integers. If the aspect ratio is different from the original, the PixelMap will be stretched or scaled to the specified dimensions. The original dimensions are used by default.|
| [Image_ErrorCode OH_DecodingOptions_GetDesiredRegion(OH_DecodingOptions *options, Image_Region *desiredRegion)](#oh_decodingoptions_getdesiredregion) | Obtains the region to decode.<br> Since the corresponding **SetDesiredRegion** function cannot meet the regional decoding requirements, starting from API version 19, you are advised to use [OH_DecodingOptions_GetCropRegion](#oh_decodingoptions_getcropregion) instead.|
| [Image_ErrorCode OH_DecodingOptions_SetDesiredRegion(OH_DecodingOptions *options, Image_Region *desiredRegion)](#oh_decodingoptions_setdesiredregion) | Sets the region to decode.<br> The actual decoding will process the entire original image, without any regional decoding effect. Starting from API version 19, you are advised to use [OH_DecodingOptions_SetCropRegion](#oh_decodingoptions_setcropregion) instead.|
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
| [Image_ErrorCode OH_ImageSourceNative_CreateFromData(uint8_t *data, size_t dataSize, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromdata) | Creates the pointer to an OH_ImageSourceNative object based on buffer data.<br> The passed **data** must be undecoded. Do not pass the pixel buffer data such as RGBA and YUV. If you want to create a PixelMap based on the pixel buffer data, call [OH_PixelmapNative_CreatePixelmap](capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap).|
| [Image_ErrorCode OH_ImageSourceNative_CreateFromDataWithUserBuffer(uint8_t *data, size_t datalength, OH_ImageSourceNative **imageSource)](#oh_imagesourcenative_createfromdatawithuserbuffer) | Creates an image source from data buffer. The data buffer is directly accessed by the image source object, and therefore the data buffer must remain accessible within the lifecycle of the image source object.|
| [Image_ErrorCode OH_ImageSourceNative_CreateFromRawFile(RawFileDescriptor *rawFile, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromrawfile) | Creates the pointer to an OH_ImageSourceNative object by using the raw file descriptor of an image resource file.|
| [Image_ErrorCode OH_ImageSourceNative_CreatePixelmap(OH_ImageSourceNative *source, OH_DecodingOptions *options, OH_PixelmapNative **pixelmap)](#oh_imagesourcenative_createpixelmap) | Creates the pointer to an OH_PixelmapNative object based on decoding options.|
| [Image_ErrorCode OH_ImageSourceNative_CreatePixelmapUsingAllocator(OH_ImageSourceNative *source, OH_DecodingOptions *options, IMAGE_ALLOCATOR_TYPE allocator, OH_PixelmapNative **pixelmap)](#oh_imagesourcenative_createpixelmapusingallocator) | Creates an OH_PixelmapNative object based on decoding options and memory type, where **allocatorType** specifies the memory type of the PixelMap.<br> By default, the system selects an appropriate memory type based on the image type, image size, and platform capability. When processing the returned PixelMap object, consider the impact of stride.|
| [Image_ErrorCode OH_ImageSourceNative_CreatePixelmapList(OH_ImageSourceNative *source, OH_DecodingOptions *options, OH_PixelmapNative *resVecPixMap[], size_t size)](#oh_imagesourcenative_createpixelmaplist) | Creates an array of OH_PixelmapNative objects based on decoding options.<br> This function decodes all frames at once. If the number of frames is high or the size of individual frames is large, it can lead to significant memory usage. In these cases, you are advised to use the **Image** component for displaying animations. The **Image** component decodes frames one by one, which uses less memory than this function.|
| [Image_ErrorCode OH_ImageSourceNative_CreatePicture(OH_ImageSourceNative *source, OH_DecodingOptionsForPicture *options, OH_PictureNative **picture)](#oh_imagesourcenative_createpicture) | Creates the pointer to an OH_PictureNative object based on decoding options.|
| [Image_ErrorCode OH_ImageSourceNative_CreatePictureAtIndex(OH_ImageSourceNative *source, uint32_t index, OH_PictureNative **picture)](#oh_imagesourcenative_createpictureatindex) | Creates the pointer to an OH_PictureNative object at the specified index.|
| [Image_ErrorCode OH_ImageSourceNative_GetDelayTimeList(OH_ImageSourceNative *source, int32_t *delayTimeList, size_t size)](#oh_imagesourcenative_getdelaytimelist) | Obtains the image delay time list.|
| [Image_ErrorCode OH_ImageSourceNative_GetImageInfo(OH_ImageSourceNative *source, int32_t index, OH_ImageSource_Info *info)](#oh_imagesourcenative_getimageinfo) | Obtains the information about an image with a given index.|
| [Image_ErrorCode OH_ImageSourceNative_GetImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)](#oh_imagesourcenative_getimageproperty) | Obtains the value of an image property. **value.data** obtained through this API lacks the string terminator **\0**. Please use it with caution.|
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyShort(OH_ImageSourceNative *source, Image_String *key, uint16_t *value)](#oh_imagesourcenative_getimagepropertyshort) | Obtains an image property value of the short integer type.|
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyLong(OH_ImageSourceNative *source, Image_String *key, uint32_t *value)](#oh_imagesourcenative_getimagepropertylong) | Obtains an image property value of the long integer type.|
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyDouble(OH_ImageSourceNative *source, Image_String *key, double *value)](#oh_imagesourcenative_getimagepropertydouble) | Obtains an image property value of the floating-point type.|
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyArraySize(OH_ImageSourceNative *source, Image_String *key, size_t *size)](#oh_imagesourcenative_getimagepropertyarraysize) | Obtains the length of a property array or a string property.|
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyString(OH_ImageSourceNative *source, Image_String *key, char *value, size_t size)](#oh_imagesourcenative_getimagepropertystring) | Obtains an image property value of the string type.|
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyIntArray(OH_ImageSourceNative *source, Image_String *key, int32_t *value, size_t size)](#oh_imagesourcenative_getimagepropertyintarray) | Obtains an image property value of the integer array type.|
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyDoubleArray(OH_ImageSourceNative *source, Image_String *key, double *value, size_t size)](#oh_imagesourcenative_getimagepropertydoublearray) | Obtains an image property value of the floating-point array type.|
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyBlob(OH_ImageSourceNative *source, Image_String *key, void *value, size_t size)](#oh_imagesourcenative_getimagepropertyblob) | Obtains an image property value of the binary object type.|
| [Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyShort(OH_ImageSourceNative *source, Image_String *key, uint16_t value)](#oh_imagesourcenative_modifyimagepropertyshort) | Changes an image property value of the short integer type.|
| [Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyLong(OH_ImageSourceNative *source, Image_String *key, uint32_t value)](#oh_imagesourcenative_modifyimagepropertylong) | Changes an image property value of the long integer type.|
| [Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyDouble(OH_ImageSourceNative *source, Image_String *key, double value)](#oh_imagesourcenative_modifyimagepropertydouble) | Changes an image property value of the floating-point type.|
| [Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyIntArray(OH_ImageSourceNative *source, Image_String *key, int32_t *value, size_t size)](#oh_imagesourcenative_modifyimagepropertyintarray) | Changes an image property value of the integer array type.|
| [Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyDoubleArray(OH_ImageSourceNative *source, Image_String *key, double *value, size_t size)](#oh_imagesourcenative_modifyimagepropertydoublearray) | Changes an image property value of the floating-point array type.|
| [Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyBlob(OH_ImageSourceNative *source, Image_String *key, void *value, size_t size)](#oh_imagesourcenative_modifyimagepropertyblob) | Changes an image property value of the binary object type.|
| <!--DelRow--> [Image_ErrorCode OH_ImageSourceNative_ReadImageMetadataByType(OH_ImageSourceNative *source, uint32_t index, Image_MetadataType *metadataTypes, size_t typeCount, OH_PictureMetadata **outMetadataArray, size_t *metadataCount)](#oh_imagesourcenative_readimagemetadatabytype) | Reads the metadata of an image source. You can use **metadataType** to specify the metadata. If **metadataTypes** is not specified, all supported metadata is returned.|
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyWithNull(OH_ImageSourceNative *source, Image_String *key, Image_String *value)](#oh_imagesourcenative_getimagepropertywithnull) | Obtains the value of an image property. The output **value.data** ends with the string terminator **\0**.|
| [Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)](#oh_imagesourcenative_modifyimageproperty) | Modifies the value of an image property.|
| [Image_ErrorCode OH_ImageSourceNative_GetFrameCount(OH_ImageSourceNative *source, uint32_t *frameCount)](#oh_imagesourcenative_getframecount) | Obtains the number of image frames.|
| [Image_ErrorCode OH_ImageSourceNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)](#oh_imagesourcenative_getsupportedformats) | Obtains the supported image formats that can be decoded.|
| [Image_ErrorCode OH_ImageSourceNative_Release(OH_ImageSourceNative *source)](#oh_imagesourcenative_release) | Releases the pointer to an OH_ImageSourceNative object.|
| [Image_ErrorCode OH_DecodingOptionsForPicture_Create(OH_DecodingOptionsForPicture **options)](#oh_decodingoptionsforpicture_create) | Creates the pointer to an OH_DecodingOptionsForPicture object.|
| [Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options, Image_AuxiliaryPictureType **desiredAuxiliaryPictures, size_t *length)](#oh_decodingoptionsforpicture_getdesiredauxiliarypictures) | Obtains desired auxiliary pictures in the decoding options (auxiliary pictures contained in **picture** expected to be decoded.)|
| [Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options, Image_AuxiliaryPictureType *desiredAuxiliaryPictures, size_t length)](#oh_decodingoptionsforpicture_setdesiredauxiliarypictures) | Sets desired auxiliary pictures in the decoding options.|
| <!--DelRow--> [Image_ErrorCode OH_DecodingOptionsForPicture_GetNeedsDecodeDfxData(OH_DecodingOptionsForPicture *options, bool *needsDecodeDfxData)](#oh_decodingoptionsforpicture_getneedsdecodedfxdata) | Obtains the **needsDecodeDfxData** parameter in the decoding options.|
| <!--DelRow--> [Image_ErrorCode OH_DecodingOptionsForPicture_SetNeedsDecodeDfxData(OH_DecodingOptionsForPicture *options, bool needsDecodeDfxData)](#oh_decodingoptionsforpicture_setneedsdecodedfxdata) | Sets the **needsDecodeDfxData** parameter in the decoding options.|
| <!--DelRow--> [Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredSizeForMainPixelmap(OH_DecodingOptionsForPicture *options, Image_Size *desiredSizeForMainPixelmap)](#oh_decodingoptionsforpicture_getdesiredsizeformainpixelmap) | Obtains the expected size of the main picture in the **DecodingOptionsForPicture** struct.|
| <!--DelRow--> [Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredSizeForMainPixelmap(OH_DecodingOptionsForPicture *options, Image_Size desiredSizeForMainPixelmap)](#oh_decodingoptionsforpicture_setdesiredsizeformainpixelmap) | Sets the expected size of the main picture in the **DecodingOptionsForPicture** struct.|
| <!--DelRow--> [Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredPixelFormat(OH_DecodingOptionsForPicture *options, PIXEL_FORMAT *desiredPixelFormat)](#oh_decodingoptionsforpicture_getdesiredpixelformat) | Obtains the pixel format in the **DecodingOptionsForPicture** struct.|
| <!--DelRow--> [Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredPixelFormat(OH_DecodingOptionsForPicture *options, PIXEL_FORMAT desiredPixelFormat)](#oh_decodingoptionsforpicture_setdesiredpixelformat) | Sets the pixel format in the **DecodingOptionsForPicture** struct.|
| [Image_ErrorCode OH_DecodingOptionsForPicture_Release(OH_DecodingOptionsForPicture *options)](#oh_decodingoptionsforpicture_release) | Releases the pointer to an OH_DecodingOptionsForPicture object.|
| [Image_ErrorCode OH_ImageSourceNative_CreateImageRawData(const OH_ImageSourceNative *source, OH_ImageRawData **rawData)](#oh_imagesourcenative_createimagerawdata) | Obtains the rawData object from an image.|
| [Image_ErrorCode OH_ImageSourceNative_GetBufferFromRawData(const OH_ImageRawData *rawData, uint8_t **data, size_t *length)](#oh_imagesourcenative_getbufferfromrawdata) | Obtains binary data from a rawData object.|
| [Image_ErrorCode OH_ImageSourceNative_GetBitsPerPixelFromRawData(const OH_ImageRawData *rawData, uint8_t *bitsPerPixel)](#oh_imagesourcenative_getbitsperpixelfromrawdata) | Obtains the number of bits occupied by each pixel in the buffer data.|
| [Image_ErrorCode OH_ImageSourceNative_DestroyImageRawData(OH_ImageRawData *rawData)](#oh_imagesourcenative_destroyimagerawdata) | Destroys a rawData object.|

## Enum Description

### IMAGE_DYNAMIC_RANGE

```c
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

```c
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

```c
enum Image_CropAndScaleStrategy
```

**Description**

Enumerates the cropping and scaling strategies when **desiredSize** and **desiredRegion** are both specified.<br> If **Image_CropAndScaleStrategy** is not specified in [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) and both **desiredRegion** and **desiredSize** are set, the final decoding result may vary slightly due to differences in decoding algorithms used for different image formats.<br> For example, if the original image size is 200x200, and you specify **desiredSize:{width: 150, height: 150}, desiredRegion:{x: 0, y: 0, width: 100, height: 100}**, the expectation is to decode the top-left 1/4 region of the original image and then scale the pixelMap size to 150x150.<br> For JPEG and WebP images (as well as some DNG images that decode a JPEG preview within the file and therefore are treated as JPEG format), the system first performs downsampling. For instance, it might downsample by 7/8 and then crop the region based on a 175x175 image size. As a result, the final cropped region will be slightly larger than the top-left 1/4 of the original image.<br> For SVG images, since they are vector graphics, they can be scaled arbitrarily without loss of clarity. During decoding, the scaling ratio is determined based on the proportion between **desiredSize** and the original image size. Cropping is then performed on the scaled image. As a result, the actual decoded region returned may vary.<br> To ensure consistent results when both **desiredRegion** and **desiredSize** are set, set **Image_CropAndScaleStrategy** to **CROP_FIRST**.

**Since**: 18

| Enum Item| Description|
| -- | -- |
| IMAGE_CROP_AND_SCALE_STRATEGY_SCALE_FIRST = 1 | Scales and then crops the image.|
| IMAGE_CROP_AND_SCALE_STRATEGY_CROP_FIRST = 2 | Crops and then scales the image.|


## Function Description

### OH_ImageSourceInfo_Create()

```c
Image_ErrorCode OH_ImageSourceInfo_Create(OH_ImageSource_Info **info)
```

**Description**

Creates the pointer to an OH_ImageSource_Info object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) **info | Double pointer to an OH_ImageSource_Info object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceInfo_GetWidth()

```c
Image_ErrorCode OH_ImageSourceInfo_GetWidth(OH_ImageSource_Info *info, uint32_t *width)
```

**Description**

Obtains the image width. For an SVG image without the width property, the default value **0** is returned.

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

```c
Image_ErrorCode OH_ImageSourceInfo_GetHeight(OH_ImageSource_Info *info, uint32_t *height)
```

**Description**

Obtains the image height. For an SVG image without the height property, the default value **0** is returned.

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

```c
Image_ErrorCode OH_ImageSourceInfo_GetDynamicRange(OH_ImageSource_Info *info, bool *isHdr)
```

**Description**

Check whether an image is HDR.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | Pointer to an OH_ImageSource_Info object.|
| bool *isHdr | Whether the image is HDR. The value **true** indicates yes, and the value **false** indicates no.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceInfo_GetMimeType()

```c
Image_ErrorCode OH_ImageSourceInfo_GetMimeType(OH_ImageSource_Info *info, Image_MimeType *mimetype)
```

**Description**

Obtains the MIME type of an image.

> **NOTE**
>
> - The member variable **data** of the [mimeType struct](./capi-image-nativemodule-image-string.md#member-variables) is a char pointer that points to the **mimeType** address held within the **info** struct. Release **info** will result in this memory being deallocated.
> - To avoid garbled characters, you can either make a deep copy of **mimeType.data**, or release **info** when **mimeType** is no longer needed.
> - **mimeType.data** does not end with **\0** and must be used together with **mimeType.size**.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | Pointer to an OH_ImageSource_Info object.|
| [Image_MimeType](capi-image-nativemodule-image-string.md) *mimeType | Pointer to the MIME type.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: A parameter is incorrect. The **info** or **mimetype** parameter is a null pointer.|

### OH_ImageSourceInfo_Release()

```c
Image_ErrorCode OH_ImageSourceInfo_Release(OH_ImageSource_Info *info)
```

**Description**

Releases the pointer to an OH_ImageSource_Info object. After this API is called, **mimeType.data** obtained via **OH_ImageSourceInfo_GetMimeType()** becomes invalid. If you need to use the MIME type data after the release, perform a deep copy before the release.

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

```c
Image_ErrorCode OH_DecodingOptions_Create(OH_DecodingOptions **options)
```

**Description**

Creates the pointer to an OH_DecodingOptions object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) **options | Double pointer to an OH_DecodingOptions object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetPixelFormat()

```c
Image_ErrorCode OH_DecodingOptions_GetPixelFormat(OH_DecodingOptions *options, int32_t *pixelFormat)
```

**Description**

Obtains the pixel format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| int32_t *pixelFormat | Pixel format. The default value is **RGBA_8888**. For details about pixel formats, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_SetPixelFormat()

```c
Image_ErrorCode OH_DecodingOptions_SetPixelFormat(OH_DecodingOptions *options,int32_t pixelFormat)
```

**Description**

Sets the pixel format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| int32_t pixelFormat | Pixel format. The default value is **RGBA_8888**. For details about pixel formats, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetIndex()

```c
Image_ErrorCode OH_DecodingOptions_GetIndex(OH_DecodingOptions *options, uint32_t *index)
```

**Description**

Obtains the index of an image.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| uint32_t *index | Pointer to the image index. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_SetIndex()

```c
Image_ErrorCode OH_DecodingOptions_SetIndex(OH_DecodingOptions *options, uint32_t index)
```

**Description**

Sets the index for an image.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| uint32_t index | Image index. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetRotate()

```c
Image_ErrorCode OH_DecodingOptions_GetRotate(OH_DecodingOptions *options, float *rotate)
```

**Description**

Obtains the rotation degree.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| float *rotate | Pointer to the rotation degree, in deg. The default value is **0**. The value range is [0, 360].|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_SetRotate()

```c
Image_ErrorCode OH_DecodingOptions_SetRotate(OH_DecodingOptions *options, float rotate)
```

**Description**

Sets the rotation angle.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| float rotate | Pointer to the rotation degree, in deg. The default value is **0**. The value range is [0, 360].|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetDesiredSize()

```c
Image_ErrorCode OH_DecodingOptions_GetDesiredSize(OH_DecodingOptions *options, Image_Size *desiredSize)
```

**Description**

Obtains the desired output dimensions.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| [Image_Size](capi-image-nativemodule-image-size.md) *desiredSize | Expected output dimensions. The default value is the original image dimensions.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_SetDesiredSize()

```c
Image_ErrorCode OH_DecodingOptions_SetDesiredSize(OH_DecodingOptions *options, Image_Size *desiredSize)
```

**Description**

Sets the desired output dimensions. The **desiredSize** parameter determines the dimensions of the PixelMap obtained after decoding, where both the width and height must be positive integers. If the aspect ratio is different from the original, the PixelMap will be stretched or scaled to the specified dimensions. The original dimensions are used by default.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| [Image_Size](capi-image-nativemodule-image-size.md) *desiredSize | Expected output dimensions. The default value is the original image dimensions.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetDesiredRegion()

```c
Image_ErrorCode OH_DecodingOptions_GetDesiredRegion(OH_DecodingOptions *options, Image_Region *desiredRegion)
```

**Description**

Obtains the region to decode.<br> Since the corresponding **SetDesiredRegion** function cannot meet the regional decoding requirements, starting from API version 19, you are advised to use [OH_DecodingOptions_GetCropRegion](#oh_decodingoptions_getcropregion) instead.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| [Image_Region](capi-image-nativemodule-image-region.md) *desiredRegion | Region to decode. By default, the full image area is used.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_SetDesiredRegion()

```c
Image_ErrorCode OH_DecodingOptions_SetDesiredRegion(OH_DecodingOptions *options, Image_Region *desiredRegion)
```

**Description**

Sets the region to decode.<br> The actual decoding will process the entire original image, without any regional decoding effect. Starting from API version 19, you are advised to use [OH_DecodingOptions_SetCropRegion](#oh_decodingoptions_setcropregion) instead.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| [Image_Region](capi-image-nativemodule-image-region.md) *desiredRegion | Region to decode. By default, the full image area is used.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetDesiredDynamicRange()

```c
Image_ErrorCode OH_DecodingOptions_GetDesiredDynamicRange(OH_DecodingOptions *options, int32_t *desiredDynamicRange)
```

**Description**

Obtains the desired dynamic range configured during decoding.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| int32_t *desiredDynamicRange | Pointer to the expected dynamic range. The default value is **SDR**. For details, see [IMAGE_DYNAMIC_RANGE](#image_dynamic_range).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_SetDesiredDynamicRange()

```c
Image_ErrorCode OH_DecodingOptions_SetDesiredDynamicRange(OH_DecodingOptions *options, int32_t desiredDynamicRange)
```

**Description**

Sets the desired dynamic range during decoding.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to an OH_DecodingOptions object.|
| int32_t desiredDynamicRange | Expected dynamic range. The default value is **SDR**. For details, see [IMAGE_DYNAMIC_RANGE](#image_dynamic_range).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptions_GetDesiredColorSpace()

```c
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

```c
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

```c
Image_ErrorCode OH_DecodingOptions_SetCropAndScaleStrategy(OH_DecodingOptions *options, int32_t cropAndScaleStrategy)
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

```c
Image_ErrorCode OH_DecodingOptions_GetCropAndScaleStrategy(OH_DecodingOptions *options, int32_t *cropAndScaleStrategy)
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

```c
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

```c
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

```c
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

```c
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
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) **res | Double pointer to the OH_ImageSourceNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_BAD_SOURCE**: The decoding data source is abnormal.|

### OH_ImageSourceNative_CreateFromFd()

```c
Image_ErrorCode OH_ImageSourceNative_CreateFromFd(int32_t fd, OH_ImageSourceNative **res)
```

**Description**

Creates the pointer to an OH_ImageSourceNative object based on a file descriptor.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| int32_t fd | File descriptor.|
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) **res | Double pointer to the OH_ImageSourceNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_CreateFromData()

```c
Image_ErrorCode OH_ImageSourceNative_CreateFromData(uint8_t *data, size_t dataSize, OH_ImageSourceNative **res)
```

**Description**

Creates the pointer to an OH_ImageSourceNative object based on buffer data.<br> The passed **data** must be undecoded. Do not pass the pixel buffer data such as RGBA and YUV.<br> If you want to create a PixelMap based on the pixel buffer data, call [OH_PixelmapNative_CreatePixelmap](capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap).

Usage scenario: This API is applicable for scenarios where the application has already obtained complete encoded image data (such as binary data in JPEG, PNG, or WebP formats) through a network, file, or other modules. The API creates an image source object, which can then be used to call [OH_ImageSourceNative_GetImageInfo](#oh_imagesourcenative_getimageinfo) to read image information, or [OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap) to decode the data into a PixelMap.

Resource management: The successfully created OH_ImageSourceNative object is held by the caller and must be released through [OH_ImageSourceNative_Release](#oh_imagesourcenative_release) after use. The input data is managed by the caller and should not be decoded pixel data. 

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| uint8_t *data | Pointer to the buffer data.|
| size_t dataSize | Size of the buffer.|
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) **res | Double pointer to the OH_ImageSourceNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_BAD_SOURCE**: The decoding data source is abnormal.|

### OH_ImageSourceNative_CreateFromDataWithUserBuffer()

```c
Image_ErrorCode OH_ImageSourceNative_CreateFromDataWithUserBuffer(uint8_t *data, size_t datalength, OH_ImageSourceNative **imageSource)
```

**Description**

Creates an image source from data buffer. The data buffer is directly accessed by the image source object, and therefore the data buffer must remain accessible within the lifecycle of the image source object.

Usage scenario: This API is applicable for scenarios where you want to reduce data copying during image source creation and the caller can guarantee the lifecycle of the input buffer.

Resource management: Before calling [OH_ImageSourceNative_Release](#oh_imagesourcenative_release) to release the image source object, the buffer pointed to by **data** must not be freed, reused, or changed to other image data. Otherwise, subsequent operations such as reading image information, decoding, or reading metadata may result in accessing invalid data.

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

```c
Image_ErrorCode OH_ImageSourceNative_CreateFromRawFile(RawFileDescriptor *rawFile, OH_ImageSourceNative **res)
```

**Description**

Creates the pointer to an OH_ImageSourceNative object by using the raw file descriptor of an image resource file.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [RawFileDescriptor](../apis-localization-kit/capi-rawfile-rawfiledescriptor.md) *rawFile | Pointer to the file descriptor of the raw file.|
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) **res | Double pointer to the OH_ImageSourceNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_CreatePixelmap()

```c
Image_ErrorCode OH_ImageSourceNative_CreatePixelmap(OH_ImageSourceNative *source, OH_DecodingOptions *options, OH_PixelmapNative **pixelmap)
```

**Description**

Creates the pointer to an OH_PixelmapNative object based on decoding options.

Usage scenario: This API is applicable for decoding encoded images such as JPEG, PNG, WebP, and single-frame GIF into PixelMaps that can be read, processed, or re-encoded. Before decoding, you can use OH_DecodingOptions to set parameters such as frame index, target pixel format, target size, crop region, and desired dynamic range.

Restrictions: **source**, **options**, and **pixelmap** cannot be null pointers. Before calling this API, you need to create an OH_ImageSourceNative object. If you need to customize decoding options, create and set an OH_DecodingOptions object first. After the API is successfully called, **pixelmap** points to the newly created OH_PixelmapNative object. If the API fails to be executed, the object pointed to by **pixelmap** should not be used.

Resource management: The successfully created OH_PixelmapNative object is held by the caller and must be released through [OH_PixelmapNative_Destroy](capi-pixelmap-native-h.md#oh_pixelmapnative_destroy) after use. The OH_DecodingOptions and OH_ImageSourceNative objects are not automatically released when the PixelMap is created. They must be released by calling [OH_DecodingOptions_Release](#oh_decodingoptions_release) and [OH_ImageSourceNative_Release](#oh_imagesourcenative_release), respectively.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to an OH_ImageSourceNative object.|
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to the decoding options.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the OH_PixelmapNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_CreatePixelmapUsingAllocator()

```c
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapUsingAllocator(OH_ImageSourceNative *source, OH_DecodingOptions *options, IMAGE_ALLOCATOR_TYPE allocator, OH_PixelmapNative **pixelmap)
```

**Description**

Creates an OH_PixelmapNative object based on decoding options and memory type, where **allocatorType** specifies the memory type of the PixelMap.<br> By default, the system selects an appropriate memory type based on the image type, image size, and platform capability. When processing the returned PixelMap object, consider the impact of stride.

Usage scenario: This API is applicable for scenarios where the caller needs to explicitly specify the memory type of the PixelMap. For example, when the subsequent image processing pipeline requires DMA memory, IMAGE_ALLOCATOR_TYPE_DMA can be specified.

Restrictions: **source**, **options**, and **pixelmap** cannot be null pointers. The value of **allocator** must be a valid enumeration value defined in [IMAGE_ALLOCATOR_TYPE](#image_allocator_type). The specified memory type may be restricted by the image type, image size, system version, and device capability. The API may return **IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE**. If sandbox isolation is enabled for the calling process and **IMAGE_ALLOCATOR_TYPE_DMA** is specified or DMA memory is selected by **IMAGE_ALLOCATOR_TYPE_AUTO**, you need to configure the SELinux permission for the sandbox process to access DMA memory-related resources. Otherwise, the API call may be blocked or fail due to SELinux policy interception.

Resource management: The successfully created PixelMap must be released by calling [OH_PixelmapNative_Destroy](capi-pixelmap-native-h.md#oh_pixelmapnative_destroy). When reading or writing pixel data, you cannot assume that the number of bytes per row equals the width multiplied by the number of bytes per pixel. Instead, you should use [OH_PixelmapImageInfo_GetRowStride](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getrowstride) to obtain the row stride.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to an OH_ImageSourceNative object.|
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to the decoding options.|
| [IMAGE_ALLOCATOR_TYPE](#image_allocator_type) allocator | Memory type used by the returned PixelMap.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the OH_PixelmapNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_BAD_SOURCE**: The data source is abnormal.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: The MIME type is not supported.<br>         **IMAGE_SOURCE_TOO_LARGE**: The image is too large.<br>         **IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE**: The allocator type is not supported. For example, decoding HDR images using shared memory is not supported because only DMA supports HDR metadata.<br>         **IMAGE_SOURCE_UNSUPPORTED_OPTIONS**: The options are not supported. For example, an image cannot be converted into the required pixel format.<br>         **IMAGE_DECODE_FAILED**: Decoding fails.<br>         **IMAGE_SOURCE_ALLOC_FAILED**: The memory allocation fails.|

### OH_ImageSourceNative_CreatePixelmapList()

```c
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapList(OH_ImageSourceNative *source, OH_DecodingOptions *options, OH_PixelmapNative *resVecPixMap[], size_t size)
```

**Description**

Creates an array of OH_PixelmapNative objects based on decoding options.<br> This function decodes all frames at once. If the number of frames is high or the size of individual frames is large, it can lead to significant memory usage. In these cases, you are advised to use the **Image** component for displaying animations. The **Image** component decodes frames one by one, which uses less memory than this function.

Usage scenario: This API is applicable for scenarios where you need to obtain all frames of an animated image in one go and process them yourself, such as generating a thumbnail sequence, analyzing each frame, or re-encoding the animated image. If you only need to play an animated image, using this API is not recommended.

Restrictions: **source**, **options**, and **resVecPixMap** cannot be null pointers. The caller needs to prepare a **resVecPixMap** array with sufficient length based on the number of frames. The size of the array must be the same as the number of elements that can be written to the array. Before calling this API, you can call [OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount) to query the number of frames.

Resource management: The **resVecPixMap** array is provided by the caller. Once successfully created, each OH_PixelmapNative object in the array is held by the caller. After use, you need to call [OH_PixelmapNative_Destroy](capi-pixelmap-native-h.md#oh_pixelmapnative_destroy) to release the objects one by one. On API failure, check the array for any non-null PixelMap pointers already written and release them as well.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to an OH_ImageSourceNative object.|
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | Pointer to the decoding options.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *resVecPixMap[] | Pointer to an array of OH_PixelmapNative objects created at the C++ local layer.|
| size_t size | Size of the array. You can use [OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount) to obtain the size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported.|

### OH_ImageSourceNative_CreatePicture()

```c
Image_ErrorCode OH_ImageSourceNative_CreatePicture(OH_ImageSourceNative *source, OH_DecodingOptionsForPicture *options, OH_PictureNative **picture)
```

**Description**

Creates the pointer to an OH_PictureNative object based on decoding options.

Restrictions: **source**, **options**, and **picture** cannot be null pointers.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to an OH_ImageSourceNative object.|
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | Pointer to the decoding options.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **picture | Double pointer to the OH_PictureNative object created at the C++ local layer.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_DECODE_FAILED**: Decoding fails.|

### OH_ImageSourceNative_CreatePictureAtIndex()

```c
Image_ErrorCode OH_ImageSourceNative_CreatePictureAtIndex(OH_ImageSourceNative *source, uint32_t index, OH_PictureNative **picture)
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

```c
Image_ErrorCode OH_ImageSourceNative_GetDelayTimeList(OH_ImageSourceNative *source, int32_t *delayTimeList, size_t size)
```

**Description**

Obtains the image delay time list.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to an OH_ImageSourceNative object.|
| int32_t *delayTimeList | Pointer to the delay time list obtained. It cannot be a null pointer.|
| size_t size | Size of the delay time list. You can use [OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount) to obtain the size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_GetImageInfo()

```c
Image_ErrorCode OH_ImageSourceNative_GetImageInfo(OH_ImageSourceNative *source, int32_t index, OH_ImageSource_Info *info)
```

**Description**

Obtains the information about an image with a given index.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to an OH_ImageSourceNative object.|
| int32_t index | Index of an image. For a GIF image, the value range is [0, N-1], where N indicates the number of GIF frames. For an image with only one frame, you can pass in **0**.|
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | Pointer to the image information obtained, which is an OH_ImageSource_Info struct.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_GetImageProperty()

```c
Image_ErrorCode OH_ImageSourceNative_GetImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)
```

**Description**

Obtains the value of an image property.<br> **value.data** obtained through this API lacks the string terminator **\0**. Please use it with caution.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to an OH_ImageSourceNative object. OH_ImageSourceNative must be actively released after use. For details, see [OH_ImageSourceNative_Release](#oh_imagesourcenative_release).|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property. For details about the value range, see **OHOS_IMAGE_PROPERTY_*XXX*** series constants defined in [Variables](capi-image-common-h.md#variables) of **image_common.h**.|
| [Image_String](capi-image-nativemodule-image-string.md) *value | Pointer to the obtained value (output parameter). Before calling this API, set **value->data** to a null pointer and **value->size** to **0**. The API will automatically allocate the required memory for **value->data** and assign a value to **value->size**. After finishing using this memory, release the memory pointed to by **value->data** using the **free()** function provided by the C standard library. Otherwise, a memory leak will occur.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_GetImagePropertyShort()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyShort(OH_ImageSourceNative *source, Image_String *key, uint16_t *value)
```

**Description**

Obtains an image property value of the short integer type.

> **NOTE**
>
> When reading a DNG image, this API applies special handling to some keys. Refer to the **OHOS_IMAGE_PROPERTY_XXX** series constants defined in [Variables](capi-image-common-h.md#variables) for the string values of the following fields:
> - **NewSubfileType**, **ImageWidth**, **ImageLength**, **DefaultCropSize**, **Orientation**, **Compression**, **PhotometricInterpretation**, **PlanarConfiguration**, **RowsPerStrip**, **StripOffsets**, **StripByteCounts**, **SamplesPerPixel**, **BitsPerSample**, **YCbCrCoefficients**, **YCbCrSubSampling**, **YCbCrPositioning**, **ReferenceBlackWhite**, **XResolution**, **YResolution**, and **ResolutionUnit**: For these properties, values related to the main image are returned.
> - **ImageUniqueID**: The value is verified based on the specifications. If the value fails to comply with the specifications, an empty string is returned.
> - **ExifVersion**, **FlashpixVersion**, and **ColorSpace**: If the image does not contain these properties, an error code is returned.
> - **DNGVersion**: If the value is earlier than **1.0.0.0**, **1.0.0.0** is returned.
> - **GPSVersionID**: If there is no valid GPS data, the GPS version number is cleared and **0** is returned.
> - **GPSAltitudeRef**: If **GPSAltitude** is not set, this property is set to **0xFFFFFFFF**.
> - **ISOSpeedRatings**: If its value is **0** or **65535**, the recommended exposure index is used first. If the recommended exposure index does not exist, the standard output sensitivity, ISO speed, and exposure index are used in sequence.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property is to be queried.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property to be queried.|
| uint16_t *value | Pointer to the obtained property value. This is the output parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the short integer type.|

### OH_ImageSourceNative_GetImagePropertyLong()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyLong(OH_ImageSourceNative *source, Image_String *key, uint32_t *value)
```

**Description**

Obtains an image property value of the long integer type.

> **NOTE**
>
> When reading a DNG image, this API applies special handling to some keys. Refer to the **OHOS_IMAGE_PROPERTY_XXX** series constants defined in [Variables](capi-image-common-h.md#variables) for the string values of the following fields:
> - **NewSubfileType**, **ImageWidth**, **ImageLength**, **DefaultCropSize**, **Orientation**, **Compression**, **PhotometricInterpretation**, **PlanarConfiguration**, **RowsPerStrip**, **StripOffsets**, **StripByteCounts**, **SamplesPerPixel**, **BitsPerSample**, **YCbCrCoefficients**, **YCbCrSubSampling**, **YCbCrPositioning**, **ReferenceBlackWhite**, **XResolution**, **YResolution**, and **ResolutionUnit**: For these properties, values related to the main image are returned.
> - **ImageUniqueID**: The value is verified based on the specifications. If the value fails to comply with the specifications, an empty string is returned.
> - **ExifVersion**, **FlashpixVersion**, and **ColorSpace**: If the image does not contain these properties, an error code is returned.
> - **DNGVersion**: If the value is earlier than **1.0.0.0**, **1.0.0.0** is returned.
> - **GPSVersionID**: If there is no valid GPS data, the GPS version number is cleared and **0** is returned.
> - **GPSAltitudeRef**: If **GPSAltitude** is not set, this property is set to **0xFFFFFFFF**.
> - **ISOSpeedRatings**: If its value is **0** or **65535**, the recommended exposure index is used first. If the recommended exposure index does not exist, the standard output sensitivity, ISO speed, and exposure index are used in sequence.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property is to be queried.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property to be queried.|
| uint32_t *value | Pointer to the obtained property value. This is the output parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the long integer type.|

### OH_ImageSourceNative_GetImagePropertyDouble()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyDouble(OH_ImageSourceNative *source, Image_String *key, double *value)
```

**Description**

Obtains an image property value of the floating-point type.

> **NOTE**
>
> When reading a DNG image, this API applies special handling to some keys. Refer to the **OHOS_IMAGE_PROPERTY_XXX** series constants defined in [Variables](capi-image-common-h.md#variables) for the string values of the following fields:
> - **NewSubfileType**, **ImageWidth**, **ImageLength**, **DefaultCropSize**, **Orientation**, **Compression**, **PhotometricInterpretation**, **PlanarConfiguration**, **RowsPerStrip**, **StripOffsets**, **StripByteCounts**, **SamplesPerPixel**, **BitsPerSample**, **YCbCrCoefficients**, **YCbCrSubSampling**, **YCbCrPositioning**, **ReferenceBlackWhite**, **XResolution**, **YResolution**, and **ResolutionUnit**: For these properties, values related to the main image are returned.
> - **ImageUniqueID**: The value is verified based on the specifications. If the value fails to comply with the specifications, an empty string is returned.
> - **ExifVersion**, **FlashpixVersion**, and **ColorSpace**: If the image does not contain these properties, an error code is returned.
> - **DNGVersion**: If the value is earlier than **1.0.0.0**, **1.0.0.0** is returned.
> - **GPSVersionID**: If there is no valid GPS data, the GPS version number is cleared and **0** is returned.
> - **GPSAltitudeRef**: If **GPSAltitude** is not set, this property is set to **0xFFFFFFFF**.
> - **ISOSpeedRatings**: If its value is **0** or **65535**, the recommended exposure index is used first. If the recommended exposure index does not exist, the standard output sensitivity, ISO speed, and exposure index are used in sequence.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property is to be queried.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property to be queried.|
| double *value | Pointer to the obtained property value. This is the output parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the floating-point type.|

### OH_ImageSourceNative_GetImagePropertyArraySize()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyArraySize(OH_ImageSourceNative *source, Image_String *key, size_t *size)
```

**Description**

Obtains the length of a property array or a string property.

Usage scenario: This API is applicable to query the required buffer size before reading image properties of the string, array, or binary object type. Typical process: Call this API to obtain the length, allocate the buffer (by the caller), and then call [OH_ImageSourceNative_GetImagePropertyString](#oh_imagesourcenative_getimagepropertystring), [OH_ImageSourceNative_GetImagePropertyIntArray](#oh_imagesourcenative_getimagepropertyintarray), [OH_ImageSourceNative_GetImagePropertyDoubleArray](#oh_imagesourcenative_getimagepropertydoublearray), or [OH_ImageSourceNative_GetImagePropertyBlob](#oh_imagesourcenative_getimagepropertyblob) to read the actual content.

Resource management: This API does not allocate the buffer for property values. For subsequent property value reading, if the buffer is allocated by the caller, the caller is responsible for freeing it. If OH_ImageSourceNative_GetImageProperty](#oh_imagesourcenative_getimageproperty) or [OH_ImageSourceNative_GetImagePropertyWithNull](#oh_imagesourcenative_getimagepropertywithnull) is used and **value->data** is allocated by the system, you must call **free()** to release the buffer after use.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property is to be queried.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property to be queried.|
| size_t *size | Pointer to the length of the property array or string property. This is the output parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the array or string type.|

### OH_ImageSourceNative_GetImagePropertyString()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyString(OH_ImageSourceNative *source, Image_String *key, char *value, size_t size)
```

**Description**

Obtains an image property value of the string type.

> **NOTE**
>
> When reading a DNG image, this API applies special handling to some keys. Refer to the **OHOS_IMAGE_PROPERTY_XXX** series constants defined in [Variables](capi-image-common-h.md#variables) for the string values of the following fields:
> - **NewSubfileType**, **ImageWidth**, **ImageLength**, **DefaultCropSize**, **Orientation**, **Compression**, **PhotometricInterpretation**, **PlanarConfiguration**, **RowsPerStrip**, **StripOffsets**, **StripByteCounts**, **SamplesPerPixel**, **BitsPerSample**, **YCbCrCoefficients**, **YCbCrSubSampling**, **YCbCrPositioning**, **ReferenceBlackWhite**, **XResolution**, **YResolution**, and **ResolutionUnit**: For these properties, values related to the main image are returned.
> - **ImageUniqueID**: The value is verified based on the specifications. If the value fails to comply with the specifications, an empty string is returned.
> - **ExifVersion**, **FlashpixVersion**, and **ColorSpace**: If the image does not contain these properties, an error code is returned.
> - **DNGVersion**: If the value is earlier than **1.0.0.0**, **1.0.0.0** is returned.
> - **GPSVersionID**: If there is no valid GPS data, the GPS version number is cleared and **0** is returned.
> - **GPSAltitudeRef**: If **GPSAltitude** is not set, this property is set to **0xFFFFFFFF**.
> - **ISOSpeedRatings**: If its value is **0** or **65535**, the recommended exposure index is used first. If the recommended exposure index does not exist, the standard output sensitivity, ISO speed, and exposure index are used in sequence.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property is to be queried.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property to be queried.|
| char *value | Pointer to the obtained property value. This is the output parameter. The caller is responsible for memory management and deallocation.|
| size_t size | String length.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the string type.|

### OH_ImageSourceNative_GetImagePropertyIntArray()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyIntArray(OH_ImageSourceNative *source, Image_String *key, int32_t *value, size_t size)
```

**Description**

Obtains an image property value of the integer array type.

> **NOTE**
>
> When reading a DNG image, this API applies special handling to some keys. Refer to the **OHOS_IMAGE_PROPERTY_XXX** series constants defined in [Variables](capi-image-common-h.md#variables) for the string values of the following fields:
> - **NewSubfileType**, **ImageWidth**, **ImageLength**, **DefaultCropSize**, **Orientation**, **Compression**, **PhotometricInterpretation**, **PlanarConfiguration**, **RowsPerStrip**, **StripOffsets**, **StripByteCounts**, **SamplesPerPixel**, **BitsPerSample**, **YCbCrCoefficients**, **YCbCrSubSampling**, **YCbCrPositioning**, **ReferenceBlackWhite**, **XResolution**, **YResolution**, and **ResolutionUnit**: For these properties, values related to the main image are returned.
> - **ImageUniqueID**: The value is verified based on the specifications. If the value fails to comply with the specifications, an empty string is returned.
> - **ExifVersion**, **FlashpixVersion**, and **ColorSpace**: If the image does not contain these properties, an error code is returned.
> - **DNGVersion**: If the value is earlier than **1.0.0.0**, **1.0.0.0** is returned.
> - **GPSVersionID**: If there is no valid GPS data, the GPS version number is cleared and **0** is returned.
> - **GPSAltitudeRef**: If **GPSAltitude** is not set, this property is set to **0xFFFFFFFF**.
> - **ISOSpeedRatings**: If its value is **0** or **65535**, the recommended exposure index is used first. If the recommended exposure index does not exist, the standard output sensitivity, ISO speed, and exposure index are used in sequence.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property is to be queried.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property to be queried.|
| int32_t *value | Pointer to the obtained property value. This is the output parameter. The caller is responsible for memory management and deallocation.|
| size_t size | String length.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the integer array type.|

### OH_ImageSourceNative_GetImagePropertyDoubleArray()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyDoubleArray(OH_ImageSourceNative *source, Image_String *key, double *value, size_t size)
```

**Description**

Obtains an image property value of the floating-point array type.

> **NOTE**
>
> When reading a DNG image, this API applies special handling to some keys. Refer to the **OHOS_IMAGE_PROPERTY_XXX** series constants defined in [Variables](capi-image-common-h.md#variables) for the string values of the following fields:
> - **NewSubfileType**, **ImageWidth**, **ImageLength**, **DefaultCropSize**, **Orientation**, **Compression**, **PhotometricInterpretation**, **PlanarConfiguration**, **RowsPerStrip**, **StripOffsets**, **StripByteCounts**, **SamplesPerPixel**, **BitsPerSample**, **YCbCrCoefficients**, **YCbCrSubSampling**, **YCbCrPositioning**, **ReferenceBlackWhite**, **XResolution**, **YResolution**, and **ResolutionUnit**: For these properties, values related to the main image are returned.
> - **ImageUniqueID**: The value is verified based on the specifications. If the value fails to comply with the specifications, an empty string is returned.
> - **ExifVersion**, **FlashpixVersion**, and **ColorSpace**: If the image does not contain these properties, an error code is returned.
> - **DNGVersion**: If the value is earlier than **1.0.0.0**, **1.0.0.0** is returned.
> - **GPSVersionID**: If there is no valid GPS data, the GPS version number is cleared and **0** is returned.
> - **GPSAltitudeRef**: If **GPSAltitude** is not set, this property is set to **0xFFFFFFFF**.
> - **ISOSpeedRatings**: If its value is **0** or **65535**, the recommended exposure index is used first. If the recommended exposure index does not exist, the standard output sensitivity, ISO speed, and exposure index are used in sequence.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property is to be queried.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property to be queried.|
| double *value | Pointer to the obtained property value. This is the output parameter. The caller is responsible for memory management and deallocation.|
| size_t size | Size of the array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the floating-point array type.|

### OH_ImageSourceNative_GetImagePropertyBlob()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyBlob(OH_ImageSourceNative *source, Image_String *key, void *value, size_t size)
```

**Description**

Obtains an image property value of the binary object type.

> **NOTE**
>
> When reading a DNG image, this API applies special handling to some keys. Refer to the **OHOS_IMAGE_PROPERTY_XXX** series constants defined in [Variables](capi-image-common-h.md#variables) for the string values of the following fields:
> - **NewSubfileType**, **ImageWidth**, **ImageLength**, **DefaultCropSize**, **Orientation**, **Compression**, **PhotometricInterpretation**, **PlanarConfiguration**, **RowsPerStrip**, **StripOffsets**, **StripByteCounts**, **SamplesPerPixel**, **BitsPerSample**, **YCbCrCoefficients**, **YCbCrSubSampling**, **YCbCrPositioning**, **ReferenceBlackWhite**, **XResolution**, **YResolution**, and **ResolutionUnit**: For these properties, values related to the main image are returned.
> - **ImageUniqueID**: The value is verified based on the specifications. If the value fails to comply with the specifications, an empty string is returned.
> - **ExifVersion**, **FlashpixVersion**, and **ColorSpace**: If the image does not contain these properties, an error code is returned.
> - **DNGVersion**: If the value is earlier than **1.0.0.0**, **1.0.0.0** is returned.
> - **GPSVersionID**: If there is no valid GPS data, the GPS version number is cleared and **0** is returned.
> - **GPSAltitudeRef**: If **GPSAltitude** is not set, this property is set to **0xFFFFFFFF**.
> - **ISOSpeedRatings**: If its value is **0** or **65535**, the recommended exposure index is used first. If the recommended exposure index does not exist, the standard output sensitivity, ISO speed, and exposure index are used in sequence.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property is to be queried.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property to be queried.|
| void *value | Pointer to the obtained property value. This is the output parameter. The caller is responsible for memory management and deallocation.|
| size_t size | Size of the array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the binary object type.|

### OH_ImageSourceNative_ModifyImagePropertyShort()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyShort(OH_ImageSourceNative *source, Image_String *key, uint16_t value)
```

**Description**

Changes an image property value of the short integer type.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property value is to be changed.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property whose value is to be changed.|
| uint16_t value | Property value.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the short integer type.|

### OH_ImageSourceNative_ModifyImagePropertyLong()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyLong(OH_ImageSourceNative *source, Image_String *key, uint32_t value)
```

**Description**

Changes an image property value of the long integer type.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property value is to be changed.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property whose value is to be changed.|
| uint32_t value | Property value.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the long integer type.|

### OH_ImageSourceNative_ModifyImagePropertyDouble()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyDouble(OH_ImageSourceNative *source, Image_String *key, double value)
```

**Description**

Changes an image property value of the floating-point type.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property value is to be changed.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property whose value is to be changed.|
| double value | Property value.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the floating-point type.|

### OH_ImageSourceNative_ModifyImagePropertyIntArray()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyIntArray(OH_ImageSourceNative *source, Image_String *key, int32_t *value, size_t size)
```

**Description**

Changes an image property value of the integer array type.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property value is to be changed.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property whose value is to be changed.|
| int32_t *value | Pointer to the property value.|
| size_t size | Size of the array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the integer array type.|

### OH_ImageSourceNative_ModifyImagePropertyDoubleArray()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyDoubleArray(OH_ImageSourceNative *source, Image_String *key, double *value, size_t size)
```

**Description**

Changes an image property value of the floating-point array type.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property value is to be changed.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property whose value is to be changed.|
| double *value | Pointer to the property value.|
| size_t size | Size of the array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the floating-point array type.|

### OH_ImageSourceNative_ModifyImagePropertyBlob()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyBlob(OH_ImageSourceNative *source, Image_String *key, void *value, size_t size)
```

**Description**

Changes an image property value of the binary object type.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to ImageSource whose property value is to be changed.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property whose value is to be changed.|
| void *value | Pointer to the property value.|
| size_t size | Size of the array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **key**, or **value** is **nullptr**.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: Image properties for the current MIME type are not supported for querying.<br>         **IMAGE_SOURCE_UNSUPPORTED_METADATA**: The specified metadata does not exist or is not of the binary object type.|
<!--Del-->
### OH_ImageSourceNative_ReadImageMetadataByType()

```c
Image_ErrorCode OH_ImageSourceNative_ReadImageMetadataByType(OH_ImageSourceNative *source, uint32_t index, Image_MetadataType *metadataTypes, size_t typeCount, OH_PictureMetadata **outMetadataArray, size_t *metadataCount)
```

**Description**

Reads the metadata of an image source. You can use **metadataTypes** to specify the metadata types to read. If **metadataTypes** is not specified, all supported metadata is returned.

**Since:** 26.0.0

**System API**: This is a system API.

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to the image source.|
| uint32_t index | Image index.|
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) *metadataTypes | Metadata types.|
| size_t typeCount | Number of the metadata types.|
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) **outMetadataArray | Output parameter, which is used to receive the metadata array allocated by this function. After use, the caller needs to release the object.|
| size_t *metadataCount | Number of **OH_PictureMetadata** elements returned in the output metadata array.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**202**: This API is called by a non-system application.</li><br>         <li>**IMAGE_SOURCE_INVALID_PARAMETER**: **source**, **outMetadataArray**, or **metadataCount** is a null pointer.</li><br>         <li>**IMAGE_SOURCE_UNSUPPORTED_METADATA**: The metadata does not exist or the metadata type is not supported.</li><br>         <li>**IMAGE_SOURCE_ALLOC_FAILED**: The memory allocation fails.</li><br>         </ul> |
<!--DelEnd-->
### OH_ImageSourceNative_GetImagePropertyWithNull()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyWithNull(OH_ImageSourceNative *source, Image_String *key, Image_String *value)
```

**Description**

Obtains the value of an image property. The output **value.data** ends with the string terminator **\0**.

Usage scenario: This API is applicable for reading image properties in string format, such as the image orientation, capture time, and device information. Different from [OH_ImageSourceNative_GetImageProperty](#oh_imagesourcenative_getimageproperty), this API returns **value.data** that ends with **\0**, making it more suitable for direct handling as a C string.

Restrictions: **source**, **key**, and **value** cannot be null pointers. Before calling this API, set **value.data** to **NULL** and **value.size** to **0**. After the API is executed successfully, the property value can be read through **value.data** and **value.size**. If the API fails to be executed, **value.data** should not be read.

Resource management: After the API is successfully called, **value.data** is allocated by the system. The caller must call **free()** to release the memory after using it.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source |  Pointer to an OH_ImageSourceNative object. OH_ImageSourceNative must be actively released after use. For details, see [OH_ImageSourceNative_Release](#oh_imagesourcenative_release).|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property key. For details about the value range, see **OHOS_IMAGE_PROPERTY_*XXX*** series constants defined in [Variables](capi-image-common-h.md#variables) of **image_common.h**.|
| [Image_String](capi-image-nativemodule-image-string.md) *value | Pointer to the value obtained. Before calling this API, set **value->data** to a null pointer and **value->size** to **0**. The API will automatically allocate the required memory for **value->data** and assign a value to **value->size**. After finishing using this memory, release the memory pointed to by **value->data** using the **free()** function provided by the C standard library. Otherwise, a memory leak may occur.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: The **source**, **key**, or **value** parameter is a null pointer.|

### OH_ImageSourceNative_ModifyImageProperty()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)
```

**Description**

Modifies the value of an image property.

Usage scenario: This API is applicable for modifying image properties in an ImageSource, such as orientation, user comment, and other string properties. For properties of the short, long, double, array, or binary object type, you are advised to use the corresponding ModifyImagePropertyShort, ModifyImagePropertyLong, ModifyImagePropertyDouble, ModifyImagePropertyIntArray, ModifyImagePropertyDoubleArray, or ModifyImagePropertyBlob API to avoid type mismatches.

Resource management: The memory pointed to by **key** and **value** is managed by the caller. The API does not take over their lifecycle. Modified properties are stored in the current ImageSource object. To generate an image file or image data containing the modified properties, you need to use the encoding API to re-output the image.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to an OH_ImageSourceNative object. OH_ImageSourceNative must be actively released after use. For details, see [OH_ImageSourceNative_Release](#oh_imagesourcenative_release).|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the property key. For details about the value range, see **OHOS_IMAGE_PROPERTY_*XXX*** series constants defined in [Variables](capi-image-common-h.md#variables) of **image_common.h**.|
| [Image_String](capi-image-nativemodule-image-string.md) *value | Pointer to the new value.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_GetFrameCount()

```c
Image_ErrorCode OH_ImageSourceNative_GetFrameCount(OH_ImageSourceNative *source, uint32_t *frameCount)
```

**Description**

Obtains the number of image frames.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to an OH_ImageSourceNative object.|
| uint32_t *frameCount | Pointer to the number of frames obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ImageSourceNative_GetSupportedFormats()

```c
Image_ErrorCode OH_ImageSourceNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)
```

**Description**

Obtains the supported image formats that can be decoded.

Usage scenario: This API is suitable for dynamically querying the decoding formats supported by the current system before creating an image source or displaying format options. The decoding capability for some formats may depend on the system version and device capabilities. You are advised to rely on the result returned by this API as the authoritative source.

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

```c
Image_ErrorCode OH_ImageSourceNative_Release(OH_ImageSourceNative *source)
```

**Description**

Releases the pointer to an OH_ImageSourceNative object.

Resource management: Objects successfully created by **OH_ImageSourceNative_CreateFromUri**, **OH_ImageSourceNative_CreateFromFd**, **OH_ImageSourceNative_CreateFromData**, **OH_ImageSourceNative_CreateFromDataWithUserBuffer**, or **OH_ImageSourceNative_CreateFromRawFile** must be released using this API when they are no longer needed. After release, they must not be passed to any API for reading image information, decoding, or reading or modifying properties. Releasing an ImageSource does not automatically release any OH_PixelmapNative, OH_PictureNative, or OH_ImageRawData objects. These objects must be released by calling their respective release APIs.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to an OH_ImageSourceNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptionsForPicture_Create()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_Create(OH_DecodingOptionsForPicture **options)
```

**Description**

Creates the pointer to an OH_DecodingOptionsForPicture object.

Restrictions: **options** cannot be a null pointer. If the API returns a failure, the output parameter content cannot be used in the subsequent process.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) **options | Double pointer to an OH_DecodingOptionsForPicture object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options, Image_AuxiliaryPictureType **desiredAuxiliaryPictures, size_t *length)
```

**Description**

Obtains desired auxiliary pictures in the decoding options (auxiliary pictures contained in **picture** expected to be decoded.)

Restrictions: **options**, **desiredAuxiliaryPictures**, and **length** cannot be null pointers. If no desired auxiliary picture is set, the API returns **IMAGE_BAD_PARAMETER**.

Resource management: The **desiredAuxiliaryPictures** array returned by the API is allocated by the API. After the array is used, the caller needs to **use delete[]** to release it.

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

```c
Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options, Image_AuxiliaryPictureType *desiredAuxiliaryPictures, size_t length)
```

**Description**

Sets desired auxiliary pictures in the decoding options.

Restrictions: **options** and **desiredAuxiliaryPictures** cannot be null pointers. The value of **length** must be greater than 0. The auxiliary picture type in the **desiredAuxiliaryPictures** array must be the currently supported **Image_AuxiliaryPictureType**.

Resource management: The API saves the auxiliary picture type in the input array to the **OH_DecodingOptionsForPicture** object and does not hold the input array pointer. After the API returns, the caller can release or reuse the array. When this API is called multiple times, the newly input auxiliary picture types are added to the existing set. Only one copy of each type is retained.

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
<!--Del-->
### OH_DecodingOptionsForPicture_GetNeedsDecodeDfxData()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_GetNeedsDecodeDfxData(OH_DecodingOptionsForPicture *options, bool *needsDecodeDfxData)
```

**Description**

Obtains the **needsDecodeDfxData** parameter in the decoding options.

**Since:** 26.0.0

**System API**: This is a system API.

**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | Pointer to the **OH_DecodingOptionsForPicture** struct.|
| bool *needsDecodeDfxData | Whether the image DFX data needs to be decoded. The value **true** indicates yes, and the value **false** indicates no.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**202**: This API is called by a non-system application.</li><br>         <li>**IMAGE_SOURCE_INVALID_PARAMETER**: **options** or **needsDecodeDfxData** is a null pointer.</li><br>         </ul> |

### OH_DecodingOptionsForPicture_SetNeedsDecodeDfxData()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_SetNeedsDecodeDfxData(OH_DecodingOptionsForPicture *options, bool needsDecodeDfxData)
```

**Description**

Sets the **needsDecodeDfxData** parameter in the decoding options.

**Since:** 26.0.0

**System API**: This is a system API.

**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | Pointer to the **OH_DecodingOptionsForPicture** struct.|
| bool needsDecodeDfxData | Whether the image DFX data needs to be decoded. The value **true** indicates yes, and the value **false** indicates no.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**202**: This API is called by a non-system application.</li><br>         <li>**IMAGE_SOURCE_INVALID_PARAMETER**: **options** is a null pointer.</li><br>         </ul> |

### OH_DecodingOptionsForPicture_GetDesiredSizeForMainPixelmap()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredSizeForMainPixelmap(OH_DecodingOptionsForPicture *options, Image_Size *desiredSizeForMainPixelmap)
```

**Description**

Obtains the expected size of the main picture in the **DecodingOptionsForPicture** struct.

**Since:** 26.0.0

**System API**: This is a system API.

**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | Pointer to the **OH_DecodingOptionsForPicture** struct.|
| [Image_Size](capi-image-nativemodule-image-size.md) *desiredSizeForMainPixelmap | Expected size of the main picture.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**202**: This API is called by a non-system application.</li><br>         <li>**IMAGE_SOURCE_INVALID_PARAMETER**: **options** is a null pointer.</li><br>         </ul> |

### OH_DecodingOptionsForPicture_SetDesiredSizeForMainPixelmap()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredSizeForMainPixelmap(OH_DecodingOptionsForPicture *options, Image_Size desiredSizeForMainPixelmap)
```

**Description**

Sets the expected size of the main picture in the **DecodingOptionsForPicture** struct.

**Since:** 26.0.0

**System API**: This is a system API.

**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | Pointer to the **OH_DecodingOptionsForPicture** struct.|
| [Image_Size](capi-image-nativemodule-image-size.md) desiredSizeForMainPixelmap | Expected size of the main picture.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**202**: This API is called by a non-system application.</li><br>         <li>**IMAGE_SOURCE_INVALID_PARAMETER**: **options** is a null pointer.</li><br>         </ul> |

### OH_DecodingOptionsForPicture_GetDesiredPixelFormat()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredPixelFormat(OH_DecodingOptionsForPicture *options, PIXEL_FORMAT *desiredPixelFormat)
```

**Description**

Obtains the pixel format in the **DecodingOptionsForPicture** struct.

**Since:** 26.0.0

**System API**: This is a system API.

**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | Pointer to the **OH_DecodingOptionsForPicture** struct.|
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) *desiredPixelFormat | Pixel format in the decoding options.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**202**: This API is called by a non-system application.</li><br>         <li>**IMAGE_SOURCE_INVALID_PARAMETER**: **options** is a null pointer.</li><br>         </ul> |

### OH_DecodingOptionsForPicture_SetDesiredPixelFormat()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredPixelFormat(OH_DecodingOptionsForPicture *options, PIXEL_FORMAT desiredPixelFormat)
```

**Description**

Sets the pixel format in the **DecodingOptionsForPicture** struct.

**Since:** 26.0.0

**System API**: This is a system API.

**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | Pointer to the **OH_DecodingOptionsForPicture** struct.|
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) desiredPixelFormat | Pixel format in the decoding options.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**202**: This API is called by a non-system application.</li><br>         <li>**IMAGE_SOURCE_INVALID_PARAMETER**: **options** is a null pointer.</li><br>         </ul> |
<!--DelEnd-->
### OH_DecodingOptionsForPicture_Release()

```c
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

### OH_ImageSourceNative_CreateImageRawData()

```c
Image_ErrorCode OH_ImageSourceNative_CreateImageRawData(const OH_ImageSourceNative *source, OH_ImageRawData **rawData)
```

**Description**

Obtains the rawData object from an image. The rawData object usually occupies a large amount of memory because it contains raw data from the camera.<br>        When the rawData object is no longer needed, call the [OH_ImageSourceNative_DestroyImageRawData](capi-image-source-native-h.md#oh_imagesourcenative_destroyimagerawdata) method to destroy it in a timely manner to deallocate memory resources.

Usage scenario: This API is applicable for reading raw data from an image source containing raw image data and passing it to custom image processing, algorithm analysis, or saving pipelines. For common image display or general pixel processing scenarios, you should use [OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap) to decode the image into a PixelMap.

Resource management: The successfully created OH_ImageRawData object is held by the caller and must be destroyed using [OH_ImageSourceNative_DestroyImageRawData](#oh_imagesourcenative_destroyimagerawdata) after use. The lifecycle of the rawData object and the OH_ImageSourceNative object are independent of each other. Releasing ImageSource does not automatically destroy rawData.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [const OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | Pointer to the image source.|
| [OH_ImageRawData](capi-image-nativemodule-oh-imagerawdata.md) **rawData | Double pointer to the rawData object obtained after decoding.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_SOURCE**: The source is incorrect.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: The rawData object is invalid.<br>         **IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE**: The MIME type is not supported.|

### OH_ImageSourceNative_GetBufferFromRawData()

```c
Image_ErrorCode OH_ImageSourceNative_GetBufferFromRawData(const OH_ImageRawData *rawData, uint8_t **data, size_t *length)
```

**Description**

Obtains binary data from a rawData object.

Resource management: **data** returns the address of the internal binary buffer of the rawData object. The caller must not call **free()** on ***data**, nor continue to access this address after the rawData object has been destroyed by [OH_ImageSourceNative_DestroyImageRawData](#oh_imagesourcenative_destroyimagerawdata). If you need to use the data after rawData is destroyed, you must perform a deep copy before destroying it.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [const OH_ImageRawData](capi-image-nativemodule-oh-imagerawdata.md) *rawData | Pointer to the rawData object.|
| uint8_t **data | Pointer to the binary buffer data.|
| size_t *length | Pointer to the length of the obtained data.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: The rawData object is invalid.|

### OH_ImageSourceNative_GetBitsPerPixelFromRawData()

```c
Image_ErrorCode OH_ImageSourceNative_GetBitsPerPixelFromRawData(const OH_ImageRawData *rawData, uint8_t *bitsPerPixel)
```

**Description**

Obtains the number of bits occupied by each pixel in the buffer data.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [const OH_ImageRawData](capi-image-nativemodule-oh-imagerawdata.md) *rawData | Pointer to the rawData object.|
| uint8_t *bitsPerPixel | Pointer to the number of bits per pixel.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: The rawData object is invalid.|

### OH_ImageSourceNative_DestroyImageRawData()

```c
Image_ErrorCode OH_ImageSourceNative_DestroyImageRawData(OH_ImageRawData *rawData)
```

**Description**

Destroys a rawData object.

Resource management: This API only destroys the OH_ImageRawData object and its internal resources, but does not release the OH_ImageSourceNative object. After the destruction, the data address obtained through [OH_ImageSourceNative_GetBufferFromRawData](#oh_imagesourcenative_getbufferfromrawdata) becomes invalid immediately.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageRawData](capi-image-nativemodule-oh-imagerawdata.md) *rawData | Pointer to the rawData object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_SOURCE_INVALID_PARAMETER**: The rawData object is invalid.|
<!--no_check-->