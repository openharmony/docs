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

### 静态常量

  | 静态常量 | 描述 | 
| -------- | -------- |
| [USB_ENDPOINT_DIR_MASK](_u_s_b.md#usb\_endpoint\_dir\_mask)&nbsp;&nbsp;&nbsp;0x80 | 从地址中提取USB Endpoint方向的位掩码。 | 
| [USB_ENDPOINT_DIR_IN](_u_s_b.md#usb\_endpoint\_dir\_in)&nbsp;&nbsp;&nbsp;0x80 | USB Endpoint从设备到主机的数据方向。 | 
| [USB_ENDPOINT_DIR_OUT](_u_s_b.md#usb\_endpoint\_dir\_out)&nbsp;&nbsp;&nbsp;0 | USB Endpoint从主机到设备的数据方向。 | 



### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| ([UsbdRequestCallback](_u_s_b.md#usbdrequestcallback))&nbsp;(uint8_t&nbsp;\*requestArg) | 请求回调函数。 | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [UsbdBulkCbCmd](_u_s_b.md#usbdbulkcbcmd)&nbsp;{&nbsp;CMD_USBD_BULK_CALLBACK_READ,&nbsp;CMD_USBD_BULK_CALLBACK_WRITE&nbsp;} | 批量回调命令字。&nbsp;[更多...](_u_s_b.md#usbdbulkcbcmd) | 
| [UsbdDeviceAction](_u_s_b.md#usbddeviceaction)&nbsp;{&nbsp;ACT_DEVUP&nbsp;=&nbsp;0,&nbsp;ACT_DEVDOWN,&nbsp;ACT_UPDEVICE,&nbsp;ACT_DOWNDEVICE&nbsp;} | 主机端和设备端插拔事件。&nbsp;[更多...](_u_s_b.md#usbddeviceaction) | 


## **详细描述**

USB驱动模块接口定义中使用的自定义数据类型。

USB驱动模块接口定义中使用的自定义数据类型, 包括分发的命令字、数据方向等。

**Since：**

3.0

**Version：**

1.0
