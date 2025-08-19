# fiber.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## 概述

纤程是一种轻量级的用户态线程，用于在用户空间内实现高效的任务调度和上下文切换，此为声明纤程的C接口。

**库：** libffrt.z.so

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 20

**相关模块：** [FFRT](capi-ffrt.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [FFRT_C_API int ffrt_fiber_init(ffrt_fiber_t* fiber, void(\*func)(void*), void* arg, void* stack, size_t stack_size)](#ffrt_fiber_init) | 纤程初始化函数，此函数初始化纤程实例，该实例可以存储上下文。 |
| [FFRT_C_API void ffrt_fiber_switch(ffrt_fiber_t* from, ffrt_fiber_t* to)](#ffrt_fiber_switch) | 纤程切换函数，调用该函数的线程会暂停当前任务的执行，并将当前上下文保存到from纤程中，同时恢复to纤程中的上下文。 |

## 函数说明

### ffrt_fiber_init()

```
FFRT_C_API int ffrt_fiber_init(ffrt_fiber_t* fiber, void(*func)(void*), void* arg, void* stack, size_t stack_size)
```

**描述**

纤程初始化函数，此函数初始化纤程实例，该实例可以存储上下文。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| fiber | 指向要初始化的纤程的指针, 具体可参考[ffrt_fiber_t](capi-ffrt-ffrt-fiber-t.md)。 |
| func | 纤程切换后所要执行的方法。 |
|  void* arg | 纤程切换后所要执行方法的入参。 |
|  void* stack | 纤程堆栈内存指针。 |
|  size_t stack_size | 纤程堆栈大小, 具体可参考[ffrt_storage_size_t](capi-type-def-h.md#ffrt_storage_size_t)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int (ffrt_fiber_t* fiber, void(*func) | 初始化成功返回ffrt_success，否则返回ffrt_error。 |

### ffrt_fiber_switch()

```
FFRT_C_API void ffrt_fiber_switch(ffrt_fiber_t* from, ffrt_fiber_t* to)
```

**描述**

纤程切换函数，调用该函数的线程会暂停当前任务的执行，并将当前上下文保存到from纤程中，同时恢复to纤程中的上下文。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_fiber_t](capi-ffrt-ffrt-fiber-t.md)* from | 将要保存的纤程指针。 |
| [ffrt_fiber_t](capi-ffrt-ffrt-fiber-t.md)* to | 将要恢复的纤程指针。 |


