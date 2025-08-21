# Hitrace

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 概述

hitraceChain为开发者提供跨线程、跨进程的分布式跟踪能力。HiTraceChain支持在业务执行流程中，生成和传递唯一跟踪标识，在业务流程中输出的各类调试信息中（包括应用事件、系统事件、日志等）携带该跟踪标识。在调试、问题定位过程中，开发人员可以通过该唯一跟踪标识将本次业务流程端到端的各类信息快速关联起来。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 10
## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [trace.h](capi-trace-h.md) | HiTraceMeter模块打点接口定义，通过这些接口实现性能打点相关功能。用户态tarce格式使用竖线 `|` 作为分隔符，所以通过HiTraceMeter接口传递的字符串类型参数应避免包含该字符，防止trace解析异常。<br> 用户态trace总长度限制512字符，超过的部分将会被截断。<br> |
