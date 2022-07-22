# OHOS::USB::UsbdClient


## **概述**

**所属模块:**

[USB](_u_s_b.md)


## **汇总**


### Public 成员函数

  | Public&nbsp;成员函数 | 描述 | 
| -------- | -------- |
| [OpenDevice](_u_s_b.md#opendevice)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev) | 打开设备，建立连接。&nbsp;[更多...](_u_s_b.md#opendevice) | 
| [CloseDevice](_u_s_b.md#closedevice)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev) | 关闭设备，释放与设备相关的所有系统资源。&nbsp;[更多...](_u_s_b.md#closedevice) | 
| [GetDeviceDescriptor](_u_s_b.md#getdevicedescriptor)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;descriptor) | 获取设备描述符。&nbsp;[更多...](_u_s_b.md#getdevicedescriptor) | 
| [GetStringDescriptor](_u_s_b.md#getstringdescriptor)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;descId,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;descriptor) | 根据String&nbsp;ID获取设备的字符串描述符。&nbsp;[更多...](_u_s_b.md#getstringdescriptor) | 
| [GetConfigDescriptor](_u_s_b.md#getconfigdescriptor)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;descId,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;descriptor) | 根据config&nbsp;ID获取设备的配置描述符config。&nbsp;[更多...](_u_s_b.md#getconfigdescriptor) | 
| [GetRawDescriptor](_u_s_b.md#getrawdescriptor)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;descriptor) | 获取原始描述符。&nbsp;[更多...](_u_s_b.md#getrawdescriptor) | 
| [GetFileDescriptor](_u_s_b.md#getfiledescriptor)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;int32_t&nbsp;&amp;fd) | 获取文件描述符。&nbsp;[更多...](_u_s_b.md#getfiledescriptor) | 
| [SetConfig](_u_s_b.md#setconfig)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;configIndex) | 设置当前的config信息。&nbsp;[更多...](_u_s_b.md#setconfig) | 
| [GetConfig](_u_s_b.md#getconfig)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;&amp;configIndex) | 获取当前的config信息。&nbsp;[更多...](_u_s_b.md#getconfig) | 
| [ClaimInterface](_u_s_b.md#claiminterface)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;interfaceid,&nbsp;uint8_t&nbsp;force) | 打开接口，并声明独占接口，必须在数据传输前执行。&nbsp;[更多...](_u_s_b.md#claiminterface) | 
| [ReleaseInterface](_u_s_b.md#releaseinterface)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;interfaceid) | 关闭接口，释放接口的占用，在停止数据传输后执行。&nbsp;[更多...](_u_s_b.md#releaseinterface) | 
| [SetInterface](_u_s_b.md#setinterface)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;interfaceid,&nbsp;uint8_t&nbsp;altIndex) | 设置指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择。&nbsp;[更多...](_u_s_b.md#setinterface) | 
| [BulkTransferRead](_u_s_b.md#bulktransferread)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;int32_t&nbsp;timeout,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 在给定端点上执行批量数据读取，返回读取的数据和长度，端点方向必须为数据读取，可以设置超时时间。&nbsp;[更多...](_u_s_b.md#bulktransferread) | 
| [BulkTransferWrite](_u_s_b.md#bulktransferwrite)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;int32_t&nbsp;timeout,&nbsp;const&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 在给定端点上执行批量数据写入，&nbsp;返回读取的数据和长度，端点方向必须为数据写入。&nbsp;[更多...](_u_s_b.md#bulktransferwrite) | 
| [ControlTransfer](_u_s_b.md#controltransfer)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbCtrlTransfer](_o_h_o_s_1_1_u_s_b_1_1_usb_ctrl_transfer.md)&nbsp;&amp;ctrl,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 对此设备执行端点零的控制事务，传输方向由请求类型决定。&nbsp;如果requestType＆&nbsp;USB_ENDPOINT_DIR_MASK是USB_DIR_OUT&nbsp;，则传输是写入，如果是USB_DIR_IN&nbsp;，则传输是读取。&nbsp;[更多...](_u_s_b.md#controltransfer) | 
| [InterruptTransferRead](_u_s_b.md#interrupttransferread)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;int32_t&nbsp;timeout,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 在给定端点上执行中断数据读取，&nbsp;返回读取的数据和长度，端点方向必须为数据读取。&nbsp;[更多...](_u_s_b.md#interrupttransferread) | 
| [InterruptTransferWrite](_u_s_b.md#interrupttransferwrite)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;int32_t&nbsp;timeout,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 在给定端点上执行中断数据写入，&nbsp;返回读取的数据和长度，端点方向必须为数据写入。&nbsp;[更多...](_u_s_b.md#interrupttransferwrite) | 
| [IsoTransferRead](_u_s_b.md#isotransferread)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;int32_t&nbsp;timeout,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 在给定端点上执行等时数据读取，&nbsp;返回读取的数据和长度，端点方向必须为数据读取。&nbsp;[更多...](_u_s_b.md#isotransferread) | 
| [IsoTransferWrite](_u_s_b.md#isotransferwrite)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;int32_t&nbsp;timeout,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 在给定端点上执行等时数据写入，&nbsp;返回读取的数据和长度，端点方向必须为数据写入。&nbsp;[更多...](_u_s_b.md#isotransferwrite) | 
| [RequestQueue](_u_s_b.md#requestqueue)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;const&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;clientData,&nbsp;const&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;buffer) | 将指定的端点进行异步数据发送或者接收请求，数据传输方向由端点方向决定。&nbsp;[更多...](_u_s_b.md#requestqueue) | 
| [RequestWait](_u_s_b.md#requestwait)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;clientData,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;buffer,&nbsp;int32_t&nbsp;timeout) | 等待RequestQueue异步请求的操作结果。&nbsp;[更多...](_u_s_b.md#requestwait) | 
| [RequestCancel](_u_s_b.md#requestcancel)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe) | 取消待处理的数据请求。&nbsp;[更多...](_u_s_b.md#requestcancel) | 
| [GetCurrentFunctions](_u_s_b.md#getcurrentfunctions)&nbsp;(int32_t&nbsp;&amp;funcs) | 获取从设备支持的功能列表（按位域表示）（从设备）。&nbsp;[更多...](_u_s_b.md#getcurrentfunctions) | 
| [SetCurrentFunctions](_u_s_b.md#setcurrentfunctions)&nbsp;(int32_t&nbsp;funcs) | 设置从设备支持的功能列表（按位域表示）（从设备）。&nbsp;[更多...](_u_s_b.md#setcurrentfunctions) | 
| [SetPortRole](_u_s_b.md#setportrole)&nbsp;(int32_t&nbsp;portId,&nbsp;int32_t&nbsp;powerRole,&nbsp;int32_t&nbsp;dataRole) | 设置port端口的角色。&nbsp;[更多...](_u_s_b.md#setportrole) | 
| [QueryPort](_u_s_b.md#queryport)&nbsp;(int32_t&nbsp;&amp;portId,&nbsp;int32_t&nbsp;&amp;powerRole,&nbsp;int32_t&nbsp;&amp;dataRole,&nbsp;int32_t&nbsp;&amp;mode) | 查询port端口的当前设置。&nbsp;[更多...](_u_s_b.md#queryport) | 
| [BindUsbdSubscriber](_u_s_b.md#bindusbdsubscriber)&nbsp;(const&nbsp;sptr&lt;&nbsp;[UsbdSubscriber](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md)&nbsp;&gt;&nbsp;&amp;subscriber) | 绑定订阅者。&nbsp;[更多...](_u_s_b.md#bindusbdsubscriber) | 
| [UnbindUsbdSubscriber](_u_s_b.md#unbindusbdsubscriber)&nbsp;(const&nbsp;sptr&lt;&nbsp;[UsbdSubscriber](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md)&nbsp;&gt;&nbsp;&amp;subscriber) | 解绑订阅者。&nbsp;[更多...](_u_s_b.md#unbindusbdsubscriber) | 
| [RegBulkCallback](_u_s_b.md#regbulkcallback)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;const&nbsp;sptr&lt;&nbsp;IRemoteObject&nbsp;&gt;&nbsp;&amp;cb) | 注册批量传输异步回调函数。&nbsp;[更多...](_u_s_b.md#regbulkcallback) | 
| [UnRegBulkCallback](_u_s_b.md#unregbulkcallback)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe) | 注销批量传输异步回调函数。&nbsp;[更多...](_u_s_b.md#unregbulkcallback) | 
| [BulkRead](_u_s_b.md#bulkread)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;sptr&lt;&nbsp;Ashmem&nbsp;&gt;&nbsp;&amp;ashmem) | 批量传输异步读数据。&nbsp;[更多...](_u_s_b.md#bulkread) | 
| [BulkWrite](_u_s_b.md#bulkwrite)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;sptr&lt;&nbsp;Ashmem&nbsp;&gt;&nbsp;&amp;ashmem) | 批量传输异步写数据。&nbsp;[更多...](_u_s_b.md#bulkwrite) | 
| [BulkCancel](_u_s_b.md#bulkcancel)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe) | 批量传输异步取消接口，用于取消当前接口的异步批量读写操作。&nbsp;[更多...](_u_s_b.md#bulkcancel) | 


### 静态 Public 成员函数

  | 静态&nbsp;Public&nbsp;成员函数 | 描述 | 
| -------- | -------- |
| **GetInstance**&nbsp;() | 获取实例。 | 
