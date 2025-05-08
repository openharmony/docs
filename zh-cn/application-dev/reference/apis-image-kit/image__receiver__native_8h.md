# image_receiver_native.h


## 概述

声明从native层获取图片数据的方法。

**库：** libimage_receiver.so

**引用文件**：&lt;multimedia/image_framework/image/image_receiver_native.h&gt;

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**起始版本：** 12

**相关模块：**[Image_NativeModule](_image___native_module.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) | 用于定义OH_ImageReceiverNative数据类型名称。  | 
| typedef struct [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) | 用于定义OH_ImageReceiverOptions数据类型名称。  | 
| typedef void(\* [OH_ImageReceiver_OnCallback](_image___native_module.md#oh_imagereceiver_oncallback)) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver) | 定义native层图片的回调方法。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverOptions_Create](_image___native_module.md#oh_imagereceiveroptions_create) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*\*options) | 创建应用层 [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) 对象。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverOptions_GetSize](_image___native_module.md#oh_imagereceiveroptions_getsize) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*options, [Image_Size](_image___size.md) \*size) | 获取 [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) 对象的 [Image_Size](_image___size.md) 信息。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverOptions_SetSize](_image___native_module.md#oh_imagereceiveroptions_setsize) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*options, [Image_Size](_image___size.md) size) | 设置 [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) 对象的 [Image_Size](_image___size.md) 信息。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverOptions_GetCapacity](_image___native_module.md#oh_imagereceiveroptions_getcapacity) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*options, int32_t \*capacity) | 获取 [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) 对象的图片缓存容量的信息。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverOptions_SetCapacity](_image___native_module.md#oh_imagereceiveroptions_setcapacity) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*options, int32_t capacity) | 设置 [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) 对象的图片缓存容量的信息。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverOptions_Release](_image___native_module.md#oh_imagereceiveroptions_release) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*options) | 释放 [OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) 对象。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_Create](_image___native_module.md#oh_imagereceivernative_create) ([OH_ImageReceiverOptions](_image___native_module.md#oh_imagereceiveroptions) \*options, [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*\*receiver) | 创建应用层 [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) 对象。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_GetReceivingSurfaceId](_image___native_module.md#oh_imagereceivernative_getreceivingsurfaceid) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver, uint64_t \*surfaceId) | 通过  [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) 获取SurfaceId。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_ReadLatestImage](_image___native_module.md#oh_imagereceivernative_readlatestimage) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver, [OH_ImageNative](_image___native_module.md#oh_imagenative) \*\*image) | 通过 [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) 获取最新的一张图片。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_ReadNextImage](_image___native_module.md#oh_imagereceivernative_readnextimage) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver, [OH_ImageNative](_image___native_module.md#oh_imagenative) \*\*image) | 通过 [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) 获取下一张图片。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_On](_image___native_module.md#oh_imagereceivernative_on) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver, [OH_ImageReceiver_OnCallback](_image___native_module.md#oh_imagereceiver_oncallback) callback) | 注册一个 [OH_ImageReceiver_OnCallback](_image___native_module.md#oh_imagereceiver_oncallback) 回调事件。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_Off](_image___native_module.md#oh_imagereceivernative_off) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver) | 关闭 [OH_ImageReceiver_OnCallback](_image___native_module.md#oh_imagereceiver_oncallback) 回调事件。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_GetSize](_image___native_module.md#oh_imagereceivernative_getsize) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver, [Image_Size](_image___size.md) \*size) | 通过 [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) 获取ImageReceiver的大小。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_GetCapacity](_image___native_module.md#oh_imagereceivernative_getcapacity) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver, int32_t \*capacity) | 通过 [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) 获取ImageReceiver的容量。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageReceiverNative_Release](_image___native_module.md#oh_imagereceivernative_release) ([OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) \*receiver) | 释放native [OH_ImageReceiverNative](_image___native_module.md#oh_imagereceivernative) 对象。  | 
