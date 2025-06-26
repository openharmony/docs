# HiDumper

HiDumper is a command-line tool used to export essential system information for analyzing and locating issues.

## Environment Setup

- The [environment setup](hdc.md#environment-setup) is complete.

- The devices are properly connected and **hdc shell** is executed.

## Command Description

| Commands| Description|
| -------- | -------- |
| -h  | Displays help information.|
| -lc | Lists system information clusters.|
| -ls | Lists system capabilities.|
| -c | Obtains the detailed information about the system information cluster.|
| -c [base system] | Obtains the detailed information about the base or system information cluster.|
| -s | Obtains the detailed information about all system capabilities.|
| -s [SA0 SA1] | Obtains the detailed information about one or more system capabilities.|
| -s [SA] -a ["option"] | Executes a specific option of a system capability. **SA** indicates a system capability, and **option** indicates an option supported by the system capability. You can run **-s [SA] -a ["-h"]** to obtain all options supported by a system capability.|
| -e | Obtains crash logs.|
| --net [pid] | Obtains network information. If **pid** is specified, obtains only the network traffic usage of the specified process.|
| --storage [pid] | Obtains storage information. If **pid** is specified, obtains the I/O information of the specified process.|
| -p [pid] | Obtains all process and thread information.|
| --cpuusage [pid] | Obtains the CPU usage by process and category. If **pid** is specified, obtains the CPU usage of the specified process.|
| --cpufreq | Obtains the actual CPU frequency.|
| --mem [pid] | Obtains the total memory usage. If **pid** is specified, obtains the memory usage of the specified process.|
| --zip | Saves the exported compressed file to **/data/log/hidumper**.|
| --ipc pid/-a --start-stat/stop-stat/stat | Collects the IPC statistics of a process in a period of time. **-a** is used to collect the IPC statistics of all processes, **--start-stat** is used to start collecting statistics, **--stat** is used to obtain statistics, and **--stop-stat** is used to stop collecting statistics.|
| --mem-smaps pid [-v] | Obtains the memory usage of a specified process from **/proc/pid/smaps**. **-v** is used to specify more details about the process. This command is only available in the Debug version.|
| --mem-jsheap pid [-T tid] [--gc] [--leakobj] |  Triggers Garbage Collection (GC) for all threads and exports their snapshots. **pid** is mandatory. If **tid** is specified, triggers GC for the specified thread and exports its snapshot. If **--gc** is specified, triggers GC but not exports the snapshot. If **--leakobj** is specified, obtains the list of leaked objects.|

## Examples

1. Display help information.

    ```
    hidumper -h
    ```

    **Example**

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
    -p                          |processes information, include list and information of processes and threads
    -p [pid]                    |dump threads under pid, includes smap, block channel, execute time, mountinfo
    --cpufreq                   |dump real CPU frequency of each core
    --mem [pid]                 |dump memory usage of total; dump memory usage of specified pid if pid was specified
    --zip                       |compress output to /data/log/hidumper
    --mem-smaps pid [-v]        |display statistic in /proc/pid/smaps, use -v specify more details
    --mem-jsheap pid [-T tid] [--gc] [--leakobj]  |triggerGC, dumpHeapSnapshot and dumpLeakList under pid and tid
    --ipc pid ARG               |ipc load statistic; pid must be specified or set to -a dump all processes. ARG must be one of --start-stat | --stop-stat | --stat
    --cpuusage [pid]            |dump cpu usage by processes and category; if PID is specified, dump category usage of specified pid
    ```

2. Lists system information clusters.

    ```
    hidumper -lc
    ```

    **Example**

    ```
    $ hidumper -lc
    System cluster list:
    base                             system
    ```

3. Lists system capabilities.

    ```
    hidumper -ls
    ```

    **Example**

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

4. Obtain the detailed information about the system information cluster.

    ```
    hidumper -c
    ```

    **Example**

    ```
    $ hidumper -c

    -------------------------------[base]-------------------------------

    BuildId: OpenHarmony 5.0.0.37
    ReleaseType: Canary1
    ...
    ```

5. Obtain the detailed information about the base or system information cluster.

    ```
    hidumper -c base
    hidumper -c system
    ```

    **Example**

    ```
    $ hidumper -c base

    -------------------------------[base]-------------------------------

    BuildId: OpenHarmony 5.0.0.37
    ReleaseType: Canary1
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

6. Obtain the detailed information about all system capabilities.

    ```
    hidumper -s
    ```

    **Example**

    ```
    $ hidumper -s

    -------------------------------[ability]-------------------------------


    ----------------------------------SystemAbilityManager----------------------------------
    The arguments are illegal and you can enter '-h' for help.

    -------------------------------[ability]-------------------------------


    ----------------------------------RenderService----------------------------------
    ------Graphic2D--RenderService ------
    Usage:
    h                             |help text for the tool
    ...
    ```

7. Obtain the detailed information about one or more system capabilities.

    ```
    hidumper -s [SA0]
    hidumper -s [SA0] [SA1]
    ```

    **Example**

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
    ------Graphic2D--RenderService ------
    Usage:
    h                             |help text for the tool
    screen                         |dump all screen information in the system
    surface                        |dump all surface information
    composer fps                   |dump the fps info of composer
    ...
    ```

8. Executes a specific option of a system capability.
   
    Obtain the help information about **RenderService**.

    ```
    hidumper -s RenderService -a "h" 
    ```

    **Example**

    ```
    $ hidumper -s RenderService -a "h"

    -------------------------------[ability]-------------------------------


    ----------------------------------RenderService----------------------------------
    ------Graphic2D--RenderService ------
    Usage:
    h                             |help text for the tool
    screen                         |dump all screen information in the system
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

    Obtain the refresh frame rate of a surface.

    ```
    hidumper -s RenderService -a "surface_name fps" 
    ```

    **Example**

    ```
    $ hidumper -s RenderService -a "surface_name fps"

    -------------------------------[ability]-------------------------------


    ----------------------------------RenderService----------------------------------

    -- The recently fps records info of screens:
    ```

    Use the **-t** parameter to disable the automatic screen-off functionality; use the **-f** parameter or restart the device to enable the automatic screen-off functionality.

    ```
    hidumper -s 3301 -a -t
    hidumper -s 3301 -a -f
    ```

    **Example**

    ```
    $ hidumper -s 3301 -a -t

    -------------------------------[ability]-------------------------------


    ----------------------------------PowerManagerService----------------------------------
    $ hidumper -s 3301 -a -f

    -------------------------------[ability]-------------------------------


    ----------------------------------PowerManagerService----------------------------------
    ```

9. Obtain the crash information generated by the Faultlog module.

    ```
    hidumper -e 
    ```

    **Example**

    ```
    $ hidumper -e

    -------------------------------[faultlog]-------------------------------


    /data/log/faultlog/faultlogger/syswarning-com.ohos.sceneboard-20020022-20241106104006

    Generated by HiviewDFX@OpenHarmony
    ...
    ```

10. Obtain network information. Specify **pid** to obtain the network traffic usage of the specified process.

    ```
    hidumper --net pid
    hidumper --net
    ```

    **Example**

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


11. Obtains storage information. If **pid** is specified, obtains the I/O information of the specified process.

    ```
    hidumper --storage pid
    hidumper --storage
    ```

    **Example**

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


12. Obtain all process and thread information.

    ```
    hidumper -p pid
    hidumper -p
    ```

    > **Note**
    >
    > In the Release version, this command can be used to export the process information of the debugging applications.
    >
    > How to distinguish the Debug and Release versions:
    >
    > 1. Run the **hdc shell "param get|grep const.debuggable"** command to check whether the output is **0** or **1**.
    >
    > 2. Run the **hdc shell "param get|grep const.product.software.version"** command to check whether the current version contains the **log** string.
    >
    > The Release version outputs **0** and does not contain the **log** string.
    >
    > The Debug version outputs **1** and contains the **log** string.

    **Example**

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

13. Obtain CPU usage, which is displayed by process and category.

    ```
    hidumper --cpuusage pid
    hidumper --cpuusage
    ```

    **Example**

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

14. Obtain the actual CPU frequency.

    ```
    hidumper --cpufreq
    ```

    **Example**

    ```
    $ hidumper --cpufreq

    -------------------------------[cpufreq]-------------------------------


    cmd is: cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq

    1018000

    cmd is: cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq

    1530000
    ...
    ```

15. Obtain memory usage of all processes.

    ```
    hidumper --mem
    ```

    **Example**

    ```
    $ hidumper --mem
    -------------------------------[memory]-------------------------------
    Total Memory Usage by PID:
    PID       Total Pss(xxx in SwapPss)   Total Vss   Total Rss   Total Uss          GL       Graph         Dma     PurgSum     PurgPin    Name
    1          4309(2216 in SwapPss) kB  2158196 kB     4180 kB     1760 kB        0 kB        0 kB        0 kB        0 kB        0 kB    init
    2            45613(0 in SwapPss) kB 17452952 kB    48352 kB    44088 kB        0 kB        0 kB        0 kB        0 kB        0 kB    sysmgr-main
    ...
    ```

    Obtain memory usage of the specified process on the device.

    ```
    hidumper --mem pid
    ```

    **Example**

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

    The **Graph** field represents the memory size used by the process in the **/proc/process_dmabuf_info** node.
   
16. Save the exported compressed file to **/data/log/hidumper**.

    ```
    hidumper --zip
    ```

    **Example**

    ```
    $ hidumper --zip
    100%,[-],The result is:/data/log/hidumper/20241106-120444-166.zip
    ```

17. Collect IPC statistics of the process in a period. Use **-a** to collect the IPC statistics of all processes. Specify **pid** to collect the IPC statistics of the specified process. Use **--start-stat** to start collecting statistics, use **--stat:** to obtain statistics, and use **--stop-stat** to stop collecting statistics.

    ```
    hidumper --ipc pid --start-stat
    hidumper --ipc pid --stat
    hidumper --ipc pid --stop-stat
    ```

    **Example**

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

    **Example**

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

18. Export the detailed memory usage of the specified process.

    ```
    hidumper --mem-smaps pid [-v]
    ```

    > **Note**
    >
    > This command is available only in the Debug version and is unavailable in the Release version.
    >
    > For details about how to distinguish the debug and release versions, see **hidumper -p**.

    **Example**

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
    -p                          |processes information, include list and information of processes and threads
    -p [pid]                    |dump threads under pid, includes smap, block channel, execute time, mountinfo
    --cpufreq                   |dump real CPU frequency of each core
    --mem [pid]                 |dump memory usage of total; dump memory usage of specified pid if pid was specified
    --zip                       |compress output to /data/log/hidumper
    --mem-smaps pid [-v]        |display statistic in /proc/pid/smaps, use -v specify more details
    --mem-jsheap pid [-T tid] [--gc] [--leakobj]  |triggerGC, dumpHeapSnapshot and dumpLeakList under pid and tid
    --ipc pid ARG               |ipc load statistic; pid must be specified or set to -a dump all processes. ARG must be one of --start-stat | --stop-stat | --stat
    --cpuusage [pid]            |dump cpu usage by processes and category; if PID is specified, dump category usage of specified pid
    
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
    -p                          |processes information, include list and information of processes and threads
    -p [pid]                    |dump threads under pid, includes smap, block channel, execute time, mountinfo
    --cpufreq                   |dump real CPU frequency of each core
    --mem [pid]                 |dump memory usage of total; dump memory usage of specified pid if pid was specified
    --zip                       |compress output to /data/log/hidumper
    --mem-smaps pid [-v]        |display statistic in /proc/pid/smaps, use -v specify more details
    --mem-jsheap pid [-T tid] [--gc] [--leakobj]  |triggerGC, dumpHeapSnapshot and dumpLeakList under pid and tid
    --ipc pid ARG               |ipc load statistic; pid must be specified or set to -a dump all processes. ARG must be one of --start-stat | --stop-stat | --stat
    --cpuusage [pid]            |dump cpu usage by processes and category; if PID is specified, dump category usage of specified pid
    ```

18. Run the **hidumper --mem-jsheap pid [-T tid] [--gc] [--leakobj]** command to trigger GC for all threads and export their snapshots. **pid** is mandatory. Specify **tid** to trigger GC and export snapshot of the specified thread. Specify **--gc** to trigger GC but not to export snapshot. Specify **--leakobj** to obtain the list of leaked objects. This command is only available in the Debug version.

    ```
    hidumper --mem-jsheap pid [-T tid] [--gc] [--leakobj]
    ```

    > **Note**
    >
    > In the Release version, this command can be used to export the snapshot information of the debugging applications.
    >
    > For details about how to distinguish the debug and release versions, see **hidumper -p**.
    >
    > The path to the jsheap file is **/data/log/faultlog/temp or /data/log/reliability/resource_leak/memory_leak**.

    **Example**

    ```
    $ hidumper --mem-jsheap 64949
    $ ls |grep hidumper
    hidumper-jsheap-64949-64949-1730872962493
    $ hidumper --mem-jsheap 64949 -T 64949
    $ ls |grep hidumper
    hidumper-jsheap-64949-64949-1730872962493
    $ hidumper --mem-jsheap 64949 --gc
    $ hidumper --mem-jsheap 64949 --leakobj
    $ ls |grep hidumper
    hidumper-jsheap-64949-64949-1730873174145
    hidumper-leaklist-64949-1730873210483
    ```
    
