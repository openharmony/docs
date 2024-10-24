# PsRegStatusInfo


## 概述

PS注册状态信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [notifyType](#notifytype) | 通知类型 | 
| enum [RilRegStatus](_ril_v11.md#rilregstatus)[regStatus](#regstatus) | 注册状态，具体查看[RilRegStatus](_ril_v11.md#rilregstatus) | 
| int [lacCode](#laccode) | 地区区域码  | 
| int [cellId](#cellid) | 小区标识  | 
| enum [RilRadioTech](_ril_v11.md#rilradiotech)[radioTechnology](#radiotechnology) | 语音接入技术类型，具体查看[RilRadioTech](_ril_v11.md#rilradiotech) | 
| boolean [isNrAvailable](#isnravailable) | 表示NR模式是否可用  | 
| boolean [isEnDcAvailable](#isendcavailable) | 表示ENDC是否可用  | 
| boolean [isDcNrRestricted](#isdcnrrestricted) | 表示DCNR是否受限  | 


## 类成员变量说明


### cellId

```
int PsRegStatusInfo::cellId
```
**描述**

小区标识


### isDcNrRestricted

```
boolean PsRegStatusInfo::isDcNrRestricted
```
**描述**

表示DCNR是否受限


### isEnDcAvailable

```
boolean PsRegStatusInfo::isEnDcAvailable
```
**描述**

表示ENDC是否可用


### isNrAvailable

```
boolean PsRegStatusInfo::isNrAvailable
```
**描述**

表示NR模式是否可用


### lacCode

```
int PsRegStatusInfo::lacCode
```
**描述**

地区区域码


### notifyType

```
int PsRegStatusInfo::notifyType
```
**描述**

通知类型

- 0：禁止主动上报

- 1：使用格式1上报，具体由芯片自定义

- 2：使用格式2上报，具体由芯片自定义 


### radioTechnology

```
enum RilRadioTech PsRegStatusInfo::radioTechnology
```
**描述**

语音接入技术类型，具体查看[RilRadioTech](_ril_v11.md#rilradiotech)


### regStatus

```
enum RilRegStatus PsRegStatusInfo::regStatus
```
**描述**

注册状态，具体查看[RilRegStatus](_ril_v11.md#rilregstatus)
