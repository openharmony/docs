# Using HiLog (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @suxunquan-->
<!--Designer: @milkbread123-->
<!--Tester: @yufeifei-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=3120a9eb545cca6ffdcd89f28e2434c3ac8d5a79 translatedAt=2026-07-31T01:31:53.351Z pushedAt=2026-07-31T07:29:06.328Z -->

During application development, you can log from your application's key code. Through logs, you can find out how the application is running. For example, the logs can tell you whether the application is running properly, and whether the code execution sequence and logic branch are correct.

HiLog is a subsystem that provides logging for the system framework, services, and applications to record information on user operations and system running status.

## Available APIs

HiLog defines five log levels: DEBUG, INFO, WARN, ERROR, and FATAL. It provides corresponding methods for printing logs at different levels. The following table lists the APIs. For details, see [log.h](../reference/apis-performance-analysis-kit/capi-log-h.md).

| API/Macro| Description|
| -------- | -------- |
| bool OH_LOG_IsLoggable(unsigned int domain, const char \*tag, LogLevel level) | Checks whether a log with the specified domain, tag, and log level can be printed.<br>Returns **true** if the specified log can be printed; returns **false** otherwise. |
| int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char \*tag, const char \*fmt, ...) | Outputs a log with the specified domain, tag, and log level, and determines the variadic parameters to output based on the printf format type and privacy indicators.<br>A return value greater than or equal to 0 indicates success, and a value less than 0 indicates failure. |
| int OH_LOG_PrintMsg(LogType type, LogLevel level, unsigned int domain, const char \*tag, const char \*message) | Outputs a log string with the specified domain, tag, and log level.<br>A return value greater than or equal to 0 indicates success, and a value less than 0 indicates failure.<br>**Note:** This API is supported since API version 18. |
| int OH_LOG_PrintMsgByLen(LogType type, LogLevel level, unsigned int domain, const char \*tag, size_t tagLen, const char \*message, size_t messageLen) | Outputs a log string with the specified domain, tag, and log level, with the tag and string lengths specified.<br>A return value greater than or equal to 0 indicates success, and a value less than 0 indicates failure.<br>**Note:** This API is supported since API version 18. |
| int OH_LOG_VPrint(LogType type, LogLevel level, unsigned int domain, const char \*tag, const char \*fmt, va_list ap) | Equivalent to `OH_LOG_Print`, but the parameter list is `va_list`.<br>**Note:** This API is supported since API version 18. |
| \#define OH_LOG_DEBUG(type, ...) ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, **VA_ARGS**)) | Outputs DEBUG logs. This is a function-like macro.|
| \#define OH_LOG_INFO(type, ...) ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, **VA_ARGS**)) | Outputs INFO logs. This is a function-like macro.|
| \#define OH_LOG_WARN(type, ...) ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, **VA_ARGS**)) | Outputs WARN logs. This is a function-like macro.|
| \#define OH_LOG_ERROR(type, ...) ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, **VA_ARGS**)) | Outputs ERROR logs. This is a function-like macro.|
| \#define OH_LOG_FATAL(type, ...) ((void)OH_LOG_Print((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, **VA_ARGS**)) | Outputs FATAL logs. This is a function-like macro.|
| void OH_LOG_SetCallback(LogCallback callback) | Registers a callback function. After registration, you can obtain the HiLog logs of the current process through the `LogCallback` callback. If `OH_LOG_IsLoggable` returns **true**, the callback can obtain the log. |
| void OH_LOG_SetMinLogLevel(LogLevel level) | Sets the minimum log level for app log printing to intercept low-level log printing.<br>**Note:** This API is supported since API version 15. |
| void OH_LOG_SetLogLevel(LogLevel level, PreferStrategy prefer) | Sets the minimum log level for the current app process. Different preference strategies can be configured.<br>**Note:** This API is supported since API version 21. |

