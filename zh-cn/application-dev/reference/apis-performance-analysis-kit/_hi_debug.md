# HiDebug


## 概述

提供调试功能。

本模块函数可用于获取 cpu uage、memory、heap、capture trace等。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [hidebug.h](hidebug_8h.md) | 定义HiDebug模块的调试功能。 |
| [hidebug_type.h](hidebug__type_8h.md) | HiDebug模块代码结构体定义。 |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| struct  [HiDebug_ThreadCpuUsage](_hi_debug___thread_cpu_usage.md) | 应用程序所有线程的CPU使用率结构体定义。 |
| struct  [HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md) | 系统内存信息结构类型定义。 |
| struct  [HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md) | 应用程序进程本机内存信息结构类型定义。 |
| struct  [HiDebug_MemoryLimit](_hi_debug___memory_limit.md) | 应用程序进程内存限制结构类型定义。 |


### 宏定义

| 名称 | 描述 |
| -------- | -------- |
| [HIDEBUG_TRACE_TAG_FFRT](#hidebug_trace_tag_ffrt)   (1ULL &lt;&lt; 13) | FFRT任务标签。 |
| [HIDEBUG_TRACE_TAG_COMMON_LIBRARY](#hidebug_trace_tag_common_library)   (1ULL &lt;&lt; 16) | 公共库子系统标签。 |
| [HIDEBUG_TRACE_TAG_HDF](#hidebug_trace_tag_hdf)   (1ULL &lt;&lt; 18) | HDF子系统标签。 |
| [HIDEBUG_TRACE_TAG_NET](#hidebug_trace_tag_net)   (1ULL &lt;&lt; 23) | 网络标签。 |
| [HIDEBUG_TRACE_TAG_NWEB](#hidebug_trace_tag_nweb)   (1ULL &lt;&lt; 24) | NWeb标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO](#hidebug_trace_tag_distributed_audio)   (1ULL &lt;&lt; 27) | 分布式音频标签。 |
| [HIDEBUG_TRACE_TAG_FILE_MANAGEMENT](#hidebug_trace_tag_file_management)   (1ULL &lt;&lt; 29) | 文件管理标签。 |
| [HIDEBUG_TRACE_TAG_OHOS](#hidebug_trace_tag_ohos)   (1ULL &lt;&lt; 30) | OHOS通用标签。 |
| [HIDEBUG_TRACE_TAG_ABILITY_MANAGER](#hidebug_trace_tag_ability_manager)   (1ULL &lt;&lt; 31) | Ability Manager标签。 |
| [HIDEBUG_TRACE_TAG_CAMERA](#hidebug_trace_tag_camera)   (1ULL &lt;&lt; 32) | 相机模块标签。 |
| [HIDEBUG_TRACE_TAG_MEDIA](#hidebug_trace_tag_media)   (1ULL &lt;&lt; 33) | 媒体模块标签。 |
| [HIDEBUG_TRACE_TAG_IMAGE](#hidebug_trace_tag_image)   (1ULL &lt;&lt; 34) | 图像模块标签。 |
| [HIDEBUG_TRACE_TAG_AUDIO](#hidebug_trace_tag_audio)   (1ULL &lt;&lt; 35) | 音频模块标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA](#hidebug_trace_tag_distributed_data)   (1ULL &lt;&lt; 36) | 分布式数据管理器模块标签。 |
| [HIDEBUG_TRACE_TAG_GRAPHICS](#hidebug_trace_tag_graphics)   (1ULL &lt;&lt; 38) | 图形模块标签。 |
| [HIDEBUG_TRACE_TAG_ARKUI](#hidebug_trace_tag_arkui)   (1ULL &lt;&lt; 39) | ArkUI开发框架标签。 |
| [HIDEBUG_TRACE_TAG_NOTIFICATION](#hidebug_trace_tag_notification)   (1ULL &lt;&lt; 40) | 通知模块标签。 |
| [HIDEBUG_TRACE_TAG_MISC](#hidebug_trace_tag_misc)   (1ULL &lt;&lt; 41) | MISC模块标签。 |
| [HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT](#hidebug_trace_tag_multimodal_input)   (1ULL &lt;&lt; 42) | 多模态输入模块标签。 |
| [HIDEBUG_TRACE_TAG_RPC](#hidebug_trace_tag_rpc)   (1ULL &lt;&lt; 46) | RPC标签。 |
| [HIDEBUG_TRACE_TAG_ARK](#hidebug_trace_tag_ark)   (1ULL &lt;&lt; 47) | JSVM虚拟机标签。 |
| [HIDEBUG_TRACE_TAG_WINDOW_MANAGER](#hidebug_trace_tag_window_manager)   (1ULL &lt;&lt; 48) | 窗口管理器标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN](#hidebug_trace_tag_distributed_screen)   (1ULL &lt;&lt; 50) | 分布式屏幕标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA](#hidebug_trace_tag_distributed_camera)   (1ULL &lt;&lt; 51) | 分布式相机标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK](#hidebug_trace_tag_distributed_hardware_framework)   (1ULL &lt;&lt; 52) | 分布式硬件框架标签。 |
| [HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER](#hidebug_trace_tag_global_resource_manager)   (1ULL &lt;&lt; 53) | 全局资源管理器标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER](#hidebug_trace_tag_distributed_hardware_device_manager)   (1ULL &lt;&lt; 54) | 分布式硬件设备管理器标签。 |
| [HIDEBUG_TRACE_TAG_SAMGR](#hidebug_trace_tag_samgr)   (1ULL &lt;&lt; 55) | SA标签。 |
| [HIDEBUG_TRACE_TAG_POWER_MANAGER](#hidebug_trace_tag_power_manager)   (1ULL &lt;&lt; 56) | 电源管理器标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER](#hidebug_trace_tag_distributed_scheduler)   (1ULL &lt;&lt; 57) | 分布式调度程序标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT](#hidebug_trace_tag_distributed_input)   (1ULL &lt;&lt; 59) | 分布式输入标签。 |
| [HIDEBUG_TRACE_TAG_BLUETOOTH](#hidebug_trace_tag_bluetooth)   (1ULL &lt;&lt; 60) | 蓝牙标签。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [HiDebug_ErrorCode](#hidebug_errorcode-1) [HiDebug_ErrorCode](#hidebug_errorcode) | 错误码定义。 |
| typedef struct [HiDebug_ThreadCpuUsage](_hi_debug___thread_cpu_usage.md) [HiDebug_ThreadCpuUsage](#hidebug_threadcpuusage) | 应用程序所有线程的CPU使用率结构体定义。 |
| typedef [HiDebug_ThreadCpuUsage](_hi_debug___thread_cpu_usage.md) \* [HiDebug_ThreadCpuUsagePtr](#hidebug_threadcpuusageptr) | HiDebug_ThreadCpuUsage指针定义。 |
| typedef struct [HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md) [HiDebug_SystemMemInfo](#hidebug_systemmeminfo) | 系统内存信息结构类型定义。 |
| typedef struct [HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md) [HiDebug_NativeMemInfo](#hidebug_nativememinfo) | 应用程序进程本机内存信息结构类型定义。 |
| typedef struct [HiDebug_MemoryLimit](_hi_debug___memory_limit.md) [HiDebug_MemoryLimit](#hidebug_memorylimit) | 应用程序进程内存限制结构类型定义。 |
| typedef enum [HiDebug_TraceFlag](#hidebug_traceflag-1) [HiDebug_TraceFlag](#hidebug_traceflag) | 采集trace线程的类型。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [HiDebug_ErrorCode](#hidebug_errorcode-1) {<br/>HIDEBUG_SUCCESS = 0,<br/>HIDEBUG_INVALID_ARGUMENT = 401,<br/>HIDEBUG_TRACE_CAPTURED_ALREADY = 11400102,<br/>HIDEBUG_NO_PERMISSION = 11400103,<br/>HIDEBUG_TRACE_ABNORMAL = 11400104,<br/>HIDEBUG_NO_TRACE_RUNNING = 11400105<br/>} | 错误码定义。 |
| [HiDebug_TraceFlag](#hidebug_traceflag-1) {<br/>HIDEBUG_TRACE_FLAG_MAIN_THREAD = 1, HIDEBUG_TRACE_FLAG_ALL_THREADS = 2<br/>} | 采集trace线程的类型。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| double [OH_HiDebug_GetSystemCpuUsage](#oh_hidebug_getsystemcpuusage) () | 获取系统的CPU资源占用情况百分比。 |
| double [OH_HiDebug_GetAppCpuUsage](#oh_hidebug_getappcpuusage) () | 获取进程的CPU使用率百分比。 |
| [HiDebug_ThreadCpuUsagePtr](#hidebug_threadcpuusageptr) [OH_HiDebug_GetAppThreadCpuUsage](#oh_hidebug_getappthreadcpuusage) () | 获取应用所有线程CPU使用情况。 |
| void [OH_HiDebug_FreeThreadCpuUsage](#oh_hidebug_freethreadcpuusage) ([HiDebug_ThreadCpuUsagePtr](#hidebug_threadcpuusageptr) \*threadCpuUsage) | 释放线程数据结构。 |
| void [OH_HiDebug_GetSystemMemInfo](#oh_hidebug_getsystemmeminfo) ([HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md) \*systemMemInfo) | 获取系统内存信息。 |
| void [OH_HiDebug_GetAppNativeMemInfo](#oh_hidebug_getappnativememinfo) ([HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md) \*nativeMemInfo) | 获取应用程序进程的内存信息。 |
| void [OH_HiDebug_GetAppMemoryLimit](#oh_hidebug_getappmemorylimit) ([HiDebug_MemoryLimit](_hi_debug___memory_limit.md) \*memoryLimit) | 获取应用程序进程的内存限制。 |
| [HiDebug_ErrorCode](#hidebug_errorcode) [OH_HiDebug_StartAppTraceCapture](#oh_hidebug_startapptracecapture) ([HiDebug_TraceFlag](#hidebug_traceflag) flag, uint64_t tags, uint32_t limitSize, char \*fileName, uint32_t length) | 启动应用trace采集。 |
| [HiDebug_ErrorCode](#hidebug_errorcode) [OH_HiDebug_StopAppTraceCapture](#oh_hidebug_stopapptracecapture) () | 停止采集应用程序trace。 |


## 宏定义说明


### HIDEBUG_TRACE_TAG_ABILITY_MANAGER

```
#define HIDEBUG_TRACE_TAG_ABILITY_MANAGER   (1ULL << 31)
```

**描述**

Ability Manager标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_ARK

```
#define HIDEBUG_TRACE_TAG_ARK   (1ULL << 47)
```

**描述**

JSVM虚拟机标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_ARKUI

```
#define HIDEBUG_TRACE_TAG_ARKUI   (1ULL << 39)
```

**描述**

ArkUI开发框架标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_AUDIO

```
#define HIDEBUG_TRACE_TAG_AUDIO   (1ULL << 35)
```

**描述**

音频模块标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_BLUETOOTH

```
#define HIDEBUG_TRACE_TAG_BLUETOOTH   (1ULL << 60)
```

**描述**

蓝牙标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_CAMERA

```
#define HIDEBUG_TRACE_TAG_CAMERA   (1ULL << 32)
```

**描述**

相机模块标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_COMMON_LIBRARY

```
#define HIDEBUG_TRACE_TAG_COMMON_LIBRARY   (1ULL << 16)
```

**描述**

公共库子系统标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO   (1ULL << 27)
```

**描述**

分布式音频标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA   (1ULL << 51)
```

**描述**

分布式相机标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA   (1ULL << 36)
```

**描述**

分布式数据管理器模块标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER   (1ULL << 54)
```

**描述**

分布式硬件设备管理器标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK   (1ULL << 52)
```

**描述**

分布式硬件框架标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT   (1ULL << 59)
```

**描述**

分布式输入标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER   (1ULL << 57)
```

**描述**

分布式调度程序标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN   (1ULL << 50)
```

**描述**

分布式屏幕标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_FFRT

```
#define HIDEBUG_TRACE_TAG_FFRT   (1ULL << 13)
```

**描述**

FFRT任务标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_FILE_MANAGEMENT

```
#define HIDEBUG_TRACE_TAG_FILE_MANAGEMENT   (1ULL << 29)
```

**描述**

文件管理标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER

```
#define HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER   (1ULL << 53)
```

**描述**

全局资源管理器标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_GRAPHICS

```
#define HIDEBUG_TRACE_TAG_GRAPHICS   (1ULL << 38)
```

**描述**

图形模块标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_HDF

```
#define HIDEBUG_TRACE_TAG_HDF   (1ULL << 18)
```

**描述**

HDF子系统标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_IMAGE

```
#define HIDEBUG_TRACE_TAG_IMAGE   (1ULL << 34)
```

**描述**

图像模块标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_MEDIA

```
#define HIDEBUG_TRACE_TAG_MEDIA   (1ULL << 33)
```

**描述**

媒体模块标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_MISC

```
#define HIDEBUG_TRACE_TAG_MISC   (1ULL << 41)
```

**描述**

MISC模块标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT

```
#define HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT   (1ULL << 42)
```

**描述**

多模态输入模块标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_NET

```
#define HIDEBUG_TRACE_TAG_NET   (1ULL << 23)
```

**描述**

网络标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_NOTIFICATION

```
#define HIDEBUG_TRACE_TAG_NOTIFICATION   (1ULL << 40)
```

**描述**

通知模块标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_NWEB

```
#define HIDEBUG_TRACE_TAG_NWEB   (1ULL << 24)
```

**描述**

NWeb标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_OHOS

```
#define HIDEBUG_TRACE_TAG_OHOS   (1ULL << 30)
```

**描述**

OHOS通用标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_POWER_MANAGER

```
#define HIDEBUG_TRACE_TAG_POWER_MANAGER   (1ULL << 56)
```

**描述**

电源管理器标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_RPC

```
#define HIDEBUG_TRACE_TAG_RPC   (1ULL << 46)
```

**描述**

RPC标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_SAMGR

```
#define HIDEBUG_TRACE_TAG_SAMGR   (1ULL << 55)
```

**描述**

SA标签。

**起始版本：** 12


### HIDEBUG_TRACE_TAG_WINDOW_MANAGER

```
#define HIDEBUG_TRACE_TAG_WINDOW_MANAGER   (1ULL << 48)
```

**描述**

窗口管理器标签。

**起始版本：** 12


## 类型定义说明


### HiDebug_ErrorCode

```
typedef enum HiDebug_ErrorCode HiDebug_ErrorCode
```

**描述**

错误码定义。

**起始版本：** 12


### HiDebug_MemoryLimit

```
typedef struct HiDebug_MemoryLimit HiDebug_MemoryLimit
```

**描述**

应用程序进程内存限制结构类型定义。

**起始版本：** 12


### HiDebug_NativeMemInfo

```
typedef struct HiDebug_NativeMemInfo HiDebug_NativeMemInfo
```

**描述**

应用程序进程本机内存信息结构类型定义。

**起始版本：** 12


### HiDebug_SystemMemInfo

```
typedef struct HiDebug_SystemMemInfo HiDebug_SystemMemInfo
```

**描述**

系统内存信息结构类型定义。

**起始版本：** 12


### HiDebug_ThreadCpuUsage

```
typedef struct HiDebug_ThreadCpuUsage HiDebug_ThreadCpuUsage
```

**描述**

应用程序所有线程的CPU使用率结构体定义。

**起始版本：** 12


### HiDebug_ThreadCpuUsagePtr

```
typedef HiDebug_ThreadCpuUsage* HiDebug_ThreadCpuUsagePtr
```

**描述**

HiDebug_ThreadCpuUsage指针定义。

**起始版本：** 12


### HiDebug_TraceFlag

```
typedef enum HiDebug_TraceFlag HiDebug_TraceFlag
```

**描述**

采集trace线程的类型。

**起始版本：** 12


## 枚举类型说明


### HiDebug_ErrorCode

```
enum HiDebug_ErrorCode
```

**描述**

错误码定义。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| HIDEBUG_SUCCESS | 成功 |
| HIDEBUG_INVALID_ARGUMENT | 无效参数，可能的原因： 1.参数传值问题 2.参数类型问题 |
| HIDEBUG_TRACE_CAPTURED_ALREADY | 重复采集 |
| HIDEBUG_NO_PERMISSION | 没有写文件的权限 |
| HIDEBUG_TRACE_ABNORMAL | trace状态异常 |


### HiDebug_TraceFlag

```
enum HiDebug_TraceFlag
```

**描述**

采集trace线程的类型。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| HIDEBUG_TRACE_FLAG_MAIN_THREAD | 只采集当前应用主线程 |
| HIDEBUG_TRACE_FLAG_ALL_THREADS | 采集当前应用下所有线程 |


## 函数说明


### OH_HiDebug_FreeThreadCpuUsage()

```
void OH_HiDebug_FreeThreadCpuUsage (HiDebug_ThreadCpuUsagePtr * threadCpuUsage)
```

**描述**

释放线程数据结构。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| threadCpuUsage | 应用的所有线程可用CPU使用缓冲区指针，见[HiDebug_ThreadCpuUsagePtr](#hidebug_threadcpuusageptr)。 传入的参数是要由OH_HiDebug_GetAppThreadCpuUsage()得到的。 |


### OH_HiDebug_GetAppCpuUsage()

```
double OH_HiDebug_GetAppCpuUsage ()
```

**描述**

获取进程的CPU使用率百分比。

**起始版本：** 12

**返回：**

返回进程的CPU使用率百分比。如果返回结果为0，可能的原因是获取失败。


### OH_HiDebug_GetAppMemoryLimit()

```
void OH_HiDebug_GetAppMemoryLimit (HiDebug_MemoryLimit * memoryLimit)
```

**描述**

获取应用程序进程的内存限制。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| memoryLimit | 表示指向[HiDebug_MemoryLimit](_hi_debug___memory_limit.md)。经过该函数调用，如果结构体里的数据为空，说明调用失败。 |


### OH_HiDebug_GetAppNativeMemInfo()

```
void OH_HiDebug_GetAppNativeMemInfo (HiDebug_NativeMemInfo * nativeMemInfo)
```

**描述**

获取应用程序进程的内存信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| nativeMemInfo | 表示指向[HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md)。经过该函数调用，如果结构体里的数据为空，说明调用失败。 |


### OH_HiDebug_GetAppThreadCpuUsage()

```
HiDebug_ThreadCpuUsagePtr OH_HiDebug_GetAppThreadCpuUsage ()
```

**描述**

获取应用所有线程CPU使用情况。

**起始版本：** 12

**返回：**

返回所有线程CPU使用情况，见[HiDebug_ThreadCpuUsagePtr](#hidebug_threadcpuusageptr)。如果返回的结果是null，说明调用失败。


### OH_HiDebug_GetSystemCpuUsage()

```
double OH_HiDebug_GetSystemCpuUsage ()
```

**描述**

获取系统的CPU资源占用情况百分比。

**起始版本：** 12

**返回：**

返回系统CPU资源占用情况百分比。如果返回结果为0，可能的原因是获取失败。

### OH_HiDebug_GetSystemMemInfo()

```
void OH_HiDebug_GetSystemMemInfo (HiDebug_SystemMemInfo * systemMemInfo)
```

**描述**

获取系统内存信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| systemMemInfo | 表示指向[HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md)。经过该函数调用，如果结构体里的数据为空，说明调用失败。|


### OH_HiDebug_StartAppTraceCapture()

```
HiDebug_ErrorCode OH_HiDebug_StartAppTraceCapture (HiDebug_TraceFlag flag, uint64_t tags, uint32_t limitSize, char * fileName, uint32_t length )
```

**描述**

启动应用trace采集。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| flag | 采集线程trace方式。 |
| tags | 采集trace场景标签。 |
| limitSize | trace文件的最大大小（以字节为单位），最大为 500MB。 |
| fileName | 输出trace文件名缓冲区。 |
| length | 输出trace文件名缓冲区长度。 |

**返回：**

0 - 成功。 401 - fileName参数为空指针或者传入的length参数过小或者limitSize参数小于等于0。 11400102 - 已经开启了一个trace。 11400103 - 没有权限去开启trace。 11400104 - 系统内部错误。


### OH_HiDebug_StopAppTraceCapture()

```
HiDebug_ErrorCode OH_HiDebug_StopAppTraceCapture ()
```

**描述**

停止采集应用程序trace。

**起始版本：** 12

**返回：**

0 - 成功 11400104 - 系统内部的原因 11400105 - 没有trace正在采集。

### OH_HiDebug_GetGraphicsMemory();
```
HiDebug_ErrorCode OH_HiDebug_GetGraphicsMemory(uint32_t *value);
```

**描述**

获取应用gpu显存大小。

**起始版本：** 14

**参数:**

| 名称 | 描述                              |
| -------- |---------------------------------|
| value | 指向用来保存接口获取到的应用显存大小（单位KB）的变量的指针。 |

**返回：**

0 - 成功 401 - 传入参数无效 11400104 - 系统内部异常。