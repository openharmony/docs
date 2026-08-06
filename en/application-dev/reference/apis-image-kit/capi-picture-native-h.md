# picture_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## Overview

The file declares the APIs for obtaining picture data and information.

**File to include**: <multimedia/image_framework/image/picture_native.h>

**Library**: libpicture.so

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 13

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_PictureNative_AuxiliaryPictureCopyItem](capi-image-nativemodule-oh-picturenative-auxiliarypicturecopyitem.md) | OH_PictureNative_AuxiliaryPictureCopyItem | Specifies the copy rules for auxiliary pictures when creating a deep copy of a PictureNative object. It describes how to copy an auxiliary picture from one type to another.|
| [OH_PictureNative_MetadataCopyItem](capi-image-nativemodule-oh-picturenative-metadatacopyitem.md) | OH_PictureNative_MetadataCopyItem | Specifies the copy rules for metadata when creating a deep copy of a PictureNative object. It describes how to copy metadata from one type to another.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) | - | Describes the picture, which is used to perform operations related to the picture.<br> Picture is an object that includes a main picture, auxiliary picture, and metadata.<br> The main picture contains most information about the image and is mainly used to render the image.<br> The auxiliary picture is used to store data related to but different from the main picture, revealing more comprehensive details.<br> The metadata is generally used to store information about the image file.|
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) | - | Describes the auxiliary picture, which is used to perform operations related to the auxiliary picture.|
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) | - | Describes the auxiliary picture information, which is used to perform operations related to the auxiliary picture information.|
| [OH_ComposeOptions](capi-image-nativemodule-oh-composeoptions.md) | OH_ComposeOptions | HDR composition option struct encapsulated at the native layer. It is used to specify parameters used for HDR composition, such as the target pixel format.|
| <!--DelRow-->[OH_DecomposeOptions](#oh_decomposeoptions) | OH_DecomposeOptions | Struct in the native layer that encapsulates HDR decomposition option parameters. It is used to specify the parameters for HDR decomposition, including the gain map size and the target pixel format.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) | Image_AuxiliaryPictureType | Type of the auxiliary picture.|

### Functions

| Name| Description|
| -- | -- |
| [Image_ErrorCode OH_ComposeOptions_Create(OH_ComposeOptions **options)](#oh_composeoptions_create) | Creates an **OH_ComposeOptions** instance.|
| [Image_ErrorCode OH_ComposeOptions_SetDesiredPixelFormat(OH_ComposeOptions *options, PIXEL_FORMAT desiredPixelFormat)](#oh_composeoptions_setdesiredpixelformat) | Sets the pixel format in **OH_ComposeOptions**.|
| [Image_ErrorCode OH_ComposeOptions_GetDesiredPixelFormat(OH_ComposeOptions *options, PIXEL_FORMAT *desiredPixelFormat)](#oh_composeoptions_getdesiredpixelformat) | Obtains the pixel format in **OH_ComposeOptions**.|
| [Image_ErrorCode OH_ComposeOptions_Release(OH_ComposeOptions *options)](#oh_composeoptions_release) | Releases the pointer to **OH_ComposeOptions**.|
| [Image_ErrorCode OH_PictureNative_CreatePicture(OH_PixelmapNative *mainPixelmap, OH_PictureNative **picture)](#oh_picturenative_createpicture) | Creates the pointer to an OH_PictureNative object.|
| [Image_ErrorCode OH_PictureNative_GetMainPixelmap(OH_PictureNative *picture, OH_PixelmapNative **mainPixelmap)](#oh_picturenative_getmainpixelmap) | Obtains the pointer to the OH_PixelmapNative object of a main picture.|
| [Image_ErrorCode OH_PictureNative_GetHdrComposedPixelmap(OH_PictureNative *picture, OH_PixelmapNative **hdrPixelmap)](#oh_picturenative_gethdrcomposedpixelmap) | Obtains the pointer to the OH_PixelmapNative object of an HDR picture.|
| [Image_ErrorCode OH_PictureNative_GetHdrComposedPixelmapWithOptions(OH_PictureNative *picture, OH_ComposeOptions *options, OH_PixelmapNative **hdrPixelmap)](#oh_picturenative_gethdrcomposedpixelmapwithoptions) | Obtains the pointer to **OH_PixelmapNative** of an HDR picture based on **OH_ComposeOptions**.|
| [Image_ErrorCode OH_PictureNative_GetGainmapPixelmap(OH_PictureNative *picture, OH_PixelmapNative **gainmapPixelmap)](#oh_picturenative_getgainmappixelmap) | Obtains the pointer to the OH_PixelmapNative object of a gain map.|
| [Image_ErrorCode OH_PictureNative_SetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative *auxiliaryPicture)](#oh_picturenative_setauxiliarypicture) | Sets an auxiliary picture.|
| [Image_ErrorCode OH_PictureNative_GetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative **auxiliaryPicture)](#oh_picturenative_getauxiliarypicture) | Obtains an auxiliary picture by type.|
| [Image_ErrorCode OH_PictureNative_GetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType, OH_PictureMetadata **metadata)](#oh_picturenative_getmetadata) | Obtains the metadata of a main picture.|
| [Image_ErrorCode OH_PictureNative_SetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType, OH_PictureMetadata *metadata)](#oh_picturenative_setmetadata) | Sets the metadata for a main picture.|
| [Image_ErrorCode OH_PictureNative_GetAuxiliaryPictureCount(OH_PictureNative *picture, uint32_t *count)](#oh_picturenative_getauxiliarypicturecount) | Obtains the number of auxiliary pictures.|
| [Image_ErrorCode OH_PictureNative_GetAuxiliaryPictureTypes(OH_PictureNative *picture, Image_AuxiliaryPictureType *auxiliaryPictureTypes, uint32_t *count)](#oh_picturenative_getauxiliarypicturetypes) | Obtains the type of an auxiliary picture.|
| [Image_ErrorCode OH_PictureNative_GetMetadataCount(OH_PictureNative *picture, uint32_t *count)](#oh_picturenative_getmetadatacount) | Obtains the number of metadata items in a Picture object.|
| [Image_ErrorCode OH_PictureNative_GetMetadataTypes(OH_PictureNative *picture, Image_MetadataType *metadataTypes, uint32_t *count)](#oh_picturenative_getmetadatatypes) | Obtains the metadata type in a Picture object.|
| [Image_ErrorCode OH_PictureNative_RemoveAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type)](#oh_picturenative_removeauxiliarypicture) | Removes an auxiliary image from a Picture object.|
| [Image_ErrorCode OH_PictureNative_RemoveMetadata(OH_PictureNative *picture, Image_MetadataType type)](#oh_picturenative_removemetadata) | Removes metadata from a Picture object.|
| [Image_ErrorCode OH_PictureNative_DeepCopyWithItems(OH_PictureNative *source, const OH_PictureNative_AuxiliaryPictureCopyItem *auxiliaryPictureCopyItems, uint32_t auxiliaryPictureCopyCount, const OH_PictureNative_MetadataCopyItem *metadataCopyItems, uint32_t metadataCopyCount, Image_AuxiliaryPictureType *sourceAuxPictureAsMainPixelMap, OH_PictureNative **picture)](#oh_picturenative_deepcopywithitems) | Creates a deep copy of a PictureNative object and copies the specified auxiliary picture and metadata to the specified target type.|
| [Image_ErrorCode OH_PictureNative_Release(OH_PictureNative *picture)](#oh_picturenative_release) | Releases the pointer to an OH_PictureNative object.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_Create(uint8_t *data, size_t dataLength, Image_Size *size, Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative **auxiliaryPicture)](#oh_auxiliarypicturenative_create) | Creates the pointer to an OH_AuxiliaryPictureNative object. This API supports only continuous pixel data whose [PIXEL_FORMAT](./capi-pixelmap-native-h.md#pixel_format) is BGRA_8888 and creates an auxiliary picture in RGBA_8888 format.|
| <!--DelRow--> [Image_ErrorCode OH_AuxiliaryPictureNative_CreateUsingAllocator(uint8_t *data, uint32_t dataLength, OH_AuxiliaryPictureInfo *info, IMAGE_ALLOCATOR_MODE allocator, OH_AuxiliaryPictureNative **auxiliaryPicture)](#oh_auxiliarypicturenative_createusingallocator) | Creates an OH_AuxiliaryPictureNative object with a specified memory type. <ul><li>The system selects the memory type based on factors such as image type, image size, and platform capabilities by default. </li><li>When processing the auxiliary picture returned by this API, the impact of stride must be taken into account. </li><li>If **data** is NULL or **dataLength** is less than or equal to 0, the auxiliary picture data will not be initialized.</li></ul> |
| [Image_ErrorCode OH_AuxiliaryPictureNative_WritePixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *source, size_t bufferSize)](#oh_auxiliarypicturenative_writepixels) | Reads pixels in the buffer and writes the result to an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_ReadPixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *destination, size_t *bufferSize)](#oh_auxiliarypicturenative_readpixels) | Reads pixels of an auxiliary picture and writes the result to the buffer.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_GetType(OH_AuxiliaryPictureNative *auxiliaryPicture, Image_AuxiliaryPictureType *type)](#oh_auxiliarypicturenative_gettype) | Obtains the type of an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_GetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture, OH_AuxiliaryPictureInfo **info)](#oh_auxiliarypicturenative_getinfo) | Obtains the information of an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_SetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture, OH_AuxiliaryPictureInfo *info)](#oh_auxiliarypicturenative_setinfo) | Sets the information for an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_GetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture, Image_MetadataType metadataType, OH_PictureMetadata **metadata)](#oh_auxiliarypicturenative_getmetadata) | Obtains the metadata of an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_SetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture, Image_MetadataType metadataType, OH_PictureMetadata *metadata)](#oh_auxiliarypicturenative_setmetadata) | Sets the metadata for an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_AcquirePixelmap(OH_AuxiliaryPictureNative *auxiliaryPicture, OH_PixelmapNative **pixelmap)](#oh_auxiliarypicturenative_acquirepixelmap) | Obtains the OH_PixelmapNative object of an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_Release(OH_AuxiliaryPictureNative *picture)](#oh_auxiliarypicturenative_release) | Releases the pointer to an OH_AuxiliaryPictureNative object.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_Create(OH_AuxiliaryPictureInfo **info)](#oh_auxiliarypictureinfo_create) | Creates an OH_AuxiliaryPictureInfo object.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_GetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType *type)](#oh_auxiliarypictureinfo_gettype) | Obtains the auxiliary picture type in **OH_AuxiliaryPictureInfo**.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_SetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType type)](#oh_auxiliarypictureinfo_settype) | Sets the auxiliary picture type in **OH_AuxiliaryPictureInfo**.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_GetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)](#oh_auxiliarypictureinfo_getsize) | Obtains the image size in **OH_AuxiliaryPictureInfo**.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_SetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)](#oh_auxiliarypictureinfo_setsize) | Sets the image size in **OH_AuxiliaryPictureInfo**.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_GetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t *rowStride)](#oh_auxiliarypictureinfo_getrowstride) | Obtains the row stride in **OH_AuxiliaryPictureInfo**.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_SetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t rowStride)](#oh_auxiliarypictureinfo_setrowstride) | Sets the row stride in **OH_AuxiliaryPictureInfo**.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_GetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT *pixelFormat)](#oh_auxiliarypictureinfo_getpixelformat) | Obtains the pixel format in **OH_AuxiliaryPictureInfo**.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_SetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT pixelFormat)](#oh_auxiliarypictureinfo_setpixelformat) | Sets the pixel format in **OH_AuxiliaryPictureInfo**.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_Release(OH_AuxiliaryPictureInfo *info)](#oh_auxiliarypictureinfo_release) | Releases the pointer to an OH_AuxiliaryPictureInfo object.|
| <!--DelRow-->[Image_ErrorCode OH_DecomposeOptions_Create(OH_DecomposeOptions **outOwnedOptions)](#oh_decomposeoptions_create) | Creates an OH_DecomposeOptions instance.|
| <!--DelRow-->[Image_ErrorCode OH_DecomposeOptions_SetIsFullSizeGainmap(OH_DecomposeOptions *options, bool isFullSizeGainmap)](#oh_decomposeoptions_setisfullsizegainmap) | Sets whether to generate a full-size gain map (the size of the gain map is the same as that of the main picture). If this parameter is not set, the default value **false** is used. That is, the size of the gain map is half of that of the main picture.|
| <!--DelRow-->[Image_ErrorCode OH_DecomposeOptions_SetDesiredPixelFormat(OH_DecomposeOptions *options, int32_t desiredPixelFormat)](#oh_decomposeoptions_setdesiredpixelformat) | Sets the pixel format of the SDR PixelMap after HDR decomposition.|
| <!--DelRow-->[Image_ErrorCode OH_DecomposeOptions_GetDesiredPixelFormat(OH_DecomposeOptions *options, int32_t *desiredPixelFormat)](#oh_decomposeoptions_getdesiredpixelformat) | Obtains the pixel format of the SDR PixelMap after HDR decomposition.|
| <!--DelRow-->[Image_ErrorCode OH_DecomposeOptions_Release(OH_DecomposeOptions *options)](#oh_decomposeoptions_release) | Releases the pointer to **OH_DecomposeOptions**.|
| <!--DelRow-->[Image_ErrorCode OH_PictureNative_DecomposeToPicture(OH_PixelmapNative *hdrPixelmap, OH_DecomposeOptions *options, OH_PictureNative **outOwnedPicture)](#oh_picturenative_decomposetopicture) | Decomposes an HDR PixelMap into a Picture object that contains an SDR PixelMap and a gain map.|

## Enum Description

### Image_AuxiliaryPictureType

```c
enum Image_AuxiliaryPictureType
```

**Description**

Type of the auxiliary picture.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| AUXILIARY_PICTURE_TYPE_GAINMAP = 1 | Gain map, a mechanism for transforming an SDR image into an HDR image capable of adjustable display adjustment. It is a set of combinations describing how to apply gain map metadata.|
| AUXILIARY_PICTURE_TYPE_DEPTH_MAP = 2 | Depth map, which stores the depth data of an image. It captures the distance between each pixel and the camera to provide 3D scene structure. It is usually used for 3D modeling and scene comprehension.|
| AUXILIARY_PICTURE_TYPE_UNREFOCUS_MAP = 3 | Defocused portrait original image, which provides a method to emphasize background blur in portrait photographing. It helps users select a focus region in post-processing, allowing for greater creative control.|
| AUXILIARY_PICTURE_TYPE_LINEAR_MAP = 4 | Linear map, which is used to provide additional viewpoints or supplementary information. It is usually used to enhance visual effects and can contain linear representations of lighting, colors, or other visual elements in a scene.|
| AUXILIARY_PICTURE_TYPE_FRAGMENT_MAP = 5 | Fragment map, which indicates regions obscured by watermarks in the original image. It is used to remove or correct the watermark interference, thereby enhancing the image completeness and visibility.|

## Function Description

### OH_ComposeOptions_Create()

```c
Image_ErrorCode OH_ComposeOptions_Create(OH_ComposeOptions **options)
```

**Description**

Creates an **OH_ComposeOptions** instance.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ComposeOptions](capi-image-nativemodule-oh-composeoptions.md) **options | Pointer to **OH_ComposeOptions**.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ComposeOptions_SetDesiredPixelFormat()

```c
Image_ErrorCode OH_ComposeOptions_SetDesiredPixelFormat(OH_ComposeOptions *options, PIXEL_FORMAT desiredPixelFormat)
```

**Description**

Sets the pixel format in **OH_ComposeOptions**.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ComposeOptions](capi-image-nativemodule-oh-composeoptions.md) *options | Pointer to **OH_ComposeOptions**.|
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) desiredPixelFormat | Pixel format. The RGBA_1010102, YCBCR_P010, and YCRCB_P010 formats are supported.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: The parameter is incorrect. For example, **options** is nullptr or the passed **desiredPixelFormat** is not supported.|

### OH_ComposeOptions_GetDesiredPixelFormat()

```c
Image_ErrorCode OH_ComposeOptions_GetDesiredPixelFormat(OH_ComposeOptions *options, PIXEL_FORMAT *desiredPixelFormat)
```

**Description**

Obtains the pixel format in **OH_ComposeOptions**.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ComposeOptions](capi-image-nativemodule-oh-composeoptions.md) *options | Pointer to **OH_ComposeOptions**.|
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) *desiredPixelFormat | Pixel format in the composition options.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_ComposeOptions_Release()

```c
Image_ErrorCode OH_ComposeOptions_Release(OH_ComposeOptions *options)
```

**Description**

Releases the pointer to **OH_ComposeOptions**.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ComposeOptions](capi-image-nativemodule-oh-composeoptions.md) *options | Pointer to **OH_ComposeOptions**.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureNative_CreatePicture()

```c
Image_ErrorCode OH_PictureNative_CreatePicture(OH_PixelmapNative *mainPixelmap, OH_PictureNative **picture)
```

**Description**

Creates the pointer to an OH_PictureNative object.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *mainPixelmap | Pointer to the OH_PixelmapNative object of the main picture.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **picture | Double pointer to the OH_PictureNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureNative_GetMainPixelmap()

```c
Image_ErrorCode OH_PictureNative_GetMainPixelmap(OH_PictureNative *picture, OH_PixelmapNative **mainPixelmap)
```

**Description**

Obtains the pointer to the OH_PixelmapNative object of a main picture.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **mainPixelmap | Double pointer to the OH_PixelmapNative object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureNative_GetHdrComposedPixelmap()

```c
Image_ErrorCode OH_PictureNative_GetHdrComposedPixelmap(OH_PictureNative *picture, OH_PixelmapNative **hdrPixelmap)
```

**Description**

Obtains the pointer to the OH_PixelmapNative object of an HDR picture.

Restrictions: **picture** and **hdrPixelmap** cannot be null pointers. If the picture does not support HDR synthesis, the API returns **IMAGE_UNSUPPORTED_OPERATION**.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **hdrPixelmap | Double pointer to the OH_PixelmapNative object of the HDR picture.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported. For example, the Picture object does not contain a gain map.|

### OH_PictureNative_GetHdrComposedPixelmapWithOptions()

```c
Image_ErrorCode OH_PictureNative_GetHdrComposedPixelmapWithOptions(OH_PictureNative *picture, OH_ComposeOptions *options, OH_PixelmapNative **hdrPixelmap)
```

**Description**

Obtains the pointer to **OH_PixelmapNative** of an HDR picture based on **OH_ComposeOptions**.

Restrictions: **picture**, **options**, and **hdrPixelmap** cannot be null pointers. If the picture does not support HDR synthesis, the API returns **IMAGE_UNSUPPORTED_OPERATION**.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [OH_ComposeOptions](capi-image-nativemodule-oh-composeoptions.md) *options | Pointer to **OH_ComposeOptions**.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **hdrPixelmap | Pointer to **OH_PixelmapNative** of the obtained HDR picture.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported. For example, the Picture object does not contain a gain map.|

### OH_PictureNative_GetGainmapPixelmap()

```c
Image_ErrorCode OH_PictureNative_GetGainmapPixelmap(OH_PictureNative *picture, OH_PixelmapNative **gainmapPixelmap)
```

**Description**

Obtains the pointer to the OH_PixelmapNative object of a gain map.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **gainmapPixelmap | Double pointer to the OH_PixelmapNative object of the gain map.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureNative_SetAuxiliaryPicture()

```c
Image_ErrorCode OH_PictureNative_SetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative *auxiliaryPicture)
```

**Description**

Sets an auxiliary picture.

Restrictions: Neither **picture** nor **auxiliaryPicture** can be a null pointer. The value of **type** must be one of the supported auxiliary picture types and must be consistent with the auxiliary picture type of the auxiliaryPicture object.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) type | Type of the auxiliary picture.|
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to an OH_AuxiliaryPictureNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureNative_GetAuxiliaryPicture()

```c
Image_ErrorCode OH_PictureNative_GetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative **auxiliaryPicture)
```

**Description**

Obtains an auxiliary picture by type.

Restrictions: Neither **picture** nor **auxiliaryPicture** can be a null pointer. The value of **type** must be one of the supported auxiliary picture types.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) type | Type of the auxiliary picture.|
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) **auxiliaryPicture | Double pointer to the OH_AuxiliaryPictureNative object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureNative_GetMetadata()

```c
Image_ErrorCode OH_PictureNative_GetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType, OH_PictureMetadata **metadata)
```

**Description**

Obtains the metadata of a main picture.

Restrictions: **picture** and **metadata** cannot be null pointers. **metadataType** must be a metadata type supported by the picture. For an unsupported metadata type, **IMAGE_UNSUPPORTED_METADATA** is returned.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) metadataType | Metadata type.|
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) **metadata | Double pointer to the metadata.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_METADATA**: unsupported metadata type.|

### OH_PictureNative_SetMetadata()

```c
Image_ErrorCode OH_PictureNative_SetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType, OH_PictureMetadata *metadata)
```

**Description**

Sets the metadata for a main picture.

Restrictions: Neither **picture** nor **metadata** can be a null pointer. **metadataType** must be a metadata type supported by the picture.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) metadataType | Metadata type.|
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) *metadata | Pointer to the metadata.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_METADATA**: unsupported metadata type.|

### OH_PictureNative_GetAuxiliaryPictureCount()

```c
Image_ErrorCode OH_PictureNative_GetAuxiliaryPictureCount(OH_PictureNative *picture, uint32_t *count)
```

**Description**

Obtains the number of auxiliary pictures.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to the OH_PictureNative object.|
| uint32_t *count | Number of auxiliary pictures.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**IMAGE_INVALID_PARAMETER**: **picture** or **count** is a null pointer, or picture obtaining fails.</li><br>         </ul> |

### OH_PictureNative_GetAuxiliaryPictureTypes()

```c
Image_ErrorCode OH_PictureNative_GetAuxiliaryPictureTypes(OH_PictureNative *picture, Image_AuxiliaryPictureType *auxiliaryPictureTypes, uint32_t *count)
```

**Description**

Obtains the type of an auxiliary picture.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to the OH_PictureNative object.|
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) *auxiliaryPictureTypes | Pointer to the array that receives the auxiliary image types.|
| uint32_t *count | For input, it is the size of the auxiliary image type array. For output, it is the actual number of auxiliary images.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**IMAGE_INVALID_PARAMETER**: **picture**, **auxiliaryPictureTypes**, or **count** is a null pointer, the image cannot be obtained, or **count** is less than the required value.</li><br>         </ul> |

### OH_PictureNative_GetMetadataCount()

```c
Image_ErrorCode OH_PictureNative_GetMetadataCount(OH_PictureNative *picture, uint32_t *count)
```

**Description**

Obtains the number of metadata items in a Picture object.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to the OH_PictureNative object.|
| uint32_t *count | Number of metadata items.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**IMAGE_INVALID_PARAMETER**: **picture** or **count** is a null pointer, or picture obtaining fails.</li><br>         </ul> |

### OH_PictureNative_GetMetadataTypes()

```c
Image_ErrorCode OH_PictureNative_GetMetadataTypes(OH_PictureNative *picture, Image_MetadataType *metadataTypes, uint32_t *count)
```

**Description**

Obtains the metadata type in a Picture object.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to the OH_PictureNative object.|
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) *metadataTypes | Pointer to the array that receives the metadata types.|
| uint32_t *count | For input, it is the size of the **metadataTypes** array. For output, it is the actual number of metadata items.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**IMAGE_INVALID_PARAMETER**: **picture**, **metadataTypes**, or **count** is a non pointer, the picture fails to be obtained, or **count** is less than the required value.</li><br>         </ul> |

### OH_PictureNative_RemoveAuxiliaryPicture()

```c
Image_ErrorCode OH_PictureNative_RemoveAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type)
```

**Description**

Removes an auxiliary image from a Picture object.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to the OH_PictureNative object.|
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) type | Type of the auxiliary picture to remove.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The auxiliary picture is successfully removed or does not exist.</li><br>         <li>**IMAGE_INVALID_PARAMETER**: The **picture** pointer is null, the picture failed to be obtained, or the auxiliary picture type is not supported.</li><br>         </ul> |

### OH_PictureNative_RemoveMetadata()

```c
Image_ErrorCode OH_PictureNative_RemoveMetadata(OH_PictureNative *picture, Image_MetadataType type)
```

**Description**

Removes metadata from a Picture object.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to the OH_PictureNative object.|
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) type | Metadata type to remove.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The metadata is successfully removed or does not exist.</li><br>         <li>**IMAGE_INVALID_PARAMETER**: **picture** is a null pointer, or picture obtaining fails.</li><br>         <li>**IMAGE_UNSUPPORTED_METADATA**: Unsupported metadata type.</li><br>         </ul> |

### OH_PictureNative_DeepCopyWithItems()

```c
Image_ErrorCode OH_PictureNative_DeepCopyWithItems(OH_PictureNative *source, const OH_PictureNative_AuxiliaryPictureCopyItem *auxiliaryPictureCopyItems, uint32_t auxiliaryPictureCopyCount, const OH_PictureNative_MetadataCopyItem *metadataCopyItems, uint32_t metadataCopyCount, Image_AuxiliaryPictureType *sourceAuxPictureAsMainPixelMap, OH_PictureNative **picture)
```

**Description**

Creates a deep copy of a PictureNative object and copies the specified auxiliary picture and metadata to the specified target type.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *source | Pointer to the source PictureNative object, which cannot be NULL.|
| [const OH_PictureNative_AuxiliaryPictureCopyItem](capi-image-nativemodule-oh-picturenative-auxiliarypicturecopyitem.md) *auxiliaryPictureCopyItems | Auxiliary picture struct to be copied. The source and target auxiliary picture types are supported. If the value of **auxiliaryPictureCopyCount** is 0, this parameter can be NULL.|
| uint32_t auxiliaryPictureCopyCount | Number of auxiliary pictures to be copied.|
| [const OH_PictureNative_MetadataCopyItem](capi-image-nativemodule-oh-picturenative-metadatacopyitem.md) *metadataCopyItems | Metadata struct to be copied. The source and target metadata types are supported. If the value of **metadataCopyCount** is 0, this parameter can be NULL.|
| uint32_t metadataCopyCount | Number of metadata items to be copied.|
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) *sourceAuxPictureAsMainPixelMap | Specifies the auxiliary image type in the source picture that will be used as the main picture of the copied picture. If the original main picture should be used, this parameter can be NULL.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **picture | Output parameter, which is used to receive the newly created PictureNative object. When the caller no longer needs the object, release it.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li> **IMAGE_INVALID_PARAMETER**: The **source** or **picture** pointer is null, the picture fails to be obtained or the number of pictures does not match, or the number of pictures is not zero but the corresponding array is a null pointer.</li><br>         <li>**IMAGE_ALLOC_FAILED**: The memory allocation fails.</li><br>         </ul> |

### OH_PictureNative_Release()

```c
Image_ErrorCode OH_PictureNative_Release(OH_PictureNative *picture)
```

**Description**

Releases the pointer to an OH_PictureNative object.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureNative_Create()

```c
Image_ErrorCode OH_AuxiliaryPictureNative_Create(uint8_t *data, size_t dataLength, Image_Size *size, Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative **auxiliaryPicture)
```

**Description**

Creates the pointer to an OH_AuxiliaryPictureNative object. This API supports only continuous pixel data whose [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) is BGRA_8888 and creates an auxiliary picture in RGBA_8888 format.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| uint8_t *data | Pointer to the image data.|
| size_t dataLength | Length of the image data.|
| [Image_Size](capi-image-nativemodule-image-size.md) *size | Pointer to the size of the auxiliary picture.|
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) type | Type of the auxiliary picture.|
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) **auxiliaryPicture | Double pointer to the OH_AuxiliaryPictureNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|
<!--Del-->
### OH_AuxiliaryPictureNative_CreateUsingAllocator()

```c
Image_ErrorCode OH_AuxiliaryPictureNative_CreateUsingAllocator(uint8_t *data, uint32_t dataLength, OH_AuxiliaryPictureInfo *info, IMAGE_ALLOCATOR_MODE allocator, OH_AuxiliaryPictureNative **auxiliaryPicture)
```

**Description**

Creates an OH_AuxiliaryPictureNative object with a specified memory type. <ul><li>The system selects the memory type based on factors such as image type, image size, and platform capabilities by default. </li><li>When processing the auxiliary picture returned by this API, the impact of stride must be taken into account. </li><li>If **data** is NULL or **dataLength** is less than or equal to 0, the auxiliary picture data will not be initialized.</li></ul>

**Since:** 26.0.0

**System API**: This is a system API.

**Parameters**

| Name| Description|
| -- | -- |
| uint8_t *data | Pointer to the picture data.|
| uint32_t dataLength | Length of the picture data.|
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the basic information about the auxiliary picture.|
| [IMAGE_ALLOCATOR_MODE](capi-image-common-h.md#image_allocator_mode) allocator | Memory type used by the auxiliary picture. For details about the available options, see [IMAGE_ALLOCATOR_MODE](capi-image-common-h.md#image_allocator_mode).|
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) **auxiliaryPicture | Output parameter, which is used to receive the address of the newly created OH_AuxiliaryPictureNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**202**: This API is called by a non-system application.</li><br>         <li> **IMAGE_INVALID_PARAMETER**: **info** or **auxiliaryPicture** is a null pointer, **allocator** is invalid, the size or type of the auxiliary picture is invalid, or **dataLength** is less than the required value.</li><br>         <li>**IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE**: Unsupported memory type.<br>         For example, creating a gain map using shared memory is not supported because only DMA supports HDR metadata.</li><br>         <li>**IMAGE_ALLOC_FAILED**: The memory allocation fails.</li><br>         </ul> |
<!--DelEnd-->
### OH_AuxiliaryPictureNative_WritePixels()

```c
Image_ErrorCode OH_AuxiliaryPictureNative_WritePixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *source, size_t bufferSize)
```

**Description**

Reads pixels in the buffer and writes the result to an auxiliary picture.

Restrictions: **auxiliaryPicture** and **source** must not be null pointers. **bufferSize** must match the size of the pixel data to be written.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to an OH_AuxiliaryPictureNative object.|
| uint8_t *source | Pixels to be written.|
| size_t bufferSize | Buffer size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_ALLOC_FAILED**: memory allocation failure.<br>         **IMAGE_COPY_FAILED**: memory copy failure.|

### OH_AuxiliaryPictureNative_ReadPixels()

```c
Image_ErrorCode OH_AuxiliaryPictureNative_ReadPixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *destination, size_t *bufferSize)
```

**Description**

Reads pixels of an auxiliary picture and writes the result to the buffer.

Restrictions: **auxiliaryPicture**, **destination**, and **bufferSize** cannot be null pointers. **bufferSize** must indicate the size of the writable buffer for **destination**. After the API is successfully called, **bufferSize** is updated to the size of the actually read data.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to an OH_AuxiliaryPictureNative object.|
| uint8_t *destination | Pointer to the buffer to which the pixels of the auxiliary data will be written.|
| size_t *bufferSize | Pointer to the buffer size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_ALLOC_FAILED**: memory allocation failure.<br>         **IMAGE_COPY_FAILED**: memory copy failure.|

### OH_AuxiliaryPictureNative_GetType()

```c
Image_ErrorCode OH_AuxiliaryPictureNative_GetType(OH_AuxiliaryPictureNative *auxiliaryPicture, Image_AuxiliaryPictureType *type)
```

**Description**

Obtains the type of an auxiliary picture.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to an OH_AuxiliaryPictureNative object.|
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) *type | Pointer to the auxiliary picture type.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureNative_GetInfo()

```c
Image_ErrorCode OH_AuxiliaryPictureNative_GetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture, OH_AuxiliaryPictureInfo **info)
```

**Description**

Obtains the information of an auxiliary picture.

Resource management: The OH_AuxiliaryPictureInfo object returned by the API is managed by the caller and must be released using OH_AuxiliaryPictureInfo_Release() after use.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to an OH_AuxiliaryPictureNative object.|
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) **info | Double pointer to the auxiliary picture information.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureNative_SetInfo()

```c
Image_ErrorCode OH_AuxiliaryPictureNative_SetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture, OH_AuxiliaryPictureInfo *info)
```

**Description**

Sets the information for an auxiliary picture.

Resource management: The API reads and saves the information value in OH_AuxiliaryPictureInfo. After the API is called, the caller still needs to manage the lifecycle of the OH_AuxiliaryPictureInfo object.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to an OH_AuxiliaryPictureNative object.|
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the auxiliary picture information.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureNative_GetMetadata()

```c
Image_ErrorCode OH_AuxiliaryPictureNative_GetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture, Image_MetadataType metadataType, OH_PictureMetadata **metadata)
```

**Description**

Obtains the metadata of an auxiliary picture.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to an OH_AuxiliaryPictureNative object.|
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) metadataType | Metadata type.|
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) **metadata | Double pointer to the metadata.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_METADATA**: unsupported metadata type, or mismatch between the metadata type and the auxiliary picture type.|

