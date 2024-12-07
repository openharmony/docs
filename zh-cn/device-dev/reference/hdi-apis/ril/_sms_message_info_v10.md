# SmsMessageInfo


## 概述

上报短信信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [indicationType](#indicationtype) | 响应类型 | 
| int [size](#size) | 总数  | 
| List&lt; unsigned char &gt; [pdu](#pdu) | 协议数据单元  | 


## 类成员变量说明


### indicationType

```
int SmsMessageInfo::indicationType
```
**描述**

响应类型

- 0：查询上报

- 1：主动上报 


### pdu

```
List<unsigned char> SmsMessageInfo::pdu
```
**描述**

协议数据单元


### size

```
int SmsMessageInfo::size
```
**描述**

总数
