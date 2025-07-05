# 稳定性故障分析导读

本文档将简单介绍稳定性故障的概念与分类，并提供各类稳定性问题的参考帮助，用于指导OpenHarmony应用开发者充分利用系统提供的调试能力和工具定位各类稳定性问题。

应用稳定性问题主要包括应用崩溃、无响应、资源泄漏等问题，性能问题不属于稳定性范畴，要了解性能相关内容可以参考[UI性能优化概览](ui-performance-overview.md)。

<!--RP1-->
<!--RP1End-->

## 应用崩溃

应用崩溃有时也被称为应用闪退，指应用异常退出。应用异常退出的原因归纳起来主要有：

- 遇到未处理的JS异常，如`TypeError`、`ReferenceError`等
- 遇到未处理的native异常，如`SIGSEGV`、`SIGABRT`等
- 遇到系统资源限制被系统查杀，如内存不足、文件句柄不足、线程句柄不足等
- 应用UI无响应被系统查杀

本文档接下来提及的应用崩溃问题如无特别说明，指的是前两类，被分别称为jscrash问题和cppcrash问题，而后面两类则称为应用资源泄漏问题和应用无响应问题。

### jscrash

发生jscrash问题后，系统的FaultLogger模块会收集问题有关的各种故障信息，可参考该链接了解如何[获取日志](../dfx/jscrash-guidelines.md#获取日志)。

以下是一些关于jscrash问题的参考帮助：

- [分析jscrash](../dfx/jscrash-guidelines.md#分析js-crash进程崩溃)
- [jscrash问题排查方法](../dfx/jscrash-guidelines.md#问题定位思路)
- [jscrash问题案例分析](../dfx/jscrash-guidelines.md#分析案例)

### cppcrash

发生cppcrash问题后，系统的FaultLogger模块会收集问题有关的各种故障信息，可参考该链接了解如何[获取崩溃日志](../dfx/cppcrash-guidelines.md#获取崩溃日志)。

以下是一些关于cppcrash问题的参考帮助：

- [分析cppcrash](../dfx/cppcrash-guidelines.md#分析cppcrash进程崩溃)
- [cppcrash问题排查方法](../dfx/cppcrash-guidelines.md#cppcrash问题分析步骤)
- [cppcrash问题案例分析](../dfx/cppcrash-guidelines.md#案例分析)
<!--RP1-->
<!--RP1End-->

## 应用无响应

应用无响应问题也被称为AppFreeze问题，以下是一些关于AppFreeze问题的参考帮助：

- [分析AppFreeze](../dfx/appfreeze-guidelines.md#分析appfreeze应用无响应)
<!--RP1-->
<!--RP1End-->

## 应用资源泄漏

以下是一些关于应用资源泄漏问题的参考帮助：

- [资源泄漏事件介绍](../dfx/hiappevent-watcher-resourceleak-events.md)
- [订阅资源泄漏事件（ArkTS）](../dfx/hiappevent-watcher-resourceleak-events-arkts.md)
- [订阅资源泄漏事件（C/C++）](../dfx/hiappevent-watcher-resourceleak-events-ndk.md)
<!--RP1-->
<!--RP1End-->
