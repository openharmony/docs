# queue.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--SE: @geoffrey_guo; @huangyouzhong-->
<!--TSE: @lotsof; @sunxuhao-->

## Overview

The **queue.h** file declares the queue APIs in C.

**File to include**: <ffrt/queue.h>

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 10

**Related module**: [FFRT](capi-ffrt.md)

## Summary

### Structs

| Name              | Description|
|------------------|--|
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) | Queue handle. |

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ffrt_queue_type_t](#ffrt_queue_type_t) | ffrt_queue_type_t | Enumerates the queue types.|

### Function

| Name| Description|
| -- | -- |
| [FFRT_C_API int ffrt_queue_attr_init(ffrt_queue_attr_t* attr)](#ffrt_queue_attr_init) | Initializes the queue attribute.|
| [FFRT_C_API void ffrt_queue_attr_destroy(ffrt_queue_attr_t* attr)](#ffrt_queue_attr_destroy) | Destroys the queue attribute.|
| [FFRT_C_API void ffrt_queue_attr_set_qos(ffrt_queue_attr_t* attr, ffrt_qos_t qos)](#ffrt_queue_attr_set_qos) | Sets the queue QoS.|
| [FFRT_C_API ffrt_qos_t ffrt_queue_attr_get_qos(const ffrt_queue_attr_t* attr)](#ffrt_queue_attr_get_qos) | Obtains the queue QoS.|
| [FFRT_C_API void ffrt_queue_attr_set_timeout(ffrt_queue_attr_t* attr, uint64_t timeout_us)](#ffrt_queue_attr_set_timeout) | Sets the queue timeout. The minimum timeout value is 1 ms. Any value set below this threshold will default to 1 ms.|
| [FFRT_C_API uint64_t ffrt_queue_attr_get_timeout(const ffrt_queue_attr_t* attr)](#ffrt_queue_attr_get_timeout) | Obtains the queue timeout.|
| [FFRT_C_API void ffrt_queue_attr_set_callback(ffrt_queue_attr_t* attr, ffrt_function_header_t* f)](#ffrt_queue_attr_set_callback) | Sets a callback that is invoked when a queue task times out.|
| [FFRT_C_API ffrt_function_header_t* ffrt_queue_attr_get_callback(const ffrt_queue_attr_t* attr)](#ffrt_queue_attr_get_callback) | Obtains the callback that is invoked when a queue task times out.|
| [FFRT_C_API void ffrt_queue_attr_set_max_concurrency(ffrt_queue_attr_t* attr, const int max_concurrency)](#ffrt_queue_attr_set_max_concurrency) | Sets the maximum concurrency for a queue, which must be a concurrent queue.|
| [FFRT_C_API int ffrt_queue_attr_get_max_concurrency(const ffrt_queue_attr_t* attr)](#ffrt_queue_attr_get_max_concurrency) | Obtains the maximum concurrency of a queue, which must be a concurrent queue.|
| [FFRT_C_API ffrt_queue_t ffrt_queue_create(ffrt_queue_type_t type, const char* name, const ffrt_queue_attr_t* attr)](#ffrt_queue_create) | Creates a queue.|
| [FFRT_C_API void ffrt_queue_destroy(ffrt_queue_t queue)](#ffrt_queue_destroy) | Destroys a queue.|
| [FFRT_C_API void ffrt_queue_submit(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr)](#ffrt_queue_submit) | Submits a task to a queue.|
| [FFRT_C_API ffrt_task_handle_t ffrt_queue_submit_h(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr)](#ffrt_queue_submit_h) | Submits a task to a queue, and obtains the task handle.|
| [FFRT_C_API void ffrt_queue_submit_f(ffrt_queue_t queue, ffrt_function_t func, void* arg, const ffrt_task_attr_t* attr)](#ffrt_queue_submit_f) | Submits a task to a queue. It is a simplified wrapper of **ffrt_queue_submit**. This API assumes that the callback function does not need to be destroyed. The task function and parameters are encapsulated into a queue task structure, which is then passed to **ffrt_queue_submit** along with other parameters.|
| [FFRT_C_API ffrt_task_handle_t ffrt_queue_submit_h_f(ffrt_queue_t queue, ffrt_function_t func, void* arg, const ffrt_task_attr_t* attr)](#ffrt_queue_submit_h_f) | Submits a task to a queue, and obtains the task handle. It is a simplified wrapper of **ffrt_queue_submit_h**. This API assumes that the callback function does not need to be destroyed. The task function and parameters are encapsulated into a queue task structure, which is then passed to **ffrt_queue_submit_h** along with other parameters.|
| [FFRT_C_API void ffrt_queue_wait(ffrt_task_handle_t handle)](#ffrt_queue_wait) | Waits until a task in the queue is complete.|
| [FFRT_C_API int ffrt_queue_cancel(ffrt_task_handle_t handle)](#ffrt_queue_cancel) | Cancels a task in the queue.|
| [FFRT_C_API ffrt_queue_t ffrt_get_main_queue(void)](#ffrt_get_main_queue) | Obtains the main thread queue.|

## Enum Description

### ffrt_queue_type_t

```
enum ffrt_queue_type_t
```

**Description**

Enumerates the queue types.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| ffrt_queue_serial | Serial queue.|
| ffrt_queue_concurrent | Concurrent queue.|
| ffrt_queue_max | Invalid queue type.|


## Function Description

### ffrt_queue_attr_init()

```
FFRT_C_API int ffrt_queue_attr_init(ffrt_queue_attr_t* attr)
```

**Description**

Initializes the queue attribute.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | Pointer to the queue attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **0** if the queue attribute is initialized;<br>          returns **-1** otherwise.|

### ffrt_queue_attr_destroy()

```
FFRT_C_API void ffrt_queue_attr_destroy(ffrt_queue_attr_t* attr)
```

**Description**

Destroys the queue attribute.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | Pointer to the queue attribute.|

### ffrt_queue_attr_set_qos()

```
FFRT_C_API void ffrt_queue_attr_set_qos(ffrt_queue_attr_t* attr, ffrt_qos_t qos)
```

**Description**

Sets the queue QoS.

**Since**: 10


**Parameters**

| Name                                                      | Description|
|-----------------------------------------------------------| -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | Pointer to the queue attribute.|
| [ffrt_qos_t](capi-type-def-h.md#variables) qos                  | QoS.|

### ffrt_queue_attr_get_qos()

```
FFRT_C_API ffrt_qos_t ffrt_queue_attr_get_qos(const ffrt_queue_attr_t* attr)
```

**Description**

Obtains the queue QoS.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [const ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | Pointer to the queue attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API [ffrt_qos_t](capi-type-def-h.md#variables)| Returns the queue QoS.|

### ffrt_queue_attr_set_timeout()

```
FFRT_C_API void ffrt_queue_attr_set_timeout(ffrt_queue_attr_t* attr, uint64_t timeout_us)
```

**Description**

Sets the serial queue timeout. The minimum timeout value is 1 ms. Any value set below this threshold will default to 1 ms.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | Pointer to the serial queue attribute.|
| uint64_t timeout_us | Serial queue timeout, in microseconds.|

### ffrt_queue_attr_get_timeout()

```
FFRT_C_API uint64_t ffrt_queue_attr_get_timeout(const ffrt_queue_attr_t* attr)
```

**Description**

Obtains the serial queue timeout.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [const ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | Pointer to the serial queue attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API uint64_t | Returns the serial queue timeout.|

### ffrt_queue_attr_set_callback()

```
FFRT_C_API void ffrt_queue_attr_set_callback(ffrt_queue_attr_t* attr, ffrt_function_header_t* f)
```

**Description**

Sets a callback that is invoked when a queue task times out.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | Pointer to the serial queue attribute.|
| [ffrt_function_header_t](capi-ffrt-ffrt-function-header-t.md)* f | Pointer to the callback function invoked upon a timeout.|

### ffrt_queue_attr_get_callback()

```
FFRT_C_API ffrt_function_header_t* ffrt_queue_attr_get_callback(const ffrt_queue_attr_t* attr)
```

**Description**

Obtains the callback that is invoked when a queue task times out.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [const ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | Pointer to the serial queue attribute.|

**Returns**

| Type                                    | Description|
|----------------------------------------| -- |
| FFRT_C_API [ffrt_function_header_t](capi-ffrt-ffrt-function-header-t.md)* | Returns the callback.|

### ffrt_queue_attr_set_max_concurrency()

```
FFRT_C_API void ffrt_queue_attr_set_max_concurrency(ffrt_queue_attr_t* attr, const int max_concurrency)
```

**Description**

Sets the maximum concurrency for a concurrent queue.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | Pointer to the queue attribute.|
| const int max_concurrency | Maximum concurrency.|

### ffrt_queue_attr_get_max_concurrency()

```
FFRT_C_API int ffrt_queue_attr_get_max_concurrency(const ffrt_queue_attr_t* attr)
```

**Description**

Obtains the maximum concurrency of a concurrent queue.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | Pointer to the queue attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns the maximum concurrency.|

### ffrt_queue_create()

```
FFRT_C_API ffrt_queue_t ffrt_queue_create(ffrt_queue_type_t type, const char* name, const ffrt_queue_attr_t* attr)
```

**Description**

Creates a queue.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_queue_type_t](capi-queue-h.md#ffrt_queue_type_t) type | Queue type.|
| const char* name | Pointer to the queue name.|
| [const ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | Pointer to the queue attribute.|

**Returns**

| Type                         | Description|
|-----------------------------| -- |
| FFRT_C_API [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) | Returns a non-null queue handle if the queue is created;<br>          returns a null pointer otherwise.|

### ffrt_queue_destroy()

```
FFRT_C_API void ffrt_queue_destroy(ffrt_queue_t queue)
```

**Description**

Destroys a queue.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) queue | Queue handle.|

### ffrt_queue_submit()

```
FFRT_C_API void ffrt_queue_submit(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr)
```

**Description**

Submits a task to a queue.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) queue | Queue handle.|
| [ffrt_function_header_t](capi-ffrt-ffrt-function-header-t.md)* f | Pointer to the task execution function.|
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

### ffrt_queue_submit_h()

```
FFRT_C_API ffrt_task_handle_t ffrt_queue_submit_h(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr)
```

**Description**

Submits a task to a queue, and obtains the task handle.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) queue | Queue handle.|
| [ffrt_function_header_t](capi-ffrt-ffrt-function-header-t.md)* f | Pointer to the task execution function.|
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

**Returns**

| Type                               | Description|
|-----------------------------------| -- |
| FFRT_C_API [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) | Returns a non-null task handle if the task is submitted;<br>          returns a null pointer otherwise.|

### ffrt_queue_submit_f()

```
FFRT_C_API void ffrt_queue_submit_f(ffrt_queue_t queue, ffrt_function_t func, void* arg, const ffrt_task_attr_t* attr)
```

**Description**

Submits a task to a queue. It is a simplified wrapper of **ffrt_queue_submit**. This API assumes that the callback function does not need to be destroyed. The task function and parameters are encapsulated into a queue task structure, which is then passed to **ffrt_queue_submit** along with other parameters.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) queue | Queue handle.|
| [ffrt_function_t](capi-type-def-h.md#ffrt_function_t) func | Task function.|
| void* arg | Pointer to the argument.|
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

**References**

[ffrt_queue_submit](capi-queue-h.md#ffrt_queue_submit)


### ffrt_queue_submit_h_f()

```
FFRT_C_API ffrt_task_handle_t ffrt_queue_submit_h_f(ffrt_queue_t queue, ffrt_function_t func, void* arg, const ffrt_task_attr_t* attr)
```

**Description**

Submits a task to a queue, and obtains the task handle. It is a simplified wrapper of **ffrt_queue_submit_h**. This API assumes that the callback function does not need to be destroyed. The task function and parameters are encapsulated into a queue task structure, which is then passed to **ffrt_queue_submit_h** along with other parameters.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) queue | Queue handle.|
| [ffrt_function_t](capi-type-def-h.md#ffrt_function_t) func | Task function.|
| void* arg | Pointer to the argument.|
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) | Returns a non-null task handle if the task is submitted;<br>          returns a null pointer otherwise.|

**References**

[ffrt_queue_submit_h](capi-queue-h.md#ffrt_queue_submit_h)


### ffrt_queue_wait()

```
FFRT_C_API void ffrt_queue_wait(ffrt_task_handle_t handle)
```

**Description**

Waits until a task in the queue is complete.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) handle | Task handle.|

### ffrt_queue_cancel()

```
FFRT_C_API int ffrt_queue_cancel(ffrt_task_handle_t handle)
```

**Description**

Cancels a task in the queue.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) handle | Task handle.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **0** if the task is canceled;<br>          returns **-1** otherwise.|

### ffrt_get_main_queue()

```
FFRT_C_API ffrt_queue_t ffrt_get_main_queue(void)
```

**Description**

Obtains the main thread queue.

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) | Returns the handle to the main thread queue.|
