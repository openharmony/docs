# CallRestrictionResult


## 概述

呼叫限制结果信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [result](#result) | int<br/>查询结果，具体查看[RilErrType](_ril.md#rilerrtype) | 
| [status](#status) | int<br/>业务状态 | 
| [classCw](#classcw) | int<br/>业务类别，参考3GPP&nbsp;TS&nbsp;27.007&nbsp; | 


## 类成员变量说明


### classCw

  
```
int CallRestrictionResult::classCw
```
**描述:**
业务类别，参考3GPP TS 27.007


### result

  
```
int CallRestrictionResult::result
```
**描述:**
查询结果，具体查看[RilErrType](_ril.md#rilerrtype)


### status

  
```
int CallRestrictionResult::status
```
**描述:**
业务状态

- 0：未激活

- 1：激活 
