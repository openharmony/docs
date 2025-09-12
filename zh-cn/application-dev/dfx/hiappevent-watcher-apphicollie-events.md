# 任务执行超时事件介绍

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @rr_cn-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 简介

任务执行超时指要监控的业务代码逻辑执行时长超过业务逻辑预期时间。为了更好地定位和分析问题，开发者可以利用[任务执行超时检测](apptask-timeout-guidelines.md#任务执行超时检测)机制，根据生成的[日志规格](apptask-timeout-guidelines.md#日志规格)，主动分析任务执行超时的执行情况。

## 检测原理

详见[任务执行超时检测原理](apptask-timeout-guidelines.md#检测原理)。

## 接口说明

开发者可以通过HiAppEvent提供接口订阅任务执行超时事件“EVENT_APP_HICOLLIE”，系统检测到任务执行超时后，会抓取维测信息通过HiAppEvent将任务执行超时回调给应用进程。

- [订阅任务执行超时事件（ArkTS）](hiappevent-watcher-apphicollie-events-arkts.md)
- [订阅任务执行超时事件（C/C++）](hiappevent-watcher-apphicollie-events-ndk.md)

## 事件字段说明

### params字段说明

任务执行超时事件信息中params属性的详细描述如下：

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| time | number | 事件触发时间，单位为ms。 |
| foreground | boolean | 应用是否处于前台状态。true表示应用处于前台；false表示应用处于后台。 |
| bundle_version | string | 应用版本。 |
| process_name | string | 应用的进程名称。 |
| pid | number | 应用的进程ID。 |
| uid | number | 应用的用户ID。 |
| uuid | string | 根据故障信息生成的故障特征码，用于标识特征相同的崩溃故障。 |
| exception | object | 异常信息，详见exception属性。 |
| hilog | string[] | 日志信息。 |
| peer_binder | string[] | binder调用信息，binder调用链及相关抓栈信息。 |
| memory | object | 内存信息，详见memory属性。 |
| external_log | string[] | 故障日志文件路径。**为避免目录空间超限（限制参考log_over_limit），导致新生成的日志文件写入失败，日志文件处理完后请及时删除。** |
| log_over_limit | boolean | 生成的故障日志文件与已存在的日志文件总大小是否超过5M上限。true表示超过上限，日志写入失败；false表示未超过上限。 |

### exception字段说明

exception属性的详细描述如下：

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| name | string | 异常类型 |
| message | string | 异常原因 |

### memory字段说明

memory属性的详细描述如下：

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| rss | number | 进程实际占用内存大小，单位KB。 |
| vss | number | 进程向系统申请的虚拟内存大小，单位KB。 |
| pss | number | 进程实际使用的物理内存大小，单位KB。 |
| sys_free_mem | number | 空闲内存大小，单位KB。 |
| sys_avail_mem | number | 可用内存大小，单位KB。 |
| sys_total_mem | number | 总内存大小，单位KB。 |
