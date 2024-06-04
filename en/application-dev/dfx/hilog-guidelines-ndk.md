# Using HiLog to Print Logs (C/C++)

During application development, you can log from your application's key code. You can find out how your application is running through logs. For example, the logs can tell you whether the application is running properly, whether the code running time sequence is normal, and whether the running logic and branch are correct.

HiLog is a log system that provides logging for the system framework, services, and applications to record information on user operations and system running status.

## Available APIs

HiLog defines five log levels: DEBUG, INFO, WARN, ERROR, and FATAL, and provides the following APIs to output logs at different levels. For details, see [hilog](../reference/apis-performance-analysis-kit/_hi_log.md)).

| API/Macro| Description|
| -------- | -------- |
| bool OH_LOG_IsLoggable(unsigned int domain, const char \*tag, LogLevel level) | Checks whether logs of the specified service domain, tag, and level can be printed.<br>Returns **true** if the specified logs can be output; returns **false** otherwise.| 
| int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char \*tag, const char \*fmt, ...) | Outputs logs of the specified domain, tag, and log level, with the variable parameters based on the printf format string.<br>Returns the total number of bytes if log printing is successful; returns **-1** otherwise.|
| \#define OH_LOG_DEBUG(type, ...) ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | Outputs DEBUG logs. This is a function-like macro.|
| \#define OH_LOG_INFO(type, ...) ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | Outputs INFO logs. This is a function-like macro.|
| \#define OH_LOG_WARN(type, ...) ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | Outputs WARN logs. This is a function-like macro.|
| \#define OH_LOG_ERROR(type, ...) ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | Outputs ERROR logs. This is a function-like macro.|
| \#define OH_LOG_FATAL(type, ...) ((void)OH_LOG_Print((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | Outputs FATAL logs. This is a function-like macro.|
| void OH_LOG_SetCallback(LogCallback callback) | Registers a callback function. You can then obtain all logs for the current process through the **LogCallback** callback.|

### Parameter Description

> **NOTE**
>
> The domains, tags, and levels specified in **OH_LOG_IsLoggable()** and **OH_LOG_Print()** must be the same.

- **domain**: service domain of logs. The value range is 0x0000 to 0xFFFF. You can define the value as required.

- **tag**: log identifier. It can be any string. You are advised to use this parameter to identify the class or service behavior of a method call.

- **level**: log level. For details about the value, see [LogLevel](../reference/apis-performance-analysis-kit/_hi_log.md#loglevel).

- **fmt**: format string used to output logs in a specified format. The value is a string in the "%{private flag}specifier" format.
  | Privacy Flag| Description|
  | -------- | -------- |
  | private | Parameters are displayed as **\<private>** in printed logs.|
  | public | Parameters are displayed in plaintext as they are in printed logs.|
  | N/A| If no private flag is specified, the default value **private** is used.|

  | Specifier| Description| Example|
  | -------- | -------- | -------- |
  | d/i | Prints logs of the **number**, **bool**, and **bigint** types.| 123 |
  | s | Prints logs of the **string**, **undefined**, and **null** types.| "123" |

  You can set several parameters in the format string. For example, **%s** in the format string **%s World** identifies a variable of the string type, whose value is defined in **args**.

  To enable parameters identified by **{private}** to be displayed as they are, run **hilog -p off**.

- **args**: the parameter list corresponding to the parameter type specified in the format string. There can be no or multiple parameters in the list. The number and type of parameters must be mapped to the identifiers in the format string.

## Constraints

A log contains a maximum of 4096 bytes. If this limit is exceeded, excess content will be discarded.

## How to Develop

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

4. The output is as follows:

   ```
   12-11 12:21:47.579  2695 2695 E A03200/MY_TAG: Failed to visit <private>, reason:11.
   ```

### Example of Using the Log Callback

```c++
#include "hilog/log.h"
static constexpr OHOS::HiviewDFX::HiLogLabel LABEL = {LOG_CORE, 0xD003200, "MY_TAG"};

// Callback function, which is a log processing function you customize.
void MyHiLog(const LogType type, const LogLevel level, const unsigned int domain, const char *tag, const char *msg)
{
    // user-defined to handle your log, such as redirect/filter
}

static void Test(void)
{
   // 1. Register a callback.
    OH_LOG_SetCallback(MyHiLog);
    
   // 2. Call the HiLog API to print logs. The log content is output to HiLog and returned to MyHiLog through the callback. You can process logs in MyHiLog.
   HiLog::Info(LABEL, "hello world");
}
```
