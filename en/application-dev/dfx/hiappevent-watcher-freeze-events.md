# Application Freeze Event Overview

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=f319e3e62d6356bf78f31e2e8f7ba3927caddf1e translatedAt=2026-07-31T01:29:09.322Z pushedAt=2026-07-31T03:51:51.495Z -->

## Overview

AppFreeze (application freeze) means that an application does not respond to user operations (for example, clicking) for a specified period of time. To address application freeze problems, the system provides the application freeze detection, maintenance and debugging log capturing, and log reporting capabilities to help you locate faults.

This section introduces the detection principle of **AppFreeze** (app freeze) as well as the meaning and specifications of each field. To learn how to use HiAppEvent APIs to subscribe to app freeze events, refer to the following documents. Both ArkTS and C/C++ APIs are available; choose based on your needs.

- [Subscribing to Application Freeze Events (ArkTS)](hiappevent-watcher-freeze-events-arkts.md)

- [Subscribing to Application Freeze Events (C/C++)](hiappevent-watcher-freeze-events-ndk.md)

> **NOTE**
>
> App freeze events can be subscribed to using HiAppEvent in [app clones](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/app-clone) and atomic services. Since API version 22, app freeze events can be subscribed to using HiAppEvent in [input method applications](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/inputmethod-application-guide).

## Detection Principles

