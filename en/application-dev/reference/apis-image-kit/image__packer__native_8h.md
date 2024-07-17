# image_packer_native.h


## Overview

The **image_packer_native.h** file declares the APIs for image encoding.

**Library**: libimage_packer.so

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Since**: 12

**Related module**: [Image_NativeModule](_image___native_module.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) [OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) | Defines the **ImagePacker** struct, which is used to perform operations related to an image packer.| 
| typedef struct [OH_PackingOptions](_image___native_module.md#oh_packingoptions) [OH_PackingOptions](_image___native_module.md#oh_packingoptions) | Defines a struct for image encoding parameters.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [IMAGE_PACKER_DYNAMIC_RANGE](_image___native_module.md#image_packer_dynamic_range) {<br>IMAGE_PACKER_DYNAMIC_RANGE_AUTO = 0,<br>IMAGE_PACKER_DYNAMIC_RANGE_SDR = 1 } | Enumerates the dynamic range for encoding.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_Create](_image___native_module.md#oh_packingoptions_create) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*\*options) | Creates the pointer to an **OH_PackingOptions** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_GetMimeType](_image___native_module.md#oh_packingoptions_getmimetype) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [Image_MimeType](_image___native_module.md#image_mimetype) \*format) | Obtains the MIME type.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_SetMimeType](_image___native_module.md#oh_packingoptions_setmimetype) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [Image_MimeType](_image___native_module.md#image_mimetype) \*format) | Sets the MIME type.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_GetQuality](_image___native_module.md#oh_packingoptions_getquality) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, uint32_t \*quality) | Obtains the encoding quality.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_SetQuality](_image___native_module.md#oh_packingoptions_setquality) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, uint32_t quality) | Sets the encoding quality.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_GetDesiredDynamicRange](_image___native_module.md#oh_packingoptions_getdesireddynamicrange) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, int32_t \*desiredDynamicRange) | Obtains the desired dynamic range during encoding.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_SetDesiredDynamicRange](_image___native_module.md#oh_packingoptions_setdesireddynamicrange) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, int32_t desiredDynamicRange) | Sets the desired dynamic range during encoding.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_Release](_image___native_module.md#oh_packingoptions_release) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options) | Releases the pointer to an **OH_PackingOptions** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_Create](_image___native_module.md#oh_imagepackernative_create) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*\*imagePacker) | Creates the pointer to an **OH_ImagePackerNative** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToDataFromImageSource](_image___native_module.md#oh_imagepackernative_packtodatafromimagesource) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*imageSource, uint8_t \*outData, size_t \*size) | Encodes an image source into data in a given format.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToDataFromPixelmap](_image___native_module.md#oh_imagepackernative_packtodatafrompixelmap) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, uint8_t \*outData, size_t \*size) | Encodes a pixel map into data in a given format.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToFileFromImageSource](_image___native_module.md#oh_imagepackernative_packtofilefromimagesource) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*imageSource, int32_t fd) | Encodes an image source into a file.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToFileFromPixelmap](_image___native_module.md#oh_imagepackernative_packtofilefrompixelmap) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, int32_t fd) | Encodes a pixel map into a file.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_Release](_image___native_module.md#oh_imagepackernative_release) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker) | Releases the pointer to an **OH_ImagePackerNative** object.| 
