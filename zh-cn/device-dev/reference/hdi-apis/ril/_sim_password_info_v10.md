# SimPasswordInfo


## 概述

SIM卡密码信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [fac](#fac) | SIM锁类型。 | 
| String [oldPassword](#oldpassword) | 旧密码文本  | 
| String [newPassword](#newpassword) | 新密码文本  | 
| int [serial](#serial) | 请求的序列号  | 
| int [passwordLength](#passwordlength) | 旧密码或新密码的最大长度  | 


## 类成员变量说明


### fac

```
String SimPasswordInfo::fac
```
**描述**

SIM锁类型。

- AO：禁止所有呼出

- OI：禁止所有国际呼出。

- OX：禁止所有国际呼出,归属国除外

- AI：禁止所有呼入

- IR：归属地以外漫游时,禁止所有呼入。

- AB：禁止所有业务（仅在模式大于等于0时适用）

- AG：禁止呼出业务（仅在模式大于等于0时适用）

- AC：禁止呼入业务（仅在模式大于等于0时适用）

- FD：FDN，固定号码拨号

- PN：锁网络

- PU：锁子网

- PP：锁定SP 


### newPassword

```
String SimPasswordInfo::newPassword
```
**描述**

新密码文本


### oldPassword

```
String SimPasswordInfo::oldPassword
```
**描述**

旧密码文本


### passwordLength

```
int SimPasswordInfo::passwordLength
```
**描述**

旧密码或新密码的最大长度


### serial

```
int SimPasswordInfo::serial
```
**描述**

请求的序列号
