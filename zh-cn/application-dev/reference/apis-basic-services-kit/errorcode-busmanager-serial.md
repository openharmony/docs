# 串口管理错误码

<!--Kit: Basic Services Kit-->
<!--Subsystem: BusManager-->
<!--Owner: @hwymlgitcode-->
<!--Designer: @hwymlgitcode-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->

> **说明：**
> API参考中的参数说明与SDK中@ohos.busManager.serial.d.ts文件的注释保持一致。
>
> 本模块首批接口从API version 19开始支持。后续版本的新增接口，采用上标单独标记接口的起始版本。
>
> 本文档提供串口通信接口调用的错误码说明，帮助开发者快速定位和解决串口通信问题。适用于开发串口通信应用、调试串口通信异常等场景。以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 错误码汇总

| 错误码ID | 错误信息 | 触发接口 |
| --- | --- | --- |
| 35700001 | Service error. | getSerialPortList, open, close, write, onDataRead, offDataRead, flush, drain, setRts, getCts, getDsr, sendBrk, onDisconnect, offDisconnect, setDtr, addPortAuthorization |
| 35700002 | Invalid parameter. | open, write, addPortAuthorization |
| 35700003 | Virtual serial port disconnected. |open, write, onDataRead, flush, drain, setRts, getCts, sendBrk, getDsr, setDtr |
| 35700004 | Port already in use. | open |
| 35700005 | Port not open. | close, write, onDataRead, offDataRead, flush, drain, setRts, getCts, sendBrk, getDsr, setDtr, onDisconnect, offDisconnect |
| 35700006 | Transmission timeout. | write |
| 35700007 | User authorization required. | open |
| 35700008 | Permission denied. | addPortAuthorization |

## 35700001 服务异常

**错误信息**

Service error.

**错误描述**

调用串口通信相关接口时，串口通信服务内部发生异常（如服务崩溃、资源不足等）。

**可能原因**

1. 串口通信服务未启动。

2. 串口通信服务进程崩溃或系统资源不足。

**处理步骤**

1. 检查设备串口功能是否正常。

2. 重启设备后重试。

## 35700002 参数错误

**错误信息**

Invalid parameter.

**错误描述**

调用串口通信相关接口时，传入的参数不合法。

**可能原因**

1. 波特率取值不在支持的范围内（标准值为9600/19200/38400/57600/115200等常用波特率，或[1, 115200]范围内的正整数）。

2. 写入数据长度超出(0, 4096]范围（单位：字节）。

3. 超时时间超出[0, 300000]范围（单位：ms）。

4. 参数类型与接口定义不匹配，如期望number类型但传入string类型。

**处理步骤**

1. 检查波特率是否为支持的常用波特率（如9600/19200/38400/57600/115200），或是否为[1, 115200]范围内的正整数。

2. 检查写入数据长度是否在(0, 4096]范围内（单位：字节）。

3. 检查超时时间参数是否在[0, 300000]范围内（单位：ms）。

4. 检查参数类型是否正确。

## 35700003 虚拟串口断开

**错误信息**

Virtual serial port disconnected.

**错误描述**

操作串口通信相关接口时，USB虚拟串口设备已断开连接。

**可能原因**

1. USB转串口线缆被拔出。

2. USB虚拟串口设备异常断开。

**处理步骤**

1. 检查USB转串口线缆连接是否正常，确保设备连接稳定。

2. 重新插拔USB设备后，重新调用[getSerialPortList](js-apis-busmanager-serial.md#serialgetserialportlist)获取设备列表，再调用[open](js-apis-busmanager-serial.md#open)接口打开设备，以恢复串口通信功能。

## 35700004 端口已被占用

**错误信息**

Port already in use.

**错误描述**

调用[open](js-apis-busmanager-serial.md#open)接口打开串口时，需确保串口端口未被其他应用或进程占用，否则会因端口已被占用而报错。

**配对调用说明：**
- 调用open()打开串口后，必须在使用完毕后调用close()关闭串口释放资源。
- 未正确关闭串口可能导致端口被占用，影响后续使用。
- 建议在finally块中调用close()确保资源释放。

**可能原因**

1. 同一串口被其他应用打开。

2. 上次操作未正常关闭串口。

**处理步骤**

1. 关闭占用该串口的其他应用。

2. 调用[close](js-apis-busmanager-serial.md#close)关闭串口后重新打开。

## 35700005 端口未打开

**错误信息**

Port not open.

**错误描述**

操作串口通信相关接口时，串口端口未打开。

**状态转换说明：**
- 调用open()后，串口处于打开状态，可以调用[onDataRead](js-apis-busmanager-serial.md#ondataread)、[write](js-apis-busmanager-serial.md#write)等接口。onDataRead需与offDataRead配对调用，在close()前应先调用offDataRead取消订阅
- 调用close()后，串口处于关闭状态，上述接口将无法使用。
- 必须在串口打开状态下才能进行读写等操作。

**可能原因**

1. 未调用[open](js-apis-busmanager-serial.md#open)接口打开串口。

2. 串口已被关闭。

**处理步骤**

1. 先调用[open](js-apis-busmanager-serial.md#open)接口打开串口。

2. 检查串口是否已被关闭，若已关闭则重新打开。

## 35700006 传输超时

**错误信息**

Transmission timeout.

**错误描述**

调用[write](js-apis-busmanager-serial.md#write)接口写入数据时（需确保串口已打开），若数据传输超时则会报此错误。

**前置条件：**
- 必须先调用[open](js-apis-busmanager-serial.md#open)打开串口，才能调用write()接口。
- write()接口依赖串口处于打开状态。

**可能原因**

1. 写入操作等待时间超过设定的超时时间限制。

2. 接收端设备未响应。

3. 串口通信参数配置不匹配。

4. 写入请求过于频繁导致硬件缓冲区拥塞。

**处理步骤**

1. 检查接收端设备是否正常连接。

2. 适当增大超时时间参数（单位：ms）。

3. 检查串口通信参数（波特率等）是否与对端一致。

4. 在确保串口正常打开的情况下，可降低写入频率或在每次写入之间调用[drain](js-apis-busmanager-serial.md#drain)接口等待前次数据发送完成后再发送，避免硬件缓冲区拥塞。

**write和drain的配合使用：**
- drain()用于等待串口发送缓冲区中的数据全部发送完成。
- 在连续写入大量数据时，建议在write()之间调用drain()，确保数据按顺序完整发送。
- 典型调用流程：write() → drain() → write() → drain() → ...。

## 35700007 需要用户授权

**错误信息**

User authorization required.

**错误描述**

调用[open](js-apis-busmanager-serial.md#open)接口打开串口时，系统会校验用户是否已允许应用访问目标串口，若用户拒绝授权，则抛出该错误码。

**可能原因**

1. 用户在授权弹窗中拒绝了应用访问目标串口的请求。

**处理步骤**

1. 引导用户在授权弹窗中允许应用访问目标串口。

## 35700008 权限被拒绝

**错误信息**

Permission denied.

**错误描述**

调用serial.addPortAuthorization接口时，该接口仅允许串口授权弹窗应用（系统指定的用于处理串口设备授权弹窗的预置应用）调用，若当前应用不是串口授权弹窗应用则会报权限被拒绝错误。

**可能原因**

1. 调用方不是串口授权弹窗应用。serial.addPortAuthorization接口仅允许串口授权弹窗应用调用。

**处理步骤**

1. 确认当前应用是否为串口授权弹窗应用。该接口仅允许特定的串口授权弹窗应用调用，其他应用无法使用。
