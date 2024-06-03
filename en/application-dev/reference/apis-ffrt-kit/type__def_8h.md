# type_def.h


## Overview

The **type_def.h** file declares the common types.

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
| struct&nbsp;&nbsp;[ffrt_mutex_t](ffrt__mutex__t.md) | Describes a mutex. | 
| struct&nbsp;&nbsp;[ffrt_cond_t](ffrt__cond__t.md) | Describes a condition variable. | 


### Types

| Name| Description| 
| -------- | -------- |
|  typedef int [ffrt_qos_t] (_f_f_r_t.md#types)| Defines the QoS type. | 
|  typedef void(\*[ffrt_function_t] (_f_f_r_t.md#types))(void\*)| Defines the type of the pointer to a task execution function. | 
|  typedef void\* [ffrt_task_handle_t] (_f_f_r_t.md#types)| Defines the handle to a task. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [ffrt_qos_default_t](_f_f_r_t.md#ffrt_qos_default_t) {<br>ffrt_qos_inherit = -1, <br>ffrt_qos_background, <br>ffrt_qos_utility, <br>ffrt_qos_default,<br>ffrt_qos_user_initiated<br>} | Enumerates the task QoS types. | 
| [ffrt_storage_size_t](_f_f_r_t.md#ffrt_storage_size_t) {<br>ffrt_task_attr_storage_size = 128, <br>ffrt_auto_managed_function_storage_size = 64 + sizeof(ffrt_function_header_t), <br>ffrt_mutex_storage_size = 64, <br>ffrt_cond_storage_size = 64,<br>ffrt_queue_attr_storage_size = 128<br>} | Enumerates the storage sizes available for different types of structs. | 
| [ffrt_function_kind_t](_f_f_r_t.md#ffrt_function_kind_t) { ffrt_function_kind_general, ffrt_function_kind_queue } | Enumerates the task types. | 
| [ffrt_dependence_type_t](_f_f_r_t.md#ffrt_dependence_type_t) { ffrt_dependence_data, ffrt_dependence_task } | Enumerates the dependency types. | 
| [ffrt_error_t](_f_f_r_t.md#ffrt_error_t) {<br>ffrt_error = -1, <br>ffrt_success = 0, <br>ffrt_error_nomem = ENOMEM, <br>ffrt_error_timedout = ETIMEDOUT,<br>ffrt_error_busy = EBUSY, <br>ffrt_error_inval = EINVAL<br>} | Enumerates the FFRT error codes. | 
