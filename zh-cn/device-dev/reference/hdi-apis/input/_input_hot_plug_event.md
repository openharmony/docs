# InputHotPlugEvent


## 概述

热插拔事件数据包结构。

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [devIndex](#devindex) | 设备索引  | 
| uint32_t [devType](#devtype) | 设备类型  | 
| uint32_t [status](#status) | 设备状态 | 


## 类成员变量说明


### devIndex

```
uint32_t InputHotPlugEvent::devIndex
```
**描述**

设备索引。


### devType

```
uint32_t InputHotPlugEvent::devType
```
**描述**

设备类型。


### status

```
uint32_t InputHotPlugEvent::status
```
**描述**

设备状态。

- 1: 离线。

- 0: 在线。 
