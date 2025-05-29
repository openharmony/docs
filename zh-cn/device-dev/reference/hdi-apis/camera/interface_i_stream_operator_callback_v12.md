# IStreamOperatorCallback


## 概述

定义Camera设备流回调操作。

对Camera设备执行流回调的抓捕，结束，错误捕获和帧捕获等操作。

**起始版本：** 4.1

**相关模块：**[Camera](_camera_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnCaptureStartedV1_2](#oncapturestartedv1_2) ([in] int captureId, [in] struct [CaptureStartedInfo](_capture_started_info_v12.md)[] infos) | 在捕获开始时调用。  | 


## 成员函数说明


### OnCaptureStartedV1_2()

```
IStreamOperatorCallback::OnCaptureStartedV1_2 ([in] int captureId, [in] struct CaptureStartedInfo[] infos)
```
**描述**

在捕获开始时调用。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| captureId | 回调对应的捕获请求ID。  | 
| infos | 捕获开始消息的列表。 | 
