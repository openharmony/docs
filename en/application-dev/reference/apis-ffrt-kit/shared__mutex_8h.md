# shared_mutex.h


## Overview

The **shared_mutex.h** file declares read-write lock interfaces in C.

**Library**: libffrt.z.so

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 18

**Related module**: [FFRT](_f_f_r_t.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| FFRT_C_API int [ffrt_rwlock_init](_f_f_r_t.md#ffrt_rwlock_init) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock, const [ffrt_rwlockattr_t](ffrt__rwlockattr__t.md) \*attr) | Initializes a read-write lock. | 
| FFRT_C_API int [ffrt_rwlock_wrlock](_f_f_r_t.md#ffrt_rwlock_wrlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | Obtains a write lock. | 
| FFRT_C_API int [ffrt_rwlock_trywrlock](_f_f_r_t.md#ffrt_rwlock_trywrlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | Attempts to obtain a write lock; if it fails, the function returns immediately. | 
| FFRT_C_API int [ffrt_rwlock_rdlock](_f_f_r_t.md#ffrt_rwlock_rdlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | Obtains a read lock. | 
| FFRT_C_API int [ffrt_rwlock_tryrdlock](_f_f_r_t.md#ffrt_rwlock_tryrdlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | Attempts to obtain a read lock; if it fails, the function returns immediately. | 
| FFRT_C_API int [ffrt_rwlock_unlock](_f_f_r_t.md#ffrt_rwlock_unlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | Releases the read-write lock. | 
| FFRT_C_API int [ffrt_rwlock_destroy](_f_f_r_t.md#ffrt_rwlock_destroy) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | Destroys the read-write lock. | 
