# Main Thread Jank Event Overview

HiAppEvent provides APIs for subscribing to main thread jank events.

- [Subscribing to Main Thread Jank Events (ArkTS)](hiappevent-watcher-mainthreadjank-events-arkts.md)
- [Subscribing to Main Thread Jank Events (C/C++)](hiappevent-watcher-mainthreadjank-events-ndk.md)

The **params** parameter in the event information is described as follows.

**params**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| time     | number | Event triggering time, in ms.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of the application.|
| uid | number | User ID of the application.|
| begin_time | number | Begin time of a task in the main thread.|
| end_time | number | End time of a task in the main thread.|
| external_log| string[] | Path of the generated log files. If the directory files exceed the threshold (for details, see **log_over_limit**), new log files may fail to be written. Therefore, delete the log files immediately after they are processed.|
| log_over_limit| boolean | Whether the size of generated log files and existing log files exceeds the upper limit (10 MB). The value **true** indicates that the upper limit is exceeded and logs fail to be written. The value **false** indicates that the upper limit is not exceeded.|
