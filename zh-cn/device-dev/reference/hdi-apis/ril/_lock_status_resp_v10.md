# LockStatusResp


## 概述

SIM卡解锁响应

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [result](#result) | 查询结果，具体查看[RilErrType](_ril_v10.md#rilerrtype) | 
| int [remain](#remain) | 剩余次数  | 


## 类成员变量说明


### remain

```
int LockStatusResp::remain
```
**描述**

剩余次数


### result

```
int LockStatusResp::result
```
**描述**

查询结果，具体查看[RilErrType](_ril_v10.md#rilerrtype)