### OH_AuxiliaryPictureNative_SetMetadata()

```c
Image_ErrorCode OH_AuxiliaryPictureNative_SetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture, Image_MetadataType metadataType, OH_PictureMetadata *metadata)
```

**Description**

Sets the metadata for an auxiliary picture.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to an OH_AuxiliaryPictureNative object.|
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) metadataType | Metadata type.|
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) *metadata | Pointer to the metadata.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_METADATA**: unsupported metadata type, or mismatch between the metadata type and the auxiliary picture type.|

### OH_AuxiliaryPictureNative_AcquirePixelmap()

```c
Image_ErrorCode OH_AuxiliaryPictureNative_AcquirePixelmap(OH_AuxiliaryPictureNative *auxiliaryPicture, OH_PixelmapNative **pixelmap)
```

**Description**

Obtains the OH_PixelmapNative object of an auxiliary picture.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to the OH_AuxiliaryPictureNative object.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Output parameter, which is used to receive the address of the obtained OH_PixelmapNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>**IMAGE_SUCCESS**: The operation is successful.</li><br>         <li>**IMAGE_INVALID_PARAMETER**: **auxiliaryPicture** or **pixelmap** is a null pointer.</li><br>         <li>**IMAGE_GET_IMAGE_DATA_FAILED**: The auxiliary picture or pixel data cannot be obtained.</li><br>         <li>**IMAGE_ALLOC_FAILED**: The memory allocation fails.</li><br>         </ul> |

