# CellListRatLte


## 概述

LTE小区信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [arfcn](#arfcn) | BCCH载频的绝对射频频道号，取值范围0~1023  | 
| int [pci](#pci) | 物理小区标识  | 
| int [rsrp](#rsrp) | 信号接收功率，取值范围-140~-44  | 
| int [rsrq](#rsrq) | 信号接收质量，取值范围-19~-3  | 
| int [rxlev](#rxlev) | 信号接收强度，取值范围-120~37  | 


## 类成员变量说明


### arfcn

```
int CellListRatLte::arfcn
```
**描述**

BCCH载频的绝对射频频道号，取值范围0~1023


### pci

```
int CellListRatLte::pci
```
**描述**

物理小区标识


### rsrp

```
int CellListRatLte::rsrp
```
**描述**

信号接收功率，取值范围-140~-44


### rsrq

```
int CellListRatLte::rsrq
```
**描述**

信号接收质量，取值范围-19~-3


### rxlev

```
int CellListRatLte::rxlev
```
**描述**

信号接收强度，取值范围-120~37
