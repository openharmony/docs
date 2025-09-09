# hidumper

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @m0_55013956-->
<!--Designer: @milkbread123-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

HiDumper是用于统一系统信息导出的命令行工具，支持分析CPU、内存、存储等系统资源使用情况，查询系统服务运行情况，定位资源使用异常、通信等相关问题。


针对HiDumper所支撑的使用场景，本章节将介绍其查询内存信息、查询CPU使用情况、查询系统能力、查询进程信息、查询存储信息、查询系统信息等基础功能，以及系统故障日志获取，进程间通信记录导出，导出信息支持压缩转储等能力。


HiDumper命令行工具使用常见问题汇总在[常见问题](#常见问题)章节。


## 环境要求

- 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)。

- 请确保设备已正常连接，并执行hdc shell。


## 命令行说明

| 选项 | 说明 |
| -------- | -------- |
| -h | 帮助命令。 |
| [-lc](#查询系统信息) | 列出系统信息簇。 |
| [-ls](#查询系统服务列表) | 列出正在运行的系统能力。 |
| [-c](#查询系统信息) | 获取系统全量信息簇详细信息，包含设备信息、内核信息和环境变量等。 |
| [-c [base system]](#查询系统信息) | 获取指定信息簇详细信息，可选"base"或者"system"。 |
| [-s](#获取系统服务详细信息) | 获取所有系统能力详细信息。 |
| [-s [SA0 SA1]](#获取系统服务详细信息) | 获取一个或多个系统能力的详细信息。多个系统能力名称之间使用空格分隔。可通过 -ls 查询系统能力名称。 |
| [-s [SA] -a ["option"]](#获取指定系统服务提供的能力) | 执行单个系统能力的特定选项。<br />SA：系统能力名称。<br />option：该系统能力支持的选项。可通过 -s [SA] -a ["-h"] 获取单个系统能力支持的所有选项。 |
| [-e](#获取系统故障日志) | 获取记录的故障日志。输出日志的规格可参考：[CppCrash](cppcrash-guidelines.md#日志规格)、[JSCrash](jscrash-guidelines.md#日志规格)、[AppFreeze](appfreeze-guidelines.md#日志规格)。 |
| [--net [pid]](#查询网络信息) | 获取网络信息，包含网络流量、网络接口统计、IP信息等。如果指定了进程的pid，则只输出该进程的网络流量使用信息。 |
| [--storage [pid]](#查询存储信息) | 获取存储信息，包含磁盘统计、磁盘使用量、文件句柄等信息。如果指定了进程的pid，则只显示该进程的io信息。 |
| [-p [pid]](#查询进程信息) | 获取进程信息，包括进程和线程的列表和信息。 |
| [--cpuusage [pid]](#查询进程cpu使用率) | 获取CPU使用率，取值范围(0, CPU核数]，按进程和类别分类；如果指定pid，则获取指定pid的CPU使用率。 |
| [--cpufreq](#查询cpu频率) | 获取CPU每个核的真实频率，单位：kHz。 |
| [--mem [--prune]](#查询整机内存) | 获取总内存使用情况。如果指定--prune，只导出精简的内存使用情况。<br />**说明**：从API version 20开始，支持--prune参数。 |
| [--mem pid [--show-ashmem] [--show-dmabuf]](#查询进程内存) | 获取指定pid的进程内存使用情况。<br />指定 --show-ashmem，则补充打印该进程的ashmem使用详细信息。<br />如果是应用进程，指定--show-dmabuf，则补充打印DMA内存详情信息。<br />**说明**：从API version 20开始，支持--show-ashmem、--show-dmabuf参数。 |
| [--zip](#导出信息压缩存储) | 保存命令输出到 /data/log/hidumper 下的压缩文件，压缩格式为 ZIP。 |
| [--ipc [pid]/-a --start-stat/stat/--stop-stat](#获取进程间通信信息) | 统计一段时间进程IPC信息。如果使用-a，则统计所有进程IPC数据。使用--start-stat开始统计，使用--stat获取统计数据，使用--stop-stat结束统计。 |
| [--mem-smaps pid [-v]](#查询进程内存) | 获取pid内存统计信息，数据来源于/proc/pid/smaps，使用-v指定更多详细信息。（仅支持导出[debug版本应用](performance-analysis-kit-terminology.md#debug版本应用)）<br />**说明**：从API version 20开始，支持该参数。 |
| [--mem-jsheap pid [-T tid] [--gc] [--leakobj] [--raw]](#查询虚拟机堆内存) | 必选参数pid。触发ArkTS应用JS线程的gc和堆内存快照导出。指定线程tid时，仅触发该线程的gc和堆内存快照导出；指定--gc时，仅触发gc，不导出快照；指定--leakobj时，应用开启泄露检测可获取泄露对象列表。<br>文件命名格式为：<!--RP1-->jsheap-进程号-JS线程号-时间戳<!--RP1End-->，文件内容为JSON结构的JS堆快照。<br>指定--raw时，堆快照以rawheap格式导出。<br />**说明**：从API version 19开始，支持--raw参数。 |
| <!--DelRow-->[--mem-cjheap pid [--gc]](#查询虚拟机堆内存) | pid为必选参数。触发仓颉应用gc和堆内存快照导出。如果指定--gc，只触发gc不做快照导出。<br />**说明**：从API version 20开始，支持该参数。 |

## 查询内存信息

HiDumper内存信息查询模块主要用于查看系统整机内存使用情况和单个进程内存使用情况。开发者需要了解相关的[内存基础知识](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-memory-basic-knowledge)。

### 查询整机内存

可使用hidumper --mem命令获取整机内存使用情况。

打印效果为：

```
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

VSS (Virtual Set Size)表示当前进程虚拟内存的大小，包括所有映射到该进程地址空间的内存区域。

RSS (Resident Set Size)表示当前进程实际驻留在物理内存中的内存大小。

PSS (Proportional Set Size)是一种更精确的内存使用度量方法，它将共享库所占的内存按比例分配给每个使用该库的进程。

PurgSum（Purgeable Summary）表示当前进程可回收内存的总量。

PurgPin（Purgeable Pinned）表示可回收但暂时无法立即回收的内存。

GL代表GPU内存，包含应用使用的GPU内存和统一渲染在服务进程内产生的GPU内存。

Graph代表图形内存，即DMA内存。

可使用hidumper --mem --prune命令获取整机内存精简的使用情况。

打印效果为：

```shell
$ hidumper --mem --prune
-------------------------------[memory]-------------------------------
Total Memory Usage by PID:
PID        Total Pss(xxx in SwapPss)           GL     AdjLabel     Name
1           4061(1668 in SwapPss) kB         0 kB        -1000     xxx
2            101723(0 in SwapPss) kB         0 kB        -1000     xxx
...
```

AdjLabel代表该进程内存的回收优先级，取值范围为[-1000, 1000]，该值越大则表示该进程越不重要，内存会被优先回收。


### 查询进程内存

可使用hidumper --mem pid命令获取指定进程的内存使用情况，pid为指定的进程号。

使用样例：

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

可使用hidumper --mem pid --show-ashmem获取指定pid的内存使用情况，同时打印ashmem使用详细信息。

使用样例：

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
Process_name    Process_ID      Fd      Cnode_idx       Applicant_Pid   Ashmem_name     Virtual_size    Physical_size   magic    -> 详细ashmem信息
wei.xxx.xxx  27336   72      328415  27336   dev/ashmem/Paf.Permission.appImg        147456  147456  14105
```

使用hidumper --mem pid --show-dmabuf命令可获取指定PID的内存使用情况，并打印DMA内存详细信息。

使用样例：

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
字段说明：

| 字段 | 说明 |
| -------- | -------- |
| Process | 持有ION内存块的应用进程包名（16个字符截断）。 |
| pid | 发生故障进程pid。 |
| fd | 进程持有的句柄。 |
| size_bytes | 进程持有的ION内存buffer大小，单位：B。 |
| ino | 文件inode号（索引节点号）。 |
| exp_pid | 从内核申请ION内存的进程pid。 |
| exp_task_comm | 从内核申请ION内存的进程名。 |
| buf_name | ION内存的buffer名字。 |
| exp_name | ION内存的buffer扩展名。 |
| buf_type | ION内存的buffer类型。 |
| leak_type | ION内存泄漏维测的buffer类型。 |

可使用hidumper --mem-smaps pid命令获取指定进程的详细内存使用情况，该命令会累加相同内存段的内存值。

使用样例：

```txt
$ hidumper --mem-smaps 3456  # 3456 为目标可调试应用进程号

-------------------------------[memory]-------------------------------

                                    Shared      Shared      Private     Private
Size        Rss         Pss         Clean       Dirty       Clean       Dirty       Swap        SwapPss     Counts      Category                         Name
16          0           0           0           0           0           0           4           4           3           FilePage other                   [anon]
8           8           8           0           0           8           0           0           0           1           FilePage other                   /bin/init
2048        52          0           0           52          0           0           0           0           1           dev                              /dev/__parameters__/param_sec_dac
80          28          1           0           28          0           0           0           0           1           dev                              /dev/__parameters__/param_selinux
...
```

统计信息说明：

| 字段 | 说明 |
| -------- | -------- |
| Counts | 相同内存段出现的次数。 |
| Category | 内存所属类别。 |

可使用hidumper --mem-smaps pid -v命令获取指定进程的详细内存使用情况，该命令会直接打印进程的所有内存信息，不会对相同内存信息做二次处理。


使用样例：

```txt
$ hidumper --mem-smaps 3456 -v   # 3456 为目标可调试应用进程号

-------------------------------[memory]-------------------------------
                                    Shared      Shared      Private     Private
Size        Rss         Pss         Clean       Dirty       Clean       Dirty       Swap        SwapPss     Category                   Name
4           4           2           0           4           0           0           0           0           FilePage other             [anon]
4           4           2           0           4           0           0           0           0           FilePage other             /bin/init
...
```

**注意事项**

hidumper --mem-smaps [pid] [-v]命令调试的进程应为“使用调试证书签名的应用”，同[debug版本应用](performance-analysis-kit-terminology.md#debug版本应用)。

要确认命令指定的应用是否为可调试应用，可以执行以下命令进行查询：hdc shell "bm dump -n [应用包名] | grep appProvisionType"查询，预期返回信息为"appProvisionType": "debug"。

以包名com.example.myapplication为例，可执行如下命令查询：

```shell
hdc shell "bm dump -n com.example.myapplication | grep appProvisionType"
```

如包名对应的应用是可调试应用，预期返回信息：

```shell
"appProvisionType": "debug",
```

构建可调试应用需要使用调试证书进行签名，申请调试证书及签名可参考：[申请调试证书](https://developer.huawei.com/consumer/cn/doc/app/agc-help-add-debugcert-0000001914263178)。


### 查询虚拟机堆内存

<!--RP2-->
使用hidumper --mem-jsheap pid [-T tid] [--gc] [--leakobj] [--raw]命令可以查看ArkTS应用虚拟机堆内存，使用hidumper --mem-cjheap pid [--gc]命令可以查看仓颉应用虚拟机堆内存。生成的堆内存文件存放于/data/log/faultlog/temp目录。
<!--RP2End-->

> **注意：**
>
> hidumper --mem-jsheap pid [-T tid] [--gc] [--leakobj] [--raw]命令调试的进程应为“使用调试证书签名的应用”，同[debug版本应用](performance-analysis-kit-terminology.md#debug版本应用)。
>
> 确认命令指定的应用是否为可调试应用：参考上述hidumper --mem-smaps [pid] [-v]命令中的注意事项。

- 可使用hidumper --mem-jsheap pid命令获取指定进程所有JS线程的虚拟机堆内存，文件命名为：<!--RP1-->jsheap-进程号-JS线程号-时间戳<!--RP1End-->，如果有多个JS线程会生成多个文件。

  使用样例：

  <!--RP3-->
  ```shell
  $ hidumper --mem-jsheap 64949  -> 64949 为目标应用进程号
  $ ls | grep jsheap   -> 进入堆内存文件存放目录后执行
  jsheap-64949-64949-1751075546050
  jsheap-64949-64989-1751075546050
  ```
  <!--RP3End-->

- 可使用hidumper --mem-jsheap pid -T tid命令获取指定进程指定JS线程的虚拟机堆内存，文件命名为：<!--RP1-->jsheap-进程号-JS线程号-时间戳<!--RP1End-->。

  使用样例：

  <!--RP4-->
  ```shell
  $ hidumper --mem-jsheap 64949 -T 64949  -> 64949 为目标应用进程号
  $ ls | grep jsheap  -> 进入堆内存文件存放目录后执行
  jsheap-64949-64949-1751075567710
  ```
  <!--RP4End-->

- 可使用hidumper --mem-jsheap pid [-T tid] --raw获取指定进程或指定JS线程的虚拟机堆内存，生成的堆内存文件为rawheap格式，文件命名为<!--RP1-->jsheap-进程号-JS线程号-时间戳<!--RP1End-->.rawheap。rawheap的解析转换可参考使用：[rawheap-translator工具](../tools/rawheap-translator.md)。

  使用样例：

  <!--RP5-->
  ```shell
  $ hidumper --mem-jsheap 64949 --raw  -> 64949 为目标应用进程号
  $ ls | grep jsheap  -> 进入堆内存文件存放目录后执行
  jsheap-64949-64949-1751075546050.rawheap
  jsheap-64949-64989-1751075546050.rawheap
  $ hidumper --mem-jsheap 64949 -T 64949 --raw  -> 64949 为目标应用进程号
  $ ls | grep jsheap
  jsheap-64949-64949-1751075546055.rawheap
  ```
  <!--RP5End-->

- 可使用hidumper --mem-jsheap pid --gc命令触发指定应用进程GC。该命令不会生成任何文件，执行成功不会有命令回显。

  使用样例：

  ```shell
  $ hidumper --mem-jsheap 64949 --gc  -> 64949 为目标应用进程号
  ```

- 可使用hidumper --mem-jsheap pid --leakobj获取指定进程的虚拟机堆内存和泄漏对象信息，文件命名为：<!--RP6-->leaklist-进程号-时间戳<!--RP6End-->。

    获取指定进程的虚拟机堆内存和泄露对象信息的前提是应用已通过[@ohos.hiviewdfx.jsLeakWatcher (js泄露检测)](../reference/apis-performance-analysis-kit/js-apis-jsleakwatcher.md)接口开启了泄漏检测功能。

    具体使用步骤为：

    1. 应用调用[jsLeakWatcher.enable](../reference/apis-performance-analysis-kit/js-apis-jsleakwatcher.md#jsleakwatcherenable)接口。
    2. 应用调用[jsLeakWatcher.watch](../reference/apis-performance-analysis-kit/js-apis-jsleakwatcher.md#jsleakwatcherwatch)接口。
    3. 执行hidumper --mem-jsheap [pid] --leakobj命令，导出虚拟机堆内存和泄漏对象信息。

  使用样例：

  <!--RP7-->
  ```shell
  $ hidumper --mem-jsheap 64949 --leakobj
  $ ls | grep leaklist
  leaklist-64949-1730873210483
  ```
  <!--RP7End-->

<!--Del-->
- 可使用hidumper --mem-cjheap pid命令获取指定仓颉进程的虚拟机堆内存，文件命名为：cjheap-进程号-时间戳。

  使用样例：

  ```shell
  $ hidumper --mem-cjheap 65012  -> 65012 为目标应用进程号
  $ ls | grep cjheap   -> 进入堆内存文件存放目录后执行
  cjheap-65012-1751075546050
  ```

- 可使用hidumper --mem-cjheap pid --gc命令触发指定仓颉应用进程GC。该命令不会生成任何文件，执行成功不会有命令回显。

  使用样例：

  ```shell
  $ hidumper --mem-cjheap 65012 --gc  -> 65012 为目标应用进程号
  ```
<!--DelEnd-->
上述生成的文件，可以通过hdc[文件传输](hdc.md#文件传输)命令从设备中获取。


## 查询CPU使用情况

使用hidumper工具查看CPU相关信息，可以了解到当前系统的CPU负载情况。


### 查询整机CPU使用率

可使用hidumper --cpuusage获取整机CPU使用率。

打印效果为：

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


### 查询进程CPU使用率

可使用hidumper --cpuusage pid获取指定进程的CPU使用率。

打印效果为：

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


### 查询CPU频率

可使用hidumper --cpufreq获取CPU频率信息。

打印效果为：

```shell
$ hidumper --cpufreq

-------------------------------[cpufreq]-------------------------------


cmd is: cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq

1018000

cmd is: cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq

1530000
...
```


## 查询系统服务


### 查询系统服务列表

- 可使用hidumper -ls命令获取正在运行的系统服务列表。

打印效果为：

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


### 获取系统服务详细信息

- 可使用hidumper -s获取所有系统服务的详细信息。

打印效果为：

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


- 可使用hidumper -s [SA0] [SA1]获取指定的一个或多个系统服务的详细信息。其中系统能力名[SA0] [SA1]可通过上述hidumper -ls命令查询得到。


打印效果为：


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


### 获取指定系统服务提供的能力


可使用hidumper -s [SA] -a ["option"]可以获取指定系统服务提供的能力。


以RenderService系统渲染服务为例，获取其使用帮助，打印效果如下：


```shell
$ hidumper -s RenderService -a "h"

-------------------------------[ability]-------------------------------

----------------------------------RenderService----------------------------------
------ Graphic2D--RenderSerice ------
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
screen                        |dump all screen infomation in the system
```


系统服务提供的具体功能，如获取GPU相关信息，可以使用以下命令，打印结果如下：

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


## 查询进程信息

可使用hidumper -p [pid]命令获取指定进程的相关信息，包括进程的挂载信息，进程的线程信息，线程的运行时间，进程等待通道信息。


> **注意：**
>
> hidumper -p [pid]命令调试的进程应为“使用调试证书签名的应用”。
>
> 确认命令指定的应用是否为可调试应用：参考hidumper --mem-smaps [pid] [-v]命令中的介绍。


打印效果为：


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


## 查询网络信息

可使用hidumper --net命令获取网络流量信息，网络接口统计信息、网口统计信息、IP信息、iptable信息和binder信息。该功能是通过netstat、ifconfig、iptables等系统命令获取网络信息。

打印效果为：

```shell
$ hidumper --net

-------------------------------[net traffic]-------------------------------

Received Bytes:0
Sent Bytes:51885

-------------------------------[net]-------------------------------

cmd is: netstat -nW  -> 通过netstat -nW命令查询网络连接、路由表、接口统计等网络相关信息。
...
```


可使用hidumper --net [pid]命令获取指定进程的网络流量信息。


打印效果为：


```shell
$ hidumper --net 1

-------------------------------[net traffic]-------------------------------

Received Bytes:0
Sent Bytes:51885
```


## 查询存储信息

- 可使用hidumper --storage命令获取磁盘统计信息、磁盘使用量信息、文件句柄信息、IO流量统计信息和挂载信息。

打印效果为：

```shell
$ hidumper --storage

-------------------------------[storage]-------------------------------


cmd is: storaged -u -p
...
```


- 可使用hidumper --storage [pid]命令获取指定进程的IO信息。


打印效果为：


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


IO信息的相关字段解释如下：


- rchar：代表自进程启动以来所读取的总字符数，包括通过缓存或直接读取的字符。单位为Byte。

- wchar：代表自进程启动以来所写入的总字符数，包括通过缓存或直接写入的字符。单位为Byte。

- syscr：代表自进程启动以来所执行的 read 系统调用的次数。

- syscw：代表自进程启动以来所执行的 write 系统调用的次数。

- read_bytes：代表自进程启动以来所读取的字节数，包括从文件系统、网络等设备读取的字节数。单位为Byte。

- write_bytes：代表自进程启动以来所写入的字节数，包括写入到文件系统、网络等设备的字节数。单位为Byte。

- cancelled_write_bytes：代表自进程启动以来，因写入操作被取消而未写入的字节数。通常情况下，只有在向磁盘写入数据时发生错误或写入操作被中断时，该字段的值才会非零。单位为Byte。


## 查询系统信息

- 可使用hidumper -lc命令获取系统信息簇列表。

打印效果为：

```shell
$ hidumper -lc
System cluster list:
base                             system
```

- 可使用hidumper -c [系统通信息簇名称]命令获取指定信息簇信息。

例如可使用hidumper -c base命令获取设备信息、内核版本、启动参数和启动时间。打印效果为：

```shell
-------------------------------[base]-------------------------------

BuildId: ALN-AL00 5.0.1.XXX(XXX)   -> 设备信息
ReleaseType: Beta1
OsVersion: phone/HUAWEI/HUAWEI/ALN/OpenHarmony-5.0.1.XXX(Beta1)/ALN-AL10/ALN-AL10/XX/5.0.1.XXX/default
DeviceType: phone
...

/proc/version

Hongmeng version: HongMeng Kernel X.XX.XX  -> 内核版本

/proc/cmdline   -> 启动参数

ohos.boot.post_data_blks=0x0 ohos.boot.ptn_last_blk=0x772AFFF ...

cmd is: uptime -p

up 0 weeks, 0 days, 5 hours, 27 minutes   -> 启动时间
```

例如可使用hidumper -c system命令获取环境变量、内核模块信息、当前已加载的内核模块、slab信息、zone信息、vmstat、vmalloc信息、cpu频率信息和内存信息。打印效果为：

```shell
$ hidumper -c system

-------------------------------[system]-------------------------------


cmd is: printenv   -> 环境变量

_=/system/bin/printenv
LANG=en_US.UTF-8
HOME=/root
PULSE_STATE_PATH=/data/data/.pulse_dir/state
OLDPWD=/
PWD=/
TMP=/data/local/mtp_tmp/
PULSE_RUNTIME_PATH=/data/data/.pulse_dir/runtime
...

/proc/modules   -> 内核模块信息

modem_driver 1490944 24 - Live 0x0000000000000000
hmtpp_freq_dal_kirin 20480 0 [permanent], Live 0x0000000000000000 (O)
kconsole 20480 0 [permanent], Live 0x0000000000000000 (O)
hmtpp_dal 40960 2 hmtpp_freq_dal_kirin, Live 0x0000000000000000 (O)
...

cmd is: lsmod  -> 当前已加载的内核模块

Module                  Size  Used by
modem_driver         1490944  24
hmtpp_freq_dal_kirin    20480  0 [permanent]
kconsole               20480  0 [permanent]
hmtpp_dal              40960  2 hmtpp_freq_dal_kirin
...

/proc/slabinfo   -> slab 信息

slabinfo - version: 2.0
#name       <active_objs> <num_objs> <objsize> <objperslab> <pagesperslab> : tunables <limit> <batchcount> <sharedfactor> : slabdata <active_slabs> <num_slabs> <num_pool> <sharedavail> <reclaimable>
slab-[16]                  48459  54432     16    252      1 : tunables 0 0 0 : slabdata    215    216      4 0 0
slab-[24]                  78315  83328     24    168      1 : tunables 0 0 0 : slabdata    496    496      4 0 0
slab-[32]                   5834   9954     32    126      1 : tunables 0 0 0 : slabdata     79     79      4 0 0
...

/proc/zoneinfo   -> zone 信息

Node 0, zone      DMA
  per-node stats
      nr_inactive_anon 419922
      nr_active_anon 11737
      nr_inactive_file 381289
      nr_active_file 456643
...

/proc/vmstat   -> vmstat 信息

workingset_refault_anon    63071
workingset_refault_file        0
workingset_activate_anon     1742
workingset_activate_file        0
...

/proc/vmallocinfo   -> vmalloc 信息

0x0000000000000000-0x0000000000000000    4096 of_iomap+0xe4/0xec pages=1 phys=0xfb21b000 ioremap
0x0000000000000000-0x0000000000000000    4096 of_iomap+0xe4/0xec pages=1 phys=0xffb85000 ioremap
0x0000000000000000-0x0000000000000000    4152 gen_pool_add_owner+0x48/0xc0 pages=2 vmalloc
0x0000000000000000-0x0000000000000000    4096 of_iomap+0xe4/0xec pages=1 phys=0xee262000 ioremap
...

cmd is: cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq   -> CPU 频率信息

1430000

cmd is: cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq

1530000

cmd is: cat /sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq

1430000
...

-------------------------------[memory]-------------------------------     -> 内存信息
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

- 可使用hidumper -c命令获取全量信息簇信息。这包含上述base和system信息簇合集。


## 获取系统故障日志

可使用hidumper -e命令获取系统故障日志，打印对应故障日志的文件名及详细内容。

```shell
$ hidumper -e

-------------------------------[faultlog]-------------------------------


/data/log/faultlog/faultlogger/syswarning-com.ohos.sceneboard-20020022-20241106104006  -> 故障日志文件名

Generated by HiviewDFX@OpenHarmony  -> 故障日志详细内容
...
```


## 获取进程间通信信息

可使用hidumper --ipc -a --start-stat/stop-stat/stat命令获取整机采集时间区间内IPC信息。

打印效果为：

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

可使用hidumper --ipc [pid] --start-stat/stop-stat/stat命令获取指定进程采集时间区间内的IPC信息。

打印效果为：

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


## 导出信息压缩存储

hidumper提供有--zip命令支持将任意类型导出信息输出到 /data/log/hidumper 下的压缩文件，可以与其他命令组合使用，压缩格式为ZIP，文件命名为当前时间戳，如下打印效果所示。

```shell
$ hidumper --zip
100%,[-],The result is:/data/log/hidumper/20250622-120444-166.zip
```

例如，对于 hidumper -e 命令获取系统故障日志，其输出的文本内容较多，可以考虑使用压缩存储，打印效果如下：

```shell
$ hidumper -e

-------------------------------[faultlog]-------------------------------


/data/log/faultlog/faultlogger/syswarning-com.ohos.sceneboard-20020022-20241106104006  -> 故障日志文件名

Generated by HiviewDFX@OpenHarmony
...  -> 故障日志详细内容，大量的文本内容，此处省略
$ hidumper -e --zip
100%,[-],The result is:/data/log/hidumper/20250623-092235-087.zip
```

## 常用ArkUI基础信息显示能力
ArkUI基于hidumper增强开发了获取组件树等信息的能力。
### 获取应用窗口信息
打印全量窗口信息，可以在全量信息中找出对应窗口的WinId，将该WinId作为参数传递给其他命令以获取相关信息。

```shell
hdc shell hidumper -s WindowManagerService -a '-a'
```
 **使用样例：**
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

常见windowName与内置应用窗口的对应关系：
|windowName|内置应用窗口|
|---|---|
| EntryView|桌面|
| RecentView|最近任务|
| SystemUi_NavigationBar|三键导航|
|  SystemUi_StatusBar|状态栏|
| ScreenLockWindow|锁屏|

### 获取期望应用组件树
如果需要查看应用中所有组件的信息，可以通过下列命令实现。

```shell
hdc shell "hidumper -s WindowManagerService -a '-w %windowId% -element'"
```
windowId是期望应用的窗口ID。

**使用样例：**

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

### 获取应用中指定Node的组件信息
如果只需要查看组件中某一节点的组件信息，可以通过下列命令实现。

```shell
hdc shell "hidumper -s WindowManagerService -a '-w %windowId% -element -lastpage %nodeID%'"
```
windowId是应用的窗口ID，nodeID是指定Node的ID。可以通过获取期望应用组件树的操作获取nodeID。

**使用样例：**
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

### 获取期望应用的Inspector树
上述示例中的element/render树主要包含多项内部实现，与应用代码中的组件无法一一对应。可以通过打印Inspector树来获取与应用中组件对应的树结构及组件基本信息。Inspector树与DevEco Testing及DevEco中的ArkUI Inspector完全匹配。

使用此功能需要先打开ArkUI debug调试开关。
```shell
hdc shell param set persist.ace.testmode.enabled 1
```
set: 设置命令；persist.ace.testmode.enabled：ArkUI debug调试开关名称；1：开关设置为true，打开调试功能。

命令如下：
```shell
hdc shell "hidumper -s WindowManagerService -a '-w %windowId% -inspector'"
```
**使用样例：**

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

### 获取期望应用路由栈信息

该命令将输出应用页面路由栈的信息，依据栈的创建顺序及其父子关系排列。

> **说明：**
>
> 仅支持通过[Navigation](../ui/arkts-navigation-navigation.md)组件实现页面路由的应用。

命令：

```shell
hidumper -s WindowManagerService -a '-w %windowId% -navigation -c'
```
**使用样例：**
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
> **说明：**
>
> 同一级别的节点，显示在最下方的节点为栈顶节点。

## 常见问题


### hidumper 查询到的内存使用情况与hidebug接口获取到的内存使用情况之间的关系

**现象描述**

hidumper --mem 系列命令与[HiDebug](../reference/apis-performance-analysis-kit/js-apis-hidebug.md)接口获取到的内存信息存在差异。

**可能原因&amp;解决方法**

hidumper --mem命令与HiDebug接口内存获取功能详细对比参考下表。

**表1**

| 命令或接口 | 使用场景 | 数据来源 | 是否导出图形内存 |
| -------- | -------- | -------- | -------- |
| hidumper --mem | 命令行获取**所有进程**的内存使用情况 | 系统节点：/proc/pid/smaps_rollup | 是 |
| hidumper --mem [pid] | 命令行获取**单个进程**的内存使用情况 | 系统节点：/proc/pid/smaps | 是 |
| hidumper --mem-smaps [pid] | 命令行获取**单个进程**的详细内存使用情况 | 系统节点：/proc/pid/smaps_rollup | 否 |
| [hidebug.getAppNativeMemInfo](../reference/apis-performance-analysis-kit/js-apis-hidebug.md#hidebuggetappnativememinfo12) | 获取**应用自身**的内存使用情况 | 系统节点：/proc/pid/smaps_rollup | 否 |

若想通过hidebug获取图形内存，请参考[HiDebug能力概述](hidebug-guidelines.md)中的相关说明。


### hidumper获取进程虚拟机内存和泄露对象信息为空

**现象描述**

通过hidumper --mem-jsheap [pid] --leakobj命令获取指定进程的虚拟机堆内存和泄露对象信息，该命令没有正常生成文件。

**可能原因&amp;解决方法**

hidumper --mem-jsheap [pid] --leakobj 命令依赖[JsLeakWatcher](../reference/apis-performance-analysis-kit/js-apis-jsleakwatcher.md)。应用需通过JsLeakWatcher接口开启泄漏检测功能。具体步骤参考：[查询虚拟机堆内存](#查询虚拟机堆内存)。
