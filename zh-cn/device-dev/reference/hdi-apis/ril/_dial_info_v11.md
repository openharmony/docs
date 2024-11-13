# DialInfo


## 概述

拨号信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [clir](#clir) | CLIR模式 | 
| String [address](#address) | 电话号码  | 


## 类成员变量说明


### address

```
String DialInfo::address
```
**描述**

电话号码


### clir

```
int DialInfo::clir
```
**描述**

CLIR模式

- 0：默认

- 1：开启

- 2：关闭 


### serial

```
int DialInfo::serial
```
**描述**

请求的序列号
