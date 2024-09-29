# CaptureStartedInfo


## 概述

定义CaptureStartedInfo，该信息由[IStreamOperatorCallback::OnCaptureStartedV1_2](interface_i_stream_operator_callback_v12.md#oncapturestartedv1_2)使用。

**起始版本：** 4.1

**相关模块：**[Camera](_camera_v12.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [streamId_](#streamid_) | 流的ID，用于在设备内唯一标识一条流。  | 
| int [exposureTime_](#exposuretime_) | 曝光时间，单位为毫秒。  | 


## 类成员变量说明


### exposureTime_

```
int CaptureStartedInfo::exposureTime_
```
**描述**

曝光时间，单位为毫秒。


### streamId_

```
int CaptureStartedInfo::streamId_
```
**描述**

流的ID，用于在设备内唯一标识一条流。
