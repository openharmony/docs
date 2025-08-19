# 应用冻屏事件介绍
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @rr_cn-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 简介

用户在使用应用时，如果出现点击无反应或应用无响应等情况，并且持续时间超过一定限制，就会被定义为应用冻屏，也被称为应用无响应或应用卡死。为了应对应用冻屏问题，系统会提供资应用冻屏检测、维测日志抓取、日志上报的能力，为开发者提供详细的维测日志以辅助故障定位。

## 检测原理

详见[AppFreeze（应用冻屏）检测原理](appfreeze-guidelines.md#检测原理)。

## 接口说明

开发者可以通过HiAppEvent提供接口订阅应用冻屏事件“hiAppEvent.event.APP_FREEZE”，系统检测到应用冻屏后，会抓取维测信息通过HiAppEvent将冻屏事件回调给应用进程。

- [订阅应用冻屏事件（ArkTS）](hiappevent-watcher-freeze-events-arkts.md)

- [订阅应用冻屏事件（C/C++）](hiappevent-watcher-freeze-events-ndk.md)

## 事件字段说明

### params字段说明

应用无响应事件信息中params属性的详细描述如下：

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| time | number | 事件触发时间，单位为ms。 |
| foreground | boolean | 应用是否处于前台状态。true表示应用处于前台；false表示应用处于后台。 |
| bundle_version | string | 应用版本。 |
| bundle_name | string | 应用名称。 |
| process_name | string | 应用的进程名称。 |
| pid | number | 应用的进程ID。 |
| uid | number | 应用的用户ID。 |
| uuid | string | 根据故障信息生成的故障特征码，用于标识特征相同的崩溃故障。 |
| exception | object | 异常信息，详见exception属性。 |
| hilog | string[] | 日志信息。 |
| event_handler | string[] | 主线程未处理消息。 |
| event_handler_size_3s | string | [THREAD_BLOCK_6S事件](appfreeze-guidelines.md#thread_block_6s-应用主线程卡死超时)（仅在应用无响应事件生效）中3s时任务栈中任务数量。 |
| event_handler_size_6s | string | [THREAD_BLOCK_6S事件](appfreeze-guidelines.md#thread_block_6s-应用主线程卡死超时)（仅在应用无响应事件生效）中6s时任务栈中任务数量。 |
| peer_binder | string[] | binder调用信息。 |
| threads | object[] | 全量线程调用栈，详见thread属性。 |
| memory | object | 内存信息，详见memory属性。 |
| external_log<sup>12+</sup> | string[] | 故障日志文件路径。**为避免目录空间超限（限制参考log_over_limit），导致新生成的日志文件写入失败，日志文件处理完后请及时删除。** |
| log_over_limit<sup>12+</sup> | boolean | 生成的故障日志文件与已存在的日志文件总大小是否超过5M上限。true表示超过上限，日志写入失败；false表示未超过上限。 |

### exception字段说明

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| name | string | 异常类型 |
| message | string | 异常原因 |

### thread字段说明

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| thread_name | string | 线程名。 |
| tid | number | 线程id。 |
| frames | object[] | 线程调用栈，详见frame属性。 |

### frame字段说明

Native帧frame字段说明

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| symbol | string | 函数名称。**名称长度超过256字节时将被删除，防止超长字符串引起未知问题。** |
| file | string | 文件名。 |
| buildId | string | 文件唯一标识。**文件可能没有buildId，请参考[日志规格](cppcrash-guidelines.md#一般故障场景日志规格)**。 |
| pc | string | 程序执行的指令在文件内的偏移十六进制字节数。 |
| offset | number | 程序执行的指令在函数内偏移字节数。 |

Js帧frame字段说明

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| file | string | 文件名 |
| packageName | string | 模块的包名 |
| symbol | string | 函数名称 |
| line | number | 代码行号 |
| column | number | 代码列号 |

### memory字段说明

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| rss | number | 进程实际占用内存大小，单位KB。 |
| vss | number | 进程向系统申请的虚拟内存大小，单位KB。 |
| pss | number | 进程实际使用的物理内存大小，单位KB。 |
| sys_free_mem | number | 空闲内存大小，单位KB。 |
| sys_avail_mem | number | 可用内存大小，单位KB。 |
| sys_total_mem | number | 总内存大小，单位KB。 |

## 应用冻屏规格自定义参数设置

### 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| setEventParam(params: Record&lt;string, ParamType>, domain: string, name?: string): Promise&lt;void> | **应用冻屏事件自定义参数设置方法。**|

### 参数设置说明

开发者可以通过该接口订阅name为hiAppEvent.event.APP_FREEZE的应用冻屏事件，具体使用详见[setEventParam使用](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventseteventparam12)。
