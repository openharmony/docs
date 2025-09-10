# timer.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## 概述

声明定时器的C接口。

**引用文件：** <ffrt/timer.h>

**库：** libffrt.z.so

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 12

**相关模块：** [FFRT](capi-ffrt.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [FFRT_C_API ffrt_timer_t ffrt_timer_start(ffrt_qos_t qos, uint64_t timeout, void* data, ffrt_timer_cb cb, bool repeat)](#ffrt_timer_start) | 启动计时器。 |
| [FFRT_C_API int ffrt_timer_stop(ffrt_qos_t qos, ffrt_timer_t handle)](#ffrt_timer_stop) | 关闭计时器。 |

## 函数说明

### ffrt_timer_start()

```
FFRT_C_API ffrt_timer_t ffrt_timer_start(ffrt_qos_t qos, uint64_t timeout, void* data, ffrt_timer_cb cb, bool repeat)
```

**描述**

启动计时器。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ffrt_qos_t](capi-type-def-h.md#变量) qos | QoS等级。 |
| uint64_t timeout | 超时时间(毫秒)。 |
| void* data | 超时后回调函数的入参。 |
| [ffrt_timer_cb](capi-type-def-h.md#ffrt_timer_cb) cb | 超时执行的回调函数。 |
| bool repeat | 是否重复执行该定时器（该功能暂未支持）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API [ffrt_timer_t](capi-type-def-h.md#变量) | 返回定时器句柄。 |

### ffrt_timer_stop()

```
FFRT_C_API int ffrt_timer_stop(ffrt_qos_t qos, ffrt_timer_t handle)
```

**描述**

关闭计时器。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| ffrt_qos_t qos | QoS等级。 |
| ffrt_timer_t handle | 定时器句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 关闭成功返回0，<br>          关闭失败返回-1。 |


