# HiAppEvent_AppEventGroup


## 概述

具有相同事件名称的事件组。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**相关模块：**[HiAppEvent](_hi_app_event.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [name](#name) | 事件数组中相同的事件名称。  | 
| const struct [HiAppEvent_AppEventInfo](_hi_app_event___app_event_info.md) \* [appEventInfos](#appeventinfos) | 具有相同事件名称的事件数组。  | 
| uint32_t [infoLen](#infolen) | 具有相同事件名称的事件数组的长度。  | 


## 结构体成员变量说明


### appEventInfos

```
const struct HiAppEvent_AppEventInfo* HiAppEvent_AppEventGroup::appEventInfos
```
**描述**
具有相同事件名称的事件数组。


### infoLen

```
uint32_t HiAppEvent_AppEventGroup::infoLen
```
**描述**
具有相同事件名称的事件数组的长度。


### name

```
const char* HiAppEvent_AppEventGroup::name
```
**描述**
事件数组中相同的事件名称。
