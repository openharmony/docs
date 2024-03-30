# hiappevent_cfg.h


## Overview

Defines the configuration items of the event logging configuration function.

If you want to configure the application event logging function, you can directly use configuration item constants.

Example:

```
bool res = OH_HiAppEvent_Configure(MAX_STORAGE, "100M");
```

**Since**: 8

**Related module**: [HiAppEvent](_hi_app_event.md)


## Summary


### Macros

| Name| Description| 
| -------- | -------- |
| [DISABLE](_hi_app_event.md#disable)   "disable" | Specifies whether to disable event logging.| 
| [MAX_STORAGE](_hi_app_event.md#max_storage)   "max_storage" | Specifies the storage quota of the event file directory.| 
