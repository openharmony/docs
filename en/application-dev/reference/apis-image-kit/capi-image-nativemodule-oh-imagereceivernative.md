# OH_ImageReceiverNative
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The OH_ImageReceiverNative struct describes the image receiver, which is encapsulated at the native layer. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

To create an OH_ImageReceiverNative object, call [OH_ImageReceiverNative_Create](capi-image-receiver-native-h.md#oh_imagereceivernative_create).

To release an OH_ImageReceiverNative object, call [OH_ImageReceiverNative_Release](capi-image-receiver-native-h.md#oh_imagereceivernative_release).

The table below describes the content and operation mode of the OH_ImageReceiverNative struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint64_t | surfaceId | Surface ID of the receiver.| [OH_ImageReceiverNative_GetReceivingSurfaceId](capi-image-receiver-native-h.md#oh_imagereceivernative_getreceivingsurfaceid) |Obtains the surface ID through an OH_ImageReceiverNative object.|
| OH_ImageNative | image | Image at the native layer.| [OH_ImageReceiverNative_ReadLatestImage](capi-image-receiver-native-h.md#oh_imagereceivernative_readlatestimage) | Obtains the latest image through an OH_ImageReceiverNative object.|
| OH_ImageNative | image | Image at the native layer.| [OH_ImageReceiverNative_ReadNextImage](capi-image-receiver-native-h.md#oh_imagereceivernative_readnextimage) |Obtains the next image through an OH_ImageReceiverNative object.|
| OH_ImageReceiver_OnCallback | callback| Callback function of the image receiver.| [OH_ImageReceiverNative_On](capi-image-receiver-native-h.md#oh_imagereceivernative_on) |Registers an OH_ImageReceiver_OnCallback.|
| OH_ImageReceiver_OnCallback | callback| Callback function of the image receiver.| [OH_ImageReceiverNative_Off](capi-image-receiver-native-h.md#oh_imagereceivernative_off) |Unregisters an OH_ImageReceiver_OnCallback.|
| Image_Size | size | Size of an image receiver.| [OH_ImageReceiverNative_GetSize](capi-image-receiver-native-h.md#oh_imagereceivernative_getsize) |Obtains the size of an OH_ImageReceiverNative.|
|int32_t | capacity| Capacity of an image receiver.| [OH_ImageReceiverNative_GetCapacity](capi-image-receiver-native-h.md#oh_imagereceivernative_getcapacity) |Obtains the capacity of an OH_ImageReceiverNative.|

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_receiver_native.h](capi-image-receiver-native-h.md)
