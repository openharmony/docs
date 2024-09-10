# IDCameraProviderCallback


## 概述

定义Distributed Camera设备功能回调操作。

对Distributed Camera设备执行创建通道，创建流，捕获图像和更新设置等操作。

**起始版本：** 3.2

**相关模块：**[Camera](_distributed.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OpenSession](#opensession) ([in] struct [DHBase](_d_h_base.md) dhBase) | 在源设备和目的设备之间创建传输通道。打开并初始化分布式相机会话。  | 
| [CloseSession](#closesession) ([in] struct [DHBase](_d_h_base.md) dhBase) | 关闭分布式相机会话，并销毁源设备和目的设备之间的传输通道。  | 
| [ConfigureStreams](#configurestreams) ([in] struct [DHBase](_d_h_base.md) dhBase,[in] struct [DCStreamInfo](_d_c_stream_info.md)[] streamInfos) | 配置流。  | 
| [ReleaseStreams](#releasestreams) ([in] struct [DHBase](_d_h_base.md) dhBase,[in] int[] streamIds) | 释放流。  | 
| [StartCapture](#startcapture) ([in] struct [DHBase](_d_h_base.md) dhBase,[in] struct [DCCaptureInfo](_d_c_capture_info.md)[] captureInfos) | 开始捕获图像。  | 
| [StopCapture](#stopcapture) ([in] struct [DHBase](_d_h_base.md) dhBase,[in] int[] streamIds) | 停止捕获图像。  | 
| [UpdateSettings](#updatesettings) ([in] struct [DHBase](_d_h_base.md) dhBase,[in] struct [DCameraSettings](_d_camera_settings.md)[] settings) | 更新设备控制参数。  | 


## 成员函数说明


### CloseSession()

```
IDCameraProviderCallback::CloseSession ([in] struct DHBase dhBase)
```
**描述**

关闭分布式相机会话，并销毁源设备和目的设备之间的传输通道。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。


### ConfigureStreams()

```
IDCameraProviderCallback::ConfigureStreams ([in] struct DHBase dhBase, [in] struct DCStreamInfo[] streamInfos )
```
**描述**

配置流。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。  | 
| streamInfos | 流信息列表，流信息定义在[DCStreamInfo](_d_c_stream_info.md)。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。


### OpenSession()

```
IDCameraProviderCallback::OpenSession ([in] struct DHBase dhBase)
```
**描述**

在源设备和目的设备之间创建传输通道。打开并初始化分布式相机会话。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。


### ReleaseStreams()

```
IDCameraProviderCallback::ReleaseStreams ([in] struct DHBase dhBase, [in] int[] streamIds )
```
**描述**

释放流。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。  | 
| streamIds | 要释放的流ID列表。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。


### StartCapture()

```
IDCameraProviderCallback::StartCapture ([in] struct DHBase dhBase, [in] struct DCCaptureInfo[] captureInfos )
```
**描述**

开始捕获图像。

本接口必须在调用**ConfigStreams**配置流之后调用。 图像捕获有两种模式，分别是连续捕获和单次捕获。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。  | 
| captureInfos | 捕获请求的参数信息，具体信息查看[DCCaptureInfo](_d_c_capture_info.md)。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。


### StopCapture()

```
IDCameraProviderCallback::StopCapture ([in] struct DHBase dhBase, [in] int[] streamIds )
```
**描述**

停止捕获图像。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。


### UpdateSettings()

```
IDCameraProviderCallback::UpdateSettings ([in] struct DHBase dhBase, [in] struct DCameraSettings[] settings )
```
**描述**

更新设备控制参数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dhBase | 分布式相机设备基础信息。 | 
| settings | 设置参数，包括sensor帧率，3A相关参数等。具体信息查看[DCameraSettings](_d_camera_settings.md)。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[DCamRetCode](_distributed.md#dcamretcode)。
