# OH_DecodingOptions
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## Overview

The OH_DecodingOptions struct describes the decoding options encapsulated at the native layer. The struct is used to set decoding options and is passed in as an input parameter for creating a PixelMap. For details, see [OH_ImageSourceNative_CreatePixelmap](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmap).

The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

To create an OH_DecodingOptions object, call [OH_DecodingOptions_Create](capi-image-source-native-h.md#oh_decodingoptions_create).

To release an OH_DecodingOptions object, call [OH_DecodingOptions_Release](capi-image-source-native-h.md#oh_decodingoptions_release).

The table below describes the content and operation mode of the OH_DecodingOptions struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| int32_t | pixelFormat | Pixel format.| [OH_DecodingOptions_GetPixelFormat](capi-image-source-native-h.md#oh_decodingoptions_getpixelformat) |Obtains the pixel format.|
| int32_t | pixelFormat | Pixel format.| [OH_DecodingOptions_SetPixelFormat](capi-image-source-native-h.md#oh_decodingoptions_setpixelformat) | Sets the pixel format.|
| uint32_t | index | Index of the image to decode.| [OH_DecodingOptions_GetIndex](capi-image-source-native-h.md#oh_decodingoptions_getindex) | Obtains the index of an image.|
| uint32_t | index | Index of the image to decode.| [OH_DecodingOptions_SetIndex](capi-image-source-native-h.md#oh_decodingoptions_setindex) | Sets the index for an image.|
| float | rotate | Rotation angle.| [OH_DecodingOptions_GetRotate](capi-image-source-native-h.md#oh_decodingoptions_getrotate) | Obtains the rotation degree.|
| float | rotate | Rotation angle.| [OH_DecodingOptions_SetRotate](capi-image-source-native-h.md#oh_decodingoptions_setrotate) | Sets the rotation angle.|
| Image_Size | desiredSize | Desired output size.| [OH_DecodingOptions_GetDesiredSize](capi-image-source-native-h.md#oh_decodingoptions_getdesiredsize) | Obtains the desired output size.|
| Image_Size | desiredSize | Desired output size.| [OH_DecodingOptions_SetDesiredSize](capi-image-source-native-h.md#oh_decodingoptions_setdesiredsize) | Sets the desired output size.|
| Image_Region | desiredRegion | Region to decode.| [OH_DecodingOptions_GetDesiredRegion](capi-image-source-native-h.md#oh_decodingoptions_getdesiredregion) | Obtains the region to decode.|
| Image_Region | desiredRegion | Region to decode.| [OH_DecodingOptions_SetDesiredRegion](capi-image-source-native-h.md#oh_decodingoptions_setdesiredregion) | Sets the region to decode.|
| int32_t | desiredDynamicRange | Desired dynamic range.| [OH_DecodingOptions_GetDesiredDynamicRange](capi-image-source-native-h.md#oh_decodingoptions_getdesireddynamicrange) |Obtains the desired dynamic range configured during decoding.|
| int32_t | desiredDynamicRange | Desired dynamic range.| [OH_DecodingOptions_SetDesiredDynamicRange](capi-image-source-native-h.md#oh_decodingoptions_setdesireddynamicrange)|Sets the desired dynamic range during decoding.|

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_source_native.h](capi-image-source-native-h.md)
