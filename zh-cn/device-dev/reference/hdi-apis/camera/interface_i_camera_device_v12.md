# ICameraDevice


## 概述

定义Camera设备基本的操作。

获取流操作句柄，获取动态能力值等操作。

**起始版本：** 4.1

**相关模块：**[Camera](_camera_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetStreamOperator_V1_2](#getstreamoperator_v1_2) ([in] [IStreamOperatorCallback](interface_i_stream_operator_callback_v12.md) callbackObj, [out] [IStreamOperator](interface_i_stream_operator_v12.md) streamOperator) | 获取流操作句柄。 | 
| [GetStatus](#getstatus) ([in] unsigned char[] metaIn, [out] unsigned char[] metaOut) | 获取动态能力值。 | 


## 成员函数说明


### GetStatus()

```
ICameraDevice::GetStatus ([in] unsigned char[] metaIn, [out] unsigned char[] metaOut)
```

**描述**

获取动态能力值。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| metaIn | 能力输入。 | 
| metaOut | 能力输出。 捕获错误等信息[OnCaptureError](interface_i_stream_operator_callback_v10.md#oncaptureerror)。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v12.md#camretcode)。


### GetStreamOperator_V1_2()

```
ICameraDevice::GetStreamOperator_V1_2 ([in] IStreamOperatorCallback callbackObj, [out] IStreamOperator streamOperator)
```

**描述**

获取流操作句柄。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 设置流回调接口，详细可查看[IStreamOperatorCallback](interface_i_stream_operator_callback_v12.md)， 用于上报捕获开始[OnCaptureStartedV1_2](interface_i_stream_operator_callback_v12.md#oncapturestartedv1_2)，捕获结束[OnCaptureEnded](interface_i_stream_operator_callback_v10.md#oncaptureended)， 捕获错误等信息[OnCaptureError](interface_i_stream_operator_callback_v10.md#oncaptureerror)。 | 
| streamOperator | 返回流操作句柄。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v12.md#camretcode)。
