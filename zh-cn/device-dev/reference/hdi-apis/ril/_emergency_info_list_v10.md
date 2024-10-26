# EmergencyInfoList


## 概述

紧急呼叫号码列表。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [callSize](#callsize) | 总数  | 
| int [flag](#flag) | 号码列表标识  | 
| List&lt; struct [EmergencyCall](_emergency_call_v10.md) &gt; [calls](#calls) | 号码列表  | 


## 类成员变量说明


### calls

```
List<struct EmergencyCall> EmergencyInfoList::calls
```
**描述**

号码列表


### callSize

```
int EmergencyInfoList::callSize
```
**描述**

总数


### flag

```
int EmergencyInfoList::flag
```
**描述**

号码列表标识
