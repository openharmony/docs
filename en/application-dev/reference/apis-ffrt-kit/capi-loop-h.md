# loop.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## Overview

The **loop.h** file declares the loop APIs in C.

**File to include**: <ffrt/loop.h>

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 12

**Related module**: [FFRT](capi-ffrt.md)

## Summary

### Structs

| Name             | Description|
|-----------------|----|
| [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) | Defines the handle to a loop.  |


### Function

| Name| Description|
| -- | -- |
| [FFRT_C_API ffrt_loop_t ffrt_loop_create(ffrt_queue_t queue)](#ffrt_loop_create) | Creates a loop.|
| [FFRT_C_API int ffrt_loop_destroy(ffrt_loop_t loop)](#ffrt_loop_destroy) | Destroys a loop.|
| [FFRT_C_API int ffrt_loop_run(ffrt_loop_t loop)](#ffrt_loop_run) | Runs a loop.|
| [FFRT_C_API void ffrt_loop_stop(ffrt_loop_t loop)](#ffrt_loop_stop) | Stops a loop.|
| [FFRT_C_API int ffrt_loop_epoll_ctl(ffrt_loop_t loop, int op, int fd, uint32_t events, void *data, ffrt_poller_cb cb)](#ffrt_loop_epoll_ctl) | Manages listening events on a loop.|
| [FFRT_C_API ffrt_timer_t ffrt_loop_timer_start(ffrt_loop_t loop, uint64_t timeout, void* data, ffrt_timer_cb cb, bool repeat)](#ffrt_loop_timer_start) | Starts the timer on a loop.|
| [FFRT_C_API int ffrt_loop_timer_stop(ffrt_loop_t loop, ffrt_timer_t handle)](#ffrt_loop_timer_stop) | Stops the timer on a loop.|

## Function Description

### ffrt_loop_create()

```
FFRT_C_API ffrt_loop_t ffrt_loop_create(ffrt_queue_t queue)
```

**Description**

Creates a loop.

**Since**: 12


**Parameters**

| Name                   | Description|
|------------------------| -- |
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) queue | Concurrent queue.|

**Returns**

| Type                        | Description|
|----------------------------| -- |
| FFRT_C_API [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) | Returns the **ffrt_loop_t** object if the loop is created;<br>          returns a null pointer otherwise.|

### ffrt_loop_destroy()

```
FFRT_C_API int ffrt_loop_destroy(ffrt_loop_t loop)
```

**Description**

Destroys a loop.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) loop | Loop object.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **0** if the loop is destroyed;<br>          returns **-1** otherwise.|

### ffrt_loop_run()

```
FFRT_C_API int ffrt_loop_run(ffrt_loop_t loop)
```

**Description**

Runs a loop.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) loop | Loop object.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **0** if the loop runs successfully;<br>          returns **-1** otherwise.|

### ffrt_loop_stop()

```
FFRT_C_API void ffrt_loop_stop(ffrt_loop_t loop)
```

**Description**

Stops a loop.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) loop | Loop object.|

### ffrt_loop_epoll_ctl()

```
FFRT_C_API int ffrt_loop_epoll_ctl(ffrt_loop_t loop, int op, int fd, uint32_t events, void *data, ffrt_poller_cb cb)
```

**Description**

Manages listening events on a loop.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) loop | Loop object.|
| int op | Operation to be performed.|
| int fd | File descriptor.|
| uint32_t events | Event.|
| void *data | Pointer to the input parameter in the callback function invoked upon event changes.|
| [ffrt_poller_cb](capi-type-def-h.md#ffrt_poller_cb) cb | Callback function invoked upon event changes.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **0** if the operation is successful;<br>          returns **-1** otherwise.|

### ffrt_loop_timer_start()

```
FFRT_C_API ffrt_timer_t ffrt_loop_timer_start(ffrt_loop_t loop, uint64_t timeout, void* data, ffrt_timer_cb cb, bool repeat)
```

**Description**

Starts the timer on a loop.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) loop | Loop object.|
| uint64_t timeout | Timeout, in milliseconds.|
| void* data | Pointer to the input parameter in the callback function invoked upon event changes.|
| [ffrt_timer_cb](capi-type-def-h.md#ffrt_timer_cb) cb | Callback function invoked upon event changes.|
| bool repeat | Whether to repeat the timer.|

**Returns**

| Type                                              | Description|
|--------------------------------------------------| -- |
| FFRT_C_API [ffrt_timer_t](capi-type-def-h.md#variables)| Returns the timer handle.|

### ffrt_loop_timer_stop()

```
FFRT_C_API int ffrt_loop_timer_stop(ffrt_loop_t loop, ffrt_timer_t handle)
```

**Description**

Stops the timer on a loop.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| ffrt_loop_t loop | Loop object.|
| ffrt_timer_t handle | Timer handle.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **0** if the operation is successful;<br>returns **-1** otherwise.|
