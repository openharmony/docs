# queue.h


## Overview

The **queue.h** file declares the queue interfaces in C.

**File to include**: &lt;ffrt/queue.h&gt;

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 10

**Related module**: [FFRT](_f_f_r_t.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef void \* [ffrt_queue_t](_f_f_r_t.md#ffrt_queue_t) | Defines the handle to a queue. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [ffrt_queue_type_t](_f_f_r_t.md#ffrt_queue_type_t) {<br>ffrt_queue_serial,<br>ffrt_queue_concurrent,<br>ffrt_queue_max<br>} | Enumerates the queue types. | 


### Functions

| Name| Description| 
| -------- | -------- |
| FFRT_C_API int [ffrt_queue_attr_init](_f_f_r_t.md#ffrt_queue_attr_init) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Initializes the queue attribute. | 
| FFRT_C_API void [ffrt_queue_attr_destroy](_f_f_r_t.md#ffrt_queue_attr_destroy) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Destroys the queue attribute. | 
| FFRT_C_API void [ffrt_queue_attr_set_qos](_f_f_r_t.md#ffrt_queue_attr_set_qos) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr, [ffrt_qos_t](_f_f_r_t.md#ffrt_qos_t) qos) | Sets the queue QoS. | 
| FFRT_C_API [ffrt_qos_t](_f_f_r_t.md#ffrt_qos_t) [ffrt_queue_attr_get_qos](_f_f_r_t.md#ffrt_queue_attr_get_qos) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Obtains the queue QoS. | 
| FFRT_C_API void [ffrt_queue_attr_set_timeout](_f_f_r_t.md#ffrt_queue_attr_set_timeout) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr, uint64_t timeout_us) | Sets the queue timeout. | 
| FFRT_C_API uint64_t [ffrt_queue_attr_get_timeout](_f_f_r_t.md#ffrt_queue_attr_get_timeout) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Obtains the queue timeout. | 
| FFRT_C_API void [ffrt_queue_attr_set_callback](_f_f_r_t.md#ffrt_queue_attr_set_callback) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr, [ffrt_function_header_t](ffrt__function__header__t.md) \*f) | Sets a callback that is invoked when a queue task times out. | 
| FFRT_C_API [ffrt_function_header_t](ffrt__function__header__t.md) \* [ffrt_queue_attr_get_callback](_f_f_r_t.md#ffrt_queue_attr_get_callback) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Obtains the callback that is invoked when a queue task times out. | 
| FFRT_C_API void [ffrt_queue_attr_set_max_concurrency](_f_f_r_t.md#ffrt_queue_attr_set_max_concurrency) ([ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr, const int max_concurrency) | Sets the maximum concurrency for a queue, which must be a concurrent queue. | 
| FFRT_C_API int [ffrt_queue_attr_get_max_concurrency](_f_f_r_t.md#ffrt_queue_attr_get_max_concurrency) (const [ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Obtains the maximum concurrency of a queue, which must be a concurrent queue. | 
| FFRT_C_API [ffrt_queue_t](_f_f_r_t.md#ffrt_queue_t) [ffrt_queue_create](_f_f_r_t.md#ffrt_queue_create) ([ffrt_queue_type_t](_f_f_r_t.md#ffrt_queue_type_t) type, const char \*name, const [ffrt_queue_attr_t](ffrt__queue__attr__t.md) \*attr) | Creates a queue. | 
| FFRT_C_API void [ffrt_queue_destroy](_f_f_r_t.md#ffrt_queue_destroy) ([ffrt_queue_t](_f_f_r_t.md#ffrt_queue_t) queue) | Destroys a queue. | 
| FFRT_C_API void [ffrt_queue_submit](_f_f_r_t.md#ffrt_queue_submit) ([ffrt_queue_t](_f_f_r_t.md#ffrt_queue_t) queue, [ffrt_function_header_t](ffrt__function__header__t.md) \*f, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task to a queue. | 
| FFRT_C_API [ffrt_task_handle_t](_f_f_r_t.md#ffrt_task_handle_t) [ffrt_queue_submit_h](_f_f_r_t.md#ffrt_queue_submit_h) ([ffrt_queue_t](_f_f_r_t.md#ffrt_queue_t) queue, [ffrt_function_header_t](ffrt__function__header__t.md) \*f, const [ffrt_task_attr_t](ffrt__task__attr__t.md) \*attr) | Submits a task to a queue, and obtains the task handle. | 
| FFRT_C_API void [ffrt_queue_wait](_f_f_r_t.md#ffrt_queue_wait) ([ffrt_task_handle_t](_f_f_r_t.md#ffrt_task_handle_t) handle) | Waits until a task in the queue is complete. | 
| FFRT_C_API int [ffrt_queue_cancel](_f_f_r_t.md#ffrt_queue_cancel) ([ffrt_task_handle_t](_f_f_r_t.md#ffrt_task_handle_t) handle) | Cancels a task in the queue. | 
| FFRT_C_API [ffrt_queue_t](_f_f_r_t.md#ffrt_queue_t) [ffrt_get_main_queue](_f_f_r_t.md#ffrt_get_main_queue) (void) | Obtains the main thread queue. | 
| FFRT_C_API [ffrt_queue_t](_f_f_r_t.md#ffrt_queue_t) [ffrt_get_current_queue](_f_f_r_t.md#ffrt_get_current_queue) (void) | Obtains the ArkTS Worker thread queue. | 
