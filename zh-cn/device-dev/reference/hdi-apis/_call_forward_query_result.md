# CallForwardQueryResult


## 概述

呼叫转移查询结果信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [serial](#serial) | int<br/>请求的序列号&nbsp; | 
| [result](#result) | int<br/>查询结果，具体查看[RilErrType](_ril.md#rilerrtype) | 
| [status](#status) | int<br/>状态 | 
| [classx](#classx) | int<br/>业务类别，参考3GPP&nbsp;TS&nbsp;27.007&nbsp; | 
| [type](#type) | int<br/>号码地址类型 | 
| [reason](#reason) | int<br/>呼叫转移类型 | 
| [time](#time) | int<br/>等待时长&nbsp; | 
| [number](#number) | String<br/>电话号码&nbsp; | 


## 类成员变量说明


### classx

  
```
int CallForwardQueryResult::classx
```
**描述:**
业务类别，参考3GPP TS 27.007


### number

  
```
String CallForwardQueryResult::number
```
**描述:**
电话号码


### reason

  
```
int CallForwardQueryResult::reason
```
**描述:**
呼叫转移类型

- 0：无条件转移

- 1：遇忙转移

- 2：无应答转移

- 3：不可达转移（无网络服务或者关机时）

- 4：所有呼叫转移

- 5：所有条件转移 


### result

  
```
int CallForwardQueryResult::result
```
**描述:**
查询结果，具体查看[RilErrType](_ril.md#rilerrtype)


### serial

  
```
int CallForwardQueryResult::serial
```
**描述:**
请求的序列号


### status

  
```
int CallForwardQueryResult::status
```
**描述:**
状态

- 0：未激活

- 1：激活 


### time

  
```
int CallForwardQueryResult::time
```
**描述:**
等待时长


### type

  
```
int CallForwardQueryResult::type
```
**描述:**
号码地址类型

- 129：普通号码

- 145：国际号码 
