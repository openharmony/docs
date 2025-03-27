# usbd_type.h


## 概述

USB驱动模块接口定义中使用的自定义数据类型。

USB驱动模块接口定义中使用的自定义数据类型, 包括分发的命令字、数据方向等。

**起始版本：** 3.0

**相关模块：**[USB](_u_s_b.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) | USB设备。 | 
| struct&nbsp;&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) | 管道信息。 | 
| struct&nbsp;&nbsp;[UsbCtrlTransfer](_o_h_o_s_1_1_u_s_b_1_1_usb_ctrl_transfer.md) | USB控制传输。 | 
| struct&nbsp;&nbsp;[USBDeviceInfo](_o_h_o_s_1_1_u_s_b_1_1_u_s_b_device_info.md) | USB设备信息。 | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [USB_MAX_INTERFACES](_u_s_b.md#usb_max_interfaces)&nbsp;&nbsp;&nbsp;32 | USB设备最大接口数量。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [UsbdRequestCallback](_u_s_b.md#usbdrequestcallback)) (uint8_t \*requestArg) | 请求回调函数。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [UsbdBulkCbCmd](_u_s_b.md#usbdbulkcbcmd) { [CMD_USBD_BULK_CALLBACK_READ](_u_s_b.md) , [CMD_USBD_BULK_CALLBACK_WRITE](_u_s_b.md) } | 批量回调命令字。 | 
| [UsbdDeviceAction](_u_s_b.md#usbddeviceaction) { [ACT_DEVUP](_u_s_b.md) = 0 , [ACT_DEVDOWN](_u_s_b.md) , [ACT_UPDEVICE](_u_s_b.md) , [ACT_DOWNDEVICE](_u_s_b.md) } | 主机端和设备端插拔事件。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| static const int32_t [USB_ENDPOINT_DIR_MASK](_u_s_b.md#usb_endpoint_dir_mask) = 0x80 | 从地址中提取USB Endpoint方向的位掩码。 | 
| static const int32_t [USB_ENDPOINT_DIR_IN](_u_s_b.md#usb_endpoint_dir_in) = 0x80 | USB Endpoint从设备到主机的数据方向。 | 
| static const int32_t [USB_ENDPOINT_DIR_OUT](_u_s_b.md#usb_endpoint_dir_out) = 0 | USB Endpoint从主机到设备的数据方向。 | 
