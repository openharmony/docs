# shared_mutex.h


## 概述

声明rwlock的C接口。

**库：** libffrt.z.so \@kit FunctionFlowRuntimeKit

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 18

**相关模块：**[FFRT](_f_f_r_t.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| FFRT_C_API int [ffrt_rwlock_init](_f_f_r_t.md#ffrt_rwlock_init) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock, const [ffrt_rwlockattr_t](ffrt__rwlockattr__t.md) \*attr) | 初始化rwlock。  | 
| FFRT_C_API int [ffrt_rwlock_wrlock](_f_f_r_t.md#ffrt_rwlock_wrlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | 获取写锁。  | 
| FFRT_C_API int [ffrt_rwlock_trywrlock](_f_f_r_t.md#ffrt_rwlock_trywrlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | 尝试获取写锁。  | 
| FFRT_C_API int [ffrt_rwlock_rdlock](_f_f_r_t.md#ffrt_rwlock_rdlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | 获取读锁。  | 
| FFRT_C_API int [ffrt_rwlock_tryrdlock](_f_f_r_t.md#ffrt_rwlock_tryrdlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | 尝试获取读锁。  | 
| FFRT_C_API int [ffrt_rwlock_unlock](_f_f_r_t.md#ffrt_rwlock_unlock) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | 释放rwlock。  | 
| FFRT_C_API int [ffrt_rwlock_destroy](_f_f_r_t.md#ffrt_rwlock_destroy) ([ffrt_rwlock_t](ffrt__rwlock__t.md) \*rwlock) | 销毁rwlock。  | 
