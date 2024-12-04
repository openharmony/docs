# image_native.h


## Overview

The **image_native.h** file declares the cropping rectangle, size, and component data of an image.

**Library**: libohimage.so

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 12

**Related module**: [Image_NativeModule](_image___native_module.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_ImageNative](_image___native_module.md#oh_imagenative) [OH_ImageNative](_image___native_module.md#oh_imagenative) | Defines the alias for an image object at the native layer. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetImageSize](_image___native_module.md#oh_imagenative_getimagesize) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, [Image_Size](_image___size.md) \*size) | Obtains the [Image_Size](_image___size.md) information of an [OH_ImageNative](_image___native_module.md#oh_imagenative) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetComponentTypes](_image___native_module.md#oh_imagenative_getcomponenttypes) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, uint32_t \*\*types, size_t \*typeSize) | Obtains the component types of an [OH_ImageNative](_image___native_module.md#oh_imagenative) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetByteBuffer](_image___native_module.md#oh_imagenative_getbytebuffer) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, uint32_t componentType, OH_NativeBuffer \*\*nativeBuffer) | Obtains the buffer corresponding to a component type in an [OH_ImageNative](_image___native_module.md#oh_imagenative) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetBufferSize](_image___native_module.md#oh_imagenative_getbuffersize) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, uint32_t componentType, size_t \*size) | Obtains the size of the buffer corresponding to a component type in an [OH_ImageNative](_image___native_module.md#oh_imagenative) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetRowStride](_image___native_module.md#oh_imagenative_getrowstride) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, uint32_t componentType, int32_t \*rowStride) | Obtains the row stride corresponding to a component type in an [OH_ImageNative](_image___native_module.md#oh_imagenative) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetPixelStride](_image___native_module.md#oh_imagenative_getpixelstride) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, uint32_t componentType, int32_t \*pixelStride) | Obtains the pixel stride corresponding to a component type in an [OH_ImageNative](_image___native_module.md#oh_imagenative) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetTimestamp](_image___native_module.md#oh_imagenative_gettimestamp) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, int64_t \*timestamp) | Obtains the timestamp of an [OH_ImageNative](_image___native_module.md#oh_imagenative) object.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_Release](_image___native_module.md#oh_imagenative_release) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image) | Releases an [OH_ImageNative](_image___native_module.md#oh_imagenative) object. | 
