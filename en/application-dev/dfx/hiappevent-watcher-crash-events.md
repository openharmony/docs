# Crash Event Overview

## Overview

Crash is an unexpected exit of an application process. Specifically, crash events occur in the following scenarios:

1. The native code does not process [C++ crash signals](cppcrash-guidelines.md#c-crash-signals).
2. The JS/ArkTS code does process exceptions.

The following describes the meanings and specifications of fields in crash events. For details about how to use the ArkTs and C/C++ APIs provided by HiAppEvent to subscribe to system crash events, see the following documents:  

- [Subscribing to Crash Events (ArkTS)](hiappevent-watcher-crash-events-arkts.md)
- [Subscribing to Crash Events (C/C++)](hiappevent-watcher-crash-events-ndk.md)

## Fields

### params

The **params** parameter in the event information is described as follows.

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| time     | number | Event triggering time, in ms.|
| crash_type | string | Crash type, which can be NativeCrash (native exception) or JsError (JS exception). For details about problem analysis, see [Analyzing C++ Crash](cppcrash-guidelines.md) and [Analyzing JS Crash](jscrash-guidelines.md).|
| foreground | boolean | Whether the application is running in the foreground. The value **true** indicates that the application is in the foreground, and the value **false** indicates the opposite.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of an application.|
| uid | number | User ID of an application.|
| uuid | string | Error ID, which is generated based on fault information and uniquely identifies crash faults of the same type.|
| exception | object | Exception information in brief. For details, see [exception](#exception). For details about all fault information, see the **external_log** file.|
| hilog | string[] | Log information, which displays a maximum of 100 lines of HiLog logs. For more logs, see the fault log file.|
| threads | object[] | Full thread call stack. For details, see [thread](#thread). This field applies only to NativeCrash events.|
| external_log<sup>12+</sup> | string[] | Path of the error log file. To avoid failed writing of new log files due to insufficient directory space, delete the log files after they are processed. For details about the threshold, see the **log_over_limit** field.|
| log_over_limit<sup>12+</sup> | boolean | Whether the size of generated fault log files and existing log files exceeds the upper limit (5 MB). The value **true** indicates that the upper limit is exceeded and logs fail to be written. The value **false** indicates that the upper limit is not exceeded.|

### exception

#### exception of JsError

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| name | string | Exception type.|
| message | string | Exception cause.|
| stack | string | Exception call stack.|

#### exception of NativeCrash

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| message | string | Exception cause.|
| signal | object | Signal information. For details, see [signal](#signal).|
| thread_name | string | Thread name.|
| tid | number | Thread ID.|
| frames | object[] | Thread call stack. For details, see [frame](#frame).|

### signal

For details about the signals, see [C++ Crash Signals](cppcrash-guidelines.md#c-crash-signals).

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| signo | number | Signal value.|
| code | number | Level-2 signal category.|
| address | string | Address where an access error occurs.|

### thread

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| thread_name | string | Thread name.|
| tid | number | Thread ID.|
| frames | object[] | Thread call stack. For details, see [frame](#frame).|

### frame

#### Native frame

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| file | string | File name. It may also be anonymous memory mapping, such as [heap] and [stack].|
| symbol | string | Function name. If the name length exceeds 256 bytes, the name is deleted to prevent unknown issues.|
| buildId | string | Unique file ID. A file may not contain **buildId**. For details, see [C++ Crash Logs](cppcrash-guidelines.md#c-crash-signals).|
| pc | string | Number of offset bytes in a file.|
| offset | number | Number of offset bytes in a function.|

#### JS frame

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| file | string | File name.|
| packageName | string | Module package name.|
| symbol | string | Function name.|
| line | number | Line number of the exception code.|
| column | number | Column number of the exception code.|
