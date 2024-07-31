# image_receiver_mdk.h


## 概述

声明从native层获取图片数据的方法。

**库**：libimage_receiver_ndk.z.so

**引用文件**：&lt;multimedia/image_framework/image_receiver_mdk.h&gt;

**起始版本：** 10

**相关模块：** [Image](image.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OhosImageReceiverInfo](_ohos_image_receiver_info.md) | 定义**ImageReceiver**的相关信息。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct ImageReceiverNative_ [ImageReceiverNative](image.md#imagereceivernative) | 用于定义ImageReceiverNative数据类型名称。  | 
| typedef void(\* [OH_Image_Receiver_On_Callback](image.md#oh_image_receiver_on_callback)) () | 定义native层图片的回调方法。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_Image_Receiver_CreateImageReceiver](image.md#oh_image_receiver_createimagereceiver) (napi_env env, struct [OhosImageReceiverInfo](_ohos_image_receiver_info.md) info, napi_value \*res) | 创建应用层 **ImageReceiver** 对象。  | 
| [ImageReceiverNative](image.md#imagereceivernative) \* [OH_Image_Receiver_InitImageReceiverNative](image.md#oh_image_receiver_initimagereceivernative) (napi_env env, napi_value source) | 通过应用层**ImageReceiver**对象初始化native层[ImageReceiverNative](image.md#imagereceivernative)对象。  | 
| int32_t [OH_Image_Receiver_GetReceivingSurfaceId](image.md#oh_image_receiver_getreceivingsurfaceid) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, char \*id, size_t len) | 通过[ImageReceiverNative](image.md#imagereceivernative)获取receiver的id。  | 
| int32_t [OH_Image_Receiver_ReadLatestImage](image.md#oh_image_receiver_readlatestimage) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, napi_value \*image) | 通过[ImageReceiverNative](image.md#imagereceivernative)获取最新的一张图片。  | 
| int32_t [OH_Image_Receiver_ReadNextImage](image.md#oh_image_receiver_readnextimage) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, napi_value \*image) | 通过[ImageReceiverNative](image.md#imagereceivernative)获取下一张图片。  | 
| int32_t [OH_Image_Receiver_On](image.md#oh_image_receiver_on) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, [OH_Image_Receiver_On_Callback](image.md#oh_image_receiver_on_callback) callback) | 注册一个[OH_Image_Receiver_On_Callback](image.md#oh_image_receiver_on_callback)回调事件。每当接收新图片，该回调事件就会响应。  | 
| int32_t [OH_Image_Receiver_GetSize](image.md#oh_image_receiver_getsize) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, struct [OhosImageSize](_ohos_image_size.md) \*size) | 通过[ImageReceiverNative](image.md#imagereceivernative)获取**ImageReceiver**的大小。  | 
| int32_t [OH_Image_Receiver_GetCapacity](image.md#oh_image_receiver_getcapacity) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, int32_t \*capacity) | 通过[ImageReceiverNative](image.md#imagereceivernative)获取**ImageReceiver**的容量。  | 
| int32_t [OH_Image_Receiver_GetFormat](image.md#oh_image_receiver_getformat) (const [ImageReceiverNative](image.md#imagereceivernative) \*native, int32_t \*format) | 通过[ImageReceiverNative](image.md#imagereceivernative)获取**ImageReceiver**的格式。  | 
| int32_t [OH_Image_Receiver_Release](image.md#oh_image_receiver_release) ([ImageReceiverNative](image.md#imagereceivernative) \*native) | 释放native层 [ImageReceiverNative](image.md#imagereceivernative) 对象。  | 
