# GetClipResult


## 概述

主叫号码显示结果信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [result](#result) | 查询结果，具体查看[RilErrType](_ril_v11.md#rilerrtype) | 
| int [action](#action) | 禁止或使能CLIP（Calling line Identification Presentation Supplementary Service）功能  | 
| int [clipStat](#clipstat) | CLIP业务在网络的签约状态 | 


## 类成员变量说明


### action

```
int GetClipResult::action
```
**描述**

禁止或使能CLIP（Calling line Identification Presentation Supplementary Service）功能


### clipStat

```
int GetClipResult::clipStat
```
**描述**

CLIP业务在网络的签约状态

- 0：CLIP业务未提供

- 1：CLIP业务已提供

- 2：未知（网络原因） 


### result

```
int GetClipResult::result
```
**描述**

查询结果，具体查看[RilErrType](_ril_v11.md#rilerrtype)
