# timer.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--SE: @geoffrey_guo; @huangyouzhong-->
<!--TSE: @lotsof; @sunxuhao-->

## Overview

The **timer.h** file declares the timer APIs in C.

**File to include**: <ffrt/timer.h>

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 12

**Related module**: [FFRT](capi-ffrt.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [FFRT_C_API ffrt_timer_t ffrt_timer_start(ffrt_qos_t qos, uint64_t timeout, void* data, ffrt_timer_cb cb, bool repeat)](#ffrt_timer_start) | Starts the timer.|

## Function Description

### ffrt_timer_start()

```
FFRT_C_API ffrt_timer_t ffrt_timer_start(ffrt_qos_t qos, uint64_t timeout, void* data, ffrt_timer_cb cb, bool repeat)
```

**Description**

Starts the timer.

**Since**: 12


**Parameters**

| Name                                                 | Description|
|------------------------------------------------------| -- |
| [ffrt_qos_t](capi-type-def-h.md#variables) qos             | QoS.|
| uint64_t timeout                                     | Timeout, in milliseconds.|
| void* data                                           | Pointer to the input parameter in the callback function invoked upon a timeout.|
| [ffrt_timer_cb](capi-type-def-h.md#ffrt_timer_cb) cb | Callback function invoked upon a timeout.|
| bool repeat                                          | Whether to repeat the timer (not supported yet).|

**Returns**

| Type                         | Description|
|-----------------------------| -- |
| FFRT_C_API [ffrt_timer_t](capi-type-def-h.md#variables)| Returns the timer handle.|
