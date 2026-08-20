# hidebug_type.h

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @leiguangyu-->
<!--Designer: @mgce1-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## 概述

HiDebug模块代码结构体定义。

**引用文件：** <hidebug/hidebug_type.h>

**库：** libohhidebug.so

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**起始版本：** 12

**相关模块：** [HiDebug](capi-hidebug.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [HiDebug_ThreadCpuUsage](capi-hidebug-hidebug-threadcpuusage.md) | HiDebug_ThreadCpuUsage | 当前进程所有线程的CPU使用率结构体定义。使用场景：应用性能监控：获取线程CPU使用率，监控应用的运行状态和性能瓶颈。线程性能优化：分析各线程的CPU占用情况，优化线程调度和资源分配。系统调试：在调试阶段追踪线程的CPU使用情况，定位性能问题。 |
| [HiDebug_SystemMemInfo](capi-hidebug-hidebug-systemmeminfo.md) | HiDebug_SystemMemInfo | 系统内存信息结构类型定义。用于获取系统内存的总量、空闲量、可用量等关键信息，适用于系统性能分析、内存监控、故障诊断等场景，帮助开发者了解系统内存使用状况，优化内存管理策略。 |
| [HiDebug_NativeMemInfo](capi-hidebug-hidebug-nativememinfo.md) | HiDebug_NativeMemInfo | 应用程序进程本机内存信息结构类型定义。 |
| [HiDebug_MemoryLimit](capi-hidebug-hidebug-memorylimit.md) | HiDebug_MemoryLimit | 应用程序进程内存限制结构类型定义。 |
| [OH_HiDebug_RequestTraceConfig](capi-hidebug-oh-hidebug-requesttraceconfig.md) | OH_HiDebug_RequestTraceConfig | 请求trace采集的配置结构类型定义。用于在应用性能分析和调试场景中配置trace采集参数，如定位应用启动慢、UI卡顿、CPU占用高等性能问题。 |
| [HiDebug_JsStackFrame](capi-hidebug-hidebug-jsstackframe.md) | HiDebug_JsStackFrame | js栈帧内容的定义。用于在性能分析和调试场景中，记录js调用栈的帧信息，包括代码位置、函数名称、映射区域等关键信息。 |
| [HiDebug_NativeStackFrame](capi-hidebug-hidebug-nativestackframe.md) | HiDebug_NativeStackFrame | native栈帧内容的定义。 |
| [HiDebug_StackFrame](capi-hidebug-hidebug-stackframe.md) | HiDebug_StackFrame | 栈帧内容的定义。该结构体用于表示调试时的栈帧信息，支持获取当前栈的类型以及对应的js栈帧或Native栈帧内容，帮助开发者进行问题定位和调试分析。 |
| [HiDebug_MallocDispatch](capi-hidebug-hidebug-mallocdispatch.md) | HiDebug_MallocDispatch | 应用程序进程可替换/恢复的HiDebug_MallocDispatch表结构类型定义。通过该结构体，开发者可以自定义内存管理函数指针，实现对进程内存分配和释放的监控与定制。主要特点包括：支持动态替换和恢复内存管理函数、提供全面的内存操作接口（malloc、calloc、realloc、free、mmap、munmap）、不影响系统默认内存管理行为。使用场景包括：内存泄漏检测、内存使用性能分析、自定义内存分配策略、内存安全监控等。能够帮助开发者及时发现和解决内存问题，提升应用稳定性和性能。 |
| [HiDebug_GraphicsMemorySummary](capi-hidebug-hidebug-graphicsmemorysummary.md) | HiDebug_GraphicsMemorySummary | 应用图形显存占用详情的结构定义。 |
| [HiDebug_ProcessSamplerConfig](capi-hidebug-hidebug-processsamplerconfig.md) | HiDebug_ProcessSamplerConfig | 采样配置的结构定义。 |
| [HiDebug_Backtrace_Object__*](capi-hidebug-hidebug-backtrace-object--8h.md) | HiDebug_Backtrace_Object | 用于栈回溯及栈解析的对象。该对象封装了栈回溯所需的上下文信息，包括调用栈地址、线程状态等数据，通过相关接口可获取详细的栈帧信息和符号解析结果。该对象通过HiDebug相关接口创建，使用后需要调用对应的销毁接口释放资源。 |
| [HiDebug_ThreadCpuUsage*](capi-hidebug-hidebug-threadcpuusage.md) | HiDebug_ThreadCpuUsagePtr | HiDebug_ThreadCpuUsage指针定义。 |
| [OH_HiDebug_ResProfilerConfig](capi-hidebug-oh-hidebug-resprofilerconfig.md) | OH_HiDebug_ResProfilerConfig | 定义资源采集配置结构体类型。 |
| [OH_HiDebug_ProfilingResult](capi-hidebug-oh-hidebug-profilingresult.md) | OH_HiDebug_ProfilingResult | 封装单次资源采集的结果。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [HiDebug_ErrorCode](#hidebug_errorcode) | HiDebug_ErrorCode | 错误码定义。用于HiDebug模块各功能接口的返回状态标识，包括成功、参数错误、权限问题、系统内部错误、设备不支持等多种情况。开发者可根据错误码定位问题原因并采取相应的错误处理措施。 |
| [HiDebug_TraceFlag](#hidebug_traceflag) | HiDebug_TraceFlag | 采集trace线程的类型。 |
| [HiDebug_StackFrameType](#hidebug_stackframetype) | HiDebug_StackFrameType | 栈帧类型的枚举值定义。 |
| [HiDebug_CrashObjType](#hidebug_crashobjtype) | HiDebug_CrashObjType | 维测信息数据类型的枚举。 |
| [OH_HiDebug_ResourceType](#oh_hidebug_resourcetype) | OH_HiDebug_ResourceType | 定义资源采集类型的枚举。 |
| [OH_HiDebug_MemListenerType](#oh_hidebug_memlistenertype) | OH_HiDebug_MemListenerType | 内存监听回调的类型枚举。开发者根据回调类型处理相关逻辑。 |

### 宏定义

| 名称 | 描述 |
| -- | -- |
| [HIDEBUG_TRACE_TAG_FFRT](#hidebug_trace_tag_ffrt) (1ULL << 13)                                                               | FFRT任务标签。<br>**起始版本：** 12      |
| [HIDEBUG_TRACE_TAG_COMMON_LIBRARY](#hidebug_trace_tag_common_library) (1ULL << 16)                                           | 公共库子系统标签。<br>**起始版本：** 12          |
| [HIDEBUG_TRACE_TAG_HDF](#hidebug_trace_tag_hdf) (1ULL << 18)                                                                 | HDF子系统标签。<br>**起始版本：** 12          |
| [HIDEBUG_TRACE_TAG_NET](#hidebug_trace_tag_net) (1ULL << 23)                                                                 | 网络标签。<br>**起始版本：** 12              |
| [HIDEBUG_TRACE_TAG_NWEB](#hidebug_trace_tag_nweb) (1ULL << 24)                                                               | NWeb标签。<br>**起始版本：** 12            |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO](#hidebug_trace_tag_distributed_audio) (1ULL << 27)                                     | 分布式音频标签。<br>**起始版本：** 12           |
| [HIDEBUG_TRACE_TAG_FILE_MANAGEMENT](#hidebug_trace_tag_file_management) (1ULL << 29)                                         | 文件管理标签。<br>**起始版本：** 12            |
| [HIDEBUG_TRACE_TAG_OHOS](#hidebug_trace_tag_ohos) (1ULL << 30)                                                               | OHOS通用标签。<br>**起始版本：** 12          |
| [HIDEBUG_TRACE_TAG_ABILITY_MANAGER](#hidebug_trace_tag_ability_manager) (1ULL << 31)                                         | Ability Manager标签。<br>**起始版本：** 12 |
| [HIDEBUG_TRACE_TAG_CAMERA](#hidebug_trace_tag_camera) (1ULL << 32)                                                           | 相机模块标签。<br>**起始版本：** 12            |
| [HIDEBUG_TRACE_TAG_MEDIA](#hidebug_trace_tag_media) (1ULL << 33)                                                             | 媒体模块标签。<br>**起始版本：** 12            |
| [HIDEBUG_TRACE_TAG_IMAGE](#hidebug_trace_tag_image) (1ULL << 34)                                                             | 图像模块标签。<br>**起始版本：** 12            |
| [HIDEBUG_TRACE_TAG_AUDIO](#hidebug_trace_tag_audio) (1ULL << 35)                                                             | 音频模块标签。<br>**起始版本：** 12            |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA](#hidebug_trace_tag_distributed_data) (1ULL << 36)                                       | 分布式数据管理器模块标签。<br>**起始版本：** 12      |
| [HIDEBUG_TRACE_TAG_GRAPHICS](#hidebug_trace_tag_graphics) (1ULL << 38)                                                       | 图形模块标签。<br>**起始版本：** 12            |
| [HIDEBUG_TRACE_TAG_ARKUI](#hidebug_trace_tag_arkui) (1ULL << 39)                                                             | ArkUI开发框架标签。<br>**起始版本：** 12       |
| [HIDEBUG_TRACE_TAG_NOTIFICATION](#hidebug_trace_tag_notification) (1ULL << 40)                                               | 通知模块标签。<br>**起始版本：** 12            |
| [HIDEBUG_TRACE_TAG_MISC](#hidebug_trace_tag_misc) (1ULL << 41)                                                               | MISC模块标签。<br>**起始版本：** 12          |
| [HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT](#hidebug_trace_tag_multimodal_input) (1ULL << 42)                                       | 多模态输入模块标签。<br>**起始版本：** 12         |
| [HIDEBUG_TRACE_TAG_RPC](#hidebug_trace_tag_rpc) (1ULL << 46)                                                                 | RPC标签。<br>**起始版本：** 12             |
| [HIDEBUG_TRACE_TAG_ARK](#hidebug_trace_tag_ark) (1ULL << 47)                                                                 | JSVM虚拟机标签。<br>**起始版本：** 12         |
| [HIDEBUG_TRACE_TAG_WINDOW_MANAGER](#hidebug_trace_tag_window_manager) (1ULL << 48)                                           | 窗口管理器标签。<br>**起始版本：** 12           |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN](#hidebug_trace_tag_distributed_screen) (1ULL << 50)                                   | 分布式屏幕标签。<br>**起始版本：** 12           |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA](#hidebug_trace_tag_distributed_camera) (1ULL << 51)                                   | 分布式相机标签。<br>**起始版本：** 12           |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK](#hidebug_trace_tag_distributed_hardware_framework) (1ULL << 52)           | 分布式硬件框架标签。<br>**起始版本：** 12         |
| [HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER](#hidebug_trace_tag_global_resource_manager) (1ULL << 53)                         | 全局资源管理器标签。<br>**起始版本：** 12         |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER](#hidebug_trace_tag_distributed_hardware_device_manager) (1ULL << 54) | 分布式硬件设备管理器标签。<br>**起始版本：** 12      |
| [HIDEBUG_TRACE_TAG_SAMGR](#hidebug_trace_tag_samgr) (1ULL << 55)                                                             | SA标签。<br>**起始版本：** 12              |
| [HIDEBUG_TRACE_TAG_POWER_MANAGER](#hidebug_trace_tag_power_manager) (1ULL << 56)                                             | 电源管理器标签。<br>**起始版本：** 12           |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER](#hidebug_trace_tag_distributed_scheduler) (1ULL << 57)                             | 分布式调度程序标签。<br>**起始版本：** 12         |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT](#hidebug_trace_tag_distributed_input) (1ULL << 59)                                     | 分布式输入标签。<br>**起始版本：** 12           |
| [HIDEBUG_TRACE_TAG_BLUETOOTH](#hidebug_trace_tag_bluetooth) (1ULL << 60)                                                     | 蓝牙标签。<br>**起始版本：** 12              |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_HiDebug_RequestTraceCallback)(HiDebug_ErrorCode errorCode, const char* filePath)](#oh_hidebug_requesttracecallback) | OH_HiDebug_RequestTraceCallback | 请求trace采集的回调类型定义。 |
| [typedef void (\*OH_HiDebug_ProfilingCallback)(OH_HiDebug_ProfilingResult* result)](#oh_hidebug_profilingcallback) | OH_HiDebug_ProfilingCallback | 定义资源采集回调函数。 |

## 枚举类型说明

### HiDebug_ErrorCode

```c
enum HiDebug_ErrorCode
```

**描述**

错误码定义。用于HiDebug模块各功能接口的返回状态标识，包括成功、参数错误、权限问题、系统内部错误、设备不支持等多种情况。开发者可根据错误码定位问题原因并采取相应的错误处理措施。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| HIDEBUG_SUCCESS = 0 | 成功。 |
| HIDEBUG_INVALID_ARGUMENT = 401 | 无效参数，可能的原因： 1.参数传值问题；2.参数类型问题。 |
| HIDEBUG_TRACE_CAPTURED_ALREADY = 11400102 | 重复采集。 |
| HIDEBUG_NO_PERMISSION = 11400103 | 没有写文件的权限。 |
| HIDEBUG_TRACE_ABNORMAL = 11400104 | 系统内部错误。 |
| HIDEBUG_NO_TRACE_RUNNING = 11400105 | 当前没有trace正在运行。 |
| OH_HIDEBUG_TRACE_STORAGE_LIMIT = 11400120 | trace文件存储达到限制。<br/>**起始版本：** 24 |
| HIDEBUG_INVALID_SYMBOLIC_PC_ADDRESS = 11400200 | 传入符号解析函数的pc地址是无效的。<br/>**起始版本：** 20 |
| HIDEBUG_NOT_SUPPORTED = 11400300 | 当前设备不支持。<br>**起始版本：** 22 |
| HIDEBUG_UNDER_SAMPLING = 11400301 | 当前进程正在采样。<br>**起始版本：** 22 |
| HIDEBUG_RESOURCE_UNAVAILABLE = 11400302 | 采样资源不可用。<br>**起始版本：** 22 |
| HIDEBUG_RES_PROF_SUCCESS = 11400400 | 资源采集启动/停止成功。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_INVALID_ARG = 11400410 | 资源采集参数无效。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_INVALID_MAX_DURATION = 11400411 | 资源采集最大持续时间参数无效。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_INVALID_FILTER_SIZE = 11400412 | 资源采集过滤大小参数无效。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_INVALID_MAX_STACK_DEPTH = 11400413 | 资源采集最大回栈深度参数无效。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_INVALID_STATISTICS_INTERVAL = 11400414 | 资源采集统计间隔参数无效。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_INVALID_SAMPLE_INTERVAL = 11400415 | 资源采集采样大小参数无效。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_INVALID_RESOURCE_TYPE = 11400416 | 资源采集资源类型参数无效。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_PERMISSION_DENIED = 11400420 | 资源采集权限不足，采集资源的目标进程仅支持调用接口进程本身。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_ALREADY_STARTED = 11400421 | 资源采集重复启动。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_NOT_STARTED = 11400422 | 资源采集未启动，停止失败。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_PROCESS_OVERLIMIT = 11400423 | 资源采集进程数超出 4 个限制。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_CONFLICT = 11400424 | 资源采集与命令行工具或系统采集任务冲突。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_AUTO_STOPPED_BY_DURATION = 11400425 | 资源采集到达指定最大持续时间限制自动停止。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_DAILY_QUOTA_EXCEEDED = 11400426 | 资源采集每日配额超出 10 次限制。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_CPU_OVERLOADED = 11400427 | 系统 CPU 处于高负载状态，CPU 占用率超过 70%。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_MEM_PRESSURE_CRITICAL = 11400428 | 内存可用空间紧张，可用空间少于 15%。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_STORAGE_PRESSURE_CRITICAL = 11400429 | 存储可用空间紧张，可用空间少于 15%。<br>**起始版本：** 24 |
| HIDEBUG_RES_PROF_FAILURE = 11400430 | 资源采集启动/停止失败。<br>**起始版本：** 24 |

### HiDebug_TraceFlag

```c
enum HiDebug_TraceFlag
```

**描述**

采集trace线程的类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| HIDEBUG_TRACE_FLAG_MAIN_THREAD = 1 | 只采集当前应用主线程。 |
| HIDEBUG_TRACE_FLAG_ALL_THREADS = 2 | 采集当前应用下所有线程。 |

### HiDebug_StackFrameType

```c
enum HiDebug_StackFrameType
```

**描述**

栈帧类型的枚举值定义。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| HIDEBUG_STACK_FRAME_TYPE_JS = 1 | js类型栈帧。 |
| HIDEBUG_STACK_FRAME_TYPE_NATIVE = 2 | native类型栈帧。 |

### HiDebug_CrashObjType

```c
enum HiDebug_CrashObjType
```

**描述**

维测信息数据类型的枚举。

**起始版本：** 23

| 枚举项 | 描述 |
| -- | -- |
| HIDEBUG_CRASHOBJ_STRING = 0 | 字符串 |
| HIDEBUG_CRASHOBJ_MEMORY_64B = 1 | 64字节内存块 |
| HIDEBUG_CRASHOBJ_MEMORY_256B = 2 | 256字节内存块 |
| HIDEBUG_CRASHOBJ_MEMORY_1024B = 3 | 1024字节内存块 |
| HIDEBUG_CRASHOBJ_MEMORY_2048B = 4 | 2048字节内存块 |
| HIDEBUG_CRASHOBJ_MEMORY_4096B = 5 | 4096字节内存块 |

### OH_HiDebug_ResourceType

```c
enum OH_HiDebug_ResourceType
```

**描述**

定义资源采集类型的枚举。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_RES_TYPE_FD | 文件描述符<br>**起始版本：** 24 |
| OH_RES_TYPE_THREAD | 线程<br>**起始版本：** 24 |
| OH_RES_TYPE_NATIVE | Native 内存<br>**起始版本：** 24 |
| OH_RES_TYPE_GPU | GPU 内存<br>**起始版本：** 24 |
| OH_RES_TYPE_GLOBAL_HANDLE | 全局句柄<br>**起始版本：** 24 |

### OH_HiDebug_MemListenerType

```c
enum OH_HiDebug_MemListenerType
```

**描述**

内存监听回调的类型枚举。开发者根据回调类型处理相关逻辑。

**起始版本：** 26.0.0

| 枚举项 | 描述 |
| -- | -- |
| OH_HIDEBUG_DO_NOTHING = 0 | 无特定操作，仅通知回调。<br>**起始版本：** 26.0.0 |
| OH_HIDEBUG_RUNNING_GC = 1 | 垃圾回收（GC）操作。<br>**起始版本：** 26.0.0 |
| OH_HIDEBUG_DUMP_SNAPSHOT = 2 | 导出内存快照。<br>**起始版本：** 26.0.0 |

## 宏定义说明

### HIDEBUG_TRACE_TAG_FFRT

```c
#define HIDEBUG_TRACE_TAG_FFRT (1ULL << 13)
```

**描述**

FFRT任务标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_COMMON_LIBRARY

```c
#define HIDEBUG_TRACE_TAG_COMMON_LIBRARY (1ULL << 16)
```

**描述**

公共库子系统标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_HDF

```c
#define HIDEBUG_TRACE_TAG_HDF (1ULL << 18)
```

**描述**

HDF子系统标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_NET

```c
#define HIDEBUG_TRACE_TAG_NET (1ULL << 23)
```

**描述**

网络标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_NWEB

```c
#define HIDEBUG_TRACE_TAG_NWEB (1ULL << 24)
```

**描述**

NWeb标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO

```c
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO (1ULL << 27)
```

**描述**

分布式音频标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_FILE_MANAGEMENT

```c
#define HIDEBUG_TRACE_TAG_FILE_MANAGEMENT (1ULL << 29)
```

**描述**

文件管理标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_OHOS

```c
#define HIDEBUG_TRACE_TAG_OHOS (1ULL << 30)
```

**描述**

OHOS通用标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_ABILITY_MANAGER

```c
#define HIDEBUG_TRACE_TAG_ABILITY_MANAGER (1ULL << 31)
```

**描述**

Ability Manager标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_CAMERA

```c
#define HIDEBUG_TRACE_TAG_CAMERA (1ULL << 32)
```

**描述**

相机模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_MEDIA

```c
#define HIDEBUG_TRACE_TAG_MEDIA (1ULL << 33)
```

**描述**

媒体模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_IMAGE

```c
#define HIDEBUG_TRACE_TAG_IMAGE (1ULL << 34)
```

**描述**

图像模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_AUDIO

```c
#define HIDEBUG_TRACE_TAG_AUDIO (1ULL << 35)
```

**描述**

音频模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA

```c
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA (1ULL << 36)
```

**描述**

分布式数据管理器模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_GRAPHICS

```c
#define HIDEBUG_TRACE_TAG_GRAPHICS (1ULL << 38)
```

**描述**

图形模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_ARKUI

```c
#define HIDEBUG_TRACE_TAG_ARKUI (1ULL << 39)
```

**描述**

ArkUI开发框架标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_NOTIFICATION

```c
#define HIDEBUG_TRACE_TAG_NOTIFICATION (1ULL << 40)
```

**描述**

通知模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_MISC

```c
#define HIDEBUG_TRACE_TAG_MISC (1ULL << 41)
```

**描述**

MISC模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT

```c
#define HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT (1ULL << 42)
```

**描述**

多模态输入模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_RPC

```c
#define HIDEBUG_TRACE_TAG_RPC (1ULL << 46)
```

**描述**

RPC标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_ARK

```c
#define HIDEBUG_TRACE_TAG_ARK (1ULL << 47)
```

**描述**

JSVM虚拟机标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_WINDOW_MANAGER

```c
#define HIDEBUG_TRACE_TAG_WINDOW_MANAGER (1ULL << 48)
```

**描述**

窗口管理器标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN

```c
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN (1ULL << 50)
```

**描述**

分布式屏幕标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA

```c
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA (1ULL << 51)
```

**描述**

分布式相机标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK

```c
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK (1ULL << 52)
```

**描述**

分布式硬件框架标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER

```c
#define HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER (1ULL << 53)
```

**描述**

全局资源管理器标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER

```c
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER (1ULL << 54)
```

**描述**

分布式硬件设备管理器标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_SAMGR

```c
#define HIDEBUG_TRACE_TAG_SAMGR (1ULL << 55)
```

**描述**

SA标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_POWER_MANAGER

```c
#define HIDEBUG_TRACE_TAG_POWER_MANAGER (1ULL << 56)
```

**描述**

电源管理器标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER

```c
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER (1ULL << 57)
```

**描述**

分布式调度程序标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT

```c
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT (1ULL << 59)
```

**描述**

分布式输入标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_BLUETOOTH

```c
#define HIDEBUG_TRACE_TAG_BLUETOOTH (1ULL << 60)
```

**描述**

蓝牙标签。

**起始版本：** 12

## 函数说明

### OH_HiDebug_RequestTraceCallback()

```c
typedef void (*OH_HiDebug_RequestTraceCallback)(HiDebug_ErrorCode errorCode, const char* filePath)
```

**描述**

请求trace采集的回调类型定义。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| HiDebug_ErrorCode errorCode | 返回结果码，参考[HiDebug_ErrorCode](#hidebug_errorcode)。 |
| const char\* filePath | 返回采集的trace文件，失败时可能是空指针。 |

### OH_HiDebug_ProfilingCallback()

```c
typedef void (*OH_HiDebug_ProfilingCallback)(OH_HiDebug_ProfilingResult* result)
```

**描述**

定义资源采集回调函数。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_HiDebug_ProfilingResult\* result | 资源采集回调函数的参数。 |
