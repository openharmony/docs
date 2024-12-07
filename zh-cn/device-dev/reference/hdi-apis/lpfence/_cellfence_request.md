# CellfenceRequest


## 概述

定义添加基站围栏的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceCellfence](_hdi_lpfence_cellfence.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [cellfenceId](#cellfenceid) | 基站围栏的ID号，用于标识某个基站围栏，不可重复添加相同ID号的围栏。  | 
| struct [CellfenceInfo](_cellfence_info.md)[] [cellInfo](#cellinfo) | 基站围栏信息，详见[CellfenceInfo](_cellfence_info.md)。  | 


## 类成员变量说明


### cellfenceId

```
int CellfenceRequest::cellfenceId
```
**描述**

基站围栏的ID号，用于标识某个基站围栏，不可重复添加相同ID号的围栏。


### cellInfo

```
struct CellfenceInfo [] CellfenceRequest::cellInfo
```
**描述**

基站围栏信息，详见[CellfenceInfo](_cellfence_info.md)。
