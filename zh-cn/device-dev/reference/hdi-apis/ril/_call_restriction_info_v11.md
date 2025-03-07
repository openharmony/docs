# CallRestrictionInfo


## 概述

呼叫限制信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [mode](#mode) | 操作模式 | 
| String [fac](#fac) | 操作对象  | 
| String [password](#password) | 密码  | 


## 类成员变量说明


### fac

```
String CallRestrictionInfo::fac
```
**描述**

操作对象


### mode

```
int CallRestrictionInfo::mode
```
**描述**

操作模式

- 0：去激活

- 1：激活 


### password

```
String CallRestrictionInfo::password
```
**描述**

密码
