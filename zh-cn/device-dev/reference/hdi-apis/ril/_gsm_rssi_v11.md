# GsmRssi


## 概述

GSM信号强度。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [rxlev](#rxlev) | 信号接收强度，取值范围0~31  | 
| int [ber](#ber) | 误码率，取值范围0~7  | 


## 类成员变量说明


### ber

```
int GsmRssi::ber
```
**描述**

误码率，取值范围0~7


### rxlev

```
int GsmRssi::rxlev
```
**描述**

信号接收强度，取值范围0~31