### OH_AuxiliaryPictureNative_Release()

```c
Image_ErrorCode OH_AuxiliaryPictureNative_Release(OH_AuxiliaryPictureNative *picture)
```

**Description**

Releases the pointer to an OH_AuxiliaryPictureNative object.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *picture | Pointer to an OH_AuxiliaryPictureNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_Create()

```c
Image_ErrorCode OH_AuxiliaryPictureInfo_Create(OH_AuxiliaryPictureInfo **info)
```

**Description**

Creates an OH_AuxiliaryPictureInfo object.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) **info | Double pointer to the OH_AuxiliaryPictureInfo object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_GetType()

```c
Image_ErrorCode OH_AuxiliaryPictureInfo_GetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType *type)
```

**Description**

Obtains the auxiliary picture type in **OH_AuxiliaryPictureInfo**.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) *type | Pointer to the type of the auxiliary picture.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_SetType()

```c
Image_ErrorCode OH_AuxiliaryPictureInfo_SetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType type)
```

**Description**

Sets the auxiliary picture type in **OH_AuxiliaryPictureInfo**.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) type | Type of the auxiliary picture.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_GetSize()

```c
Image_ErrorCode OH_AuxiliaryPictureInfo_GetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)
```

**Description**

Obtains the image size in **OH_AuxiliaryPictureInfo**.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| [Image_Size](capi-image-nativemodule-image-size.md) *size | Pointer to the size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_SetSize()

