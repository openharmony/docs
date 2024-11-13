# HdiNfc (V1_0)


## 概述

为nfc服务提供统一的访问nfc驱动的接口。

NFC服务通过获取的nfc驱动对象提供的API接口访问nfc驱动，包括开关NFC、初始化NFC、读写数据、配置RF参数、 通过IO控制发送NCI指令给nfc驱动。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [INfcCallback.idl](_i_nfc_callback_8idl_v10.md) | 定义NFC回调的接口文件 | 
| [INfcInterface.idl](_i_nfc_interface_8idl_v10.md) | 定义NFC开关、初始化、传输数据的适配接口文件。 | 
| [NfcTypes.idl](_nfc_types_8idl_v10.md) | 声明类型定义，包括开关NFC、初始化NFC、读写数据、配置RF参数等 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[INfcCallback](interface_i_nfc_callback_v10.md) | 用于从nfc芯片给nfc协议栈上报数据和事件的回调声明。 | 
| interface&nbsp;&nbsp;[INfcInterface](interface_i_nfc_interface_v10.md) | 声明操作nfc芯片的API，包括关闭、打开nfc，初始化nfc，读写数据、配置RF参数、发送nci指令。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [NfcEvent](#nfcevent) {<br/>OPEN_CPLT = 0 , CLOSE_CPLT = 1 , POST_INIT_CPLT = 2 , PRE_DISCOVER_CPLT = 3 , REQUEST_CONTROL = 4 , RELEASE_CONTROL = 5 , ERROR = 6 , HCI_NETWORK_RESET = 7<br/>} | NFC事件（包括打开NFC完成、关闭NFC完成、预配置NFC完成等上报事件）的枚举定义。 | 
| [NfcStatus](#nfcstatus) {<br/>OK = 0 , FAILED = 1 , ERR_TRANSPORT = 2 , ERR_CMD_TIMEOUT = 3 , REFUSED = 4<br/>} | NFC状态的枚举定义。 | 
| [NfcCommand](#nfccommand) { CMD_INVALID = 0 } | NFC指令的枚举定义。 | 


## 枚举类型说明


### NfcCommand

```
enum NfcCommand
```

**描述**


NFC指令的枚举定义。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| CMD_INVALID | 无效指令 | 


### NfcEvent

```
enum NfcEvent
```

**描述**


NFC事件（包括打开NFC完成、关闭NFC完成、预配置NFC完成等上报事件）的枚举定义。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| OPEN_CPLT | NFC打开完成事件 | 
| CLOSE_CPLT | NFC关闭完成事件 | 
| POST_INIT_CPLT | NFC初始化完成事件 | 
| PRE_DISCOVER_CPLT | NFC discover预配置完成事件 | 
| REQUEST_CONTROL | 请求控制事件 | 
| RELEASE_CONTROL | 释放控制事件 | 
| ERROR | 错误事件 | 
| HCI_NETWORK_RESET | HCI复位事件 | 


### NfcStatus

```
enum NfcStatus
```

**描述**


NFC状态的枚举定义。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| OK | NFC状态OK | 
| FAILED | NFC状态失败 | 
| ERR_TRANSPORT | 传输错误 | 
| ERR_CMD_TIMEOUT | 发送命令超时 | 
| REFUSED | 请求被拒绝 | 
