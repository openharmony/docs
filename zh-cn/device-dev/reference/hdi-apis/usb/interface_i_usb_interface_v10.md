# IUsbInterface


## 概述

定义USB驱动基本的操作功能。

上层USB服务调用相关功能接口，可以打开/关闭设备，获取设备描述符，批量读取/写入数据等。

**起始版本：** 3.2

**相关模块：**[USB](_u_s_b_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OpenDevice](#opendevice) ([in] struct [UsbDev](_usb_dev_v10.md) dev) | 打开设备，建立连接。  | 
| [CloseDevice](#closedevice) ([in] struct [UsbDev](_usb_dev_v10.md) dev) | 关闭设备，释放与设备相关的所有系统资源。  | 
| [GetDeviceDescriptor](#getdevicedescriptor) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [out] unsigned char[] descriptor) | 获取设备描述符，设备描述符提供了关于设备、设备的配置以及任何设备所归属的类的信息。  | 
| [GetStringDescriptor](#getstringdescriptor) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char descId, [out] unsigned char[] descriptor) | 根据设备的字符串ID获取字符串描述符，字符串描述符是提供一些设备接口相关的描述性信息，比如厂商的名字、产品序列号等。  | 
| [GetConfigDescriptor](#getconfigdescriptor) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char descId, [out] unsigned char[] descriptor) | 根据设备的配置ID获取配置描述符，配置描述符包含有关配置及其接口、备用设置及其终结点的信息。  | 
| [GetRawDescriptor](#getrawdescriptor) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [out] unsigned char[] descriptor) | 获取USB设备的原始描述符。  | 
| [GetFileDescriptor](#getfiledescriptor) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [out] int fd) | 获取USB设备的文件描述符。  | 
| [SetConfig](#setconfig) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char configIndex) | 设置USB设备当前的配置信息，USB设备被主机配置过后，主机可以使用设备提供的所有功能。  | 
| [GetConfig](#getconfig) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [out] unsigned char configIndex) | 获取USB设备当前的配置信息。  | 
| [ClaimInterface](#claiminterface) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char interfaceid, [in] unsigned char force) | 打开USB设备的接口并声明独占，必须在数据传输前执行。  | 
| [ReleaseInterface](#releaseinterface) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char interfaceid) | 在停止数据传输后关闭占用的USB设备接口，并释放相关资源。  | 
| [ManageInterface](#manageinterface) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char interfaceid, [in] bool disable) | 设置USB设备接口启动状态。  | 
| [SetInterface](#setinterface) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char interfaceid, [in] unsigned char altIndex) | 设置USB设备指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择。  | 
| [BulkTransferRead](#bulktransferread) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] int timeout, [out] unsigned char[] data) | 在USB设备指定端点方向为读取时，执行批量数据读取。  | 
| [BulkTransferWrite](#bulktransferwrite) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] int timeout, [in] unsigned char[] data) | 在USB设备指定端点方向为写入时，执行批量数据写入。  | 
| [ControlTransferRead](#controltransferread) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbCtrlTransfer](_usb_ctrl_transfer_v10.md) ctrl, [out] unsigned char[] data) | 在传输状态为读取并且控制端点是端点零时，对USB设备执行控制传输。  | 
| [ControlTransferWrite](#controltransferwrite) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbCtrlTransfer](_usb_ctrl_transfer_v10.md) ctrl, [in] unsigned char[] data) | 在传输状态为写入并且控制端点是端点零时，对USB设备执行控制传输。  | 
| [InterruptTransferRead](#interrupttransferread) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] int timeout, [out] unsigned char[] data) | 在USB设备指定端点方向为数据读取时执行中断数据读取。  | 
| [InterruptTransferWrite](#interrupttransferwrite) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] int timeout, [in] unsigned char[] data) | 在USB设备指定端点方向为写入时执行中断数据写入。  | 
| [IsoTransferRead](#isotransferread) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] int timeout, [out] unsigned char[] data) | 在USB设备指定端点方向为读取时执行等时数据读取。  | 
| [IsoTransferWrite](#isotransferwrite) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] int timeout, [in] unsigned char[] data) | 在USB设备指定端点方向为写入时执行等时数据写入。  | 
| [RequestQueue](#requestqueue) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] unsigned char[] clientData, [in] unsigned char[] buffer) | 在USB设备指定端点上进行异步数据发送或者接收请求，数据传输方向由端点方向决定。  | 
| [RequestWait](#requestwait) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [out] unsigned char[] clientData, [out] unsigned char[] buffer, [in] int timeout) | 等待RequestQueue异步请求的操作结果。  | 
| [RequestCancel](#requestcancel) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe) | 取消待处理的数据请求。  | 
| [GetCurrentFunctions](#getcurrentfunctions) ([out] int funcs) | 获取USB设备当前的功能（按位域表示）。  | 
| [SetCurrentFunctions](#setcurrentfunctions) ([in] int funcs) | 设置USB设备当前的功能（按位域表示）。  | 
| [SetPortRole](#setportrole) ([in] int portId, [in] int powerRole, [in] int dataRole) | 设置USB设备端口的角色。  | 
| [QueryPort](#queryport) ([out] int portId, [out] int powerRole, [out] int dataRole, [out] int mode) | 查询USB设备端口的当前设置信息。  | 
| [BindUsbdSubscriber](#bindusbdsubscriber) ([in] [IUsbdSubscriber](interface_i_usbd_subscriber_v10.md) subscriber) | 绑定订阅者。  | 
| [UnbindUsbdSubscriber](#unbindusbdsubscriber) ([in] [IUsbdSubscriber](interface_i_usbd_subscriber_v10.md) subscriber) | 解绑订阅者。  | 
| [RegBulkCallback](#regbulkcallback) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] [IUsbdBulkCallback](interface_i_usbd_bulk_callback_v10.md) cb) | 注册批量传输异步回调函数。  | 
| [UnRegBulkCallback](#unregbulkcallback) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe) | 注销批量传输异步回调函数。  | 
| [BulkRead](#bulkread) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] Ashmem ashmem) | 批量传输异步读数据。  | 
| [BulkWrite](#bulkwrite) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] Ashmem ashmem) | 批量传输异步写数据。  | 
| [BulkCancel](#bulkcancel) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe) | 批量传输异步取消接口，用于取消当前接口的异步批量读写操作。  | 


## 成员函数说明


### BindUsbdSubscriber()

```
IUsbInterface::BindUsbdSubscriber ([in] IUsbdSubscriber subscriber)
```
**描述**

绑定订阅者。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| subscriber | 订阅者信息，详见[IUsbdSubscriber](interface_i_usbd_subscriber_v10.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkCancel()

```
IUsbInterface::BulkCancel ([in] struct UsbDev dev, [in] struct UsbPipe pipe )
```
**描述**

批量传输异步取消接口，用于取消当前接口的异步批量读写操作。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkRead()

```
IUsbInterface::BulkRead ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] Ashmem ashmem )
```
**描述**

批量传输异步读数据。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。  | 
| ashmem | 共享内存，用于存放读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkTransferRead()

```
IUsbInterface::BulkTransferRead ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [out] unsigned char[] data )
```
**描述**

在USB设备指定端点方向为读取时，执行批量数据读取。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。  | 
| timeout | 超时时间。  | 
| data | 读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkTransferWrite()

```
IUsbInterface::BulkTransferWrite ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] unsigned char[] data )
```
**描述**

在USB设备指定端点方向为写入时，执行批量数据写入。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。  | 
| timeout | 超时时间。  | 
| data | 写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkWrite()

```
IUsbInterface::BulkWrite ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] Ashmem ashmem )
```
**描述**

批量传输异步写数据。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。  | 
| ashmem | 为共享内存，用于存放需要写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ClaimInterface()

```
IUsbInterface::ClaimInterface ([in] struct UsbDev dev, [in] unsigned char interfaceid, [in] unsigned char force )
```
**描述**

打开USB设备的接口并声明独占，必须在数据传输前执行。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| interfaceid | USB设备接口ID。  | 
| force | 是否强制，1表示强制，0表示不强制。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### CloseDevice()

```
IUsbInterface::CloseDevice ([in] struct UsbDev dev)
```
**描述**

关闭设备，释放与设备相关的所有系统资源。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ControlTransferRead()

```
IUsbInterface::ControlTransferRead ([in] struct UsbDev dev, [in] struct UsbCtrlTransfer ctrl, [out] unsigned char[] data )
```
**描述**

在传输状态为读取并且控制端点是端点零时，对USB设备执行控制传输。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| ctrl | USB设备控制数据，详见[UsbCtrlTransfer](_usb_ctrl_transfer_v10.md)。  | 
| data | 读取的数据。 | 

**返回：**

0 表示成功。

非零值 表示失败。


### ControlTransferWrite()

```
IUsbInterface::ControlTransferWrite ([in] struct UsbDev dev, [in] struct UsbCtrlTransfer ctrl, [in] unsigned char[] data )
```
**描述**

在传输状态为写入并且控制端点是端点零时，对USB设备执行控制传输。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| ctrl | USB设备控制数据，详见[UsbCtrlTransfer](_usb_ctrl_transfer_v10.md)。  | 
| data | 写入的数据。 | 

**返回：**

0 表示成功。

非零值 表示失败。


### GetConfig()

```
IUsbInterface::GetConfig ([in] struct UsbDev dev, [out] unsigned char configIndex )
```
**描述**

获取USB设备当前的配置信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| configIndex | USB设备配置信息的字符串描述符索引值（数字字符串）。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetConfigDescriptor()

```
IUsbInterface::GetConfigDescriptor ([in] struct UsbDev dev, [in] unsigned char descId, [out] unsigned char[] descriptor )
```
**描述**

根据设备的配置ID获取配置描述符，配置描述符包含有关配置及其接口、备用设置及其终结点的信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| descId | USB设备的配置ID。  | 
| descriptor | 获取USB设备配置信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetCurrentFunctions()

```
IUsbInterface::GetCurrentFunctions ([out] int funcs)
```
**描述**

获取USB设备当前的功能（按位域表示）。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| funcs | 设备当前的功能值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetDeviceDescriptor()

```
IUsbInterface::GetDeviceDescriptor ([in] struct UsbDev dev, [out] unsigned char[] descriptor )
```
**描述**

获取设备描述符，设备描述符提供了关于设备、设备的配置以及任何设备所归属的类的信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| descriptor | USB设备的描述符信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetFileDescriptor()

```
IUsbInterface::GetFileDescriptor ([in] struct UsbDev dev, [out] int fd )
```
**描述**

获取USB设备的文件描述符。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| fd | USB设备的文件描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetRawDescriptor()

```
IUsbInterface::GetRawDescriptor ([in] struct UsbDev dev, [out] unsigned char[] descriptor )
```
**描述**

获取USB设备的原始描述符。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| descriptor | USB设备的原始描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetStringDescriptor()

```
IUsbInterface::GetStringDescriptor ([in] struct UsbDev dev, [in] unsigned char descId, [out] unsigned char[] descriptor )
```
**描述**

根据设备的字符串ID获取字符串描述符，字符串描述符是提供一些设备接口相关的描述性信息，比如厂商的名字、产品序列号等。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| descId | USB设备的描述符ID。  | 
| descriptor | 获取USB设备的字符串描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### InterruptTransferRead()

```
IUsbInterface::InterruptTransferRead ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [out] unsigned char[] data )
```
**描述**

在USB设备指定端点方向为数据读取时执行中断数据读取。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。  | 
| timeout | 超时时间。  | 
| data | 读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### InterruptTransferWrite()

```
IUsbInterface::InterruptTransferWrite ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] unsigned char[] data )
```
**描述**

在USB设备指定端点方向为写入时执行中断数据写入。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。  | 
| timeout | 超时时间。  | 
| data | 写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### IsoTransferRead()

```
IUsbInterface::IsoTransferRead ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [out] unsigned char[] data )
```
**描述**

在USB设备指定端点方向为读取时执行等时数据读取。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。  | 
| timeout | 超时时间。  | 
| data | 读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### IsoTransferWrite()

```
IUsbInterface::IsoTransferWrite ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] unsigned char[] data )
```
**描述**

在USB设备指定端点方向为写入时执行等时数据写入。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。  | 
| timeout | 超时时间。  | 
| data | 写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ManageInterface()

```
IUsbInterface::ManageInterface ([in] struct UsbDev dev, [in] unsigned char interfaceid, [in] bool disable )
```
**描述**

设置USB设备接口启动状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| interfaceid | USB设备接口ID。  | 
| disable | USB设备接口是否禁用,true表示禁用,false表示不禁用。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### OpenDevice()

```
IUsbInterface::OpenDevice ([in] struct UsbDev dev)
```
**描述**

打开设备，建立连接。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### QueryPort()

```
IUsbInterface::QueryPort ([out] int portId, [out] int powerRole, [out] int dataRole, [out] int mode )
```
**描述**

查询USB设备端口的当前设置信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| portId | USB设备端口ID。  | 
| powerRole | USB设备电源角色。  | 
| dataRole | USB设备数据角色。  | 
| mode | USB设备模式。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### RegBulkCallback()

```
IUsbInterface::RegBulkCallback ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] IUsbdBulkCallback cb )
```
**描述**

注册批量传输异步回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。  | 
| cb | 回调函数对象，详见[IUsbdBulkCallback](interface_i_usbd_bulk_callback_v10.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ReleaseInterface()

```
IUsbInterface::ReleaseInterface ([in] struct UsbDev dev, [in] unsigned char interfaceid )
```
**描述**

在停止数据传输后关闭占用的USB设备接口，并释放相关资源。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| interfaceid | USB设备接口ID。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### RequestCancel()

```
IUsbInterface::RequestCancel ([in] struct UsbDev dev, [in] struct UsbPipe pipe )
```
**描述**

取消待处理的数据请求。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### RequestQueue()

```
IUsbInterface::RequestQueue ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] unsigned char[] clientData, [in] unsigned char[] buffer )
```
**描述**

在USB设备指定端点上进行异步数据发送或者接收请求，数据传输方向由端点方向决定。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。  | 
| clientData | 用户数据。  | 
| buffer | 传输的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### RequestWait()

```
IUsbInterface::RequestWait ([in] struct UsbDev dev, [out] unsigned char[] clientData, [out] unsigned char[] buffer, [in] int timeout )
```
**描述**

等待RequestQueue异步请求的操作结果。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| clientData | 用户数据。  | 
| buffer | 传输的数据。  | 
| timeout | 超时时间。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SetConfig()

```
IUsbInterface::SetConfig ([in] struct UsbDev dev, [in] unsigned char configIndex )
```
**描述**

设置USB设备当前的配置信息，USB设备被主机配置过后，主机可以使用设备提供的所有功能。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| configIndex | USB设备配置信息的字符串描述符索引值（数字字符串）。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SetCurrentFunctions()

```
IUsbInterface::SetCurrentFunctions ([in] int funcs)
```
**描述**

设置USB设备当前的功能（按位域表示）。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| funcs | 待设置的设备功能值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SetInterface()

```
IUsbInterface::SetInterface ([in] struct UsbDev dev, [in] unsigned char interfaceid, [in] unsigned char altIndex )
```
**描述**

设置USB设备指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| interfaceid | USB设备接口ID。  | 
| altIndex | USB设备接口的备用设置信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SetPortRole()

```
IUsbInterface::SetPortRole ([in] int portId, [in] int powerRole, [in] int dataRole )
```
**描述**

设置USB设备端口的角色。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| portId | USB设备端口ID。  | 
| powerRole | 电源角色的值。  | 
| dataRole | 数据角色的值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### UnbindUsbdSubscriber()

```
IUsbInterface::UnbindUsbdSubscriber ([in] IUsbdSubscriber subscriber)
```
**描述**

解绑订阅者。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| subscriber | 订阅者信息，详见[IUsbdSubscriber](interface_i_usbd_subscriber_v10.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### UnRegBulkCallback()

```
IUsbInterface::UnRegBulkCallback ([in] struct UsbDev dev, [in] struct UsbPipe pipe )
```
**描述**

注销批量传输异步回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev_v10.md)。  | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe_v10.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。
