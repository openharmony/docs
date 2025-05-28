# 使用HiLog打印日志（C/C++）

在应用开发过程中，可在关键代码处输出日志信息。在运行应用后，通过查看日志信息来分析应用执行情况（如应用是否正常运行、代码运行时序、运行逻辑分支是否正常等）。

HiLog日志系统，提供给系统框架、服务、以及应用，用于打印日志，记录用户操作、系统运行状态等。

## 接口说明

HiLog中定义了DEBUG、INFO、WARN、ERROR、FATAL五种日志级别，并提供了对应的方法输出不同级别的日志，接口如下表所示，具体说明可查阅[API参考文档](../reference/apis-performance-analysis-kit/_hi_log.md)。

| 方法/宏 | 接口描述 |
| -------- | -------- |
| bool OH_LOG_IsLoggable(unsigned int domain, const char \*tag, LogLevel level) | 检查指定domain、tag和日志级别的日志是否可以打印。<br/>如果指定日志可以打印则返回true；否则返回false。 | 
| int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char \*tag, const char \*fmt, ...) | 输出指定domain、tag和日志级别的日志，并按照printf格式类型和隐私指示确定需要输出的变参。<br/>返回值大于等于0表示成功，小于0表示失败。 |
| int OH_LOG_PrintMsg(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *message) | 输出指定domain、tag和日志级别的日志字符串。<br/>返回值大于等于0表示成功，小于0表示失败。 |
| int OH_LOG_PrintMsgByLen(LogType type, LogLevel level, unsigned int domain, const char *tag, size_t tagLen, const char *message, size_t messageLen) | 输出指定domain、tag和日志级别的日志字符串，需要指定tag及字符串长度。<br/>返回值大于等于0表示成功，小于0表示失败。 |
| int OH_LOG_VPrint(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, va_list ap) | 等效于OH_LOG_Print，但是参数列表为va_list。|
| \#define OH_LOG_DEBUG(type, ...) ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | DEBUG级别写日志，宏封装接口。 |
| \#define OH_LOG_INFO(type, ...) ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | INFO级别写日志，宏封装接口。 |
| \#define OH_LOG_WARN(type, ...) ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | WARN级别写日志，宏封装接口。 |
| \#define OH_LOG_ERROR(type, ...) ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | ERROR级别写日志，宏封装接口。 |
| \#define OH_LOG_FATAL(type, ...) ((void)OH_LOG_Print((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, \_\_VA_ARGS__)) | FATAL级别写日志，宏封装接口。 |
| void OH_LOG_SetCallback(LogCallback callback) | 注册函数，注册后可通过LogCallback回调获取本进程所有的hilog日志。|
| void OH_LOG_SetMinLogLevel(LogLevel level)|设置应用日志打印的最低日志级别，进程在打印日志时，需要同时校验该日志级别和全局日志级别，所以设置的日志级别不能低于全局日志级别，[全局日志级别](hilog.md#查看和设置日志级别)默认为Info。|

### 参数解析

> **说明：**
>
> OH_LOG_IsLoggable()和OH_LOG_Print()使用的domain、tag和level应保持一致。

- domain：用于指定输出日志所对应的业务领域，取值范围为0x0000~0xFFFF，开发者可以根据需要进行自定义。

- tag：用于指定日志标识，可以为任意字符串，建议标识调用所在的类或者业务行为。tag最多为31字节，超出后会截断，不建议使用中文字符，可能出现乱码或者对齐问题。

- level：用于指定日志级别。取值见[LogLevel](../reference/apis-performance-analysis-kit/_hi_log.md#loglevel)。

- fmt：格式字符串，用于日志的格式化输出。日志打印的格式化参数需按照“%{private flag}specifier”的格式打印。
  | 隐私标识符（private flag） | 说明 |
  | -------- | -------- |
  | private | 表示日志打印结果不可见，输出结果为&lt;private&gt;。 |
  | public | 表示日志打印结果可见，明文显示参数。 |
  | 无 | 缺省值默认为private，日志打印结果不可见。 |

  | 格式说明符（specifier） | 说明 | 示例 |
  | -------- | -------- | -------- |
  | d/i | 支持打印number、bool和bigint类型。 | 123 |
  | s | 支持打印string、undefined和null类型。 | "123" |

  格式字符串中可以设置多个参数，例如格式字符串为“%s World”，“%s”为参数类型为string的变参标识，具体取值在args中定义。<!--Del-->

  调试时可通过命令“hilog -p off”指令，关闭隐私开关，明文显示private日志内容。
<!--DelEnd-->

- args：可以为0个或多个参数，是格式字符串中参数类型对应的参数列表。参数的数量、类型必须与格式字符串中的标识一一对应。

## 约束与限制

日志最多打印4096字节，超出限制文本将被截断。

## 开发步骤

1. 在CMakeLists.txt中新增libhilog_ndk.z.so链接：

   ```
   target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
   ```

2. 在源文件中包含hilog头文件，并定义domain、tag宏：

   ```c++
   #include "hilog/log.h"
   ```

   ```c++
   #undef LOG_DOMAIN
   #undef LOG_TAG
   #define LOG_DOMAIN 0x3200  // 全局domain宏，标识业务领域
   #define LOG_TAG "MY_TAG"   // 全局tag宏，标识模块日志tag
   ```

3. 打印日志：

   ```c++
   OH_LOG_INFO(LOG_APP, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
   // 设置应用日志最低打印级别，设置完成后，低于Warn级别的日志将无法打印
   OH_LOG_SetMinLogLevel(LOG_WARN);
   OH_LOG_INFO(LOG_APP, "this is an info level log");
   OH_LOG_ERROR(LOG_APP, "this is an info level log");
   ```

4. 输出结果：

   ```
   01-02 08:39:38.915   9012-9012     A03200/MY_TAG                   pid-9012              I     Failed to visit <private>, reason:11.
   01-02 08:39:38.915   9012-9012     A03200/MY_TAG                   pid-9012              E     this is an info level log
   ```

### 日志回调接口使用示例

> **注意**
>
> 在回调函数中禁止递归调用hilog接口，否则会导致循环调用问题。

```c++
#include "hilog/log.h"

// 回调函数，开发者自定义的日志处理函数
void MyHiLog(const LogType type, const LogLevel level, const unsigned int domain, const char *tag, const char *msg)
{
    // user-defined to handle your log, such as redirect/filter
    // 注意: 在回调函数中禁止递归调用hilog接口，否则会导致循环调用问题。
}

static void Test(void)
{
   // 1.注册回调接口
   OH_LOG_SetCallback(MyHiLog);
    
   // 2.调用hilog接口打印日志，日志内容会输出到hilog，同时通过回调返回给MyHiLog，开发者可以在MyHiLog中自行处理日志
   OH_LOG_INFO(LOG_APP, "hello world");
}
```
