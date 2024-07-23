# pixelmap_native.h


## Overview

The **pixelmap_native.h** file declares the APIs for accessing a pixel map.

**Library**: libpixelmap.so

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 12

**Related module**: [Image_NativeModule](_image___native_module.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) | Defines the **Pixelmap** struct, which is used to perform operations related to a pixel map.| 
| typedef struct [OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) [OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) | Defines a struct for the initialization parameters.| 
| typedef struct [OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) [OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) | Defines a struct for the image information.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [PIXELMAP_ALPHA_TYPE](_image___native_module.md#pixelmap_alpha_type) {<br>PIXELMAP_ALPHA_TYPE_UNKNOWN = 0,<br>PIXELMAP_ALPHA_TYPE_OPAQUE = 1,<br>PIXELMAP_ALPHA_TYPE_PREMULTIPLIED = 2 } | Enumerates the alpha types of a pixel map.| 
| [PIXEL_FORMAT](_image___native_module.md#pixel_format) {<br>PIXEL_FORMAT_UNKNOWN = 0, PIXEL_FORMAT_RGB_565 = 2,<br>PIXEL_FORMAT_RGBA_8888 = 3, PIXEL_FORMAT_BGRA_8888 = 4,<br>PIXEL_FORMAT_RGB_888 = 5, PIXEL_FORMAT_ALPHA_8 = 6,<br>PIXEL_FORMAT_RGBA_F16 = 7, PIXEL_FORMAT_NV21 = 8,<br>PIXEL_FORMAT_NV12 = 9<br>} | Enumerates the image pixel formats.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_Create](_image___native_module.md#oh_pixelmapinitializationoptions_create) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*\*options) | Creates the pointer to an **OH_Pixelmap_InitializationOptions** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetWidth](_image___native_module.md#oh_pixelmapinitializationoptions_getwidth) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, uint32_t \*width) | Obtains the image width.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetWidth](_image___native_module.md#oh_pixelmapinitializationoptions_setwidth) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, uint32_t width) | Sets the image width.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetHeight](_image___native_module.md#oh_pixelmapinitializationoptions_getheight) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, uint32_t \*height) | Obtains the image height.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetHeight](_image___native_module.md#oh_pixelmapinitializationoptions_setheight) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, uint32_t height) | Sets the image height.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetPixelFormat](_image___native_module.md#oh_pixelmapinitializationoptions_getpixelformat) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t \*pixelFormat) | Obtains the pixel format.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetPixelFormat](_image___native_module.md#oh_pixelmapinitializationoptions_setpixelformat) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t pixelFormat) | Sets the pixel format.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetAlphaType](_image___native_module.md#oh_pixelmapinitializationoptions_getalphatype) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t \*alphaType) | Obtains the alpha type.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetAlphaType](_image___native_module.md#oh_pixelmapinitializationoptions_setalphatype) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t alphaType) | Sets the alpha type.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_Release](_image___native_module.md#oh_pixelmapinitializationoptions_release) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options) | Releases the pointer to an **OH_Pixelmap_InitializationOptions** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_Create](_image___native_module.md#oh_pixelmapimageinfo_create) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*\*info) | Creates the pointer to an **OH_Pixelmap_ImageInfo** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetWidth](_image___native_module.md#oh_pixelmapimageinfo_getwidth) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, uint32_t \*width) | Obtains the image width.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetHeight](_image___native_module.md#oh_pixelmapimageinfo_getheight) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, uint32_t \*height) | Obtains the image height.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetRowStride](_image___native_module.md#oh_pixelmapimageinfo_getrowstride) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, uint32_t \*rowStride) | Obtains the row stride.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetPixelFormat](_image___native_module.md#oh_pixelmapimageinfo_getpixelformat) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, int32_t \*pixelFormat) | Obtains the pixel format.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetAlphaType](_image___native_module.md#oh_pixelmapimageinfo_getalphatype) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, int32_t \*alphaType) | Obtains the alpha type.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetDynamicRange](_image___native_module.md#oh_pixelmapimageinfo_getdynamicrange) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, bool \*isHdr) | Obtains the dynamic range of a pixel map.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_Release](_image___native_module.md#oh_pixelmapimageinfo_release) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info) | Releases the pointer to an **OH_Pixelmap_ImageInfo** object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_CreatePixelmap](_image___native_module.md#oh_pixelmapnative_createpixelmap) (uint8_t \*data, size_t dataLength, [OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*\*pixelmap) | Creates a **PixelMap** object based on properties. By default, the BGRA_8888 format is used for data processing.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_ReadPixels](_image___native_module.md#oh_pixelmapnative_readpixels) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, uint8_t \*destination, size_t \*bufferSize) | Reads the image pixel data and writes the data to an ArrayBuffer.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_WritePixels](_image___native_module.md#oh_pixelmapnative_writepixels) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, uint8_t \*source, size_t bufferSize) | Reads the image pixel data in the buffer and writes the data to a pixel map.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_GetImageInfo](_image___native_module.md#oh_pixelmapnative_getimageinfo) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, [OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*imageInfo) | Obtains the image information.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Opacity](_image___native_module.md#oh_pixelmapnative_opacity) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float rate) | Sets the opacity ratio to enable the pixel map to achieve the corresponding opacity effect.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Scale](_image___native_module.md#oh_pixelmapnative_scale) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float scaleX, float scaleY) | Scales an image based on a given width and height.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Translate](_image___native_module.md#oh_pixelmapnative_translate) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float x, float y) | Translates an image based on given coordinates.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Rotate](_image___native_module.md#oh_pixelmapnative_rotate) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float angle) | Rotates an image based on a given angle.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Flip](_image___native_module.md#oh_pixelmapnative_flip) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, bool shouldFilpHorizontally, bool shouldFilpVertically) | Flips an image based on a given angle.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Crop](_image___native_module.md#oh_pixelmapnative_crop) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, [Image_Region](_image___region.md) \*region) | Crops an image based on a given size.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Release](_image___native_module.md#oh_pixelmapnative_release) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap) | Releases the pointer to an **OH_PixelmapNative** object.| 