```c
Image_ErrorCode OH_AuxiliaryPictureInfo_SetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)
```

**Description**

Sets the image size in **OH_AuxiliaryPictureInfo**.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| [Image_Size](capi-image-nativemodule-image-size.md) *size | Pointer to the size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_GetRowStride()

```c
Image_ErrorCode OH_AuxiliaryPictureInfo_GetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t *rowStride)
```

**Description**

Obtains the row stride in **OH_AuxiliaryPictureInfo**.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| uint32_t *rowStride | Pointer to the row stride, which is the space occupied by each row of pixels in memory.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_SetRowStride()

```c
Image_ErrorCode OH_AuxiliaryPictureInfo_SetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t rowStride)
```

**Description**

Sets the row stride in **OH_AuxiliaryPictureInfo**.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| uint32_t rowStride | Row stride, which is the space occupied by each row of pixels in memory.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_GetPixelFormat()

```c
Image_ErrorCode OH_AuxiliaryPictureInfo_GetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT *pixelFormat)
```

**Description**

Obtains the pixel format in **OH_AuxiliaryPictureInfo**.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) *pixelFormat | Pointer to the pixel format obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_SetPixelFormat()

```c
Image_ErrorCode OH_AuxiliaryPictureInfo_SetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT pixelFormat)
```

