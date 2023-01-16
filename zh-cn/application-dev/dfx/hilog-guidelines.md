# HiLog开发指导  
## 概述
HiLog是OpenHarmony日志系统，提供给系统框架、服务、以及应用打印日志，记录用户操作、系统运行状态等。
> **说明：**
> 仅当开发者使用Native API开发应用时，可参考本开发指导。API文档请参考[HiLog Native API参考](../reference/native-apis/_hi_log.md)

## 接口说明
| 方法/宏 | 接口描述 | 
| -------- | -------- |
| int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...) | 输出指定日志类型、日志级别、业务领域、Tag的hilog日志，并且按照printf格式类型和隐私指示确定需要输出的变参。| 
| #define OH_LOG_DEBUG(type, ...) ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__))| DEBUG级别写日志，宏封装接口 | 
| #define OH_LOG_INFO(type, ...) ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | INFO级别写日志，宏封装接口 | 
| #define OH_LOG_WARN(type, ...) ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | WARN级别写日志，宏封装接口 | 
| #define OH_LOG_ERROR(type, ...) ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | ERROR级别写日志，宏封装接口 | 
| #define OH_LOG_FATAL(type, ...) ((void)OH_LOG_Print((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | FATAL级别写日志，宏封装接口 | 
| bool OH_LOG_IsLoggable(unsigned int domain, const char *tag, LogLevel level) | 功能：检查指定业务领域、TAG、级别的日志是否可以打印。<br/>输入参数：<br/>-&nbsp;domain：指定日志业务领域。<br/>-&nbsp;tag:&nbsp;指定日志TAG。<br/>-&nbsp;level:&nbsp;指定日志level。<br/>输出参数：无<br/>返回值：如果指定domain、tag、level日志可以打印则返回true；否则返回false。 | 

## 开发示例
1.在源文件中包含hilog头文件：
```c++
#include "hilog/log.h"
```
2.定义domain、tag宏：
```c++
#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x3200  // 标识业务领域，范围0xD0000~0xDFFFF
#define LOG_TAG "MY_TAG"
```
3.打印日志，以打印INFO级别的日志为例：
```c++
OH_LOG_INFO(LOG_APP, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
```
4.输出结果：
```
12-11 12:21:47.579  2695 2695 I A03200/MY_TAG: Failed to visit <private>, reason:11.
```