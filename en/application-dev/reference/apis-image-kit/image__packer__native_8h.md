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
| typedef struct [OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) [OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) | Defines a struct for the image packer, which is used to perform operations related to an image packer.| 
| typedef struct [OH_PackingOptions](_image___native_module.md#oh_packingoptions) [OH_PackingOptions](_image___native_module.md#oh_packingoptions) | Defines a struct for image encoding parameters.| 
| typedef struct [OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) [OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) | Defines a struct for image sequence encoding parameters. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [IMAGE_PACKER_DYNAMIC_RANGE](_image___native_module.md#image_packer_dynamic_range) {<br>IMAGE_PACKER_DYNAMIC_RANGE_AUTO = 0,<br>IMAGE_PACKER_DYNAMIC_RANGE_SDR = 1<br>} | Enumerates the dynamic range for encoding.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_Create](_image___native_module.md#oh_packingoptions_create) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*\*options) | Creates the pointer to an **OH_PackingOptions** struct.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_GetMimeType](_image___native_module.md#oh_packingoptions_getmimetype) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [Image_MimeType](_image___native_module.md#image_mimetype) \*format) | Obtains the MIME type.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_SetMimeType](_image___native_module.md#oh_packingoptions_setmimetype) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [Image_MimeType](_image___native_module.md#image_mimetype) \*format) | Sets the MIME type.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_GetQuality](_image___native_module.md#oh_packingoptions_getquality) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, uint32_t \*quality) | Obtains the encoding quality.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_SetQuality](_image___native_module.md#oh_packingoptions_setquality) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, uint32_t quality) | Sets the encoding quality.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_GetDesiredDynamicRange](_image___native_module.md#oh_packingoptions_getdesireddynamicrange) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, int32_t \*desiredDynamicRange) | Obtains the desired dynamic range during encoding.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_SetDesiredDynamicRange](_image___native_module.md#oh_packingoptions_setdesireddynamicrange) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, int32_t desiredDynamicRange) | Sets the desired dynamic range during encoding.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptions_Release](_image___native_module.md#oh_packingoptions_release) ([OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options) | Releases the pointer to an **OH_PackingOptions** struct.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_Create](_image___native_module.md#oh_packingoptionsforsequence_create) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*\*options) | Creates the pointer to an **OH_PackingOptionsForSequence** struct. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_SetFrameCount](_image___native_module.md#oh_packingoptionsforsequence_setframecount) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, uint32_t frameCount) | Sets the number of frames for image sequence encoding. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_GetFrameCount](_image___native_module.md#oh_packingoptionsforsequence_getframecount) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, uint32_t \*frameCount) | Obtains the number of frames for image sequence encoding. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_SetDelayTimeList](_image___native_module.md#oh_packingoptionsforsequence_setdelaytimelist) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, int32_t \*delayTimeList, size_t delayTimeListLength) | Sets the delay time array for image sequence encoding. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_GetDelayTimeList](_image___native_module.md#oh_packingoptionsforsequence_getdelaytimelist) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, int32_t \*delayTimeList, size_t delayTimeListLength) | Obtains the delay time array for image sequence encoding. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_SetDisposalTypes](_image___native_module.md#oh_packingoptionsforsequence_setdisposaltypes) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, uint32_t \*disposalTypes, size_t disposalTypesLength) | Sets the disposal type array for image sequence encoding. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_GetDisposalTypes](_image___native_module.md#oh_packingoptionsforsequence_getdisposaltypes) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, uint32_t \*disposalTypes, size_t disposalTypesLength) | Obtains the disposal type array for image sequence encoding. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_SetLoopCount](_image___native_module.md#oh_packingoptionsforsequence_setloopcount) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, uint32_t loopCount) | Sets the number of loops for image sequence encoding. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_GetLoopCount](_image___native_module.md#oh_packingoptionsforsequence_getloopcount) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, uint32_t \*loopCount) | Obtains the number of loops for image sequence encoding. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PackingOptionsForSequence_Release](_image___native_module.md#oh_packingoptionsforsequence_release) ([OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options) | Releases the pointer to an **OH_PackingOptionsForSequence** struct. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_Create](_image___native_module.md#oh_imagepackernative_create) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*\*imagePacker) | Creates the pointer to an **OH_ImagePackerNative** struct.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToDataFromImageSource](_image___native_module.md#oh_imagepackernative_packtodatafromimagesource) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*imageSource, uint8_t \*outData, size_t \*size) | Encodes an image source into data in a given format.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToDataFromPixelmap](_image___native_module.md#oh_imagepackernative_packtodatafrompixelmap) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, uint8_t \*outData, size_t \*size) | Encodes a PixelMap into data in a given format.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToDataFromPicture](_image___native_module.md#oh_imagepackernative_packtodatafrompicture) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, uint8_t \*outData, size_t \*size) | Encodes a picture into data in a given format.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToDataFromPixelmapSequence](_image___native_module.md#oh_imagepackernative_packtodatafrompixelmapsequence) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, [OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*\*pixelmapSequence, size_t sequenceLength, uint8_t \*outData, size_t \*outDataSize) | Encodes a PixelMap sequence into data. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToFileFromImageSource](_image___native_module.md#oh_imagepackernative_packtofilefromimagesource) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*imageSource, int32_t fd) | Encodes an image source into a file.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToFileFromPixelmap](_image___native_module.md#oh_imagepackernative_packtofilefrompixelmap) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, int32_t fd) | Encodes a PixelMap into a file.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToFileFromPicture](_image___native_module.md#oh_imagepackernative_packtofilefrompicture) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](_image___native_module.md#oh_packingoptions) \*options, [OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, int32_t fd) | Encodes a picture into a file.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_PackToFileFromPixelmapSequence](_image___native_module.md#oh_imagepackernative_packtofilefrompixelmapsequence) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker, [OH_PackingOptionsForSequence](_image___native_module.md#oh_packingoptionsforsequence) \*options, [OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*\*pixelmapSequence, size_t sequenceLength, int32_t fd) | Encodes a PixelMap sequence into a file. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImagePackerNative_Release](_image___native_module.md#oh_imagepackernative_release) ([OH_ImagePackerNative](_image___native_module.md#oh_imagepackernative) \*imagePacker) | Releases the pointer to an **OH_ImagePackerNative** struct.| 
