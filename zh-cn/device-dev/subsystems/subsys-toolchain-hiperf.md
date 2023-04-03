# hiperf使用指导


hiperf是为开发人员提供性能采样分析的工具，基于内核perf机制进行的用户态能力的扩展，可以对指定的程序或者整个系统进行性能采样。


hiperf支持的命令有：list、stat、record、report等，可以通过hiperf -h进行查看。


下面对hiperf的常用命令进行详细说明：


## list 命令


### 参数说明

列出设备上支持的所有perf事件名称，事件名称用于 stat 和 record命令的 -e 和 -g 参数。

  
```
Usage: hiperf list [event type]
```

  | 参数 | 功能说明 | 
| -------- | -------- |
| hw | 列出支持的&nbsp;hardware&nbsp;事件（PMU支持） | 
| sw | 列出支持的&nbsp;software&nbsp;事件 | 
| tp | 列出支持&nbsp;tracepotint&nbsp;事件 | 
| cache | 列出支持的&nbsp;cache&nbsp;事件（PMU支持） | 
| raw | 列出支持的原始PMU事件 | 


### 使用示例

下面列出了设备支持的hardware事件，并且会提示哪些事件此设备不支持。

  
```
hiperf list hw
event not support hw-stalled-cycles-backend
event not support hw-stalled-cycles-frontend
event not support hw-ref-cpu-cycles

Supported events for hardware:
        hw-cpu-cycles
        hw-instructions
        hw-cache-references
        hw-cache-misses
        hw-branch-instructions
        hw-branch-misses
        hw-bus-cycles
```


## stat 命令


### 参数说明

  监听指定目标程序，周期性打印性能计数器的值。
  
```
Usage: hiperf stat [options]
       Collect performance counter information.
```


  | 参数 | 功能说明 | 
| -------- | -------- |
| -a | 采集监听整个系统的所有线程和默认的性能计数器的值。 | 
| -c | 指定cpu&nbsp;id，可以是0,1,2用逗号分隔。 | 
| -d&nbsp;&lt;_sec_&gt; | 指定监听的时间，单位为秒。 | 
| -i&nbsp;&lt;_ms_&gt; | 指定监听事件的间隔打印时间，单位毫秒。 | 
| -e | 指定监听的事件，可以通过list命令查看支持的所有事件，其中event:u&nbsp;或者&nbsp;:k&nbsp;表示限制事件为用户空间或者内核空间。 | 
| -g | 指定需要在同一组监听的事件，同一组事件会被放入同一个PMU监听。 | 
| --no-inherit | 不监听目标线程/进程启动的子线程。 | 
| -p | 指定需要监听的进程pid。 | 
| -t | 指定需要监听的线程tid。 | 
| --verbose | 显示详细的报告内容，包括一些原始的时间数据等等。 | 


### 使用示例

下面是通过 stat 监听整个系统3秒的示例：

  
```
hiperf stat -d 3 -a
this is root mode, perfEventParanoid assume as -1
Start Profiling...
Timeout exit (total 3009 ms)
                count                           name | comment                          | coverage
               132523         hw-branch-instructions | 15.750 M/sec                     | (100%)
                62554               hw-branch-misses | 47.202372% miss rate             | (100%)
              6994768                  hw-cpu-cycles | 0.832068 GHz                     | (100%)
              1237627                hw-instructions | 5.651758 cycles per instruction  | (100%)
                  248            sw-context-switches | 29.959 K/sec                     | (100%)
                    0                 sw-page-faults | 0.000 /sec                       | (100%)
              9402580                  sw-task-clock | 0.002758 cpus used               | (100%)
```


### 字段说明

  | 字段名 | 含义 | 
| -------- | -------- |
| count | 表示事件发生的次数。 | 
| name | 事件的名称，在&nbsp;list&nbsp;命令中可以看到所有支持的命令，hw&nbsp;和&nbsp;sw&nbsp;的前缀分别代表是hardware事件还是software事件。 | 
| comment | 一些经过计算的方便用户阅读的值。例如&nbsp;CPU&nbsp;的相对主频，千位进制换算等等。 | 
| coverage | 该事件在PMU中的&nbsp;enable&nbsp;百分比，受限于PMU数量，每次装载的PMU监听事件是有限的。 | 


