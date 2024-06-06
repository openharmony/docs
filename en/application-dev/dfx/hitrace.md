# hitrace

The **HiTrace** module provides APIs to implement call chain tracing throughout a service process. With this module, you can quickly obtain the run log specific to the call chain of a service process and locate faults in inter-device, inter-process, or inter-thread communications.

## Prerequisites

- The [environment setup](hdc.md#environment-setup) is complete.

- The devices are properly connected.

## Command Description

| Command| Description|
| -------- | -------- |
| -h  | Shows help information. |
| -l | Shows the tag list. |
| --trace_begin | Starts capturing trace data.|
| --trace_finish | Stops capturing trace data.|
| --trace_dump | Dumps trace data to the specified position.|
| -b N | Sets the buffer size for trace data in KB. The default buffer size is 2048 KB.|
| -t N | Sets the trace uptime in seconds, which depends on the time required for analysis. The default value is 5 seconds.|
| -o | Outputs trace data to the specified file based on the file name (**stdout** by default).|
| -z | Compresses the trace data.|
| --trace_clock | Sets the type of the clock for adding a timestamp to a trace. The value can be **boot** (default), **global**, **mono**, **uptime**, or **perf**.|
| --trace_finish_nodump | Stops capturing trace packets without dumping trace data.|

## Examples

Run the following commands in the hdc shell:

1. Run the **hitrace -l** command to display the tag list.

   ![](figures/hitrace-l.png)

2. Run the **hitrace --trace_begin app** command to start capturing trace data with a specified tag.

   ![](figures/hitrace-begin-app.png)

3. Run the **hitrace --trace_finish** or **hitrace --trace_finish -o /data/local/tmp/test.htrace** command to stop capturing trace data. The former prints the captured trace data in the command-line window, and the latter outputs the data to the specified file.

   ![](figures/hitrace-finish.png)

4. Run the **hitrace -b 10240 -t 10 -o /data/local/tmp/test1.htrace app ability** command to capture trace data with the following settings.

   ![](figures/hitrace-b.png)

   - Buffer size: 10240 KB
   - Trace uptime: 10s
   - Output path: /data/local/tmp/test1.htrace
   - Tags: app and ability

5. Run the **hitrace --trace_dump** or **hitrace --trace_dump -o /data/local/tmp/test2.htrace** command to dump trace data. The former dumps trace data to the command-line window, and the latter the specified file.

   ![](figures/hitrace-dump.png)

   You can also run the **hitrace --trace_dump |grep \***\***\***** command todump trace data based on keywords.
