# HdiHci

## 概述

HdiHci为HCI服务提供统一接口。

主机可以使用该模块提供的接口来初始化HCI（主机控制器接口），并通过该服务与控制器交换数据。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [HciTypes.idl](_hci_types_8idl.md) | 声明HCI模块使用的数据结构。 | 
| [IHciCallback.idl](_i_hci_callback_8idl.md) | 定义HCI回调函数，包含初始化结果和从控制器接收的数据。 | 
| [IHciInterface.idl](_i_hci_interface_8idl.md) | 声明接口以初始化HCI，向控制器发送数据及关闭HCI接口。 | 

### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IHciCallback](interface_i_hci_callback.md) | 定义HCI回调函数，包含初始化结果和从控制器接收的数据。 | 
| interface&nbsp;&nbsp;[IHciInterface](interface_i_hci_interface.md) | 声明接口以初始化HCI，向控制器发送数据及关闭HCI接口。 | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [BtStatus](#btstatus) { SUCCESS = 0 , INITIAL_ERROR = 1 , UNKNOWN = 2 } | 声明接口的操作结果。 | 
| [BtType](#bttype) { HCI_CMD = 1 , ACL_DATA = 2 , SCO_DATA = 3 , HCI_EVENT = 4 , ISO_DATA = 5 } | 声明通过HCI传输的数据类型。 | 

## 枚举类型说明


### BtStatus

```
enum BtStatus
```

**描述**

声明接口的操作结果。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| SUCCESS | 成功。 | 
| INITIAL_ERROR | 初始化失败。 | 
| UNKNOWN | 未知。 | 


### BtType

```
enum BtType
```

**描述**

声明通过HCI传输的数据类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| HCI_CMD | HCI命令。 | 
| ACL_DATA | ACL数据。 | 
| SCO_DATA | SCO数据。 | 
| HCI_EVENT | HCI事件。 | 
| ISO_DATA | ISO数据。| 
