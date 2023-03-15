# IUsbdSubscriber


## **概述**

定义USB驱动的订阅类相关函数。

当设备接入/断开会调用DeviceEvent进行信息上报。 当端口状态发生变化时会调用PortChangedEvent进行信息上报。

**相关模块:**

[USB](usb.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [DeviceEvent](#deviceevent)&nbsp;([in]&nbsp;struct&nbsp;[USBDeviceInfo](_u_s_b_device_info.md)&nbsp;info) | 设备状态改变事件。 | 
| [PortChangedEvent](#portchangedevent)&nbsp;([in]&nbsp;struct&nbsp;[PortInfo](_port_info.md)&nbsp;info) | 端口改变事件。 | 


## **成员函数说明**


### DeviceEvent()

  
```
IUsbdSubscriber::DeviceEvent ([in] struct USBDeviceInfo info)
```

**描述：**

设备状态改变事件。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| UsbInfo | USB设备信息。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### PortChangedEvent()

  
```
IUsbdSubscriber::PortChangedEvent ([in] struct PortInfo info)
```

**描述：**

端口改变事件。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| info | 端口信息。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。
