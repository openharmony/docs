# hiappevent_cfg.h


## Overview

Defines the configuration items of the event logging configuration function.

If you want to configure the application event logging function, you can directly use configuration item constants.

Example:

```
bool res = OH_HiAppEvent_Configure(MAX_STORAGE, "100M");
```

**Library**: libhiappevent_ndk.z.so

**File to include**: <hiappevent/hiappevent_cfg.h>

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Since**: 8

**Related module**: [HiAppEvent](_hi_app_event.md)


## Summary


### Macros

| Name| Description| 
| -------- | -------- |
| [DISABLE](_hi_app_event.md#disable)&nbsp;&nbsp;&nbsp;"disable" | Specifies whether to disable event logging. The default value is **false**. The value **true** means to disable the event logging function, and the value **false** means the opposite. | 
| [MAX_STORAGE](_hi_app_event.md#max_storage)&nbsp;&nbsp;&nbsp;"max_storage" | Specifies the storage quota of the event file directory. The default value is **10M**. | 
