# photo_native.h


## 概述

声明相机照片概念。

**库：** libohcamera.so

**引用文件：**&lt;ohcamera/photo_native.h&gt;

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 12

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_PhotoNative](_o_h___camera.md#oh_photonative) [OH_PhotoNative](_o_h___camera.md#oh_photonative) | 相机照片对象。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoNative_GetMainImage](_o_h___camera.md#oh_photonative_getmainimage) ([OH_PhotoNative](_o_h___camera.md#oh_photonative) \*photo, OH_ImageNative \*\*mainImage) | 获取全质量图。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoNative_Release](_o_h___camera.md#oh_photonative_release) ([OH_PhotoNative](_o_h___camera.md#oh_photonative) \*photo) | 释放全质量图实例。 | 
