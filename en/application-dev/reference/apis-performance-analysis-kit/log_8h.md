# log.h


## Overview

Defines the logging functions of the HiLog module.

Before outputting logs, you must define the service domain, and log tag, use the function with the specified log type and level, and specify the privacy identifier.

**Log domain**: service domain of logs. You can define the value as required. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF.

**Log tag**: a string used to identify the class, file, or service behavior.

**Log level**: DEBUG, INFO, WARN, ERROR, or FATAL.

**Parameter format**: printf format string, which starts with a % character, including a parameter type identifier and a variable parameter.

**Privacy identifier**: **{public}** or **{private}** added between the % character and the parameter type identifier in each parameter.
 If no privacy identifier is added, the parameter is considered to be **private**.

Example

Define the service domain and tag:

```
#define LOG_DOMAIN 0x0201
#define LOG_TAG "MY_TAG"
```

Print the log:

```
HILOG_WARN(LOG_APP, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
```

Output:

```
05-06 15:01:06.870 1051 1051 W 0201/MY_TAG: Failed to visit <private>, reason:503.
```

**File to include**: <hilog/log.h>

**Since**: 8

**Related module**: [HiLog](_hi_log.md)


## Summary


### Macros

| Name| Description| 
| -------- | -------- |
| [LOG_DOMAIN](_hi_log.md#log_domain)&nbsp;&nbsp;&nbsp;0 | Indicates the service domain for a log file.| 
| [LOG_TAG](_hi_log.md#log_tag)&nbsp;&nbsp;&nbsp;NULL | Indicates the string constant used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur. | 
| [OH_LOG_DEBUG](_hi_log.md#oh_log_debug)(type, ...)&nbsp;&nbsp;&nbsp;((void) [OH_LOG_Print](_hi_log.md#oh_log_print)((type), [LOG_DEBUG](_hi_log.md), [LOG_DOMAIN](_hi_log.md#log_domain), [LOG_TAG](_hi_log.md#log_tag), \_\_VA_ARGS\_\_)) | Indicates DEBUG logs. This is a function-like macro.| 
| [OH_LOG_INFO](_hi_log.md#oh_log_info)(type, ...)&nbsp;&nbsp;&nbsp;((void) [OH_LOG_Print](_hi_log.md#oh_log_print)((type), [LOG_INFO](_hi_log.md), [LOG_DOMAIN](_hi_log.md#log_domain), [LOG_TAG](_hi_log.md#log_tag), \_\_VA_ARGS\_\_)) | Indicates INFO logs. This is a function-like macro.| 
| [OH_LOG_WARN](_hi_log.md#oh_log_warn)(type, ...)&nbsp;&nbsp;&nbsp;((void) [OH_LOG_Print](_hi_log.md#oh_log_print)((type), [LOG_WARN](_hi_log.md), [LOG_DOMAIN](_hi_log.md#log_domain), [LOG_TAG](_hi_log.md#log_tag), \_\_VA_ARGS\_\_)) | Indicates WARN logs. This is a function-like macro.| 
| [OH_LOG_ERROR](_hi_log.md#oh_log_error)(type, ...)&nbsp;&nbsp;&nbsp;((void) [OH_LOG_Print](_hi_log.md#oh_log_print)((type), [LOG_ERROR](_hi_log.md), [LOG_DOMAIN](_hi_log.md#log_domain), [LOG_TAG](_hi_log.md#log_tag), \_\_VA_ARGS\_\_)) | Indicates ERROR logs. This is a function-like macro.| 
| [OH_LOG_FATAL](_hi_log.md#oh_log_fatal)(type, ...)&nbsp;&nbsp;&nbsp;((void)HiLogPrint((type), [LOG_FATAL](_hi_log.md), [LOG_DOMAIN](_hi_log.md#log_domain), [LOG_TAG](_hi_log.md#log_tag), \_\_VA_ARGS\_\_)) | Indicates FATAL logs. This is a function-like macro.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef void(\* [LogCallback](_hi_log.md#logcallback)) (const [LogType](_hi_log.md#logtype) type, const [LogLevel](_hi_log.md#loglevel) level, const unsigned int domain, const char \*tag, const char \*msg) | Defines a function for customizing the processing of logs in the callback. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [LogType](_hi_log.md#logtype) { LOG_APP = 0 } | Enumerates the log types. | 
| [LogLevel](_hi_log.md#loglevel) {<br>LOG_DEBUG = 3,<br>LOG_INFO = 4,<br>LOG_WARN = 5,<br>LOG_ERROR = 6,<br>LOG_FATAL = 7<br>} | Enumerates the log levels. | 


### Functions

| Name| Description| 
| -------- | -------- |
| int [OH_LOG_Print](_hi_log.md#oh_log_print) ([LogType](_hi_log.md#logtype) type, [LogLevel](_hi_log.md#loglevel) level, unsigned int domain, const char \*tag, const char \*fmt,...) __attribute__((__format__(os_log | Outputs logs. | 
| int bool [OH_LOG_IsLoggable](_hi_log.md#oh_log_isloggable) (unsigned int domain, const char \*tag, [LogLevel](_hi_log.md#loglevel) level) | Checks whether logs of the specified service domain, tag, and level can be printed. | 
| void [OH_LOG_SetCallback](_hi_log.md#oh_log_setcallback) ([LogCallback](_hi_log.md#logcallback) callback) | Registers a callback function. | 
| void [OH_LOG_SetMinLogLevel](_hi_log.md#oh_log_setminloglevel) ([LogLevel](_hi_log.md#loglevel) level) | Sets the minimum log level. When a process prints logs, both the minimum log level and global log level are verified.<br>Therefore, the minimum log level cannot be lower than the global log level. The default [global log level](../../dfx/hilog.md#displaying-and-setting-log-levels) is **Info**.| 
| int [OH_LOG_PrintMsg](_hi_log.md#oh_log_printmsg) ([LogType](_hi_log.md#logtype) type, [LogLevel](_hi_log.md#loglevel) level, unsigned int domain, const char \*tag, const char \*message) | Outputs constant log strings of the specified **type**, **level**, **domain**, and **tag**. | 
| int [OH_LOG_PrintMsgByLen](_hi_log.md#oh_log_printmsgbylen) ([LogType](_hi_log.md#logtype) type, [LogLevel](_hi_log.md#loglevel) level, unsigned int domain, const char \*tag, size_t tagLen, const char \*message, size_t messageLen) | Outputs constant log strings of the specified **domain**, **tag**, and **level**. The tag and string length must be specified. Unlike **OH_LOG_PrintMsg**, this API allows strings without terminators. | 
| int [OH_LOG_VPrint](_hi_log.md#oh_log_vprint)(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, va_list ap) | - |  Outputs logs of specified **type**, **level**, **domain**, **tag**, and variables determined by the format specifier and privacy identifier in the printf format. The variables are of the **va_list** type.|
