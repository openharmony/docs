# type_def.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung-->
<!--Designer: @zhanglu161-->
<!--Tester: @lotsof-->
<!--Adviser: @jinqiuheng-->

## 概述

定义通用类型。

**引用文件：** <ffrt/type_def.h>

**库：** libffrt.z.so

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 10

**相关模块：** [FFRT](capi-ffrt.md)

## 汇总

### 变量

| 名称  | typedef关键字 | 描述                     |
|-----|------------|------------------------|
| int | ffrt_qos_t | QoS类型，用于设置任务的QoS等级。 |
| int | ffrt_timer_t | 定时器句柄，用于标识已创建的定时器。 |
| using qos = int | - | QoS类型。<br>**起始版本：** 10 |

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ffrt_function_header_t](capi-ffrt-ffrt-function-header-t.md) | ffrt_function_header_t | 任务执行体，用于定义任务的执行和销毁回调。`exec`回调在任务被调度时调用，`destroy`回调在任务完成后被调用以释放任务相关资源。两者共同管理FFRT任务的完整生命周期。 |
| [ffrt_dependence_t](capi-ffrt-ffrt-dependence-t.md) | ffrt_dependence_t | 依赖数据项结构，用于描述任务间的单个依赖关系。 |
| [ffrt_deps_t](capi-ffrt-ffrt-deps-t.md) | ffrt_deps_t | 依赖结构体，用于保存任务的依赖列表。 |
| [ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md) | ffrt_task_attr_t | 任务属性结构体，用于存储任务的属性信息。 |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md) | ffrt_queue_attr_t | 队列属性结构体，用于存储队列的属性信息。 |
| [ffrt_condattr_t](capi-ffrt-ffrt-condattr-t.md) | ffrt_condattr_t | 条件变量属性结构体，用于存储条件变量的属性信息。 |
| [ffrt_mutexattr_t](capi-ffrt-ffrt-mutexattr-t.md) | ffrt_mutexattr_t | 互斥锁属性结构体，用于存储互斥锁的属性信息。 |
| [ffrt_rwlockattr_t](capi-ffrt-ffrt-rwlockattr-t.md) | ffrt_rwlockattr_t | 读写锁属性结构体，用于存储读写锁的属性信息。 |
| [ffrt_mutex_t](capi-ffrt-ffrt-mutex-t.md) | ffrt_mutex_t | 互斥锁结构体，用于存储互斥锁的内部数据。 |
| [ffrt_rwlock_t](capi-ffrt-ffrt-rwlock-t.md) | ffrt_rwlock_t | 读写锁结构体，用于存储读写锁的内部数据。 |
| [ffrt_cond_t](capi-ffrt-ffrt-cond-t.md) | ffrt_cond_t | 条件变量结构体，用于存储条件变量的内部数据。 |
| [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) | ffrt_task_handle_t | 任务句柄，用于标识不同的任务。 |
| [ffrt_fiber_t](capi-ffrt-ffrt-fiber-t.md) | ffrt_fiber_t | 纤程结构体，用于存储纤程执行上下文。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ffrt_queue_priority_t](#ffrt_queue_priority_t) | ffrt_queue_priority_t | 并发队列中用于排序任务调度的任务优先级类型枚举。 |
| [ffrt_qos_default_t](#ffrt_qos_default_t) | ffrt_qos_default_t | 任务QoS类型枚举。 |
| [ffrt_storage_size_t](#ffrt_storage_size_t) | ffrt_storage_size_t | 多种类型结构体的存储大小定义，单位是字节。 |
| [ffrt_function_kind_t](#ffrt_function_kind_t) | ffrt_function_kind_t | 任务类型枚举，用于区分通用并发任务和队列调度的任务。 |
| [ffrt_dependence_type_t](#ffrt_dependence_type_t) | ffrt_dependence_type_t | 依赖类型枚举。用于指定任务间的依赖关系（数据就绪或任务完成）。 |
| [ffrt_error_t](#ffrt_error_t) | ffrt_error_t | 错误码枚举，由FFRT接口返回。 |
| [ffrt_mutex_type](#ffrt_mutex_type) | ffrt_mutex_type | 互斥锁类型枚举。 |
| [qos_default](#qos_default) | - | 任务QoS类型枚举。各枚举值与[ffrt_qos_default_t](capi-type-def-h.md#ffrt_qos_default_t)中对应的枚举值等价。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void(\*ffrt_function_t)(void*)](#ffrt_function_t) | ffrt_function_t | 任务执行函数指针类型。函数指针定义了FFRT任务的入口点。FFRT在调度执行任务时调用该函数，并通过参数传入用户数据指针。 |
| [typedef void (\*ffrt_poller_cb)(void* data, uint32_t event)](#ffrt_poller_cb) | ffrt_poller_cb | poller回调函数类型。当poller检测到已注册事件时调用该回调。`data`指针携带注册时传入的用户数据，`event`值标识触发的事件类型。 |
| [typedef void (\*ffrt_timer_cb)(void* data)](#ffrt_timer_cb) | ffrt_timer_cb | 定时器回调函数类型。当定时器到期时调用该回调。`data`指针携带定时器注册时传入的用户数据。 |

## 枚举类型说明

### ffrt_queue_priority_t

```c
enum ffrt_queue_priority_t
```

**描述**

并发队列中用于排序任务调度的任务优先级类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ffrt_queue_priority_immediate = 0 | 最高优先级。任务尽快被调度（句柄时间等于提交时间）；优先于`high`被调度。 |
| ffrt_queue_priority_high | 高优先级。按句柄时间排序；优先于`low`被调度。 |
| ffrt_queue_priority_low | 低优先级。按句柄时间排序；优先于`idle`被调度。 |
| ffrt_queue_priority_idle | 最低优先级。按句柄时间排序；仅在队列中不存在其他优先级任务时才被调度。 |

### ffrt_qos_default_t

```c
enum ffrt_qos_default_t
```

**描述**

任务QoS类型枚举。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| ffrt_qos_inherit = -1 | 继承。<br>继承调用线程的QoS。用于任务需要采用创建者优先级的场景。 |
| ffrt_qos_background | 后台任务。<br>最低优先级。用于用户无感知的工作，例如后台数据同步或日志刷新。 |
| ffrt_qos_utility | 实用工具类任务。<br>用于用户可感知但不主动等待的长时间任务，例如数据加载或内容索引。 |
| ffrt_qos_default | 默认类型。<br>无特殊QoS要求时使用的默认QoS，适用于大多数一般任务。 |
| ffrt_qos_user_initiated | 用户发起的任务。<br>用于用户主动触发、需要快速响应但不阻塞UI的任务，例如打开文档或执行搜索。 |
| ffrt_qos_deadline_request | 时限请求任务。<br>用于有明确截止时间的任务，系统优先保障其调度资源。<br>**起始版本：** 23 |
| ffrt_qos_user_interactive | 用户交互任务。<br>适用于UI响应等需要立即与用户交互的操作。<br>**起始版本：** 23 |
| ffrt_qos_max = ffrt_qos_user_interactive | 最高QoS等级。<br>等价于ffrt_qos_user_interactive。<br>**起始版本：** 23 |

### ffrt_storage_size_t

```c
enum ffrt_storage_size_t
```

**描述**

多种类型结构体的存储大小定义，单位是字节。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| ffrt_task_attr_storage_size = 128 | 任务属性存储大小，单位是字节。 |
| ffrt_auto_managed_function_storage_size = 64 + sizeof(ffrt_function_header_t) | 任务执行体存储大小，单位是字节。 |
| ffrt_mutex_storage_size = 64 | 互斥锁存储大小，单位是字节。 |
| ffrt_cond_storage_size = 64 | 条件变量存储大小，单位是字节。 |
| ffrt_queue_attr_storage_size = 128 | 队列属性存储大小，单位是字节。 |
| ffrt_rwlock_storage_size = 64 | 读写锁存储大小，单位是字节。<br>**起始版本：** 18 |
| ffrt_fiber_storage_size| 纤程存储大小，单位是字节。该常量定义纤程存储大小。实际值取决于目标架构：aarch64架构：22字节；arm架构：64字节；x86_64架构：8字节；其他平台：不支持。<br>**起始版本：** 20  |
### ffrt_function_kind_t

```c
enum ffrt_function_kind_t
```

**描述**

任务类型枚举，用于区分通用并发任务和队列调度的任务。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| ffrt_function_kind_general | 通用任务。任务可提交到FFRT调度器并发执行。 |
| ffrt_function_kind_queue | 队列任务。任务通过队列按提交顺序依次执行。 |

### ffrt_dependence_type_t

```c
enum ffrt_dependence_type_t
```

**描述**

依赖类型枚举。用于指定任务间的依赖关系（数据就绪或任务完成）。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| ffrt_dependence_data | 数据依赖类型。任务仅在所引用的数据就绪后被调度。 |
| ffrt_dependence_task | 任务依赖类型。任务仅在所引用的任务完成后被调度。 |

### ffrt_error_t

```c
enum ffrt_error_t
```

**描述**

错误码枚举，由FFRT接口返回。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| ffrt_error = -1 | 通用错误。 |
| ffrt_success = 0 | 成功。 |
| ffrt_error_nomem = ENOMEM | 内存不足错误。 |
| ffrt_error_timedout = ETIMEDOUT | 超时错误。 |
| ffrt_error_busy = EBUSY | 资源忙碌错误。资源正忙，请稍后重试。 |
| ffrt_error_inval = EINVAL | 无效值错误。 |

### ffrt_mutex_type

```c
enum ffrt_mutex_type
```

**描述**

互斥锁类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ffrt_mutex_normal = 0 | 普通互斥锁类型。 |
| ffrt_mutex_recursive = 2 | 递归互斥锁类型，允许同一线程对同一互斥锁多次加锁。 |
| ffrt_mutex_default = ffrt_mutex_normal | 默认互斥锁类型，等价于`ffrt_mutex_normal`。 |

### qos_default

```c
enum qos_default
```

**描述**

任务QoS类型枚举。各枚举值与[ffrt_qos_default_t](capi-type-def-h.md#ffrt_qos_default_t)中对应的枚举值等价。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| qos_inherit = ffrt_qos_inherit | 继承。<br>继承调用线程的QoS。用于任务需要采用创建者优先级的场景。 |
| qos_background = ffrt_qos_background | 后台任务。<br>最低优先级。用于用户无感知的工作，例如后台数据同步或日志刷新。 |
| qos_utility = ffrt_qos_utility | 实用工具类任务。<br>用于用户可感知但不主动等待的长时间任务，例如数据加载或内容索引。 |
| qos_default = ffrt_qos_default | 默认类型。<br>无特殊QoS要求时使用的默认QoS，适用于大多数一般任务。 |
| qos_user_initiated = ffrt_qos_user_initiated | 用户发起的任务。<br>用于用户主动触发、需要快速响应但不阻塞UI的任务，例如打开文档或执行搜索。 |
| qos_deadline_request = ffrt_qos_deadline_request | 时限请求任务。<br>用于有明确截止时间的任务，系统优先保障其调度资源。<br>**起始版本：** 23 |
| qos_user_interactive = ffrt_qos_user_interactive | 用户交互任务。<br>适用于UI响应等需要立即与用户交互的操作。<br>**起始版本：** 23 |
| qos_max = ffrt_qos_user_interactive | 最高QoS等级。<br>等价于ffrt_qos_user_interactive。<br>**起始版本：** 23 |


## 函数说明

### ffrt_function_t()

```c
typedef void(*ffrt_function_t)(void*)
```

**描述**

任务执行函数指针类型。函数指针定义了FFRT任务的入口点。FFRT在调度执行任务时调用该函数，并通过参数传入用户数据指针。

**起始版本：** 10

### ffrt_poller_cb()

```c
typedef void (*ffrt_poller_cb)(void* data, uint32_t event)
```

**描述**

poller回调函数类型。当poller检测到已注册事件时调用该回调。`data`指针携带注册时传入的用户数据，`event`值标识触发的事件类型。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| void\* data | 指向poller注册时传入的用户数据指针。 |
| uint32_t event | 触发回调的事件类型。 |

### ffrt_timer_cb()

```c
typedef void (*ffrt_timer_cb)(void* data)
```

**描述**

定时器回调函数类型。当定时器到期时调用该回调。`data`指针携带定时器注册时传入的用户数据。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| void\* data | 指向定时器注册时传入的用户数据指针。 |


