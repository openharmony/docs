# task.h


## 概述

声明任务提供的C接口。

**起始版本：** 10

**相关模块：**[FFRT](_f_f_r_t.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| FFRT_C_API int [ffrt_task_attr_init](_f_f_r_t.md#ffrt_task_attr_init) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 初始化任务属性。  | 
| FFRT_C_API void [ffrt_task_attr_set_name](_f_f_r_t.md#ffrt_task_attr_set_name) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr, const char\* name) | 设置任务名字。  | 
| FFRT_C_API const char\*&nbsp;&nbsp;[ffrt_task_attr_get_name](_f_f_r_t.md#ffrt_task_attr_get_name) (const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 获取任务名字。  | 
| FFRT_C_API void [ffrt_task_attr_destroy](_f_f_r_t.md#ffrt_task_attr_destroy) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 销毁任务属性。  | 
| FFRT_C_API void [ffrt_task_attr_set_qos](_f_f_r_t.md#ffrt_task_attr_set_qos) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr, [ffrt_qos_t](_f_f_r_t.md) qos) | 设置任务qos。  | 
| FFRT_C_API [ffrt_qos_t](_f_f_r_t.md)[ffrt_task_attr_get_qos](_f_f_r_t.md#ffrt_task_attr_get_qos) (const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 获取任务qos。  | 
| FFRT_C_API void [ffrt_task_attr_set_delay](_f_f_r_t.md#ffrt_task_attr_set_delay) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr, uint64_t delay_us) | 设置任务延迟时间。  | 
| FFRT_C_API uint64_t [ffrt_task_attr_get_delay](_f_f_r_t.md#ffrt_task_attr_get_delay) (const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 获取任务延迟时间。  | 
| FFRT_C_API void [ffrt_task_attr_set_queue_priority](_f_f_r_t.md#ffrt_task_attr_set_queue_priority) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr, ffrt_queue_priority_t priority) | 设置并行队列任务优先级。  | 
| FFRT_C_API ffrt_queue_priority_t [ffrt_task_attr_get_queue_priority](_f_f_r_t.md#ffrt_task_attr_get_queue_priority) (const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 获取并行队列任务优先级。  | 
| FFRT_C_API int [ffrt_this_task_update_qos](_f_f_r_t.md#ffrt_this_task_update_qos) ([ffrt_qos_t](_f_f_r_t.md) qos) | 更新任务qos。  | 
| FFRT_C_API [ffrt_qos_t](_f_f_r_t.md)[ffrt_this_task_get_qos](_f_f_r_t.md#ffrt_this_task_get_qos) () | 获取任务qos。  | 
| FFRT_C_API uint64_t [ffrt_this_task_get_id](_f_f_r_t.md#ffrt_this_task_get_id) (void) | 获取任务id。  | 
| FFRT_C_API void\*&nbsp;&nbsp;[ffrt_alloc_auto_managed_function_storage_base](_f_f_r_t.md#ffrt_alloc_auto_managed_function_storage_base) ([ffrt_function_kind_t](_f_f_r_t.md#ffrt_function_kind_t) kind) | 申请函数执行结构的内存。  | 
| FFRT_C_API void [ffrt_submit_base](_f_f_r_t.md#ffrt_submit_base) ([ffrt_function_header_t](ffrt__function__header__t.md)\* f, const [ffrt_deps_t](ffrt__deps__t.md)\* in_deps, const [ffrt_deps_t](ffrt__deps__t.md)\* out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 提交任务调度执行。  | 
| FFRT_C_API [ffrt_task_handle_t](_f_f_r_t.md)[ffrt_submit_h_base](_f_f_r_t.md#ffrt_submit_h_base) ([ffrt_function_header_t](ffrt__function__header__t.md)\* f, const [ffrt_deps_t](ffrt__deps__t.md)\* in_deps, const [ffrt_deps_t](ffrt__deps__t.md)\* out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 提交任务调度执行并返回任务句柄。  | 
| FFRT_C_API void [ffrt_task_handle_destroy](_f_f_r_t.md#ffrt_task_handle_destroy) ([ffrt_task_handle_t](_f_f_r_t.md) handle) | 销毁任务句柄。  | 
| FFRT_C_API void [ffrt_wait_deps](_f_f_r_t.md#ffrt_wait_deps) (const [ffrt_deps_t](ffrt__deps__t.md)\* deps) | 等待依赖的任务完成，当前任务开始执行。  | 
| FFRT_C_API void [ffrt_wait](_f_f_r_t.md#ffrt_wait) (void) | 等待之前所有提交任务完成，当前任务开始执行。  | 
