# log.h


## Overview

Defines the logging functions of the HiLog module.

Before outputting logs, you must define the service domain, and log tag, use the function with the specified log type and level, and specify the privacy identifier.

Service domain: service domain of logs. You can define the value as required. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF.

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

**Since**

8

**Related module**

[HiLog](_hi_log.md)


## Summary


### Macros

| Name| Description|
| -------- | -------- |
| [LOG_DOMAIN](_hi_log.md#log_domain)   0 | Defines the service domain for a log file.|
| [LOG_TAG](_hi_log.md#log_tag)   NULL | Defines a string constant used to identify the class, file, or service.|
| [OH_LOG_DEBUG](_hi_log.md#oh_log_debug)(type, ...)   ((void)[OH_LOG_Print](_hi_log.md#oh_log_print)((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, \_\_VA\_ARGS\_\_)) | Outputs DEBUG logs. This is a function-like macro.|
| [OH_LOG_INFO](_hi_log.md#oh_log_info)(type, ...)   ((void)[OH_LOG_Print](_hi_log.md#oh_log_print)((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, \_\_VA\_ARGS\_\_)) | Outputs INFO logs. This is a function-like macro.|
| [OH_LOG_WARN](_hi_log.md#oh_log_warn)(type, ...)   ((void)[OH_LOG_Print](_hi_log.md#oh_log_print)((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, \_\_VA\_ARGS\_\_)) | Outputs WARN logs. This is a function-like macro.|
| [OH_LOG_ERROR](_hi_log.md#oh_log_error)(type, ...)   ((void)[OH_LOG_Print](_hi_log.md#oh_log_print)((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, \_\_VA\_ARGS\_\_)) | Outputs ERROR logs. This is a function-like macro.|
| [OH_LOG_FATAL](_hi_log.md#oh_log_fatal)(type, ...)   ((void)HiLogPrint((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, \_\_VA\_ARGS\_\_)) | Outputs FATAL logs. This is a function-like macro.|


### Enums

| Name| Description|
| -------- | -------- |
| [LogType](_hi_log.md#logtype) { LOG_APP= 0 } | Log type.|
| [LogLevel](_hi_log.md#loglevel) { LOG_DEBUG = 3, LOG_INFO = 4, LOG_WARN = 5, LOG_ERROR = 6, LOG_FATAL =7 } | Log level.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_LOG_Print](_hi_log.md#oh_log_print) ([LogType](_hi_log.md#logtype) type, [LogLevel](_hi_log.md#loglevel) level, unsigned int domain, const char \*tag, const char \*fmt,...) \_\_attribute__((\_\_format__(os_log, 5, 6))) | Outputs logs.|
| [OH_LOG_IsLoggable](_hi_log.md#oh_log_isloggable) (unsigned int domain, const char \*tag, [LogLevel](_hi_log.md#loglevel) level) | Checks whether logs of the specified service domain, tag, and level can be printed.|
