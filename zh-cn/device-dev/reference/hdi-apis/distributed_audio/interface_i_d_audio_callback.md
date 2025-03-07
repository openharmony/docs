# IDAudioCallback


## 概述

定义Distributed Audio设备基本的操作。

启用和关闭分布式音频设备、设置音频参数、事件通知等相关操作。

**起始版本：** 4.1

**相关模块：**[Audio](_distributed.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OpenDevice](#opendevice) ([in] String adpName, [in] int devId) | 打开分布式音频设备。  | 
| [CloseDevice](#closedevice) ([in] String adpName, [in] int devId) | 关闭分布式音频设备。  | 
| [SetParameters](#setparameters) ([in] String adpName, [in] int devId, [in] struct [AudioParameter](_audio_parameter.md) param) | 设置分布式音频设备参数。  | 
| [NotifyEvent](#notifyevent) ([in] String adpName, [in] int devId, [in] struct [DAudioEvent](_d_audio_event.md) event) | 向分布式音频SA通知事件。  | 
| [WriteStreamData](#writestreamdata) ([in] String adpName, [in] int devId, [in] struct [AudioData](_audio_data.md) data) | 向分布式音频设备写入播放流。  | 
| [ReadStreamData](#readstreamdata) ([in] String adpName, [in] int devId, [out] struct [AudioData](_audio_data.md) data) | 向分布式音频设备读取录制流。  | 
| [ReadMmapPosition](#readmmapposition) ([in] String adpName, [in] int devId, [out] unsigned long frames, [out] struct [CurrentTime](_current_time.md) time) | 获取当前读写的帧数及时间戳  | 
| [RefreshAshmemInfo](#refreshashmeminfo) ([in] String adpName, [in] int devId, [in] FileDescriptor fd, [in] int ashmemLength, [in] int lengthPerTrans) | 刷新共享内存信息  | 


## 成员函数说明


### CloseDevice()

```
IDAudioCallback::CloseDevice ([in] String adpName, [in] int devId )
```
**描述**

关闭分布式音频设备。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adpName | 分布式音频设备NetworkID。  | 
| devId | 分布式音频设备的端口ID。 | 

**返回：**

成功返回值0，失败返回负值。


### NotifyEvent()

```
IDAudioCallback::NotifyEvent ([in] String adpName, [in] int devId, [in] struct DAudioEvent event )
```
**描述**

向分布式音频SA通知事件。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adpName | 分布式音频设备NetworkID。  | 
| devId | 分布式音频设备的端口ID。  | 
| event | 通知事件类型(如焦点事件，音量事件)。  | 

**返回：**

成功返回值0，失败返回负值。


### OpenDevice()

```
IDAudioCallback::OpenDevice ([in] String adpName, [in] int devId )
```
**描述**

打开分布式音频设备。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adpName | 分布式音频设备NetworkID。  | 
| devId | 分布式音频设备的端口ID。 | 

**返回：**

成功返回值0，失败返回负值。


### ReadMmapPosition()

```
IDAudioCallback::ReadMmapPosition ([in] String adpName, [in] int devId, [out] unsigned long frames, [out] struct CurrentTime time )
```
**描述**

获取当前读写的帧数及时间戳

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adpName | 分布式音频设备NetworkID。  | 
| devId | 分布式音频设备的端口ID。  | 
| frames | 获取的当前帧数及时间戳。  | 
| time | 当前时间戳。 | 

**返回：**

成功返回值0，失败返回负值。


### ReadStreamData()

```
IDAudioCallback::ReadStreamData ([in] String adpName, [in] int devId, [out] struct AudioData data )
```
**描述**

向分布式音频设备读取录制流。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adpName | 分布式音频设备NetworkID。  | 
| devId | 分布式音频设备的端口ID。  | 
| data | 音频流数据。 | 

**返回：**

成功返回值0，失败返回负值。


### RefreshAshmemInfo()

```
IDAudioCallback::RefreshAshmemInfo ([in] String adpName, [in] int devId, [in] FileDescriptor fd, [in] int ashmemLength, [in] int lengthPerTrans )
```
**描述**

刷新共享内存信息

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adpName | 分布式音频设备NetworkID。  | 
| devId | 分布式音频设备的端口ID。  | 
| fd | 共享内存对应文件描述符。  | 
| ashmemLength | 共享内存总字节数。  | 
| lengthPerTrans | 每次传输的字节数。 | 

**返回：**

成功返回值0，失败返回负值。


### SetParameters()

```
IDAudioCallback::SetParameters ([in] String adpName, [in] int devId, [in] struct AudioParameter param )
```
**描述**

设置分布式音频设备参数。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adpName | 分布式音频设备NetworkID。  | 
| devId | 分布式音频设备的端口ID。  | 
| param | 音频参数(包括采样率、通道数等)。  | 

**返回：**

成功返回值0，失败返回负值。


### WriteStreamData()

```
IDAudioCallback::WriteStreamData ([in] String adpName, [in] int devId, [in] struct AudioData data )
```
**描述**

向分布式音频设备写入播放流。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adpName | 分布式音频设备NetworkID。  | 
| devId | 分布式音频设备的端口ID。  | 
| data | 音频流数据。 | 

**返回：**

成功返回值0，失败返回负值。
