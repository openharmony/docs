# UsbDeviceDescriptor


## 概述

标准设备描述符，对应于USB协议中的**标准设备描述符**。

**起始版本：** 4.0

**相关模块：**[HdiUsbDdk](_hdi_usb_ddk.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned char [bLength](#blength) | 描述符的大小，以字节为单位。  | 
| unsigned char [bDescriptorType](#bdescriptortype) | 描述符类型。  | 
| unsigned short [bcdUSB](#bcdusb) | USB协议版本号。  | 
| unsigned char [bDeviceClass](#bdeviceclass) | USB-IF分配的设备类别代码。  | 
| unsigned char [bDeviceSubClass](#bdevicesubclass) | USB-IF分配的设备子类代码。该值受bDeviceClass的值限制。  | 
| unsigned char [bDeviceProtocol](#bdeviceprotocol) | USB-IF分配的协议代码。该值受bDeviceClass和bDeviceSubClass的限制。  | 
| unsigned char [bMaxPacketSize0](#bmaxpacketsize0) | 终结点0的最大数据包大小。只有值8、16、32和64是有效的。  | 
| unsigned short [idVendor](#idvendor) | USB-IF分配的供应商ID。  | 
| unsigned short [idProduct](#idproduct) | 供应商分配的产品ID。  | 
| unsigned short [bcdDevice](#bcddevice) | 设备发布编号。  | 
| unsigned char [iManufacturer](#imanufacturer) | 描述供应商的字符串描述符的索引。  | 
| unsigned char [iProduct](#iproduct) | 描述产品的字符串描述符的索引。  | 
| unsigned char [iSerialNumber](#iserialnumber) | 描述设备SN的字符串描述符的索引。  | 
| unsigned char [bNumConfigurations](#bnumconfigurations) | 配置数量。  | 


## 类成员变量说明


### bcdDevice

```
unsigned short UsbDeviceDescriptor::bcdDevice
```
**描述**

设备发布编号。


### bcdUSB

```
unsigned short UsbDeviceDescriptor::bcdUSB
```
**描述**

USB协议版本号。


### bDescriptorType

```
unsigned char UsbDeviceDescriptor::bDescriptorType
```
**描述**

描述符类型。


### bDeviceClass

```
unsigned char UsbDeviceDescriptor::bDeviceClass
```
**描述**

USB-IF分配的设备类别代码。


### bDeviceProtocol

```
unsigned char UsbDeviceDescriptor::bDeviceProtocol
```
**描述**

USB-IF分配的协议代码。该值受bDeviceClass和bDeviceSubClass的限制。


### bDeviceSubClass

```
unsigned char UsbDeviceDescriptor::bDeviceSubClass
```
**描述**

USB-IF分配的设备子类代码。该值受bDeviceClass的值限制。


### bLength

```
unsigned char UsbDeviceDescriptor::bLength
```
**描述**

描述符的大小，以字节为单位。


### bMaxPacketSize0

```
unsigned char UsbDeviceDescriptor::bMaxPacketSize0
```
**描述**

终结点0的最大数据包大小。只有值8、16、32和64是有效的。


### bNumConfigurations

```
unsigned char UsbDeviceDescriptor::bNumConfigurations
```
**描述**

配置数量。


### idProduct

```
unsigned short UsbDeviceDescriptor::idProduct
```
**描述**

供应商分配的产品ID。


### idVendor

```
unsigned short UsbDeviceDescriptor::idVendor
```
**描述**

USB-IF分配的供应商ID。


### iManufacturer

```
unsigned char UsbDeviceDescriptor::iManufacturer
```
**描述**

描述供应商的字符串描述符的索引。


### iProduct

```
unsigned char UsbDeviceDescriptor::iProduct
```
**描述**

描述产品的字符串描述符的索引。


### iSerialNumber

```
unsigned char UsbDeviceDescriptor::iSerialNumber
```
**描述**

描述设备SN的字符串描述符的索引。
