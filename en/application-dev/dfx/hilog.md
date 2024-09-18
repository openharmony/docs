# hilog


HiLog is a log system that provides logging for the system framework, services, and applications to record information on user operations and system running status. You can run the hilog commands to query related log information.


## Prerequisites

- The environment for OpenHarmony Device Connector (hdc) has been set up. For details, see [Environment Setup](hdc.md#environment-setup).

- The devices are properly connected.


## Commands

The table below lists the available **hilog** command line options.

| Short Option | Long Option | Parameter | Description | 
| -------- | -------- | -------- | -------- |
| -h | --help |  | Shows help information. | 
| Default | Default |  | Performs a blocking read on logs, with no exiting after the read finishes. | 
| -x | --exit |  | Performs a non-blocking read on logs, with exiting after the read finishes. | 
| -g |  |  | Checks the buffer size for logs of a specified type. This option is used together with **-t**, which specifies a log type. By default, the **app** or **core** types are used. | 
| -G | --buffer-size | &lt;size&gt; | Sets the size of the buffer for logs of a specified type. This option is used together with **-t**, which specifies a log type. By default, the **app** or **core** types are used. The unit can be B, KB, MB, or GB. | 
| -r |  |  | Clears the buffer for logs of a specified type. This option is used together with **-t**, which specifies a log type. By default, the **app** or **core** types are used. | 
| <!--DelRow-->-p | --privacy | &lt;on/off&gt; | Specifies whether to enable privacy for logs during system debugging. | 
| <!--DelRow--> |  | on | Enables privacy so that parameters are displayed as **\<private>** in printed logs. | 
| <!--DelRow--> |  | off | Disables privacy so that parameters are displayed as they are in printed logs. | 
| -k |  | &lt;on/off&gt; | Specifies whether to enable kernel logging. | 
|  |  | on | Enables kernel logging. | 
|  |  | off | Disables kernel logging. | 
| -s | --statistics |  | Shows statistics. This option must be used together with **-t** or **-D**. | 
| -S |  |  | Clears statistics. This option must be used together with **-t** or **-D**. | 
| -Q |  | &lt;control-type&gt; | Specifies whether to enable the default quota for flow control. | 
|  |  | pidon | Enables process flow control. | 
|  |  | pidoff | Disables process flow control. | 
|  |  | domainon | Enables domain flow control. | 
|  |  | domainoff | Disables domain flow control. | 
| -L | --level | &lt;level&gt; | Sets the log level, for example, **-L D/I/W/E/F**. | 
| -t | --type | &lt;type&gt; | Sets the log type, for example, **-t app core init**. | 
| -D | --domain | &lt;domain&gt; | Sets the domain. | 
| -T | --Tag | &lt;tag&gt; | Sets the tag. | 
| -a | --head | &lt;n&gt; | Shows the first several lines of logs.The parameter **\<n>** indicates the number of first lines to show. | 
| -z | --tail | &lt;n&gt; | Shows the last several lines of logs.The parameter **\<n>** indicates the number of last lines to show. | 
| -P | --pid | &lt;pid&gt; | Identifies a process. | 
| -e | --regex | &lt;expr&gt; | Prints only the lines of logs that match the regular expression specified through **\<expr>**. | 
| -f | --filename | &lt;filename&gt; | Sets the names of the files to be flushed to disk. | 
| -l | --length | &lt;length&gt; | Sets the size of the files to be flushed to disk. The value must be greater than or equal to 64 KB. | 
| -n | --number | &lt;number&gt; | Sets the number of files to be flushed to disk. | 
| -j | --jobid | &lt;jobid&gt; | Sets the ID of a flushing task. | 
| -w | --write | &lt;control&gt; | Controls a flushing task. | 
|  |  | query | Queries flushing tasks. | 
|  |  | start | Starts a flushing task. The command line parameters are the file name, size of a single file, flushing mode, and number of rotated files. | 
|  |  | stop | Stops a flushing task. | 
| -m | --stream | &lt;algorithm&gt; | Sets the flushing mode. | 
|  |  | none | Indicates that data is flushed to disks in non-compression mode. | 
|  |  | zlib | Indicates that data is flushed to disks using the zlib compression algorithm. The flushed file is in .gz format. | 
|  |  | zstd | Indicates that data is flushed to disks using the zstd compression algorithm. The flushed file is in .zst format. | 
| -v | --format | &lt;format&gt; |  | 
|  |  | time | Displays the local time. | 
|  |  | color | Adds colors to logs at different levels. By default, logs are displayed in black and white. | 
|  |  | epoch | Displays the amount of time elapsed since the epoch time. | 
|  |  | monotonic | Displays the amount of time elapsed since the system startup time. | 
|  |  | usec | Displays the time in microseconds. | 
|  |  | nsec | Displays the time in nanoseconds. | 
|  |  | year | Displays the time with the year portion. | 
|  |  | zone | Displays the time with the local time zone. | 
| -b | --baselevel | &lt;loglevel&gt; | Sets the lowest level of logs that can be printed: D(DEBUG)/I(INFO)/W(WARN)/E(ERROR)/F(FATAL). | 


### Query Related Commands

| Short Option | Long Option | Description | 
| -------- | -------- | -------- |
| -h | --help | Displays the help information about the **hilog** commands. | 


### Time Related Commands

| Short Option | Long Option | Parameter | Description | 
| -------- | -------- | -------- | -------- |
| -v | --format | &lt;format&gt; | Sets the time format. | 

**Parameters**

| Name | Description | 
| -------- | -------- |
| time | Displays the local time. | 
| color | Adds colors to logs at different levels. By default, logs are displayed in black and white. | 
| epoch | Displays the amount of time elapsed since the epoch time. | 
| monotonic | Displays the amount of time elapsed since the system startup time. | 
| usec | Displays the time in microseconds. | 
| nsec | Displays the time in nanoseconds. | 
| year | Displays the time with the year portion. | 
| zone | Displays the time with the local time zone. | 
