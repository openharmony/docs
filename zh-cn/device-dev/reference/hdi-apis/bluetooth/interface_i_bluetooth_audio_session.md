# IBluetoothAudioSession

## 概述

声明开启音频会话，发送渲染操作结果，和结束音频会话的接口。

**起始版本：** 4.0

**相关模块：**[HdiA2dp](_hdi_a2dp.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [StartSession](#startsession) ([in] enum SessionType sessionType, [in] IBluetoothAudioCallback callbackObj, [out] SharedMemQueue< unsigned char > queue) | 开启音频会话并注册回调函数。 | 
| [StopSession](#stopsession) ([in] enum SessionType sessionType) | 结束音频会话。 | 
| [RenderOperationResult](#renderoperationresult) ([in] enum Operation operation, [in] enum Status status) | 发送渲染操作结果。 | 


## 成员函数说明


### RenderOperationResult()

```
IBluetoothAudioSession::RenderOperationResult ([in] enum Operation operation, [in] enum Status status )
```

**描述**

发送渲染操作结果。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| operation | 表示渲染操作。 | 
| Status | 表示渲染操作成功或失败。 | 

**返回：**

如果操作成功返回0；否则返回负值。


### StartSession()

```
IBluetoothAudioSession::StartSession ([in] enum SessionType sessionType, [in] IBluetoothAudioCallback callbackObj, [out] SharedMemQueue< unsigned char > queue )
```

**描述**

开启音频会话并注册回调函数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sessionType | 表示会话类型。 | 
| callbackObj | 表示回调函数。相关详细信息，请参考[IBluetoothAudioCallback](interface_i_bluetooth_audio_callback.md)。 | 

**返回：**

如果操作成功返回0；否则返回负值。

### StopSession()

```
IBluetoothAudioSession::StopSession ([in] enum SessionType sessionType)
```

**描述**

结束音频会话。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sessionType | 表示会话类型。 | 

**返回：**

如果操作成功返回0；否则返回负值。
