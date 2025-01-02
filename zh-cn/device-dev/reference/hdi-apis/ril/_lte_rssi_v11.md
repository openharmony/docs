# LteRssi


## 概述

LTE信号强度。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [rxlev](#rxlev) | 信号接收强度，取值范围0~99  | 
| int [rsrq](#rsrq) | 表示信号接收质量，取值范围0~33  | 
| int [rsrp](#rsrp) | 表示接收信号码功率，取值范围0~97  | 
| int [snr](#snr) | 表示信号干扰噪声比，适用于LTE模式，取值范围0~251  | 


## 类成员变量说明


### rsrp

```
int LteRssi::rsrp
```
**描述**

表示接收信号码功率，取值范围0~97


### rsrq

```
int LteRssi::rsrq
```
**描述**

表示信号接收质量，取值范围0~33


### rxlev

```
int LteRssi::rxlev
```
**描述**

信号接收强度，取值范围0~99


### snr

```
int LteRssi::snr
```
**描述**

表示信号干扰噪声比，适用于LTE模式，取值范围0~251
