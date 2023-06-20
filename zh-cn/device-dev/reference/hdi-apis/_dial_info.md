# DialInfo


## 概述

拨号信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [serial](#serial) | int<br/>请求的序列号&nbsp; | 
| [clir](#clir) | int<br/>CLIR模式 | 
| [address](#address) | String<br/>电话号码&nbsp; | 


## 类成员变量说明


### address

  
```
String DialInfo::address
```
**描述:**
电话号码


### clir

  
```
int DialInfo::clir
```
**描述:**
CLIR模式

- 0：默认

- 1：开启

- 2：关闭 


### serial

  
```
int DialInfo::serial
```
**描述:**
请求的序列号
