# HiLog Development
## Introduction
HiLog is the log system of OpenHarmony that provides logging for the system framework, services, and applications to record information on user operations and system running status.
> **NOTE**
> This development guide is applicable only when you use Native APIs for application development. For details about the APIs, see [HiLog Native API Reference](../reference/native-apis/_hi_log.md).

## Available APIs
| API/Macro| Description| 
| -------- | -------- |
| int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...) | Outputs logs based on the specified log type, log level, service domain, log tag, and variable parameters determined by the format specifier and privacy identifier in the printf format.| 
| #define OH_LOG_DEBUG(type, ...) ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, \_*VA*ARGS__))| Outputs DEBUG logs. This is a function-like macro.| 
| #define OH_LOG_INFO(type, ...) ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, \_*VA*ARGS__)) | Outputs INFO logs. This is a function-like macro.| 
| #define OH_LOG_WARN(type, ...) ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, \_*VA*ARGS__)) | Outputs WARN logs. This is a function-like macro.| 
| #define OH_LOG_ERROR(type, ...) ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, \_*VA*ARGS__)) | Outputs ERROR logs. This is a function-like macro.| 
| #define OH_LOG_FATAL(type, ...) ((void)OH_LOG_Print((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, \_*VA*ARGS__)) | Outputs FATAL logs. This is a function-like macro.| 
| bool OH_LOG_IsLoggable(unsigned int domain, const char *tag, LogLevel level) | Checks whether logs of the specified service domain, tag, and level can be printed.<br>Input arguments:<br>- **domain**: service domain.<br>- **tag**: log tag.<br>- **level**: log level.<br>Output arguments: none<br>Return value: Returns **true** if the specified logs can be printed; returns **false** otherwise.| 

## Development Examples
1. Include the **hilog** header file in the source file.
```c++
#include "hilog/log.h"
```
2. Define the **domain** and **tag** macros.
```c++
#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x3200 // Service domain. The value ranges from 0xD0000 to 0xDFFFF.
#define LOG_TAG "MY_TAG"
```
3. Print logs. For example, to print INFO logs, use the following code:
```c++
OH_LOG_INFO(LOG_APP, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
```
4. View the output log information.
```
12-11 12:21:47.579  2695 2695 I A03200/MY_TAG: Failed to visit <private>, reason:11.
```
