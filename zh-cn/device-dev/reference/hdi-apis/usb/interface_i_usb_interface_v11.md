# IUsbInterface


## 概述

定义USB驱动基本的操作功能。

上层USB服务调用相关功能接口，可以打开/关闭设备，获取设备描述符，批量读取/写入数据等。

**起始版本：** 5.0

**相关模块：**[HdiUsb](_hdi_usb.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetInterfaceActiveStatus](#getinterfaceactivestatus) ([in] struct UsbDev dev, [in] unsigned char interfaceid, [out] boolean unactivated) | 获取USB设备接口的激活信息。 | 
| [GetDeviceSpeed](#getdevicespeed) ([in] struct UsbDev dev, [out] unsigned char speed) | 获取USB设备速率。 | 
| [GetDeviceFileDescriptor](#getdevicefiledescriptor) ([in] struct UsbDev dev, [out] FileDescriptor fd) | 获取文件描述符。 | 
| [BulkTransferReadwithLength](#bulktransferreadwithlength) ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] int length, [out] unsigned char[] data) | 在USB设备指定端点方向为读取时，执行批量数据读取。 | 
| [ClearHalt](#clearhalt) ([in] struct UsbDev dev, [in] struct UsbPipe pipe) | 清除端点的暂停状态。 | 
| [ControlTransferReadwithLength](#controltransferreadwithlength) ([in] struct UsbDev dev, [in] struct [UsbCtrlTransferParams](_usb_ctrl_transfer_params_v11.md) ctrl, [out] unsigned char[] data) | 在传输状态为读取并且控制端点是端点零时，对USB设备执行控制传输。 | 
| [ResetDevice](#resetdevice) ([in] struct UsbDev dev) | 重置设备。 | 


## 成员函数说明


### BulkTransferReadwithLength()

```
IUsbInterface::BulkTransferReadwithLength ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] int length, [out] unsigned char[] data )
```

**描述**

在USB设备指定端点方向为读取时，执行批量数据读取。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息。 | 
| pipe | USB设备管道信息。 | 
| timeout | 超时时间。 | 
| length | 读取的最大字节长度。 | 
| data | 读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ClearHalt()

```
IUsbInterface::ClearHalt ([in] struct UsbDev dev, [in] struct UsbPipe pipe )
```

**描述**

清除端点的暂停状态。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息。 | 
| pipe | USB设备管道信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ControlTransferReadwithLength()

```
IUsbInterface::ControlTransferReadwithLength ([in] struct UsbDev dev, [in] struct UsbCtrlTransferParams ctrl, [out] unsigned char[] data )
```

**描述**

在传输状态为读取并且控制端点是端点零时，对USB设备执行控制传输。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息。 | 
| ctrl | USB设备控制数据。 | 
| data | 写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetDeviceFileDescriptor()

```
IUsbInterface::GetDeviceFileDescriptor ([in] struct UsbDev dev, [out] FileDescriptor fd )
```

**描述**

获取文件描述符。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息。 | 
| fd | USB USB设备文件描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetDeviceSpeed()

```
IUsbInterface::GetDeviceSpeed ([in] struct UsbDev dev, [out] unsigned char speed )
```

**描述**

获取USB设备速率。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息。 | 
| speed | USB设备速率。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetInterfaceActiveStatus()

```
IUsbInterface::GetInterfaceActiveStatus ([in] struct UsbDev dev, [in] unsigned char interfaceid, [out] boolean unactivated )
```

**描述**

获取USB设备接口的激活信息。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息。 | 
| interfaceid | USB设备接口ID。 | 
| unactivated | USB设备接口激活状态。true表示未激活，false表示已激活。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ResetDevice()

```
IUsbInterface::ResetDevice ([in] struct UsbDev dev)
```

**描述**

重置设备。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。
