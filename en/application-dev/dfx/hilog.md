# hilog


HiLog is a log system that provides logging for the system framework, services, and applications to record information on user operations and system running status. You can run the hilog commands to query related log information.


## Prerequisites

- The environment for OpenHarmony Device Connector (hdc) has been set up. For details, see [Environment Setup](hdc.md#environment-setup).

- The devices are properly connected.


## Commands

The table below lists the available **hilog** command line options.

| Short Option| Long Option| Parameter| Description| 
| -------- | -------- | -------- | -------- |
| -h | --help |  | Shows help information.| 
| Default| Default|  | Performs a blocking read on logs, with no exiting after the read finishes.| 
| -x | --exit |  | Performs a non-blocking read on logs, with exiting after the read finishes.| 
| -g |  |  | Checks the buffer size for logs of a specified type. This option is used together with **-t**, which specifies a log type. By default, the **app** or **core** types are used.| 
| -G | --buffer-size | &lt;size&gt; | Sets the size of the buffer for logs of a specified type. This option is used together with **-t**, which specifies a log type. By default, the **app** or **core** types are used. The unit can be B, KB, MB, or GB. The value ranges from 64 KB to 16 MB.| 
| -r |  |  | Clears the buffer for logs of a specified type. This option is used together with **-t**, which specifies a log type. By default, the **app** or **core** types are used.| 
| <!--DelRow-->-p | --privacy | &lt;on/off&gt; | Specifies whether to enable privacy for logs during system debugging.| 
| <!--DelRow--> |  | on | Enables privacy so that parameters are displayed as **\<private>** in printed logs.| 
| <!--DelRow--> |  | off | Disables privacy so that parameters are displayed as they are in printed logs.| 
| -k |  | &lt;on/off&gt; | Specifies whether to enable kernel logging.| 
|  |  | on | Enables kernel logging.| 
|  |  | off | Disables kernel logging.| 
| -s | --statistics |  | Shows statistics. This option must be used together with **-t** or **-D**.| 
| -S |  |  | Clears statistics. This option must be used together with **-t** or **-D**.| 
| -Q |  | &lt;control-type&gt; | Specifies whether to enable the default quota for flow control.| 
|  |  | pidon | Enables process flow control.| 
|  |  | pidoff | Disables process flow control.| 
|  |  | domainon | Enables domain flow control.| 
|  |  | domainoff | Disables domain flow control.| 
| -L | --level | &lt;level&gt; | Sets the log level, for example, **-L D/I/W/E/F**.| 
| -t | --type | &lt;type&gt; | Sets the log type, for example, **-t app core init**.| 
| -D | --domain | &lt;domain&gt; | Sets the domain.| 
| -T | --tag | &lt;tag&gt; | Sets the tag.| 
| -a | --head | &lt;n&gt; | Shows the first several lines of logs.The parameter **\<n>** indicates the number of first lines to show.| 
| -z | --tail | &lt;n&gt; | Shows the last several lines of logs.The parameter **\<n>** indicates the number of last lines to show.| 
| -P | --pid | &lt;pid&gt; | Identifies a process.| 
| -e | --regex | &lt;expr&gt; | Prints only the lines of logs that match the regular expression specified through **\<expr>**.| 
| -f | --filename | &lt;filename&gt; | Sets the names of the files to be flushed to disk.| 
| -l | --length | &lt;length&gt; | Sets the size of the files to be flushed to disk. The value must be greater than or equal to 64 KB.| 
| -n | --number | &lt;number&gt; | Sets the number of files to be flushed to disk.| 
| -j | --jobid | &lt;jobid&gt; | Sets the ID of a flushing task.| 
| -w | --write | &lt;control&gt; | Controls a flushing task.| 
|  |  | query | Queries flushing tasks.| 
|  |  | start | Starts a flushing task. The command line parameters are the file name, size of a single file, flushing mode, and number of rotated files.| 
|  |  | stop | Stops a flushing task.|
|  |  | refresh | Refreshes the logs in the buffer to the flushed file.|
|  |  | clear | Deletes log files that are flushed to disks.| 
| -m | --stream | &lt;algorithm&gt; | Sets the flushing mode.| 
|  |  | none | Indicates that data is flushed to disks in non-compression mode.| 
|  |  | zlib | Indicates that data is flushed to disks using the zlib compression algorithm. The flushed file is in .gz format.| 
|  |  | zstd | Indicates that data is flushed to disks using the zstd compression algorithm. The flushed file is in .zst format.| 
| -v | --format | &lt;format&gt; |  | 
|  |  | time | Displays the local time.| 
|  |  | color | Adds colors to logs at different levels. By default, logs are displayed in black and white.| 
|  |  | epoch | Displays the amount of time elapsed since the epoch time.| 
|  |  | monotonic | Displays the amount of time elapsed since the system startup time.| 
|  |  | usec | Displays the time in microseconds.| 
|  |  | nsec | Displays the time in nanoseconds.| 
|  |  | year | Displays the time with the year portion.| 
|  |  | zone | Displays the time with the local time zone.| 
| -b | --baselevel | &lt;loglevel&gt; | Sets the lowest level of logs that can be printed: D(DEBUG)/I(INFO)/W(WARN)/E(ERROR)/F(FATAL).| 

## Examples

### Display the help information.

   ```
   hilog -h
   ```

   **Example**

   ```
    $ hilog -h
    Usage:
    -h --help
      Show all help information.
      Show single help information with option:
      query/clear/buffer/stats/persist/private/kmsg/flowcontrol/baselevel/domain/combo
    Querying logs options:
      No option performs a blocking read and keeps printing.
      -x --exit
        Performs a non-blocking read and exits when all logs in buffer are printed.
      -a <n>, --head=<n>
        Show n lines logs on head of buffer.
      -z <n>, --tail=<n>
        Show n lines logs on tail of buffer.
   ```

### Display the size of the log buffer.

   ```
   hilog -g
   ```

   **Example**

   ```
   $ hilog -g
   Log type app buffer size is 16.0M
   Log type init buffer size is 16.0M
   Log type core buffer size is 16.0M
   Log type only_prerelease buffer size is 16.0M
   ```

### Change the size of the log buffer.

   ```
   hilog -G size
   ```

   **Example**
   ```
   $ hilog -G 16M
   Set log type app buffer size to 16.0M successfully
   Set log type init buffer size to 16.0M successfully
   Set log type core buffer size to 16.0M successfully
   Set log type only_prerelease buffer size to 16.0M successfully
   ```

### Enable/Disable process flow control.

   ```
   hilog -Q pidon/pidoff
   ```
   

   **Example**

   ```
   $ hilog -Q pidon
   Set flow control by process to enabled successfully
   $
   $ hilog -Q pidoff
   Set flow control by process to disabled successfully
   ```

### Enable/Disable domain flow control.

   ```
   hilog -Q domainon/domainoff
   ```

   **Example**

   ```
   $ hilog -Q domainon
   Set flow control by domain to enabled successfully
   $
   $ hilog -Q domainoff
   Set flow control by domain to disabled successfully
   ```

### Display logs of a specified level.

   ```
   hilog -L D/I/W/E/F
   ```

   **Example**

   ```
   $ hilog -L E
   08-28 09:01:25.730  2678  2678 E A00F00/com.huawei.hmos.aidataservice/AiDataService_5.10.7.320: DataChangeNotifyManager: notifyDataChange CommonEntity no valid entity to notify
   08-28 09:01:56.058  8560  8560 E A00500/com.ohos.settingsdata/SettingsData: DB not ready request = datashare:///com.ohos.settingsdata/entry/settingsdata/SETTINGSDATA?Proxy=true&key=analysis_service_switch_on , retry after DB startup
   08-28 09:01:56.082  8560  8560 E A00500/com.ohos.settingsdata/SettingsData: decoder failure: /data/migrate/settings_global.xml , error code:-1
   08-28 09:01:56.082  8560  8560 E A00500/com.ohos.settingsdata/SettingsData: clearXml failed:No such file or directory, error code:13900002
   08-28 09:01:56.083  8560  8560 E A00500/com.ohos.settingsdata/SettingsData: readText failed:No such file or directory, error code:13900002
   08-28 09:01:56.371  8586  8586 E A00500/com.ohos.settingsdata/SettingsData: DB not ready request =    datashare:///com.ohos.settingsdata/entry/settingsdata/SETTINGSDATA?Proxy=true&key=photo_network_connection_status , retry after DB startup
   08-28 09:01:56.408  8586  8586 E A00500/com.ohos.settingsdata/SettingsData: decoder failure: /data/migrate/settings_global.xml , error code:-1
   ```

### Display logs of a specified tag.

   ```
   hilog -T tag
   ```

   **Example**

   ```
   $ hilog -T SAMGR
   08-28 09:27:59.581   610 11504 I C01800/samgr/SAMGR: CommonEventCollect save extraData 1661
   08-28 09:27:59.581   610 11504 I C01800/samgr/SAMGR: OnReceiveEvent get action: usual.event.BATTERY_CHANGED code: 0, extraDataId 1661
   08-28 09:27:59.582   610 11504 I C01800/samgr/SAMGR: DoEvent:4 name:usual.event.BATTERY_CHANGED value:0
   08-28 09:27:59.582   610 11504 W C01800/samgr/SAMGR: LoadSa SA:10120 AddDeath fail,cnt:1,callpid:610
   08-28 09:27:59.583   610 11504 I C01800/samgr/SAMGR: LoadSa SA:10120 size:1,count:1
   08-28 09:27:59.601   610 11504 I C01800/samgr/SAMGR: Scheduler SA:10120 loading
   08-28 09:27:59.965 11518 11518 I C01800/media_analysis_service/SAMGR: SA:10120 OpenSo spend 315ms
   08-28 09:27:59.965   610  4064 I C01800/samgr/SAMGR: AddProc:media_analysis_service. size:75
   ```

### Display logs of a specified process.

   ```
   hilog -P pid
   ```

   **Example**

   ```
   $ hilog -P 618
   08-28 10:19:16.872   618 17729 I C02D15/hiview/XPower: [task_52]#current system load is: 0.028767
   08-28 10:19:23.997   618 17580 I C02D10/hiview/CpuCollector: CalculateProcessCpuStatInfos: startTime=1724811553746, endTime=1724811563996, startBootTime=47001084, endBootTime=47011335, period=10251
   08-28 10:19:23.999   618 17580 I C02D10/hiview/CpuCollector: CollectProcessCpuStatInfos: collect process cpu statistics information size=234, isNeedUpdate=1
   08-28 10:19:24.002   618 17580 W C01650/hiview/Rdb:  DB :
   08-28 10:19:24.002   618 17580 W C01650/hiview/Rdb:  device: 12583051 inode: 40230 mode: 432 size: 569344 natime: Wed Aug 28 00:00:06 2024
   08-28 10:19:24.002   618 17580 W C01650/hiview/Rdb:  smtime: Wed Aug 28 00:34:30 2024
   08-28 10:19:24.002   618 17580 W C01650/hiview/Rdb:  sctime: Wed Aug 28 00:34:30 2024
   ```

### Display and set flushing tasks

   ```
   hilog -w control
   ```

   > **NOTE**
   >
   > Run **hilog -w query** to query the current task.
   >
   > Run **hilog -w start -n 1000** to start the HiLog flushing task and set the number of flushed files to **1000**.
   >
   > Run **hilog -w start -n 100 -t kmsg** to start the kmsglog flushing task and set the number of flushed files to **100**.
   >
   > Run hilog -w stop to stop the flushing task.

   **Example**

   ```
   $ hilog -w query
   Persist task query failed
   No running persistent task [CODE: -63]
   $
   $ hilog -w start -n 1000
   Persist task [jobid:1][fileNum:1000][fileSize:4194304] start successfully
   $
   $ hilog -w start -n 100 -t kmsg
   Persist task [jobid:2][fileNum:100][fileSize:4194304] start successfully
   $
   $ hilog -w stop
   Persist task [jobid:1] stop successfully
   Persist task [jobid:2] stop successfully
   ```

### Set the lowest level of logs that can be printed

   ```
   hilog -b D/I/W/E/F
   ```

   **Example**

   ```
   $ hilog -b E
   Set global log level to E successfully
   ```
<!--Del-->
### Enable/Disable the privacy format.

   ```
   hilog -p on/off
   ```

   **Example**

   ```
   # hilog -p on
   Set hilog privacy format on successfully
   #
   # hilog -p off
   Set hilog privacy format off successfully
   ```
<!--DelEnd-->
