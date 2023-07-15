# SetupDataCallResultInfo


## 概述

数据业务激活结果信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [flag](#flag) | int<br/>激活结果信息标识&nbsp; | 
| [reason](#reason) | int<br/>数据业务激活失败原因码，参考3GPP&nbsp;TS&nbsp;24.008&nbsp; | 
| [retryTime](#retrytime) | int<br/>数据业务激活重试次数&nbsp; | 
| [cid](#cid) | int<br/>分组报文协议(PDP)上下文标识符&nbsp; | 
| [active](#active) | int<br/>是否激活成功，0表示激活失败，1表示激活成功&nbsp; | 
| [maxTransferUnit](#maxtransferunit) | int<br/>最大传输数据单元&nbsp; | 
| [pduSessionId](#pdusessionid) | int<br/>数据单元标识&nbsp; | 
| [type](#type) | String<br/>数据业务类型，“default”表示默认数据业务，“mms”表示彩信数据业务&nbsp; | 
| [netPortName](#netportname) | String<br/>网络设备名称&nbsp; | 
| [address](#address) | String<br/>网络地址&nbsp; | 
| [dns](#dns) | String<br/>域名服务地址&nbsp; | 
| [dnsSec](#dnssec) | String<br/>备用域名服务地址&nbsp; | 
| [gateway](#gateway) | String<br/>网关地址&nbsp; | 
| [pCscfPrimAddr](#pcscfprimaddr) | String<br/>首选代理呼叫控制功能模块(P-CSCF)地址&nbsp; | 
| [pCscfSecAddr](#pcscfsecaddr) | String<br/>备用P-CSCF地址&nbsp; | 


## 类成员变量说明


### active

  
```
int SetupDataCallResultInfo::active
```
**描述:**
是否激活成功，0表示激活失败，1表示激活成功


### address

  
```
String SetupDataCallResultInfo::address
```
**描述:**
网络地址


### cid

  
```
int SetupDataCallResultInfo::cid
```
**描述:**
分组报文协议(PDP)上下文标识符


### dns

  
```
String SetupDataCallResultInfo::dns
```
**描述:**
域名服务地址


### dnsSec

  
```
String SetupDataCallResultInfo::dnsSec
```
**描述:**
备用域名服务地址


### flag

  
```
int SetupDataCallResultInfo::flag
```
**描述:**
激活结果信息标识


### gateway

  
```
String SetupDataCallResultInfo::gateway
```
**描述:**
网关地址


### maxTransferUnit

  
```
int SetupDataCallResultInfo::maxTransferUnit
```
**描述:**
最大传输数据单元


### netPortName

  
```
String SetupDataCallResultInfo::netPortName
```
**描述:**
网络设备名称


### pCscfPrimAddr

  
```
String SetupDataCallResultInfo::pCscfPrimAddr
```
**描述:**
首选代理呼叫控制功能模块(P-CSCF)地址


### pCscfSecAddr

  
```
String SetupDataCallResultInfo::pCscfSecAddr
```
**描述:**
备用P-CSCF地址


### pduSessionId

  
```
int SetupDataCallResultInfo::pduSessionId
```
**描述:**
数据单元标识


### reason

  
```
int SetupDataCallResultInfo::reason
```
**描述:**
数据业务激活失败原因码，参考3GPP TS 24.008


### retryTime

  
```
int SetupDataCallResultInfo::retryTime
```
**描述:**
数据业务激活重试次数


### type

  
```
String SetupDataCallResultInfo::type
```
**描述:**
数据业务类型，“default”表示默认数据业务，“mms”表示彩信数据业务
