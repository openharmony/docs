# ModeData


## 概述

接收短信处理模式。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| boolean [result](#result) | 是否接收短信  | 
| int [mode](#mode) | 接收短信处理模式，详见**AckIncomeCause** | 
| String [pdu](#pdu) | 协议数据单元  | 


## 类成员变量说明


### mode

```
int ModeData::mode
```
**描述**

接收短信处理模式，详见**AckIncomeCause**


### pdu

```
String ModeData::pdu
```
**描述**

协议数据单元


### result

```
boolean ModeData::result
```
**描述**

是否接收短信


### serial

```
int ModeData::serial
```
**描述**

请求的序列号
