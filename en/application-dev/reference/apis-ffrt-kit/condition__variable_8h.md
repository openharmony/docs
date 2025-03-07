# condition_variable.h


## Overview

The **condition_variable.h** file declares the condition variable interfaces in C.

**Since**: 10

**Related module**: [FFRT](_f_f_r_t.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| FFRT_C_API int [ffrt_cond_init](_f_f_r_t.md#ffrt_cond_init) ([ffrt_cond_t](ffrt__cond__t.md)\* cond, const [ffrt_condattr_t](ffrt__condattr__t.md)\* attr) | Initializes a condition variable. | 
| FFRT_C_API int [ffrt_cond_signal](_f_f_r_t.md#ffrt_cond_signal) ([ffrt_cond_t](ffrt__cond__t.md)\* cond) | Unblocks at least one of the threads that are blocked on a condition variable. | 
| FFRT_C_API int [ffrt_cond_broadcast](_f_f_r_t.md#ffrt_cond_broadcast) ([ffrt_cond_t](ffrt__cond__t.md)\* cond) | Unblocks all threads currently blocked on a condition variable. | 
| FFRT_C_API int [ffrt_cond_wait](_f_f_r_t.md#ffrt_cond_wait) ([ffrt_cond_t](ffrt__cond__t.md)\* cond, [ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | Blocks the calling thread on a condition variable. | 
| FFRT_C_API int [ffrt_cond_timedwait](_f_f_r_t.md#ffrt_cond_timedwait) ([ffrt_cond_t](ffrt__cond__t.md)\* cond, [ffrt_mutex_t](ffrt__mutex__t.md)\* mutex, const struct timespec\* time_point) | Blocks the calling thread on a condition variable for a given duration. | 
| FFRT_C_API int [ffrt_cond_destroy](_f_f_r_t.md#ffrt_cond_destroy) ([ffrt_cond_t](ffrt__cond__t.md)\* cond) | Destroys a condition variable. | 
