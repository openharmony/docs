# loop.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## 概述

声明循环的C接口。

**引用文件：** <ffrt/loop.h>

**库：** libffrt.z.so

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 12

**相关模块：** [FFRT](capi-ffrt.md)

## 汇总

### 结构体

| 名称              | 描述 |
|-----------------|----|
| [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) | loop句柄。   |


### 函数

| 名称 | 描述 |
| -- | -- |
| [FFRT_C_API ffrt_loop_t ffrt_loop_create(ffrt_queue_t queue)](#ffrt_loop_create) | 创建loop对象。 |
| [FFRT_C_API int ffrt_loop_destroy(ffrt_loop_t loop)](#ffrt_loop_destroy) | 销毁loop对象。 |
| [FFRT_C_API int ffrt_loop_run(ffrt_loop_t loop)](#ffrt_loop_run) | 开启loop循环。 |
| [FFRT_C_API void ffrt_loop_stop(ffrt_loop_t loop)](#ffrt_loop_stop) | 停止loop循环。 |
| [FFRT_C_API int ffrt_loop_epoll_ctl(ffrt_loop_t loop, int op, int fd, uint32_t events, void *data, ffrt_poller_cb cb)](#ffrt_loop_epoll_ctl) | 管理loop上的监听事件。 |
| [FFRT_C_API ffrt_timer_t ffrt_loop_timer_start(ffrt_loop_t loop, uint64_t timeout, void* data, ffrt_timer_cb cb, bool repeat)](#ffrt_loop_timer_start) | 在ffrt loop上启动定时器。 |
| [FFRT_C_API int ffrt_loop_timer_stop(ffrt_loop_t loop, ffrt_timer_t handle)](#ffrt_loop_timer_stop) | 停止ffrt loop定时器。 |

## 函数说明

### ffrt_loop_create()

```
FFRT_C_API ffrt_loop_t ffrt_loop_create(ffrt_queue_t queue)
```

**描述**

创建loop对象。

**起始版本：** 12


**参数：**

| 参数项                    | 描述 |
|------------------------| -- |
| [ffrt_queue_t](capi-ffrt-ffrt-queue-t.md) queue | 并发队列。 |

**返回：**

| 类型                         | 说明 |
|----------------------------| -- |
| FFRT_C_API [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) | 创建成功返回ffrt_loop_t对象，<br>          创建失败返回空指针。 |

### ffrt_loop_destroy()

```
FFRT_C_API int ffrt_loop_destroy(ffrt_loop_t loop)
```

**描述**

销毁loop对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) loop | loop对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 销毁成功返回0，<br>          销毁失败返回-1。 |

### ffrt_loop_run()

```
FFRT_C_API int ffrt_loop_run(ffrt_loop_t loop)
```

**描述**

开启loop循环。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) loop | loop对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | loop循环失败返回-1，<br>          loop循环成功返回0。 |

### ffrt_loop_stop()

```
FFRT_C_API void ffrt_loop_stop(ffrt_loop_t loop)
```

**描述**

停止loop循环。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) loop | loop对象。 |

### ffrt_loop_epoll_ctl()

```
FFRT_C_API int ffrt_loop_epoll_ctl(ffrt_loop_t loop, int op, int fd, uint32_t events, void *data, ffrt_poller_cb cb)
```

**描述**

管理loop上的监听事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) loop | loop对象。 |
| int op | fd操作符。 |
| int fd | 事件描述符。 |
| uint32_t events | 事件。 |
| void *data | 事件变化时触发的回调函数的入参。 |
| [ffrt_poller_cb](capi-type-def-h.md#ffrt_poller_cb) cb | 事件变化时触发的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 成功返回0，<br>          失败返回-1。 |

### ffrt_loop_timer_start()

```
FFRT_C_API ffrt_timer_t ffrt_loop_timer_start(ffrt_loop_t loop, uint64_t timeout, void* data, ffrt_timer_cb cb, bool repeat)
```

**描述**

在ffrt loop上启动定时器。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_loop_t](capi-ffrt-ffrt-loop-t.md) loop | loop对象。 |
| uint64_t timeout | 超时时间(毫秒)。 |
| void* data | 事件变化时触发的回调函数的入参。 |
| [ffrt_timer_cb](capi-type-def-h.md#ffrt_timer_cb) cb | 事件变化时触发的回调函数。 |
| bool repeat | 是否重复执行该定时器。 |

**返回：**

| 类型                                               | 说明 |
|--------------------------------------------------| -- |
| FFRT_C_API [ffrt_timer_t](capi-type-def-h.md#变量) | 返回定时器句柄。 |

### ffrt_loop_timer_stop()

```
FFRT_C_API int ffrt_loop_timer_stop(ffrt_loop_t loop, ffrt_timer_t handle)
```

**描述**

停止ffrt loop定时器。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| ffrt_loop_t loop | loop对象。 |
| ffrt_timer_t handle | timer对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 成功返回0，<br>失败返回-1。 |


