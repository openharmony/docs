# FFRT


## 概述

FFRT（Function Flow运行时）是支持Function Flow编程模型的软件运行时库，用于调度执行开发者基于Function Flow编程模型开发的应用。

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [condition_variable.h](condition__variable_8h.md) | 声明条件变量提供的C接口。 | 
| [loop.h](loop_8h.md) | 声明FFRT LOOP机制的C接口。 | 
| [mutex.h](mutex_8h.md) | 声明mutex提供的C接口。 | 
| [queue.h](queue_8h.md) | 声明串行队列提供的C接口。 | 
| [sleep.h](sleep_8h.md) | 声明sleep和yield C接口。 | 
| [task.h](task_8h.md) | 声明任务提供的C接口。 | 
| [timer.h](timer_8h.md) | 声明定时器的C接口。 | 
| [type_def.h](type__def_8h.md) | 定义通用类型。 | 


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
| typedef void\*&nbsp;&nbsp;**ffrt_loop_t** |  | 
| typedef void\*&nbsp;&nbsp;ffrt_queue_t | 队列句柄。 | 
| typedef int ffrt_qos_t | qos类型。 | 
| typedef void(\*ffrt_function_t ) (void\*) | 任务执行函数指针类型。 | 
| typedef void\*&nbsp;&nbsp;ffrt_task_handle_t | 并行任务句柄。 | 
| typedef void (\*[ffrt_poller_cb](#ffrt_poller_cb)) (void\* data, uint32_t event) | ffrt_poller_cb callback定义 | 
| typedef void (\*[ffrt_timer_cb](#ffrt_timer_cb)) (void\* data) | ffrt_timer_cb callback定义 | 
| typedef int [ffrt_timer_t](#ffrt_timer_t) | ffrt_timer_t 类型定义 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ffrt_queue_type_t](#ffrt_queue_type_t) { ffrt_queue_serial = 0, ffrt_queue_concurrent, ffrt_queue_max } | 队列类型。 | 
| [ffrt_task_priority_t](#ffrt_task_priority_t) { ffrt_task_priority_immediate = 0, ffrt_task_priority_high = 1, ffrt_task_priority_low = 2, ffrt_task_priority_idle } | 任务的优先级类型。 | 
| [ffrt_qos_default_t](#ffrt_qos_default_t) {<br/>ffrt_qos_inherit = -1, ffrt_qos_background, ffrt_qos_utility, ffrt_qos_default,<br/>ffrt_qos_user_initiated<br/>} | 任务的qos类型。 | 
| [ffrt_storage_size_t](#ffrt_storage_size_t) {<br/>ffrt_task_attr_storage_size = 128, ffrt_auto_managed_function_storage_size = 64 + sizeof(ffrt_function_header_t), ffrt_mutex_storage_size = 64, ffrt_cond_storage_size = 64,<br/>ffrt_queue_attr_storage_size = 128<br/>} | 多种类型数据结构分配大小定义。 | 
| [ffrt_function_kind_t](#ffrt_function_kind_t) { ffrt_function_kind_general, ffrt_function_kind_queue } | 任务类型。 | 
| [ffrt_dependence_type_t](#ffrt_dependence_type_t) { ffrt_dependence_data, ffrt_dependence_task } | 依赖类型。 | 
| [ffrt_error_t](#ffrt_error_t) {<br/>ffrt_error = -1, ffrt_success = 0, ffrt_error_nomem = ENOMEM, ffrt_error_timedout = ETIMEDOUT,<br/>ffrt_error_busy = EBUSY, ffrt_error_inval = EINVAL<br/>} | FFRT错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| FFRT_C_API int [ffrt_cond_init](#ffrt_cond_init) ([ffrt_cond_t](ffrt__cond__t.md)\* cond, const [ffrt_condattr_t](ffrt__condattr__t.md)\* attr) | 初始化条件变量。 | 
| FFRT_C_API int [ffrt_cond_signal](#ffrt_cond_signal) ([ffrt_cond_t](ffrt__cond__t.md)\* cond) | 唤醒阻塞在条件变量上的一个任务。 | 
| FFRT_C_API int [ffrt_cond_broadcast](#ffrt_cond_broadcast) ([ffrt_cond_t](ffrt__cond__t.md)\* cond) | 唤醒阻塞在条件变量上的所有任务。 | 
| FFRT_C_API int [ffrt_cond_wait](#ffrt_cond_wait) ([ffrt_cond_t](ffrt__cond__t.md)\* cond, [ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | 条件变量等待函数，条件变量不满足时阻塞当前任务。 | 
| FFRT_C_API int [ffrt_cond_timedwait](#ffrt_cond_timedwait) ([ffrt_cond_t](ffrt__cond__t.md)\* cond, [ffrt_mutex_t](ffrt__mutex__t.md)\* mutex, const struct timespec\* time_point) | 条件变量超时等待函数，条件变量不满足时阻塞当前任务，超时等待返回. | 
| FFRT_C_API int [ffrt_cond_destroy](#ffrt_cond_destroy) ([ffrt_cond_t](ffrt__cond__t.md)\* cond) | 销毁条件变量。 | 
| FFRT_C_API ffrt_loop_t [ffrt_loop_create](#ffrt_loop_create) (ffrt_queue_t queue) | 创建loop队列。 | 
| FFRT_C_API int [ffrt_loop_destory](#ffrt_loop_destory) (ffrt_loop_t loop) | 销毁loop队对象。 | 
| FFRT_C_API int [ffrt_loop_run](#ffrt_loop_run) (ffrt_loop_t loop) | 开启loop循环。 | 
| FFRT_C_API void [ffrt_loop_stop](#ffrt_loop_stop) (ffrt_loop_t loop) | 停止loop循环。 | 
| FFRT_C_API int [ffrt_loop_epoll_ctl](#ffrt_loop_epoll_ctl) (ffrt_loop_t loop, int op, int fd, uint32_t events, void\* data, [ffrt_poller_cb](#ffrt_poller_cb) cb) | 管理loop上的监听事件。 | 
| FFRT_C_API [ffrt_timer_t](#ffrt_timer_t)[ffrt_loop_timer_start](#ffrt_loop_timer_start) (ffrt_loop_t loop, uint64_t timeout, void\* data, [ffrt_timer_cb](#ffrt_timer_cb) cb, bool repeat) | 在ffrt loop上启动定时器。 | 
| FFRT_C_API int [ffrt_loop_timer_stop](#ffrt_loop_timer_stop) (ffrt_loop_t loop, [ffrt_timer_t](#ffrt_timer_t) handle) | 停止ffrt loop定时器。 | 
| FFRT_C_API int [ffrt_mutex_init](#ffrt_mutex_init) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex, const [ffrt_mutexattr_t](ffrt__mutexattr__t.md)\* attr) | 初始化mutex。 | 
| FFRT_C_API int [ffrt_mutex_lock](#ffrt_mutex_lock) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | 获取mutex。 | 
| FFRT_C_API int [ffrt_mutex_unlock](#ffrt_mutex_unlock) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | 释放mutex。 | 
| FFRT_C_API int [ffrt_mutex_trylock](#ffrt_mutex_trylock) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | 尝试获取mutex。 | 
| FFRT_C_API int [ffrt_mutex_destroy](#ffrt_mutex_destroy) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | 销毁mutex。 | 
| FFRT_C_API int [ffrt_queue_attr_init](#ffrt_queue_attr_init) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | 初始化串行队列属性。 | 
| FFRT_C_API void [ffrt_queue_attr_destroy](#ffrt_queue_attr_destroy) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | 销毁串行队列属性。 | 
| FFRT_C_API void [ffrt_queue_attr_set_qos](#ffrt_queue_attr_set_qos) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr, ffrt_qos_t qos) | 设置串行队列qos属性。 | 
| FFRT_C_API ffrt_qos_t[ffrt_queue_attr_get_qos](#ffrt_queue_attr_get_qos) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | 获取串行队列qos属性。 | 
| FFRT_C_API void [ffrt_queue_attr_set_timeout](#ffrt_queue_attr_set_timeout) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr, uint64_t timeout_us) | 设置串行队列timeout属性。 | 
| FFRT_C_API uint64_t [ffrt_queue_attr_get_timeout](#ffrt_queue_attr_get_timeout) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | 获取串行队列任务执行的timeout时间。 | 
| FFRT_C_API void [ffrt_queue_attr_set_callback](#ffrt_queue_attr_set_callback) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr, [ffrt_function_header_t](ffrt__function__header__t.md)\* f) | 设置串行队列超时回调方法。 | 
| FFRT_C_API [ffrt_function_header_t](ffrt__function__header__t.md)\*&nbsp;&nbsp;[ffrt_queue_attr_get_callback](#ffrt_queue_attr_get_callback) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | 获取串行队列超时回调方法。 | 
| FFRT_C_API void [ffrt_queue_attr_set_max_concurrency](#ffrt_queue_attr_set_max_concurrency) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr, const int max_concurrency) | 设置并行队列最大并发度。 | 
| FFRT_C_API int [ffrt_queue_attr_get_max_concurrency](#ffrt_queue_attr_get_max_concurrency) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | 获取并行队列最大并发度。 | 
| FFRT_C_API ffrt_queue_t[ffrt_queue_create](#ffrt_queue_create) ([ffrt_queue_type_t](#ffrt_queue_type_t) type, const char\* name, const [ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | 创建队列。 | 
| FFRT_C_API void [ffrt_queue_destroy](#ffrt_queue_destroy) (ffrt_queue_t queue) | 销毁队列。 | 
| FFRT_C_API void [ffrt_queue_submit](#ffrt_queue_submit) (ffrt_queue_t queue, [ffrt_function_header_t](ffrt__function__header__t.md)\* f, const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 提交一个任务到队列中调度执行。 | 
| FFRT_C_API ffrt_task_handle_t[ffrt_queue_submit_h](#ffrt_queue_submit_h) (ffrt_queue_t queue, [ffrt_function_header_t](ffrt__function__header__t.md)\* f, const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 提交一个任务到队列中调度执行，并返回任务句柄。 | 
| FFRT_C_API void [ffrt_queue_wait](#ffrt_queue_wait) (ffrt_task_handle_t handle) | 等待队列中一个任务执行完成。 | 
| FFRT_C_API int [ffrt_queue_cancel](#ffrt_queue_cancel) (ffrt_task_handle_t handle) | 取消队列中一个任务。 | 
| FFRT_C_API ffrt_queue_t[ffrt_get_main_queue](#ffrt_get_main_queue) () | 获取主线程队列。 | 
| FFRT_C_API ffrt_queue_t[ffrt_get_current_queue](#ffrt_get_current_queue) () | 获取应用 Worker(ArkTs)线程队列。 | 
| FFRT_C_API int [ffrt_usleep](#ffrt_usleep) (uint64_t usec) | 睡眠usec微秒。 | 
| FFRT_C_API void [ffrt_yield](#ffrt_yield) (void) | 当前任务主动放权，让其他任务有机会调度执行。 | 
| FFRT_C_API int [ffrt_task_attr_init](#ffrt_task_attr_init) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 初始化任务属性。 | 
| FFRT_C_API void [ffrt_task_attr_set_name](#ffrt_task_attr_set_name) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr, const char\* name) | 设置任务名字。 | 
| FFRT_C_API const char\*&nbsp;&nbsp;[ffrt_task_attr_get_name](#ffrt_task_attr_get_name) (const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 获取任务名字。 | 
| FFRT_C_API void [ffrt_task_attr_destroy](#ffrt_task_attr_destroy) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 销毁任务属性。 | 
| FFRT_C_API void [ffrt_task_attr_set_qos](#ffrt_task_attr_set_qos) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr, ffrt_qos_t qos) | 设置任务qos。 | 
| FFRT_C_API ffrt_qos_t[ffrt_task_attr_get_qos](#ffrt_task_attr_get_qos) (const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 获取任务qos。 | 
| FFRT_C_API void [ffrt_task_attr_set_delay](#ffrt_task_attr_set_delay) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr, uint64_t delay_us) | 设置任务延迟时间。 | 
| FFRT_C_API uint64_t [ffrt_task_attr_get_delay](#ffrt_task_attr_get_delay) (const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 获取任务延迟时间。 | 
| FFRT_C_API void [ffrt_task_attr_set_queue_priority](#ffrt_task_attr_set_queue_priority) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr, ffrt_queue_priority_t priority) | 设置并行队列任务优先级。 | 
| FFRT_C_API ffrt_queue_priority_t [ffrt_task_attr_get_queue_priority](#ffrt_task_attr_get_queue_priority) (const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 获取并行队列任务优先级。 | 
| FFRT_C_API int [ffrt_this_task_update_qos](#ffrt_this_task_update_qos) (ffrt_qos_t qos) | 更新任务qos。 | 
| FFRT_C_API ffrt_qos_t[ffrt_this_task_get_qos](#ffrt_this_task_get_qos) () | 获取任务qos。 | 
| FFRT_C_API uint64_t [ffrt_this_task_get_id](#ffrt_this_task_get_id) (void) | 获取任务id。 | 
| FFRT_C_API void\*&nbsp;&nbsp;[ffrt_alloc_auto_managed_function_storage_base](#ffrt_alloc_auto_managed_function_storage_base) ([ffrt_function_kind_t](#ffrt_function_kind_t) kind) | 申请函数执行结构的内存。 | 
| FFRT_C_API void [ffrt_submit_base](#ffrt_submit_base) ([ffrt_function_header_t](ffrt__function__header__t.md)\* f, const [ffrt_deps_t](ffrt__deps__t.md)\* in_deps, const [ffrt_deps_t](ffrt__deps__t.md)\* out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 提交任务调度执行。 | 
| FFRT_C_API ffrt_task_handle_t[ffrt_submit_h_base](#ffrt_submit_h_base) ([ffrt_function_header_t](ffrt__function__header__t.md)\* f, const [ffrt_deps_t](ffrt__deps__t.md)\* in_deps, const [ffrt_deps_t](ffrt__deps__t.md)\* out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | 提交任务调度执行并返回任务句柄。 | 
| FFRT_C_API void [ffrt_task_handle_destroy](#ffrt_task_handle_destroy) (ffrt_task_handle_t handle) | 销毁任务句柄。 | 
| FFRT_C_API void [ffrt_wait_deps](#ffrt_wait_deps) (const [ffrt_deps_t](ffrt__deps__t.md)\* deps) | 等待依赖的任务完成，当前任务开始执行。 | 
| FFRT_C_API void [ffrt_wait](#ffrt_wait) (void) | 等待之前所有提交任务完成，当前任务开始执行。 | 
| FFRT_C_API [ffrt_timer_t](#ffrt_timer_t)[ffrt_timer_start](#ffrt_timer_start) (ffrt_qos_t qos, uint64_t timeout, void\* data, [ffrt_timer_cb](#ffrt_timer_cb) cb, bool repeat) | 启动计时器。 | 
| FFRT_C_API int [ffrt_timer_stop](#ffrt_timer_stop) (ffrt_qos_t qos, [ffrt_timer_t](#ffrt_timer_t) handle) | 关闭计时器。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| ffrt_function_t[ffrt_function_header_t::exec](#exec) | 任务执行函数 | 
| ffrt_function_t[ffrt_function_header_t::destroy](#destroy) | 任务销毁函数 | 
| uint64_t [ffrt_function_header_t::reserve](#reserve) [2] | 保留位. | 
| [ffrt_dependence_type_t](#ffrt_dependence_type_t)[ffrt_dependence_t::type](#type) | 依赖类型 | 
| const void\*&nbsp;&nbsp;[ffrt_dependence_t::ptr](#ptr) | 依赖数据地址 | 
| uint32_t [ffrt_deps_t::len](#len) | 依赖数量 | 
| const [ffrt_dependence_t](ffrt__dependence__t.md)\*&nbsp;&nbsp;[ffrt_deps_t::items](#items) | 依赖数据 | 
| uint32_t [ffrt_task_attr_t::storage](#storage-46) [(ffrt_task_attr_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)] | 任务属性所占空间 | 
| uint32_t [ffrt_queue_attr_t::storage](#storage-36) [(ffrt_queue_attr_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)] | 串行队列属性所占空间 | 
| long [ffrt_condattr_t::storage](#storage-56) | FFRT条件变量属性所占空间 | 
| long [ffrt_mutexattr_t::storage](#storage-66) | FFRT锁属性所占空间 | 
| uint32_t [ffrt_mutex_t::storage](#storage-26) [(ffrt_mutex_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)] | FFRT互斥锁所占空间 | 
| uint32_t [ffrt_cond_t::storage](#storage-16) [(ffrt_cond_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)] | FFRT条件变量所占空间 | 


## 类型定义说明


### ffrt_poller_cb

```
typedef void(*ffrt_poller_cb) (void* data, uint32_t event)
```

**描述**

ffrt_poller_cb callback定义


### ffrt_timer_cb

```
typedef void(*ffrt_timer_cb) (void* data)
```

**描述**

ffrt_timer_cb callback定义


### ffrt_timer_t

```
typedef int ffrt_timer_t
```

**描述**

ffrt_timer_t 类型定义


## 枚举类型说明


### ffrt_dependence_type_t

```
enum ffrt_dependence_type_t
```

**描述**

依赖类型。

| 枚举名称 | 描述 | 
| -------- | -------- |
| ffrt_dependence_data | 数据依赖类型 | 
| ffrt_dependence_task | 任务依赖类型 | 


### ffrt_error_t

```
enum ffrt_error_t
```

**描述**

FFRT错误码。

| 枚举名称 | 枚举值 | 描述 | 
| -------- | -------- | -------- |
| ffrt_error | -1 | 失败 | 
| ffrt_success | 0 | 成功 | 
| ffrt_error_nomem | ENOMEM | 内存不足 | 
| ffrt_error_timedout | ETIMEDOUT | 超时 | 
| ffrt_error_busy | EBUSY | 重新尝试 | 
| ffrt_error_inval | EINVAL | 值无效 | 


### ffrt_function_kind_t

```
enum ffrt_function_kind_t
```

**描述**

任务类型。

| 名称 | 描述 | 
| -------- | -------- |
| ffrt_function_kind_general | 通用任务类型 | 
| ffrt_function_kind_queue | 队列任务类型 | 


### ffrt_qos_default_t

```
enum ffrt_qos_default_t
```

**描述**

任务的qos类型。

| 枚举名称 | 枚举值 | 描述 | 
| -------- | -------- | -------- |
| ffrt_qos_inherit | ffrt_qos_inherit | 继承当前任务qos属性 | 
| ffrt_qos_background | ffrt_qos_background | 后台任务 | 
| ffrt_qos_utility | ffrt_qos_utility | 实时工具 | 
| ffrt_qos_default | ffrt_qos_default | 默认类型 | 
| ffrt_qos_user_initiated | ffrt_qos_user_initiated | 用户期望 | 


### ffrt_queue_type_t

```
enum ffrt_queue_type_t
```

**描述**

队列类型。

| 枚举名称 | 枚举值 | 描述 | 
| -------- | -------- | -------- |
| ffrt_queue_serial | 0 | 串行队列 | 
| ffrt_queue_concurrent |  | 并行队列 | 
| ffrt_queue_max |  | 无效队列类型 | 


### ffrt_storage_size_t

```
enum ffrt_storage_size_t
```

**描述**

多种类型数据结构分配大小定义。

| 枚举名称 | 枚举值 | 描述 | 
| -------- | -------- | -------- |
| ffrt_task_attr_storage_size | 128 | 任务属性 | 
| ffrt_auto_managed_function_storage_size | 64 + sizeof(ffrt_function_header_t) | 任务执行体 | 
| ffrt_mutex_storage_size | 64 | 互斥锁 | 
| ffrt_cond_storage_size | 64 | 条件变量 | 
| ffrt_queue_attr_storage_size | 128 | 队列属性 | 


### ffrt_task_priority_t

```
enum ffrt_task_priority_t
```

**描述**

任务的优先级类型。

| 枚举名称 | 枚举值 | 描述 | 
| -------- | -------- | -------- |
| ffrt_task_priority_immediate | 0 | immediate 优先级 | 
| ffrt_task_priority_high | 1 | high 优先级 | 
| ffrt_task_priority_low | 2 | low 优先级 | 
| ffrt_task_priority_idle |  | lowest 优先级 | 


## 函数说明


### ffrt_alloc_auto_managed_function_storage_base()

```
FFRT_C_API void* ffrt_alloc_auto_managed_function_storage_base (ffrt_function_kind_t kind)
```

**描述**

申请函数执行结构的内存。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| kind | 函数执行结构类型，支持通用和队列函数执行结构类型。 | 

**返回：**

申请函数执行结构成功返回非空指针， 申请函数执行结构失败返回空指针。


### ffrt_cond_broadcast()

```
FFRT_C_API int ffrt_cond_broadcast (ffrt_cond_t*  cond)
```

**描述**

唤醒阻塞在条件变量上的所有任务。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cond | 条件变量指针。 | 

**返回：**

唤醒成功返回ffrt_success， 唤醒失败返回ffrt_error_inval。


### ffrt_cond_destroy()

```
FFRT_C_API int ffrt_cond_destroy (ffrt_cond_t*  cond)
```

**描述**

销毁条件变量。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cond | 条件变量指针。 | 

**返回：**

销毁条件变量成功返回ffrt_success， 销毁条件变量失败返回ffrt_error_inval。


### ffrt_cond_init()

```
FFRT_C_API int ffrt_cond_init (ffrt_cond_t*  cond, const ffrt_condattr_t*  attr )
```

**描述**

初始化条件变量。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cond | 条件变量指针。 | 
| attr | 条件变量属性指针。 | 

**返回：**

初始化条件变量成功返回ffrt_success， 初始化条件变量失败返回ffrt_error_inval。


### ffrt_cond_signal()

```
FFRT_C_API int ffrt_cond_signal (ffrt_cond_t*  cond)
```

**描述**

唤醒阻塞在条件变量上的一个任务。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cond | 条件变量指针。 | 

**返回：**

唤醒成功返回ffrt_success， 唤醒失败返回ffrt_error_inval。


### ffrt_cond_timedwait()

```
FFRT_C_API int ffrt_cond_timedwait (ffrt_cond_t*  cond, ffrt_mutex_t*  mutex, const struct timespec*  time_point )
```

**描述**

条件变量超时等待函数，条件变量不满足时阻塞当前任务，超时等待返回.

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cond | 条件变量指针。 | 
| mutex | mutex指针。 | 
| time_point | 最大等待到的时间点，超过这个时间点等待返回。 | 

**返回：**

等待后被成功唤醒返回ffrt_success， 等待超时返回ffrt_error_timedout。 等待失败ffrt_error_inval。


### ffrt_cond_wait()

```
FFRT_C_API int ffrt_cond_wait (ffrt_cond_t*  cond, ffrt_mutex_t*  mutex )
```

**描述**

条件变量等待函数，条件变量不满足时阻塞当前任务。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cond | 条件变量指针。 | 
| mutex | mutex指针。 | 

**返回：**

等待后被成功唤醒返回ffrt_success， 等待失败返回ffrt_error_inval。


### ffrt_get_current_queue()

```
FFRT_C_API ffrt_queue_t ffrt_get_current_queue ()
```

**描述**

获取应用 Worker(ArkTs)线程队列。

**起始版本：** 12

**返回：**

创建队列成功返回非空队列句柄， 创建队列失败返回空指针。


### ffrt_get_main_queue()

```
FFRT_C_API ffrt_queue_t ffrt_get_main_queue ()
```

**描述**

获取主线程队列。

**起始版本：** 12

**返回：**

创建队列成功返回非空队列句柄， 创建队列失败返回空指针。


### ffrt_loop_create()

```
FFRT_C_API ffrt_loop_t ffrt_loop_create (ffrt_queue_t queue)
```

**描述**

创建loop队列。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| queue | 并发队列。 | 

**返回：**

创建成功返回ffrt_loop_t对象，失败返回空指针。


### ffrt_loop_destory()

```
FFRT_C_API int ffrt_loop_destory (ffrt_loop_t loop)
```

**描述**

销毁loop队对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| loop | loop对象。 | 

**返回：**

销毁成功返回0，-1是销毁失败。


### ffrt_loop_epoll_ctl()

```
FFRT_C_API int ffrt_loop_epoll_ctl (ffrt_loop_t loop, int op, int fd, uint32_t events, void*  data, ffrt_poller_cb cb )
```

**描述**

管理loop上的监听事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| loop | loop对象。 | 
| op | fd操作符。 | 
| fd | 事件描述符。 | 
| events | 事件。 | 
| data | 事件变化时触发的回调函数的入参。 | 
| cb | 事件变化时触发的回调函数。 | 

**返回：**

成功返回0，失败返回-1.


### ffrt_loop_run()

```
FFRT_C_API int ffrt_loop_run (ffrt_loop_t loop)
```

**描述**

开启loop循环。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| loop | loop对象。 | 

**返回：**

loop循环失败返回-1，0是成功。


### ffrt_loop_stop()

```
FFRT_C_API void ffrt_loop_stop (ffrt_loop_t loop)
```

**描述**

停止loop循环。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| loop | loop对象。 | 


### ffrt_loop_timer_start()

```
FFRT_C_API ffrt_timer_t ffrt_loop_timer_start (ffrt_loop_t loop, uint64_t timeout, void*  data, ffrt_timer_cb cb, bool repeat )
```

**描述**

在ffrt loop上启动定时器。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| loop | loop对象。 | 
| timeout | 超时时间. | 
| data | 事件变化时触发的回调函数的入参。 | 
| cb | 事件变化时触发的回调函数。 | 
| repeat | 是否重复执行该定时器。 | 

**返回：**

返回定时器句柄。


### ffrt_loop_timer_stop()

```
FFRT_C_API int ffrt_loop_timer_stop (ffrt_loop_t loop, ffrt_timer_t handle )
```

**描述**

停止ffrt loop定时器。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| loop | loop对象。 | 
| handle | timer对象。 | 

**返回：**

成功返回0，失败返回-1.


### ffrt_mutex_destroy()

```
FFRT_C_API int ffrt_mutex_destroy (ffrt_mutex_t*  mutex)
```

**描述**

销毁mutex。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mutex | mutex指针。 | 

**返回：**

销毁mutex成功返回ffrt_success， 销毁mutex失败返回ffrt_error_inval。


### ffrt_mutex_init()

```
FFRT_C_API int ffrt_mutex_init (ffrt_mutex_t*  mutex, const ffrt_mutexattr_t*  attr )
```

**描述**

初始化mutex。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mutex | mutex指针。 | 
| attr | mutex属性。 | 

**返回：**

初始化mutex成功返回ffrt_success， 初始化mutex失败返回ffrt_error或ffrt_error_inval。


### ffrt_mutex_lock()

```
FFRT_C_API int ffrt_mutex_lock (ffrt_mutex_t*  mutex)
```

**描述**

获取mutex。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mutex | mutex指针。 | 

**返回：**

获取mutex成功返回ffrt_success， 获取mutex失败返回ffrt_error_inval， 或者阻塞当前任务。


### ffrt_mutex_trylock()

```
FFRT_C_API int ffrt_mutex_trylock (ffrt_mutex_t*  mutex)
```

**描述**

尝试获取mutex。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mutex | mutex指针。 | 

**返回：**

获取mutex成功返回ffrt_success， 获取mutex失败返回ffrt_error_inval或ffrt_error_busy。


### ffrt_mutex_unlock()

```
FFRT_C_API int ffrt_mutex_unlock (ffrt_mutex_t*  mutex)
```

**描述**

释放mutex。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mutex | mutex指针。 | 

**返回：**

释放mutex成功返回ffrt_success， 释放mutex失败返回ffrt_error_inval。


### ffrt_queue_attr_destroy()

```
FFRT_C_API void ffrt_queue_attr_destroy (ffrt_queue_attr_t*  attr)
```

**描述**

销毁串行队列属性。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 串行队列属性指针。 | 


### ffrt_queue_attr_get_callback()

```
FFRT_C_API ffrt_function_header_t* ffrt_queue_attr_get_callback (const ffrt_queue_attr_t*  attr)
```

**描述**

获取串行队列超时回调方法。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 串行队列属性指针。 | 

**返回：**

返回串行队列超时回调方法。


### ffrt_queue_attr_get_max_concurrency()

```
FFRT_C_API int ffrt_queue_attr_get_max_concurrency (ffrt_queue_attr_t*  attr)
```

**描述**

获取并行队列最大并发度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 队列属性指针。 | 

**返回：**

返回最大并发度。


### ffrt_queue_attr_get_qos()

```
FFRT_C_API ffrt_qos_t ffrt_queue_attr_get_qos (const ffrt_queue_attr_t*  attr)
```

**描述**

获取串行队列qos属性。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 串行队列属性指针。 | 

**返回：**

返回串行队列的qos属性。


### ffrt_queue_attr_get_timeout()

```
FFRT_C_API uint64_t ffrt_queue_attr_get_timeout (const ffrt_queue_attr_t*  attr)
```

**描述**

获取串行队列任务执行的timeout时间。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 串行队列属性指针。 | 

**返回：**

返回串行队列任务执行的timeout时间。


### ffrt_queue_attr_init()

```
FFRT_C_API int ffrt_queue_attr_init (ffrt_queue_attr_t*  attr)
```

**描述**

初始化串行队列属性。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 串行队列属性指针。 | 

**返回：**

执行成功时返回0， 执行失败时返回-1。


### ffrt_queue_attr_set_callback()

```
FFRT_C_API void ffrt_queue_attr_set_callback (ffrt_queue_attr_t*  attr, ffrt_function_header_t*  f )
```

**描述**

设置串行队列超时回调方法。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 串行队列属性指针。 | 
| f | 超时回调方法执行体。 | 


### ffrt_queue_attr_set_max_concurrency()

```
FFRT_C_API void ffrt_queue_attr_set_max_concurrency (ffrt_queue_attr_t*  attr, const int max_concurrency )
```

**描述**

设置并行队列最大并发度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 队列属性指针。 | 
| max_concurrency | 最大并发度。 | 


### ffrt_queue_attr_set_qos()

```
FFRT_C_API void ffrt_queue_attr_set_qos (ffrt_queue_attr_t*  attr, ffrt_qos_t qos )
```

**描述**

设置串行队列qos属性。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 串行队列属性指针。 | 
| qos | qos属性值。 | 


### ffrt_queue_attr_set_timeout()

```
FFRT_C_API void ffrt_queue_attr_set_timeout (ffrt_queue_attr_t*  attr, uint64_t timeout_us )
```

**描述**

设置串行队列timeout属性。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 串行队列属性指针。 | 
| timeout_us | 串行队列任务执行的timeout时间。 | 


### ffrt_queue_cancel()

```
FFRT_C_API int ffrt_queue_cancel (ffrt_task_handle_t handle)
```

**描述**

取消队列中一个任务。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 任务句柄。 | 

**返回：**

取消任务成功返回0， 取消任务失败返回-1。


### ffrt_queue_create()

```
FFRT_C_API ffrt_queue_t ffrt_queue_create (ffrt_queue_type_t type, const char*  name, const ffrt_queue_attr_t*  attr )
```

**描述**

创建队列。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 队列类型。 | 
| name | 队列名字。 | 
| attr | 队列属性。 | 

**返回：**

创建队列成功返回非空队列句柄， 创建队列失败返回空指针。


### ffrt_queue_destroy()

```
FFRT_C_API void ffrt_queue_destroy (ffrt_queue_t queue)
```

**描述**

销毁队列。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| queue | 队列句柄。 | 


### ffrt_queue_submit()

```
FFRT_C_API void ffrt_queue_submit (ffrt_queue_t queue, ffrt_function_header_t*  f, const ffrt_task_attr_t*  attr )
```

**描述**

提交一个任务到队列中调度执行。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| queue | 队列句柄。 | 
| f | 任务的执行体。 | 
| attr | 任务属性。 | 


### ffrt_queue_submit_h()

```
FFRT_C_API ffrt_task_handle_t ffrt_queue_submit_h (ffrt_queue_t queue, ffrt_function_header_t*  f, const ffrt_task_attr_t*  attr )
```

**描述**

提交一个任务到队列中调度执行，并返回任务句柄。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| queue | 队列句柄。 | 
| f | 任务的执行体。 | 
| attr | 任务属性。 | 

**返回：**

提交成功返回非空任务句柄， 提交失败返回空指针。


### ffrt_queue_wait()

```
FFRT_C_API void ffrt_queue_wait (ffrt_task_handle_t handle)
```

**描述**

等待队列中一个任务执行完成。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 任务句柄。 | 


### ffrt_submit_base()

```
FFRT_C_API void ffrt_submit_base (ffrt_function_header_t*  f, const ffrt_deps_t*  in_deps, const ffrt_deps_t*  out_deps, const ffrt_task_attr_t*  attr )
```

**描述**

提交任务调度执行。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| f | 任务执行体封装的指针。 | 
| in_deps | 输入依赖指针。 | 
| out_deps | 输出依赖指针。 | 
| attr | 任务属性。 | 


### ffrt_submit_h_base()

```
FFRT_C_API ffrt_task_handle_t ffrt_submit_h_base (ffrt_function_header_t*  f, const ffrt_deps_t*  in_deps, const ffrt_deps_t*  out_deps, const ffrt_task_attr_t*  attr )
```

**描述**

提交任务调度执行并返回任务句柄。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| f | 任务执行体封装的指针。 | 
| in_deps | 输入依赖指针。 | 
| out_deps | 输出依赖指针。 | 
| attr | 任务属性。 | 

**返回：**

提交任务成功返回非空任务句柄， 提交任务失败返回空指针。


### ffrt_task_attr_destroy()

```
FFRT_C_API void ffrt_task_attr_destroy (ffrt_task_attr_t*  attr)
```

**描述**

销毁任务属性。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 任务属性指针。 | 


### ffrt_task_attr_get_delay()

```
FFRT_C_API uint64_t ffrt_task_attr_get_delay (const ffrt_task_attr_t*  attr)
```

**描述**

获取任务延迟时间。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 任务属性指针。 | 

**返回：**

返回任务的延迟时间。


### ffrt_task_attr_get_name()

```
FFRT_C_API const char* ffrt_task_attr_get_name (const ffrt_task_attr_t*  attr)
```

**描述**

获取任务名字。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 任务属性指针。 | 

**返回：**

获取任务名字成功返回非空指针， 获取任务名字失败返回空指针。


### ffrt_task_attr_get_qos()

```
FFRT_C_API ffrt_qos_t ffrt_task_attr_get_qos (const ffrt_task_attr_t*  attr)
```

**描述**

获取任务qos。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 任务属性指针。 | 

**返回：**

返回任务的qos，默认返回ffrt_qos_default。


### ffrt_task_attr_get_queue_priority()

```
FFRT_C_API ffrt_queue_priority_t ffrt_task_attr_get_queue_priority (const ffrt_task_attr_t*  attr)
```

**描述**

获取并行队列任务优先级。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 任务属性指针。 | 

**返回：**

返回任务优先级。


### ffrt_task_attr_init()

```
FFRT_C_API int ffrt_task_attr_init (ffrt_task_attr_t*  attr)
```

**描述**

初始化任务属性。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 任务属性指针。 | 

**返回：**

初始化任务属性成功返回0， 初始化任务属性失败返回-1。


### ffrt_task_attr_set_delay()

```
FFRT_C_API void ffrt_task_attr_set_delay (ffrt_task_attr_t*  attr, uint64_t delay_us )
```

**描述**

设置任务延迟时间。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 任务属性指针。 | 
| delay_us | 任务延迟时间，单位微秒。 | 


### ffrt_task_attr_set_name()

```
FFRT_C_API void ffrt_task_attr_set_name (ffrt_task_attr_t*  attr, const char*  name )
```

**描述**

设置任务名字。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 任务属性指针。 | 
| name | 任务名字。 | 


### ffrt_task_attr_set_qos()

```
FFRT_C_API void ffrt_task_attr_set_qos (ffrt_task_attr_t*  attr, ffrt_qos_t qos )
```

**描述**

设置任务qos。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 任务属性指针。 | 
| qos | 任务qos类型。 | 


### ffrt_task_attr_set_queue_priority()

```
FFRT_C_API void ffrt_task_attr_set_queue_priority (ffrt_task_attr_t*  attr, ffrt_queue_priority_t priority )
```

**描述**

设置并行队列任务优先级。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attr | 任务属性指针。 | 
| priority | 任务优先级。 | 


### ffrt_task_handle_destroy()

```
FFRT_C_API void ffrt_task_handle_destroy (ffrt_task_handle_t handle)
```

**描述**

销毁任务句柄。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 任务句柄。 | 


### ffrt_this_task_get_id()

```
FFRT_C_API uint64_t ffrt_this_task_get_id (void )
```

**描述**

获取任务id。

**起始版本：** 10

**返回：**

返回当前任务的id。


### ffrt_this_task_get_qos()

```
FFRT_C_API ffrt_qos_t ffrt_this_task_get_qos ()
```

**描述**

获取任务qos。

**起始版本：** 12

**返回：**

返回任务qos。


### ffrt_this_task_update_qos()

```
FFRT_C_API int ffrt_this_task_update_qos (ffrt_qos_t qos)
```

**描述**

更新任务qos。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| qos | 当前任务待更新的qos。 | 

**返回：**

更新任务qos成功返回0， 更新任务qos失败返回-1。


### ffrt_timer_start()

```
FFRT_C_API ffrt_timer_t ffrt_timer_start (ffrt_qos_t qos, uint64_t timeout, void*  data, ffrt_timer_cb cb, bool repeat )
```

**描述**

启动计时器。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| qos | qos等级。 | 
| timeout | 超时时间。 | 
| data | 超时后回调函数的入参。 | 
| cb | 超时执行的回调函数。 | 
| repeat | 是否重复执行该定时器。 | 

**返回：**

返回定时器句柄。


### ffrt_timer_stop()

```
FFRT_C_API int ffrt_timer_stop (ffrt_qos_t qos, ffrt_timer_t handle )
```

**描述**

关闭计时器。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| qos | qos等级。 | 
| handle | 定时器句柄。 | 

**返回：**

0 代表返回成功，其余是失败。


### ffrt_usleep()

```
FFRT_C_API int ffrt_usleep (uint64_t usec)
```

**描述**

睡眠usec微秒。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| usec | 睡眠时间，单位微秒。 | 

**返回：**

执行成功时返回ffrt_success。


### ffrt_wait()

```
FFRT_C_API void ffrt_wait (void )
```

**描述**

等待之前所有提交任务完成，当前任务开始执行。

**起始版本：** 10


### ffrt_wait_deps()

```
FFRT_C_API void ffrt_wait_deps (const ffrt_deps_t*  deps)
```

**描述**

等待依赖的任务完成，当前任务开始执行。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deps | 依赖的指针。 | 


### ffrt_yield()

```
FFRT_C_API void ffrt_yield (void )
```

**描述**

当前任务主动放权，让其他任务有机会调度执行。

**起始版本：** 10


## 变量说明


### destroy

```
ffrt_function_t ffrt_function_header_t::destroy
```

**描述**

任务销毁函数


### exec

```
ffrt_function_t ffrt_function_header_t::exec
```

**描述**

任务执行函数


### items

```
const ffrt_dependence_t* ffrt_deps_t::items
```

**描述**

依赖数据


### len

```
uint32_t ffrt_deps_t::len
```

**描述**

依赖数量


### ptr

```
const void* ffrt_dependence_t::ptr
```

**描述**

依赖数据地址


### reserve

```
uint64_t ffrt_function_header_t::reserve[2]
```

**描述**

保留位.


### storage [1/6]

```
uint32_t ffrt_cond_t::storage[(ffrt_cond_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```

**描述**

FFRT条件变量所占空间


### storage [2/6]

```
uint32_t ffrt_mutex_t::storage[(ffrt_mutex_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```

**描述**

FFRT互斥锁所占空间


### storage [3/6]

```
uint32_t ffrt_queue_attr_t::storage[(ffrt_queue_attr_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```

**描述**

串行队列属性所占空间


### storage [4/6]

```
uint32_t ffrt_task_attr_t::storage[(ffrt_task_attr_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```

**描述**

任务属性所占空间


### storage [5/6]

```
long ffrt_condattr_t::storage
```

**描述**

FFRT条件变量属性所占空间


### storage [6/6]

```
long ffrt_mutexattr_t::storage
```

**描述**

FFRT锁属性所占空间


### type

```
ffrt_dependence_type_t ffrt_dependence_t::type
```

**描述**

依赖类型
