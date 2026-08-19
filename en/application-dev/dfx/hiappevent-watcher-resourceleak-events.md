# Resource Leak Event Overview

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @xuxinao-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=281a5975cfb5f25896e63aa56d3d9f8deabd3462 translatedAt=2026-08-15T01:47:45.131Z pushedAt=2026-08-15T07:17:12.529Z -->

## Overview

Resource leaks occur when resources, such as handles, threads, or memory, are not properly released during application running. As a result, the resources are occupied for a long time and cannot be used by other applications. If a certain type of resource is exhausted, the system may crash or restart.

This topic describes the fields of the resource leak event. For details about how to use the ArkTs and C/C++ APIs provided by HiAppEvent to subscribe to system resource leak events, see the following documents:  

- [Subscribing to Resource Leak Events (ArkTS)](hiappevent-watcher-resourceleak-events-arkts.md)

- [Subscribing to Resource Leak Events (C/C++)](hiappevent-watcher-resourceleak-events-ndk.md)

> **NOTE**
>
> Resource leak events can be subscribed to using HiAppEvent in [application clones](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/app-clone) and atomic services. Since API version 22, resource leak events can be subscribed to using HiAppEvent in [input method applications](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/inputmethod-application-guide).

## Detection Principles

For details about the detection principles, see [Resource Leak Detection](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/resource-leak-guidelines).

## Customizing Specifications

### setEventConfig API Description

| Name| Description|
| -------- | -------- |
| setEventConfig(name: string, config: Record<string, ParamType>): Promise&lt;void> | Sets the resource leak log specification parameters. The name parameter must be the resource leak event name constant **hiappevent.event.RESOURCE_OVERLIMIT**. **Only the JS memory leak type is supported.**<br>**Note:** This API is supported since API version 20. |

### setEventConfig Parameter Setting Description

You can use the HiAppEvent APIs to set the log and callback event specifications of **RESOURCE_OVERLIMIT** in **Record<string, ParamType>**. The specific parameter descriptions are as follows.

| Name         | Type  | Mandatory| Description                                                        |
| --------------- | ------ | ---- | ------------------------------------------------------------ |
| js_heap_logtype | string | No | **event**: When the app encounters OOM, no heap snapshot is passed.<br>**event_rawheap**: When the app encounters OOM, the system generates and passes a heap snapshot.<br>**Note:** Only the above two values are accepted. If any other value is passed, the method call fails without producing any effect. |

> **NOTE**
>
> Even if the **js_heap_logtype** parameter is set to **event_rawheap**, heap snapshot file generation is not guaranteed. This is because the app may exit prematurely due to screen freezing caused by performance issues when generating a heap snapshot.

Parameter configuration example:

```ts
let configParams: Record<string, hiAppEvent.ParamType> = {
    "js_heap_logtype": "event", // Obtain only events.
    // "js_heap_logtype": "event_rawheap", // Obtain heap snapshots.
};

hiAppEvent.setEventConfig(hiAppEvent.event.RESOURCE_OVERLIMIT, configParams);
```

> **NOTE**
>
> When you call the **setEventConfig** API, each call takes effect only within the current app lifecycle. After the app restarts, you must call the **setEventConfig** API again.
>
> Within the same app lifecycle, you can call **setEventConfig** multiple times, and the value from the last successful call prevails.
>
> During debugging and self-testing, if the OOM event is triggered too many times within a single day, you may not receive the JS memory leak event callback from HiAppEvent. You can work around this by adjusting the system time forward by one day.

### configEventPolicy

Page switch log configuration is supported since **API version 24**. When a resource leak fault occurs in the app, the system can collect and report page switch logs to help you locate the issue.

Setting the log and callback event specifications for resource leak events is supported since **API version 26.0.0**.

| Name | Description |
| -------- | -------- |
| [configEventPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventconfigeventpolicy22) (policy: EventPolicy): Promise&lt;void>| Sets the resource leak event policy parameters. This API supports enabling page switch log collection for resource leak events and setting the log and callback event specifications for resource leak events. |

### configEventPolicy Parameter Settings

