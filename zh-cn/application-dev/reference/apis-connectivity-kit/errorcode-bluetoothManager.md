# 蓝牙服务子系统错误码

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 2900001 蓝牙服务停止

**错误信息**

Service stopped.

**错误描述**

蓝牙服务已停止，蓝牙服务相关的接口无法调用。

**可能原因**

蓝牙服务启动异常。

**处理步骤**

重新执行打开或关闭蓝牙。

## 2900003 蓝牙开关关闭

**错误信息**

Bluetooth disabled.

**错误描述**

蓝牙开关已关闭。

**可能原因**

蓝牙开关已关闭。

**处理步骤**

重新执行打开蓝牙开关。

## 2900004 配置文件不支持

**错误信息**

Profile not supported.

**错误描述**

配置文件是不支持的。

**可能原因**

该配置文件在当前设备环境不支持。

**处理步骤**

检查设备是否支持该配置文件功能，若不支持则停止调用。

## 2900005 蓝牙设备未连接

**错误信息**

Device not connected.

**错误描述**

该设备蓝牙未连接。

**可能原因**

设备配对异常。

**处理步骤**

重新打开蓝牙开关，执行配对流程。

## 2900006 超最大连接数

**错误信息**

The maximum number of connections has been reached.

**错误描述**

超过最大连接数量。

**可能原因**

超出设备最大连接数量。

**处理步骤**

检查已配对设备数量，是否超出阈值。

## 2900007 异步接口调用超时

**错误信息**

Asynchronous interface invoking timeout.

**错误描述**

异步接口调用超时。

**可能原因**

远端设备无响应。

**处理步骤**

超时后重试；若和远端设备存在链路，可以断开后，再重试。

## 2900008 空指针

**错误信息**

The value of proxy is a null pointer.

**错误描述**

pimpl或proxy为空。

**可能原因**

设备配对异常。

**处理步骤**

重新打开蓝牙开关，执行配对流程。

## 2900009 硬件资源不足

**错误信息**

Fails to start scan as it is out of hardware resources.

**错误描述**

由于硬件资源不足，无法启动本次扫描。

**可能原因**

当前系统中本应用或其他应用已启动的扫描通道过多，导致硬件资源不足。

**处理步骤**

本应用未启动过扫描，可重新关开蓝牙，释放其他应用占用的扫描资源；

本应用已启动过其他通道的扫描，可调用停止扫描接口，停止其他已启动的扫描，释放硬件资源后再重新启动本次扫描。

## 2900010 资源达到上限

**错误信息**

Resources have reached the upper limit.

**错误描述**

资源达到上限。

**可能原因**

应用申请资源过多，需要释放资源。

**处理步骤**

调用对应接口释放资源。

## 2900011 操作频繁

**错误信息**

The operation is busy. The last operation is not complete.

**错误描述**

操作忙碌，上一个执行的操作还未完成。

**可能原因**

