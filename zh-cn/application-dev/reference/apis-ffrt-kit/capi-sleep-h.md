# sleep.h

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--SE: @geoffrey_guo; @huangyouzhong-->
<!--TSE: @lotsof; @sunxuhao-->

## 概述

声明sleep和yield的C接口。

**引用文件：** <ffrt/sleep.h>

**库：** libffrt.z.so

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 10

**相关模块：** [FFRT](capi-ffrt.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [FFRT_C_API int ffrt_usleep(uint64_t usec)](#ffrt_usleep) | 睡眠调用线程固定的时间。 |

## 函数说明

### ffrt_usleep()

```
FFRT_C_API int ffrt_usleep(uint64_t usec)
```

**描述**

睡眠调用线程固定的时间。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint64_t usec | 睡眠时间，单位是微秒。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| FFRT_C_API int | 执行成功时返回ffrt_success，<br>          执行失败时返回ffrt_error。 |


