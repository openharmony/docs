# log.h


## 概述

HiLog模块日志接口定义，通过这些接口实现日志打印相关功能。

用户输出日志时，先定义日志所属业务领域、日志TAG，然后按照类型、级别选择对应API，指定参数隐私标识输出日志内容。

业务领域：指定日志所对应的业务领域，用户自定义使用，用于标识业务的子系统、模块。16进制整数，范围0x0~0xFFFF。

日志TAG：字符串常量，用于标识调用所在的类或者业务。

日志级别：DEBUG、INFO、WARN、ERROR、FATAL。

参数格式：类printf的方式，包括格式字符串（包括参数类型标识）和变参。

隐私参数标识：在格式字符串每个参数中符号后类型前增加{public}、{private}标识。

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

**自从：**

8

**相关模块：**

[HiLog](_hi_log.md)


## 汇总


### 宏定义

| 宏定义名称 | 描述 |
| -------- | -------- |
| [LOG_DOMAIN](_hi_log.md#logdomain)   0 | 日志所对应的业务领域，用于标识业务的子系统、模块。 |
| [LOG_TAG](_hi_log.md#logtag)   NULL | 字符串常量，标识调用所在的类或者业务。 |
| [OH_LOG_DEBUG](_hi_log.md#ohlogdebug)(type, ...)   ((void)[OH_LOG_Print](_hi_log.md#ohlogprint)((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | DEBUG级别写日志，宏封装接口。 |
| [OH_LOG_INFO](_hi_log.md#ohloginfo)(type, ...)   ((void)[OH_LOG_Print](_hi_log.md#ohlogprint)((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | INFO级别写日志，宏封装接口。 |
| [OH_LOG_WARN](_hi_log.md#ohlogwarn)(type, ...)   ((void)[OH_LOG_Print](_hi_log.md#ohlogprint)((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | WARN级别写日志，宏封装接口。 |
| [OH_LOG_ERROR](_hi_log.md#ohlogerror)(type, ...)   ((void)[OH_LOG_Print](_hi_log.md#ohlogprint)((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | ERROR级别写日志，宏封装接口。 |
| [OH_LOG_FATAL](_hi_log.md#ohlogfatal)(type, ...)   ((void)HiLogPrint((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | FATAL级别写日志，宏封装接口。 |


### 枚举

| 枚举名称 | 描述 |
| -------- | -------- |
| [LogType](_hi_log.md#logtype) { LOG_APP= 0 } | 日志类型。 |
| [LogLevel](_hi_log.md#loglevel) { LOG_DEBUG = 3, LOG_INFO = 4, LOG_WARN = 5, LOG_ERROR = 6, LOG_FATAL =7 } | 日志级别。 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_LOG_Print](_hi_log.md#ohlogprint) ([LogType](_hi_log.md#logtype) type, [LogLevel](_hi_log.md#loglevel) level, unsigned int domain, const char \*tag, const char \*fmt,...) __attribute__((__format__(os_log | 写日志接口。 |
| [OH_LOG_IsLoggable](_hi_log.md#ohlogisloggable) (unsigned int domain, const char \*tag, [LogLevel](_hi_log.md#loglevel) level) | 检查指定业务领域、TAG、级别的日志是否可以打印。 |