You can set the parameters of [EventPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#eventpolicy22) to enable page switch log collection for resource leak events and set the log and callback event specifications for resource leak events.

| Name | Type | Read-only | Optional | Description |
| ---------- | ------- | ---- | ---- | ------------------------------------------ |
| resourceOverlimitPolicy | [ResourceOverlimitPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#resourceoverlimitpolicy24) | No | Yes | Resource leak event configuration policy. |

Parameter configuration example:

```ts
import { deviceInfo, BusinessError } from '@kit.BasicServicesKit';
import { hilog, hiAppEvent } from '@kit.PerformanceAnalysisKit';

let policy: hiAppEvent.EventPolicy = {
    resourceOverlimitPolicy: {
        pageSwitchLogEnable: true, // Enable page switch logging. Supported since API version 24.
        useRefinedLogFileName: true, // Enable the refined event log file name switch. Supported since API version 26.0.0.
        js_heap_logtype: "event", // Obtain only events. Supported since API version 26.0.0.
        // js_heap_logtype: "event_rawheap", // Obtain heap snapshots simultaneously. Supported since API version 26.0.0.
    }
};
hiAppEvent.configEventPolicy(policy).then(() => {
    hilog.info(0x0000, 'hiAppEvent', `Set resourceOverlimit config policy successfully.`);
}).catch((err: BusinessError) => {
    hilog.error(0x0000, 'hiAppEvent', `Failed to set resourceOverlimit config policy. code: ${err.code}, message: ${err.message}`);
});
```

## params

The **params** parameter in the event information is described as follows.

| Name| Type| Description|
| -------- | -------- | -------- |
| time | number | Event triggering time, in ms.|
| app_running_unique_id | string | Unique ID associated with the app runtime.<br>**Note:** This parameter is supported since API version 24. |
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of an application.|
| uid | number | User ID of an application.|
| resource_type | string | Resource type. For details, see **resource_type**.|
| memory | object | (Specific to resource_type pss_memory or js_heap) Memory information. For details, see [memory](#memory). |
| fd | object | (Specific to resource_type fd) File descriptor information. For details, see [fd](#fd). |
| thread | object | (Specific to resource_type thread) Thread information. For details, see [thread](#thread). |
| external_log | string[] | Path of the error log file. If the directory files exceed the threshold (for details, see **log_over_limit**), new log files may fail to be written. Therefore, delete the log files immediately after they are processed.|
| log_over_limit | boolean | Whether the size of generated fault log files and existing log files exceeds the upper limit (2 GB). The value **true** indicates that the upper limit is exceeded and logs fail to be written. The value **false** indicates that the upper limit is not exceeded.|
| page_switch_log | string | Page transition log path. For details about the log, see [Page Switch Logs](pageswitch-log.md).<br>**Note:** Supported since API version 24. |

### resource_type

| Value| Description|
| -------- | -------- |
| pss_memory | PSS memory leak.|
| rss_memory | RSS memory leak.<br>**Note:** This field is supported since API version 26.0.0. |
| ion_memory | ION memory leak.<br>**Note:** This field is supported since API version 20. |
| gpu_memory | GPU memory leak.<br>**Note:** This field is supported since API version 20. |
| js_heap | JS memory leak. |
| fd | Handle leak.|
| thread | Thread leak.|

### memory

| Name| Type| Description|
| -------- | -------- | -------- |
| rss | number | Size of the memory allocated for a process (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| vss | number | Size of the virtual memory applied by a process from the system (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| pss | number | Size of the physical memory actually used by a process (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| ion | number | Size of the ION memory actually used by a process (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.<br>**Note:** Supported since API version 20. |
| gpu | number | Size of the GPU memory actually used by a process (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.<br>**Note:** Supported since API version 20. |
| sys_free_mem | number | Size of the free memory (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| sys_avail_mem | number | Size of the available memory (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| sys_total_mem | number | Size of the total memory (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| limit_size | number | Limit of memory size (only available for **js_heap**), in KB.|
| live_object_size | number | Size of the used memory (only available for **js_heap**), in KB.|
| rss_detail | object | Detailed distribution information of RSS memory (only available for **rss_memory**). For details, see [detail field description](#detail).<br>**Note:** Supported since API version 26.0.0. |
| pss_detail | object | Detailed distribution information of PSS memory (only available for **pss_memory**). For details, see [detail field description](#detail).<br>**Note:** Supported since API version 26.0.0. |

### detail

| Name | Type | Description |
| -------- | -------- | -------- |
| .db | number | Memory occupied by database files, in KB. |
| .hap | number | Memory occupied by HAP files, in KB. |
| .so | number | Memory occupied by shared library files, in KB. |
| .ttf | number | Memory occupied by font files, in KB. |
| anon_page_other | number | Memory occupied by other anonymous pages, in KB. |
| ark ts heap | number | Memory occupied by the ArkTS heap, in KB. |
| arkweb-js heap | number | Memory occupied by the ArkWeb JS heap, in KB. |
| arkweb-pa heap | number | Memory occupied by the ArkWeb PA heap, in KB. |
| dart heap | number | Memory occupied by the Dart heap, in KB. |
| dev | number | Memory occupied by various files under /dev, in KB. |
| file_page_other | number | Memory occupied by other file pages, in KB. |
| jsvm heap | number | Memory occupied by the JSVM heap, in KB. |
| kotlin heap | number | Memory occupied by the Kotlin heap, in KB. |
| native heap | number | Memory occupied by the Native heap, in KB. |
| other | number | Memory occupied by other types, in KB. |
| rn-hermes heap | number | Memory occupied by the React Native Hermes heap, in KB. |
| stack | number | Memory occupied by the stack space, in KB. |

### fd

| Name| Type| Description|
| -------- | -------- | -------- |
| num | number | Total number of FDs.|
| top_fd_type | string | FD type that is most frequently used.|
| top_fd_num | number | Number of FDs that are most frequently used.|

### thread

| Name| Type| Description|
| -------- | -------- | -------- |
| num | number | Total number of threads.|

## Customizing params

Currently, the resource leak event reports the JS memory leak event information, which may not meet your personal requirements. Therefore, the **setEventParam** method is provided to customize event reporting information.

### Available APIs

| Name| Description|
| -------- | -------- |
| setEventParam(params: Record&lt;string, ParamType>, domain: string, name?: string): Promise&lt;void> | Sets custom event parameters.<br>**Note:** This API is supported since API version 20. |