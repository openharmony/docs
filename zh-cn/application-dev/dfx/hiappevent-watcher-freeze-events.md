# 卡死事件介绍

HiAppEvent提供接口用于订阅系统卡死事件。

- [订阅卡死事件（ArkTS）](hiappevent-watcher-freeze-events-arkts.md)
- [订阅卡死事件（C/C++）](hiappevent-watcher-freeze-events-ndk.md)

卡死事件信息中params属性的详细描述如下：

**params属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| time     | number | 事件触发时间，单位为毫秒。 |
| foreground | boolean | 应用是否处于前台状态。true表示应用处于前台；false表示应用处于后台。|
| bundle_version | string | 应用版本。 |
| bundle_name | string | 应用名称。 |
| process_name | string | 应用的进程名称。 |
| pid | number | 应用的进程id。|
| uid | number | 应用的用户id。 |
| uuid | string | 根据故障信息生成的故障特征码，用于标识特征相同的崩溃故障。 |
| exception | object | 异常信息，详见exception属性。 |
| hilog | string[] | 日志信息。|
| event_handler | string[] | 主线程未处理消息。 |
| event_handler_size_3s | string | [THREAD_BLOCK_6S事件](appfreeze-guidelines.md#thread_block_6s-应用主线程卡死超时)（仅在该事件生效）中3s时任务栈中任务数。 |
| event_handler_size_6s | string | THREAD_BLOCK_6S事件（仅在该事件生效）中6s时任务栈中任务数。 |
| peer_binder | string[] | binder调用信息。 |
| threads | object[] | 全量线程调用栈，详见thread属性。 |
| memory | object | 内存信息，详见memory属性。 |
| external_log<sup>12+</sup> | string[] | 故障日志文件路径。**为避免目录空间超限（限制参考log_over_limit），导致新生成的日志文件写入失败，日志文件处理完后请及时删除。** |
| log_over_limit<sup>12+</sup> | boolean | 生成的故障日志文件与已存在的日志文件总大小是否超过5M上限。true表示超过上限，日志写入失败；false表示未超过上限。 |

**exception属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| name | string | 异常类型。 |
| message | string | 异常原因。 |

**thread属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| thread_name | string | 线程名。 |
| tid | number | 线程id。 |
| frames | object[] | 线程调用栈，详见frame属性。 |

**frame属性(Native帧)：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| symbol | string | 函数名称。**在整机高负载的情况下，采用低开销方式获取调用栈的情况，可能损失函数名称。** |
| file | string | 文件名。 |
| buildId | string | 文件唯一标识。**在整机高负载的情况下，采用低开销方式获取调用栈的情况，可能损失build-id信息。** |
| pc | string | 程序执行的指令在文件内的偏移十六进制字节数。|
| offset | number | 程序执行的指令在函数内偏移字节数。|

**frame属性(JS帧)：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| file | string | 文件名。 |
| packageName | string | 模块的包名。 |
| symbol | string | 函数名称。 |
| line | number | 异常所在代码行号。 |
| column | number | 异常所在代码列号。|

**memory属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| rss | number | 进程实际占用内存大小，单位KB。 |
| vss | number | 进程向系统申请的虚拟内存大小，单位KB。 |
| pss | number | 进程实际使用的物理内存大小，单位KB。 |
| sys_free_mem | number | 空闲内存大小，单位KB。 |
| sys_avail_mem | number | 可用内存大小，单位KB。 |
| sys_total_mem | number | 总内存大小，单位KB。 |
