# LteRssi


## 概述

LTE信号强度。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [rxlev](#rxlev) | int<br/>信号接收强度，取值范围0~99&nbsp; | 
| [rsrq](#rsrq) | int<br/>表示信号接收质量，取值范围0~33&nbsp; | 
| [rsrp](#rsrp) | int<br/>表示接收信号码功率，取值范围0~97&nbsp; | 
| [snr](#snr) | int<br/>表示信号干扰噪声比，适用于LTE模式，取值范围0~251&nbsp; | 


## 类成员变量说明


### rsrp

  
```
int LteRssi::rsrp
```
**描述:**
表示接收信号码功率，取值范围0~97


### rsrq

  
```
int LteRssi::rsrq
```
**描述:**
表示信号接收质量，取值范围0~33


### rxlev

  
```
int LteRssi::rxlev
```
**描述:**
信号接收强度，取值范围0~99


### snr

  
```
int LteRssi::snr
```
**描述:**
表示信号干扰噪声比，适用于LTE模式，取值范围0~251
