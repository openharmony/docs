# 查看HiTraceMeter日志

## 通过DevEco Studio可视化界面查看

使用DevEco Studio Profiler的CPU Insight功能，可视化展示HiTraceMeter日志内容，分析应用或服务的CPU使用率和线程运行状态，查看指定时间段内程序在CPU上的执行耗时。具体使用指导请参考[CPU活动分析：CPU分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-insight-session-cpu)。

## 通过命令行工具查看

1. 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)，确保可以使用 `hdc shell` 命令正常连接设备。

2. 在DevEco Studio的Terminal窗口或主机命令行窗口执行 `hdc shell` 命令连接设备，然后在设备上执行[hitrace](hitrace.md)命令，开启HiTraceMeter日志抓取服务。

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

3. 在设备上运行包含HiTraceMeter打点的相关程序。

4. 转储HiTraceMeter文本日志，该日志包含步骤3中生成的HiTraceMeter打点信息。

   - 默认将日志打印在窗口中。

   ```shell
   $ hitrace --trace_dump
   ```

   - 可提供文件名将日志保存至文件中，文件路径只能是 `/data/local/tmp/`，其他路径无权限。

   ```shell
   $ hitrace --trace_dump -o /data/local/tmp/trace.ftrace
   ```

5. 在设备上执行hitrace命令，停止HiTraceMeter日志抓取服务。

   ```shell
   $ hitrace --trace_finish
   ```

6. 退出设备，进入主机，导出设备中的HiTraceMeter文本日志到当前目录。

   ```shell
   $ exit
   PS D:\xxx\xxx> hdc file recv /data/local/tmp/trace.ftrace ./
   ```

7. 搜索HiTraceMeter文本日志中的打点名称等关键字，查看打点是否成功。

