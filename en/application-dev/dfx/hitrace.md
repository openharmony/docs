# hitrace

**HiTrace** provides APIs to implement call chain tracing throughout a service process. With this module, you can quickly obtain the run log specific to the call chain of a service process and locate faults across threads, processes, and devices.

## Environment Requirements

- The [environment setup](hdc.md#environment-setup) is complete.
- The devices are properly connected.

## Command Description

| Command                 | Description                                                    |
| --------------------- | ------------------------------------------------------------ |
| -h                    | Displays help information.                                                  |
| -l                    | Displays the tag list.                                               |
| --trace_begin         | Starts capturing trace data.                                             |
| --trace_finish        | Stops capturing trace data.                                             |
| --trace_dump          | Dumps trace information.                                             |
| -b N                  | Sets the buffer size (in KB) for trace data. The default buffer size is 2048 KB.|
| -t N                  | Sets the trace uptime in seconds, which depends on the time required for analysis. The default value is 5 seconds.|
| -o                    | Specifies the target file name (**stdout** by default).                  |
| -z                    | Compresses the trace data.                                            |
| --trace_clock         | Sets the type of the clock for adding a timestamp to a trace. The value can be **boot** (default), **global**, **mono**, **uptime**, or **perf**.|
| --trace_finish_nodump | Stops printing when trace capturing is stopped.                            |
| --start_bgsrv         | Starts trace collection in the snapshot mode.                                 |
| --dump_bgsrv          | Dumps the trace data in the snapshot mode to a file.                               |
| --stop_bgsrv          | Stops trace collection in the snapshot mode.                                 |
| --trace_level         | Sets the trace level threshold. The trace level lower than the threshold does not take effect. The value can be **Debug**, **Info**, **Critical**, **Commercial**, or **D**, **I**, **C**, or **M**. The logging level priority is **D** < **I** < **C** < **M**. You can use the logging APIs with the trace level in [js-apis-hitracemeter](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md) and [_hitrace](../reference/apis-performance-analysis-kit/_hitrace.md) to check whether the trace output of different thresholds meets the expectation.|

> **Description**
>
> The snapshot mode is a trace collection service with a fixed trace tag. By default, the trace data is not stored. You can run the **--dump_bgsrv** command to trigger trace dump at the current time. The trace file is in binary format and is generated in **/data/log/hitrace** by default. The file name format is **trace-YYMMDDHHmmSS@[BOOT_TIME].sys**. You can view the file using [SmartPerf](https://www.smartperf.host).

## Examples

Run the following commands in the hdc shell:

1. Display the tag list in hitrace.

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
          bluetooth - communicatio bluetooth
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
   istributeddatamgr - Distributed Data Manager
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
2. Start to capture the trace data of a specified tag.

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
3. Stop to capture the trace data.

   By default, the trace data is displayed in the CLI.

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
   Add the output path to export the trace data to the corresponding file.

   ```shell
   hitrace --trace_finish -o /data/local/tmp/test.ftrace
   ```
   **Example 2**

   ```shell
   $ hitrace --trace_finish -o /data/local/tmp/test.ftrace
   2024/11/14 11:50:33 start to read trace.
   2024/11/14 11:50:33 trace read done, output: /data/local/tmp/test.ftrace
   ```
4. Capture trace data with the following settings:

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
   - Tags: app and ability
5. Dump trace information.

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
   #
   ```
   Add the output path to export the trace data to the corresponding file.

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
6. Start trace collection in the snapshot mode.

   ```shell
   hitrace --start_bgsrv
   ```
   **Example**

   ```shell
   $ hitrace --start_bgsrv
   2024/11/14 11:55:53 hitrace enter, running_state is SNAPSHOT_START
   2024/11/14 11:55:54 OpenSnapshot done.
   ```
7. Dump the trace data in snapshot mode.

   By default, the trace data is stored in the binary format in **/data/log/hitrace/**. The file is named in the format of **trace-YYMMDDHHmmSS@[BOOT_TIME].sys**. You can view the file using [SmartPerf](https://www.smartperf.host).

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
8. Stop trace collection in the snapshot mode.

   ```shell
   hitrace --stop_bgsrv
   ```
   **Example**

   ```shell
   $ hitrace --stop_bgsrv
   2024/11/14 11:59:43 hitrace enter, running_state is SNAPSHOT_STOP
   2024/11/14 11:59:43 CloseSnapshot done.
   ```
9. Compress the trace data.

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
10. Set the trace output clock to **boot** (system time of the device).

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
11. Stop capturing and printing trace data in the CLI.

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
12. Set the trace level threshold to **Info**.

    ```shell
    hitrace --trace_level Info
    ```
    **Example**

    ```shell
    $ hitrace --trace_level Info
    2024/11/14 12:05:07 hitrace enter, running_state is SET_TRACE_LEVEL
    2024/11/14 12:05:07 success to set trace level.
    ```

<!--no_check-->