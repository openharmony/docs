# HdiUsbfnMtp


## 概述

为mtp服务提供统一的API，以访问usb mtp/ptp驱动程序。

mtp服务可以获得usb mtp/ptp驱动程序对象或代理，然后调用该对象或代理提供的API来传输不同类型的mtp/ptp数据包。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IUsbfnMtpInterface.idl](_i_usbfn_mtp_interface_8idl.md) | 声明usb模块提供的API，用于获取usb信息、订阅或取消订阅usb数据、启用或禁用usb、设置usb数据报告模式以及设置准确性和测量范围等usb选项。 | 
| [UsbfnMtpTypes.idl](_usbfn_mtp_types_8idl.md) | 定义usb模块使用的数据，包括usb信息，并上报了usb数据。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IUsbfnMtpInterface](interface_i_usbfn_mtp_interface.md) | 定义在usb上执行基本操作的函数。 | 
| struct&nbsp;&nbsp;[UsbFnMtpFileSlice](_usb_fn_mtp_file_slice.md) | 标准设备描述符，对应于USB协议中的**标准设备描述符**。 | 
