# mutex.h


## Overview

The **mutex.h** file declares the mutex interfaces in C.

**Since**: 10

**Related module**: [FFRT](_f_f_r_t.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| FFRT_C_API int [ffrt_mutex_init](_f_f_r_t.md#ffrt_mutex_init) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex, const [ffrt_mutexattr_t](ffrt__mutexattr__t.md)\* attr) | Initializes a mutex. | 
| FFRT_C_API int [ffrt_mutex_lock](_f_f_r_t.md#ffrt_mutex_lock) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | Locks a mutex. | 
| FFRT_C_API int [ffrt_mutex_unlock](_f_f_r_t.md#ffrt_mutex_unlock) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | Unlocks a mutex. | 
| FFRT_C_API int [ffrt_mutex_trylock](_f_f_r_t.md#ffrt_mutex_trylock) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | Attempts to lock a mutex. | 
| FFRT_C_API int [ffrt_mutex_destroy](_f_f_r_t.md#ffrt_mutex_destroy) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | Destroys a mutex. | 
