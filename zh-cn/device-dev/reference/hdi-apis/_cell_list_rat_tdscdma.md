# CellListRatTdscdma


## 概述

TDSCDMA小区信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [arfcn](#arfcn) | int<br/>BCCH载频的绝对射频频道号&nbsp; | 
| [syncId](#syncid) | int<br/>同步标识&nbsp; | 
| [sc](#sc) | int<br/>超级小区&nbsp; | 
| [cellId](#cellid) | int<br/>小区标识&nbsp; | 
| [lac](#lac) | int<br/>位置区号，取值范围0~0xFFFF&nbsp; | 
| [rscp](#rscp) | int<br/>接收信号码功率&nbsp; | 
| [drx](#drx) | int<br/>不连续接收周期长度&nbsp; | 
| [rac](#rac) | int<br/>路由区域码&nbsp; | 
| [cpid](#cpid) | int<br/>超级小区标识&nbsp; | 


## 类成员变量说明


### arfcn

  
```
int CellListRatTdscdma::arfcn
```
**描述:**
BCCH载频的绝对射频频道号


### cellId

  
```
int CellListRatTdscdma::cellId
```
**描述:**
小区标识


### cpid

  
```
int CellListRatTdscdma::cpid
```
**描述:**
超级小区标识


### drx

  
```
int CellListRatTdscdma::drx
```
**描述:**
不连续接收周期长度


### lac

  
```
int CellListRatTdscdma::lac
```
**描述:**
位置区号，取值范围0~0xFFFF


### rac

  
```
int CellListRatTdscdma::rac
```
**描述:**
路由区域码


### rscp

  
```
int CellListRatTdscdma::rscp
```
**描述:**
接收信号码功率


### sc

  
```
int CellListRatTdscdma::sc
```
**描述:**
超级小区


### syncId

  
```
int CellListRatTdscdma::syncId
```
**描述:**
同步标识
