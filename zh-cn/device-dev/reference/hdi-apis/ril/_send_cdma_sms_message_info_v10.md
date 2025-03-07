# SendCdmaSmsMessageInfo


## 概述

发送CDMA短信信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [state](#state) | 状态  | 
| String [smscPdu](#smscpdu) | 短信业务中心  | 


## 类成员变量说明


### serial

```
int SendCdmaSmsMessageInfo::serial
```
**描述**

请求的序列号


### smscPdu

```
String SendCdmaSmsMessageInfo::smscPdu
```
**描述**

短信业务中心


### state

```
int SendCdmaSmsMessageInfo::state
```
**描述**

状态
