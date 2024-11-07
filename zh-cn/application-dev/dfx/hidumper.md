# hidumper

HiDumper为开发、测试人员提供统一的系统信息获取工具，可帮助使用者分析，定位问题。

## 环境要求

- 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)。

- 正常连接设备。

## 命令行说明

| 选项 | 说明 |
| -------- | -------- |
| -h  | 帮助命令。 |
| -lc | 列出系统信息集群。 |
| -ls | 列出系统能力。 |
| -c | 获取系统信息集群详细信息。 |
| -c [base system] | 获取"base"或者"system"信息集群详细信息。 |
| -s | 获取所有系统能力详细信息。 |
| -s [SA0 SA1] | 获取一个或多个系统能力详细信息。 |
| -s [SA] -a ["option"] | 执行单个系统能力的特定选项。SA表示系统能力名称，option表示该系统能力支持的选项。可通过 -s [SA] -a ["-h"] 获取单个系统能力支持的所有选项。|
| -e | 获取崩溃历史记录的故障日志。 |
| --net [pid] | 获取网络信息。如果指定了进程的pid，则只输出该进程的网络流量使用信息。 |
| --storage [pid] | 获取存储信息。如果指定了进程的pid，则只输出该进程的io信息。 |
| -p [pid] | 获取进程信息，包括进程和线程的列表和信息。 |
| --cpuusage [pid] | 获取CPU使用率,按进程和类别分类；如果指定pid，则获取指定pid的CPU使用信息。 |
| --cpufreq | 获取CPU每个核的真实频率。 |
| --mem [pid] | 获取总内存占用率；如果指定pid，则获取指定pid的内存占用率。 |
| --zip | 保存命令输出到/data/log/hidumper下的压缩文件。 |
| --ipc pid/-a --start-stat/stop-stat/stat | 统计一段时间进程IPC信息，如果使用-a则统计所有进程IPC数据，--start-stat开始统计，--stat获取统计数据，--stop-stat结束统计。 |
| --mem-smaps pid [-v] | 获取pid内存统计信息，数据来源于/proc/pid/smaps，使用-v指定更多详细信息。 (仅限制debug版本使用) |
| --mem-jsheap pid [-T tid] [--gc] | pid 必选参数。命令触发所有线程gc和快照导出。如果指定线程的tid，只触发该线程gc和快照导出；如果指定--gc，只触发gc不做快照导出。 |

## 常用命令

1. 查看帮助命令。

    ```
    hidumper -h
    ```

    **使用样例：**

    ```
    $ hidumper -h
    usage:
    -h                          |help text for the tool
    -lc                         |a list of system information clusters
    -ls                         |a list of system abilities
    -c                          |all system information clusters
    -c [base system]            |system information clusters labeled "base" and "system"
    -s                          |all system abilities
    -s [SA0 SA1]                |system abilities labeled "SA0" and "SA1"
    -s [SA] -a ['-h']           |system ability labeled "SA" with arguments "-h" specified
    -e                          |faultlogs of crash history
    --net [pid]                 |dump network information; if pid is specified, dump traffic usage of specified pid
    --storage [pid]             |dump storage information; if pid is specified, dump /proc/pid/io
    -p                          |processes information, include list and infromation of processes and threads
    -p [pid]                    |dump threads under pid, includes smap, block channel, execute time, mountinfo
    --cpuusage [pid]            |dump cpu usage by processes and category; if PID is specified, dump category usage of specified pid
    --cpufreq                   |dump real CPU frequency of each core
    --mem [pid]                 |dump memory usage of total; dump memory usage of specified pid if pid was specified
    --zip                       |compress output to /data/log/hidumper
    --mem-smaps pid [-v]        |display statistic in /proc/pid/smaps, use -v specify more details
    --mem-jsheap pid [-T tid] [--gc]  |triggerGC and dumpHeapSnapshot under pid and tid
    --ipc pid ARG               |ipc load statistic; pid must be specified or set to -a dump all processes. ARG must be one of --start-stat | --stop-stat | --stat
    ```

