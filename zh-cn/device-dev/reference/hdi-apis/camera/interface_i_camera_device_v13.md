# ICameraDevice


## 概述

定义Camera设备基本的操作。

获取流操作句柄，获取动态能力值等操作。

**起始版本：** 5.0

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetStreamOperator_V1_3](#getstreamoperator_v1_3) ([in] [IStreamOperatorCallback](interface_i_stream_operator_callback_v13.md) callbackObj,<br/>[out] [IStreamOperator](interface_i_stream_operator_v13.md) streamOperator) | 获取流操作句柄。 | 
| [GetSecureCameraSeq](#getsecurecameraseq) ([out] unsigned long SeqId) | 获取安全相机序号。 | 


## 成员函数说明


### GetSecureCameraSeq()

```
ICameraDevice::GetSecureCameraSeq ([out] unsigned long SeqId)
```

**描述**

获取安全相机序号。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| SeqId | 返回安全相机序号，如果序号等于0表示返回不是安全相机。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### GetStreamOperator_V1_3()

```
ICameraDevice::GetStreamOperator_V1_3 ([in] IStreamOperatorCallback callbackObj, [out] IStreamOperator streamOperator)
```

**描述**

获取流操作句柄。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 设置流回调接口，详细可查看[IStreamOperatorCallback](interface_i_stream_operator_callback_v13.md)， 用于上报捕获开始**[OnCaptureStarted()](interface_i_stream_operator_callback_v10.md#oncapturestarted)**，捕获结束**[OnCaptureEnded()](interface_i_stream_operator_callback_v10.md#oncaptureended)**， 捕获错误等信息**[OnCaptureError()](interface_i_stream_operator_callback_v10.md#oncaptureerror)**。 | 
| streamOperator | 返回流操作句柄。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。
