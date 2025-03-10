# IVideoProcessCallback


## 概述

定义声明图像处理回调。

获取在流程完成时、状态已更改时、出错时的回调函数。

**起始版本：** 5.0

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnStatusChanged](#onstatuschanged) ([in] enum SessionStatus status) | 在进程状态更改时调用。 有关报告模式的详细信息，请参阅**[SetResultMode()](interface_i_camera_device_v10.md#setresultmode)。** | 
| [OnProcessDone](#onprocessdone) ([in] String videoId) | 在进程完成时调用。 有关报告模式的详细信息，请参阅**[SetResultMode()](interface_i_camera_device_v10.md#setresultmode)**。 | 
| [OnError](#onerror) ([in] String videoId, [in] enum ErrorCode errorCode) | 在处理会话时发生错误时调用。 | 


## 成员函数说明


### OnError()

```
IVideoProcessCallback::OnError ([in] String videoId, [in] enum ErrorCode errorCode)
```

**描述**

在处理会话时发生错误时调用。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoId | 视频流id。 | 
| ErrorCode | errorCode 错误码，请参阅**[ErrorCode](_camera_v12.md#errorcode)**。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### OnProcessDone()

```
IVideoProcessCallback::OnProcessDone ([in] String videoId)
```

**描述**

在进程完成时调用。 有关报告模式的详细信息，请参阅**[SetResultMode()](interface_i_camera_device_v10.md#setresultmode)**。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoId | 视频流id。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### OnStatusChanged()

```
IVideoProcessCallback::OnStatusChanged ([in] enum SessionStatus status)
```

**描述**

在进程状态更改时调用。 有关报告模式的详细信息，请参阅**[SetResultMode()](interface_i_camera_device_v10.md#setresultmode)**。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 会话的新状态。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。
