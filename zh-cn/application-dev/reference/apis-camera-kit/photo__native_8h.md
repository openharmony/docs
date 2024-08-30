# photo__native.h


## 概述

声明全质量图对象概念。

**库：** libohcamera.so

**引用文件：**&lt;ohcamera/photo_native.h&gt;

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 12

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| struct  [OH_PhotoNative](_o_h___photonative.md) | 全质量图对象的回调。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoNative_GetMainImage](_o_h___camera.md#oh_photonative_getmainimage) ([OH_PhotoNative](_o_h___camera.md#oh_photonative)\* photo, [OH_ImageNative](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-image-kit/_image___native_module.md#oh_imagenative)\** mainImage) | 获取主图。 |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoNative_Release](_o_h___camera.md#oh_photonative_release) ([OH_PhotoNative](_o_h___camera.md#oh_photonative)\* photo) | 释放输出资源。 |
