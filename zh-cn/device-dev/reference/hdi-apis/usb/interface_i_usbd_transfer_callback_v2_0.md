# IUsbdTransferCallback


## 概述

定义回调用于上报USB异步传输读取/写入数据的结果。

上层USB服务开发人员可以根据USB驱动模块提供的标准接口获取如下功能：在提交异步传输请求时，将回调函数注册到传输对象中，传输完成后， 通过回调函数处理传输结果。

**起始版本：** 5.1

**相关模块：**[HdiUsb](_hdi_usb_v2_0.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnTransferWriteCallback](#ontransferwritecallback)([in] int status, [in] int actLength, [in] [UsbIsoPacketDescriptor](_usb_iso_packet_descriptor_v2_0.md)[] descs, [in] unsigned long userData) | USB异步传输写入数据回调。 | 
| [OnTransferReadCallback](#ontransferreadcallback)([in] int status, [in] int actLength, [in] [UsbIsoPacketDescriptor](_usb_iso_packet_descriptor_v2_0.md)[] descs, [in] unsigned long userData) | USB异步传输读取数据回调。 | 


## 成员函数说明


### OnTransferWriteCallback()

```
IUsbdTransferCallback::OnTransferWriteCallback([in] int status, [in] int actLength, [in] UsbIsoPacketDescriptor[] descs, [in] unsigned long userData)
```

**描述**

USB异步传输写入数据回调。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | USB异步传输状态。 | 
| actLength | 实际写入数据的长度。 | 
| descs | 用于实时传输的分包描述符。 | 
| userData | 用户自定义数据。 | 


### OnTransferReadCallback()

```
IUsbdTransferCallback::OnTransferReadCallback([in] int status, [in] int actLength, [in] UsbIsoPacketDescriptor[] descs, [in] unsigned long userData)
```

**描述**

USB异步传输读取数据回调。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | USB异步传输状态。 | 
| actLength | 实际写入数据的长度。 | 
| descs | 用于实时传输的分包描述符。 | 
| userData | 用户自定义数据。 | 
