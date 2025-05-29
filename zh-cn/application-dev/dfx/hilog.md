# hilog


HiLog日志系统，提供给系统框架、服务、以及应用，用于打印日志，记录用户操作、系统运行状态等。开发者可以通过hilog命令行查询相关日志信息。


## 环境要求

- 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)。

- 确保设备已正常连接，并执行hdc shell。


## 命令行说明

| 短选项 | 长选项 | 参数 | 说明 | 
| -------- | -------- | -------- | -------- |
| -h | --help | - | 帮助命令。 | 
| 缺省 | 缺省 | - | 阻塞读日志，不退出。 | 
| -x | --exit | - | 非阻塞读日志，读完退出。 | 
| -g | - | - | 查询buffer的大小，配合-t指定某一类型使用，默认app和core。 | 
| -G | --buffer-size | &lt;size&gt; | 设置指定&lt;type&gt;日志类型缓冲区的大小，配合-t指定某一类型使用，默认app和core， 可使用B/K/M为单位，范围为64K-16M。 | 
| -r | - | - | 清除buffer日志，配合-t指定某一类型使用，默认app和core。 | 
| <!--DelRow-->-p | --privacy | &lt;on/off&gt; | 支持系统调试时日志隐私开关控制。 | 
| <!--DelRow--> |  | on | 打开隐私开关，显示&lt;private&gt;。 | 
| <!--DelRow--> |  | off | 关闭隐私开关，显示明文。 | 
| -k | - | &lt;on/off&gt; | Kernel日志读取开关控制。 | 
|  |  | on | 打开读取kernel日志。 | 
|  |  | off | 关闭读取kernel日志。 | 
| -s | --statistics | - | 查询统计信息，需配合-t或-D使用。 | 
| -S | - | - | 清除统计信息，需配合-t或-D使用。 | 
| -Q | - | &lt;control-type&gt; | 流控缺省配额开关控制。 | 
|  |  | pidon | 进程流控开关打开。 | 
|  |  | pidoff | 进程流控开关关闭。 | 
|  |  | domainon | domain流控开关打开。 | 
|  |  | domainoff | domain流控开关关闭。 | 
| -L | --level | &lt;level&gt; | 指定级别的日志，示例：-L D/I/W/E/F。 | 
| -t | --type | &lt;type&gt; | 指定类型的日志，示例：-t app/core/init/only_prerelease。app为应用日志，core为系统日志，init为启动日志，only_prerelease为仅在系统release版本前打印的日志，应用开发者无需关注。| 
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
| -v | --format | &lt;format&gt; | 显示格式控制。 | 
|  |  | time | 显示本地时间。 | 
|  |  | color | 显示不同级别显示不同颜色，参数缺省级别颜色模式处理（按黑白方式）。 | 
|  |  | epoch | 显示相对1970时间。 | 
|  |  | monotonic | 显示相对启动时间。 | 
|  |  | usec | 显示微秒精度时间。 | 
|  |  | nsec | 显示纳秒精度时间。 | 
|  |  | year | 显示将年份添加到显示的时间。 | 
|  |  | zone | 显示将本地时区添加到显示的时间。 | 
|  |  | wrap | 日志换行显示时，新行不增加时间戳等前缀。 |
| -b | --baselevel | &lt;loglevel&gt; | 设置可打印日志的最低等级：D(DEBUG)/I(INFO)/W(WARN)/E(ERROR)/F(FATAL)。 | 
| | --persist| - |配置日志级别设置命令持久化（重启设置不会丢失）。|

## 常用命令

### 查看帮助命令

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

### 非阻塞读日志

   ```
   hilog -x
   ```

   **使用样例：**

   ```
   $ hilog -x
   11-15 15:51:02.087  2823  2823 I A01B05/com.ohos.sceneboard/AOD: AodClockFullScreen --> timeTextLineHeight:313.3333333333333 clockMarginTop:99
   11-15 15:51:02.087  2823  2823 I A01B05/com.ohos.sceneboard/AOD: AodClockFullScreen --> timeFontSize:114.48717948717947
   11-15 15:51:02.090  2823  2823 I A01B05/com.ohos.sceneboard/AOD: AodClockFullScreen --> timeTextWidth:202,timeTextHeight:292
   11-15 15:51:02.100  2823  2823 I A01B05/com.ohos.sceneboard/AOD: ComponentUtil --> Component(ComponentId-AodClockNumber) draw complete.
   11-15 15:51:02.110  1197  1197 E C01406/render_service/OHOS::RS: [LoadImgsbyResolution] Can't find resolution (1084 x 2412) in config file
   11-15 15:51:02.127  1197  1197 E C01406/render_service/OHOS::RS: [LoadImgsbyResolution] Can't find resolution (1084 x 2412) in config file
   ```

### 查看日志缓冲区大小

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

### 修改日志缓冲区大小

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

