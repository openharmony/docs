# picture_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## Overview

The file declares the APIs for obtaining picture data and information.

**Library**: libpicture.so

**Since**: 13

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) | OH_PictureNative | Describes the picture, which is used to perform operations related to the picture.|
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) | OH_AuxiliaryPictureNative | Describes the auxiliary picture, which is used to perform operations related to the auxiliary picture.|
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) | OH_AuxiliaryPictureInfo | Describes the auxiliary picture information, which is used to perform operations related to the auxiliary picture information.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) | Image_AuxiliaryPictureType | Type of the auxiliary picture.|

### Functions

| Name| Description|
| -- | -- |
| [Image_ErrorCode OH_PictureNative_CreatePicture(OH_PixelmapNative *mainPixelmap, OH_PictureNative **picture)](#oh_picturenative_createpicture) | Creates the pointer to an OH_PictureNative object.|
| [Image_ErrorCode OH_PictureNative_GetMainPixelmap(OH_PictureNative *picture, OH_PixelmapNative **mainPixelmap)](#oh_picturenative_getmainpixelmap) | Obtains the pointer to the OH_PixelmapNative object of a main picture.|
| [Image_ErrorCode OH_PictureNative_GetHdrComposedPixelmap(OH_PictureNative *picture, OH_PixelmapNative **hdrPixelmap)](#oh_picturenative_gethdrcomposedpixelmap) | Obtains the pointer to the OH_PixelmapNative object of an HDR picture.|
| [Image_ErrorCode OH_PictureNative_GetGainmapPixelmap(OH_PictureNative *picture, OH_PixelmapNative **gainmapPixelmap)](#oh_picturenative_getgainmappixelmap) | Obtains the pointer to the OH_PixelmapNative object of a gain map.|
| [Image_ErrorCode OH_PictureNative_SetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type,OH_AuxiliaryPictureNative *auxiliaryPicture)](#oh_picturenative_setauxiliarypicture) | Sets an auxiliary picture.|
| [Image_ErrorCode OH_PictureNative_GetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type,OH_AuxiliaryPictureNative **auxiliaryPicture)](#oh_picturenative_getauxiliarypicture) | Obtains an auxiliary picture by type.|
| [Image_ErrorCode OH_PictureNative_GetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType,OH_PictureMetadata **metadata)](#oh_picturenative_getmetadata) | Obtains the metadata of a main picture.|
| [Image_ErrorCode OH_PictureNative_SetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType,OH_PictureMetadata *metadata)](#oh_picturenative_setmetadata) | Sets the metadata for a main picture.|
| [Image_ErrorCode OH_PictureNative_Release(OH_PictureNative *picture)](#oh_picturenative_release) | Releases the pointer to an OH_PictureNative object.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_Create(uint8_t *data, size_t dataLength, Image_Size *size,Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative **auxiliaryPicture)](#oh_auxiliarypicturenative_create) | Creates the pointer to an OH_AuxiliaryPictureNative object.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_WritePixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *source,size_t bufferSize)](#oh_auxiliarypicturenative_writepixels) | Reads pixels in the buffer and writes the result to an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_ReadPixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *destination,size_t *bufferSize)](#oh_auxiliarypicturenative_readpixels) | Reads pixels of an auxiliary picture and writes the result to the buffer.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_GetType(OH_AuxiliaryPictureNative *auxiliaryPicture,Image_AuxiliaryPictureType *type)](#oh_auxiliarypicturenative_gettype) | Obtains the type of an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_GetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture,OH_AuxiliaryPictureInfo **info)](#oh_auxiliarypicturenative_getinfo) | Obtains the information of an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_SetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture,OH_AuxiliaryPictureInfo *info)](#oh_auxiliarypicturenative_setinfo) | Sets the information for an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_GetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture,Image_MetadataType metadataType, OH_PictureMetadata **metadata)](#oh_auxiliarypicturenative_getmetadata) | Obtains the metadata of an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_SetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture,Image_MetadataType metadataType, OH_PictureMetadata *metadata)](#oh_auxiliarypicturenative_setmetadata) | Sets the metadata for an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureNative_Release(OH_AuxiliaryPictureNative *picture)](#oh_auxiliarypicturenative_release) | Releases the pointer to an OH_AuxiliaryPictureNative object.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_Create(OH_AuxiliaryPictureInfo **info)](#oh_auxiliarypictureinfo_create) | Creates an OH_AuxiliaryPictureInfo object.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_GetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType *type)](#oh_auxiliarypictureinfo_gettype) | Obtains the auxiliary picture type from the auxiliary picture information.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_SetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType type)](#oh_auxiliarypictureinfo_settype) | Sets the auxiliary picture type in the auxiliary picture information.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_GetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)](#oh_auxiliarypictureinfo_getsize) | Obtains the size of an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_SetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)](#oh_auxiliarypictureinfo_setsize) | Sets the size for an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_GetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t *rowStride)](#oh_auxiliarypictureinfo_getrowstride) | Obtains the row stride of an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_SetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t rowStride)](#oh_auxiliarypictureinfo_setrowstride) | Sets the row stride for an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_GetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT *pixelFormat)](#oh_auxiliarypictureinfo_getpixelformat) | Obtains the pixel format of an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_SetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT pixelFormat)](#oh_auxiliarypictureinfo_setpixelformat) | Sets the pixel format for an auxiliary picture.|
| [Image_ErrorCode OH_AuxiliaryPictureInfo_Release(OH_AuxiliaryPictureInfo *info)](#oh_auxiliarypictureinfo_release) | Releases the pointer to an OH_AuxiliaryPictureInfo object.|

## Enum Description

### Image_AuxiliaryPictureType

```
enum Image_AuxiliaryPictureType
```

**Description**

Enumerates the auxiliary picture types.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| AUXILIARY_PICTURE_TYPE_GAINMAP = 1 | Gain map, a mechanism for transforming an SDR image into an HDR image capable of adjustable display adjustment. It is a set of combinations describing how to apply gain map metadata.|
| AUXILIARY_PICTURE_TYPE_DEPTH_MAP = 2 | Depth map, which stores the depth data of an image. It captures the distance between each pixel and the camera to provide 3D scene structure. It is usually used for 3D modeling and scene comprehension.|
| AUXILIARY_PICTURE_TYPE_UNREFOCUS_MAP = 3 | Defocused portrait original image, which provides a method to emphasize background blur in portrait photographing. It helps users select a focus region in post-processing, allowing for greater creative control.|
| AUXILIARY_PICTURE_TYPE_LINEAR_MAP = 4 | Linear map, which is used to provide additional viewpoints or supplementary information. It is usually used to enhance visual effects and can contain linear representations of lighting, colors, or other visual elements in a scene.|
| AUXILIARY_PICTURE_TYPE_FRAGMENT_MAP = 5 | Fragment map, which indicates regions obscured by watermarks in the original image. It is used to remove or correct the watermark interference, thereby enhancing the image completeness and visibility.|


## Function Description

### OH_PictureNative_CreatePicture()

```
Image_ErrorCode OH_PictureNative_CreatePicture(OH_PixelmapNative *mainPixelmap, OH_PictureNative **picture)
```

**Description**

Creates the pointer to an OH_PictureNative object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *mainPixelmap | Pointer to the OH_PixelmapNative object of the main picture.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **picture | Double pointer to the OH_PictureNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureNative_GetMainPixelmap()

```
Image_ErrorCode OH_PictureNative_GetMainPixelmap(OH_PictureNative *picture, OH_PixelmapNative **mainPixelmap)
```

**Description**

Obtains the pointer to the OH_PixelmapNative object of a main picture.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **mainPixelmap | Double pointer to the OH_PixelmapNative object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureNative_GetHdrComposedPixelmap()

```
Image_ErrorCode OH_PictureNative_GetHdrComposedPixelmap(OH_PictureNative *picture, OH_PixelmapNative **hdrPixelmap)
```

**Description**

Obtains the pointer to the OH_PixelmapNative object of an HDR picture.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **hdrPixelmap | Double pointer to the OH_PixelmapNative object of the HDR picture.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported. For example, the Picture object does not contain a gain map.|

### OH_PictureNative_GetGainmapPixelmap()

```
Image_ErrorCode OH_PictureNative_GetGainmapPixelmap(OH_PictureNative *picture, OH_PixelmapNative **gainmapPixelmap)
```

**Description**

Obtains the pointer to the OH_PixelmapNative object of a gain map.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **gainmapPixelmap | Double pointer to the OH_PixelmapNative object of the gain map.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureNative_SetAuxiliaryPicture()

```
Image_ErrorCode OH_PictureNative_SetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type,OH_AuxiliaryPictureNative *auxiliaryPicture)
```

**Description**

Sets an auxiliary picture.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) type | Type of the auxiliary picture.|
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to an OH_AuxiliaryPictureNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureNative_GetAuxiliaryPicture()

```
Image_ErrorCode OH_PictureNative_GetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type,OH_AuxiliaryPictureNative **auxiliaryPicture)
```

**Description**

Obtains an auxiliary picture by type.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative object.|
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) type | Type of the auxiliary picture.|
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) **auxiliaryPicture | Double pointer to the OH_AuxiliaryPictureNative object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureNative_GetMetadata()

```
Image_ErrorCode OH_PictureNative_GetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType,OH_PictureMetadata **metadata)
```

**Description**

Obtains the metadata of a main picture.

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
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_UNSUPPORTED_METADATA**: unsupported metadata type.|

### OH_PictureNative_SetMetadata()

```
Image_ErrorCode OH_PictureNative_SetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType,OH_PictureMetadata *metadata)
```

**Description**

Sets the metadata for a main picture.

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
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_UNSUPPORTED_METADATA**: unsupported metadata type.|

### OH_PictureNative_Release()

```
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
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureNative_Create()

```
Image_ErrorCode OH_AuxiliaryPictureNative_Create(uint8_t *data, size_t dataLength, Image_Size *size,Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative **auxiliaryPicture)
```

**Description**

Creates the pointer to an OH_AuxiliaryPictureNative object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| uint8_t *data | Pointer to the image data.|
| size_t dataLength | Length of the image data.|
| [Image_Size](capi-image-nativemodule-image-size.md) *size | Pointer to the size of the auxiliary picture.|
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) type | Type of the auxiliary picture.|
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) **auxiliaryPicture | Double pointer to the OH_AuxiliaryPictureNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureNative_WritePixels()

```
Image_ErrorCode OH_AuxiliaryPictureNative_WritePixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *source,size_t bufferSize)
```

**Description**

Reads pixels in the buffer and writes the result to an auxiliary picture.

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
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_ALLOC_FAILED**: memory allocation failure.<br> **IMAGE_COPY_FAILED**: memory copy failure.|

### OH_AuxiliaryPictureNative_ReadPixels()

```
Image_ErrorCode OH_AuxiliaryPictureNative_ReadPixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *destination,size_t *bufferSize)
```

**Description**

Reads pixels of an auxiliary picture and writes the result to the buffer.

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
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_ALLOC_FAILED**: memory allocation failure.<br> **IMAGE_COPY_FAILED**: memory copy failure.|

### OH_AuxiliaryPictureNative_GetType()

```
Image_ErrorCode OH_AuxiliaryPictureNative_GetType(OH_AuxiliaryPictureNative *auxiliaryPicture,Image_AuxiliaryPictureType *type)
```

**Description**

Obtains the type of an auxiliary picture.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to an OH_AuxiliaryPictureNative object.|
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) *type | Pointer to the auxiliary picture type.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureNative_GetInfo()

```
Image_ErrorCode OH_AuxiliaryPictureNative_GetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture,OH_AuxiliaryPictureInfo **info)
```

**Description**

Obtains the information of an auxiliary picture.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to an OH_AuxiliaryPictureNative object.|
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) **info | Double pointer to the auxiliary picture information.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureNative_SetInfo()

```
Image_ErrorCode OH_AuxiliaryPictureNative_SetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture,OH_AuxiliaryPictureInfo *info)
```

**Description**

Sets the information for an auxiliary picture.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-image-nativemodule-oh-auxiliarypicturenative.md) *auxiliaryPicture | Pointer to an OH_AuxiliaryPictureNative object.|
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the auxiliary picture information.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureNative_GetMetadata()

```
Image_ErrorCode OH_AuxiliaryPictureNative_GetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture,Image_MetadataType metadataType, OH_PictureMetadata **metadata)
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
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_UNSUPPORTED_METADATA**: unsupported metadata type, or mismatch between the metadata type and the auxiliary picture type.|