上一个执行的操作还未完成即执行本次操作，例如[readCharacteristicValue](js-apis-bluetooth-ble.md#readcharacteristicvalue)未结束即进行下一次操作。

其他涉及的接口有[writeCharacteristicValue](js-apis-bluetooth-ble.md#writecharacteristicvalue)、[readDescriptorValue](js-apis-bluetooth-ble.md#readdescriptorvalue)、[writeDescriptorValue](js-apis-bluetooth-ble.md#writedescriptorvalue)、[getRssiValue](js-apis-bluetooth-ble.md#getrssivalue)、[setCharacteristicChangeNotification](js-apis-bluetooth-ble.md#setcharacteristicchangenotification)、[setCharacteristicChangeIndication](js-apis-bluetooth-ble.md#setcharacteristicchangeindication)，如调用未完成均可能阻塞下一次操作。

**处理步骤**

异步接口需等待callback或promise返回后再执行下一次操作。

## 2900013 前置操作超时

**错误信息**

The user does not respond.

**错误描述**

用户未回复前置操作。

**可能原因**

用户在一定时间内未执行规定操作，导致前置操作超时。

**处理步骤**

重新执行前置操作。

## 2900014 用户拒绝此操作

**错误信息**

User refuse the action.

**错误描述**

用户执行拒绝操作。

**可能原因**

用户拒绝前置操作的请求。

**处理步骤**

重新执行前置操作。

## 2900015 参数格式与规范不一致

**错误信息**

Parameter format mismatch with specification.

**错误描述**

参数格式与规范不一致。

**可能原因**

例如，参数长度不符合规范，或本应使用大写字母的参数却传入了小写字母。

**处理步骤**

检查参数格式，是否与规范保持一致。

## 2900016 设备未配对

**错误信息**

Device unpaired.

**错误描述**

设备未配对。

**可能原因**

查询的地址与设备未配对。

**处理步骤**

在蓝牙设置界面检查是否与该设备配对。

## 2900099 操作失败

根据实际错误原因的不同，上报不同的错误信息，具体如下。

### 操作失败
**错误信息**

Operation failed.

**错误描述**

操作失败。发生内部系统错误，包括SA异常，IPC异常等。

**可能原因**

蓝牙接口调用失败的通用错误码，常见可能原因如下：
1. 未满足接口调用的前置依赖条件。
2. 指定的虚拟地址不存在。

**处理步骤**

检查接口调用的前置依赖条件，具体处理步骤可参考[蓝牙接口调用报错2900099](../../connectivity/bluetooth/bluetooth-faq-2900099-errorcode.md)。

### 无效参数
**错误信息**

Operation failed. Invalid parameter.

**错误描述**

入参无效。

**可能原因**

函数入参不在有效范围内。

**处理步骤**

检查接口调用传参是否符合接口说明或协议规范。

### GATT特征值为空
**错误信息**

Operation failed. GATT character is nullptr.

**错误描述**

基于通用属性协议（Generic Attribute Profile，[GATT](../../connectivity/terminology.md#gatt)）的特征值为空。

**可能原因**

特征值为空。

**处理步骤**

检查接口调用传参。

### 调用接口时前一个接口调用流程未完成
**错误信息**

Operation failed. Please call the interface only after the previous callback has been completed.

**错误描述**

在前一个接口回调完成后，再调用该接口。

**可能原因**

前一个接口的回调未完成。

**处理步骤**

等待前一个接口的回调完成。

### 对端设备未被发现或被记录
**错误信息**

Operation failed. Address has not been discovered or recorded.

**错误描述**

设备尚未被发现或被记录。

**可能原因**

配对的对端设备未被发现或被记录。

**处理步骤**

配对已被发现或记录的对端设备。

### 蓝牙开关已经打开
**错误信息**

Operation failed. Bluetooth switch state is turn on.

**错误描述**

蓝牙开关已经打开。

**可能原因**

蓝牙开关已经打开。

**处理步骤**

检查蓝牙开关状态，在蓝牙开关状态无误时重复操作。

### 蓝牙开关状态正在切换
**错误信息**

Operation failed. Bluetooth switch state is turning state.

**错误描述**

蓝牙开关状态正在切换中。

**可能原因**

蓝牙开关状态正在切换中。

**处理步骤**

等待蓝牙开关状态切换完成，再尝试操作。

### 蓝牙开关在受限状态
**错误信息**

Operation failed. In restrict bluetooth state.

**错误描述**

蓝牙开关在受限状态。

**可能原因**

蓝牙开关在受限状态。

**处理步骤**

等待蓝牙开关退出受限状态后，再尝试操作。

### 云设备正在绑定
**错误信息**

Operation failed. Cloud device is bonding.

**错误描述**

云设备正在绑定中。

**可能原因**

云设备正在绑定中。

**处理步骤**

等待云设备绑定完成后，再尝试操作。

### 设备处于发现流程中或处于已发现状态
**错误信息**

Operation failed. In DISCOVERYING or DISCOVERY_STARTED state.

**错误描述**

在发现流程中或处于已发现状态。

**可能原因**

设备处于发现流程中或处于已发现状态。

**处理步骤**

请勿重复发起蓝牙扫描。

### 由于硬件资源不足无法启动扫描
**错误信息**

Operation failed. Fails to start scan as it is out of hardware resources.

**错误描述**

由于硬件资源不足，无法启动本次扫描。

**可能原因**

当前系统中本应用或其他应用已启动的扫描通道过多，导致硬件资源不足。

**处理步骤**

1. 本应用未启动过扫描，可重新关开蓝牙，释放其他应用占用的扫描资源。
2. 本应用已启动过其他通道的扫描，可调用停止扫描接口，停止其他已启动的扫描，释放硬件资源后再重新启动本次扫描。

### GATT未连接
**错误信息**

Operation failed. GATT not in connected state.

**错误描述**

GATT不在已连接状态。

**可能原因**

GATT未连接。

**处理步骤**

请先连接GATT，再尝试操作。

### 业务扫描期间不允许发起连接
**错误信息**

Operation failed. Not allowed to connect during scanning.

**错误描述**

扫描期间不允许连接。

**可能原因**

业务扫描期间不允许发起连接。

**处理步骤**

请先完成业务扫描，再发起连接。

### 无效蓝牙地址或传输类型
**错误信息**

Operation failed. Invalid bluetooth addr or transport type.

**错误描述**

无效蓝牙地址或传输类型。

**可能原因**

入参包含无效的蓝牙地址或传输类型。

**处理步骤**

检查入参是否符合协议要求。

### IPC数据传输失败
**错误信息**

Operation failed. IPC trans failed.

**错误描述**

IPC数据传输失败。

**可能原因**

数据传输异常。

**处理步骤**

请检查传入数据，再尝试操作。

### 已达到最大连接数
**错误信息**

Operation failed. Max connections has reached.

**错误描述**

已达到最大连接数。

**可能原因**

已达到最大连接数。

**处理步骤**

清理已连接设备后，再尝试发起新连接。

### 设备已连接
**错误信息**

Operation failed. This device has connected.

**错误描述**

该设备已连接。

**可能原因**

该设备已连接。

**处理步骤**

该设备已连接。请勿重复操作。

### 设备未连接
**错误信息**

Operation failed. This device isn't connected.

**错误描述**

该设备未连接。

**可能原因**

该设备未连接。

**处理步骤**

设备未连接，当前操作无效。请先连接设备。

### GATT服务端准备写入队列已满
**错误信息**

Operation failed. The prepare write queue of GATT server is full.

**错误描述**

GATT服务端准备写入队列已满。

**可能原因**

GATT服务端准备写入队列已满，GATT客户端写入数据量过大。

**处理步骤**

GATT客户端写入数据量过大，建议将数据分片写入。

### 对端设备存在错误行为
**错误信息**

Operation failed. Remote device has an error.

**错误描述**

对端设备出现错误。

**可能原因**

对端设备存在错误行为。

**处理步骤**

保证对端设备使用正确，再尝试操作。

## 2900100 IPC传输失败

**错误信息**

IPC failed.

**错误描述**

IPC 数据传输失败。

**可能原因**

数据传入异常。

**处理步骤**

请检查传入数据。

## 2901000 禁止读操作

**错误信息**

Read forbidden.

**错误描述**

禁止读操作。

**可能原因**

无读操作权限。

**处理步骤**

检查是否有读操作权限。

## 2901001 禁止写操作

**错误信息**

Write forbidden.

**错误描述**

禁止写操作。

**可能原因**

无写操作权限。

**处理步骤**

检查是否有写操作权限。

## 2901003 GATT未连接

**错误信息**

The connection is not established.

**错误描述**

GATT未连接。

**可能原因**

GATT处于未连接的状态下执行操作，例如调用[getServices](js-apis-bluetooth-ble.md#getservices)和[readCharacteristicValue](js-apis-bluetooth-ble.md#readcharacteristicvalue)。

**处理步骤**

确保GATT处于已连接的状态。

## 2901004 GATT传输拥塞

**错误信息**

The connection is congested.

**错误描述**

GATT处于拥塞状态。

**可能原因**

读写特征值或描述符过于频繁，导致底层数据传输拥塞，例如入参[GattWriteType](js-apis-bluetooth-ble.md#gattwritetype)为WRITE_NO_RESPONSE的[writeCharacteristicValue](js-apis-bluetooth-ble.md#writecharacteristicvalue)接口调用过于频繁可能导致拥塞。

**处理步骤**

降低读写操作频率，如果是WRITE_NO_RESPONSE类型的写数据操作，建议调用间隔控制在50ms以上。

## 2901005 GATT未加密

**错误信息**

The connection is not encrypted.

**错误描述**

GATT处于未加密的状态下，执行需要加密权限的特征值或描述符读写操作。此操作是否需要加密由server端特征值或描述符的权限指定。

**可能原因**

GATT加密权限不足。

**处理步骤**

检查GATT是否有加密权限。

## 2901006 GATT未认证

**错误信息**

The connection is not authenticated.

**错误描述**

GATT处于未认证的状态下，执行需要认证权限的特征值或描述符读写操作。此操作是否需要加密由server端特征值或描述符的权限指定。

**可能原因**

GATT认证权限不足。

**处理步骤**

检查与对端设备是否配对，是否有认证权限。

## 2901007 GATT未授权

**错误信息**

The connection is not authorized.

**错误描述**

GATT处于未授权的状态下，执行需要授权的特征值或描述符读写操作。此操作是否需要授权由server端特征值或描述符的权限指定。

**可能原因**

GATT未授权。

**处理步骤**

检查GATT是否已授权。

## 2901008 GATT服务不存在

**错误信息**

GATT service is not found.

**错误描述**

GATT服务不存在。在获取指定的GATT服务之前，该服务应当已经被添加。

**可能原因**

GATT服务尚未被添加。

**处理步骤**

先调用[addService](js-apis-bluetooth-ble.md#addservice)添加该服务。

## 2901054 IO传输失败

**错误信息**

IO error.

**错误描述**

IO传输失败。

**可能原因**

IO传输异常，造成失败。

**处理步骤**

请重试该操作。

## 2902050 开启扫描失败

**错误信息**

Failed to start scan as Ble scan is already started by the app.

**错误描述**

开启扫描失败。

**可能原因**

Ble扫描已被app开启。

**处理步骤**

检查是否已经开启扫描。

## 2902054 广播报文超限

**错误信息**

The length of the advertising data exceeds the upper limit.

**错误描述**

广播报文超过最大长度。

**可能原因**

传统广播报文的最大长度为31字节，超过此长度将返回异常。当前，该长度限制仅适用于传统广播，不包括扩展广播。

**处理步骤**

检查广播报文是否超过最大长度限制。

## 2902055 广播标识符无效

**错误信息**

Invalid advertising id.

**错误描述**

广播标识符无效。

**可能原因**

传入的广播标识符应为[startAdvertising](js-apis-bluetooth-ble.md#blestartadvertising11)接口返回的值，无效的广播标识符默认为0xFF。

**处理步骤**

检查传入的广播标识符是否为[startAdvertising](js-apis-bluetooth-ble.md#blestartadvertising11)接口返回的有效标识符。

## 2903050 HID不在前台

**错误信息**

HID application is not int the foreground.

**错误描述**

注册HID设备能力的应用不在前台。

**可能原因**

当前注册HID设备能力的应用处于后台。

**处理步骤**

检查注册HID能力的应用是否处于前台。

## 2903051 HID已注册

**错误信息**

Any HID application has been registered.

**错误描述**

其他应用已经注册过HID设备能力。

**可能原因**

只允许一个应用注册HID设备能力。

**处理步骤**

检查是否已经有其他应用注册HID设备能力。

## 2903052 HID未注册

**错误信息**

HID application does not register.

**错误描述**

当前应用还没有注册HID设备能力。

**可能原因**

应用只有在注册HID设备能力之后才能和HID主机进行连接并进行数据交互。

**处理步骤**

检查当前应用注册HID设备能力是否成功。

## 2903053 HID未连接

**错误信息**

HID device is not connected.

**错误描述**

当前HID设备还没有连接HID主机。

**可能原因**

只有在连接完成之后HID设备才能和HID主机进行数据交互。

**处理步骤**

检查当前应用是否注册HID设备能力并连接HID主机成功。

