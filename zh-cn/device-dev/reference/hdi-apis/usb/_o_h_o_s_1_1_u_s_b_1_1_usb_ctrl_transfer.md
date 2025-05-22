# UsbCtrlTransfer

## 概述

USB控制传输。

**起始版本：** 3.0

**相关模块：**[USB](_u_s_b.md)

## 汇总

### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [requestType](#requesttype) | 请求类型。  | 
| int32_t [requestCmd](#requestcmd) | 请求命令字。  | 
| int32_t [value](#value) | 请求值。  | 
| int32_t [index](#index) | 索引。  | 
| int32_t [timeout](#timeout) | 超时时间。  | 

## 类成员变量说明

### index

```
int32_t UsbCtrlTransfer::index
```
**描述**

索引。

### requestCmd

```
int32_t UsbCtrlTransfer::requestCmd
```
**描述**

请求命令字。

### requestType

```
int32_t UsbCtrlTransfer::requestType
```
**描述**

请求类型。

### timeout

```
int32_t UsbCtrlTransfer::timeout
```
**描述**

超时时间。

### value

```
int32_t UsbCtrlTransfer::value
```
**描述**

请求值。
