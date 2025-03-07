# HdiA2dp

## 概述

HdiA2dp为A2DP服务提供统一接口。

主机可以通过该模块提供的接口创建音频通话，与音频子系统交换数据。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [BluetoothAudioTypes.idl](_bluetooth_audio_types_8idl.md) | 声明数据结构。 | 
| [IBluetoothAudioCallback.idl](_i_bluetooth_audio_callback_8idl.md) | 声明回调函数，包含音频开始、暂停和结束操作。 | 
| [IBluetoothAudioSession.idl](_i_bluetooth_audio_session_8idl.md) | 声明开启音频会话，发送渲染操作结果，和结束音频会话的接口。 | 

### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IBluetoothAudioCallback](interface_i_bluetooth_audio_callback.md) | 声明用于音频渲染开启、暂停，和结束的回调函数。 | 
| interface&nbsp;&nbsp;[IBluetoothAudioSession](interface_i_bluetooth_audio_session.md) | 声明开启音频会话，发送渲染操作结果，和结束音频会话的接口。 | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Operation](#operation) { SUSPEND_RENDER = 0 , START_RENDER = 1 } | 声明操作行为。 | 
| [Status](#status) { SUCCESS = 0 , FAILURE = 1 } | 声明接口调用的操作结果。 | 
| [SessionType](#sessiontype) { UNKNOWN_TYPE , SOFTWARE_ENCODING , HARDWARE_ENCODING } | 声明音频会话的类型。 | 

## 枚举类型说明

### Operation

```
enum Operation
```

**描述**

声明操作行为。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| SUSPEND_RENDER | 暂停渲染。 | 
| START_RENDER | 开启渲染。 | 

### SessionType

```
enum SessionType
```

**描述**

声明音频会话的类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| UNKNOWN_TYPE | 未知类型。 | 
| SOFTWARE_ENCODING | 软件编码类型。 | 
| HARDWARE_ENCODING | 硬件编码类型。 | 

### Status

```
enum Status
```

**描述**

声明接口调用的操作结果。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| SUCCESS | 调用成功。 | 
| FAILURE | 调用失败。 | 
