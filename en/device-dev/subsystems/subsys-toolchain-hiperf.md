# hiperf


hiperf is a performance sampling and analysis tool provided for developers. It extends the user-mode capabilities based on the kernel perf mechanism and can conduct performance sampling of the specified application or the entire system.


You can run the **hiperf -h** command to display the commands supported by hiperf.


The following describes the common commands (**list**, **stat**, **record**, and **report**) supported by hiperf.


## list


### Parameters

The **list** command lists all the perf events supported by the device. The event names are used for the **-e** and **-g** parameters of the **stat** and **record** commands.


```
hiperf list [event type]
```

| Parameter| Description|
| -------- | -------- |
| hw | Lists the hardware events supported by the performance monitoring unit (PMU).|
| sw | Lists the software events supported. |
| tp | Lists the tracepotint events supported. |
| cache | Lists the cache events supported by the PMU. |
| raw | Lists the raw PMU events supported.|


### Example

List the hardware events supported by the PMU. The command also lists the events that are not supported by the PMU.


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


## stat


### Parameters

  The **stat** command monitors the specified application and periodically prints the values of performance counters.

```
hiperf stat [options]
Collect performance counter information.
```


| Parameter| Description|
| -------- | -------- |
| -a | Collects the values of all threads and default performance counters of the system.|
| -c | Specifies the IDs of the CPUs to monitor. Use commas (,) to separate multiple CPU IDs, for example **0,1,2**. |
| -d&nbsp;&lt;_sec_&gt; | Specifies the monitoring period, in seconds. |
| -i&nbsp;&lt;_ms_&gt; | Specifies the interval for printing the monitored events, in milliseconds. |
| -e | Specifies the events to monitor. You can run the **list** command to list all the events supported. **event:u** indicates an event in the user space, and **event:k** indicates an event in the kernel space. |
| -g | Specifies a group of events to monitor. The events in the same group are monitored by the same PMU.|
| --no-inherit | Leaves the sub-threads of the target thread or process not monitored.|
| -p | Specifies the process IDs (PIDs) to monitor.|
| -t | Specifies the thread IDs (TIDs) to monitor.|
| --verbose | Displays detailed report, including raw time data.|


### Example

Monitor the entire system for 3 seconds.


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


### Field Description

| Field| Description|
| -------- | -------- |
| count | Indicates the times that an event occurred.|
| name | Indicates the event name. You can run the **list** command to list all the supported events. **hw** stands for hardware, and **sw** for software. |
| comment | Provides values calculated from those in the **Count** column for easy understanding. For example, the CPU frequency (**hw-cpu-cycles**) is converted to **0.832068** GHz from **6994768**. |
| coverage | Indicates the percentage of PMU resources occupied by the event. The number of events to be monitored by a PMU varies depending on the number of PMUs.|


## record


### Parameters

The **record** command samples the specified application and saves the sampling data to a file (**perf.data** by default).


```
hiperf record [options]
Collect performance sampling information.
```

| Parameter| Description|
| -------- | -------- |
| -a | Samples all processes and threads in the system.|
| --exclude-hiperf | Leaves the hiperf process not sampled.|
| -c | Specifies the IDs of the CPUs to sample.|
| --cpu-limit&nbsp;&lt;_percent_&gt; | Specifies the maximum percentage of CPU resources occupied by the sampling. |
| -d&nbsp;&lt;sec&gt; | Specifies the sampling duration, in seconds.|
| -f&nbsp;&lt;freq&gt; | Specifies how often a sampling event is triggered. The default value is 4000 times/second.<br>Note: A higher value indicates heavier CPU load but more sampling data.|
| --period&nbsp;&lt;_num_&gt; | Specifies the number of occurrence times of an event that triggers a sampling. That is, a sampling is performed once when the event occurs the specified number of times. |
| -e | Specifies the events to monitor. You can run the **list** command to list all the events supported. **event:u** indicates an event in the user space, and **event:k** indicates an event in the kernel space.|
| -g | Specifies a group of events to monitor. The events in the same group are monitored by the same PMU.|
| --no-inherit | Leaves the sub-threads of the target thread or process not monitored.|
| -p | Specifies the processes to monitor.|
| -t | Specifies the threads to monitor.|
| --offcpu | Monitors the CPU scheduling event, which is equivalent to the **--period 1 -e sched:sched_switch** event.|
| -j&nbsp;&lt;_branch_filter1_&gt;[,_branch_filter2_]... | Monitors the branch prediction events. Branch prediction tries to predict the next instruction to be executed if there are multiple if else conditions. |
| -s&nbsp;/&nbsp;--call-stack&nbsp;&lt;_fp&nbsp;\\|&nbsp;dwarf[,size]_&gt; | Sets the user stack unwinding mode, which can be **fp** or **dwarf**. If **dwarf** is used, you can specify the size of the user stack to be sampled. The default value is **65528**. |
| --delay-unwind | Delays the stack unwinding till the sampling is complete.|
| --disable-unwind | Disables stack unwinding. The user register and stack data is stored in **perf.data** for offline stack unwinding.|
| --disable-callstack-expend | Disables the unwound call stack information from being combined or extended.|
| --clockid&nbsp;&lt;_clock&nbsp;type_&gt; | Sets the clock source for the sampling data. The options are **monotonic**, **boottime**, and **realtime**. |
| --symbol-dir&nbsp;&lt;_dir_&gt; | Specifies the directory of the symbol table. The specified symbol table will be preferentially used in stack unwinding. |
| -m&nbsp;&lt;_mmap&nbsp;pages_&gt; | Specifies the cache size, in pages. The default value is **1024**. The parameter value must be a power of 2. The value range is [2 - 1024].<br>Note: <br>A higher value indicates a lower event loss rate but higher memory usage. |
| --app&nbsp;&lt;_package&nbsp;name_&gt; | Specifies the bundle name of the target application to be sampled. The default timeout interval is 10 seconds. If the specified application does not exist, the hiperf process exits after 10 seconds. |
| --data-limit&nbsp;&lt;_SIZE[K\|M\|G]_&gt; | Specifies the maximum size of the sampling result, in KB, MB, or GB. By default, there is no limit on the size.|
| -o&nbsp;&lt;_output&nbsp;file&nbsp;name_&gt; | Specifies the name of the sampling result file. It is **/data/local/tmp/perf.data** by default. |
| -z | Saves the output file in .gzip format.|
| --verbose | Displays detailed log information during sampling.|


