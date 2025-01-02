# hiappevent_param.h


## Overview

Defines the names of all predefined event parameters.

In addition to custom events associated with specific applications, you can use predefined events for logging.

Example:

```
ParamList list = OH_HiAppEvent_CreateParamList();
OH_HiAppEvent_AddInt32Param(list, PARAM_USER_ID, 123);
int res = OH_HiAppEvent_Write("user_domain", EVENT_USER_LOGIN, BEHAVIOR, list);
OH_HiAppEvent_DestroyParamList(list);
```

**File to include**: <hiappevent/hiappevent_param.h>

**Since**: 8

**Related module**: [HiAppEvent](_hi_app_event.md)


## Summary


### Macros

| Name| Description| 
| -------- | -------- |
| [PARAM_USER_ID](_hi_app_event.md#param_user_id)   "user_id" | User ID.| 
| [PARAM_DISTRIBUTED_SERVICE_NAME](_hi_app_event.md#param_distributed_service_name)   "ds_name" | Distributed service name.| 
| [PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID](_hi_app_event.md#param_distributed_service_instance_id)   "ds_instance_id" | Distributed service instance ID.| 
