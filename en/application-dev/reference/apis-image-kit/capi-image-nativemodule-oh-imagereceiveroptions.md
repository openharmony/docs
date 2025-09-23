# OH_ImageReceiverOptions
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the data type name of the image receiver options.

OH_ImageReceiverOptions is the image receiver option setter struct encapsulated at the native layer. It is used to pass parameters during the creation of an OH_ImageReceiverNative object. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

To create an OH_ImageReceiverOptions object, call [OH_ImageReceiverOptions_Create](capi-image-receiver-native-h.md#oh_imagereceiveroptions_create).

To release an OH_ImageReceiverOptions object, call [OH_ImageReceiverOptions_Release](capi-image-receiver-native-h.md#oh_imagereceiveroptions_release).

The table below describes the content and operation mode of the OH_ImageReceiverOptions struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| Image_Size | size | Image size.| [OH_ImageReceiverOptions_GetSize](capi-image-receiver-native-h.md#oh_imagereceiveroptions_getsize) |Obtains the image size of an OH_ImageReceiverOptions object.|
| Image_Size | size | Image size.| [OH_ImageReceiverOptions_SetSize](capi-image-receiver-native-h.md#oh_imagereceiveroptions_setsize) |Sets the image size for an OH_ImageReceiverOptions object.|
| int32_t | capacity | Capacity of the image buffer.| [OH_ImageReceiverOptions_GetCapacity](capi-image-receiver-native-h.md#oh_imagereceiveroptions_getcapacity) |Obtains the capacity of an OH_ImageReceiverOptions object.|
| int32_t | capacity | Capacity of the image buffer.| [OH_ImageReceiverOptions_SetCapacity](capi-image-receiver-native-h.md#oh_imagereceiveroptions_setcapacity) |Sets the capacity for an OH_ImageReceiverOptions object.|

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_receiver_native.h](capi-image-receiver-native-h.md)
