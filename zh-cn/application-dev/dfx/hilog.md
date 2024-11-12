# hilog


HiLog日志系统，提供给系统框架、服务、以及应用，用于打印日志，记录用户操作、系统运行状态等。开发者可以通过hilog命令行查询相关日志信息。


## 前置条件

- 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)。

- 正常连接设备。


## 命令行说明

hilog命令行使用方式：

| 短选项 | 长选项 | 参数 | 说明 | 
| -------- | -------- | -------- | -------- |
| -h | --help |  | 帮助命令。 | 
| 缺省 | 缺省 |  | 阻塞读日志，不退出。 | 
| -x | --exit |  | 非阻塞读日志，读完退出。 | 
| -g |  |  | 查询buffer的大小，配合-t指定某一类型使用，默认app和core。 | 
| -G | --buffer-size | &lt;size&gt; | 设置指定&lt;type&gt;日志类型缓冲区的大小，配合-t指定某一类型使用，默认app和core， 可使用B/K/M为单位，范围为64K-16M。 | 
| -r |  |  | 清除buffer日志，配合-t指定某一类型使用，默认app和core。 | 
| <!--DelRow-->-p | --privacy | &lt;on/off&gt; | 支持系统调试时日志隐私开关控制。 | 
| <!--DelRow--> |  | on | 打开隐私开关，显示&lt;private&gt;。 | 
| <!--DelRow--> |  | off | 关闭隐私开关，显示明文。 | 
| -k |  | &lt;on/off&gt; | Kernel日志读取开关控制。 | 
|  |  | on | 打开读取kernel日志。 | 
|  |  | off | 关闭读取kernel日志。 | 
| -s | --statistics |  | 查询统计信息，需配合-t或-D使用。 | 
| -S |  |  | 清除统计信息，需配合-t或-D使用。 | 
| -Q |  | &lt;control-type&gt; | 流控缺省配额开关控制。 | 
|  |  | pidon | 进程流控开关打开。 | 
|  |  | pidoff | 进程流控开关关闭。 | 
|  |  | domainon | domain流控开关打开。 | 
|  |  | domainoff | domain流控开关关闭。 | 
| -L | --level | &lt;level&gt; | 指定级别的日志，示例：-L D/I/W/E/F。 | 
| -t | --type | &lt;type&gt; | 指定类型的日志，示例：-t app core init。 | 
| -D | --domain | &lt;domain&gt; | 指定domain。 | 
| -T | --tag | &lt;tag&gt; | 指定tag。 | 
| -a | --head | &lt;n&gt; | 只显示前&lt;n&gt;行日志。 | 
| -z | --tail | &lt;n&gt; | 只显示后&lt;n&gt;行日志。 | 
| -P | --pid | &lt;pid&gt; | 标识不同的pid。 | 
| -e | --regex | &lt;expr&gt; | 只打印日志消息与&lt;expr&gt;匹配的行，其中&lt;expr&gt;是一个正则表达式。 | 
| -f | --filename | &lt;filename&gt; | 设置落盘的文件名。 | 
| -l | --length | &lt;length&gt; | 设置落盘的文件大小，需要大于等于64K。 | 
| -n | --number | &lt;number&gt; | 设置落盘文件的个数。 | 
| -j | --jobid | &lt;jobid&gt; | 设置落盘任务的ID。 | 
| -w | --write | &lt;control&gt; | 落盘任务控制。 | 
|  |  | query | 落盘任务查询。 | 
|  |  | start | 落盘任务开始，命令行参数为文件名、单文件大小、落盘算法、rotate文件数目。 | 
|  |  | stop | 落盘任务停止。 |
|  |  | refresh | 刷新缓冲区的日志到落盘文件。 |
|  |  | clear | 删除已经落盘的日志文件。 | 
| -m | --stream | &lt;algorithm&gt; | 落盘方式控制。 | 
|  |  | none | 无压缩方式落盘。 | 
|  |  | zlib | zlib压缩算法落盘，落盘文件为.gz。 | 
|  |  | zstd | zstd压缩算法落盘，落盘文件为.zst。 | 
| -v | --format | &lt;format&gt; |  | 
|  |  | time | 显示本地时间。 | 
|  |  | color | 显示不同级别显示不同颜色，参数缺省级别颜色模式处理（按黑白方式）。 | 
|  |  | epoch | 显示相对1970时间。 | 
|  |  | monotonic | 显示相对启动时间。 | 
|  |  | usec | 显示微秒精度时间。 | 
|  |  | nsec | 显示纳秒精度时间。 | 
|  |  | year | 显示将年份添加到显示的时间。 | 
|  |  | zone | 显示将本地时区添加到显示的时间。 | 
| -b | --baselevel | &lt;loglevel&gt; | 设置可打印日志的最低等级：D(DEBUG)/I(INFO)/W(WARN)/E(ERROR)/F(FATAL)。 | 

## 常用命令

### 查看帮助命令。

   ```
   hilog -h
   ```

   **使用样例：**

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

### 查看日志缓冲区大小。

   ```
   hilog -g
   ```

   **使用样例：**

   ```
   $ hilog -g
   Log type app buffer size is 16.0M
   Log type init buffer size is 16.0M
   Log type core buffer size is 16.0M
   Log type only_prerelease buffer size is 16.0M
   ```

### 修改日志缓冲区大小。

   ```
   hilog -G size
   ```

   **使用样例：**
   ```
   $ hilog -G 16M
   Set log type app buffer size to 16.0M successfully
   Set log type init buffer size to 16.0M successfully
   Set log type core buffer size to 16.0M successfully
   Set log type only_prerelease buffer size to 16.0M successfully
   ```

### 进程流控开关。

   ```
   hilog -Q pidon/pidoff
   ```
   

   **使用样例：**

   ```
   $ hilog -Q pidon
   Set flow control by process to enabled successfully
   $
   $ hilog -Q pidoff
   Set flow control by process to disabled successfully
   ```

### domain流控开关。

   ```
   hilog -Q domainon/domainoff
   ```

   **使用样例：**

   ```
   $ hilog -Q domainon
   Set flow control by domain to enabled successfully
   $
   $ hilog -Q domainoff
   Set flow control by domain to disabled successfully
   ```

### 查看指定级别日志。

   ```
   hilog -L D/I/W/E/F
   ```

   **使用样例：**

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

### 查看指定TAG日志。

   ```
   hilog -T tag
   ```

   **使用样例：**

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

### 查看指定进程日志。

   ```
   hilog -P pid
   ```

   **使用样例：**

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

### 查看、设置落盘任务。

   ```
   hilog -w control
   ```

   > **说明：**
   >
   > 查询当前任务： hilog -w query
   >
   > 开启hilog落盘任务，并且设置落盘文件数量为1000个： hilog -w start -n 1000
   >
   > 开启kmsglog落盘任务，并且设置落盘文件数量为100个： hilog -w start -n 100 -t kmsg
   >
   > 停止当前落盘任务： hilog -w stop

   **使用样例：**

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

### 设置可打印日志的最低等级

   ```
   hilog -b D/I/W/E/F
   ```

   **使用样例：**

   ```
   $ hilog -b E
   Set global log level to E successfully
   ```
<!--Del-->
### 隐私开关

   ```
   hilog -p on/off
   ```

   **使用样例：**

   ```
   # hilog -p on
   Set hilog privacy format on successfully
   #
   # hilog -p off
   Set hilog privacy format off successfully
   ```
<!--DelEnd-->