# IStreamOperator


## 概述

定义Camera设备流操作。

对Camera设备执行流的创建、配置与添加参数、属性获取、句柄绑定与解除、图像捕获与取消、流的转换以及流释放操作。

流是指从底层设备输出，经本模块内部各环节处理，最终传递到上层服务或者应用的一组数据序列。 本模块支持的流的类型有预览流，录像流，拍照流等，更多类型可查看[StreamIntent](_camera_v10.md#streamintent)。

**起始版本：** 4.1

**相关模块：**[Camera](_camera_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [UpdateStreams](#updatestreams) ([in] struct StreamInfo_V1_1[] streamInfos) | 更新流。 | 
| [ConfirmCapture](#confirmcapture) ([in] int captureId) | 确认捕获。 | 


## 成员函数说明


### ConfirmCapture()

```
IStreamOperator::ConfirmCapture ([in] int captureId)
```

**描述**

确认捕获。

该函数必须在开始捕获后调用，场景处于夜景模式。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| captureId | 要确认的流的ID。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v12.md#camretcode)。


### UpdateStreams()

```
IStreamOperator::UpdateStreams ([in] struct StreamInfo_V1_1[] streamInfos)
```

**描述**

更新流。

该函数必须在 Loop CancelCaptures **CancelCaptures** 之后调用。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamInfos | 表示流信息列表，由 [StreamInfo](_stream_info___v1__1_v11.md)定义。 传递的流信息可能会被更改。因此，您可以运行[GetStreamAttributes](interface_i_stream_operator_v10.md#getstreamattributes)来获取创建流后最新的流属性。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v12.md#camretcode)。
