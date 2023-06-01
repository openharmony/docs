# CellListRatWcdma


## 概述

WCDMA小区信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [arfcn](#arfcn) | int<br/>BCCH载频的绝对射频频道号，取值范围0~16383&nbsp; | 
| [psc](#psc) | int<br/>主扰码，&nbsp;取值范围0~511&nbsp; | 
| [rscp](#rscp) | int<br/>接收信号码功率，&nbsp;取值范围-120~25&nbsp; | 
| [ecno](#ecno) | int<br/>每个调制比特的功率与噪声频谱密度之比,&nbsp;取值范围-25~0&nbsp; | 


## 类成员变量说明


### arfcn

  
```
int CellListRatWcdma::arfcn
```
**描述:**
BCCH载频的绝对射频频道号，取值范围0~16383


### ecno

  
```
int CellListRatWcdma::ecno
```
**描述:**
每个调制比特的功率与噪声频谱密度之比, 取值范围-25~0


### psc

  
```
int CellListRatWcdma::psc
```
**描述:**
主扰码， 取值范围0~511


### rscp

  
```
int CellListRatWcdma::rscp
```
**描述:**
接收信号码功率， 取值范围-120~25
