# hiappevent_event.h


## Overview

Defines the names of all predefined events.

In addition to custom events associated with specific applications, you can use predefined events for logging.

Example:

```
ParamList list = OH_HiAppEvent_CreateParamList();
OH_HiAppEvent_AddInt32Param(list, PARAM_USER_ID, 123);
int res = OH_HiAppEvent_Write("user_domain", EVENT_USER_LOGIN, BEHAVIOR, list);
OH_HiAppEvent_DestroyParamList(list);
```

**File to include**: <hiappevent/hiappevent_event.h>

**Since**: 8

**Related module**: [HiAppEvent](_hi_app_event.md)


## Summary


### Macros

| Name| Description| 
| -------- | -------- |
| [EVENT_USER_LOGIN](_hi_app_event.md#event_user_login)   "hiappevent.user_login" | User login event. | 
| [EVENT_USER_LOGOUT](_hi_app_event.md#event_user_logout)   "hiappevent.user_logout" | User logout event. | 
| [EVENT_DISTRIBUTED_SERVICE_START](_hi_app_event.md#event_distributed_service_start)   "hiappevent.distributed_service_start" | Distributed service event. | 
| [EVENT_APP_CRASH](_hi_app_event.md#event_app_crash)   "APP_CRASH" | Application crash event. | 
| [EVENT_APP_FREEZE](_hi_app_event.md#event_app_freeze)   "APP_FREEZE" | Application freeze event. | 
| [EVENT_APP_LAUNCH](_hi_app_event.md#event_app_launch)   "APP_LAUNCH" | Application loading event. | 
| [EVENT_SCROLL_JANK](_hi_app_event.md#event_scroll_jank)   "SCROLL_JANK" | Event indicating application freeze during swiping. | 
| [EVENT_CPU_USAGE_HIGH](_hi_app_event.md#event_cpu_usage_high)   "CPU_USAGE_HIGH" | Event indicating high CPU usage of an application. | 
| [EVENT_BATTERY_USAGE](_hi_app_event.md#event_battery_usage)   "BATTERY_USAGE" | Application power usage event. | 
| [EVENT_RESOURCE_OVERLIMIT](_hi_app_event.md#event_resource_overlimit)   "RESOURCE_OVERLIMIT" | Application resource threshold-crossing event. | 
| [DOMAIN_OS](_hi_app_event.md#domain_os)   "OS" | OS scope. | 
