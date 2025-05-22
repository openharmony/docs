# ICameraDevice

## 概述

定义Camera设备基本的操作。

设置流回调接口、更新控制参数、执行metadata相关操作。

**起始版本：** 4.0

**相关模块：**[Camera](_camera_v11.md)

## 汇总

### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetStreamOperator_V1_1](#getstreamoperator_v1_1) ([in] IStreamOperatorCallback callbackObj, [out] [IStreamOperator](interface_i_stream_operator_v11.md) streamOperator) | 获取流操作句柄。 | 
| [GetDefaultSettings](#getdefaultsettings) ([out] unsigned char[] settings) | 获取默认的相机设备控制参数。 | 

## 成员函数说明

### GetDefaultSettings()

```
ICameraDevice::GetDefaultSettings ([out] unsigned char[] settings)
```

**描述**

获取默认的相机设备控制参数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| settings | 指示默认的相机参数,包括传感器帧速率和3A参数。<br/>3A 代表自动对焦 (AF), 自动曝光 (AE), 和自动白平衡 (AWB)。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。

### GetStreamOperator_V1_1()

```
ICameraDevice::GetStreamOperator_V1_1 ([in] IStreamOperatorCallback callbackObj, [out] IStreamOperator streamOperator)
```

**描述**

获取流操作句柄。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 设置流回调接口，详细可查看[IStreamOperatorCallback](interface_i_stream_operator_callback_v10.md)，用于上报捕获开始[OnCaptureStarted](interface_i_stream_operator_callback_v10.md#oncapturestarted)，捕获结束[OnCaptureEnded](interface_i_stream_operator_callback_v10.md#oncaptureended)，捕获错误等信息[OnCaptureError](interface_i_stream_operator_callback_v10.md#oncaptureerror)。 | 
| streamOperator | 返回流操作句柄。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。
