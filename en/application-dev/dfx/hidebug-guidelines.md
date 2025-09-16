# Introduction to HiDebug

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--Designer: @kutcherzhou1-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

HiDebug can obtain the memory, CPU, and GPU data of the system or application processes, and enable process trace collection.

This topic describes the ArkTS and C/C++ APIs of the HiDebug module and classifies them by API capability.

For details about the APIs, see [ArkTS API Reference](../reference/apis-performance-analysis-kit/js-apis-hidebug.md) and [C API Reference](../reference/apis-performance-analysis-kit/capi-hidebug-h.md).

## Constraints

API calls of this module are time-consuming. Some API calls take seconds, which may cause thread freezes. It is recommended that the APIs of the HiDebug module be used only in the application debugging and optimization phases. If the APIs are required in other scenarios, evaluate the impact of the APIs on application performance.

## Obtaining Memory Information

HiDebug can obtain the system memory, application process memory usage, application thread memory usage, and native memory allocation data collected by the memory allocator. During program development, these memory data can be used to detect and solve problems, optimize program performance, and ensure program stability.

### APIs (ArkTS)

| Name| Description  |
| -------- | -------- |
| hidebug.getNativeHeapSize | Obtains the total number of bytes occupied by the total space (**uordblks** and **fordblks**, which are obtained through **mallinfo**) held by a process, which is measured by the memory allocator.|
| hidebug.getNativeHeapAllocatedSize | Obtains the total number of bytes occupied by the total allocated space (**uordblks**, which is obtained through **mallinfo**) held by a process, which is measured by the memory allocator.|
| hidebug.getNativeHeapFreeSize | Obtains the total number of bytes occupied by the total free space (**fordblks**, which is obtained from **mallinfo**) held by a process, which is measured by the memory allocator.|
| hidebug.getPss | Obtains the size of the physical memory actually used by the application process. This API is implemented by reading and summing up the values of **Pss** and **SwapPss** in the **/proc/{pid}/smaps_rollup** node.|
| hidebug.getVss | Obtains the virtual set size used by the application process. This API is implemented by reading the value of **size** (number of memory pages) from the **/proc/{pid}/statm** node and calculating the value using the following formula: **vss** = **size** × page size (4 KB/page).|
| hidebug.getSharedDirty | Obtains the size of the shared dirty memory of a process. This API is implemented by reading the value of **Shared_Dirty** in **/proc/{pid}/smaps_rollup**.|
| hidebug.getPrivateDirty | Obtains the size of the private dirty memory of a process. This API is implemented by reading the value of **Private_Dirty** in the **/proc/{pid}/smaps_rollup** node.|
| hidebug.getAppNativeMemInfo | Obtains the memory information of the application process. This API is implemented by reading data from the **/proc/{pid}/smaps_rollup and /proc/{pid}/statm** node.|
| hidebug.getAppNativeMemInfoAsync | Obtains the memory information of an application process in asynchronous mode.<br>**Note**: This API is supported since API version 20.|
| hidebug.getAppNativeMemInfoWithCache | Obtains the memory information of an application process. This API has a cache mechanism to improve its performance.<br>**Note**: This API is supported since API version 20.|
| hidebug.getSystemMemInfo | Obtains system memory information. This API is implemented by reading data from the **/proc/meminfo** node.|
| hidebug.getAppMemoryLimit | Obtains the memory limit of an application process. **rsslimit** and **vsslimit** are the values of **RLIMIT_RSS** and **RLIMIT_AS** obtained through the **getrlimit** API, respectively.|
| hidebug.setJsRawHeapTrimLevel | Sets the trimming level of the original heap snapshot stored by the current process.<br>**Note**: This API is supported since API version 20.|

### APIs (C/C++)

