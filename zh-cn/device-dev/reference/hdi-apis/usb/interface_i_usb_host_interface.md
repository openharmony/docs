# IUsbHostInterface


## 概述

**相关模块：**[HdiUsb](_hdi_usb_v2_0.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OpenDevice](#opendevice)([in] struct [UsbDev](_usb_dev.md) dev) | 打开设备，建立连接。 | 
| [CloseDevice](#closedevice)([in] struct [UsbDev](_usb_dev.md) dev) | 关闭设备，释放与设备相关的所有系统资源。 | 
| [ResetDevice](#resetdevice)([in] struct [UsbDev](_usb_dev.md) dev) | 重置设备。 | 
| [ClaimInterface](#claiminterface)([in] struct [UsbDev](_usb_dev.md) dev, [in] unsigned char interfaceid, [in] unsigned char force) | 打开USB设备的接口并声明独占，必须在数据传输前执行。 | 
| [SetInterface](#setinterface)([in] struct [UsbDev](_usb_dev.md) dev, [in] unsigned char interfaceid, [in] unsigned char altIndex) | 设置USB设备指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择。 | 
| [ReleaseInterface](#releaseinterface)([in] struct [UsbDev](_usb_dev.md) dev, [in] unsigned char interfaceid) | 在停止数据传输后关闭占用的USB设备接口，并释放相关资源。 | 
| [SetConfig](#setconfig)([in] struct [UsbDev](_usb_dev.md) dev, [in] unsigned char configIndex) | 设置USB设备当前的配置信息，USB设备被主机配置过后，主机可以使用设备提供的所有功能。 | 
| [ManageInterface](#manageinterface)([in] struct [UsbDev](_usb_dev.md) dev, [in] unsigned char interfaceid, [in] boolean disable) | 设置USB设备接口启动状态。 | 
| [ClearHalt](#clearhalt)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe) | 清除端点的暂停状态。 | 
| [GetDeviceSpeed](#getdevicespeed)([in] struct [UsbDev](_usb_dev.md) dev, [out] unsigned char speed) | 获取USB设备速率。 | 
| [GetDeviceFileDescriptor](#getdevicefiledescriptor)([in] struct [UsbDev](_usb_dev.md) dev, [out] FileDescriptor fd) | 获取文件描述符。 | 
| [GetStringDescriptor](#getstringdescriptor)([in] struct [UsbDev](_usb_dev.md) dev, [in] unsigned char descId, [out] unsigned char[] descriptor) | 根据设备的字符串ID获取字符串描述符，字符串描述符是提供一些设备接口相关的描述性信息，比如厂商的名字、产品序列号等。 | 
| [GetRawDescriptor](#getrawdescriptor)([in] struct [UsbDev](_usb_dev.md) dev, [out] unsigned char[] descriptor) | 获取USB设备的原始描述符。 | 
| [GetConfig](#getconfig)([in] struct [UsbDev](_usb_dev.md) dev, [out] unsigned char configIndex) | 获取USB设备当前的配置信息。 | 
| [GetInterfaceActiveStatus](#getinterfaceactivestatus)([in] struct [UsbDev](_usb_dev.md) dev, [in] unsigned char interfaceid, [out] boolean unactivated) | 获取USB设备接口的激活信息。 | 
| [GetDeviceDescriptor](#getdevicedescriptor)([in] struct [UsbDev](_usb_dev.md) dev, [out] unsigned char[] descriptor) | 获取设备描述符，设备描述符提供了关于设备、设备的配置以及任何设备所归属的类的信息。 | 
| [GetConfigDescriptor](#getconfigdescriptor)([in] struct [UsbDev](_usb_dev.md) dev, [in] unsigned char descId, [out] unsigned char[] descriptor) | 根据设备的配置ID获取配置描述符，配置描述符包含有关配置及其接口、备用设置及其终结点的信息。 | 
| [GetFileDescriptor](#getfiledescriptor)([in] struct [UsbDev](_usb_dev.md) dev, [out] int fd) | 获取USB设备的文件描述符。 | 
| [RequestQueue](#requestqueue)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe, [in] unsigned char[] clientData, [in] unsigned char[] buffer) | 在USB设备指定端点上进行异步数据发送或者接收请求，数据传输方向由端点方向决定。 | 
| [RequestWait](#requestwait)([in] struct [UsbDev](_usb_dev.md) dev, [out] unsigned char[] clientData, [out] unsigned char[] buffer, [in] int timeout) | 等待RequestQueue异步请求的操作结果。 | 
| [RequestCancel](#requestcancel)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe) | 取消待处理的数据请求。 | 
| [BulkTransferRead](#bulktransferread)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe, [in] int timeout, [out] unsigned char[] data) | 在USB设备指定端点方向为读取时，执行批量数据读取。 | 
| [BulkTransferWrite](#bulktransferwrite)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe, [in] int timeout, [in] unsigned char[] data) | 在USB设备指定端点方向为写入时，执行批量数据写入。 | 
| [BulkTransferReadwithLength](#bulktransferreadwithlength)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe, [in] int timeout, [in] int length, [out] unsigned char[] data) | 在USB设备指定端点方向为读取时，执行批量数据读取。 | 
| [RegBulkCallback](#regbulkcallback)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe, [in] [IUsbdBulkCallback](interface_i_usbd_bulk_callback.md) cb) | 注册批量传输异步回调函数。 | 
| [UnRegBulkCallback](#unregbulkcallback)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe) | 注销批量传输异步回调函数。 | 
| [BulkRead](#bulkread)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe, [in] Ashmem ashmem) | 批量传输异步读数据。 | 
| [BulkWrite](#bulkwrite)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe, [in] Ashmem ashmem) | 批量传输异步写数据。 | 
| [BulkCancel](#bulkcancel)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe) | 批量传输异步取消接口，用于取消当前接口的异步批量读写操作。 | 
| [ControlTransferRead](#controltransferread)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbCtrlTransfer](_usb_ctrl_transfer.md) ctrl, [out] unsigned char[] data) | 在传输状态为读取并且控制端点是端点零时，对USB设备执行控制传输。 | 
| [ControlTransferWrite](#controltransferwrite)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbCtrlTransfer](_usb_ctrl_transfer.md) ctrl, [in] unsigned char[] data) | 在传输状态为写入并且控制端点是端点零时，对USB设备执行控制传输。 | 
| [BulkTransferReadwithLength](#bulktransferreadwithlength)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbCtrlTransferParams](_usb_ctrl_transfer_params.md) ctrl, [out] unsigned char[] data) | 在传输状态为读取并且控制端点是端点零时，对USB设备执行控制传输。 | 
| [InterruptTransferRead](#interrupttransferread)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe, [in] int timeout, [out] unsigned char[] data) | 在USB设备指定端点方向为数据读取时执行中断数据读取。 | 
| [InterruptTransferWrite](#interrupttransferwrite)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe, [in] int timeout, [in] unsigned char[] data) | 在USB设备指定端点方向为写入时执行中断数据写入。 | 
| [IsoTransferRead](#isotransferread)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe, [in] int timeout, [out] unsigned char[] data) | 在USB设备指定端点方向为读取时执行等时数据读取。 | 
| [IsoTransferWrite](#isotransferwrite)([in] struct [UsbDev](_usb_dev.md) dev, [in] struct [UsbPipe](_usb_pipe.md) pipe, [in] int timeout, [in] unsigned char[] data) | 在USB设备指定端点方向为写入时执行等时数据写入。 | 
| [BindUsbdHostSubscriber](#bindusbdhostsubscriber)([in] [IUsbdSubscriber](interface_i_usbd_subscriber.md) subscriber) | 绑定订阅者。 | 
| [UnbindUsbdHostSubscriber](#unbindusbdhostsubscriber)([in] [IUsbdSubscriber](interface_i_usbd_subscriber.md) subscriber) | 解绑订阅者。 | 
| [UsbSubmitTransfer](#usbsubmittransfer)([in] struct [UsbDev](_usb_dev.md) dev, [in] [USBTransferInfo](_u_s_b_transfer_info_v2_0.md) info, [in] [IUsbdTransferCallback](interface_i_usbd_transfer_callback_v2_0.md) cb, [in] Ashmem ashmem) | 提交USB异步传输请求。 | 
| [UsbCancelTransfer](#usbcanceltransfer)([in] struct [UsbDev](_usb_dev.md) dev, [in] int endpoint) | 取消USB异步传输。 | 


## 成员函数说明


### OpenDevice()

```
IUsbdSubscriber::OpenDevice([in] struct UsbDev dev)
```

**描述**

打开设备，建立连接。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### CloseDevice()

```
IUsbdSubscriber::CloseDevice([in] struct UsbDev dev)
```

**描述**

关闭设备，释放与设备相关的所有系统资源。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ResetDevice()

```
IUsbdSubscriber::ResetDevice([in] struct UsbDev dev)
```

**描述**

重置设备。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ClaimInterface()

```
IUsbdSubscriber::ClaimInterface([in] struct UsbDev dev, [in] unsigned char interfaceid, [in] unsigned char force)
```

**描述**

打开USB设备的接口并声明独占，必须在数据传输前执行。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| interfaceid | USB设备接口ID。 | 
| force | 是否强制，1表示强制，0表示不强制。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SetInterface()

```
IUsbdSubscriber::SetInterface([in] struct UsbDev dev, [in] unsigned char interfaceid, [in] unsigned char altIndex)
```

**描述**

设置USB设备指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| interfaceid | USB设备接口ID。 | 
| altIndex | USB设备接口的备用设置信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ReleaseInterface()

```
IUsbdSubscriber::ReleaseInterface([in] struct UsbDev dev, [in] unsigned char interfaceid)
```

**描述**

在停止数据传输后关闭占用的USB设备接口，并释放相关资源。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| interfaceid | USB设备接口ID。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SetConfig()

```
IUsbdSubscriber::SetConfig([in] struct UsbDev dev, [in] unsigned char configIndex)
```

**描述**

设置USB设备当前的配置信息，USB设备被主机配置过后，主机可以使用设备提供的所有功能。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| configIndex | USB设备配置信息的字符串描述符索引值（数字字符串）。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ManageInterface()

```
IUsbdSubscriber::ManageInterface([in] struct UsbDev dev, [in] unsigned char interfaceid, [in] boolean disable);
```

**描述**

设置USB设备接口启动状态。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| interfaceid | USB设备接口ID。 | 
| disable | USB设备接口是否禁用,true表示禁用,false表示不禁用。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ClearHalt()

```
IUsbdSubscriber::ClearHalt([in] struct UsbDev dev, [in] struct UsbPipe pipe);
```

**描述**

清除端点的暂停状态。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息。 | 

**返回：**

0 表示操作成功。


### GetDeviceSpeed()

```
IUsbdSubscriber::GetDeviceSpeed([in] struct UsbDev dev, [out] unsigned char speed);
```

**描述**

获取USB设备速率。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| speed | USB设备速率。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetDeviceFileDescriptor()

```
IUsbdSubscriber::GetDeviceFileDescriptor([in] struct UsbDev dev, [out] FileDescriptor fd);
```

**描述**

获取文件描述符。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| fd | USB设备文件描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetStringDescriptor()

```
IUsbdSubscriber::GetStringDescriptor([in] struct UsbDev dev, [in] unsigned char descId, [out] unsigned char[] descriptor);
```

**描述**

根据设备的字符串ID获取字符串描述符，字符串描述符是提供一些设备接口相关的描述性信息，比如厂商的名字、产品序列号等。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| descId | USB设备的描述符ID。 | 
| descriptor | 获取USB设备的字符串描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetRawDescriptor()

```
IUsbdSubscriber::GetRawDescriptor([in] struct UsbDev dev, [out] unsigned char[] descriptor);
```

**描述**

获取USB设备的原始描述符。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| descriptor | USB设备的原始描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetConfig()

```
IUsbdSubscriber::GetConfig([in] struct UsbDev dev, [out] unsigned char configIndex);
```

**描述**

获取USB设备当前的配置信息。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| configIndex | USB设备配置信息的字符串描述符索引值（数字字符串）。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetInterfaceActiveStatus()

```
IUsbdSubscriber::GetInterfaceActiveStatus([in] struct UsbDev dev, [in] unsigned char interfaceid, [out] boolean unactivated );
```

**描述**

获取USB设备接口的激活信息。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| interfaceid | USB设备接口ID。 | 
| unactivated | USB设备接口激活状态。true表示未激活，false表示已激活。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetDeviceDescriptor()

```
IUsbdSubscriber::GetDeviceDescriptor([in] struct UsbDev dev, [out] unsigned char[] descriptor);
```

**描述**

获取设备描述符，设备描述符提供了关于设备、设备的配置以及任何设备所归属的类的信息。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| descriptor | USB设备配置信息的字符串描述符索引值（数字字符串）。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetConfigDescriptor()

```
IUsbdSubscriber::GetConfigDescriptor([in] struct UsbDev dev, [in] unsigned char descId, [out] unsigned char[] descriptor);
```

**描述**

根据设备的配置ID获取配置描述符，配置描述符包含有关配置及其接口、备用设置及其终结点的信息。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| descId | USB设备的配置ID。 | 
| descriptor | 获取USB设备配置信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetFileDescriptor()

```
IUsbdSubscriber::GetFileDescriptor([in] struct UsbDev dev, [out] int fd);
```

**描述**

获取USB设备的文件描述符。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| fd | USB设备的文件描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### RequestQueue()

```
IUsbdSubscriber::RequestQueue([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] unsigned char[] clientData, [in] unsigned char[] buffer);
```

**描述**

在USB设备指定端点上进行异步数据发送或者接收请求，数据传输方向由端点方向决定。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| clientData | 用户数据。 | 
| buffer | 传输的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### RequestWait()

```
IUsbdSubscriber::RequestWait([in] struct UsbDev dev, [out] unsigned char[] clientData, [out] unsigned char[] buffer, [in] int timeout);
```

**描述**

等待RequestQueue异步请求的操作结果。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| clientData | 用户数据。 | 
| buffer | 传输的数据。 | 
| timeout | 超时时间。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### RequestCancel()

```
IUsbdSubscriber::RequestCancel([in] struct UsbDev dev, [in] struct UsbPipe pipe);
```

**描述**

取消待处理的数据请求。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkTransferRead()

```
IUsbdSubscriber::BulkTransferRead([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [out] unsigned char[] data);
```

**描述**

在USB设备指定端点方向为读取时，执行批量数据读取。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| timeout | 超时时间。 | 
| data | 读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkTransferWrite()

```
IUsbdSubscriber::BulkTransferWrite([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] unsigned char[] data);
```

**描述**

在USB设备指定端点方向为写入时，执行批量数据写入。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| timeout | 超时时间。 | 
| data | 写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkTransferReadwithLength()

```
IUsbdSubscriber::BulkTransferReadwithLength([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] int length, [out] unsigned char[] data);
```

**描述**

在USB设备指定端点方向为读取时，执行批量数据读取。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息。 | 
| timeout | 超时时间。 | 
| length | 读取的最大字节长度。 | 
| data | 读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### RegBulkCallback()

```
IUsbdSubscriber::RegBulkCallback([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] IUsbdBulkCallback cb);
```

**描述**

注册批量传输异步回调函数。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| cb | 回调函数对象，详见[IUsbdBulkCallback](interface_i_usbd_bulk_callback.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### UnRegBulkCallback()

```
IUsbdSubscriber::UnRegBulkCallback([in] struct UsbDev dev, [in] struct UsbPipe pipe);
```

**描述**

注销批量传输异步回调函数。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkRead()

```
IUsbdSubscriber::BulkRead([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] Ashmem ashmem);
```

**描述**

批量传输异步读数据。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| ashmem | 共享内存，用于存放读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkWrite()

```
IUsbdSubscriber::BulkWrite([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] Ashmem ashmem);
```

**描述**

批量传输异步写数据。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| ashmem | 为共享内存，用于存放需要写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkCancel()

```
IUsbdSubscriber:: BulkCancel([in] struct UsbDev dev, [in] struct UsbPipe pipe);
```

**描述**

批量传输异步取消接口，用于取消当前接口的异步批量读写操作。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ControlTransferRead()

```
IUsbdSubscriber::ControlTransferRead([in] struct UsbDev dev, [in] struct UsbCtrlTransfer ctrl, [out] unsigned char[] data);
```

**描述**

在传输状态为读取并且控制端点是端点零时，对USB设备执行控制传输。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| ctrl | USB设备控制数据，[UsbCtrlTransfer](_usb_ctrl_transfer.md)。 | 
| data | 读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ControlTransferWrite()

```
IUsbdSubscriber::ControlTransferWrite([in] struct UsbDev dev, [in] struct UsbCtrlTransfer ctrl, [in] unsigned char[] data);
```

**描述**

获取USB设备当前的配置信息。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| ctrl | USB设备控制数据，[UsbCtrlTransfer](_usb_ctrl_transfer.md)。 | 
| data | 写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ControlTransferReadwithLength()

```
IUsbdSubscriber::ControlTransferReadwithLength([in] struct UsbDev dev, [in] struct UsbCtrlTransferParams ctrl, [out] unsigned char[] data);
```

**描述**

在传输状态为读取并且控制端点是端点零时，对USB设备执行控制传输。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| ctrl | USB设备控制数据。 | 
| data | 写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### InterruptTransferRead()

```
IUsbdSubscriber::InterruptTransferRead([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [out] unsigned char[] data);
```

**描述**

在USB设备指定端点方向为数据读取时执行中断数据读取。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息。 | 
| timeout | 超时时间。 | 
| data | 读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### InterruptTransferWrite()

```
IUsbdSubscriber::InterruptTransferWrite([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] unsigned char[] data);
```

**描述**

在USB设备指定端点方向为写入时执行中断数据写入。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息。 | 
| timeout | 超时时间。 | 
| data | 写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### IsoTransferRead()

```
IUsbdSubscriber::IsoTransferRead([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [out] unsigned char[] data);
```

**描述**

在USB设备指定端点方向为读取时执行等时数据读取。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息。 | 
| timeout | 超时时间。 | 
| data | 读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### IsoTransferWrite()

```
IUsbdSubscriber::IsoTransferWrite([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] unsigned char[] data);
```

**描述**

USB设备指定端点方向为写入时执行等时数据写入。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息。 | 
| timeout | 超时时间。 | 
| data | 写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BindUsbdHostSubscriber()

```
IUsbdSubscriber::BindUsbdHostSubscriber([in] IUsbdSubscriber subscriber);
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


### UnbindUsbdHostSubscriber()

```
IUsbdSubscriber::UnbindUsbdHostSubscriber([in] IUsbdSubscriber subscriber);
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


### UsbSubmitTransfer()

```
IUsbdSubscriber::UsbSubmitTransfer([in] struct UsbDev dev, [in] USBTransferInfo info, [in] IUsbdTransferCallback cb, [in] Ashmem ashmem);
```

**描述**

提交USB异步传输请求。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| info | USB传输信息实体。 | 
| cb | USB传输回调函数。 | 
| ashmem | 共享内存对象实体。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### UsbCancelTransfer()

```
IUsbdSubscriber::UsbCancelTransfer([in] struct UsbDev dev, [in] int endpoint);
```

**描述**

取消USB异步传输。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| endpoint | USB设备传输端点值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。
