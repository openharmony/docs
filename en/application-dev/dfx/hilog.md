# hilog

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liuyifeifei;@buzhenwang-->
<!--Designer: @shenchenkai-->
<!--Tester: @liyang2235-->
<!--Adviser: @foryourself-->

HiLog is a log system that provides logging for the system framework, services, and applications to record information on user operations and system running status. You can run the hilog commands to query related log information.


## Environment Setup

- The environment for OpenHarmony Device Connector (hdc) has been set up. For details, see [Environment Setup](hdc.md#environment-setup).

- The devices are properly connected and **hdc shell** is executed.

<!--RP15-->
## Overview

### Log Generation

If the HiLog API is called in the service code, HiLog logs are generated during service running.

### Viewing Logs

- Online checking:

  Run the **hdc shell hilog** command.

- Checking persisted files:

  By default, HiLog logs are not persisted. You need to enable the persist task to persist logs to the **data/log/hilog** directory on the device. You can run the **hdc file recv data/log/hilog** command to export logs and view them locally.

  For details about how to enable or disable the persist task, see [Checking and Setting Persisting Tasks](#checking-and-setting-persisting-tasks).

### Log Format

| Column 1| Column 2| Column 3| Column 4|  Column 5| Column 6| Column 7|
| -------- | -------- | -------- | -------- | -------- | -------- | -------- |
| Date| Timestamp| Process ID| Thread ID| Log level| **domainID**/Log tag:| Log content|
| 04-19 | 17:02:14.735 | 5394 | 5394 | I | A03200/testTag: | this is a info level hilog |

> **NOTE**
>
> Log level: **I** indicates the **Info** level. For details about other levels, see [Log Level](../reference/apis-performance-analysis-kit/capi-log-h.md#loglevel)
>
> **domainID**: In **A03200**, **A** indicates application logs (**LOG_APP**), and **3200** indicates that the **domainID** is **0x3200**.

<!--RP15End-->

## Commands

<!--RP18-->
| Short Option| Long Option| Parameter| Description|
| -------- | -------- | -------- | -------- |
| -h | --help | - | Shows help information.|
| Default| Default| - | Performs a blocking read on logs, with no exiting after the read finishes.|
| -x | --exit | - | Performs a non-blocking read on logs, with exiting after the read finishes.|
| -a | --head | &lt;n&gt; | Shows the first several lines of logs. The parameter **\<n>** indicates the number of first lines to show.|
| -z | --tail | &lt;n&gt; | Shows the last several lines of logs. The parameter **\<n>** indicates the number of last lines to show.|
| -t | --type | &lt;type&gt; | Views logs of a specified type.|
|  |  | app | Views application logs.|
|  |  | core | Views system logs.|
|  |  | init | Views startup logs.|
|  |  | kmsg | Views kernel logs.|
|  |  | only_prerelease | Views logs that are printed before the system release version. Application developers do not need to pay attention to these logs.|
| -L | --level | &lt;level&gt; | Sets the log level, for example, **-L D/I/W/E/F**.|
| -D | --domain | &lt;domain&gt; | Sets the domain.|
| -T | --tag | &lt;tag&gt; | Sets the tag.|
| -P | --pid | &lt;pid&gt; | Identifies a process.|
| -e | --regex | &lt;expr&gt; | Prints only the lines of logs that match the regular expression specified through **\<expr>**.|
| -v | --format | &lt;format&gt; | Sets the display format.|
|  |  | color/colour | Displays logs in different colors. By default, logs are displayed in black and white.|
|  |  | time | Displays the local time.|
|  |  | epoch | Displays the amount of time elapsed since the epoch time.|
|  |  | monotonic | Displays the amount of time elapsed since the system startup time.|
|  |  | msec | Displays the time in milliseconds.|
|  |  | usec | Displays the time in microseconds.|
|  |  | nsec | Displays the time in nanoseconds.|
|  |  | year | Displays the time with the year portion.|
|  |  | zone | Displays the time with the local time zone.|
|  |  | wrap | Displays logs in different lines without adding prefixes such as the timestamp to the new line.|
|  |  | long | Displays all data fields separated by spaces.|
| -r | - | - | Clears the buffer for logs of a specified type. This option is used together with **-t**, which specifies a log type. By default, the **app** or **core** types are used.|
| -g | - | - | Checks the buffer size for logs of a specified type. This option is used together with **-t**, which specifies a log type. By default, the **app** or **core** types are used.|
| -G | --buffer-size | &lt;size&gt; | Sets the size of the buffer for logs of a specified type. This option is used together with **-t**, which specifies a log type. By default, the **app** or **core** types are used. The unit can be B, KB, MB, or GB. The value ranges from 64 KB to 16 MB.|
| -s | --statistics | - | Shows statistics. This option must be used together with **-t** or **-D**.|
| -S | - | - | Clears statistics. This option must be used together with **-t** or **-D**.|
| -w | --write | &lt;control&gt; | Controls a flushing task.|
|  |  | query | Queries flushing tasks.|
|  |  | start | Starts a flushing task. The command line parameters are the file name, size of a single file, flushing mode, and number of rotated files.|
|  |  | stop | Stops a flushing task.|
|  |  | refresh | Refreshes the logs in the buffer to the flushed file.|
|  |  | clear | Deletes log files that are flushed to disks.|
| -f | --filename | &lt;filename&gt; | Sets the names of the files to be flushed to disk.|
| -l | --length | &lt;length&gt; | Sets the size of the files to be flushed to disk. The value must be greater than or equal to 64 KB.|
| -n | --number | &lt;number&gt; | Sets the number of files to be flushed to disk.|
| -m | --stream | &lt;algorithm&gt; | Sets the flushing mode.|
|  |  | none | Indicates that data is flushed to disks in non-compression mode.|
|  |  | zlib | Indicates that data is flushed to disks using the zlib compression algorithm. The flushed file is in .gz format.|
| -j | --jobid | &lt;jobid&gt; | Sets the ID of a flushing task.|
| -p | --privacy | &lt;on/off&gt; | Specifies whether to enable privacy for logs during system debugging.|
|  |  | on | Enables privacy so that parameters are displayed as **\<private>** in printed logs.|
|  |  | off | Disables privacy so that parameters are displayed as they are in printed logs.|
| -k | - | &lt;on/off&gt; | Specifies whether to enable kernel logging.|
|  |  | on | Enables kernel logging.|
|  |  | off | Disables kernel logging.|
| -Q | - | &lt;control-type&gt; | Controls whether to enable the default quota when the threshold is exceeded.|
|  |  | pidon | Enables the process flow control.|
|  |  | pidoff | Disables the process flow control.|
|  |  | domainon | Enables the domain flow control.|
|  |  | domainoff | Disables the domain flow control.|
| -b | --baselevel | &lt;loglevel&gt; | Sets the lowest level of logs that can be printed: D(DEBUG)/I(INFO)/W(WARN)/E(ERROR)/F(FATAL). This command can be used together with **-D** and **-T** to set the lowest log level.|
| - | --persist| - |Persists the log level setting command. (The setting will not be lost after the system is restarted.)|
<!--RP18End-->


## Displaying the Help Information

```shell
hilog -h
```

**Example**

```shell
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

## **Non-Blocking Log Reading**

```shell
hilog -x
```

**Example**

<!--RP1-->
   ```shell
   $ hilog -x
   11-15 15:51:02.087  2823  2823 I A01B05/AOD: AodClockFullScreen --> timeTextLineHeight:313.3333333333333 clockMarginTop:99
   11-15 15:51:02.087  2823  2823 I A01B05/AOD: AodClockFullScreen --> timeFontSize:114.48717948717947
   11-15 15:51:02.090  2823  2823 I A01B05/AOD: AodClockFullScreen --> timeTextWidth:202,timeTextHeight:292
   11-15 15:51:02.100  2823  2823 I A01B05/AOD: ComponentUtil --> Component(ComponentId-AodClockNumber) draw complete.
   11-15 15:51:02.110  1197  1197 E C01406/OHOS::RS: [LoadImgsbyResolution] Can't find resolution (1084 x 2412) in config file
   11-15 15:51:02.127  1197  1197 E C01406/OHOS::RS: [LoadImgsbyResolution] Can't find resolution (1084 x 2412) in config file
   ```
<!--RP1End-->

## **Viewing Logs of a Specified Level**

```shell
hilog -L D/I/W/E/F
```

**Example**

<!--RP2-->
   ```shell
   $ hilog -L E
   08-28 09:01:25.730  2678  2678 E A00F00/AiDataService_5.10.7.320: DataChangeNotifyManager: notifyDataChange CommonEntity no valid entity to notify
   08-28 09:01:56.058  8560  8560 E A00500/SettingsData: DB not ready request = datashare:///com.ohos.settingsdata/entry/settingsdata/SETTINGSDATA?Proxy=true&key=analysis_service_switch_on , retry after DB startup
   08-28 09:01:56.082  8560  8560 E A00500/SettingsData: decoder failure: /data/migrate/settings_global.xml , error code:-1
   08-28 09:01:56.082  8560  8560 E A00500/SettingsData: clearXml failed:No such file or directory, error code:13900002
   08-28 09:01:56.083  8560  8560 E A00500/SettingsData: readText failed:No such file or directory, error code:13900002
   08-28 09:01:56.371  8586  8586 E A00500/SettingsData: DB not ready request =    datashare:///com.ohos.settingsdata/entry/settingsdata/SETTINGSDATA?Proxy=true&key=photo_network_connection_status , retry after DB startup
   08-28 09:01:56.408  8586  8586 E A00500/SettingsData: decoder failure: /data/migrate/settings_global.xml , error code:-1
   ```
<!--RP2End-->

## **Viewing Logs of a Specified Type**

```shell
hilog -t app
```

**Example**

<!--RP3-->
   ```shell
   $ hilog -t app
   11-15 16:04:45.903  5630  5630 I A0A5A5/Diagnosis: [DetectionFilter]820001084: switch off
   11-15 16:04:45.905  5630  5630 I A0A5A5/Diagnosis: [DetectionFilter]847005050: frequency limit
   11-15 16:04:45.905  5630  5630 I A0A5A5/Diagnosis: [SmartNotifyHandler]detections after filter: []
   11-15 16:04:45.905  5630  5630 I A0A5A5/Diagnosis: [SmartNotifyHandler]no detections to detect
   11-15 16:04:45.924  5687  5687 I A01B06/KG: MetaBalls-SystemTopPanelController --> init charging status = 3
   ```
<!--RP3End-->

## **Viewing Logs of a Specified Domain**

```shell
hilog -D 01B06
```

**Example**

<!--RP4-->
   ```shell
   $ hilog -D 01B06
   11-15 16:04:54.981  5687  5687 I A01B06/KG: MetaBalls-MetaBallRenderer --> pressTime = 0 appearTime = 1731657885972
   11-15 16:04:54.981  5687  5687 I A01B06/KG: MetaBalls-MetaBallRenderer --> backAnimator on finish
   11-15 16:04:54.982  5687  5687 I A01B06/KG: MetaBalls-MetaBallRenderer --> setTimeout over 9s and begin animate on finish
   11-15 16:04:55.297  5687  5687 I A01B06/KG: MetaBalls-MetaBallRenderer --> chargingTextExitAnimation onFinish
   11-15 16:04:55.494  5687  5687 I A01B06/KG: MetaBalls-MetaBallRenderer --> uiExtension session send data success,type: exitAnimationFinish
   ```
<!--RP4End-->

## **Viewing Logs of a Specified Domain**

```shell
hilog -T tag
```

**Example**

<!--RP5-->
   ```shell
   $ hilog -T SAMGR
   08-28 09:27:59.581   610 11504 I C01800/SAMGR: CommonEventCollect save extraData 1661
   08-28 09:27:59.581   610 11504 I C01800/SAMGR: OnReceiveEvent get action: usual.event.BATTERY_CHANGED code: 0, extraDataId 1661
   08-28 09:27:59.582   610 11504 I C01800/SAMGR: DoEvent:4 name:usual.event.BATTERY_CHANGED value:0
   08-28 09:27:59.582   610 11504 W C01800/SAMGR: LoadSa SA:10120 AddDeath fail,cnt:1,callpid:610
   08-28 09:27:59.583   610 11504 I C01800/SAMGR: LoadSa SA:10120 size:1,count:1
   08-28 09:27:59.601   610 11504 I C01800/SAMGR: Scheduler SA:10120 loading
   08-28 09:27:59.965 11518 11518 I C01800/SAMGR: SA:10120 OpenSo spend 315ms
   08-28 09:27:59.965   610  4064 I C01800/SAMGR: AddProc:media_analysis_service. size:75
   ```
<!--RP5End-->

## **Viewing the First n Lines of Logs in the Buffer**

```shell
hilog -a 8
```

**Example**

<!--RP6-->
   ```shell
   $ hilog -a 8
   11-15 16:04:08.628     0     0 I I00000/HiLog: ========Zeroth log of type: init
   11-15 16:04:08.603   506   506 I I02C01/CustCarrierMount: MountCarrierToShared start
   11-15 16:04:08.604   506   506 I I02C01/CustCarrierMount: success to mount carrier to shared
   11-15 16:04:15.394   972   972 I I02C01/CustCarrierMount: UpdateCotaOpkeyLink start
   11-15 16:04:15.396   972   972 W I02C01/CustCarrierMount: not exist CUST_GLOBAL_CARRIER_DIR or COTA_PARAM_CARRIER_DIR
   11-15 16:04:15.887   972   972 I I02C01/CustCarrierMount: success to update cota carrier
   11-15 16:04:48.749  5777  5901 I A00001/HiAI_Metadata: metadata is null
   11-15 16:04:48.749  5777  5901 I A00001/HiAI_PluginAbilityInfo: abilityInfo is null
   ```
<!--RP6End-->

## **Viewing the Last n Lines of Logs in the Buffer**

```shell
hilog -z 8
```

**Example**

<!--RP7-->
   ```shell
   $ hilog -z 8
   11-15 16:12:19.015  1899  7867 W C01719/ffrt: 423:FFRTQosApplyForOther:244 tid 7867, Operation not permitted, ret:-1, eno:1
   11-15 16:12:19.125  1043  1072 I C01C42/TimeService: uid: 1010 id:428551571 name:wifi_manager_service wk:0
   11-15 16:12:19.125  1043  1072 I C01C42/TimeService: bat: -1 id:428551571 we:505225000000 mwe:512725000000
   11-15 16:12:19.125  1043  1072 I C01C42/TimeService: typ:3 trig: 505 225000000, bt: 495230369193
   11-15 16:12:19.125  1043  1072 I C01C42/TimeService: cb: 428551571 ret: 0
   11-15 16:12:19.435  3086  7813 I C01719/ffrt: 45:~WorkerThread:72 to exit, qos[3]
   11-15 16:12:19.691   800  1404 I C01713/SUSPEND_MANAGER: [(HasSpecialStateFromBgtask):759] 20020107_com.ohos.medialibrary.medialibrarydata
   11-15 16:12:19.691   800  1404 I C01713/SUSPEND_MANAGER: [(DozeFreezeUnit):890] Doze has special:ERR_HAS_PID_EFFICIENCY_RESOURCE
   ```
<!--RP7End-->

## **Viewing Logs of a Specified Process**

```shell
hilog -P pid
```

**Example**

<!--RP8-->
   ```shell
   $ hilog -P 618
   08-28 10:19:16.872   618 17729 I C02D15/XPower: [task_52]#current system load is: 0.028767
   08-28 10:19:23.997   618 17580 I C02D10/CpuCollector: CalculateProcessCpuStatInfos: startTime=1724811553746, endTime=1724811563996, startBootTime=47001084, endBootTime=47011335, period=10251
   08-28 10:19:23.999   618 17580 I C02D10/CpuCollector: CollectProcessCpuStatInfos: collect process cpu statistics information size=234, isNeedUpdate=1
   08-28 10:19:24.002   618 17580 W C01650/Rdb:  DB :
   08-28 10:19:24.002   618 17580 W C01650/Rdb:  device: 12583051 inode: 40230 mode: 432 size: 569344 natime: Wed Aug 28 00:00:06 2024
   08-28 10:19:24.002   618 17580 W C01650/Rdb:  smtime: Wed Aug 28 00:34:30 2024
   08-28 10:19:24.002   618 17580 W C01650/Rdb:  sctime: Wed Aug 28 00:34:30 2024
   ```
<!--RP8End-->

## **Viewing Logs That Match the Regular Expression Keyword**

```shell
hilog -e start
```

**Example**

<!--RP9-->
   ```shell
   $ hilog -e start
   11-15 16:17:17.578   547  4504 I C01800/SAMGR: AddProc start proc:media_analysis_service spend 223ms
   11-15 16:17:17.578   547  4504 I C01800/SAMGR: Scheduler proc:media_analysis_service handle started event
   11-15 16:17:17.578   547  4504 I C01800/SAMGR: Scheduler proc:media_analysis_service started
   11-15 16:17:17.580  8877  8877 I C01810/SAFWK: start tasks proc:media_analysis_service end,spend 1ms
   11-15 16:17:17.582  8877  8877 I C01651/DataShare: [operator()()-data_share_manager_impl.cpp:134]: RecoverObs start
   11-15 16:17:17.589  8877  8893 I C01651/DataShare: [Connect()-ams_mgr_proxy.cpp:67]: connect start, uri = ******/media
   11-15 16:17:18.225  1155  1633 I C02943/ThermalHdi: CreateLogFile start
   11-15 16:17:18.264  1155  1633 I C02943/ThermalHdi: CompressFile start
   ```
<!--RP9End-->

## **Viewing Logs in Different Formats**

```shell
hilog -v time/color/epoch/monotonic/usec/nsec/year/zone/wrap
```

**Example**

Display the local time in nanoseconds.

<!--RP10-->
   ```shell
   $ hilog -v time
   11-15 16:36:21.027  1134  1723 I C02B01/HrilExt: [NotifyToBoosterTel-(hril_manager_ext.cpp:440)] RilExt:Notify to booster tel finish
   11-15 16:36:21.027  1134  1723 I C02B01/HrilExt: [NotifyToBoosterNet-(hril_manager_ext.cpp:450)] RilExt: HNOTI_BOOSTER_NET_IND report to booster net
   11-15 16:36:21.027  1134  1723 I C02B01/HrilExt: [NotifyToBoosterNet-(hril_manager_ext.cpp:454)] RilExt: HNOTI_BOOSTER_NET_IND report to booster net finish
   11-15 16:36:21.027  1134  1723 I P01FFF/Rilvendor: CHAN [HandleUnsolicited] HandleUnsolicited done for modem:0, index:0, atResponse:^BOOSTERNTF: 3, 20,"0600100001000004000000000102A4FF0202F6FF"
   11-15 16:36:21.802  2809  2831 E C02D06/XCollie: Send kick,foundation to hungtask Successful
   11-15 16:36:21.911   882  3016 I C01F0B/TelephonyVSim: state machine ProcessEvent Id: 125
   11-15 16:36:21.911   882  3016 I C01F0B/TelephonyVSim: StateProcess
   ```

Display the time in nanoseconds.

   ```shell
   $ hilog -v nsec
   11-15 16:37:09.010658555  1134  1723 I C02B01/HrilExt: [BoosterRawInd-(hril_booster.cpp:296)] RilExt: BoosterRawInd
   11-15 16:37:09.010676263  1134  1723 I C02B01/HrilExt: [BoosterRawInd-(hril_booster.cpp:328)] check need notify to satellite:indType 6
   11-15 16:37:09.010800221  1134  1723 I C02B01/HrilExt: [NotifyToBoosterTel-(hril_manager_ext.cpp:436)] RilExt: report to telephony ext, requestNum: 4201
   11-15 16:37:09.011011680  1134  1723 I C02B01/HrilExt: [NotifyToBoosterTel-(hril_manager_ext.cpp:440)] RilExt:Notify to booster tel finish
   11-15 16:37:09.011064805  1134  1723 I C02B01/HrilExt: [NotifyToBoosterNet-(hril_manager_ext.cpp:450)] RilExt: HNOTI_BOOSTER_NET_IND report to booster net
   11-15 16:37:09.011200742  1134  1723 I C02B01/HrilExt: [NotifyToBoosterNet-(hril_manager_ext.cpp:454)] RilExt: HNOTI_BOOSTER_NET_IND report to booster net finish
   ```
<!--RP10End-->

## Checking and Setting Persisting Tasks

**Viewing persist tasks**

```shell
hilog -w query
```

No persist task exists:

```shell
$ hilog -w query
Persist task query failed
No running persistent task [CODE: -63]
```

Persist tasks exist:

```shell
$ hilog -w query
1 init,core,app,only_prerelease zlib /data/log/hilog/hilog 4.0M 1000
2 kmsg zlib /data/log/hilog/hilog_kmsg 4.0M 100
```

**Enabling a persist task**

> **NOTE**
>
> You can only enable a persist task when no persist task exists. If a persist task exists, stop it first.

Enable a HiLog persist task and set the number of persist files to **1000**.

```shell
$ hilog -w start -n 1000
Persist task [jobid:1][fileNum:1000][fileSize:4194304] start successfully
```

Enable a kmsglog persist task and set the number of persist files to **100**.

```shell
$ hilog -w start -n 100 -t kmsg
Persist task [jobid:2][fileNum:100][fileSize:4194304] start successfully
```

When enabling a persist task, you can customize the persist rules. The compression mode can be **zlib**, **zstd**, or **none**.

For example, run the following command to set the persistent file name to **kmsglog**, file size to **2 MB**, number of files to **100**, and compression mode to **zlib**:

```shell
$ hilog -w start -t kmsg -f kmsglog -l 2M -n 100 -m zlib
Persist task [jobid:2][fileNum:100][fileSize:2097152] start successfully
```

**Disabling a persist task**

Stop the current persist task:

```shell
$ hilog -w stop
Persist task [jobid:1] stop successfully
Persist task [jobid:2] stop successfully
```

## Displaying and Setting Log Levels

**Viewing the Global Log Level**

```shell
$ param get hilog.loggable.global
I
```
<!--RP17-->
The default global log level is **INFO**.
<!--RP17End-->

<!--RP16-->
## Setting Log Levels

   ```text
   // Set the global log level. The setting does not take effect after the device restarts.
   hilog -b D/I/W/E/F

   // Set the global log level. The setting still takes effect after the device is restarted.
   hilog -b D/I/W/E/F --persist

   // Set the log level of [DOMAINID] of the LOG_APP type.
   hilog -b D/I/W/E/F -D 0x[DOMAINID]

   // Set the log level of [TAG].
   hilog -b D/I/W/E/F -T [TAG]
   ```

   **Example**

   ```shell
   $ hilog -b E
   Set global log level to E successfully

   $ hilog -b E --persist
   Set global log level to E successfully
   Set persist global log level to E successfully

   $ hilog -b D -D 0x2d00
   Set domain 0x2d00 log level to D successfully

   $ hilog -b E -T testTag
   Set tag testTag log level to E successfully
   ```
<!--RP16End-->

## Other Common Commands

### Displaying the Log Buffer Size

```shell
hilog -g
```

**Example**

```shell
$ hilog -g
Log type app buffer size is 16.0M
Log type init buffer size is 16.0M
Log type core buffer size is 16.0M
Log type only_prerelease buffer size is 16.0M
```

### Setting the Log Buffer Size

```shell
hilog -G size
```

**Example**

```shell
$ hilog -G 16M
Set log type app buffer size to 16.0M successfully
Set log type init buffer size to 16.0M successfully
Set log type core buffer size to 16.0M successfully
Set log type only_prerelease buffer size to 16.0M successfully
```

### Clearing the Log Buffer

```shell
hilog -r
```

**Example**

```shell
$ hilog -r
Log type core,app,only_prerelease buffer clear successfully
```

### Setting Kernel Log Reading

```shell
hilog -k on/off
```

**Example**

```shell
$ hilog -k on
Set hilogd storing kmsg log on successfully

$ hilog -k off
Set hilogd storing kmsg log off successfully
```

### Displaying Statistics

```shell
hilog -s
```

> **NOTE**
>
> You need to run the **param set persist.sys.hilog.stats true** command to enable the statistics functionality, and restart the device before starting statistics collection.

**Example**

```shell
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

```shell
MAX_FREQ: the maximum number of log lines per second
TIME: occurrence time
MAX_TP: the maximum number of bytes per second
LINES: the total number of lines in a statistical period
LENGTH: the total number of bytes in a statistical period
DROPPED: the number of dropped lines in a statistical period
```

### Clearing Statistics

```shell
hilog -S
```

**Example**

```shell
$ hilog -S
Statistic info clear successfully
```

### Setting Process Flow Control

```shell
hilog -Q pidon/pidoff
```

**Example**

Enable process flow control:

```shell
$ hilog -Q pidon
Set flow control by process to enabled successfully
```

Disable process flow control:

```shell
$ hilog -Q pidoff
Set flow control by process to disabled successfully
```

### Setting Domain Flow Control

```shell
hilog -Q domainon/domainoff
```

**Example**

Enable domain flow control:

```shell
$ hilog -Q domainon
Set flow control by domain to enabled successfully
```

Disable domain flow control:

```shell
$ hilog -Q domainoff
Set flow control by domain to disabled successfully
```

## HiLog Flow Control Mechanism

When the number of logs exceeds the upper limit, the HiLog flow control mechanism is triggered to discard excess logs and display a warning log. By default, this mechanism is disabled for debug applications.

The flow control mechanism is as follows:

### Application Logs

The flow control is performed by process. The application logs printed in the **LOG_APP** buffer adapt to the PID flow control mechanism. When the number of logs of the **LOG_APP** type printed by a process exceeds the threshold within one second, the flow control is triggered. The following example shows the warning log:

<!--RP11-->
```text
04-19 17:02:34.219  5394  5394 W A00032/LOGLIMIT: ==com.example.myapplication LOGS OVER PROC QUOTA, 3091 DROPPED==
```
<!--RP11End-->

This log indicates that the number of logs printed by the **com.example.myapplication** process exceeds the threshold at **17:02:34**. In the previous second of **17:02:34.219**, 3091 lines of logs are discarded due to flow control and are not printed.

**Solution**: Disable the process control mechanism by referring to [Setting Process Flow Control](#setting-process-flow-control).


### System Logs

The flow control is performed by domain ID. The system logs printed in the **LOG_CORE** buffer adapt to the domain flow control mechanism. When the number of logs of the **LOG_CORE** type printed by a domain ID exceeds the threshold within one second, the flow control is triggered. The following is an example of the warning log:

<!--RP12-->
```text
04-19 17:02:34.219  5394  5394 W C02C02/LOGLIMIT: 108 line(s) dropped in a second!
```
<!--RP12End-->

This log indicates that the number of logs printed by domain ID **02C02** exceeds the threshold at **17:02:34**. In the previous second of **17:02:34.219**, 108 lines of logs are discarded due to flow control and are not printed.

**Solution**: Disable the domain control mechanism by referring to [Setting Domain Flow Control](#setting-domain-flow-control).


## Handling Log Loss

Currently, maintenance and debugging information is available in all log loss scenarios. You can search for the corresponding keyword in HiLog to view the causes.

You can use regular expressions to search for log lines containing the keywords **LOGLIMIT**, **Slow reader missed**, and **write socket failed**.

**LOGLIMIT** indicates that log loss occurs due to process or domain flow control. **Slow reader missed** indicates that global logs are lost. **write socket failed** indicates that process logs are lost.

> **NOTE**
>
> When these messages are displayed, logs are lost and cannot be restored.
> 
> If the log loss issue occurs in the online O&M scenario, rectify the fault by referring to the following method, reproduce the issue locally, and view the complete logs.


### LOGLIMIT

**LOGLIMIT** indicates that the number of printed logs exceeds the threshold defined by the process or domain flow control. If domain logs exceed the HiLog specifications, you must reduce and correct them at the domain level. The following is an example of the warning log:

<!--RP13-->
```text
04-19 17:02:34.219  5394  5394 W A00032/LOGLIMIT: ==com.example.myapplication LOGS OVER PROC QUOTA, 3091 DROPPED==
```
<!--RP13End-->

**Solution**: Disable the corresponding control mechanism by referring to [HiLog Flow Control Mechanism](#hilog-flow-control-mechanism)


### Slow reader missed

**Slow reader missed** indicates that a large number of logs are generated before and after the printing time point. As a result, the logs in the HiLog buffer are overwritten circularly before they are persisted. The following is an example of the warning log:

```text
04-19 17:02:34.219     0     0 I C00000/HiLog: ========Slow reader missed log lines: 137
```

**Cause**: Global logs are lost in any of the following situations:

- The log level is set to **D**.

- The flow control is disabled.

- A module is repeatedly printing logs.

**Solution**

- Run the **hilog -g** command to query the buffer size. (The default size of the HiLog buffer is 256 KB.)

- Run the **hilog -G** command to increase the HiLog buffer size. For example, run the following command to change the buffer size to 16 MB (the maximum size is 16 MB):

  ```shell
  hilog -G 16M
  ```

- Check whether logs are frequently printed in the background. If logs of a domain are frequently printed and log reading is affected, you can run the command to disable the log printing of the domain by referring to the "Solution" of **write socket failed**.


### write socket failed

**write socket failed** indicates that logs fail to be written into the socket and packet loss occurs. The following is an example of the warning log:

<!--RP14-->
```text
04-19 17:02:34.219  5394  5394 W A00032/HiLog: write socket failed, 8 line(s) dropped!
```
<!--RP14End-->

**Cause**: Process logs are lost in any of the following situations:

- The log level is set to **D**.

- The flow control is disabled.

- A module is repeatedly printing logs.

- If a high CPU load or insufficient memory issue occurs, the socket server processes logs slowly and logs are stacked in the socket channel. As a result, the client fails to write socket data.

**Solution**: Disable the log printing of other domains and print only the logs of the current module.

- Disable the log printing of other domains:

  ```shell
  hilog -b X
  ```

- Enable the log printing of the current module:

  **LOG_APP**:

  ```shell
  hilog -b I -D 0x3200  (Set the log print level of the 03200 domain to INFO.)
  
  hilog -b I -D 0x3201  (Set the log print level of the 03201 domain to INFO.)
  ```

  **LOG_CORE**:

  ```shell
  hilog -b I -D d003200  (Set the log print level of the 03200 domain to INFO.)
  
  hilog -b I -D d003201  (Set the log print level of the 03201 domain to INFO.)
  ```
