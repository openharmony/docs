# CellRatGsm


## 概述

GSM蜂窝信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [band](#band) | 小区的band信息  | 
| int [arfcn](#arfcn) | BCCH载频的绝对射频频道号，取值范围0~1023  | 
| int [bsic](#bsic) | 基站识别码  | 
| int [cellId](#cellid) | 小区标识  | 
| int [lac](#lac) | 位置区号，取值范围0~0xFFFF  | 
| int [rxlev](#rxlev) | 信号接收强度，取值范围-120~37  | 
| int [rxQuality](#rxquality) | 信号接收质量，取值范围0~7  | 
| int [ta](#ta) | 取值范围0~63  | 


## 类成员变量说明


### arfcn

```
int CellRatGsm::arfcn
```
**描述**

BCCH载频的绝对射频频道号，取值范围0~1023


### band

```
int CellRatGsm::band
```
**描述**

小区的band信息


### bsic

```
int CellRatGsm::bsic
```
**描述**

基站识别码


### cellId

```
int CellRatGsm::cellId
```
**描述**

小区标识


### lac

```
int CellRatGsm::lac
```
**描述**

位置区号，取值范围0~0xFFFF


### rxlev

```
int CellRatGsm::rxlev
```
**描述**

信号接收强度，取值范围-120~37


### rxQuality

```
int CellRatGsm::rxQuality
```
**描述**

信号接收质量，取值范围0~7


### ta

```
int CellRatGsm::ta
```
**描述**

取值范围0~63
