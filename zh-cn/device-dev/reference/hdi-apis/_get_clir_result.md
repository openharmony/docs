# GetClirResult


## 概述

主叫号码显示限制结果信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [result](#result) | int<br/>查询结果，具体查看[RilErrType](_ril.md#rilerrtype) | 
| [action](#action) | int<br/>禁止或使能CLIR功能&nbsp; | 
| [clirStat](#clirstat) | int<br/>CLIR业务在网络的签约状态。 | 


## 类成员变量说明


### action

  
```
int GetClirResult::action
```
**描述:**
禁止或使能CLIR功能


### clirStat

  
```
int GetClirResult::clirStat
```
**描述:**
CLIR业务在网络的签约状态。

- 0：CLIR业务未提供

- 1：CLIR业务以永久模式提供

- 2：未知（网络原因）

- 3：CLIR业务临时限制

- 4：CLIR业务临时允许 


### result

  
```
int GetClirResult::result
```
**描述:**
查询结果，具体查看[RilErrType](_ril.md#rilerrtype)
