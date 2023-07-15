# GetClipResult


## 概述

主叫号码显示结果信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [result](#result) | int<br/>查询结果，具体查看[RilErrType](_ril.md#rilerrtype) | 
| [action](#action) | int<br/>禁止或使能CLIP（Calling&nbsp;line&nbsp;Identification&nbsp;Presentation&nbsp;Supplementary&nbsp;Service）功能&nbsp; | 
| [clipStat](#clipstat) | int<br/>CLIP业务在网络的签约状态 | 


## 类成员变量说明


### action

  
```
int GetClipResult::action
```
**描述:**
禁止或使能CLIP（Calling line Identification Presentation Supplementary Service）功能


### clipStat

  
```
int GetClipResult::clipStat
```
**描述:**
CLIP业务在网络的签约状态

- 0：CLIP业务未提供

- 1：CLIP业务已提供

- 2：未知（网络原因） 


### result

  
```
int GetClipResult::result
```
**描述:**
查询结果，具体查看[RilErrType](_ril.md#rilerrtype)
