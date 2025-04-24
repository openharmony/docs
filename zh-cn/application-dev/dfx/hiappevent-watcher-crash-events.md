# 崩溃事件介绍

## 概述

本文主要面向开发者介绍崩溃事件各个字段的含义以及规格，开发者如果想了解如何使用HiAppEvent提供接口订阅系统崩溃事件，请参考以下两篇文档，目前已提供ArkTs和C/C++两种接口，开发者按需使用。

- [订阅崩溃事件（ArkTS）](hiappevent-watcher-crash-events-arkts.md)
- [订阅崩溃事件（C/C++）](hiappevent-watcher-crash-events-ndk.md)

## 事件字段说明

### params字段说明

崩溃事件信息中params属性的详细描述如下：

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| time     | number | 事件触发时间，单位为毫秒。 |
| crash_type | string | 崩溃类型。支持JsError和NativeCrash两种崩溃类型。 |
| foreground | boolean | 应用是否处于前台状态。true表示处于前台状态；false表示处于后台状态。 |
| bundle_version | string | 应用版本。 |
| bundle_name | string | 应用名称。 |
| pid | number | 应用的进程id。|
| uid | number | 应用的用户id。 |
| uuid | string | 故障id。 |
| exception | object | 异常信息, 详见[exception字段说明](#exception字段说明)。包含故障简要信息，全量故障信息见external_log文件。 |
| hilog | string[] | 日志信息，最多显示100行hilog日志，更多hilog日志请查看故障日志文件。|
| threads | object[] | 全量线程调用栈，详见[thread字段说明](#thread字段说明)。仅NativeCrash类型的崩溃事件提供。 |
| external_log<sup>12+</sup> | string[] | 故障日志文件路径。故障日志文件包括cppcrash，jscrash。分析问题请参考[CppCrash分析指南](cppcrash-guidelines.md)和[JSCrash分析指南](jscrash-guidelines.md)。**为避免目录空间超限导致新生成的日志文件写入失败，日志文件处理完后请及时删除，超限规格请参考log_over_limit字段** |
| log_over_limit<sup>12+</sup> | boolean | 生成的故障日志文件与已存在的日志文件总大小是否超过5M上限。true表示超过上限，日志写入失败；false表示未超过上限。 |

### exception字段说明

#### JsError类型exception字段说明

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| name | string | 异常类型。 |
| message | string | 异常原因。 |
| stack | string | 异常调用栈。 |

#### NativeCrash类型exception字段说明

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| message | string | 异常原因。 |
| signal | object | 信号信息，详见[signal字段说明](#signal字段说明)。 |
| thread_name | string | 线程名。 |
| tid | number | 线程id。 |
| frames | object[] | 线程调用栈，详见[frame字段说明](#frame字段说明)。 |

### signal字段说明

信号详细介绍请参考[CppCrash分析指南崩溃信号说明](cppcrash-guidelines.md#哪些信号会生成cppcrash日志)

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| signo | number | 信号值 |
| code | number | 信号值二级分类 |
| address | string | 信号错误地址 |

### thread字段说明

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| thread_name | string | 线程名。 |
| tid | number | 线程id。 |
| frames | object[] | 线程调用栈，详见[frame字段说明](#frame字段说明)。 |

### frame字段说明

#### Native帧frame字段说明

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| file | string | 文件名称。也有可能是匿名内存映射，比如[heap]、[stack]等 |
| symbol | string | 函数名称。**名称长度超过256字节时会被删除掉，防止超长字符串引起未知问题。** |
| buildId | string | 文件唯一标识。**文件可能没有buildId，请参考[CppCrash分析指南崩溃日志内容说明](cppcrash-guidelines.md#崩溃日志内容说明)** |
| pc | string | 在文件内的偏移字节数。 |
| offset | number | 在函数内偏移字节数。 |

#### Js帧frame字段说明

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| file | string | 文件名。 |
| packageName | string | 模块的包名。 |
| symbol | string | 函数名称。 |
| column | number | 异常所在行。 |
| line | number | 异常所在列。 |
