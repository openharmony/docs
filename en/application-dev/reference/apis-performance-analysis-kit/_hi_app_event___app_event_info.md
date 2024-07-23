# HiAppEvent_AppEventInfo


## Overview

Defines information about a single event, including the event domain, event name, event type, and custom parameter list in JSON string format.

\@SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12

**Related module**: [HiAppEvent](_hi_app_event.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const char \* [domain](#domain) | Pointer to the event domain. | 
| const char \* [name](#name) | Pointer to the event name. | 
| enum [EventType](_hi_app_event.md#eventtype) [type](#type) | Event type. | 
| const char \* [params](#params) | A list of custom parameters in JSON string format. | 


## Member Variable Description


### domain

```
const char* HiAppEvent_AppEventInfo::domain
```
**Description**
Pointer to the event domain.


### name

```
const char* HiAppEvent_AppEventInfo::name
```
**Description**
Pointer to the event name.


### params

```
const char* HiAppEvent_AppEventInfo::params
```
**Description**
A list of custom parameters in JSON string format.


### type

```
enum EventType HiAppEvent_AppEventInfo::type
```
**Description**
Event type.
