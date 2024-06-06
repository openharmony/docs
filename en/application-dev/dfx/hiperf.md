# hiperf

hiperf is a command-line debugging tool that helps you capture performance data of a specific program or the entire system, like the kernel's perf tool. hiperf can run on Windows, Linux, and macOS.

## Prerequisites

- The [environment setup](hdc.md#environment-setup) is complete.

- The devices are properly connected.

## Command Format

```
hiperf [options] COMMAND [args for command]
```

- [options]
  - Optional
  - Debugging commands, such as enabling the logging function.

- COMMAND
  - Mandatory
  - Name of a subfunction, such as list, recrod, stat, dump, and report.

- [args for command]
  - Parameters of the subfunction.

## Command Help

You can run the **--help** command to view help information.

```
hiperf --help
```

![](figures/hipref-help.png)

Run the following command to view the help information about a subfunction:

```
hiperf [command] --help
```

## list

The **list** command lists all the events supported by the device. The event names are used for the **-e** and **-g** options of the **stat** and **record** commands.

```
Usage: hiperf list [event type name]
```

Run the **help** command to query the supported event types.

```
hiperf list --help
```

![](figures/hipref-list-help.png)

List the hardware events supported by the device. The command also lists the events that are not supported by the device.

```
hiperf list hw
```

![](figures/hipref-list-hw.png)

## record

The **record** command samples the specified application and saves the sampling data to a file (**/data/local/tmp/perf.data** by default).

```
Usage: hiperf record [options] [command [command-args]] 
```

Sample all processes in the system for 3 seconds and display detailed log information.

```
hiperf record -d 3 -a --verbose
```

Sample the process whose PID is 267 for 10 seconds and use DWARF for backtracking.

```
hiperf record -p 267 -d 10 -s dwarf
```

![](figures/hipref-record-pid.png)

For more information about the command, view the help information.

```
hiperf record --help
```

## stat

The **stat** command monitors the specified application and periodically prints the values of performance counters.

```
Usage: hiperf stat [options] [command [command-args]]
```

Monitor the performance counter of process 2349 on CPU 0 for 3 seconds.

```
hiperf stat -p 2349 -d 3 -c 0
```

For more information about the command, view the help information.

```
hiperf stat --help
```

## dump

The **dump** command reads the **perf.data** file without processing it. You can then verify the correctness of the read data, that is, the raw sampling data.

```
Usage: hiperf dump [option] \<filename\>
```

Run the **dump** command to read the **/data/local/tmp/perf.data** file and export the read data to the **/data/local/tmp/perf.dump** file.

```
hiperf dump -i /data/local/tmp/perf.data -o /data/local/tmp/perf.dump
```

![](figures/hipref-dump.png)

For more information about the command, view the help information.

```
hiperf dump --help
```

## report

The **report** command displays the sampling data (read from **perf.data**) and converts it to the required format (for example, JSON or ProtoBuf).

```
Usage: hiperf dump [option] \<filename\>
```

Output a common report, with the minimum display percentage of 1%.

```
hiperf report --limit-percent 1
```

For more information about the command, view the help information.

```
hiperf report --help
```

## Scripts

Run scripts to perform sampling operations to generate flame graphs for data visualization. You can obtain the tool from the [developtools_hiperf](https://gitee.com/openharmony/developtools_hiperf/tree/master/script) repository.

1. Sampling

   Run **command_script.py** to sample data. This script is the packaging script of the **report** command.

   ```
   usage: command_script.py [-h]                         
                            (-app PACKAGE_NAME | -lp LOCAL_PROGRAM | -cmd CMD | -p [PID [PID ...]] | -t [TID [TID ...]] | -sw)
                            [-a ABILITY] [-r RECORD_OPTIONS] [-lib LOCAL_LIB_DIR]
                            [-o OUTPUT_PERF_DATA] [--not_hdc_root]
   ```

   Sample the **com.ohos.launch** package.

   ```
   python command_script.py -app com.ohos.launch
   ```

   Sample the hdcd process.

   ```
   python command_script.py -lp hdcd
   ```

2. Collecting Symbol Tables

   Run **recv_binary_cache.py** to collect symbol tables. The tool searches for the ELF in the specified paths based on the related files and libraries recorded in **perf.data** and their buildids.

   ```
   usage: recv_binary_cache.py [-h] [-i PERF_DATA] [-l LOCAL_LIB_DIR [LOCAL_LIB_DIR ...]]
   ```

   The following specifies two symbol table paths.

   ```
   python recv_binary_cache.py -l Z:\OHOS_MASTER\out\ohos-arm-release\lib.unstripped  Z:\OHOS_MASTER\out\ohos-arm-release\exe.unstripped
   ```

   The symbol table files will be copied to the **binary_cache** folder. The tool preferentially searches for the specified symbol table paths. If no path is specified, the tool copies the files in the device.

3. Generating a Flame Graph

   Run **make_report.py** to display the sampled data in an HTML page.

   ```
   usage: make_report.py [-h] [-i PERF_DATA] [-r REPORT_HTML]
   ```

   An HTML file is generated. The default file name is **hiperf_report.html**.

   ```
   python make_report.py -i perf.data
   ```
