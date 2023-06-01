# SmsMessageIOInfo


## 概述

SIM卡短信信息

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [serial](#serial) | int<br/>请求的序列号&nbsp; | 
| [smscPdu](#smscpdu) | String<br/>短信业务中心&nbsp; | 
| [pdu](#pdu) | String<br/>协议数据单元&nbsp; | 
| [state](#state) | int<br/>状态&nbsp; | 
| [index](#index) | int<br/>消息索引&nbsp; | 


## 类成员变量说明


### index

  
```
int SmsMessageIOInfo::index
```
**描述:**
消息索引


### pdu

  
```
String SmsMessageIOInfo::pdu
```
**描述:**
协议数据单元


### serial

  
```
int SmsMessageIOInfo::serial
```
**描述:**
请求的序列号


### smscPdu

  
```
String SmsMessageIOInfo::smscPdu
```
**描述:**
短信业务中心


### state

  
```
int SmsMessageIOInfo::state
```
**描述:**
状态
