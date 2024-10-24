# IStreamOperator


## 概述

定义Camera设备流操作。

对Camera设备执行流的创建、配置与添加参数、属性获取、句柄绑定与解除、图像捕获与取消、流的转换以及流释放操作。

流是指从底层设备输出，经本模块内部各环节处理，最终传递到上层服务或者应用的一组数据序列。 本模块支持的流的类型有预览流，录像流，拍照流等，更多类型可查看[StreamIntent](_camera_v10.md#streamintent)。

**起始版本：** 3.2

**相关模块：**[Camera](_camera_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [IsStreamsSupported](#isstreamssupported) ([in] enum [OperationMode](_camera_v10.md#operationmode) mode, [in] unsigned char[] modeSetting, [in] struct [StreamInfo](_stream_info_v10.md)[] infos, [out] enum [StreamSupportType](_camera_v10.md#streamsupporttype) type) | 查询是否支持添加参数对应的流。 | 
| [CreateStreams](#createstreams) ([in] struct [StreamInfo](_stream_info_v10.md)[] streamInfos) | 创建流。 | 
| [ReleaseStreams](#releasestreams) ([in] int[] streamIds) | 释放流。 | 
| [CommitStreams](#commitstreams) ([in] enum [OperationMode](_camera_v10.md#operationmode) mode, [in] unsigned char[] modeSetting) | 配置流。 | 
| [GetStreamAttributes](#getstreamattributes) ([out] struct [StreamAttribute](_stream_attribute_v10.md)[] attributes) | 获取流的属性。 | 
| [AttachBufferQueue](#attachbufferqueue) ([in] int streamId, [in] BufferProducerSequenceable bufferProducer) | 绑定生产者句柄和指定流。 | 
| [DetachBufferQueue](#detachbufferqueue) ([in] int streamId) | 解除生产者句柄和指定流的绑定关系。 | 
| [Capture](#capture) ([in] int captureId, [in] struct [CaptureInfo](_capture_info_v10.md) info, [in] boolean isStreaming) | 捕获图像。 | 
| [CancelCapture](#cancelcapture) ([in] int captureId) | 取消连续捕获。 | 
| [ChangeToOfflineStream](#changetoofflinestream) ([in] int[] streamIds, [in] [IStreamOperatorCallback](interface_i_stream_operator_callback_v10.md) callbackObj, [out] [IOfflineStreamOperator](interface_i_offline_stream_operator_v10.md) offlineOperator) | 将指定流转换成离线流。 | 


## 成员函数说明


### AttachBufferQueue()

```
IStreamOperator::AttachBufferQueue ([in] int streamId, [in] BufferProducerSequenceable bufferProducer )
```

**描述**

绑定生产者句柄和指定流。

如果在[CreateStreams](#createstreams)创建流时已经指定了生产者句柄，则不需要调用该接口。如果需要重新绑定， 需先调用[DetachBufferQueue](#detachbufferqueue)进行解绑，然后再绑定。

对于一些IOT设备，可能不需要或者不支持预览流的图像数据缓存流转，那么不需要绑定生产者句柄， 此时在创建流时[CreateStreams](#createstreams)的[StreamInfo](_stream_info_v10.md)参数的生产者句柄bufferQueue_为空，而 tunneledMode_需设置为false。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamId | 用于标识要绑定的流。 | 
| bufferProducer | 生产者句柄。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。

**参见：**

[DetachBufferQueue](#detachbufferqueue)


### CancelCapture()

```
IStreamOperator::CancelCapture ([in] int captureId)
```

**描述**

取消连续捕获。

捕获结束时，会调用[OnCaptureEnded](interface_i_stream_operator_callback_v10.md#oncaptureended)来通知调用者捕获的帧计数等信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| captureId | 用于标识要取消的捕获请求。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。

**参见：**

[Capture](#capture)


### Capture()

```
IStreamOperator::Capture ([in] int captureId, [in] struct CaptureInfo info, [in] boolean isStreaming )
```

**描述**

捕获图像。

本接口必须在调用[CommitStreams](#commitstreams)配置流之后调用。 图像捕获有两种模式，分别是连续捕获和单次捕获。

- 连续捕获即触发之后模块内部进行连续的捕获，消费者只需调用此函数一次即可连续接收捕获的图像数据。若再次调用了本接口， 则停止当前捕获，更新捕获信息，再进行一次新的捕获，多用于预览、录像或者连拍场景。

- 单次捕获即触发之后只捕获一帧图像数据，用于单次拍照场景。捕获启动时，会调用[OnCaptureStarted](interface_i_stream_operator_callback_v10.md#oncapturestarted)来通知调用者捕获已经启动。

- 连续捕获需调用[CancelCapture](#cancelcapture)来停止捕获。捕获结束时，会调用[OnCaptureEnded](interface_i_stream_operator_callback_v10.md#oncaptureended)来通知调用者捕获的帧计数等信息。

[CaptureInfo](_capture_info_v10.md)的enableShutterCallback_使能[OnFrameShutter](interface_i_stream_operator_callback_v10.md#onframeshutter)，使能后每次捕获触发[OnFrameShutter](interface_i_stream_operator_callback_v10.md#onframeshutter)。

对于多个流同时捕获的场景，本模块内部保证同时上报多路流捕获数据。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| captureId | 捕获请求的唯一标识，由调用者指定，调用者需保证在Camera设备打开期间，捕获请求ID是唯一的。 | 
| info | 捕获请求的参数信息，具体信息查看[CaptureInfo](_capture_info_v10.md)。 | 
| isStreaming | 是否连续捕获，true表示连续捕获，否则为单次捕获。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。

**参见：**

OnFrameShutter


### ChangeToOfflineStream()

```
IStreamOperator::ChangeToOfflineStream ([in] int[] streamIds, [in] IStreamOperatorCallback callbackObj, [out] IOfflineStreamOperator offlineOperator )
```

**描述**

将指定流转换成离线流。

离线流只能由拍照流转换而来，其他流不支持。 一些设备处理能力有限，可能导致拍照时算法处理时间较长，从而引起捕获请求堆积在模块内部，而转换为离线 流之后，可关闭底层设备，由离线流接替，进行后续的处理。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamIds | 用于指定要转换成离线流的流集合。 | 
| callbackObj | 用于设置离线流的回调。 | 
| offlineOperator | 转换后的离线流。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。


### CommitStreams()

```
IStreamOperator::CommitStreams ([in] enum OperationMode mode, [in] unsigned char[] modeSetting )
```

**描述**

配置流。

本接口需在调用[CreateStreams](#createstreams)创建流之后调用。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | 流运行的模式，支持的模式定义在[OperationMode](_camera_v10.md#operationmode)。 | 
| modeSetting | 流的配置参数，包括帧率，ZOOM等信息。ZOOM：变焦，目前可以忽略 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。


### CreateStreams()

```
IStreamOperator::CreateStreams ([in] struct StreamInfo[] streamInfos)
```

**描述**

创建流。

此函数接口依据输入的流信息创建流，调用该接口之前需先通过[IsStreamsSupported](#isstreamssupported)查询HAL是否支持要创建的流。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamInfos | 流信息列表，流信息定义在[StreamInfo](_stream_info_v10.md)。输入的流信息可能会被修改，需通过 [GetStreamAttributes](#getstreamattributes)获取最新的流属性。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。


### DetachBufferQueue()

```
IStreamOperator::DetachBufferQueue ([in] int streamId)
```

**描述**

解除生产者句柄和指定流的绑定关系。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamId | 用于标识要解除绑定的流。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。

**参见：**

[AttachBufferQueue](#attachbufferqueue)


### GetStreamAttributes()

```
IStreamOperator::GetStreamAttributes ([out] struct StreamAttribute[] attributes)
```

**描述**

获取流的属性。

通过该接口获取的流属性可能会和[CreateStreams](#createstreams)输入的流信息存在差异。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attributes | 用于获取流的属性。在调用[CreateStreams](#createstreams)时，通过参数streamInfos携带的流信息可能会被重写。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。


### IsStreamsSupported()

```
IStreamOperator::IsStreamsSupported ([in] enum OperationMode mode, [in] unsigned char[] modeSetting, [in] struct StreamInfo[] infos, [out] enum StreamSupportType type )
```

**描述**

查询是否支持添加参数对应的流。

此函数接口根据输入的运行模式和配置信息以及当前模块中正在运行的流，查询是否支持动态添加流。

- 如果本模块支持在不停止其他流的情况下添加新流，或者即使停止其他流但上层服务或应用不感知， 则通过type参数返回DYNAMIC_SUPPORTED，上层服务或应用可以直接添加新流；

- 如果本模块支持添加新流但需要上层服务或应用先停止所有流的捕获，则通过type参数返回RE_CONFIGURED_REQUIRED;

- 如果不支持添加输入的新流，则返回NOT_SUPPORTED。 此函数需要在调用[CreateStreams](#createstreams)创建流之前调用。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | 流的使用模式，支持的模式参考[OperationMode](_camera_v10.md#operationmode)。 | 
| modeSetting | 流的配置，包括帧率，3A等配置信息。3A：自动曝光 (AE)、自动聚焦 (AF)、自动白平衡 (AWB) | 
| infos | 流的配置信息，具体参考[StreamInfo](_stream_info_v10.md)。 | 
| type | 对动态配置流的支持类型，支持类型定义在[StreamSupportType](_camera_v10.md#streamsupporttype)。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。


### ReleaseStreams()

```
IStreamOperator::ReleaseStreams ([in] int[] streamIds)
```

**描述**

释放流。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamIds | 要释放的流ID列表。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。
