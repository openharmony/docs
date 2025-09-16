# Task Execution Timeout Event Overview

## Overview

Task execution timeout indicates that the execution duration of the monitored service code logic exceeds the expected duration. To better locate and analyze problems, use the [Task Execution Timeout Detection](apptask-timeout-guidelines.md#task-execution-timeout-detection) mechanism and analyze task execution timeout based on the [log specifications](apptask-timeout-guidelines.md#log-specifications).

## Detection Principles

For details, see [Detection Principles](apptask-timeout-guidelines.md#detection-principles).

## Available APIs

You can subscribe to task execution timeout events **EVENT_APP_HICOLLIE** using the APIs provided by HiAppEvent. When the system detects that a task execution times out, it captures maintenance and debugging information and sends the timeout callback to the application process through HiAppEvent.

- [Subscribing to Task Execution Timeout Events (C/C++)](hiappevent-watcher-apphicollie-events-ndk.md)

## Field Description

### params

The **params** parameter in the event information is described as follows:

| Name| Type| Description|
| -------- | -------- | -------- |
| time | number | Event triggering time, in ms.|
| foreground | boolean | Whether the application is running in the foreground. The value **true** indicates that the application is in the foreground, and the value **false** indicates the opposite.|
| bundle_version | string | Application version.|
| process_name | string | Process name of the application.|
| pid | number | Process ID of an application.|
| uid | number | User ID of an application.|
| uuid | string | Error ID, which is generated based on fault information and uniquely identifies crash faults of the same type.|
| exception | object | Exception information. For details, see **exception**.|
| hilog | string[] | Log information.|
| peer_binder | string[] | Binder call, binder call chain, and related stack capture information.|
| memory | object | Memory information. For details, see **memory**.|
| external_log | string[] | Path of the error log file. If the directory files exceed the threshold (for details, see **log_over_limit**), new log files may fail to be written. Therefore, delete the log files immediately after they are processed.|
| log_over_limit | boolean | Whether the size of generated fault log files and existing log files exceeds the upper limit (5 MB). The value **true** indicates that the upper limit is exceeded and logs fail to be written. The value **false** indicates that the upper limit is not exceeded.|

### exception

 

| Name| Type| Description|
| -------- | -------- | -------- |
| name | string | Exception type.|
| message | string | Exception cause.|

### memory

 

| Name| Type| Description|
| -------- | -------- | -------- |
| rss | number | Size of the memory allocated for a process, in KB.|
| vss | number | Size of the virtual memory applied by a process from the system, in KB.|
| pss | number | Size of the physical memory actually used by a process, in KB.|
| sys_free_mem | number | Size of free memory, in KB.|
| sys_avail_mem | number | Size of available memory, in KB.|
| sys_total_mem | number | Total memory size, in KB.|
