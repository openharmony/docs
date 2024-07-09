# image_receiver_native.h


## Overview

The **image_receiver_native.h** file declares the APIs used to obtain image data from the native layer.

**Library**: libimage_receiver.so

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Since**: 12

**Related module**: [Image_NativeModule](_image___native_module.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) | Defines the data type name of the image receiver at the native layer. | 
| typedef struct [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) | Defines the data type name of the image receiver options. | 
| typedef void(\* [OH_ImageReceiver_OnCallback](_image___native_module.md#oh_imagereceiver_oncallback)) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver) | Defines the callbacks for the image receiver at the native layer. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverOptions_Create](_image___native_module.md#oh_imagereceiveroptions_create) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*\*options) | Creates an **OH_ImageReceiverOptions** object at the application layer. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverOptions_GetSize](_image___native_module.md#oh_imagereceiveroptions_getsize) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*options, [Image_Size](_image___size.md) \*size) | Obtains the [Image_Size](_image___size.md) information of an [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverOptions_SetSize](_image___native_module.md#oh_imagereceiveroptions_setsize) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*options, [Image_Size](_image___size.md) size) | Sets the [Image_Size](_image___size.md) information for an [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverOptions_GetCapacity](_image___native_module.md#oh_imagereceiveroptions_getcapacity) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*options, int32_t \*capacity) | Obtains the capacity of an [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverOptions_SetCapacity](_image___native_module.md#oh_imagereceiveroptions_setcapacity) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*options, int32_t capacity) | Sets the capacity for an [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverOptions_Release](_image___native_module.md#oh_imagereceiveroptions_release) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*options) | Releases an [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_Create](_image___native_module.md#oh_imagereceivernative_create) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*options, [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*\*receiver) | Creates an **OH_ImageReceiverNative** object at the application layer. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_GetReceivingSurfaceId](_image___native_module.md#oh_imagereceivernative_getreceivingsurfaceid) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver, uint64_t \*surfaceId) | Obtains the receiver ID through an [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_ReadLatestImage](_image___native_module.md#oh_imagereceivernative_readlatestimage) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver, [OH_ImageNative](_image___native_module.md#oh_imagenative) \*\*image) | Obtains the latest image through an [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_ReadNextImage](_image___native_module.md#oh_imagereceivernative_readnextimage) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver, [OH_ImageNative](_image___native_module.md#oh_imagenative) \*\*image) | Obtains the next image through an [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_On](_image___native_module.md#oh_imagereceivernative_on) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver, [OH_ImageReceiver_OnCallback](_image___native_module.md#oh_imagereceiver_oncallback) callback) | Registers a callback, which is an [OH_ImageReceiver_OnCallback](_image___native_module.md#oh_imagereceiver_oncallback) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_Off](_image___native_module.md#oh_imagereceivernative_off) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver) | Unregisters a callback, which is an [OH_ImageReceiver_OnCallback](_image___native_module.md#oh_imagereceiver_oncallback) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_GetSize](_image___native_module.md#oh_imagereceivernative_getsize) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver, [Image_Size](_image___size.md) \*size) | Obtains the size of an image receiver, which is an [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_GetCapacity](_image___native_module.md#oh_imagereceivernative_getcapacity) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver, int32_t \*capacity) | Obtains the capacity of an image receiver, which is an [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) object. | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_Release](_image___native_module.md#oh_imagereceivernative_release) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver) | Releases an [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) object. | 