2. 列出系统信息集群。

    ```
    hidumper -lc
    ```

    **使用样例：**

    ```
    $ hidumper -lc
    System cluster list:
    base                             system
    ```

3. 列出系统能力。

    ```
    hidumper -ls
    ```

    **使用样例：**

    ```
    $ hidumper -ls
    System ability list:
    SystemAbilityManager             RenderService                    AbilityManagerService
    DataObserverMgr                  AccountMgr                       AIEngine
    BundleMgr                        FormMgr                          ApplicationManagerService
    AccessibilityManagerService      UserIdmService                   UserAuthService
    AuthExecutorMgrService           PinAuthService                   FaceAuthService
    FingerprintAuthService           WifiDevice                       WifiHotspot
    WifiP2p                          WifiScan                         1125
    1126                             BluetoothHost                    NetConnManager
    NetPolicyManager                 NetStatsManager                  NetTetheringManager
    ...
    ```

4. 获取系统信息集群详细信息。

    ```
    hidumper -c
    ```

    **使用样例：**

    ```
    $ hidumper -c

    -------------------------------[base]-------------------------------

    BuildId: OpenHarmony 5.0.0.37
    RleaseType: Canary1
    ...
    ```

5. 获取"base"或者"system"信息集群详细信息。

    ```
    hidumper -c base
    hidumper -c system
    ```

    **使用样例：**

    ```
    $ hidumper -c base

    -------------------------------[base]-------------------------------

    BuildId: OpenHarmony 5.0.0.37
    RleaseType: Canary1
    ...

    $ hidumper -c system

    -------------------------------[system]-------------------------------


    cmd is: printenv

    _=/system/bin/printenv
    LANG=en_US.UTF-8
    HOME=/root
    PULSE_STATE_PATH=/data/data/.pulse_dir/state
    ...
    ```

6. 获取所有系统能力详细信息，命令格式如下：

    ```
    hidumper -s
    ```

    **使用样例：**

    ```
    $ hidumper -s

    -------------------------------[ability]-------------------------------


    ----------------------------------SystemAbilityManager----------------------------------
    The arguments are illegal and you can enter '-h' for help.

    -------------------------------[ability]-------------------------------


    ----------------------------------RenderService----------------------------------
    ------Graphic2D--RenderSerice ------
    Usage:
    h                             |help text for the tool
    ...
    ```

7. 获取一个或多个系统能力详细信息，命令格式如下：

    ```
    hidumper -s [SA0]
    hidumper -s [SA0] [SA1]
    ```

    **使用样例：**

    ```
    $ hidumper -s 4606

    -------------------------------[ability]-------------------------------


    ----------------------------------WindowManagerService----------------------------------
    Usage:
    -h                             |help text for the tool
    -a                             |dump all window information in the system
    -w {window id} [ArkUI Option]  |dump specified window information
    ------------------------------------[ArkUI Option]------------------------------------

    $ hidumper -s 4606 10

    -------------------------------[ability]-------------------------------


    ----------------------------------WindowManagerService----------------------------------
    Usage:
    -h                             |help text for the tool
    -a                             |dump all window information in the system
    -w {window id} [ArkUI Option]  |dump specified window information
    ------------------------------------[ArkUI Option]------------------------------------


    -------------------------------[ability]-------------------------------


    ----------------------------------RenderService----------------------------------
    ------Graphic2D--RenderSerice ------
    Usage:
    h                             |help text for the tool
    screen                         |dump all screen infomation in the system
    surface                        |dump all surface information
    composer fps                   |dump the fps info of composer
    ...
    ```

