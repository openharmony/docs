# OH_ImageSourceNative
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the image source, which is encapsulated at the native layer and is used to create image data. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

You can create an OH_ImageSourceNative object in multiple ways, as described below.

| API| Description|
| -------- | -------- |
| [OH_ImageSourceNative_CreateFromUri](capi-image-source-native-h.md#oh_imagesourcenative_createfromuri) |Creates an OH_ImageSourceNative object based on a URI.|
| [OH_ImageSourceNative_CreateFromFd](capi-image-source-native-h.md#oh_imagesourcenative_createfromfd) |Creates an OH_ImageSourceNative object based on a file descriptor.|
| [OH_ImageSourceNative_CreateFromData](capi-image-source-native-h.md#oh_imagesourcenative_createfromdata) |Creates an OH_ImageSourceNative object based on buffer data.|
| [OH_ImageSourceNative_CreateFromRawFile](capi-image-source-native-h.md#oh_imagesourcenative_createfromrawfile) |Creates an OH_ImageSourceNative object by using the raw file descriptor of an image resource file.|
| [OH_ImageSourceNative_CreatePixelmap](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmap) |Creates an OH_PixelmapNative object based on decoding options.|
| [OH_ImageSourceNative_CreatePixelmapList](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmaplist) |Creates an array of OH_PixelmapNative objects based on decoding options.|

To release an OH_ImageSourceNative object, call [OH_ImageSourceNative_Release](capi-image-source-native-h.md#oh_imagesourcenative_release).

The table below describes the content and operation mode of the OH_ImageSourceNative struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| int32_t | delayTimeList | Image delay time list.| [OH_ImageSourceNative_GetDelayTimeList](capi-image-source-native-h.md#oh_imagesourcenative_getdelaytimelist) |Obtains the image delay time list.|
| OH_ImageSource_Info | info | Image source information.| [OH_ImageSourceNative_GetImageInfo](capi-image-source-native-h.md#oh_imagesourcenative_getimageinfo) |Obtains the information about an image with a given index.|
| Image_String | value | Configuration item.| [OH_ImageSourceNative_GetImageProperty](capi-image-source-native-h.md#oh_imagesourcenative_getimageproperty) |Obtains the value of an image property.|
| Image_String | value | Configuration item.| [OH_ImageSourceNative_ModifyImageProperty](capi-image-source-native-h.md#oh_imagesourcenative_modifyimageproperty) |Modifies the value of an image property.|
| uint32_t | frameCount | Number of frames.| [OH_ImageSourceNative_GetFrameCount](capi-image-source-native-h.md#oh_imagesourcenative_getframecount) |Obtains the number of image frames.|

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_source_native.h](capi-image-source-native-h.md)
