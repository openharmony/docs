# CsRegStatusInfo


## 概述

CS注册状态信息。

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
| [flag](#flag) | int<br/>标志，由搜网管理在响应中使用&nbsp; | 


## 类成员变量说明


### cellId

  
```
int CsRegStatusInfo::cellId
```
**描述:**
小区标识


### flag

  
```
int CsRegStatusInfo::flag
```
**描述:**
标志，由搜网管理在响应中使用


### lacCode

  
```
int CsRegStatusInfo::lacCode
```
**描述:**
地区区域码


### notifyType

  
```
int CsRegStatusInfo::notifyType
```
**描述:**
通知类型

- 0：禁止主动上报

- 1：使用格式1上报，格式具体由芯片自定义

- 2：使用格式2上报，格式具体由芯片自定义 


### radioTechnology

  
```
enum RilRadioTech CsRegStatusInfo::radioTechnology
```
**描述:**
语音接入技术类型，具体查看[RilRadioTech](_ril.md#rilradiotech)


### regStatus

  
```
enum RilRegStatus CsRegStatusInfo::regStatus
```
**描述:**
注册状态，具体查看[RilRegStatus](_ril.md#rilregstatus)
