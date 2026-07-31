# hidumper

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Lutao98-->
<!--Designer: @milkbread123-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=8524fb94d9fdbb23f729551fe489ee4015dca550 translatedAt=2026-07-31T01:31:31.256Z pushedAt=2026-07-31T07:22:55.501Z -->

hidumper is a command line tool used to export system information. It can analyze the usage of system resources such as CPU, memory, and storage, query the running status of system services, and locate resource usage exceptions and communication problems.

Based on the application scenarios supported by hidumper, this topic describes the following basic capabilities: querying memory, CPU usage, system capabilities, process, storage, and system information, obtaining system fault logs, exporting inter-process communication records, and compressing and dumping exported information.

For FAQs about hidumper, see [FAQs](#faqs).

## Environment Setup

- The [environment setup](hdc.md#environment-setup) is complete.

- The devices are properly connected and **hdc shell** is executed.

## Command Description

| Commands| Description|
| -------- | -------- |
| -h | Displays help information.|
| [-lc](#querying-system-information)| Lists system information clusters.|
| [-ls](#querying-system-service-list)| Lists the running system capabilities.|
| [-c](#querying-system-information)| Obtains the detailed information about all system information clusters, including device information, kernel information, and environment variables.|
| [-c [base system]](#querying-system-information)| Obtains details about a specified information cluster, which can be **base** or **system**.|
| [-s](#obtaining-system-service-details)| Obtains the detailed information about all system capabilities.|
| [-s [SA0 SA1]](#obtaining-system-service-details)| Obtains the detailed information about one or more system capabilities. Multiple system capability names are separated by spaces. You can run **-ls** to query the system capability name.|
| [-s [SA] -a ["option"]](#obtaining-capabilities-of-a-specified-system-service)| Executes a specific option of a system capability.<br>**SA**: system capability name.<br>**option**: options supported by the system capability. You can run **-s [SA] -a ["-h"]** to obtain all options supported by a system capability.|
| [-e](#obtaining-system-fault-logs)| Obtains fault logs. For details about the log specifications, see [CppCrash](cppcrash-guidelines.md#log-specifications), [JSCrash](jscrash-guidelines.md#log-specifications), and [AppFreeze](appfreeze-guidelines.md#log-specifications).|
| [-e --list [process_name] [-n num] [--since timestamp] [--until timestamp]](#obtaining-abnormal-exit-record-list)| Obtains the list of abnormal exit records.<br>Note: This parameter is supported since API version 22.|
| [-e --print [process_name] [-n num] [--since timestamp] [--until timestamp]](#obtaining-abnormal-exit-logs)| Obtains the abnormal exit fault log. For details about the log specifications, see [CppCrash](cppcrash-guidelines.md#log-specifications), [JSCrash](jscrash-guidelines.md#log-specifications), and [AppFreeze](appfreeze-guidelines.md#log-specifications).<br>Note: This parameter is supported since API version 22.|
| [-e --print record_id](#obtaining-abnormal-exit-logs)| Obtains the fault log of the specified abnormal exit record ID. For details about the log specifications, see [CppCrash](cppcrash-guidelines.md#log-specifications), [JSCrash](jscrash-guidelines.md#log-specifications), and [AppFreeze](appfreeze-guidelines.md#log-specifications).<br>Note: This parameter is supported since API version 22.|
| [--net [pid]](#querying-network-information)| Obtains network information, including network traffic, network API statistics, and IP information. If **pid** is specified, obtains only the network traffic usage of the specified process.|
| [--storage [pid]](#querying-storage-information)| Obtains storage information, including disk statistics, disk usage, and file handles. If **pid** is specified, the I/O information of the specified process is displayed.|
| [-p [pid]](#querying-process-information)| Obtains all process and thread information.|
| [-p pid --fd/--thread [-v]](#querying-fd-and-thread-information) | Obtains the file handle or thread information of the specified process. <br />When -v is specified, prints detailed information.<br />**Note:** Since API version 26.0.0, supports this parameter.|
| [--cpuusage [pid]](#querying-process-cpu-usage)| Obtains the CPU usage by process and category. If a PID is specified, the CPU usage of the specified PID is displayed. The value range is (0, Number of CPU cores].|
| [--cpufreq](#querying-cpu-frequency)| Obtains the actual CPU frequency of each core, in kHz.|
| [--mem [--prune]](#querying-device-memory)| Obtains the total memory usage. If **--prune** is specified, only simplified memory usage is exported.<br>Note: The **--prune** parameter is supported since API version 20.|
| <!--RP11-->[--mem pid [--show-ashmem] [--show-dmabuf]](#querying-process-memory) | Obtains the memory usage of the specified process.<br />When --show-ashmem is specified, additionally prints detailed ashmem usage information for the process.<br />When --show-dmabuf is specified, additionally prints detailed DMA memory usage information.<br />**Note:**<br />Since API version 20, supports --show-ashmem and --show-dmabuf for application processes.<br/>Since API version 23, supports --show-dmabuf for system service processes.<!--RP11End--> |
| [--zip](#compressing-exported-information)| Saves the command output to a compressed file in ZIP format in **/data/log/hidumper**.|
| [--ipc [pid]/-a --start-stat/stat/--stop-stat](#obtaining-ipc-information)| Collects IPC information of a process in a specified period. If **-a** is used, IPC information of all processes is collected. **--start-stat** starts the IPC information collection. **--stat** obtains the IPC information. **--stop-stat** stops the IPC information collection.|
| [--mem-smaps pid [-v]](#querying-process-memory)| Obtains the memory usage of a specified process from **/proc/pid/smaps**. **-v** is used to specify more details about the process. (This command is available only for [applications of the debug version](performance-analysis-kit-terminology.md#applications-of-the-debug-version).)<br>Note: This parameter is supported since API version 20.|
| [--mem-jsheap pid [-T tid] [--gc] [--leakobj] [--raw] [--clean] [--single]](#querying-vm-heap-memory) | pid is a mandatory parameter. Triggers GC and heap memory snapshot export for the JS thread of an ArkTS app. File naming format: <!--RP1-->jsheap-ProcessID-JSThreadID-Timestamp<!--RP1End-->. The file content is a JS heap snapshot in JSON structure.<br />When thread tid is specified, triggers GC and heap memory snapshot export only for that thread.<br />When --gc is specified, triggers only GC without exporting a snapshot.<br />When --leakobj is specified, the app enables leak detection to obtain a list of leaked objects.<br />When --raw is specified, the heap snapshot is exported in rawheap format.<br />When --clean is specified, triggers cleanup of nodeId information after snapshot export.<br />When --single is specified, exports one snapshot per process, supports only rawheap format, and must be used with the --raw command.<br />When exporting a snapshot, the app must be in a bright screen state.<br />**Note:**<br />Since API version 19, supports the --raw parameter.<br />Since API version 24, supports the --clean parameter.<br />Since API version 26.0.0, supports the --single parameter.<br />Since API version 26.0.0, [release version apps](performance-analysis-kit-terminology.md#applications-of-the-release-version) support this command, but must also meet the [profileable tag](../quick-start/app-configuration-file.md#tags-in-the-configuration-file), enterprise-type [appDistributionType](../reference/apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1), and developer mode enabled. |
| <!--DelRow-->[--mem-cjheap pid [--gc]](#querying-vm-heap-memory)| Triggers GC and exports a heap snapshot for the Cangjie application. The **pid** parameter is mandatory. If **--gc** is specified, only GC is triggered. No snapshot is exported.<br>Note: This parameter is supported since API version 20.|
| <!--RP13-->[--mem-heap pid ARG [--leakobj]](#querying-vm-heap-memory) | Exports memory snapshot information of the specified type. ARG specifies the snapshot type. Currently supports --native and --kotlin types.<br />When --leakobj is specified, triggers only printing of suspected memory leak points without snapshot export, and is used only with the --native parameter.<br />**Note:** Since API version 26.0.0, supports the --leakobj parameter and --kotlin type snapshot export.<!--RP13End--> |

## Querying Memory Information

The hidumper memory information query module is used to view device memory usage and process memory usage. To use this module, you need to understand the [basic memory knowledge](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-memory-basic-knowledge).

### Querying Device Memory

Run the **hidumper --mem** command to obtain the device memory usage.

The output is as follows:

```shell
$ hidumper --mem
-------------------------------[memory]-------------------------------
Total Memory Usage by PID:
PID       Total Pss(xxx in SwapPss)   Total Vss   Total Rss   Total Uss          GL       Graph         Dma     PurgSum     PurgPin    Name
1          4309(2216 in SwapPss) kB  2158196 kB     4180 kB     1760 kB        0 kB        0 kB        0 kB        0 kB        0 kB    init
2            45613(0 in SwapPss) kB 17452952 kB    48352 kB    44088 kB        0 kB        0 kB        0 kB        0 kB        0 kB    sysmgr-main
...
Total Memory Usage by Size:
PID        Total Pss(xxx in SwapPss)    Total Vss    Total Rss    Total Uss           GL        Graph          Dma      PurgSum      PurgPin     Name
3031         421826(0 in SwapPss) kB   5199308 kB    610812 kB    395712 kB         0 kB     17000 kB     17000 kB         0 kB         0 kB     xxx
1473         409349(0 in SwapPss) kB   7014040 kB    449460 kB    389528 kB    160336 kB     57092 kB     57092 kB         0 kB         0 kB     xxx
...
Total Pss by OOM adjustment:
System: 1426777 kB
   xxx(pid=1473):  409349 kB
   xxx(pid=992):     80734 kB (23720 kB in SwapPss)
...
Total Pss by Category:
File-backed Page(1414160 kB):
      1053457 kB : .so
       322813 kB : other
        25616 kB : .hap
         8064 kB : .ttf
         3696 kB : .db
          514 kB : dev
Anonymous Page(2280332 kB):
      1348463 kB : native heap
       518107 kB : ark ts heap
       361195 kB : other
        49287 kB : stack
         3280 kB : dev
            0 kB : guard
GPU(160340 kB):
       160340 kB : GL
Graph(350708 kB):
       350708 kB : Graph
DMA(350708 kB):
       350708 kB : Dma

      Total RAM:15803612 kB
       Free RAM:10287099 kB (3999535 cached + 6287564 free)
       Used RAM:3961668 kB (3163324 total pss + 798344 kernel)
       Lost RAM:2086013 kB

Total RAM by Category:
hidumper - Hardware Usage:1860480 kB
      CMA Usage:0 kB
-   Kernel Usage:656937 kB
Processes Usage:3694492 kB

Total Purgeable:
  Total PurgSum:0 kB
  Total PurgPin:0 kB
```

Virtual Set Size (VSS) is the virtual memory size of the process, including all memory areas mapped to the process address space.

Resident Set Size (RSS) is the size of memory actually resident in physical memory for the process.

Proportional Set Size (PSS) is a more accurate method of measuring memory usage. It allocates the memory consumed by shared libraries among all processes using them in proportion to their actual share.

Purgeable Summary (PurgSum) is the total amount of memory that can be reclaimed by the process.

Purgeable Pinned (PurgPin) is memory that is reclaimable but not immediately reclaimable.

GL indicates the GPU memory usage, including both the memory consumed by applications and that produced by unified rendering in the service process.

Graph indicates the graphics memory, that is, the DMA memory.

You can run the **hidumper --mem --prune** command to obtain the simplified device memory usage.

The output is as follows:

```shell
$ hidumper --mem --prune
-------------------------------[memory]-------------------------------
Total Memory Usage by PID:
PID        Total Pss(xxx in SwapPss)           GL     AdjLabel     Name
1           4061(1668 in SwapPss) kB         0 kB        -1000     xxx
2            101723(0 in SwapPss) kB         0 kB        -1000     xxx
...
```

AdjLabel indicates the memory reclaim priority of the process. The value ranges from -1000 to 1000. A larger value indicates that the process is less important, and the memory is reclaimed first.

### Querying Process Memory

Run the **hidumper --mem pid** command to obtain the memory usage of a specified process. **pid** indicates the process ID.

<!--RP18-->
<!--RP18End-->

Example:

```shell
$ hidumper --mem 27336

-------------------------------[memory]-------------------------------

                          Pss         Shared         Shared        Private        Private           Swap        SwapPss           Heap           Heap           Heap
                        Total          Clean          Dirty          Clean          Dirty          Total          Total           Size          Alloc           Free
                       ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )
              ------------------------------------------------------------------------------------------------------------------------------------------------------
            GL              0              0              0              0              0              0              0              0              0              0
         Graph              0              0              0              0              0              0              0              0              0              0
   ark ts heap          12676           5516              0          12468              0           3068           3068              0              0              0
         guard              0              0              0              0              0              0              0              0              0              0
   native heap          15427          27132              0          14424              0          18776          18776          55796          53564           2809
          .hap              4              0              0              4              0              0              0              0              0              0
AnonPage other           1109           4932              0            968              0           4280           4280              0              0              0
         stack           1404              0              0           1404              0             28             28              0              0              0
           .db             32              0              0             32              0              0              0              0              0              0
           .so          12877          58928          18868           5628           2028           1036           1036              0              0              0
           dev             52              0            284             52              0              0              0              0              0              0
          .ttf            296           1264              0              0              0              0              0              0              0              0
FilePage other          21933           1432           4300          21524            148              0              0              0              0              0
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
         Total          92998          99204          23452          56504           2176          27188          27188          55796          53564           2809

native heap:
  jemalloc meta:          1010            276              0           1000              0            156            156              0              0              0
  jemalloc heap:         13126          22412              0          12260              0          17876          17876              0              0              0
       brk heap:          1259           4444              0           1132              0            744            744              0              0              0
      musl heap:            32              0              0             32              0              0              0              0              0              0

Purgeable:
        PurgSum:0 kB
        PurgPin:0 kB

DMA:
            Dma:0 kB

Ashmem:
Total Ashmem:144 kB
```

Run the **hidumper --mem pid --show-ashmem** command to obtain the memory usage of a specified PID and print the detailed ashmem usage information.

Example:

```shell
$ hidumper --mem 27336 --show-ashmem
-------------------------------[memory]-------------------------------

                          Pss         Shared         Shared        Private        Private           Swap        SwapPss           Heap           Heap           Heap
                        Total          Clean          Dirty          Clean          Dirty          Total          Total           Size          Alloc           Free
                       ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )
              ------------------------------------------------------------------------------------------------------------------------------------------------------
            GL              0              0              0              0              0              0              0              0              0              0
         Graph              0              0              0              0              0              0              0              0              0              0
   ark ts heap          12657           5516              0          12468              0           3068           3068              0              0              0
         guard              0              0              0              0              0              0              0              0              0              0
   native heap          15191          27132              0          14252              0          18780          18780          55792          53527           2629
          .hap              4              0              0              4              0              0              0              0              0              0
AnonPage other           1094           4932              0            964              0           4280           4280              0              0              0
         stack           1388              0              0           1388              0             28             28              0              0              0
           .db             32              0              0             32              0              0              0              0              0              0
           .so          12557          59184          18868           5372           2028           1036           1036              0              0              0
           dev             52              0            284             52              0              0              0              0              0              0
          .ttf            296           1264              0              0              0              0              0              0              0              0
FilePage other          21916           1432           4300          21524            148              0              0              0              0              0
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
         Total          92379          99460          23452          56056           2176          27192          27192          55792          53527           2629

native heap:
  jemalloc meta:          1008            276              0           1000              0            156            156              0              0              0
  jemalloc heap:         12892          22412              0          12088              0          17880          17880              0              0              0
       brk heap:          1259           4444              0           1132              0            744            744              0              0              0
      musl heap:            32              0              0             32              0              0              0              0              0              0

Purgeable:
        PurgSum:0 kB
        PurgPin:0 kB

DMA:
            Dma:0 kB

Ashmem:
Total Ashmem:144 kB
Process_name    Process_ID      Fd      Cnode_idx       Applicant_Pid   Ashmem_name     Virtual_size    Physical_size   magic    -> Detailed ashmem information
wei.xxx.xxx  27336   72      328415  27336   dev/ashmem/Paf.Permission.appImg        147456  147456  14105
```

Run the **hidumper --mem pid --show-dmabuf** command to obtain the memory usage of a specified PID and print the DMA memory details.

Example:

```shell
$ hidumper --mem 27336 --show-dmabuf
-------------------------------[memory]-------------------------------

                          Pss         Shared         Shared        Private        Private           Swap        SwapPss           Heap           Heap           Heap
                        Total          Clean          Dirty          Clean          Dirty          Total          Total           Size          Alloc           Free
                       ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )         ( kB )
              ------------------------------------------------------------------------------------------------------------------------------------------------------
            GL              0              0              0              0              0              0              0              0              0              0
         Graph              0              0              0              0              0              0              0              0              0              0
   ark ts heap          12657           5516              0          12468              0           3068           3068              0              0              0
         guard              0              0              0              0              0              0              0              0              0              0
   native heap          15191          27132              0          14252              0          18780          18780          55792          53527           2629
          .hap              4              0              0              4              0              0              0              0              0              0
AnonPage other           1094           4932              0            964              0           4280           4280              0              0              0
         stack           1388              0              0           1388              0             28             28              0              0              0
           .db             32              0              0             32              0              0              0              0              0              0
           .so          12557          59184          18868           5372           2028           1036           1036              0              0              0
           dev             52              0            284             52              0              0              0              0              0              0
          .ttf            296           1264              0              0              0              0              0              0              0              0
FilePage other          21916           1432           4300          21524            148              0              0              0              0              0
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
         Total          92379          99460          23452          56056           2176          27192          27192          55792          53527           2629

native heap:
  jemalloc meta:          1008            276              0           1000              0            156            156              0              0              0
  jemalloc heap:         12892          22412              0          12088              0          17880          17880              0              0              0
       brk heap:          1259           4444              0           1132              0            744            744              0              0              0
      musl heap:            32              0              0             32              0              0              0              0              0              0

Purgeable:
        PurgSum:0 kB
        PurgPin:0 kB

DMA:
            Dma:0 kB
Process               pid         fd        size_bytes        ino       exp_pid       exp_task_comm     buf_name      exp_name      buf_type      leak_type
m.xxx.xxx             7612        87        40960             2750      1424          allocatxxxx       RSxxxxxx      xxxxx          xx            xxxx

Ashmem:
Total Ashmem:144 kB
```

Field description:

| Field| Description|
| -------- | -------- |
| Process | Bundle name of the application process that holds the ION memory block (truncated to 16 characters).|
| pid | PID of the faulty process.|
| fd | Handle held by the process.|
| size_bytes | Size of the ION buffer held by the process, in bytes.|
| ino | Inode number of the file.|
| exp_pid | PID of the process that applies for the ION memory from the kernel.|
| exp_task_comm | Name of the process that applies for the ION memory from the kernel.|
| buf_name | Name of the ION buffer.|
| exp_name | Extension name of the ION buffer.|
| buf_type | Type of the ION buffer.|
| leak_type | Type of the ION buffer used for memory leak maintenance and debugging.|

<!--RP12-->
<!--RP12End-->

Run the **hidumper --mem-smaps pid** command to obtain the detailed memory usage of a specified process. This command aggregates values for identical memory segments.

Example:

```txt
$ hidumper --mem-smaps 3456  # 3456 indicates the process ID of the target debuggable application.

-------------------------------[memory]-------------------------------

                                    Shared      Shared      Private     Private
Size        Rss         Pss         Clean       Dirty       Clean       Dirty       Swap        SwapPss     Counts      Category                         Name
16          0           0           0           0           0           0           4           4           3           FilePage other                   [anon]
8           8           8           0           0           8           0           0           0           1           FilePage other                   /bin/init
2048        52          0           0           52          0           0           0           0           1           dev                              /dev/__parameters__/param_sec_dac
80          28          1           0           28          0           0           0           0           1           dev                              /dev/__parameters__/param_selinux
...
```

Statistics

| Field| Description|
| -------- | -------- |
| Counts | Number of occurrences of the same memory segment.|
| Category | Memory category.|

Run the **hidumper --mem-smaps pid -v** command to obtain the detailed memory usage of a specified process. This command directly prints all memory information of the process and does not perform secondary processing on the same memory information.

Example:

```txt
$ hidumper --mem-smaps 3456 -v   # 3456 indicates the process ID of the target debuggable application.

-------------------------------[memory]-------------------------------
                                    Shared      Shared      Private     Private
Size        Rss         Pss         Clean       Dirty       Clean       Dirty       Swap        SwapPss     Category                   Name
4           4           2           0           4           0           0           0           0           FilePage other             [anon]
4           4           2           0           4           0           0           0           0           FilePage other             /bin/init
...
```

**NOTE**

The **hidumper --mem-smaps \[pid] \[-v]** command should be used for [applications of the debug version](performance-analysis-kit-terminology.md#applications-of-the-debug-version).

To check whether the application specified by the command is a debug-type application, run the **hdc shell "bm dump -n [application bundle name] | grep appProvisionType"** command. The expected result is **"appProvisionType": "debug"**.

For example, run the following command to check the bundle name **com.example.myapplication**:

```shell
hdc shell "bm dump -n com.example.myapplication | grep appProvisionType"
```

If the application is a debug application, the following information is displayed:

```shell
"appProvisionType": "debug",
```

To build a debug application, you need to use a debug certificate for signature. For details about how to request and use the debug certificate, see [Requesting a Debug Certificate](https://developer.huawei.com/consumer/en/doc/app/agc-help-add-debugcert-0000001914263178).

### Querying VM Heap Memory

<!--RP2-->

Run the **hidumper --mem-jsheap pid [-T tid] [--gc] [--leakobj] [--raw] [--clean] [--single]** command to view the ArkTS app VM heap memory. Run the **hidumper --mem-cjheap pid [--gc]** command to view the Cangjie app VM heap memory. Run the **hidumper --mem-heap pid ARG [--leakobj]** command to view the specified VM heap memory, where ARG specifies the snapshot type. The generated heap memory files are stored in the /data/log/faultlog/temp directory.

<!--RP2End-->

> **NOTE**
>
> The processes debugged by the **hidumper --mem-jsheap pid [-T tid] [--gc] [--leakobj] [--raw] [--clean] [--single]** and **hidumper --mem-heap pid ARG [--leakobj]** commands must be "apps signed with a debug certificate," the same as [debug version apps](performance-analysis-kit-terminology.md#applications-of-the-debug-version).
>
> To check whether the app specified by the command is a debuggable app, refer to the notes in the **hidumper --mem-smaps [pid] [-v]** command above.

- Run the **hidumper --mem-jsheap pid** command to obtain the VM heap memory of all JS threads of a specified process. The file is named in the format of <!--RP1-->**jsheap-Process ID-JS thread ID-Timestamp**<!--RP1End-->. If there are multiple JS threads, multiple files will be generated.

  Example:

  <!--RP3-->

  ```shell
  $ hidumper --mem-jsheap 64949  -> 64949 indicates the process ID of the target application.
  $ ls | grep jsheap   -> Go to the heap memory file directory and run the command.
  jsheap-64949-64949-1751075546050
  jsheap-64949-64989-1751075546050
  ```

  <!--RP3End-->

- Run the **hidumper --mem-jsheap pid -T tid** command to obtain the VM heap memory of a specified JS thread in a specified process. The file is named in the format of <!--RP1-->**jsheap-Process ID-JS thread ID-Timestamp**<!--RP1End-->.

  Example:

  <!--RP4-->

  ```shell
  $ hidumper --mem-jsheap 64949 -T 64949  -> 64949 indicates the process ID of the target application.
  $ ls | grep jsheap   -> Go to the heap memory file directory and run the command.
  jsheap-64949-64949-1751075567710
  ```

  <!--RP4End-->

- Run the **hidumper --mem-jsheap pid \[-T tid] --raw** command to obtain the VM heap memory of a specified process or JS thread. The generated heap memory file is in .rawheap format and is named in the format of <!--RP1-->**jsheap-Process ID-JS thread ID-Timestamp**<!--RP1End-->**.rawheap**. For details about how to parse and convert the .rawheap file, see [rawheap-translator](../tools/rawheap-translator.md).

  Example:

  <!--RP5-->

  ```shell
  $ hidumper --mem-jsheap 64949 --raw  -> 64949 indicates the process ID of the target application.
  $ ls | grep jsheap   -> Go to the heap memory file directory and run the command.
  jsheap-64949-64949-1751075546050.rawheap
  jsheap-64949-64989-1751075546050.rawheap
  $ hidumper --mem-jsheap 64949 -T 64949 --raw  -> 64949 indicates the process ID of the target application.
  $ ls | grep jsheap
  jsheap-64949-64949-1751075546055.rawheap
  ```

  <!--RP5End-->

- Run the **hidumper --mem-jsheap pid --gc** command to trigger GC for a specified application process. If this command is executed successfully, no file is generated.

  Example:

  ```shell
  $ hidumper --mem-jsheap 64949 --gc  -> 64949 indicates the process ID of the target application.
  ```

- Run the **hidumper --mem-jsheap pid --leakobj** command to obtain the VM heap memory and leaked object information of a specified process. The file is named in the format of <!--RP6-->**leaklist-Process ID-Timestamp**<!--RP6End-->.

    The prerequisite for obtaining the VM heap memory and leaked object information of a specified process is that the app has enabled the leak detection feature through the [@ohos.hiviewdfx.jsLeakWatcher](../reference/apis-performance-analysis-kit/js-apis-jsleakwatcher.md) API.

    The procedure is as follows:

    1. The application calls the [jsLeakWatcher.enable](../reference/apis-performance-analysis-kit/js-apis-jsleakwatcher.md#jsleakwatcherenable) API.

    2. The application calls the [jsLeakWatcher.watch](../reference/apis-performance-analysis-kit/js-apis-jsleakwatcher.md#jsleakwatcherwatch) API.

    3. Run the **hidumper --mem-jsheap [pid] --leakobj** command to export the VM heap memory and leaked object information.

  Example:

  <!--RP7-->

  ```shell
  $ hidumper --mem-jsheap 64949 --leakobj
  $ ls | grep leaklist
  leaklist-64949-1730873210483
  ```

  <!--RP7End-->

- Run the **hidumper --mem-jsheap pid --clean** command to obtain the VM heap memory of a specified process and trigger cleanup of nodeId node information. This command does not generate any files, and no output is displayed upon successful execution.

  Example:

  ```shell
  $ hidumper --mem-jsheap 64949 --clean  -> 64949 is the target app process ID.
  ```

- Run the **hidumper --mem-jsheap pid --raw --single** command to obtain the VM heap memory of a specified process. The memory data of all threads under this process is generated into a single .rawheap file named <!--RP8-->jsheap-Process ID-Timestamp<!--RP8End-->.rawheap. For parsing and conversion of rawheap files, see [rawheap-translator](../tools/rawheap-translator.md).

  Example:

  ```shell
  $ hidumper --mem-jsheap 64949 --raw --single  -> 64949 is the target app process ID.
  ```

- Run the **hidumper --mem-heap pid --native --leakobj** command to print suspected native heap memory leak points of a specified process. This command does not generate any files.

  Example:

  ```shell
  $ hidumper --mem-heap 65097 --native --leakobj  -> 65097 is the target app process ID.
  192 bytes leak directly at 0x59d4852740
    first 32 memory:
      0x59d4852740: 00 7f 80 d4 59 00 00 00 88 39 2f d4 59 00 00 00 ....Y....9/.Y...
      0x59d4852750: 01 00 00 00 00 00 00 00 00 00 00 00 84 00 00 00 ................
    last 32 memory:
      0x59d48527e0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
      0x59d48527f0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
  8 bytes leak directly at 0x59d4809b40
    referencing 8 bytes leak in 1 allocations
    memory:
      0x59d4809b40: 48 9b 80 d4 59 00 00 00                         H...Y...
  8 bytes leak indirectly at 0x59d4809b48
    referencing 8 bytes leak in 1 allocations
    memory:
      0x59d4809b48: 50 9b 80 d4 59 00 00 00                         P...Y...
  8 bytes leak indirectly at 0x59d4809b40
    memory:
      0x59d4809b50: 00 00 00 00 00 00 00 00                         ........
  ```

  Parsing description:

  192 bytes leak directly at 0x59d4852740 indicates that 192 bytes are directly leaked starting from 0x59d4852740. When the number of leaked bytes is greater than 64, only the first 32 bytes and the last 32 bytes are printed.

  ```shell
    8 bytes leak directly at 0x59d4809b40
      referencing 8 bytes leak in 1 allocations
      memory:
        0x59d4809b40: 48 9b 80 d4 59 00 00 00                         H...Y...
  ```

  This indicates that 8 bytes are directly leaked starting from 0x59d4809b40. When the number of leaked bytes is less than 64, all bytes are printed.

  "referencing" indicates that this address references another address. The printed content points to the referenced address. Reading from back to front, the pointed address is 0x59d4809b48. Therefore, the pointed-to 0x59d4809b48 and the next pointed-to 0x59d4809b40 are indirect leaks.

  The print order follows these rules:

  1. Direct leaks come first: "directly" entries appear before "indirectly" entries.

  2. Larger sizes come first: the 192-byte entry appears before the 8-byte entry.

  3. Larger referenced memory blocks come first: the "referencing 8 bytes" entry appears before entries with no reference or with references smaller than 8 bytes.

  4. Smaller addresses come first.

- Run the **hidumper --mem-heap pid --native** command to export the native heap memory snapshot file of a specified process. The file is named <!--RP9-->nativeheap-Process ID-Timestamp.<!--RP9End-->

  Example:

  <!--RP10-->

  ```shell
  $ hidumper --mem-heap 65097 --native  -> 65097 is the target app process ID.
  $ ls | grep nativeheap -> 进入堆内存文件存放目录后执行
  nativeheap-65097-1775640819058
  ```

  <!--RP10End-->

  Parsing description:

  > **NOTE**
  >
  > The content of this file is in binary format and must be viewed using a hex editor.

  ```tex
  4E 53 4E 41 50 31 2E 30 64 00 00 00 00 00 00 00
  20 C0 E0 8F 5A 00 00 00 20 00 00 00 00 00 00 00
  C0 B7 E0 8F 5A 00 00 00 40 00 00 00 00 00 00 00
  60 80 E0 8F 5A 00 00 00 30 00 00 00 00 00 00 00
  ...
  ```

  The first 8 bytes of the first line, 4E 53 4E 41 50 31 2E 30, represent "NSNAP1.0" when converted to characters, indicating the version number of this file. This field is fixed.

  The last 8 bytes of the first line, 64 00 00 00 00 00 00 00, represent the number of leak points, which is 0x0000000000000064, or 100 in decimal. This indicates that 100 leak points were detected in this run. This value changes based on the number of reported nodes.

  Based on the number of detected leak points, the corresponding number of information entries is displayed starting from the second line, with each entry occupying 16 bytes.

  Taking the second line as an example, the first 8 bytes represent the address: 0x0000005A8FE0C020, and the last 8 bytes represent the size: 0x0000000000000020, which is 32 bytes.

  <!--RP14-->
  <!--RP14End-->

  <!--RP15-->
  <!--RP15End-->

- Run the **hidumper --mem-heap pid --kotlin** command to export the Kotlin heap memory snapshot file of a specified process. The file is named <!--RP16-->kotlinheap-Process ID-Timestamp.<!--RP16End-->

  Example:

  <!--RP17-->

  ```shell
  $ hidumper --mem-heap 65097 --kotlin  -> 65097 is the target app process ID.
  $ ls | grep kotlinheap -> 进入堆内存文件存放目录后执行
  kotlinheap-65097-1775640819058
  ```

  <!--RP17End-->

<!--Del-->

- Run the **hidumper --mem-cjheap pid** command to obtain the VM heap memory of a specified Cangjie process. The file name format is **cjheap-Process ID-Timestamp**.

  Example:

  ```shell
  $ hidumper --mem-cjheap 65012  -> 65012 indicates the process ID of the target application.
  $ ls | grep cjheap   -> Run this command in the heap memory file directory.
  cjheap-65012-1751075546050
  ```

- Run the **hidumper --mem-cjheap pid --gc** command to trigger GC for a specified Cangjie application process. If this command is executed successfully, no file is generated.

  Example:

  ```shell
  $ hidumper --mem-cjheap 65012 --gc  -> 65012 indicates the process ID of the target application.
  ```

<!--DelEnd-->

You can run the hdc [file transfer](hdc.md#transferring-files) command to obtain the generated file from the device.

## Querying CPU Usage

You can use the hidumper to query the CPU information, which includes the system CPU load.

### Querying Device CPU Usage

Run the **hidumper --cpuusage** command to obtain the device CPU usage.

The output is as follows:

```shell
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

### Querying Process CPU Usage

Run the **hidumper --cpuusage pid** command to obtain the CPU usage of a specified process.

The output is as follows:

```shell
$ hidumper --cpuusage 1

-------------------------------[cpuusage]-------------------------------

Load average: 12.1 / 12.2 / 12.1; the cpu load average in 1 min, 5 min and 15 min
CPU usage from 2024-11-06 11:59:33 to 2024-11-06 11:59:35
Total: 3.80%; User Space: 1.45%; Kernel Space: 2.35%; iowait: 0.00%; irq: 0.14%; idle: 96.06%
Details of Processes:
    PID   Total Usage      User Space    Kernel Space    Page Fault Minor    Page Fault Major    Name
    1          0.00%           0.00%          0.00%           38368                1394            init
```

### Querying CPU Frequency

Run the **hidumper --cpufreq** command to obtain the CPU frequency.

The output is as follows:

```shell
$ hidumper --cpufreq

-------------------------------[cpufreq]-------------------------------


cmd is: cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq

1018000

cmd is: cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq

1530000
...
```

## Querying System Services

### Querying System Service List

- Run the **hidumper -ls** command to obtain the running system service list.

The output is as follows:

```shell
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

### Obtaining System Service Details

- Run the **hidumper -s** command to obtain detailed information about all system services.

The output is as follows:

```shell
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

- Run the **hidumper -s [SA0] [SA1]** command to obtain detailed information about one or more specified system services. You can run the **hidumper -ls** command to query the system capability names **[SA0] [SA1]**.

The output is as follows:

```shell
$ hidumper -s WindowManagerService

-------------------------------[ability]-------------------------------


----------------------------------WindowManagerService----------------------------------
Usage:
-h                             |help text for the tool
-a                             |dump all window information in the system
-w {window id} [ArkUI Option]  |dump specified window information
------------------------------------[ArkUI Option]------------------------------------
...
$ hidumper -s WindowManagerService RenderService

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

### Obtaining Capabilities of a Specified System Service

Run the **hidumper -s [SA] -a ["option"]** command to obtain the capabilities provided by a specified system service.

The following example obtains the help information about RenderService:

```shell
$ hidumper -s RenderService -a "h"

-------------------------------[ability]-------------------------------

----------------------------------RenderService----------------------------------
------ Graphic2D--RenderService ------
Usage:
gles                          |inquire gpu info
h                             |help text for the tool
allInfo                       |dump all info
fpsCount                      |dump the refresh rate counts info
surfacenode                   |surfacenode [id]
trimMem                       |dump trim Mem info
surface                       |dump all surface information
MultiRSTrees                  |dump multi RS Trees info
fpsClear                      |[surface name]/composer fpsClear, clear the fps info
dumpMem                       |dump Cache
allSurfacesMem                |dump surface mem info
RSTree                        |dump RS Tree info
rsLogFlag                     |set rs log flag
nodeNotOnTree                 |dump nodeNotOnTree info
client                        |dump client ui node trees
clearFpsCount                 |clear the refresh rate counts info
hitchs                        |[windowname] hitchs, dump the hitchs info of window
vktextureLimit                |dump vk texture limit info
EventParamList                |dump EventParamList info
dumpNode                      |dump render node info
dumpExistPidMem               |dumpExistPidMem [pid], dump exist pid mem info
fps                           |[windowname] fps, dump the fps info of window
flushJankStatsRs              |flush rs jank stats hisysevent
screen                        |dump all screen information in the system
```

Run the following command to obtain the capability of obtaining GPU information:

```shell
$ hidumper -s RenderService -a "gles"

-------------------------------[ability]-------------------------------


----------------------------------RenderService----------------------------------

-- DumpGpuInfo:
GL_VENDOR: HUAWEI
GL_RENDERER: Maleoon 910
GL_VERSION: OpenGL ES 3.2 B283
GL_SHADING_LANGUAGE_VERSION: OpenGL ES GLSL ES 3.20
```

## Querying Process Information

Run the **hidumper -p [pid]** command to obtain information about a specified process, including the mount, thread, thread runtime, and wait channel information.

> **NOTE**
>
> The **hidumper -p [pid]** command should be used for applications signed by the debug certificate.
>
> For details about how to check whether the application specified by the command is debuggable, see the description of the **hidumper --mem-smaps [pid] [-v]** command.

The output is as follows:

```shell
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

## Querying FD and Thread Information

Starting from API version 26.0.0, you can use the **-p pid --fd/--thread [-v]** command to obtain summary information about the file descriptors or threads of a specified process. The **-v** option provides detailed information about the file descriptors or threads of the specified process.

> **NOTE**
>
> The processes that can be debugged using the **-p pid --fd/--thread [-v]** command must be "apps signed with a debug certificate."
>
> To check whether the app specified by the command is a debuggable app, refer to the notes in [Querying Process Memory](#querying-process-memory).

The output is as follows:

```shell
$ hidumper -p 2121 --fd
fd num: 83
Summary:
Leaked fd:ashmem

Leaked fd Top 10:
23      ashmem
10      /data/storage/el1/database/phone_launcher/rdb/Launcher.db
8       socket
7       eventfd
6       eventpoll
5       /data/storage/el1/database/phone_launcher/rdb/Launcher.db-dwr
4       pipe
3       /dev/null
2       /proc/204/sched_rtg_ctrl
2       dmabuf
Top Dir 10:
2       /proc/
02      /proc/204/sched_rtg_ctrl
2       anon_inode:malitl_
01      anon_inode:malitl_2121_0xebd3d8a0
01      anon_inode:malitl_2121_0xec5d6c70
1       /dev/mali
01      /dev/mali0

$ hidumper -p 2121 --fd -v
fd num: 83
Summary:
Leaked fd:ashmem

Leaked fd Top 10:
23      ashmem
10      /data/storage/el1/database/phone_launcher/rdb/Launcher.db
8       socket
7       eventfd
6       eventpoll
5       /data/storage/el1/database/phone_launcher/rdb/Launcher.db-dwr
4       pipe
3       /dev/null
2       /proc/204/sched_rtg_ctrl
2       dmabuf
Top Dir 10:
2       /proc/
02      /proc/204/sched_rtg_ctrl
2       anon_inode:malitl_
01      anon_inode:malitl_2121_0xebd3d8a0
01      anon_inode:malitl_2121_0xec5d6c70
1       /dev/mali
01      /dev/mali0
Fd link counts:
anon_inode:malitl_2121_0xec5d6c70:1
/system/app/com.ohos.contacts/Contacts.hap:1
/dev/mali0:1
/system/app/com.ohos.photos/Photos.hap:1
...

$ hidumper -p 2121 --thread
Thread num: 43
Top 10 Thread Names:
4       mali-utility-wo
4       OS_GC_Thread
2       RSRenderThread
1       OS_FFRT_2_0
1       OS_FFRT_2_1
1       OS_FFRT_2_2
1       OS_FFRT_2_3
1       OS_FFRT_3_0
1       OS_FFRT_3_1
1       OS_FFRT_3_2

$ hidumper -p 2121 --thread -v
Thread num: 43
Top 10 Thread Names:
4       mali-utility-wo
4       OS_GC_Thread
2       RSRenderThread
1       OS_FFRT_2_0
1       OS_FFRT_2_1
1       OS_FFRT_2_2
1       OS_FFRT_2_3
1       OS_FFRT_3_0
1       OS_FFRT_3_1
1       OS_FFRT_3_2
tid     thread_name     start_time
2121    m.ohos.launcher 5033
3047    OS_IPC_0_3047   24094
3048    OS_DfxWatchdog  24095
3049    OS_IPC_1_3049   24095
3051    OS_IPC_2_3051   24098
3052    OS_IPC_3_3052   24098
3053    OS_FFRT_5_0     24099
...
```

The **--fd** and **--thread** options cannot be used together:

```shell
$ hidumper -p 2121 --fd --thread
hidumper: invalid arg: --fd and --thread cannot be used together
```

## Querying Network Information

Run the **hidumper --net** command to obtain the network traffic information, network interface statistics, network port statistics, IP information, iptable information, and binder information. This capability is implemented by running system commands such as **netstat**, **ifconfig**, and **iptables**.

The output is as follows:

```shell
$ hidumper --net

-------------------------------[net traffic]-------------------------------

Received Bytes:0
Sent Bytes:51885

-------------------------------[net]-------------------------------

cmd is: netstat -nW  -> Run the netstat -nW command to query network information, such as the network connection, route table, and interface statistics.
...
```

Run the **hidumper --net [pid]** command to obtain the network traffic information of a specified process.

The output is as follows:

```shell
$ hidumper --net 1

-------------------------------[net traffic]-------------------------------

Received Bytes:0
Sent Bytes:51885
```

## Querying Storage Information

- Run the **hidumper --storage** command to obtain disk statistics, disk usage, file handle information, I/O traffic statistics, and mount information.

The output is as follows:

```shell
$ hidumper --storage

-------------------------------[storage]-------------------------------


cmd is: storaged -u -p
...
```

- Run the **hidumper --storage [pid]** command to obtain the I/O information of a specified process.

The output is as follows:

```shell
$ hidumper --storage 1

-------------------------------[storage io]-------------------------------


/proc/1/io

rchar: 28848175
wchar: 4364169
syscr: 16886
syscw: 15866
read_bytes: 30617600
write_bytes: 10907648
cancelled_write_bytes: 734003
```

The fields in the I/O information are described as follows:

- **rchar**: total number of characters read by the process from the cache or directly since it starts, in bytes.

- **wchar**: total number of characters written by the process from the cache or directly since it starts, in bytes.

- **syscr**: number of **read** system calls executed by the process since it starts.

- **syscw**: number of **write** system calls executed by the process since it starts.

- **read_bytes**: number of bytes read by the process from the file system and network since it starts, in bytes.

- **write_bytes**: number of bytes written by the process to the file system and network since it starts, in bytes.

- **cancelled_write_bytes**: number of bytes that are not written due to write cancellation since the process starts, in bytes. Generally, the value of this field is 0 unless an error occurs when data is written to the disk or the write operation is interrupted.  

## Querying System Information

- Run the **hidumper -lc** command to obtain the system information cluster list.

The output is as follows:

```shell
$ hidumper -lc
System cluster list:
base                             system
```

- Run the **hidumper -c [system information cluster name]** command to obtain information about a specified information cluster.

For example, run the **hidumper -c base** command to obtain the device information, kernel version, boot parameters, and boot time. The output is as follows:

```shell
-------------------------------[base]-------------------------------

BuildId: ALN-AL00 5.0.1.XXX(XXX)   -> Device information
ReleaseType: Beta1
OsVersion: phone/HUAWEI/HUAWEI/ALN/OpenHarmony-5.0.1.XXX(Beta1)/ALN-AL10/ALN-AL10/XX/5.0.1.XXX/default
DeviceType: phone
...

/proc/version

Hongmeng version: HongMeng Kernel X.XX.XX  -> Kernel version

/proc/cmdline   -> Boot parameters

ohos.boot.post_data_blks=0x0 ohos.boot.ptn_last_blk=0x772AFFF ...

cmd is: uptime -p

up 0 weeks, 0 days, 5 hours, 27 minutes   -> Boot time
```

For example, run the **hidumper -c system** command to obtain the environment variables, kernel module, loaded kernel modules, slab, zone, vmstat, vmalloc, CPU frequency, and memory information. The output is as follows:

```shell
$ hidumper -c system

-------------------------------[system]-------------------------------


cmd is: printenv   -> Environment variables

_=/system/bin/printenv
LANG=en_US.UTF-8
HOME=/root
PULSE_STATE_PATH=/data/data/.pulse_dir/state
OLDPWD=/
PWD=/
TMP=/data/local/mtp_tmp/
PULSE_RUNTIME_PATH=/data/data/.pulse_dir/runtime
...

/proc/modules   -> Kernel module information

modem_driver 1490944 24 - Live 0x0000000000000000
hmtpp_freq_dal_kirin 20480 0 [permanent], Live 0x0000000000000000 (O)
kconsole 20480 0 [permanent], Live 0x0000000000000000 (O)
hmtpp_dal 40960 2 hmtpp_freq_dal_kirin, Live 0x0000000000000000 (O)
...

cmd is: lsmod  -> Loaded kernel module

Module                  Size  Used by
modem_driver         1490944  24
hmtpp_freq_dal_kirin    20480  0 [permanent]
kconsole               20480  0 [permanent]
hmtpp_dal              40960  2 hmtpp_freq_dal_kirin
...

/proc/slabinfo   -> slab information

slabinfo - version: 2.0
#name       <active_objs> <num_objs> <objsize> <objperslab> <pagesperslab> : tunables <limit> <batchcount> <sharedfactor> : slabdata <active_slabs> <num_slabs> <num_pool> <sharedavail> <reclaimable>
slab-[16]                  48459  54432     16    252      1 : tunables 0 0 0 : slabdata    215    216      4 0 0
slab-[24]                  78315  83328     24    168      1 : tunables 0 0 0 : slabdata    496    496      4 0 0
slab-[32]                   5834   9954     32    126      1 : tunables 0 0 0 : slabdata     79     79      4 0 0
...

/proc/zoneinfo   -> zone information

Node 0, zone      DMA
  per-node stats
      nr_inactive_anon 419922
      nr_active_anon 11737
      nr_inactive_file 381289
      nr_active_file 456643
...

/proc/vmstat   -> vmstat information

workingset_refault_anon    63071
workingset_refault_file        0
workingset_activate_anon     1742
workingset_activate_file        0
...

/proc/vmallocinfo   -> vmalloc information

0x0000000000000000-0x0000000000000000    4096 of_iomap+0xe4/0xec pages=1 phys=0xfb21b000 ioremap
0x0000000000000000-0x0000000000000000    4096 of_iomap+0xe4/0xec pages=1 phys=0xffb85000 ioremap
0x0000000000000000-0x0000000000000000    4152 gen_pool_add_owner+0x48/0xc0 pages=2 vmalloc
0x0000000000000000-0x0000000000000000    4096 of_iomap+0xe4/0xec pages=1 phys=0xee262000 ioremap
...

cmd is: cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq   -> CPU frequency information

1430000

cmd is: cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq

1530000

cmd is: cat /sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq

1430000
...

-------------------------------[memory]-------------------------------     -> Memory information
Total Memory Usage by PID:
PID        Total Pss(xxx in SwapPss)    Total Vss    Total Rss    Total Uss           GL        Graph          Dma      PurgSum      PurgPin     Name
1           4001(1672 in SwapPss) kB     59028 kB      5744 kB      1972 kB         0 kB         0 kB         0 kB         0 kB         0 kB     init
2             50451(0 in SwapPss) kB 18014398163279052 kB     52088 kB     49448 kB         0 kB         0 kB         0 kB         0 kB         0 kB     sysmgr-main
79             2741(0 in SwapPss) kB   2145468 kB      6052 kB      1292 kB         0 kB         0 kB         0 kB         0 kB         0 kB     crypto.elf
80             8796(0 in SwapPss) kB   2156116 kB     12584 kB      6940 kB         0 kB         0 kB         0 kB         0 kB         0 kB     devmgr.elf
85            96861(0 in SwapPss) kB  37180468 kB    100932 kB     94808 kB         0 kB         0 kB         0 kB         0 kB         0 kB     devhost.elf
501            2256(0 in SwapPss) kB   2142484 kB      3892 kB      1620 kB         0 kB         0 kB         0 kB         0 kB         0 kB     hguard.elf
586         1656(1412 in SwapPss) kB     32852 kB       744 kB       236 kB         0 kB         0 kB         0 kB         0 kB         0 kB     ueventd
...
```

- Run the **hidumper -c** command to obtain all information clusters, including the **base** and **system** clusters.

## Obtaining System Fault Logs

Run the **hidumper -e** command to obtain the system fault log and print its file name and details.

```shell
$ hidumper -e

-------------------------------[faultlog]-------------------------------


/data/log/faultlog/faultlogger/syswarning-com.ohos.sceneboard-20020022-20241106104006  -> Fault log file name

Generated by HiviewDFX@OpenHarmony  -> Fault log details
...
```

## Obtaining Abnormal Exit Record List

Run the **hidumper -e --list** command to obtain the abnormal exit record list.

```shell
$ hidumper -e --list
time                  foreground               reason              record_id              process_name
2025-09-26 15:45:06   False                    ThreadBlock6S       05233453489239878113   xxx.xxx.sceneboard
2025-09-26 15:45:03   False                    LowMemoryKill       23123453489239875544   xxx.xxx.sceneboard
2025-09-26 14:43:06   False                    LowMemoryKill       45453453489233242345   xxx.xxx.sceneboard
2025-09-26 12:42:05   True                     LowMemoryKill       45455345348923987811   xxx.xxx.sceneboard
2025-09-26 10:45:45   False                    LowMemoryKill       78767783489239873255   xxx.xxx.sceneboard
2025-09-26 10:40:06   False                    LowMemoryKill       78767783489239454666   xxx.xxx.systemui
...
```

Run the **hidumper -e --list process_name** command to obtain the abnormal exit record list of a specified process.

```shell
$ hidumper -e --list sceneboard
time                  foreground               reason              record_id              process_name
2025-09-26 15:45:06   False                    ThreadBlock6S       05233453489239878113   xxx.xxx.sceneboard
2025-09-26 15:45:03   False                    LowMemoryKill       23123453489239875544   xxx.xxx.sceneboard
2025-09-26 14:43:06   False                    LowMemoryKill       45453453489233242345   xxx.xxx.sceneboard
2025-09-26 12:42:05   True                     LowMemoryKill       45455345348923987811   xxx.xxx.sceneboard
2025-09-26 10:45:45   False                    LowMemoryKill       78767783489239873255   xxx.xxx.sceneboard
...
```

Run the **hidumper -e --list -n num** command to obtain the abnormal exit record list. The **num** parameter specifies the number of records to be displayed.

```shell
$ hidumper -e --list -n 2
time                  foreground               reason              record_id              process_name
2025-09-26 15:45:06   False                    ThreadBlock6S       05233453489239878113   xxx.xxx.sceneboard
2025-09-26 15:45:03   False                    LowMemoryKill       23123453489239875544   xxx.xxx.sceneboard
```

Run the **hidumper -e --list process_name -n num --since timestamp --until timestamp** command to obtain the latest abnormal exit records of a specified process within a specified period. The **num** parameter specifies the number of records to be displayed, and the **timestamp** parameter specifies the time range.

> **NOTE**
>
> The time interval follows a left-closed and right-open rule, and no data can be retrieved when the start time and end time are exactly the same.

```shell
$ hidumper -e --list sceneboard -n 4 --since '2025-09-26 12:42:05' --until '2025-09-26 15:45:07'
time                  foreground               reason              record_id              process_name
2025-09-26 15:45:06   False                    ThreadBlock6S       05233453489239878113   xxx.xxx.sceneboard
2025-09-26 15:45:03   False                    LowMemoryKill       23123453489239875544   xxx.xxx.sceneboard
2025-09-26 14:43:06   False                    LowMemoryKill       45453453489233242345   xxx.xxx.sceneboard
2025-09-26 12:42:05   True                     LowMemoryKill       45455345348923987811   xxx.xxx.sceneboard
$ hidumper -e --list --since '2025-09-26 12:42:05' --until '2025-09-26 12:42:05'
no records found.
```

Field description:

| Field| Description|
| -------- | -------- |
| time | Time when an abnormal exit occurs.|
| foreground | Whether the process is in the foreground when an abnormal exit occurs. The value **True** indicates that the process is in the foreground, and **False** indicates the opposite.|
| reason | Reason for the abnormal exit. For details, see [reason](#reason).|
| record_id | ID of an abnormal exit record.|
| process_name | Name of the process where an abnormal exit occurs.|

### reason

For the following reasons, refer to [Analysis Method and Procedure](appkilled-guidelines.md#analysis-method-and-procedure) to rectify the fault.

| Type  | Description                      |
| ------- | ------------------------- |
| IllegalAudioRendererBySuspend | No proper background task is applied for the application, but a large amount of audio is played in the background.|
| LowMemoryKill | Low device memory.|
| OomKiller | The device memory is used up and cannot be allocated.|
| PowerSaveClean | The device is switched to the power saving mode or emergency mode.|
| ResourceLeak(AshmemLeak) | The Ashmem memory usage of the application exceeds the threshold.|
| ResourceLeak(GpuLeak) | The GPU memory usage of the application exceeds the threshold.|
| ResourceLeak(GpuRsLeak) | The GPU memory usage of the application in the Render Service process exceeds the threshold.|
| ResourceLeak(IonLeak) | The ION memory usage of the application exceeds the threshold.|
| RssThresholdKiller | The Resident Size Set (RSS) usage of the application exceeds the threshold.|
| SwapFull | The swap space of the system is used up.|
| ThreadBlock6S | The main application process is blocked. You can view fault log details based on **record_id**.|
| AppInputBlock | The input event does not respond. You can view fault log details based on **record_id**.|
| LifecycleTimeout | The lifecycle times out. You can view fault log details based on **record_id**.|
| JsError | A JS crash occurs. You can view fault log details based on **record_id**.|
| CppCrash | A native crash occurs. You can view fault log details based on **record_id**.|

## Obtaining Abnormal Exit Logs

Run the **hidumper -e --print** command to obtain system fault logs and print the file name and details.

> **NOTE**
>
> Abnormal exit records can be retained for a maximum of 30 days. A maximum of 10 fault logs of the same type can be retained for the same process. If the queried logs have been deleted, a message is displayed.

```shell
$ hidumper -e --print

-------------------------------[faultlog]-------------------------------

/data/log/faultlog/faultlogger/xxxx-com.xxx.sceneboard-20020022-20250926154006  -> Name of the fault log file.

Generated by HiviewDFX@OpenHarmony  -> Fault log details
...   -> Fault log details, which are omitted due to excessive text content.

-------------------------------[faultlog]-------------------------------

/data/log/faultlog/faultlogger/xxxx-com.xxx.sceneboard-20020022-20250926124106  -> Name of the fault log file.

Generated by HiviewDFX@OpenHarmony  -> Fault log details
...   -> Fault log details, which are omitted due to excessive text content.

-------------------------------[faultlog]-------------------------------

/data/log/faultlog/faultlogger/xxxx-com.xxx.sceneboard-20020022-20250926114206  -> Name of the fault log file.

Generated by HiviewDFX@OpenHarmony  -> Fault log details
...   -> Fault log details, which are omitted due to excessive text content.

-------------------------------[faultlog]-------------------------------

/data/log/faultlog/faultlogger/xxxx-com.xxx.systemui-20020022-20250926104506  -> Name of the fault log file.

Generated by HiviewDFX@OpenHarmony  -> Fault log details
...   -> Fault log details, which are omitted due to excessive text content.

-------------------------------[faultlog]-------------------------------

/data/log/faultlog/faultlogger/xxxx-com.xxx.hidumper-20020022-20250926104206  -> Name of the fault log file.

The faultlog has been deleted by the system due to expiration.  -> The message indicating that logs are deleted due to expiration is displayed.
```

Run the **hidumper -e --print process_name** command to print the name and details of the system fault log file of a specified process.

```shell
$ hidumper -e --print systemui

-------------------------------[faultlog]-------------------------------

/data/log/faultlog/faultlogger/xxxx-com.xxx.systemui-20020022-20250926104506  -> Name of the fault log file.

Generated by HiviewDFX@OpenHarmony  -> Fault log details
...
```

Run the **hidumper -e --print -n num** command to print the names and details of the system fault log files and specify the number of files to be printed.

```shell
$ hidumper -e --print -n 2

-------------------------------[faultlog]-------------------------------

/data/log/faultlog/faultlogger/xxxx-com.xxx.sceneboard-20020022-20250926154006  -> Name of the fault log file.

Generated by HiviewDFX@OpenHarmony  -> Fault log details
...   -> Fault log details, which are omitted due to excessive text content.

-------------------------------[faultlog]-------------------------------

/data/log/faultlog/faultlogger/xxxx-com.xxx.sceneboard-20020022-20250926124106  -> Name of the fault log file.

Generated by HiviewDFX@OpenHarmony  -> Fault log details
...   -> Fault log details, which are omitted due to excessive text content.
```

Run the **hidumper -e --print process_name -n num --since timestamp --until timestamp** command to obtain system fault logs, print the file name and details, and specify the number of files and time range of a specified process.

```shell
$ hidumper -e --print sceneboard -n 2 --since '2025-09-26 12:40:05' --until '2025-09-26 15:45:07'

-------------------------------[faultlog]-------------------------------

/data/log/faultlog/faultlogger/xxxx-com.xxx.sceneboard-20020022-20250926154006  -> Name of the fault log file.

Generated by HiviewDFX@OpenHarmony  -> Fault log details
...   -> Fault log details, which are omitted due to excessive text content.

-------------------------------[faultlog]-------------------------------

/data/log/faultlog/faultlogger/xxxx-com.xxx.sceneboard-20020022-20250926124106  -> Name of the fault log file.

Generated by HiviewDFX@OpenHarmony  -> Fault log details
...   -> Fault log details, which are omitted due to excessive text content.
```

Run the **hidumper -e --print record_id** command to obtain the system fault log based on the ID of a specified abnormal exit record, including the file name and details. If no matching record is found, the system displays the query failure cause.

```shell
$ hidumper -e --print 05233453489239878113

-------------------------------[faultlog]-------------------------------

/data/log/faultlog/faultlogger/xxxx-com.xxx.sceneboard-20020022-20250926104006  -> Name of the fault log file.

Generated by HiviewDFX@OpenHarmony  -> Fault log details
...   -> Fault log details, which are omitted due to excessive text content.

$ hidumper -e --print 23123453489239875544
this type of record does not have faultlog.  -> Reason for failure.
```

## Obtaining IPC Information

Run the **hidumper --ipc -a --start-stat/stop-stat/stat** command to obtain the IPC information within the collection period.

The output is as follows:

```shell
$ hidumper --ipc -a --start-stat
StartIpcStatistics pid:1473 success
StartIpcStatistics pid:775 success
StartIpcStatistics pid:1472 success
...
$ hidumper --ipc -a --stat
GlobalStatisticsInfo
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

Run the **hidumper --ipc [pid] --start-stat/stop-stat/stat** command to obtain the IPC information of a specified process within the collection period.

The output is as follows:

```shell
$ hidumper --ipc 1473 --start-stat
StartIpcStatistics pid:1473 success
$ hidumper --ipc 1473 --stat
GlobalStatisticsInfo
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

$ hidumper --ipc 1473 --stop-stat
StopIpcStatistics pid:1473 success
```

## Compressing Exported Information

HiDiumper provides the **--zip** command to export any type of exported information into a ZIP file in **/data/log/hidumper**. This command can be combined with other commands, and the file is named with the current timestamp, as shown in the following example.

```shell
$ hidumper --zip
100%,[-],The result is:/data/log/hidumper/20250622-120444-166.zip
```

For example, if the system fault log obtained by running the **hidumper -e** command is large, you can compress the log as follows:

```shell
$ hidumper -e

-------------------------------[faultlog]-------------------------------


/data/log/faultlog/faultlogger/syswarning-com.ohos.sceneboard-20020022-20241106104006  -> Fault log file name

Generated by HiviewDFX@OpenHarmony
...  -> Fault log details, which are omitted due to excessive text content.
$ hidumper -e --zip
100%,[-],The result is:/data/log/hidumper/20250623-092235-087.zip
```

## Common ArkUI Basic Information Display Capabilities

ArkUI provides the capability of obtaining information such as the component tree based on the enhanced hidumper.

### Obtaining Application Window Information

Run the following command to print the full window information. You can find the **WinId** of the corresponding window in the full information and pass it as a parameter to other commands to obtain related information.

```shell
hdc shell hidumper -s WindowManagerService -a '-a'
```

 **Example**

```text
-------------------------------[ability]-------------------------------


----------------------------------WindowManagerService---------------------------------
-------------------------------------ScreenGroup 1-------------------------------------
WindowName             DisplayId Pid     WinId Type Mode Flag ZOrd Orientation [ x    y    w    h    ]
ScreenLockWindow       0         1274    2     2110 1    0    4    0           [ 0    0    720  1280 ]
SystemUi_NavigationBar 0         1274    5     2112 102  1    3    0           [ 0    1208 720  72   ]
SystemUi_StatusBar     0         1274    4     2108 102  1    2    0           [ 0    0    720  72   ]
settings0              0         10733   11    1    1    1    1    0           [ 0    72   720  1136 ]
EntryView              0         1546    8     2001 1    0    0    8           [ 0    0    720  1280 ]
---------------------------------------------------------------------------------------
SystemUi_VolumePanel   0         1274    3     2111 1    1    -1   0           [ 0    0    0    0    ]
SystemUi_DropdownPan   0         1274    6     2109 1    1    -1   0           [ 0    0    0    0    ]
SystemUi_BannerNotic   0         1274    7     2111 1    1    -1   0           [ 0    0    0    0    ]
RecentView             0         1546    9     2115 1    1    -1   0           [ 0    0    0    0    ]
imeWindow              0         1530    10    2105 1    1    -1   0           [ 0    0    0    0    ]
Focus window: 2
total window num: 10
```

The following table lists the mapping between common **windowName** and built-in application windows.

|windowName|Built-in Application Window|
|---|---|
| EntryView|Home screen.|
| RecentView|Recent tasks.|
| SystemUi_NavigationBar|Three-key navigation.|
|  SystemUi_StatusBar|Status bar.|
| ScreenLockWindow|Lock screen.|

### Obtaining an Application Component Tree

Run the following command to view information about all components in an application:

```shell
hdc shell "hidumper -s WindowManagerService -a '-w %windowId% -element'"
```

**windowId** is the window ID of the target application.

**Example**

```text
hdc shell "hidumper -s WindowManagerService -a '-w 5 -element'"

-------------------------------[ability]-------------------------------
----------------------------------WindowManagerService---------------------------------
WindowName: SystemUi_NavigationBar
DisplayId: 0
WinId: 5
Pid: 1274
Type: 2112
Mode: 102
Flag: 1
Orientation: 0
IsStartingWindow: false
FirstFrameCallbackCalled: 0
IsVisible: false
WindowRect: [ 0, 1208, 720, 72 ]
TouchHotAreas: [ 0, 1208, 720, 72 ]
  |-> RootElement childSize:1
    | ID: 0
    | elmtId: -1
    | retakeID: 16
    | Active: Y
    |-> StackElement childSize:2
      | ID: 1
      | elmtId: -1
      | retakeID: 14
      | Active: Y
      |-> StageElement childSize:1
        | ID: 2
        | elmtId: -1
        | retakeID: 13
        | Active: Y
        |-> PageElement childSize:1
          | ID: 3
          | elmtId: -1
          | retakeID: 569
          | Active: Y
......
```

### Obtaining Component Information of a Specified Application Node

Run the following command to view component information of a node:

```shell
hdc shell "hidumper -s WindowManagerService -a '-w %windowId% -element -lastpage %nodeID%'"
```

**windowId** indicates the window ID of the application, and **nodeID** indicates the ID of the specified node. You can obtain the **nodeID** by obtaining the target application component tree.

**Example**

```text
hdc shell "hidumper -s WindowManagerService -a '-w 5 -element -lastpage 3'"

-------------------------------[ability]-------------------------------
----------------------------------WindowManagerService---------------------------------
WindowName: SystemUi_NavigationBar
DisplayId: 0
WinId: 5
Pid: 1274
Type: 2112
Mode: 102
Flag: 1
Orientation: 0
IsStartingWindow: false
FirstFrameCallbackCalled: 0
IsVisible: false
WindowRect: [ 0, 1208, 720, 72 ]
TouchHotAreas: [ 0, 1208, 720, 72 ]
    |-> PageElement childSize:1
        | ID: 3
        | elmtId: -1
        | retakeID: 569
        | Active: Y
......
```

### Obtaining the Inspector Tree of an Application

The **element/render** tree in the preceding example mainly contains multiple internal implementations, which cannot be mapped to components in the application code. You can print the Inspector tree to obtain the tree structure and basic information corresponding to the application components. The Inspector tree matches DevEco Testing and ArkUI Inspector in DevEco Studio.

You need to enable ArkUI debug before using this functionality.

```shell
hdc shell param set persist.ace.testmode.enabled 1
```

**set**: command for setting; **persist.ace.testmode.enabled**: ArkUI debug switch name; **1**: the switch is set to **true** to enable the debug functionality.

The command is as follows:

```shell
hdc shell "hidumper -s WindowManagerService -a '-w %windowId% -inspector'"
```

**Example**

```text
hdc shell "hidumper -s WindowManagerService -a '-w 5 -inspector'"

|-> rootstacktag childSize:1
| ID: 2100001
| compid:
| text:
| top: 72.000000
| left: 0.000000
| width: 0.000000
| height: 0.000000
| visible: 1
| clickable: 0
| checkable: 0
|-> Column childSize:1
| ID: 128
| compid:
| text:
| top: 72.000000
| left: 0.000000
| width: 720.000000
| height: 1136.000000
| visible: 1
| clickable: 0
| checkable: 0
|-> GridContainer childSize:1
| ID: 129
| compid:
| text:
| top: 72.000000
| left: 0.000000
| width: 720.000000
| height: 1136.000000
| visible: 1
| clickable: 0
| checkable: 0
|-> Column childSize:2
| ID: 130
| compid:
| text:
| top: 72.000000
| left: 0.000000
| width: 720.000000
| height: 180.000000
| visible: 1
| clickable: 0
| checkable: 0

......
```

### Obtaining Application Route Stack Information

This command outputs the information about the application page route stack, which is sorted based on the stack creation sequence and parent-child relationship.

> **NOTE**
>
> This command can be used only for applications that implement page routing through the [Navigation](../ui/arkts-navigation-architecture.md) component.

The command is as follows:

```shell
hidumper -s WindowManagerService -a '-w %windowId% -navigation -c'
```

**Example**

```text
hidumper -s WindowManagerService -a '-w 15 -navigation -c'

-------------------------------[ability]-------------------------------


----------------------------------WindowManagerService--------------------------------
WindowName: myapplication0
DisplayId: 0
WinId: 12
Pid: 5908
Type: 1
Mode: 1
Flag: 0
Orientation: 0
IsStartingWindow: false
FirstFrameCallbackCalled: 1
VisibilityState: 0
Focusable: true
DecoStatus: true
IsPrivacyMode: false
isSnapshotSkip: 0
WindowRect: [ 0, 0, 720, 1280 ]
TouchHotAreas: [ 0, 0, 720, 1280 ]
bundleName:com.example.myapplication
moduleName:entry
 LastRequestVsyncTime: 2351504075334
 transactionFlags: [ 5908, 0 ]
 last vsyncId: 527
Navigation number: 4
|-> Navigation ID: 7, Depth: 7, Mode: "SPLIT", NavDestinations:
  | [0]{ ID: 0, Name: "pageOne", Mode: "STANDARD", IsOnShow: "FALSE" }
  | [1]{ ID: 1, Name: "pageTwo", Mode: "STANDARD", IsOnShow: "TRUE" }
|-> Navigation ID: 19, Depth: 7, Mode: "AUTO (STACK)", NavDestinations:
  |-> Navigation ID: 28, Depth: 11, Mode: "STACK", NavDestinations:
  | [0]{ ID: 2, Name: "pageOne", Mode: "STANDARD", IsOnShow: "FALSE" }
  | [1]{ ID: 3, Name: "pageTwo", Mode: "DIALOG", IsOnShow: "FALSE" }
    |-> Navigation ID: 123, Depth: 11, Mode: "AUTO (SPLIT)", NavDestinations:
      | [0]{ ID: 4, Name: "pageFive", Mode: "STANDARD", IsOnShow: "FALSE" }
      | [1]{ ID: 5, Name: "pageSix", Mode: "STANDARD", IsOnShow: "FALSE" }
  | [2]{ ID: 6, Name: "pageThree", Mode: "STANDARD", IsOnShow: "TRUE" }
```

> **NOTE**
>
> For the same-level nodes, the node displayed at the bottom is the stack top node.

## FAQs

### What is the difference between the memory usage queried by hidumper and that by the HiDebug APIs?

**Symptom**

The memory information obtained by the **hidumper --mem** commands is different from that by the [HiDebug](../reference/apis-performance-analysis-kit/js-apis-hidebug.md) APIs.

**Possible Causes and Solution**

The following table compares the memory information obtained by the **hidumper --mem** commands and that by the HiDebug APIs.

**Table 1**

| Command/API| Usage Scenario| Data Source| Whether to Export Graphics Memory|
| -------- | -------- | -------- | -------- |
| hidumper --mem | Obtain the memory usage of all processes.| System node: **/proc/pid/smaps_rollup**| Yes|
| hidumper --mem [pid] | Obtain the memory usage of a process.| System node: **/proc/pid/smaps**| Yes|
| hidumper --mem-smaps [pid] | Obtain the detailed memory usage of a process.| System node: **/proc/pid/smaps_rollup**| No|
| [hidebug.getAppNativeMemInfo](../reference/apis-performance-analysis-kit/js-apis-hidebug.md#hidebuggetappnativememinfo12) | Obtain the memory usage of an application.| System node: **/proc/pid/smaps_rollup**| No|

To obtain the graphics memory using HiDebug, see [HiDebug Overview](hidebug-guidelines.md).

### hidumper Fails to Obtain Process VM Memory and Leaked Object Information

**Symptom**

When running the **hidumper --mem-jsheap [pid] --leakobj** command to obtain the VM heap memory and leaked object information of a specified process, the command does not generate files as expected.

**Possible Causes and Solution**

The **hidumper --mem-jsheap \[pid] --leakobj** command depends on [JsLeakWatcher](../reference/apis-performance-analysis-kit/js-apis-jsleakwatcher.md). The application must enable leak detection through the **JsLeakWatcher** API. For details, see [Querying VM Heap Memory](#querying-vm-heap-memory).