### 清除缓冲区日志

   ```
   hilog -r
   ```

   **使用样例：**
   ```
   $ hilog -r
   Log type core,app,only_prerelease buffer clear successfully
   ```

### 内核日志读取开关控制

   ```
   hilog -k on/off
   ```

   **使用样例：**
   ```
   $ hilog -k on
   Set hilogd storing kmsg log on successfully
   $ 
   $ hilog -k off
   Set hilogd storing kmsg log off successfully
   ```

### 查询统计信息

   ```
   hilog -s
   ```

   **使用样例：**
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

   **统计信息说明**
   ```
   MAX_FREQ：日志打印频率最高的每秒行数
   TIME：    对应发生时间
   MAX_TP：  日志打印频率最高的每秒字节数
   LINES：   统计周期内的总行数
   LENGTH：  统计周期内的总字节数
   DROPPED： 统计周期内丢失的行数
   ```

### 清除统计信息

   ```
   hilog -S
   ```

   **使用样例：**

   ```
   $ hilog -S
   Statistic info clear successfully
   ```

### 进程流控开关

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

### domain流控开关

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

### 查看指定级别日志

   ```
   hilog -L D/I/W/E/F
   ```

   **使用样例：**

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

### 查看指定类型日志

   ```
   hilog -t app
   ```

   **使用样例：**

   ```
   $ hilog -t app
   11-15 16:04:45.903  5630  5630 I A0A5A5/os.hiviewcare:staticSubscriber/Diagnosis: [DetectionFilter]820001084: switch off
   11-15 16:04:45.905  5630  5630 I A0A5A5/os.hiviewcare:staticSubscriber/Diagnosis: [DetectionFilter]847005050: frequency limit
   11-15 16:04:45.905  5630  5630 I A0A5A5/os.hiviewcare:staticSubscriber/Diagnosis: [SmartNotifyHandler]detections after filter: []
   11-15 16:04:45.905  5630  5630 I A0A5A5/os.hiviewcare:staticSubscriber/Diagnosis: [SmartNotifyHandler]no detections to detect
   11-15 16:04:45.924  5687  5687 I A01B06/common/KG: MetaBalls-SystemTopPanelController --> init charging status = 3
   ```

### 查看指定domain日志

   ```
   hilog -D 01B06
   ```

   **使用样例：**

   ```
   $ hilog -D 01B06
   11-15 16:04:54.981  5687  5687 I A01B06/common/KG: MetaBalls-MetaBallRenderer --> pressTime = 0 appearTime = 1731657885972
   11-15 16:04:54.981  5687  5687 I A01B06/common/KG: MetaBalls-MetaBallRenderer --> backAnimator on finish
   11-15 16:04:54.982  5687  5687 I A01B06/common/KG: MetaBalls-MetaBallRenderer --> setTimeout over 9s and begin animate on finish
   11-15 16:04:55.297  5687  5687 I A01B06/common/KG: MetaBalls-MetaBallRenderer --> chargingTextExitAnimation onFinish
   11-15 16:04:55.494  5687  5687 I A01B06/common/KG: MetaBalls-MetaBallRenderer --> uiExtension session send data success,type: exitAnimationFinish
   ```

### 查看指定TAG日志

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

### 查看缓冲区前n行日志

   ```
   hilog -a 8
   ```

   **使用样例：**

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

### 查看缓冲区后n行日志

   ```
   hilog -z 8
   ```

   **使用样例：**

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

### 查看指定进程日志

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

### 查看符合正则匹配关键字的日志

   ```
   hilog -e start
   ```

   **使用样例：**

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

### 查看和设置落盘任务

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
   >
   > 开启kmsglog落盘任务，并且设置落盘规则，其中压缩方式可以为zlib，zstd，none。以设置规则为例：文件名为kmsglog，大小为2M，数量为100个, 其压缩方式为zlib压缩，命令行为： hilog -w start -t kmsg -f kmsglog -l 2M -n 100 -m zlib

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
   $
   $ hilog -w start -t kmsg -f kmsglog -l 2M -n 100 -m zlib
   Persist task [jobid:2][fileNum:100][fileSize:2097152] start successfully
   ```

### 设置日志显示格式

   ```
   hilog -v time/color/epoch/monotonic/usec/nsec/year/zone/wrap
   ```

   **使用样例：**

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

### 查看和设置日志级别

   ```
   // 全局日志级别默认为Info，查询全局日志级别
   param get param get hilog.loggable.global

   // 设置全局日志级别
   hilog -b D/I/W/E/F

   // 设置[DOMAINID]可打印的日志级别
   hilog -b D/I/W/E/F -D [DOMAINID]

   // 设置[TAG]可打印的日志级别
   hilog -b D/I/W/E/F -T [TAG]

   // 设置全局日志级别，重启仍生效
   hilog -b D/I/W/E/F --persist
   ```

   **使用样例：**

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