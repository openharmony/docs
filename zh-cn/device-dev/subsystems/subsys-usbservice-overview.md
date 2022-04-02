# USB服务概述


## 概述

USB设备分为Host设备（主机设备）和Device设备（从设备）。用户可通过Port Service来根据实际业务把运行OpenHarmony的设备切换为Host设备或者Device设备。目前在Host模式下，支持获取USB设备列表，USB设备权限管理，控制传输、批量传输的同异步数据传输等，在Device模式下，支持HDC（调试）、ACM（串口）、ECM（网口）等功能的切换。

  **图1** USB服务架构图
  ![zh-cn_image_0000001267088285](figures/zh-cn_image_0000001267088285.png)

- USB FWK/API：基于USB Service服务，使用NAPI技术，向上提供JS接口。

- USB Service：使用C++代码实现，包含Host、Device、Port三个模块。基于HDI的接口，主要实现USB设备的列表管理、Function 管理、Port管理、USB设备权限管理等功能。

- USB HAL：使用C代码实现，基于Host SDK和Device SDK，封装了对USB设备的基本操作，向上提供C++接口，同时通过HDF框架接收内核上报的信息。


## 接口说明

- Host部分

  | 头文件 | 接口名称 | 功能描述 | 
| -------- | -------- | -------- |
| usb_srv_client.h | int32_t&nbsp;OpenDevice(const&nbsp;UsbDevice&nbsp;&amp;device,&nbsp;USBDevicePipe&nbsp;&amp;pip); | 打开USB设备，建立连接 | 
|  | int32_t&nbsp;HasRight(std::string&nbsp;deviceName); | 判断是否有权访问设备 | 
|  | int32_t&nbsp;RequestRight(std::string&nbsp;deviceName); | 请求给定软件包的临时权限以访问设备 | 
|  | int32_t&nbsp;GetDevices(std::vector&nbsp;&amp;deviceList); | 获取USB设备列表 | 
|  | int32_t&nbsp;ClaimInterface(USBDevicePipe&nbsp;&amp;pip,&nbsp;const&nbsp;UsbInterface&nbsp;&amp;interface,&nbsp;bool&nbsp;force); | 打开接口，并申明独占接口，必须在数据传输前执行 | 
|  | int32_t&nbsp;ReleaseInterface(USBDevicePipe&nbsp;&amp;pip,&nbsp;const&nbsp;UsbInterface&nbsp;&amp;interface); | 关闭接口，释放接口的占用，在停止数据传输后执行 | 
|  | int32_t&nbsp;BulkTransfer(USBDevicePipe&nbsp;&amp;pip,&nbsp;const&nbsp;USBEndpoint&nbsp;&amp;endpoint,&nbsp;std::vector&nbsp;&amp;vdata,&nbsp;int32_t&nbsp;timeout); | 在给定端点上执行批量数据传输，&nbsp;返回读取或发送的数据长度，通过端点方向确定读取或发送数据 | 
|  | int32_t&nbsp;ControlTransfer(USBDevicePipe&nbsp;&amp;pip,&nbsp;const&nbsp;UsbCtrlTransfer&nbsp;&amp;ctrl,&nbsp;std::vector&nbsp;&amp;vdata); | 对此设备执行端点零的控制事务，传输方向由请求类型决定 | 
|  | int32_t&nbsp;SetConfiguration(USBDevicePipe&nbsp;&amp;pip,&nbsp;const&nbsp;USBConfig&nbsp;&amp;config); | 设置设备当前使用的配置，通过配置值进行指定 | 
|  | int32_t&nbsp;SetInterface(USBDevicePipe&nbsp;&amp;pipe,&nbsp;const&nbsp;UsbInterface&nbsp;&amp;interface); | 设置指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择 | 
|  | int32_t&nbsp;GetRawDescriptors(std::vector&nbsp;&amp;vdata); | 获取原始的USB描述符 | 
|  | int32_t&nbsp;GetFileDescriptor(); | 获取文件描述符 | 
|  | bool&nbsp;Close(const&nbsp;USBDevicePipe&nbsp;&amp;pip); | 关闭设备，释放与设备相关的所有系统资源 | 
|  | int32_t&nbsp;PipeRequestWait(USBDevicePipe&nbsp;&amp;pip,&nbsp;int64_t&nbsp;timeout,&nbsp;UsbRequest&nbsp;&amp;req); | 获取异步传输结果 | 
|  | int32_t&nbsp;RequestInitialize(UsbRequest&nbsp;&amp;request); | 初始化异步数据传输request | 
|  | int32_t&nbsp;RequestFree(UsbRequest&nbsp;&amp;request); | 释放异步数据传输request | 
|  | int32_t&nbsp;RequestAbort(UsbRequest&nbsp;&amp;request); | 取消待处理的数据请求 | 
|  | int32_t&nbsp;RequestQueue(UsbRequest&nbsp;&amp;request); | 将指定的端点进行异步数据发送或者接收请求，数据传输方向由端点方向决定 | 
|  | int32_t&nbsp;BulkRequstDataSize(const&nbsp;UsbDev&nbsp;&amp;dev,&nbsp;const&nbsp;UsbPipe&nbsp;&amp;pipe,&nbsp;uint32_t&nbsp;&amp;length); | 异步批量读取数据，传输大量数据时使用 | 
|  | int32_t&nbsp;BulkReadData(const&nbsp;UsbDev&nbsp;&amp;dev,&nbsp;const&nbsp;UsbPipe&nbsp;&amp;pipe,&nbsp;std::vector&nbsp;&amp;data); | 与BulkReadData配合使用，获取读取结果 | 
|  | int32_t&nbsp;BulkWriteData(const&nbsp;UsbDev&nbsp;&amp;dev,&nbsp;const&nbsp;UsbPipe&nbsp;&amp;pipe,&nbsp;const&nbsp;std::vector&nbsp;&amp;data); | 异步批量写数据，传输大量数据时使用 | 
|  | int32_t&nbsp;BulkGetWriteCompleteLength(const&nbsp;UsbDev&nbsp;&amp;dev,&nbsp;const&nbsp;UsbPipe&nbsp;&amp;pipe,&nbsp;uint32_t&nbsp;&amp;length); | 与BulkWriteData配合使用，获取写入状态，由length描述 | 

