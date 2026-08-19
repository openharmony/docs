# HiDebug

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @leiguangyu-->
<!--Designer: @mgce1-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## 概述

提供调试功能。本模块函数可用于获取CPU usage、memory、heap、capture trace等。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**起始版本：** 12

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [hidebug.h](capi-hidebug-h.md) | 定义HiDebug模块的调试功能，提供CPU使用率监控、内存信息查询、trace采集、栈回溯、性能采样、内存导出监听、维测信息记录等能力，帮助开发者进行应用性能分析、资源管理和问题诊断。 |
| [hidebug_type.h](capi-hidebug-type-h.md) | HiDebug模块提供系统性能分析和调试能力的结构体定义，支持线程CPU使用率统计、系统内存信息采集、Native内存追踪、栈回溯分析等功能。用于性能优化、问题诊断、资源监控等场景，帮助开发者快速定位性能瓶颈、内存泄漏等问题。模块设计遵循统一的数据结构规范，提供trace采集、资源采集等功能的配置和回调类型，支持多维度性能数据采集和分析。 |
