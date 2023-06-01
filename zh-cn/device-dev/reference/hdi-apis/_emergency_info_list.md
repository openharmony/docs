# EmergencyInfoList


## 概述

紧急呼叫号码列表。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [callSize](#callsize) | int<br/>总数&nbsp; | 
| [flag](#flag) | int<br/>号码列表标识&nbsp; | 
| [calls](#calls) | List&lt;&nbsp;struct&nbsp;[EmergencyCall](_emergency_call.md)&nbsp;&gt;<br/>号码列表&nbsp; | 


## 类成员变量说明


### calls

  
```
List<struct EmergencyCall> EmergencyInfoList::calls
```
**描述:**
号码列表


### callSize

  
```
int EmergencyInfoList::callSize
```
**描述:**
总数


### flag

  
```
int EmergencyInfoList::flag
```
**描述:**
号码列表标识
