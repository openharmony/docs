# VoiceRadioTechnology


## 概述

电路域接入技术。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [RilSrvStatus](_ril_v10.md#rilsrvstatus)[srvStatus](#srvstatus) | 系统服务状态  | 
| enum [RilSrvDomain](_ril_v10.md#rilsrvdomain)[srvDomain](#srvdomain) | 系统服务域  | 
| enum [RilRoamStatus](_ril_v10.md#rilroamstatus)[roamStatus](#roamstatus) | 漫游状态  | 
| enum [RilSimStatus](_ril_v10.md#rilsimstatus)[simStatus](#simstatus) | SIM卡状态  | 
| enum [RilSimLockStatus](_ril_v10.md#rilsimlockstatus)[lockStatus](#lockstatus) | SIM卡的LOCK状态  | 
| enum [RilSysMode](_ril_v10.md#rilsysmode)[sysMode](#sysmode) | 系统制式  | 
| String [sysModeName](#sysmodename) | 系统制式对应字符串  | 
| enum [RilRadioTech](_ril_v10.md#rilradiotech)[actType](#acttype) | 语音接入技术类型，具体查看[RilRadioTech](_ril_v10.md#rilradiotech) | 
| String [actName](#actname) | 语音接入技术类型对应字符串  | 
| int [flag](#flag) | 接入技术标识  | 


## 类成员变量说明


### actName

```
String VoiceRadioTechnology::actName
```
**描述**

语音接入技术类型对应字符串


### actType

```
enum RilRadioTech VoiceRadioTechnology::actType
```
**描述**

语音接入技术类型，具体查看[RilRadioTech](_ril_v10.md#rilradiotech)


### flag

```
int VoiceRadioTechnology::flag
```
**描述**

接入技术标识


### lockStatus

```
enum RilSimLockStatus VoiceRadioTechnology::lockStatus
```
**描述**

SIM卡的LOCK状态


### roamStatus

```
enum RilRoamStatus VoiceRadioTechnology::roamStatus
```
**描述**

漫游状态


### simStatus

```
enum RilSimStatus VoiceRadioTechnology::simStatus
```
**描述**

SIM卡状态


### srvDomain

```
enum RilSrvDomain VoiceRadioTechnology::srvDomain
```
**描述**

系统服务域


### srvStatus

```
enum RilSrvStatus VoiceRadioTechnology::srvStatus
```
**描述**

系统服务状态


### sysMode

```
enum RilSysMode VoiceRadioTechnology::sysMode
```
**描述**

系统制式


### sysModeName

```
String VoiceRadioTechnology::sysModeName
```
**描述**

系统制式对应字符串
