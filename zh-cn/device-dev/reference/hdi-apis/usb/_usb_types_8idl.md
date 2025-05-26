# UsbTypes.idl


## 概述

USB驱动相关的数据类型。

**起始版本：** 5.1

**相关模块：**[HdiUsb](_hdi_usb_v2_0.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[UsbCtrlTransferParams](_usb_ctrl_transfer_params.md) | 定义了控制传输参数, 用于 IUsbHostInterface::[ControlTransferReadwithLength](interface_i_usb_host_interface.md#controltransferreadwithlength) | 
| struct&nbsp;&nbsp;[UsbDev](_usb_dev.md) | USB设备地址信息。 | 
| struct&nbsp;&nbsp;[UsbPipe](_usb_pipe.md) | USB设备管道信息。 | 
| struct&nbsp;&nbsp;[UsbCtrlTransfer](_usb_ctrl_transfer.md) | USB设备控制传输信息。 | 
| struct&nbsp;&nbsp;[USBDeviceInfo](_u_s_b_device_info.md) | USB设备信息。 | 
| struct&nbsp;&nbsp;[PortInfo](_port_info.md) | USB设备端口信息。 | 
| struct&nbsp;&nbsp;[UsbPortStatus](_usb_port_status.md) | USB设备端口状态参数 | 
| struct&nbsp;&nbsp;[UsbPort](_usb_port.md) | USB设备状态参数 | 
| struct&nbsp;&nbsp;[UsbIsoPacketDescriptor](_usb_iso_packet_descriptor_v2_0.md) | USB异步传输用于实时传输的分包描述符。 | 
| struct&nbsp;&nbsp;[USBTransferInfo](_u_s_b_transfer_info_v2_0.md) | USB异步传输入参信息。 | 
