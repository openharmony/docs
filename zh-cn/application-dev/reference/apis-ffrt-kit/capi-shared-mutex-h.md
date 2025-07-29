# shared_mutex.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--SE: @geoffrey_guo; @huangyouzhong-->
<!--TSE: @lotsof; @sunxuhao-->

## 概述

声明rwlock的C接口。

**引用文件：** <ffrt/shared_mutex.h>

**库：** libffrt.z.so

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 18

**相关模块：** [FFRT](capi-ffrt.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [FFRT_C_API int ffrt_rwlock_init(ffrt_rwlock_t* rwlock, const ffrt_rwlockattr_t* attr)](#ffrt_rwlock_init) | 初始化rwlock。 |
| [FFRT_C_API int ffrt_rwlock_wrlock(ffrt_rwlock_t* rwlock)](#ffrt_rwlock_wrlock) | 获取写锁。 |
| [FFRT_C_API int ffrt_rwlock_trywrlock(ffrt_rwlock_t* rwlock)](#ffrt_rwlock_trywrlock) | 尝试获取写锁。 |
| [FFRT_C_API int ffrt_rwlock_rdlock(ffrt_rwlock_t* rwlock)](#ffrt_rwlock_rdlock) | 获取读锁。 |
| [FFRT_C_API int ffrt_rwlock_tryrdlock(ffrt_rwlock_t* rwlock)](#ffrt_rwlock_tryrdlock) | 尝试获取读锁。 |
| [FFRT_C_API int ffrt_rwlock_unlock(ffrt_rwlock_t* rwlock)](#ffrt_rwlock_unlock) | 释放rwlock。 |

## 函数说明

### ffrt_rwlock_init()

```
FFRT_C_API int ffrt_rwlock_init(ffrt_rwlock_t* rwlock, const ffrt_rwlockattr_t* attr)
```

**描述**

初始化rwlock。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | rwlock指针。 |
| [const ffrt_rwlockattr_t](capi-ffrt-ffrt-rwlockattr-t.md)* attr | rwlock属性指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 初始化rwlock成功返回ffrt_success，<br>          初始化rwlock失败返回ffrt_error_inval。 |

### ffrt_rwlock_wrlock()

```
FFRT_C_API int ffrt_rwlock_wrlock(ffrt_rwlock_t* rwlock)
```

**描述**

获取写锁。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | rwlock指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 获取写锁成功返回ffrt_success，<br>          获取写锁失败返回ffrt_error_inval或者阻塞当前任务。 |

### ffrt_rwlock_trywrlock()

```
FFRT_C_API int ffrt_rwlock_trywrlock(ffrt_rwlock_t* rwlock)
```

**描述**

尝试获取写锁。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | rwlock指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 获取写锁成功返回ffrt_success，<br>          获取写锁失败返回ffrt_error_inval或ffrt_error_busy。 |

### ffrt_rwlock_rdlock()

```
FFRT_C_API int ffrt_rwlock_rdlock(ffrt_rwlock_t* rwlock)
```

**描述**

获取读锁。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | rwlock指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 获取读锁成功返回ffrt_success，<br>          获取读锁失败返回ffrt_error_inval或者阻塞当前任务。 |

### ffrt_rwlock_tryrdlock()

```
FFRT_C_API int ffrt_rwlock_tryrdlock(ffrt_rwlock_t* rwlock)
```

**描述**

尝试获取读锁。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | rwlock指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 获取读锁成功返回ffrt_success，<br>          获取读锁失败返回ffrt_error_inval或ffrt_error_busy。 |

### ffrt_rwlock_unlock()

```
FFRT_C_API int ffrt_rwlock_unlock(ffrt_rwlock_t* rwlock)
```

**描述**

释放rwlock。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md)* rwlock | rwlock指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 释放rwlock成功返回ffrt_success，<br>          释放rwlock失败返回ffrt_error_inval。 |