| Name| Description  |
| -------- | -------- |
| OH_HiDebug_GetSystemMemInfo | Obtains system memory information. This API is implemented by reading data from the **/proc/meminfo** node.|
| OH_HiDebug_GetAppNativeMemInfo | Obtains the memory information of the application process. This API is implemented by reading data from the **/proc/{pid}/smaps_rollup and /proc/{pid}/statm** node.|
| OH_HiDebug_GetAppNativeMemInfoWithCache | Obtains the memory information of an application process. This API has a cache mechanism to improve its performance.<br>**Note**: This API is supported since API version 20.|
| OH_HiDebug_GetAppMemoryLimit | Obtains the memory limit of an application process. **rsslimit** and **vsslimit** are the values of **RLIMIT_RSS** and **RLIMIT_AS** obtained through the getrlimit API, respectively.|

## Obtaining GPU Memory Information

HiDebug can obtain the GPU memory information of an application. In graphics-intensive applications, GPU memory management is critical. Misuse of GPU memory resources will cause severe frame freezes and affect user experience. GPU memory resources include:

1. Memory tracked by MemoryTracker, which is directly allocated by the GPU driver using the physical page allocator. Its size depends on the implementation of the GPU hardware driver.

2. Memory occupied by RenderService for loading required resources, such as images and textures.

### APIs (ArkTS)

| Name| Description  |
| -------- | -------- |
| hidebug.getGraphicsMemory | Obtains the GPU memory size of an application in asynchronous mode.|
| hidebug.getGraphicsMemorySync | Obtains the GPU memory size of an application in synchronous mode.|

### APIs (C/C++)

| Name| Description  |
| -------- | -------- |
| OH_HiDebug_GetGraphicsMemory | Obtains the GPU memory size of an application.|

## Obtaining CPU Usage

Monitoring the CPU usage is critical to performance analysis during application development. It helps optimize application performance and ensure smooth running. HiDebug provides multiple APIs to obtain the CPU usage.

### Implementation Principles

The HiView process obtains and caches the running data of the current CPU every 10 seconds as the benchmark for calculating the CPU usage. The following data is included:

1. System CPU usage data

The **/proc/stat** node contains the statistics of the CPU running data since the system is started. You can run the following command on the terminal to view the node information:

```
cat  /proc/stat
cpu  648079 547 703220 16994706 23006 101071 0 0 0 0
...
```

Fields in the CPU indicator:

The CPU statistics from left to right are as follows (**cpu** indicates the total running data of the CPU):

- **user**: user-mode time, in jiffies

- **nice**: nice user-mode time, in jiffies

- **system**: kernel-mode time, in jiffies

- **idle**: idle time, in jiffies (excluding the I/O wait time)

- **iowait**: I/O wait time, in jiffies

- **irq**: hard interrupt time, in jiffies

- **softirq**: soft interrupt time, in jiffies

- **steal**: stolen time (time spent running other operating systems in a virtual environment)

- **guest**: guest time (time spent running virtual CPUs by the operating system)

- **guest_nice**: nice guest time (time spent running a guest with a **nice** value)

2. Process/Thread CPU usage data

```
// Process CPU running data collected by the kernel
struct ucollection_process_cpu_item {
    int pid;
    unsigned int thread_total;
    unsigned long long min_flt;
    unsigned long long maj_flt;
    unsigned long long cpu_usage_utime; // User-mode CPU running duration
    unsigned long long cpu_usage_stime;// Kernel-mode CPU running duration
    unsigned long long cpu_load_time;
};
// Thread CPU running data collected by the kernel
struct ucollection_thread_cpu_item {
    int tid;
    char name[16]; // 16 : max length of thread name
    unsigned long long cpu_usage_utime;// User-mode CPU running duration
    unsigned long long cpu_usage_stime;// Kernel-mode CPU running duration
    unsigned long long cpu_load_time;
};
```

You can call the API to obtain the current data, calculate the increments based on the baseline data, and use the following formulas to obtain the CPU usages:

System CPU usage:

