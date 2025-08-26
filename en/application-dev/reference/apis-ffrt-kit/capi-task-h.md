# task.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## Overview

The **task.h** file declares the task APIs in C.

**File to include**: <ffrt/task.h>

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 10

**Related module**: [FFRT](capi-ffrt.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [FFRT_C_API int ffrt_task_attr_init(ffrt_task_attr_t* attr)](#ffrt_task_attr_init) | Initializes a task attribute.|
| [FFRT_C_API void ffrt_task_attr_set_name(ffrt_task_attr_t* attr, const char* name)](#ffrt_task_attr_set_name) | Sets a task name.|
| [FFRT_C_API const char* ffrt_task_attr_get_name(const ffrt_task_attr_t* attr)](#ffrt_task_attr_get_name) | Obtains a task name.|
| [FFRT_C_API void ffrt_task_attr_destroy(ffrt_task_attr_t* attr)](#ffrt_task_attr_destroy) | Destroys a task attribute.|
| [FFRT_C_API void ffrt_task_attr_set_qos(ffrt_task_attr_t* attr, ffrt_qos_t qos)](#ffrt_task_attr_set_qos) | Sets the task QoS.|
| [FFRT_C_API ffrt_qos_t ffrt_task_attr_get_qos(const ffrt_task_attr_t* attr)](#ffrt_task_attr_get_qos) | Obtains the task QoS.|
| [FFRT_C_API void ffrt_task_attr_set_delay(ffrt_task_attr_t* attr, uint64_t delay_us)](#ffrt_task_attr_set_delay) | Sets the task delay time.|
| [FFRT_C_API uint64_t ffrt_task_attr_get_delay(const ffrt_task_attr_t* attr)](#ffrt_task_attr_get_delay) | Obtains the task delay time.|
| [FFRT_C_API void ffrt_task_attr_set_queue_priority(ffrt_task_attr_t* attr, ffrt_queue_priority_t priority)](#ffrt_task_attr_set_queue_priority) | Sets the task priority in the queue.|
| [FFRT_C_API ffrt_queue_priority_t ffrt_task_attr_get_queue_priority(const ffrt_task_attr_t* attr)](#ffrt_task_attr_get_queue_priority) | Obtains the task priority in the queue.|
| [FFRT_C_API void ffrt_task_attr_set_stack_size(ffrt_task_attr_t* attr, uint64_t size)](#ffrt_task_attr_set_stack_size) | Sets the task stack size.|
| [FFRT_C_API uint64_t ffrt_task_attr_get_stack_size(const ffrt_task_attr_t* attr)](#ffrt_task_attr_get_stack_size) | Obtains the task stack size.|
| [FFRT_C_API int ffrt_this_task_update_qos(ffrt_qos_t qos)](#ffrt_this_task_update_qos) | Updates the task QoS.|
| [FFRT_C_API ffrt_qos_t ffrt_this_task_get_qos(void)](#ffrt_this_task_get_qos) | Obtains the task QoS.|
| [FFRT_C_API uint64_t ffrt_this_task_get_id(void)](#ffrt_this_task_get_id) | Obtains the ID of this task.|
| [FFRT_C_API void *ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_t kind)](#ffrt_alloc_auto_managed_function_storage_base) | Applies for memory for the task execution function struct.|
| [FFRT_C_API void ffrt_submit_base(ffrt_function_header_t* f, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps,const ffrt_task_attr_t* attr)](#ffrt_submit_base) | Submits a task.|
| [FFRT_C_API ffrt_task_handle_t ffrt_submit_h_base(ffrt_function_header_t* f, const ffrt_deps_t* in_deps,const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)](#ffrt_submit_h_base) | Submits a task, and obtains the task handle.|
| [FFRT_C_API void ffrt_submit_f(ffrt_function_t func, void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps,const ffrt_task_attr_t* attr)](#ffrt_submit_f) | Submits a task. It is a simplified wrapper of **ffrt_submit_base**. This API assumes that the callback function does not need to be destroyed. The task function and parameters are encapsulated into a general task structure, which is then passed to **ffrt_submit_base** along with other parameters.|
| [FFRT_C_API ffrt_task_handle_t ffrt_submit_h_f(ffrt_function_t func, void* arg, const ffrt_deps_t* in_deps,const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)](#ffrt_submit_h_f) | Submits a task, and obtains the task handle. It is a simplified wrapper of **ffrt_submit_h_base**. This API assumes that the callback function does not need to be destroyed. The task function and parameters are encapsulated into a general task structure, which is then passed to **ffrt_submit_h_base** along with other parameters.|
| [FFRT_C_API uint32_t ffrt_task_handle_inc_ref(ffrt_task_handle_t handle)](#ffrt_task_handle_inc_ref) | Increases the number of task handle references.|
| [FFRT_C_API uint32_t ffrt_task_handle_dec_ref(ffrt_task_handle_t handle)](#ffrt_task_handle_dec_ref) | Decreases the number of task handle references.|
| [FFRT_C_API void ffrt_task_handle_destroy(ffrt_task_handle_t handle)](#ffrt_task_handle_destroy) | Destroys a task handle.|
| [FFRT_C_API void ffrt_wait_deps(const ffrt_deps_t* deps)](#ffrt_wait_deps) | Waits until the dependent tasks are complete.|
| [FFRT_C_API void ffrt_wait(void)](#ffrt_wait) | Waits until all submitted tasks are complete.|

## Function Description

### ffrt_task_attr_init()

```
FFRT_C_API int ffrt_task_attr_init(ffrt_task_attr_t* attr)
```

**Description**

Initializes a task attribute.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **0** if the task attribute is initialized;<br>          returns **-1** otherwise.|

### ffrt_task_attr_set_name()

```
FFRT_C_API void ffrt_task_attr_set_name(ffrt_task_attr_t* attr, const char* name)
```

**Description**

Sets a task name.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|
| const char* name | Pointer to the task name.|

### ffrt_task_attr_get_name()

```
FFRT_C_API const char* ffrt_task_attr_get_name(const ffrt_task_attr_t* attr)
```

**Description**

Obtains a task name.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API const char* | Returns a non-null pointer to the task name if the name is obtained;<br>          returns a null pointer otherwise.|

### ffrt_task_attr_destroy()

```
FFRT_C_API void ffrt_task_attr_destroy(ffrt_task_attr_t* attr)
```

**Description**

Destroys a task attribute.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

### ffrt_task_attr_set_qos()

```
FFRT_C_API void ffrt_task_attr_set_qos(ffrt_task_attr_t* attr, ffrt_qos_t qos)
```

**Description**

Sets the task QoS.

**Since**: 10


**Parameters**

| Name                                                    | Description|
|---------------------------------------------------------| -- |
| [ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|
| [ffrt_qos_t](capi-type-def-h.md#variables) qos                | Task QoS.|

### ffrt_task_attr_get_qos()

```
FFRT_C_API ffrt_qos_t ffrt_task_attr_get_qos(const ffrt_task_attr_t* attr)
```

**Description**

Obtains the task QoS.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API [ffrt_qos_t](capi-type-def-h.md#variables)| Returns the QoS, which is **ffrt_qos_default** by default.|

### ffrt_task_attr_set_delay()

```
FFRT_C_API void ffrt_task_attr_set_delay(ffrt_task_attr_t* attr, uint64_t delay_us)
```

**Description**

Sets the task delay time.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|
| uint64_t delay_us | Delay time, in microseconds.|

### ffrt_task_attr_get_delay()

```
FFRT_C_API uint64_t ffrt_task_attr_get_delay(const ffrt_task_attr_t* attr)
```

**Description**

Obtains the task delay time.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API uint64_t | Returns the delay time.|

### ffrt_task_attr_set_queue_priority()

```
FFRT_C_API void ffrt_task_attr_set_queue_priority(ffrt_task_attr_t* attr, ffrt_queue_priority_t priority)
```

**Description**

Sets the task priority in the queue.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|
| [ffrt_queue_priority_t](capi-type-def-h.md#ffrt_queue_priority_t) priority | Task priority.|

### ffrt_task_attr_get_queue_priority()

```
FFRT_C_API ffrt_queue_priority_t ffrt_task_attr_get_queue_priority(const ffrt_task_attr_t* attr)
```

**Description**

Obtains the task priority in the queue.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

**Returns**

| Type                                                     | Description|
|---------------------------------------------------------| -- |
| FFRT_C_API [ffrt_queue_priority_t](capi-type-def-h.md#ffrt_queue_priority_t) | Returns the task priority.|

### ffrt_task_attr_set_stack_size()

```
FFRT_C_API void ffrt_task_attr_set_stack_size(ffrt_task_attr_t* attr, uint64_t size)
```

**Description**

Sets the task stack size.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|
| uint64_t size | Size of the task stack, in bytes.|

### ffrt_task_attr_get_stack_size()

```
FFRT_C_API uint64_t ffrt_task_attr_get_stack_size(const ffrt_task_attr_t* attr)
```

**Description**

Obtains the task stack size.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API uint64_t | Returns the task stack size, in bytes.|

### ffrt_this_task_update_qos()

```
FFRT_C_API int ffrt_this_task_update_qos(ffrt_qos_t qos)
```

**Description**

Updates the task QoS.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_qos_t](capi-type-def-h.md#variables) qos| QoS to be updated.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API int | Returns **0** if the QoS is updated;<br>          returns **-1** otherwise.|

### ffrt_this_task_get_qos()

```
FFRT_C_API ffrt_qos_t ffrt_this_task_get_qos(void)
```

**Description**

Obtains the task QoS.

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API [ffrt_qos_t](capi-type-def-h.md#variables)| Returns the task QoS.|

### ffrt_this_task_get_id()

```
FFRT_C_API uint64_t ffrt_this_task_get_id(void)
```

**Description**

Obtains the ID of this task.

**Since**: 10

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API uint64_t | Returns the ID.|

### ffrt_alloc_auto_managed_function_storage_base()

```
FFRT_C_API void *ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_t kind)
```

**Description**

Applies for memory for the task execution function struct.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_function_kind_t](capi-type-def-h.md#ffrt_function_kind_t) kind | Type of the task execution function, which can be general or queue.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API void * | Returns a non-null pointer if the memory is allocated;<br>          returns a null pointer otherwise.|

### ffrt_submit_base()

```
FFRT_C_API void ffrt_submit_base(ffrt_function_header_t* f, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps,const ffrt_task_attr_t* attr)
```

**Description**

Submits a task.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_function_header_t](capi-ffrt-ffrt-function-header-t.md)* f | Pointer to the task execution function.|
| [const ffrt_deps_t](capi-ffrt-ffrt-deps-t.md)* in_deps | Pointer to the input dependencies.|
| [const ffrt_deps_t](capi-ffrt-ffrt-deps-t.md)* out_deps | Pointer to the output dependencies.|
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

### ffrt_submit_h_base()

```
FFRT_C_API ffrt_task_handle_t ffrt_submit_h_base(ffrt_function_header_t* f, const ffrt_deps_t* in_deps,const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)
```

**Description**

Submits a task, and obtains the task handle.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_function_header_t](capi-ffrt-ffrt-function-header-t.md)* f | Pointer to the task execution function.|
| [const ffrt_deps_t](capi-ffrt-ffrt-deps-t.md)* in_deps | Pointer to the input dependencies.|
| [const ffrt_deps_t](capi-ffrt-ffrt-deps-t.md)* out_deps | Pointer to the output dependencies.|
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

**Returns**

| Type                               | Description|
|-----------------------------------| -- |
| FFRT_C_API [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) | Returns a non-null task handle if the task is submitted;<br>          returns a null pointer otherwise.|

### ffrt_submit_f()

```
FFRT_C_API void ffrt_submit_f(ffrt_function_t func, void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps,const ffrt_task_attr_t* attr)
```

**Description**

Submits a task. It is a simplified wrapper of **ffrt_submit_base**. This API assumes that the callback function does not need to be destroyed. The task function and parameters are encapsulated into a general task structure, which is then passed to **ffrt_submit_base** along with other parameters.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_function_t](capi-type-def-h.md#ffrt_function_t) func | Task function.|
| void* arg | Pointer to the argument.|
| [const ffrt_deps_t](capi-ffrt-ffrt-deps-t.md)* in_deps | Pointer to the input dependencies.|
| [const ffrt_deps_t](capi-ffrt-ffrt-deps-t.md)* out_deps | Pointer to the output dependencies.|
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

**References**

[ffrt_submit_base](capi-task-h.md#ffrt_submit_base)


### ffrt_submit_h_f()

```
FFRT_C_API ffrt_task_handle_t ffrt_submit_h_f(ffrt_function_t func, void* arg, const ffrt_deps_t* in_deps,const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)
```

**Description**

Submits a task, and obtains the task handle. It is a simplified wrapper of **ffrt_submit_h_base**. This API assumes that the callback function does not need to be destroyed. The task function and parameters are encapsulated into a general task structure, which is then passed to **ffrt_submit_h_base** along with other parameters.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_function_t](capi-type-def-h.md#ffrt_function_t) func | Task function.|
| void* arg | Pointer to the argument.|
| [const ffrt_deps_t](capi-ffrt-ffrt-deps-t.md)* in_deps | Pointer to the input dependencies.|
| [const ffrt_deps_t](capi-ffrt-ffrt-deps-t.md)* out_deps | Pointer to the output dependencies.|
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | Pointer to the task attribute.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) | Returns a non-null task handle if the task is submitted;<br>          returns a null pointer otherwise.|

**References**

[ffrt_submit_h_base](capi-task-h.md#ffrt_submit_h_base)


### ffrt_task_handle_inc_ref()

```
FFRT_C_API uint32_t ffrt_task_handle_inc_ref(ffrt_task_handle_t handle)
```

**Description**

Increases the number of task handle references.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) handle | Task handle.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API uint32_t | Returns the original number of task handle references.|

### ffrt_task_handle_dec_ref()

```
FFRT_C_API uint32_t ffrt_task_handle_dec_ref(ffrt_task_handle_t handle)
```

**Description**

Decreases the number of task handle references.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) handle | Task handle.|

**Returns**

| Type| Description|
| -- | -- |
| FFRT_C_API uint32_t | Returns the original number of task handle references.|

### ffrt_task_handle_destroy()

```
FFRT_C_API void ffrt_task_handle_destroy(ffrt_task_handle_t handle)
```

**Description**

Destroys a task handle.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) handle | Task handle.|

### ffrt_wait_deps()

```
FFRT_C_API void ffrt_wait_deps(const ffrt_deps_t* deps)
```

**Description**

Waits until the dependent tasks are complete.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [const ffrt_deps_t](capi-ffrt-ffrt-deps-t.md)* deps | Pointer to the dependencies.|

### ffrt_wait()

```
FFRT_C_API void ffrt_wait(void)
```

**Description**

Waits until all submitted tasks are complete.

**Since**: 10
