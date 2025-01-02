# type_def.h


## Overview

The **type_def.h** file declares the common types.

**Since**: 10

**Related module**: [FFRT](_f_f_r_t.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[ffrt_function_header_t](ffrt__function__header__t.md) | Describes a task execution function.| 
| struct&nbsp;&nbsp;[ffrt_dependence_t](ffrt__dependence__t.md) | Describes dependency data.| 
| struct&nbsp;&nbsp;[ffrt_deps_t](ffrt__deps__t.md) | Describes dependencies.| 
| struct&nbsp;&nbsp;[ffrt_task_attr_t](ffrt__task__attr__t.md) | Describes a task attribute.| 
| struct&nbsp;&nbsp;[ffrt_queue_attr_t](ffrt__queue__attr__t.md) | Describes a queue attribute.| 
| struct&nbsp;&nbsp;[ffrt_condattr_t](ffrt__condattr__t.md) | Describes a condition variable attribute.| 
| struct&nbsp;&nbsp;[ffrt_mutexattr_t](ffrt__mutexattr__t.md) | Describes a mutex attribute.| 
| struct&nbsp;&nbsp;[ffrt_mutex_t](ffrt__mutex__t.md) | Describes a mutex.| 
| struct&nbsp;&nbsp;[ffrt_cond_t](ffrt__cond__t.md) | Describes a condition variable.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef int [ffrt_qos_t](_f_f_r_t.md) | Defines the QoS type.| 
| typedef void(\*[ffrt_function_t](_f_f_r_t.md)) (void\* ) | Defines the type of the pointer to a task execution function.| 
| typedef void\*&nbsp;&nbsp;[ffrt_task_handle_t](_f_f_r_t.md) | Defines the handle to a task.| 
| typedef void(\*[ffrt_poller_cb](_f_f_r_t.md#ffrt_poller_cb)) (void\* data, uint32_t event) |  | 
| typedef void(\*[ffrt_timer_cb](_f_f_r_t.md#ffrt_timer_cb)) (void\* data) |  | 
| typedef int [ffrt_timer_t](_f_f_r_t.md#ffrt_timer_t) |  | 


### Enums

| Name| Description| 
| -------- | -------- |
| [ffrt_task_priority_t](_f_f_r_t.md#ffrt_task_priority_t) { [ffrt_task_priority_immediate](_f_f_r_t.md) = 0, [ffrt_task_priority_high](_f_f_r_t.md) = 1, [ffrt_task_priority_low](_f_f_r_t.md) = 2, [ffrt_task_priority_idle](_f_f_r_t.md) } | Enumerates the task priority types.| 
| [ffrt_qos_default_t](_f_f_r_t.md#ffrt_qos_default_t) {<br>[ffrt_qos_inherit](_f_f_r_t.md) = -1, [ffrt_qos_background](_f_f_r_t.md), [ffrt_qos_utility](_f_f_r_t.md), [ffrt_qos_default](_f_f_r_t.md),<br>[ffrt_qos_user_initiated](_f_f_r_t.md)<br>} | Enumerates the task QoS types.| 
| [ffrt_storage_size_t](_f_f_r_t.md#ffrt_storage_size_t) {<br>[ffrt_task_attr_storage_size](_f_f_r_t.md) = 128, [ffrt_auto_managed_function_storage_size](_f_f_r_t.md) = 64 + sizeof(ffrt_function_header_t), [ffrt_mutex_storage_size](_f_f_r_t.md) = 64, [ffrt_cond_storage_size](_f_f_r_t.md) = 64,<br>[ffrt_queue_attr_storage_size](_f_f_r_t.md) = 128<br>} | Enumerates the storage sizes available for different types of structs.| 
| [ffrt_function_kind_t](_f_f_r_t.md#ffrt_function_kind_t) { [ffrt_function_kind_general](_f_f_r_t.md), [ffrt_function_kind_queue](_f_f_r_t.md) } | Enumerates the task types.| 
| [ffrt_dependence_type_t](_f_f_r_t.md#ffrt_dependence_type_t) { [ffrt_dependence_data](_f_f_r_t.md), [ffrt_dependence_task](_f_f_r_t.md) } | Enumerates the dependency types.| 
| [ffrt_error_t](_f_f_r_t.md#ffrt_error_t) {<br>[ffrt_error](_f_f_r_t.md) = -1, [ffrt_success](_f_f_r_t.md) = 0, [ffrt_error_nomem](_f_f_r_t.md) = ENOMEM, [ffrt_error_timedout](_f_f_r_t.md) = ETIMEDOUT,<br>[ffrt_error_busy](_f_f_r_t.md) = EBUSY, [ffrt_error_inval](_f_f_r_t.md) = EINVAL<br>} | Enumerates the FFRT error codes.| 
