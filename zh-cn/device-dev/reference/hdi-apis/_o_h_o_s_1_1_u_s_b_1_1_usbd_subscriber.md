# OHOS::USB::UsbdSubscriber


## **概述**

**所属模块:**

[USB](_u_s_b.md)


## **汇总**


### Public 成员函数

  | Public&nbsp;成员函数 | 描述 | 
| -------- | -------- |
| [DeviceEvent](_u_s_b.md#deviceevent)&nbsp;(const&nbsp;[UsbInfo](_o_h_o_s_1_1_u_s_b_1_1_usb_info.md)&nbsp;&amp;info)=0 | 设备事件。&nbsp;[更多...](_u_s_b.md#deviceevent) | 
| [PortChangedEvent](_u_s_b.md#portchangedevent)&nbsp;(int32_t&nbsp;portId,&nbsp;int32_t&nbsp;powerRole,&nbsp;int32_t&nbsp;dataRole,&nbsp;int32_t&nbsp;mode)=0 | 端口改变事件。&nbsp;[更多...](_u_s_b.md#portchangedevent) | 
| [OnRemoteRequest](_u_s_b.md#onremoterequest)&nbsp;(uint32_t&nbsp;code,&nbsp;MessageParcel&nbsp;&amp;data,&nbsp;MessageParcel&nbsp;&amp;reply,&nbsp;MessageOption&nbsp;&amp;option)&nbsp;override | 远程请求。&nbsp;[更多...](_u_s_b.md#onremoterequest) | 


### Private 成员函数

  | Private&nbsp;成员函数 | 描述 | 
| -------- | -------- |
| [OHOS::USB::UsbdSubscriber::ParserUsbInfo](_u_s_b.md#parserusbinfo)&nbsp;(MessageParcel&nbsp;&amp;data,&nbsp;MessageParcel&nbsp;&amp;reply,&nbsp;MessageOption&nbsp;&amp;option,&nbsp;UsbInfo&nbsp;&amp;info) | 解析USB设备信息。&nbsp;[更多...](_u_s_b.md#parserusbinfo) | 
| [OHOS::USB::UsbdSubscriber::ParserPortInfo](_u_s_b.md#parserportinfo)&nbsp;(MessageParcel&nbsp;&amp;data,&nbsp;MessageParcel&nbsp;&amp;reply,&nbsp;MessageOption&nbsp;&amp;option,&nbsp;PortInfo&nbsp;&amp;info) | 解析USB设备端口信息。&nbsp;[更多...](_u_s_b.md#parserportinfo) | 


## **详细描述**

USB驱动订阅类。

**Since：**

3.0

**Version：**

1.0