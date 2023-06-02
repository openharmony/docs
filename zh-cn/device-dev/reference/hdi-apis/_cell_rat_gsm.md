# CellRatGsm


## 概述

GSM蜂窝信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [band](#band) | int<br/>小区的band信息&nbsp; | 
| [arfcn](#arfcn) | int<br/>BCCH载频的绝对射频频道号，取值范围0~1023&nbsp; | 
| [bsic](#bsic) | int<br/>基站识别码&nbsp; | 
| [cellId](#cellid) | int<br/>小区标识&nbsp; | 
| [lac](#lac) | int<br/>位置区号，取值范围0~0xFFFF&nbsp; | 
| [rxlev](#rxlev) | int<br/>信号接收强度，取值范围-120~37&nbsp; | 
| [rxQuality](#rxquality) | int<br/>信号接收质量，取值范围0~7&nbsp; | 
| [ta](#ta) | int<br/>取值范围0~63&nbsp; | 


## 类成员变量说明


### arfcn

  
```
int CellRatGsm::arfcn
```
**描述:**
BCCH载频的绝对射频频道号，取值范围0~1023


### band

  
```
int CellRatGsm::band
```
**描述:**
小区的band信息


### bsic

  
```
int CellRatGsm::bsic
```
**描述:**
基站识别码


### cellId

  
```
int CellRatGsm::cellId
```
**描述:**
小区标识


### lac

  
```
int CellRatGsm::lac
```
**描述:**
位置区号，取值范围0~0xFFFF


### rxlev

  
```
int CellRatGsm::rxlev
```
**描述:**
信号接收强度，取值范围-120~37


### rxQuality

  
```
int CellRatGsm::rxQuality
```
**描述:**
信号接收质量，取值范围0~7


### ta

  
```
int CellRatGsm::ta
```
**描述:**
取值范围0~63
