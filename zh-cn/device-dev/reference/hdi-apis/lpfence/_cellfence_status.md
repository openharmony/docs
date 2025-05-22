# CellfenceStatus


## 概述

定义设备与基站围栏状态关系的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceCellfence](_hdi_lpfence_cellfence.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [cellfenceId](#cellfenceid) | 基站围栏的ID号，用于标识某个基站围栏。  | 
| unsigned short [status](#status) | 设备与该基站围栏的位置关系。详见[CellfenceTransition](_hdi_lpfence_cellfence.md#cellfencetransition)。  | 


## 类成员变量说明


### cellfenceId

```
int CellfenceStatus::cellfenceId
```
**描述**

基站围栏的ID号，用于标识某个基站围栏。


### status

```
unsigned short CellfenceStatus::status
```
**描述**

设备与该基站围栏的位置关系。详见[CellfenceTransition](_hdi_lpfence_cellfence.md#cellfencetransition)。
