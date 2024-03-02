# CaptureEndedInfo


## 概述

捕获结束相关信息，用于捕获结束回调[OnCaptureEnded](interface_i_stream_operator_callback_v10.md#oncaptureended)。

**起始版本：** 3.2

**相关模块：**[Camera](_camera_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [streamId_](#streamid_) | 捕获的流ID。 | 
| int [frameCount_](#framecount_) | 捕获结束时已经抓取的帧数。 | 


## 类成员变量说明


### frameCount_

```
int CaptureEndedInfo::frameCount_
```

**描述**

捕获结束时已经抓取的帧数。


### streamId_

```
int CaptureEndedInfo::streamId_
```

**描述**

捕获的流ID。
