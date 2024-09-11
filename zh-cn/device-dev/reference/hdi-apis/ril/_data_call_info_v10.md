# DataCallInfo


## 概述

数据业务信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [radioTechnology](#radiotechnology) | 无线接入技术，具体查看[RilRadioTech](_ril_v10.md#rilradiotech) | 
| boolean [modemCognitive](#modemcognitive) | 是否modem设置PDP上下文  | 
| boolean [roamingAllowed](#roamingallowed) | 是否允许漫游，true表示允许，false表示禁止  | 
| boolean [isRoaming](#isroaming) | 是否漫游，true表示漫游，false表示非漫游  | 
| struct [DataProfileDataInfo](_data_profile_data_info_v10.md)[dataProfileInfo](#dataprofileinfo) | PDP上下文信息  | 


## 类成员变量说明


### dataProfileInfo

```
struct DataProfileDataInfo DataCallInfo::dataProfileInfo
```
**描述**

PDP上下文信息


### isRoaming

```
boolean DataCallInfo::isRoaming
```
**描述**

是否漫游，true表示漫游，false表示非漫游


### modemCognitive

```
boolean DataCallInfo::modemCognitive
```
**描述**

是否modem设置PDP上下文


### radioTechnology

```
int DataCallInfo::radioTechnology
```
**描述**

无线接入技术，具体查看[RilRadioTech](_ril_v10.md#rilradiotech)


### roamingAllowed

```
boolean DataCallInfo::roamingAllowed
```
**描述**

是否允许漫游，true表示允许，false表示禁止


### serial

```
int DataCallInfo::serial
```
**描述**

请求的序列号
