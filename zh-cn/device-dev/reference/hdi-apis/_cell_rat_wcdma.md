# CellRatWcdma


## 概述

WCDMA蜂窝信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [arfcn](#arfcn) | int<br/>BCCH载频的绝对射频频道号，取值范围0~16383&nbsp; | 
| [psc](#psc) | int<br/>主扰码，取值范围0~511&nbsp; | 
| [cellId](#cellid) | int<br/>小区标识&nbsp; | 
| [lac](#lac) | int<br/>位置区号，取值范围0~0xFFFF&nbsp; | 
| [rscp](#rscp) | int<br/>信号接收功率dBm，&nbsp;取值范围-140~-44&nbsp; | 
| [rxlev](#rxlev) | int<br/>信号接收强度，取值范围-19~-3&nbsp; | 
| [ecno](#ecno) | int<br/>接收信号强度dbm，取值范围-90~-25&nbsp; | 
| [drx](#drx) | int<br/>不连续接收周期长度，取值范围6~9&nbsp; | 
| [ura](#ura) | int<br/>UTRAN（UMTS&nbsp;Terrestrial&nbsp;Radio&nbsp;Access&nbsp;Network）注册区域标识&nbsp; | 


## 类成员变量说明


### arfcn

  
```
int CellRatWcdma::arfcn
```
**描述:**
BCCH载频的绝对射频频道号，取值范围0~16383


### cellId

  
```
int CellRatWcdma::cellId
```
**描述:**
小区标识


### drx

  
```
int CellRatWcdma::drx
```
**描述:**
不连续接收周期长度，取值范围6~9


### ecno

  
```
int CellRatWcdma::ecno
```
**描述:**
接收信号强度dbm，取值范围-90~-25


### lac

  
```
int CellRatWcdma::lac
```
**描述:**
位置区号，取值范围0~0xFFFF


### psc

  
```
int CellRatWcdma::psc
```
**描述:**
主扰码，取值范围0~511


### rscp

  
```
int CellRatWcdma::rscp
```
**描述:**
信号接收功率dBm， 取值范围-140~-44


### rxlev

  
```
int CellRatWcdma::rxlev
```
**描述:**
信号接收强度，取值范围-19~-3


### ura

  
```
int CellRatWcdma::ura
```
**描述:**
UTRAN（UMTS Terrestrial Radio Access Network）注册区域标识
