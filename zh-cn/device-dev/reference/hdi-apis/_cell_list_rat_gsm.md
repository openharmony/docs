# CellListRatGsm


## 概述

GSM小区信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [band](#band) | int<br/>小区的band信息&nbsp; | 
| [arfcn](#arfcn) | int<br/>BCCH（Broadcast&nbsp;Control&nbsp;Channel）载频的绝对射频频道号，取值范围0~1023&nbsp; | 
| [bsic](#bsic) | int<br/>基站识别码&nbsp; | 
| [cellId](#cellid) | int<br/>小区信息标识&nbsp; | 
| [lac](#lac) | int<br/>位置区号，取值范围0~0xFFFF&nbsp; | 
| [rxlev](#rxlev) | int<br/>信号接收强度，取值范围-120~37&nbsp; | 


## 类成员变量说明


### arfcn

  
```
int CellListRatGsm::arfcn
```
**描述:**
BCCH（Broadcast Control Channel）载频的绝对射频频道号，取值范围0~1023


### band

  
```
int CellListRatGsm::band
```
**描述:**
小区的band信息


### bsic

  
```
int CellListRatGsm::bsic
```
**描述:**
基站识别码


### cellId

  
```
int CellListRatGsm::cellId
```
**描述:**
小区信息标识


### lac

  
```
int CellListRatGsm::lac
```
**描述:**
位置区号，取值范围0~0xFFFF


### rxlev

  
```
int CellListRatGsm::rxlev
```
**描述:**
信号接收强度，取值范围-120~37
