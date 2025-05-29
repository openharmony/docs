# EmergencyCall


## 概述

紧急呼叫号码。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [index](#index) | 号码条数索引 | 
| int [total](#total) | 号码总条数 | 
| String [eccNum](#eccnum) | 号码 | 
| String [mcc](#mcc) | 国家码 | 
| enum [EccType](_ril_v10.md#ecctype)[eccType](#ecctype) | 紧急呼叫类型，具体查看[EccType](_ril_v10.md#ecctype) | 
| enum [SimpresentType](_ril_v10.md#simpresenttype)[simpresent](#simpresent) | 表示号码是有卡时生效还是无卡生效，具体查看[SimpresentType](_ril_v10.md#simpresenttype) | 
| enum [AbnormalServiceType](_ril_v10.md#abnormalservicetype)[abnormalService](#abnormalservice) | 表示号码有效性是否区分CS域非正常服务状态，具体查看[AbnormalServiceType](_ril_v10.md#abnormalservicetype) | 


## 类成员变量说明


### abnormalService

```
enum AbnormalServiceType EmergencyCall::abnormalService
```

**描述**


表示号码有效性是否区分CS域非正常服务状态，具体查看[AbnormalServiceType](_ril_v10.md#abnormalservicetype)


### eccNum

```
String EmergencyCall::eccNum
```

**描述**


号码


### eccType

```
enum EccType EmergencyCall::eccType
```

**描述**


紧急呼叫类型，具体查看[EccType](_ril_v10.md#ecctype)


### index

```
int EmergencyCall::index
```

**描述**


号码条数索引


### mcc

```
String EmergencyCall::mcc
```

**描述**


国家码


### simpresent

```
enum SimpresentType EmergencyCall::simpresent
```

**描述**


表示号码是有卡时生效还是无卡生效，具体查看[SimpresentType](_ril_v10.md#simpresenttype)


### total

```
int EmergencyCall::total
```

**描述**


号码总条数