## record 命令


### 参数说明

采样指定目标程序，并且将采样数据保存到指定的文件中（默认为perf.data）

  
```
Usage: hiperf record [options]
       Collect performance sampling information.
```

  | 参数 | 功能说明 | 
| -------- | -------- |
| -a | 对整个系统的所有进程和线程进行采样。 | 
| --exclude-hiperf | 不采样hiperf自身进程。 | 
| -c | 指定采样的cpu&nbsp;id。 | 
| --cpu-limit&nbsp;&lt;_percent_&gt; | 限定采样过程占用的CPU最大百分比。 | 
| -d&nbsp;&lt;sec&gt; | 指定采样时长，单位秒。 | 
| -f&nbsp;&lt;freq&gt; | 设置采样事件的触发频率，默认为4000。<br/>说明：该频率越高cpu负载会越高，但是数据采样会越多。 | 
| --period&nbsp;&lt;_num_&gt; | 设置采样事件触发周期，以次数为单位，即发生指定的次数后采样一次。 | 
| -e | 指定监听的事件，可以通过list命令查看支持的所有事件，其中event:u&nbsp;或者&nbsp;:k&nbsp;可以表示限制事件为用户空间或者内核空间。 | 
| -g | 指定需要在同一组监听的事件，同一组事件会被放入同一个PMU监听。 | 
| --no-inherit | 不监听目标线程或者进程启动的子线程。 | 
| -p | 指定需要监听的进程。 | 
| -t | 指定需要监听的线程。 | 
| --offcpu | 监听CPU调度事件，它等价于&nbsp;--period&nbsp;1&nbsp;-e&nbsp;sched:sched_switch&nbsp;事件。 | 
| -j&nbsp;&lt;_branch_filter1_&gt;[,_branch_filter2_]... | 监听分支预测事件。分支预测就是指令存在多个if&nbsp;else判定的情况下，CPU去预测下一步即将执行哪一条指令。 | 
| -s&nbsp;/&nbsp;--call-stack&nbsp;&lt;_fp&nbsp;\\|&nbsp;dwarf[,size]_&gt; | 设置用户栈的回栈方式，支持fp和dwarf两种方式。dwarf&nbsp;后面可以指定采样的用户堆栈大小，默认是&nbsp;65528。 | 
| --delay-unwind | 延迟回栈，等到采样结束再进行回栈。 | 
| --disable-unwind | 不进行回栈，用户的寄存器和堆栈数据会保存在perf.data中，供离线回栈使用。 | 
| --disable-callstack-expend | 默认会对回栈的调用栈信息进行合并扩展，此选项会关闭该功能。 | 
| --clockid&nbsp;&lt;_clock&nbsp;type_&gt; | 设置采样数据的时钟源，支持monotonic、boottime、realtime等。 | 
| --symbol-dir&nbsp;&lt;_dir_&gt; | 指定符号表路径，如果指定了回栈时会优先使用该路径下的符号表。 | 
| -m&nbsp;&lt;_mmap&nbsp;pages_&gt; | 指定缓存的大小，默认值为1024，以页为单位。参数需要为2的幂，范围为&nbsp;[2&nbsp;-&nbsp;1024]。<br/>说明：该值越高，事件丢失率会越低，但是内存占用会增大。 | 
| --app&nbsp;&lt;_package&nbsp;name_&gt; | 指定采样的目标应用的包名，默认超时等待时间为10秒。 | 
| --data-limit&nbsp;&lt;_SIZE[K\|M\|G]_&gt; | 指定采样结果的最大容量，支持K/M/G(B)为单位，默认无大小限制。 | 
| -o&nbsp;&lt;_output&nbsp;file&nbsp;name_&gt; | 指定采样数据结果文件名，默认为/data/local/tmp/perf.data。 | 
| -z | 启动压缩模式，在保存到文件的时候，会用gzip进行压缩。 | 
| --verbose | 采样的时候显示更详细的日志信息。 | 


### 使用示例

- 对全系统所有进程采样3秒，并且显示详细的日志信息
    
  ```
  hiperf record -d 3 -a --verbose
  ```

- 指定使用fp方式进行回栈
    
  ```
  hiperf record -s fp -d 3 -a
  ```

