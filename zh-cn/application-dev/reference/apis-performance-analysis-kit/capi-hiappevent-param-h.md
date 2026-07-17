# hiappevent_param.h

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--Designer: @jiangwenhao-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## 概述

定义所有预定义的参数名称。开发者可以使用特定预定义的参数名称进行打点或对系统事件进行自定义参数规格设置。

如下宏定义的使用方法可参见指南：订阅主线程超时事件时[OH_HiAppEvent_SetEventConfig接口参数设置说明](../../dfx/hiappevent-watcher-mainthreadjank-events.md#oh_hiappevent_seteventconfig接口参数设置说明)、订阅崩溃事件时[OH_HiAppEvent_SetEventConfig接口参数设置说明](../../dfx/hiappevent-watcher-crash-events.md#oh_hiappevent_seteventconfig接口参数设置说明)。

**引用文件：** &lt;hiappevent/hiappevent_param.h&gt;

**库：** libhiappevent_ndk.z.so

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 8

**相关模块：** [HiAppEvent](capi-hiappevent.md)

## 汇总

### 宏定义

| 名称 | 描述 |
| -- | -- |
| [PARAM_USER_ID](#param_user_id) "user_id"                                                        | 用户ID。可用于预定义事件打点。<br>**起始版本：** 8  |
| [PARAM_DISTRIBUTED_SERVICE_NAME](#param_distributed_service_name) "ds_name"                      | 分布式服务名称。可用于预定义事件打点。<br>**起始版本：** 8   |
| [PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID](#param_distributed_service_instance_id) "ds_instance_id" | 分布式服务实例ID。可用于预定义事件打点。<br>**起始版本：** 8 |
| [MAIN_THREAD_JANK_PARAM_LOG_TYPE](#main_thread_jank_param_log_type) "log_type" | 用于MAIN_THREAD_JANK_V2事件，主线程超时检测采集日志的类型。<br>**起始版本：** 22 |
| [MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL](#main_thread_jank_param_sample_interval) "sample_interval" | 用于MAIN_THREAD_JANK_V2事件，主线程超时检测间隔和采样间隔。单位：ms。<br>**起始版本：** 22 |
| [MAIN_THREAD_JANK_PARAM_IGNORE_STARTUP_TIME](#main_thread_jank_param_ignore_startup_time) "ignore_startup_time" | 用于MAIN_THREAD_JANK_V2事件，应用启动期间忽略主线程超时检测的时间。单位：s。<br>**起始版本：** 22 |
| [MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT](#main_thread_jank_param_sample_count) "sample_count" | 用于MAIN_THREAD_JANK_V2事件，主线程超时检测的采样栈的次数。<br>**起始版本：** 22 |
| [MAIN_THREAD_JANK_PARAM_REPORT_TIMES_PER_APP](#main_thread_jank_param_report_times_per_app) "report_times_per_app" | 用于MAIN_THREAD_JANK_V2事件，每个应用PID一个生命周期内，主线程超时采样上报的次数，一个生命周期内只能设置一次。<br>**起始版本：** 22 |
| [MAIN_THREAD_JANK_PARAM_AUTO_STOP_SAMPLING](#main_thread_jank_param_auto_stop_sampling) "auto_stop_sampling" | 用于MAIN_THREAD_JANK_V2事件，主线程超时结束时，是否停止采样主线程堆栈。<br>**起始版本：** 22 |
| [OH_APP_CRASH_PARAM_EXTEND_PC_LR_PRINTING](#oh_app_crash_param_extend_pc_lr_printing) "extend_pc_lr_printing"                                                        | 用于设置APP_CRASH事件中的CPP_CRASH类型的日志规格，是否打印PC、LR寄存器扩展字节范围的内存内容。<br>**起始版本：** 24  |
| [OH_APP_CRASH_PARAM_LOG_FILE_CUTOFF_SZ_BYTES](#oh_app_crash_param_log_file_cutoff_sz_bytes) "log_file_cutoff_sz_bytes"                                                        | 用于设置APP_CRASH事件中的CPP_CRASH类型的日志规格，按设置的参数值大小截断CPP_CRASH日志。<br>**起始版本：** 24  |
| [OH_APP_CRASH_PARAM_SIMPLIFY_VMA_PRINTING](#oh_app_crash_param_simplify_vma_printing) "simplify_vma_printing"                                                        | 用于设置APP_CRASH事件中的CPP_CRASH类型的日志规格，是否只打印崩溃日志中出现的地址所属的VMA映射信息，以减小CPP_CRASH日志文件大小。<br>**起始版本：** 24  |
| [OH_APP_CRASH_PARAM_MERGE_CPPCRASH_APP_LOG](#oh_app_crash_param_merge_cppcrash_app_log) "merge_cppcrash_app_log"                                                        | 用于设置APP_CRASH事件中的CPP_CRASH类型的日志规格，是否在CPP_CRASH场景拼接应用沙箱中指定文件的日志。<br>**起始版本：** 24  |
| [OH_APP_CRASH_PARAM_COLLECT_MINIDUMP](#oh_app_crash_param_collect_minidump) "collect_minidump"  | <!--RP1-->用于APP_CRASH事件，是否使能minidump。<!--RP1End--><br>**起始版本：** 26.0.0  |


## 宏定义说明

### PARAM_USER_ID

```c
#define PARAM_USER_ID "user_id"
```

**描述**

用户ID。

**起始版本：** 8

### PARAM_DISTRIBUTED_SERVICE_NAME

```c
#define PARAM_DISTRIBUTED_SERVICE_NAME "ds_name"
```

**描述**

分布式服务名称。

**起始版本：** 8

### PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID

```c
#define PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID "ds_instance_id"
```

**描述**

分布式服务实例ID。

**起始版本：** 8

### MAIN_THREAD_JANK_PARAM_LOG_TYPE

```c
#define MAIN_THREAD_JANK_PARAM_LOG_TYPE "log_type"
```

**描述**

用于MAIN_THREAD_JANK_V2事件，主线程超时检测采集日志的类型。

**起始版本：** 22

### MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL

```c
#define MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL "sample_interval"
```

**描述**

用于MAIN_THREAD_JANK_V2事件，主线程超时检测间隔和采样间隔。

**起始版本：** 22

### MAIN_THREAD_JANK_PARAM_IGNORE_STARTUP_TIME

```c
#define MAIN_THREAD_JANK_PARAM_IGNORE_STARTUP_TIME "ignore_startup_time"
```

**描述**

用于MAIN_THREAD_JANK_V2事件，应用启动期间忽略主线程超时检测的时间。

**起始版本：** 22

### MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT

```c
#define MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT "sample_count"
```

**描述**

用于MAIN_THREAD_JANK_V2事件，主线程超时检测的采样栈的次数。

**起始版本：** 22

### MAIN_THREAD_JANK_PARAM_REPORT_TIMES_PER_APP

```c
#define MAIN_THREAD_JANK_PARAM_REPORT_TIMES_PER_APP "report_times_per_app"
```

**描述**

用于MAIN_THREAD_JANK_V2事件，每个应用PID一个生命周期内，主线程超时采样上报的次数，一个生命周期内只能设置一次。

**起始版本：** 22

### MAIN_THREAD_JANK_PARAM_AUTO_STOP_SAMPLING

```c
#define MAIN_THREAD_JANK_PARAM_AUTO_STOP_SAMPLING "auto_stop_sampling"
```

**描述**

用于MAIN_THREAD_JANK_V2事件，是否停止采样主线程堆栈。

**起始版本：** 22

### OH_APP_CRASH_PARAM_EXTEND_PC_LR_PRINTING

```c
#define OH_APP_CRASH_PARAM_EXTEND_PC_LR_PRINTING "extend_pc_lr_printing"
```

**描述**

用于设置APP_CRASH事件中的CPP_CRASH类型的日志规格，是否打印PC、LR寄存器扩展字节范围的内存内容。

**起始版本：** 24

### OH_APP_CRASH_PARAM_LOG_FILE_CUTOFF_SZ_BYTES

```c
#define OH_APP_CRASH_PARAM_LOG_FILE_CUTOFF_SZ_BYTES "log_file_cutoff_sz_bytes"
```

**描述**

用于设置APP_CRASH事件中的CPP_CRASH类型的日志规格，按设置的参数值大小截断CPP_CRASH日志。

**起始版本：** 24

### OH_APP_CRASH_PARAM_SIMPLIFY_VMA_PRINTING

```c
#define OH_APP_CRASH_PARAM_SIMPLIFY_VMA_PRINTING "simplify_vma_printing"
```

**描述**

用于设置APP_CRASH事件中的CPP_CRASH类型的日志规格，是否只打印崩溃日志中出现的地址所属的VMA映射信息，以减小CPP_CRASH日志文件大小。

**起始版本：** 24

### OH_APP_CRASH_PARAM_MERGE_CPPCRASH_APP_LOG

```c
#define OH_APP_CRASH_PARAM_MERGE_CPPCRASH_APP_LOG "merge_cppcrash_app_log"
```

**描述**

用于设置APP_CRASH事件中的CPP_CRASH类型的日志规格，是否在CPP_CRASH场景拼接应用沙箱中指定文件的日志。

**起始版本：** 24

### OH_APP_CRASH_PARAM_COLLECT_MINIDUMP

```c
#define OH_APP_CRASH_PARAM_COLLECT_MINIDUMP "collect_minidump"
```

**描述**

<!--RP2-->用于APP_CRASH事件，是否使能minidump。<!--RP2End-->

**起始版本：** 26.0.0
