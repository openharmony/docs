# HdiUsb（V2_0）


## 概述

提供统一的USB驱动标准接口，实现USB驱动接入。

提供统一的USB驱动标准接口，实现USB驱动接入

提供统一的USB驱动标准接口，实现USB驱动接入。

上层USB服务开发人员可以根据USB驱动模块提供的标准接口获取如下功能：打开/关闭设备，获取设备描述符，获取文件描述符，打开/关闭接口，批量读取/写入数据， 设置/获取设备功能，绑定/解绑订阅者等。

上层USB服务开发人员可以根据USB驱动模块提供的标准接口获取如下功能：异步传输读取/写入数据回调函数。

**起始版本：** 5.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IUsbdBulkCallback.idl](_i_usbd_bulk_callback_8idl.md) | USB驱动批量传输读/写数据的回调。 | 
| [IUsbDeviceInterface.idl](_i_usb_device_interface_8idl.md) | 声明标准的USB驱动接口函数。 | 
| [IUsbdSubscriber.idl](_i_usbd_subscriber_8idl.md) | USB驱动的订阅函数。 | 
| [IUsbdTransferCallback.idl](_i_usbd_transfer_callback_8idl.md) | 声明标准的USB驱动接口函数。 | 
| [IUsbHostInterface.idl](_i_usb_host_interface_8idl.md) | 声明标准的USB驱动接口函数。 | 
| [IUsbPortInterface.idl](_i_usb_port_interface_8idl.md) | 声明标准的USB驱动接口函数。 | 
| [UsbTypes.idl](_usb_types_8idl.md) | USB驱动相关的数据类型。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IUsbdBulkCallback](interface_i_usbd_bulk_callback.md) | SB驱动的回调函数。 | 
| interface&nbsp;&nbsp;[IUsbDeviceInterface](interface_i_usb_device_interface.md) |  | 
| interface&nbsp;&nbsp;[IUsbdSubscriber](interface_i_usbd_subscriber.md) | 定义USB驱动的订阅类相关函数。 | 
| interface&nbsp;&nbsp;[IUsbdTransferCallback](interface_i_usbd_transfer_callback_v2_0.md) | 定义回调用于上报USB异步传输读取/写入数据的结果。 | 
| interface&nbsp;&nbsp;[IUsbHostInterface](interface_i_usb_host_interface.md) | 定义USB驱动基本的操作功能。上层USB服务调用相关功能接口，可以打开/关闭设备，获取设备描述符，批量读取/写入数据等。 | 
| interface&nbsp;&nbsp;[IUsbPortInterface](interface_i_usb_port_interface.md) | 定义USB驱动基本的操作功能。上层USB服务调用端口相关功能接口，可以设置/查询USB设备端口的角色，查询USB设备所有端口的当前设置信息等。 | 
| struct&nbsp;&nbsp;[UsbCtrlTransferParams](_usb_ctrl_transfer_params.md) | 定义了控制传输参数, 用于 [ControlTransferReadwithLength()](interface_i_usb_host_interface.md#controltransferreadwithlength) | 
| struct&nbsp;&nbsp;[UsbDev](_usb_dev.md) | USB设备地址信息。 | 
| struct&nbsp;&nbsp;[UsbPipe](_usb_pipe.md) | USB设备管道信息。 | 
| struct&nbsp;&nbsp;[UsbCtrlTransfer](_usb_ctrl_transfer.md) | USB设备控制传输信息。 | 
| struct&nbsp;&nbsp;[USBDeviceInfo](_u_s_b_device_info.md) | USB设备信息。 | 
| struct&nbsp;&nbsp;[PortInfo](_port_info.md) | USB设备端口信息。 | 
| struct&nbsp;&nbsp;[UsbPortStatus](_usb_port_status.md) | USB设备端口状态参数 | 
| struct&nbsp;&nbsp;[UsbPort](_usb_port.md) | USB设备状态参数 | 
| struct&nbsp;&nbsp;[UsbIsoPacketDescriptor](_usb_iso_packet_descriptor_v2_0.md) | USB异步传输用于实时传输的分包描述符。 | 
| struct&nbsp;&nbsp;[USBTransferInfo](_u_s_b_transfer_info_v2_0.md) | USB异步传输入参信息。 | 
