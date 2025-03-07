# HdiUsb


## 概述

提供统一的USB驱动标准接口，实现USB驱动接入。

上层USB服务开发人员可以根据USB驱动模块提供的标准接口获取如下功能：打开/关闭设备，获取设备描述符，获取文件描述符，打开/关闭接口，批量读取/写入数据， 设置/获取设备功能，绑定/解绑订阅者等。

**起始版本：** 5.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IUsbInterface.idl](_i_usb_interface_8idl_v11.md) | 声明标准的USB驱动接口函数。 | 
| [UsbTypes.idl](_usb_types_8idl_v11.md) | USB驱动相关的数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IUsbInterface](interface_i_usb_interface_v11.md) | 定义USB驱动基本的操作功能。 | 
| struct&nbsp;&nbsp;[UsbCtrlTransferParams](_usb_ctrl_transfer_params_v11.md) | USB设备控制传输信息。 | 
