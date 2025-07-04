# HiLog


HiLog is a log system that provides logging for the system framework, services, and applications to record information on user operations and system running status. You can run the hilog commands to query related log information.


## Environment Setup

- The environment for OpenHarmony Device Connector (hdc) has been set up. For details, see [Environment Setup](hdc.md#environment-setup).

- The devices are properly connected and **hdc shell** is executed.


## Commands

| Short Option| Long Option| Parameter| Description|
| -------- | -------- | -------- | -------- |
| -h | --help | - | Shows help information.|
| Default| Default| - | Performs a blocking read on logs, with no exiting after the read finishes.|
| -x | --exit | - | Performs a non-blocking read on logs, with exiting after the read finishes.|
| -g | - | - | Checks the buffer size for logs of a specified type. This option is used together with **-t**, which specifies a log type. By default, the **app** or **core** types are used.|
| -G | --buffer-size | &lt;size&gt; | Sets the size of the buffer for logs of a specified type. This option is used together with **-t**, which specifies a log type. By default, the **app** or **core** types are used. The unit can be B, KB, MB, or GB. The value ranges from 64 KB to 16 MB.|
| -r | - | - | Clears the buffer for logs of a specified type. This option is used together with **-t**, which specifies a log type. By default, the **app** or **core** types are used.|
| <!--DelRow-->-p | --privacy | &lt;on/off&gt; | Specifies whether to enable privacy for logs during system debugging.|
| <!--DelRow--> |  | on | Enables privacy so that parameters are displayed as **\<private>** in printed logs.|
| <!--DelRow--> |  | off | Disables privacy so that parameters are displayed as they are in printed logs.|
| -k | - | &lt;on/off&gt; | Specifies whether to enable kernel logging.|
|  |  | on | Enables kernel logging.|
|  |  | off | Disables kernel logging.|
| -s | --statistics | - | Shows statistics. This option must be used together with **-t** or **-D**.|
| -S | - | - | Clears statistics. This option must be used together with **-t** or **-D**.|
| -Q | - | &lt;control-type&gt; | Specifies whether to enable the default quota for flow control.|
|  |  | pidon | Enables process flow control.|
|  |  | pidoff | Disables process flow control.|
|  |  | domainon | Enables domain flow control.|
|  |  | domainoff | Disables domain flow control.|
| -L | --level | &lt;level&gt; | Sets the log level, for example, **-L D/I/W/E/F**.|
| -t | --type | &lt;type&gt; | Sets the log type, for example, **-t app/core/init/only_prerelease**. **app** indicates the application log, **core** indicates the system log, **init** indicates the startup log, and **only_prerelease** indicates the log printed before the Release version.|
| -D | --domain | &lt;domain&gt; | Sets the domain.|
| -T | --tag | &lt;tag&gt; | Sets the tag.|
| -a | --head | &lt;n&gt; | Shows the first several lines of logs. The parameter **\<n>** indicates the number of first lines to show.|
| -z | --tail | &lt;n&gt; | Shows the last several lines of logs. The parameter **\<n>** indicates the number of last lines to show.|
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
| -v | --format | &lt;format&gt; | Sets the display format.|
|  |  | time | Displays the local time.|
|  |  | color | Adds colors to logs at different levels. By default, logs are displayed in black and white.|
|  |  | epoch | Displays the amount of time elapsed since the epoch time.|
|  |  | monotonic | Displays the amount of time elapsed since the system startup time.|
|  |  | usec | Displays the time in microseconds.|
|  |  | nsec | Displays the time in nanoseconds.|
|  |  | year | Displays the time with the year portion.|
|  |  | zone | Displays the time with the local time zone.|
|  |  | wrap | Displays logs in different lines without adding prefixes such as the timestamp to the new line.|
| -b | --baselevel | &lt;loglevel&gt; | Sets the lowest level of logs that can be printed: D(DEBUG)/I(INFO)/W(WARN)/E(ERROR)/F(FATAL).|
| | --persist| - |Persists the log level setting command. (The setting will not be lost after the system is restarted.)|

## Examples

### Displaying the Help Information

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

### Non-Blocking Reading on Logs

   ```
   hilog -x
   ```

   **Example**

   ```
   $ hilog -x
   11-15 15:51:02.087  2823  2823 I A01B05/com.ohos.sceneboard/AOD: AodClockFullScreen --> timeTextLineHeight:313.3333333333333 clockMarginTop:99
   11-15 15:51:02.087  2823  2823 I A01B05/com.ohos.sceneboard/AOD: AodClockFullScreen --> timeFontSize:114.48717948717947
   11-15 15:51:02.090  2823  2823 I A01B05/com.ohos.sceneboard/AOD: AodClockFullScreen --> timeTextWidth:202,timeTextHeight:292
   11-15 15:51:02.100  2823  2823 I A01B05/com.ohos.sceneboard/AOD: ComponentUtil --> Component(ComponentId-AodClockNumber) draw complete.
   11-15 15:51:02.110  1197  1197 E C01406/render_service/OHOS::RS: [LoadImgsbyResolution] Can't find resolution (1084 x 2412) in config file
   11-15 15:51:02.127  1197  1197 E C01406/render_service/OHOS::RS: [LoadImgsbyResolution] Can't find resolution (1084 x 2412) in config file
   ```

### Displaying the Log Buffer Size

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

### Setting the Log Buffer Size

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

### Clearing the Log Buffer

   ```
   hilog -r
   ```

   **Example**
   ```
   $ hilog -r
   Log type core,app,only_prerelease buffer clear successfully
   ```

### Enabling/Disabling Kernel Log Reading

   ```
   hilog -k on/off
   ```

   **Example**
   ```
   $ hilog -k on
   Set hilogd storing kmsg log on successfully
   $ 
   $ hilog -k off
   Set hilogd storing kmsg log off successfully
   ```

### Displaying Statistics

   ```
   hilog -s
   ```

   **Example**
   ```
   $ param set persist.sys.hilog.stats true
   Set parameter persist.sys.hilog.stats true success
   $ reboot
   $ hilog -s
   Log statistic report (Duration: 0h0m32s.564, From: 11-15 16:04:08.628):
   Total lines: 137517, length: 8.0M
   DEBUG lines: 0(0%), length: 0.0B(0%)
   INFO lines: 101795(74%), length: 6.1M(76%)
   WARN lines: 10268(7.5%), length: 719.9K(8.8%)
   ERROR lines: 25452(19%), length: 1.2M(15%)
   FATAL lines: 2(0.0015%), length: 259.0B(0.0031%)
   ------------------------------------------------------------
   Domain Table:
   LOGTYPE- DOMAIN---- TAG----------------------------- MAX_FREQ-- TIME---------------- MAX_TP---- TIME---------------- LINES----- LENGTH---- DROPPED---
   app----- 0xf00----- -------------------------------- 924.00---- 11-15 16:04:25.594-- 111975.00- 11-15 16:04:25.594-- 3386------ 371.5K---- 0---------
   app----- 0x0------- -------------------------------- 285.00---- 11-15 16:04:34.877-- 44242.00-- 11-15 16:04:34.877-- 990------- 129.2K---- 0---------
   ```

   **Description**
   ```
   MAX_FREQ: the maximum number of log lines per second
   TIME: occurrence time
   MAX_TP: the maximum number of bytes per second
   LINES: the total number of lines in a statistical period
   LENGTH: the total number of bytes in a statistical period
   DROPPED: the number of dropped lines in a statistical period
   ```

### Clearing Statistics

   ```
   hilog -S
   ```

   **Example**

   ```
   $ hilog -S
   Statistic info clear successfully
   ```

### Enabling/Disabling Process Flow Control

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

### Enabling/Disabling Domain Flow Control

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

### Displaying Logs of a Specified Level

   ```
   hilog -L D/I/W/E/F
   ```

   **Example**

   ```
   $ hilog -L E
   08-28 09:01:25.730  2678  2678 E A00F00/com.aidataservice/AiDataService_5.10.7.320: DataChangeNotifyManager: notifyDataChange CommonEntity no valid entity to notify
   08-28 09:01:56.058  8560  8560 E A00500/com.ohos.settingsdata/SettingsData: DB not ready request = datashare:///com.ohos.settingsdata/entry/settingsdata/SETTINGSDATA?Proxy=true&key=analysis_service_switch_on , retry after DB startup
   08-28 09:01:56.082  8560  8560 E A00500/com.ohos.settingsdata/SettingsData: decoder failure: /data/migrate/settings_global.xml , error code:-1
   08-28 09:01:56.082  8560  8560 E A00500/com.ohos.settingsdata/SettingsData: clearXml failed:No such file or directory, error code:13900002
   08-28 09:01:56.083  8560  8560 E A00500/com.ohos.settingsdata/SettingsData: readText failed:No such file or directory, error code:13900002
   08-28 09:01:56.371  8586  8586 E A00500/com.ohos.settingsdata/SettingsData: DB not ready request =    datashare:///com.ohos.settingsdata/entry/settingsdata/SETTINGSDATA?Proxy=true&key=photo_network_connection_status , retry after DB startup
   08-28 09:01:56.408  8586  8586 E A00500/com.ohos.settingsdata/SettingsData: decoder failure: /data/migrate/settings_global.xml , error code:-1
   ```

### Displaying Logs of a Specified Type

   ```
   hilog -t app
   ```

   **Example**

   ```
   $ hilog -t app
   11-15 16:04:45.903  5630  5630 I A0A5A5/os.hiviewcare:staticSubscriber/Diagnosis: [DetectionFilter]820001084: switch off
   11-15 16:04:45.905  5630  5630 I A0A5A5/os.hiviewcare:staticSubscriber/Diagnosis: [DetectionFilter]847005050: frequency limit
   11-15 16:04:45.905  5630  5630 I A0A5A5/os.hiviewcare:staticSubscriber/Diagnosis: [SmartNotifyHandler]detections after filter: []
   11-15 16:04:45.905  5630  5630 I A0A5A5/os.hiviewcare:staticSubscriber/Diagnosis: [SmartNotifyHandler]no detections to detect
   11-15 16:04:45.924  5687  5687 I A01B06/common/KG: MetaBalls-SystemTopPanelController --> init charging status = 3
   ```

### Displaying Logs of a Specified Domain

   ```
   hilog -D 01B06
   ```

   **Example**

   ```
   $ hilog -D 01B06
   11-15 16:04:54.981  5687  5687 I A01B06/common/KG: MetaBalls-MetaBallRenderer --> pressTime = 0 appearTime = 1731657885972
   11-15 16:04:54.981  5687  5687 I A01B06/common/KG: MetaBalls-MetaBallRenderer --> backAnimator on finish
   11-15 16:04:54.982  5687  5687 I A01B06/common/KG: MetaBalls-MetaBallRenderer --> setTimeout over 9s and begin animate on finish
   11-15 16:04:55.297  5687  5687 I A01B06/common/KG: MetaBalls-MetaBallRenderer --> chargingTextExitAnimation onFinish
   11-15 16:04:55.494  5687  5687 I A01B06/common/KG: MetaBalls-MetaBallRenderer --> uiExtension session send data success,type: exitAnimationFinish
   ```

### Displaying Logs of a Specified Tag

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

### Displaying Logs in the First N Lines of the Buffer

   ```
   hilog -a 8
   ```

   **Example**

   ```
   $ hilog -a 8
   11-15 16:04:08.628     0     0 I I00000/HiLog: ========Zeroth log of type: init
   11-15 16:04:08.603   506   506 I I02C01/cust_carrier_mount/CustCarrierMount: MountCarrierToShared start
   11-15 16:04:08.604   506   506 I I02C01/cust_carrier_mount/CustCarrierMount: success to mount carrier to shared
   11-15 16:04:15.394   972   972 I I02C01/cust_carrier_mount/CustCarrierMount: UpdateCotaOpkeyLink start
   11-15 16:04:15.396   972   972 W I02C01/cust_carrier_mount/CustCarrierMount: not exsit CUST_GLOBAL_CARRIER_DIR or COTA_PARAM_CARRIER_DIR
   11-15 16:04:15.887   972   972 I I02C01/cust_carrier_mount/CustCarrierMount: success to update cota carrier
   11-15 16:04:48.749  5777  5901 I A00001/com.hiai.core/HiAI_Metadata: metadata is null
   11-15 16:04:48.749  5777  5901 I A00001/com.hiai.core/HiAI_PluginAbilityInfo: abilityInfo is null
   ```

### Displaying Logs in the Last N Lines of the Buffer

   ```
   hilog -z 8
   ```

   **Example**

   ```
   $ hilog -z 8
   11-15 16:12:19.015  1899  7867 W C01719/wifi_manager_service/ffrt: 423:FFRTQosApplyForOther:244 tid 7867, Operation not permitted, ret:-1, eno:1
   11-15 16:12:19.125  1043  1072 I C01C42/time_service/TimeService: uid: 1010 id:428551571 name:wifi_manager_service wk:0
   11-15 16:12:19.125  1043  1072 I C01C42/time_service/TimeService: bat: -1 id:428551571 we:505225000000 mwe:512725000000
   11-15 16:12:19.125  1043  1072 I C01C42/time_service/TimeService: typ:3 trig: 505 225000000, bt: 495230369193
   11-15 16:12:19.125  1043  1072 I C01C42/time_service/TimeService: cb: 428551571 ret: 0
   11-15 16:12:19.435  3086  7813 I C01719/com.ohos.contactsdataability/ffrt: 45:~WorkerThread:72 to exit, qos[3]
   11-15 16:12:19.691   800  1404 I C01713/resource_schedule_service/SUSPEND_MANAGER: [(HasSpecialStateFromBgtask):759] 20020107_com.ohos.medialibrary.medialibrarydata
   11-15 16:12:19.691   800  1404 I C01713/resource_schedule_service/SUSPEND_MANAGER: [(DozeFreezeUnit):890] Doze has special:ERR_HAS_PID_EFFICIENCY_RESOURCE
   ```

### Displaying Logs of a Specified Process

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

### Displaying Logs That Match the Regular Expression Keyword

   ```
   hilog -e start
   ```

   **Example**

   ```
   $ hilog -e start
   11-15 16:17:17.578   547  4504 I C01800/samgr/SAMGR: AddProc start proc:media_analysis_service spend 223ms
   11-15 16:17:17.578   547  4504 I C01800/samgr/SAMGR: Scheduler proc:media_analysis_service handle started event
   11-15 16:17:17.578   547  4504 I C01800/samgr/SAMGR: Scheduler proc:media_analysis_service started
   11-15 16:17:17.580  8877  8877 I C01810/media_analysis_service/SAFWK: start tasks proc:media_analysis_service end,spend 1ms
   11-15 16:17:17.582  8877  8877 I C01651/media_analysis_service/DataShare: [operator()()-data_share_manager_impl.cpp:134]: RecoverObs start
   11-15 16:17:17.589  8877  8893 I C01651/media_analysis_service/DataShare: [Connect()-ams_mgr_proxy.cpp:67]: connect start, uri = ******/media
   11-15 16:17:18.225  1155  1633 I C02943/power_host/ThermalHdi: CreateLogFile start
   11-15 16:17:18.264  1155  1633 I C02943/power_host/ThermalHdi: CompressFile start
   ```

### Displaying and Setting Flushing Tasks

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
   > Run **hilog -w stop** to stop the flushing task.
   >
   > Run **hilog -w start -t kmsg -f kmsglog -l 2M -n 100 -m zlib** to start the kmsglog flushing task and set the file name to **kmsglog**, size to 2 MB, number of files to **100**, compression mode to **zlib**. The compression mode can be **zlib**, **zstd** or **none**.

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
   $
   $ hilog -w start -t kmsg -f kmsglog -l 2M -n 100 -m zlib
   Persist task [jobid:2][fileNum:100][fileSize:2097152] start successfully
   ```

### Setting the Log Display Format

   ```
   hilog -v time/color/epoch/monotonic/usec/nsec/year/zone/wrap
   ```

   **Example**

   ```
   $ hilog -v time
   11-15 16:36:21.027  1134  1723 I C02B01/riladapter_host/HrilExt: [NotifyToBoosterTel-(hril_manager_ext.cpp:440)] RilExt:Notify to booster tel finish
   11-15 16:36:21.027  1134  1723 I C02B01/riladapter_host/HrilExt: [NotifyToBoosterNet-(hril_manager_ext.cpp:450)] RilExt: HNOTI_BOOSTER_NET_IND report to booster net
   11-15 16:36:21.027  1134  1723 I C02B01/riladapter_host/HrilExt: [NotifyToBoosterNet-(hril_manager_ext.cpp:454)] RilExt: HNOTI_BOOSTER_NET_IND report to booster net finish
   11-15 16:36:21.027  1134  1723 I P01FFF/riladapter_host/Rilvendor: CHAN [HandleUnsolicited] HandleUnsolicited done for modem:0, index:0, atResponse:^BOOSTERNTF: 3, 20,"0600100001000004000000000102A4FF0202F6FF"
   11-15 16:36:21.802  2809  2831 E C02D06/com.ohos.sceneboard/XCollie: Send kick,foundation to hungtask Successful
   11-15 16:36:21.911   882  3016 I C01F0B/telephony/TelephonyVSim: state machine ProcessEvent Id: 125
   11-15 16:36:21.911   882  3016 I C01F0B/telephony/TelephonyVSim: StateProcess
   $
   $ hilog -v nsec
   11-15 16:37:09.010658555  1134  1723 I C02B01/riladapter_host/HrilExt: [BoosterRawInd-(hril_booster.cpp:296)] RilExt: BoosterRawInd
   11-15 16:37:09.010676263  1134  1723 I C02B01/riladapter_host/HrilExt: [BoosterRawInd-(hril_booster.cpp:328)] check need notify to satellite:indType 6
   11-15 16:37:09.010800221  1134  1723 I C02B01/riladapter_host/HrilExt: [NotifyToBoosterTel-(hril_manager_ext.cpp:436)] RilExt: report to telephony ext, requestNum: 4201
   11-15 16:37:09.011011680  1134  1723 I C02B01/riladapter_host/HrilExt: [NotifyToBoosterTel-(hril_manager_ext.cpp:440)] RilExt:Notify to booster tel finish
   11-15 16:37:09.011064805  1134  1723 I C02B01/riladapter_host/HrilExt: [NotifyToBoosterNet-(hril_manager_ext.cpp:450)] RilExt: HNOTI_BOOSTER_NET_IND report to booster net
   11-15 16:37:09.011200742  1134  1723 I C02B01/riladapter_host/HrilExt: [NotifyToBoosterNet-(hril_manager_ext.cpp:454)] RilExt: HNOTI_BOOSTER_NET_IND report to booster net finish
   ```

### Displaying and Setting Log Levels

   ```
   // The default global log level is Info.
   param get param get hilog.loggable.global

   // Set the global log level.
   hilog -b D/I/W/E/F

   // Set the log level of [DOMAINID].
   hilog -b D/I/W/E/F -D [DOMAINID]

   // Set the log level of [TAG].
   hilog -b D/I/W/E/F -T [TAG]

   // Set the global log level. The setting still takes effect after the device is restarted.
   hilog -b D/I/W/E/F --persist
   ```

   **Example**

   ```
   $ param get hilog.loggable.global
   I

   $ hilog -b E
   Set global log level to E successfully

   $ hilog -b D -D 0x2d00
   Set domain 0x2d00 log level to D successfully

   $ hilog -b E -T testTag
   Set tag testTag log level to E successfully
   ```
<!--Del-->
### Enabling/Disabling the Privacy Format

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
