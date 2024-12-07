# SendSmsResultInfo


## 概述

发送短信响应信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [msgRef](#msgref) | 信息参考号  | 
| String [pdu](#pdu) | 协议数据单元  | 
| int [errCode](#errcode) | 错误码  | 
| int [flag](#flag) | 短信响应标识  | 


## 类成员变量说明


### errCode

```
int SendSmsResultInfo::errCode
```
**描述**

错误码


### flag

```
int SendSmsResultInfo::flag
```
**描述**

短信响应标识


### msgRef

```
int SendSmsResultInfo::msgRef
```
**描述**

信息参考号


### pdu

```
String SendSmsResultInfo::pdu
```
**描述**

协议数据单元
