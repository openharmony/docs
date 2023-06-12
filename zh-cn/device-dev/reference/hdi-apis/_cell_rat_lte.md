# CellRatLte


## 概述

LTE蜂窝信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [arfcn](#arfcn) | int<br/>BCCH载频的绝对射频频道号&nbsp; | 
| [cellId](#cellid) | int<br/>小区标识&nbsp; | 
| [pci](#pci) | int<br/>物理小区标识&nbsp; | 
| [tac](#tac) | int<br/>类型分配码&nbsp; | 
| [rsrp](#rsrp) | int<br/>信号接收功率，取值范围-140~-44&nbsp; | 
| [rsrq](#rsrq) | int<br/>信号接收质量，取值范围-19~-3&nbsp; | 
| [rssi](#rssi) | int<br/>接收信号强度dbm，-90~-25&nbsp; | 


## 类成员变量说明


### arfcn

  
```
int CellRatLte::arfcn
```
**描述:**
BCCH载频的绝对射频频道号


### cellId

  
```
int CellRatLte::cellId
```
**描述:**
小区标识


### pci

  
```
int CellRatLte::pci
```
**描述:**
物理小区标识


### rsrp

  
```
int CellRatLte::rsrp
```
**描述:**
信号接收功率，取值范围-140~-44


### rsrq

  
```
int CellRatLte::rsrq
```
**描述:**
信号接收质量，取值范围-19~-3


### rssi

  
```
int CellRatLte::rssi
```
**描述:**
接收信号强度dbm，-90~-25


### tac

  
```
int CellRatLte::tac
```
**描述:**
类型分配码
