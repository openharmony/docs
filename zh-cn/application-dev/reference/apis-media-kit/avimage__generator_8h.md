# avimage_generator.h


## 概述

定义AVImageGenerator接口。使用AVImageGenerator提供的Native API从视频资源中获取指定时间视频帧。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**库：** libavimage_generator.so

**起始版本：** 18

**相关模块：**[AVImageGenerator](_a_v_image_generator.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVImageGenerator](_a_v_image_generator.md#oh_avimagegenerator) [OH_AVImageGenerator](_a_v_image_generator.md#oh_avimagegenerator) | 定义OH_AVImageGenerator类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVImageGenerator](_a_v_image_generator.md#oh_avimagegenerator) \* [OH_AVImageGenerator_Create](_a_v_image_generator.md#oh_avimagegenerator_create) (void) | 创建OH_AVImageGenerator实例。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVImageGenerator_SetFDSource](_a_v_image_generator.md#oh_avimagegenerator_setfdsource) ([OH_AVImageGenerator](_a_v_image_generator.md#oh_avimagegenerator) \*generator, int32_t fd, int64_t offset, int64_t size) | 通过媒体文件描述设置数据源。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVImageGenerator_FetchFrameByTime](_a_v_image_generator.md#oh_avimagegenerator_fetchframebytime) ([OH_AVImageGenerator](_a_v_image_generator.md#oh_avimagegenerator) \*generator, int64_t timeUs, [OH_AVImageGenerator_QueryOptions](_a_v_image_generator.md#oh_avimagegenerator_queryoptions) options, OH_PixelmapNative \*\*pixelMap) | 从视频资源中获取特定时间的视频帧。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVImageGenerator_Release](_a_v_image_generator.md#oh_avimagegenerator_release) ([OH_AVImageGenerator](_a_v_image_generator.md#oh_avimagegenerator) \*generator) | 释放用于OH_AVImageGenerator的资源以及销毁OH_AVImageGenerator对象。  | 
