# Performance Analysis Kit简介

Performance Analysis Kit（性能分析服务）为开发者提供应用事件、日志、跟踪分析工具，可观测应用运行时状态，用于行为分析、故障分析、安全分析、统计分析，帮助开发者持续改进应用体验。

Performance Analysis Kit承载着HarmonyOS DFX子系统面向应用开发者提供的提升应用质量能力集合，详见[应用质量概览](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-quality-overview)。

## 使用场景

- 应用调试：提供流水日志功能，帮助开发者记录和获取日志，以便进行问题分析。

- 问题定位：提供各类场景的故障现场，包含可靠性、性能、功耗、分布式故障相关的日志、事件、跟踪。

- 线上监控：提供应用构建线上观测所需的日志、事件、跟踪接口，方便开发者记录和分析应用的线上运行情况。


## 能力范围

- [HiLog流水日志](hilog-guidelines-arkts.md)，提供开发者记录和获取流水日志的能力。

- [HiAppEvent应用事件](hiappevent-intro.md)，提供开发者记录故障、行为、安全、统计事件的能力，并订阅系统事件，设置数据处理者以完成数据上传。

- [HiTraceMeter](hitracemeter-intro.md)和[HiTraceChain跟踪](hitracechain-intro.md)，提供开发者进行Trace度量和跨线程、跨进程分布式跟踪的能力。

- [HiChecker开发态检测](hichecker-guidelines-arkts.md)，提供开发者检测应用线程耗时调用、元能力资源泄漏等问题的能力。

- [HiDebug资源采集](hidebug-guidelines.md)，提供开发者获取应用、系统资源使用情况的能力。

- [HiCollie耗时检测](hicollie-guidelines-ndk.md)，提供开发者检测业务线程任务执行超时，以及上报超时事件的能力。

- 调试命令提供包含[hdc](hdc.md)、[hilog](hilog.md)、[hidumper](hidumper.md)、[hitrace](hitrace.md)、[hiperf](hiperf.md)等命令行工具用于调试系统和应用。


## 亮点/特征

**便捷的构建APM系统**

- 提供接口（[HiDebug](hidebug-guidelines.md)、[HiAppEvent](hiappevent-intro.md)、[HiLog](hilog-guidelines-arkts.md)），可用于自建端侧APM（Application Performance Management，应用性能管理平台）SDK，与厂商自研APM对接。

- 基于[HiAppEvent自定义事件](event-subscription-overview.md#应用事件)，订阅系统事件，快捷记录和收集运营和运维所需事件。

**强大的故障检测与异常处理机制**

- 提供全方位的故障检测能力，涵盖稳定性[故障检测](fault-detection-overview.md)、[性能检测](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/perf-detection)与[功耗检测](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/power-analysis)。

- 提供精简、标准且完备的异常日志，支持精准记录异常传播路径。

- 全面的异常检测机制，实时感知异常，通知应用，自动拉起恢复。

**全面的基础维测能力**

- 日志提供分级分类功能，支持多语言，隐私处理和流量控制。

- 提供完备的事件框架和事件打点、记录、上报机制。

- 支持追踪进程轨迹，进行程序性能分析。
