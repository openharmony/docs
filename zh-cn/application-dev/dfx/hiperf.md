# hiperf

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @leiguangyu-->
<!--Designer: @Maplestroy-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

hiperf是一款集成多种性能分析功能的命令行工具，可用于分析系统性能瓶颈、定位软件热点及优化代码效率，支持采集和统计程序运行时的性能数据。


开发者可优先使用[Deveco Studio](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-insight-session-time)或[SmartPerf](https://gitcode.com/openharmony/developtools_smartperf_host/blob/master/smartperf_host/ide/src/doc/md/quickstart_hiperf.md)等图形前端工具采集函数的调用栈，获取调用栈上各层函数的执行时间，通过泳道图等方式查看调用链信息进而进行性能分析。若需要指定采集的事件、采样周期、采集时长、CPU核数等选项，可以单独使用 hiperf 命令行工具。采样数据 perf.data 文件可以使用SmartPerf工具打开并以可视化的火焰图进行展示。


本文档详细说明了hiperf命令行工具的使用方法，帮助开发者借助该工具进行详细的性能分析。


## 环境要求

- 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)。

- 确保设备已连接，然后执行hdc shell。


## 命令行说明

使用hiperf --help可以列出hiperf所有的命令，包括dump、list、record、report、stat等。

```shell
$ hiperf --help
```


