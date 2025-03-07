# Using HiLog (C/C++)

During application development, you can log from your application's key code. Through logs, you can find out how the application is running. For example, the logs can tell you whether the application is running properly, and whether the code execution sequence and logic branch are correct.

HiLog is a subsystem that provides logging for the system framework, services, and applications to record information on user operations and system running status.

## Available APIs

HiLog defines five log levels (DEBUG, INFO, WARN, ERROR, and FATAL) and provides APIs to output logs of different levels. For details about the APIs, see [hilog](../reference/apis-performance-analysis-kit/_hi_log.md).

| API/Macro| Description|
| -------- | -------- |
| bool OH_LOG_IsLoggable(unsigned int domain, const char \*tag, LogLevel level) | Checks whether logs of the specified service domain, tag, and level can be printed.<br>This API returns **true** if the specified logs can be printed and returns **false** otherwise.| 
| int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char \*tag, const char \*fmt, ...) | Outputs logs of the specified domain, tag, and log level, with the variable parameters in the **printf** format.<br>If the return value is greater than or equal to 0, the operation is successful. Otherwise, the operation fails.|
| int OH_LOG_PrintMsg(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *message) | Outputs log strings of the specified domain, tag, and log level.<br>If the return value is greater than or equal to 0, the operation is successful. Otherwise, the operation fails.|
| int OH_LOG_PrintMsgByLen(LogType type, LogLevel level, unsigned int domain, const char *tag, size_t tagLen, const char *message, size_t messageLen) | Outputs the log string of the specified domain, tag, and log level, with the tag and string length specified.<br>If the return value is greater than or equal to 0, the operation is successful. Otherwise, the operation fails.|
| int OH_LOG_VPrint(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, va_list ap) | Used in the same way as **OH_LOG_Print**, but the parameter list is **va_list**.|
| \#define OH_LOG_DEBUG(type, ...) ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | Outputs DEBUG logs. This is a function-like macro.|
| \#define OH_LOG_INFO(type, ...) ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | Outputs INFO logs. This is a function-like macro.|
| \#define OH_LOG_WARN(type, ...) ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | Outputs WARN logs. This is a function-like macro.|
| \#define OH_LOG_ERROR(type, ...) ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | Outputs ERROR logs. This is a function-like macro.|
| \#define OH_LOG_FATAL(type, ...) ((void)OH_LOG_Print((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | Outputs FATAL logs. This is a function-like macro.|
| void OH_LOG_SetCallback(LogCallback callback) | Registers a callback function to return all logs for the process.|
| void OH_LOG_SetMinLogLevel(LogLevel level)|Sets the minimum log level. When a process prints logs, both the minimum log level and the global log level are verified. Therefore, the minimum log level cannot be lower than the global log level. The default value of [global log level](hilog.md#displaying-and-setting-log-levels) is **Info**.|

### Parameters

> **NOTE**
>
> The domains, tags, and levels specified in **OH_LOG_IsLoggable()** and **OH_LOG_Print()** must be the same.

- **domain**: service domain of logs. The value range is 0x0000 to 0xFFFF. You can define the value as required.

- **tag**: log identifier. It can be any string. You are advised to use this parameter to identify the class or service behavior of a method call. A tag can contain a maximum of 31 bytes. If a tag contains more than 31 bytes, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.

- **level**: log level. For details about the value, see [LogLevel](../reference/apis-performance-analysis-kit/_hi_log.md#loglevel).

- **fmt**: format of the log to output. The value is a string in the "%{private flag}specifier" format.
  | Private Flag| Description|
  | -------- | -------- |
  | private | The output is **\<private>**, which indicates that the log information is invisible.|
  | public | The log information is displayed.|
  | Not specified| The default value **\<private>** is used.|

  | Specifier| Description| Example|
  | -------- | -------- | -------- |
  | d/i | Prints logs of the **number**, **bool**, and **bigint** types.| 123 |
  | s | Prints logs of the **string**, **undefined**, and **null** types.| "123" |

  You can set multiple parameters in the **format** string, for example, **%s World**, where **%s** is a variable of the string type and its value is defined by **args**. <!--Del-->

  To display the log masked by {**private**} in debugging, run the **hilog -p off** command.
<!--DelEnd-->

- **args**: parameters of the types specified by **specifier** in **format**. This parameter can be left blank. The number and type of parameters must match **specifier**.

## Constraints

The maximum size of a log file is 4096 bytes. Excess content will be discarded.

## How to Develop

1. Add the link of **libhilog_ndk.z.so** to **CMakeLists.txt**.

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

3. Print logs.

   ```c++
   OH_LOG_INFO(LOG_APP, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
   // Set the minimum log level to Warn.
   OH_LOG_SetMinLogLevel(LOG_WARN);
   OH_LOG_INFO(LOG_APP, "this is an info level log");
   OH_LOG_ERROR(LOG_APP, "this is an info level log");
   ```

4. The output is as follows:

   ```
   01-02 08:39:38.915   9012-9012     A03200/MY_TAG                   pid-9012              I     Failed to visit <private>, reason:11.
   01-02 08:39:38.915   9012-9012     A03200/MY_TAG                   pid-9012              E     this is an info level log
   ```

### Registering a Log Callback

> **Note**
>
> The hilog APIs cannot be called in the callback to print logs. Otherwise, an infinite loop occurs.

```c++
#include "hilog/log.h"
static constexpr OHOS::HiviewDFX::HiLogLabel LABEL = {LOG_CORE, 0xD003200, "MY_TAG"};

// Customize a callback for processing logs.
void MyHiLog(const LogType type, const LogLevel level, const unsigned int domain, const char *tag, const char *msg)
{
    // Define how to handle your logs, such as redirect/filter.
    // Note: Do not call the hilog APIs in the callback to print logs. Otherwise, an infinite loop occurs.
}

static void Test(void)
{
   // 1. Register a callback.
    OH_LOG_SetCallback(MyHiLog);
    
   // 2. Call the hilog API to print logs. Logs are output to HiLog and returned to **MyHiLog()** through the registered callback. Then, **MyHiLog()** is called to process the logs.
   HiLog::Info(LABEL, "hello world");
}
```
