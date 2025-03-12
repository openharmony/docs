# image_source_native.h


## Overview

The **image_source_native.h** file declares the APIs for image decoding.

**Library**: libimage_source.so

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Since**: 12

**Related module**: [Image_NativeModule](_image___native_module.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) | Defines a struct for the image source, which is used to perform operations related to an image source.| 
| typedef struct [OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) [OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) | Defines a struct for the image source information, which is created by calling [OH_ImageSourceInfo_Create](_image___native_module.md#oh_imagesourceinfo_create).| 
| typedef struct [OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) [OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) | Defines a struct for decoding options, which are used in [OH_ImageSourceNative_CreatePixelmap](_image___native_module.md#oh_imagesourcenative_createpixelmap).| 


### Enums

| Name| Description| 
| -------- | -------- |
| [IMAGE_ALLOCATOR_TYPE](_image___native_module.md#image_allocator_type) {<br>IMAGE_ALLOCATOR_TYPE_AUTO = 0,<br>IMAGE_ALLOCATOR_TYPE_DMA = 1,<br>IMAGE_ALLOCATOR_TYPE_SHARE_MEMORY = 2 } | Enumerates the types of allocators used to allocate PixelMap memory.| 
| [IMAGE_DYNAMIC_RANGE](_image___native_module.md#image_dynamic_range) {<br>IMAGE_DYNAMIC_RANGE_AUTO = 0,<br>IMAGE_DYNAMIC_RANGE_SDR = 1,<br>IMAGE_DYNAMIC_RANGE_HDR = 2<br>} | Enumerates the desired dynamic range for decoding.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceInfo_Create](_image___native_module.md#oh_imagesourceinfo_create) ([OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) \*\*info) | Creates the pointer to an **OH_ImageSource_Info** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceInfo_GetWidth](_image___native_module.md#oh_imagesourceinfo_getwidth) ([OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) \*info, uint32_t \*width) | Obtains the image width.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceInfo_GetHeight](_image___native_module.md#oh_imagesourceinfo_getheight) ([OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) \*info, uint32_t \*height) | Obtains the image height.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceInfo_GetDynamicRange](_image___native_module.md#oh_imagesourceinfo_getdynamicrange) ([OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) \*info, bool \*isHdr) | Obtains the dynamic range of an image.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceInfo_Release](_image___native_module.md#oh_imagesourceinfo_release) ([OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) \*info) | Releases the pointer to an **OH_ImageSource_Info** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_Create](_image___native_module.md#oh_decodingoptions_create) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*\*options) | Creates the pointer to an **OH_DecodingOptions** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_GetPixelFormat](_image___native_module.md#oh_decodingoptions_getpixelformat) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, int32_t \*pixelFormat) | Obtains the pixel format.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_SetPixelFormat](_image___native_module.md#oh_decodingoptions_setpixelformat) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, int32_t pixelFormat) | Sets the pixel format.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_GetIndex](_image___native_module.md#oh_decodingoptions_getindex) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, uint32_t \*index) | Obtains the index of an image.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_SetIndex](_image___native_module.md#oh_decodingoptions_setindex) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, uint32_t index) | Sets the index for an image.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_GetRotate](_image___native_module.md#oh_decodingoptions_getrotate) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, float \*rotate) | Obtains the rotation degree.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_SetRotate](_image___native_module.md#oh_decodingoptions_setrotate) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, float rotate) | Sets the rotation angle.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_GetDesiredSize](_image___native_module.md#oh_decodingoptions_getdesiredsize) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, [Image_Size](_image___size.md) \*desiredSize) | Obtains the desired output size.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_SetDesiredSize](_image___native_module.md#oh_decodingoptions_setdesiredsize) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, [Image_Size](_image___size.md) \*desiredSize) | Sets the desired output size.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_GetDesiredRegion](_image___native_module.md#oh_decodingoptions_getdesiredregion) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, [Image_Region](_image___region.md) \*desiredRegion) | Obtains the region to decode.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_SetDesiredRegion](_image___native_module.md#oh_decodingoptions_setdesiredregion) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, [Image_Region](_image___region.md) \*desiredRegion) | Sets the region to decode.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_GetDesiredDynamicRange](_image___native_module.md#oh_decodingoptions_getdesireddynamicrange) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, int32_t \*desiredDynamicRange) | Obtains the desired dynamic range configured during decoding.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_SetDesiredDynamicRange](_image___native_module.md#oh_decodingoptions_setdesireddynamicrange) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, int32_t desiredDynamicRange) | Sets the desired dynamic range during decoding.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_Release](_image___native_module.md#oh_decodingoptions_release) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options) | Releases the pointer to an **OH_DecodingOptions** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreateFromUri](_image___native_module.md#oh_imagesourcenative_createfromuri) (char \*uri, size_t uriSize, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*\*res) | Creates the pointer to an **OH_ImageSourceNative** object based on a URI.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreateFromFd](_image___native_module.md#oh_imagesourcenative_createfromfd) (int32_t fd, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*\*res) | Creates the pointer to an **OH_ImageSourceNative** object based on a file descriptor.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreateFromData](_image___native_module.md#oh_imagesourcenative_createfromdata) (uint8_t \*data, size_t dataSize, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*\*res) | Creates the pointer to an **OH_ImageSourceNative** object based on buffer data.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreateFromRawFile](_image___native_module.md#oh_imagesourcenative_createfromrawfile) (RawFileDescriptor \*rawFile, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*\*res) | Creates the pointer to an **OH_ImageSourceNative** object by using the raw file descriptor of an image resource file.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreatePixelmap](_image___native_module.md#oh_imagesourcenative_createpixelmap) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, [OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*\*pixelmap) | Creates the pointer to an **OH_PixelmapNative** object based on decoding options.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode)[OH_ImageSourceNative_CreatePixelmapUsingAllocator](_image___native_module.md#oh_imagesourcenative_createpixelmapusingallocator) (OH_ImageSourceNative \*source, OH_DecodingOptions \*options, [IMAGE_ALLOCATOR_TYPE](_image___native_module.md#image_allocator_type) allocator, OH_PixelmapNative \*\*pixelmap) | Creates an **OH_PixelmapNative** object based on decoding options and memory type, where **allocatorType** specifies the memory type of the PixelMap.<br>By default, the system selects an appropriate memory type based on the image type, image size, and platform capability. When processing the returned PixelMap object, consider the impact of stride.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreatePixelmapList](_image___native_module.md#oh_imagesourcenative_createpixelmaplist) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, [OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*resVecPixMap[], size_t size) | Creates an array of **OH_PixelmapNative** objects based on decoding options.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreatePicture](_image___native_module.md#oh_imagesourcenative_createpicture) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, OH_DecodingOptionsForPicture \*options, [OH_PictureNative](_image___native_module.md#oh_picturenative) \*\*picture) | Creates the pointer to an **OH_PictureNative** object based on decoding options.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_GetDelayTimeList](_image___native_module.md#oh_imagesourcenative_getdelaytimelist) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, int32_t \*delayTimeList, size_t size) | Obtains the image delay time list.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_GetImageInfo](_image___native_module.md#oh_imagesourcenative_getimageinfo) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, int32_t index, [OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) \*info) | Obtains the information about an image with a given index.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_GetImageProperty](_image___native_module.md#oh_imagesourcenative_getimageproperty) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | Obtains the value of an image property.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_ModifyImageProperty](_image___native_module.md#oh_imagesourcenative_modifyimageproperty) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | Modifies the value of an image property.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_GetFrameCount](_image___native_module.md#oh_imagesourcenative_getframecount) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, uint32_t \*frameCount) | Obtains the number of image frames.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_Release](_image___native_module.md#oh_imagesourcenative_release) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source) | Releases the pointer to an **OH_ImageSourceNative** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptionsForPicture_Create](_image___native_module.md#oh_decodingoptionsforpicture_create) (OH_DecodingOptionsForPicture \*\*options) | Creates the pointer to an **OH_DecodingOptionsForPicture** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures](_image___native_module.md#oh_decodingoptionsforpicture_getdesiredauxiliarypictures) (OH_DecodingOptionsForPicture \*options, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) \*\*desiredAuxiliaryPictures, size_t \*length) | Obtains desired auxiliary pictures in the decoding options (auxiliary pictures contained in **picture** expected to be decoded.)| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures](_image___native_module.md#oh_decodingoptionsforpicture_setdesiredauxiliarypictures) (OH_DecodingOptionsForPicture \*options, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) \*desiredAuxiliaryPictures, size_t length) | Sets desired auxiliary pictures in the decoding options.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptionsForPicture_Release](_image___native_module.md#oh_decodingoptionsforpicture_release) (OH_DecodingOptionsForPicture \*options) | Releases the pointer to an **OH_DecodingOptionsForPicture** object.| 
