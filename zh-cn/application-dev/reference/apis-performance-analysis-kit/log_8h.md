# log.h


## 概述

HiLog模块日志接口定义，通过这些接口实现日志打印相关功能。

用户输出日志时，先定义日志所属业务领域、日志TAG，然后按照类型、级别选择对应API，指定参数隐私标识输出日志内容。

业务领域：指定日志所对应的业务领域，用户自定义使用，用于标识业务的子系统、模块。16进制整数，范围0x0~0xFFFF。

日志TAG：字符串常量，用于标识调用所在的类或者业务。

日志级别：DEBUG、INFO、WARN、ERROR、FATAL。

参数格式：类printf的%方式，包括格式字符串（包括参数类型标识）和变参。

隐私参数标识：在格式字符串每个参数中%符号后类型前增加{public}、{private}标识。
注意：每个参数未指定隐私标识时，缺省为隐私。

使用示例：

定义业务领域、TAG：

```
#define LOG_DOMAIN 0x0201
#define LOG_TAG "MY_TAG"
```

日志打印：

```
HILOG_WARN(LOG_APP, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
```

结果输出：

```
05-06 15:01:06.870 1051 1051 W 0201/MY_TAG: Failed to visit <private>, reason:503.
```

**引用文件：** &lt;hilog/log.h&gt;

**起始版本：** 8

**相关模块：**[HiLog](_hi_log.md)


## 汇总


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [LOG_DOMAIN](_hi_log.md#log_domain)&nbsp;&nbsp;&nbsp;0 | 日志所对应的业务领域，用于标识业务的子系统、模块。 | 
| [LOG_TAG](_hi_log.md#log_tag)&nbsp;&nbsp;&nbsp;NULL | 字符串常量，标识调用所在的类或者业务。tag最多为31字节，超出后会截断。不建议使用中文字符，可能出现乱码或者对齐问题。  | 
| [OH_LOG_DEBUG](_hi_log.md#oh_log_debug)(type, ...)&nbsp;&nbsp;&nbsp;((void) [OH_LOG_Print](_hi_log.md#oh_log_print)((type), [LOG_DEBUG](_hi_log.md), [LOG_DOMAIN](_hi_log.md#log_domain), [LOG_TAG](_hi_log.md#log_tag), \_\_VA_ARGS\_\_)) | DEBUG级别写日志，宏封装接口。 | 
| [OH_LOG_INFO](_hi_log.md#oh_log_info)(type, ...)&nbsp;&nbsp;&nbsp;((void) [OH_LOG_Print](_hi_log.md#oh_log_print)((type), [LOG_INFO](_hi_log.md), [LOG_DOMAIN](_hi_log.md#log_domain), [LOG_TAG](_hi_log.md#log_tag), \_\_VA_ARGS\_\_)) | INFO级别写日志，宏封装接口。 | 
| [OH_LOG_WARN](_hi_log.md#oh_log_warn)(type, ...)&nbsp;&nbsp;&nbsp;((void) [OH_LOG_Print](_hi_log.md#oh_log_print)((type), [LOG_WARN](_hi_log.md), [LOG_DOMAIN](_hi_log.md#log_domain), [LOG_TAG](_hi_log.md#log_tag), \_\_VA_ARGS\_\_)) | WARN级别写日志，宏封装接口。 | 
| [OH_LOG_ERROR](_hi_log.md#oh_log_error)(type, ...)&nbsp;&nbsp;&nbsp;((void) [OH_LOG_Print](_hi_log.md#oh_log_print)((type), [LOG_ERROR](_hi_log.md), [LOG_DOMAIN](_hi_log.md#log_domain), [LOG_TAG](_hi_log.md#log_tag), \_\_VA_ARGS\_\_)) | ERROR级别写日志，宏封装接口。 | 
| [OH_LOG_FATAL](_hi_log.md#oh_log_fatal)(type, ...)&nbsp;&nbsp;&nbsp;((void)HiLogPrint((type), [LOG_FATAL](_hi_log.md), [LOG_DOMAIN](_hi_log.md#log_domain), [LOG_TAG](_hi_log.md#log_tag), \_\_VA_ARGS\_\_)) | FATAL级别写日志，宏封装接口。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [LogCallback](_hi_log.md#logcallback)) (const [LogType](_hi_log.md#logtype) type, const [LogLevel](_hi_log.md#loglevel) level, const unsigned int domain, const char \*tag, const char \*msg) | 函数指针，开发者自定义回调函数内容，在回调函数中，可自行对hilog日志进行处理。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [LogType](_hi_log.md#logtype) { LOG_APP = 0 } | 日志类型。  | 
| [LogLevel](_hi_log.md#loglevel) {<br/>LOG_DEBUG = 3,<br/>LOG_INFO = 4,<br/>LOG_WARN = 5,<br/>LOG_ERROR = 6,<br/>LOG_FATAL = 7<br/>} | 日志级别。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int [OH_LOG_Print](_hi_log.md#oh_log_print) ([LogType](_hi_log.md#logtype) type, [LogLevel](_hi_log.md#loglevel) level, unsigned int domain, const char \*tag, const char \*fmt,...) __attribute__((__format__(os_log | 写日志接口。  | 
| int bool [OH_LOG_IsLoggable](_hi_log.md#oh_log_isloggable) (unsigned int domain, const char \*tag, [LogLevel](_hi_log.md#loglevel) level) | 检查指定业务领域、TAG、级别的日志是否可以打印。  | 
| void [OH_LOG_SetCallback](_hi_log.md#oh_log_setcallback) ([LogCallback](_hi_log.md#logcallback) callback) | 注册函数。  | 
| void [OH_LOG_SetMinLogLevel](_hi_log.md#oh_log_setminloglevel) ([LogLevel](_hi_log.md#loglevel) level) | 设置应用日志打印的最低日志级别。 进程在打印日志时，需要同时校验该日志级别和全局日志级别，<br/>所以设置的日志级别不能低于全局日志级别，[全局日志级别](../../dfx/hilog.md#查看和设置日志级别)默认为Info。 | 
| int [OH_LOG_PrintMsg](_hi_log.md#oh_log_printmsg) ([LogType](_hi_log.md#logtype) type, [LogLevel](_hi_log.md#loglevel) level, unsigned int domain, const char \*tag, const char \*message) | 写日志接口。输出指定type、level、domain、tag的常量日志字符串。  | 
| int [OH_LOG_PrintMsgByLen](_hi_log.md#oh_log_printmsgbylen) ([LogType](_hi_log.md#logtype) type, [LogLevel](_hi_log.md#loglevel) level, unsigned int domain, const char \*tag, size_t tagLen, const char \*message, size_t messageLen) | 写日志接口。输出指定domain、tag和日志级别的常量日志字符串，需要指定tag及字符串长度，和OH_LOG_PrintMsg区别是可以接受不带结束符的字符串。  | 
| int [OH_LOG_VPrint](_hi_log.md#oh_log_vprint)(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, va_list ap) | - | 写日志接口。指定日志类型、日志级别、业务领域、TAG，按照类printf格式类型和隐私指示确定需要输出的变参，变参为va_list类型。 |
