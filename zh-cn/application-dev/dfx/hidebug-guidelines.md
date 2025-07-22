# HiDebug能力概述

HiDebug可用于系统或应用进程的内存、CPU、GPU等相关数据的获取，开启进程Trace采集等。

本文主要介绍当前HiDebug模块中提供的ArkTS及C/C++接口，并根据接口能力进行分类。

接口详情可查看[ArkTS API参考文档](../reference/apis-performance-analysis-kit/js-apis-hidebug.md)及[C API参考文档](../reference/apis-performance-analysis-kit/capi-hidebug-h.md)。

## 约束限制

由于该模块的接口所需获取的信息比较耗费性能，接口调用较为耗时，部分接口调用时长可达秒级，甚至导致调用线程发生freeze。且基于HiDebug模块定义，该模块内的接口仅建议在应用调试、调优阶段使用。若需要在其他场景使用时，请在使用前认真评估所需调用的接口对应用性能的影响。

## 获取内存信息

HiDebug可用于整机内存、应用进程内存占用、应用线程内存占用、以及内存分配器统计的native内存分配数据的获取。在程序开发过程中，查看设备及应用进程的内存数据，是发现和解决各种问题，优化程序性能以及确保程序稳定性的关键手段。

### 接口说明（ArkTS）

| | |
| -------- | -------- |
| hidebug.getNativeHeapSize | 获取内存分配器统计的进程持有的普通块所占用的总字节数。mallinfo接口中获取到的uordblks与fordblks之和。 |
| hidebug.getNativeHeapAllocatedSize | 获取内存分配器统计的进程持有的已使用的普通块所占用的总字节数。mallinfo接口中获取到的uordblks。 |
| hidebug.getNativeHeapFreeSize | 获取内存分配器统计的进程持有的空闲的普通块所占用的总字节数。mallinfo接口中获取到的fordblks。 |
| hidebug.getPss | 获取应用进程实际使用的物理内存大小。读取/proc/{pid}/smaps_rollup节点中的Pss与SwapPss值并求和。 |
| hidebug.getVss | 获取应用进程虚拟耗用内存大小。读取/proc/{pid}/statm节点中的size值（内存页数），vss = size \* 页大小（4K/页）。 |
| hidebug.getSharedDirty | 获取进程的共享脏内存大小。读取/proc/{pid}/smaps_rollup节点中的Shared_Dirty值。 |
| hidebug.getPrivateDirty | 获取进程的私有脏内存大小。读取/proc/{pid}/smaps_rollup中的Private_Dirty值。 |
| hidebug.getAppNativeMemInfo | 获取应用进程内存信息。读取/proc/{pid}/smaps_rollup和/proc/{pid}/statm节点的数据。 |
| hidebug.getAppNativeMemInfoAsync | 异步方式获取应用进程内存信息。<br/>**说明**：从API version 20开始，支持该接口。 |
| hidebug.getAppNativeMemInfoWithCache | 获取应用进程内存信息（该接口存在缓存机制以提高接口性能）。<br/>**说明**：从API version 20开始，支持该接口。 |
| hidebug.getSystemMemInfo | 获取系统内存信息。读取/proc/meminfo节点的数据。 |
| hidebug.getAppMemoryLimit | 获取应用程序进程内存限制，其中rsslimit由getrlimit 接口获取到的RLIMIT_RSS资源值，vsslimit由getrlimit接口获取到的的RLIMIT_AS资源值。 |

### 接口说明（C/C++）

| | |
| -------- | -------- |
| OH_HiDebug_GetSystemMemInfo | 获取系统内存信息。读取/proc/meminfo节点的数据。 |
| OH_HiDebug_GetAppNativeMemInfo | 获取应用进程内存信息。读取/proc/{pid}/smaps_rollup和/proc/{pid}/statm节点的数据。 |
| OH_HiDebug_GetAppNativeMemInfoWithCache | 获取应用程序进程的内存信息，该接口存在缓存机制以提高性能。<br/>**说明**：从API version 20开始，支持该接口。 |
| OH_HiDebug_GetAppMemoryLimit | 获取应用程序进程内存限制，其中rsslimit由getrlimit 接口获取到的RLIMIT_RSS资源值，vsslimit有getrlimit接口获取到的的RLIMIT_AS资源值。 |

