# HiAppEvent_AppEventGroup


## Overview

Defines an array of events with the same event name. 

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12

**Related module**: [HiAppEvent](_hi_app_event.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const char \* [name](#name) | Pointer to the event name. | 
| const struct [HiAppEvent_AppEventInfo](_hi_app_event___app_event_info.md) \* [appEventInfos](#appeventinfos) | Pointer to the array of events with the same event name. | 
| uint32_t [infoLen](#infolen) | Length of the event array. | 


## Member Variable Description


### appEventInfos

```
const struct HiAppEvent_AppEventInfo* HiAppEvent_AppEventGroup::appEventInfos
```
**Description**
Pointer to the array of events with the same event name. 


### infoLen

```
uint32_t HiAppEvent_AppEventGroup::infoLen
```
**Description**
Length of the event array.


### name

```
const char* HiAppEvent_AppEventGroup::name
```
**Description**
Pointer to the event name.