8. 执行单个系统能力的特定选项。
   
    获取RenderService的使用帮助，命令格式如下：

    ```
    hidumper -s RenderService -a "h" 
    ```

    **使用样例：**

    ```
    $ hidumper -s RenderService -a "h"

    -------------------------------[ability]-------------------------------


    ----------------------------------RenderService----------------------------------
    ------Graphic2D--RenderSerice ------
    Usage:
    h                             |help text for the tool
    screen                         |dump all screen infomation in the system
    surface                        |dump all surface information
    composer fps                   |dump the fps info of composer
    [surface name] fps             |dump the fps info of surface
    composer fpsClear              |clear the fps info of composer
    [windowname] fps               |dump the fps info of window
    [windowname] hitchs            |dump the hitchs info of window
    [surface name] fpsClear        |clear the fps info of surface
    nodeNotOnTree                  |dump nodeNotOnTree info
    allSurfacesMem                 |dump surface mem info
    RSTree                         |dump RSTree info
    EventParamList                 |dump EventParamList info
    allInfo                        |dump all info
    client                         |dump client ui node trees
    client-server                  |dump client and server info
    dumpMem                        |dump Cache
    trimMem cpu/gpu/shader         |release Cache
    surfacenode [id]               |dump node info
    fpsCount                       |dump the refresh rate counts info
    clearFpsCount                  |clear the refresh rate counts info
    vktextureLimit                 |dump vk texture limit info
    flushJankStatsRs|flush rs jank stats hisysevent
    ```

    获取对应surface的刷新帧率，可以使用以下命令，返回值为surface刷新帧对应的时间戳。

    ```
    hidumper -s RenderService -a "surface_name fps" 
    ```

    **使用样例：**

    ```
    $ hidumper -s RenderService -a "surface_name fps"

    -------------------------------[ability]-------------------------------


    ----------------------------------RenderService----------------------------------

    -- The recently fps records info of screens:
    ```

    为开发者提供使设备不自动息屏的能力。-t参数使设备不自动息屏，-f参数使设备恢复自动息屏，或者设备重启使设备恢复自动息屏。

    ```
    hidumper -s 3301 -a -t
    hidumper -s 3301 -a -f
    ```

    **使用样例：**

    ```
    $ hidumper -s 3301 -a -t

    -------------------------------[ability]-------------------------------


    ----------------------------------PowerManagerService----------------------------------
    $ hidumper -s 3301 -a -f

    -------------------------------[ability]-------------------------------


    ----------------------------------PowerManagerService----------------------------------
    ```

9. 获取Faultlog模块生成的崩溃历史信息。

    ```
    hidumper -e 
    ```

    **使用样例：**

    ```
    $ hidumper -e

    -------------------------------[faultlog]-------------------------------


    /data/log/faultlog/faultlogger/syswarning-com.ohos.sceneboard-20020022-20241106104006

    Generated by HiviewDFX@OpenHarmony
    ...
    ```

10. 获取网络信息；如果指定了进程的pid，则只获取该进程的网络流量使用信息。

    ```
    hidumper --net pid
    hidumper --net
    ```

    **使用样例：**

    ```
    $ hidumper --net 1

    -------------------------------[net traffic]-------------------------------

    Received Bytes:0
    Sent Bytes:51885
    
    $ hidumper --net

    -------------------------------[net traffic]-------------------------------

    Received Bytes:0
    Sent Bytes:51885
    
    -------------------------------[net]-------------------------------

    cmd is: netstat -nW
    ...

    ```


11. 获取存储信息。如果指定了进程的pid，则只输出该进程的io信息。

    ```
    hidumper --storage pid
    hidumper --storage
    ```

    **使用样例：**

    ```
    $ hidumper --storage 1

    -------------------------------[storage io]-------------------------------


    /proc/1/io

    rchar: 28848175
    wchar: 4364169
    syscr: 16886
    syscw: 15866
    read_bytes: 30617600
    write_bytes: 10907648
    cancelled_write_bytes: 7340032
    $ hidumper --storage

    -------------------------------[storage]-------------------------------


    cmd is: storaged -u -p
    ...
    ```


