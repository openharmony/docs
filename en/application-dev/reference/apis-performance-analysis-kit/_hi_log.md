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
| [log.h](log_8h.md) | Defines the logging functions of the HiLog module.<br>**File to include**: <hilog/log.h><br>**Library**: libhilog_ndk.z.so|


### Macros

| Name| Description| 
| -------- | -------- |
| [LOG_DOMAIN](#log_domain)&nbsp;&nbsp;&nbsp;0 | Defines the service domain for a log file.| 
| [LOG_TAG](#log_tag)&nbsp;&nbsp;&nbsp;NULL | Defines a string constant used to identify the class, file, or service.| 
| [OH_LOG_DEBUG](#oh_log_debug)(type, ...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](#oh_log_print)((type), LOG_DEBUG, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), \_\_VA_ARGS\_\_)) | Outputs DEBUG logs. This is a function-like macro.| 
| [OH_LOG_INFO](#oh_log_info)(type, ...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](#oh_log_print)((type), LOG_INFO, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), \_\_VA_ARGS\_\_)) | Outputs INFO logs. This is a function-like macro.| 
| [OH_LOG_WARN](#oh_log_warn)(type, ...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](#oh_log_print)((type), LOG_WARN, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), \_\_VA_ARGS\_\_)) | Outputs WARN logs. This is a function-like macro.| 
| [OH_LOG_ERROR](#oh_log_error)(type, ...)&nbsp;&nbsp;&nbsp;((void)[OH_LOG_Print](#oh_log_print)((type), LOG_ERROR, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), \_\_VA_ARGS\_\_)) | Outputs ERROR logs. This is a function-like macro.| 
| [OH_LOG_FATAL](#oh_log_fatal)(type, ...)&nbsp;&nbsp;&nbsp;((void)HiLogPrint((type), LOG_FATAL, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), \_\_VA_ARGS\_\_)) | Outputs FATAL logs. This is a function-like macro.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef void(\* [LogCallback](#logcallback)) (const [LogType](#logtype) type, const [LogLevel](#loglevel) level, const unsigned int domain, const char \*tag, const char \*msg) | Pointer to the callback function. You can customize the processing of logs in the callback.| 


### Enum

| Name| Description| 
| -------- | -------- |
| [LogType](#logtype) { LOG_APP = 0 } | **Log Type**| 
| [LogLevel](#loglevel) {<br>LOG_DEBUG = 3,<br>LOG_INFO = 4,<br>LOG_WARN = 5,<br>LOG_ERROR = 6,<br>LOG_FATAL = 7<br>} | Log level.| 


### Functions

| Name| Description| 
| -------- | -------- |
| int [OH_LOG_Print](#oh_log_print) ([LogType](#logtype) type, [LogLevel](#loglevel) level, unsigned int domain, const char \*tag, const char \*fmt,...) \_\_attribute\_\_((\_\_format\_\_(os_log | Outputs logs.| 
| int bool [OH_LOG_IsLoggable](#oh_log_isloggable) (unsigned int domain, const char \*tag, [LogLevel](#loglevel) level) | Checks whether logs of the specified service domain, tag, and level can be printed.| 
| void [OH_LOG_SetCallback](#oh_log_setcallback) ([LogCallback](#logcallback) callback) | Registers a callback function.| 


## Macro Description


### LOG_DOMAIN

```
#define LOG_DOMAIN   0
```

**Description**

Defines the service domain for a log file.

The service domain is used to identify the subsystem and module of a service. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value is beyond the range, its significant bits are automatically truncated.

**Since**: 8


### LOG_TAG

```
#define LOG_TAG   NULL
```

**Description**

Defines a string constant used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.

**Since**: 8


### OH_LOG_DEBUG

```
#define OH_LOG_DEBUG( type,  ... )   ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description**

Outputs DEBUG logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**.| 
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.| 
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.| 

**See**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_ERROR

```
#define OH_LOG_ERROR( type,  ... )   ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description**

Outputs ERROR logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**.| 
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.| 
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.| 

**See**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_FATAL

```
#define OH_LOG_FATAL( type,  ... )   ((void)HiLogPrint((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description**

Outputs FATAL logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**.| 
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.| 
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.| 

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
| type | Log type. The type for third-party applications is defined by **LOG_APP**.| 
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.| 
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.| 

**See**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_WARN

```
#define OH_LOG_WARN( type,  ... )   ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description**

Outputs WARN logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**.| 
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.| 
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.| 

**See**

[OH_LOG_Print](#oh_log_print)


## Type Description


### LogCallback

```
typedef void(* LogCallback) (const LogType type, const LogLevel level, const unsigned int domain, const char *tag, const char *msg)
```

**Description**

Pointer to the callback function. You can customize the processing of logs in the callback.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**.| 
| level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**.| 
| domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF.| 
| tag | Log tag, which is a string used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.| 
| msg | Log content, which is made up of formatted log strings.| 


## Enum Description


### LogLevel

```
enum LogLevel
```

**Description**

Log level.

You are advised to select log levels based on their respective use cases. Log levels:

**DEBUG**: provides more detailed process information than INFO logs to help developers analyze service processes and locate faults. DEBUG logs are not recorded in official versions by default. They are available in debug versions or in official versions with the debug function enabled.

**INFO**: indicates the key service process nodes and exceptions (for example, no network signal or login failure) that occur during service running. These logs should be recorded by the dominant module in the service to avoid repeated logging conducted by multiple invoked modules or low-level functions.

**WARN**: indicates a severe, unexpected fault that has little impact on users and can be rectified by the programs themselves or through simple operations.

**ERROR**: indicates a program or functional error that affects the normal running or use of the functionality and can be fixed at a high cost, for example, by resetting data.

**FATAL**: indicates that a program or functionality is about to crash and the fault cannot be rectified.

**Since**: 8

| Value| Description| 
| -------- | -------- |
| LOG_DEBUG | DEBUG level to be used by **OH_LOG_DEBUG**.| 
| LOG_INFO | INFO level to be used by **OH_LOG_INFO**.| 
| LOG_WARN | WARN level to be used by **OH_LOG_WARN**.| 
| LOG_ERROR | ERROR level to be used by **OH_LOG_ERROR**.| 
| LOG_FATAL | FATAL level to be used by **OH_LOG_FATAL**.| 


### LogType

```
enum LogType
```

**Description**

**Log Type**

You can use this function to specify the type of output logs. Currently, only **LOG_APP** is available.

**Since**: 8

| Value| Description| 
| -------- | -------- |
| LOG_APP | Application log.| 


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
| domain | Service domain.| 
| tag | Log tag.| 
| level | Log level.| 

**Returns**

**true** if the specified logs can be output; **false** otherwise.


### OH_LOG_Print()

```
int OH_LOG_Print (LogType type, LogLevel level, unsigned int domain, const char * tag, const char * fmt,  ... )
```

**Description**

Outputs logs.

You can use this function to output logs based on the specified log type, log level, service domain, log tag, and variable parameters determined by the format specifier and privacy identifier in the printf format.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**.| 
| level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**.| 
| domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF.| 
| tag | Log tag, which is a string used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.| 
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.| 
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.| 

**Returns**

**0** or a larger value if the operation is successful; a value smaller than **0** otherwise.


### OH_LOG_SetCallback()

```
void OH_LOG_SetCallback (LogCallback callback)
```

**Description**

Registers a callback function.

After this function is called, the customized callback can take over all logs of the current process. Note that whether this API is called or not, it does not change the default log processing of the current process.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Custom callback function. If processing of logs is not needed, a null pointer can be transferred.| 
