# HiCollie

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## 概述

提供检测业务线程卡死、卡顿，以及上报卡死事件的能力。本模块函数支持以下功能：<br>（1）注册应用业务线程卡死的周期性检测任务；<br>（2）注册应用业务线程卡顿检测的回调函数；<br>（3）上报应用业务线程卡死事件。<br> 使用场景：应用卡顿问题定位、线程健康状态监控、开发调试阶段的卡死问题诊断、卡顿数据采集与分析。

**起始版本：** 12

**系统能力：** SystemCapability.HiviewDFX.HiCollie

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [hicollie.h](capi-hicollie-h.md) | HiCollie模块提供检测业务线程卡死、卡顿，以及上报卡死事件的能力。 |
