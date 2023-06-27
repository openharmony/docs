# PsRegStatusInfo


## 概述

PS注册状态信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [notifyType](#notifytype) | int<br/>通知类型 | 
| [regStatus](#regstatus) | enum&nbsp;[RilRegStatus](_ril.md#rilregstatus)<br/>注册状态，具体查看[RilRegStatus](_ril.md#rilregstatus) | 
| [lacCode](#laccode) | int<br/>地区区域码&nbsp; | 
| [cellId](#cellid) | int<br/>小区标识&nbsp; | 
| [radioTechnology](#radiotechnology) | enum&nbsp;[RilRadioTech](_ril.md#rilradiotech)<br/>语音接入技术类型，具体查看[RilRadioTech](_ril.md#rilradiotech) | 
| [isNrAvailable](#isnravailable) | boolean<br/>表示NR模式是否可用&nbsp; | 
| [isEnDcAvailable](#isendcavailable) | boolean<br/>表示ENDC是否可用&nbsp; | 
| [isDcNrRestricted](#isdcnrrestricted) | boolean<br/>表示DCNR是否受限&nbsp; | 


## 类成员变量说明


### cellId

  
```
int PsRegStatusInfo::cellId
```
**描述:**
小区标识


### isDcNrRestricted

  
```
boolean PsRegStatusInfo::isDcNrRestricted
```
**描述:**
表示DCNR是否受限


### isEnDcAvailable

  
```
boolean PsRegStatusInfo::isEnDcAvailable
```
**描述:**
表示ENDC是否可用


### isNrAvailable

  
```
boolean PsRegStatusInfo::isNrAvailable
```
**描述:**
表示NR模式是否可用


### lacCode

  
```
int PsRegStatusInfo::lacCode
```
**描述:**
地区区域码


### notifyType

  
```
int PsRegStatusInfo::notifyType
```
**描述:**
通知类型

- 0：禁止主动上报

- 1：使用格式1上报，具体由芯片自定义

- 2：使用格式2上报，具体由芯片自定义 


### radioTechnology

  
```
enum RilRadioTech PsRegStatusInfo::radioTechnology
```
**描述:**
语音接入技术类型，具体查看[RilRadioTech](_ril.md#rilradiotech)


### regStatus

  
```
enum RilRegStatus PsRegStatusInfo::regStatus
```
**描述:**
注册状态，具体查看[RilRegStatus](_ril.md#rilregstatus)
