# USB


## **概述**

提供统一的USB驱动标准接口，实现USB驱动接入。

上层USB服务开发人员可以根据USB驱动模块提供的标准接口获取如下功能：打开/关闭设备，获取设备描述符，获取文件描述符，打开/关闭接口，批量读取/写入数据， 设置/获取设备功能，绑定/解绑订阅者等。

**Since**:

3.2

**Version**:

1.0


## **汇总**


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [IUsbdBulkCallback.idl](_i_usbd_bulk_callback_8idl.md) | USB驱动批量传输读/写数据的回调。 | 
| [IUsbdSubscriber.idl](_i_usbd_subscriber_8idl.md) | USB驱动的订阅函数。 | 
| [IUsbInterface.idl](_i_usb_interface_8idl.md) | 声明标准的USB驱动接口函数。 | 
| [UsbTypes.idl](_usb_types_8idl.md) | USB驱动相关的数据类型。 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [IUsbdBulkCallback](interface_i_usbd_bulk_callback.md) | USB驱动的回调函数。 | 
| [IUsbdSubscriber](interface_i_usbd_subscriber.md) | 定义USB驱动的订阅类相关函数。 | 
| [IUsbInterface](interface_i_usb_interface.md) | 定义USB驱动基本的操作功能。 | 
| [PortInfo](_port_info.md) | USB设备端口信息。 | 
| [UsbDev](_usb_dev.md) | USB设备地址信息。 | 
| [UsbPipe](_usb_pipe.md) | USB设备管道信息。 | 
| [UsbCtrlTransfer](_usb_ctrl_transfer.md) | USB设备控制传输信息。 | 
| [USBDeviceInfo](_u_s_b_device_info.md) | USB设备信息。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.usb.v1_0 | USB驱动接口的包路径。 | 
