# FFRT

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## 概述

FFRT（Function Flow运行时）是支持Function Flow编程模型的软件运行时库，用于调度执行开发者基于Function Flow编程模型开发的应用。

**起始版本：** 10
## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [condition_variable.h](capi-condition-variable-h.md) | 声明条件变量的C接口。 |
| [fiber.h](capi-fiber-h.md) | 纤程是一种轻量级的用户态线程，用于在用户空间内实现高效的任务调度和上下文切换，此为声明纤程的C接口。 |
| [loop.h](capi-loop-h.md) | 声明循环的C接口。 |
| [mutex.h](capi-mutex-h.md) | 声明mutex的C接口。 |
| [queue.h](capi-queue-h.md) | 声明队列的C接口。 |
| [shared_mutex.h](capi-shared-mutex-h.md) | 声明rwlock的C接口。 |
| [sleep.h](capi-sleep-h.md) | 声明sleep和yield的C接口。 |
| [task.h](capi-task-h.md) | 声明任务的C接口。 |
| [timer.h](capi-timer-h.md) | 声明定时器的C接口。 |
| [type_def.h](capi-type-def-h.md) | 定义通用类型。 |