8. HiTraceMeter支持文本日志的可视化分析。

   - 导入DevEco Studio进行分析。
     在DevEco Studio Profiler的会话区选择“Open File”，将HiTraceMeter文本日志导入DevEco Studio。
     具体分析可参考[CPU活动分析：CPU分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-insight-session-cpu)文档。
   - 通过[HiSmartPerf](https://gitee.com/openharmony/developtools_smartperf_host)工具进行分析，工具下载链接[developtools_smartperf_host 发行版](https://gitee.com/openharmony/developtools_smartperf_host/releases)。

## 用户态trace格式说明

### API 19前用户态trace格式

| 打点类型          | 开启HiTraceChain时格式                              | 未开启HiTraceChain时格式 |
| ----------------- | --------------------------------------------------- | ------------------------ |
| 开始同步trace打点 | B\|PID\|H:[ChainId,SpanId,ParentSpanId]#name        | B\|PID\|H:name           |
| 结束同步trace打点 | E\|PID\|                                            | E\|PID\|                 |
| 开始异步trace打点 | S\|PID\|H:[ChainId,SpanId,ParentSpanId]#name taskId | S\|PID\|H:name taskId    |
| 结束异步trace打点 | F\|PID\|H:[ChainId,SpanId,ParentSpanId]#name taskId | F\|PID\|H:name taskId    |
| 整数trace打点     | C\|PID\|H:[ChainId,SpanId,ParentSpanId]#name count  | C\|PID\|H:name count     |

> **说明：**
>
> 用户态trace总长度限制512字符，超过部分将被截断。

#### 格式中的字段说明

- **B/E/S/F/C**

  - B：开始同步trace打点。
  - E：结束同步trace打点。
  - S：开始异步trace打点。
  - F：结束异步trace打点。
  - C：整数trace打点。

- **PID**

  进程ID。

- **[ChainId,SpanId,ParentSpanId]#**

  开启HiTraceChain时，会将HiTraceId记录在trace打点中，结尾使用#分隔符与`name`字段区分。

  未开启HiTraceChain时，打点不包含该字段。

  - ChainId：HiTraceId的链Id。
  - SpanId：HiTraceId的当前跨度号。
  - ParentSpanId：HiTraceId的父跨度号。

- **name**

  `name`字段表示打点名称或整数变量名。

- **taskId**

  `taskId`字段表示异步跟踪id，和`name`字段一起用于匹配相同的异步开始与结束打点。

  `taskId`与`name`字段之间使用空格进行分隔。

- **count**

  `count`字段为整数值。

  `count`与`name`字段之间使用空格进行分隔。

### API 19后用户态trace格式

各字段均使用竖线作为分隔符，对后续新增字段，均以**竖线+字段**的方式，追加在当前用户态trace格式的末尾。

| 打点类型          | 开启HiTraceChain时格式                                       | 未开启HiTraceChain时格式                                     |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 开始同步trace打点 | B\|PID\|H:[ChainId,SpanId,ParentSpanId]#name\|%level%tag\|customArgs | B\|PID\|H:name\|%level%tag\|customArgs                       |
| 结束同步trace打点 | E\|PID\|%level%tag                                           | E\|PID\|%level%tag                                           |
| 开始异步trace打点 | S\|PID\|H:[ChainId,SpanId,ParentSpanId]#name\|taskId\|%level%tag\|customCategory\|customArgs | S\|PID\|H:name\|taskId\|%level%tag\|customCategory\|customArgs |
| 结束异步trace打点 | F\|PID\|H:[ChainId,SpanId,ParentSpanId]#name\|taskId\|%level%tag | F\|PID\|H:name\|taskId\|%level%tag                           |
| 整数trace打点     | C\|PID\|H:[ChainId,SpanId,ParentSpanId]#name\|count\|%level%tag | C\|PID\|H:name\|count\|%level%tag                            |

> **说明：**
>
> 用户态trace总长度限制512字符，建议`name`、`customCategory`和`customArgs`总长度不超过420字符，避免被截断。

#### 格式中的字段说明

- **B/E/S/F/C**

  - B：开始同步trace打点。
  - E：结束同步trace打点。
  - S：开始异步trace打点。
  - F：结束异步trace打点。
  - C：整数trace打点。

- **PID**

  进程ID。

- **[ChainId,SpanId,ParentSpanId]#**

  开启HiTraceChain时，会将HiTraceId记录在trace打点中，结尾使用#分隔符与`name`字段区分。

  未开启HiTraceChain时，打点不包含该字段。

  - ChainId：HiTraceId的链Id。
  - SpanId：HiTraceId的当前跨度号。
  - ParentSpanId：HiTraceId的父跨度号。

- **name**

  `name`字段表示打点名称或整数变量名。

- **taskId**

  `taskId`字段表示异步跟踪id，和`name`字段一起用于匹配相同的异步开始与结束打点。

- **count**

  `count`字段为整数值。

- **%level**

  通过打点接口传入的`level`字段，表示打点级别，该字段为以下字符之一：D、I、C、M。

  `level`字段与%level映射关系参考[HiTraceOutputLevel](#hitraceoutputlevel)。

  > **说明：**
  >
  > API 19前的trace打点接口没有`level`字段，这些trace打点默认为COMMERCIAL级别打点。

- **%tag**

  %tag字段表示trace打点所属tag类别，每类用两位数字表示，可包含多个从小到大排列的两位数字。例如 `B|1314|H:TestFunction|I3062`，表示该条打点属于HITRACE_TAG_OHOS及HITRACE_TAG_APP两类tag下的打点。

  tag名称、tag值与%tag映射关系参考[HiTraceMeter Tag](#hitracemeter-tag)。

  > **说明：**
  >
  > NDK C/C++和ArkTs/JS的HiTraceMeter性能打点接口并没有字段与%tag对应，这些打点接口均属于应用打点，对应的tag名称为HITRACE_TAG_APP，用户态trace中的%tag字段值为62。

- **customCategory**

  `customCategory`字段表示自定义聚类名称。

  在trace可视化工具中，同一进程中相同聚类名称的异步打点放在同一泳道上进行展示。

- **customArgs**

  `customArgs`字段表示自定义键值对，格式为“key=value”，多个键值对使用逗号分隔，例如“key1=value1,key2=value2”。

  在trace可视化工具中，对满足格式要求的`customArgs`以键值对形式展示解析结果。

#### 特殊情况说明

实际开发中，如`customCategory`和`customArgs`字段不需要，则传入空字符串（仅开始同步trace打点接口和开始异步trace打点接口涉及这两个字段）。
针对这两个字段是否为空字符串的情况，以未开启HiTraceChain时的格式为例，进行说明。HiTraceChain具体使用指导请参考[使用HiTraceChain打点](hitracechain-guidelines-arkts.md)。

API 19前的trace打点接口默认将这两个字段视为空字符串。

- 开始同步trace打点接口

  - `customArgs`字段不为空字符串

    ```text
    B|PID|H:name|%level%tag|customArgs
    ```

  - `customArgs`字段为空字符串

    ```text
    B|PID|H:name|%level%tag
    ```

- 开始异步trace打点接口

  - `customCategory`和`customArgs`字段均不为空字符串

    ```text
    S|PID|H:name|taskId|%level%tag|customCategory|customArgs
    ```

  - `customCategory`字段为空字符串，`customArgs`字段不为空字符串

    ```text
    S|PID|H:name|taskId|%level%tag||customArgs
    ```

  - `customCategory`字段不为空字符串，`customArgs`字段为空字符串

    ```text
    S|PID|H:name|taskId|%level%tag|customCategory
    ```

  - `customCategory`和`customArgs`字段均为空字符串

    ```text
    S|PID|H:name|taskId|%level%tag
    ```
### HiTraceMeter Tag

| tag名称                              | tag值      | %tag |
| ------------------------------------ | ---------- | ---- |
| HITRACE_TAG_ALWAYS                   | 1ULL << 0  | 00   |
| HITRACE_TAG_COMMERCIAL               | 1ULL << 5  | 05   |
| HITRACE_TAG_DRM                      | 1ULL << 6  | 06   |
| HITRACE_TAG_SECURITY                 | 1ULL << 7  | 07   |
| HITRACE_TAG_ANIMATION                | 1ULL << 9  | 09   |
| HITRACE_TAG_PUSH                     | 1ULL << 10 | 10   |
| HITRACE_TAG_VIRSE                    | 1ULL << 11 | 11   |
| HITRACE_TAG_MUSL                     | 1ULL << 12 | 12   |
| HITRACE_TAG_FFRT                     | 1ULL << 13 | 13   |
| HITRACE_TAG_CLOUD                    | 1ULL << 14 | 14   |
| HITRACE_TAG_DEV_AUTH                 | 1ULL << 15 | 15   |
| HITRACE_TAG_COMMONLIBRARY            | 1ULL << 16 | 16   |
| HITRACE_TAG_HDCD                     | 1ULL << 17 | 17   |
| HITRACE_TAG_HDF                      | 1ULL << 18 | 18   |
| HITRACE_TAG_USB                      | 1ULL << 19 | 19   |
| HITRACE_TAG_INTERCONNECTION          | 1ULL << 20 | 20   |
| HITRACE_TAG_DLP_CREDENTIAL           | 1ULL << 21 | 21   |
| HITRACE_TAG_ACCESS_CONTROL           | 1ULL << 22 | 22   |
| HITRACE_TAG_NET                      | 1ULL << 23 | 23   |
| HITRACE_TAG_NWEB                     | 1ULL << 24 | 24   |
| HITRACE_TAG_HUKS                     | 1ULL << 25 | 25   |
| HITRACE_TAG_USERIAM                  | 1ULL << 26 | 26   |
| HITRACE_TAG_DISTRIBUTED_AUDIO        | 1ULL << 27 | 27   |
| HITRACE_TAG_DLSM                     | 1ULL << 28 | 28   |
| HITRACE_TAG_FILEMANAGEMENT           | 1ULL << 29 | 29   |
| HITRACE_TAG_OHOS                     | 1ULL << 30 | 30   |
| HITRACE_TAG_ABILITY_MANAGER          | 1ULL << 31 | 31   |
| HITRACE_TAG_ZCAMERA                  | 1ULL << 32 | 32   |
| HITRACE_TAG_ZMEDIA                   | 1ULL << 33 | 33   |
| HITRACE_TAG_ZIMAGE                   | 1ULL << 34 | 34   |
| HITRACE_TAG_ZAUDIO                   | 1ULL << 35 | 35   |
| HITRACE_TAG_DISTRIBUTEDDATA          | 1ULL << 36 | 36   |
| HITRACE_TAG_MDFS                     | 1ULL << 37 | 37   |
| HITRACE_TAG_GRAPHIC_AGP              | 1ULL << 38 | 38   |
| HITRACE_TAG_ACE                      | 1ULL << 39 | 39   |
| HITRACE_TAG_NOTIFICATION             | 1ULL << 40 | 40   |
| HITRACE_TAG_MISC                     | 1ULL << 41 | 41   |
| HITRACE_TAG_MULTIMODALINPUT          | 1ULL << 42 | 42   |
| HITRACE_TAG_SENSORS                  | 1ULL << 43 | 43   |
| HITRACE_TAG_MSDP                     | 1ULL << 44 | 44   |
| HITRACE_TAG_DSOFTBUS                 | 1ULL << 45 | 45   |
| HITRACE_TAG_RPC                      | 1ULL << 46 | 46   |
| HITRACE_TAG_ARK                      | 1ULL << 47 | 47   |
| HITRACE_TAG_WINDOW_MANAGER           | 1ULL << 48 | 48   |
| HITRACE_TAG_ACCOUNT_MANAGER          | 1ULL << 49 | 49   |
| HITRACE_TAG_DISTRIBUTED_SCREEN       | 1ULL << 50 | 50   |
| HITRACE_TAG_DISTRIBUTED_CAMERA       | 1ULL << 51 | 51   |
| HITRACE_TAG_DISTRIBUTED_HARDWARE_FWK | 1ULL << 52 | 52   |
| HITRACE_TAG_GLOBAL_RESMGR            | 1ULL << 53 | 53   |
| HITRACE_TAG_DEVICE_MANAGER           | 1ULL << 54 | 54   |
| HITRACE_TAG_SAMGR                    | 1ULL << 55 | 55   |
| HITRACE_TAG_POWER                    | 1ULL << 56 | 56   |
| HITRACE_TAG_DISTRIBUTED_SCHEDULE     | 1ULL << 57 | 57   |
| HITRACE_TAG_DEVICE_PROFILE           | 1ULL << 58 | 58   |
| HITRACE_TAG_DISTRIBUTED_INPUT        | 1ULL << 59 | 59   |
| HITRACE_TAG_BLUETOOTH                | 1ULL << 60 | 60   |
| HITRACE_TAG_ACCESSIBILITY_MANAGER    | 1ULL << 61 | 61   |
| HITRACE_TAG_APP                      | 1ULL << 62 | 62   |

### HiTraceOutputLevel

| trace输出级别枚举名称（C/C++） | trace输出级别枚举名称（ArkTS/JS） | 枚举值 | %level |
| ------------------------------ | --------------------------------- | ------ | ------ |
| HITRACE_LEVEL_DEBUG            | DEBUG                             | 0      | D      |
| HITRACE_LEVEL_INFO             | INFO                              | 1      | I      |
| HITRACE_LEVEL_CRITICAL         | CRITICAL                          | 2      | C      |
| HITRACE_LEVEL_COMMERCIAL       | COMMERCIAL                        | 3      | M      |
