# bytrace<a name="EN-US_TOPIC_0000001083359811"></a>

## Overview<a name="section11388623181619"></a>

bytrace is a tool for you to trace processes and analyze performance. It encapsulates and extends the kernel ftrace and supports event tracking in the user space. With bytrace, you can open a user-space or kernel-space label you want to view \(run the  **bytrace -l**  command to query all the supported labels\) and run the  **--trace\_begin**  and  **-o filename**  \(or  **--output filename**\) commands to capture traces and dump them to a specified file.

## How to Develop<a name="section1595564317164"></a>

bytrace supports the following commands:

**Table  1**  Commands

| Option | Description |
| -------- | -------- |
| -h, --help | Views the help text for bytrace. |
| -b&nbsp;_n_, --buffer_size&nbsp;_n_ | Sets the size of the buffer (KB) for storing and reading traces. The default buffer size is 2048 KB. |
| -t&nbsp;_n_, --time&nbsp;_n_ | Sets the bytrace uptime in seconds, which depends on the time required for analysis. |
| --trace_clock&nbsp;_clock_ | Sets the type of the clock for adding a timestamp to a trace, which can be **boot** (default), **global**, **mono**, **uptime**, or **perf**. |
| --trace_begin | Starts capturing traces. |
| --trace_dump | Dumps traces to a specified position (console where you run this command by default). |
| --trace_finish | Stops capturing traces and dumps traces to a specified position (console where you run this command by default). |
| -l, --list_categories | Lists the bytrace categories supported by the device. |
| --overwrite | Sets the action to take when the buffer is full. If this option is used, the latest traces are discarded; if this option is not used, the earliest traces are discarded (default). |
| -o&nbsp;_filename_, --output&nbsp;_filename_ | Outputs traces to a specified file. |
| -z | Compresses a captured trace. |

## Usage Example<a name="section667273201818"></a>

The following are some examples of bytrace commands:

-   Query supported labels.

```
bytrace -l  
```

Alternatively, run the following command to query the supported bytrace categories:

```
bytrace --list_categories
```

-   Capture traces whose label is ability, with the buffer size set to 4096 KB and bytrace uptime set to 10s.

```
bytrace -b 4096 -t 10 --overwrite ability > /data/mytrace.ftrace
```

-   Set the clock type for traces to  **mono**.

```
bytrace --trace_clock mono -b 4096 -t 10 --overwrite ability > /data/mytrace.ftrace
```

-   Compress the captured trace.

```
bytrace -z -b 4096 -t 10 --overwrite ability > /data/mytrace.ftrace
```

