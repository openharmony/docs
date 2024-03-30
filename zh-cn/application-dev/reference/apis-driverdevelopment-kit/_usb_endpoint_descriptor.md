# UsbEndpointDescriptor


## 概述

标准端点描述符，对应USB协议中Standard Endpoint Descriptor。

**起始版本：**

10

**相关模块:**

[USB DDK](_usb_ddk.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [bLength](#blength) | 该描述符的大小，单位为字节。 |
| [bDescriptorType](#bdescriptortype) | 描述符类型。 |
| [bEndpointAddress](#bendpointaddress) | 端点地址，包含端点编号以及端点方向。 |
| [bmAttributes](#bmattributes) | 端点属性，包括传输类型、同步类型、使用类型。 |
| [wMaxPacketSize](#wmaxpacketsize) | 该端点所能承载的最大包的大小。 |
| [bInterval](#binterval) | 数据传输轮询端点的时间间隔。 |
| [bRefresh](#brefresh) | 用于音频类设备，同步反馈的速率。 |
| [bSynchAddress](#bsynchaddress) | 用于音频类设备，同步端点的地址。 |


## 结构体成员变量说明


### bDescriptorType


```
uint8_t UsbEndpointDescriptor::bDescriptorType
```

**描述:**

描述符类型。


### bEndpointAddress


```
uint8_t UsbEndpointDescriptor::bEndpointAddress
```

**描述:**

端点地址，包含端点编号以及端点方向。


### bInterval


```
uint8_t UsbEndpointDescriptor::bInterval
```

**描述:**

数据传输轮询端点的时间间隔。


### bLength


```
uint8_t UsbEndpointDescriptor::bLength
```

**描述:**

该描述符的大小，单位为字节。


### bmAttributes


```
uint8_t UsbEndpointDescriptor::bmAttributes
```

**描述:**

端点属性，包括传输类型、同步类型、使用类型。


### bRefresh


```
uint8_t UsbEndpointDescriptor::bRefresh
```

**描述:**

用于音频类设备，同步反馈的速率。


### bSynchAddress


```
uint8_t UsbEndpointDescriptor::bSynchAddress
```

**描述:**

用于音频类设备，同步端点的地址。


### wMaxPacketSize


```
uint16_t UsbEndpointDescriptor::wMaxPacketSize
```

**描述:**

该端点所能承载的最大包的大小。
