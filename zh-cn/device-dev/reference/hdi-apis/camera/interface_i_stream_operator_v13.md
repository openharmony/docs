# IStreamOperator


## 概述

定义Camera设备流操作。

对Camera设备执行流的创建、配置与添加参数、属性获取、句柄绑定与解除、图像捕获与取消、流的转换以及流释放操作。

流是指从底层设备输出，经本模块内部各环节处理，最终传递到上层服务或者应用的一组数据序列。 本模块支持的流的类型有预览流，录像流，拍照流等，更多类型可查看**[StreamIntent](_camera_v10.md#streamintent)**。

**起始版本：** 5.0

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [EnableResult](#enableresult) ([in] int streamId, [in] unsigned char[] results) | 打开metadata和其他信息在流上上报开关。 | 
| [DisableResult](#disableresult) ([in] int streamId, [in] unsigned char[] results) | 关闭metadata和其他信息在流上上报开关。 | 


## 成员函数说明


### DisableResult()

```
IStreamOperator::DisableResult ([in] int streamId, [in] unsigned char[] results)
```

**描述**

关闭metadata和其他信息在流上上报开关。

关闭之后，相应的**[OnResult()](interface_i_stream_operator_callback_v13.md#onresult)**不再上报，需[EnableResult](#enableresult)使能之后才上报。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamId | 需要关闭上报metadata等信息的流id。 | 
| results | results 需要关闭上报开关的多个metadata和其余信息。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### EnableResult()

```
IStreamOperator::EnableResult ([in] int streamId, [in] unsigned char[] results)
```

**描述**

打开metadata和其他信息在流上上报开关。

**OnResult**只上报此接口使能后的metadata即相机相关信息。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamId | 需要打开上报metadata等信息的流id。 | 
| results | 需要打开上报开关的多个metadata和其余信息。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。