## 获取显存信息

HiDebug可用获取应用所占用显存（图形显示所需占用的内存）资源数据。在图形化密集型应用中，显存的管理至关重要，滥用显存资源将导致应用运行严重卡顿，进而影响用户体验。显存资源包括以下两个部分：

1. MemoryTracker统计的由GPU驱动程序使用物理页面分配器直接分配的内存，该部分内存取决于GPU硬件驱动程序的实现。

2. RenderService渲染进程加载的该进程渲染时所需资源占用的内存，例如图片，纹理等资源。

### 接口说明(ArkTS)

| | |
| -------- | -------- |
| hidebug.getGraphicsMemory | 使用异步方式获取应用显存大小。 |
| hidebug.getGraphicsMemorySync | 使用同步方式获取应用显存大小。 |

### 接口说明(C/C++)

| | |
| -------- | -------- |
| OH_HiDebug_GetGraphicsMemory | 获取应用显存大小。 |

## 获取CPU使用率

应用开发过程中，监控CPU使用率是性能分析的重要方面。获取CPU使用率可以帮助开发者优化应用性能，确保应用运行流畅。为了便于获取CPU使用率，HiDebug提供了多个接口以供使用。

### 实现原理

hiview进程会按照10s的周期，获取当前CPU的运行数据并缓存，以作为CPU使用率的计算基准，主要包括以下数据：

1.系统CPU使用数据：

/proc/stat节点包含了自系统启动以来CPU 运行数据的统计信息，可在终端中使用以下命令查看该节点信息：

```
cat  /proc/stat
cpu  648079 547 703220 16994706 23006 101071 0 0 0 0
...
```

CPU 指标字段含义：

CPU 的统计信息从左到右分别代表以下含义（其中cpu为所有cpu运行数据的总和）

- user: 用户态时间（单位：jiffies）

- nice: nice 用户态时间（单位：jiffies）

- system: 内核态时间（单位：jiffies）

- idle: 空闲时间（单位：jiffies，不包含 IO 等待时间）

- iowait: IO 等待时间（单位：jiffies）

- irq: 硬中断时间（单位：jiffies）

- softirq: 软中断时间（单位：jiffies）

- steal: 被盗时间（虚拟化环境中运行其他操作系统上花费的时间）

- guest: 来宾时间（操作系统运行虚拟 CPU 花费的时间）

- guest_nice: nice 来宾时间（运行一个带 nice 值的 guest 花费的时间）

2.进程CPU使用数据/线程CPU使用数据：

```
// 内核统计的进程cpu运行数据
struct ucollection_process_cpu_item {
    int pid;
    unsigned int thread_total;
    unsigned long long min_flt;
    unsigned long long maj_flt;
    unsigned long long cpu_usage_utime; // 用户态CPU运行时长
    unsigned long long cpu_usage_stime;// 内核态CPU运行时长
    unsigned long long cpu_load_time;
};
// 内核统计的线程cpu运行数据
struct ucollection_thread_cpu_item {
    int tid;
    char name[16]; // 16 ：max length of thread name
    unsigned long long cpu_usage_utime;// 用户态CPU运行时长
    unsigned long long cpu_usage_stime;// 内核态CPU运行时长
    unsigned long long cpu_load_time;
};
```

当调用接口时，通过获取当前数据，与基准数据计算求得增量，并通过以下公式获取CPU使用率：

系统CPU使用率：

```
(systemUsage增量 + niceUsage增量 + userUsage增量) /(userTime增量 + niceTime增量 + systemTime增量 + idleTime增量 + ioWaitTime增量 + irqTime增量 + softIrqTime增量)
```