- Device部分

  | 头文件 | 接口名称 | 功能描述 | 
| -------- | -------- | -------- |
| usb_srv_client.h | int32_t&nbsp;GetCurrentFunctions(int32_t&nbsp;&amp;funcs); | 获取设备模式下的当前USB功能列表的数字组合掩码 | 
|  | int32_t&nbsp;SetCurrentFunctions(int32_t&nbsp;funcs); | 在设备模式下设置当前的USB功能列表 | 
|  | int32_t&nbsp;UsbFunctionsFromString(std::string&nbsp;funcs); | 将给定的功能列表描述字符串转换为功能列表的数字组合掩码 | 
|  | std::string&nbsp;UsbFunctionsToString(int32_t&nbsp;funcs); | 将给定的功能列表的数字组合掩码转换为功能列表描述字符串 | 

- Port部分

  | 头文件 | 接口名称 | 功能描述 | 
| -------- | -------- | -------- |
| usb_srv_client.h | int32_t&nbsp;GetSupportedModes(int32_t&nbsp;portId,&nbsp;int32_t&nbsp;&amp;supportedModes); | 获取指定的端口支持的模式列表的组合掩码 | 
|  | int32_t&nbsp;SetPortRole(int32_t&nbsp;portId,&nbsp;int32_t&nbsp;powerRole,&nbsp;int32_t&nbsp;dataRole); | 设置指定的端口支持的角色模式，包含充电角色、数据传输角色 | 
|  | int32_t&nbsp;GetPorts(std::vector&nbsp;&amp;usbPorts); | 获取物理USB端口描述信息列表 | 
