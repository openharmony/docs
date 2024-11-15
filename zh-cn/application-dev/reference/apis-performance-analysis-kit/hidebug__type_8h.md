# hidebug_type.h


## 概述

HiDebug模块代码结构体定义。

**库：** libohhidebug.so

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**引用文件：** &lt;hidebug/hidebug_type.h&gt;

**起始版本：** 12

**相关模块：**[HiDebug](_hi_debug.md)


## 汇总


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
| [HIDEBUG_TRACE_TAG_FFRT](_hi_debug.md#hidebug_trace_tag_ffrt)   (1ULL &lt;&lt; 13) | FFRT任务标签。 |
| [HIDEBUG_TRACE_TAG_COMMON_LIBRARY](_hi_debug.md#hidebug_trace_tag_common_library)   (1ULL &lt;&lt; 16) | 公共库子系统标签。 |
| [HIDEBUG_TRACE_TAG_HDF](_hi_debug.md#hidebug_trace_tag_hdf)   (1ULL &lt;&lt; 18) | HDF子系统标签。 |
| [HIDEBUG_TRACE_TAG_NET](_hi_debug.md#hidebug_trace_tag_net)   (1ULL &lt;&lt; 23) | 网络标签。 |
| [HIDEBUG_TRACE_TAG_NWEB](_hi_debug.md#hidebug_trace_tag_nweb)   (1ULL &lt;&lt; 24) | NWeb标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO](_hi_debug.md#hidebug_trace_tag_distributed_audio)   (1ULL &lt;&lt; 27) | 分布式音频标签。 |
| [HIDEBUG_TRACE_TAG_FILE_MANAGEMENT](_hi_debug.md#hidebug_trace_tag_file_management)   (1ULL &lt;&lt; 29) | 文件管理标签。 |
| [HIDEBUG_TRACE_TAG_OHOS](_hi_debug.md#hidebug_trace_tag_ohos)   (1ULL &lt;&lt; 30) | OHOS通用标签。 |
| [HIDEBUG_TRACE_TAG_ABILITY_MANAGER](_hi_debug.md#hidebug_trace_tag_ability_manager)   (1ULL &lt;&lt; 31) | Ability Manager标签。 |
| [HIDEBUG_TRACE_TAG_CAMERA](_hi_debug.md#hidebug_trace_tag_camera)   (1ULL &lt;&lt; 32) | 相机模块标签。 |
| [HIDEBUG_TRACE_TAG_MEDIA](_hi_debug.md#hidebug_trace_tag_media)   (1ULL &lt;&lt; 33) | 媒体模块标签。 |
| [HIDEBUG_TRACE_TAG_IMAGE](_hi_debug.md#hidebug_trace_tag_image)   (1ULL &lt;&lt; 34) | 图像模块标签。 |
| [HIDEBUG_TRACE_TAG_AUDIO](_hi_debug.md#hidebug_trace_tag_audio)   (1ULL &lt;&lt; 35) | 音频模块标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA](_hi_debug.md#hidebug_trace_tag_distributed_data)   (1ULL &lt;&lt; 36) | 分布式数据管理器模块标签。 |
| [HIDEBUG_TRACE_TAG_GRAPHICS](_hi_debug.md#hidebug_trace_tag_graphics)   (1ULL &lt;&lt; 38) | 图形模块标签。 |
| [HIDEBUG_TRACE_TAG_ARKUI](_hi_debug.md#hidebug_trace_tag_arkui)   (1ULL &lt;&lt; 39) | ArkUI开发框架标签。 |
| [HIDEBUG_TRACE_TAG_NOTIFICATION](_hi_debug.md#hidebug_trace_tag_notification)   (1ULL &lt;&lt; 40) | 通知模块标签。 |
| [HIDEBUG_TRACE_TAG_MISC](_hi_debug.md#hidebug_trace_tag_misc)   (1ULL &lt;&lt; 41) | MISC模块标签。 |
| [HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT](_hi_debug.md#hidebug_trace_tag_multimodal_input)   (1ULL &lt;&lt; 42) | 多模态输入模块标签。 |
| [HIDEBUG_TRACE_TAG_RPC](_hi_debug.md#hidebug_trace_tag_rpc)   (1ULL &lt;&lt; 46) | RPC标签。 |
| [HIDEBUG_TRACE_TAG_ARK](_hi_debug.md#hidebug_trace_tag_ark)   (1ULL &lt;&lt; 47) | JSVM虚拟机标签。 |
| [HIDEBUG_TRACE_TAG_WINDOW_MANAGER](_hi_debug.md#hidebug_trace_tag_window_manager)   (1ULL &lt;&lt; 48) | 窗口管理器标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN](_hi_debug.md#hidebug_trace_tag_distributed_screen)   (1ULL &lt;&lt; 50) | 分布式屏幕标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA](_hi_debug.md#hidebug_trace_tag_distributed_camera)   (1ULL &lt;&lt; 51) | 分布式相机标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK](_hi_debug.md#hidebug_trace_tag_distributed_hardware_framework)   (1ULL &lt;&lt; 52) | 分布式硬件框架标签。 |
| [HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER](_hi_debug.md#hidebug_trace_tag_global_resource_manager)   (1ULL &lt;&lt; 53) | 全局资源管理器标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER](_hi_debug.md#hidebug_trace_tag_distributed_hardware_device_manager)   (1ULL &lt;&lt; 54) | 分布式硬件设备管理器标签。 |
| [HIDEBUG_TRACE_TAG_SAMGR](_hi_debug.md#hidebug_trace_tag_samgr)   (1ULL &lt;&lt; 55) | SA标签。 |
| [HIDEBUG_TRACE_TAG_POWER_MANAGER](_hi_debug.md#hidebug_trace_tag_power_manager)   (1ULL &lt;&lt; 56) | 电源管理器标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER](_hi_debug.md#hidebug_trace_tag_distributed_scheduler)   (1ULL &lt;&lt; 57) | 分布式调度程序标签。 |
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT](_hi_debug.md#hidebug_trace_tag_distributed_input)   (1ULL &lt;&lt; 59) | 分布式输入标签。 |
| [HIDEBUG_TRACE_TAG_BLUETOOTH](_hi_debug.md#hidebug_trace_tag_bluetooth)   (1ULL &lt;&lt; 60) | 蓝牙标签。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [HiDebug_ErrorCode](_hi_debug.md#hidebug_errorcode-1) [HiDebug_ErrorCode](_hi_debug.md#hidebug_errorcode) | 错误码定义。 |
| typedef struct [HiDebug_ThreadCpuUsage](_hi_debug___thread_cpu_usage.md) [HiDebug_ThreadCpuUsage](_hi_debug.md#hidebug_threadcpuusage) | 应用程序所有线程的CPU使用率结构体定义。 |
| typedef [HiDebug_ThreadCpuUsage](_hi_debug___thread_cpu_usage.md) \* [HiDebug_ThreadCpuUsagePtr](_hi_debug.md#hidebug_threadcpuusageptr) | HiDebug_ThreadCpuUsage指针定义。 |
| typedef struct [HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md) [HiDebug_SystemMemInfo](_hi_debug.md#hidebug_systemmeminfo) | 系统内存信息结构类型定义。 |
| typedef struct [HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md) [HiDebug_NativeMemInfo](_hi_debug.md#hidebug_nativememinfo) | 应用程序进程本机内存信息结构类型定义。 |
| typedef struct [HiDebug_MemoryLimit](_hi_debug___memory_limit.md) [HiDebug_MemoryLimit](_hi_debug.md#hidebug_memorylimit) | 应用程序进程内存限制结构类型定义。 |
| typedef enum [HiDebug_TraceFlag](_hi_debug.md#hidebug_traceflag-1) [HiDebug_TraceFlag](_hi_debug.md#hidebug_traceflag) | 采集trace线程的类型。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [HiDebug_ErrorCode](_hi_debug.md#hidebug_errorcode-1) {<br/>HIDEBUG_SUCCESS = 0,<br/>HIDEBUG_INVALID_ARGUMENT = 401,<br/>HIDEBUG_TRACE_CAPTURED_ALREADY = 11400102,<br/>HIDEBUG_NO_PERMISSION = 11400103,<br/>HIDEBUG_TRACE_ABNORMAL = 11400104,<br/>HIDEBUG_NO_TRACE_RUNNING = 11400105<br/>} | 错误码定义 |
| [HiDebug_TraceFlag](_hi_debug.md#hidebug_traceflag-1) {<br/>HIDEBUG_TRACE_FLAG_MAIN_THREAD = 1, HIDEBUG_TRACE_FLAG_ALL_THREADS = 2<br/>} | 采集trace线程的类型。 |
