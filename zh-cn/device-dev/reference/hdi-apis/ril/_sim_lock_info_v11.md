# SimLockInfo


## 概述

SIM卡锁信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [classx](#classx) | 业务类别，取值为该类信息的整数之和，默认为255。 | 
| int [serial](#serial) | 请求的序列号。  | 
| String [fac](#fac) | SIM锁类型。 | 
| int [mode](#mode) | 模式。 | 
| int [status](#status) | SIM卡锁状态。 当fac参数为PN，PU，PP时，表示的是锁网锁卡前三层锁的激活状态。 | 
| String [passwd](#passwd) | 密码文本。  | 


## 类成员变量说明


### classx

```
int SimLockInfo::classx
```
**描述**

业务类别，取值为该类信息的整数之和，默认为255。

- 1：电话服务。

- 2：数据服务。

- 4：传真服务。

- 8：短消息服务。

- 16：数据电路同步。

- 32：数据电路异步。

- 64：专用分组访问。

- 128：专用便携式设备(PAD)访问 


### fac

```
String SimLockInfo::fac
```
**描述**

SIM锁类型。

- AO：禁止所有呼出。

- OI：禁止所有国际呼出。

- OX：禁止所有国际呼出，归属国除外。

- AI：禁止所有呼入。

- IR：归属地以外漫游时,禁止所有呼入。

- AB：禁止所有业务（仅在模式大于等于0时适用）。

- AG：禁止呼出业务（仅在模式大于等于0时适用）。

- AC：禁止呼入业务（仅在模式大于等于0时适用）。

- FD：FDN，固定号码拨号。

- PN：锁网络。

- PU：锁子网。

- PP：锁定SP 。


### mode

```
int SimLockInfo::mode
```
**描述**

模式。

- 0：去激活（当fac参数为PN，PU，PP时，为解锁操作）。

- 1：激活（当fac参数为PN，PU，PP时，不支持激活）。

- 2：查询。 


### passwd

```
String SimLockInfo::passwd
```
**描述**

密码文本。


### serial

```
int SimLockInfo::serial
```
**描述**

请求的序列号。


### status

```
int SimLockInfo::status
```
**描述**

SIM卡锁状态。 当fac参数为PN，PU，PP时，表示的是锁网锁卡前三层锁的激活状态。

- 0：未激活。

- 1：激活。 
