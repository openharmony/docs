# UsbFnMtpFileSlice


## 概述

标准设备描述符，对应于USB协议中的**标准设备描述符**。

**起始版本：** 4.0

**相关模块：**[HdiUsbfnMtp](_hdi_usbfn_mtp.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| FileDescriptor [fd](#fd) | 文件描述符。  | 
| long [offset](#offset) | 管道。  | 
| long [length](#length) | 数据长度。  | 
| unsigned short [command](#command) | 请求命令。  | 
| unsigned int [transactionId](#transactionid) | 传输id。  | 


## 类成员变量说明


### command

```
unsigned short UsbFnMtpFileSlice::command
```
**描述**

请求命令。


### fd

```
FileDescriptor UsbFnMtpFileSlice::fd
```
**描述**

文件描述符。


### length

```
long UsbFnMtpFileSlice::length
```
**描述**

数据长度。


### offset

```
long UsbFnMtpFileSlice::offset
```
**描述**

管道。

### transactionId

```
unsigned int UsbFnMtpFileSlice::transactionId
```
**描述**

传输id。
