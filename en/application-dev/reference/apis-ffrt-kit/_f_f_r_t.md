# FFRT


## Overview

Function Flow Runtime (FFRT) is a software runtime library that works with the Function Flow programming model. It is used to schedule and execute tasks of an application developed on the Function Flow programming model.

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [condition_variable.h](condition__variable_8h.md) | Declares the condition variable interfaces in C.| 
| [loop.h](loop_8h.md) | Declares the loop interfaces in C.| 
| [mutex.h](mutex_8h.md) | Declares the mutex interfaces in C.| 
| [queue.h](queue_8h.md) | Declares the queue interfaces in C.| 
| [sleep.h](sleep_8h.md) | Declares the sleep and yield interfaces in C.| 
| [task.h](task_8h.md) | Declares the task interfaces in C.| 
| [timer.h](timer_8h.md) | Declares the timer interfaces in C.| 
| [type_def.h](type__def_8h.md) | Declares the common types.| 


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
| typedef void\*&nbsp;&nbsp;**ffrt_loop_t** |  | 
| typedef void\*&nbsp;&nbsp;ffrt_queue_t | Defines the handle to a queue.| 
| typedef int ffrt_qos_t | Defines the QoS type.| 
| typedef void(\*ffrt_function_t ) (void\*) | Defines the type of the pointer to a task execution function.| 
| typedef void\*&nbsp;&nbsp;ffrt_task_handle_t | Defines the handle to a task.| 
| typedef void (\*[ffrt_poller_cb](#ffrt_poller_cb)) (void\* data, uint32_t event) | Defines the callback for ffrt_poller_cb.| 
| typedef void (\*[ffrt_timer_cb](#ffrt_timer_cb)) (void\* data) | Defines the callback for ffrt_timer_cb.| 
| typedef int [ffrt_timer_t](#ffrt_timer_t) | Defines the ffrt_timer_t type.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [ffrt_queue_type_t](#ffrt_queue_type_t) { ffrt_queue_serial = 0, ffrt_queue_concurrent, ffrt_queue_max } | Enumerates the queue types.| 
| [ffrt_task_priority_t](#ffrt_task_priority_t) { ffrt_task_priority_immediate = 0, ffrt_task_priority_high = 1, ffrt_task_priority_low = 2, ffrt_task_priority_idle } | Enumerates the task priority types.| 
| [ffrt_qos_default_t](#ffrt_qos_default_t) {<br>ffrt_qos_inherit = -1, ffrt_qos_background, ffrt_qos_utility, ffrt_qos_default,<br>ffrt_qos_user_initiated<br>} | Enumerates the task QoS types.| 
| [ffrt_storage_size_t](#ffrt_storage_size_t) {<br>ffrt_task_attr_storage_size = 128, ffrt_auto_managed_function_storage_size = 64 + sizeof(ffrt_function_header_t), ffrt_mutex_storage_size = 64, ffrt_cond_storage_size = 64,<br>ffrt_queue_attr_storage_size = 128<br>} | Enumerates the storage sizes available for different types of structs.| 
| [ffrt_function_kind_t](#ffrt_function_kind_t) { ffrt_function_kind_general, ffrt_function_kind_queue } | Enumerates the task types.| 
| [ffrt_dependence_type_t](#ffrt_dependence_type_t) { ffrt_dependence_data, ffrt_dependence_task } | Enumerates the dependency types.| 
| [ffrt_error_t](#ffrt_error_t) {<br>ffrt_error = -1, ffrt_success = 0, ffrt_error_nomem = ENOMEM, ffrt_error_timedout = ETIMEDOUT,<br>ffrt_error_busy = EBUSY, ffrt_error_inval = EINVAL<br>} | Enumerates the FFRT error codes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| FFRT_C_API int [ffrt_cond_init](#ffrt_cond_init) ([ffrt_cond_t](ffrt__cond__t.md)\* cond, const [ffrt_condattr_t](ffrt__condattr__t.md)\* attr) | Initializes a condition variable.| 
| FFRT_C_API int [ffrt_cond_signal](#ffrt_cond_signal) ([ffrt_cond_t](ffrt__cond__t.md)\* cond) | Unblocks at least one of the threads that are blocked on a condition variable.| 
| FFRT_C_API int [ffrt_cond_broadcast](#ffrt_cond_broadcast) ([ffrt_cond_t](ffrt__cond__t.md)\* cond) | Unblocks all threads currently blocked on a condition variable.| 
| FFRT_C_API int [ffrt_cond_wait](#ffrt_cond_wait) ([ffrt_cond_t](ffrt__cond__t.md)\* cond, [ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | Blocks the calling thread on a condition variable.| 
| FFRT_C_API int [ffrt_cond_timedwait](#ffrt_cond_timedwait) ([ffrt_cond_t](ffrt__cond__t.md)\* cond, [ffrt_mutex_t](ffrt__mutex__t.md)\* mutex, const struct timespec\* time_point) | Blocks the calling thread on a condition variable for a given duration.| 
| FFRT_C_API int [ffrt_cond_destroy](#ffrt_cond_destroy) ([ffrt_cond_t](ffrt__cond__t.md)\* cond) | Destroys a condition variable.| 
| FFRT_C_API ffrt_loop_t [ffrt_loop_create](#ffrt_loop_create) (ffrt_queue_t queue) | Creates a loop.| 
| FFRT_C_API int [ffrt_loop_destory](#ffrt_loop_destory) (ffrt_loop_t loop) | Destroys a loop.| 
| FFRT_C_API int [ffrt_loop_run](#ffrt_loop_run) (ffrt_loop_t loop) | Runs a loop.| 
| FFRT_C_API void [ffrt_loop_stop](#ffrt_loop_stop) (ffrt_loop_t loop) | Stops a loop.| 
| FFRT_C_API int [ffrt_loop_epoll_ctl](#ffrt_loop_epoll_ctl) (ffrt_loop_t loop, int op, int fd, uint32_t events, void\* data, [ffrt_poller_cb](#ffrt_poller_cb) cb) | Manages listening events on a loop.| 
| FFRT_C_API [ffrt_timer_t](#ffrt_timer_t)[ffrt_loop_timer_start](#ffrt_loop_timer_start) (ffrt_loop_t loop, uint64_t timeout, void\* data, [ffrt_timer_cb](#ffrt_timer_cb) cb, bool repeat) | Starts the timer on a loop.| 
| FFRT_C_API int [ffrt_loop_timer_stop](#ffrt_loop_timer_stop) (ffrt_loop_t loop, [ffrt_timer_t](#ffrt_timer_t) handle) | Stops the timer on a loop.| 
| FFRT_C_API int [ffrt_mutex_init](#ffrt_mutex_init) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex, const [ffrt_mutexattr_t](ffrt__mutexattr__t.md)\* attr) | Initializes a mutex.| 
| FFRT_C_API int [ffrt_mutex_lock](#ffrt_mutex_lock) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | Locks a mutex.| 
| FFRT_C_API int [ffrt_mutex_unlock](#ffrt_mutex_unlock) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | Unlocks a mutex.| 
| FFRT_C_API int [ffrt_mutex_trylock](#ffrt_mutex_trylock) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | Attempts to lock a mutex.| 
| FFRT_C_API int [ffrt_mutex_destroy](#ffrt_mutex_destroy) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | Destroys a mutex.| 
| FFRT_C_API int [ffrt_queue_attr_init](#ffrt_queue_attr_init) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | Initializes a queue attribute.| 
| FFRT_C_API void [ffrt_queue_attr_destroy](#ffrt_queue_attr_destroy) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | Destroys a queue attribute.| 
| FFRT_C_API void [ffrt_queue_attr_set_qos](#ffrt_queue_attr_set_qos) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr, ffrt_qos_t qos) | Sets the queue QoS.| 
| FFRT_C_API ffrt_qos_t[ffrt_queue_attr_get_qos](#ffrt_queue_attr_get_qos) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | Obtains the queue QoS.| 
| FFRT_C_API void [ffrt_queue_attr_set_timeout](#ffrt_queue_attr_set_timeout) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr, uint64_t timeout_us) | Sets the queue timeout.| 
| FFRT_C_API uint64_t [ffrt_queue_attr_get_timeout](#ffrt_queue_attr_get_timeout) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | Obtains the queue timeout.| 
| FFRT_C_API void [ffrt_queue_attr_set_callback](#ffrt_queue_attr_set_callback) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr, [ffrt_function_header_t](ffrt__function__header__t.md)\* f) | Sets a callback that is invoked when a queue task times out.| 
| FFRT_C_API [ffrt_function_header_t](ffrt__function__header__t.md)\*&nbsp;&nbsp;[ffrt_queue_attr_get_callback](#ffrt_queue_attr_get_callback) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | Obtains the callback that is invoked when a queue task times out.| 
| FFRT_C_API void [ffrt_queue_attr_set_max_concurrency](#ffrt_queue_attr_set_max_concurrency) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr, const int max_concurrency) | Sets the maximum concurrency for a queue, which must be a concurrent queue.| 
| FFRT_C_API int [ffrt_queue_attr_get_max_concurrency](#ffrt_queue_attr_get_max_concurrency) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | Obtains the maximum concurrency of a queue, which must be a concurrent queue.| 
| FFRT_C_API ffrt_queue_t[ffrt_queue_create](#ffrt_queue_create) ([ffrt_queue_type_t](#ffrt_queue_type_t) type, const char\* name, const [ffrt_queue_attr_t](ffrt__queue__attr__t.md)\* attr) | Creates a queue.| 
| FFRT_C_API void [ffrt_queue_destroy](#ffrt_queue_destroy) (ffrt_queue_t queue) | Destroys a queue.| 
| FFRT_C_API void [ffrt_queue_submit](#ffrt_queue_submit) (ffrt_queue_t queue, [ffrt_function_header_t](ffrt__function__header__t.md)\* f, const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | Submits a task to a queue.| 
| FFRT_C_API ffrt_task_handle_t[ffrt_queue_submit_h](#ffrt_queue_submit_h) (ffrt_queue_t queue, [ffrt_function_header_t](ffrt__function__header__t.md)\* f, const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | Submits a task to a queue, and obtains the task handle.| 
| FFRT_C_API void [ffrt_queue_wait](#ffrt_queue_wait) (ffrt_task_handle_t handle) | Waits until a task in the queue is complete.| 
| FFRT_C_API int [ffrt_queue_cancel](#ffrt_queue_cancel) (ffrt_task_handle_t handle) | Cancels a task in the queue.| 
| FFRT_C_API ffrt_queue_t[ffrt_get_main_queue](#ffrt_get_main_queue) () | Obtains the main thread queue.| 
| FFRT_C_API ffrt_queue_t[ffrt_get_current_queue](#ffrt_get_current_queue) () | Obtains the ArkTS Worker thread queue.| 
| FFRT_C_API int [ffrt_usleep](#ffrt_usleep) (uint64_t usec) | Suspends the calling thread for a given duration.| 
| FFRT_C_API void [ffrt_yield](#ffrt_yield) (void) | Passes control to other tasks so that they can be executed.| 
| FFRT_C_API int [ffrt_task_attr_init](#ffrt_task_attr_init) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | Initializes a task attribute.| 
| FFRT_C_API void [ffrt_task_attr_set_name](#ffrt_task_attr_set_name) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr, const char\* name) | Sets a task name.| 
| FFRT_C_API const char\*&nbsp;&nbsp;[ffrt_task_attr_get_name](#ffrt_task_attr_get_name) (const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | Obtains a task name.| 
| FFRT_C_API void [ffrt_task_attr_destroy](#ffrt_task_attr_destroy) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | Destroys a task attribute.| 
| FFRT_C_API void [ffrt_task_attr_set_qos](#ffrt_task_attr_set_qos) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr, ffrt_qos_t qos) | Sets the task QoS.| 
| FFRT_C_API ffrt_qos_t[ffrt_task_attr_get_qos](#ffrt_task_attr_get_qos) (const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | Obtains the task QoS.| 
| FFRT_C_API void [ffrt_task_attr_set_delay](#ffrt_task_attr_set_delay) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr, uint64_t delay_us) | Sets the task delay time.| 
| FFRT_C_API uint64_t [ffrt_task_attr_get_delay](#ffrt_task_attr_get_delay) (const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | Obtains the task delay time.| 
| FFRT_C_API void [ffrt_task_attr_set_queue_priority](#ffrt_task_attr_set_queue_priority) ([ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr, ffrt_queue_priority_t priority) | Sets the task priority in the queue.| 
| FFRT_C_API ffrt_queue_priority_t [ffrt_task_attr_get_queue_priority](#ffrt_task_attr_get_queue_priority) (const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | Obtains the task priority in the queue.| 
| FFRT_C_API int [ffrt_this_task_update_qos](#ffrt_this_task_update_qos) (ffrt_qos_t qos) | Updates the QoS of this task.| 
| FFRT_C_API ffrt_qos_t[ffrt_this_task_get_qos](#ffrt_this_task_get_qos) () | Obtains the QoS of this task.| 
| FFRT_C_API uint64_t [ffrt_this_task_get_id](#ffrt_this_task_get_id) (void) | Obtains the ID of this task.| 
| FFRT_C_API void\*&nbsp;&nbsp;[ffrt_alloc_auto_managed_function_storage_base](#ffrt_alloc_auto_managed_function_storage_base) ([ffrt_function_kind_t](#ffrt_function_kind_t) kind) | Applies for memory for the task execution function struct.| 
| FFRT_C_API void [ffrt_submit_base](#ffrt_submit_base) ([ffrt_function_header_t](ffrt__function__header__t.md)\* f, const [ffrt_deps_t](ffrt__deps__t.md)\* in_deps, const [ffrt_deps_t](ffrt__deps__t.md)\* out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | Submits a task.| 
| FFRT_C_API ffrt_task_handle_t[ffrt_submit_h_base](#ffrt_submit_h_base) ([ffrt_function_header_t](ffrt__function__header__t.md)\* f, const [ffrt_deps_t](ffrt__deps__t.md)\* in_deps, const [ffrt_deps_t](ffrt__deps__t.md)\* out_deps, const [ffrt_task_attr_t](ffrt__task__attr__t.md)\* attr) | Submits a task, and obtains the task handle.| 
| FFRT_C_API void [ffrt_task_handle_destroy](#ffrt_task_handle_destroy) (ffrt_task_handle_t handle) | Destroys a task handle.| 
| FFRT_C_API void [ffrt_wait_deps](#ffrt_wait_deps) (const [ffrt_deps_t](ffrt__deps__t.md)\* deps) | Waits until the dependent tasks are complete.| 
| FFRT_C_API void [ffrt_wait](#ffrt_wait) (void) | Waits until all submitted tasks are complete.| 
| FFRT_C_API [ffrt_timer_t](#ffrt_timer_t)[ffrt_timer_start](#ffrt_timer_start) (ffrt_qos_t qos, uint64_t timeout, void\* data, [ffrt_timer_cb](#ffrt_timer_cb) cb, bool repeat) | Starts the timer.| 
| FFRT_C_API int [ffrt_timer_stop](#ffrt_timer_stop) (ffrt_qos_t qos, [ffrt_timer_t](#ffrt_timer_t) handle) | Stops the timer.| 


### Variables

| Name| Description| 
| -------- | -------- |
| ffrt_function_t[ffrt_function_header_t::exec](#exec) | Function used to execute a task.| 
| ffrt_function_t[ffrt_function_header_t::destroy](#destroy) | Function used to destroy a task.| 
| uint64_t [ffrt_function_header_t::reserve](#reserve) [2] | Reserved bit.| 
| [ffrt_dependence_type_t](#ffrt_dependence_type_t)[ffrt_dependence_t::type](#type) | Dependency type.| 
| const void\*&nbsp;&nbsp;[ffrt_dependence_t::ptr](#ptr) | Address of the dependency data.| 
| uint32_t [ffrt_deps_t::len](#len) | Number of dependencies.| 
| const [ffrt_dependence_t](ffrt__dependence__t.md)\*&nbsp;&nbsp;[ffrt_deps_t::items](#items) | Dependency data.| 
| uint32_t [ffrt_task_attr_t::storage](#storage-46) [(ffrt_task_attr_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)] | Storage size of a task attribute.| 
| uint32_t [ffrt_queue_attr_t::storage](#storage-36) [(ffrt_queue_attr_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)] | Storage size of a queue attribute.| 
| long [ffrt_condattr_t::storage](#storage-56) | Storage size of a condition variable attribute.| 
| long [ffrt_mutexattr_t::storage](#storage-66) | Storage size of a mutex attribute.| 
| uint32_t [ffrt_mutex_t::storage](#storage-26) [(ffrt_mutex_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)] | Storage size of a mutex.| 
| uint32_t [ffrt_cond_t::storage](#storage-16) [(ffrt_cond_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)] | Storage size of a condition variable.| 


## Type Description


### ffrt_poller_cb

```
typedef void(*ffrt_poller_cb) (void* data, uint32_t event)
```

**Description**

Defines the callback for ffrt_poller_cb.


### ffrt_timer_cb

```
typedef void(*ffrt_timer_cb) (void* data)
```

**Description**

Defines the callback for ffrt_timer_cb.


### ffrt_timer_t

```
typedef int ffrt_timer_t
```

**Description**

Defines the ffrt_timer_t type.


## Enum Description


### ffrt_dependence_type_t

```
enum ffrt_dependence_type_t
```

**Description**

Enumerates the dependency types.

| Name| Description| 
| -------- | -------- |
| ffrt_dependence_data | Data dependency.| 
| ffrt_dependence_task | Task dependency.| 


### ffrt_error_t

```
enum ffrt_error_t
```

**Description**

Enumerates the FFRT error codes.

| Name| Value| Description| 
| -------- | -------- | -------- |
| ffrt_error | -1 | Failure.| 
| ffrt_success | 0 | Success.| 
| ffrt_error_nomem | ENOMEM | Insufficient memory.| 
| ffrt_error_timedout | ETIMEDOUT | Timeout.| 
| ffrt_error_busy | EBUSY | Try again.| 
| ffrt_error_inval | EINVAL | Invalid value.| 


### ffrt_function_kind_t

```
enum ffrt_function_kind_t
```

**Description**

Enumerates the task types.

| Name| Description| 
| -------- | -------- |
| ffrt_function_kind_general | General task.| 
| ffrt_function_kind_queue | Queue task.| 


### ffrt_qos_default_t

```
enum ffrt_qos_default_t
```

**Description**

Enumerates the task QoS types.

| Name| Value| Description| 
| -------- | -------- | -------- |
| ffrt_qos_inherit | ffrt_qos_inherit | Inherits the QoS of the current task.| 
| ffrt_qos_background | ffrt_qos_background | Background task.| 
| ffrt_qos_utility | ffrt_qos_utility | Real-time tool.| 
| ffrt_qos_default | ffrt_qos_default | Default type.| 
| ffrt_qos_user_initiated | ffrt_qos_user_initiated | User initiated.| 


### ffrt_queue_type_t

```
enum ffrt_queue_type_t
```

**Description**

Enumerates the queue types.

| Name| Value| Description| 
| -------- | -------- | -------- |
| ffrt_queue_serial | 0 | Queue queue.| 
| ffrt_queue_concurrent |  | Concurrent queue.| 
| ffrt_queue_max |  | Invalid queue type.| 


### ffrt_storage_size_t

```
enum ffrt_storage_size_t
```

**Description**

Enumerates the storage sizes available for different types of structs.

| Name| Value| Description| 
| -------- | -------- | -------- |
| ffrt_task_attr_storage_size | 128 | Storage size for the task attribute struct.| 
| ffrt_auto_managed_function_storage_size | 64 + sizeof(ffrt_function_header_t) | Storage size for the task execution function struct.| 
| ffrt_mutex_storage_size | 64 | Storage size for the mutex struct.| 
| ffrt_cond_storage_size | 64 | Storage size for the condition variable struct.| 
| ffrt_queue_attr_storage_size | 128 | Storage size for the queue attribute struct.| 


### ffrt_task_priority_t

```
enum ffrt_task_priority_t
```

**Description**

Enumerates the task priority types.

| Name| Value| Description| 
| -------- | -------- | -------- |
| ffrt_task_priority_immediate | 0 | Immediate priority.| 
| ffrt_task_priority_high | 1 | High priority.| 
| ffrt_task_priority_low | 2 | Low priority.| 
| ffrt_task_priority_idle |  | Lowest priority.| 


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
| kind | Type of the task execution function, which can be general or queue.| 

**Returns**

Returns a non-null pointer if the memory is allocated; returns a null pointer otherwise.


### ffrt_cond_broadcast()

```
FFRT_C_API int ffrt_cond_broadcast (ffrt_cond_t*  cond)
```

**Description**

Unblocks all threads currently blocked on a condition variable.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| cond | Pointer to the condition variable.| 

**Returns**

Returns **ffrt_success** if all the threads are unblocked; returns **ffrt_error_inval** otherwise.


### ffrt_cond_destroy()

```
FFRT_C_API int ffrt_cond_destroy (ffrt_cond_t*  cond)
```

**Description**

Destroys a condition variable.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| cond | Pointer to the condition variable.| 

**Returns**

Returns **ffrt_success** if the condition variable is destroyed; returns **ffrt_error_inval** otherwise.


### ffrt_cond_init()

```
FFRT_C_API int ffrt_cond_init (ffrt_cond_t*  cond, const ffrt_condattr_t*  attr )
```

**Description**

Initializes a condition variable.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| cond | Pointer to the condition variable.| 
| attr | Pointer to the condition variable attribute.| 

**Returns**

Returns **ffrt_success** if the condition variable is initialized; returns **ffrt_error_inval** otherwise.


### ffrt_cond_signal()

```
FFRT_C_API int ffrt_cond_signal (ffrt_cond_t*  cond)
```

**Description**

Unblocks at least one of the threads that are blocked on a condition variable.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| cond | Pointer to the condition variable.| 

**Returns**

Returns **ffrt_success** if at least one of the threads is unblocked; returns **ffrt_error_inval** otherwise.


### ffrt_cond_timedwait()

```
FFRT_C_API int ffrt_cond_timedwait (ffrt_cond_t*  cond, ffrt_mutex_t*  mutex, const struct timespec*  time_point )
```

**Description**

Blocks the calling thread on a condition variable for a given duration.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| cond | Pointer to the condition variable.| 
| mutex | Pointer to the mutex.| 
| time_point | Pointer to the maximum duration that the thread is blocked. If **ffrt_cond_signal** or **ffrt_cond_broadcast** is not called to unblock the thread when the maximum duration reaches, the thread is automatically unblocked.| 

**Returns**

Returns **ffrt_success** if the thread is blocked; returns **ffrt_error_timedout** if the maximum duration reaches; returns **ffrt_error_inval** if the blocking fails.


### ffrt_cond_wait()

```
FFRT_C_API int ffrt_cond_wait (ffrt_cond_t*  cond, ffrt_mutex_t*  mutex )
```

**Description**

Blocks the calling thread on a condition variable.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| cond | Pointer to the condition variable.| 
| mutex | Pointer to the mutex.| 

**Returns**

Returns **ffrt_success** if the thread is blocked; returns **ffrt_error_inval** if the blocking fails.


### ffrt_get_current_queue()

```
FFRT_C_API ffrt_queue_t ffrt_get_current_queue ()
```

**Description**

Obtains the ArkTS Worker thread queue.

**Since**: 12

**Returns**

Returns a non-null queue handle if the queue is created; returns a null pointer otherwise.


### ffrt_get_main_queue()

```
FFRT_C_API ffrt_queue_t ffrt_get_main_queue ()
```

**Description**

Obtains the main thread queue.

**Since**: 12

**Returns**

Returns a non-null queue handle if the queue is created; returns a null pointer otherwise.


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
| queue | Concurrent queue.| 

**Returns**

Returns the **ffrt_loop_t** object if the loop is created; returns a null pointer otherwise.


### ffrt_loop_destory()

```
FFRT_C_API int ffrt_loop_destory (ffrt_loop_t loop)
```

**Description**

Destroys a loop.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| loop | Loop object.| 

**Returns**

Returns **0** if the loop is destroyed; returns **-1** otherwise.


### ffrt_loop_epoll_ctl()

```
FFRT_C_API int ffrt_loop_epoll_ctl (ffrt_loop_t loop, int op, int fd, uint32_t events, void*  data, ffrt_poller_cb cb )
```

**Description**

Manages listening events on a loop.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| loop | Loop object.| 
| op | Operation to be performed.| 
| fd | File descriptor.| 
| events | Events linked to the file descriptor.| 
| data | Pointer to the input parameter in the callback function invoked upon event changes.| 
| cb | Callback function invoked upon event changes.| 

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
| loop | Loop object.| 

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
| loop | Loop object.| 


### ffrt_loop_timer_start()

```
FFRT_C_API ffrt_timer_t ffrt_loop_timer_start (ffrt_loop_t loop, uint64_t timeout, void*  data, ffrt_timer_cb cb, bool repeat )
```

**Description**

Starts the timer on a loop.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| loop | Loop object.| 
| timeout | Timeout duration of the timer.| 
| data | Pointer to the input parameter in the callback function invoked upon event changes.| 
| cb | Callback function invoked upon event changes.| 
| repeat | Whether to repeat the timer.| 

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
| loop | Loop object.| 
| handle | Timer handle.| 

**Returns**

Returns **0** if the timer is stopped; returns **-1** otherwise.


### ffrt_mutex_destroy()

```
FFRT_C_API int ffrt_mutex_destroy (ffrt_mutex_t*  mutex)
```

**Description**

Destroys a mutex.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mutex | Pointer to the mutex.| 

**Returns**

Returns **ffrt_success** if the mutex is destroyed; returns **ffrt_error_inval** otherwise.


### ffrt_mutex_init()

```
FFRT_C_API int ffrt_mutex_init (ffrt_mutex_t*  mutex, const ffrt_mutexattr_t*  attr )
```

**Description**

Initializes a mutex.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mutex | Pointer to the mutex.| 
| attr | Pointer to the mutex attribute.| 

**Returns**

Returns **ffrt_success** if the mutex is initialized; returns **ffrt_error** or **ffrt_error_inval** otherwise.


### ffrt_mutex_lock()

```
FFRT_C_API int ffrt_mutex_lock (ffrt_mutex_t*  mutex)
```

**Description**

Locks a mutex.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mutex | Pointer to the mutex.| 

**Returns**

Returns **ffrt_success** if the mutex is locked; returns **ffrt_error_inval** or blocks the calling thread otherwise.


### ffrt_mutex_trylock()

```
FFRT_C_API int ffrt_mutex_trylock (ffrt_mutex_t*  mutex)
```

**Description**

Attempts to lock a mutex.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mutex | Pointer to the mutex.| 

**Returns**

Returns **ffrt_success** if the mutex is locked; returns **ffrt_error_inval** or **ffrt_error_busy** otherwise.


### ffrt_mutex_unlock()

```
FFRT_C_API int ffrt_mutex_unlock (ffrt_mutex_t*  mutex)
```

**Description**

Unlocks a mutex.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mutex | Pointer to the mutex.| 

**Returns**

Returns **ffrt_success** if the mutex is unlocked; returns **ffrt_error_inval** otherwise.


### ffrt_queue_attr_destroy()

```
FFRT_C_API void ffrt_queue_attr_destroy (ffrt_queue_attr_t*  attr)
```

**Description**

Destroys a queue attribute.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute.| 


### ffrt_queue_attr_get_callback()

```
FFRT_C_API ffrt_function_header_t* ffrt_queue_attr_get_callback (const ffrt_queue_attr_t*  attr)
```

**Description**

Obtains the callback that is invoked when a queue task times out.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute.| 

**Returns**

Returns the callback.


### ffrt_queue_attr_get_max_concurrency()

```
FFRT_C_API int ffrt_queue_attr_get_max_concurrency (ffrt_queue_attr_t*  attr)
```

**Description**

Obtains the maximum concurrency of a queue, which must be a concurrent queue.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute.| 

**Returns**

Returns the maximum concurrency.


### ffrt_queue_attr_get_qos()

```
FFRT_C_API ffrt_qos_t ffrt_queue_attr_get_qos (const ffrt_queue_attr_t*  attr)
```

**Description**

Obtains the queue QoS.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute.| 

**Returns**

Returns the QoS.


### ffrt_queue_attr_get_timeout()

```
FFRT_C_API uint64_t ffrt_queue_attr_get_timeout (const ffrt_queue_attr_t*  attr)
```

**Description**

Obtains the queue timeout.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute.| 

**Returns**

Returns the timeout.


### ffrt_queue_attr_init()

```
FFRT_C_API int ffrt_queue_attr_init (ffrt_queue_attr_t*  attr)
```

**Description**

Initializes a queue attribute.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute.| 

**Returns**

Returns **0** if the queue attribute is initialized; returns **-1** otherwise.


### ffrt_queue_attr_set_callback()

```
FFRT_C_API void ffrt_queue_attr_set_callback (ffrt_queue_attr_t*  attr, ffrt_function_header_t*  f )
```

**Description**

Sets a callback that is invoked when a queue task times out.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute.| 
| f | Pointer to the callback function invoked upon a timeout.| 


### ffrt_queue_attr_set_max_concurrency()

```
FFRT_C_API void ffrt_queue_attr_set_max_concurrency (ffrt_queue_attr_t*  attr, const int max_concurrency )
```

**Description**

Sets the maximum concurrency for a queue, which must be a concurrent queue.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute.| 
| max_concurrency | Maximum concurrency.| 


### ffrt_queue_attr_set_qos()

```
FFRT_C_API void ffrt_queue_attr_set_qos (ffrt_queue_attr_t*  attr, ffrt_qos_t qos )
```

**Description**

Sets the queue QoS.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute.| 
| qos | QoS.| 


### ffrt_queue_attr_set_timeout()

```
FFRT_C_API void ffrt_queue_attr_set_timeout (ffrt_queue_attr_t*  attr, uint64_t timeout_us )
```

**Description**

Sets the queue timeout.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the queue attribute.| 
| timeout_us | Timeout.| 


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
| handle | Task handle.| 

**Returns**

Returns **0** if the task is canceled; returns **-1** otherwise.


### ffrt_queue_create()

```
FFRT_C_API ffrt_queue_t ffrt_queue_create (ffrt_queue_type_t type, const char*  name, const ffrt_queue_attr_t*  attr )
```

**Description**

Creates a queue.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Queue type.| 
| name | Pointer to the queue name.| 
| attr | Pointer to the queue attribute.| 

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
| queue | Queue handle.| 


### ffrt_queue_submit()

```
FFRT_C_API void ffrt_queue_submit (ffrt_queue_t queue, ffrt_function_header_t*  f, const ffrt_task_attr_t*  attr )
```

**Description**

Submits a task to a queue.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| queue | Queue handle.| 
| f | Pointer to the task execution function.| 
| attr | Pointer to the task attribute.| 


### ffrt_queue_submit_h()

```
FFRT_C_API ffrt_task_handle_t ffrt_queue_submit_h (ffrt_queue_t queue, ffrt_function_header_t*  f, const ffrt_task_attr_t*  attr )
```

**Description**

Submits a task to a queue, and obtains the task handle.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| queue | Queue handle.| 
| f | Pointer to the task execution function.| 
| attr | Pointer to the task attribute.| 

**Returns**

Returns a non-null task handle if the task is submitted; returns a null pointer otherwise.


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
| handle | Task handle.| 


### ffrt_submit_base()

```
FFRT_C_API void ffrt_submit_base (ffrt_function_header_t*  f, const ffrt_deps_t*  in_deps, const ffrt_deps_t*  out_deps, const ffrt_task_attr_t*  attr )
```

**Description**

Submits a task.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| f | Pointer to the task execution function.| 
| in_deps | Pointer to the input dependencies.| 
| out_deps | Pointer to the output dependencies.| 
| attr | Pointer to the task attribute.| 


### ffrt_submit_h_base()

```
FFRT_C_API ffrt_task_handle_t ffrt_submit_h_base (ffrt_function_header_t*  f, const ffrt_deps_t*  in_deps, const ffrt_deps_t*  out_deps, const ffrt_task_attr_t*  attr )
```

**Description**

Submits a task, and obtains the task handle.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| f | Pointer to the task execution function.| 
| in_deps | Pointer to the input dependencies.| 
| out_deps | Pointer to the output dependencies.| 
| attr | Pointer to the task attribute.| 

**Returns**

Returns a non-null task handle if the task is submitted; returns a null pointer otherwise.


### ffrt_task_attr_destroy()

```
FFRT_C_API void ffrt_task_attr_destroy (ffrt_task_attr_t*  attr)
```

**Description**

Destroys a task attribute.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute.| 


### ffrt_task_attr_get_delay()

```
FFRT_C_API uint64_t ffrt_task_attr_get_delay (const ffrt_task_attr_t*  attr)
```

**Description**

Obtains the task delay time.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute.| 

**Returns**

Returns the delay time.


### ffrt_task_attr_get_name()

```
FFRT_C_API const char* ffrt_task_attr_get_name (const ffrt_task_attr_t*  attr)
```

**Description**

Obtains a task name.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute.| 

**Returns**

Returns a non-null pointer to the task name if the name is obtained; returns a null pointer otherwise.


### ffrt_task_attr_get_qos()

```
FFRT_C_API ffrt_qos_t ffrt_task_attr_get_qos (const ffrt_task_attr_t*  attr)
```

**Description**

Obtains the task QoS.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute.| 

**Returns**

Returns the QoS, which is **ffrt_qos_default** by default.


### ffrt_task_attr_get_queue_priority()

```
FFRT_C_API ffrt_queue_priority_t ffrt_task_attr_get_queue_priority (const ffrt_task_attr_t*  attr)
```

**Description**

Obtains the task priority in the queue.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute.| 

**Returns**

Returns the task priority.


### ffrt_task_attr_init()

```
FFRT_C_API int ffrt_task_attr_init (ffrt_task_attr_t*  attr)
```

**Description**

Initializes a task attribute.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute.| 

**Returns**

Returns **0** if the task attribute is initialized; returns **-1** otherwise.


### ffrt_task_attr_set_delay()

```
FFRT_C_API void ffrt_task_attr_set_delay (ffrt_task_attr_t*  attr, uint64_t delay_us )
```

**Description**

Sets the task delay time.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute.| 
| delay_us | Delay time, in microseconds.| 


### ffrt_task_attr_set_name()

```
FFRT_C_API void ffrt_task_attr_set_name (ffrt_task_attr_t*  attr, const char*  name )
```

**Description**

Sets a task name.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute.| 
| name | Pointer to the task name.| 


### ffrt_task_attr_set_qos()

```
FFRT_C_API void ffrt_task_attr_set_qos (ffrt_task_attr_t*  attr, ffrt_qos_t qos )
```

**Description**

Sets the task QoS.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute.| 
| qos | QoS.| 


### ffrt_task_attr_set_queue_priority()

```
FFRT_C_API void ffrt_task_attr_set_queue_priority (ffrt_task_attr_t*  attr, ffrt_queue_priority_t priority )
```

**Description**

Sets the task priority in the queue.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| attr | Pointer to the task attribute.| 
| priority | Task priority.| 


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
| handle | Task handle.| 


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
FFRT_C_API ffrt_qos_t ffrt_this_task_get_qos ()
```

**Description**

Obtains the QoS of this task.

**Since**: 12

**Returns**

Returns the QoS.


### ffrt_this_task_update_qos()

```
FFRT_C_API int ffrt_this_task_update_qos (ffrt_qos_t qos)
```

**Description**

Updates the QoS of this task.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| qos | New QoS.| 

**Returns**

Returns **0** if the QoS is updated; returns **-1** otherwise.


### ffrt_timer_start()

```
FFRT_C_API ffrt_timer_t ffrt_timer_start (ffrt_qos_t qos, uint64_t timeout, void*  data, ffrt_timer_cb cb, bool repeat )
```

**Description**

Starts the timer.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| qos | QoS.| 
| timeout | Timeout duration of the timer.| 
| data | Pointer to the input parameter in the callback function invoked upon a timeout.| 
| cb | Callback function invoked upon a timeout.| 
| repeat | Whether to repeat the timer.| 

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
| qos | QoS.| 
| handle | Handle to the timer.| 

**Returns**

Returns **0** if the timer stops; returns other values if the timer fails to stop.


### ffrt_usleep()

```
FFRT_C_API int ffrt_usleep (uint64_t usec)
```

**Description**

Suspends the calling thread for a given duration.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| usec | Duration that the calling thread is suspended, in microseconds.| 

**Returns**

Returns **ffrt_success** if the thread is suspended.


### ffrt_wait()

```
FFRT_C_API void ffrt_wait (void )
```

**Description**

Waits until all submitted tasks are complete.

**Since**: 10


### ffrt_wait_deps()

```
FFRT_C_API void ffrt_wait_deps (const ffrt_deps_t*  deps)
```

**Description**

Waits until the dependent tasks are complete.

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| deps | Pointer to the dependencies.| 


### ffrt_yield()

```
FFRT_C_API void ffrt_yield (void )
```

**Description**

Passes control to other tasks so that they can be executed.

**Since**: 10


## Variable Description


### destroy

```
ffrt_function_t ffrt_function_header_t::destroy
```

**Description**

Function used to destroy a task.


### exec

```
ffrt_function_t ffrt_function_header_t::exec
```

**Description**

Function used to execute a task.


### items

```
const ffrt_dependence_t* ffrt_deps_t::items
```

**Description**

Dependency data.


### len

```
uint32_t ffrt_deps_t::len
```

**Description**

Number of dependencies.


### ptr

```
const void* ffrt_dependence_t::ptr
```

**Description**

Address of the dependency data.


### reserve

```
uint64_t ffrt_function_header_t::reserve[2]
```

**Description**

Reserved bit.


### storage [1/6]

```
uint32_t ffrt_cond_t::storage[(ffrt_cond_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```

**Description**

Storage size of a condition variable.


### storage [2/6]

```
uint32_t ffrt_mutex_t::storage[(ffrt_mutex_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```

**Description**

Storage size of a mutex.


### storage [3/6]

```
uint32_t ffrt_queue_attr_t::storage[(ffrt_queue_attr_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```

**Description**

Storage size of a queue attribute.


### storage [4/6]

```
uint32_t ffrt_task_attr_t::storage[(ffrt_task_attr_storage_size + sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```

**Description**

Storage size of a task attribute.


### storage [5/6]

```
long ffrt_condattr_t::storage
```

**Description**

Storage size of a condition variable attribute.


### storage [6/6]

```
long ffrt_mutexattr_t::storage
```

**Description**

Storage size of a mutex attribute.


### type

```
ffrt_dependence_type_t ffrt_dependence_t::type
```

**Description**

Dependency type.