**Description**

Sets the pixel format in **OH_AuxiliaryPictureInfo**.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) pixelFormat | Pixel format.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_Release()

```c
Image_ErrorCode OH_AuxiliaryPictureInfo_Release(OH_AuxiliaryPictureInfo *info)
```

**Description**

Releases the pointer to an OH_AuxiliaryPictureInfo object.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

<!--Del-->
### OH_DecomposeOptions

```c
typedef struct OH_DecomposeOptions OH_DecomposeOptions
```

**Description**

Struct at the native layer that encapsulates HDR decomposition option parameters. It is used to specify the parameters for HDR decomposition, including the gain map size (full-size or half-size) and the pixel formats of the resulting SDR PixelMap and gain map.

**Since:** 26.0.0

### OH_DecomposeOptions_Create()

```c
Image_ErrorCode OH_DecomposeOptions_Create(OH_DecomposeOptions **outOwnedOptions)
```

**Description**

Creates an OH_DecomposeOptions instance. The created instance must be released by calling [OH_DecomposeOptions_Release](#oh_decomposeoptions_release).

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecomposeOptions](#oh_decomposeoptions) **outOwnedOptions | Pointer to the created OH_DecomposeOptions object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_INVALID_PARAMETER**: Parameter error. For example, **outOwnedOptions** is nullptr.<br>         **IMAGE_ALLOC_FAILED**: memory allocation failure.<br>         **202**: This API is called by a non-system application.|

### OH_DecomposeOptions_SetIsFullSizeGainmap()

```c
Image_ErrorCode OH_DecomposeOptions_SetIsFullSizeGainmap(OH_DecomposeOptions *options, bool isFullSizeGainmap)
```

**Description**

Sets whether to generate a full-size gain map (the size of the gain map is the same as that of the main picture). If this parameter is not set, the default value **false** is used. That is, the size of the gain map is half of that of the main picture.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecomposeOptions](#oh_decomposeoptions) *options | Pointer to the OH_DecomposeOptions object.|
| bool isFullSizeGainmap | Whether to generate a full-size gain map. If this parameter is set to **true**, a full-size gain map is generated. If this parameter is set to **false**, a 1/2 reduced gain map is generated.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_INVALID_PARAMETER**: Parameter error. For example, **options** is nullptr.<br>         **202**: This API is called by a non-system application.|

### OH_DecomposeOptions_GetIsFullSizeGainmap()

```c
Image_ErrorCode OH_DecomposeOptions_GetIsFullSizeGainmap(OH_DecomposeOptions *options, bool *isFullSizeGainmap)
```

**Description**

Checks whether to generate a full-size gain map (the size of the gain map is the same as that of the main picture). If **isFullSizeGainmap** is set to **true**, the size of the gain map is the same as that of the main picture. Otherwise, the size of the gain map is half of that of the main picture.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecomposeOptions](#oh_decomposeoptions) *options | Pointer to the OH_DecomposeOptions object.|
| bool *isFullSizeGainmap | Pointer to the bool value, which is used to receive the setting of whether to generate a full-size gain map.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_INVALID_PARAMETER**: Parameter error. For example, **options** or **isFullSizeGainmap** is nullptr.<br>         **202**: This API is called by a non-system application.|

### OH_DecomposeOptions_SetDesiredPixelFormat()

```c
Image_ErrorCode OH_DecomposeOptions_SetDesiredPixelFormat(OH_DecomposeOptions *options, int32_t desiredPixelFormat)
```

**Description**

Sets the pixel format of the SDR PixelMap and gain map after decomposition. If not set, the default value is **RGBA_8888**.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecomposeOptions](#oh_decomposeoptions) *options | Pointer to the OH_DecomposeOptions object.|
| int32_t desiredPixelFormat | Pixel format of the SDR PixelMap and gain map after decomposition. The RGBA_8888, NV12, and NV21 formats are supported.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_INVALID_PARAMETER**: Parameter error. For example, **options** is nullptr.<br>         **IMAGE_UNSUPPORTED_OPERATION**: Unsupported pixel format.<br>         **202**: This API is called by a non-system application.|

### OH_DecomposeOptions_GetDesiredPixelFormat()

```c
Image_ErrorCode OH_DecomposeOptions_GetDesiredPixelFormat(OH_DecomposeOptions *options, int32_t *desiredPixelFormat)
```

**Description**

Obtains the pixel format of the SDR PixelMap and gain map after decomposition.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecomposeOptions](#oh_decomposeoptions) *options | Pointer to the OH_DecomposeOptions object.|
| int32_t *desiredPixelFormat | Pointer to an int32_t value, which is used to receive the pixel format setting.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_INVALID_PARAMETER**: Parameter error. For example, **options** or **desiredPixelFormat** is nullptr.<br>         **202**: This API is called by a non-system application.|

### OH_DecomposeOptions_Release()

```c
Image_ErrorCode OH_DecomposeOptions_Release(OH_DecomposeOptions *options)
```

**Description**

Releases the pointer to **OH_DecomposeOptions**.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_DecomposeOptions](#oh_decomposeoptions) *options | Pointer to the OH_DecomposeOptions object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_INVALID_PARAMETER**: Parameter error. For example, **options** is nullptr.<br>         **202**: This API is called by a non-system application.|

### OH_PictureNative_DecomposeToPicture()

```c
Image_ErrorCode OH_PictureNative_DecomposeToPicture(OH_PixelmapNative *hdrPixelmap, OH_DecomposeOptions *options, OH_PictureNative **outOwnedPicture)
```

**Description**

Decomposes an HDR PixelMap into a Picture object that contains an SDR PixelMap and a gain map. The created instance must be released by calling [OH_PictureNative_Release](#oh_picturenative_release).

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *hdrPixelmap | Pointer to the HDR PixelMap to decompose. The pixel format must be RGBA_F16, RGBA_1010102, YCBCR_P010, or YCRCB_P010.|
| [OH_DecomposeOptions](#oh_decomposeoptions) *options | HDR decomposition configuration options. This parameter is mandatory.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **outOwnedPicture | Pointer to the Picture object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_INVALID_PARAMETER**: Parameter error. For example, **hdrPixelmap**, **options** or **outOwnedPicture** is nullptr.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The pixel format of **hdrPixelmap** is not RGBA_F16, RGBA_1010102, YCBCR_P010, or YCRCB_P010.<br>         **IMAGE_DECOMPOSE_FAILED**: HDR decomposition failed.<br>         **IMAGE_ALLOC_FAILED**: memory allocation failure.<br>         **202**: This API is called by a non-system application.|
<!--DelEnd-->
