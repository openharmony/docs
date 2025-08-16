# Performance Analysis Kit简介

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @mzyan-->
<!--Designer: @liyueric-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

Performance Analysis Kit（性能分析服务）为开发者提供应用事件、日志、跟踪分析工具，可观测应用运行时状态，用于行为分析、故障分析、安全分析、统计分析，帮助开发者持续改进应用体验。

Performance Analysis Kit承载着HarmonyOS DFX子系统面向应用开发者提供的提升应用质量能力集合，详见[应用质量概览](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-quality-overview)。

## 使用场景

- 应用调试：提供流水日志功能，帮助开发者记录和获取日志，以便进行问题分析。

- 问题定位：提供各类场景的故障现场，包含可靠性、性能、功耗、分布式故障相关的日志、事件、跟踪。

- 线上监控：提供应用构建线上观测所需的日志、事件、跟踪接口，方便开发者记录和分析应用的线上运行情况。


## 能力范围

- [故障检测](fault-detection-overview.md)，提供开发者检测应用稳定性故障的能力，包括崩溃检测、地址越界检测、应用冻屏检测、资源泄漏检测、任务超时检测等。

- [功耗检测](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/power-analysis)，提供开发者检测应用功耗异常的能力，如CPU高负载检测。

- [性能检测](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/perf-detection)，提供开发者检测应用性能异常的能力，如应用启动耗时检测、滑动丢帧检测等。

- [日志打印](hilog-guidelines-arkts.md)，提供开发者记录和获取流水日志的能力。

- [事件订阅](hiappevent-intro.md)，提供开发者记录故障、行为、安全、统计事件的能力，并订阅系统事件，设置数据处理者以完成数据上传。

- [性能跟踪](hitracemeter-intro.md)与[分布式调用链跟踪](hitracechain-intro.md)，提供开发者通过进行性能追踪和跨线程、跨进程的分布式跟踪能力。

- [检测模式](hichecker-guidelines-arkts.md)，提供开发者检测应用线程耗时调用、元能力资源泄漏等问题的能力。

- [系统调试信息获取](hidebug-guidelines.md)，提供开发者获取应用和系统资源使用情况的能力。

- [业务线程超时检测](hicollie-guidelines-ndk.md)，提供开发者检测业务线程任务执行超时并上报超时事件的能力。

- [错误管理](errormanager-guidelines.md)与[应用恢复](apprecovery-guidelines.md)，提供开发者捕获应用运行时异常能力，以及应用非预期退出后启动状态和数据的自恢复能力。

- 调试命令提供包含[hdc](hdc.md)、[hilog](hilog.md)、[hidumper](hidumper.md)、[hitrace](hitrace.md)、[hiperf](hiperf.md)等工具用于调试系统和应用。


## 亮点/特征

**便捷的构建APM系统**

- 提供接口（[HiDebug](hidebug-guidelines.md)、[HiAppEvent](hiappevent-intro.md)、[HiLog](hilog-guidelines-arkts.md)），可用于自建端侧APM（Application Performance Management，应用性能管理平台）SDK，与厂商自研APM对接。

- 基于[HiAppEvent自定义事件](event-subscription-overview.md#应用事件)，订阅系统事件，快捷记录和收集运营和运维所需事件。

**强大的故障检测与异常处理机制**

- 提供全方位的应用质量检测能力，涵盖[故障检测](fault-detection-overview.md)、[性能检测](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/perf-detection)与[功耗检测](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/power-analysis)。

- 提供精简、标准且完备的异常日志，支持精准记录异常传播路径。

- 全面的异常检测机制，实时感知异常，通知应用，自动拉起恢复。

**全面的基础维测能力**

- 日志提供分级分类功能，支持多语言，隐私处理和流量控制。

- 提供完备的事件框架和事件打点、记录、上报机制。

- 支持追踪进程轨迹，进行程序性能分析。
