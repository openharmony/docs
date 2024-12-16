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
| exception | object | 异常信息，详见exception属性。NativeCrash类型的崩溃事件详见exception属性（NativeCrash类型）。exception只包含故障简要信息，具体的故障定位信息见external_log文件。 |
| hilog | string[] | 日志信息，最多显示100行hilog日志，更多hilog日志通过故障日志文件获取。|
| threads | object[] | 全量线程调用栈，详见thread属性。仅NativeCrash类型的崩溃事件提供。 |
| external_log<sup>12+</sup> | string[] | 故障日志文件路径。故障日志文件包括CPPCRASH，JSERROR。开发者可通过该路径下的文件，完成[CPPCRASH问题分析](cppcrash-guidelines.md)及[JSERROR问题分析](jscrash-guidelines.md)。**为避免目录空间超限（限制参考log_over_limit），导致新生成的日志文件写入失败，日志文件处理完后请及时删除。** |
| log_over_limit<sup>12+</sup> | boolean | 生成的故障日志文件与已存在的日志文件总大小是否超过5M上限。true表示超过上限，日志写入失败；false表示未超过上限。 |

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
| signo | number | 信号值(siginfo_t中的si_signo属性) |
| code | number | 信号值二级分类（siginfo_t中的si_code属性） |
| address | string | 信号错误地址（siginfo_t中的si_address属性） |

[信号值&信号值二级分类详解](cppcrash-guidelines.md)

**thread属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| thread_name | string | 线程名。 |
| tid | number | 线程id。 |
| frames | object[] | 线程调用栈，详见frame属性。 |

**frame属性(C/C++帧)：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| file | string | 文件名。 |
| symbol | string | 函数名称。 |
| buildId | string | 文件唯一标识。 |
| pc | string | pc寄存器地址。 |
| offset | number | 函数偏移量。 |

**frame属性(JS帧)：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| file | string | 文件名。 |
| symbol | string | 函数名称。 |
| column | number | 异常所在行。 |
| line | number | 异常所在列。 |