12. 获取进程信息，包括进程、线程的列表等信息。

    ```
    hidumper -p pid
    hidumper -p
    ```

    **使用样例：**

    ```
    $ hidumper -p 64949

    -------------------------------[processes]-------------------------------


    cmd is: ps -efT -p 64949

    UID            PID   TID  PPID TCNT STIME TTY          TIME CMD
    20020169     64949 64949   629   17 11:40:14 ?     00:00:00 com.example.jsleakwatcher
    20020169     64949   733   629   17 11:40:28 ?     00:00:00 com.example.jsleakwatcher
    ...
    $ hidumper -p

    -------------------------------[processes]-------------------------------


    cmd is: ps -efT

    UID            PID   TID  PPID TCNT STIME TTY          TIME CMD
    root             1     1     0    1 10:46:59 ?     00:00:08 init --second-stage 2389791
    root             2     2     0  127 10:46:59 ?     00:00:24 [sysmgr-main]
    root             2     4     0  127 10:46:59 ?     00:00:00 [call_ebr]
    ...
    ```

13. 获取CPU使用率，根据进程和类别分类展示。

    ```
    hidumper --cpuusage pid
    hidumper --cpuusage
    ```

    **使用样例：**

    ```
    $ hidumper --cpuusage 1

    -------------------------------[cpuusage]-------------------------------

    Load average: 12.1 / 12.2 / 12.1; the cpu load average in 1 min, 5 min and 15 min
    CPU usage from 2024-11-06 11:59:33 to 2024-11-06 11:59:35
    Total: 3.80%; User Space: 1.45%; Kernel Space: 2.35%; iowait: 0.00%; irq: 0.14%; idle: 96.06%
    Details of Processes:
        PID   Total Usage      User Space    Kernel Space    Page Fault Minor    Page Fault Major    Name
        1          0.00%           0.00%          0.00%           38368                1394            init
    $ hidumper --cpuusage

    -------------------------------[cpuusage]-------------------------------

    Load average: 12.1 / 12.2 / 12.1; the cpu load average in 1 min, 5 min and 15 min
    CPU usage from 2024-11-06 11:59:33 to 2024-11-06 11:59:38
    Total: 6.38%; User Space: 2.57%; Kernel Space: 3.81%; iowait: 0.02%; irq: 0.14%; idle: 93.46%
    Details of Processes:
        PID   Total Usage      User Space    Kernel Space    Page Fault Minor    Page Fault Major    Name
        105      109.01%           0.00%        109.01%             164                   0            tppmgr.elf
        2          0.89%           0.00%          0.89%               0                   0            sysmgr-main
    ...
    ```

14. 获取CPU每个核的真实频率。

    ```
    hidumper --cpufreq
    ```

    **使用样例：**

    ```
    $ hidumper --cpufreq

    -------------------------------[cpufreq]-------------------------------


    cmd is: cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq

    1018000

    cmd is: cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq

    1530000
    ...
    ```

15. 获取设备中所有pid的内存信息。

    ```
    hidumper --mem
    ```

    **使用样例：**

    ```
    $ hidumper --mem
    -------------------------------[memory]-------------------------------
    Total Memory Usage by PID:
    PID       Total Pss(xxx in SwapPss)   Total Vss   Total Rss   Total Uss          GL       Graph         Dma     PurgSum     PurgPin    Name
    1          4309(2216 in SwapPss) kB  2158196 kB     4180 kB     1760 kB        0 kB        0 kB        0 kB        0 kB        0 kB    init
    2            45613(0 in SwapPss) kB 17452952 kB    48352 kB    44088 kB        0 kB        0 kB        0 kB        0 kB        0 kB    sysmgr-main
    ...
    ```

    获取设备中指定pid的内存信息。

    ```
    hidumper --mem pid
    ```

    **使用样例：**

    ```
    $ hidumper --mem 1

    -------------------------------[memory]-------------------------------

                            Pss        Shared        Shared       Private       Private          Swap       SwapPss          Heap          Heap          Heap
                        Total         Clean         Dirty         Clean         Dirty         Total         Total          Size         Alloc          Free
                        ( kB )        ( kB )        ( kB )        ( kB )        ( kB )        ( kB )        ( kB )        ( kB )        ( kB )        ( kB )
                --------------------------------------------------------------------------------------------------------------------------------------------
                GL             0             0             0             0             0             0             0             0             0             0
            Graph             0             0             0             0             0             0             0             0             0             0
    native heap           924             0             0           924             0          1948          1948             0             0             0
    AnonPage other            84            16             0            84             0            52            52             0             0             0
            stack            28             0             0            28             0             0             0             0             0             0
            .so           413          1548             0           248            56           216           216             0             0             0
            dev           190             0           856             0             0             0             0             0             0             0
    FilePage other           420             0             0           404            16             0             0             0             0             0
    ----------------------------------------------------------------------------------------------------------------------------------------------------------
            Total          4275          1564           856          1688            72          2216          2216             0             0             0

    native heap:
    jemalloc meta:           120             0             0           120             0            52            52             0             0             0
    jemalloc heap:           776             0             0           776             0          1888          1888             0             0             0
        brk heap:            20             0             0            20             0             8             8             0             0             0
        musl heap:             8             0             0             8             0             0             0             0             0             0

    Purgeable:
            PurgSum:0 kB
            PurgPin:0 kB

    DMA:
                Dma:0 kB
    ```

    **Graph字段统计方式为：计算/proc/process_dmabuf_info节点下该进程使用的内存大小。**
   
