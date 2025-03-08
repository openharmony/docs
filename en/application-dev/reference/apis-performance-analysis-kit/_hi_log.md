# HiLog


## Overview

Provides logging functions.

For example, you can use logging functions to output logs of the specified log type, service domain, log tag, and log level.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Since**: 8


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [log.h](log_8h.md) | Defines the logging functions of the HiLog module. | 


### Macros

| Name| Description| 
| -------- | -------- |
| [LOG_DOMAIN](#log_domain)&nbsp;&nbsp;&nbsp;0 | Indicates the service domain for a log file. | 
| [LOG_TAG](#log_tag)&nbsp;&nbsp;&nbsp;NULL | Indicates the string constant used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur. | 
| [OH_LOG_DEBUG](#oh_log_debug)(type, ...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](#oh_log_print)((type), LOG_DEBUG, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), __VA_ARGS__)) | Indicates DEBUG logs. This is a function-like macro. | 
| [OH_LOG_INFO](#oh_log_info)(type, ...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](#oh_log_print)((type), LOG_INFO, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), __VA_ARGS__)) | Indicates INFO logs. This is a function-like macro. | 
| [OH_LOG_WARN](#oh_log_warn)(type, ...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](#oh_log_print)((type), LOG_WARN, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), __VA_ARGS__)) | Indicates WARN logs. This is a function-like macro. | 
| [OH_LOG_ERROR](#oh_log_error)(type, ...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](#oh_log_print)((type), LOG_ERROR, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), __VA_ARGS__)) | Indicates ERROR logs. This is a function-like macro. | 
| [OH_LOG_FATAL](#oh_log_fatal)(type, ...)&nbsp;&nbsp;&nbsp;((void)HiLogPrint((type), LOG_FATAL, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), __VA_ARGS__)) | Indicates FATAL logs. This is a function-like macro. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef void(\* [LogCallback](#logcallback)) (const [LogType](#logtype) type, const [LogLevel](#loglevel) level, const unsigned int domain, const char \*tag, const char \*msg) | Defines a function for customizing the processing of logs in the callback. | 


### Enum

| Name| Description| 
| -------- | -------- |
| [LogType](#logtype) { LOG_APP = 0 } | Enumerates the log types. | 
| [LogLevel](#loglevel) {<br>LOG_DEBUG = 3, LOG_INFO = 4, LOG_WARN = 5, LOG_ERROR = 6,<br>LOG_FATAL = 7<br>} | Enumerates the log levels. | 


### Functions

| Name| Description| 
| -------- | -------- |
| int [OH_LOG_Print](#oh_log_print) ([LogType](#logtype) type, [LogLevel](#loglevel) level, unsigned int domain, const char \*tag, const char \*fmt,...) __attribute__((__format__(os_log | Outputs logs. | 
| int bool [OH_LOG_IsLoggable](#oh_log_isloggable) (unsigned int domain, const char \*tag, [LogLevel](#loglevel) level) | Checks whether logs of the specified service domain, tag, and level can be printed. | 
| void [OH_LOG_SetCallback](#oh_log_setcallback) ([LogCallback](#logcallback) callback) | Registers a callback function. | 
| void [OH_LOG_SetMinLogLevel](#oh_log_setminloglevel) ([LogLevel](#loglevel) level) | Sets the minimum log level. When a process prints logs, both the minimum log level and global log level are verified.<br>Therefore, the minimum log level cannot be lower than the global log level. The default [global log level](../../dfx/hilog.md#displaying-and-setting-log-levels) is **Info**.| 
| int [OH_LOG_PrintMsg](#oh_log_printmsg) ([LogType](#logtype) type, [LogLevel](#loglevel) level, unsigned int domain, const char \*tag, const char \*message) | Outputs logs. Outputs constant log strings of the specified **type**, **level**, **domain**, and **tag**. | 
| int [OH_LOG_PrintMsgByLen](#oh_log_printmsgbylen) ([LogType](#logtype) type, [LogLevel](#loglevel) level, unsigned int domain, const char \*tag, size_t tagLen, const char \*message, size_t messageLen) |  Outputs constant log strings of the specified **domain**, **tag**, and **level**. The tag and string length must be specified. Unlike **OH_LOG_PrintMsg**, this API allows strings without terminators. | 
| int [OH_LOG_VPrint](#oh_log_vprint)(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, va_list ap) | - |  Outputs logs of the specified **type**, **level**, **domain**, **tag**, and variables determined by the format specifier and privacy identifier in the printf format. The variables are of the **va_list** type.|


## Macro Description


### LOG_DOMAIN

```
#define LOG_DOMAIN   0
```
**Description**
Indicates the service domain for a log file.

Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed.

**Since**: 8


### LOG_TAG

```
#define LOG_TAG   NULL
```
**Description**
Indicates the string constant used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.

**Since**: 8


### OH_LOG_DEBUG

```
#define OH_LOG_DEBUG( type,  ... )   ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```
**Description**
Indicates DEBUG logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**. | 
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter. | 
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string. | 

**See**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_ERROR

```
#define OH_LOG_ERROR( type,  ... )   ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```
**Description**
Indicates ERROR logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**. | 
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter. | 
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string. | 

**See**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_FATAL

```
#define OH_LOG_FATAL( type,  ... )   ((void)HiLogPrint((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```
**Description**
Indicates FATAL logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**. | 
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter. | 
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string. | 

**See**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_INFO

```
#define OH_LOG_INFO( type,  ... )   ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```
**Description**
Outputs INFO logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**. | 
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter. | 
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string. | 

**See**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_WARN

```
#define OH_LOG_WARN( type,  ... )   ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```
**Description**
Indicates WARN logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**. | 
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter. | 
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string. | 

**See**

[OH_LOG_Print](#oh_log_print)


## Type Description


### LogCallback

```
typedef void(* LogCallback) (const LogType type, const LogLevel level, const unsigned int domain, const char *tag, const char *msg)
```
**Description**
Defines a function for customizing the processing of logs in the callback.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**. | 
| level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**. | 
| domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed. | 
| tag | Log tag, which is a string used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur. | 
| msg | Log content, which is made up of formatted log strings. | 


## Enum Description


### LogLevel

```
enum LogLevel
```
**Description**
Enumerates the log levels.

You are advised to select log levels based on their respective use cases. Log levels:

**DEBUG**: provides more detailed process information than INFO logs to help developers analyze service processes and locate faults. DEBUG logs are not recorded in official versions by default. They are available in debug versions or in official versions with the debug function enabled.

**INFO**: indicates the key service process nodes and exceptions (for example, no network signal or login failure) that occur during service running. These logs should be recorded by the dominant module in the service to avoid repeated logging conducted by multiple invoked modules or low-level functions.

**WARN**: indicates a severe, unexpected fault that has little impact on users and can be rectified by the programs themselves or through simple operations.

**ERROR**: indicates a program or functional error that affects the normal running or use of the functionality and can be fixed at a high cost, for example, by resetting data.

**FATAL**: indicates that a program or functionality is about to crash and the fault cannot be rectified.

**Since**: 8

| Value| Description| 
| -------- | -------- |
| LOG_DEBUG  | DEBUG level to be used by **OH_LOG_DEBUG**.&nbsp;&nbsp; | 
| LOG_INFO  | INFO level to be used by **OH_LOG_INFO**.&nbsp;&nbsp; | 
| LOG_WARN  | WARN level to be used by **OH_LOG_WARN**.&nbsp;&nbsp; | 
| LOG_ERROR  | ERROR level to be used by **OH_LOG_ERROR**.&nbsp;&nbsp; | 
| LOG_FATAL  | FATAL level to be used by **OH_LOG_FATAL**.&nbsp;&nbsp; | 


### LogType

```
enum LogType
```
**Description**
Enumerates the log types.

You can use this function to specify the type of output logs. Currently, only **LOG_APP** is available.

**Since**: 8

| Value| Description| 
| -------- | -------- |
| LOG_APP  | Application log.| 


## Function Description


### OH_LOG_IsLoggable()

```
int bool OH_LOG_IsLoggable (unsigned int domain, const char * tag, LogLevel level )
```
**Description**
Checks whether logs of the specified service domain, tag, and level can be printed.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| domain | Service domain. | 
| tag | Log tag. | 
| level | Log level. | 

**Returns**

**true** if the specified logs can be output; **false** otherwise.


### OH_LOG_Print()

```
int OH_LOG_Print (LogType type, LogLevel level, unsigned int domain, const char * tag, const char * fmt,  ... )
```
**Description**
 

Outputs logs of the specified **type**, **level**, **domain**, **tag**, and variables determined by the format specifier and privacy identifier in the printf format.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**. | 
| level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**. | 
| domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed. | 
| tag | Log tag, which is a string used to identify the class or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur. | 
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter. | 
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string. | 

**Returns**

**0** or a larger value if the operation is successful; a value smaller than **0** otherwise.


### OH_LOG_PrintMsg()

```
int OH_LOG_PrintMsg (LogType type, LogLevel level, unsigned int domain, const char * tag, const char * message )
```
**Description**
 Outputs constant log strings of the specified **type**, **level**, **domain**, and **tag**.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**. | 
| level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**. | 
| domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed. | 
| tag | Log tag, which is a string used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur. | 
| message | Constant log string. | 

**Returns**

**0** or a larger value if the operation is successful; a value smaller than **0** otherwise.


### OH_LOG_PrintMsgByLen()

```
int OH_LOG_PrintMsgByLen (LogType type, LogLevel level, unsigned int domain, const char * tag, size_t tagLen, const char * message, size_t messageLen )
```
**Description**
 Outputs log constant strings of the specified **domain**, **tag**, and **level**. The tag and string length must be specified. Unlike **OH_LOG_PrintMsg**, this API allows strings without terminators.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**. | 
| level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**. | 
| domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed. | 
| tag | Log tag, which is a string used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur. | 
| tagLen | Length of the tag. | 
| message | Constant log string. | 
| messageLen | Length of the constant string, which is less than 3500 characters. | 

**Returns**

**0** or a larger value if the operation is successful; a value smaller than **0** otherwise.

### OH_LOG_VPrint()

```
int OH_LOG_VPrint(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, va_list ap)
```

**Description**

 Outputs logs of the specified **type**, **level**, **domain**, **tag**, and variables determined by the format specifier and privacy identifier in the printf format. The variables are of the **va_list** type.

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| LogType type | Log type. The type for third-party applications is defined by **LOG_APP**.|
| LogLevel level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**.|
| unsigned int domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF.|
| const char *tag | Log tag, which is a string used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| const char *fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.|
| va_list ap | Parameter list of the **va_list** type that corresponds to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.|

**Returns**

| Type| Description|
| -- | -- |
| int | **0** or a larger value if the operation is successful; a value smaller than **0** otherwise.|

### OH_LOG_SetCallback()

```
void OH_LOG_SetCallback (LogCallback callback)
```
**Description**
Registers a callback function.

After this function is called, the customized callback can take over all logs of the current process.

Note that whether this API is called or not, it does not change the default log processing of the current process.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Custom callback function. If processing of logs is not needed, a null pointer can be transferred. | 


### OH_LOG_SetMinLogLevel()

```
void OH_LOG_SetMinLogLevel (LogLevel level)
```
**Description**
Sets the minimum log level. When a process prints logs, both the minimum log level and global log level are verified.

Therefore, the minimum log level cannot be lower than the global log level. The default [global log level](../../dfx/hilog.md#displaying-and-setting-log-levels) is **Info**.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| level | Log level. | 
