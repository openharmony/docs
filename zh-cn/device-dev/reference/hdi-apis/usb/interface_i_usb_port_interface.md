# IUsbPortInterface


## 概述

**相关模块：**[HdiUsb](_hdi_usb_v2_0.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [SetPortRole](#setportrole)([in] int portId, [in] int powerRole, [in] int dataRole) | 设置USB设备端口的角色。 | 
| [QueryPort](#queryport)([out] int portId, [out] int powerRole, [out] int dataRole, [out] int mode) | 查询USB设备端口的当前设置信息。 | 
| [QueryPorts](#queryports)([out] struct [UsbPort](_usb_port.md)[] portList) | 查询USB设备所有端口的当前设置信息。 | 
| [BindUsbdPortSubscriber](#bindusbdportsubscriber)([in] [IUsbdSubscriber](interface_i_usbd_subscriber.md) subscriber) | 绑定订阅者。 | 
| [UnbindUsbdPortSubscriber](#unbindusbdportsubscriber)([in] [IUsbdSubscriber](interface_i_usbd_subscriber.md) subscriber) | 解绑订阅者。 | 


## 成员函数说明


### SetPortRole()

```
IUsbPortInterface::SetPortRole([in] int portId, [in] int powerRole, [in] int dataRole)
```

**描述**

设置USB设备端口的角色。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| portId | USB设备端口ID。 | 
| powerRole | 电源角色的值。 | 
| dataRole | 数据角色的值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### QueryPort()

```
IUsbPortInterface::QueryPort([out] int portId, [out] int powerRole, [out] int dataRole, [out] int mode)
```

**描述**

查询USB设备端口的当前设置信息。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| portId | USB设备端口ID。 | 
| powerRole | USB设备电源角色。 | 
| dataRole | USB设备数据角色。 | 
| mode | USB设备模式。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### QueryPorts()

```
IUsbPortInterface::QueryPorts([out] struct UsbPort[] portList);
```

**描述**

查询USB设备所有端口的当前设置信息。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| portList | USB设备端口ID集合。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BindUsbdPortSubscriber()

```
IUsbPortInterface::BindUsbdPortSubscriber([in] IUsbdSubscriber subscriber)
```

**描述**

绑定订阅者。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| subscriber | 订阅者信息，详见[IUsbdSubscriber](interface_i_usbd_subscriber.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### UnbindUsbdPortSubscriber()

```
IUsbPortInterface::UnbindUsbdPortSubscriber([in] IUsbdSubscriber subscriber);
```

**描述**

解绑订阅者。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| subscriber | 订阅者信息，详见[IUsbdSubscriber](interface_i_usbd_subscriber.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。
