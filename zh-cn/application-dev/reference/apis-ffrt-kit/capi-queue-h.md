# queue.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung-->
<!--Designer: @zhanglu161-->
<!--Tester: @lotsof-->
<!--Adviser: @jinqiuheng-->

## 概述

声明队列的C接口。

**引用文件：** <ffrt/queue.h>

**库：** libffrt.z.so

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 10

**相关模块：** [FFRT](capi-ffrt.md)

## 汇总

### 结构体

| 名称               | 描述 |
|------------------|--|
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) | 队列句柄。  |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ffrt_queue_type_t](#ffrt_queue_type_t) | ffrt_queue_type_t | 枚举队列类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [FFRT_C_API int ffrt_queue_attr_init(ffrt_queue_attr_t* attr)](#ffrt_queue_attr_init) | 初始化队列属性。该队列属性不再使用时，必须通过[ffrt_queue_attr_destroy](capi-queue-h.md#ffrt_queue_attr_destroy)销毁。 |
| [FFRT_C_API void ffrt_queue_attr_destroy(ffrt_queue_attr_t* attr)](#ffrt_queue_attr_destroy) | 销毁队列属性。该队列属性必须已通过[ffrt_queue_attr_init](capi-queue-h.md#ffrt_queue_attr_init)初始化。 |
| [FFRT_C_API void ffrt_queue_attr_set_qos(ffrt_queue_attr_t* attr, ffrt_qos_t qos)](#ffrt_queue_attr_set_qos) | 设置队列属性的QoS。 |
| [FFRT_C_API ffrt_qos_t ffrt_queue_attr_get_qos(const ffrt_queue_attr_t* attr)](#ffrt_queue_attr_get_qos) | 获取队列属性的QoS。 |
| [FFRT_C_API void ffrt_queue_attr_set_timeout(ffrt_queue_attr_t* attr, uint64_t timeout_us)](#ffrt_queue_attr_set_timeout) | 设置队列属性的任务执行超时时长。 |
| [FFRT_C_API uint64_t ffrt_queue_attr_get_timeout(const ffrt_queue_attr_t* attr)](#ffrt_queue_attr_get_timeout) | 获取队列属性的任务执行超时时长。 |
| [FFRT_C_API void ffrt_queue_attr_set_callback(ffrt_queue_attr_t* attr, ffrt_function_header_t* f)](#ffrt_queue_attr_set_callback) | 设置队列属性的超时回调函数。当队列中的任务执行时间超过通过[ffrt_queue_attr_set_timeout](capi-queue-h.md#ffrt_queue_attr_set_timeout)设置的超时时长时触发该回调。 |
| [FFRT_C_API ffrt_function_header_t* ffrt_queue_attr_get_callback(const ffrt_queue_attr_t* attr)](#ffrt_queue_attr_get_callback) | 获取队列属性的超时回调函数。 |
| [FFRT_C_API void ffrt_queue_attr_set_max_concurrency(ffrt_queue_attr_t* attr, const int max_concurrency)](#ffrt_queue_attr_set_max_concurrency) | 设置并发队列属性的最大并发度。 |
| [FFRT_C_API int ffrt_queue_attr_get_max_concurrency(const ffrt_queue_attr_t* attr)](#ffrt_queue_attr_get_max_concurrency) | 获取并发队列属性的最大并发度。 |
| [FFRT_C_API void ffrt_queue_attr_set_thread_mode(ffrt_queue_attr_t* attr, bool mode)](#ffrt_queue_attr_set_thread_mode) | 设置队列属性的执行模式。该接口指定队列中的任务是以协程模式还是线程模式执行。默认以协程模式执行。将mode设为`true`时启用基于线程的执行。 |
| [FFRT_C_API bool ffrt_queue_attr_get_thread_mode(const ffrt_queue_attr_t* attr)](#ffrt_queue_attr_get_thread_mode) | 获取队列属性的执行模式。 |
| [FFRT_C_API ffrt_queue_t ffrt_queue_create(ffrt_queue_type_t type, const char* name, const ffrt_queue_attr_t* attr)](#ffrt_queue_create) | 创建队列。该队列不再使用时，必须通过[ffrt_queue_destroy](capi-queue-h.md#ffrt_queue_destroy)销毁。 |
| [FFRT_C_API void ffrt_queue_destroy(ffrt_queue_t queue)](#ffrt_queue_destroy) | 销毁队列。该队列必须已通过[ffrt_queue_create](capi-queue-h.md#ffrt_queue_create)创建。销毁时会取消尚未开始执行的任务，并阻塞等待正在执行的任务完成。 |
| [FFRT_C_API void ffrt_queue_submit(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr)](#ffrt_queue_submit) | 提交任务到队列。 |
| [FFRT_C_API ffrt_task_handle_t ffrt_queue_submit_h(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr)](#ffrt_queue_submit_h) | 提交任务到队列，并获取任务句柄。 |
| [FFRT_C_API void ffrt_queue_submit_f(ffrt_queue_t queue, ffrt_function_t func, void* arg, const ffrt_task_attr_t* attr)](#ffrt_queue_submit_f) | 提交任务到队列，是[ffrt_queue_submit](capi-queue-h.md#ffrt_queue_submit)接口的简化形式。该接口将给定的任务函数及其参数包装为用于队列提交的任务包装器（`ffrt_function_kind_queue`）。其中用于处理执行后清理的任务销毁回调（after_func）会被设为NULL，因而省略任何额外清理动作。生成的任务包装器随后通过[ffrt_queue_submit](capi-queue-h.md#ffrt_queue_submit)接口被提交到指定队列。 |
| [FFRT_C_API ffrt_task_handle_t ffrt_queue_submit_h_f(ffrt_queue_t queue, ffrt_function_t func, void* arg, const ffrt_task_attr_t* attr)](#ffrt_queue_submit_h_f) | 提交任务到队列并获取任务句柄，是[ffrt_queue_submit_h](capi-queue-h.md#ffrt_queue_submit_h)接口的简化形式。该接口将给定的任务函数及其参数包装为用于队列提交的任务包装器（`ffrt_function_kind_queue`）。其中用于处理执行后清理的任务销毁回调（after_func）会被设为NULL，因而省略任何额外清理动作。生成的任务包装器随后通过[ffrt_queue_submit_h](capi-queue-h.md#ffrt_queue_submit_h)接口被提交到指定队列。 |
| [FFRT_C_API void ffrt_queue_wait(ffrt_task_handle_t handle)](#ffrt_queue_wait) | 等待队列中的任务执行完成。 |
| [FFRT_C_API int ffrt_queue_cancel(ffrt_task_handle_t handle)](#ffrt_queue_cancel) | 取消队列中的任务。已开始执行的任务无法被取消。 |
| [FFRT_C_API ffrt_queue_t ffrt_get_main_queue(void)](#ffrt_get_main_queue) | 获取应用主线程队列。 |
| [FFRT_C_API ffrt_queue_t ffrt_get_current_queue(void)](#ffrt_get_current_queue) | 获取应用Worker（ArkTS）线程队列。（API18废弃） |

## 枚举类型说明

### ffrt_queue_type_t

```c
enum ffrt_queue_type_t
```

**描述**

枚举队列类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ffrt_queue_serial | 串行队列。 |
| ffrt_queue_concurrent | 并发队列。 |
| ffrt_queue_max | 最大有效队列类型值，作为哨兵使用（例如用于迭代）。 |


## 函数说明

### ffrt_queue_attr_init()

```c
FFRT_C_API int ffrt_queue_attr_init(ffrt_queue_attr_t* attr)
```

**描述**

初始化队列属性。该队列属性不再使用时，必须通过[ffrt_queue_attr_destroy](capi-queue-h.md#ffrt_queue_attr_destroy)销毁。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 队列属性初始化成功时返回`0`；<br>         否则返回`-1`。 |

### ffrt_queue_attr_destroy()

```c
FFRT_C_API void ffrt_queue_attr_destroy(ffrt_queue_attr_t* attr)
```

**描述**

销毁队列属性。该队列属性必须已通过[ffrt_queue_attr_init](capi-queue-h.md#ffrt_queue_attr_init)初始化。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |

### ffrt_queue_attr_set_qos()

```c
FFRT_C_API void ffrt_queue_attr_set_qos(ffrt_queue_attr_t* attr, ffrt_qos_t qos)
```

**描述**

设置队列属性的QoS。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |
| [ffrt_qos_t](capi-type-def-h.md#变量) qos | QoS等级，取值范围参见[ffrt_qos_t](capi-type-def-h.md#变量)枚举定义。 |

### ffrt_queue_attr_get_qos()

```c
FFRT_C_API ffrt_qos_t ffrt_queue_attr_get_qos(const ffrt_queue_attr_t* attr)
```

**描述**

获取队列属性的QoS。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API [ffrt_qos_t](capi-type-def-h.md#变量) | QoS等级，取值范围参见[ffrt_qos_t](capi-type-def-h.md#变量)枚举定义。 |

### ffrt_queue_attr_set_timeout()

```c
FFRT_C_API void ffrt_queue_attr_set_timeout(ffrt_queue_attr_t* attr, uint64_t timeout_us)
```

**描述**

设置队列属性的任务执行超时时长。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |
| uint64_t timeout_us | 队列任务执行超时时长，单位是微秒。下限为1000微秒（1毫秒），低于1000的值会被强制设为1000。 |

### ffrt_queue_attr_get_timeout()

```c
FFRT_C_API uint64_t ffrt_queue_attr_get_timeout(const ffrt_queue_attr_t* attr)
```

**描述**

获取队列属性的任务执行超时时长。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API uint64_t | 队列任务执行超时时长，单位是微秒。 |

### ffrt_queue_attr_set_callback()

```c
FFRT_C_API void ffrt_queue_attr_set_callback(ffrt_queue_attr_t* attr, ffrt_function_header_t* f)
```

**描述**

设置队列属性的超时回调函数。当队列中的任务执行时间超过通过[ffrt_queue_attr_set_timeout](capi-queue-h.md#ffrt_queue_attr_set_timeout)设置的超时时长时触发该回调。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |
| [ffrt_function_header_t](capi-ffrt-ffrt-function-header-t.md)* f | 队列超时回调函数。 |

### ffrt_queue_attr_get_callback()

```c
FFRT_C_API ffrt_function_header_t* ffrt_queue_attr_get_callback(const ffrt_queue_attr_t* attr)
```

**描述**

获取队列属性的超时回调函数。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API [ffrt_function_header_t](capi-ffrt-ffrt-function-header-t.md)* | 队列任务超时回调函数。 |

### ffrt_queue_attr_set_max_concurrency()

```c
FFRT_C_API void ffrt_queue_attr_set_max_concurrency(ffrt_queue_attr_t* attr, const int max_concurrency)
```

**描述**

设置并发队列属性的最大并发度。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |
| const int max_concurrency | 队列可并发执行的最大任务数。 |

### ffrt_queue_attr_get_max_concurrency()

```c
FFRT_C_API int ffrt_queue_attr_get_max_concurrency(const ffrt_queue_attr_t* attr)
```

**描述**

获取并发队列属性的最大并发度。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 队列的最大并发度。 |

### ffrt_queue_attr_set_thread_mode()

```c
FFRT_C_API void ffrt_queue_attr_set_thread_mode(ffrt_queue_attr_t* attr, bool mode)
```

**描述**

设置队列属性的执行模式。该接口指定队列中的任务是以协程模式还是线程模式执行。默认以协程模式执行。将mode设为`true`时启用基于线程的执行。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |
| bool mode | 是否启用基于线程的执行模式。- `true`：任务以原生线程执行（线程模式）。- `false`：任务以协程执行（默认）。 |

### ffrt_queue_attr_get_thread_mode()

```c
FFRT_C_API bool ffrt_queue_attr_get_thread_mode(const ffrt_queue_attr_t* attr)
```

**描述**

获取队列属性的执行模式。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API bool | 任务以原生线程执行（线程模式）时返回`true`；<br>         任务以协程执行（默认）时返回`false`。 |

### ffrt_queue_create()

```c
FFRT_C_API ffrt_queue_t ffrt_queue_create(ffrt_queue_type_t type, const char* name, const ffrt_queue_attr_t* attr)
```

**描述**

创建队列。该队列不再使用时，必须通过[ffrt_queue_destroy](capi-queue-h.md#ffrt_queue_destroy)销毁。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_type_t](capi-queue-h.md#ffrt_queue_type_t) type | 队列类型。`ffrt_queue_serial`适用于任务需按顺序执行的场景；`ffrt_queue_concurrent`适用于任务可并发执行以提高吞吐量的场景。 |
| const char* name | 指向队列名称的指针。 |
| [const ffrt_queue_attr_t](capi-ffrt-ffrt-queue-attr-t.md)* attr | 指向队列属性的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) | 队列创建成功时返回非空的队列句柄；<br>         否则返回空指针。 |

### ffrt_queue_destroy()

```c
FFRT_C_API void ffrt_queue_destroy(ffrt_queue_t queue)
```

**描述**

销毁队列。该队列必须已通过[ffrt_queue_create](capi-queue-h.md#ffrt_queue_create)创建。销毁时会取消尚未开始执行的任务，并阻塞等待正在执行的任务完成。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) queue | 队列句柄。 |

### ffrt_queue_submit()

```c
FFRT_C_API void ffrt_queue_submit(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr)
```

**描述**

提交任务到队列。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) queue | 队列句柄。 |
| [ffrt_function_header_t](capi-ffrt-ffrt-function-header-t.md)* f | 指向任务执行体的指针。 |
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | 指向任务属性的指针。 |

**参考：**

[ffrt_queue_submit_h](capi-queue-h.md#ffrt_queue_submit_h)


### ffrt_queue_submit_h()

```c
FFRT_C_API ffrt_task_handle_t ffrt_queue_submit_h(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr)
```

**描述**

提交任务到队列，并获取任务句柄。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) queue | 队列句柄。 |
| [ffrt_function_header_t](capi-ffrt-ffrt-function-header-t.md)* f | 指向任务执行体的指针。 |
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | 指向任务属性的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) | 任务提交成功时返回非空的任务句柄；<br>         否则返回空指针。 |

**参考：**

[ffrt_queue_submit](capi-queue-h.md#ffrt_queue_submit)


### ffrt_queue_submit_f()

```c
FFRT_C_API void ffrt_queue_submit_f(ffrt_queue_t queue, ffrt_function_t func, void* arg, const ffrt_task_attr_t* attr)
```

**描述**

提交任务到队列，是[ffrt_queue_submit](capi-queue-h.md#ffrt_queue_submit)接口的简化形式。该接口将给定的任务函数及其参数包装为用于队列提交的任务包装器（`ffrt_function_kind_queue`）。其中用于处理执行后清理的任务销毁回调（after_func）会被设为NULL，因而省略任何额外清理动作。生成的任务包装器随后通过[ffrt_queue_submit](capi-queue-h.md#ffrt_queue_submit)接口被提交到指定队列。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) queue | 队列句柄。 |
| [ffrt_function_t](capi-type-def-h.md#ffrt_function_t) func | 要执行的任务函数。 |
| void* arg | 指向传递给任务函数的参数或闭包数据的指针。 |
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | 指向任务属性的指针。 |

**参考：**

[ffrt_queue_submit](capi-queue-h.md#ffrt_queue_submit)


### ffrt_queue_submit_h_f()

```c
FFRT_C_API ffrt_task_handle_t ffrt_queue_submit_h_f(ffrt_queue_t queue, ffrt_function_t func, void* arg, const ffrt_task_attr_t* attr)
```

**描述**

提交任务到队列并获取任务句柄，是[ffrt_queue_submit_h](capi-queue-h.md#ffrt_queue_submit_h)接口的简化形式。该接口将给定的任务函数及其参数包装为用于队列提交的任务包装器（`ffrt_function_kind_queue`）。其中用于处理执行后清理的任务销毁回调（after_func）会被设为NULL，因而省略任何额外清理动作。生成的任务包装器随后通过[ffrt_queue_submit_h](capi-queue-h.md#ffrt_queue_submit_h)接口被提交到指定队列。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) queue | 队列句柄。 |
| [ffrt_function_t](capi-type-def-h.md#ffrt_function_t) func | 要执行的任务函数。 |
| void* arg | 指向传递给任务函数的参数或闭包数据的指针。 |
| [const ffrt_task_attr_t](capi-ffrt-ffrt-task-attr-t.md)* attr | 指向任务属性的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) | 任务提交成功时返回非空的任务句柄；<br>         否则返回空指针。 |

**参考：**

[ffrt_queue_submit_h](capi-queue-h.md#ffrt_queue_submit_h)


### ffrt_queue_wait()

```c
FFRT_C_API void ffrt_queue_wait(ffrt_task_handle_t handle)
```

**描述**

等待队列中的任务执行完成。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) handle | 任务句柄。 |

### ffrt_queue_cancel()

```c
FFRT_C_API int ffrt_queue_cancel(ffrt_task_handle_t handle)
```

**描述**

取消队列中的任务。已开始执行的任务无法被取消。

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_task_handle_t](capi-ffrt-ffrt-task-handle-t.md) handle | 任务句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 任务取消成功时返回`0`；<br>          任务已执行完毕或已从队列中移除时返回`1`；<br>          handle为空时返回`-1`。 |

### ffrt_get_main_queue()

```c
FFRT_C_API ffrt_queue_t ffrt_get_main_queue(void)
```

**描述**

获取应用主线程队列。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) | 应用主线程队列。 |

### ffrt_get_current_queue()

```c
FFRT_C_API ffrt_queue_t ffrt_get_current_queue(void)
```

**描述**

获取应用Worker（ArkTS）线程队列。

**起始版本：** 12

**废弃版本：** 18

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) | 应用Worker（ArkTS）线程队列。 |


