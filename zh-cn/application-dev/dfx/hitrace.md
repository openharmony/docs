# hitrace

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

hitrace命令行工具提供trace信息采集能力，支持采集系统提供的打点和开发者使用[HitraceMeter接口](hitracemeter-intro.md)在应用中设置的打点。该工具支持多种方式采集文本格式或二进制格式的trace信息，帮助开发者观测程序运行情况和定位故障问题。


## 环境要求

- 根据hdc命令行工具指导，完成[hdc环境准备](hdc.md#环境准备)。

- 确保设备已正常连接，并执行hdc shell。


## 命令行说明

| 命令 | 含义说明 | 
| -------- | -------- |
| -h/--help | 查看帮助。 | 
| -l/--list_categories | 查看tag列表。 | 
| --trace_begin | 开始捕获trace。 | 
| --trace_finish | 结束捕获trace。 | 
| --trace_finish_nodump | 结束捕获trace，与--trace_finish的区别是不输出trace信息。 | 
| --trace_dump | 导出trace信息。 | 
| --record | 使能录制模式，允许长时间采集并落盘trace数据，必须和--trace_begin或--trace_finish一起使用。 | 
| --overwrite | 设置内核缓冲区满之后的行为，未设置此选项时默认丢弃最老数据，设置此选项后丢弃最新数据。 | 
| --file_size | 设置文件大小（单位为KB），仅在采集二进制格式trace数据时有效。 | 
| -b N/--buffer_size N | 设置用于存储和读取trace的缓冲区大小（单位为KB）。最小值为512，最大值与设备当前可用内存有关。 | 
| -t N/--time N | 设置hitrace采集时长，单位为s。 | 
| -o/--output filename | 指定目标文件的名称（导出trace格式为文本时默认为stdout，如需保存到文件，建议使用/data/local/tmp路径。导出trace格式为二进制时不支持此选项）。 | 
| -z | 压缩捕获的trace数据。 | 
| --text | 导出trace数据为文本格式（默认为文本格式）。 | 
| --raw | 导出trace数据为二进制格式（默认为文本格式）。 | 
| --trace_clock | 设置向trace添加时间戳的时钟类型，可以是boot（默认）、global、mono、uptime或perf。不同设备支持的时钟类型不同，建议使用默认的boot进行采集，其时间为从本次开机起的时间戳，单位为s。每种时间类型的说明如下：<br/>- boot：系统启动后的时间戳，休眠或系统挂起时也会计时。<br/>- global：全局同步的时钟，可能有性能开销。<br/>- mono：系统启动后的时间戳，休眠或系统挂起时不会计时。<br/>- uptime：系统启动后的时间戳，类似于mono。<br/>- perf：高性能计数器，适合性能分析。 | 
| --start_bgsrv | 开启快照模式trace捕获。 | 
| --dump_bgsrv | 触发快照模式trace输出到文件。 | 
| --stop_bgsrv | 关闭快照模式trace捕获。 | 
| --trace_level | 设置trace输出级别阈值，输出级别可以是Debug、Info、Critical、Commercial或其对应缩写D、I、C、M。<br/>**说明**：从API version 19开始，支持该命令。 | 

> **说明：**
>
> trace信息可以用两种不同的格式保存，分别为文本格式和二进制格式。文本格式的trace可以直接用文本编辑器查看，二进制格式的trace可以使用[Smartperf_Host](https://gitee.com/openharmony/developtools_smartperf_host)工具进行可视化trace分析。工具下载链接：[developtools_smartperf_host官方发行版](https://gitee.com/openharmony/developtools_smartperf_host/releases)。


## 常用命令


### 查看帮助信息


```shell
hitrace -h
```


**使用样例**：


```shell
$ hitrace -h
2025/05/28 15:19:52 hitrace enter, running_state is SHOW_HELP
usage: hitrace [options] [categories...]
options include:
  -b N                   Set the size of the buffer (KB) for storing and reading traces.
                         The default buffer size is 18432 KB.
  --buffer_size N        Like "-b N".
  -l                     List available hitrace categories.
  --list_categories      Like "-l".
  -t N                   Set the hitrace running duration in seconds (5s by default), which depends on
                         the time required for analysis.
  --time N               Like "-t N".
  --trace_clock clock    Sets the type of the clock for adding a timestamp to a trace, which can be
                         boot (default), global, mono, uptime, or perf.
  --trace_begin          Start capturing traces.
  --trace_dump           Dump traces to a specified path (stdout by default).
  --trace_finish         Stop capturing traces and dumps traces to a specified path (stdout by default).
  --trace_finish_nodump  Stop capturing traces and not dumps traces.
  --record               Enable or disable long-term trace collection tasks in conjunction with
                         "--trace_begin" and "--trace_finish".
  --overwrite            Set the action to take when the buffer is full. If this option is used,
                         the latest traces are discarded; if this option is not used (default setting),
                         the earliest traces are discarded.
  -o filename            Specifies the name of the target file (stdout by default).
  --output filename      Like "-o filename".
  -z                     Compresses a captured trace.
  --text                 Specify the output format of trace as text.
  --raw                  Specify the output format of trace as raw trace, the default format is text.
  --start_bgsrv          Enable trace_service in snapshot mode.
  --dump_bgsrv           Trigger the dump trace task of the trace_service.
  --stop_bgsrv           Disable trace_service in snapshot mode.
  --file_size            Sets the size of the raw trace (KB). The default file size is 102400 KB.
                         Only effective in raw trace mode
  --trace_level level    Set the system parameter "persist.hitrace.level.threshold", which can control
                         the level threshold of trace dotting. Valid values for "level" include
                         D or Debug, I or Info, C or Critical, M or Commercial.
```


### 查看hitrace包含的tag

```shell
hitrace -l
```

**使用样例**：

```shell
$ hitrace -l
2025/05/27 16:24:38 hitrace enter, running_state is SHOW_LIST_CATEGORY
            tagName:   description:
             ability - Ability Manager
       accesscontrol - Access Control Module
       accessibility - Accessibility Manager
             account - Account Manager
                 ace - ACE development framework
           animation - Animation
                 app - APP Module
                 ark - ARK Module
              binder - Binder kernel Info
           bluetooth - communicatin bluetooth
               cloud - Cloud subsystem tag
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
                hmfs - HMFS commands
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
                musl - musl module
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
             zbinder - OpenHarmony binder communication
             zcamera - OpenHarmony Camera Module
              zimage - OpenHarmony Image Module
              zmedia - OpenHarmony Media Module
```


### 捕获指定时长文本格式trace

不指定-o参数时，默认将捕获到的trace内容显示在命令行窗口。下面参数是指定采集10秒的数据，缓冲区大小为204800KB，采集的tag为app。

```shell
hitrace -t 10 -b 204800 app
```


**使用样例**：


```shell
$ hitrace -t 10 -b 204800 app
2025/06/04 10:14:52 start capture, please wait 10s ...
# tracer: nop
#                                          _-----=> irqs-off
#                                         / _----=> need-resched
#                                        | / _---=> hardirq/softirq
#                                        || / _--=> preempt-depth
#                                        ||| /     delay
#           TASK-PID       TGID    CPU#  ||||   TIMESTAMP  FUNCTION
#              | |           |       |   ||||      |         |
 KstateRecvThrea-1132    (    952) [003] .... 589942.951387: tracing_mark_write: B|952|H:CheckMsgFromNetlink|I62
 KstateRecvThrea-1132    (    952) [003] .... 589942.951554: tracing_mark_write: B|952|H:OnKstateCallback, mask: 8, data: [PID 15461 KILLED][SIG 9]|I62
 KstateRecvThrea-1132    (    952) [003] .... 589942.951693: tracing_mark_write: E|952|I62
 KstateRecvThrea-1132    (    952) [003] .... 589942.951737: tracing_mark_write: E|952|I62
 state_change_ha-1139    (    952) [001] .... 589942.951909: tracing_mark_write: B|952|H:ProcessEvent, eventId: 6|I62
 state_change_ha-1139    (    952) [001] .... 589942.952510: tracing_mark_write: E|952|I62
2025/06/04 10:15:02 TraceFinish done.
```


指定-o参数时，可以将trace信息保存到指定目录，建议保存在/data/local/tmp路径下。


```shell
hitrace -t 10 -b 204800 app -o /data/local/tmp/test.ftrace
```


**使用样例**：


```shell
$ hitrace -t 10 -b 204800 app -o /data/local/tmp/test.ftrace
2025/06/04 10:19:47 start capture, please wait 10s ...
2025/06/04 10:19:57 capture done, start to read trace.
2025/06/04 10:19:57 trace read done, output: /data/local/tmp/test.ftrace
2025/06/04 10:19:57 TraceFinish done.
```


### 捕获指定时长二进制格式trace

命令带--raw参数时可捕获二进制格式trace，捕获二进制格式trace时不支持指定路径，固定保存在路径/data/log/hitrace下。采集结束后，采集结束后生成文件的绝对路径会显示在命令行窗口。

```shell
hitrace -t 10 -b 204800 app --raw
```


**使用样例**：


```shell
$ hitrace -t 10 -b 204800 app --raw
2025/06/04 10:21:16 hitrace enter, running_state is RECORDING_SHORT_RAW
2025/06/04 10:21:16 args: tags:app bufferSize:204800 overwrite:1
2025/06/04 10:21:16 start capture, please wait 10s ...
2025/06/04 10:21:27 capture done, output files:
    /data/log/hitrace/record_trace_20250604102116@590322-695861087.sys
```


### 快照模式捕获文本格式trace

快照模式下，trace信息保存在内核缓冲区。当数据量超出缓冲区大小时，默认丢弃最早的数据。

使用以下命令开启快照模式，指定缓冲区大小为204800KB，采集的tag为app和graphic。

```shell
hitrace --trace_begin -b 204800 app graphic
```

**使用样例**：

```shell
$ hitrace --trace_begin -b 204800 app graphic
2025/06/04 16:03:39 hitrace enter, running_state is RECORDING_LONG_BEGIN
2025/06/04 16:03:39 args: tags:app,graphic bufferSize:204800 overwrite:1
2025/06/04 16:03:39 OpenRecording done.
```

在开启快照模式后，可以使用下面的命令将当前缓冲区内的数据导出。默认将trace信息显示到命令行窗口。

```shell
hitrace --trace_dump
```

**使用样例**：

```shell
$ hitrace --trace_dump
2025/06/04 16:07:57 start to read trace.
# tracer: nop
#                                          _-----=> irqs-off
#                                         / _----=> need-resched
#                                        | / _---=> hardirq/softirq
#                                        || / _--=> preempt-depth
#                                        ||| /     delay
#           TASK-PID       TGID    CPU#  ||||   TIMESTAMP  FUNCTION
#              | |           |       |   ||||      |         |
 KstateRecvThrea-1132    (    952) [002] .... 610865.463378: tracing_mark_write: B|952|H:CheckMsgFromNetlink|I62
 KstateRecvThrea-1132    (    952) [002] .... 610865.463503: tracing_mark_write: B|952|H:OnKstateCallback, mask: 8, data: [PID 14446 KILLED][SIG 9]|I62
 KstateRecvThrea-1132    (    952) [002] .... 610865.463626: tracing_mark_write: E|952|I62
 KstateRecvThrea-1132    (    952) [002] .... 610865.463654: tracing_mark_write: E|952|I62
 state_change_ha-1139    (    952) [001] .... 610865.463767: tracing_mark_write: B|952|H:ProcessEvent, eventId: 6|I62
 state_change_ha-1139    (    952) [001] .... 610865.463879: tracing_mark_write: E|952|I62
 state_change_ha-1139    (    952) [001] .... 610866.506055: tracing_mark_write: B|952|H:ProcessEvent, eventId: 0|I62
 state_change_ha-1139    (    952) [001] .... 610866.506297: tracing_mark_write: B|952|H:HandleStateTransition, 20020111_com.ohos.medialibrary.medialibrarydata_[6255]|I62
 state_change_ha-1139    (    952) [001] .... 610866.506782: tracing_mark_write: E|952|I62
 state_change_ha-1139    (    952) [001] .... 610866.506824: tracing_mark_write: E|952|I62
 state_change_ha-1139    (    952) [001] .... 610866.557458: tracing_mark_write: B|952|H:ProcessEvent, eventId: 0|I62
 state_change_ha-1139    (    952) [001] .... 610866.558060: tracing_mark_write: E|952|I62
 state_change_ha-1139    (    952) [001] .... 610866.558101: tracing_mark_write: E|952|I62
```

导出时也可以使用-o命令保存到指定文件，建议保存到/data/local/tmp路径下。

```shell
hitrace --trace_dump -o /data/local/tmp/test.ftrace
```

**使用样例**：

```shell
$ hitrace --trace_dump -o /data/local/tmp/test.ftrace
2025/06/04 16:09:10 start to read trace.
2025/06/04 16:09:10 trace read done, output: /data/local/tmp/test.ftrace
```

需要停止采集时，有如下三种命令：

1. 停止采集，并将当前缓冲区内的trace信息显示到命令行窗口。

    ```shell
    hitrace --trace_finish
    ```

    **使用样例**：

    ```shell
    $ hitrace --trace_finish
    2025/06/04 16:22:02 start to read trace.
    # tracer: nop
    #                                          _-----=> irqs-off
    #                                         / _----=> need-resched
    #                                        | / _---=> hardirq/softirq
    #                                        || / _--=> preempt-depth
    #                                        ||| /     delay
    #           TASK-PID       TGID    CPU#  ||||   TIMESTAMP  FUNCTION
    #              | |           |       |   ||||      |         |
    KstateRecvThrea-1132    (    952) [002] .... 610865.463378: tracing_mark_write: B|952|H:CheckMsgFromNetlink|I62
    KstateRecvThrea-1132    (    952) [002] .... 610865.463503: tracing_mark_write: B|952|H:OnKstateCallback, mask: 8, data: [PID 14446 KILLED][SIG 9]|I62
    KstateRecvThrea-1132    (    952) [002] .... 610865.463626: tracing_mark_write: E|952|I62
    KstateRecvThrea-1132    (    952) [002] .... 610865.463654: tracing_mark_write: E|952|I62
    ```

2. 停止采集，并将当前缓冲区内的trace信息保存到指定文件。建议保存路径为/data/local/tmp。

    ```shell
    hitrace --trace_finish -o /data/local/tmp/test.ftrace
    ```

    **使用样例**：

    ```shell
    $ hitrace --trace_finish -o /data/local/tmp/test.ftrace
    2025/06/04 16:24:52 start to read trace.
    2025/06/04 16:24:52 trace read done, output: /data/local/tmp/test.ftrace
    2025/06/04 16:24:52 Trace Closed.
    ```

3. 停止采集，不输出trace信息。

    ```shell
    hitrace --trace_finish_nodump
    ```

    **使用样例**：

    ```shell
    $ hitrace --trace_finish_nodump
    2025/06/04 16:26:11 hitrace enter, running_state is RECORDING_LONG_FINISH_NODUMP
    2025/06/04 16:26:11 end capture trace.
    ```


### 快照模式捕获二进制格式trace


快照模式下捕获二进制格式trace时不支持指定tag，默认采集以下tag。


```shell
"net", "dsched", "graphic", "multimodalinput", "dinput", "ark", "ace", "window","zaudio", "daudio", "zmedia", "dcamera", "zcamera", "dhfwk", "app", "gresource", "ability", "power", "samgr", "ffrt", "nweb", "hdf", "virse", "workq", "ipa", "sched", "freq", "disk", "sync", "binder", "mmc", "membus", "load"
```


使用下面的命令开启捕获二进制trace。


```shell
hitrace --start_bgsrv
```


**使用样例**：


```shell
$ hitrace --start_bgsrv
2025/06/04 16:44:54 hitrace enter, running_state is SNAPSHOT_START
2025/06/04 16:44:54 OpenSnapshot done.
```


使用以下命令将当前缓冲区的trace信息导出到文件。二进制格式trace不支持指定路径导出或显示到命令行窗口，导出的文件路径会显示在命令行窗口。


```shell
hitrace --dump_bgsrv
```


**使用样例**：


```shell
$ hitrace --dump_bgsrv
2025/06/04 16:50:34 hitrace enter, running_state is SNAPSHOT_DUMP
2025/06/04 16:50:35 DumpSnapshot done, output:
    /data/log/hitrace/trace_20250604164454@613340-339960.sys
```


在结束捕获时，可以使用下面的命令停止采集。


```shell
hitrace --stop_bgsrv
```


**使用样例**：


```shell
$ hitrace --stop_bgsrv
2025/06/04 16:52:51 hitrace enter, running_state is SNAPSHOT_STOP
2025/06/04 16:52:52 CloseSnapshot done.
```


### 录制模式捕获trace

录制模式下，系统会持续保存运行时生成的二进制格式trace，文件大小超过设定的值时会生成新文件。不支持指定保存路径。

使用以下命令开启录制模式。缓冲区大小设定为204800KB，文件大小设为102400KB，采集的tag为app和graphic。

```shell
hitrace --trace_begin --record -b 204800 --file_size 102400 app graphic
```

**使用样例**：

```shell
$ hitrace --trace_begin --record -b 204800 --file_size 102400 app graphic
2025/06/04 17:03:37 hitrace enter, running_state is RECORDING_LONG_BEGIN_RECORD
2025/06/04 17:03:37 args: tags:app,graphic bufferSize:204800 overwrite:1 fileSize:102400
2025/06/04 17:03:37 trace capturing.
```


采集结束时，使用以下命令停止采集，命令行窗口会显示生成的文件的绝对路径。


```shell
hitrace --trace_finish --record
```


**使用样例**：


```shell
$ hitrace --trace_finish --record
2025/06/04 17:06:14 hitrace enter, running_state is RECORDING_LONG_FINISH_RECORD
2025/06/04 17:06:15 capture done, output files:
    /data/log/hitrace/record_trace_20250604170337@614463-183970330.sys
    /data/log/hitrace/record_trace_20250604170423@614508-554071886.sys
    /data/log/hitrace/record_trace_20250604170552@614597-598551039.sys
```


### 捕获trace后进行压缩

```shell
hitrace -z -b 102400 -t 10 sched freq idle disk -o /data/local/tmp/test.ftrace
```

**使用样例**：

```shell
$ hitrace -z -b 102400 -t 10 sched freq idle disk -o /data/local/tmp/test.ftrace
2024/11/14 12:00:18 start capture, please wait 10s ...
2024/11/14 12:00:28 capture done, start to read trace.
2024/11/14 12:00:29 trace read done, output: /data/local/tmp/test.ftrace
2024/11/14 12:00:29 TraceFinish done.
```


### 设置trace输出级别阈值

打点级别优先级从高到低分别为 M（Commercial）、C（Critical）、I（Info）、D（Debug），低于trace输出级别阈值的打点将不会生效。

开发者可使用带trace级别的打点接口（参考[js-apis-hitracemeter](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)和[_hitrace](../reference/apis-performance-analysis-kit/capi-trace-h.md)中的API version 19的trace打点接口），测试不同阈值下的trace输出是否符合预期。

```shell
// 设置trace输出级别阈值
hitrace --trace_level D/I/C/M
hitrace --trace_level Debug/Info/Critical/Commercial
```

**使用样例**：

```shell
$ hitrace --trace_level Info
2024/11/14 12:05:07 hitrace enter, running_state is SET_TRACE_LEVEL
2024/11/14 12:05:07 success to set trace level.
```


## trace文件名说明

使用hitrace命令行工具采集二进制格式trace信息时，不支持指定文件路径。默认保存在/data/log/hitrace路径下，hitrace自动生成文件名并将绝对路径显示在命令行窗口。

快照模式下生成的trace文件名以trace开头，录制模式下生成的trace文件名以record开头，后面为本地时间和boot time（从开机时间开始的时间戳）。

以下面这个文件名为例：20250701215441说明这个文件生成的时间为2025年7月1日21时54分41秒，此时对应的boot time为6016.653165227。

```shell
$ hitrace --dump_bgsrv
2025/07/01 21:54:41 hitrace enter, running_state is SNAPSHOT_DUMP
2025/07/01 21:54:42 DumpSnapshot done, output:
    /data/log/hitrace/trace_20250701215441@6016-653165227.sys
```


## 常见问题


### 执行hitrace命令后显示错误码1

**现象描述**

执行hitrace命令后报错，错误码为1。

```shell
$ hitrace --dump_bgsrv
2025/07/04 17:20:38 hitrace enter, running_state is SNAPSHOT_DUMP
2025/07/04 17:20:38 error: DumpSnapshot failed, errorCode(1)
```

**可能原因&amp;解决方法**

错误码1表示hiview进程状态异常，可以尝试重启手机后重新采集。


### 执行hitrace命令后报错“not support category on this device”

**现象描述**

执行hitrace命令后报错，命令行窗口显示“not support category on this device”。

```shell
$ hitrace -t 10 aaa
2025/07/04 17:24:21 error: aaa is not support category on this device.
2025/07/04 17:24:21 error: parsing args failed, exit.
```

**可能原因&amp;解决方法**

命令中指定的tag不存在，建议使用“hitrace -l”命令查看支持的tag范围。


### 执行hitrace命令后显示错误码1004

**现象描述**

执行hitrace命令后报错，错误码为1004。

```shell
$ hitrace --dump_bgsrv
2025/07/04 17:25:58 hitrace enter, running_state is SNAPSHOT_DUMP
2025/07/04 17:25:58 error: DumpSnapshot failed, errorCode(1004)
```

**可能原因&amp;解决方法**

1004表示写入文件错误，可能的原因包括：

1. 采集文本格式trace时，使用-o参数指定输出的文件路径不存在或无权限。建议将trace保存到/data/local/tmp路径下。

2. 磁盘空间已满时，不会生成新的trace文件，建议释放磁盘空间，确保空闲空间大于500MB，然后重新采集。
