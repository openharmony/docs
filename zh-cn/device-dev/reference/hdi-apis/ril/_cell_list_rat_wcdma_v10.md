# CellListRatWcdma


## 概述

WCDMA小区信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [arfcn](#arfcn) | BCCH载频的绝对射频频道号，取值范围0~16383  | 
| int [psc](#psc) | 主扰码， 取值范围0~511  | 
| int [rscp](#rscp) | 接收信号码功率， 取值范围-120~25  | 
| int [ecno](#ecno) | 每个调制比特的功率与噪声频谱密度之比, 取值范围-25~0  | 


## 类成员变量说明


### arfcn

```
int CellListRatWcdma::arfcn
```
**描述**

BCCH载频的绝对射频频道号，取值范围0~16383


### ecno

```
int CellListRatWcdma::ecno
```
**描述**

每个调制比特的功率与噪声频谱密度之比, 取值范围-25~0


### psc

```
int CellListRatWcdma::psc
```
**描述**

主扰码， 取值范围0~511


### rscp

```
int CellListRatWcdma::rscp
```
**描述**

接收信号码功率， 取值范围-120~25
