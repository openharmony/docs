# IImageProcessCallback


## 概述

定义声明图像处理回调。

获取在流程完成时、状态已更改时、出错时的回调函数。

**起始版本：** 4.1

**相关模块：**[Camera](_camera_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnProcessDone](#onprocessdone) ([in] String imageId, [in] [ImageBufferInfo](_image_buffer_info_v12.md) buffer) | 在进程完成时调用。 有关报告模式的详细信息，请参阅 [SetResultMode](interface_i_camera_device_v10.md#setresultmode)。 | 
| [OnStatusChanged](#onstatuschanged) ([in] enum [SessionStatus](_camera_v12.md#sessionstatus) status) | 在进程状态更改时调用。 有关报告模式的详细信息，请参阅 [SetResultMode](interface_i_camera_device_v10.md#setresultmode)。 | 
| [OnError](#onerror) ([in] String imageId, [in] int errorCode) | 闪光灯的最新状态。 | 


## 成员函数说明


### OnError()

```
IImageProcessCallback::OnError ([in] String imageId, [in] int errorCode )
```

**描述**

闪光灯的最新状态。

**起始版本：** 4.1


### OnProcessDone()

```
IImageProcessCallback::OnProcessDone ([in] String imageId, [in] ImageBufferInfo buffer )
```

**描述**

在进程完成时调用。 有关报告模式的详细信息，请参阅 [SetResultMode](interface_i_camera_device_v10.md#setresultmode)。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageId | 镜像ID。 | 
| buffer | 缓冲区。 | 


### OnStatusChanged()

```
IImageProcessCallback::OnStatusChanged ([in] enum SessionStatus status)
```

**描述**

在进程状态更改时调用。 有关报告模式的详细信息，请参阅 [SetResultMode](interface_i_camera_device_v10.md#setresultmode)。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 会话的新状态。 | 
