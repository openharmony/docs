# type_def.h


## Overview

The **type_def.h** file declares the common types.

**File to include**: &lt;ffrt/type_def.h&gt;

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 10

**Related module**: [FFRT](_f_f_r_t.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[ffrt_function_header_t](ffrt__function__header__t.md) | Describes a task execution function. | 
| struct&nbsp;&nbsp;[ffrt_dependence_t](ffrt__dependence__t.md) | Describes dependency data. | 
| struct&nbsp;&nbsp;[ffrt_deps_t](ffrt__deps__t.md) | Describes dependencies. | 
| struct&nbsp;&nbsp;[ffrt_task_attr_t](ffrt__task__attr__t.md) | Describes a task attribute. | 
| struct&nbsp;&nbsp;[ffrt_queue_attr_t](ffrt__queue__attr__t.md) | Describes a queue attribute. | 
| struct&nbsp;&nbsp;[ffrt_condattr_t](ffrt__condattr__t.md) | Describes a condition variable attribute. | 
| struct&nbsp;&nbsp;[ffrt_mutexattr_t](ffrt__mutexattr__t.md) | Describes a mutex attribute. | 
| struct&nbsp;&nbsp;[ffrt_rwlockattr_t](ffrt__rwlockattr__t.md) | Describes a read-write lock attribute. | 
| struct&nbsp;&nbsp;[ffrt_mutex_t](ffrt__mutex__t.md) | Describes a mutex. | 
| struct&nbsp;&nbsp;[ffrt_rwlock_t](ffrt__rwlock__t.md) | Describes a read-write lock. | 
| struct&nbsp;&nbsp;[ffrt_cond_t](ffrt__cond__t.md) | Describes a condition variable. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef int [ffrt_qos_t](_f_f_r_t.md#ffrt_qos_t) | QoS type. | 
| typedef void(\* [ffrt_function_t](_f_f_r_t.md#ffrt_function_t)) (void \*) | Defines the type of the pointer to a task execution function. | 
| typedef void \* [ffrt_task_handle_t](_f_f_r_t.md#ffrt_task_handle_t) | Defines the handle to a task. | 
| typedef void(\* [ffrt_poller_cb](_f_f_r_t.md#ffrt_poller_cb)) (void \*data, uint32_t event) | The poller callback function definition. | 
| typedef void(\* [ffrt_timer_cb](_f_f_r_t.md#ffrt_timer_cb)) (void \*data) | The timer callback function definition. | 
| typedef int [ffrt_timer_t](_f_f_r_t.md#ffrt_timer_t) | Handle to the timer. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [ffrt_queue_priority_t](_f_f_r_t.md#ffrt_queue_priority_t) {<br>ffrt_queue_priority_immediate = 0, <br>ffrt_queue_priority_high, <br>ffrt_queue_priority_low, ffrt_queue_priority_idle<br>} | Enumerates the task priority types. | 
| [ffrt_qos_default_t](_f_f_r_t.md#ffrt_qos_default_t) {<br>ffrt_qos_inherit = -1, <br>ffrt_qos_background, ffrt_qos_utility, <br>ffrt_qos_default,<br>ffrt_qos_user_initiated<br>} | Enumerates the task QoS types. | 
| [ffrt_storage_size_t](_f_f_r_t.md#ffrt_storage_size_t) {<br>ffrt_task_attr_storage_size = 128, <br>ffrt_auto_managed_function_storage_size = 64 + sizeof(ffrt_function_header_t), <br>ffrt_mutex_storage_size = 64, <br>ffrt_cond_storage_size = 64,<br>ffrt_queue_attr_storage_size = 128<br>} | Enumerates the storage sizes available for different types of structs. | 
| [ffrt_function_kind_t](_f_f_r_t.md#ffrt_function_kind_t) { <br>ffrt_function_kind_general, <br>ffrt_function_kind_queue<br> } | Enumerates the task types. | 
| [ffrt_dependence_type_t](_f_f_r_t.md#ffrt_dependence_type_t) { <br>ffrt_dependence_data, <br>ffrt_dependence_task<br> } | Enumerates the dependency types. |
| [ffrt_error_t](_f_f_r_t.md#ffrt_error_t) {<br>ffrt_error = -1, <br>ffrt_success = 0, <br>ffrt_error_nomem = ENOMEM, <br>ffrt_error_timedout = ETIMEDOUT,<br>ffrt_error_busy = EBUSY, <br>ffrt_error_inval = EINVAL<br>} | Enumerates the FFRT error codes. | 
| [ffrt_mutex_type](_f_f_r_t.md#ffrt_mutex_type) {<br>ffrt_mutex_normal = 0, <br>ffrt_mutex_recursive = 2, <br>ffrt_mutex_default = ffrt_mutex_normal <br>} | Enumerates the mutex types. | 
