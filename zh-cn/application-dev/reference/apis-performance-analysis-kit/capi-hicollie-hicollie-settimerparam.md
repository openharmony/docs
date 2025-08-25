# HiCollie_SetTimerParam

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @rr_cn-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 概述

定义OH_HiCollie_SetTimer函数的输入参数。

**起始版本：** 18

**相关模块：** [HiCollie](capi-hicollie.md)

**所在头文件：** [hicollie.h](capi-hicollie-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| const char *name | timer任务名称。 |
| unsigned int timeout | 任务超时时间阈值，单位s。 |
| [OH_HiCollie_Callback](capi-hicollie-h.md#oh_hicollie_callback) func | 超时发生时执行的回调函数。 |
| void *arg                                                            | 回调函数的参数。 |
| [HiCollie_Flag](capi-hicollie-h.md#hicollie_flag) flag               | 超时发生时执行的动作，参考[HiCollie_Flag](capi-hicollie-h.md#hicollie_flag)。 |


