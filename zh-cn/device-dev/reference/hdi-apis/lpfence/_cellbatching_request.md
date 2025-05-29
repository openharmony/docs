# CellbatchingRequest


## 概述

定义设置基站轨迹数据上报功能的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceCellbatching](_hdi_lpfence_cellbatching.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [status](#status) | 基站轨迹数据记录功能开关，详见[CellbatchingSwitch](_hdi_lpfence_cellbatching.md#cellbatchingswitch)。  | 
| int [interval](#interval) | 设置modem接收基站数据的时间间隔，单位为秒，最小间隔30秒，最大间隔240秒。  | 


## 类成员变量说明


### interval

```
int CellbatchingRequest::interval
```
**描述**

设置modem接收基站数据的时间间隔，单位为秒，最小间隔30秒，最大间隔240秒。


### status

```
int CellbatchingRequest::status
```
**描述**

基站轨迹数据记录功能开关，详见[CellbatchingSwitch](_hdi_lpfence_cellbatching.md#cellbatchingswitch)。
