# log.h

## Overview

Defines the logging functions of the HiLog module. Before outputting logs, you must define the service domain, and log tag, use the API with the specified log type and level, and specify the privacy identifier.<br> **Service domain**: service domain of logs. You can define the value as required. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed.<br> **Log tag**: a string used to identify the class, file, or service behavior.<br> **Log level**: DEBUG, INFO, WARN, ERROR, or FATAL.<br> **Parameter format**: printf format string, which starts with a % character, including a parameter type identifier and a variable parameter.<br> **Privacy identifier**: **{public}** or **{private}** added between the % character and the parameter type identifier in each parameter. **Note**: If no privacy identifier is added, the parameter is considered to be **private**.

**Library**: libhilog.so

**System capability**: SystemCapability.HiviewDFX.HiLog

**Since**: 8

**Related module**: [HiLog](capi-hilog.md)

## Summary

### Enum

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [LogType](#logtype) | LogType | Enumerates the log types. You can use this function to specify the type of output logs. Currently, only **LOG_APP** is available.<br>|
| [LogLevel](#loglevel) | LogLevel | Enumerates the log levels. You are advised to select log levels based on their respective use cases. Log levels:<br> **DEBUG**: provides more detailed process information than INFO logs to help developers analyze service processes and locate faults. DEBUG logs are not recorded in official versions by default. They are available in debug versions or in official versions with the debug function enabled.<br> **INFO**: indicates the key service process nodes and exceptions (for example, no network signal or login failure) that occur during service running. These logs should be recorded by the dominant module in the service to avoid repeated logging conducted by multiple invoked modules or low-level functions.<br> **WARN**: indicates a severe, unexpected fault that has little impact on users and can be rectified by the programs themselves or through simple operations.<br> **ERROR**: indicates a program or functional error that affects the normal running or use of the functionality and can be fixed at a high cost, for example, by resetting data.<br> **FATAL**: indicates that a program or functionality is about to crash and the fault cannot be rectified.<br>|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...)](#oh_log_print) | - |  Outputs logs of the specified **type**, **level**, **domain**, **tag**, and variables determined by the format specifier and privacy identifier in the printf format.|
| [int OH_LOG_PrintMsg(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *message)](#oh_log_printmsg) | - |  Outputs constant log strings of the specified **type**, **level**, **domain**, and **tag**.|
| [int OH_LOG_PrintMsgByLen(LogType type, LogLevel level, unsigned int domain, const char *tag, size_t tagLen,const char *message, size_t messageLen)](#oh_log_printmsgbylen) | - |  Outputs log constant strings of the specified **domain**, **tag**, and **level**. The tag and string length must be specified. Unlike **OH_LOG_PrintMsg**, this API allows strings without terminators.|
| [int OH_LOG_VPrint(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, va_list ap)](#oh_log_vprint) | - |  Outputs logs of the specified **type**, **level**, **domain**, **tag**, and variables determined by the format specifier and privacy identifier in the printf format. The variables are of the **va_list** type.|
| [bool OH_LOG_IsLoggable(unsigned int domain, const char *tag, LogLevel level)](#oh_log_isloggable) | - | Checks whether logs of the specified service domain, tag, and level can be printed.|
| [OH_LOG_DEBUG(type, ...)((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))](#oh_log_debug) | - | Indicates DEBUG logs. This is a function-like macro. Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.<br>|
| [OH_LOG_INFO(type, ...)((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))](#oh_log_info) | - | Indicates INFO logs. This is a function-like macro. Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.<br>|
| [OH_LOG_WARN(type, ...)((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))](#oh_log_warn) | - | Indicates WARN logs. This is a function-like macro. Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.|
| [OH_LOG_ERROR(type, ...)((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))](#oh_log_error) | - | Indicates ERROR logs. This is a function-like macro. Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.|
| [OH_LOG_FATAL(type, ...)((void)OH_LOG_Print((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))](#oh_log_fatal) | - | Indicates FATAL logs. This is a function-like macro. Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.<br>|
| [typedef void (\*LogCallback)(const LogType type, const LogLevel level, const unsigned int domain, const char *tag,const char *msg)](#logcallback) | LogCallback | Defines a function for customizing the processing of logs in the callback.|
| [void OH_LOG_SetCallback(LogCallback callback)](#oh_log_setcallback) | - | Registers a callback function. After this function is called, the customized callback can take over all logs of the current process.<br> Note that whether this API is called or not, it does not change the default log processing of the current process.|
| [void OH_LOG_SetMinLogLevel(LogLevel level)](#oh_log_setminloglevel) | - | Sets the minimum log level. Note: If the set log level is lower than the [global log level](../../dfx/hilog.md#displaying-and-setting-log-levels), the setting does not take effect.|

## Enum Description

### LogType

```
enum LogType
```

**Description**

Enumerates the log types. You can use this function to specify the type of output logs. Currently, only **LOG_APP** is available.<br>

**Since**: 8

| Enum Item| Description|
| -- | -- |
| LOG_APP = 0 | Application log.|

### LogLevel

```
enum LogLevel
```

**Description**

Enumerates the log levels. You are advised to select log levels based on their respective use cases. Log levels:<br> **DEBUG**: provides more detailed process information than INFO logs to help developers analyze service processes and locate faults. DEBUG logs are not recorded in official versions by default. They are available in debug versions or in official versions with the debug function enabled.<br> **INFO**: indicates the key service process nodes and exceptions (for example, no network signal or login failure) that occur during service running. These logs should be recorded by the dominant module in the service to avoid repeated logging conducted by multiple invoked modules or low-level functions.<br> **WARN**: indicates a severe, unexpected fault that has little impact on users and can be rectified by the programs themselves or through simple operations.<br> **ERROR**: indicates a program or functional error that affects the normal running or use of the functionality and can be fixed at a high cost, for example, by resetting data.<br> **FATAL**: indicates that a program or functionality is about to crash and the fault cannot be rectified.<br>

**Since**: 8

| Enum Item| Description|
| -- | -- |
| LOG_DEBUG = 3 | DEBUG level to be used by **OH_LOG_DEBUG**.|
| LOG_INFO = 4 | INFO level to be used by **OH_LOG_INFO**.|
| LOG_WARN = 5 | WARN level to be used by **OH_LOG_WARN**.|
| LOG_ERROR = 6 | ERROR level to be used by **OH_LOG_ERROR**.|
| LOG_FATAL = 7 | FATAL level to be used by **OH_LOG_FATAL**.|


## Function Description

### OH_LOG_Print()

```
int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...)
```

**Description**

 Outputs logs of the specified **type**, **level**, **domain**, **tag**, and variables determined by the format specifier and privacy identifier in the printf format.

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [LogType](capi-log-h.md#logtype) type | Log type. The type for third-party applications is defined by **LOG_APP**.|
| [LogLevel](capi-log-h.md#loglevel) level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**.|
| unsigned int domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed.|
| const char *tag | Log tag, which is a string used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| const char *fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.|
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.|

**Returns**

| Type| Description|
| -- | -- |
| int | **0** or a larger value if the operation is successful; a value smaller than **0** otherwise.<br> Possible failure causes: The **LogLevel** passed in is lower than the allowed log level; the **domain** is out of range; the **tag** is a null pointer; the CPU is overloaded; the memory is insufficient; the number of logs on the device is too large.|

### OH_LOG_PrintMsg()

```
int OH_LOG_PrintMsg(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *message)
```

**Description**

 Outputs constant log strings of the specified **type**, **level**, **domain**, and **tag**.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [LogType](capi-log-h.md#logtype) type | Log type. The type for third-party applications is defined by **LOG_APP**.|
| [LogLevel](capi-log-h.md#loglevel) level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**.|
| unsigned int domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed.|
| const char *tag | Log tag, which is a string used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| const char *message | Constant log string.|

**Returns**

| Type| Description|
| -- | -- |
| int | **0** or a larger value if the operation is successful; a value smaller than **0** otherwise.<br> Possible failure causes: The **LogLevel** passed in is lower than the allowed log level; the **domain** is out of range; the **tag** is a null pointer; the CPU is overloaded; the memory is insufficient; the number of logs on the device is too large.|

### OH_LOG_PrintMsgByLen()

```
int OH_LOG_PrintMsgByLen(LogType type, LogLevel level, unsigned int domain, const char *tag, size_t tagLen,const char *message, size_t messageLen)
```

**Description**

 Outputs log constant strings of the specified **domain**, **tag**, and **level**. The tag and string length must be specified. Unlike **OH_LOG_PrintMsg**, this API allows strings without terminators.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [LogType](capi-log-h.md#logtype) type | Log type. The type for third-party applications is defined by **LOG_APP**.|
| [LogLevel](capi-log-h.md#loglevel) level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**.|
| unsigned int domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed.|
| const char *tag | Log tag, which is a string used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| size_t tagLen | Length of the tag.|
| const char *message | Constant log string.|
| size_t messageLen | Length of the constant string, which is less than 3500 characters.|

**Returns**

| Type| Description|
| -- | -- |
| int | **0** or a larger value if the operation is successful; a value smaller than **0** otherwise.<br> Possible failure causes: The **LogLevel** passed in is lower than the allowed log level; the **domain** is out of range; the **tag** is a null pointer; the CPU is overloaded; the memory is insufficient; the number of logs on the device is too large.|

### OH_LOG_VPrint()

```
int OH_LOG_VPrint(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, va_list ap)
```

**Description**

 Outputs logs of the specified **type**, **level**, **domain**, **tag**, and variables determined by the format specifier and privacy identifier in the printf format. The variables are of the **va_list** type.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [LogType](capi-log-h.md#logtype) type | Log type. The type for third-party applications is defined by **LOG_APP**.|
| [LogLevel](capi-log-h.md#loglevel) level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**.|
| unsigned int domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed.|
| const char *tag | Log tag, which is a string used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| const char *fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.|
| va_list ap | Parameter list of the **va_list** type that corresponds to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.|

**Returns**

| Type| Description|
| -- | -- |
| int | **0** or a larger value if the operation is successful; a value smaller than **0** otherwise.<br> Possible failure causes: The **LogLevel** passed in is lower than the allowed log level; the **domain** is out of range; the **tag** is a null pointer; the CPU is overloaded; the memory is insufficient; the number of logs on the device is too large.|

### OH_LOG_IsLoggable()

```
bool OH_LOG_IsLoggable(unsigned int domain, const char *tag, LogLevel level)
```

**Description**

Checks whether logs of the specified service domain, tag, and level can be printed.

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| unsigned int domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed.|
| const char *tag | Log tag, which is a string used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| [LogLevel](capi-log-h.md#loglevel) level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the specified logs can be output; **false** otherwise.|

### OH_LOG_DEBUG()

```
OH_LOG_DEBUG(type, ...)((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description**

Indicates DEBUG logs. This is a function-like macro. Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.<br>

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| type | Log type. The third-party application log type is [LOG_APP](capi-log-h.md#logtype).|
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.|
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.|

**See also**

[OH_LOG_Print](capi-log-h.md#oh_log_print)


### OH_LOG_INFO()

```
OH_LOG_INFO(type, ...)((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description**

Indicates INFO logs. This is a function-like macro. Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.<br>

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| type | Log type. The type for third-party applications is defined by **LOG_APP**.|
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.|
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.|

**See also**

[OH_LOG_Print](capi-log-h.md#oh_log_print)


### OH_LOG_WARN()

```
OH_LOG_WARN(type, ...)((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description**

Indicates WARN logs. This is a function-like macro. Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| type | Log type. The third-party application log type is [LOG_APP](capi-log-h.md#logtype).|
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.|
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.|

**See also**

[OH_LOG_Print](capi-log-h.md#oh_log_print)


### OH_LOG_ERROR()

```
OH_LOG_ERROR(type, ...)((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description**

Indicates ERROR logs. This is a function-like macro. Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| type | Log type. The third-party application log type is [LOG_APP](capi-log-h.md#logtype).|
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.|
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.|

**See also**

[OH_LOG_Print](capi-log-h.md#oh_log_print)


### OH_LOG_FATAL()

```
OH_LOG_FATAL(type, ...)((void)OH_LOG_Print((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```

**Description**

Indicates FATAL logs. This is a function-like macro. Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.<br>

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| type | Log type. The third-party application log type is [LOG_APP](capi-log-h.md#logtype).|
| fmt | Format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.|
| ... | Parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.|

**See also**

[OH_LOG_Print](capi-log-h.md#oh_log_print)


### LogCallback()

```
typedef void (*LogCallback)(const LogType type, const LogLevel level, const unsigned int domain, const char *tag,const char *msg)
```

**Description**

Defines a function for customizing the processing of logs in the callback.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const LogType](capi-log-h.md#logtype) type | Log type. The third-party application log type is [LOG_APP](capi-log-h.md#logtype).|
| [ const LogLevel](capi-log-h.md#loglevel) level | Log level. The value can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**.|
|  const unsigned int domain | Service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed.|
|  const char *tag | Log tag, which is a string used to identify the class, file, or service. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.|
| const char *msg | Log content, which is made up of formatted log strings.|

### OH_LOG_SetCallback()

```
void OH_LOG_SetCallback(LogCallback callback)
```

**Description**

Registers a callback function. After this function is called, the customized callback can take over all logs of the current process.<br> Note that whether this API is called or not, it does not change the default log processing of the current process.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [LogCallback](capi-log-h.md#logcallback) callback | Custom callback function. If processing of logs is not needed, a null pointer can be transferred.|

### OH_LOG_SetMinLogLevel()

```
void OH_LOG_SetMinLogLevel(LogLevel level)
```

**Description**

Sets the minimum log level. If the set log level is lower than the [global log level](../../dfx/hilog.md#displaying-and-setting-log-levels), the setting does not take effect.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [LogLevel](capi-log-h.md#loglevel) level | Log level.|
