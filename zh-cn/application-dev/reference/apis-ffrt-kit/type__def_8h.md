# type_def.h


## 概述

定义通用类型。

**引用文件：**&lt;ffrt/type_def.h&gt;

**库：** libffrt.z.so 

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 10

**相关模块：**[FFRT](_f_f_r_t.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ffrt_function_header_t](ffrt__function__header__t.md) | 任务执行体。  | 
| struct&nbsp;&nbsp;[ffrt_dependence_t](ffrt__dependence__t.md) | 依赖数据结构。  | 
| struct&nbsp;&nbsp;[ffrt_deps_t](ffrt__deps__t.md) | 依赖结构定义。  | 
| struct&nbsp;&nbsp;[ffrt_task_attr_t](ffrt__task__attr__t.md) | 并行任务属性结构。  | 
| struct&nbsp;&nbsp;[ffrt_queue_attr_t](ffrt__queue__attr__t.md) | 串行队列属性结构。  | 
| struct&nbsp;&nbsp;[ffrt_condattr_t](ffrt__condattr__t.md) | FFRT条件变量属性结构。  | 
| struct&nbsp;&nbsp;[ffrt_mutexattr_t](ffrt__mutexattr__t.md) | FFRT锁属性结构。  | 
| struct&nbsp;&nbsp;[ffrt_rwlockattr_t](ffrt__rwlockattr__t.md) | FFRT读写锁属性结构。  | 
| struct&nbsp;&nbsp;[ffrt_mutex_t](ffrt__mutex__t.md) | FFRT互斥锁结构。  | 
| struct&nbsp;&nbsp;[ffrt_rwlock_t](ffrt__rwlock__t.md) | FFRT读写锁结构。  | 
| struct&nbsp;&nbsp;[ffrt_cond_t](ffrt__cond__t.md) | FFRT条件变量结构。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef int [ffrt_qos_t](_f_f_r_t.md#ffrt_qos_t) | QoS类型。  | 
| typedef void(\* [ffrt_function_t](_f_f_r_t.md#ffrt_function_t)) (void \*) | 任务执行函数指针类型。  | 
| typedef void \* [ffrt_task_handle_t](_f_f_r_t.md#ffrt_task_handle_t) | 并行任务句柄。  | 
| typedef void(\* [ffrt_poller_cb](_f_f_r_t.md#ffrt_poller_cb)) (void \*data, uint32_t event) | poller回调函数定义。  | 
| typedef void(\* [ffrt_timer_cb](_f_f_r_t.md#ffrt_timer_cb)) (void \*data) | timer回调函数定义。  | 
| typedef int [ffrt_timer_t](_f_f_r_t.md#ffrt_timer_t) | 定时器句柄。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ffrt_queue_priority_t](_f_f_r_t.md#ffrt_queue_priority_t) {<br/>ffrt_queue_priority_immediate = 0, <br/>ffrt_queue_priority_high, <br/>ffrt_queue_priority_low, ffrt_queue_priority_idle<br/>} | 任务的优先级类型。  | 
| [ffrt_qos_default_t](_f_f_r_t.md#ffrt_qos_default_t) {<br/>ffrt_qos_inherit = -1, <br/>ffrt_qos_background, ffrt_qos_utility, <br/>ffrt_qos_default,<br/>ffrt_qos_user_initiated<br/>} | 任务的QoS类型。  | 
| [ffrt_storage_size_t](_f_f_r_t.md#ffrt_storage_size_t) {<br/>ffrt_task_attr_storage_size = 128, <br/>ffrt_auto_managed_function_storage_size = 64 + sizeof(ffrt_function_header_t), <br/>ffrt_mutex_storage_size = 64, <br/>ffrt_cond_storage_size = 64,<br/>ffrt_queue_attr_storage_size = 128<br/>} | 多种类型数据结构分配大小定义。  | 
| [ffrt_function_kind_t](_f_f_r_t.md#ffrt_function_kind_t) { <br/>ffrt_function_kind_general, <br/>ffrt_function_kind_queue<br/> } | 任务类型。  | 
| [ffrt_dependence_type_t](_f_f_r_t.md#ffrt_dependence_type_t) { <br/>ffrt_dependence_data, <br/>ffrt_dependence_task<br/> } | 依赖类型。  |
| [ffrt_error_t](_f_f_r_t.md#ffrt_error_t) {<br/>ffrt_error = -1, <br/>ffrt_success = 0, <br/>ffrt_error_nomem = ENOMEM, <br/>ffrt_error_timedout = ETIMEDOUT,<br/>ffrt_error_busy = EBUSY, <br/>ffrt_error_inval = EINVAL<br/>} | FFRT错误码。  | 
| [ffrt_mutex_type](_f_f_r_t.md#ffrt_mutex_type) {<br/>ffrt_mutex_normal = 0, <br/>ffrt_mutex_recursive = 2, <br/>ffrt_mutex_default = ffrt_mutex_normal <br/>} | 互斥锁类型枚举。  | 
