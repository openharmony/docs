# IUsbInterface


## 概述

定义USB驱动基本的操作功能。

上层USB服务调用相关功能接口，可以打开/关闭设备，获取设备描述符，批量读取/写入数据等。

**起始版本：** 5.0

**相关模块：**[USB](_u_s_b_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetDeviceSpeed](#getdevicespeed) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [out] unsigned char speed) | 获取设备的速度。 | 
| [GetInterfaceActiveStatus](#getinterfaceactivestatus) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char interfaceid, [out] bool unactived) | 获取接口是否激活。 | 

### GetDeviceSpeed()

```
IUsbInterface::GetDeviceSpeed ([in] struct UsbDev dev, [out] unsigned char speed )
```
**描述**
获取设备的速度。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| speed | 输出设备的速度。 | 

**返回：**

0：表示UNKONOW。
1: 表示低速传输。
2：表示全速传输。
3：表示高速传输。
4：表示无线传输。
5：表示急速传输。
6：表示超速传输。
其他值表示操作失败。

### GetInterfaceActiveStatus()

```
IUsbInterface::GetInterfaceActiveStatus ([in] struct UsbDev dev, [in] unsigned char interfaceid, [out] bool unactived)
```
**描述**
获取接口是否激活。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| interfaceid | USB设备接口ID。  | 
| unactived | USB设备接口是否激活,true表示未激活,false表示激活。 | 

**返回：**

0 表示接口激活。
1 表示接口未激活。
非0和1 表示操作失败。
