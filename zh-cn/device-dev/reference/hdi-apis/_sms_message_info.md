# SmsMessageInfo


## 概述

上报短信信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [indicationType](#indicationtype) | int<br/>响应类型 | 
| [size](#size) | int<br/>总数&nbsp; | 
| [pdu](#pdu) | List&lt;&nbsp;unsigned&nbsp;char&nbsp;&gt;<br/>协议数据单元&nbsp; | 


## 类成员变量说明


### indicationType

  
```
int SmsMessageInfo::indicationType
```
**描述:**
响应类型

- 0：查询上报

- 1：主动上报 


### pdu

  
```
List<unsigned char> SmsMessageInfo::pdu
```
**描述:**
协议数据单元


### size

  
```
int SmsMessageInfo::size
```
**描述:**
总数
