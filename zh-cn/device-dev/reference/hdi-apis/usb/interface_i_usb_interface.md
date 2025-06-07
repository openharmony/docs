# IUsbInterface


## 概述

定义USB驱动异步传输及取消传输功能。

上层USB服务开发人员可以根据USB驱动模块提供的标准接口获取如下功能：异步传输功能，支持批量读取/写入数据、中断传输读取数据、实时传输读取/写入数据， 支持取消传输。

**起始版本：** 5.1

**相关模块：**[HdiUsb](_hdi_usb_v1_2.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [UsbSubmitTransfer()](#usbsubmittransfer) ([in] struct UsbDev dev, [in] [USBTransferInfo](_u_s_b_transfer_info.md) info, [in] [IUsbdTransferCallback](interface_i_usbd_transfer_callback_v1_2.md) cb, [in] Ashmem ashmem) | 提交USB异步传输请求。 | 
| [UsbCancelTransfer()](#usbcanceltransfer) ([in] struct UsbDev dev, [in] int endpoint) | 取消USB异步传输。 | 


## 成员函数说明


### UsbCancelTransfer()

```
IUsbInterface::UsbCancelTransfer ([in] struct UsbDev dev, [in] int endpoint )
```

**描述**

取消USB异步传输。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息。 | 
| endpoint | USB设备传输端点值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### UsbSubmitTransfer()

```
IUsbInterface::UsbSubmitTransfer ([in] struct UsbDev dev, [in] USBTransferInfo info, [in] IUsbdTransferCallback cb, [in] Ashmem ashmem )
```

**描述**

提交USB异步传输请求。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息。 | 
| info | USB传输信息实体。 | 
| cb | USB传输回调函数。 | 
| ashmem | 共享内存对象实体。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。
