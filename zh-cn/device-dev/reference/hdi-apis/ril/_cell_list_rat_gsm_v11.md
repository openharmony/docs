# CellListRatGsm


## 概述

GSM小区信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [band](#band) | 小区的band信息  | 
| int [arfcn](#arfcn) | BCCH（Broadcast Control Channel）载频的绝对射频频道号，取值范围0~1023  | 
| int [bsic](#bsic) | 基站识别码  | 
| int [cellId](#cellid) | 小区信息标识  | 
| int [lac](#lac) | 位置区号，取值范围0~0xFFFF  | 
| int [rxlev](#rxlev) | 信号接收强度，取值范围-120~37  | 


## 类成员变量说明


### arfcn

```
int CellListRatGsm::arfcn
```
**描述**

BCCH（Broadcast Control Channel）载频的绝对射频频道号，取值范围0~1023


### band

```
int CellListRatGsm::band
```
**描述**

小区的band信息


### bsic

```
int CellListRatGsm::bsic
```
**描述**

基站识别码


### cellId

```
int CellListRatGsm::cellId
```
**描述**

小区信息标识


### lac

```
int CellListRatGsm::lac
```
**描述**

位置区号，取值范围0~0xFFFF


### rxlev

```
int CellListRatGsm::rxlev
```
**描述**

信号接收强度，取值范围-120~37