| 命令 | 命令说明 | 
| -------- | -------- |
| --hilog | 设置该选项后，程序运行过程中产生的日志会被记录到hilog中。 | 
| --logpath | 设置日志文件的保存路径，现支持用户将输出文件路径设定为"/data/local/tmp/"目录，并允许用户自定义文件名称。 | 
| --logtag | 开启指定功能的日志。 | 
| --debug | 记录debug级别的日志。 | 
| --verbose | 记录verbose级别的日志。 | 
| --much | 记录much级别的日志。 | 
| --nodebug | 关闭所有日志的记录。 | 
| --mixlog | 日志输出到命令行界面。 | 
| -h/--help | 帮助命令。 | 
| [dump](#dump命令) | 将性能数据文件（如perf.data）转换为内容可读的格式。 | 
| [list](#list命令) | 展示当前系统支持的性能事件类型。 | 
| [record](#record命令) | 收集性能数据。 | 
| [report](#report命令) | 将性能数据进行可视化转换。 | 
| [stat](#stat命令) | 统计性能数据。 | 


**使用样例**：


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


## 常用命令


### 性能数据采样记录


1. 对进程ID为1234的进程采样10秒，设置回栈方式为fp（栈指针），采样频率1000次/秒，事件类型为hw-cpu-cycles和hw-instructions，采样文件保存至/data/local/tmp/perf.data。


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


采集的数据将保存为二进制格式的perf.data文件，包含性能分析所需的采样数据、进程信息、符号表及函数调用等内容。利用火焰图脚本可将采样数据转换为可视化火焰图，以此分析系统性能瓶颈、定位软件热点并优化代码效率。


2. 对应用com.example.insight_test_stage进行采样，采样时长为10s，回栈方式设置为dwarf（调试信息表），采样周期为1000，事件类型为hw-cpu-cycles和hw-instructions，使用默认保存路径。


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


采集的数据会被保存至默认路径/data/local/tmp/perf.data中。


### 性能数据统计


1. 对进程ID为1745，1910的进程进行计数，计数时长为10s。


```
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


2. 对进程ID为1745和1910的进程进行计数，计数时长为10秒，事件类型为hw-cpu-cycles、hw-instructions、sw-task-clock，指定打印信息的时间间隔为3000ms。


```
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


2.3 对进程ID为1910的进程进行计数，计数时长为3s，事件类型为hw-cpu-cycles，hw-instructions，并打印详细的信息。


```
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


## debug应用


> **注意：**
>
> hiperf record/stat -p [pid] 命令采集的进程应为“使用调试证书签名的应用”。
> 
> 确认命令指定的应用是否为可调试应用，可执行hdc shell "bm dump -n bundlename | grep appProvisionType"查询，预期返回信息为"appProvisionType": "debug"。
> 
> 以包名com.example.myapplication为例，可执行如下命令查询：
> 
> ```shell
> hdc shell "bm dump -n com.example.myapplication | grep appProvisionType"
> ```
> 
> 如包名对应的应用是可调试应用，预期返回信息如下：
> 
> ```shell
> "appProvisionType": "debug",
> ```
> 
> 构建可调试应用需要使用调试证书进行签名，申请调试证书及签名可参考：[申请调试证书](https://developer.huawei.com/consumer/cn/doc/app/agc-help-add-debugcert-0000001914263178)。


## list命令

展示当前系统支持的性能事件类型，事件类型可用于record和stat命令-e选项的参数。

**参数**：

| 参数名 | 说明 | 
| -------- | -------- |
| -h/--help | 帮助命令。 | 
| hw | 硬件事件。<br/>当前支持事件：<br/>- hw-cpu-cycles<br/>- hw-instructions<br/>- hw-cache-references<br/>- hw-cache-misses<br/>- hw-branch-instructions<br/>- hw-branch-misses<br/>- hw-bus-cycles<br/>- hw-stalled-cycles-frontend<br/>- hw-stalled-cycles-backend | 
| sw | 软件事件。 | 
| tp | tracepoint事件。 | 
| cache | 硬件缓存事件。 | 
| raw | 原始性能监测单元（PMU）事件。 | 

**命令行示例**：

```
Usage: hiperf list [event type name]
```

查询支持的硬件事件类型。


```
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


## record命令

采集指定进程或指定应用的性能数据，包括CPU周期、指令数、函数调用等信息，并且将采样数据保存到指定的文件中。

**record命令参数说明**

<!--RP1-->
| 参数 | 参数说明 | 
| -------- | -------- |
| -h/--help | 帮助命令。 | 
| -c | 设置采集的CPU ID，只采集对应的CPU数据。 | 
| --cpu-limit | 设置采集时CPU最大占比，取值范围：1 - 100，默认25。 | 
| -d | 采集时长，单位为s。该参数不能和--control一起使用。 | 
| -f | 采集频率，默认4000次/s。该参数不能和--period一起使用。 | 
| --period | 设置采集事件周期，多少事件采集一次。该参数不能和-f一起使用。 | 
| -e | 采集事件，支持对多种事件进行采集，多个事件之间以逗号隔开。可通过list命令获取当前支持的事件类型。 | 
| -g | 采集事件群组，以逗号隔开。 | 
| --no-inherit | 不采集子进程数据。 | 
| -p | 采集进程ID，支持对多个进程进行采样，多个进程号之间以逗号隔开。该参数不能和-a一起使用。 | 
| -t | 采集线程ID，支持对多个线程进行采样，多个线程号之间以逗号隔开。该参数不能和-a一起使用。 | 
| --exclude-tid | 不采集线程ID，通过线程ID排除特定线程的采样。多个线程号之间以逗号隔开。该参数不能和-a一起使用。 | 
| --exclude-thread | 不采集线程名，通过线程名排除特定线程的采样。多个线程名之间以逗号隔开。该参数不能和-a一起使用。 | 
| --offcpu | 跟踪线程何时脱离CPU调度。 | 
| -j | 分支堆栈采样，过滤器支持any、any_call、any_ret、ind_call、ind_jmp、cond、call。 | 
| -s/--callstack | 设置回栈模式，可设置为fp(栈指针)、dwarf(调试信息表)两种模式中的一种，默认是fp模式。 | 
| --kernel-callchain | 采集内核态堆栈，该参数必须和-s参数一起使用。 | 
| --callchain-useronly | 仅收集用户态堆栈。 | 
| --delay-unwind | 回栈模式被设置为dwarf时，设置此选项后调用栈会在录制后展开。 | 
| --disable-unwind | 回栈模式被设置为dwarf时，设置此选项后调用栈将不会在录制后展开。 | 
| --disable-callstack-expand | 回栈模式被设置为dwarf时，设置此选项后会用缓存的线程栈来对调用栈进行合并。 | 
| --enable-debuginfo-symbolic | -s fp/dwarf被设置时，elf在.gnu_debugdata段的符号会被解析，默认不解析。 | 
| --clockid | 设置采集时钟类型，支持monotonic和monotonic_raw，部分事件支持boottime、realtime和clock_tai时钟类型。 | 
| --symbol-dir | 符号表文件路径，用于采集过程中进行符号化操作。 | 
| -m | mmap页数量，取值范围：2 - 1024，默认1024。 | 
| --app | 采集的应用程序名，以逗号隔开。应用程序必须是启动状态，应用程序未启动时会等待20s，20s内应用程序未启动，命令会自动结束。该参数不能和-a一起使用。 | 
| --chkms | 设置查询的间隔时间，单位为ms。取值范围：1 - 200，默认10。 | 
| --data-limit | 输出数据达到指定大小停止采集，默认无限制。 | 
| -o | 设置输出文件路径，默认路径以设备上运行 hiperf record -h/--help 时显示的 -o 参数说明为准，并允许用户自定义文件名称。 | 
| -z | 以.gz的压缩文件形式输出。 | 
| --restart | 收集应用启动的性能指标信息，如果进程在30秒内未启动，采集操作将结束。 | 
| --verbose | 输出更详细的报告。 | 
| --control [command] | 采集操作启停控制参数。命令包括prepare/start/pause/resume/output/stop。该参数不能和-d一起使用。 | 
| --dedup_stack | 删除记录中的重复堆栈。 | 
| --cmdline-size | 设置/sys/kernel/tracing/saved_cmdlines_size节点的值，单位byte，取值范围：512 - 4096。 | 
| --report | 采集后回栈报告。 | 
| --backtrack | 采集之前一段时间的数据，该参数必须和--control prepare一起使用。 | 
| --backtrack-sec | 采集之前数据的时长，单位为秒。取值范围：5 - 30，默认10。该参数必须和--backtrack一起使用。 | 
| --dumpoptions | 展示采集参数的详细信息。 | 
| -a | 采集整机的性能数据。 | 
| --exclude-hiperf | 不采集hiperf进程自身的性能数据，该可选参数必须和-a一起使用。 | 
| --exclude-process | 不采集的进程名，该参数必须和-a一起使用。 |
<!--RP1End-->

**命令行示例**：

```
Usage: hiperf record [options] [command [command-args]]
```

对指定的pid为267的进程采样10秒，并使用dwarf回栈。

```
$ hiperf record -p 267 -d 10 -s dwarf
```


## stat命令

监听用户指定的目标程序，周期性打印性能计数器的值。

**stat命令参数说明**

<!--RP2-->
| 参数 | 参数说明 | 
| -------- | -------- |
| -h/--help | 帮助命令。 | 
| -c | 设置采集的CPU ID，只采集对应的CPU数据。 | 
| -d | 采集时长，单位为s。该参数不能和--control一起使用。 | 
| -i | 设置打印stat信息的间隔时长，单位ms。 | 
| -e | 采集事件，支持采集多种事件，多个事件之间以逗号隔开。 | 
| -g | 采集事件群组，以逗号隔开。可通过list命令获取当前支持的事件类型。 | 
| --no-inherit | 不采集子进程数据。 | 
| -p | 采集进程ID，支持对多个进程进行采样，多个进程号之间以逗号隔开。该参数不能和-a一起使用。 | 
| -t | 采集线程ID，支持对多个线程进行采样，多个线程号之间以逗号隔开。该参数不能和-a一起使用。 | 
| --app | 采集的应用程序名，以逗号隔开。应用程序必须是启动状态，应用程序未启动时会等待20s，20s内应用程序未启动，命令会自动结束。该参数不能和-a一起使用。 | 
| --chkms | 设置查询的间隔时间，单位为毫秒，取值范围：1 - 200，默认10。 | 
| --per-core | 每个CPU核的打印计数。 | 
| --pre-thread | 每个线程的打印计数。 | 
| --restart | 收集应用启动的性能指标信息，如果进程在30秒内未启动，记录将退出。该参数必须和--app一起使用。 | 
| --verbose | 输出详细的信息。 | 
| --dumpoptions | 展示当前列表里所有选项的详细信息。 | 
| --control [command] | 采集操作启停控制参数。命令包括prepare/start/stop。该参数不能和-d一起使用。<br/>**说明**：从API version 20开始，支持该参数。 | 
| -o | 设置输出文件路径，默认路径以设备上运行 hiperf stat -h/--help 时显示的 -o 参数说明为准，并允许用户自定义文件名称。该参数必须和--control prepare一起使用，不能和--control一起使用。<br/>**说明**：从API version 20开始，支持该参数。 | 
| -a | 统计整机的性能数据。 |

**命令行示例**：

```
hiperf stat [options] [command [command-args]]
```

使用stat命令监听进程号为2349的进程在CPU 0上运行3秒的性能数据。

```
$ hiperf stat -p 1745 -d 3 -c 0
```


## dump命令

此命令用于将不同格式的性能数据文件（如perf.data）转换为内容易读的明文，便于开发和测试人员核对其中原始采样数据的正确性。

**dump命令参数说明**

| 参数 | 参数说明 | 
| -------- | -------- |
| -h/--help | 帮助命令。 | 
| --head | 仅输出数据头和属性。 | 
| -d | 仅输出数据段。 | 
| -f | 仅输出附加功能。 | 
| --sympath | 符号表文件路径。 | 
| -i | 采样文件的路径。 | 
| -o | 设置输出文件路径，现支持用户将输出文件路径设定为"/data/local/tmp/"目录，并允许用户自定义文件名称。若未设置该参数，数据将会输出到命令行界面。 | 
| --elf | 将elf格式的文件转换成内容可读的明文。 | 
| --proto | 将proto格式的文件转换成内容可读的明文。 | 
| --export | 将用户栈数据分割成多个文件。 | 

**命令行示例**：

```
Usage: hiperf dump [option] \<filename\>
```

使用dump命令将/data/local/tmp/perf.data文件读取出来，并输出到/data/local/tmp/perf.dump文件中。

```
$ hiperf dump -i /data/local/tmp/perf.data -o /data/local/tmp/perf.dump
```


## report命令

此命令主要用于将采样数据（perf.data）转换为用户指定的格式（例如Json或者ProtoBuf)，并可以将属于相同进程、线程、函数的样本分组到同一样本条目中，根据样本条目的事件计数对样本条目进行排序，并以报告的形式进行展示。

**report命令参数说明**

| 参数 | 参数说明 | 
| -------- | -------- |
| -h/--help | 帮助命令。 | 
| --symbol-dir | 符号表文件路径。 | 
| --limit-percent | 筛选性能占比不低于指定百分比（取值范围 1 - 100）的性能数据，仅在报告中保留并展示符合该阈值条件的数据条目。 | 
| -s | 显示回栈模式。 | 
| --call-stack-limit-percent | 展示指定比例的堆栈内容，取值范围：1 - 100。 | 
| -i | 资源文件路径，默认perf.data。 | 
| -o | 设置输出文件路径，现支持用户将输出文件路径设定为"/data/local/tmp/"目录，并允许用户自定义文件名称。若未设置该参数，数据将会输出到命令行界面。 | 
| --proto | 输出protobuf格式数据。 | 
| --json | 输出json格式数据。 | 
| --diff | 显示源文件与转换后文件的差别。不能与--proto、--json、-s参数一起使用。 | 
| --branch | 根据函数地址显示分支。 | 
| --&lt;keys&gt; &lt;keyname1&gt;[,keyname2][,...] | 可选关键字：comms、pids、tids、dsos、funcs、from_dsos、from_funcs，例如： --comms hiperf。 | 
| --sort [key1],[key2],[...] | 按关键字排序。 | 
| --hide_count | 报告中不显示数值。 | 
| --dumpoptions | 展示当前列表里所有选项的详细信息。 | 

**命令行示例**：

```
Usage: hiperf report [option] \<filename\>
```

从采样文件（perf.data）中提取对性能影响较大（占比≥1%）的关键数据，并以报告的形式进行展示。
```
$ hiperf report -i /data/local/tmp/perf.data --limit-percent 1
```
