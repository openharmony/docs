# 崩溃事件介绍

HiAppEvent提供接口用于订阅系统崩溃事件。

- [订阅崩溃事件（ArkTS）](hiappevent-watcher-crash-events-arkts.md)
- [订阅崩溃事件（C/C++）](hiappevent-watcher-crash-events-ndk.md)

崩溃事件信息中params属性的详细描述如下：

**params属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| time     | number | 事件触发时间，单位为毫秒。 |
| crash_type | string | 崩溃类型。支持JsError和NativeCrash两种崩溃类型。 |
| foreground | boolean | 应用是否处于前台状态。 |
| bundle_version | string | 应用版本。 |
| bundle_name | string | 应用名称。 |
| pid | number | 应用的进程id。|
| uid | number | 应用的用户id。 |
| uuid | string | 故障id。 |
| exception | object | 异常信息，详见exception属性。NativeCrash类型的崩溃事件详见exception属性（NativeCrash类型）。 |
| hilog | string[] | 日志信息。|
| threads | object[] | 全量线程调用栈，详见thread属性。仅NativeCrash类型的崩溃事件提供。 |
| external_log<sup>12+</sup> | string[] | 故障日志文件路径。 |
| log_over_limit<sup>12+</sup> | boolean | 生成的日志文件与已存在的日志文件总大小是否超过5M上限。true表示超过上限，日志写入失败；false表示未超过上限。 |

**exception属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| name | string | 异常类型。 |
| message | string | 异常原因。 |
| stack | string | 异常调用栈。 |

**exception属性（NativeCrash类型）：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| message | string | 异常原因。 |
| signal | object | 信号信息，详见signal属性。 |
| thread_name | string | 线程名。 |
| tid | number | 线程id。 |
| frames | object[] | 线程调用栈，详见frame属性。 |

**signal属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| signo | number | 信号值。 |
| code | number | 信号错误码。 |

**thread属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| thread_name | string | 线程名。 |
| tid | number | 线程id。 |
| frames | object[] | 线程调用栈，详见frame属性。 |

**frame属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| symbol | string | 函数名称。 |
| file | string | 文件名。 |
| buildId | string | 文件唯一标识。 |
| pc | string | pc寄存器地址。 |
| offset | number | 函数偏移量。 |
