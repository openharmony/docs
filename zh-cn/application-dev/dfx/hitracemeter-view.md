# 查看HiTraceMeter日志

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @MontSaintMichel-->
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


### API version 19前用户态trace格式

| 打点类型 | 开启HiTraceChain时格式 | 未开启HiTraceChain时格式 | 
| -------- | -------- | -------- |
| 开始同步trace打点 | B\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name | B\|PID\|H:name | 
| 结束同步trace打点 | E\|PID\| | E\|PID\| | 
| 开始异步trace打点 | S\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name taskId | S\|PID\|H:name taskId | 
| 结束异步trace打点 | F\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name taskId | F\|PID\|H:name taskId | 
| 整数trace打点 | C\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name count | C\|PID\|H:name count | 

> **说明：**
>
> 用户态trace总长度限制512字符，超过部分将被截断。


**格式中的字段说明**


- **B/E/S/F/C**

  - B：开始同步trace打点。
  - E：结束同步trace打点。
  - S：开始异步trace打点。
  - F：结束异步trace打点。
  - C：整数trace打点。

- **PID**

  进程ID。

- **[ChainId,SpanId,ParentSpanId]\#**

  开启HiTraceChain时，会将HiTraceId记录在trace打点中，结尾使用\#分隔符与name字段区分。

  未开启HiTraceChain时，打点不包含该字段。

  - ChainId：HiTraceId的链Id。
  - SpanId：HiTraceId的当前跨度号。
  - ParentSpanId：HiTraceId的父跨度号。

- **name**

  name字段表示打点名称或整数变量名。

- **taskId**

  taskId字段表示异步跟踪id，和name字段一起用于匹配相同的异步开始与结束打点。

  taskId与name字段之间使用空格进行分隔。

- **count**

  count字段为整数值。

  count与name字段之间使用空格进行分隔。


### API version 19后用户态trace格式

各字段使用竖线作为分隔符。对后续新增字段，均采用**竖线+字段**的方式，追加到当前用户态trace格式的末尾。

| 打点类型 | 开启HiTraceChain时格式 | 未开启HiTraceChain时格式 | 
| -------- | -------- | -------- |
| 开始同步trace打点 | B\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name\|%level%tag\|customArgs | B\|PID\|H:name\|%level%tag\|customArgs | 
| 结束同步trace打点 | E\|PID\|%level%tag | E\|PID\|%level%tag | 
| 开始异步trace打点 | S\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name\|taskId\|%level%tag\|customCategory\|customArgs | S\|PID\|H:name\|taskId\|%level%tag\|customCategory\|customArgs | 
| 结束异步trace打点 | F\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name\|taskId\|%level%tag | F\|PID\|H:name\|taskId\|%level%tag | 
| 整数trace打点 | C\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name\|count\|%level%tag | C\|PID\|H:name\|count\|%level%tag | 

> **说明：**
>
> 用户态trace总长度限制512字符。建议name、customCategory和customArgs的总长度不超过420字符，以避免被截断。


**格式中的字段说明**


- **B/E/S/F/C**

  - B：开始同步trace打点。
  - E：结束同步trace打点。
  - S：开始异步trace打点。
  - F：结束异步trace打点。
  - C：整数trace打点。

- **PID**

  进程ID。

- **[ChainId,SpanId,ParentSpanId]\#**

  开启HiTraceChain时，会将HiTraceId记录在trace打点中，结尾使用\#分隔符与name字段区分。

  未开启HiTraceChain时，打点不包含该字段。

  - ChainId：HiTraceId的链Id。
  - SpanId：HiTraceId的当前跨度号。
  - ParentSpanId：HiTraceId的父跨度号。

- **name**

  name字段表示打点名称或整数变量名。

- **taskId**

  taskId字段表示异步跟踪id，和name字段一起用于匹配相同的异步开始与结束打点。

- **count**

  count字段为整数值。

