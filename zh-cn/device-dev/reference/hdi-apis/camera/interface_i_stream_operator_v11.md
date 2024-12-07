# IStreamOperator


## 概述

定义Camera设备流操作。

对Camera设备执行流的创建、配置与添加参数、属性获取、句柄绑定与解除、图像捕获与取消、流的转换以及流释放操作。

流是指从底层设备输出，经本模块内部各环节处理，最终传递到上层服务或者应用的一组数据序列。 本模块支持的流的类型有预览流，录像流，拍照流等，更多类型可查看[StreamIntent](_camera_v10.md#streamintent)。

**起始版本：** 4.0

**相关模块：**[Camera](_camera_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [IsStreamsSupported_V1_1](#isstreamssupported_v1_1) ([in] enum [OperationMode_V1_1](_camera_v11.md#operationmode_v1_1) mode, [in] unsigned char[] modeSetting, [in] struct [StreamInfo_V1_1](_stream_info___v1__1_v11.md)[] infos, [out] enum StreamSupportType type) | 查询是否支持添加参数对应的流。 | 
| [CreateStreams_V1_1](#createstreams_v1_1) ([in] struct [StreamInfo_V1_1](_stream_info___v1__1_v11.md)[] streamInfos) | 创建流。 | 
| [CommitStreams_V1_1](#commitstreams_v1_1) ([in] enum [OperationMode_V1_1](_camera_v11.md#operationmode_v1_1) mode, [in] unsigned char[] modeSetting) | 配置流。 | 


## 成员函数说明


### CommitStreams_V1_1()

```
IStreamOperator::CommitStreams_V1_1 ([in] enum OperationMode_V1_1 mode, [in] unsigned char[] modeSetting )
```

**描述**

配置流。

本接口需在调用[CreateStreams_V1_1](#createstreams_v1_1)创建流之后调用。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | 流运行的模式，支持的模式定义在[OperationMode_V1_1](_camera_v11.md#operationmode_v1_1)。 | 
| modeSetting | 流的配置参数，包括帧率，ZOOM等信息。ZOOM：变焦。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。


### CreateStreams_V1_1()

```
IStreamOperator::CreateStreams_V1_1 ([in] struct StreamInfo_V1_1[] streamInfos)
```

**描述**

创建流。

此函数接口依据输入的流信息创建流，调用该接口之前需先通过[IsStreamsSupported_V1_1](#isstreamssupported_v1_1)查询HAL是否支持要创建的流。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamInfos | 流信息列表，流信息定义在[StreamInfo](_stream_info___v1__1_v11.md)。输入的流信息可能会被修改，需通过 [GetStreamAttributes](interface_i_stream_operator_v10.md#getstreamattributes)获取最新的流属性。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。


### IsStreamsSupported_V1_1()

```
IStreamOperator::IsStreamsSupported_V1_1 ([in] enum OperationMode_V1_1 mode, [in] unsigned char[] modeSetting, [in] struct StreamInfo_V1_1[] infos, [out] enum StreamSupportType type )
```

**描述**

查询是否支持添加参数对应的流。

此函数接口根据输入的运行模式和配置信息以及当前模块中正在运行的流，查询是否支持动态添加流。

- 如果本模块支持在不停止其他流的情况下添加新流，或者即使停止其他流但上层服务或应用不感知， 则通过type参数返回DYNAMIC_SUPPORTED，上层服务或应用可以直接添加新流；

- 如果本模块支持添加新流但需要上层服务或应用先停止所有流的捕获，则通过type参数返回RE_CONFIGURED_REQUIRED;

- 如果不支持添加输入的新流，则返回NOT_SUPPORTED。

此函数需要在调用[CommitStreams_V1_1](#commitstreams_v1_1)创建流之前调用。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | 流的使用模式，支持的模式参考[OperationMode_V1_1](_camera_v11.md#operationmode_v1_1)。 | 
| modeSetting | 流的配置，包括帧率，3A等配置信息。3A：自动曝光 (AE)、自动聚焦 (AF)、自动白平衡 (AWB)。 | 
| infos | 流的配置信息，具体参考[StreamInfo](_stream_info___v1__1_v11.md)。 | 
| type | 对动态配置流的支持类型，支持类型定义在[StreamSupportType](_camera_v10.md#streamsupporttype)。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。
