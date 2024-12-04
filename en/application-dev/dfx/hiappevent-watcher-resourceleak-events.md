# Resource Leak Event Overview

HiAppEvent provides APIs for subscribing to system resource leak events of the system.

- - [Subscribing to Resource Leak Events (ArkTS)](hiappevent-watcher-resourceleak-events-arkts.md)
- - [Subscribing to Resource Leak Events (C/C++)](hiappevent-watcher-resourceleak-events-ndk.md)

The **params** parameter in the event information is described as follows.

**params**

| Name            | Type   | Description                                                                      |
|----------------|-------|----------------------------------------------------------------------|
| time           | number | Event triggering time, in ms.                                                           |
| bundle_version | string | Application version.                                                                   |
| bundle_name    | string | Application name.                                                                   |
| pid            | number | Process ID of the application.                                                                |
| uid            | number | User ID of the application.                                                                |
| resource_type  | string | Resource type. For details, see **resource_type**.                                             |
| memory         | object | Memory information (only available for **pss_memory** and **js_heap**). For details, see **memory**.                    |
| fd             | object | File descriptor information (only available for **fd**). For details, see **fd**.                                     |
| thread         | object | Thread information (only available for **thread**). For details, see **thread**.                                |
| external_log   | string[] | Path of the error log file. If the directory files exceed the threshold (for details, see **log_over_limit**), new log files may fail to be written. Therefore, delete the log files immediately after they are processed.|
| log_over_limit | Boolean  | Whether the size of generated fault log files and existing log files exceeds the upper limit (5 MB). The value **true** indicates that the upper limit is exceeded and logs fail to be written. The value **false** indicates that the upper limit is not exceeded.           |

**resource_type**

| Value   | Description                      |
| ------- | ------------------------- |
| pss_memory | PSS memory leak.|
| js_heap | JS memory leak.|
| fd | FD resource leak.|
| thread | Thread leak.|

**memory**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| rss | number | Size of the memory allocated for a process (only available for **pss_memory**), in KB.|
| vss | number | Size of the virtual memory applied by a process from the system (only available for **pss_memory**), in KB.|
| pss | number | Size of the physical memory actually used by a process (only available for **pss_memory**), in KB.|
| sys_free_mem | number | Size of free memory (only available for **pss_memory**), in KB.|
| sys_avail_mem | number | Size of available memory (only available for **pss_memory**), in KB.|
| sys_total_mem | number | Total memory size (only available for **pss_memory**), in KB.|
| limit_size | number | Limit of memory size (only available for **js_heap**), in KB.|
| live_object_size | number | Size of the used memory (only available for **js_heap**), in KB.|

**fd**

| Name       | Type  | Description               |
| ----------- | ------ | ------------------- |
| num         | number | Total number of FDs.         |
| top_fd_type | string | FD with the largest number. |
| top_fd_num  | number | Number of **top_fd_type**.|

**thread**

| Name| Type  | Description          |
| ---- | ------ | -------------- |
| num  | number | Total number of threads.|
