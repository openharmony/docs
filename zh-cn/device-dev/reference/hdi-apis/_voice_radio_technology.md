# VoiceRadioTechnology


## 概述

电路域接入技术。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [srvStatus](#srvstatus) | enum&nbsp;[RilSrvStatus](_ril.md#rilsrvstatus)<br/>系统服务状态&nbsp; | 
| [srvDomain](#srvdomain) | enum&nbsp;[RilSrvDomain](_ril.md#rilsrvdomain)<br/>系统服务域&nbsp; | 
| [roamStatus](#roamstatus) | enum&nbsp;[RilRoamStatus](_ril.md#rilroamstatus)<br/>漫游状态&nbsp; | 
| [simStatus](#simstatus) | enum&nbsp;[RilSimStatus](_ril.md#rilsimstatus)<br/>SIM卡状态&nbsp; | 
| [lockStatus](#lockstatus) | enum&nbsp;[RilSimLockStatus](_ril.md#rilsimlockstatus)<br/>SIM卡的LOCK状态&nbsp; | 
| [sysMode](#sysmode) | enum&nbsp;[RilSysMode](_ril.md#rilsysmode)<br/>系统制式&nbsp; | 
| [sysModeName](#sysmodename) | String<br/>系统制式对应字符串&nbsp; | 
| [actType](#acttype) | enum&nbsp;[RilRadioTech](_ril.md#rilradiotech)<br/>语音接入技术类型，具体查看[RilRadioTech](_ril.md#rilradiotech) | 
| [actName](#actname) | String<br/>语音接入技术类型对应字符串&nbsp; | 
| [flag](#flag) | int<br/>接入技术标识&nbsp; | 


## 类成员变量说明


### actName

  
```
String VoiceRadioTechnology::actName
```
**描述:**
语音接入技术类型对应字符串


### actType

  
```
enum RilRadioTech VoiceRadioTechnology::actType
```
**描述:**
语音接入技术类型，具体查看[RilRadioTech](_ril.md#rilradiotech)


### flag

  
```
int VoiceRadioTechnology::flag
```
**描述:**
接入技术标识


### lockStatus

  
```
enum RilSimLockStatus VoiceRadioTechnology::lockStatus
```
**描述:**
SIM卡的LOCK状态


### roamStatus

  
```
enum RilRoamStatus VoiceRadioTechnology::roamStatus
```
**描述:**
漫游状态


### simStatus

  
```
enum RilSimStatus VoiceRadioTechnology::simStatus
```
**描述:**
SIM卡状态


### srvDomain

  
```
enum RilSrvDomain VoiceRadioTechnology::srvDomain
```
**描述:**
系统服务域


### srvStatus

  
```
enum RilSrvStatus VoiceRadioTechnology::srvStatus
```
**描述:**
系统服务状态


### sysMode

  
```
enum RilSysMode VoiceRadioTechnology::sysMode
```
**描述:**
系统制式


### sysModeName

  
```
String VoiceRadioTechnology::sysModeName
```
**描述:**
系统制式对应字符串
