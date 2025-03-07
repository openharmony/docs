# HiAppEvent_AppEventInfo


## 概述

单个事件信息，包含事件领域，事件名称，事件类型和json格式字符串表示的事件中携带的自定义参数列表。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**相关模块：**[HiAppEvent](_hi_app_event.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [domain](#domain) | 事件领域。  | 
| const char \* [name](#name) | 事件名称。  | 
| enum [EventType](_hi_app_event.md#eventtype) [type](#type) | 事件类型。  | 
| const char \* [params](#params) | Json格式字符串类型的事件参数列表。  | 


## 结构体成员变量说明


### domain

```
const char* HiAppEvent_AppEventInfo::domain
```
**描述**
事件领域。


### name

```
const char* HiAppEvent_AppEventInfo::name
```
**描述**
事件名称。


### params

```
const char* HiAppEvent_AppEventInfo::params
```
**描述**
Json格式字符串类型的事件参数列表。


### type

```
enum EventType HiAppEvent_AppEventInfo::type
```
**描述**
事件类型。
