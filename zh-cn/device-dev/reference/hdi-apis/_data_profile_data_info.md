# DataProfileDataInfo


## 概述

PDP上下文信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [serial](#serial) | int<br/>请求的序列号&nbsp; | 
| [profileId](#profileid) | int<br/>数据业务类型号，0表示默认数据业务，1表示彩信数据业务&nbsp; | 
| [authenticationType](#authenticationtype) | int<br/>鉴权类型 | 
| [apn](#apn) | String<br/>接入点名称&nbsp; | 
| [protocol](#protocol) | String<br/>网际协议版本&nbsp; | 
| [roamingProtocol](#roamingprotocol) | String<br/>漫游网际协议版本&nbsp; | 
| [userName](#username) | String<br/>用户名&nbsp; | 
| [password](#password) | String<br/>密码&nbsp; | 


## 类成员变量说明


### apn

  
```
String DataProfileDataInfo::apn
```
**描述:**
接入点名称


### authenticationType

  
```
int DataProfileDataInfo::authenticationType
```
**描述:**
鉴权类型

- 0：无

- 1：密码认证协议（PAP）

- 2：质询握手认证协议（CHAP） 


### password

  
```
String DataProfileDataInfo::password
```
**描述:**
密码


### profileId

  
```
int DataProfileDataInfo::profileId
```
**描述:**
数据业务类型号，0表示默认数据业务，1表示彩信数据业务


### protocol

  
```
String DataProfileDataInfo::protocol
```
**描述:**
网际协议版本


### roamingProtocol

  
```
String DataProfileDataInfo::roamingProtocol
```
**描述:**
漫游网际协议版本


### serial

  
```
int DataProfileDataInfo::serial
```
**描述:**
请求的序列号


### userName

  
```
String DataProfileDataInfo::userName
```
**描述:**
用户名
