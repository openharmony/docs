# SimAuthenticationRequestInfo


## 概述

SIM卡鉴权请求信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| String [aid](#aid) | 应用标识  | 
| String [authData](#authdata) | 认证数据信息  | 


## 类成员变量说明


### aid

```
String SimAuthenticationRequestInfo::aid
```
**描述**

应用标识


### authData

```
String SimAuthenticationRequestInfo::authData
```
**描述**

认证数据信息


### serial

```
int SimAuthenticationRequestInfo::serial
```
**描述**

请求的序列号
