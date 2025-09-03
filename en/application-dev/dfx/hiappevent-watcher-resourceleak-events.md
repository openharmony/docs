# Resource Leak Event Overview

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @xuxinao-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## Overview

Resource leaks occur when resources, such as handles, threads, or memory, are not properly released during application running. As a result, the resources are occupied for a long time and cannot be used by other applications. If a certain type of resource is exhausted, the system may crash or restart. To address resource leak problems, the system provides the resource leak detection and determination, maintenance and debugging logs, and log reporting capabilities for you to locate faults.

## Event Detection Principles

For details, see [Analyzing Resource Leaks](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/resource-leak-guidelines).

## Available APIs

You can call the API provided by HiAppEvent to subscribe to the system resource leak event **hiAppEvent.event.RESOURCE_OVERLIMIT**. When detecting a leak in an application process, the system captures maintenance and debugging information and sends the leak event to the application process through HiAppEvent.

- - [Subscribing to Resource Leak Events (ArkTS)](hiappevent-watcher-resourceleak-events-arkts.md)

- - [Subscribing to Resource Leak Events (C/C++)](hiappevent-watcher-resourceleak-events-ndk.md)

## params

The **params** parameter in the event information is described as follows.

| Name| Type| Description|
| -------- | -------- | -------- |
| time | number | Event triggering time, in ms.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of an application.|
| uid | number | User ID of an application.|
| resource_type | string | Resource type. For details, see **resource_type**.|
| memory | object | Memory information (only available for **pss_memory** and **js_heap**). For details, see **memory**.|
| fd | object | File descriptor information (only available for **fd**). For details, see **fd**.|
| thread | object | Thread information (only available for **thread**). For details, see **thread**.|
| external_log | string[] | Path of the error log file. If the directory files exceed the threshold (for details, see **log_over_limit**), new log files may fail to be written. Therefore, delete the log files immediately after they are processed.|
| log_over_limit | boolean | Whether the size of generated fault log files and existing log files exceeds the upper limit (2 GB). The value **true** indicates that the upper limit is exceeded and logs fail to be written. The value **false** indicates that the upper limit is not exceeded.|

### **resource_type**

| Value| Description|
| -------- | -------- |
| pss_memory | PSS memory leak.|
| ion_memory | ION memory leak.|
| gpu_memory | GPU memory leak.|
| js_heap | JS memory leak.|
| fd | Handle leak.|
| thread | Thread leak.|

### **memory**

| Name| Type| Description|
| -------- | -------- | -------- |
| rss | number | Size of the memory allocated for a process (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| vss | number | Size of the virtual memory applied by a process from the system (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| pss | number | Size of the physical memory actually used by a process (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| ion | number | Size of the ION memory actually used by a process (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| gpu | number | Size of the GPU memory actually used by a process (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| sys_free_mem | number | Size of the free memory (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| sys_avail_mem | number | Size of the available memory (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| sys_total_mem | number | Size of the total memory (only available for **pss_memory**, **ion_memory**, and **gpu_memory**), in KB.|
| limit_size | number | Limit of memory size (only available for **js_heap**), in KB.|
| live_object_size | number | Size of the used memory (only available for **js_heap**), in KB.|

### **fd**

| Name| Type| Description|
| -------- | -------- | -------- |
| num | number | Total number of FDs.|
| top_fd_type | string | FD type that is most frequently used.|
| top_fd_num | number | Number of FDs that are most frequently used.|

### **thread**

| Name| Type| Description|
| -------- | -------- | -------- |
| num | number | Total number of threads.|

## Customizing Parameters for Resource Leak Events

Currently, the resource leak event reports the JS memory leak event information, which may not meet your personal requirements. Therefore, the **setEventParam** method is provided to customize event reporting information.

### APIs 

| Name| Description|
| -------- | -------- |
| setEventParam(params: Record&lt;string, ParamType>, domain: string, name?: string): Promise&lt;void> | Sets custom event parameters.<br>Note: This API is supported since API version 20.|
