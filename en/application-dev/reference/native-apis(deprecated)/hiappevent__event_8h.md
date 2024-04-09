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

**Since**: 8

**Related module**: [HiAppEvent](_hi_app_event.md)


## Summary


### Macros

| Name| Description| 
| -------- | -------- |
| [EVENT_USER_LOGIN](_hi_app_event.md#event_user_login)   "hiappevent.user_login" | User login event.| 
| [EVENT_USER_LOGOUT](_hi_app_event.md#event_user_logout)   "hiappevent.user_logout" | User logout event.| 
| [EVENT_DISTRIBUTED_SERVICE_START](_hi_app_event.md#event_distributed_service_start)   "hiappevent.distributed_service_start" | Distributed service event.| 
