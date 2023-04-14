# HiLog


## Overview

Provides logging functions.

For example, you can use logging functions to output logs of the specified log type, service domain, log tag, and log level.

\@syscap SystemCapability.HiviewDFX.HiLog

**Since:**
8

## Summary


### Files

| Name | Description | 
| -------- | -------- |
| [log.h](log_8h.md) | Defines the logging functions of the HiLog module.<br>File to Include: <hilog/log.h>  | 


### Macros

| Name | Description | 
| -------- | -------- |
| [LOG_DOMAIN](#log_domain)   0 | Defines the service domain for a log file.  | 
| [LOG_TAG](#log_tag)   NULL | Defines a string constant used to identify the class, file, or service.  | 
| [OH_LOG_DEBUG](#oh_log_debug)(type, ...)   ((void)[OH_LOG_Print](#oh_log_print)((type), LOG_DEBUG, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), __VA_ARGS__)) | Outputs DEBUG logs. This is a function-like macro.  | 
| [OH_LOG_INFO](#oh_log_info)(type, ...)   ((void)[OH_LOG_Print](#oh_log_print)((type), LOG_INFO, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), __VA_ARGS__)) | Outputs INFO logs. This is a function-like macro.  | 
| [OH_LOG_WARN](#oh_log_warn)(type, ...)   ((void)[OH_LOG_Print](#oh_log_print)((type), LOG_WARN, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), __VA_ARGS__)) | Outputs WARN logs. This is a function-like macro.  | 
| [OH_LOG_ERROR](#oh_log_error)(type, ...)   ((void)[OH_LOG_Print](#oh_log_print)((type), LOG_ERROR, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), __VA_ARGS__)) | Outputs ERROR logs. This is a function-like macro.  | 
| [OH_LOG_FATAL](#oh_log_fatal)(type, ...)   ((void)HiLogPrint((type), LOG_FATAL, [LOG_DOMAIN](#log_domain), [LOG_TAG](#log_tag), __VA_ARGS__)) | Outputs FATAL logs. This is a function-like macro.  | 


### Enums

| Name | Description | 
| -------- | -------- |
| [LogType](#logtype) { LOG_APP = 0 } | Enumerates log types.  | 
| [LogLevel](#loglevel) {<br/>LOG_DEBUG = 3, LOG_INFO = 4, LOG_WARN = 5, LOG_ERROR = 6,<br/>LOG_FATAL = 7<br/>} | Enumerates log levels.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_LOG_Print](#oh_log_print) ([LogType](#logtype) type, [LogLevel](#loglevel) level, unsigned int domain, const char *tag, const char *fmt,...) \_\_attribute\_\_((\_\_format\_\_(os_log, 5,6))) |Outputs logs.  | 
| [OH_LOG_IsLoggable](#oh_log_isloggable) (unsigned int domain, const char \*tag, [LogLevel](#loglevel) level) | Checks whether logs of the specified service domain, log tag, and log level can be output.  | 


## Macro Description


### LOG_DOMAIN

  
```
#define LOG_DOMAIN   0
```
**Description**<br>
Defines the service domain for a log file.

The service domain is used to identify the subsystem and module of a service. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value is beyond the range, its significant bits are automatically truncated.


### LOG_TAG

  
```
#define LOG_TAG   NULL
```
**Description**<br>
Defines a string constant used to identify the class, file, or service.


### OH_LOG_DEBUG

  
```
#define OH_LOG_DEBUG( type,  ... )   ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```
**Description**<br>
Outputs DEBUG logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| type | Indicates the log type. The type for third-party applications is defined by LOG_APP.  | 
| fmt | Indicates the format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.  | 
| ... | Indicates the parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.  | 

 **See**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_ERROR

  
```
#define OH_LOG_ERROR( type,  ... )   ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```
**Description**<br>
Outputs ERROR logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| type | Indicates the log type. The type for third-party applications is defined by LOG_APP.  | 
| fmt | Indicates the format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.  | 
| ... | Indicates the parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.  | 

 **See**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_FATAL

  
```
#define OH_LOG_FATAL( type,  ... )   ((void)HiLogPrint((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```
**Description**<br>
Outputs FATAL logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| type | Indicates the log type. The type for third-party applications is defined by LOG_APP.  | 
| fmt | Indicates the format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.  | 
| ... | Indicates the parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.  | 

 **See**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_INFO

  
```
#define OH_LOG_INFO( type,  ... )   ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```
**Description**<br>
Outputs INFO logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| type | Indicates the log type. The type for third-party applications is defined by LOG_APP.  | 
| fmt | Indicates the format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.  | 
| ... | Indicates the parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.  | 

 **See**

[OH_LOG_Print](#oh_log_print)


### OH_LOG_WARN

  
```
#define OH_LOG_WARN( type,  ... )   ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
```
**Description**<br>
Outputs WARN logs. This is a function-like macro.

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| type | Indicates the log type. The type for third-party applications is defined by LOG_APP.  | 
| fmt | Indicates the format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.  | 
| ... | Indicates the parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.  | 

 **See**

[OH_LOG_Print](#oh_log_print)


## Enum Description


### LogLevel

  
```
enum LogLevel
```
**Description**<br>
Enumerates log levels.

You are advised to select log levels based on their respective use cases:

DEBUG: provides more detailed process information than INFO logs to help developers analyze service processes and locate faults. DEBUG logs are not recorded in official versions by default. They are available in debug versions or in official versions with the debug function enabled.

INFO: indicates the key service process nodes and exceptions (for example, no network signal or login failure) that occur during service running. These logs should be recorded by the dominant module in the service to avoid repeated logging conducted by multiple invoked modules or low-level functions.

WARN: indicates a severe, unexpected fault that has little impact on users and can be rectified by the programs themselves or through simple operations.

ERROR: indicates a program or functional error that affects the normal running or use of the functionality and can be fixed at a high cost, for example, by resetting data.

FATAL: indicates that a program or functionality is about to crash and the fault cannot be rectified.

| Name | Description | 
| -------- | -------- |
| LOG_DEBUG  | DEBUG level to be used by OH_LOG_DEBUG | 
| LOG_INFO  | INFO level to be used by OH_LOG_INFO | 
| LOG_WARN  | WARN level to be used by OH_LOG_WARN | 
| LOG_ERROR  | ERROR level to be used by OH_LOG_ERROR | 
| LOG_FATAL  | FATAL level to be used by OH_LOG_FATAL | 


### LogType

  
```
enum LogType
```
**Description**<br>
Enumerates log types.

Currently, only LOG_APP is available.

| Name | Description | 
| -------- | -------- |
| LOG_APP  | Application log | 


## Function Description


### OH_LOG_IsLoggable()

  
```
int bool OH_LOG_IsLoggable (unsigned int domain, const char * tag, LogLevel level )
```
**Description**<br>
Checks whether logs of the specified service domain, log tag, and log level can be output.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| domain | Indicates the service domain of logs.  | 
| tag | Indicates the log tag.  | 
| level | Indicates the log level.  | 

**Returns**

Returns **true** if the specified logs can be output; returns **false** otherwise.


### OH_LOG_Print()

  
```
int OH_LOG_Print (LogType type, LogLevel level, unsigned int domain, const char * tag, const char * fmt,  ... )
```
**Description**<br>
Outputs logs.

You can use this function to output logs based on the specified log type, log level, service domain, log tag, and variable parameters determined by the format specifier and privacy identifier in the printf format.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| type | Indicates the log type. The type for third-party applications is defined by LOG_APP.  | 
| level | Indicates the log level, which can be **LOG_DEBUG**, **LOG_INFO**, **LOG_WARN**, **LOG_ERROR**, and **LOG_FATAL**.  | 
| domain | Indicates the service domain. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF.  | 
| tag | Indicates the log tag, which is a string used to identify the class, file, or service.  | 
| fmt | Indicates the format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, **{public}** or **{private}** is added between the % character and the format specifier in each parameter.  | 
| ... | Indicates the parameter list corresponding to the parameter type in the format string. The number and type of parameters must be mapped onto the identifier in the format string.  | 

**Returns**

Returns **0** or a larger value if the operation is successful; returns a value smaller than **0** otherwise.
