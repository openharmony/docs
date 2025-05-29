# CallInfoList


## 概述

通话状态信息列表。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [callSize](#callsize) | 总数  | 
| int [flag](#flag) | 通话状态信息列表标识  | 
| List&lt; struct [CallInfo](_call_info_v10.md) &gt; [calls](#calls) | 通话状态信息列表  | 


## 类成员变量说明


### calls

```
List<struct CallInfo> CallInfoList::calls
```
**描述**

通话状态信息列表


### callSize

```
int CallInfoList::callSize
```
**描述**

总数


### flag

```
int CallInfoList::flag
```
**描述**

通话状态信息列表标识
