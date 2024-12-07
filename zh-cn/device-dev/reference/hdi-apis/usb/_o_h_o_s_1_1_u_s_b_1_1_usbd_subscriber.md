# UsbdSubscriber


## 概述

USB驱动订阅类。

**起始版本：** 3.0

**相关模块：**[USB](_u_s_b.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [UsbdSubscriber](#usbdsubscriber) () | USB驱动订阅类构造函数。  | 
| [~UsbdSubscriber](#usbdsubscriber) ()=default | USB驱动订阅类析构函数。  | 
| [DeviceEvent](#deviceevent) (const [UsbInfo](_o_h_o_s_1_1_u_s_b_1_1_usb_info.md) &amp;info)=0 | 设备事件。  | 
| [PortChangedEvent](#portchangedevent) (int32_t portId, int32_t powerRole, int32_t dataRole, int32_t mode)=0 | 端口改变事件。  | 
| [OnRemoteRequest](#onremoterequest) (uint32_t code, MessageParcel &amp;data, MessageParcel &amp;reply, MessageOption &amp;option) override | 远程请求。  | 


### 静态 Private 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [ParserUsbInfo](#parserusbinfo) (MessageParcel &amp;data, MessageParcel &amp;reply, MessageOption &amp;option, [UsbInfo](_o_h_o_s_1_1_u_s_b_1_1_usb_info.md) &amp;info) | 解析USB设备信息。  | 
| [ParserPortInfo](#parserportinfo) (MessageParcel &amp;data, MessageParcel &amp;reply, MessageOption &amp;option, PortInfo &amp;info) | 解析USB设备端口信息。  | 


## 构造及析构函数说明


### UsbdSubscriber()

```
UsbdSubscriber::UsbdSubscriber ()
```
**描述**

USB驱动订阅类构造函数。

**起始版本：** 3.0


### ~UsbdSubscriber()

```
virtual UsbdSubscriber::~UsbdSubscriber ()
```
**描述**

USB驱动订阅类析构函数。

**起始版本：** 3.0


## 成员函数说明


### DeviceEvent()

```
virtual int32_t UsbdSubscriber::DeviceEvent (const UsbInfo & info)
```
**描述**

设备事件。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| [UsbInfo](_o_h_o_s_1_1_u_s_b_1_1_usb_info.md) | 输入参数，USB设备信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### OnRemoteRequest()

```
int32_t UsbdSubscriber::OnRemoteRequest (uint32_t code, MessageParcel & data, MessageParcel & reply, MessageOption & option )
```
**描述**

远程请求。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| code | 输入参数，命令字。  | 
| data | 输入参数，待解析的数据。  | 
| reply | 输出参数，返回的数据。  | 
| option | 输入参数，选项数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ParserPortInfo()

```
static int32_t UsbdSubscriber::ParserPortInfo (MessageParcel & data, MessageParcel & reply, MessageOption & option, PortInfo & info )
```
**描述**

解析USB设备端口信息。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| code | 输入参数，命令字。  | 
| reply | 输出参数，返回的数据。  | 
| option | 输入参数，选项数据。  | 
| info | 输出参数，USB设备端口信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ParserUsbInfo()

```
static int32_t UsbdSubscriber::ParserUsbInfo (MessageParcel & data, MessageParcel & reply, MessageOption & option, UsbInfo & info )
```
**描述**

解析USB设备信息。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| code | 输入参数，命令字。  | 
| reply | 输出参数，返回的数据。  | 
| option | 输入参数，选项数据。  | 
| info | 输出参数，USB设备信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### PortChangedEvent()

```
virtual int32_t UsbdSubscriber::PortChangedEvent (int32_t portId, int32_t powerRole, int32_t dataRole, int32_t mode )
```
**描述**

端口改变事件。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| portId | 输入参数，端口ID。  | 
| powerRole | 输入参数，电源角色的值。  | 
| dataRole | 输入参数，数据角色的值。  | 
| mode | 输入参数，端口模式的值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。