16. 保存命令输出到/data/log/hidumper下的压缩文件。

    ```
    hidumper --zip
    ```

    **使用样例：**

    ```
    $ hidumper --zip
    100%,[-],The result is:/data/log/hidumper/20241106-120444-166.zip
    ```

17. 统计一段时间进程IPC信息，如果使用-a则统计所有进程IPC数据，指定pid则统计对应进程的IPC数据。--start-stat开始统计，--stat获取统计数据，--stop-stat结束统计。

    ```
    hidumper --ipc pid --start-stat
    hidumper --ipc pid --stat
    hidumper --ipc pid --stop-stat
    ```

    **使用样例：**

    ```
    $ hidumper --ipc 1473 --start-stat
    StartIpcStatistics pid:1473 success
    $ hidumper --ipc 1473 --stat
    ********************************GlobalStatisticsInfo********************************
    CurrentPid:1473
    TotalCount:2
    TotalTimeCost:2214
    --------------------------------ProcessStatisticsInfo-------------------------------
    CallingPid:625
    CallingPidTotalCount:2
    CallingPidTotalTimeCost:2214
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~InterfaceStatisticsInfo~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    DescriptorCode:OHOS.ILocalAbilityManager_6
    DescriptorCodeCount:2
    DescriptorCodeTimeCost:
    Total:2214 | Max:1444 | Min:770 | Avg:1107
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ------------------------------------------------------------------------------------
    ************************************************************************************
    $ hidumper --ipc 1473 --stop-stat
    StopIpcStatistics pid:1473 success
    ```

    ```
    hidumper --ipc -a --start-stat
    hidumper --ipc -a --stat
    hidumper --ipc -a --stop-stat
    ```

    **使用样例：**

    ```
    $ hidumper --ipc -a --start-stat
    StartIpcStatistics pid:1473 success
    StartIpcStatistics pid:775 success
    StartIpcStatistics pid:1472 success
    ...
    $ hidumper --ipc -a --stat
    ********************************GlobalStatisticsInfo********************************
    CurrentPid:1473
    TotalCount:3
    TotalTimeCost:3783
    --------------------------------ProcessStatisticsInfo-------------------------------
    CallingPid:625
    CallingPidTotalCount:3
    ...
    $ hidumper --ipc -a --stop-stat
    StopIpcStatistics pid:1473 success
    StopIpcStatistics pid:775 success
    StopIpcStatistics pid:1472 success
    ...
    ```

