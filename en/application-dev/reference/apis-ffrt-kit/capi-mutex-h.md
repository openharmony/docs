# mutex.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--SE: @geoffrey_guo; @huangyouzhong-->
<!--TSE: @lotsof; @sunxuhao-->

## Overview

The **mutex.h** file declares the mutex APIs in C.

**File to include**: <ffrt/mutex.h>

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 10

**Related module**: [FFRT](capi-ffrt.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [FFRT_C_API int ffrt_mutexattr_init(ffrt_mutexattr_t* attr)](#ffrt_mutexattr_init) | Initializes the mutex attribute.|
| [FFRT_C_API int ffrt_mutexattr_settype(ffrt_mutexattr_t* attr, int type)](#ffrt_mutexattr_settype) | Sets the mutex attribute type.|
| [FFRT_C_API int ffrt_mutexattr_gettype(ffrt_mutexattr_t* attr, int* type)](#ffrt_mutexattr_gettype) | Obtains the mutex type.|
| [FFRT_C_API int ffrt_mutexattr_destroy(ffrt_mutexattr_t* attr)](#ffrt_mutexattr_destroy) | Destroys the mutex attribute. This API needs to be called by users.|
| [FFRT_C_API int ffrt_mutex_init(ffrt_mutex_t* mutex, const ffrt_mutexattr_t* attr)](#ffrt_mutex_init) | Initializes a mutex.|
| [FFRT_C_API int ffrt_mutex_lock(ffrt_mutex_t* mutex)](#ffrt_mutex_lock) | Locks a mutex.|
| [FFRT_C_API int ffrt_mutex_unlock(ffrt_mutex_t* mutex)](#ffrt_mutex_unlock) | Unlocks a mutex.|
| [FFRT_C_API int ffrt_mutex_trylock(ffrt_mutex_t* mutex)](#ffrt_mutex_trylock) | Attempts to lock a mutex.|

## Function Description

### ffrt_mutexattr_init()

```
FFRT_C_API int ffrt_mutexattr_init(ffrt_mutexattr_t* attr)
```

**Description**

Initializes the mutex attribute.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_mutexattr_t](capi-ffrt-ffrt-mutexattr-t.md)* attr | Pointer to the mutex attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the mutex attribute is initialized;<br>          returns **ffrt_error_inval** otherwise.|

### ffrt_mutexattr_settype()

```
FFRT_C_API int ffrt_mutexattr_settype(ffrt_mutexattr_t* attr, int type)
```

**Description**

Sets the mutex attribute type.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_mutexattr_t](capi-ffrt-ffrt-mutexattr-t.md)* attr | Pointer to the mutex attribute.|
| int type | Mutex type.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the mutex attribute type is set;<br>          returns **ffrt_error_inval** if the pointer to the mutex attribute is null<br>          or the mutex is not of the **ffrt_mutex_normal** or **ffrt_mutex_recursive** type.|

### ffrt_mutexattr_gettype()

```
FFRT_C_API int ffrt_mutexattr_gettype(ffrt_mutexattr_t* attr, int* type)
```

**Description**

Obtains the mutex type.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_mutexattr_t](capi-ffrt-ffrt-mutexattr-t.md)* attr | Pointer to the mutex attribute.|
| int* type | Pointer to the mutex type.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the mutex type is obtained;<br>          returns **ffrt_error_inval** if the pointer to the mutex attribute or mutex type is null.|

### ffrt_mutexattr_destroy()

```
FFRT_C_API int ffrt_mutexattr_destroy(ffrt_mutexattr_t* attr)
```

**Description**

Destroys the mutex attribute. This API needs to be called by users.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_mutexattr_t](capi-ffrt-ffrt-mutexattr-t.md)* attr | Pointer to the mutex attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the mutex attribute is destroyed;<br>          returns **ffrt_error_inval** otherwise.|

### ffrt_mutex_init()

```
FFRT_C_API int ffrt_mutex_init(ffrt_mutex_t* mutex, const ffrt_mutexattr_t* attr)
```

**Description**

Initializes a mutex.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_mutex_t](capi-ffrt-ffrt-mutex-t.md)* mutex | Pointer to the mutex.|
| [const ffrt_mutexattr_t](capi-ffrt-ffrt-mutexattr-t.md)* attr | Pointer to the mutex attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the mutex is initialized;<br>          returns **ffrt_error_inval** otherwise.|

### ffrt_mutex_lock()

```
FFRT_C_API int ffrt_mutex_lock(ffrt_mutex_t* mutex)
```

**Description**

Locks a mutex.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_mutex_t](capi-ffrt-ffrt-mutex-t.md)* mutex | Pointer to the mutex.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the mutex is locked;<br>          returns **ffrt_error_inval** or blocks the calling thread otherwise.|

### ffrt_mutex_unlock()

```
FFRT_C_API int ffrt_mutex_unlock(ffrt_mutex_t* mutex)
```

**Description**

Unlocks a mutex.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_mutex_t](capi-ffrt-ffrt-mutex-t.md)* mutex | Pointer to the mutex.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the mutex is unlocked;<br>          returns **ffrt_error_inval** otherwise.|

### ffrt_mutex_trylock()

```
FFRT_C_API int ffrt_mutex_trylock(ffrt_mutex_t* mutex)
```

**Description**

Attempts to lock a mutex.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_mutex_t](capi-ffrt-ffrt-mutex-t.md)* mutex | Pointer to the mutex.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the mutex is locked;<br>          returns **ffrt_error_inval** or **ffrt_error_busy** otherwise.|
