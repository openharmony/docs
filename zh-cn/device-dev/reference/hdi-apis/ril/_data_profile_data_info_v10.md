# DataProfileDataInfo


## 概述

PDP上下文信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [profileId](#profileid) | 数据业务类型号，0表示默认数据业务，1表示彩信数据业务  | 
| int [authenticationType](#authenticationtype) | 鉴权类型 | 
| String [apn](#apn) | 接入点名称  | 
| String [protocol](#protocol) | 网际协议版本  | 
| String [roamingProtocol](#roamingprotocol) | 漫游网际协议版本  | 
| String [userName](#username) | 用户名  | 
| String [password](#password) | 密码  | 


## 类成员变量说明


### apn

```
String DataProfileDataInfo::apn
```
**描述**

接入点名称


### authenticationType

```
int DataProfileDataInfo::authenticationType
```
**描述**

鉴权类型

- 0：无

- 1：密码认证协议（PAP）

- 2：质询握手认证协议（CHAP） 


### password

```
String DataProfileDataInfo::password
```
**描述**

密码


### profileId

```
int DataProfileDataInfo::profileId
```
**描述**

数据业务类型号，0表示默认数据业务，1表示彩信数据业务


### protocol

```
String DataProfileDataInfo::protocol
```
**描述**

网际协议版本


### roamingProtocol

```
String DataProfileDataInfo::roamingProtocol
```
**描述**

漫游网际协议版本


### serial

```
int DataProfileDataInfo::serial
```
**描述**

请求的序列号


### userName

```
String DataProfileDataInfo::userName
```
**描述**

用户名
