# GsmSmsMessageInfo


## 概述

发送GSM短信信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [state](#state) | 状态  | 
| String [smscPdu](#smscpdu) | 短信业务中心  | 
| String [pdu](#pdu) | 协议数据单元  | 


## 类成员变量说明


### pdu

```
String GsmSmsMessageInfo::pdu
```
**描述**

协议数据单元


### serial

```
int GsmSmsMessageInfo::serial
```
**描述**

请求的序列号


### smscPdu

```
String GsmSmsMessageInfo::smscPdu
```
**描述**

短信业务中心


### state

```
int GsmSmsMessageInfo::state
```
**描述**

状态
