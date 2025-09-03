# hidebug_type.h

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--Designer: @kutcherzhou1-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

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
| [HiDebug_ThreadCpuUsage](capi-hidebug-hidebug-threadcpuusage.md) | HiDebug_ThreadCpuUsage | 应用程序所有线程的CPU使用率结构体定义。 |
| [HiDebug_SystemMemInfo](capi-hidebug-hidebug-systemmeminfo.md) | HiDebug_SystemMemInfo | 系统内存信息结构类型定义。 |
| [HiDebug_NativeMemInfo](capi-hidebug-hidebug-nativememinfo.md) | HiDebug_NativeMemInfo | 应用程序进程本机内存信息结构类型定义。 |
| [HiDebug_MemoryLimit](capi-hidebug-hidebug-memorylimit.md) | HiDebug_MemoryLimit | 应用程序进程内存限制结构类型定义。 |
| [HiDebug_JsStackFrame](capi-hidebug-hidebug-jsstackframe.md) | HiDebug_JsStackFrame | js栈帧内容的定义。 |
| [HiDebug_NativeStackFrame](capi-hidebug-hidebug-nativestackframe.md) | HiDebug_NativeStackFrame | native栈帧内容的定义。 |
| [HiDebug_StackFrame](capi-hidebug-hidebug-stackframe.md) | HiDebug_StackFrame | 栈帧内容的定义。 |
| [HiDebug_MallocDispatch](capi-hidebug-hidebug-mallocdispatch.md) | HiDebug_MallocDispatch | 应用程序进程可替换/恢复的HiDebug_MallocDispatch表结构类型定义。 |
| [HiDebug_Backtrace_Object__*](capi-hidebug-hidebug-backtrace-object--8h.md) | HiDebug_Backtrace_Object | 用于栈回溯及栈解析的对象。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [HiDebug_ErrorCode](#hidebug_errorcode) | HiDebug_ErrorCode | 错误码定义。 |
| [HiDebug_TraceFlag](#hidebug_traceflag) | HiDebug_TraceFlag | 采集trace线程的类型。 |
| [HiDebug_StackFrameType](#hidebug_stackframetype) | HiDebug_StackFrameType | 栈帧类型的枚举值定义。 |

### 宏定义

| 名称                                                                                                                           | 描述                 |
|------------------------------------------------------------------------------------------------------------------------------|--------------------|
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

## 枚举类型说明

### HiDebug_ErrorCode

```
enum HiDebug_ErrorCode
```

**描述**

错误码定义。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| HIDEBUG_SUCCESS = 0 | 成功。 |
| HIDEBUG_INVALID_ARGUMENT = 401 | 无效参数，可能的原因： 1.参数传值问题；2.参数类型问题。 |
| HIDEBUG_TRACE_CAPTURED_ALREADY = 11400102 | 重复采集。 |
| HIDEBUG_NO_PERMISSION = 11400103 | 没有写文件的权限。 |
| HIDEBUG_TRACE_ABNORMAL = 11400104 | 系统内部错误。 |
| HIDEBUG_NO_TRACE_RUNNING = 11400105 | 当前没有trace正在运行。 |
| HIDEBUG_INVALID_SYMBOLIC_PC_ADDRESS = 11400200 | 传入符号解析函数的pc地址是无效的。<br/>**起始版本：** 20。 |

### HiDebug_TraceFlag

```
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

```
enum HiDebug_StackFrameType
```

**描述**

栈帧类型的枚举值定义。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| HIDEBUG_STACK_FRAME_TYPE_JS = 1 | js类型栈帧。 |
| HIDEBUG_STACK_FRAME_TYPE_NATIVE = 2 | native类型栈帧。 |


## 宏定义说明

### HIDEBUG_TRACE_TAG_FFRT

```
#define HIDEBUG_TRACE_TAG_FFRT (1ULL << 13)
```

**描述**

FFRT任务标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_COMMON_LIBRARY

```
#define HIDEBUG_TRACE_TAG_COMMON_LIBRARY (1ULL << 16)
```

**描述**

公共库子系统标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_HDF

```
#define HIDEBUG_TRACE_TAG_HDF (1ULL << 18)
```

**描述**

HDF子系统标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_NET

```
#define HIDEBUG_TRACE_TAG_NET (1ULL << 23)
```

**描述**

网络标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_NWEB

```
#define HIDEBUG_TRACE_TAG_NWEB (1ULL << 24)
```

**描述**

NWeb标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO (1ULL << 27)
```

**描述**

分布式音频标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_FILE_MANAGEMENT

```
#define HIDEBUG_TRACE_TAG_FILE_MANAGEMENT (1ULL << 29)
```

**描述**

文件管理标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_OHOS

```
#define HIDEBUG_TRACE_TAG_OHOS (1ULL << 30)
```

**描述**

OHOS通用标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_ABILITY_MANAGER

```
#define HIDEBUG_TRACE_TAG_ABILITY_MANAGER (1ULL << 31)
```

**描述**

Ability Manager标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_CAMERA

```
#define HIDEBUG_TRACE_TAG_CAMERA (1ULL << 32)
```

**描述**

相机模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_MEDIA

```
#define HIDEBUG_TRACE_TAG_MEDIA (1ULL << 33)
```

**描述**

媒体模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_IMAGE

```
#define HIDEBUG_TRACE_TAG_IMAGE (1ULL << 34)
```

**描述**

图像模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_AUDIO

```
#define HIDEBUG_TRACE_TAG_AUDIO (1ULL << 35)
```

**描述**

音频模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA (1ULL << 36)
```

**描述**

分布式数据管理器模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_GRAPHICS

```
#define HIDEBUG_TRACE_TAG_GRAPHICS (1ULL << 38)
```

**描述**

图形模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_ARKUI

```
#define HIDEBUG_TRACE_TAG_ARKUI (1ULL << 39)
```

**描述**

ArkUI开发框架标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_NOTIFICATION

```
#define HIDEBUG_TRACE_TAG_NOTIFICATION (1ULL << 40)
```

**描述**

通知模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_MISC

```
#define HIDEBUG_TRACE_TAG_MISC (1ULL << 41)
```

**描述**

MISC模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT

```
#define HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT (1ULL << 42)
```

**描述**

多模态输入模块标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_RPC

```
#define HIDEBUG_TRACE_TAG_RPC (1ULL << 46)
```

**描述**

RPC标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_ARK

```
#define HIDEBUG_TRACE_TAG_ARK (1ULL << 47)
```

**描述**

JSVM虚拟机标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_WINDOW_MANAGER

```
#define HIDEBUG_TRACE_TAG_WINDOW_MANAGER (1ULL << 48)
```

**描述**

窗口管理器标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN (1ULL << 50)
```

**描述**

分布式屏幕标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA (1ULL << 51)
```

**描述**

分布式相机标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK (1ULL << 52)
```

**描述**

分布式硬件框架标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER

```
#define HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER (1ULL << 53)
```

**描述**

全局资源管理器标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER (1ULL << 54)
```

**描述**

分布式硬件设备管理器标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_SAMGR

```
#define HIDEBUG_TRACE_TAG_SAMGR (1ULL << 55)
```

**描述**

SA标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_POWER_MANAGER

```
#define HIDEBUG_TRACE_TAG_POWER_MANAGER (1ULL << 56)
```

**描述**

电源管理器标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER (1ULL << 57)
```

**描述**

分布式调度程序标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT (1ULL << 59)
```

**描述**

分布式输入标签。

**起始版本：** 12

### HIDEBUG_TRACE_TAG_BLUETOOTH

```
#define HIDEBUG_TRACE_TAG_BLUETOOTH (1ULL << 60)
```

**描述**

蓝牙标签。

**起始版本：** 12