18. 导出指定进程内存信息的详细使用情况。

    ```
    hidumper --mem-smaps pid [-v]
    ```

    > **注意**
    >
    > 该命令仅限debug版本使用，release版本不可用。
    >
    > 如何区分debug/release版本：
    >
    > 命令1：执行hdc shell "param get|grep const.debuggable"查看输出为0还是1。
    >
    > 命令2：执行hdc shell "param get|grep const.product.software.version"查看当前版本是否包含"log"字符串。
    >
    > release版本:命令1执行结果为0且命令2不包含"log"字符串
    >
    > debug版本:非release版本即为debug版本

    **使用样例：**

    ```
    $ hidumper --mem-smaps 1
    usage:
    -h                          |help text for the tool
    -lc                         |a list of system information clusters
    -ls                         |a list of system abilities
    -c                          |all system information clusters
    -c [base system]            |system information clusters labeled "base" and "system"
    -s                          |all system abilities
    -s [SA0 SA1]                |system abilities labeled "SA0" and "SA1"
    -s [SA] -a ['-h']           |system ability labeled "SA" with arguments "-h" specified
    -e                          |faultlogs of crash history
    --net [pid]                 |dump network information; if pid is specified, dump traffic usage of specified pid
    --storage [pid]             |dump storage information; if pid is specified, dump /proc/pid/io
    -p                          |processes information, include list and infromation of processes and threads
    -p [pid]                    |dump threads under pid, includes smap, block channel, execute time, mountinfo
    --cpuusage [pid]            |dump cpu usage by processes and category; if PID is specified, dump category usage of specified pid
    --cpufreq                   |dump real CPU frequency of each core
    --mem [pid]                 |dump memory usage of total; dump memory usage of specified pid if pid was specified
    --zip                       |compress output to /data/log/hidumper
    --mem-smaps pid [-v]        |display statistic in /proc/pid/smaps, use -v specify more details
    --mem-jsheap pid [-T tid] [--gc]  |triggerGC and dumpHeapSnapshot under pid and tid
    --ipc pid ARG               |ipc load statistic; pid must be specified or set to -a dump all processes. ARG must be one of --start-stat | --stop-stat | --stat
    
    $ hidumper --mem-smaps 1 -v
    usage:
    -h                          |help text for the tool
    -lc                         |a list of system information clusters
    -ls                         |a list of system abilities
    -c                          |all system information clusters
    -c [base system]            |system information clusters labeled "base" and "system"
    -s                          |all system abilities
    -s [SA0 SA1]                |system abilities labeled "SA0" and "SA1"
    -s [SA] -a ['-h']           |system ability labeled "SA" with arguments "-h" specified
    -e                          |faultlogs of crash history
    --net [pid]                 |dump network information; if pid is specified, dump traffic usage of specified pid
    --storage [pid]             |dump storage information; if pid is specified, dump /proc/pid/io
    -p                          |processes information, include list and infromation of processes and threads
    -p [pid]                    |dump threads under pid, includes smap, block channel, execute time, mountinfo
    --cpuusage [pid]            |dump cpu usage by processes and category; if PID is specified, dump category usage of specified pid
    --cpufreq                   |dump real CPU frequency of each core
    --mem [pid]                 |dump memory usage of total; dump memory usage of specified pid if pid was specified
    --zip                       |compress output to /data/log/hidumper
    --mem-smaps pid [-v]        |display statistic in /proc/pid/smaps, use -v specify more details
    --mem-jsheap pid [-T tid] [--gc]  |triggerGC and dumpHeapSnapshot under pid and tid
    --ipc pid ARG               |ipc load statistic; pid must be specified or set to -a dump all processes. ARG must be one of --start-stat | --stop-stat | --stat
    ```

19. 运行  **hidumper --mem-jsheap pid [-T tid] [--gc]**  pid 必选参数。命令触发所有线程gc和快照导出。如果指定线程的tid，只触发该线程gc和快照导出；如果指定--gc，只触发gc不做快照导出。(仅限debug版本使用)

    ```
    hidumper --mem-jsheap pid [-T tid] [--gc]
    ```

    > **注意**
    >
    > 该命令在release版本只支持导出debug应用的快照信息。
    >
    > 如何区分debug和release版本：同上。
    >
    > 导出的jsheap文件一般位于/data/log/faultlog/temp或/data/log/reliability/resource_leak/memory_leak下

    **使用样例：**

    ```
    $ hidumper --mem-jsheap 64949
    $ ls |grep hidumper
    hidumper-jsheap-64949-64949-1730872962493
    $ hidumper --mem-jsheap 64949 -T 64949
    $ ls |grep hidumper
    hidumper-jsheap-64949-64949-1730872962493
    $ hidumper --mem-jsheap 64949 --gc
    ```
