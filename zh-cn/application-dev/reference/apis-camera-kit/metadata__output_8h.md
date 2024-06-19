# metadata_output.h


## 概述

声明元数据输出概念。

**库：** libohcamera.so

**引用文件：**&lt;ohcamera/metadata_output.h&gt;

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[MetadataOutput_Callbacks](_metadata_output___callbacks.md) | 元数据输出的回调。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) [Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) | 元数据输出对象  | 
| typedef void(\* [OH_MetadataOutput_OnMetadataObjectAvailable](_o_h___camera.md#oh_metadataoutput_onmetadataobjectavailable)) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput, [Camera_MetadataObject](_camera___metadata_object.md) \*metadataObject, uint32_t size) | 在[MetadataOutput_Callbacks](_metadata_output___callbacks.md)中被调用的元数据输出元数据对象可用回调。  | 
| typedef void(\* [OH_MetadataOutput_OnError](_o_h___camera.md#oh_metadataoutput_onerror)) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | 在[MetadataOutput_Callbacks](_metadata_output___callbacks.md)中被调用的元数据输出错误回调。  | 
| typedef struct [MetadataOutput_Callbacks](_metadata_output___callbacks.md) [MetadataOutput_Callbacks](_o_h___camera.md#metadataoutput_callbacks) | 元数据输出的回调。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_MetadataOutput_RegisterCallback](_o_h___camera.md#oh_metadataoutput_registercallback) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput, [MetadataOutput_Callbacks](_metadata_output___callbacks.md) \*callback) | 注册元数据输出更改事件回调。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_MetadataOutput_UnregisterCallback](_o_h___camera.md#oh_metadataoutput_unregistercallback) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput, [MetadataOutput_Callbacks](_metadata_output___callbacks.md) \*callback) | 注销元数据输出更改事件回调。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_MetadataOutput_Start](_o_h___camera.md#oh_metadataoutput_start) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput) | 启动元数据输出。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_MetadataOutput_Stop](_o_h___camera.md#oh_metadataoutput_stop) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput) | 停止元数据输出。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_MetadataOutput_Release](_o_h___camera.md#oh_metadataoutput_release) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput) | 释放元数据输出。  | 
