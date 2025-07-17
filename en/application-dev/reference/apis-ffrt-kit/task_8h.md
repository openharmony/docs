# task.h


## Overview

The **task.h** file declares the task interfaces in C.

**File to include**: &lt;ffrt/task.h&gt;

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 10

**Related module**: [FFRT](_f_f_r_t.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| FFRT_C_API int [ffrt_task_attr_init](_f_f_r_t.md#ffrt_task_attr_init) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Initializes a task attribute. | 
| FFRT_C_API void [ffrt_task_attr_set_name](_f_f_r_t.md#ffrt_task_attr_set_name) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr, const char \*name) | Sets a task name. | 
| FFRT_C_API const char \* [ffrt_task_attr_get_name](_f_f_r_t.md#ffrt_task_attr_get_name) (const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Obtains a task name. | 
| FFRT_C_API void [ffrt_task_attr_destroy](_f_f_r_t.md#ffrt_task_attr_destroy) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Destroys a task attribute. | 
| FFRT_C_API void [ffrt_task_attr_set_qos](_f_f_r_t.md#ffrt_task_attr_set_qos) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr, [ffrt_qos_t](_f_f_r_t.md#ffrt_qos_t) qos) | Sets the task QoS. | 
| FFRT_C_API [ffrt_qos_t](_f_f_r_t.md#ffrt_qos_t) [ffrt_task_attr_get_qos](_f_f_r_t.md#ffrt_task_attr_get_qos) (const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Obtains the task QoS. | 
| FFRT_C_API void [ffrt_task_attr_set_delay](_f_f_r_t.md#ffrt_task_attr_set_delay) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr, uint64_t delay_us) | Sets the task delay time. | 
| FFRT_C_API uint64_t [ffrt_task_attr_get_delay](_f_f_r_t.md#ffrt_task_attr_get_delay) (const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Obtains the task delay time. | 
| FFRT_C_API void [ffrt_task_attr_set_queue_priority](_f_f_r_t.md#ffrt_task_attr_set_queue_priority) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr, [ffrt_queue_priority_t](_f_f_r_t.md#ffrt_queue_priority_t) priority) | Sets the task priority in the queue. | 
| FFRT_C_API [ffrt_queue_priority_t](_f_f_r_t.md#ffrt_queue_priority_t) [ffrt_task_attr_get_queue_priority](_f_f_r_t.md#ffrt_task_attr_get_queue_priority) (const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Obtains the task priority in the queue. | 
| FFRT_C_API void [ffrt_task_attr_set_stack_size](_f_f_r_t.md#ffrt_task_attr_set_stack_size) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr, uint64_t size) | Sets the task stack size. | 
| FFRT_C_API uint64_t [ffrt_task_attr_get_stack_size](_f_f_r_t.md#ffrt_task_attr_get_stack_size) (const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Obtains the task stack size. | 
| FFRT_C_API int [ffrt_this_task_update_qos](_f_f_r_t.md#ffrt_this_task_update_qos) ([ffrt_qos_t](_f_f_r_t.md#ffrt_qos_t) qos) | Updates the task QoS. | 
| FFRT_C_API [ffrt_qos_t](_f_f_r_t.md#ffrt_qos_t) [ffrt_this_task_get_qos](_f_f_r_t.md#ffrt_this_task_get_qos) (void) | Obtains the task QoS. | 
| FFRT_C_API uint64_t [ffrt_this_task_get_id](_f_f_r_t.md#ffrt_this_task_get_id) (void) | Obtains the ID of this task. | 
| FFRT_C_API void \* [ffrt_alloc_auto_managed_function_storage_base](_f_f_r_t.md#ffrt_alloc_auto_managed_function_storage_base) ([ffrt_function_kind_t](_f_f_r_t.md#ffrt_function_kind_t) kind) | Applies for memory for the function execution structure. | 
| FFRT_C_API void [ffrt_submit_base](_f_f_r_t.md#ffrt_submit_base) ([ffrt_function_header_t](ffrt__function__header__t.md) \*f, const [ffrt_deps_t](ffrt__deps__t.md) \*in_deps, const [ffrt_deps_t](ffrt__deps__t.md) \*out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task. | 
| FFRT_C_API [ffrt_task_handle_t](_f_f_r_t.md#ffrt_task_handle_t) [ffrt_submit_h_base](_f_f_r_t.md#ffrt_submit_h_base) ([ffrt_function_header_t](ffrt__function__header__t.md) \*f, const [ffrt_deps_t](ffrt__deps__t.md) \*in_deps, const [ffrt_deps_t](ffrt__deps__t.md) \*out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task, and obtains the task handle. | 
| FFRT_C_API void [ffrt_submit_f](_f_f_r_t.md#ffrt_submit_f) ([ffrt_function_t](_f_f_r_t.md#ffrt_function_t) func, void \*arg, const [ffrt_deps_t](ffrt__deps__t.md) \*in_deps, const [ffrt_deps_t](ffrt__deps__t.md) \*out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task. It is a simplified form of **ffrt_submit_base**. | 
| FFRT_C_API [ffrt_task_handle_t](_f_f_r_t.md#ffrt_task_handle_t)[ffrt_submit_h_f](_f_f_r_t.md#ffrt_submit_h_f) ([ffrt_function_t](_f_f_r_t.md#ffrt_function_t) func, void \*arg, const [ffrt_deps_t](ffrt__deps__t.md) \*in_deps, const [ffrt_deps_t](ffrt__deps__t.md) \*out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task, and obtains the task handle. It is a simplified form of **ffrt_submit_h_base**. | 
| FFRT_C_API uint32_t [ffrt_task_handle_inc_ref](_f_f_r_t.md#ffrt_task_handle_inc_ref) ([ffrt_task_handle_t](_f_f_r_t.md#ffrt_task_handle_t) handle) | Increases the number of task handle references. | 
| FFRT_C_API uint32_t [ffrt_task_handle_dec_ref](_f_f_r_t.md#ffrt_task_handle_dec_ref) ([ffrt_task_handle_t](_f_f_r_t.md#ffrt_task_handle_t) handle) | Decreases the number of task handle references. | 
| FFRT_C_API void [ffrt_task_handle_destroy](_f_f_r_t.md#ffrt_task_handle_destroy) ([ffrt_task_handle_t](_f_f_r_t.md#ffrt_task_handle_t) handle) | Destroys a task handle. | 
| FFRT_C_API void [ffrt_wait_deps](_f_f_r_t.md#ffrt_wait_deps) (const [ffrt_deps_t](ffrt__deps__t.md) \*deps) | Waits until the dependent tasks are complete. | 
| FFRT_C_API void [ffrt_wait](_f_f_r_t.md#ffrt_wait) (void) | Waits until all submitted tasks are complete. | 
