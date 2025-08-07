# type_def.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--SE: @geoffrey_guo; @huangyouzhong-->
<!--TSE: @lotsof; @sunxuhao-->

## Overview

The **type_def.h** file declares the common types.

**File to include**: <ffrt/type_def.h>

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 10

**Related module**: [FFRT](capi-ffrt.md)

## Summary

### Variables

| Name | typedef Keyword| Description                    |
|-----|------------|------------------------|
| int | ffrt_timer_t | Handle to the timer.                |
| int | ffrt_qos_t | QoS type.                |
| using qos = int | - | QoS type.<br>**Since**: 10|

### Structs

| Name| typedef Keyword                                           | Description          |
| -- |-------------------------------------------------------|--------------|
| [ffrt_function_header_t](capi-ffrt-ffrt-function-header-t.md) | ffrt_function_header_t                                | Describes a task execution function.      |
| [ffrt_dependence_t](capi-ffrt-ffrt-dependence-t.md) | ffrt_dependence_t                                     | Describes dependency data.     |
| [ffrt_deps_t](capi-ffrt-ffrt-deps-t.md) | ffrt_deps_t                                           | Describes dependencies.     |
| [ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md) | ffrt_task_attr_t                                      | Describes a task attribute.   |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md) | ffrt_queue_attr_t                                     | Describes a serial queue attribute.   |
| [ffrt_condattr_t](capi-ffrt-ffrt-condattr-t.md) | ffrt_condattr_t                                       | Describes a condition variable attribute.|
| [ffrt_mutexattr_t](capi-ffrt-ffrt-mutexattr-t.md) | ffrt_mutexattr_t                                      | Describes a mutex attribute.  |
| [ffrt_rwlockattr_t](capi-ffrt-ffrt-rwlockattr-t.md) | ffrt_rwlockattr_t                                     | Describes a read-write lock attribute.|
| [ffrt_mutex_t](capi-ffrt-ffrt-mutex-t.md) | ffrt_mutex_t                                          | Describes a mutex.  |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md) | ffrt_rwlock_t                                         | Describes a read-write lock.  |
| [ffrt_cond_t](capi-ffrt-ffrt-cond-t.md) | ffrt_cond_t                                           | Describes a condition variable. |
| void* | [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) | Defines the handle to a task.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ffrt_queue_priority_t](#ffrt_queue_priority_t) | ffrt_queue_priority_t | Enumerates the task priority types.|
| [ffrt_qos_default_t](#ffrt_qos_default_t) | ffrt_qos_default_t | Enumerates the task QoS types.|
| [ffrt_storage_size_t](#ffrt_storage_size_t) | ffrt_storage_size_t | Enumerates the storage sizes available for different types of structs.|
| [ffrt_function_kind_t](#ffrt_function_kind_t) | ffrt_function_kind_t | Enumerates the task types.|
| [ffrt_dependence_type_t](#ffrt_dependence_type_t) | ffrt_dependence_type_t | Enumerates the dependency types.|
| [ffrt_error_t](#ffrt_error_t) | ffrt_error_t | Enumerates the FFRT error codes.|
| [ffrt_mutex_type](#ffrt_mutex_type) | ffrt_mutex_type | Enumerates the mutex types. **ffrt_mutex_normal** indicates a normal mutex, **ffrt_mutex_recursive** indicates a recursive mutex, and **ffrt_mutex_default** indicates a default mutex.|
| [qos_default](#qos_default) | - | Enumerates the task QoS types.|

### Function

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void(\*ffrt_function_t)(void*)](#ffrt_function_t) | ffrt_function_t | Defines the type of the pointer to a task execution function.|
| [typedef void (\*ffrt_poller_cb)(void* data, uint32_t event)](#ffrt_poller_cb) | ffrt_poller_cb | Defines the poller callback function.|
| [typedef void (\*ffrt_timer_cb)(void* data)](#ffrt_timer_cb) | ffrt_timer_cb | Defines the timer callback function.|


## Enum Description

### ffrt_queue_priority_t

```
enum ffrt_queue_priority_t
```

**Description**

Enumerates the task priority types.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| ffrt_queue_priority_immediate = 0 | Immediate priority.|
| ffrt_queue_priority_high | High priority.|
| ffrt_queue_priority_low | Low priority.|
| ffrt_queue_priority_idle | Lowest priority.|

### ffrt_qos_default_t

```
enum ffrt_qos_default_t
```

**Description**

Enumerates the task QoS types.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| ffrt_qos_inherit = -1 | Inherited task QoS.|
| ffrt_qos_background | Background task.|
| ffrt_qos_utility | Real-time utility.|
| ffrt_qos_default | Default type.|
| ffrt_qos_user_initiated | User initiated.|

### ffrt_storage_size_t

```
enum ffrt_storage_size_t
```

**Description**

Enumerates the storage sizes available for different types of structs.

**Since**: 10

| Enum Item| Description                 |
| -- |---------------------|
| ffrt_task_attr_storage_size = 128 | Storage size for the task attribute struct.               |
| ffrt_auto_managed_function_storage_size = 64 + sizeof(ffrt_function_header_t) | Storage size for the task execution function struct.              |
| ffrt_mutex_storage_size = 64 | Storage size for the mutex struct.                |
| ffrt_cond_storage_size = 64 | Storage size for the condition variable struct.               |
| ffrt_queue_attr_storage_size = 128 | Storage size for the queue attribute struct.               |
| ffrt_rwlock_storage_size = 64 | Read-write lock.<br>**Since**: 18|

### ffrt_function_kind_t

```
enum ffrt_function_kind_t
```

**Description**

Task type.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| ffrt_function_kind_general | General task.|
| ffrt_function_kind_queue | Queue task.|

### ffrt_dependence_type_t

```
enum ffrt_dependence_type_t
```

**Description**

Enumerates the dependency types.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| ffrt_dependence_data | Data dependency.|
| ffrt_dependence_task | Task dependency.|

### ffrt_error_t

```
enum ffrt_error_t
```

**Description**

Enumerates the FFRT error codes.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| ffrt_error = -1 | Failure.|
| ffrt_success = 0 | Success.|
| ffrt_error_nomem = ENOMEM | Insufficient memory.|
| ffrt_error_timedout = ETIMEDOUT | Timeout.|
| ffrt_error_busy = EBUSY | Try again.|
| ffrt_error_inval = EINVAL | Invalid value.|

### ffrt_mutex_type

```
enum ffrt_mutex_type
```

**Description**

Enumerates the mutex types. **ffrt_mutex_normal** indicates a normal mutex, **ffrt_mutex_recursive** indicates a recursive mutex, and **ffrt_mutex_default** indicates a default mutex.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| ffrt_mutex_normal = 0 | Normal mutex.|
| ffrt_mutex_recursive = 2 | Recursive mutex.|
| ffrt_mutex_default = ffrt_mutex_normal | Default mutex.|

### qos_default

```
enum qos_default
```

**Description**

Enumerates the task QoS types.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| qos_inherit = ffrt_qos_inherit | Inherited task QoS.|
| qos_background = ffrt_qos_background | Background task.|
| qos_utility = ffrt_qos_utility | Real-time utility.|
| qos_default = ffrt_qos_default | Default type.|
| qos_user_initiated = ffrt_qos_user_initiated | User initiated.|


## Function Description

### ffrt_function_t()

```
typedef void(*ffrt_function_t)(void*)
```

**Description**

Defines the type of the pointer to a task execution function.

**Since**: 10

### ffrt_poller_cb()

```
typedef void (*ffrt_poller_cb)(void* data, uint32_t event)
```

**Description**

Defines the poller callback function.

**Since**: 12

### ffrt_timer_cb()

```
typedef void (*ffrt_timer_cb)(void* data)
```

**Description**

Defines the timer callback function.

**Since**: 12
