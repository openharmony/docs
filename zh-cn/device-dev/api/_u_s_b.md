# USB


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [usb_info.h](usb__info_8h.md) | USB驱动订阅模块使用的数据类型。 | 
| [usbd_client.h](usbd__client_8h.md) | 声明标准USB驱动接口函数。 | 
| [usbd_subscriber.h](usbd__subscriber_8h.md) | USB驱动订阅模块。 | 
| [usbd_type.h](usbd__type_8h.md) | USB驱动模块接口定义中使用的自定义数据类型。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [OHOS::USB::USBDeviceInfo](_o_h_o_s_1_1_u_s_b_1_1_u_s_b_device_info.md) | USB设备信息。&nbsp;[更多...](_o_h_o_s_1_1_u_s_b_1_1_u_s_b_device_info.md) | 
| [OHOS::USB::UsbInfo](_o_h_o_s_1_1_u_s_b_1_1_usb_info.md) | USB设备信息类。&nbsp;[更多...](_o_h_o_s_1_1_u_s_b_1_1_usb_info.md) | 
| [OHOS::USB::UsbdClient](_o_h_o_s_1_1_u_s_b_1_1_usbd_client.md) | Usb驱动类。[更多...](_o_h_o_s_1_1_u_s_b_1_1_usbd_client.md) | 
| [OHOS::USB::UsbdSubscriber](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md) | 订阅类。[更多...](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md) | 
| [OHOS::USB::UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) | USB设备。&nbsp;[更多...](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md) | 
| [OHOS::USB::UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) | 管道信息。&nbsp;[更多...](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md) | 
| [OHOS::USB::UsbCtrlTransfer](_o_h_o_s_1_1_u_s_b_1_1_usb_ctrl_transfer.md) | USB控制传输。&nbsp;[更多...](_o_h_o_s_1_1_u_s_b_1_1_usb_ctrl_transfer.md) | 


### 宏定义

  | 宏定义 | 描述 | 
