# Crash Event Overview

HiAppEvent provides APIs for subscribing to crash events.

- [Subscribing to Crash Events (ArkTS)](hiappevent-watcher-crash-events-arkts.md)
- [Subscribing to Crash Events (C/C++)](hiappevent-watcher-crash-events-ndk.md)

The **params** parameter in the event information is described as follows.

**params**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| time     | number | Event triggering time, in ms.|
| crash_type | string | Crash type, which can be JsError or NativeCrash.|
| foreground | boolean | Whether the application is running in the foreground.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of the application.|
| uid | number | User ID of the application.|
| uuid | string | Error ID.|
| exception | object | Exception information. For details, see **exception**. <br>For details about the NativeCrash events, see **exception (NativeCrash)**. **exception** contains only brief fault information. For details, see the **external_log** file.|
| hilog | string[] | Log information. A maximum of 100 lines of HiLog information can be displayed. More logs can be obtained from the error log file.|
| threads | object[] | Full thread call stack. For details, see **thread**. This field applies only to NativeCrash events.|
| external_log<sup>12+</sup> | string[] | Path of the error log file. Error log files include **CPPCRASH** and **JSERROR**. You can use them for [Analyzing CPP Crash](cppcrash-guidelines.md) and [Analyzing JS Crash](jscrash-guidelines.md). If the directory files exceed the threshold (for details, see **log_over_limit**), new log files may fail to be written. Therefore, delete the log files immediately after they are processed.|
| log_over_limit<sup>12+</sup> | boolean | Whether the size of generated fault log files and existing log files exceeds the upper limit (5 MB). The value **true** indicates that the upper limit is exceeded and logs fail to be written. The value **false** indicates that the upper limit is not exceeded.|

**exception**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| name | string | Exception type.|
| message | string | Exception cause.|
| stack | string | Exception call stack.|

**exception (NativeCrash)**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| message | string | Exception cause.|
| signal | object | Signal information. For details, see **signal**.|
| thread_name | string | Thread name.|
| tid | number | Thread ID.|
| frames | object[] | Thread call stack. For details, see **frame**.|

**signal**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| signo | number | Signal value (**si_signo** in **siginfo_t**)|
| code | number | Level-2 classification of signal values (**si_code** in **siginfo_t**)|
| address | string | Signal error address (**si_address** attribute in **siginfo_t**)|

[Signal Value & Level-2 Classification of Signal Values](cppcrash-guidelines.md)

**thread**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| thread_name | string | Thread name.|
| tid | number | Thread ID.|
| frames | object[] | Thread call stack. For details, see **frame**.|

**frame (native)**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| file | string | File name.|
| symbol | string | Function name. When the length of a function name exceeds 256 bytes, the stack frame does not contain the function name.|
| buildId | string | Unique file ID. If the ELF file does not contain **.note.gnu.build-id**, the stack frame does not contain the **build-id** information.|
| pc | string | PC register address.|
| offset | number | Function offset.|

**frame (JS)**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| file | string | File name.|
| packageName | string | Package name of the module.|
| symbol | string | Function name.|
| column | number | The column where an exception occurs.|
| line | number | The line where an exception occurs.|
