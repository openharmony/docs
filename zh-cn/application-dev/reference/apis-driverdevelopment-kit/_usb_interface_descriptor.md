# UsbInterfaceDescriptor


## 概述

标准接口描述符，对应USB协议中Standard Interface Descriptor。

**起始版本：**

10

**相关模块:**

[USB DDK](_usb_ddk.md)

**所在头文件：** [usb_ddk_types.h](usb__ddk__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [bLength](#blength) | 该描述符的大小，单位为字节。 |
| [bDescriptorType](#bdescriptortype) | 描述符类型。 |
| [bInterfaceNumber](#binterfacenumber) | 接口编号。 |
| [bAlternateSetting](#balternatesetting) | 用来选择该接口的备用配置的值。 |
| [bNumEndpoints](#bnumendpoints) | 该接口所使用的端点数量（不包括端点零）。 |
| [bInterfaceClass](#binterfaceclass) | 由USB标准化组织（USB-IF）分配的设备类代码。 |
| [bInterfaceSubClass](#binterfacesubclass) | 由USB标准化组织（USB-IF）分配的子类代码，其值由[bInterfaceClass](#binterfaceclass)的值限定。 |
| [bInterfaceProtocol](#binterfaceprotocol) | 由USB标准化组织（USB-IF）分配的协议代码，其值由[bInterfaceClass](#binterfaceclass)和[bInterfaceSubClass](#binterfacesubclass)的值限定。 |
| [iInterface](#iinterface) | 描述该接口的字符串描述符的索引。 |


## 结构体成员变量说明


### bAlternateSetting


```
uint8_t UsbInterfaceDescriptor::bAlternateSetting
```

**描述:**

用来选择该接口的备用配置的值。


### bDescriptorType


```
uint8_t UsbInterfaceDescriptor::bDescriptorType
```

**描述:**

描述符类型。


### bInterfaceClass


```
uint8_t UsbInterfaceDescriptor::bInterfaceClass
```

**描述:**

由USB标准化组织（USB-IF）分配的设备类代码。


### bInterfaceNumber


```
uint8_t UsbInterfaceDescriptor::bInterfaceNumber
```

**描述:**

接口编号。


### bInterfaceProtocol


```
uint8_t UsbInterfaceDescriptor::bInterfaceProtocol
```

**描述:**

由USB标准化组织（USB-IF）分配的协议代码，其值由[bInterfaceClass](#binterfaceclass)和[bInterfaceSubClass](#binterfacesubclass)的值限定。


### bInterfaceSubClass


```
uint8_t UsbInterfaceDescriptor::bInterfaceSubClass
```

**描述:**

由USB标准化组织（USB-IF）分配的子类代码，其值由[bInterfaceClass](#binterfaceclass)的值限定。


### bLength


```
uint8_t UsbInterfaceDescriptor::bLength
```

**描述:**

该描述符的大小，单位为字节。


### bNumEndpoints


```
uint8_t UsbInterfaceDescriptor::bNumEndpoints
```

**描述:**

该接口所使用的端点数量（不包括端点零）。


### iInterface


```
uint8_t UsbInterfaceDescriptor::iInterface
```

**描述:**

描述该接口的字符串描述符的索引。
