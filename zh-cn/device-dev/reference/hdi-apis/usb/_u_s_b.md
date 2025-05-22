# USB


## 概述

定义（USB）功能的标准API接口。

该模块用于获取描述符、接口对象、请求对象和提交请求的自定义数据类型和函数。

**起始版本：** 3.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [usb_info.h](usb__info_8h.md) | USB驱动订阅模块使用的数据类型。 | 
| [usbd_client.h](usbd__client_8h.md) | 声明标准USB驱动接口函数。 | 
| [usbd_subscriber.h](usbd__subscriber_8h.md) | USB驱动订阅模块。 | 
| [usbd_type.h](usbd__type_8h.md) | USB驱动模块接口定义中使用的自定义数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[USBDeviceInfo](_o_h_o_s_1_1_u_s_b_1_1_u_s_b_device_info.md) | USB设备信息。 | 
| class&nbsp;&nbsp;[UsbInfo](_o_h_o_s_1_1_u_s_b_1_1_usb_info.md) | USB设备信息类。 | 
| class&nbsp;&nbsp;[UsbdClient](_o_h_o_s_1_1_u_s_b_1_1_usbd_client.md) | USB驱动客户端类。 | 
| class&nbsp;&nbsp;[UsbdSubscriber](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md) | USB驱动订阅类。 | 
| struct&nbsp;&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) | USB设备。 | 
| struct&nbsp;&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) | 管道信息。 | 
| struct&nbsp;&nbsp;[UsbCtrlTransfer](_o_h_o_s_1_1_u_s_b_1_1_usb_ctrl_transfer.md) | USB控制传输。 | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [USB_MAX_INTERFACES](#usb_max_interfaces)&nbsp;&nbsp;&nbsp;32 | USB设备最大接口数量。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [UsbdRequestCallback](#usbdrequestcallback)) (uint8_t \*requestArg) | 请求回调函数。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [UsbdBulkCbCmd](#usbdbulkcbcmd) { CMD_USBD_BULK_CALLBACK_READ , CMD_USBD_BULK_CALLBACK_WRITE } | 批量回调命令字。 | 
| [UsbdDeviceAction](#usbddeviceaction) { ACT_DEVUP = 0 , ACT_DEVDOWN , ACT_UPDEVICE , ACT_DOWNDEVICE } | 主机端和设备端插拔事件。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| static const int32_t [USB_ENDPOINT_DIR_MASK](#usb_endpoint_dir_mask) = 0x80 | 从地址中提取USB Endpoint方向的位掩码。 | 
| static const int32_t [USB_ENDPOINT_DIR_IN](#usb_endpoint_dir_in) = 0x80 | USB Endpoint从设备到主机的数据方向。 | 
| static const int32_t [USB_ENDPOINT_DIR_OUT](#usb_endpoint_dir_out) = 0 | USB Endpoint从主机到设备的数据方向。 | 


## 宏定义说明


### USB_MAX_INTERFACES

```
#define USB_MAX_INTERFACES   32
```

**描述**


USB设备最大接口数量。


## 类型定义说明


### UsbdRequestCallback

```
typedef void(* UsbdRequestCallback) (uint8_t *requestArg)
```

**描述**


请求回调函数。


## 枚举类型说明


### UsbdBulkCbCmd

```
enum UsbdBulkCbCmd
```

**描述**


批量回调命令字。

**起始版本：** 3.0

| 枚举值 | 描述 | 
| -------- | -------- |
| CMD_USBD_BULK_CALLBACK_READ | 批量回调读取。 | 
| CMD_USBD_BULK_CALLBACK_WRITE | 批量回调写入。 | 


### UsbdDeviceAction

```
enum UsbdDeviceAction
```

**描述**


主机端和设备端插拔事件。

**起始版本：** 3.0

| 枚举值 | 描述 | 
| -------- | -------- |
| ACT_DEVUP | 主机端接入设备。 | 
| ACT_DEVDOWN | 主机端拔出设备。 | 
| ACT_UPDEVICE | 设备连接。 | 
| ACT_DOWNDEVICE | 设备断开。 | 


## 变量说明


### USB_ENDPOINT_DIR_IN

```
const int32_t USB_ENDPOINT_DIR_IN = 0x80
```

**描述**


USB Endpoint从设备到主机的数据方向。


### USB_ENDPOINT_DIR_MASK

```
const int32_t USB_ENDPOINT_DIR_MASK = 0x80
```

**描述**


从地址中提取USB Endpoint方向的位掩码。


### USB_ENDPOINT_DIR_OUT

```
const int32_t USB_ENDPOINT_DIR_OUT = 0
```

**描述**


USB Endpoint从主机到设备的数据方向。
