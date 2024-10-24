# CallForwardQueryInfoList


## 概述

呼叫转移信息列表。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [callSize](#callsize) | 总数  | 
| int [flag](#flag) | 呼叫转移查询结果信息标识  | 
| List&lt; struct [CallForwardQueryResult](_call_forward_query_result_v10.md) &gt; [calls](#calls) | 呼叫转移查询结果信息  | 


## 类成员变量说明


### calls

```
List<struct CallForwardQueryResult> CallForwardQueryInfoList::calls
```
**描述**

呼叫转移查询结果信息


### callSize

```
int CallForwardQueryInfoList::callSize
```
**描述**

总数


### flag

```
int CallForwardQueryInfoList::flag
```
**描述**

呼叫转移查询结果信息标识
