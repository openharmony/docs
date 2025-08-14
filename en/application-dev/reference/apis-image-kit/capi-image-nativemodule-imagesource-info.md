# OH_ImageSource_Info
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## Overview

The OH_ImageSource_Info struct describes the image source information encapsulated at the native layer. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

To create an OH_ImageSource_Info object, call [OH_ImageSourceInfo_Create](capi-image-source-native-h.md#oh_imagesourceinfo_create).

To release an OH_ImageSource_Info object, call [OH_ImageSourceInfo_Release](capi-image-source-native-h.md#oh_imagesourceinfo_release).

The table below describes the content and operation mode of the OH_ImageSource_Info struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | Image width.| [OH_ImageSourceInfo_GetWidth](capi-image-source-native-h.md#oh_imagesourceinfo_getwidth) |Obtains the image width.|
| uint32_t | height | Image height.| [OH_ImageSourceInfo_GetHeight](capi-image-source-native-h.md#oh_imagesourceinfo_getheight) |Obtains the image height.|
| bool | isHdr | Dynamic range.| [OH_ImageSourceInfo_GetDynamicRange](capi-image-source-native-h.md#oh_imagesourceinfo_getdynamicrange) |Obtains the dynamic range of an image.|

**Since**: 13

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_source_native.h](capi-image-source-native-h.md)
