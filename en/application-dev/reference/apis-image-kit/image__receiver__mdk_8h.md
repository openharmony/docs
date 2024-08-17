# image_receiver_mdk.h


## Overview

The **image_receiver_mdk.h** file declares the APIs used to obtain image data from the native layer.

**Library**: libimage_receiver_ndk.z.so

**File to include**: &lt;multimedia/image_framework/image_receiver_mdk.h&gt;

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OhosImageReceiverInfo](_ohos_image_receiver_info.md) | Defines the information about an image receiver. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct ImageReceiverNative_ [ImageReceiverNative](image.md#imagereceivernative) | Defines the data type name of the image receiver at the native layer. | 
| typedef void(\* [OH_Image_Receiver_On_Callback](image.md#oh_image_receiver_on_callback)) () | Defines the callbacks for the image interface at the native layer. | 


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_Image_Receiver_CreateImageReceiver](image.md#oh_image_receiver_createimagereceiver) (napi_env env, struct [OhosImageReceiverInfo](_ohos_image_receiver_info.md) info, napi_value \*res) | Creates an **ImageReceiver** object at the application layer. | 
| [ImageReceiverNative](image.md#imagereceivernative) \* [OH_Image_Receiver_InitImageReceiverNative](image.md#oh_image_receiver_initimagereceivernative) (napi_env env, napi_value source) | Initializes an [ImageReceiverNative](image.md#imagereceivernative) object through an **ImageReceiver** object. | 
| int32_t [OH_Image_Receiver_GetReceivingSurfaceId](image.md#oh_image_receiver_getreceivingsurfaceid) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, char \*id, size_t len) | Obtains the receiver ID through an [ImageReceiverNative](image.md#imagereceivernative) object. | 
| int32_t [OH_Image_Receiver_ReadLatestImage](image.md#oh_image_receiver_readlatestimage) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, napi_value \*image) | Obtains the latest image through an [ImageReceiverNative](image.md#imagereceivernative) object. | 
| int32_t [OH_Image_Receiver_ReadNextImage](image.md#oh_image_receiver_readnextimage) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, napi_value \*image) | Obtains the next image through an [ImageReceiverNative](image.md#imagereceivernative) object. | 
| int32_t [OH_Image_Receiver_On](image.md#oh_image_receiver_on) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, [OH_Image_Receiver_On_Callback](image.md#oh_image_receiver_on_callback) callback) | Registers an [OH_Image_Receiver_On_Callback](image.md#oh_image_receiver_on_callback) callback. This callback is triggered whenever a new image is received. | 
| int32_t [OH_Image_Receiver_GetSize](image.md#oh_image_receiver_getsize) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, struct [OhosImageSize](_ohos_image_size.md) \*size) | Obtains the size of the image receiver through an [ImageReceiverNative](image.md#imagereceivernative) object. | 
| int32_t [OH_Image_Receiver_GetCapacity](image.md#oh_image_receiver_getcapacity) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, int32_t \*capacity) | Obtains the capacity of the image receiver through an [ImageReceiverNative](image.md#imagereceivernative) object. | 
| int32_t [OH_Image_Receiver_GetFormat](image.md#oh_image_receiver_getformat) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, int32_t \*format) | Obtains the format of the image receiver through an [ImageReceiverNative](image.md#imagereceivernative) object. | 
| int32_t [OH_Image_Receiver_Release](image.md#oh_image_receiver_release) ([ImageReceiverNative](image.md#imagereceivernative) \*native) | Releases an [ImageReceiverNative](image.md#imagereceivernative) object. | 
