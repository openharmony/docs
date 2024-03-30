# UsbDeviceDescriptor


## 概述

标准设备描述符，对应USB协议中Standard Device Descriptor。

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
| [bcdUSB](#bcdusb) | USB协议发布号。 |
| [bDeviceClass](#bdeviceclass) | 由USB标准化组织（USB-IF）分配的设备类代码。 |
| [bDeviceSubClass](#bdevicesubclass) | 由USB标准化组织（USB-IF）分配的子类代码，其值由[bDeviceClass](#bdeviceclass)的值限定。 |
| [bDeviceProtocol](#bdeviceprotocol) | 由USB标准化组织（USB-IF）分配的协议代码，其值由[bDeviceClass](#bdeviceclass)和[bDeviceSubClass](#bdevicesubclass)的值限定。 |
| [bMaxPacketSize0](#bmaxpacketsize0) | 端点零的最大包大小，只有8，16，32，64是合法的。 |
| [idVendor](#idvendor) | 由USB标准化组织（USB-IF）分配的厂商编号。 |
| [idProduct](#idproduct) | 由厂商分配的产品编号。 |
| [bcdDevice](#bcddevice) | 设备发布编号。 |
| [iManufacturer](#imanufacturer) | 描述厂商的字符串描述符的索引。 |
| [iProduct](#iproduct) | 描述产品的字符串描述符的索引。 |
| [iSerialNumber](#iserialnumber) | 描述设备序列号的字符串描述符的索引。 |
| [bNumConfigurations](#bnumconfigurations) | 配置数量。 |


## 结构体成员变量说明


### bcdDevice


```
uint16_t UsbDeviceDescriptor::bcdDevice
```

**描述:**

设备发布编号。


### bcdUSB


```
uint16_t UsbDeviceDescriptor::bcdUSB
```

**描述:**

USB协议发布号。


### bDescriptorType


```
uint8_t UsbDeviceDescriptor::bDescriptorType
```

**描述:**

描述符类型。


### bDeviceClass


```
uint8_t UsbDeviceDescriptor::bDeviceClass
```

**描述:**

由USB标准化组织（USB-IF）分配的设备类代码。


### bDeviceProtocol


```
uint8_t UsbDeviceDescriptor::bDeviceProtocol
```

**描述:**

由USB标准化组织（USB-IF）分配的协议代码，其值由[bDeviceClass](#bdeviceclass)和[bDeviceSubClass](#bdevicesubclass)的值限定。


### bDeviceSubClass


```
uint8_t UsbDeviceDescriptor::bDeviceSubClass
```

**描述:**

由USB标准化组织（USB-IF）分配的子类代码，其值由[bDeviceClass](#bdeviceclass)的值限定。


### bLength


```
uint8_t UsbDeviceDescriptor::bLength
```

**描述:**

该描述符的大小，单位为字节。


### bMaxPacketSize0


```
uint8_t UsbDeviceDescriptor::bMaxPacketSize0
```

**描述:**

端点零的最大包大小，只有8、16、32、64是合法的。


### bNumConfigurations


```
uint8_t UsbDeviceDescriptor::bNumConfigurations
```

**描述:**

配置数量。


### idProduct


```
uint16_t UsbDeviceDescriptor::idProduct
```

**描述:**

由厂商分配的产品编号。


### idVendor


```
uint16_t UsbDeviceDescriptor::idVendor
```

**描述:**

由USB标准化组织（USB-IF）分配的厂商编号。


### iManufacturer


```
uint8_t UsbDeviceDescriptor::iManufacturer
```

**描述:**

描述厂商的字符串描述符的索引。


### iProduct


```
uint8_t UsbDeviceDescriptor::iProduct
```

**描述:**

描述产品的字符串描述符的索引。


### iSerialNumber


```
uint8_t UsbDeviceDescriptor::iSerialNumber
```

**描述:**

描述设备序列号的字符串描述符的索引。
