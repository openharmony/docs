# hiperf

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @leiguangyu-->
<!--Designer: @Maplestroy91-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=44da34c75e0877dd26e067a23f1dc0303066fdbb translatedAt=2026-07-31T01:32:14.076Z pushedAt=2026-07-31T07:39:23.302Z -->

hiperf is a command line tool that integrates multiple performance analysis capabilities, enabling you to identify system bottlenecks, locate software hotspots, optimize code efficiency, and collect and analyze runtime performance data.

You can use hiperf through [Deveco Studio](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-software-install) or [SmartPerf](https://gitcode.com/openharmony/developtools_smartperf_host/releases) to collect the function call stack, obtain the execution time of each function on the call stack, and view the call chain information in a swimlane diagram for performance analysis. For details, see [Basic Time Analysis: Time](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-insight-session-time) and [hiperf Usage](https://gitcode.com/openharmony/developtools_smartperf_host/blob/master/smartperf_host/ide/src/doc/md/quickstart_hiperf.md). To specify the event, sampling period, collection duration, and number of CPU cores, you can use HiPerf. The **perf.data** file can be opened using SmartPerf and displayed in a flame graph.

This topic describes how to use hiperf to perform performance analysis.

## Environment Setup

- The environment for OpenHarmony Device Connector (hdc) has been set up. For details, see [Environment Setup](hdc.md#environment-setup).

- The devices are properly connected and **hdc shell** is executed.

## Command Syntax

Run the **hiperf --help** command to list all hiperf commands, including **dump**, **list**, **record**, **report**, and **stat**.

```shell
$ hiperf --help
```

| Command| Description| 
| -------- | -------- |
| --hilog | Records logs generated during program running to HiLog.| 
| --logpath | Sets the save path of log files. You can set the output file path to **/data/local/tmp/** and customize the file name.| 
| --logtag | Enables logs of a specified functionality.| 
| --debug | Records **debug** logs.| 
| --verbose | Records **verbose** logs.| 
| --much | Records **much** logs.| 
| --nodebug | Disables all logs.| 
| --mixlog | Outputs logs to the CLI.| 
| -h/--help | Displays the help information.| 
| [dump](#dump)| Converts the performance data file (for example, **perf.data**) into a readable format.| 
| [list](#list)| Displays the performance event types supported by the system.| 
| [record](#record)| Collects performance data.| 
| [report](#report)| Converts performance data into visualized data.| 
| [stat](#stat)| Collects statistics on performance data.| 

**Example**

```shell
$ hiperf --help
Usage: hiperf [options] command [args for command]
options:
        --debug                 show debug log, usage format: --debug [command] [args]
        --help                  show help
        --hilog                 use hilog not file to record log
        --logpath               log file name full path, usage format: --logpath [filepath] [command] [args]
        --logtag                enable log level for HILOG_TAG, usage format: --logtag <tag>[:level][,<tag>[:level]] [command] [args]
                                tag: Dump, Report, Record, Stat... level: D, V, M...
                                example: hiperf --verbose --logtag Record:D [command] [args]
        --mixlog                mix the log in output, usage format: --mixlog [command] [args]
        --much                  show extremely much debug log, usage format: --much [command] [args]
        --nodebug               disable debug log, usage format: --nodebug [command] [args]
        --verbose               show debug log, usage format: --verbose [command] [args]     
        -h                      show help
command:
        dump:   Dump content of a perf data file, like perf.data
        help:   Show more help information for hiperf
        list:   List the supported event types.
        record: Collect performance sample information
        report: report sampling information from perf.data format file
        stat:   Collect performance counter information

See 'hiperf help [command]' for more information on a specific command.
```

## Common Commands

### Recording Performance Data Sampling

1. Sample the process **1234** for 10 seconds. Set the stack unwinding mode to **fp**, sampling frequency to **1000** times per second, event types to **hw-cpu-cycles** and **hw-instructions**, and save the sampling file to **/data/local/tmp/perf.data**.

    ```shell
    $ hiperf record -p 1234 -s fp -f 1000 -d 10 -e hw-cpu-cycles,hw-instructions -o /data/local/tmp/perf.data
    Profiling duration is 10.000 seconds.
    Start Profiling...
    Timeout exit (total 10335 ms)
    Process and Saving data...
    Hiperf is not running as root mode. Do not need load kernel syms
    [ hiperf record: Captured 3.014 MB perf data. ]
    [ Sample records: 1293, Non sample records: 855 ]
    [ Sample lost: 0, Non sample lost: 0 ]
    ```

    The collected data is saved as a **perf.data** file in binary format, which contains the sampling data, process information, symbol table, and function calls required for performance analysis. You can use the flame graph script to convert the sampling data into a flame graph to identify system performance bottlenecks, locate software hotspots, and optimize code efficiency.

2. Sample the application **com.example.insight_test_stage**. Set the sampling duration to **10s**, stack unwinding mode to **dwarf** (debug information table), sampling period to **1000**, event types to **hw-cpu-cycles** and **hw-instructions**, and use the default save path.

    ```shell
    $ hiperf record --app com.example.insight_test_stage -d 10 -s dwarf --period 1000 -e hw-cpu-cycles,hw-instructions
    Profiling duration is 10.000 seconds.
    Start Profiling...
    Timeout exit (total 10000 ms)
    Process and Saving data...
    Hiperf is not running as root mode. Do not need load kernel syms
    [ hiperf record: Captured 0.296 MB perf data. ]
    [ Sample records: 0, Non sample records: 2640 ]
    [ Sample lost: 0, Non sample lost: 0 ]
    ```

    The collected data is saved to the default path **/data/local/tmp/perf.data**.

### Collecting Performance Statistics

1. Count the processes with process IDs 1745 and 1910 for a counting duration of 10 seconds.

    ```shell
    $ hiperf stat -d 10 -p 1745,1910
    Profiling duration is 10.000 seconds.
    Start Profiling...
    Timeout exit (total 10000 ms)
                        count  name                           | comment                          | coverage
                      148,450  hw-branch-instructions         | 26.404 M/sec                     | (100%)
                      49,833  hw-branch-misses               | 33.568878 miss rate              | (100%)
                    8,986,523  hw-cpu-cycles                  | 1.598409 GHz                     | (100%)
                    1,283,596  hw-instructions                | 7.001053 cycles per instruction  | (100%)
                          63  sw-context-switches            | 11.206 K/sec                     | (100%)
                            0  sw-page-faults                 | 0.000 /sec                       | (100%)
                    5,622,169  sw-task-clock                  | 0.000562 cpus used               | (100%)
    ```

2. Count processes **1745** and **1910** for **10** seconds, with event types set to **hw-cpu-cycles**, **hw-instructions**, and **sw-task-clock**, and a print interval of **3000** ms.

    ```shell
    $ hiperf stat -d 10 -p 1745,1910 -e hw-cpu-cycles,hw-instructions,sw-task-clock -i 3000
    Profiling duration is 10.000 seconds.
    Start Profiling...
    Report at 3000 ms (6999 ms left):
                        count  name                           | comment                          | coverage
                    2,534,675  hw-cpu-cycles                  | 1.717114 GHz                     | (100%)
                      324,279  hw-instructions                | 7.816340 cycles per instruction  | (100%)
                    1,476,125  sw-task-clock                  | 0.000492 cpus used               | (100%)
    Report at 6000 ms (3999 ms left):
                        count  name                           | comment                          | coverage
                    5,112,570  hw-cpu-cycles                  | 1.724259 GHz                     | (100%)
                      648,303  hw-instructions                | 7.886081 cycles per instruction  | (100%)
                    2,965,083  sw-task-clock                  | 0.000494 cpus used               | (100%)
    Report at 9000 ms (999 ms left):
                        count  name                           | comment                          | coverage
                    7,870,422  hw-cpu-cycles                  | 1.724897 GHz                     | (100%)
                      994,407  hw-instructions                | 7.914689 cycles per instruction  | (100%)
                    4,562,835  sw-task-clock                  | 0.000507 cpus used               | (100%)
    Timeout exit (total 10000 ms)
    ```

3. Count the process with process ID 1910 for a counting duration of 3 seconds, with the event types hw-cpu-cycles and hw-instructions, and print detailed information.

    ```shell
    $ hiperf stat -d 3 -p 1910 -e hw-cpu-cycles,hw-instructions --verbose
    Profiling duration is 3.000 seconds.
    Start Profiling...
    Timeout exit (total 3000 ms)
    hw-cpu-cycles id:1342(c-1:p1910) timeEnabled:133583 timeRunning:133583 value:255740
    hw-cpu-cycles id:1343(c-1:p1988) timeEnabled:0 timeRunning:0 value:0
    hw-cpu-cycles id:1344(c-1:p1989) timeEnabled:0 timeRunning:0 value:0
    hw-cpu-cycles id:1345(c-1:p1990) timeEnabled:187833 timeRunning:187833 value:331425
    ...
    hw-instructions id:1375(c-1:p1910) timeEnabled:133583 timeRunning:133583 value:36485
    hw-instructions id:1376(c-1:p1988) timeEnabled:0 timeRunning:0 value:0
    hw-instructions id:1377(c-1:p1989) timeEnabled:0 timeRunning:0 value:0
    hw-instructions id:1378(c-1:p1990) timeEnabled:187833 timeRunning:187833 value:47816
    ...
                        count  name                           | comment                          | coverage
                      669,850  hw-cpu-cycles                  |                                  | (100%)
                      94,903  hw-instructions                | 7.058259 cycles per instruction  | (100%)
    ```

## list

Displays the performance event types supported by the system, which can be used as parameters of the **-e** option in the **record** and **stat** commands.

**Parameters**

| Name| Description| 
| -------- | -------- |
| -h/--help | Displays the help information.| 
| hw | Lists the hardware events.<br>The following events are supported:<br>- hw-cpu-cycles<br>- hw-instructions<br>- hw-cache-references<br>- hw-cache-misses<br>- hw-branch-instructions<br>- hw-branch-misses<br>- hw-bus-cycles<br>- hw-stalled-cycles-frontend<br>- hw-stalled-cycles-backend | 
| sw | Lists the software events.| 
| tp | Lists the tracepoint event.| 
| cache | Lists the hardware cache events.| 
| raw | Lists original performance monitoring unit (PMU) events.| 

**Example**

```shell
Usage: hiperf list [event type name]
```

Query the supported hardware event types.

```shell
$ hiperf list hw
event not support hw-ref-cpu-cycles

Supported events for hardware:
        hw-cpu-cycles
        hw-instructions
        hw-cache-references
        hw-cache-misses
        hw-branch-instructions
        hw-branch-misses
        hw-bus-cycles
        hw-stalled-cycles-frontend
        hw-stalled-cycles-backend
```

## record

Collects the performance data of a specified process or application, including the CPU cycle, number of instructions, and function calls, and saves the sampling data to a specified file. (For the default path, run the **hiperf record -h/--help** command to view the description of the **-o** parameter.)

> **NOTE**
>
> The process to be collected must be an [app signed with a debug certificate](hiperf.md#what-should-i-do-if-hiperf-fails-to-collect-applications-without-the-debug-certificate-signature).  
> Since API version 24, on PC devices, you can use the terminal command-line app to collect apps with the profileable attribute enabled in [configuration file tags](../quick-start/app-configuration-file.md#tags-in-the-configuration-file).
> Since API version 26.0.0, you can collect apps with the profileable attribute enabled in [configuration file tags](../quick-start/app-configuration-file.md#tags-in-the-configuration-file).

**Parameters of the record command**

<!--RP1-->

| Parameter | Description |
| -------- | -------- |
| -h/--help | Help command. |
| -c | Sets the CPU ID for collection. Only data from the specified CPU is collected. |
| --cpu-limit | Sets the maximum CPU usage percentage during collection. Value range: 1–100, default: 25. |
| -d | Collection duration, in seconds. This parameter cannot be used together with --control. |
| -f | Sampling frequency. The default value is 4000 times/s. This parameter cannot be used together with --period. |
| --period | Sets the collection event period, that is, how many events trigger one sample. This parameter cannot be used together with -f. |
| -e | Collection events. Multiple event types are supported, separated by commas. Use the list command to view the supported event types. |
| -g | Collection event group, separated by commas. |
| --no-inherit | Does not collect data from child processes. |
| -p | Process IDs to collect. Multiple process IDs are supported, separated by commas. This parameter cannot be used together with -a. |
| -t | Thread IDs to collect. Multiple thread IDs are supported, separated by commas. This parameter cannot be used together with -a. |
| --exclude-tid | Thread IDs to exclude from collection. Multiple thread IDs are supported, separated by commas. This parameter cannot be used together with -a. |
| --exclude-thread | Thread names to exclude from collection. Multiple thread names are supported, separated by commas. This parameter cannot be used together with -a. |
| --offcpu | Traces when a thread is scheduled off the CPU. |
| -j | Branch stack sampling. Supported filters: any, any_call, any_ret, ind_call, ind_jmp, cond, call. |
| -s/--call-stack | Sets the backtrace mode. Available modes: fp (Frame Pointer) and dwarf (debug information table). |
| --kernel-callchain | Collects kernel-mode call stacks. This parameter must be used together with -s. |
| --callchain-useronly | Collects only user-mode call stacks. |
| --delay-unwind | When the backtrace mode is set to dwarf, the call stack is unwound after recording if this option is set. |
| --disable-unwind | When the backtrace mode is set to dwarf, the call stack is not unwound after recording if this option is set. |
| --disable-callstack-expand | When the backtrace mode is set to dwarf, cached thread stacks are used to merge call stacks if this option is set. |
| --enable-debuginfo-symbolic | When -s fp/dwarf is set, symbols in the .gnu_debugdata section of the ELF file are resolved. By default, they are not resolved. |
| --clockid | Sets the clock type for collection. Supported types: monotonic and monotonic_raw. Some events also support boottime, realtime, and clock_tai. |
| --symbol-dir | Path of the symbol table file, used for symbolization during collection. |
| -m | Number of mmap pages. Value range: 2–1024, default: 1024. |
| --app | Names of the applications to collect, separated by commas. The applications must be running. If an application is not started, the command waits for 20 seconds and automatically ends if the application is still not started within that period. This parameter cannot be used together with -a. |
| --chkms | Sets the query interval, in milliseconds. Value range: 1–200, default: 10. |
| --data-limit | Stops collection when the output data reaches the specified size. By default, there is no limit. |
| -o | Sets the output file path and allows you to customize the file name. |
| -z | Outputs data as a .gz compressed file. |
| --restart | Collects performance metrics during app startup. If the process does not start within 30 seconds, the collection operation ends. |
| --verbose | Outputs a more detailed report. |
| --control [command] | Controls the start and stop of the collection operation. Supported commands: prepare, start, pause, resume, output, stop. This parameter cannot be used together with -d. |
| --dedup_stack | Removes duplicate stacks from the record. |
| --cmdline-size | Sets the value of the /sys/kernel/tracing/saved_cmdlines_size node, in bytes. Value range: 512–4096. |
| --report | Generates a backtrace report after collection. |
| --backtrack | Collects data from a period before the current time. This parameter must be used together with --control prepare. |
| --backtrack-sec | Duration of the backtrack data collection, in seconds. Value range: 5–30, default: 10. This parameter must be used together with --backtrack. |
| --dumpoptions | Displays detailed information about the collection parameters. |
| -a | Collects performance data of the entire device. |
| --exclude-hiperf | Does not collect performance data of the hiperf process itself. This optional parameter must be used together with -a. |
| --exclude-process | Names of processes to exclude from collection. This parameter must be used together with -a. |
| --pipe_input | In device development, this parameter is used to establish a command input channel when a client process calls hiperf. You can refer to the [hiperf_client API](../../device-dev/subsystems/subsys-toolchain-hiperf.md) to use this capability. In app development, this parameter is not needed. |
| --pipe_output | In device development, this parameter is used to establish a response output channel when a client process calls hiperf. You can refer to the [hiperf_client API](../../device-dev/subsystems/subsys-toolchain-hiperf.md) to use this capability. In app development, this parameter is not needed. |
| --append-smo-data | When this parameter is enabled, the name of the original .so file in the packaged .so is added.<br>**NOTE**<br>This parameter is supported since API version 23. |
| --add-counter | Collects the performance counter values of the events specified by this parameter. Multiple events are separated by commas. This parameter must be used together with --no-inherit.<br>**Note:** This parameter is supported since API version 26.0.0. |
| --raw-data | Enables the collection of raw binary event data, typically used to obtain detailed information about tracepoint events.<br>**Note:** This parameter is supported since API version 26.0.0. |

<!--RP1End-->

**Example**

```shell
Usage: hiperf record [options] [command [command-args]]
```

Sample the process 267 for 10 seconds and use **dwarf** to unwind the stack.

```shell
$ hiperf record -p 267 -d 10 -s dwarf
```

## stat

Monitors the specified application and periodically prints the values of performance counters.

> **NOTE**
>
> The process to be collected must be an [app signed with a debug certificate](hiperf.md#what-should-i-do-if-hiperf-fails-to-collect-applications-without-the-debug-certificate-signature).  
> Since API version 24, on PC devices, you can use the terminal command-line app to collect apps with the profileable attribute enabled in [configuration file tags](../quick-start/app-configuration-file.md#tags-in-the-configuration-file).
> Since API version 26.0.0, you can collect apps with the profileable attribute enabled in [configuration file tags](../quick-start/app-configuration-file.md#tags-in-the-configuration-file).

**Parameters of the stat command**

<!--RP2-->

| Parameter| Description| 
| -------- | -------- |
| -h/--help | Displays the help information.| 
| -c | Sets the ID of the CPU to collect its data.| 
| -d | Sets the collection duration, in seconds. This parameter cannot be used together with **--control**.| 
| -i | Sets the interval for printing **stat** information, in milliseconds.| 
| -e | Specifies the events to collect. Multiple events are supported; use commas (,) to separate them.| 
| -g | Specifies the event groups to collect, which are separated by commas (,). You can run the **list** command to obtain the supported event types.| 
| --no-inherit | Collects no subprocess data.| 
| -p | Specifies the process ID to collect. Multiple process IDs are supported; separate them with commas (,). This parameter cannot be used together with **-a**.| 
| -t | Specifies the thread ID to collect. Multiple thread IDs are supported; separate them with commas (,). This parameter cannot be used together with **-a**.| 
| --app | Sets the application names to collect. Use commas (,) to separate them. The application must already be running. If it has not started, the command waits up to 20s and then exits automatically. This parameter cannot be used together with **-a**.| 
| --chkms | Sets the query interval, in milliseconds. The value ranges from 1 to 200. The default value is **10**.| 
| --per-core | Obtains the print count of each CPU core.| 
| --per-thread | Obtains the print count of each thread.| 
| --restart | Collects performance indicator information about application startup. If a process is not started within 30 seconds, the record exits. This parameter must be used together with **--app**.| 
| --verbose | Outputs detailed information.| 
| --dumpoptions | Displays details about all options in the list.| 
| --control [command] | Controls the collection operation. The commands include **prepare**, **start**, and **stop**. This parameter cannot be used together with **-d**.<br>Note: This parameter is supported since API version 20.| 
| -o | Sets the output file path. You can customize the file name.<br>For the default path, run the **hiperf stat -h/--help** command to view the description of the **-o** parameter.<br>This parameter must be used with **--control prepare**, and cannot be used with **--control**.<br>Note: This parameter is supported since API version 20.| 
| -a | Collects the device performance data.|

<!--RP2End-->

**Example**

```shell
hiperf stat [options] [command [command-args]]
```

Run the **stat** command to monitor the performance data of the process **2349** that runs on CPU 0 for three seconds.

```shell
$ hiperf stat -p 1745 -d 3 -c 0
```

## dump

Converts performance data files in different formats (for example, **perf.data**) into plain texts for you to check the correctness of original sampling data.

**Parameters of the dump command**

| Parameter| Description| 
| -------- | -------- |
| -h/--help | Displays the help information.| 
| --head | Outputs only the data header and attributes.| 
| -d | Outputs only the data segment.| 
| -f | Outputs only additional functions.| 
| --sympath | Specifies the path of the symbol table file.| 
| -i | Specifies the path of the sampling file.| 
| -o | Sets the output file path. You can set the output file path to **/data/local/tmp/** and customize the file name. If this parameter is not set, the data is output to the CLI.| 
| --elf | Converts the ELF file to a readable plaintext.| 
| --proto | Converts the .proto file to a readable plaintext.| 
| --export | Splits the user stack data into multiple files.| 

**Example**

```shell
Usage: hiperf dump [option] \<filename\>
```

Run the **dump** command to read the **/data/local/tmp/perf.data** file and export it to the **/data/local/tmp/perf.dump** file.

```shell
$ hiperf dump -i /data/local/tmp/perf.data -o /data/local/tmp/perf.dump
```

## report

This command is mainly used to convert the sampling data (**perf.data**) to a user-specified format (such as JSON or ProtoBuf). It can group samples belonging to the same process, thread, or function into individual sample entries, sort the sample entries by their event counts, and display them in a report.

**Parameters of the report command**

| Parameter| Description| 
| -------- | -------- |
| -h/--help | Displays the help information.| 
| --symbol-dir | Specifies the path of the symbol table file.| 
| --limit-percent | Filters performance data whose share is at least the specified percentage (1 to 100). Only entries meeting this threshold are included in the report.| 
| -s | Displays the stack mode.| 
| --call-stack-limit-percent | Displays the stack content of a specified proportion. The value ranges from 1 to 100.| 
| -i | Specifies the resource file path. The default value is **perf.data**.| 
| -o | Sets the output file path. You can set the output file path to **/data/local/tmp/** and customize the file name. If this parameter is not set, the data is output to the CLI.| 
| --proto | Outputs data in ProtoBuf format.| 
| --json | Outputs data in JSON format.| 
| --diff | Displays the differences between the source file and the converted file. This parameter cannot be used together with **--proto**, **--json**, or **-s**.| 
| --branch | Displays the branches based on the function address.| 
| --&lt;keys&gt; &lt;keyname1&gt;[,keyname2][,...] | Specifies the keywords, which can be **comms**, **pids**, **tids**, **dsos**, **funcs**, **from_dsos** or **from_funcs**, for example, **--comms hiperf**.| 
| --sort [key1],[key2],[...] | Sorts the data by keyword.| 
| --hide_count | Hides values in the report.| 
| --dumpoptions | Displays details about all options in the list.| 

**Example**

```shell
Usage: hiperf report [option] \<filename\>
```

Extract key data that has a great impact on performance (≥ 1%) from the **perf.data** file and displays the data in a report.

```shell
$ hiperf report -i /data/local/tmp/perf.data --limit-percent 1
```

## FAQs

### What should I do if hiperf fails to collect applications without the debug certificate signature

**Symptom**

Only applications with the debug certificate signature can be collected. The message "only support debug application" is displayed.

Since API version 26.0.0, collection of release-certificate-signed apps with the profileable tag attribute enabled is supported. The error message is: only support debug or profileable application.

**Possible Causes and Solution**

**Causes**

The app does not have a debug certificate signature and the profileable tag attribute is not enabled.

**Solution**

When you use the `hiperf record/stat -p [pid]` command, the process to be collected must be an app signed with a debug certificate or a release-certificate-signed app with the profileable tag attribute enabled.

To check whether the app specified in the command is a debuggable app, run the hdc shell "bm dump -n bundlename | grep appProvisionType" command to query whether it is an app signed with a debug certificate. For an app signed with a debug certificate, the expected output is "appProvisionType": "debug".

Alternatively, run the hdc shell "bm dump -n bundlename | grep profileable" command to query whether it is a release-certificate-signed app with the profileable tag attribute enabled. For such an app, the expected output is "profileable": true.

For example, run the following command to check the bundle name **com.example.myapplication**:

```shell
hdc shell "bm dump -n com.example.myapplication | grep appProvisionType"
```

If the app corresponding to the bundle name is a debuggable app signed with a debug certificate, the expected output is as follows:

```shell
"appProvisionType": "debug",
```

or

```shell
hdc shell "bm dump -n bundlename | grep profileable"
```

If the app corresponding to the bundle name is a debuggable app with the profileable tag attribute enabled, the expected output is as follows:

```shell
"profileable": true
```

To build a debug-type application, you need to use a debug certificate for signature. For details about how to request and use the debug certificate, see [Requesting a Debug Certificate](https://developer.huawei.com/consumer/en/doc/app/agc-help-add-debugcert-0000001914263178).

For details about enabling the profileable tag attribute, see [Tags in the Configuration File](../quick-start/app-configuration-file.md#tags-in-the-configuration-file).