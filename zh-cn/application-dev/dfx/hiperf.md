# hiperf

hiperf为开发人员提供用于调试的命令行工具，用于抓取特定程序或者系统的性能数据，类似内核的perf工具，该工具支持在 Windows/Linux/Mac 等操作系统上运行。

## 前置条件

- 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)。

- 正常连接设备。

## 命令格式

```
hiperf [options] COMMAND [args for command]
```

- [options]
  - 可选的参数。
  - 主要是一些调试命令,如打开log等。

- COMMAND
  - 必选参数。
  - 子功能的名字,如list,recrod,stat,dump,report 等等。

- [args for command]
  - 子功能的参数。

## 命令帮助

可用 --help 查看帮助。

```
hiperf --help
```

![](figures/hipref-help.png)

使用如下命令查看子功能的帮助信息。

```
hiperf [command] --help
```

## list命令

可列出设备上支持的所有事件名称，事件名称用于 stat 和 record 的 -e 和 -g 参数。

```
Usage: hiperf list [event type name]
```

使用help命令查询支持的事件类型。

```
hiperf list --help
```

![](figures/hipref-list-help.png)

下面列出了设备支持的HW事件，并且会提示哪些事件此设备不支持。

```
hiperf list hw
```

![](figures/hipref-list-hw.png)

## record命令

采样指定目标程序，并且将采样数据保存到指定的文件中(默认为/data/local/tmp/perf.data)。

```
Usage: hiperf record [options] [command [command-args]] 
```

对指定的PID为267的进程采样10秒，并且使用dwarf回栈。

```
hiperf record -p 267 -d 10 -s dwarf
```

![](figures/hipref-record-pid.png)

更多详细信息请参考命令帮助。

```
hiperf record --help
```

## stat命令

监听指定目标程序，周期性打印性能计数器的值。

```
Usage: hiperf stat [options] [command [command-args]]
```

下面展示了一个 stats 监听2349进程在CPU0上3秒的性能计数器命令。

```
hiperf stat -p 2349 -d 3 -c 0
```

更多详细信息请参考命令帮助。

```
hiperf stat --help
```

## dump命令

此命令主要以不加以处理的方式直接读取perf.data的数据，开发和测试人员可核对其中原始采样数据的正确性。

```
Usage: hiperf dump [option] \<filename\>
```

使用dump命令将/data/local/tmp/perf.data文件读取出来，输出到/data/local/tmp/perf.dump文件中。

```
hiperf dump -i /data/local/tmp/perf.data -o /data/local/tmp/perf.dump
```

![](figures/hipref-dump.png)

更多详细信息请参考命令帮助。

```
hiperf dump --help
```

## report命令

此命令主要用于展示相关采样数据（从perf.data中读取）并且转换为用户需要的格式（比如Json或者ProtoBuf）。

```
Usage: hiperf report [option] \<filename\>
```

范例输出普通报告的命令，限制为占比不超过1%。

```
hiperf report --limit-percent 1
```

更多详细信息请参考命令帮助。

```
hiperf report --help
```

## 脚本

一般用户用脚本执行采样操作，可生成可视化的火焰图。工具可在[developtools_hiperf仓库](https://gitee.com/openharmony/developtools_hiperf/tree/master/script)中获取。

1. 采样。

   由 command_script.py 完成，它是 report 命令的包装脚本。

   ```
   usage: command_script.py [-h]                         
                            (-app PACKAGE_NAME | -lp LOCAL_PROGRAM | -cmd CMD | -p [PID [PID ...]] | -t [TID [TID ...]] | -sw)
                            [-a ABILITY] [-r RECORD_OPTIONS] [-lib LOCAL_LIB_DIR]
                            [-o OUTPUT_PERF_DATA] [--not_hdc_root]
   ```

   对指定包名采样，包名是 com.ohos.launch。

   ```
   python command_script.py -app com.ohos.launch
   ```

   对特定进程采样，进程名称是 hdcd。

   ```
   python command_script.py -lp hdcd
   ```

2. 收集符号表。

   由 recv_binary_cache.py 完成，它主要根据 perf.data 里面记录的相关文件和库以及它们的 buildid， 在用户指定的路径中去寻找对应的 ELF 作为符号表文件用于回栈或者打印函数名等。

   ```
   usage: recv_binary_cache.py [-h] [-i PERF_DATA] [-l LOCAL_LIB_DIR [LOCAL_LIB_DIR ...]]
   ```

   指定了2个符号表路径的位置。

   ```
   python recv_binary_cache.py -l Z:\OHOS_MASTER\out\ohos-arm-release\lib.unstripped  Z:\OHOS_MASTER\out\ohos-arm-release\exe.unstripped
   ```

   对应的符号表文件会复制到 binary_cache 文件夹，优先检查用户给出的符号表位置，如果没有则复制设备中的文件。

3. 生成火焰图。

   由 make_report.py 完成，将采样后的数据导出为HTML展示页面。

   ```
   usage: make_report.py [-h] [-i PERF_DATA] [-r REPORT_HTML]
   ```

   产生HTML文件，默认的文件名是 hiperf_report.html。

   ```
   python make_report.py -i perf.data
   ```
