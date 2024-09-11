# SsNoticeInfo


## 概述

补充业务信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serviceType](#servicetype) | 业务类型 | 
| int [requestType](#requesttype) | 请求类型 | 
| int [serviceClass](#serviceclass) | 服务类别，参考3GPP TS 27.007  | 
| int [result](#result) | 查询结果，具体查看[RilErrType](_ril_v10.md#rilerrtype) | 


## 类成员变量说明


### requestType

```
int SsNoticeInfo::requestType
```
**描述**

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
**描述**

查询结果，具体查看[RilErrType](_ril_v10.md#rilerrtype)


### serviceClass

```
int SsNoticeInfo::serviceClass
```
**描述**

服务类别，参考3GPP TS 27.007


### serviceType

```
int SsNoticeInfo::serviceType
```
**描述**

业务类型

- 0：无条件

- 1：遇忙时

- 2：无应答时

- 3：不可达时（无网络服务或者关机时） 