### OH_AuxiliaryPictureNative_SetMetadata()

```
Image_ErrorCode OH_AuxiliaryPictureNative_SetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture,Image_MetadataType metadataType, OH_PictureMetadata *metadata)
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
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_UNSUPPORTED_METADATA**: unsupported metadata type, or mismatch between the metadata type and the auxiliary picture type.|

### OH_AuxiliaryPictureNative_Release()

```
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
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_Create()

```
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
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_GetType()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_GetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType *type)
```

**Description**

Obtains the auxiliary picture type from the auxiliary picture information.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) *type | Pointer to the type of the auxiliary picture.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_SetType()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_SetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType type)
```

**Description**

Sets the auxiliary picture type in the auxiliary picture information.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) type | Type of the auxiliary picture.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_GetSize()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_GetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)
```

**Description**

Obtains the size of an auxiliary picture.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| [Image_Size](capi-image-nativemodule-image-size.md) *size | Pointer to the size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_SetSize()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_SetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)
```

**Description**

Sets the size for an auxiliary picture.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| [Image_Size](capi-image-nativemodule-image-size.md) *size | Pointer to the size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_GetRowStride()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_GetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t *rowStride)
```

**Description**

Obtains the row stride of an auxiliary picture.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| uint32_t *rowStride | Pointer to the row stride, which is the number of bytes from one row of pixels in memory to the next row of pixels in memory.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_SetRowStride()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_SetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t rowStride)
```

**Description**

Sets the row stride for an auxiliary picture.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| uint32_t rowStride | Row stride, which is the number of bytes from one row of pixels in memory to the next row of pixels in memory.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_GetPixelFormat()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_GetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT *pixelFormat)
```

**Description**

Obtains the pixel format of an auxiliary picture.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) *pixelFormat | Pointer to the pixel format obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_SetPixelFormat()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_SetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT pixelFormat)
```

**Description**

Sets the pixel format for an auxiliary picture.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) *info | Pointer to the OH_AuxiliaryPictureInfo object.|
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) pixelFormat | Pixel format.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_AuxiliaryPictureInfo_Release()

```
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
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>**IMAGE_BAD_PARAMETER**: A parameter is incorrect.|
