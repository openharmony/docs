# CellRatWcdma


## 概述

WCDMA蜂窝信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [arfcn](#arfcn) | BCCH载频的绝对射频频道号，取值范围0~16383  | 
| int [psc](#psc) | 主扰码，取值范围0~511  | 
| int [cellId](#cellid) | 小区标识  | 
| int [lac](#lac) | 位置区号，取值范围0~0xFFFF  | 
| int [rscp](#rscp) | 信号接收功率dBm， 取值范围-140~-44  | 
| int [rxlev](#rxlev) | 信号接收强度，取值范围-19~-3  | 
| int [ecno](#ecno) | 接收信号强度dbm，取值范围-90~-25  | 
| int [drx](#drx) | 不连续接收周期长度，取值范围6~9  | 
| int [ura](#ura) | UTRAN（UMTS Terrestrial Radio Access Network）注册区域标识  | 


## 类成员变量说明


### arfcn

```
int CellRatWcdma::arfcn
```
**描述**

BCCH载频的绝对射频频道号，取值范围0~16383


### cellId

```
int CellRatWcdma::cellId
```
**描述**

小区标识


### drx

```
int CellRatWcdma::drx
```
**描述**

不连续接收周期长度，取值范围6~9


### ecno

```
int CellRatWcdma::ecno
```
**描述**

接收信号强度dbm，取值范围-90~-25


### lac

```
int CellRatWcdma::lac
```
**描述**

位置区号，取值范围0~0xFFFF


### psc

```
int CellRatWcdma::psc
```
**描述**

主扰码，取值范围0~511


### rscp

```
int CellRatWcdma::rscp
```
**描述**

信号接收功率dBm， 取值范围-140~-44


### rxlev

```
int CellRatWcdma::rxlev
```
**描述**

信号接收强度，取值范围-19~-3


### ura

```
int CellRatWcdma::ura
```
**描述**

UTRAN（UMTS Terrestrial Radio Access Network）注册区域标识
