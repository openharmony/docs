# CallForwardSetInfo


## 概述

呼叫转移信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [reason](#reason) | int<br/>呼叫转移类型 | 
| [mode](#mode) | int<br/>呼叫转移的操作模式 | 
| [classx](#classx) | int<br/>业务类别，参考3GPP&nbsp;TS&nbsp;27.007&nbsp; | 
| [number](#number) | String<br/>电话号码&nbsp; | 


## 类成员变量说明


### classx

  
```
int CallForwardSetInfo::classx
```
**描述:**
业务类别，参考3GPP TS 27.007


### mode

  
```
int CallForwardSetInfo::mode
```
**描述:**
呼叫转移的操作模式

- 0：去激活

- 1：激活

- 2：状态查询

- 3：注册

- 4：删除 


### number

  
```
String CallForwardSetInfo::number
```
**描述:**
电话号码


### reason

  
```
int CallForwardSetInfo::reason
```
**描述:**
呼叫转移类型

- 0：无条件转移

- 1：遇忙转移

- 2：无应答转移

- 3：不可达转移（无网络服务或者关机时）

- 4：所有呼叫转移

- 5：所有条件转移 