- **%level**

  通过打点接口传入的level字段，表示打点级别，该字段为以下字符之一：D、I、C、M。

  level字段与%level映射关系参考[HiTraceOutputLevel](#hitraceoutputlevel)。

  > **说明：**
  >
  > API version 19前的trace打点接口没有level字段，这些trace打点默认为COMMERCIAL级别。

- **%tag**

  %tag字段表示trace打点所属tag类别，每类用两位数字表示，可包含多个从小到大排列的两位数字。例如 B|1314|H:TestFunction|I3062，表示该条打点属于HITRACE_TAG_OHOS及HITRACE_TAG_APP两类tag下的打点。

  tag名称、tag值与%tag映射关系参考[HiTraceMeter Tag](#hitracemeter-tag)。

  > **说明：**
  >
  > NDK C/C++和ArkTs/JS的HiTraceMeter性能打点接口并没有字段与%tag对应，这些打点接口均属于应用打点，对应的tag名称为HITRACE_TAG_APP，用户态trace中的%tag字段值为62。

- **customCategory**

  customCategory字段表示自定义聚类名称。

  在trace可视化工具中，同一进程中相同聚类名称的异步打点放在同一泳道上进行展示。

- **customArgs**

  customArgs字段表示自定义键值对，格式为“key=value”，多个键值对使用逗号分隔，例如“key1=value1,key2=value2”。

  在trace可视化工具中，对满足格式要求的customArgs以键值对形式展示解析结果。


**特殊情况说明**


实际开发中，如customCategory和customArgs字段不需要，则传入空字符串（仅开始同步trace打点接口和开始异步trace打点接口涉及这两个字段）。


针对这两个字段是否为空字符串的情况，以未开启HiTraceChain时的格式为例，进行说明。HiTraceChain具体使用指导请参考[使用HiTraceChain打点](hitracechain-intro.md)。


API version 19前的trace打点接口默认将这两个字段视为空字符串。


- 开始同步trace打点接口

  - customArgs字段不为空字符串

     ```text
     B|PID|H:name|%level%tag|customArgs
     ```

  - customArgs字段为空字符串

     ```text
     B|PID|H:name|%level%tag
     ```

- 开始异步trace打点接口

  - customCategory和customArgs字段均不为空字符串

     ```text
     S|PID|H:name|taskId|%level%tag|customCategory|customArgs
     ```

  - customCategory字段为空字符串，customArgs字段不为空字符串

     ```text
     S|PID|H:name|taskId|%level%tag||customArgs
     ```

  - customCategory字段不为空字符串，customArgs字段为空字符串

     ```text
     S|PID|H:name|taskId|%level%tag|customCategory
     ```

  - customCategory和customArgs字段均为空字符串

     ```text
     S|PID|H:name|taskId|%level%tag
     ```


### HiTraceMeter Tag

| tag名称 | tag值 | %tag | 
| -------- | -------- | -------- |
| HITRACE_TAG_ALWAYS | 1ULL &lt;&lt; 0 | 00 | 
| HITRACE_TAG_COMMERCIAL | 1ULL &lt;&lt; 5 | 05 | 
| HITRACE_TAG_DRM | 1ULL &lt;&lt; 6 | 06 | 
| HITRACE_TAG_SECURITY | 1ULL &lt;&lt; 7 | 07 | 
| HITRACE_TAG_ANIMATION | 1ULL &lt;&lt; 9 | 09 | 
| HITRACE_TAG_PUSH | 1ULL &lt;&lt; 10 | 10 | 
| HITRACE_TAG_VIRSE | 1ULL &lt;&lt; 11 | 11 | 
| HITRACE_TAG_MUSL | 1ULL &lt;&lt; 12 | 12 | 
| HITRACE_TAG_FFRT | 1ULL &lt;&lt; 13 | 13 | 
| HITRACE_TAG_CLOUD | 1ULL &lt;&lt; 14 | 14 | 
| HITRACE_TAG_DEV_AUTH | 1ULL &lt;&lt; 15 | 15 | 
| HITRACE_TAG_COMMONLIBRARY | 1ULL &lt;&lt; 16 | 16 | 
| HITRACE_TAG_HDCD | 1ULL &lt;&lt; 17 | 17 | 
| HITRACE_TAG_HDF | 1ULL &lt;&lt; 18 | 18 | 
| HITRACE_TAG_USB | 1ULL &lt;&lt; 19 | 19 | 
| HITRACE_TAG_INTERCONNECTION | 1ULL &lt;&lt; 20 | 20 | 
| HITRACE_TAG_DLP_CREDENTIAL | 1ULL &lt;&lt; 21 | 21 | 
| HITRACE_TAG_ACCESS_CONTROL | 1ULL &lt;&lt; 22 | 22 | 
| HITRACE_TAG_NET | 1ULL &lt;&lt; 23 | 23 | 
| HITRACE_TAG_NWEB | 1ULL &lt;&lt; 24 | 24 | 
| HITRACE_TAG_HUKS | 1ULL &lt;&lt; 25 | 25 | 
| HITRACE_TAG_USERIAM | 1ULL &lt;&lt; 26 | 26 | 
| HITRACE_TAG_DISTRIBUTED_AUDIO | 1ULL &lt;&lt; 27 | 27 | 
| HITRACE_TAG_DLSM | 1ULL &lt;&lt; 28 | 28 | 
| HITRACE_TAG_FILEMANAGEMENT | 1ULL &lt;&lt; 29 | 29 | 
| HITRACE_TAG_OHOS | 1ULL &lt;&lt; 30 | 30 | 
| HITRACE_TAG_ABILITY_MANAGER | 1ULL &lt;&lt; 31 | 31 | 
| HITRACE_TAG_ZCAMERA | 1ULL &lt;&lt; 32 | 32 | 
| HITRACE_TAG_ZMEDIA | 1ULL &lt;&lt; 33 | 33 | 
| HITRACE_TAG_ZIMAGE | 1ULL &lt;&lt; 34 | 34 | 
| HITRACE_TAG_ZAUDIO | 1ULL &lt;&lt; 35 | 35 | 
| HITRACE_TAG_DISTRIBUTEDDATA | 1ULL &lt;&lt; 36 | 36 | 
| HITRACE_TAG_MDFS | 1ULL &lt;&lt; 37 | 37 | 
| HITRACE_TAG_GRAPHIC_AGP | 1ULL &lt;&lt; 38 | 38 | 
| HITRACE_TAG_ACE | 1ULL &lt;&lt; 39 | 39 | 
| HITRACE_TAG_NOTIFICATION | 1ULL &lt;&lt; 40 | 40 | 
| HITRACE_TAG_MISC | 1ULL &lt;&lt; 41 | 41 | 
| HITRACE_TAG_MULTIMODALINPUT | 1ULL &lt;&lt; 42 | 42 | 
| HITRACE_TAG_SENSORS | 1ULL &lt;&lt; 43 | 43 | 
| HITRACE_TAG_MSDP | 1ULL &lt;&lt; 44 | 44 | 
| HITRACE_TAG_DSOFTBUS | 1ULL &lt;&lt; 45 | 45 | 
| HITRACE_TAG_RPC | 1ULL &lt;&lt; 46 | 46 | 
| HITRACE_TAG_ARK | 1ULL &lt;&lt; 47 | 47 | 
| HITRACE_TAG_WINDOW_MANAGER | 1ULL &lt;&lt; 48 | 48 | 
| HITRACE_TAG_ACCOUNT_MANAGER | 1ULL &lt;&lt; 49 | 49 | 
| HITRACE_TAG_DISTRIBUTED_SCREEN | 1ULL &lt;&lt; 50 | 50 | 
| HITRACE_TAG_DISTRIBUTED_CAMERA | 1ULL &lt;&lt; 51 | 51 | 
| HITRACE_TAG_DISTRIBUTED_HARDWARE_FWK | 1ULL &lt;&lt; 52 | 52 | 
| HITRACE_TAG_GLOBAL_RESMGR | 1ULL &lt;&lt; 53 | 53 | 
| HITRACE_TAG_DEVICE_MANAGER | 1ULL &lt;&lt; 54 | 54 | 
| HITRACE_TAG_SAMGR | 1ULL &lt;&lt; 55 | 55 | 
| HITRACE_TAG_POWER | 1ULL &lt;&lt; 56 | 56 | 
| HITRACE_TAG_DISTRIBUTED_SCHEDULE | 1ULL &lt;&lt; 57 | 57 | 
| HITRACE_TAG_DEVICE_PROFILE | 1ULL &lt;&lt; 58 | 58 | 
| HITRACE_TAG_DISTRIBUTED_INPUT | 1ULL &lt;&lt; 59 | 59 | 
| HITRACE_TAG_BLUETOOTH | 1ULL &lt;&lt; 60 | 60 | 
| HITRACE_TAG_ACCESSIBILITY_MANAGER | 1ULL &lt;&lt; 61 | 61 | 
| HITRACE_TAG_APP | 1ULL &lt;&lt; 62 | 62 | 


### HiTraceOutputLevel

| trace输出级别枚举名称（C/C++） | trace输出级别枚举名称（ArkTS/JS） | 枚举值 | %level | 
| -------- | -------- | -------- | -------- |
| HITRACE_LEVEL_DEBUG | DEBUG | 0 | D | 
| HITRACE_LEVEL_INFO | INFO | 1 | I | 
| HITRACE_LEVEL_CRITICAL | CRITICAL | 2 | C | 
| HITRACE_LEVEL_COMMERCIAL | COMMERCIAL | 3 | M | 
| HITRACE_LEVEL_MAX | MAX | 3 | M | 
