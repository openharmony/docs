# CellRatNr_1_1


## 概述

NR蜂窝信息。

**起始版本：** 4.0

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [nrArfcn](#nrarfcn) | BCCH载频的绝对射频频道号  | 
| int [pci](#pci) | 物理小区标识  | 
| int [tac](#tac) | 类型分配码  | 
| int [nci](#nci) | NR小区标识  | 
| int [rsrp](#rsrp) | 信号接收功率，取值范围-140~-44  | 
| int [rsrq](#rsrq) | 信号接收质量，取值范围-19~-3  | 


## 类成员变量说明


### nci

```
int CellRatNr_1_1::nci
```
**描述**

NR小区标识


### nrArfcn

```
int CellRatNr_1_1::nrArfcn
```
**描述**

BCCH载频的绝对射频频道号


### pci

```
int CellRatNr_1_1::pci
```
**描述**

物理小区标识


### rsrp

```
int CellRatNr_1_1::rsrp
```
**描述**

信号接收功率，取值范围-140~-44


### rsrq

```
int CellRatNr_1_1::rsrq
```
**描述**

信号接收质量，取值范围-19~-3


### tac

```
int CellRatNr_1_1::tac
```
**描述**

类型分配码