- 指定使用dwarf方式进行回栈
    
  ```
  hiperf record -s dwarf -d 3 -a
  ```

- 指定采样offcpu事件
    
  ```
  hiperf record --offcpu -s dwarf -d 3 -a
  ```

- 指定延迟回栈
    
  ```
  hiperf record -d 3 -s dwarf --delay-unwind -a
  ```

- 禁止回栈，此时会保存堆栈数据到perf.data文件
    
  ```
  hiperf record -d 3 -s dwarf --disable-unwind -a
  ```

- 指定追踪的包名，如果指定的包名对应的进程不存在则会延时等待10秒，超时后进程退出
    
  ```
  hiperf record -d 3 -s dwarf --app com.ohos.launch
  ```

- 指定对采样结果数据进行压缩保存
    
  ```
  hiperf record -z -s dwarf -d 3  -a
  ```


## report 命令


### 参数说明

此命令主要用于展示record中抓取的采样数据

  
```
Usage: hiperf report [option]     
       Report sampling information from perf.data.
```

  | 参数 | 功能说明 | 
| -------- | -------- |
| --symbol-dir&nbsp;&lt;_dir_&gt; | 指定符号表路径。 | 
| --limit-percent&nbsp;&lt;_number_&gt; | 指定展示结果的最低百分比（低于的不显示）。 | 
| -s&nbsp;/&nbsp;--call-stack | 指定该选项后结果数据中会包含详细的调用栈信息。 | 
| --call-stack-limit-percent&nbsp;&lt;_number_&gt; | 调用栈的百分比最小值（低于的不显示）。 | 
| --proto | 将输入的&nbsp;perf.data&nbsp;文件转换为&nbsp;proto&nbsp;格式，默认文件名为&nbsp;perf.proto。 | 
| --json | 将输入的&nbsp;perf.data&nbsp;文件转换为&nbsp;json&nbsp;格式，默认文件名为&nbsp;perf.json。 | 
| --branch | 按分支预测的结果地址来展示报告，而不是调用栈的IP地址。 | 
| --&lt;_keys_&gt;&nbsp;&lt;_keyname1_&gt;[,_keyname2_][,...] | 按给出的关键字来过滤展示报告，keys支持：comms、pids、tids等&nbsp;例如&nbsp;--comms&nbsp;hiperf,hilog&nbsp;表示仅显示进程/线程名称为&nbsp;hiperf或者hilog的记录条目。 | 
| --sort&nbsp;&lt;_key1_&gt;[,_key2_][,...] | 按照给出的关键字来排序和显示，支持：pid、tid、comm等，可以指定多个关键字。 | 
| -i&nbsp;&lt;_filename_&gt; | 指定输入的采样数据（默认为perf.data)。 | 
| -o&nbsp;&lt;_filename_&gt; | 指定输出的报告文件名。 | 


### 使用示例

- 输出采样数据的报告，默认读取perf.data文件
    
  ```
  hiperf report
  ```

  输出结果举例：

    
  ```
  Heating count    comm            pid  tid  dso                                func
   5.68%  15073949 hiperf_example_ 1085 1091 /system/lib/ld-musl-arm.so.1       malloc
   2.57%   6834119 hiperf_example_ 1085 1091 [kernel.kallsyms]                  vector_swi
   2.27%   6013910 hiperf_example_ 1085 1087 /system/lib/ld-musl-arm.so.1       malloc
   2.19%   5805738 hiperf_example_ 1085 1091 /system/lib/ld-musl-arm.so.1       vfprintf
   2.09%   5543362 hiperf_example_ 1085 1091 [kernel.kallsyms]                  ktime_get_ts64
  report done
  ```

- 输出采集数据的调用栈报告
    
  ```
  hiperf report -s
  ```

- 指定符号表路径
    
  ```
  hiperf report -s --symbol-dir /data/local/tmp
  ```

- 指定结果过滤的关键字，指定后会只显示包含该关键字的信息。比如过滤libutils.z.so则命令如下：
    
  ```
  hiperf report --dsos libuitls.z.so
  ```

- 指定按照特定的关键字进行排序展示，比如按照dso进行排序：
    
  ```
  hiperf report --sort dso
  ```
