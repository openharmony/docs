# SmsMessageIOInfo


## 概述

SIM卡短信信息

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| String [smscPdu](#smscpdu) | 短信业务中心  | 
| String [pdu](#pdu) | 协议数据单元  | 
| int [state](#state) | 状态  | 
| int [index](#index) | 消息索引  | 


## 类成员变量说明


### index

```
int SmsMessageIOInfo::index
```
**描述**

消息索引


### pdu

```
String SmsMessageIOInfo::pdu
```
**描述**

协议数据单元


### serial

```
int SmsMessageIOInfo::serial
```
**描述**

请求的序列号


### smscPdu

```
String SmsMessageIOInfo::smscPdu
```
**描述**

短信业务中心


### state

```
int SmsMessageIOInfo::state
```
**描述**

状态
