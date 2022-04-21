# bytrace使用指导


## 简介

bytrace是开发人员用于追踪进程轨迹、分析性能的一种工具，主要对内核ftrace进行了封装和扩展，来支持用户态的打点。通过该工具可以打开想要查看的用户态和内核label（通过下面命令行bytrace -l，查看支持的所有label），然后通过命令行进行抓取trace信息到指定文件中。


## 参数说明

bytrace当前支持以下命令:

  **表1** 命令行列表

| Option | Description |
| -------- | -------- |
| -h，--help | 查看option帮助 |
| -b&nbsp;_n_，--buffer_size&nbsp;_n_ | 指定_n_(KB)内存大小用于存取trace日志，默认2048KB |
| -t&nbsp;_n_，--time&nbsp;_n_ | 用来指定trace运行的时间（单位：s），取决于需要分析过程的时间 |
| --trace_clock&nbsp;_clock_ | trace输出的时钟类型，一般设备支持boot、global、mono、uptime、perf等，默认为boot |
| --trace_begin | 启动抓trace |
| --trace_dump | 将数据输出到指定位置（默认控制台） |
| --trace_finish | 停止抓trace，并将数据输出到指定位置（默认控制台） |
| -l，--list_categories | 输出手机能支持的trace模块 |
| --overwrite | 当缓冲区满的时候，将丢弃最新的信息。（默认丢弃最老的日志） |
| -o&nbsp;_filename_，--output&nbsp;_filename_ | 指定输出的目标文件名称 |
| -z | 抓取trace后进行压缩 |


## 使用实例

准备工作，使用bytrace工具需要先进入shell命令行：


```
hdc shell
```

以下是常用bytrace命令示例，供开发者参考：

- 查询支持的label。

```
bytrace -l  
```

或者


```
bytrace --list_categories
```

- 设置4M缓存，抓取10秒，抓取label为ability的trace信息。

```
bytrace -b 4096 -t 10 --overwrite ability > /data/mytrace.ftrace
```

- 设置trace的输出时钟为mono。

```
bytrace --trace_clock mono  -b 4096 -t 10 --overwrite ability > /data/mytrace.ftrace
```

- 抓取trace后进行压缩。

```
bytrace -z  -b 4096 -t 10 --overwrite ability > /data/mytrace.ftrace
```
