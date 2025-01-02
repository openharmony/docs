# UsbCtrlTransfer


## 概述

USB设备控制传输信息。

**起始版本：** 3.2

**相关模块：**[USB](_u_s_b_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [requestType](#requesttype) | 请求类型。  | 
| int [requestCmd](#requestcmd) | 请求命令。  | 
| int [value](#value) | 请求值。  | 
| int [index](#index) | 索引值。  | 
| int [timeout](#timeout) | 超时时间。  | 


## 类成员变量说明


### index

```
int UsbCtrlTransfer::index
```
**描述**

索引值。


### requestCmd

```
int UsbCtrlTransfer::requestCmd
```
**描述**

请求命令。


### requestType

```
int UsbCtrlTransfer::requestType
```
**描述**

请求类型。


### timeout

```
int UsbCtrlTransfer::timeout
```
**描述**

超时时间。


### value

```
int UsbCtrlTransfer::value
```
**描述**

请求值。
