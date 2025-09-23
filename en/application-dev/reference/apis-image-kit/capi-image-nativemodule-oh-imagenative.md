# OH_ImageNative
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the alias for an image object at the native layer.

The struct cannot be directly operated. Instead, its fields must be operated by calling functions. The table below describes the content and operation mode of the OH_ImageNative struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| Image_Size| imageSize | Image size.|[OH_ImageNative_GetImageSize](capi-image-native-h.md#oh_imagenative_getimagesize) | Obtains the image size of an OH_ImageNative object.|
| uint32_t | types |Component type, which is used to describe the image's color component.|[OH_ImageNative_GetComponentTypes](capi-image-native-h.md#oh_imagenative_getcomponenttypes) | Obtains the component types of an OH_ImageNative object.|
| OH_NativeBuffer | nativeBuffer | Component buffer.|[OH_ImageNative_GetByteBuffer](capi-image-native-h.md#oh_imagenative_getbytebuffer) | Obtains the buffer corresponding to a component type in an OH_ImageNative object.|
| size_t | bufferSize | Buffer size.| [OH_ImageNative_GetBufferSize](capi-image-native-h.md#oh_imagenative_getbuffersize) | Obtains the size of the buffer corresponding to a component type in an OH_ImageNative object.|
| int32_t | rowStride | Row stride.| [OH_ImageNative_GetRowStride](capi-image-native-h.md#oh_imagenative_getrowstride) | Obtains the row stride corresponding to a component type in an OH_ImageNative object.|
| int32_t | pixelStride | Pixel stride.| [OH_ImageNative_GetPixelStride](capi-image-native-h.md#oh_imagenative_getpixelstride) | Obtains the pixel stride corresponding to a component type in an OH_ImageNative object.|

To release an OH_ImageNative object, call [OH_ImageNative_Release](capi-image-native-h.md#oh_imagenative_release).

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_native.h](capi-image-native-h.md)
