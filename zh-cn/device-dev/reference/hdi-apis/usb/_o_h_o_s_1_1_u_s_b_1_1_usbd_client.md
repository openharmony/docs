# UsbdClient


## 概述

USB驱动客户端类。

**起始版本：** 3.0

**相关模块：**[USB](_u_s_b.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OpenDevice](#opendevice) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev) | 打开设备，建立连接。 | 
| [CloseDevice](#closedevice) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev) | 关闭设备，释放与设备相关的所有系统资源。 | 
| [GetDeviceDescriptor](#getdevicedescriptor) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, std::vector&lt; uint8_t &gt; &amp;descriptor) | 获取设备描述符。 | 
| [GetStringDescriptor](#getstringdescriptor) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, uint8_t descId, std::vector&lt; uint8_t &gt; &amp;descriptor) | 根据String ID获取设备的字符串描述符。 | 
| [GetConfigDescriptor](#getconfigdescriptor) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, uint8_t descId, std::vector&lt; uint8_t &gt; &amp;descriptor) | 根据config ID获取设备的配置描述符config。 | 
| [GetRawDescriptor](#getrawdescriptor) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, std::vector&lt; uint8_t &gt; &amp;descriptor) | 获取原始描述符。 | 
| [GetFileDescriptor](#getfiledescriptor) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, int32_t &amp;fd) | 获取文件描述符。 | 
| [SetConfig](#setconfig) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, uint8_t configIndex) | 设置当前的config信息。 | 
| [GetConfig](#getconfig) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, uint8_t &amp;configIndex) | 获取当前的config信息。 | 
| [ClaimInterface](#claiminterface) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, uint8_t interfaceid, uint8_t force) | 打开接口，并声明独占接口，必须在数据传输前执行。 | 
| [ReleaseInterface](#releaseinterface) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, uint8_t interfaceid) | 关闭接口，释放接口的占用，在停止数据传输后执行。 | 
| [SetInterface](#setinterface) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, uint8_t interfaceid, uint8_t altIndex) | 设置指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择。 | 
| [BulkTransferRead](#bulktransferread) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe, int32_t timeout, std::vector&lt; uint8_t &gt; &amp;data) | 在给定端点上执行批量数据读取，返回读取的数据和长度，端点方向必须为数据读取，可以设置超时时间。 | 
| [BulkTransferWrite](#bulktransferwrite) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe, int32_t timeout, const std::vector&lt; uint8_t &gt; &amp;data) | 在给定端点上执行批量数据写入， 返回读取的数据和长度，端点方向必须为数据写入。 | 
| [ControlTransfer](#controltransfer) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbCtrlTransfer](_o_h_o_s_1_1_u_s_b_1_1_usb_ctrl_transfer.md) &amp;ctrl, std::vector&lt; uint8_t &gt; &amp;data) | 对此设备执行端点零的控制事务，传输方向由请求类型决定。 如果requestType＆ USB_ENDPOINT_DIR_MASK是USB_DIR_OUT ，则传输是写入，如果是USB_DIR_IN ，则传输是读取。 | 
| [InterruptTransferRead](#interrupttransferread) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe, int32_t timeout, std::vector&lt; uint8_t &gt; &amp;data) | 在给定端点上执行中断数据读取， 返回读取的数据和长度，端点方向必须为数据读取。 | 
| [InterruptTransferWrite](#interrupttransferwrite) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe, int32_t timeout, std::vector&lt; uint8_t &gt; &amp;data) | 在给定端点上执行中断数据写入， 返回读取的数据和长度，端点方向必须为数据写入。 | 
| [IsoTransferRead](#isotransferread) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe, int32_t timeout, std::vector&lt; uint8_t &gt; &amp;data) | 在给定端点上执行等时数据读取， 返回读取的数据和长度，端点方向必须为数据读取。 | 
| [IsoTransferWrite](#isotransferwrite) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe, int32_t timeout, std::vector&lt; uint8_t &gt; &amp;data) | 在给定端点上执行等时数据写入， 返回读取的数据和长度，端点方向必须为数据写入。 | 
| [RequestQueue](#requestqueue) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe, const std::vector&lt; uint8_t &gt; &amp;clientData, const std::vector&lt; uint8_t &gt; &amp;buffer) | 将指定的端点进行异步数据发送或者接收请求，数据传输方向由端点方向决定。 | 
| [RequestWait](#requestwait) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, std::vector&lt; uint8_t &gt; &amp;clientData, std::vector&lt; uint8_t &gt; &amp;buffer, int32_t timeout) | 等待RequestQueue异步请求的操作结果。 | 
| [RequestCancel](#requestcancel) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe) | 取消待处理的数据请求。 | 
| [GetCurrentFunctions](#getcurrentfunctions) (int32_t &amp;funcs) | 获取从设备支持的功能列表（按位域表示）（从设备）。 | 
| [SetCurrentFunctions](#setcurrentfunctions) (int32_t funcs) | 设置从设备支持的功能列表（按位域表示）（从设备）。 | 
| [SetPortRole](#setportrole) (int32_t portId, int32_t powerRole, int32_t dataRole) | 设置port端口的角色。 | 
| [QueryPort](#queryport) (int32_t &amp;portId, int32_t &amp;powerRole, int32_t &amp;dataRole, int32_t &amp;mode) | 查询port端口的当前设置。 | 
| [BindUsbdSubscriber](#bindusbdsubscriber) (const sptr&lt; [UsbdSubscriber](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md) &gt; &amp;subscriber) | 绑定订阅者。 | 
| [UnbindUsbdSubscriber](#unbindusbdsubscriber) (const sptr&lt; [UsbdSubscriber](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md) &gt; &amp;subscriber) | 解绑订阅者。 | 
| [RegBulkCallback](#regbulkcallback) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe, const sptr&lt; IRemoteObject &gt; &amp;cb) | 注册批量传输异步回调函数。 | 
| [UnRegBulkCallback](#unregbulkcallback) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe) | 注销批量传输异步回调函数。 | 
| [BulkRead](#bulkread) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe, sptr&lt; Ashmem &gt; &amp;ashmem) | 批量传输异步读数据。 | 
| [BulkWrite](#bulkwrite) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe, sptr&lt; Ashmem &gt; &amp;ashmem) | 批量传输异步写数据。 | 
| [BulkCancel](#bulkcancel) (const [UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) &amp;dev, const [UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) &amp;pipe) | 批量传输异步取消接口，用于取消当前接口的异步批量读写操作。 | 


### 静态 Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetInstance](#getinstance) () | USB驱动类获取实例。 | 


## 成员函数说明


### BindUsbdSubscriber()

```
int32_t UsbdClient::BindUsbdSubscriber (const sptr< UsbdSubscriber > & subscriber)
```

**描述**


绑定订阅者。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| subscriber | 输入参数，订阅者信息，详见[UsbdSubscriber](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkCancel()

```
int32_t UsbdClient::BulkCancel (const UsbDev & dev, const UsbPipe & pipe )
```

**描述**


批量传输异步取消接口，用于取消当前接口的异步批量读写操作。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkRead()

```
int32_t UsbdClient::BulkRead (const UsbDev & dev, const UsbPipe & pipe, sptr< Ashmem > & ashmem )
```

**描述**


批量传输异步读数据。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| ashmem | 输出参数，为共享内存，用于存放读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkTransferRead()

```
int32_t UsbdClient::BulkTransferRead (const UsbDev & dev, const UsbPipe & pipe, int32_t timeout, std::vector< uint8_t > & data )
```

**描述**


在给定端点上执行批量数据读取，返回读取的数据和长度，端点方向必须为数据读取，可以设置超时时间。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| timeout | 输入参数，超时时间。 | 
| data | 输出参数，获取写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkTransferWrite()

```
int32_t UsbdClient::BulkTransferWrite (const UsbDev & dev, const UsbPipe & pipe, int32_t timeout, const std::vector< uint8_t > & data )
```

**描述**


在给定端点上执行批量数据写入， 返回读取的数据和长度，端点方向必须为数据写入。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| timeout | 输入参数，超时时间。 | 
| data | 输入参数，写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### BulkWrite()

```
int32_t UsbdClient::BulkWrite (const UsbDev & dev, const UsbPipe & pipe, sptr< Ashmem > & ashmem )
```

**描述**


批量传输异步写数据。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| ashmem | 输入参数，为共享内存，用于存放需要写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ClaimInterface()

```
int32_t UsbdClient::ClaimInterface (const UsbDev & dev, uint8_t interfaceid, uint8_t force )
```

**描述**


打开接口，并声明独占接口，必须在数据传输前执行。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| interfaceid | 输入参数，USB设备interface ID。 | 
| force | 输入参数，是否强制: 1强制 0不强制。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### CloseDevice()

```
int32_t UsbdClient::CloseDevice (const UsbDev & dev)
```

**描述**


关闭设备，释放与设备相关的所有系统资源。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ControlTransfer()

```
int32_t UsbdClient::ControlTransfer (const UsbDev & dev, const UsbCtrlTransfer & ctrl, std::vector< uint8_t > & data )
```

**描述**


对此设备执行端点零的控制事务，传输方向由请求类型决定。 如果requestType＆ USB_ENDPOINT_DIR_MASK是USB_DIR_OUT ，则传输是写入，如果是USB_DIR_IN ，则传输是读取。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| ctrl | 输入参数，USB设备控制数据包结构，详见[UsbCtrlTransfer](_o_h_o_s_1_1_u_s_b_1_1_usb_ctrl_transfer.md)。 | 
| data | 输入/输出参数，读取/写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetConfig()

```
int32_t UsbdClient::GetConfig (const UsbDev & dev, uint8_t & configIndex )
```

**描述**


获取当前的config信息。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| configIndex | 输出参数，USB设备config信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetConfigDescriptor()

```
int32_t UsbdClient::GetConfigDescriptor (const UsbDev & dev, uint8_t descId, std::vector< uint8_t > & descriptor )
```

**描述**


根据config ID获取设备的配置描述符config。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| descId | 输入参数，USB的config ID。 | 
| descriptor | 输出参数，获取USB设备config信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetCurrentFunctions()

```
int32_t UsbdClient::GetCurrentFunctions (int32_t & funcs)
```

**描述**


获取从设备支持的功能列表（按位域表示）（从设备）。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，获取当前设备的function的值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetDeviceDescriptor()

```
int32_t UsbdClient::GetDeviceDescriptor (const UsbDev & dev, std::vector< uint8_t > & descriptor )
```

**描述**


获取设备描述符。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| descriptor | 输出参数，USB设备描述符信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetFileDescriptor()

```
int32_t UsbdClient::GetFileDescriptor (const UsbDev & dev, int32_t & fd )
```

**描述**


获取文件描述符。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| fd | 输出参数，USB设备文件描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetInstance()

```
static UsbdClient & UsbdClient::GetInstance ()
```

**描述**


USB驱动类获取实例。

**起始版本：** 3.0


### GetRawDescriptor()

```
int32_t UsbdClient::GetRawDescriptor (const UsbDev & dev, std::vector< uint8_t > & descriptor )
```

**描述**


获取原始描述符。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| descriptor | 输出参数，USB设备原始描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetStringDescriptor()

```
int32_t UsbdClient::GetStringDescriptor (const UsbDev & dev, uint8_t descId, std::vector< uint8_t > & descriptor )
```

**描述**


根据String ID获取设备的字符串描述符。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| descId | 输入参数，USB的string ID。 | 
| descriptor | 输出参数，获取USB设备config信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### InterruptTransferRead()

```
int32_t UsbdClient::InterruptTransferRead (const UsbDev & dev, const UsbPipe & pipe, int32_t timeout, std::vector< uint8_t > & data )
```

**描述**


在给定端点上执行中断数据读取， 返回读取的数据和长度，端点方向必须为数据读取。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| timeout | 输入参数，超时时间。 | 
| data | 输出参数，读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### InterruptTransferWrite()

```
int32_t UsbdClient::InterruptTransferWrite (const UsbDev & dev, const UsbPipe & pipe, int32_t timeout, std::vector< uint8_t > & data )
```

**描述**


在给定端点上执行中断数据写入， 返回读取的数据和长度，端点方向必须为数据写入。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| timeout | 输入参数，超时时间。 | 
| data | 输入参数，写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### IsoTransferRead()

```
int32_t UsbdClient::IsoTransferRead (const UsbDev & dev, const UsbPipe & pipe, int32_t timeout, std::vector< uint8_t > & data )
```

**描述**


在给定端点上执行等时数据读取， 返回读取的数据和长度，端点方向必须为数据读取。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| timeout | 输入参数，超时时间。 | 
| data | 输出参数，读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### IsoTransferWrite()

```
int32_t UsbdClient::IsoTransferWrite (const UsbDev & dev, const UsbPipe & pipe, int32_t timeout, std::vector< uint8_t > & data )
```

**描述**


在给定端点上执行等时数据写入， 返回读取的数据和长度，端点方向必须为数据写入。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| timeout | 输入参数，超时时间。 | 
| data | 输入参数，读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### OpenDevice()

```
int32_t UsbdClient::OpenDevice (const UsbDev & dev)
```

**描述**


打开设备，建立连接。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### QueryPort()

```
int32_t UsbdClient::QueryPort (int32_t & portId, int32_t & powerRole, int32_t & dataRole, int32_t & mode )
```

**描述**


查询port端口的当前设置。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| portId | 输出参数，port接口ID。 | 
| powerRole | 输出参数，电源角色的值。 | 
| dataRole | 输出参数，数据角色的值。 | 
| mode | 输出参数，模式的值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### RegBulkCallback()

```
int32_t UsbdClient::RegBulkCallback (const UsbDev & dev, const UsbPipe & pipe, const sptr< IRemoteObject > & cb )
```

**描述**


注册批量传输异步回调函数。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| cb | 输入参数，回调函数对象的引用。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ReleaseInterface()

```
int32_t UsbdClient::ReleaseInterface (const UsbDev & dev, uint8_t interfaceid )
```

**描述**


关闭接口，释放接口的占用，在停止数据传输后执行。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| interfaceid | 输入参数，USB设备interface ID。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### RequestCancel()

```
int32_t UsbdClient::RequestCancel (const UsbDev & dev, const UsbPipe & pipe )
```

**描述**


取消待处理的数据请求。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### RequestQueue()

```
int32_t UsbdClient::RequestQueue (const UsbDev & dev, const UsbPipe & pipe, const std::vector< uint8_t > & clientData, const std::vector< uint8_t > & buffer )
```

**描述**


将指定的端点进行异步数据发送或者接收请求，数据传输方向由端点方向决定。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| clientData | 输入参数，用户数据。 | 
| buffer | 输入参数，传输的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### RequestWait()

```
int32_t UsbdClient::RequestWait (const UsbDev & dev, std::vector< uint8_t > & clientData, std::vector< uint8_t > & buffer, int32_t timeout )
```

**描述**


等待RequestQueue异步请求的操作结果。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| clientData | 输入参数，用户数据。 | 
| buffer | 输入参数，传输数据。 | 
| timeout | 输入参数，超时时间。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SetConfig()

```
int32_t UsbdClient::SetConfig (const UsbDev & dev, uint8_t configIndex )
```

**描述**


设置当前的config信息。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| configIndex | 输入参数，USB设备config信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SetCurrentFunctions()

```
int32_t UsbdClient::SetCurrentFunctions (int32_t funcs)
```

**描述**


设置从设备支持的功能列表（按位域表示）（从设备）。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| funcs | 输入参数，传入设备支持的function的值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SetInterface()

```
int32_t UsbdClient::SetInterface (const UsbDev & dev, uint8_t interfaceid, uint8_t altIndex )
```

**描述**


设置指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| interfaceid | 输入参数，USB设备interface ID。 | 
| altIndex | 输入参数，interface的AlternateSetting信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SetPortRole()

```
int32_t UsbdClient::SetPortRole (int32_t portId, int32_t powerRole, int32_t dataRole )
```

**描述**


设置port端口的角色。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| portId | 输入参数，port接口ID。 | 
| powerRole | 输入参数，电源角色的值。 | 
| dataRole | 输入参数，数据角色的值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### UnbindUsbdSubscriber()

```
int32_t UsbdClient::UnbindUsbdSubscriber (const sptr< UsbdSubscriber > & subscriber)
```

**描述**


解绑订阅者。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| subscriber | 输入参数，订阅者信息，详见[UsbdSubscriber](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### UnRegBulkCallback()

```
int32_t UsbdClient::UnRegBulkCallback (const UsbDev & dev, const UsbPipe & pipe )
```

**描述**


注销批量传输异步回调函数。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。