For details, see [Application Freeze Detection Principles](appfreeze-guidelines.md#detection-principles).

## Custom Parameter Settings for Page Transition Log Specification

Supported since **API version 24**, page transition log configuration allows the system to collect and report page transition logs when an app freeze occurs, helping you locate issues.

### configEventPolicy

| API | Description |
| -------- | -------- |
| [configEventPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventconfigeventpolicy22) (policy: EventPolicy): Promise&lt;void>| Sets the policy parameters for app freeze events. This API enables page transition log collection for app freeze events. |

### configEventPolicy Parameter Settings

You can enable page transition log collection for app freeze events by setting parameters in [EventPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#eventpolicy22).

| Name       | Type    | Read-only | Optional | Description                                         |
| ---------- | ------- | ---- | ---- | ------------------------------------------ |
| appFreezePolicy | [AppFreezePolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#appfreezepolicy24) | No | Yes   | Configuration policy for app freeze events. |

**Parameter Setting Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog, hiAppEvent } from '@kit.PerformanceAnalysisKit';

let policy: hiAppEvent.EventPolicy = {
    "appFreezePolicy" : {
      "pageSwitchLogEnable": true // Enable page switch logging.
    }
};
hiAppEvent.configEventPolicy(policy).then(() => {
    hilog.info(0x0000, 'hiAppEvent', `Set crash config policy successfully.`);
}).catch((err: BusinessError) => {
    hilog.error(0x0000, 'hiAppEvent', `Failed to set crash config policy. code: ${err.code}, message: ${err.message}`);
});
```

## Event Fields

### params

The **params** attribute in the event information is described as follows.

| Name| Type| Description|
| -------- | -------- | -------- |
| time | number | Event triggering time, in ms.|
| foreground | boolean | Whether the application is running in the foreground. The value **true** indicates that the application is in the foreground, and the value **false** indicates the opposite.|
| release_type | string | App version type. The value **release** indicates that the app is a [release-type app](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916), and the value **debug** indicates that the app is a [debug-type app](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916).<br>**Note:** Supported since API version 23. |
| cpu_abi | string | ABI type.<br>**Note**: This field is supported since API version 23.|
| app_running_unique_id | string | Unique ID associated with the app runtime.<br>**Note:** This parameter is supported since API version 24. |
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| process_name | string | Process name of the application.|
| pid | number | Process ID of an application.|
| uid | number | User ID of an application.|
| uuid | string | Error ID, which is generated based on fault information and uniquely identifies crash faults of the same type.|
| exception | object | Exception information. For details, see [exception](#exception). |
| hilog | string[] | Log information. For the application freeze event, a maximum of 100 lines of faulty process log information can be obtained from the hilog buffer.|
| event_handler | string[] | Events not yet handled by the main thread.|
| event_handler_size_3s | string | Number of tasks in the task stack at 3s in the [THREAD_BLOCK_6S event](appfreeze-guidelines.md#thread_block_6s-app-main-thread-freeze-timeout) (effective only for Application Not Responding events). |
| event_handler_size_6s | string | Number of tasks in the task stack at 6s in the [THREAD_BLOCK_6S event](appfreeze-guidelines.md#thread_block_6s-app-main-thread-freeze-timeout) (effective only for Application Not Responding events). |
| peer_binder | string[] | Binder call information.|
| threads | object[] | Full thread call stack. For details, see [thread](#thread). |
| memory | object | Memory information. For details, see [memory](#memory). |
| external_log<sup>12+</sup> | string[] | Path of the error log file. If the directory files exceed the threshold (for details, see **log_over_limit**), new log files may fail to be written. Therefore, delete the log files immediately after they are processed.|
| log_over_limit<sup>12+</sup> | boolean | Whether the total size of the generated fault log file and existing log files exceeds the 5 MB upper limit. The value **true** indicates that the upper limit is exceeded and log writing fails; **false** indicates that the upper limit is not exceeded.<br>When [minidump](performance-analysis-kit-terminology.md#minidump) is enabled, the upper limit is adjusted to 35 MB; when minidump is disabled, the upper limit is restored to 5 MB. |
| process_life_time | number | Fault process survival time.<br>**Note:** Supported since API version 22. |
| external_callback_log | string | Custom callback log information, which can be written through [OH_HiCollie_SetFreezeCallback](../reference/apis-performance-analysis-kit/capi-hicollie-h.md#oh_hicollie_setfreezecallback).<br>**Note:** Supported since API version 24. |
| page_switch_log | string | Page transition log path. For details about the log, see [Page Switch Logs](pageswitch-log.md).<br>**Note:** Supported since API version 24. |

### exception

| Name| Type| Description|
| -------- | -------- | -------- |
| name | string | Exception type. |
| message | string | Exception cause. |

### thread

| Name | Type | Description |
| -------- | -------- | -------- |
| thread_name | string | Thread name. |
| tid | number | Thread ID. |
| frames | object[] | Thread call stack. For details, see [frame](#frame). |
| state | string | Thread running state. Read from the state value in /proc/pid/stat.<br>**Note:** Supported from API version 23. |
| utime | number | Number of CPU ticks consumed by the thread in user mode. Read from the utime value in /proc/pid/stat.<br>**Note:** Supported from API version 23.|
| stime | number | Number of CPU ticks consumed by the thread in kernel mode. Read from the stime value in /proc/pid/stat.<br>**Note:** Supported from API version 23.|
| priority | number | Real-time priority. Read from the priority value in /proc/pid/stat.<br>**Note:** Supported from API version 23.|
| nice | number | Static priority. Read from the nice value in /proc/pid/stat.<br>**Note:** Supported from API version 23.|
| clk | number | Number of clock ticks per second. Obtained using sysconf(_SC_CLK_TCK). If the call fails, the default value 100 is used. The running time (in seconds) can be calculated by dividing the number of ticks by this value.<br>**Note:** Supported from API version 23.|

### frame

Native frame

| Name| Type| Description|
| -------- | -------- | -------- |
| symbol | string | Function name. If the name length exceeds 256 bytes, the name is deleted to prevent unknown issues.|
| file | string | File name.|
| buildId | string | Build ID from the **.note.gnu.build-id** section of the ELF file. |
| pc | string | Hexadecimal byte offset of the executed instruction within the file.|
| offset | number | Byte offset of the executed instruction within the function.|

For details, see [Call stack frame](cppcrash-guidelines.md#common-faults).

JS frame

| Name| Type| Description|
| -------- | -------- | -------- |
| file | string | File name. |
| packageName | string | Package name of the module. |
| symbol | string | Function name. |
| line | number | Line number of the code. |
| column | number | Column number of the code. |

For details, see [JS hybrid stack frame](cppcrash-guidelines.md#common-faults).

### memory

| Name| Type| Description|
| -------- | -------- | -------- |
| rss | number | Actual memory usage of the process, in KB. Corresponds to the Process Memory(kB) field in [Appfreeze logs](appfreeze-guidelines.md#header-information). |
| vss | number | Size of the virtual memory applied by a process from the system, in KB.|
| pss | number | Size of the physical memory actually used by a process, in KB.|
| sys_free_mem | number | Free memory size, in KB. Corresponds to the Free value of the Device Memory(kB) field in [Appfreeze logs](appfreeze-guidelines.md#header-information). |
| sys_avail_mem | number | Available memory size, in KB. Corresponds to the Available value of the Device Memory(kB) field in [Appfreeze logs](appfreeze-guidelines.md#header-information). |
| sys_total_mem | number | Total memory size, in KB. Corresponds to the Total value of the Device Memory(kB) field in [Appfreeze logs](appfreeze-guidelines.md#header-information). |
| vm_heap_total_size | number | Total heap memory size of the main VM, in KB.<br>**Note:** Supported from API version 22. |
| vm_heap_used_size | number | Size of surviving objects continuously tracked during the lifecycle of the main VM, in KB.<br>**Note:** Supported from API version 22. |

## Customizing Parameters for Application Freeze Events

### Available APIs

| Name| Description|
| -------- | -------- |
| setEventParam(params: Record&lt;string, ParamType>, domain: string, name?: string): Promise&lt;void> | Sets custom parameters for application freeze events.|

### Setting Parameters

You can use this API to subscribe to app freeze events with the name **hiAppEvent.event.APP_FREEZE**. For details, see [hiAppEvent.setEventParam](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventseteventparam12).