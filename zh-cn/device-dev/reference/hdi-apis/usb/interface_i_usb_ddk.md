# IUsbDdk


## 概述

声明USB主机用于访问USB设备的USB DDK API。

上层USB服务调用相关功能接口，可以打开/关闭设备，获取设备描述符，批量读取/写入数据等。

**起始版本：** 4.0

**相关模块：**[HdiUsbDdk](_hdi_usb_ddk.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [Init](#init) () | 初始化DDK。  | 
| [Release](#release) () | 在停止数据传输后关闭占用的USB设备接口，并释放相关资源。  | 
| [GetDeviceDescriptor](#getdevicedescriptor) ([in] unsigned long deviceId, [out] struct [UsbDeviceDescriptor](_usb_device_descriptor.md) desc) | 获取USB设备描述符。  | 
| [GetConfigDescriptor](#getconfigdescriptor) ([in] unsigned long deviceId, [in] unsigned char configIndex, [out] List&lt; unsigned char &gt; configDesc) | 获取配置描述符。  | 
| [ClaimInterface](#claiminterface) ([in] unsigned long deviceId, [in] unsigned char interfaceIndex, [out] unsigned long interfaceHandle) | 声明USB接口。  | 
| [ReleaseInterface](#releaseinterface) ([in] unsigned long interfaceHandle) | 在停止数据传输后关闭占用的USB设备接口，并释放相关资源。  | 
| [SelectInterfaceSetting](#selectinterfacesetting) ([in] unsigned long interfaceHandle, [in] unsigned char settingIndex) | 激活USB接口的备用设置。  | 
| [GetCurrentInterfaceSetting](#getcurrentinterfacesetting) ([in] unsigned long interfaceHandle, [out] unsigned char settingIndex) | 获取USB接口的激活备用设置。  | 
| [SendControlReadRequest](#sendcontrolreadrequest) ([in] unsigned long interfaceHandle, [in] struct [UsbControlRequestSetup](_usb_control_request_setup.md) setup, [in] unsigned int timeout, [out] List&lt; unsigned char &gt; data) | 发送控制读取传输请求。此API以同步方式工作。  | 
| [SendControlWriteRequest](#sendcontrolwriterequest) ([in] unsigned long interfaceHandle, [in] struct [UsbControlRequestSetup](_usb_control_request_setup.md) setup, [in] unsigned int timeout, [in] List&lt; unsigned char &gt; data) | 发送控制写入传输请求。此API以同步方式工作。  | 
| [SendPipeRequest](#sendpiperequest) ([in] struct [UsbRequestPipe](_usb_request_pipe.md) pipe, [in] unsigned int size, [in] unsigned int offset, [in] unsigned int length, [out] unsigned int transferedLength) | 发送管道请求。此API以同步方式工作。此API适用于中断传输和批量传输。  | 
| [GetDeviceMemMapFd](#getdevicememmapfd) ([in] unsigned long deviceId, [out] FileDescriptor fd) | 获取内存映射的文件描述符。  | 


## 成员函数说明


### ClaimInterface()

```
IUsbDdk::ClaimInterface ([in] unsigned long deviceId, [in] unsigned char interfaceIndex, [out] unsigned long interfaceHandle )
```
**描述**

声明USB接口。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceId | 要操作的设备的ID。  | 
| interfaceIndex | 接口索引，对应于USB协议中的**b接口编号**。  | 
| interfaceHandle | 接口操作处理。成功声明接口后，将为此参数分配一个值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetConfigDescriptor()

```
IUsbDdk::GetConfigDescriptor ([in] unsigned long deviceId, [in] unsigned char configIndex, [out] List< unsigned char > configDesc )
```
**描述**

获取配置描述符。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceId | 要获取其描述符的设备的设备Id。  | 
| configIndex | 配置索引，对应于USB协议中的**bConfigurationValue**。  | 
| configDesc | 配置描述符，包括USB协议中定义的标准配置描述符以及相关的接口描述符和端点描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetCurrentInterfaceSetting()

```
IUsbDdk::GetCurrentInterfaceSetting ([in] unsigned long interfaceHandle, [out] unsigned char settingIndex )
```
**描述**

获取USB接口的激活备用设置。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| interfaceHandle | 接口操作处理。  | 
| settingIndex | 备用设置的索引，对应于USB协议中的**bAlternateSetting**。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetDeviceDescriptor()

```
IUsbDdk::GetDeviceDescriptor ([in] unsigned long deviceId, [out] struct UsbDeviceDescriptor desc )
```
**描述**

获取USB设备描述符。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceId | 要获取其描述符的设备的设备Id。  | 
| desc | USB协议中定义的标准设备描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### GetDeviceMemMapFd()

```
IUsbDdk::GetDeviceMemMapFd ([in] unsigned long deviceId, [out] FileDescriptor fd )
```
**描述**

获取内存映射的文件描述符。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceId | 待操作设备的ID。  | 
| fd | 为内存映射获取的文件描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### Init()

```
IUsbDdk::Init ()
```
**描述**

初始化DDK。

**起始版本：** 4.0

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### Release()

```
IUsbDdk::Release ()
```
**描述**

在停止数据传输后关闭占用的USB设备接口，并释放相关资源。

**起始版本：** 4.0

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### ReleaseInterface()

```
IUsbDdk::ReleaseInterface ([in] unsigned long interfaceHandle)
```
**描述**

在停止数据传输后关闭占用的USB设备接口，并释放相关资源。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| interfaceHandle | 接口操作处理。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SelectInterfaceSetting()

```
IUsbDdk::SelectInterfaceSetting ([in] unsigned long interfaceHandle, [in] unsigned char settingIndex )
```
**描述**

激活USB接口的备用设置。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| interfaceHandle | 接口操作处理。  | 
| settingIndex | 备用设置的索引，对应于USB协议中的**bAlternateSetting**。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SendControlReadRequest()

```
IUsbDdk::SendControlReadRequest ([in] unsigned long interfaceHandle, [in] struct UsbControlRequestSetup setup, [in] unsigned int timeout, [out] List< unsigned char > data )
```
**描述**

发送控制读取传输请求。此API以同步方式工作。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| interfaceHandle | 接口操作处理。  | 
| setup | 请求数据，对应于USB协议中的**Setup Data**。  | 
| timeout | 超时持续时间，以毫秒为单位。  | 
| data | 要传输的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SendControlWriteRequest()

```
IUsbDdk::SendControlWriteRequest ([in] unsigned long interfaceHandle, [in] struct UsbControlRequestSetup setup, [in] unsigned int timeout, [in] List< unsigned char > data )
```
**描述**

发送控制写入传输请求。此API以同步方式工作。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| interfaceHandle | 接口操作处理。  | 
| setup | 请求数据，对应于USB协议中的**Setup Data**。  | 
| timeout | 超时持续时间，以毫秒为单位。  | 
| data | 要传输的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SendPipeRequest()

```
IUsbDdk::SendPipeRequest ([in] struct UsbRequestPipe pipe, [in] unsigned int size, [in] unsigned int offset, [in] unsigned int length, [out] unsigned int transferedLength )
```
**描述**

发送管道请求。此API以同步方式工作。此API适用于中断传输和批量传输。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| 管道用于传输数据的管道。 |  | 
| size | 缓冲区大小。  | 
| offset | 所用缓冲区的偏移量。默认值为0，表示没有偏移，缓冲区从指定地址开始。  | 
| length | 使用的缓冲区的长度。默认情况下，该值等于大小，表示使用了整个缓冲区。  | 
| transferedLength | 传输数据的长度。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。
