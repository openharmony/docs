# EmergencyCall


## 概述

紧急呼叫号码。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [index](#index) | int<br/>号码条数索引&nbsp; | 
| [total](#total) | int<br/>号码总条数&nbsp; | 
| [eccNum](#eccnum) | String<br/>号码&nbsp; | 
| [mcc](#mcc) | String<br/>国家码&nbsp; | 
| [eccType](#ecctype) | enum&nbsp;[EccType](_ril.md#ecctype)<br/>紧急呼叫类型，具体查看[EccType](_ril.md#ecctype) | 
| [simpresent](#simpresent) | enum&nbsp;[SimpresentType](_ril.md#simpresenttype)<br/>表示号码是有卡时生效还是无卡生效，具体查看[SimpresentType](_ril.md#simpresenttype) | 
| [abnormalService](#abnormalservice) | enum&nbsp;[AbnormalServiceType](_ril.md#abnormalservicetype)<br/>表示号码有效性是否区分CS域非正常服务状态，具体查看**AbnormalService** | 


## 类成员变量说明


### abnormalService

  
```
enum AbnormalServiceType EmergencyCall::abnormalService
```
**描述:**
表示号码有效性是否区分CS域非正常服务状态，具体查看**AbnormalService**


### eccNum

  
```
String EmergencyCall::eccNum
```
**描述:**
号码


### eccType

  
```
enum EccType EmergencyCall::eccType
```
**描述:**
紧急呼叫类型，具体查看[EccType](_ril.md#ecctype)


### index

  
```
int EmergencyCall::index
```
**描述:**
号码条数索引


### mcc

  
```
String EmergencyCall::mcc
```
**描述:**
国家码


### simpresent

  
```
enum SimpresentType EmergencyCall::simpresent
```
**描述:**
表示号码是有卡时生效还是无卡生效，具体查看[SimpresentType](_ril.md#simpresenttype)


### total

  
```
int EmergencyCall::total
```
**描述:**
号码总条数
