# condition_variable.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## Overview

The **condition_variable.h** file declares the condition variable APIs in C.

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 10

**Related module**: [FFRT](capi-ffrt.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [FFRT_C_API int ffrt_cond_init(ffrt_cond_t* cond, const ffrt_condattr_t* attr)](#ffrt_cond_init) | Initializes a condition variable.|
| [FFRT_C_API int ffrt_cond_signal(ffrt_cond_t* cond)](#ffrt_cond_signal) | Unblocks at least one of the threads that are blocked on a condition variable.|
| [FFRT_C_API int ffrt_cond_broadcast(ffrt_cond_t* cond)](#ffrt_cond_broadcast) | Unblocks all threads currently blocked on a condition variable.|
| [FFRT_C_API int ffrt_cond_wait(ffrt_cond_t* cond, ffrt_mutex_t* mutex)](#ffrt_cond_wait) | Blocks the calling thread on a condition variable.|
| [FFRT_C_API int ffrt_cond_timedwait(ffrt_cond_t* cond, ffrt_mutex_t* mutex, const struct timespec* time_point)](#ffrt_cond_timedwait) | Blocks the calling thread on a condition variable for a given duration. If **ffrt_cond_signal** or **ffrt_cond_broadcast** is not called to unblock the thread when the maximum wait time is reached, the thread is automatically unblocked.|
| [FFRT_C_API int ffrt_cond_destroy(ffrt_cond_t* cond)](#ffrt_cond_destroy) | Destroys a condition variable.|

## Function Description

### ffrt_cond_init()

```
FFRT_C_API int ffrt_cond_init(ffrt_cond_t* cond, const ffrt_condattr_t* attr)
```

**Description**

Initializes a condition variable.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_cond_t](capi-ffrt-ffrt-cond-t.md)* cond | Pointer to the condition variable.|
| [const ffrt_condattr_t](capi-ffrt-ffrt-condattr-t.md)* attr | Pointer to the condition variable attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the condition variable is initialized;<br>          returns **ffrt_error_inval** otherwise.|

### ffrt_cond_signal()

```
FFRT_C_API int ffrt_cond_signal(ffrt_cond_t* cond)
```

**Description**

Unblocks at least one of the threads that are blocked on a condition variable.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_cond_t](capi-ffrt-ffrt-cond-t.md)* cond | Pointer to the condition variable.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if at least one of the threads is unblocked;<br>          returns **ffrt_error_inval** otherwise.|

### ffrt_cond_broadcast()

```
FFRT_C_API int ffrt_cond_broadcast(ffrt_cond_t* cond)
```

**Description**

Unblocks all threads currently blocked on a condition variable.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_cond_t](capi-ffrt-ffrt-cond-t.md)* cond | Pointer to the condition variable.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if all threads are unblocked;<br>          returns **ffrt_error_inval** otherwise.|

### ffrt_cond_wait()

```
FFRT_C_API int ffrt_cond_wait(ffrt_cond_t* cond, ffrt_mutex_t* mutex)
```

**Description**

Blocks the calling thread on a condition variable.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_cond_t](capi-ffrt-ffrt-cond-t.md)* cond | Pointer to the condition variable.|
| [ffrt_mutex_t](capi-ffrt-ffrt-mutex-t.md)* mutex | Pointer to the mutex.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the thread is unblocked after being blocked;<br>          returns **ffrt_error_inval** otherwise.|

### ffrt_cond_timedwait()

```
FFRT_C_API int ffrt_cond_timedwait(ffrt_cond_t* cond, ffrt_mutex_t* mutex, const struct timespec* time_point)
```

**Description**

Blocks the calling thread on a condition variable for a given duration. If **ffrt_cond_signal** or **ffrt_cond_broadcast** is not called to unblock the thread when the maximum wait time is reached, the thread is automatically unblocked.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_cond_t](capi-ffrt-ffrt-cond-t.md)* cond | Pointer to the condition variable.|
| [ffrt_mutex_t](capi-ffrt-ffrt-mutex-t.md)* mutex | Pointer to the mutex.|
| const struct timespec* time_point | Pointer to the maximum duration that the thread is blocked.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the thread is unblocked after being blocked;<br>          returns **ffrt_error_timedout** if the wait times out;<br>          returns **ffrt_error_inval** if the wait fails.|

### ffrt_cond_destroy()

```
FFRT_C_API int ffrt_cond_destroy(ffrt_cond_t* cond)
```

**Description**

Destroys a condition variable.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_cond_t](capi-ffrt-ffrt-cond-t.md)* cond | Pointer to the condition variable.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the condition variable is destroyed successfully;<br>returns **ffrt_error_inval** otherwise.|
