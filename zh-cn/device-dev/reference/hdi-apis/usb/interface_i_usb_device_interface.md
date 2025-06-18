# IUsbDeviceInterface


## 概述

**相关模块：**[HdiUsb](_hdi_usb_v2_0.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetCurrentFunctions](#getcurrentfunctions-)([out] int funcs) | 获取USB设备当前的功能（按位域表示）。 | 
| [SetCurrentFunctions](#setcurrentfunctions)([in] int funcs) | 设置USB设备当前的功能（按位域表示）。 | 
| [GetAccessoryInfo](#getaccessoryinfo)([out] String[] accessoryInfo) | 获取配件信息。 | 
| [OpenAccessory](#openaccessory)([out] FileDescriptor fd) | 打开配件描述符。 | 
| [CloseAccessory](#closeaccessory)([in] FileDescriptor fd) | 关闭配件描述符。 | 
| [BindUsbdDeviceSubscriber](#bindusbddevicesubscriber)([in] [IUsbdSubscriber](interface_i_usbd_subscriber.md) subscriber) | 绑定订阅者。 | 
| [UnbindUsbdDeviceSubscriber](#unbindusbddevicesubscriber)([in] [IUsbdSubscriber](interface_i_usbd_subscriber.md) subscriber) | 解绑订阅者。 | 


## 成员函数说明


### GetCurrentFunctions ()

```
IUsbDeviceInterface::GetCurrentFunctions ([out] int funcs)
```

**描述**

获取USB设备当前的功能（按位域表示）。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| funcs | 设备当前的功能值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SetCurrentFunctions()

```
IUsbDeviceInterface::SetCurrentFunctions([out] int funcs)
```

**描述**

设置USB设备当前的功能（按位域表示）。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| funcs | 设备当前的功能值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetAccessoryInfo()

```
IUsbDeviceInterface::GetAccessoryInfo([out] String[] accessoryInfo)
```

**描述**

获取配件信息。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| accessoryInfo | 表示配件信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### OpenAccessory()

```
IUsbDeviceInterface::OpenAccessory([out] FileDescriptor fd)
```

**描述**

打开配件描述符。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fd | 配件的文件描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### CloseAccessory()

```
IUsbDeviceInterface::CloseAccessory([in] FileDescriptor fd)
```

**描述**

关闭配件描述符。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fd | 配件的文件描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BindUsbdDeviceSubscriber()

```
IUsbDeviceInterface::BindUsbdDeviceSubscriber([in] IUsbdSubscriber subscriber)
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


### UnbindUsbdDeviceSubscriber()

```
IUsbDeviceInterface::UnbindUsbdDeviceSubscriber([in] IUsbdSubscriber subscriber)
```

**描述**

解绑订阅者。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| subscriber | 订阅者信息，[IUsbdSubscriber](interface_i_usbd_subscriber.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。
