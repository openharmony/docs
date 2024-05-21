# type_def.h


## 概述

定义通用类型。

**起始版本：** 10

**相关模块：**[FFRT](_f_f_r_t.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ffrt_function_header_t](ffrt__function__header__t.md) | 任务执行体。 | 
| struct&nbsp;&nbsp;[ffrt_dependence_t](ffrt__dependence__t.md) | 依赖数据结构。 | 
| struct&nbsp;&nbsp;[ffrt_deps_t](ffrt__deps__t.md) | 依赖结构定义。 | 
| struct&nbsp;&nbsp;[ffrt_task_attr_t](ffrt__task__attr__t.md) | 并行任务属性结构。 | 
| struct&nbsp;&nbsp;[ffrt_queue_attr_t](ffrt__queue__attr__t.md) | 串行队列属性结构。 | 
| struct&nbsp;&nbsp;[ffrt_condattr_t](ffrt__condattr__t.md) | FFRT条件变量属性结构。 | 
| struct&nbsp;&nbsp;[ffrt_mutexattr_t](ffrt__mutexattr__t.md) | FFRT锁属性结构。 | 
| struct&nbsp;&nbsp;[ffrt_mutex_t](ffrt__mutex__t.md) | FFRT互斥锁结构。 | 
| struct&nbsp;&nbsp;[ffrt_cond_t](ffrt__cond__t.md) | FFRT条件变量结构。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef int [ffrt_qos_t](_f_f_r_t.md) | qos类型。 | 
| typedef void(\*[ffrt_function_t](_f_f_r_t.md)) (void\* ) | 任务执行函数指针类型。 | 
| typedef void\*&nbsp;&nbsp;[ffrt_task_handle_t](_f_f_r_t.md) | 并行任务句柄。 | 
| typedef void(\*[ffrt_poller_cb](_f_f_r_t.md#ffrt_poller_cb)) (void\* data, uint32_t event) |  | 
| typedef void(\*[ffrt_timer_cb](_f_f_r_t.md#ffrt_timer_cb)) (void\* data) |  | 
| typedef int [ffrt_timer_t](_f_f_r_t.md#ffrt_timer_t) |  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ffrt_task_priority_t](_f_f_r_t.md#ffrt_task_priority_t) { [ffrt_task_priority_immediate](_f_f_r_t.md) = 0, [ffrt_task_priority_high](_f_f_r_t.md) = 1, [ffrt_task_priority_low](_f_f_r_t.md) = 2, [ffrt_task_priority_idle](_f_f_r_t.md) } | 任务的优先级类型。 | 
| [ffrt_qos_default_t](_f_f_r_t.md#ffrt_qos_default_t) {<br/>[ffrt_qos_inherit](_f_f_r_t.md) = -1, [ffrt_qos_background](_f_f_r_t.md), [ffrt_qos_utility](_f_f_r_t.md), [ffrt_qos_default](_f_f_r_t.md),<br/>[ffrt_qos_user_initiated](_f_f_r_t.md)<br/>} | 任务的qos类型。 | 
| [ffrt_storage_size_t](_f_f_r_t.md#ffrt_storage_size_t) {<br/>[ffrt_task_attr_storage_size](_f_f_r_t.md) = 128, [ffrt_auto_managed_function_storage_size](_f_f_r_t.md) = 64 + sizeof(ffrt_function_header_t), [ffrt_mutex_storage_size](_f_f_r_t.md) = 64, [ffrt_cond_storage_size](_f_f_r_t.md) = 64,<br/>[ffrt_queue_attr_storage_size](_f_f_r_t.md) = 128<br/>} | 多种类型数据结构分配大小定义。 | 
| [ffrt_function_kind_t](_f_f_r_t.md#ffrt_function_kind_t) { [ffrt_function_kind_general](_f_f_r_t.md), [ffrt_function_kind_queue](_f_f_r_t.md) } | 任务类型。 | 
| [ffrt_dependence_type_t](_f_f_r_t.md#ffrt_dependence_type_t) { [ffrt_dependence_data](_f_f_r_t.md), [ffrt_dependence_task](_f_f_r_t.md) } | 依赖类型。 | 
| [ffrt_error_t](_f_f_r_t.md#ffrt_error_t) {<br/>[ffrt_error](_f_f_r_t.md) = -1, [ffrt_success](_f_f_r_t.md) = 0, [ffrt_error_nomem](_f_f_r_t.md) = ENOMEM, [ffrt_error_timedout](_f_f_r_t.md) = ETIMEDOUT,<br/>[ffrt_error_busy](_f_f_r_t.md) = EBUSY, [ffrt_error_inval](_f_f_r_t.md) = EINVAL<br/>} | FFRT错误码。 | 
