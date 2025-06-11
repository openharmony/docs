# HiTrace

HiTrace provides APIs to implement call chain tracing throughout a service process. This can help you quickly obtain the run log for the call chain of a service process and locate faults across devices, processes, and threads.

## Environment Requirements

- The [environment setup](hdc.md#environment-setup) is complete.

- The devices are properly connected and **hdc shell** is executed.

## Command Description

| Command                 | Description                                                    |
| --------------------- | ------------------------------------------------------------ |
| -h                    | Displays help information.                                                  |
| -l                    | Displays the tag list.                                               |
| --trace_begin         | Starts capturing trace data.                                             |
| --trace_finish        | Stops capturing trace data.                                             |
| --trace_dump          | Dumps trace information.                                             |
| -b N                  | Sets the buffer size (in KB) for trace data. The default buffer size is 2048 KB.|
| -t N                  | Sets the trace uptime in seconds. The default value is 5 seconds.                  |
| -o                    | Specifies the target file name (**stdout** by default).                          |
| -z                    | Compresses the trace data.                                            |
| --trace_clock         | Sets the type of the clock for adding a timestamp to a trace. The value can be **boot** (default), **global**, **mono**, **uptime**, or **perf**.|
| --trace_finish_nodump | Stops printing when trace capturing is stopped.                           |
| --start_bgsrv         | Starts trace collection in the snapshot mode.                                      |
| --dump_bgsrv          | Dumps the trace data in the snapshot mode to a file.                                |
| --stop_bgsrv          | Stops trace collection in the snapshot mode.                                      |
| --trace_level         | Sets the trace level threshold. The value can be **Debug**, **Info**, **Critical**, **Commercial**, or **D**, **I**, **C**, or **M**.<br>**Note**: This command is supported since API version 19.|

> **Description**
>
> The snapshot mode is a trace collection with a fixed trace tag. By default, the trace data is not stored. You can run the **--dump_bgsrv** command to trigger trace dump in binary format at the current time. The trace file is generated in **/data/log/hitrace** by default. The file name format is **trace-YYMMDDHHmmSS@[BOOT_TIME].sys**. You can visually analyze the trace file using [HiSmartPerf](https://gitee.com/openharmony/developtools_smartperf_host). You can download the tool from [developertools_smartperf_host Release](https://gitee.com/openharmony/developtools_smartperf_host/releases).

## Examples

### Displaying the Tag List in HiTrace

```shell
hitrace -l
```
**Example**

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

### Starting Trace Capture for a Specified Tag

```shell
hitrace --trace_begin --record app
```
**Example**

```shell
$ hitrace --trace_begin --record app
2024/11/14 11:48:45 hitrace enter, running_state is RECORDING_LONG_BEGIN_RECORD
2024/11/14 11:48:45 args: tags:app bufferSize:18432 overwrite:1
2024/11/14 11:48:45 OpenRecording done.
```

### Stopping Trace Capture

By default, the tarce data is displayed in the CLI.

```shell
hitrace --trace_finish --record
```
**Example 1**

```shell
$ hitrace --trace_finish --record
2024/11/14 11:50:33 hitrace enter, running_state is RECORDING_LONG_FINISH_RECORD
2024/11/14 11:50:33 capture done, output files:
    /data/log/hitrace/record_trace_20241114115033@3010728-656499531.sys
```
Add an output path to export the trace data to the corresponding file.

```shell
hitrace --trace_finish -o /data/local/tmp/test.ftrace
```
**Example 2**

```shell
$ hitrace --trace_finish -o /data/local/tmp/test.ftrace
2024/11/14 11:50:33 start to read trace.
2024/11/14 11:50:33 trace read done, output: /data/local/tmp/test.ftrace
```

### Setting Parameters of Trace Capture

```shell
hitrace -b 10240 -t 10 -o /data/local/tmp/test2.ftrace app ability
```
**Example**

```shell
$ hitrace -b 10240 -t 10 -o /data/local/tmp/test2.ftrace app ability
2024/11/14 11:52:13 start capture, please wait 10s ...
2024/11/14 11:52:23 capture done, start to read trace.
2024/11/14 11:52:23 trace read done, output: /data/local/tmp/test2.ftrace
```
- Buffer size: 10240 KB
- Trace uptime: 10s
- Output path: **/data/local/tmp/test2.ftrace**.
- Tags: **app** and **ability**

### Dumping Trace Data

By default, the trace data is displayed in the CLI.

```shell
hitrace --trace_dump
```
**Example 1**

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
Add an output path to export the trace data to the corresponding file.

```shell
hitrace --trace_dump -o /data/local/tmp/test3.ftrace
```
**Example 2**

```shell
$ hitrace --trace_dump -o /data/local/tmp/test3.ftrace
2024/11/14 11:54:23 start to read trace.
2024/11/14 11:54:23 trace read done, output: /data/local/tmp/test3.ftrace
```
You can also run the **hitrace --trace_dump | grep xxx** command to dump trace data based on keywords.

### Starting Trace Capture in the Snapshot Mode

```shell
hitrace --start_bgsrv
```
**Example**

```shell
$ hitrace --start_bgsrv
2024/11/14 11:55:53 hitrace enter, running_state is SNAPSHOT_START
2024/11/14 11:55:54 OpenSnapshot done.
```

### Dumping Trace Data in the Snapshot Mode

By default, the trace data is stored in the binary format in **/data/log/hitrace/**. The file is named in the format of **trace-YYMMDDHHmmSS@[BOOT_TIME].sys**. You can visually analyze the trace file using [HiSmartPerf](https://gitee.com/openharmony/developtools_smartperf_host). You can download the tool from [developertools_smartperf_host Release](https://gitee.com/openharmony/developtools_smartperf_host/releases).

```shell
hitrace --dump_bgsrv
```
**Example**

```shell
$ hitrace --dump_bgsrv
2024/11/14 12:12:56 hitrace enter, running_state is SNAPSHOT_DUMP
2024/11/14 12:12:57 DumpSnapshot done, output:
    /data/log/hitrace/record_trace_20241114121257@2566589-103807063.sys
```

### Stopping Trace Capture in the Snapshot Mode

```shell
hitrace --stop_bgsrv
```
**Example**

```shell
$ hitrace --stop_bgsrv
2024/11/14 11:59:43 hitrace enter, running_state is SNAPSHOT_STOP
2024/11/14 11:59:43 CloseSnapshot done.
```

### Compressing Trace Data

```shell
hitrace -z -b 102400 -t 10 sched freq idle disk -o /data/local/tmp/test.ftrace
```
**Example**

```shell
$ hitrace -z -b 102400 -t 10 sched freq idle disk -o /data/local/tmp/test.ftrace
2024/11/14 12:00:18 start capture, please wait 10s ...
2024/11/14 12:00:28 capture done, start to read trace.
2024/11/14 12:00:29 trace read done, output: /data/local/tmp/test.ftrace
```

### Setting the Trace Output Clock to Boot (System Time of the Device)

```shell
hitrace --trace_clock boot -b 102400 -t 10 sched freq idle disk -o /data/local/tmp/test.ftrace
```
**Example**

```shell
$ hitrace --trace_clock boot -b 102400 -t 10 sched freq idle disk -o /data/local/tmp/test.ftrace
2024/11/14 12:01:42 start capture, please wait 10s ...
2024/11/14 12:01:52 capture done, start to read trace.
2024/11/14 12:01:52 trace read done, output: /data/local/tmp/test.ftrace
```

### Stopping Trace Capture and Canceling Trace Displaying

By default, the trace data is saved in **/data/log/hitrace/**.

```shell
hitrace --trace_finish_nodump
```
**Example**

```shell
$ hitrace --trace_finish_nodump
2024/11/14 12:03:07 hitrace enter, running_state is RECORDING_LONG_FINISH_NODUMP
2024/11/14 12:03:07 end capture trace.
```

### Obtaining and Setting the Trace Output Level Threshold

The priority of the trace level is as follows: **M** (**Commercial**), **C** (**Critical**), **I** (**Info**) and **D** (**Debug**). The trace level lower than the threshold does not take effect.

You can use the logging APIs with the trace level (for details, see the logging APIs of API version 19 in [js-apis-hitracemeter](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md) and [_hitrace](../reference/apis-performance-analysis-kit/_hitrace.md)) to test whether the trace output under different thresholds meets the expectation.

```shell
// Check the trace output level threshold. The value 0 indicates Debug, 1 indicates Info, 2 indicates Critical, and 3 indicates Commercial.
param get persist.hitrace.level.threshold

// Set the trace output level threshold.
hitrace --trace_level D/I/C/M
hitrace --trace_level Debug/Info/Critical/Commercial
```
**Example**

```shell
$ hitrace --trace_level Info
2024/11/14 12:05:07 hitrace enter, running_state is SET_TRACE_LEVEL
2024/11/14 12:05:07 success to set trace level.
$ param get persist.hitrace.level.threshold
1
```