| -------- | -------- |
| [USB_MAX_INTERFACES](#usbmaxinterfaces)&nbsp;&nbsp;&nbsp;32 | USB设备最大接口数量。 | 


### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| ([UsbdRequestCallback](#usbdrequestcallback))&nbsp;(uint8_t&nbsp;\*requestArg) | 请求回调函数。[更多...](#usbdrequestcallback) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [UsbdBulkCbCmd](#usbdbulkcbcmd)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348413461.xml#xref1485062147083931,link:zh-cn_topic_0000001348413461.xml#gga734dda3df39a921fae88ada278bf35a3a5f84dff517954bbde58a2e1a0b8e8da6](#gga734dda3df39a921fae88ada278bf35a3a5f84dff517954bbde58a2e1a0b8e8da6),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348413461.xml#xref1983135169083931,link:zh-cn_topic_0000001348413461.xml#gga734dda3df39a921fae88ada278bf35a3ac7fc2d22d4d348c672003c308263b9fb](#gga734dda3df39a921fae88ada278bf35a3ac7fc2d22d4d348c672003c308263b9fb)&nbsp;} | 批量回调命令字。&nbsp;[更多...](#usbdbulkcbcmd) | 
| [UsbdDeviceAction](#usbddeviceaction)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348413461.xml#xref709354729083931,link:zh-cn_topic_0000001348413461.xml#gga4b7620d940f58152cd17a12401120c16af3ed12ba6838a4ebb16ae0713cb2324f](#gga4b7620d940f58152cd17a12401120c16af3ed12ba6838a4ebb16ae0713cb2324f)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348413461.xml#xref601390832083931,link:zh-cn_topic_0000001348413461.xml#gga4b7620d940f58152cd17a12401120c16a97801ad0ac063dbb69d698adc19159bf](#gga4b7620d940f58152cd17a12401120c16a97801ad0ac063dbb69d698adc19159bf),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348413461.xml#xref1423061468083931,link:zh-cn_topic_0000001348413461.xml#gga4b7620d940f58152cd17a12401120c16aecf16e36110fbe276f2a11e91252de20](#gga4b7620d940f58152cd17a12401120c16aecf16e36110fbe276f2a11e91252de20),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348413461.xml#xref273156642083931,link:zh-cn_topic_0000001348413461.xml#gga4b7620d940f58152cd17a12401120c16a45115ba5d58e4a5358acae70a9fc33d4](#gga4b7620d940f58152cd17a12401120c16a45115ba5d58e4a5358acae70a9fc33d4)&nbsp;} | 主机端和设备端插拔事件。&nbsp;[更多...](#usbddeviceaction) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [OHOS::USB::UsbInfo::setDevInfoStatus](#setdevinfostatus)&nbsp;(int32_t&nbsp;status) | 设置USB设备状态。&nbsp;[更多...](#setdevinfostatus) | 
| [OHOS::USB::UsbInfo::setDevInfoBusNum](#setdevinfobusnum)&nbsp;(int32_t&nbsp;busNum) | 设置USB总线编号。&nbsp;[更多...](#setdevinfobusnum) | 
| [OHOS::USB::UsbInfo::setDevInfoDevNum](#setdevinfodevnum)&nbsp;(int32_t&nbsp;devNum) | 设置USB设备编号。&nbsp;[更多...](#setdevinfodevnum) | 
| [OHOS::USB::UsbInfo::getDevInfoStatus](#getdevinfostatus)&nbsp;()&nbsp;const | 获取USB设备状态。&nbsp;[更多...](#getdevinfostatus) | 
| [OHOS::USB::UsbInfo::getDevInfoBusNum](#getdevinfobusnum)&nbsp;()&nbsp;const | 获取USB总线编号。&nbsp;[更多...](#getdevinfobusnum) | 
| [OHOS::USB::UsbInfo::getDevInfoDevNum](#getdevinfodevnum)&nbsp;()&nbsp;const | 获取USB设备编号。&nbsp;[更多...](#getdevinfodevnum) | 
| **OHOS::USB::UsbdClient::GetInstance**&nbsp;() | 获取实例。 | 
| [OHOS::USB::UsbdClient::OpenDevice](#opendevice)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev) | 打开设备，建立连接。&nbsp;[更多...](#opendevice) | 
| [OHOS::USB::UsbdClient::CloseDevice](#closedevice)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev) | 关闭设备，释放与设备相关的所有系统资源。&nbsp;[更多...](#closedevice) | 
| [OHOS::USB::UsbdClient::GetDeviceDescriptor](#getdevicedescriptor)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;descriptor) | 获取设备描述符。&nbsp;[更多...](#getdevicedescriptor) | 
| [OHOS::USB::UsbdClient::GetStringDescriptor](#getstringdescriptor)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;descId,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;descriptor) | 根据String&nbsp;ID获取设备的字符串描述符。&nbsp;[更多...](#getstringdescriptor) | 
| [OHOS::USB::UsbdClient::GetConfigDescriptor](#getconfigdescriptor)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;descId,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;descriptor) | 根据config&nbsp;ID获取设备的配置描述符config。&nbsp;[更多...](#getconfigdescriptor) | 
| [OHOS::USB::UsbdClient::GetRawDescriptor](#getrawdescriptor)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;descriptor) | 获取原始描述符。&nbsp;[更多...](#getrawdescriptor) | 
| [OHOS::USB::UsbdClient::GetFileDescriptor](#getfiledescriptor)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;int32_t&nbsp;&amp;fd) | 获取文件描述符。&nbsp;[更多...](#getfiledescriptor) | 
| [OHOS::USB::UsbdClient::SetConfig](#setconfig)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;configIndex) | 设置当前的config信息。&nbsp;[更多...](#setconfig) | 
| [OHOS::USB::UsbdClient::GetConfig](#getconfig)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;&amp;configIndex) | 获取当前的config信息。&nbsp;[更多...](#getconfig) | 
| [OHOS::USB::UsbdClient::ClaimInterface](#claiminterface)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;interfaceid,&nbsp;uint8_t&nbsp;force) | 打开接口，并声明独占接口，必须在数据传输前执行。&nbsp;[更多...](#claiminterface) | 
| [OHOS::USB::UsbdClient::ReleaseInterface](#releaseinterface)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;interfaceid) | 关闭接口，释放接口的占用，在停止数据传输后执行。&nbsp;[更多...](#releaseinterface) | 
| [OHOS::USB::UsbdClient::SetInterface](#setinterface)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;uint8_t&nbsp;interfaceid,&nbsp;uint8_t&nbsp;altIndex) | 设置指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择。&nbsp;[更多...](#setinterface) | 
| [OHOS::USB::UsbdClient::BulkTransferRead](#bulktransferread)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;int32_t&nbsp;timeout,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 在给定端点上执行批量数据读取，返回读取的数据和长度，端点方向必须为数据读取，可以设置超时时间。&nbsp;[更多...](#bulktransferread) | 
| [OHOS::USB::UsbdClient::BulkTransferWrite](#bulktransferwrite)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;int32_t&nbsp;timeout,&nbsp;const&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 在给定端点上执行批量数据写入，&nbsp;返回读取的数据和长度，端点方向必须为数据写入。&nbsp;[更多...](#bulktransferwrite) | 
| [OHOS::USB::UsbdClient::ControlTransfer](#controltransfer)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbCtrlTransfer](_o_h_o_s_1_1_u_s_b_1_1_usb_ctrl_transfer.md)&nbsp;&amp;ctrl,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 对此设备执行端点零的控制事务，传输方向由请求类型决定。&nbsp;如果requestType＆&nbsp;USB_ENDPOINT_DIR_MASK是USB_DIR_OUT&nbsp;，则传输是写入，如果是USB_DIR_IN&nbsp;，则传输是读取。&nbsp;[更多...](#controltransfer) | 
| [OHOS::USB::UsbdClient::InterruptTransferRead](#interrupttransferread)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;int32_t&nbsp;timeout,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 在给定端点上执行中断数据读取，&nbsp;返回读取的数据和长度，端点方向必须为数据读取。&nbsp;[更多...](#interrupttransferread) | 
| [OHOS::USB::UsbdClient::InterruptTransferWrite](#interrupttransferwrite)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;int32_t&nbsp;timeout,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 在给定端点上执行中断数据写入，&nbsp;返回读取的数据和长度，端点方向必须为数据写入。&nbsp;[更多...](#interrupttransferwrite) | 
| [OHOS::USB::UsbdClient::IsoTransferRead](#isotransferread)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;int32_t&nbsp;timeout,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 在给定端点上执行等时数据读取，&nbsp;返回读取的数据和长度，端点方向必须为数据读取。&nbsp;[更多...](#isotransferread) | 
| [OHOS::USB::UsbdClient::IsoTransferWrite](#isotransferwrite)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;int32_t&nbsp;timeout,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 在给定端点上执行等时数据写入，&nbsp;返回读取的数据和长度，端点方向必须为数据写入。&nbsp;[更多...](#isotransferwrite) | 
| [OHOS::USB::UsbdClient::RequestQueue](#requestqueue)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;const&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;clientData,&nbsp;const&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;buffer) | 将指定的端点进行异步数据发送或者接收请求，数据传输方向由端点方向决定。&nbsp;[更多...](#requestqueue) | 
| [OHOS::USB::UsbdClient::RequestWait](#requestwait)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;clientData,&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;buffer,&nbsp;int32_t&nbsp;timeout) | 等待RequestQueue异步请求的操作结果。&nbsp;[更多...](#requestwait) | 
| [OHOS::USB::UsbdClient::RequestCancel](#requestcancel)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe) | 取消待处理的数据请求。&nbsp;[更多...](#requestcancel) | 
| [OHOS::USB::UsbdClient::GetCurrentFunctions](#getcurrentfunctions)&nbsp;(int32_t&nbsp;&amp;funcs) | 获取从设备支持的功能列表（按位域表示）（从设备）。&nbsp;[更多...](#getcurrentfunctions) | 
| [OHOS::USB::UsbdClient::SetCurrentFunctions](#setcurrentfunctions)&nbsp;(int32_t&nbsp;funcs) | 设置从设备支持的功能列表（按位域表示）（从设备）。&nbsp;[更多...](#setcurrentfunctions) | 
| [OHOS::USB::UsbdClient::SetPortRole](#setportrole)&nbsp;(int32_t&nbsp;portId,&nbsp;int32_t&nbsp;powerRole,&nbsp;int32_t&nbsp;dataRole) | 设置port端口的角色。&nbsp;[更多...](#setportrole) | 
| [OHOS::USB::UsbdClient::QueryPort](#queryport)&nbsp;(int32_t&nbsp;&amp;portId,&nbsp;int32_t&nbsp;&amp;powerRole,&nbsp;int32_t&nbsp;&amp;dataRole,&nbsp;int32_t&nbsp;&amp;mode) | 查询port端口的当前设置。&nbsp;[更多...](#queryport) | 
| [OHOS::USB::UsbdClient::BindUsbdSubscriber](#bindusbdsubscriber)&nbsp;(const&nbsp;sptr&lt;&nbsp;[UsbdSubscriber](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md)&nbsp;&gt;&nbsp;&amp;subscriber) | 绑定订阅者。&nbsp;[更多...](#bindusbdsubscriber) | 
| [OHOS::USB::UsbdClient::UnbindUsbdSubscriber](#unbindusbdsubscriber)&nbsp;(const&nbsp;sptr&lt;&nbsp;[UsbdSubscriber](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md)&nbsp;&gt;&nbsp;&amp;subscriber) | 解绑订阅者。&nbsp;[更多...](#unbindusbdsubscriber) | 
| [OHOS::USB::UsbdClient::RegBulkCallback](#regbulkcallback)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;const&nbsp;sptr&lt;&nbsp;IRemoteObject&nbsp;&gt;&nbsp;&amp;cb) | 注册批量传输异步回调函数。&nbsp;[更多...](#regbulkcallback) | 
| [OHOS::USB::UsbdClient::UnRegBulkCallback](#unregbulkcallback)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe) | 注销批量传输异步回调函数。&nbsp;[更多...](#unregbulkcallback) | 
| [OHOS::USB::UsbdClient::BulkRead](#bulkread)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;sptr&lt;&nbsp;Ashmem&nbsp;&gt;&nbsp;&amp;ashmem) | 批量传输异步读数据。&nbsp;[更多...](#bulkread) | 
| [OHOS::USB::UsbdClient::BulkWrite](#bulkwrite)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe,&nbsp;sptr&lt;&nbsp;Ashmem&nbsp;&gt;&nbsp;&amp;ashmem) | 批量传输异步写数据。&nbsp;[更多...](#bulkwrite) | 
| [OHOS::USB::UsbdClient::BulkCancel](#bulkcancel)&nbsp;(const&nbsp;[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)&nbsp;&amp;dev,&nbsp;const&nbsp;[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)&nbsp;&amp;pipe) | 批量传输异步取消接口，用于取消当前接口的异步批量读写操作。&nbsp;[更多...](#bulkcancel) | 
| [OHOS::USB::UsbdSubscriber::DeviceEvent](#deviceevent)&nbsp;(const&nbsp;[UsbInfo](_o_h_o_s_1_1_u_s_b_1_1_usb_info.md)&nbsp;&amp;info)=0 | 设备事件。&nbsp;[更多...](#deviceevent) | 
| [OHOS::USB::UsbdSubscriber::PortChangedEvent](#portchangedevent)&nbsp;(int32_t&nbsp;portId,&nbsp;int32_t&nbsp;powerRole,&nbsp;int32_t&nbsp;dataRole,&nbsp;int32_t&nbsp;mode)=0 | 端口改变事件。&nbsp;[更多...](#portchangedevent) | 
| [OHOS::USB::UsbdSubscriber::OnRemoteRequest](#onremoterequest)&nbsp;(uint32_t&nbsp;code,&nbsp;MessageParcel&nbsp;&amp;data,&nbsp;MessageParcel&nbsp;&amp;reply,&nbsp;MessageOption&nbsp;&amp;option)&nbsp;override | 远程请求。&nbsp;[更多...](#onremoterequest) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| [OHOS::USB::USBDeviceInfo::status](#status) | USB设备状态 | 
| [OHOS::USB::USBDeviceInfo::busNum](#busnum-12) | USB总线编号 | 
| [OHOS::USB::USBDeviceInfo::devNum](#devnum) | USB设备编号 | 
| [OHOS::USB::UsbDev::busNum](#busnum-22) | USB总线编号 | 
| [OHOS::USB::UsbDev::devAddr](#devaddr) | USB设备地址 | 
| [OHOS::USB::UsbPipe::interfaceId](#interfaceid) | USB设备接口ID | 
| [OHOS::USB::UsbPipe::endpointId](#endpointid) | USB设备端点ID | 
| [OHOS::USB::UsbCtrlTransfer::requestType](#requesttype) | 请求类型 | 
| [OHOS::USB::UsbCtrlTransfer::requestCmd](#requestcmd) | 请求命令字 | 
| [OHOS::USB::UsbCtrlTransfer::value](#value) | 请求值 | 
| [OHOS::USB::UsbCtrlTransfer::index](#index) | 索引 | 
| [OHOS::USB::UsbCtrlTransfer::timeout](#timeout) | 超时时间 | 


## **详细描述**

定义（USB）功能的标准API接口。

该模块用于获取描述符、接口对象、请求对象和提交请求的自定义数据类型和函数。

**Since：**

3.0

**Version：**

1.0


## **宏定义说明**


### USB_MAX_INTERFACES

  
```
#define USB_MAX_INTERFACES   32
```

**描述：**

USB设备最大接口数量


## **类型定义说明**


### UsbdRequestCallback

  
```
typedef void(* UsbdRequestCallback) (uint8_t *requestArg)
```

**描述：**

请求回调函数


## **枚举类型说明**


### UsbdBulkCbCmd

  
```
enum UsbdBulkCbCmd
```

**描述：**

批量回调命令字。

  | 枚举值 | 描述 | 
| -------- | -------- |
| CMD_USBD_BULK_CALLBACK_READ | 批量回调读取 | 
| CMD_USBD_BULK_CALLBACK_WRITE | 批量回调写入 | 


### UsbdDeviceAction

  
```
enum UsbdDeviceAction
```

**描述：**

主机端和设备端插拔事件。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ACT_DEVUP | 主机端接入设备 | 
| ACT_DEVDOWN | 主机端拔出设备 | 
| ACT_UPDEVICE | 设备连接 | 
| ACT_DOWNDEVICE | 设备断开 | 


## **函数说明**


### BindUsbdSubscriber()

  
```
int32_t OHOS::USB::UsbdClient::BindUsbdSubscriber (const sptr< UsbdSubscriber > & subscriber)
```

**描述：**

绑定订阅者。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| subscriber | 输入参数，订阅者信息，详见[UsbdSubscriber](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### BulkCancel()

  
```
int32_t OHOS::USB::UsbdClient::BulkCancel (const UsbDev & dev, const UsbPipe & pipe )
```

**描述：**

批量传输异步取消接口，用于取消当前接口的异步批量读写操作。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### BulkRead()

  
```
int32_t OHOS::USB::UsbdClient::BulkRead (const UsbDev & dev, const UsbPipe & pipe, sptr< Ashmem > & ashmem )
```

**描述：**

批量传输异步读数据。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| ashmem | 输出参数，为共享内存，用于存放读取的数据，详见**Ashmem**。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### BulkTransferRead()

  
```
int32_t OHOS::USB::UsbdClient::BulkTransferRead (const UsbDev & dev, const UsbPipe & pipe, int32_t timeout, std::vector< uint8_t > & data )
```

**描述：**

在给定端点上执行批量数据读取，返回读取的数据和长度，端点方向必须为数据读取，可以设置超时时间。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| timeout | 输入参数，超时时间。 | 
| data | 输出参数，获取写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### BulkTransferWrite()

  
```
int32_t OHOS::USB::UsbdClient::BulkTransferWrite (const UsbDev & dev, const UsbPipe & pipe, int32_t timeout, const std::vector< uint8_t > & data )
```

**描述：**

在给定端点上执行批量数据写入， 返回读取的数据和长度，端点方向必须为数据写入。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| timeout | 输入参数，超时时间。 | 
| data | 输入参数，写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### BulkWrite()

  
```
int32_t OHOS::USB::UsbdClient::BulkWrite (const UsbDev & dev, const UsbPipe & pipe, sptr< Ashmem > & ashmem )
```

**描述：**

批量传输异步写数据。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| ashmem | 输入参数，为共享内存，用于存放需要写入的数据，详见**Ashmem**。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### ClaimInterface()

  
```
int32_t OHOS::USB::UsbdClient::ClaimInterface (const UsbDev & dev, uint8_t interfaceid, uint8_t force )
```

**描述：**

打开接口，并声明独占接口，必须在数据传输前执行。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| interfaceid | 输入参数，USB设备interface&nbsp;ID。 | 
| force | 输入参数，是否强制:&nbsp;1强制&nbsp;0不强制。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### CloseDevice()

  
```
int32_t OHOS::USB::UsbdClient::CloseDevice (const UsbDev & dev)
```

**描述：**

关闭设备，释放与设备相关的所有系统资源。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### ControlTransfer()

  
```
int32_t OHOS::USB::UsbdClient::ControlTransfer (const UsbDev & dev, const UsbCtrlTransfer & ctrl, std::vector< uint8_t > & data )
```

**描述：**

对此设备执行端点零的控制事务，传输方向由请求类型决定。 如果requestType＆ USB_ENDPOINT_DIR_MASK是USB_DIR_OUT ，则传输是写入，如果是USB_DIR_IN ，则传输是读取。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| ctrl | 输入参数，USB设备控制数据包结构，详见[UsbCtrlTransfer](_o_h_o_s_1_1_u_s_b_1_1_usb_ctrl_transfer.md)。 | 
| data | 输入/输出参数，读取/写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### DeviceEvent()

  
```
virtual int32_t OHOS::USB::UsbdSubscriber::DeviceEvent (const UsbInfo & info)
```

**描述：**

设备事件。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| [UsbInfo](_o_h_o_s_1_1_u_s_b_1_1_usb_info.md) | 输入参数，USB设备信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### GetConfig()

  
```
int32_t OHOS::USB::UsbdClient::GetConfig (const UsbDev & dev, uint8_t & configIndex )
```

**描述：**

获取当前的config信息。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| configIndex | 输出参数，USB设备config信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### GetConfigDescriptor()

  
```
int32_t OHOS::USB::UsbdClient::GetConfigDescriptor (const UsbDev & dev, uint8_t descId, std::vector< uint8_t > & descriptor )
```

**描述：**

根据config ID获取设备的配置描述符config。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| descId | 输入参数，USB的config&nbsp;ID。 | 
| descriptor | 输出参数，获取USB设备config信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### GetCurrentFunctions()

  
```
int32_t OHOS::USB::UsbdClient::GetCurrentFunctions (int32_t & funcs)
```

**描述：**

获取从设备支持的功能列表（按位域表示）（从设备）。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，获取当前设备的function的值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### GetDeviceDescriptor()

  
```
int32_t OHOS::USB::UsbdClient::GetDeviceDescriptor (const UsbDev & dev, std::vector< uint8_t > & descriptor )
```

**描述：**

获取设备描述符。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| descriptor | 输出参数，USB设备描述符信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### getDevInfoBusNum()

  
```
int32_t OHOS::USB::UsbInfo::getDevInfoBusNum () const
```

**描述：**

获取USB总线编号。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| status | 输出参数，USB总线编号。 | 

**Since：**

3.0

**Version：**

1.0


### getDevInfoDevNum()

  
```
int32_t OHOS::USB::UsbInfo::getDevInfoDevNum () const
```

**描述：**

获取USB设备编号。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| status | 输出参数，USB设备编号。 | 

**Since：**

3.0

**Version：**

1.0


### getDevInfoStatus()

  
```
int32_t OHOS::USB::UsbInfo::getDevInfoStatus () const
```

**描述：**

获取USB设备状态。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| status | 输出参数，设备状态。 | 

**Since：**

3.0

**Version：**

1.0


### GetFileDescriptor()

  
```
int32_t OHOS::USB::UsbdClient::GetFileDescriptor (const UsbDev & dev, int32_t & fd )
```

**描述：**

获取文件描述符。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| fd | 输出参数，USB设备文件描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### GetRawDescriptor()

  
```
int32_t OHOS::USB::UsbdClient::GetRawDescriptor (const UsbDev & dev, std::vector< uint8_t > & descriptor )
```

**描述：**

获取原始描述符。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| descriptor | 输出参数，USB设备原始描述符。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### GetStringDescriptor()

  
```
int32_t OHOS::USB::UsbdClient::GetStringDescriptor (const UsbDev & dev, uint8_t descId, std::vector< uint8_t > & descriptor )
```

**描述：**

根据String ID获取设备的字符串描述符。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| descId | 输入参数，USB的string&nbsp;ID。 | 
| descriptor | 输出参数，获取USB设备config信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### InterruptTransferRead()

  
```
int32_t OHOS::USB::UsbdClient::InterruptTransferRead (const UsbDev & dev, const UsbPipe & pipe, int32_t timeout, std::vector< uint8_t > & data )
```

**描述：**

在给定端点上执行中断数据读取， 返回读取的数据和长度，端点方向必须为数据读取。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| timeout | 输入参数，超时时间。 | 
| data | 输出参数，读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### InterruptTransferWrite()

  
```
int32_t OHOS::USB::UsbdClient::InterruptTransferWrite (const UsbDev & dev, const UsbPipe & pipe, int32_t timeout, std::vector< uint8_t > & data )
```

**描述：**

在给定端点上执行中断数据写入， 返回读取的数据和长度，端点方向必须为数据写入。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| timeout | 输入参数，超时时间。 | 
| data | 输入参数，写入的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### IsoTransferRead()

  
```
int32_t OHOS::USB::UsbdClient::IsoTransferRead (const UsbDev & dev, const UsbPipe & pipe, int32_t timeout, std::vector< uint8_t > & data )
```

**描述：**

在给定端点上执行等时数据读取， 返回读取的数据和长度，端点方向必须为数据读取。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| timeout | 输入参数，超时时间。 | 
| data | 输出参数，读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### IsoTransferWrite()

  
```
int32_t OHOS::USB::UsbdClient::IsoTransferWrite (const UsbDev & dev, const UsbPipe & pipe, int32_t timeout, std::vector< uint8_t > & data )
```

**描述：**

在给定端点上执行等时数据写入， 返回读取的数据和长度，端点方向必须为数据写入。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| timeout | 输入参数，超时时间。 | 
| data | 输入参数，读取的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### OnRemoteRequest()

  
```
int32_t OHOS::USB::UsbdSubscriber::OnRemoteRequest (uint32_t code, MessageParcel & data, MessageParcel & reply, MessageOption & option )
```

**描述：**

远程请求。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| code | 输入参数，命令字。 | 
| data | 输入参数，待解析的数据。 | 
| reply | 输出参数，返回的数据。 | 
| option | 输入参数，选项数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### OpenDevice()

  
```
int32_t OHOS::USB::UsbdClient::OpenDevice (const UsbDev & dev)
```

**描述：**

打开设备，建立连接。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### PortChangedEvent()

  
```
virtual int32_t OHOS::USB::UsbdSubscriber::PortChangedEvent (int32_t portId, int32_t powerRole, int32_t dataRole, int32_t mode )
```

**描述：**

端口改变事件。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| portId | 输入参数，端口ID。 | 
| powerRole | 输入参数，电源角色的值。 | 
| dataRole | 输入参数，数据角色的值。 | 
| mode | 输入参数，端口模式的值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### QueryPort()

  
```
int32_t OHOS::USB::UsbdClient::QueryPort (int32_t & portId, int32_t & powerRole, int32_t & dataRole, int32_t & mode )
```

**描述：**

查询port端口的当前设置。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| portId | 输出参数，port接口ID。 | 
| powerRole | 输出参数，电源角色的值。 | 
| dataRole | 输出参数，数据角色的值。 | 
| mode | 输出参数，模式的值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### RegBulkCallback()

  
```
int32_t OHOS::USB::UsbdClient::RegBulkCallback (const UsbDev & dev, const UsbPipe & pipe, const sptr< IRemoteObject > & cb )
```

**描述：**

注册批量传输异步回调函数。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| cb | 输入参数，回调函数对象的引用。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### ReleaseInterface()

  
```
int32_t OHOS::USB::UsbdClient::ReleaseInterface (const UsbDev & dev, uint8_t interfaceid )
```

**描述：**

关闭接口，释放接口的占用，在停止数据传输后执行。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| interfaceid | 输入参数，USB设备interface&nbsp;ID。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### RequestCancel()

  
```
int32_t OHOS::USB::UsbdClient::RequestCancel (const UsbDev & dev, const UsbPipe & pipe )
```

**描述：**

取消待处理的数据请求。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### RequestQueue()

  
```
int32_t OHOS::USB::UsbdClient::RequestQueue (const UsbDev & dev, const UsbPipe & pipe, const std::vector< uint8_t > & clientData, const std::vector< uint8_t > & buffer )
```

**描述：**

将指定的端点进行异步数据发送或者接收请求，数据传输方向由端点方向决定。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 
| clientData | 输入参数，用户数据。 | 
| buffer | 输入参数，传输的数据。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### RequestWait()

  
```
int32_t OHOS::USB::UsbdClient::RequestWait (const UsbDev & dev, std::vector< uint8_t > & clientData, std::vector< uint8_t > & buffer, int32_t timeout )
```

**描述：**

等待RequestQueue异步请求的操作结果。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| clientData | 输入参数，用户数据。 | 
| buffer | 输入参数，传输数据。 | 
| timeout | 输入参数，超时时间。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### SetConfig()

  
```
int32_t OHOS::USB::UsbdClient::SetConfig (const UsbDev & dev, uint8_t configIndex )
```

**描述：**

设置当前的config信息。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| configIndex | 输入参数，USB设备config信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### SetCurrentFunctions()

  
```
int32_t OHOS::USB::UsbdClient::SetCurrentFunctions (int32_t funcs)
```

**描述：**

设置从设备支持的功能列表（按位域表示）（从设备）。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输入参数，传入设备支持的function的值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### setDevInfoBusNum()

  
```
void OHOS::USB::UsbInfo::setDevInfoBusNum (int32_t busNum)
```

**描述：**

设置USB总线编号。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| status | 输入参数，USB总线编号。 | 

**Since：**

3.0

**Version：**

1.0


### setDevInfoDevNum()

  
```
void OHOS::USB::UsbInfo::setDevInfoDevNum (int32_t devNum)
```

**描述：**

设置USB设备编号。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| status | 输入参数，USB设备编号。 | 

**Since：**

3.0

**Version：**

1.0


### setDevInfoStatus()

  
```
void OHOS::USB::UsbInfo::setDevInfoStatus (int32_t status)
```

**描述：**

设置USB设备状态。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| status | 输入参数，设备状态。 | 

**Since：**

3.0

**Version：**

1.0


### SetInterface()

  
```
int32_t OHOS::USB::UsbdClient::SetInterface (const UsbDev & dev, uint8_t interfaceid, uint8_t altIndex )
```

**描述：**

设置指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| interfaceid | 输入参数，USB设备interface&nbsp;ID。 | 
| altIndex | 输入参数，interface的AlternateSetting信息。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### SetPortRole()

  
```
int32_t OHOS::USB::UsbdClient::SetPortRole (int32_t portId, int32_t powerRole, int32_t dataRole )
```

**描述：**

设置port端口的角色。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| portId | 输入参数，port接口ID。 | 
| powerRole | 输入参数，电源角色的值。 | 
| dataRole | 输入参数，数据角色的值。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### UnbindUsbdSubscriber()

  
```
int32_t OHOS::USB::UsbdClient::UnbindUsbdSubscriber (const sptr< UsbdSubscriber > & subscriber)
```

**描述：**

解绑订阅者。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| subscriber | 输入参数，订阅者信息，详见[UsbdSubscriber](_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


### UnRegBulkCallback()

  
```
int32_t OHOS::USB::UsbdClient::UnRegBulkCallback (const UsbDev & dev, const UsbPipe & pipe )
```

**描述：**

注销批量传输异步回调函数。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| dev | 输入参数，USB设备地址信息，详见[UsbDev](_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md)。 | 
| pipe | 输入参数，USB设备pipe信息，详见[UsbPipe](_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md)。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。

**Since：**

3.0

**Version：**

1.0


## **变量说明**


### busNum [1/2]

  
```
int32_t OHOS::USB::USBDeviceInfo::busNum
```

**描述：**

USB总线编号


### busNum [2/2]

  
```
uint8_t OHOS::USB::UsbDev::busNum
```

**描述：**

USB总线编号


### devAddr

  
```
uint8_t OHOS::USB::UsbDev::devAddr
```

**描述：**

USB设备地址


### devNum

  
```
int32_t OHOS::USB::USBDeviceInfo::devNum
```

**描述：**

USB设备编号


### endpointId

  
```
uint8_t OHOS::USB::UsbPipe::endpointId
```

**描述：**

USB设备端点ID


### index

  
```
int32_t OHOS::USB::UsbCtrlTransfer::index
```

**描述：**

索引


### interfaceId

  
```
uint8_t OHOS::USB::UsbPipe::interfaceId
```

**描述：**

USB设备接口ID


### requestCmd

  
```
int32_t OHOS::USB::UsbCtrlTransfer::requestCmd
```

**描述：**

请求命令字


### requestType

  
```
int32_t OHOS::USB::UsbCtrlTransfer::requestType
```

**描述：**

请求类型


### status

  
```
int32_t OHOS::USB::USBDeviceInfo::status
```

**描述：**

USB设备状态


### timeout

  
```
int32_t OHOS::USB::UsbCtrlTransfer::timeout
```

**描述：**

超时时间


### value

  
```
int32_t OHOS::USB::UsbCtrlTransfer::value
```

**描述：**

请求值
