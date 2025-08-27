# timer.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

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
| [FFRT_C_API int ffrt_timer_stop(ffrt_qos_t qos, ffrt_timer_t handle)](#ffrt_timer_stop) | Stops the timer.|

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

### ffrt_timer_stop()

```
FFRT_C_API int ffrt_timer_stop(ffrt_qos_t qos, ffrt_timer_t handle)
```

**Description**

Stops the timer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| ffrt_qos_t qos | QoS.|
| ffrt_timer_t handle | Handle to the timer.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **0** if the timer is stopped successfully;<br>          returns **-1** otherwise.|
