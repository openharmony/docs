# DataProfilesInfo


## 概述

PDP上下文信息列表。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [serial](#serial) | int<br/>请求的序列号&nbsp; | 
| [profilesSize](#profilessize) | int<br/>PDP上下文数量&nbsp; | 
| [isRoaming](#isroaming) | boolean<br/>是否漫游&nbsp; | 
| [profiles](#profiles) | List&lt;&nbsp;struct&nbsp;[DataProfileDataInfo](_data_profile_data_info.md)&nbsp;&gt;<br/>PDP上下文信息列表&nbsp; | 


## 类成员变量说明


### isRoaming

  
```
boolean DataProfilesInfo::isRoaming
```
**描述:**
是否漫游


### profiles

  
```
List<struct DataProfileDataInfo> DataProfilesInfo::profiles
```
**描述:**
PDP上下文信息列表


### profilesSize

  
```
int DataProfilesInfo::profilesSize
```
**描述:**
PDP上下文数量


### serial

  
```
int DataProfilesInfo::serial
```
**描述:**
请求的序列号