```
(**systemUsage** increment + **niceUsage** increment + **userUsage** increment)/(**userTime** increment + **niceTime** increment + **systemTime** increment + **idleTime** increment + **ioWaitTime** increment + **irqTime** increment + **softIrqTime** increment)
```

Process/Thread CPU usage:

```
(**cpu_usage_utime** increment + **cpu_usage_stime** increment)/(ms-level timestamp increment)
```

### APIs (ArkTS)

| Name| Description  |
| -------- | -------- |
| hidebug.getAppThreadCpuUsage | Obtains the CPU usage of an application thread.|
| hidebug.getCpuUsage | Obtains the CPU usage of an application process.|
| hidebug.getSystemCpuUsage | Obtains the system CPU usage.|

### APIs (C/C++)

| Name| Description  |
| -------- | -------- |
| OH_HiDebug_GetSystemCpuUsage | Obtains the system CPU usage.|
| OH_HiDebug_GetAppCpuUsage | Obtains the CPU usage of a process.|
| OH_HiDebug_GetAppThreadCpuUsage | Obtains the CPU usage of all threads in an application.|
| OH_HiDebug_FreeThreadCpuUsage | Releases the data obtained by calling **OH_HiDebug_GetAppThreadCpuUsage**.|

## Obtaining VM Information

HiDebug can obtain VM memory data, GC statistics, and VM heap dump data.

### APIs (ArkTS)

| Name| Description  |
| -------- | -------- |
| hidebug.getAppVMMemoryInfo | Obtains VM memory information.|
| hidebug.getVMRuntimeStats | Obtains the system [GC](../arkts-utils/gc-introduction.md) statistics.|
| hidebug.getVMRuntimeStat | Obtains the specified system [GC](../arkts-utils/gc-introduction.md) statistics based on parameters.|
| hidebug.dumpJsRawHeapData | Dumps the original VM heap snapshot for the current thread in asynchronous mode. This API is used for [JavaScript memory leak analysis](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-js-memleak-detection).|
| hidebug.dumpJsHeapData | Dumps the VM heap data in synchronous mode. This API is used for [JavaScript memory leak analysis](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-js-memleak-detection).|
| hidebug.getAppMemoryLimit | Obtains the memory limit of an application process. **vmHeapLimit** is the VM heap size limit of the current thread, and **vmTotalHeapSize** is the total size limit of all VM heaps in the current process.|

## Obtaining Application Trace Records

HiTrace provides APIs to implement call chain tracing throughout a service process. This can help you obtain the run log for the call chain of a service process and locate faults across devices, processes, and threads. For details, see [Introduction to HiTraceMeter](hitracemeter-intro.md). To implement automatic HiTrace collection, the HiDebug module provides APIs for starting and stopping a HiTrace collection.

### APIs (ArkTS)

| Name| Description  |
| -------- | -------- |
| hidebug.startAppTraceCapture | Starts an application trace collection.|
| hidebug.stopAppTraceCapture | Stops an application trace collection.|

### APIs (C/C++)

| Name| Description  |
| -------- | -------- |
| OH_HiDebug_StartAppTraceCapture | Starts an application trace collection.|
| OH_HiDebug_StopAppTraceCapture | Stops an application trace collection.|

## Starting VM CpuProfiler

HiDebug provides APIs for starting and stopping a VM CpuProfiler, helping you implement an automatic CpuProfiler collection.

### APIs (ArkTS)

| Name| Description  |
| -------- | -------- |
| hidebug.startJsCpuProfiling | Starts the VM CPU profiling.|
| hidebug.stopJsCpuProfiling | Stops the VM CPU profiling.|

## Obtaining Call Stack

Obtaining call stack information is useful for debugging and error handling. It helps you understand the method calling sequence and caller information. HiDebug provides APIs for obtaining call stack information.

### Stack Backtracing Principles

The following figure shows the structure of the function stack frame in the ARM64 architecture.

**Figure 1**
![arm64 stack](figures/arm64_stack.png)

**FP**: stack top pointer to the top of a stack frame. When a function jumps, the start position of the stack is recorded.

