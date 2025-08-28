# 查看HiTraceMeter日志

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @kutcherzhou1; @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 通过DevEco Studio可视化界面查看

使用DevEco Studio Profiler工具可以可视化展示HiTraceMeter日志内容，分析应用或服务的CPU使用率和线程运行状态，查看指定时间段内程序在CPU上的执行耗时。具体使用指导请参考[CPU活动分析：CPU分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-insight-session-cpu)。


## 通过命令行工具查看

1. 根据hdc命令行工具指导，完成[hdc环境准备](hdc.md#环境准备)，确保可以使用“hdc shell”命令正常连接设备。

2. 在DevEco Studio Terminal窗口或主机命令行窗口执行“hdc shell”命令连接设备，然后在设备上执行[hitrace](hitrace.md)命令，开启HiTraceMeter日志抓取服务。

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

3. 在设备上运行包含HiTraceMeter打点的相关程序。

4. 使用hitrace命令行工具采集文本格式trace信息，将trace文件保存到设备/data/local/tmp/路径下，具体流程可参考[快照模式捕获文本格式trace](hitrace.md#快照模式捕获文本格式trace)。

5. 退出设备，进入主机，导出设备中的HiTraceMeter文本日志到当前目录（下面命令中的trace.ftrace根据采集时设置的文件名修改）。

   ```shell
   $ exit
   PS D:\xxx\xxx> hdc file recv /data/local/tmp/trace.ftrace ./
   ```

6. 在HiTraceMeter文本日志中搜索打点名称等关键字，查看打点是否成功。

7. HiTraceMeter支持文本日志的可视化分析。

   - 在DevEco Studio中导入日志进行分析。

      在DevEco Studio Profiler的会话区选择“Open File”，将HiTraceMeter文本日志导入DevEco Studio。

      具体分析可参考[CPU活动分析：CPU分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-insight-session-cpu)文档。
   - 通过[Smartperf_Host](https://gitee.com/openharmony/developtools_smartperf_host)工具进行分析，工具下载链接：[developtools_smartperf_host 发行版](https://gitee.com/openharmony/developtools_smartperf_host/releases)。

## 用户态trace格式说明

开发者可以通过[hitrace](hitrace.md)命令采集用户通过HiTraceMeter接口生成的用户态trace日志，从而对应用进行性能分析。本章节将详细介绍用户态trace的格式和扩展规则，包括同步、异步和整数值跟踪等类型。每种trace的字段组成、含义及与打点入参的关系都会逐一说明，并提供[具体样例](#各场景trace日志样例)供参考。

API version 19及以上版本的用户态trace格式参考[当前版本用户态trace格式](#当前版本用户态trace格式)，API version 19以下版本的用户态trace格式参考[API version 19前用户态trace格式](#api-version-19前用户态trace格式)。


### 当前版本用户态trace格式

#### 同步跟踪

 * 开始trace格式：`[类型标识符]|[进程号]|H:[分布式跟踪链路ID]#[内容]|[级别与所属Tag集合]|[自定义键值对]`

 * 结束trace格式：`[类型标识符]|[进程号]|[级别与所属Tag集合]`

一条完整的同步跟踪包括一个开始trace和一个结束trace，开始trace的`类型标识符`固定为`B`，结束trace的`类型标识符`固定为`E`。


#### 异步跟踪

 * 起始trace格式：`[类型标识符]|[进程号]|H:[分布式跟踪链路ID]#[内容]|[异步任务ID]|[级别与所属Tag集合]|[自定义聚类名称]|[自定义键值对]`

 * 结束trace格式：`[类型标识符]|[进程号]|H:[分布式跟踪链路ID]#[内容]|[异步任务ID]|[级别与所属Tag集合]`

一条完整的异步跟踪也同样包含一个开始trace和一个结束trace，开始trace的`类型标识符`固定为`S`，结束trace的`类型标识符`固定为`F`。


#### 整数值跟踪

 * trace格式：`[类型标识符]|[进程号]|H:[分布式跟踪链路ID]#[内容]|[整数值]|[级别与所属Tag集合]`

一条整数值跟踪trace仅包含一条独立trace，其中trace的`类型标识符`固定为`C`。

> **注意：**
>
> 1. 一条有效且完整的同步跟踪trace与异步跟踪trace，均包含一条起始trace和一条结束trace，开发者需要保证接口调用的匹配性，否则会导致性能跟踪异常问题。具体可参考ArkTS接口[@ohos.hiTraceMeter (性能打点)](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)或C++接口[capi-trace-h](../reference/apis-performance-analysis-kit/capi-trace-h.md)。
> 2. 用户态trace总长度限制512字符，超过部分将被截断。


### 字段说明

本小节将详细介绍用户态trace的各个字段，包括字段组成、含义，字段与打点入参之间的关系，使用[@ohos.hiTraceMeter (性能打点)](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)作为参考。

- **类型标识符**

  类型标识符与调用的[@ohos.hiTraceMeter (性能打点)](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)具体接口相关，其映射关系如下：

  - `B`：开启一个同步时间片跟踪事件。
  - `E`：结束一个同步时间片跟踪事件。
  - `S`：开启一个异步时间片跟踪事件。
  - `F`：结束一个异步时间片跟踪事件。
  - `C`：整数跟踪事件。

- **分布式跟踪链路ID**

  开启HiTraceChain（分布式跟踪）时，会将[HiTraceId](../reference/apis-performance-analysis-kit/capi-hitrace-hitraceid.md)核心信息记录在trace打点中，格式为`[ChainId,SpanId,ParentSpanId]`，结尾使用`#`分隔符与内容字段区分。

  未开启HiTraceChain（分布式跟踪）时，打点不包含该字段。

  - `ChainId`：HiTraceId的跟踪链标识。
  - `SpanId`：HiTraceId的分支标识。
  - `ParentSpanId`：HiTraceId的父分支标识。

  HiTraceChain具体使用指导请参考[使用HiTraceChain打点（ArkTS）](hitracechain-guidelines-arkts.md)与[使用HiTraceChain打点（C/C++）](hitracechain-guidelines-ndk.md)。

- **内容**

  表示打点名称或整数变量名。对应[@ohos.hiTraceMeter (性能打点)](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)接口的`name`入参。

- **异步任务ID**

  和内容字段合并用于匹配相同的异步跟踪trace的开始与结束打点。对应[@ohos.hiTraceMeter (性能打点)](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)接口的`taskId`入参。

- **整数值**

  仅在整数值跟踪trace中包含，为跟踪的整数值。对应[@ohos.hiTraceMeter (性能打点)](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)接口的`count`入参。

- **级别与所属Tag集合**

  本字段由级别和所属Tag集合两部分信息组成。

  通过打点接口传入的`级别`信息，该部分为以下字符之一：`D`、`I`、`C`、`M`。对应[@ohos.hiTraceMeter (性能打点)](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)接口的`level`入参，详细介绍及映射关系参考[HiTraceOutputLevel](#hitraceoutputlevel)。

  所属Tag集合表示trace打点所属Tag类别，每类用两位数字表示，可包含多个从小到大排列的两位数字。

  例如`B|1314|H:TestFunction|I3062`，其中`I`表示该条打点级别为`Info`，`3062`表示该条打点所属Tag集合，根据Tag名称与值的映射关系，参考[HiTraceMeter Tag](#hitracemeter-tag)可知`30`对应`ohos`Tag，`62`对应`app`Tag。

  > **说明：**
  >
  > 1. 对于API version 19及之后接口，支持自定义输出级别；对于API version 18及之前接口，trace打点默认为`COMMERCIAL`级别打点。
  >
  > 2. 系统侧存在一条用户态trace隶属于多个Tag的情况，ArkTS接口[@ohos.hiTraceMeter (性能打点)](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)和C++接口[capi-trace-h](../reference/apis-performance-analysis-kit/capi-trace-h.md)提供的应用侧用户态trace打点功能无法指定`所属Tag集合`，对应Tag分类固定为`app`，字段值为`62`。


- **自定义聚类名称**

  可用于开发者自定义的聚类操作。对应[@ohos.hiTraceMeter (性能打点)](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)接口的`customCategory`入参。该字段值可能为空，从而使得日志格式发生变化，详见[字段为空情况说明](#字段为空情况说明)。

  在trace可视化工具中，同一进程中相同聚类名称的异步打点放在同一泳道上进行展示。

- **自定义键值对**

  格式为`key=value`，多个键值对使用逗号分隔，例如`key1=value1,key2=value2`。对应[@ohos.hiTraceMeter (性能打点)](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)接口的`customArgs`入参。该字段值可能为空，从而使得日志格式发生变化，详见[字段为空情况说明](#字段为空情况说明)。

  在trace可视化工具中，对满足格式要求的自定义键值对，以键值对形式展示解析结果。


### 字段扩展规则

API version 19及后续版本的新增字段，均以**竖线+字段**的方式，追加在当前用户态trace格式的末尾。


### 各场景trace日志样例

| 打点类型          | 开启HiTraceChain时格式                                       | 未开启HiTraceChain时格式                                     |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 开始同步trace打点 | B\|1234\|H:[a92ab94c18e1341,0,0]#tracename\|M62\|user=root,type=2 | B\|1234\|H:tracename\|M62\|user=root,type=2                  |
| 结束同步trace打点 | E\|1234\|M62                                                 | E\|1234\|M62                                                 |
| 开始异步trace打点 | S\|1234\|H:[a92ab94c18e1341,0,0]#tracename\|428\|M62\|appcategory01\|user=root,type=2 | S\|1234\|H:tracename\|428\|M62\|appcategory01\|user=root,type=2 |
| 结束异步trace打点 | F\|1234\|H:[a92ab94c18e1341,0,0]#tracename\|428\|M62         | F\|1234\|H:tracename\|428\|M62                               |
| 整数trace打点     | C\|1234\|H:[a92ab94c18e1341,0,0]#tracename\|5678\|M62        | C\|1234\|H:tracename\|5678\|M62                              |

上述trace日志样例中，进程号均为`1234`，打点内容均为`tracename`，级别均为`M`，代表`COMMERCIAL`级别，所属Tag集合均为`62`，仅包含一个Tag，对应的Tag名称为`app`。在开启HiTraceChain情况下，分布式跟踪链路ID为`[a92ab94c18e1341,0,0]`。同步trace与异步trace跟踪的自定义键值对均为`user=root,type=2`，其中异步trace打点的异步任务ID为`428`，自定义聚类名称为`appcategory01`。整数值跟踪的跟踪值为`5678`。

> **说明：**
>
> 用户态trace总长度限制为512字符，建议`内容`、`自定义聚类名称`和`自定义键值对`参数总长度不超过420字符，避免被截断。

### 字段为空情况说明

如果用户态trace格式中间字段对应接口参数传入内容为空，用户态trace格式将保留`|`分隔符，如果尾部字段为空，用户态trace格式将不保留`|`分隔符。以[hiTraceMeter.startAsyncTrace()](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md#hitracemeterstartasynctrace19)和[hiTraceMeter.startSyncTrace()](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md#hitracemeterstartsynctrace19)接口的`自定义聚类名称`和`自定义键值对`参数为例，对应的格式参考如下。

- 开始同步trace打点。

  - `自定义键值对`字段不为空字符串。

    ```text
    B|[进程号]|H:[分布式跟踪链路ID]#[内容]|[级别与所属Tag集合]|[自定义键值对]
    ```

  - `自定义键值对`字段为空字符串。

    ```text
    B|[进程号]|H:[分布式跟踪链路ID]#[内容]|[级别与所属Tag集合]
    ```

- 开始异步trace打点。

  - `自定义聚类名称`和`自定义键值对`字段均不为空字符串。

    ```text
    S|[进程号]|H:[分布式跟踪链路ID]#[内容]|[异步任务ID]|[级别与所属Tag集合]|[自定义聚类名称]|[自定义键值对]
    ```

  - `自定义聚类名称`字段为空字符串，`自定义键值对`字段不为空字符串。

    ```text
    S|[进程号]|H:[分布式跟踪链路ID]#[内容]|[异步任务ID]|[级别与所属Tag集合]||[自定义键值对]
    ```

  - `自定义聚类名称`字段不为空字符串，`自定义键值对`字段为空字符串。

    ```text
    S|[进程号]|H:[分布式跟踪链路ID]#[内容]|[异步任务ID]|[级别与所属Tag集合]|[自定义聚类名称]
    ```

  - `自定义聚类名称`和`自定义键值对`字段均为空字符串。

    ```text
    S|[进程号]|H:[分布式跟踪链路ID]#[内容]|[异步任务ID]|[级别与所属Tag集合]
    ```

### HiTraceMeter Tag

以下为HitraceMeter用户态Tag集合，其中Tag值为实际代码层面基于数字1的左移值。用户态Tag可通过[“hitrace -l”命令](hitrace.md#查看hitrace包含的tag)查看其解释，其中`always`和`commercial`分别为系统侧默认常开Tag和商用版本场景定制Tag。

| Tag名称            | 代码层常量值 | Tag值 |
| ------------------ | ------------ | ----- |
| always             | 1ULL << 0    | 00    |
| commercial         | 1ULL << 5    | 05    |
| drm                | 1ULL << 6    | 06    |
| security           | 1ULL << 7    | 07    |
| animation          | 1ULL << 9    | 09    |
| push               | 1ULL << 10   | 10    |
| virse              | 1ULL << 11   | 11    |
| ffrt               | 1ULL << 13   | 13    |
| musl               | 1ULL << 12   | 12    |
| cloud              | 1ULL << 14   | 14    |
| deviceauth         | 1ULL << 15   | 15    |
| commonlibrary      | 1ULL << 16   | 16    |
| hdcd               | 1ULL << 17   | 17    |
| hdf                | 1ULL << 18   | 18    |
| usb                | 1ULL << 19   | 19    |
| interconn          | 1ULL << 20   | 20    |
| dlpcre             | 1ULL << 21   | 21    |
| accesscontrol      | 1ULL << 22   | 22    |
| net                | 1ULL << 23   | 23    |
| nweb               | 1ULL << 24   | 24    |
| huks               | 1ULL << 25   | 25    |
| useriam            | 1ULL << 26   | 26    |
| daudio             | 1ULL << 27   | 27    |
| dlsm               | 1ULL << 28   | 28    |
| filemanagement     | 1ULL << 29   | 29    |
| ohos               | 1ULL << 30   | 30    |
| ability            | 1ULL << 31   | 31    |
| zcamera            | 1ULL << 32   | 32    |
| zmedia             | 1ULL << 33   | 33    |
| zimage             | 1ULL << 34   | 34    |
| zaudio             | 1ULL << 35   | 35    |
| distributeddatamgr | 1ULL << 36   | 36    |
| mdfs               | 1ULL << 37   | 37    |
| graphic            | 1ULL << 38   | 38    |
| ace                | 1ULL << 39   | 39    |
| notification       | 1ULL << 40   | 40    |
| misc               | 1ULL << 41   | 41    |
| multimodalinput    | 1ULL << 42   | 42    |
| sensors            | 1ULL << 43   | 43    |
| msdp               | 1ULL << 44   | 44    |
| dsoftbus           | 1ULL << 45   | 45    |
| rpc                | 1ULL << 46   | 46    |
| ark                | 1ULL << 47   | 47    |
| window             | 1ULL << 48   | 48    |
| account            | 1ULL << 49   | 49    |
| dscreen            | 1ULL << 50   | 50    |
| dcamera            | 1ULL << 51   | 51    |
| dhfwk              | 1ULL << 52   | 52    |
| gresource          | 1ULL << 53   | 53    |
| devicemanager      | 1ULL << 54   | 54    |
| samgr              | 1ULL << 55   | 55    |
| power              | 1ULL << 56   | 56    |
| dsched             | 1ULL << 57   | 57    |
| deviceprofile      | 1ULL << 58   | 58    |
| dinput             | 1ULL << 59   | 59    |
| bluetooth          | 1ULL << 60   | 60    |
| accessibility      | 1ULL << 61   | 61    |
| app                | 1ULL << 62   | 62    |

### HiTraceOutputLevel

| trace输出级别枚举名称（C/C++） | trace输出级别枚举名称（ArkTS） | 枚举值 | trace级别 |
| ------------------------------ | ------------------------------ | ------ | --------- |
| HITRACE_LEVEL_DEBUG            | DEBUG                          | 0      | D         |
| HITRACE_LEVEL_INFO             | INFO                           | 1      | I         |
| HITRACE_LEVEL_CRITICAL         | CRITICAL                       | 2      | C         |
| HITRACE_LEVEL_COMMERCIAL       | COMMERCIAL                     | 3      | M         |


### API version 19前用户态trace格式

#### 同步跟踪

 * 开始trace格式：`[类型标识符]|[进程号]|H:[分布式跟踪链路ID]#[内容]`

 * 结束trace格式：`[类型标识符]|[进程号]`


#### 异步跟踪

 * 开始trace格式：`[类型标识符]|[进程号]|H:[分布式跟踪链路ID]#[内容] [异步任务ID]`

 * 结束trace格式：`[类型标识符]|[进程号]|H:[分布式跟踪链路ID]#[内容] [异步任务ID]`


#### 整数值跟踪

 * trace格式：`[类型标识符]|[进程号]|H:[分布式跟踪链路ID]#[内容] [整数值]`

> **说明：**
>
> 异步跟踪trace的开始trace格式与结束trace格式一样。需要注意的是 API version 19以前的版本，异步跟踪trace的`异步任务ID`字段、整数值跟踪的`整数值`字段与`内容`字段使用空格进行分隔。

### API version 19前各场景trace日志样例

| 打点类型            | 开启HiTraceChain时格式                          | 未开启HiTraceChain时格式  |
| ------------------- | ----------------------------------------------- | ------------------------- |
| 开始同步trace打点   | B\|1234\|H:[a92ab94c18e1341,0,0]#tracename      | B\|1234\|H:tracename      |
| 结束同步trace打点   | E\|1234\|                                       | E\|1234\|                 |
| 开始异步trace打点   | S\|1234\|H:[a92ab94c18e1341,0,0]#tracename 428  | S\|1234\|H:tracename 428  |
| 结束异步trace打点   | F\|1234\|H:[a92ab94c18e1341,0,0]#tracename 428  | F\|1234\|H:tracename 428  |
| 整数值跟踪trace打点 | C\|1234\|H:[a92ab94c18e1341,0,0]#tracename 5678 | C\|1234\|H:tracename 5678 |

上述trace日志样例中，进程号为`1234`，打点内容均为`tracename`。开启HiTraceChain情况下，分布式跟踪链路ID为`[a92ab94c18e1341,0,0]`。其中异步trace打点的异步任务ID为`428`，整数值跟踪的跟踪值为`5678`。