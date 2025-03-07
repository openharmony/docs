# WcdmaRssi


## 概述

WCDMA信号强度。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [rxlev](#rxlev) | 信号接收强度，取值范围0~99  | 
| int [ecio](#ecio) | 每个PN码片的接收能量与总接收功率谱密度之比  | 
| int [rscp](#rscp) | 接收信号码功率，取值范围0~96  | 
| int [ber](#ber) | 误码率，取值范围0~7  | 


## 类成员变量说明


### ber

```
int WcdmaRssi::ber
```
**描述**

误码率，取值范围0~7


### ecio

```
int WcdmaRssi::ecio
```
**描述**

每个PN码片的接收能量与总接收功率谱密度之比


### rscp

```
int WcdmaRssi::rscp
```
**描述**

接收信号码功率，取值范围0~96


### rxlev

```
int WcdmaRssi::rxlev
```
**描述**

信号接收强度，取值范围0~99
