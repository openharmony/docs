# HdiUsb（V1_2）


## 概述

提供统一的USB驱动标准接口，实现USB驱动接入。

提供统一的USB驱动标准接口，实现USB驱动接入。

上层USB服务开发人员可以根据USB驱动模块提供的标准接口获取如下功能：异步传输读取/写入数据回调函数。

上层USB服务开发人员可以根据USB驱动模块提供的标准接口获取如下功能：异步传输功能，支持批量读取/写入数据、中断传输读取数据、实时传输读取/写入数据， 支持取消传输。

**起始版本：** 5.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IUsbdTransferCallback.idl](_i_usbd_transfer_callback_8idl_v1_2.md) | 声明标准的USB驱动接口函数。 | 
| [IUsbInterface.idl](_i_usb_interface_8idl.md) | 声明标准的USB驱动接口函数。 | 
| [UsbTypes.idl](_usb_types_8idl_v1_2.md) | USB驱动相关的数据类型。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IUsbdTransferCallback](interface_i_usbd_transfer_callback_v1_2.md) | 定义回调用于上报USB异步传输读取/写入数据的结果。 | 
| interface&nbsp;&nbsp;[IUsbInterface](interface_i_usb_interface.md) | 定义USB驱动异步传输及取消传输功能。 | 
| struct&nbsp;&nbsp;[UsbIsoPacketDescriptor](_usb_iso_packet_descriptor.md) | USB异步传输用于实时传输的分包描述符。 | 
| struct&nbsp;&nbsp;[USBTransferInfo](_u_s_b_transfer_info.md) | USB异步传输入参信息。 | 
