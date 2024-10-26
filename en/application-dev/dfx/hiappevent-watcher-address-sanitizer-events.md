# Address Sanitizer Event Overview

HiAppEvent provides APIs for subscribing to address sanitizer events of the system.

- [Subscribing to Address Sanitizer Events (ArkTS)](hiappevent-watcher-address-sanitizer-events-arkts.md)
- [Subscribing to Address Sanitizer Events (C/C++)](hiappevent-watcher-address-sanitizer-events-ndk.md)

The **params** parameter in the event information is described as follows:

**params**:

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| time     | number | Event triggering time, in ms.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of the application.|
| uid | number | User ID of the application.|
| type | string | Type of the address sanitizer error. For details, see the description of **type**.|
| external_log | string[] | Path of the error log file. If the directory files exceed the threshold (for details, see **log_over_limit**), new log files may fail to be written. Therefore, delete the log files immediately after they are processed.|
| log_over_limit | boolean | Whether the size of generated log files and existing log files exceeds the upper limit (5 MB). The value **true** indicates that the upper limit is exceeded and logs fail to be written. The value **false** indicates that the upper limit is not exceeded.|

**type**:

| Value   | Description                      |
| ------- | ------------------------- |
| alloc-dealloc-mismatch | The memory allocation and release modes do not match.|
| allocation-size-too-big | The memory allocated is too large for the heap.|
| calloc-overflow | **calloc()** fails.|
| container-overflow | The container overflows.|
| double-free | The same memory address is released more than once.|
| dynamic-stack-buffer-overflow | The buffer access exceeds the boundary of a stack-allocated object.|
| global-buffer-overflow | The global buffer overflows.|
| heap-buffer-overflow | The heap buffer overflows.|
| heap-use-after-free | The released heap memory is used.|
| invalid-allocation-alignment | The alignment mode specified in memory allocation is invalid.|
| memcpy-param-overlap | **memcpy()** does not support overlapping memory regions.|
| new-delete-type-mismatch | The released memory size does not match the allocated memory size.|
| stack-buffer-overflow | The stack buffer overflows.|
| stack-buffer-underflow | The stack buffer underflows.|
| stack-use-after-return | The stack memory is used after the function has returned.|
| stack-use-after-scope | The stack memory is out of range.|
| strcat-param-overlap | The source and destination buffers used for string concatenation overlap.|
| use-after-poison | The poisoned memory (memory marked as invalid or inaccessible) is accessed or modified.|
