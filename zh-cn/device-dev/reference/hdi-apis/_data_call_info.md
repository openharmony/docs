# DataCallInfo


## 概述

数据业务信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [serial](#serial) | int<br/>请求的序列号&nbsp; | 
| [radioTechnology](#radiotechnology) | int<br/>无线接入技术，具体查看[RilRadioTech](_ril.md#rilradiotech) | 
| [modemCognitive](#modemcognitive) | boolean<br/>是否modem设置PDP上下文&nbsp; | 
| [roamingAllowed](#roamingallowed) | boolean<br/>是否允许漫游，true表示允许，false表示禁止&nbsp; | 
| [isRoaming](#isroaming) | boolean<br/>是否漫游，true表示漫游，false表示非漫游&nbsp; | 
| [dataProfileInfo](#dataprofileinfo) | struct&nbsp;[DataProfileDataInfo](_data_profile_data_info.md)<br/>PDP上下文信息&nbsp; | 


## 类成员变量说明


### dataProfileInfo

  
```
struct DataProfileDataInfo DataCallInfo::dataProfileInfo
```
**描述:**
PDP上下文信息


### isRoaming

  
```
boolean DataCallInfo::isRoaming
```
**描述:**
是否漫游，true表示漫游，false表示非漫游


### modemCognitive

  
```
boolean DataCallInfo::modemCognitive
```
**描述:**
是否modem设置PDP上下文


### radioTechnology

  
```
int DataCallInfo::radioTechnology
```
**描述:**
无线接入技术，具体查看[RilRadioTech](_ril.md#rilradiotech)


### roamingAllowed

  
```
boolean DataCallInfo::roamingAllowed
```
**描述:**
是否允许漫游，true表示允许，false表示禁止


### serial

  
```
int DataCallInfo::serial
```
**描述:**
请求的序列号