进程CPU使用率或线程CPU使用率 ：

```
(cpu_usage_utime增量 + cpu_usage_stime增量) /(ms级时间戳增量)
```

### 接口说明(ArkTS)

| | |
| -------- | -------- |
| hidebug.getAppThreadCpuUsage | 获取应用线程的CPU使用率。 |
| hidebug.getCpuUsage | 获取应用进程CPU使用率。 |
| hidebug.getSystemCpuUsage | 获取系统CPU使用率。 |

### 接口说明(C/C++)

| | |
| -------- | -------- |
| OH_HiDebug_GetSystemCpuUsage | 获取系统的CPU使用率。 |
| OH_HiDebug_GetAppCpuUsage | 获取进程的CPU使用率。 |
| OH_HiDebug_GetAppThreadCpuUsage | 获取应用所有线程CPU使用率。 |
| OH_HiDebug_FreeThreadCpuUsage | 释放通过OH_HiDebug_GetAppThreadCpuUsage接口获取到的数据。 |

## 获取VM信息

HiDebug可用于VM内存数据，GC统计数据的获取，以及VM堆转储。

### 接口说明(ArkTS)

| | |
| -------- | -------- |
| hidebug.getAppVMMemoryInfo | 获取VM内存相关信息。 |
| hidebug.getVMRuntimeStats | 获取系统[GC](../arkts-utils/gc-introduction.md)统计信息。 |
| hidebug.getVMRuntimeStat | 根据参数获取指定的系统[GC](../arkts-utils/gc-introduction.md)统计信息。 |
| hidebug.dumpJsRawHeapData | 使用异步方式为当前线程转储虚拟机的原始堆快照，辅助[JS内存泄漏分析](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-memory-leak-detection)。 |
| hidebug.dumpJsHeapData | 使用同步方式导出虚拟机堆，辅助[JS内存泄漏分析](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-memory-leak-detection)。 |
| hidebug.getAppMemoryLimit | 获取应用程序进程内存限制，其中vmHeapLimit为当前线程对应的虚拟机堆大小限制，vmTotalHeapSize为当前进程所有虚拟机堆总和大小的限制。 |

## 获取应用Trace记录

HiTrace提供业务流程调用链跟踪的维测接口，帮助开发者迅速获取指定业务流程调用链的运行日志，定位跨设备、跨进程、跨线程的故障问题，详情请参考[Trace性能跟踪](hitracemeter-intro.md)。为了便于实现HiTrace的自动化采集，HiDebug模块提供了启动以及停止HiTrace采集的接口。

### 接口说明(ArkTS)

| | |
| -------- | -------- |
| hidebug.startAppTraceCapture | 启动应用Trace采集。 |
| hidebug.stopAppTraceCapture | 停止应用Trace采集。 |

### 接口说明(C/C++)

| | |
| -------- | -------- |
| OH_HiDebug_StartAppTraceCapture | 启动应用Trace采集。 |
| OH_HiDebug_StopAppTraceCapture | 停止应用Trace采集。 |

## 虚拟机CpuProfiler采集

HiDebug提供了开启与停止VM虚拟机CpuProfiler采集的接口，以协助用户可以实现CpuProfiler的自动采集。

### 接口说明(ArkTS)

| | |
| -------- | -------- |
| hidebug.startJsCpuProfiling | 启动虚拟机Profiling方法跟踪。 |
| hidebug.stopJsCpuProfiling | 停止虚拟机Profiling方法跟踪。 |

## 获取调用栈信息

获取方法的调用栈信息对于调试和错误处理非常有用。调用栈信息可以帮助开发者了解方法的调用顺序和调用者的信息。为了便于开发者获取调用栈信息，HiDebug开放了获取应用调用栈的接口。

### 栈回溯原理

ARM64架构函数栈帧的结构如下图所示：

**图1**
![arm64 stack](figures/arm64 stack.png)

FP：栈顶指针，指向一个栈帧的顶部，当函数发生跳转时，会记录当时的栈的起始位置。

