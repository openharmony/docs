# UsbRequestPipe


## 概述

请求管道。

**起始版本：** 4.0

**相关模块：**[HdiUsbDdk](_hdi_usb_ddk.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [interfaceHandle](#interfacehandle) | 接口操作处理。  | 
| unsigned int [timeout](#timeout) | 超时持续时间，以毫秒为单位。  | 
| unsigned char [endpoint](#endpoint) | 端点地址。  | 


## 类成员变量说明


### endpoint

```
unsigned char UsbRequestPipe::endpoint
```
**描述**

端点地址。


### interfaceHandle

```
unsigned long UsbRequestPipe::interfaceHandle
```
**描述**

接口操作处理。


### timeout

```
unsigned int UsbRequestPipe::timeout
```
**描述**

超时持续时间，以毫秒为单位。
