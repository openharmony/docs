# HiCollie

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @rr_cn-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 概述

提供检测业务线程卡死或卡顿的能力。请注意：要在非业务线程中调用。本模块函数可用于：<br>（1）注册应用业务线程卡死的周期性检测任务；<br>（2）注册应用业务线程卡顿检测的回调函数；<br>（3）上报应用业务线程卡死事件。

**起始版本：** 12
## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [hicollie.h](capi-hicollie-h.md) | HiCollie模块对外提供检测业务线程卡死、卡顿，以及上报卡死事件的能力。 |
