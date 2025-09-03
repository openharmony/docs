# hiappevent_cfg.h

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--SE: @junjie_shi-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines the configuration items of the event logging configuration function. If you want to configure the application event logging function, you can directly use configuration item constants.

**File to include**: <hiappevent/hiappevent_cfg.h>

**Library**: libhiappevent_ndk.z.so

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Since**: 8

**Related Module**: [HiAppEvent](capi-hiappevent.md)

## Summary

### Macros

| Name                                       | Description                                                        |
|-------------------------------------------|------------------------------------------------------------|
| [DISABLE](#disable) "disable"             | Whether to disable event logging. The default value is **false**. The value **true** means to disable the event logging function, and the value **false** means the opposite.<br>**Since**: 8|
| [MAX_STORAGE](#max_storage) "max_storage" | Storage quota of the event file directory. The default value is **10M**.<br>**Since**: 8|


## Macro Description

### DISABLE

```
#define DISABLE "disable"
```

**Description**

Whether to disable event logging. The default value is **false**. The value **true** means to disable the event logging function, and the value **false** means the opposite.

**Since**: 8

### MAX_STORAGE

```
#define MAX_STORAGE "max_storage"
```

**Description**

Storage quota of the event file directory. The default value is **10M**.

**Since**: 8
