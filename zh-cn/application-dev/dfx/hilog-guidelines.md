# HiLog开发指导  
## 概述
HiLog是OpenHarmony日志系统，提供给系统框架、服务、以及应用打印日志，记录用户操作、系统运行状态等。
> **说明：**
> 仅当开发者使用Native API开发应用时，可参考本开发指导。API文档请参考[HiLog Native API参考](../reference/native-apis/_hi_log.md)

## 接口说明
| 方法/宏 | 接口描述 | 
| -------- | -------- |
| int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...) | 输出指定日志类型、日志级别、业务领域、Tag的hilog日志，并且按照printf格式类型和隐私指示确定需要输出的变参。<br/>输入参数:见参数解析。<br/>输出参数:&nbsp;无<br/>返回值：打印成功则返回日志总字节数；失败则返回-1。| 
| #define OH_LOG_DEBUG(type, ...) ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__))| DEBUG级别写日志，宏封装接口 | 
| #define OH_LOG_INFO(type, ...) ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | INFO级别写日志，宏封装接口 | 
| #define OH_LOG_WARN(type, ...) ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | WARN级别写日志，宏封装接口 | 
| #define OH_LOG_ERROR(type, ...) ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | ERROR级别写日志，宏封装接口 | 
| #define OH_LOG_FATAL(type, ...) ((void)OH_LOG_Print((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, \__VA_ARGS__)) | FATAL级别写日志，宏封装接口 | 
| bool OH_LOG_IsLoggable(unsigned int domain, const char *tag, LogLevel level) | 功能：检查指定业务领域、TAG、级别的日志是否可以打印。<br/>输入参数：见参数解析。<br/>输出参数：无<br/>返回值：如果指定domain、tag、level日志可以打印则返回true；否则返回false。 |
## 参数解析

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | enum   | 是   | 日志打印类型枚举，应用日志默认为LOG_APP。 |
| level  | enum   | 是   | 日志打印等级枚举,见LogLevel。 |
| domain | number | 是   | 日志对应的领域标识，范围是0x0~0xFFFF。<br/>建议开发者在应用内根据需要自定义划分。  |
| tag    | string | 是   | 指定日志标识，可以为任意字符串，建议用于标识调用所在的类或者业务行为。 |
| fmt    | string | 是   | 格式字符串，用于日志的格式化输出。格式字符串中可以设置多个参数，参数需要包含参数类型、隐私标识。<br/>隐私标识分为{public}和{private}，缺省为{private}。标识{public}的内容明文输出，标识{private}的内容以\<private>过滤回显。 |
| args   | any[]  | 是   | 与格式字符串format对应的可变长度参数列表。参数数目、参数类型必须与格式字符串中的标识一一对应。 |
## LogLevel
日志级别。

| 名称  |   值   | 说明                                                         |
| ----- | ------ | ------------------------------------------------------------ |
| DEBUG | 3      | 详细的流程记录，通过该级别的日志可以更详细地分析业务流程和定位分析问题。 |
| INFO  | 4      | 用于记录业务关键流程节点，可以还原业务的主要运行过程；<br/>用于记录可预料的非正常情况信息，如无网络信号、登录失败等。<br/>这些日志都应该由该业务内处于支配地位的模块来记录，避免在多个被调用的模块或低级函数中重复记录。 |
| WARN  | 5      | 用于记录较为严重的非预期情况，但是对用户影响不大，应用可以自动恢复或通过简单的操作就可以恢复的问题。 |
| ERROR | 6      | 应用发生了错误，该错误会影响功能的正常运行或用户的正常使用，可以恢复但恢复代价较高，如重置数据等。 |
| FATAL | 7      | 重大致命异常，表明应用即将崩溃，故障无法恢复。 
## 开发示例
1.在CMakeLists.txt中新增libhilog_ndk.z.so链接：
```
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
2.在源文件中包含hilog头文件, 并定义domain、tag宏：
```c++
#include "hilog/log.h"
```

```c++
#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x3200  // 全局domain宏，标识业务领域
#define LOG_TAG "MY_TAG"   // 全局tag宏，标识模块日志tag
```
3.打印日志，以打印ERROR级别的日志为例：
```c++
OH_LOG_ERROR(LOG_APP, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
```
4.输出结果：
```
12-11 12:21:47.579  2695 2695 E A03200/MY_TAG: Failed to visit <private>, reason:11.
```