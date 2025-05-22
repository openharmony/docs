# UsbPort


## 概述

USB设备状态参数

**起始版本：** 5.1

**相关模块：**[HdiUsb](_hdi_usb_v2_0.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int [id](#id) | USB端口ID。 | 
| int [supportedModes](#supportedmodes) | 支持的模式。 | 
| [UsbPortStatus](_usb_port_status.md)[usbPortStatus](#usbportstatus) | USB设备端口状态参数。 | 


## 结构体成员变量说明


### id

```
int UsbPort::id
```

**描述**

USB端口ID。


### supportedModes

```
int UsbPort::supportedModes
```

**描述**

支持的模式。


### usbPortStatus

```
UsbPortStatus UsbPort::usbPortStatus
```

**描述**

USB设备端口状态参数。
