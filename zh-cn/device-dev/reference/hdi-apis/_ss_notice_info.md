# SsNoticeInfo


## 概述

补充业务信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [serviceType](#servicetype) | int<br/>业务类型 | 
| [requestType](#requesttype) | int<br/>请求类型 | 
| [serviceClass](#serviceclass) | int<br/>服务类别，参考3GPP&nbsp;TS&nbsp;27.007&nbsp; | 
| [result](#result) | int<br/>查询结果，具体查看[RilErrType](_ril.md#rilerrtype) | 


## 类成员变量说明


### requestType

  
```
int SsNoticeInfo::requestType
```
**描述:**
请求类型

- 0：去激活

- 1：激活

- 2：状态查询

- 3：注册

- 4：删除 


### result

  
```
int SsNoticeInfo::result
```
**描述:**
查询结果，具体查看[RilErrType](_ril.md#rilerrtype)


### serviceClass

  
```
int SsNoticeInfo::serviceClass
```
**描述:**
服务类别，参考3GPP TS 27.007


### serviceType

  
```
int SsNoticeInfo::serviceType
```
**描述:**
业务类型

- 0：无条件

- 1：遇忙时

- 2：无应答时

- 3：不可达时（无网络服务或者关机时） 
