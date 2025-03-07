# IStreamOperatorCallback


## 概述

定义Camera设备流回调操作。

对Camera设备执行流回调的抓捕，结束，错误捕获和帧捕获等操作。

**起始版本：** 5.0

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnCaptureReady](#oncaptureready) ([in] int captureId, [in] int[] streamIds, [in] unsigned long timestamp) | 下次拍照准备就绪时调用。 | 
| [OnFrameShutterEnd](#onframeshutterend) ([in] int captureId, [in] int[] streamIds, [in] unsigned long timestamp) | 当前帧捕获结束时调用。 | 
| [OnCaptureEndedExt](#oncaptureendedext) ([in] int captureId, [in] struct [CaptureEndedInfoExt](_capture_ended_info_ext_v13.md)[] infos) | 当拍照结束时调用。 | 
| [OnResult](#onresult) ([in] int streamId, [in] unsigned char[] result) | 上报stream相关的metadata等信息的回调，上报方式查看**[SetResultMode()](interface_i_camera_device_v10.md#setresultmode)**。 | 


## 成员函数说明


### OnCaptureEndedExt()

```
IStreamOperatorCallback::OnCaptureEndedExt ([in] int captureId, [in] struct CaptureEndedInfoExt[] infos)
```

**描述**

当拍照结束时调用。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| captureId | 用于标识回调对应的捕获请求。 | 
| infos | 捕获结束相关信息，具体结束相关信息查看[CaptureEndedInfoExt](_capture_ended_info_ext_v13.md)。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### OnCaptureReady()

```
IStreamOperatorCallback::OnCaptureReady ([in] int captureId, [in] int[] streamIds, [in] unsigned long timestamp)
```

**描述**

下次拍照准备就绪时调用。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| captureId | 回调对应的捕获请求ID。 | 
| streamIds | 回调对应的捕获流ids。 \@Param timestamp 回调对应的时间戳。 | 
| timestamp | 回调对应的时间戳。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### OnFrameShutterEnd()

```
IStreamOperatorCallback::OnFrameShutterEnd ([in] int captureId, [in] int[] streamIds, [in] unsigned long timestamp)
```

**描述**

当前帧捕获结束时调用。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| captureId | 回调对应的捕获请求ID。 | 
| streamIds | 回调对应的捕获流ids。 \@Param timestamp 回调对应的时间戳。 | 
| timestamp | 回调对应的时间戳。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### OnResult()

```
IStreamOperatorCallback::OnResult ([in] int streamId, [in] unsigned char[] result)
```

**描述**

上报stream相关的metadata等信息的回调，上报方式查看**[SetResultMode()](interface_i_camera_device_v10.md#setresultmode)**。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamId | streamId 需要上报metadata等信息的流id。 | 
| result | 上报的metadata等信息，由**[EnableResult()](interface_i_camera_device_v10.md#enableresult)**指定， **[DisableResult()](interface_i_camera_device_v10.md#disableresult)**关闭上报开关。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。