### Example

- Sample all processes in the system for 3 seconds and display detailed log information during the sampling process.
  
  ```
  hiperf record -d 3 -a --verbose
  ```

- Enable stack unwinding in fp mode.
  
  ```
  hiperf record -s fp -d 3 -a
  ```

- Enable stack unwinding in dwarf mode.
  
  ```
  hiperf record -s dwarf -d 3 -a
  ```

- Sample offcpu events.
  
  ```
  hiperf record --offcpu -s dwarf -d 3 -a
  ```

- Delay stack unwinding.
  
  ```
  hiperf record -d 3 -s dwarf --delay-unwind -a
  ```

- Disable stack unwinding. In this case, the stack data is saved to the **perf.data** file.
  
  ```
  hiperf record -d 3 -s dwarf --disable-unwind -a
  ```

- Monitor the **com.ohos.launch** application. The hiperf process exits after 10 seconds if the process corresponding to the specified bundle name does not exist.
  
  ```
  hiperf record -d 3 -s dwarf --app com.ohos.launch
  ```

- Compress the sampling results.
  
  ```
  hiperf record -z -s dwarf -d 3  -a
  ```


## report


### Parameters

The  **report**  command displays the sampling data that is captured by using  **record**.


```
hiperf report [option]     
Report sampling information from perf.data.
```

| Parameter| Description|
| -------- | -------- |
| --symbol-dir&nbsp;&lt;_dir_&gt; | Specifies the directory of the symbol table. |
| --limit-percent&nbsp;&lt;_number_&gt; | Specifies the minimum percentage of the result to display. The result that is lower than the minimum percentage is not displayed. |
| -s&nbsp;/&nbsp;--call-stack | Displays detailed call stack information.|
| --call-stack-limit-percent&nbsp;&lt;_number_&gt; | Specifies the minimum percentage of the call stack to display. The call stack that is lower than the minimum percentage is not displayed. |
| --proto | Converts the **perf.data** file into the proto format. The default file name is **perf.proto**. |
| --json | Converts the **perf.data** file into the JSON format. The default file name is **perf.json**. |
| --branch | Displays the report based on the branch prediction result address instead of the IP address of the call stack.|
| --&lt;_keys_&gt;&nbsp;&lt;_keyname1_&gt;[,_keyname2_][,...] | Filters and displays reports based on the given keywords. **keys** supports **comms**, **pids**, and **tids**. For example, **--comms hiperf,hilog** displays only the records whose process or thread name is **hiperf** or **hilog**.|
| --sort&nbsp;&lt;_key1_&gt;[,_key2_][,...] | Sorts and displays information based on specified keywords, such as **pid**, **tid**, and **comm**. Multiple keywords can be specified. |
| -i&nbsp;&lt;_filename_&gt; | Specifies the sampling data (**perf.data** by default). |
| -o&nbsp;&lt;_filename_&gt; | Specifies the name of the report to output. |


### Example

- Output the report of the sampling data (perf.data by default).
  
  ```
  hiperf report
  ```

  Output (example):

  
  ```
  Heating count    comm            pid  tid  dso                                func
   5.68%  15073949 hiperf_example_ 1085 1091 /system/lib/ld-musl-arm.so.1       malloc
   2.57%   6834119 hiperf_example_ 1085 1091 [kernel.kallsyms]                  vector_swi
   2.27%   6013910 hiperf_example_ 1085 1087 /system/lib/ld-musl-arm.so.1       malloc
   2.19%   5805738 hiperf_example_ 1085 1091 /system/lib/ld-musl-arm.so.1       vfprintf
   2.09%   5543362 hiperf_example_ 1085 1091 [kernel.kallsyms]                  ktime_get_ts64
  report done
  ```

- Output the call stack report of the sampling data.
  
  ```
  hiperf report -s
  ```

  
  
- Set the symbol table directory.
  
  ```
  hiperf report -s --symbol-dir /data/local/tmp
  ```

  

- Display only the information containing  **libutils.z.so**.
  
  ```
  hiperf report --dsos libuitls.z.so
  ```

  
  
- Sort the result by  **dso**.
  
  ```
  hiperf report --sort dso
  ```
