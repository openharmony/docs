# ICameraDevice


## 概述

定义Camera设备基本的操作。

设置流回调接口、更新控制参数、执行metadata相关操作。

**起始版本：** 3.2

**相关模块：**[Camera](_camera_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetStreamOperator](#getstreamoperator) ([in] [IStreamOperatorCallback](interface_i_stream_operator_callback_v10.md) callbackObj, [out] [IStreamOperator](interface_i_stream_operator_v10.md) streamOperator) | 获取流操作句柄。 | 
| [UpdateSettings](#updatesettings) ([in] unsigned char[] settings) | 更新设备控制参数。 | 
| [SetResultMode](#setresultmode) ([in] enum [ResultCallbackMode](_camera_v10.md#resultcallbackmode) mode) | 设置metadata上报模式，逐帧上报还是设备状态变化时上报。 | 
| [GetEnabledResults](#getenabledresults) ([out] int[] results) | 查询使能的metadata。 | 
| [EnableResult](#enableresult) ([in] int[] results) | 打开metadata上报开关。 | 
| [DisableResult](#disableresult) ([in] int[] results) | 关闭metadata上报开关。 | 
| [Close](#close) () | 关闭当前Camera设备。 | 


## 成员函数说明


### Close()

```
ICameraDevice::Close ()
```

**描述**

关闭当前Camera设备。

**起始版本：** 3.2

**参见：**

OpenCamera


### DisableResult()

```
ICameraDevice::DisableResult ([in] int[] results)
```

**描述**

关闭metadata上报开关。

屏蔽之后，相应的**OnResult**不再上报，需[EnableResult](#enableresult)使能之后才上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| results | 需要关闭上报开关的metadata。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。

**参见：**

[EnableResult](#enableresult)


### EnableResult()

```
ICameraDevice::EnableResult ([in] int[] results)
```

**描述**

打开metadata上报开关。

**OnResult**只上报此接口使能后的metadata。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| results | 需要打开上报开关的多个metadata。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。

**参见：**

[DisableResult](#disableresult)


### GetEnabledResults()

```
ICameraDevice::GetEnabledResults ([out] int[] results)
```

**描述**

查询使能的metadata。

[EnableResult](#enableresult)使能需要上报的metadata之后，可通过此接口查询使能的metadata。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| results | 所有使能的metadata的ID数组。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。


### GetStreamOperator()

```
ICameraDevice::GetStreamOperator ([in] IStreamOperatorCallback callbackObj, [out] IStreamOperator streamOperator)
```

**描述**

获取流操作句柄。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 设置流回调接口，详细可查看[IStreamOperatorCallback](interface_i_stream_operator_callback_v10.md)， 用于上报捕获开始[OnCaptureStarted](interface_i_stream_operator_callback_v10.md#oncapturestarted)，捕获结束[OnCaptureEnded](interface_i_stream_operator_callback_v10.md#oncaptureended)， 捕获错误等信息[OnCaptureError](interface_i_stream_operator_callback_v10.md#oncaptureerror)。 | 
| streamOperator | 返回流操作句柄。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。


### SetResultMode()

```
ICameraDevice::SetResultMode ([in] enum ResultCallbackMode mode)
```

**描述**

设置metadata上报模式，逐帧上报还是设备状态变化时上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | metadata的上报模式，逐帧上报或者设备状态变化时上报，查看[ResultCallbackMode](_camera_v10.md#resultcallbackmode)。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。


### UpdateSettings()

```
ICameraDevice::UpdateSettings ([in] unsigned char[] settings)
```

**描述**

更新设备控制参数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| settings | Camera设置参数，包括sensor帧率，3A相关参数等。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。