> **NOTE**
>
> The hilog log APIs are non-signal-safe functions. Do not call non-signal-safe HiLog log APIs in signal handler functions.
>
> If the log level set is lower than the [global log level](hilog.md#displaying-and-setting-log-levels), the `OH_LOG_SetMinLogLevel()` setting does not take effect.
>
> In the debug version of an app, neither `OH_LOG_SetMinLogLevel()` nor `OH_LOG_SetLogLevel()` takes effect.

### Parameters

- **domain**: service domain of logs. The value range is 0x0000 to 0xFFFF. You can define the value as required.

- **tag**: log identifier. It can be any string. You are advised to use this parameter to identify the class or service behavior of a method call. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.

- **level**: log level. For details, see [LogLevel](../reference/apis-performance-analysis-kit/capi-log-h.md#loglevel).

- **prefer**: preference strategy. For details, see [PreferStrategy](../reference/apis-performance-analysis-kit/capi-log-h.md#preferstrategy).

- **fmt**: format of the log to output. The value is a string in the "%{private flag}specifier" format.

  | Private Flag| Description|
  | -------- | -------- |
  | private | The output is **\<private>**, which indicates that the log information is invisible.|
  | public | The log information is displayed.|
  | Not specified| The default value **\<private>** is used.|

  | Specifier| Description| Example|
  | -------- | -------- | -------- |
  | d/i | Prints decimal integer types. | 123 |
  | s | Prints char\* type. | "this is a hilog" |

  Multiple parameters can be set in a format string. For example, in the format string "%s World", "%s" is a variable argument identifier of the string type, and its specific value is defined in args. For details about format specifiers, see [printf](https://man7.org/linux/man-pages/man3/printf.3.html).

  The debug application does not have a privacy control mechanism. Parameters can be displayed in plaintext when any of the preceding private flags is used to print logs.

- **args**: parameters of the types specified by **specifier** in **format**. This parameter can be left blank. The number and type of parameters must match **specifier**.

> **NOTE**
>
> - The domains, tags, and levels specified in **OH_LOG_IsLoggable()** and **OH_LOG_Print()** must be the same.
>
> - **OH_LOG_IsLoggable()** returns **true** if the specified logs can be printed; returns **false** otherwise.
>   For debug applications, all log levels can be printed.
>
>   For release applications, logs are printed only if the log level is not lower than the global log level.
>
>   During debugging, you can change the log level. For details, see [Displaying and Setting Log Levels](hilog.md#displaying-and-setting-log-levels).

## Constraints

The maximum size of a log file is 4096 bytes. Excess content will be discarded.

## How to Develop

1. Add the link of **libhilog_ndk.z.so** to **CMakeLists.txt**.

   ```txt
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
   #define LOG_TAG "MY_TAG"   // Global tag, which identifies the module log tag.
   ```

3. Print logs.

   ```c++
   OH_LOG_INFO(LOG_APP, "Failed to visit path.");
   // Set the minimum log level to Warn.
   OH_LOG_SetMinLogLevel(LOG_WARN);
   OH_LOG_INFO(LOG_APP, "this is an info level log");
   OH_LOG_ERROR(LOG_APP, "this is an error level log");
   // Set the minimum log level to the PREFER_OPEN_LOG strategy so that logs whose levels are not lower than INFO can be printed.
   OH_LOG_SetLogLevel(LOG_WARN, PREFER_OPEN_LOG);
   OH_LOG_INFO(LOG_APP, "this is an another info level log");
   OH_LOG_ERROR(LOG_APP, "this is an another error level log");
   ```

4. The output is as follows:

<!--RP2-->

   ```txt
   01-02 08:39:38.915   9012-9012     A03200/MY_TAG                   com.example.hilogDemo              I     Failed to visit path.
   01-02 08:39:38.915   9012-9012     A03200/MY_TAG                   com.example.hilogDemo              E     this is an error level log
   01-02 08:39:38.915   9012-9012     A03200/MY_TAG                   com.example.hilogDemo              I     this is an another info level log
   01-02 08:39:38.915   9012-9012     A03200/MY_TAG                   com.example.hilogDemo              E     this is an another error level log
   ```

<!--RP2End-->

### Registering a Log Callback

> **NOTE**
>
> 1. Do not recursively call HiLog APIs in the callback function. Otherwise, circular calls may occur.
>
> 2. A process needs to register the callback function only once. If the callback function is registered multiple times, the last registered callback function takes effect.

```c++
#include "hilog/log.h"

// Customize a callback for processing logs.
void MyHiLog(const LogType type, const LogLevel level, const unsigned int domain, const char *tag, const char *msg)
{
    // Define how to handle your logs, such as redirect/filter.
    // Note: Do not recursively call HiLog APIs in the callback function. Otherwise, a circular call issue may occur.
}

static void Test(void)
{
   // 1. Register a callback.
   OH_LOG_SetCallback(MyHiLog);
    
   // 2. Call the HiLog API to print logs. The log content is output to HiLog and returned to MyHiLog through the callback, so that you can process the logs in MyHiLog.
   OH_LOG_INFO(LOG_APP, "hello world");
}
```