**SP**: stack pointer (stack bottom pointer) to the current position of the stack.

**LR**: pointer to the address returned by the function.

As shown in the preceding figure, the address adjacent to the FP stores the FP address of the previous frame and the function return address of the current frame. During stack backtracing, the stack information of the previous frame is parsed based on the function return address, and the LR and FP addresses stored in each function stack frame are found in sequence based on the FP address of the previous frame. Based on the FP stack backtracing feature, the current function can only obtain its own return address for stack parsing. Therefore, the call stack information of the current function cannot be obtained.

### APIs (C/C++)

| Name| Description  |
| -------- | -------- |
| OH_HiDebug_CreateBacktraceObject | Creates an object for stack backtracing and stack parsing.<br>Note: This API is supported since API version 20.|
| OH_HiDebug_DestroyBacktraceObject | Destroys the object created by **OH_HiDebug_CreateBacktraceObject** for stack backtracing and stack parsing.<br>Note: This API is supported since API version 20.|
| OH_HiDebug_BacktraceFromFp | Obtains the backtrace frame starting from the specified stack frame pointer.<br>Note: This API is supported since API version 20.|
| OH_HiDebug_SymbolicAddress | Obtains detailed symbol information based on the specified program counter (PC).<br>Note: This API is supported since API version 20.|

## Setting Resource Leak Detection Threshold

HiDebug provides APIs for setting the threshold of system resource leak detection. You can customize this threshold as required. This API is used to assist in memory leak detection and feature development. For details, see [Analyzing Resource Leaks](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/resource-leak-guidelines).

### APIs (ArkTS)

| Name| Description|
| -------- | -------- |
| hidebug.setAppResourceLimit | Sets the threshold for triggering resource leak detection based on the number of file descriptors (FDs), number of threads, JavaScript memory, or native memory of an application.|

## Managing GWP-Asan

HiDebug provides the capabilities of enabling and disabling GWP-Asan and querying the number of days when GWP-Asan is enabled.

### APIs (ArkTS)

| Name| Description|
| -------- | -------- |
| hidebug.enableGwpAsanGrayscale | Enables GWP-Asan to detect illegal behaviors in heap memory usage.|
| hidebug.disableGwpAsanGrayscale | Disables GWP-Asan.|
| hidebug.getGwpAsanGrayscaleState | Obtains the number of remaining days for enabling GWP-Asan.|

## Others

HiDebug provides features such as obtaining the application debugging status and starting the dump information collection of system processes.

### APIs (ArkTS)

| Name| Description|
| -------- | -------- |
| hidebug.isDebugState | Obtains the debugging state of an application process. If the Ark or native layer of the application process is in debugging state, **true** is returned. Otherwise, **false** is returned.|
| hidebug.getServiceDump | Obtains the dump information of a system service. This API can be called only by system applications.|

## FAQs

What should I do if the **OH_HiDebug_StartAppTraceCapture** and **startAppTraceCapture** APIs return local physical paths when capturing HiTrace logs?

The returned path is the real physical path on the device. If you need to access the path in the application, convert the real physical path to the sandbox path by referring to [Mappings Between Application Sandbox Paths and Physical Paths](../file-management/app-sandbox-directory.md#mappings-between-application-sandbox-paths-and-physical-paths).

Example: **/data/app/el2/100/log/com.example.myapplication/trace/com.example.myapplication_20250604_173158.trace** -> **/data/storage/el2/base/trace/com.example.myapplication_20250604_173158.trace**

What should I do if the **OH_HiDebug_GetAppThreadCpuUsage** and **getAppThreadCpuUsage** APIs report that the CPU usage of a newly created thread is 0?

If the calculation is based on the CPU usage, you need to obtain the current CPU running statistics and the calculation baseline value updated by HiView every 10 seconds. The new thread does not have a calculation baseline value. As a result, the CPU usage cannot be calculated, and 0 is returned by default.
