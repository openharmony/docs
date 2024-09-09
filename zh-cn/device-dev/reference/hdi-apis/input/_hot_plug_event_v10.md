# HotPlugEvent


## 概述

热插拔事件数据包结构。

**起始版本：** 3.2

**相关模块：**[HdiInput](_hdi_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [devIndex](#devindex) | 设备索引  | 
| unsigned int [devType](#devtype) | 设备类型  | 
| unsigned int [status](#status) | 设备状态。 | 


## 类成员变量说明


### devIndex

```
unsigned int HotPlugEvent::devIndex
```
**描述**

设备索引


### devType

```
unsigned int HotPlugEvent::devType
```
**描述**

设备类型


### status

```
unsigned int HotPlugEvent::status
```
**描述**

设备状态。

- 1: 离线。

- 0: 在线。 
