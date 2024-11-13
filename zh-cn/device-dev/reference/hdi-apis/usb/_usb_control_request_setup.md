# UsbControlRequestSetup


## 概述

控制传输的设置数据。它对应于USB协议中的**Setup Data**。

**起始版本：** 4.0

**相关模块：**[HdiUsbDdk](_hdi_usb_ddk.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned char [requestType](#requesttype) | 请求类型，对应于USB协议中的bmRequestType。  | 
| unsigned char [requestCmd](#requestcmd) | 请求命令，对应USB协议中的bRequest。  | 
| unsigned short [value](#value) | 与USB协议中的wValue相对应的值。其含义因要求而异。  | 
| unsigned short [index](#index) | 与USB协议中的wIndex相对应的索引。它通常用于传输索引或偏移量。它的含义根据请求而不同。  | 
| unsigned short [length](#length) | 数据长度，对应于USB协议中的wLength。如果传输数据，则此字段指示传输的字节数。  | 


## 类成员变量说明


### index

```
unsigned short UsbControlRequestSetup::index
```
**描述**

与USB协议中的wIndex相对应的索引。它通常用于传输索引或偏移量。它的含义根据请求而不同。


### length

```
unsigned short UsbControlRequestSetup::length
```
**描述**

数据长度，对应于USB协议中的wLength。如果传输数据，则此字段指示传输的字节数。


### requestCmd

```
unsigned char UsbControlRequestSetup::requestCmd
```
**描述**

请求命令，对应USB协议中的bRequest。


### requestType

```
unsigned char UsbControlRequestSetup::requestType
```
**描述**

请求类型，对应于USB协议中的bmRequestType。


### value

```
unsigned short UsbControlRequestSetup::value
```
**描述**

与USB协议中的wValue相对应的值。其含义因要求而异。
