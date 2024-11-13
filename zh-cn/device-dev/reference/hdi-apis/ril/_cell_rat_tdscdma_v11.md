# CellRatTdscdma


## 概述

TDSCDMA蜂窝信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [arfcn](#arfcn) | BCCH载频的绝对射频频道号  | 
| int [syncId](#syncid) | 同步标识  | 
| int [sc](#sc) | 超级小区  | 
| int [cellId](#cellid) | 小区标识  | 
| int [lac](#lac) | 地区区域码  | 
| int [rscp](#rscp) | 接收信号码功率  | 
| int [drx](#drx) | 不连续接收周期长度  | 
| int [rac](#rac) | 路由区域码  | 
| int [cpid](#cpid) | 超级小区标识  | 


## 类成员变量说明


### arfcn

```
int CellRatTdscdma::arfcn
```
**描述**

BCCH载频的绝对射频频道号


### cellId

```
int CellRatTdscdma::cellId
```
**描述**

小区标识


### cpid

```
int CellRatTdscdma::cpid
```
**描述**

超级小区标识


### drx

```
int CellRatTdscdma::drx
```
**描述**

不连续接收周期长度


### lac

```
int CellRatTdscdma::lac
```
**描述**

地区区域码


### rac

```
int CellRatTdscdma::rac
```
**描述**

路由区域码


### rscp

```
int CellRatTdscdma::rscp
```
**描述**

接收信号码功率


### sc

```
int CellRatTdscdma::sc
```
**描述**

超级小区


### syncId

```
int CellRatTdscdma::syncId
```
**描述**

同步标识
