# Resource Leak Event Overview

HiAppEvent provides APIs for subscribing to system resource leak events of the system.

- - [Subscribing to Resource Leak Events (ArkTS)](hiappevent-watcher-resourceleak-events-arkts.md)
- - [Subscribing to Resource Leak Events (C/C++)](hiappevent-watcher-resourceleak-events-ndk.md)

The **params** parameter in the event information is described as follows.

**params**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| time     | number | Event triggering time, in ms.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of the application.|
| uid | number | User ID of the application.|
| resource_type | string | Resource type. For details, see **resource_type**.|
| memory | object | Memory information. For details, see **memory**.|

**resource_type**

| Value   | Description                      |
| ------- | ------------------------- |
| pss_memory | PSS memory leak.|
| js_memory | JS memory leak.|
| fd | FD resource leak.|
| thread | Thread leak.|

**memory**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| rss | number | Size of the memory allocated for a process, in KB.|
| vss | number | Size of the virtual memory applied by a process from the system, in KB.|
| pss | number | Size of the physical memory actually used by a process, in KB.|
| sys_free_mem | number | Size of free memory, in KB.|
| sys_avail_mem | number | Size of available memory, in KB.|
| sys_total_mem | number | Total memory size, in KB.|
