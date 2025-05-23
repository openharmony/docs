# hitrace

HiTrace提供业务流程调用链跟踪的维测接口，帮助开发者迅速获取指定业务流程调用链的运行日志，定位跨设备、跨进程、跨线程的故障问题。

## 环境要求

- 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)。

- 确保设备已正常连接，并执行hdc shell。

## 命令行说明

| 命令                  | 含义说明                                                     |
| --------------------- | ------------------------------------------------------------ |
| -h                    | 帮助命令。                                                   |
| -l                    | 查看tag列表。                                                |
| --trace_begin         | 开始捕获trace。                                              |
| --trace_finish        | 结束捕获trace。                                              |
| --trace_dump          | 导出trace信息。                                              |
| -b N                  | 设置用于存储和读取trace的缓冲区大小(buffer size KB)。默认的缓冲区大小为2048 KB。 |
| -t N                  | 设置hitrace运行时长，单位为秒（默认为5秒）。                   |
| -o                    | 指定目标文件的名称（默认为stdout）。                           |
| -z                    | 压缩捕获的跟踪。                                             |
| --trace_clock         | 设置向trace添加时间戳的时钟类型，可以是引导（默认）、全局、单声道、正常运行时间或性能。 |
| --trace_finish_nodump | 停止捕获trace时，不打印trace信息。                            |
| --start_bgsrv         | 开启快照模式trace捕获。                                       |
| --dump_bgsrv          | 触发快照模式trace输出到文件。                                 |
| --stop_bgsrv          | 关闭快照模式trace捕获。                                       |
| --trace_level         | 设置trace输出级别阈值，输出级别可以是Debug、Info、Critical、Commercial或其对应缩写D、I、C、M。<br>**说明**：从API version 19开始，支持该命令。 |

