# picture_native.h


## Overview

The **picture_native.h** file declares the APIs for obtaining picture data and information.

**Library**: libpicture.so

**File to include**: &lt;multimedia/image_framework/image/picture_native.h&gt;

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 13

**Related module**: [Image_NativeModule](_image___native_module.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_PictureNative](_image___native_module.md#oh_picturenative) [OH_PictureNative](_image___native_module.md#oh_picturenative) | Defines a struct for the picture, which is used to perform operations related to the picture.| 
| typedef struct [OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) [OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) | Defines a struct for the auxiliary picture, which is used to perform operations related to the auxiliary picture.| 
| typedef struct [OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) [OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) | Defines a struct for the auxiliary picture information, which is used to perform operations related to the auxiliary picture information.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) {<br>AUXILIARY_PICTURE_TYPE_GAINMAP = 1,<br>AUXILIARY_PICTURE_TYPE_DEPTH_MAP = 2,<br>AUXILIARY_PICTURE_TYPE_UNREFOCUS_MAP = 3,<br>AUXILIARY_PICTURE_TYPE_LINEAR_MAP = 4,<br>AUXILIARY_PICTURE_TYPE_FRAGMENT_MAP = 5<br>} | Enumerates the auxiliary picture types.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_CreatePicture](_image___native_module.md#oh_picturenative_createpicture) (OH_PixelmapNative \*mainPixelmap, [OH_PictureNative](_image___native_module.md#oh_picturenative) \*\*picture) | Creates the pointer to an **OH_PictureNative** struct.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_GetMainPixelmap](_image___native_module.md#oh_picturenative_getmainpixelmap) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, OH_PixelmapNative \*\*mainPixelmap) | Obtains the pointer to the **OH_PixelmapNative** object of a main picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_GetHdrComposedPixelmap](_image___native_module.md#oh_picturenative_gethdrcomposedpixelmap) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, OH_PixelmapNative \*\*hdrPixelmap) | Obtains the pointer to the **OH_PixelmapNative** object of an HDR picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_GetGainmapPixelmap](_image___native_module.md#oh_picturenative_getgainmappixelmap) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, OH_PixelmapNative \*\*gainmapPixelmap) | Obtains the pointer to the **OH_PixelmapNative** object of a gain map.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_SetAuxiliaryPicture](_image___native_module.md#oh_picturenative_setauxiliarypicture) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) type, [OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture) | Sets an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_GetAuxiliaryPicture](_image___native_module.md#oh_picturenative_getauxiliarypicture) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) type, [OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*\*auxiliaryPicture) | Obtains an auxiliary picture by type.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_GetMetadata](_image___native_module.md#oh_picturenative_getmetadata) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, [Image_MetadataType](_image___native_module.md#image_metadatatype) metadataType, [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*\*metadata) | Obtains the metadata of a picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_SetMetadata](_image___native_module.md#oh_picturenative_setmetadata) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, [Image_MetadataType](_image___native_module.md#image_metadatatype) metadataType, [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*metadata) | Sets the metadata for a picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_Release](_image___native_module.md#oh_picturenative_release) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture) | Releases the pointer to an **OH_PictureNative** struct.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_Create](_image___native_module.md#oh_auxiliarypicturenative_create) (uint8_t \*data, size_t dataLength, [Image_Size](_image___size.md) \*size, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) type, [OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*\*auxiliaryPicture) | Creates the pointer to an **OH_AuxiliaryPictureNative** struct.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_WritePixels](_image___native_module.md#oh_auxiliarypicturenative_writepixels) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, uint8_t \*source, size_t bufferSize) | Reads pixels in the buffer and writes the result to an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_ReadPixels](_image___native_module.md#oh_auxiliarypicturenative_readpixels) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, uint8_t \*destination, size_t \*bufferSize) | Reads pixels of an auxiliary picture and writes the result to the buffer.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_GetType](_image___native_module.md#oh_auxiliarypicturenative_gettype) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) \*type) | Obtains the type of an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_GetInfo](_image___native_module.md#oh_auxiliarypicturenative_getinfo) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, [OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*\*info) | Obtains the information of an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_SetInfo](_image___native_module.md#oh_auxiliarypicturenative_setinfo) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, [OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info) | Sets the information for an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_GetMetadata](_image___native_module.md#oh_auxiliarypicturenative_getmetadata) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, [Image_MetadataType](_image___native_module.md#image_metadatatype) metadataType, [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*\*metadata) | Obtains the metadata of an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_SetMetadata](_image___native_module.md#oh_auxiliarypicturenative_setmetadata) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, [Image_MetadataType](_image___native_module.md#image_metadatatype) metadataType, [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*metadata) | Sets the metadata for an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_Release](_image___native_module.md#oh_auxiliarypicturenative_release) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*picture) | Releases the pointer to an **OH_AuxiliaryPictureNative** struct.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_Create](_image___native_module.md#oh_auxiliarypictureinfo_create) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*\*info) | Creates an **OH_AuxiliaryPictureInfo** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_GetType](_image___native_module.md#oh_auxiliarypictureinfo_gettype) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) \*type) | Obtains the auxiliary picture type from the auxiliary picture information.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_SetType](_image___native_module.md#oh_auxiliarypictureinfo_settype) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) type) | Sets the auxiliary picture type in the auxiliary picture information.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_GetSize](_image___native_module.md#oh_auxiliarypictureinfo_getsize) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, [Image_Size](_image___size.md) \*size) | Obtains the size of an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_SetSize](_image___native_module.md#oh_auxiliarypictureinfo_setsize) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, [Image_Size](_image___size.md) \*size) | Sets the size for an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_GetRowStride](_image___native_module.md#oh_auxiliarypictureinfo_getrowstride) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, uint32_t \*rowStride) | Obtains the row stride of an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_SetRowStride](_image___native_module.md#oh_auxiliarypictureinfo_setrowstride) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, uint32_t rowStride) | Sets the row stride for an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_GetPixelFormat](_image___native_module.md#oh_auxiliarypictureinfo_getpixelformat) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, PIXEL_FORMAT \*pixelFormat) | Obtains the pixel format of an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_SetPixelFormat](_image___native_module.md#oh_auxiliarypictureinfo_setpixelformat) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, PIXEL_FORMAT pixelFormat) | Sets the pixel format for an auxiliary picture.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_Release](_image___native_module.md#oh_auxiliarypictureinfo_release) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info) | Releases the pointer to an **OH_AuxiliaryPictureInfo** object.| 
