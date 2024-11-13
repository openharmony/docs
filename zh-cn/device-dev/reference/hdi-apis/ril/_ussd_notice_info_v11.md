# UssdNoticeInfo


## 概述

非结构化补充数据业务(USSD)业务信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [type](#type) | USSD类型 | 
| String [message](#message) | USSD字符串  | 


## 类成员变量说明


### message

```
String UssdNoticeInfo::message
```
**描述**

USSD字符串


### type

```
int UssdNoticeInfo::type
```
**描述**

USSD类型

- 0：网络不需要客户端回复

- 1：网络需要客户端回复

- 2：USSD会话被网络释放

- 3：其他本地客户端已经作出响应

- 4：操作不支持

- 5：网络超时 