> **说明**
>
> 快照模式定义为固定trace标签的trace捕获，默认不落盘。 `--dump_bgsrv` 命令触发当前时刻的二进制格式trace转储，文件默认生成在 `/data/log/hitrace` 目录下，命名格式为`trace-YYMMDDHHmmSS@[BOOT_TIME].sys`。可以使用[HiSmartPerf](https://gitee.com/openharmony/developtools_smartperf_host)工具进行可视化trace分析。工具下载链接：[developtools_smartperf_host官方发行版](https://gitee.com/openharmony/developtools_smartperf_host/releases)。

## 常用命令

### 查看hitrace包含的tag

```shell
hitrace -l
```
**使用样例：**

```shell
$ hitrace -l
2024/11/14 11:43:00 hitrace enter, running_state is SHOW_LIST_CATEGORY
        tagName:   description:
         ability - Ability Manager
   accesscontrol - Access Control Module
         account - Account Manager
             ace - ACE development framework
       animation - Animation
             app - APP Module
             ark - ARK Module
       bluetooth - communication bluetooth
           cloud - Cloud subsystem tag
       cloudfile - Cloud file system
      commercial - Commercial version tag
   commonlibrary - commonlibrary subsystem
          daudio - Distributed Audio
         dcamera - Distributed Camera
      deviceauth - Device Auth
   devicemanager - Device Manager
   deviceprofile - Device Profile
           dhfwk - Distributed Hardware FWK
          dinput - Distributed Input
            disk - Disk I/O
distributeddatamgr - Distributed Data Manager
          dlpcre - Dlp Credential Service
             drm - Digital Rights Management
          dsched - Distributed Schedule
         dscreen - Distributed Screen
            dslm - device security level
        dsoftbus - Distributed Softbus
            ffrt - ffrt tasks
  filemanagement - filemanagement
            freq - CPU Frequency
         graphic - Graphic Module
       gresource - Global Resource Manager
            hdcd - hdcd
             hdf - hdf subsystem
            huks - Universal KeyStore
             i2c - I2C Events
            idle - CPU Idle
       interconn - Interconnection subsystem
             ipa - thermal power allocator
             irq - IRQ Events
          irqoff - IRQ-disabled code section tracing
            load - CPU Load
            mdfs - Mobile Distributed File System
          membus - Memory Bus Utilization
          memory - Memory
      memreclaim - Kernel Memory Reclaim
            misc - Misc Module
             mmc - eMMC commands
            msdp - Multimodal Sensor Data Platform
 multimodalinput - HITRACE_TAG_MULTIMODALINPUT
             net - net
    notification - Notification Module
            nweb - NWEB Module
            ohos - OpenHarmony
       pagecache - Page cache
           power - Power Manager
      preemptoff - Preempt-disabled code section tracing
            push - Push subsystem
      regulators - Voltage and Current Regulators
             rpc - RPC and IPC
           samgr - samgr
           sched - CPU Scheduling
        security - Security subsystem
         sensors - Sensors Module
            sync - Synchronization
             ufs - UFS commands
             usb - usb subsystem
         useriam - useriam
           virse - Virtualization Service
          window - Window Manager
           workq - Kernel Workqueues
          zaudio - OpenHarmony Audio Module
         zcamera - OpenHarmony Camera Module
          zimage - OpenHarmony Image Module
          zmedia - OpenHarmony Media Module
```

### 开始捕获指定tag的trace

```shell
hitrace --trace_begin --record app
```
**使用样例：**

```shell
$ hitrace --trace_begin --record app
2024/11/14 11:48:45 hitrace enter, running_state is RECORDING_LONG_BEGIN_RECORD
2024/11/14 11:48:45 args: tags:app bufferSize:18432 overwrite:1
2024/11/14 11:48:45 OpenRecording done.
```

### 结束捕获trace

默认在命令行窗口打印trace信息。

```shell
hitrace --trace_finish --record
```
**使用样例1：**

```shell
$ hitrace --trace_finish --record
2024/11/14 11:50:33 hitrace enter, running_state is RECORDING_LONG_FINISH_RECORD
2024/11/14 11:50:33 capture done, output files:
    /data/log/hitrace/record_trace_20241114115033@3010728-656499531.sys
```
添加输出路径，trace信息将导出到对应文件。

```shell
hitrace --trace_finish -o /data/local/tmp/test.ftrace
```
**使用样例2：**

```shell
$ hitrace --trace_finish -o /data/local/tmp/test.ftrace
2024/11/14 11:50:33 start to read trace.
2024/11/14 11:50:33 trace read done, output: /data/local/tmp/test.ftrace
```

### 设置捕获trace的相关参数

```shell
hitrace -b 10240 -t 10 -o /data/local/tmp/test2.ftrace app ability
```
**使用样例：**

```shell
$ hitrace -b 10240 -t 10 -o /data/local/tmp/test2.ftrace app ability
2024/11/14 11:52:13 start capture, please wait 10s ...
2024/11/14 11:52:23 capture done, start to read trace.
2024/11/14 11:52:23 trace read done, output: /data/local/tmp/test2.ftrace
```
- 设置缓冲区大小为10240KB。
- 设置捕获trace时间为10s。
- 设置捕获的trace信息存储在文件/data/local/tmp/test2.ftrace中。
- 开启app、ability两个tag的trace捕获。

### 导出trace信息

默认在命令行窗口显示信息。

```shell
hitrace --trace_dump
```
**使用样例1：**

```shell
$ hitrace --trace_dump
2024/11/14 11:54:23 start to read trace.
# tracer: nop
#
# entries-in-buffer/entries-written: 2/2   #P:4
#
#                                          _-----=> irqs-off
#                                         / _----=> need-resched
#                                        | / _---=> hardirq/softirq
#                                        || / _--=> preempt-depth
#                                        ||| /     delay
#           TASK-PID       TGID    CPU#  ||||   TIMESTAMP  FUNCTION
#              | |           |       |   ||||      |         |
           <...>-21829   (  19280) [003] .... 3011033.731844: tracing_mark_write: trace_event_clock_sync: realtime_ts=1732002022239
           <...>-21829   (  19280) [003] .... 3011033.731865: tracing_mark_write: trace_event_clock_sync: parent_ts=3011033.750000
$
```
添加输出路径，trace信息将导出到对应文件。

```shell
hitrace --trace_dump -o /data/local/tmp/test3.ftrace
```
**使用样例2：**

```shell
$ hitrace --trace_dump -o /data/local/tmp/test3.ftrace
2024/11/14 11:54:23 start to read trace.
2024/11/14 11:54:23 trace read done, output: /data/local/tmp/test3.ftrace
```
也可根据关键词打印trace信息，使用命令`hitrace --trace_dump | grep xxx`进行过滤显示。

### 开启快照模式trace捕获

```shell
hitrace --start_bgsrv
```
**使用样例：**

```shell
$ hitrace --start_bgsrv
2024/11/14 11:55:53 hitrace enter, running_state is SNAPSHOT_START
2024/11/14 11:55:54 OpenSnapshot done.
```

### 快照模式导出trace

默认将二进制格式的trace信息保存到`/data/log/hitrace/`文件夹下，文件命名格式为`trace-YYMMDDHHmmSS@[BOOT_TIME].sys`。可以使用[HiSmartPerf](https://gitee.com/openharmony/developtools_smartperf_host)工具进行可视化trace分析。工具下载链接：[developtools_smartperf_host官方发行版](https://gitee.com/openharmony/developtools_smartperf_host/releases)。

```shell
hitrace --dump_bgsrv
```
**使用样例：**

```shell
$ hitrace --dump_bgsrv
2024/11/14 12:12:56 hitrace enter, running_state is SNAPSHOT_DUMP
2024/11/14 12:12:57 DumpSnapshot done, output:
    /data/log/hitrace/record_trace_20241114121257@2566589-103807063.sys
```

### 关闭快照模式trace捕获

```shell
hitrace --stop_bgsrv
```
**使用样例：**

```shell
$ hitrace --stop_bgsrv
2024/11/14 11:59:43 hitrace enter, running_state is SNAPSHOT_STOP
2024/11/14 11:59:43 CloseSnapshot done.
```

### 捕获trace后进行压缩

```shell
hitrace -z -b 102400 -t 10 sched freq idle disk -o /data/local/tmp/test.ftrace
```
**使用样例：**

```shell
$ hitrace -z -b 102400 -t 10 sched freq idle disk -o /data/local/tmp/test.ftrace
2024/11/14 12:00:18 start capture, please wait 10s ...
2024/11/14 12:00:28 capture done, start to read trace.
2024/11/14 12:00:29 trace read done, output: /data/local/tmp/test.ftrace
```

### 设置trace的输出时钟为boot（设备系统时间）

```shell
hitrace --trace_clock boot -b 102400 -t 10 sched freq idle disk -o /data/local/tmp/test.ftrace
```
**使用样例：**

```shell
$ hitrace --trace_clock boot -b 102400 -t 10 sched freq idle disk -o /data/local/tmp/test.ftrace
2024/11/14 12:01:42 start capture, please wait 10s ...
2024/11/14 12:01:52 capture done, start to read trace.
2024/11/14 12:01:52 trace read done, output: /data/local/tmp/test.ftrace
```

### 结束捕获trace，取消trace信息打印在命令行窗口

默认将trace信息保存到`/data/log/hitrace/`目录。

```shell
hitrace --trace_finish_nodump
```
**使用样例：**

```shell
$ hitrace --trace_finish_nodump
2024/11/14 12:03:07 hitrace enter, running_state is RECORDING_LONG_FINISH_NODUMP
2024/11/14 12:03:07 end capture trace.
```

### 查看和设置trace输出级别阈值

打点级别优先级从高到低分别为 `M`(commercial)、`C`（critical）、`I`（info）、`D`（debug），低于trace输出级别阈值的打点将不会生效。

开发者可使用带trace级别的打点接口（参考[js-apis-hitracemeter](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)和[_hitrace](../reference/apis-performance-analysis-kit/_hitrace.md)中的API version 19的trace打点接口），测试不同阈值下的trace输出是否符合预期。

```shell
// 查看trace输出级别阈值，打印的为数值，0表示Debug，1表示Info，2表示Critical，3表示Commercial
param get persist.hitrace.level.threshold

// 设置trace输出级别阈值
hitrace --trace_level D/I/C/M
hitrace --trace_level Debug/Info/Critical/Commercial
```
**使用样例：**

```shell
$ hitrace --trace_level Info
2024/11/14 12:05:07 hitrace enter, running_state is SET_TRACE_LEVEL
2024/11/14 12:05:07 success to set trace level.
$ param get persist.hitrace.level.threshold
1
```
