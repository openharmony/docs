# sleep.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## Overview

The **sleep.h** file declares the sleep and yield APIs in C.

**File to include**: <ffrt/sleep.h>

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 10

**Related module**: [FFRT](capi-ffrt.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [FFRT_C_API int ffrt_usleep(uint64_t usec)](#ffrt_usleep) | Sets the fixed sleep time.|
| [FFRT_C_API void ffrt_yield(void)](#ffrt_yield) | Passes control to other tasks so that they can be executed.|

## Function Description

### ffrt_usleep()

```
FFRT_C_API int ffrt_usleep(uint64_t usec)
```

**Description**

Sets the fixed sleep time.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| uint64_t usec | Sleep time, in microseconds.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the sleep time is set;<br>          returns **ffrt_error** otherwise.|

### ffrt_yield()

```
FFRT_C_API void ffrt_yield(void)
```

**Description**

Passes control to other tasks so that they can be executed.

**Since**: 10
