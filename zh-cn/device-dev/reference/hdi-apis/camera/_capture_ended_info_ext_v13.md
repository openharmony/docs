# CaptureEndedInfoExt


## 概述

拍照结束信息，使用于[IStreamOperatorCallback::OnCaptureEndedExt](interface_i_stream_operator_callback_v13.md#oncaptureendedext)。

**起始版本：** 5.0

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int [streamId_](#streamid_) | 流id。  | 
| int [frameCount_](#framecount_) | 帧数。  | 
| boolean [isDeferredVideoEnhancementAvailable_](#isdeferredvideoenhancementavailable_) | 是否使能二阶段视频增强处理。  | 
| String [videoId_](#videoid_) | 视频id。  | 


## 结构体成员变量说明


### frameCount_

```
int CaptureEndedInfoExt::frameCount_
```
**描述**

帧数。

**起始版本：** 5.0


### isDeferredVideoEnhancementAvailable_

```
boolean CaptureEndedInfoExt::isDeferredVideoEnhancementAvailable_
```
**描述**

是否使能二阶段视频增强处理。

**起始版本：** 5.0


### streamId_

```
int CaptureEndedInfoExt::streamId_
```
**描述**

流id。

**起始版本：** 5.0


### videoId_

```
String CaptureEndedInfoExt::videoId_
```
**描述**

视频id。

**起始版本：** 5.0