SP：栈指针（也称为栈底指针），指向栈当前的位置。

LR：保存函数返回的地址。

如图，与FP相邻的地址分别保存了上一帧的FP地址与当前帧的函数返回地址。在进行栈回溯时，可通过函数返回地址解析上一帧的栈信息，同时根据上一帧的FP地址，依次找出每个函数栈帧中存储的LR及FP地址。基于FP回栈的特性，在当前调用函数中只能获取到当前函数的返回地址进行栈解析，所以FP回栈无法获取到当前函数的调用栈信息。

### 接口说明(C/C++)

| | |
| -------- | -------- |
| OH_HiDebug_CreateBacktraceObject | 创建一个用于栈回溯及栈解析的对象。<br/>说明：从API version 20开始，支持该接口。 |
| OH_HiDebug_DestroyBacktraceObject | 销毁OH_HiDebug_CreateBacktraceObject接口创建的用于栈回溯及栈解析对象。<br/>说明：从API version 20开始，支持该接口。 |
| OH_HiDebug_BacktraceFromFp | 获取从给定的栈帧指针开始的回溯帧。<br/>说明：从API version 20开始，支持该接口。 |
| OH_HiDebug_SymbolicAddress | 通过给定的程序计数器（PC）获取详细的符号信息。<br/>说明：从API version 20开始，支持该接口。 |

## 设置资源泄露检测阈值

HiDebug提供了可以设置系统资源泄露检测阈值的接口，开发者可根据业务需要，自定义资源泄露事件触发的阈值。接口主要应用场景在于构造内存泄漏，以辅助相关功能开发，详情请参考[资源泄漏检测](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/resource-leak-guidelines)。

### 接口说明(ArkTS)

| 接口名 | 描述 |
| -------- | -------- |
| hidebug.setAppResourceLimit | 设置应用的fd数量、线程数量、js内存或者native内存等资源触发资源泄露检测事件的阈值。 |

## GWP-Asan管理

HiDebug提供了启停[GWP-Asan](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-gwpasan-detection)使能，以及查询剩余使能天数的能力。

### 接口说明(ArkTS)

| 接口名 | 描述 |
| -------- | -------- |
| hidebug.enableGwpAsanGrayscale | 使能GWP-Asan，用于检测堆内存使用中的非法行为。 |
| hidebug.disableGwpAsanGrayscale | 停止使能GWP-Asan。 |
| hidebug.getGwpAsanGrayscaleState | 获取当前GWP-Asan剩余使能天数。 |

## 其他

HiDebug提供了获取应用调试状态，启动系统进程DUMP信息采集等。

### 接口说明(ArkTS)

| 接口名 | 描述 |
| -------- | -------- |
| hidebug.isDebugState | 获取应用进程被调试状态。如果应用进程的Ark层或Native层处于调试状态，则返回true；否则返回false。 |
| hidebug.getServiceDump | 获取系统服务的DUMP信息，仅系统应用可调用。 |

## 常见问题

**在使用OH_HiDebug_StartAppTraceCapture和startAppTraceCapture接口抓取HiTrace日志时，接口返回路径为设备内物理路径**

接口返回的路径为设备内的真实物理路径，如需要在应用内访问，请参考[应用沙箱路径和真实物理路径的对应关系](../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)，需将真实物理路径转化为沙箱路径。

例如：/data/app/el2/100/log/com.example.myapplication/trace/com.example.myapplication_20250604_173158.trace -> /data/storage/el2/base/trace/com.example.myapplication_20250604_173158.trace

**在使用OH_HiDebug_GetAppThreadCpuUsage与getAppThreadCpuUsage接口获取线程CPU使用率时，新创建线程的使用率为0**

基于CPU使用率的计算方式，需要获取同时获取到当前CPU运行统计数据与hiview每10s周期性刷新的计算基准值，新创建线程由于没有计算基准值，导致CPU使用率无法计算，默认返回0。
