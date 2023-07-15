# HiLog Development (Native)
 
## Introduction

HiLog is the log system of OpenHarmony that provides logging for the system framework, services, and applications to record information on user operations and system running status.

> **NOTE**
> 
> This development guide is applicable only when you use Native APIs for application development. For details about the APIs, see [HiLog Native API Reference](../reference/native-apis/_hi_log.md).

## Available APIs

| API/Macro| Description| 
| -------- | -------- |
| int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...) | Outputs logs based on the specified log type, log level, service domain, log tag, and variable parameters determined by the format specifier and privacy identifier in the printf format.<br>Input arguments: See [Parameter Description](#parameter-description).<br>Output arguments: None<br>Return value: total number of bytes if log printing is successful; **-1** otherwise.| 
| #define OH_LOG_DEBUG(type, ...) ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, \_*VA*ARGS__))| Outputs DEBUG logs. This is a function-like macro.| 
| #define OH_LOG_INFO(type, ...) ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, \_*VA*ARGS__)) | Outputs INFO logs. This is a function-like macro.| 
| #define OH_LOG_WARN(type, ...) ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, \_*VA*ARGS__)) | Outputs WARN logs. This is a function-like macro.| 
| #define OH_LOG_ERROR(type, ...) ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, \_*VA*ARGS__)) | Outputs ERROR logs. This is a function-like macro.| 
| #define OH_LOG_FATAL(type, ...) ((void)OH_LOG_Print((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, \_*VA*ARGS__)) | Outputs FATAL logs. This is a function-like macro.| 
| bool OH_LOG_IsLoggable(unsigned int domain, const char *tag, LogLevel level) | Checks whether logs of the specified service domain, tag, and level can be printed.<br>Input arguments: See [Parameter Description](#parameter-description).<br>Output arguments: none<br>Return value: **true** if the specified logs can be printed; **false** otherwise.|

## Parameter Description

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | enum   | Yes  | Log printing type. The default value is **LOG_APP** for application logs.|
| level  | enum   | Yes  | Log printing level. For details, see [Log Level](#loglevel).|
| domain | number | Yes  | Service domain of logs. The value ranges from **0x0** to **0xFFFF**.<br>You can define the value as required. |
| tag    | string | Yes  | Log tag in the string format. You are advised to use this parameter to identify a particular service behavior or the class holding the ongoing method.|
| fmt    | string | Yes  | Format string used to output logs in a specified format. It can contain several parameters, where the parameter type and privacy identifier are mandatory.<br>Parameters labeled **{public}** are public data and are displayed in plaintext; parameters labeled **{private}** (default value) are private data and are filtered by **\<private>**.|
| args   | any[]  | Yes  | Variable-length parameter list corresponding to the format string. The number and type of parameters must map to the identifier in the format string.|

## LogLevel

Log level.

| Name |   Value  | Description                                                        |
| ----- | ------ | ------------------------------------------------------------ |
| DEBUG | 3      | Log level used to record more detailed process information than INFO logs to help developers analyze service processes and locate faults.|
| INFO  | 4      | Log level used to record key service process nodes and exceptions that occur during service running as well as information about unexpected exceptions, such as network signal loss and login failure.<br>These logs should be recorded by the dominant module in the service to avoid repeated logging conducted by multiple invoked modules or low-level functions.|
| WARN  | 5      | Log level used to record severe, unexpected faults that have little impact on users and can be rectified by the programs themselves or through simple operations.|
| ERROR | 6      | Log level used to record program or functional errors that affect the normal running or use of the functionality and can be fixed at a high cost, for example, by resetting data.|
| FATAL | 7      | Log level used to record program or functionality crashes that cannot be rectified.

## Development Example

1. Add the link of **libhilog_ndk.z.so** to **CMakeLists.txt**:
```
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
2. Include the **hilog** header file in the source file, and define the **domain** and **tag** macros.
```c++
#include "hilog/log.h"
```

```c++
#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x3200 // Global domain, which identifies the service domain.
#define LOG_TAG "MY_TAG" // Global tag, which identifies the module log tag.
```
3. Print logs. For example, to print ERROR logs, use the following code:
```c++
OH_LOG_ERROR(LOG_APP, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
```
4. View the output log information.
```
12-11 12:21:47.579  2695 2695 E A03200/MY_TAG: Failed to visit <private>, reason:11.
```
