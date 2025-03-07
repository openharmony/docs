# DataProfilesInfo


## 概述

PDP上下文信息列表。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [profilesSize](#profilessize) | PDP上下文数量  | 
| boolean [isRoaming](#isroaming) | 是否漫游  | 
| List&lt; struct [DataProfileDataInfo](_data_profile_data_info_v11.md) &gt; [profiles](#profiles) | PDP上下文信息列表  | 


## 类成员变量说明


### isRoaming

```
boolean DataProfilesInfo::isRoaming
```
**描述**

是否漫游


### profiles

```
List<struct DataProfileDataInfo> DataProfilesInfo::profiles
```
**描述**

PDP上下文信息列表


### profilesSize

```
int DataProfilesInfo::profilesSize
```
**描述**

PDP上下文数量


### serial

```
int DataProfilesInfo::serial
```
**描述**

请求的序列号
