# CsRegStatusInfo


## 概述

CS注册状态信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [notifyType](#notifytype) | 通知类型 | 
| enum [RilRegStatus](_ril_v10.md#rilregstatus)[regStatus](#regstatus) | 注册状态，具体查看[RilRegStatus](_ril_v10.md#rilregstatus) | 
| int [lacCode](#laccode) | 地区区域码  | 
| int [cellId](#cellid) | 小区标识  | 
| enum [RilRadioTech](_ril_v10.md#rilradiotech)[radioTechnology](#radiotechnology) | 语音接入技术类型，具体查看[RilRadioTech](_ril_v10.md#rilradiotech) | 
| int [flag](#flag) | 标志，由搜网管理在响应中使用  | 


## 类成员变量说明


### cellId

```
int CsRegStatusInfo::cellId
```
**描述**

小区标识


### flag

```
int CsRegStatusInfo::flag
```
**描述**

标志，由搜网管理在响应中使用


### lacCode

```
int CsRegStatusInfo::lacCode
```
**描述**

地区区域码


### notifyType

```
int CsRegStatusInfo::notifyType
```
**描述**

通知类型

- 0：禁止主动上报

- 1：使用格式1上报，格式具体由芯片自定义

- 2：使用格式2上报，格式具体由芯片自定义 


### radioTechnology

```
enum RilRadioTech CsRegStatusInfo::radioTechnology
```
**描述**

语音接入技术类型，具体查看[RilRadioTech](_ril_v10.md#rilradiotech)


### regStatus

```
enum RilRegStatus CsRegStatusInfo::regStatus
```
**描述**

注册状态，具体查看[RilRegStatus](_ril_v10.md#rilregstatus)
