# fiber.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## Overview

A fiber is a lightweight user mode thread that enables efficient task scheduling and context switching within the user space. The **fiber.h** file declares the related APIs in C.

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 20

**Related module**: [FFRT](capi-ffrt.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [FFRT_C_API int ffrt_fiber_init(ffrt_fiber_t* fiber, void(\*func)(void*), void* arg, void* stack, size_t stack_size)](#ffrt_fiber_init) | Initializes a fiber. The initialized fiber instance can store contexts.|
| [FFRT_C_API void ffrt_fiber_switch(ffrt_fiber_t* from, ffrt_fiber_t* to)](#ffrt_fiber_switch) | Switches between fibers. The thread that calls this function suspends the current task, saves the context to the **from** fiber, and restores the context of the **to** fiber.|

## Function Description

### ffrt_fiber_init()

```
FFRT_C_API int ffrt_fiber_init(ffrt_fiber_t* fiber, void(*func)(void*), void* arg, void* stack, size_t stack_size)
```

**Description**

Initializes a fiber. The initialized fiber instance can store contexts.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| fiber | Pointer to the fiber to be initialized. For details, see [ffrt_fiber_t](capi-ffrt-ffrt-fiber-t.md).|
| func | Method to be executed after fiber switching.|
|  void* arg | Pointer to the argument of the method.|
|  void* stack | Pointer to the fiber stack memory.|
|  size_t stack_size | Fiber stack size. For details, see [ffrt_storage_size_t](capi-type-def-h.md#ffrt_storage_size_t).|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int (ffrt_fiber_t* fiber, void(*func) | If the initialization is successful, **ffrt_success** is returned. Otherwise, **ffrt_error** is returned.|

### ffrt_fiber_switch()

```
FFRT_C_API void ffrt_fiber_switch(ffrt_fiber_t* from, ffrt_fiber_t* to)
```

**Description**

Switches between fibers. The thread that calls this function suspends the current task, saves the context to the **from** fiber, and restores the context of the **to** fiber.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_fiber_t](capi-ffrt-ffrt-fiber-t.md)* from | Pointer to the fiber to be saved.|
| [ffrt_fiber_t](capi-ffrt-ffrt-fiber-t.md)* to | Pointer to the fiber to be restored.|
