# HdiUsbDdk


## 概述

提供USB DDK API以打开和关闭USB接口，执行非等时和等时。

提供USB DDK类型，并声明USB DDK API所需的宏、枚举变量和数据结构。

通过USB管道进行数据传输，并实现控制传输和中断传输等。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IUsbDdk.idl](_i_usb_ddk_8idl.md) | 声明USB主机用于访问USB设备的USB DDK API。 | 
| [UsbDdkTypes.idl](_usb_ddk_types_8idl.md) | 提供USB DDK API中使用的枚举变量、结构和宏。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IUsbDdk](interface_i_usb_ddk.md) | 声明USB主机用于访问USB设备的USB DDK API。 | 
| struct&nbsp;&nbsp;[UsbControlRequestSetup](_usb_control_request_setup.md) | 控制传输的设置数据。它对应于USB协议中的**Setup Data**。 | 
| struct&nbsp;&nbsp;[UsbDeviceDescriptor](_usb_device_descriptor.md) | 标准设备描述符，对应于USB协议中的**标准设备描述符**。 | 
| struct&nbsp;&nbsp;[UsbRequestPipe](_usb_request_pipe.md) | 请求管道。 | 
