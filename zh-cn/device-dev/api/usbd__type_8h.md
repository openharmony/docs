# usbd_type.h


## **概述**

**所属模块:**

[USB](_u_s_b.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [OHOS::USB::UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) | USB设备。&nbsp;[更多...](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) | 
| [OHOS::USB::UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) | 管道信息。&nbsp;[更多...](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) | 
| [OHOS::USB::UsbCtrlTransfer](_o_h_o_s_1_1_u_s_b_1_1_usb_ctrl_transfer.md) | USB控制传输。&nbsp;[更多...](_o_h_o_s_1_1_u_s_b_1_1_usb_ctrl_transfer.md) | 
| [OHOS::USB::USBDeviceInfo](_o_h_o_s_1_1_u_s_b_1_1_u_s_b_device_info.md) | USB设备信息。&nbsp;[更多...](_o_h_o_s_1_1_u_s_b_1_1_u_s_b_device_info.md) | 


### 宏定义

  | 宏定义 | 描述 | 
| -------- | -------- |
| [USB_MAX_INTERFACES](_u_s_b.md#usbmaxinterfaces)&nbsp;&nbsp;&nbsp;32 | USB设备最大接口数量。 | 


### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| ([UsbdRequestCallback](_u_s_b.md#usbdrequestcallback))&nbsp;(uint8_t&nbsp;\*requestArg) | 请求回调函数。 | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [UsbdBulkCbCmd](_u_s_b.md#usbdbulkcbcmd)&nbsp;{&nbsp;[CMD_USBD_BULK_CALLBACK_READ](_u_s_b.md#gga734dda3df39a921fae88ada278bf35a3a5f84dff517954bbde58a2e1a0b8e8da6),&nbsp;[CMD_USBD_BULK_CALLBACK_WRITE](_u_s_b.md#gga734dda3df39a921fae88ada278bf35a3ac7fc2d22d4d348c672003c308263b9fb)&nbsp;} | 批量回调命令字。&nbsp;[更多...](_u_s_b.md#usbdbulkcbcmd) | 
| [UsbdDeviceAction](_u_s_b.md#usbddeviceaction)&nbsp;{&nbsp;[ACT_DEVUP](_u_s_b.md#gga4b7620d940f58152cd17a12401120c16af3ed12ba6838a4ebb16ae0713cb2324f)&nbsp;=&nbsp;0,&nbsp;[ACT_DEVDOWN](_u_s_b.md#gga4b7620d940f58152cd17a12401120c16a97801ad0ac063dbb69d698adc19159bf),&nbsp;[ACT_UPDEVICE](_u_s_b.md#gga4b7620d940f58152cd17a12401120c16aecf16e36110fbe276f2a11e91252de20),&nbsp;[ACT_DOWNDEVICE](_u_s_b.md#gga4b7620d940f58152cd17a12401120c16a45115ba5d58e4a5358acae70a9fc33d4)&nbsp;} | 主机端和设备端插拔事件。&nbsp;[更多...](_u_s_b.md#usbddeviceaction) | 


## **详细描述**

USB驱动模块接口定义中使用的自定义数据类型。

USB驱动模块接口定义中使用的自定义数据类型, 包括分发的命令字、数据方向等。

**Since：**

3.0

**Version：**

1.0
