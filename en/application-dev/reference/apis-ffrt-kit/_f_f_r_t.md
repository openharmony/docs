# FFRT


## Overview

Function Flow Runtime (FFRT) is a software runtime library that works with the Function Flow programming model. It is used to schedule and execute tasks of an application developed on the Function Flow programming model.

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [condition_variable.h](condition__variable_8h.md) | Declares the condition variable interfaces in C. | 
| [loop.h](loop_8h.md) | Declares the loop interfaces in C. | 
| [mutex.h](mutex_8h.md) | Declares the mutex interfaces in C. | 
| [queue.h](queue_8h.md) | Declares the queue interfaces in C. | 
| [shared_mutex.h](shared__mutex_8h.md) | Declares read-write lock interfaces in C. | 
| [sleep.h](sleep_8h.md) | Declares the sleep and yield interfaces in C. | 
| [task.h](task_8h.md) | Declares the task interfaces in C. | 
| [timer.h](timer_8h.md) | Declares the timer interfaces in C. | 
| [type_def.h](type__def_8h.md) | Declares the common types. | 


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
| typedef void \* [ffrt_loop_t](#ffrt_loop_t) | Defines the handle to a loop. | 
| typedef void \* [ffrt_queue_t](#ffrt_queue_t) | Defines the handle to a queue. | 
| typedef int [ffrt_qos_t](#ffrt_qos_t) | Defines the QoS type. | 
| typedef void(\* [ffrt_function_t](#ffrt_function_t)) (void \*) | Defines the type of the pointer to a task execution function. | 
| typedef void \* [ffrt_task_handle_t](#ffrt_task_handle_t) | Defines the handle to a task. | 
| typedef void(\* [ffrt_poller_cb](#ffrt_poller_cb)) (void \*data, uint32_t event) | Defines the poller callback function. | 
| typedef void(\* [ffrt_timer_cb](#ffrt_timer_cb)) (void \*data) | Defines the timer callback function. | 
| typedef int [ffrt_timer_t](#ffrt_timer_t) | Handle to the timer. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [ffrt_queue_type_t](#ffrt_queue_type_t) { ffrt_queue_serial, ffrt_queue_concurrent, ffrt_queue_max } | Enumerates the queue types. | 
| [ffrt_queue_priority_t](#ffrt_queue_priority_t) { ffrt_queue_priority_immediate = 0, ffrt_queue_priority_high, ffrt_queue_priority_low, ffrt_queue_priority_idle } | Enumerates the task priority types. | 
| [ffrt_qos_default_t](#ffrt_qos_default_t) {<br>ffrt_qos_inherit = -1, ffrt_qos_background, ffrt_qos_utility, ffrt_qos_default,<br>ffrt_qos_user_initiated<br>} | Enumerates the task QoS types. | 
| [ffrt_storage_size_t](#ffrt_storage_size_t) {<br>ffrt_task_attr_storage_size = 128, ffrt_auto_managed_function_storage_size = 64 + sizeof(ffrt_function_header_t), ffrt_mutex_storage_size = 64, ffrt_cond_storage_size = 64,<br>ffrt_queue_attr_storage_size = 128, ffrt_rwlock_storage_size = 64<br>} | Enumerates the storage sizes available for different types of structs. | 
| [ffrt_function_kind_t](#ffrt_function_kind_t) { ffrt_function_kind_general, ffrt_function_kind_queue } | Enumerates the task types. | 
| [ffrt_dependence_type_t](#ffrt_dependence_type_t) { ffrt_dependence_data, ffrt_dependence_task } | Enumerates the dependency types. | 
| [ffrt_error_t](#ffrt_error_t) {<br>ffrt_error = -1, ffrt_success = 0, ffrt_error_nomem = ENOMEM, ffrt_error_timedout = ETIMEDOUT,<br>ffrt_error_busy = EBUSY, ffrt_error_inval = EINVAL<br>} | Enumerates the FFRT error codes. | 
| [ffrt_mutex_type](#ffrt_mutex_type) { ffrt_mutex_normal = 0, ffrt_mutex_recursive = 2, ffrt_mutex_default = ffrt_mutex_normal } | Enumerates the mutex types. | 


### Functions

| Name| Description| 
| -------- | -------- |
| FFRT_C_API int [ffrt_cond_init](#ffrt_cond_init) ([ffrt_cond_t](ffrt__cond__t.md) \*cond, const [ffrt_condattr_t](ffrt__condattr__t.md) \*attr) | Initializes a condition variable. | 
| FFRT_C_API int [ffrt_cond_signal](#ffrt_cond_signal) ([ffrt_cond_t](ffrt__cond__t.md) \*cond) | Unblocks at least one of the threads that are blocked on a condition variable. | 
| FFRT_C_API int [ffrt_cond_broadcast](#ffrt_cond_broadcast) ([ffrt_cond_t](ffrt__cond__t.md) \*cond) | Unblocks all threads currently blocked on a condition variable. | 
| FFRT_C_API int [ffrt_cond_wait](#ffrt_cond_wait) ([ffrt_cond_t](ffrt__cond__t.md) \*cond, [ffrt_mutex_t](ffrt__mutex__t.md) \*mutex) | Blocks the calling thread on a condition variable. | 
| FFRT_C_API int [ffrt_cond_timedwait](#ffrt_cond_timedwait) ([ffrt_cond_t](ffrt__cond__t.md) \*cond, [ffrt_mutex_t](ffrt__mutex__t.md) \*mutex, const struct timespec \*time_point) | Blocks the calling thread on a condition variable for a given duration. | 
| FFRT_C_API int [ffrt_cond_destroy](#ffrt_cond_destroy) ([ffrt_cond_t](ffrt__cond__t.md) \*cond) | Destroys a condition variable. | 
| FFRT_C_API [ffrt_loop_t](#ffrt_loop_t) [ffrt_loop_create](#ffrt_loop_create) ([ffrt_queue_t](#ffrt_queue_t) queue) | Creates a loop. | 
| FFRT_C_API int [ffrt_loop_destroy](#ffrt_loop_destroy) ([ffrt_loop_t](#ffrt_loop_t) loop) | Destroys a loop. | 
| FFRT_C_API int [ffrt_loop_run](#ffrt_loop_run) ([ffrt_loop_t](#ffrt_loop_t) loop) | Runs a loop. | 
| FFRT_C_API void [ffrt_loop_stop](#ffrt_loop_stop) ([ffrt_loop_t](#ffrt_loop_t) loop) | Stops a loop. | 
| FFRT_C_API int [ffrt_loop_epoll_ctl](#ffrt_loop_epoll_ctl) ([ffrt_loop_t](#ffrt_loop_t) loop, int op, int fd, uint32_t events, void \*data, [ffrt_poller_cb](#ffrt_poller_cb) cb) | Manages listening events on a loop. | 
| FFRT_C_API [ffrt_timer_t](#ffrt_timer_t) [ffrt_loop_timer_start](#ffrt_loop_timer_start) ([ffrt_loop_t](#ffrt_loop_t) loop, uint64_t timeout, void \*data, [ffrt_timer_cb](#ffrt_timer_cb) cb, bool repeat) | Starts the timer on a loop. | 
| FFRT_C_API int [ffrt_loop_timer_stop](#ffrt_loop_timer_stop) ([ffrt_loop_t](#ffrt_loop_t) loop, [ffrt_timer_t](#ffrt_timer_t) handle) | Stops the timer on a loop. | 
| FFRT_C_API int [ffrt_mutexattr_init](#ffrt_mutexattr_init) ([ffrt_mutexattr_t](ffrt__mutexattr__t.md) \*attr) | Initializes the mutex attribute. | 
| FFRT_C_API int [ffrt_mutexattr_settype](#ffrt_mutexattr_settype) ([ffrt_mutexattr_t](ffrt__mutexattr__t.md) \*attr, int type) | Sets the mutex attribute type. | 
| FFRT_C_API int [ffrt_mutexattr_gettype](#ffrt_mutexattr_gettype) ([ffrt_mutexattr_t](ffrt__mutexattr__t.md) \*attr, int \*type) | Obtains the mutex type. | 
| FFRT_C_API int [ffrt_mutexattr_destroy](#ffrt_mutexattr_destroy) ([ffrt_mutexattr_t](ffrt__mutexattr__t.md) \*attr) | Destroys the mutex attribute. This API needs to be called by users. | 
| FFRT_C_API int [ffrt_mutex_init](#ffrt_mutex_init) ([ffrt_mutex_t](ffrt__mutex__t.md) \*mutex, const [ffrt_mutexattr_t](ffrt__mutexattr__t.md) \*attr) | Initializes a mutex. | 
| FFRT_C_API int [ffrt_mutex_lock](#ffrt_mutex_lock) ([ffrt_mutex_t](ffrt__mutex__t.md) \*mutex) | Locks a mutex. | 
| FFRT_C_API int [ffrt_mutex_unlock](#ffrt_mutex_unlock) ([ffrt_mutex_t](ffrt__mutex__t.md) \*mutex) | Unlocks a mutex. | 
| FFRT_C_API int [ffrt_mutex_trylock](#ffrt_mutex_trylock) ([ffrt_mutex_t](ffrt__mutex__t.md) \*mutex) | Attempts to lock a mutex. | 
| FFRT_C_API int [ffrt_mutex_destroy](#ffrt_mutex_destroy) ([ffrt_mutex_t](ffrt__mutex__t.md) \*mutex) | Destroys a mutex. | 
| FFRT_C_API int [ffrt_queue_attr_init](#ffrt_queue_attr_init) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Initializes the queue attribute. | 
| FFRT_C_API void [ffrt_queue_attr_destroy](#ffrt_queue_attr_destroy) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Destroys the queue attribute. | 
| FFRT_C_API void [ffrt_queue_attr_set_qos](#ffrt_queue_attr_set_qos) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr, [ffrt_qos_t](#ffrt_qos_t) qos) | Sets the queue QoS. | 
| FFRT_C_API [ffrt_qos_t](#ffrt_qos_t) [ffrt_queue_attr_get_qos](#ffrt_queue_attr_get_qos) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Obtains the queue QoS. | 
| FFRT_C_API void [ffrt_queue_attr_set_timeout](#ffrt_queue_attr_set_timeout) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr, uint64_t timeout_us) | Sets the queue timeout. | 
| FFRT_C_API uint64_t [ffrt_queue_attr_get_timeout](#ffrt_queue_attr_get_timeout) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Obtains the queue timeout. | 
| FFRT_C_API void [ffrt_queue_attr_set_callback](#ffrt_queue_attr_set_callback) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr, [ffrt_function_header_t](ffrt__function__header__t.md) \*f) | Sets a callback that is invoked when a queue task times out. | 
| FFRT_C_API [ffrt_function_header_t](ffrt__function__header__t.md) \* [ffrt_queue_attr_get_callback](#ffrt_queue_attr_get_callback) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Obtains the callback that is invoked when a queue task times out. | 
| FFRT_C_API void [ffrt_queue_attr_set_max_concurrency](#ffrt_queue_attr_set_max_concurrency) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr, const int max_concurrency) | Sets the maximum concurrency for a queue, which must be a concurrent queue. | 
| FFRT_C_API int [ffrt_queue_attr_get_max_concurrency](#ffrt_queue_attr_get_max_concurrency) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Obtains the maximum concurrency of a queue, which must be a concurrent queue. | 
| FFRT_C_API [ffrt_queue_t](#ffrt_queue_t) [ffrt_queue_create](#ffrt_queue_create) ([ffrt_queue_type_t](#ffrt_queue_type_t) type, const char \*name, const [ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Creates a queue. | 
| FFRT_C_API void [ffrt_queue_destroy](#ffrt_queue_destroy) ([ffrt_queue_t](#ffrt_queue_t) queue) | Destroys a queue. | 
| FFRT_C_API void [ffrt_queue_submit](#ffrt_queue_submit) ([ffrt_queue_t](#ffrt_queue_t) queue, [ffrt_function_header_t](ffrt__function__header__t.md) \*f, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task to a queue. | 
| FFRT_C_API [ffrt_task_handle_t](#ffrt_task_handle_t) [ffrt_queue_submit_h](#ffrt_queue_submit_h) ([ffrt_queue_t](#ffrt_queue_t) queue, [ffrt_function_header_t](ffrt__function__header__t.md) \*f, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task to a queue, and obtains the task handle. | 
| FFRT_C_API void [ffrt_queue_submit_f](#ffrt_queue_submit_f) ([ffrt_queue_t](#ffrt_queue_t) queue, [ffrt_function_t](#ffrt_function_t) func, void \*arg, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task to a queue. It is a simplified form of **ffrt_queue_submit**. | 
| FFRT_C_API [ffrt_task_handle_t](#ffrt_task_handle_t) [ffrt_queue_submit_h_f](#ffrt_queue_submit_h_f) ([ffrt_queue_t](#ffrt_queue_t) queue, [ffrt_function_t](#ffrt_function_t) func, void \*arg, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task to a queue, and obtains the task handle. It is a simplified form of **ffrt_queue_submit_h**. | 
| FFRT_C_API void [ffrt_queue_wait](#ffrt_queue_wait) ([ffrt_task_handle_t](#ffrt_task_handle_t) handle) | Waits until a task in the queue is complete. | 
| FFRT_C_API int [ffrt_queue_cancel](#ffrt_queue_cancel) ([ffrt_task_handle_t](#ffrt_task_handle_t) handle) | Cancels a task in the queue. | 
| FFRT_C_API [ffrt_queue_t](#ffrt_queue_t) [ffrt_get_main_queue](#ffrt_get_main_queue) (void) | Obtains the main thread queue. | 
| FFRT_C_API [ffrt_queue_t](#ffrt_queue_t) [ffrt_get_current_queue](#ffrt_get_current_queue) (void) | Obtains the ArkTS Worker thread queue. | 
| FFRT_C_API int [ffrt_rwlock_init](#ffrt_rwlock_init) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock, const [ffrt_rwlockattr_t](ffrt__rwlockattr__t.md) \*attr) | Initializes a read-write lock. | 
| FFRT_C_API int [ffrt_rwlock_wrlock](#ffrt_rwlock_wrlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | Obtains a write lock. | 
| FFRT_C_API int [ffrt_rwlock_trywrlock](#ffrt_rwlock_trywrlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | Attempts to obtain a write lock. | 
| FFRT_C_API int [ffrt_rwlock_rdlock](#ffrt_rwlock_rdlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | Obtains a read lock. | 
| FFRT_C_API int [ffrt_rwlock_tryrdlock](#ffrt_rwlock_tryrdlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | Attempts to obtain a read lock. | 
| FFRT_C_API int [ffrt_rwlock_unlock](#ffrt_rwlock_unlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | Releases the read-write lock. | 
| FFRT_C_API int [ffrt_rwlock_destroy](#ffrt_rwlock_destroy) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | Destroys the read-write lock. | 
| FFRT_C_API int [ffrt_usleep](#ffrt_usleep) (uint64_t usec) | Sets the fixed sleep time. | 
| FFRT_C_API void [ffrt_yield](#ffrt_yield) (void) | Passes control to other tasks so that they can be executed. | 
| FFRT_C_API int [ffrt_task_attr_init](#ffrt_task_attr_init) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Initializes a task attribute. | 
| FFRT_C_API void [ffrt_task_attr_set_name](#ffrt_task_attr_set_name) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr, const char \*name) | Sets a task name. | 
| FFRT_C_API const char \* [ffrt_task_attr_get_name](#ffrt_task_attr_get_name) (const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Obtains a task name. | 
| FFRT_C_API void [ffrt_task_attr_destroy](#ffrt_task_attr_destroy) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Destroys a task attribute. | 
| FFRT_C_API void [ffrt_task_attr_set_qos](#ffrt_task_attr_set_qos) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr, [ffrt_qos_t](#ffrt_qos_t) qos) | Sets the task QoS. | 
| FFRT_C_API [ffrt_qos_t](#ffrt_qos_t) [ffrt_task_attr_get_qos](#ffrt_task_attr_get_qos) (const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Obtains the task QoS. | 
| FFRT_C_API void [ffrt_task_attr_set_delay](#ffrt_task_attr_set_delay) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr, uint64_t delay_us) | Sets the task delay time. | 
| FFRT_C_API uint64_t [ffrt_task_attr_get_delay](#ffrt_task_attr_get_delay) (const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Obtains the task delay time. | 
| FFRT_C_API void [ffrt_task_attr_set_queue_priority](#ffrt_task_attr_set_queue_priority) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr, [ffrt_queue_priority_t](#ffrt_queue_priority_t) priority) | Sets the task priority in the queue. | 
| FFRT_C_API [ffrt_queue_priority_t](#ffrt_queue_priority_t) [ffrt_task_attr_get_queue_priority](#ffrt_task_attr_get_queue_priority) (const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Obtains the task priority in the queue. | 
| FFRT_C_API void [ffrt_task_attr_set_stack_size](#ffrt_task_attr_set_stack_size) ([ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr, uint64_t size) | Sets the task stack size. | 
| FFRT_C_API uint64_t [ffrt_task_attr_get_stack_size](#ffrt_task_attr_get_stack_size) (const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Obtains the task stack size. | 
| FFRT_C_API int [ffrt_this_task_update_qos](#ffrt_this_task_update_qos) ([ffrt_qos_t](#ffrt_qos_t) qos) | Updates the task QoS. | 
| FFRT_C_API [ffrt_qos_t](#ffrt_qos_t) [ffrt_this_task_get_qos](#ffrt_this_task_get_qos) (void) | Obtains the task QoS. | 
| FFRT_C_API uint64_t [ffrt_this_task_get_id](#ffrt_this_task_get_id) (void) | Obtains the ID of this task. | 
| FFRT_C_API void \* [ffrt_alloc_auto_managed_function_storage_base](#ffrt_alloc_auto_managed_function_storage_base) ([ffrt_function_kind_t](#ffrt_function_kind_t) kind) | Applies for memory for the task execution function struct. | 
| FFRT_C_API void [ffrt_submit_base](#ffrt_submit_base) ([ffrt_function_header_t](ffrt__function__header__t.md) \*f, const [ffrt_deps_t](ffrt__deps__t.md) \*in_deps, const [ffrt_deps_t](ffrt__deps__t.md) \*out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task. | 
| FFRT_C_API [ffrt_task_handle_t](#ffrt_task_handle_t) [ffrt_submit_h_base](#ffrt_submit_h_base) ([ffrt_function_header_t](ffrt__function__header__t.md) \*f, const [ffrt_deps_t](ffrt__deps__t.md) \*in_deps, const [ffrt_deps_t](ffrt__deps__t.md) \*out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task, and obtains the task handle. | 
| FFRT_C_API void [ffrt_submit_f](#ffrt_submit_f) ([ffrt_function_t](#ffrt_function_t) func, void \*arg, const [ffrt_deps_t](ffrt__deps__t.md) \*in_deps, const [ffrt_deps_t](ffrt__deps__t.md) \*out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task. It is a simplified form of **ffrt_submit_base**. | 
| FFRT_C_API [ffrt_task_handle_t](#ffrt_task_handle_t) [ffrt_submit_h_f](#ffrt_submit_h_f) ([ffrt_function_t](#ffrt_function_t) func, void \*arg, const [ffrt_deps_t](ffrt__deps__t.md) \*in_deps, const [ffrt_deps_t](ffrt__deps__t.md) \*out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task, and obtains the task handle. It is a simplified form of **ffrt_submit_h_base**. | 
| FFRT_C_API uint32_t [ffrt_task_handle_inc_ref](#ffrt_task_handle_inc_ref) ([ffrt_task_handle_t](#ffrt_task_handle_t) handle) | Increases the number of task handle references. | 
| FFRT_C_API uint32_t [ffrt_task_handle_dec_ref](#ffrt_task_handle_dec_ref) ([ffrt_task_handle_t](#ffrt_task_handle_t) handle) | Decreases the number of task handle references. | 
| FFRT_C_API void [ffrt_task_handle_destroy](#ffrt_task_handle_destroy) ([ffrt_task_handle_t](#ffrt_task_handle_t) handle) | Destroys a task handle. | 
| FFRT_C_API void [ffrt_wait_deps](#ffrt_wait_deps) (const [ffrt_deps_t](ffrt__deps__t.md) \*deps) | Waits until the dependent tasks are complete. | 
| FFRT_C_API void [ffrt_wait](#ffrt_wait) (void) | Waits until all submitted tasks are complete. | 
| FFRT_C_API [ffrt_timer_t](#ffrt_timer_t) [ffrt_timer_start](#ffrt_timer_start) ([ffrt_qos_t](#ffrt_qos_t) qos, uint64_t timeout, void \*data, [ffrt_timer_cb](#ffrt_timer_cb) cb, bool repeat) | Starts the timer. | 
| FFRT_C_API int [ffrt_timer_stop](#ffrt_timer_stop) ([ffrt_qos_t](#ffrt_qos_t) qos, [ffrt_timer_t](#ffrt_timer_t) handle) | Stops the timer. | 


## Type Description


### ffrt_function_t

```
typedef void(* ffrt_function_t) (void *)
```
**Description**
Defines the type of the pointer to a task execution function.

**Since**: 10


### ffrt_loop_t

```
typedef void* ffrt_loop_t
```
**Description**
Defines the handle to a loop.

**Since**: 12


### ffrt_poller_cb

```
typedef void(* ffrt_poller_cb) (void *data, uint32_t event)
```
**Description**
Defines the poller callback function.

**Since**: 12


### ffrt_qos_t

```
typedef int ffrt_qos_t
```
**Description**
Defines the QoS type.

**Since**: 10


### ffrt_queue_t

```
typedef void* ffrt_queue_t
```
**Description**
Defines the handle to a queue.

**Since**: 10


### ffrt_task_handle_t

```
typedef void* ffrt_task_handle_t
```
**Description**
Defines the handle to a task.

**Since**: 10


### ffrt_timer_cb

```
typedef void(* ffrt_timer_cb) (void *data)
```
**Description**
Defines the timer callback function.

**Since**: 12


### ffrt_timer_t

```
typedef int ffrt_timer_t
```
**Description**
Handle to the timer.

**Since**: 12


## Enum Description


### ffrt_dependence_type_t

```
enum ffrt_dependence_type_t
```
**Description**
Enumerates the dependency types.

**Since**: 10

| Value| Description| 
| -------- | -------- |
| ffrt_dependence_data  | Data dependency.| 
| ffrt_dependence_task  | Task dependency.| 


### ffrt_error_t

```
enum ffrt_error_t
```
**Description**
Enumerates the FFRT error codes.

**Since**: 10

| Value| Description| 
| -------- | -------- |
| ffrt_error  | Failure.| 
| ffrt_success  | Success.| 
| ffrt_error_nomem  | Insufficient memory.| 
| ffrt_error_timedout  | Timeout.| 
| ffrt_error_busy  | Try again.| 
| ffrt_error_inval  | Invalid value.| 


### ffrt_function_kind_t

```
enum ffrt_function_kind_t
```
**Description**
Enumerates the task types.

**Since**: 10

| Value| Description| 
| -------- | -------- |
| ffrt_function_kind_general  | General task.| 
| ffrt_function_kind_queue  | Queue task.| 


### ffrt_mutex_type

```
enum ffrt_mutex_type
```
**Description**
Enumerates the mutex types.

**ffrt_mutex_normal** indicates a normal mutex, **ffrt_mutex_recursive** indicates a recursive mutex, and **ffrt_mutex_default** indicates a default mutex.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| ffrt_mutex_normal  | Normal mutex.| 
| ffrt_mutex_recursive  | Recursive mutex.| 
| ffrt_mutex_default  | Default mutex.| 


### ffrt_qos_default_t

```
enum ffrt_qos_default_t
```
**Description**
Enumerates the task QoS types.

**Since**: 10

| Value| Description| 
| -------- | -------- |
| ffrt_qos_inherit  | Inherited task QoS.| 
| ffrt_qos_background  | Background task.| 
| ffrt_qos_utility  | Real-time utility.| 
| ffrt_qos_default  | Default type.| 
| ffrt_qos_user_initiated  | User initiated.| 


### ffrt_queue_priority_t

```
enum ffrt_queue_priority_t
```
**Description**
Enumerates the task priority types.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| ffrt_queue_priority_immediate  | Immediate priority.| 
| ffrt_queue_priority_high  | High priority.| 
| ffrt_queue_priority_low  | Low priority.| 
| ffrt_queue_priority_idle  | Lowest priority.| 


### ffrt_queue_type_t

```
enum ffrt_queue_type_t
```
**Description**
Enumerates the queue types.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| ffrt_queue_serial  | Serial queue| 
| ffrt_queue_concurrent  | Concurrent queue.| 
| ffrt_queue_max  | Invalid queue type.| 


### ffrt_storage_size_t

```
enum ffrt_storage_size_t
```
**Description**
Enumerates the storage sizes available for different types of structs.

**Since**: 10

| Value| Description| 
| -------- | -------- |
| ffrt_task_attr_storage_size  | Pointer to the task attribute.| 
| ffrt_auto_managed_function_storage_size  | Describes a task execution function.| 
| ffrt_mutex_storage_size  | Storage size for the mutex struct.| 
| ffrt_cond_storage_size  | Storage size for the condition variable struct.| 
| ffrt_queue_attr_storage_size  | Pointer to the queue attribute.| 


## Function Description


### ffrt_alloc_auto_managed_function_storage_base()

```
FFRT_C_API void* ffrt_alloc_auto_managed_function_storage_base (ffrt_function_kind_t kind)
```
**Description**
Applies for memory for the task execution function struct.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| kind | Type of the task execution function, which can be general or queue. | 

**Returns**

Returns a non-null pointer if the memory is allocated; returns a null pointer otherwise.


### ffrt_cond_broadcast()

```
FFRT_C_API int ffrt_cond_broadcast (ffrt_cond_t * cond)
```
**Description**
Unblocks all threads currently blocked on a condition variable.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| cond | Pointer to the condition variable. | 

**Returns**

Returns **ffrt_success** if all the threads are unblocked; returns **ffrt_error_inval** otherwise.


### ffrt_cond_destroy()

```
FFRT_C_API int ffrt_cond_destroy (ffrt_cond_t * cond)
```
**Description**
Destroys a condition variable.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| cond | Pointer to the condition variable. | 

**Returns**

Returns **ffrt_success** if the condition variable is destroyed; returns **ffrt_error_inval** otherwise.


### ffrt_cond_init()

```
FFRT_C_API int ffrt_cond_init (ffrt_cond_t * cond, const ffrt_condattr_t * attr )
```
**Description**
Initializes a condition variable.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| cond | Pointer to the condition variable. | 
| attr | Pointer to the condition variable attribute. | 

**Returns**

Returns **ffrt_success** if the condition variable is initialized; returns **ffrt_error_inval** otherwise.


### ffrt_cond_signal()

```
FFRT_C_API int ffrt_cond_signal (ffrt_cond_t * cond)
```
**Description**
Unblocks at least one of the threads that are blocked on a condition variable.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| cond | Pointer to the condition variable. | 

**Returns**

Returns **ffrt_success** if at least one of the threads is unblocked; returns **ffrt_error_inval** otherwise.


### ffrt_cond_timedwait()

```
FFRT_C_API int ffrt_cond_timedwait (ffrt_cond_t * cond, ffrt_mutex_t * mutex, const struct timespec * time_point )
```
**Description**
Blocks the calling thread on a condition variable for a given duration.

If **ffrt_cond_signal** or **ffrt_cond_broadcast** is not called to unblock the thread when the maximum wait time is reached, the thread is automatically unblocked.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| cond | Pointer to the condition variable. | 
| mutex | Pointer to the mutex. | 
| time_point | Pointer to the maximum duration that the thread is blocked. If **ffrt_cond_signal** or **ffrt_cond_broadcast** is not called to unblock the thread when the maximum duration reaches, the thread is automatically unblocked. | 

**Returns**

Returns **ffrt_success** if the thread is blocked; returns **ffrt_error_timedout** if the maximum duration reaches; returns **ffrt_error_inval** if the waiting fails.


### ffrt_cond_wait()

```
FFRT_C_API int ffrt_cond_wait (ffrt_cond_t * cond, ffrt_mutex_t * mutex )
```
**Description**
Blocks the calling thread on a condition variable.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| cond | Pointer to the condition variable. | 
| mutex | Pointer to the mutex. | 

**Returns**

Returns **ffrt_success** if the thread is blocked; returns **ffrt_error_inval** if the blocking fails.


### ffrt_get_current_queue()

```
FFRT_C_API ffrt_queue_t ffrt_get_current_queue (void )
```
**Description**
Obtains the ArkTS Worker thread queue.

**Deprecated version**: 18

**Since**: 12

**Returns**

Returns the handle to the thread queue.


### ffrt_get_main_queue()

```
FFRT_C_API ffrt_queue_t ffrt_get_main_queue (void )
```
**Description**
Obtains the main thread queue.

**Since**: 12

**Returns**

Returns the handle to the main thread queue.


### ffrt_loop_create()

```
FFRT_C_API ffrt_loop_t ffrt_loop_create (ffrt_queue_t queue)
```
**Description**
Creates a loop.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| queue | Concurrent queue. | 

**Returns**

Returns the **ffrt_loop_t** object if the loop is created; returns a null pointer otherwise.


### ffrt_loop_destroy()

```
FFRT_C_API int ffrt_loop_destroy (ffrt_loop_t loop)
```
**Description**
Destroys a loop.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| loop | Loop object. | 

**Returns**

Returns **0** if the loop is destroyed; returns **-1** otherwise.


### ffrt_loop_epoll_ctl()

```
FFRT_C_API int ffrt_loop_epoll_ctl (ffrt_loop_t loop, int op, int fd, uint32_t events, void * data, ffrt_poller_cb cb )
```
**Description**
Manages listening events on a loop.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| loop | Loop object. | 
| op | Operation to be performed. | 
| fd | File descriptor. | 
| events | Events linked to the file descriptor. | 
| data | Pointer to the input parameter in the callback function invoked upon event changes. | 
| cb | Callback function invoked upon event changes. | 

**Returns**

Returns **0** if the operation is successful; returns **-1** otherwise.


### ffrt_loop_run()

```
FFRT_C_API int ffrt_loop_run (ffrt_loop_t loop)
```
**Description**
Runs a loop.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| loop | Loop object. | 

**Returns**

Returns **0** if the loop runs successfully; returns **-1** otherwise.


### ffrt_loop_stop()

```
FFRT_C_API void ffrt_loop_stop (ffrt_loop_t loop)
```
**Description**
Stops a loop.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| loop | Loop object. | 


### ffrt_loop_timer_start()

```
FFRT_C_API ffrt_timer_t ffrt_loop_timer_start (ffrt_loop_t loop, uint64_t timeout, void * data, ffrt_timer_cb cb, bool repeat )
```
**Description**
Starts the timer on a loop.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| loop | Loop object. | 
| timeout | Timeout period, in milliseconds. | 
| data | Pointer to the input parameter in the callback function invoked upon event changes. | 
| cb | Callback function invoked upon event changes. | 
| repeat | Whether to repeat the timer. | 

**Returns**

Returns the timer handle.


### ffrt_loop_timer_stop()

```
FFRT_C_API int ffrt_loop_timer_stop (ffrt_loop_t loop, ffrt_timer_t handle )
```
**Description**
Stops the timer on a loop.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| loop | Loop object. | 
| handle | Timer handle. | 

**Returns**

Returns **0** if the operation is successful; returns **-1** otherwise.


### ffrt_mutex_destroy()

```
FFRT_C_API int ffrt_mutex_destroy (ffrt_mutex_t * mutex)
```
**Description**
Destroys a mutex.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mutex | Pointer to the mutex. | 

**Returns**

Returns **ffrt_success** if the mutex is destroyed; returns **ffrt_error_inval** otherwise.


### ffrt_mutex_init()

```
FFRT_C_API int ffrt_mutex_init (ffrt_mutex_t * mutex, const ffrt_mutexattr_t * attr )
```
**Description**
Initializes a mutex.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mutex | Pointer to the mutex. | 
| attr | Pointer to the mutex attribute. | 

**Returns**

Returns **ffrt_success** if the mutex is initialized; returns **ffrt_error_inval** otherwise.


### ffrt_mutex_lock()

```
FFRT_C_API int ffrt_mutex_lock (ffrt_mutex_t * mutex)
```
**Description**
Locks a mutex.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mutex | Pointer to the mutex. | 

**Returns**

Returns **ffrt_success** if the mutex is locked; returns **ffrt_error_inval** or blocks the calling thread otherwise.


### ffrt_mutex_trylock()

```
FFRT_C_API int ffrt_mutex_trylock (ffrt_mutex_t * mutex)
```
**Description**
Attempts to lock a mutex.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mutex | Pointer to the mutex. | 

**Returns**

Returns **ffrt_success** if the mutex is locked; returns **ffrt_error_inval** or **ffrt_error_busy** otherwise.


### ffrt_mutex_unlock()

```
FFRT_C_API int ffrt_mutex_unlock (ffrt_mutex_t * mutex)
```
**Description**
Unlocks a mutex.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mutex | Pointer to the mutex. | 

**Returns**

Returns **ffrt_success** if the mutex is unlocked; returns **ffrt_error_inval** otherwise.


### ffrt_mutexattr_destroy()

```
FFRT_C_API int ffrt_mutexattr_destroy (ffrt_mutexattr_t * attr)
```
**Description**
Destroys the mutex attribute. This API needs to be called by users.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the mutex attribute. | 

**Returns**

Returns **ffrt_success** if the mutex attribute is destroyed; returns **ffrt_error_inval** otherwise.


### ffrt_mutexattr_gettype()

```
FFRT_C_API int ffrt_mutexattr_gettype (ffrt_mutexattr_t * attr, int * type )
```
**Description**
Obtains the mutex type.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the mutex attribute. | 
| type | Pointer to the mutex type. | 

**Returns**

Returns **ffrt_success** if the mutex is obtained; returns **ffrt_error_inval** if the pointer to the mutex attribute or mutex type is null.


### ffrt_mutexattr_init()

```
FFRT_C_API int ffrt_mutexattr_init (ffrt_mutexattr_t * attr)
```
**Description**
Initializes the mutex attribute.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the mutex attribute. | 

**Returns**

Returns **ffrt_success** if the mutex attribute is initialized; returns **ffrt_error_inval** otherwise.


### ffrt_mutexattr_settype()

```
FFRT_C_API int ffrt_mutexattr_settype (ffrt_mutexattr_t * attr, int type )
```
**Description**
Sets the mutex attribute type.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the mutex attribute. | 
| type | Mutex type. | 

**Returns**

Returns **ffrt_success** if the mutex is set; returns **ffrt_error_inval** if the pointer to the mutex attribute is null or the mutex is not of the **ffrt_mutex_normal** or **ffrt_mutex_recursive** type.


### ffrt_queue_attr_destroy()

```
FFRT_C_API void ffrt_queue_attr_destroy (ffrt_queue_attr_t * attr)
```
**Description**
Destroys the queue attribute.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute. | 


### ffrt_queue_attr_get_callback()

```
FFRT_C_API ffrt_function_header_t* ffrt_queue_attr_get_callback (const ffrt_queue_attr_t * attr)
```
**Description**
Obtains the callback that is invoked when a queue task times out.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute. | 

**Returns**

Returns the callback.


### ffrt_queue_attr_get_max_concurrency()

```
FFRT_C_API int ffrt_queue_attr_get_max_concurrency (const ffrt_queue_attr_t * attr)
```
**Description**
Obtains the maximum concurrency of a queue, which must be a concurrent queue.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute. | 

**Returns**

Returns the maximum concurrency.


### ffrt_queue_attr_get_qos()

```
FFRT_C_API ffrt_qos_t ffrt_queue_attr_get_qos (const ffrt_queue_attr_t * attr)
```
**Description**
Obtains the queue QoS.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute. | 

**Returns**

Returns the queue QoS.


### ffrt_queue_attr_get_timeout()

```
FFRT_C_API uint64_t ffrt_queue_attr_get_timeout (const ffrt_queue_attr_t * attr)
```
**Description**
Obtains the queue timeout.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute. | 

**Returns**

Returns the timeout.


### ffrt_queue_attr_init()

```
FFRT_C_API int ffrt_queue_attr_init (ffrt_queue_attr_t * attr)
```
**Description**
Initializes the queue attribute.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute. | 

**Returns**

Returns **0** if the queue attribute is initialized; returns **-1** otherwise.


### ffrt_queue_attr_set_callback()

```
FFRT_C_API void ffrt_queue_attr_set_callback (ffrt_queue_attr_t * attr, ffrt_function_header_t * f )
```
**Description**
Sets a callback that is invoked when a queue task times out.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute. | 
| f | Pointer to the callback function invoked upon a timeout. | 


### ffrt_queue_attr_set_max_concurrency()

```
FFRT_C_API void ffrt_queue_attr_set_max_concurrency (ffrt_queue_attr_t * attr, const int max_concurrency )
```
**Description**
Sets the maximum concurrency for a queue, which must be a concurrent queue.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute. | 
| max_concurrency | Maximum concurrency. | 


### ffrt_queue_attr_set_qos()

```
FFRT_C_API void ffrt_queue_attr_set_qos (ffrt_queue_attr_t * attr, ffrt_qos_t qos )
```
**Description**
Sets the queue QoS.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute. | 
| qos | QoS. | 


### ffrt_queue_attr_set_timeout()

```
FFRT_C_API void ffrt_queue_attr_set_timeout (ffrt_queue_attr_t * attr, uint64_t timeout_us )
```
**Description**
Sets the queue timeout.

The minimum timeout value is 1 ms. Any value set below this threshold will default to 1 ms.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute. | 
| timeout_us | Queue timeout, in microseconds. | 


### ffrt_queue_cancel()

```
FFRT_C_API int ffrt_queue_cancel (ffrt_task_handle_t handle)
```
**Description**
Cancels a task in the queue.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Task handle. | 

**Returns**

Returns **0** if the task is canceled; returns **-1** otherwise.


### ffrt_queue_create()

```
FFRT_C_API ffrt_queue_t ffrt_queue_create (ffrt_queue_type_t type, const char * name, const ffrt_queue_attr_t * attr )
```
**Description**
Creates a queue.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Queue type. | 
| name | Pointer to the queue name. | 
| attr | Pointer to the queue attribute. | 

**Returns**

Returns a non-null queue handle if the queue is created; returns a null pointer otherwise.


### ffrt_queue_destroy()

```
FFRT_C_API void ffrt_queue_destroy (ffrt_queue_t queue)
```
**Description**
Destroys a queue.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| queue | Queue handle. | 


### ffrt_queue_submit()

```
FFRT_C_API void ffrt_queue_submit (ffrt_queue_t queue, ffrt_function_header_t * f, const ffrt_task_attr_t * attr )
```
**Description**
Submits a task to a queue.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| queue | Queue handle. | 
| f | Pointer to the task execution function. | 
| attr | Pointer to the task attribute. | 


### ffrt_queue_submit_f()

```
FFRT_C_API void ffrt_queue_submit_f (ffrt_queue_t queue, ffrt_function_t func, void * arg, const ffrt_task_attr_t * attr )
```
**Description**
Submits a task to a queue. It is a simplified form of **ffrt_queue_submit**.

Assuming no destroy callback is needed, the task function and parameters are encapsulated into a queue task structure, which is then passed to **ffrt_queue_submit** along with other parameters.

**Since**: 20

**Parameters**

| Name| Description| 
| -------- | -------- |
| queue | Queue handle. | 
| func | Task function. | 
| arg | Pointer to the argument. | 
| attr | Pointer to the task attribute. | 

**Reference**

[ffrt_queue_submit](#ffrt_queue_submit)


### ffrt_queue_submit_h()

```
FFRT_C_API ffrt_task_handle_t ffrt_queue_submit_h (ffrt_queue_t queue, ffrt_function_header_t * f, const ffrt_task_attr_t * attr )
```
**Description**
Submits a task to a queue, and obtains the task handle.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| queue | Queue handle. | 
| f | Pointer to the task execution function. | 
| attr | Pointer to the task attribute. | 

**Returns**

Returns a non-null task handle if the task is submitted; returns a null pointer otherwise.


### ffrt_queue_submit_h_f()

```
FFRT_C_API ffrt_task_handle_t ffrt_queue_submit_h_f (ffrt_queue_t queue, ffrt_function_t func, void * arg, const ffrt_task_attr_t * attr )
```
**Description**
Submits a task to a queue, and obtains the task handle. It is a simplified form of **ffrt_queue_submit_h**.

Assuming no destroy callback is needed, the task function and parameters are encapsulated into a queue task structure, which is then passed to **ffrt_queue_submit_h** along with other parameters.

**Since**: 20

**Parameters**

| Name| Description| 
| -------- | -------- |
| queue | Queue handle. | 
| func | Task function. | 
| arg | Pointer to the argument. | 
| attr | Pointer to the task attribute. | 

**Returns**

Returns a non-null task handle if the task is submitted; returns a null pointer otherwise.

**Reference**

[ffrt_queue_submit_h](#ffrt_queue_submit_h)


### ffrt_queue_wait()

```
FFRT_C_API void ffrt_queue_wait (ffrt_task_handle_t handle)
```
**Description**
Waits until a task in the queue is complete.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Task handle. | 


### ffrt_rwlock_destroy()

```
FFRT_C_API int ffrt_rwlock_destroy (ffrt_rwlock_t * rwlock)
```
**Description**
Destroys the read-write lock.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| rwlock | Pointer to the read-write lock. | 

**Returns**

Returns **ffrt_success** if the read-write lock is successfully destroyed; returns **ffrt_error_inval** otherwise.


### ffrt_rwlock_init()

```
FFRT_C_API int ffrt_rwlock_init (ffrt_rwlock_t * rwlock, const ffrt_rwlockattr_t * attr )
```
**Description**
Initializes a read-write lock.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| rwlock | Pointer to the read-write lock. | 
| attr | Pointer to the read-write attribute. | 

**Returns**

Returns **ffrt_success** if the read-write lock is successfully initialized; returns **ffrt_error_inval** otherwise.


### ffrt_rwlock_rdlock()

```
FFRT_C_API int ffrt_rwlock_rdlock (ffrt_rwlock_t * rwlock)
```
**Description**
Obtains a read lock.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| rwlock | Pointer to the read-write lock. | 

**Returns**

Returns **ffrt_success** if the read lock is successfully obtained; returns **ffrt_error_inval** otherwise or blocks the task.


### ffrt_rwlock_tryrdlock()

```
FFRT_C_API int ffrt_rwlock_tryrdlock (ffrt_rwlock_t * rwlock)
```
**Description**
Attempts to obtain a read lock; if it fails, the function returns immediately.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| rwlock | Pointer to the read-write lock. | 

**Returns**

Returns **ffrt_success** if the read lock is successfully obtained; returns **ffrt_error_inval** or **ffrt_error_busy** otherwise.


### ffrt_rwlock_trywrlock()

```
FFRT_C_API int ffrt_rwlock_trywrlock (ffrt_rwlock_t * rwlock)
```
**Description**
Attempts to obtain a write lock.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| rwlock | Pointer to the read-write lock. | 

**Returns**

Returns **ffrt_success** if the write lock is successfully obtained; returns **ffrt_error_inval** or **ffrt_error_busy** otherwise.


### ffrt_rwlock_unlock()

```
FFRT_C_API int ffrt_rwlock_unlock (ffrt_rwlock_t * rwlock)
```
**Description**
Releases the read-write lock.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| rwlock | Pointer to the read-write lock. | 

**Returns**

Returns **ffrt_success** if the read-write lock is successfully released; returns **ffrt_error_inval** otherwise.


### ffrt_rwlock_wrlock()

```
FFRT_C_API int ffrt_rwlock_wrlock (ffrt_rwlock_t * rwlock)
```
**Description**
Obtains a write lock.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| rwlock | Pointer to the read-write lock. | 

**Returns**

Returns **ffrt_success** if the write lock is successfully obtained; returns **ffrt_error_inval** otherwise or blocks the task.


### ffrt_submit_base()

```
FFRT_C_API void ffrt_submit_base (ffrt_function_header_t * f, const ffrt_deps_t * in_deps, const ffrt_deps_t * out_deps, const ffrt_task_attr_t * attr )
```
**Description**
Submits a task.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| f | Pointer to the task execution function. | 
| in_deps | Pointer to the input dependencies. | 
| out_deps | Pointer to the output dependencies. | 
| attr | Pointer to the task attribute. | 

### ffrt_submit_f()

```
FFRT_C_API void ffrt_submit_f (ffrt_function_t func, void * arg, const ffrt_deps_t * in_deps, const ffrt_deps_t * out_deps, const ffrt_task_attr_t * attr )
```
**Description**
Submits a task. It is a simplified form of **ffrt_submit_base**.

Assuming no destroy callback is needed, the task function and parameters are encapsulated into a general task structure, which is then passed to **ffrt_submit_base** along with other parameters.

**Since**: 20

**Parameters**

| Name| Description| 
| -------- | -------- |
| func | Task function. | 
| arg | Pointer to the argument. | 
| in_deps | Pointer to the input dependencies. | 
| out_deps | Pointer to the output dependencies. | 
| attr | Pointer to the task attribute. | 

**Reference**

[ffrt_submit_base](#ffrt_submit_base)


### ffrt_submit_h_base()

```
FFRT_C_API ffrt_task_handle_t ffrt_submit_h_base (ffrt_function_header_t * f, const ffrt_deps_t * in_deps, const ffrt_deps_t * out_deps, const ffrt_task_attr_t * attr )
```
**Description**
Submits a task, and obtains the task handle.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| f | Pointer to the task execution function. | 
| in_deps | Pointer to the input dependencies. | 
| out_deps | Pointer to the output dependencies. | 
| attr | Pointer to the task attribute. | 

**Returns**

Returns a non-null task handle if the task is submitted; returns a null pointer otherwise.


### ffrt_submit_h_f()

```
FFRT_C_API ffrt_task_handle_t ffrt_submit_h_f (ffrt_function_t func, void * arg, const ffrt_deps_t * in_deps, const ffrt_deps_t * out_deps, const ffrt_task_attr_t * attr )
```
**Description**
Submits a task, and obtains the task handle. It is a simplified form of **ffrt_submit_h_base**.

Assuming no destroy callback is needed, the task function and parameters are encapsulated into a general task structure, which is then passed to **ffrt_submit_h_base** along with other parameters.

**Since**: 20

**Parameters**

| Name| Description| 
| -------- | -------- |
| func | Task function. | 
| arg | Pointer to the argument. | 
| in_deps | Pointer to the input dependencies. | 
| out_deps | Pointer to the output dependencies. | 
| attr | Pointer to the task attribute. | 

**Returns**

Returns a non-null task handle if the task is submitted; returns a null pointer otherwise.

**Reference**

[ffrt_submit_h_base](#ffrt_submit_h_base)


### ffrt_task_attr_destroy()

```
FFRT_C_API void ffrt_task_attr_destroy (ffrt_task_attr_t * attr)
```
**Description**
Destroys a task attribute.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute. | 


### ffrt_task_attr_get_delay()

```
FFRT_C_API uint64_t ffrt_task_attr_get_delay (const ffrt_task_attr_t * attr)
```
**Description**
Obtains the task delay time.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute. | 

**Returns**

Returns the delay time.


### ffrt_task_attr_get_name()

```
FFRT_C_API const char* ffrt_task_attr_get_name (const ffrt_task_attr_t * attr)
```
**Description**
Obtains a task name.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute. | 

**Returns**

Returns a non-null pointer to the task name if the name is obtained; returns a null pointer otherwise.


### ffrt_task_attr_get_qos()

```
FFRT_C_API ffrt_qos_t ffrt_task_attr_get_qos (const ffrt_task_attr_t * attr)
```
**Description**
Obtains the task QoS.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute. | 

**Returns**

Returns the QoS, which is **ffrt_qos_default** by default.


### ffrt_task_attr_get_queue_priority()

```
FFRT_C_API ffrt_queue_priority_t ffrt_task_attr_get_queue_priority (const ffrt_task_attr_t * attr)
```
**Description**
Obtains the task priority in the queue.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute. | 

**Returns**

Returns the task priority.


### ffrt_task_attr_get_stack_size()

```
FFRT_C_API uint64_t ffrt_task_attr_get_stack_size (const ffrt_task_attr_t * attr)
```
**Description**
Obtains the task stack size.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute. | 

**Returns**

Returns the task stack size, in bytes.


### ffrt_task_attr_init()

```
FFRT_C_API int ffrt_task_attr_init (ffrt_task_attr_t * attr)
```
**Description**
Initializes a task attribute.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute. | 

**Returns**

Returns **0** if the task attribute is initialized; returns **-1** otherwise.


### ffrt_task_attr_set_delay()

```
FFRT_C_API void ffrt_task_attr_set_delay (ffrt_task_attr_t * attr, uint64_t delay_us )
```
**Description**
Sets the task delay time.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute. | 
| delay_us | Delay time, in microseconds. | 


### ffrt_task_attr_set_name()

```
FFRT_C_API void ffrt_task_attr_set_name (ffrt_task_attr_t * attr, const char * name )
```
**Description**
Sets a task name.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute. | 
| name | Pointer to the task name. | 


### ffrt_task_attr_set_qos()

```
FFRT_C_API void ffrt_task_attr_set_qos (ffrt_task_attr_t * attr, ffrt_qos_t qos )
```
**Description**
Sets the task QoS.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute. | 
| qos | Task QoS. | 


### ffrt_task_attr_set_queue_priority()

```
FFRT_C_API void ffrt_task_attr_set_queue_priority (ffrt_task_attr_t * attr, ffrt_queue_priority_t priority )
```
**Description**
Sets the task priority in the queue.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute. | 
| priority | Task priority. | 


### ffrt_task_attr_set_stack_size()

```
FFRT_C_API void ffrt_task_attr_set_stack_size (ffrt_task_attr_t * attr, uint64_t size )
```
**Description**
Sets the task stack size.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute. | 
| size | Size of the task stack, in bytes. | 


### ffrt_task_handle_dec_ref()

```
FFRT_C_API uint32_t ffrt_task_handle_dec_ref (ffrt_task_handle_t handle)
```
**Description**
Decreases the number of task handle references.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Task handle. | 

**Returns**

Returns the original number of task handle references.


### ffrt_task_handle_destroy()

```
FFRT_C_API void ffrt_task_handle_destroy (ffrt_task_handle_t handle)
```
**Description**
Destroys a task handle.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Task handle. | 


### ffrt_task_handle_inc_ref()

```
FFRT_C_API uint32_t ffrt_task_handle_inc_ref (ffrt_task_handle_t handle)
```
**Description**
Increases the number of task handle references.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Task handle. | 

**Returns**

Returns the original number of task handle references.


### ffrt_this_task_get_id()

```
FFRT_C_API uint64_t ffrt_this_task_get_id (void )
```
**Description**
Obtains the ID of this task.

**Since**: 10

**Returns**

Returns the ID.


### ffrt_this_task_get_qos()

```
FFRT_C_API ffrt_qos_t ffrt_this_task_get_qos (void )
```
**Description**
Obtains the task QoS.

**Since**: 12

**Returns**

Returns the task QoS.


### ffrt_this_task_update_qos()

```
FFRT_C_API int ffrt_this_task_update_qos (ffrt_qos_t qos)
```
**Description**
Updates the task QoS.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| qos | QoS to be updated. | 

**Returns**

Returns **0** if the QoS is updated; returns **-1** otherwise.


### ffrt_timer_start()

```
FFRT_C_API ffrt_timer_t ffrt_timer_start (ffrt_qos_t qos, uint64_t timeout, void * data, ffrt_timer_cb cb, bool repeat )
```
**Description**
Starts the timer.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| qos | QoS. | 
| timeout | Timeout period, in milliseconds. | 
| data | Pointer to the input parameter in the callback function invoked upon a timeout. | 
| cb | Callback function invoked upon a timeout. | 
| repeat | Whether to repeat the timer (not supported yet). | 

**Returns**

Returns the timer handle.


### ffrt_timer_stop()

```
FFRT_C_API int ffrt_timer_stop (ffrt_qos_t qos, ffrt_timer_t handle )
```
**Description**
Stops the timer.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| qos | QoS. | 
| handle | Handle to the timer. | 

**Returns**

Returns **0** if the timer is stopped; returns **-1** otherwise.


### ffrt_usleep()

```
FFRT_C_API int ffrt_usleep (uint64_t usec)
```
**Description**
Sets the fixed sleep time.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| usec | Sleep time, in microseconds. | 

**Returns**

Returns **ffrt_success** if the thread is suspended; returns **ffrt_error** otherwise.


### ffrt_wait()

```
FFRT_C_API void ffrt_wait (void )
```
**Description**
Waits until all submitted tasks are complete.

**Since**: 10


### ffrt_wait_deps()

```
FFRT_C_API void ffrt_wait_deps (const ffrt_deps_t * deps)
```
**Description**
Waits until the dependent tasks are complete.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| deps | Pointer to the dependencies. | 


### ffrt_yield()

```
FFRT_C_API void ffrt_yield (void )
```
**Description**
Passes control to other tasks so that they can be executed.

**Since**: 10
