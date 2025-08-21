# shared_mutex.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## Overview

The **shared_mutex.h** file declares read-write lock APIs in C.

**File to include**: <ffrt/shared_mutex.h>

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 18

**Related module**: [FFRT](capi-ffrt.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [FFRT_C_API int ffrt_rwlock_init(ffrt_rwlock_t* rwlock, const ffrt_rwlockattr_t* attr)](#ffrt_rwlock_init) | Initializes a read-write lock.|
| [FFRT_C_API int ffrt_rwlock_wrlock(ffrt_rwlock_t* rwlock)](#ffrt_rwlock_wrlock) | Obtains a write lock.|
| [FFRT_C_API int ffrt_rwlock_trywrlock(ffrt_rwlock_t* rwlock)](#ffrt_rwlock_trywrlock) | Attempts to obtain a write lock.|
| [FFRT_C_API int ffrt_rwlock_rdlock(ffrt_rwlock_t* rwlock)](#ffrt_rwlock_rdlock) | Obtains a read lock.|
| [FFRT_C_API int ffrt_rwlock_tryrdlock(ffrt_rwlock_t* rwlock)](#ffrt_rwlock_tryrdlock) | Attempts to obtain a read lock.|
| [FFRT_C_API int ffrt_rwlock_unlock(ffrt_rwlock_t* rwlock)](#ffrt_rwlock_unlock) | Releases the read-write lock.|
| [FFRT_C_API int ffrt_rwlock_destroy(ffrt_rwlock_t* rwlock)](#ffrt_rwlock_destroy) | Destroys the read-write lock.|

## Function Description

### ffrt_rwlock_init()

```
FFRT_C_API int ffrt_rwlock_init(ffrt_rwlock_t* rwlock, const ffrt_rwlockattr_t* attr)
```

**Description**

Initializes a read-write lock.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | Pointer to the read-write lock.|
| [const ffrt_rwlockattr_t](capi-ffrt-ffrt-rwlockattr-t.md)* attr | Pointer to the read-write lock attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the read-write lock is successfully initialized;<br>          returns **ffrt_error_inval** otherwise.|

### ffrt_rwlock_wrlock()

```
FFRT_C_API int ffrt_rwlock_wrlock(ffrt_rwlock_t* rwlock)
```

**Description**

Obtains a write lock.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | Pointer to the read-write lock.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the write lock is successfully obtained;<br>          returns **ffrt_error_inval** or blocks the task otherwise.|

### ffrt_rwlock_trywrlock()

```
FFRT_C_API int ffrt_rwlock_trywrlock(ffrt_rwlock_t* rwlock)
```

**Description**

Attempts to obtain a write lock.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | Pointer to the read-write lock.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the write lock is successfully obtained;<br>          returns **ffrt_error_inval** or **ffrt_error_busy** otherwise.|

### ffrt_rwlock_rdlock()

```
FFRT_C_API int ffrt_rwlock_rdlock(ffrt_rwlock_t* rwlock)
```

**Description**

Obtains a read lock.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | Pointer to the read-write lock.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the read lock is successfully obtained;<br>          returns **ffrt_error_inval** or blocks the task otherwise.|

### ffrt_rwlock_tryrdlock()

```
FFRT_C_API int ffrt_rwlock_tryrdlock(ffrt_rwlock_t* rwlock)
```

**Description**

Attempts to obtain a read lock.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | Pointer to the read-write lock.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the read lock is successfully obtained;<br>          returns **ffrt_error_inval** or **ffrt_error_busy** otherwise.|

### ffrt_rwlock_unlock()

```
FFRT_C_API int ffrt_rwlock_unlock(ffrt_rwlock_t* rwlock)
```

**Description**

Releases the read-write lock.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | Pointer to the read-write lock.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the read-write lock is successfully released;<br>          returns **ffrt_error_inval** otherwise.|

### ffrt_rwlock_destroy()

```
FFRT_C_API int ffrt_rwlock_destroy(ffrt_rwlock_t* rwlock)
```

**Description**

Destroys the read-write lock.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | Pointer to the read-write lock.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **ffrt_success** if the read-write lock is destroyed successfully;<br>returns **ffrt_error_inval** otherwise.|
