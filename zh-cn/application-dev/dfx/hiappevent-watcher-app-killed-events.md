# 应用查杀事件介绍

## 概述

查杀是指应用程序被系统强制退出的一种现象。与应用崩溃不同，查杀并非源于应用自身业务代码的异常，而是主要归因于系统基于资源管控策略而对应用实施的查杀行为。

HiAppEvent提供接口用于订阅应用查杀事件。

- [订阅应用查杀事件（ArkTS）](hiappevent-watcher-app-killed-events-arkts.md)
- [订阅应用查杀事件（C/C++）](hiappevent-watcher-app-killed-events-ndk.md)

应用查杀事件信息中params属性的详细描述如下：

## 事件字段说明

### params字段说明

查杀事件信息中params属性的详细描述如下：

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| time     | number | 事件触发时间，单位为ms。 |
| reason  | string | 查杀原因，原因范围详见[reason字段说明](#reason字段说明)。 |
| foreground | boolean | 应用是否处于前台状态。true表示应用处于前台；false表示应用处于后台。 |

### reason字段说明

| 类型   | 说明                       |
| ------- | ------------------------- |
| IllegalAudioRendererBySuspend | 应用未申请合理的后台任务，但是后台有大量音频播放。 |
| LowMemoryKill | 整机低内存。 |
| OomKiller | 整机内存耗尽，无法继续分配。 |
| PowerSaveClean | 整机切换到省电模式或应急模式。 |
| ResourceLeak(AshmemLeak) | 整机Ashmem内存占用超标。 |
| ResourceLeak(GpuLeak) | 整机GPU内存占用超标。 |
| ResourceLeak(GpuRsLeak) | 应用在Render Service进程内的GPU内存占用超标。 |
| ResourceLeak(IonLeak) | 应用的Ion内存占用超标。 |
| RssThresholdKiller | 应用的RSS（Resident Size Set）占用超标。 |
| SwapFull | 整机Swap空间耗尽。 |
