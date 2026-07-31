# App Freeze Warning Event Overview

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=f319e3e62d6356bf78f31e2e8f7ba3927caddf1e translatedAt=2026-07-29T10:49:35.034Z pushedAt=2026-07-29T12:38:13.057Z -->

## Overview

Starting from API version 26.0.0, during app runtime, if only warning events under [app freeze events](appfreeze-guidelines.md#detection-principles), such as **THREAD_BLOCK_3S** and **LIFECYCLE_HALF_TIMEOUT**, are triggered, the system classifies them as app freeze warning events. For such scenarios, the system provides capabilities including app freeze warning detection, diagnostic log capture, and log reporting, helping you identify risks early and pinpoint potential freeze or hang issues.

This section introduces the detection principle of **AppFreezeWarning** (app freeze warning) events as well as the meaning and specifications of each field. To learn how to use HiAppEvent APIs to subscribe to app freeze warning events, refer to the following documents. Both ArkTS and C/C++ APIs are available; choose based on your needs.

- [Subscribing to App Freeze Warning Events (ArkTS)](hiappevent-watcher-appfreezewarning-events-arkts.md)

- [Subscribing to App Freeze Warning Events (C/C++)](hiappevent-watcher-appfreezewarning-events-ndk.md)

> **NOTE**
>
> App freeze warning events can be subscribed to by using HiAppEvent in [app clone](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/app-clone), atomic service, and [input method app](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/inputmethod-application-guide) scenarios.

## Detection Principles

For details, see the description for **THREAD_BLOCK_3S** and **LIFECYCLE_HALF_TIMEOUT** warning events in [AppFreeze Detection Principles](appfreeze-guidelines.md#detection-principles).

## Event Field Description

### params

The following table describes the properties of the **params** field in an app freeze warning event.

| Name | Type | Description |
| -------- | -------- | -------- |
| time | number | Event trigger time, in ms. |
| foreground | boolean | Whether the app is in the foreground. **true** indicates that the app is in the foreground; **false** indicates that the app is in the background. |
| bundle_version | string | App version. |
| bundle_version_code | number | App version code. |
| bundle_name | string | App name. |
| process_name | string | Process name of the app. |
| pid | number | Process ID of the app. |
| uid | number | User ID of the app. |
| exception | object | Exception information. For details, see [exception](#exception). |
| hilog | string[] | Log information. When an Application Not Responding event log is generated, up to 1000 lines of faulty process log information are obtained from the hilog buffer. |
| event_handler | string[] | Unprocessed messages of the main thread. |
| peer_binder | string[] | Binder call information. |
| threads | object[] | Call stacks of all threads. For details, see [thread](#thread). |
| memory | object | Memory information. For details, see [memory](#memory). |
| process_life_time | number | Faulty process survival time, in s. |
| app_running_unique_id | string | Unique ID associated with the app at runtime. |

### exception

| Name | Type | Description |
| -------- | -------- | -------- |
| name | string | Exception type. |
| message | string | Exception cause. |

### thread

| Name | Type | Description |
| -------- | -------- | -------- |
| thread_name | string | Thread name. |
| tid | number | Thread ID. |
| frames | object[] | Thread call stack. For details, see [frames](#frames). |
| state | string | Thread running state. Read from the state value in /proc/pid/stat. |
| utime | number | Number of CPU ticks consumed by the thread in user mode. Read from the utime value in /proc/pid/stat. |
| stime | number | Number of CPU ticks consumed by the thread in kernel mode. Read from the stime value in /proc/pid/stat. |
| priority | number | Real-time priority. Read from the priority value in /proc/pid/stat. |
| nice | number | Static priority. Read from the nice value in /proc/pid/stat. |
| clk | number | Number of clock ticks per second. Obtained by using sysconf(_SC_CLK_TCK). If the call fails, the default value 100 is used. The running time (in seconds) can be calculated by dividing the tick count by this value. |

### frames

**Native stack frames**

| Name | Type | Description |
| -------- | -------- | -------- |
| symbol | string | Function name.<br/>**If the name exceeds 256 bytes, the excess part will be truncated to prevent unknown issues caused by excessively long strings.** |
| file | string | File name. |
| buildId | string | Derived from .note.gnu.build-id in the ELF file. |
| pc | string | Hexadecimal byte offset of the instruction executed by the program within the file. |
| offset | number | Byte offset of the instruction executed by the program within the function. |

For details, see [Common Faults](cppcrash-guidelines.md#common-faults).

**JavaScript stack frames**

| Name | Type | Description |
| -------- | -------- | -------- |
| file | string | File name. |
| packageName | string | Package name of the module. |
| symbol | string | Function name. |
| line | number | Line number in the code. |
| column | number | Column number in the code. |

For details, see [Common Faults](cppcrash-guidelines.md#common-faults).

### memory

| Name | Type | Description |
| -------- | -------- | -------- |
| rss | number | Actual physical memory occupied by the process, in KB. |
| vss | number | Virtual memory requested by the process from the system, in KB. |
| sys_free_mem | number | Free memory size, in KB. |
| sys_avail_mem | number | Available memory size, in KB. |
| sys_total_mem | number | Total memory size, in KB. |
| vm_heap_total_size | number | Total heap memory size of the main VM, in KB. |
| vm_heap_used_size | number | Size of surviving objects continuously tracked during the lifecycle of the main VM, in KB. |