# IUsbInterface


## **概述**

定义USB驱动基本的操作功能。

上层USB服务调用相关功能接口，可以打开/关闭设备，获取设备描述符，批量读取/写入数据等。

**相关模块:**

[USB](usb.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OpenDevice](#opendevice)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev) | 打开设备，建立连接。 | 
| [CloseDevice](#closedevice)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev) | 关闭设备，释放与设备相关的所有系统资源。 | 
| [GetDeviceDescriptor](#getdevicedescriptor)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[out]&nbsp;unsigned&nbsp;char[]&nbsp;descriptor) | 获取设备描述符，设备描述符提供了关于设备、设备的配置以及任何设备所归属的类的信息。 | 
| [GetStringDescriptor](#getstringdescriptor)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;unsigned&nbsp;char&nbsp;descId,&nbsp;[out]&nbsp;unsigned&nbsp;char[]&nbsp;descriptor) | 根据设备的字符串ID获取字符串描述符，字符串描述符是提供一些设备接口相关的描述性信息，比如厂商的名字、产品序列号等。 | 
| [GetConfigDescriptor](#getconfigdescriptor)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;unsigned&nbsp;char&nbsp;descId,&nbsp;[out]&nbsp;unsigned&nbsp;char[]&nbsp;descriptor) | 根据设备的配置ID获取配置描述符，配置描述符包含有关配置及其接口、备用设置及其终结点的信息。 | 
| [GetRawDescriptor](#getrawdescriptor)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[out]&nbsp;unsigned&nbsp;char[]&nbsp;descriptor) | 获取USB设备的原始描述符。 | 
| [GetFileDescriptor](#getfiledescriptor)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[out]&nbsp;int&nbsp;fd) | 获取USB设备的文件描述符。 | 
| [SetConfig](#setconfig)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;unsigned&nbsp;char&nbsp;configIndex) | 设置USB设备当前的配置信息，USB设备被主机配置过后，主机可以使用设备提供的所有功能。 | 
| [GetConfig](#getconfig)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[out]&nbsp;unsigned&nbsp;char&nbsp;configIndex) | 获取USB设备当前的配置信息。 | 
| [ClaimInterface](#claiminterface)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;unsigned&nbsp;char&nbsp;interfaceid,&nbsp;[in]&nbsp;unsigned&nbsp;char&nbsp;force) | 打开USB设备的接口并声明独占，必须在数据传输前执行。 | 
| [ReleaseInterface](#releaseinterface)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;unsigned&nbsp;char&nbsp;interfaceid) | 在停止数据传输后关闭占用的USB设备接口，并释放相关资源。 | 
| [SetInterface](#setinterface)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;unsigned&nbsp;char&nbsp;interfaceid,&nbsp;[in]&nbsp;unsigned&nbsp;char&nbsp;altIndex) | 设置USB设备指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择。 | 
| [BulkTransferRead](#bulktransferread)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe,&nbsp;[in]&nbsp;int&nbsp;timeout,&nbsp;[out]&nbsp;unsigned&nbsp;char[]&nbsp;data) | 在USB设备指定端点方向为读取时，执行批量数据读取。 | 
| [BulkTransferWrite](#bulktransferwrite)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe,&nbsp;[in]&nbsp;int&nbsp;timeout,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;data) | 在USB设备指定端点方向为写入时，执行批量数据写入。 | 
| [ControlTransferRead](#controltransferread)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbCtrlTransfer](_usb_ctrl_transfer.md)&nbsp;ctrl,&nbsp;[out]&nbsp;unsigned&nbsp;char[]&nbsp;data) | 在传输状态为读取并且控制端点是端点零时，对USB设备执行控制传输。 | 
| [ControlTransferWrite](#controltransferwrite)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbCtrlTransfer](_usb_ctrl_transfer.md)&nbsp;ctrl,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;data) | 在传输状态为写入并且控制端点是端点零时，对USB设备执行控制传输。 | 
| [InterruptTransferRead](#interrupttransferread)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe,&nbsp;[in]&nbsp;int&nbsp;timeout,&nbsp;[out]&nbsp;unsigned&nbsp;char[]&nbsp;data) | 在USB设备指定端点方向为数据读取时执行中断数据读取。 | 
| [InterruptTransferWrite](#interrupttransferwrite)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe,&nbsp;[in]&nbsp;int&nbsp;timeout,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;data) | 在USB设备指定端点方向为写入时执行中断数据写入。 | 
| [IsoTransferRead](#isotransferread)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe,&nbsp;[in]&nbsp;int&nbsp;timeout,&nbsp;[out]&nbsp;unsigned&nbsp;char[]&nbsp;data) | 在USB设备指定端点方向为读取时执行等时数据读取。 | 
| [IsoTransferWrite](#isotransferwrite)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe,&nbsp;[in]&nbsp;int&nbsp;timeout,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;data) | 在USB设备指定端点方向为写入时执行等时数据写入。 | 
| [RequestQueue](#requestqueue)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;clientData,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;buffer) | 在USB设备指定端点上进行异步数据发送或者接收请求，数据传输方向由端点方向决定。 | 
| [RequestWait](#requestwait)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[out]&nbsp;unsigned&nbsp;char[]&nbsp;clientData,&nbsp;[out]&nbsp;unsigned&nbsp;char[]&nbsp;buffer,&nbsp;[in]&nbsp;int&nbsp;timeout) | 等待RequestQueue异步请求的操作结果。 | 
| [RequestCancel](#requestcancel)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe) | 取消待处理的数据请求。 | 
| [GetCurrentFunctions](#getcurrentfunctions)&nbsp;([out]&nbsp;int&nbsp;funcs) | 获取USB设备当前的功能（按位域表示）。 | 
| [SetCurrentFunctions](#setcurrentfunctions)&nbsp;([in]&nbsp;int&nbsp;funcs) | 设置USB设备当前的功能（按位域表示）。 | 
| [SetPortRole](#setportrole)&nbsp;([in]&nbsp;int&nbsp;portId,&nbsp;[in]&nbsp;int&nbsp;powerRole,&nbsp;[in]&nbsp;int&nbsp;dataRole) | 设置USB设备端口的角色。 | 
| [QueryPort](#queryport)&nbsp;([out]&nbsp;int&nbsp;portId,&nbsp;[out]&nbsp;int&nbsp;powerRole,&nbsp;[out]&nbsp;int&nbsp;dataRole,&nbsp;[out]&nbsp;int&nbsp;mode) | 查询USB设备端口的当前设置信息。 | 
| [BindUsbdSubscriber](#bindusbdsubscriber)&nbsp;([in]&nbsp;[IUsbdSubscriber](interface_i_usbd_subscriber.md)&nbsp;subscriber) | 绑定订阅者。 | 
| [UnbindUsbdSubscriber](#unbindusbdsubscriber)&nbsp;([in]&nbsp;[IUsbdSubscriber](interface_i_usbd_subscriber.md)&nbsp;subscriber) | 解绑订阅者。 | 
| [RegBulkCallback](#regbulkcallback)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe,&nbsp;[in]&nbsp;[IUsbdBulkCallback](interface_i_usbd_bulk_callback.md)&nbsp;cb) | 注册批量传输异步回调函数。 | 
| [UnRegBulkCallback](#unregbulkcallback)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe) | 注销批量传输异步回调函数。 | 
| [BulkRead](#bulkread)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe,&nbsp;[in]&nbsp;Ashmem&nbsp;ashmem) | 批量传输异步读数据。 | 
| [BulkWrite](#bulkwrite)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe,&nbsp;[in]&nbsp;Ashmem&nbsp;ashmem) | 批量传输异步写数据。 | 
| [BulkCancel](#bulkcancel)&nbsp;([in]&nbsp;struct&nbsp;[UsbDev](_usb_dev.md)&nbsp;dev,&nbsp;[in]&nbsp;struct&nbsp;[UsbPipe](_usb_pipe.md)&nbsp;pipe) | 批量传输异步取消接口，用于取消当前接口的异步批量读写操作。 | 


## **成员函数说明**


### BindUsbdSubscriber()

  
```
IUsbInterface::BindUsbdSubscriber ([in] IUsbdSubscriber subscriber)
```

**描述：**

绑定订阅者。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| subscriber | 订阅者信息，详见[IUsbdSubscriber](interface_i_usbd_subscriber.md)。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### BulkCancel()

  
```
IUsbInterface::BulkCancel ([in] struct UsbDev dev, [in] struct UsbPipe pipe )
```

**描述：**

批量传输异步取消接口，用于取消当前接口的异步批量读写操作。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### BulkRead()

  
```
IUsbInterface::BulkRead ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] Ashmem ashmem )
```

**描述：**

批量传输异步读数据。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| ashmem | 共享内存，用于存放读取的数据。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### BulkTransferRead()

  
```
IUsbInterface::BulkTransferRead ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [out] unsigned char[] data )
```

**描述：**

在USB设备指定端点方向为读取时，执行批量数据读取。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| timeout | 超时时间。 | 
| data | 读取的数据。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### BulkTransferWrite()

  
```
IUsbInterface::BulkTransferWrite ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] unsigned char[] data )
```

**描述：**

在USB设备指定端点方向为写入时，执行批量数据写入。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| timeout | 超时时间。 | 
| data | 写入的数据。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### BulkWrite()

  
```
IUsbInterface::BulkWrite ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] Ashmem ashmem )
```

**描述：**

批量传输异步写数据。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| ashmem | 为共享内存，用于存放需要写入的数据。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### ClaimInterface()

  
```
IUsbInterface::ClaimInterface ([in] struct UsbDev dev, [in] unsigned char interfaceid, [in] unsigned char force )
```

**描述：**

打开USB设备的接口并声明独占，必须在数据传输前执行。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| interfaceid | USB设备接口ID。 | 
| force | 是否强制，1表示强制，0表示不强制。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### CloseDevice()

  
```
IUsbInterface::CloseDevice ([in] struct UsbDev dev)
```

**描述：**

关闭设备，释放与设备相关的所有系统资源。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### ControlTransferRead()

  
```
IUsbInterface::ControlTransferRead ([in] struct UsbDev dev, [in] struct UsbCtrlTransfer ctrl, [out] unsigned char[] data )
```

**描述：**

在传输状态为读取并且控制端点是端点零时，对USB设备执行控制传输。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| ctrl | USB设备控制数据，详见[UsbCtrlTransfer](_usb_ctrl_transfer.md)。 | 
| data | 读取的数据。 | 

**返回:**

0 表示成功。

非零值 表示失败。


### ControlTransferWrite()

  
```
IUsbInterface::ControlTransferWrite ([in] struct UsbDev dev, [in] struct UsbCtrlTransfer ctrl, [in] unsigned char[] data )
```

**描述：**

在传输状态为写入并且控制端点是端点零时，对USB设备执行控制传输。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| ctrl | USB设备控制数据，详见[UsbCtrlTransfer](_usb_ctrl_transfer.md)。 | 
| data | 写入的数据。 | 

**返回:**

0 表示成功。

非零值 表示失败。


### GetConfig()

  
```
IUsbInterface::GetConfig ([in] struct UsbDev dev, [out] unsigned char configIndex )
```

**描述：**

获取USB设备当前的配置信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| configIndex | USB设备配置信息的字符串描述符索引值（数字字符串）。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### GetConfigDescriptor()

  
```
IUsbInterface::GetConfigDescriptor ([in] struct UsbDev dev, [in] unsigned char descId, [out] unsigned char[] descriptor )
```

**描述：**

根据设备的配置ID获取配置描述符，配置描述符包含有关配置及其接口、备用设置及其终结点的信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| descId | USB设备的配置ID。 | 
| descriptor | 获取USB设备配置信息。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### GetCurrentFunctions()

  
```
IUsbInterface::GetCurrentFunctions ([out] int funcs)
```

**描述：**

获取USB设备当前的功能（按位域表示）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 设备当前的功能值。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### GetDeviceDescriptor()

  
```
IUsbInterface::GetDeviceDescriptor ([in] struct UsbDev dev, [out] unsigned char[] descriptor )
```

**描述：**

获取设备描述符，设备描述符提供了关于设备、设备的配置以及任何设备所归属的类的信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| descriptor | USB设备的描述符信息。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### GetFileDescriptor()

  
```
IUsbInterface::GetFileDescriptor ([in] struct UsbDev dev, [out] int fd )
```

**描述：**

获取USB设备的文件描述符。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| fd | USB设备的文件描述符。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### GetRawDescriptor()

  
```
IUsbInterface::GetRawDescriptor ([in] struct UsbDev dev, [out] unsigned char[] descriptor )
```

**描述：**

获取USB设备的原始描述符。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| descriptor | USB设备的原始描述符。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### GetStringDescriptor()

  
```
IUsbInterface::GetStringDescriptor ([in] struct UsbDev dev, [in] unsigned char descId, [out] unsigned char[] descriptor )
```

**描述：**

根据设备的字符串ID获取字符串描述符，字符串描述符是提供一些设备接口相关的描述性信息，比如厂商的名字、产品序列号等。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| descId | USB设备的描述符ID。 | 
| descriptor | 获取USB设备的字符串描述符。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### InterruptTransferRead()

  
```
IUsbInterface::InterruptTransferRead ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [out] unsigned char[] data )
```

**描述：**

在USB设备指定端点方向为数据读取时执行中断数据读取。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| timeout | 超时时间。 | 
| data | 读取的数据。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### InterruptTransferWrite()

  
```
IUsbInterface::InterruptTransferWrite ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] unsigned char[] data )
```

**描述：**

在USB设备指定端点方向为写入时执行中断数据写入。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| timeout | 超时时间。 | 
| data | 写入的数据。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### IsoTransferRead()

  
```
IUsbInterface::IsoTransferRead ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [out] unsigned char[] data )
```

**描述：**

在USB设备指定端点方向为读取时执行等时数据读取。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| timeout | 超时时间。 | 
| data | 读取的数据。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### IsoTransferWrite()

  
```
IUsbInterface::IsoTransferWrite ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] unsigned char[] data )
```

**描述：**

在USB设备指定端点方向为写入时执行等时数据写入。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| timeout | 超时时间。 | 
| data | 写入的数据。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### OpenDevice()

  
```
IUsbInterface::OpenDevice ([in] struct UsbDev dev)
```

**描述：**

打开设备，建立连接。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### QueryPort()

  
```
IUsbInterface::QueryPort ([out] int portId, [out] int powerRole, [out] int dataRole, [out] int mode )
```

**描述：**

查询USB设备端口的当前设置信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| portId | USB设备端口ID。 | 
| powerRole | USB设备电源角色。 | 
| dataRole | USB设备数据角色。 | 
| mode | USB设备模式。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### RegBulkCallback()

  
```
IUsbInterface::RegBulkCallback ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] IUsbdBulkCallback cb )
```

**描述：**

注册批量传输异步回调函数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| cb | 回调函数对象，详见[IUsbdBulkCallback](interface_i_usbd_bulk_callback.md)。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### ReleaseInterface()

  
```
IUsbInterface::ReleaseInterface ([in] struct UsbDev dev, [in] unsigned char interfaceid )
```

**描述：**

在停止数据传输后关闭占用的USB设备接口，并释放相关资源。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| interfaceid | USB设备接口ID。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### RequestCancel()

  
```
IUsbInterface::RequestCancel ([in] struct UsbDev dev, [in] struct UsbPipe pipe )
```

**描述：**

取消待处理的数据请求。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### RequestQueue()

  
```
IUsbInterface::RequestQueue ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] unsigned char[] clientData, [in] unsigned char[] buffer )
```

**描述：**

在USB设备指定端点上进行异步数据发送或者接收请求，数据传输方向由端点方向决定。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 
| clientData | 用户数据。 | 
| buffer | 传输的数据。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### RequestWait()

  
```
IUsbInterface::RequestWait ([in] struct UsbDev dev, [out] unsigned char[] clientData, [out] unsigned char[] buffer, [in] int timeout )
```

**描述：**

等待RequestQueue异步请求的操作结果。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| clientData | 用户数据。 | 
| buffer | 传输的数据。 | 
| timeout | 超时时间。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### SetConfig()

  
```
IUsbInterface::SetConfig ([in] struct UsbDev dev, [in] unsigned char configIndex )
```

**描述：**

设置USB设备当前的配置信息，USB设备被主机配置过后，主机可以使用设备提供的所有功能。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| configIndex | USB设备配置信息的字符串描述符索引值（数字字符串）。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### SetCurrentFunctions()

  
```
IUsbInterface::SetCurrentFunctions ([in] int funcs)
```

**描述：**

设置USB设备当前的功能（按位域表示）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 待设置的设备功能值。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### SetInterface()

  
```
IUsbInterface::SetInterface ([in] struct UsbDev dev, [in] unsigned char interfaceid, [in] unsigned char altIndex )
```

**描述：**

设置USB设备指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| interfaceid | USB设备接口ID。 | 
| altIndex | USB设备接口的备用设置信息。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### SetPortRole()

  
```
IUsbInterface::SetPortRole ([in] int portId, [in] int powerRole, [in] int dataRole )
```

**描述：**

设置USB设备端口的角色。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| portId | USB设备端口ID。 | 
| powerRole | 电源角色的值。 | 
| dataRole | 数据角色的值。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### UnbindUsbdSubscriber()

  
```
IUsbInterface::UnbindUsbdSubscriber ([in] IUsbdSubscriber subscriber)
```

**描述：**

解绑订阅者。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| subscriber | 订阅者信息，详见[IUsbdSubscriber](interface_i_usbd_subscriber.md)。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### UnRegBulkCallback()

  
```
IUsbInterface::UnRegBulkCallback ([in] struct UsbDev dev, [in] struct UsbPipe pipe )
```

**描述：**

注销批量传输异步回调函数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | USB设备地址信息，详见[UsbDev](_usb_dev.md)。 | 
| pipe | USB设备管道信息，详见[UsbPipe](_usb_pipe.md)。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。
