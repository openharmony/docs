# HiLog开发指导


## 概述

HiLog是OpenHarmony日志系统，提供给系统框架、服务、以及应用打印日志，记录用户操作、系统运行状态等。

本章节内容对标准系统类设备（参考内存≥128MiB）适用。


## 接口说明

  **表1** C++、C的函数接口

| C++ |  | C | 
| -------- | -------- | -------- |
| 类 | 方法 | 方法/宏 | 
| HiLog | int&nbsp;Debug(const&nbsp;HiLogLabel&nbsp;&amp;label,&nbsp;const&nbsp;char&nbsp;\*fmt,&nbsp;...) | HILOG_DEBUG(type,&nbsp;...) | 
|  | int&nbsp;Info(const&nbsp;HiLogLabel&nbsp;&amp;label,&nbsp;const&nbsp;char&nbsp;\*fmt,&nbsp;...) | HILOG_INFO(type,&nbsp;...) | 
|  | int&nbsp;Warn(const&nbsp;HiLogLabel&nbsp;&amp;label,&nbsp;const&nbsp;char&nbsp;\*fmt,&nbsp;...) | HILOG_WARN(type,&nbsp;...) | 
|  | int&nbsp;Error(const&nbsp;HiLogLabel&nbsp;&amp;label,&nbsp;const&nbsp;char&nbsp;\*fmt,&nbsp;...) | HILOG_ERROR(type,&nbsp;...) | 
|  | int&nbsp;Fatal(const&nbsp;HiLogLabel&nbsp;&amp;label,&nbsp;const&nbsp;char&nbsp;\*fmt,&nbsp;...) | HILOG_FATAL(type,&nbsp;...) | 
|  | NA | int&nbsp;HiLogPrint(LogType&nbsp;type,&nbsp;LogLevel&nbsp;level,&nbsp;unsigned&nbsp;int&nbsp;domain,&nbsp;const&nbsp;char&nbsp;\*tag,&nbsp;const&nbsp;char&nbsp;\*fmt,&nbsp;...) | 
|  | boolean&nbsp;IsLoggable(unsigned&nbsp;int&nbsp;domain,&nbsp;const&nbsp;char&nbsp;\*tag,&nbsp;LogLevel&nbsp;level) | bool&nbsp;HiLogIsLoggable(unsigned&nbsp;int&nbsp;domain,&nbsp;const&nbsp;char&nbsp;\*tag,&nbsp;LogLevel&nbsp;level) | 
| HiLogLabel | struct&nbsp;HiLogLabel | LOG_DOMAIN<br/>LOG_TAG | 

  **表2** C++接口说明函数参数和功能

| 类 | 方法 | 描述 | 
| -------- | -------- | -------- |
| HiLog | int&nbsp;Debug(const&nbsp;HiLogLabel&nbsp;&amp;label,&nbsp;const&nbsp;char&nbsp;\*fmt,&nbsp;...) | 功能：输出&nbsp;debug&nbsp;级别日志。<br/>输入参数：<br/>-&nbsp;label：用于标识输出日志的类型、业务领域、TAG。<br/>-&nbsp;format：常量格式字符串，包含参数类型、隐私标识。未加隐私标识的缺省为隐私参数。<br/>-&nbsp;fmt：格式化变参描述字符串。<br/>输出参数：无。<br/>返回值：大于等于0，成功；小于0，失败。 | 
|  | int&nbsp;Info(const&nbsp;HiLogLabel&nbsp;&amp;label,&nbsp;const&nbsp;char&nbsp;\*fmt,&nbsp;...) | 功能：输出&nbsp;info&nbsp;级别日志。<br/>参数说明同&nbsp;Debug&nbsp;接口。 | 
|  | int&nbsp;Warn(const&nbsp;HiLogLabel&nbsp;&amp;label,&nbsp;const&nbsp;char&nbsp;\*fmt,&nbsp;...) | 功能：输出&nbsp;warn&nbsp;级别日志。<br/>参数说明同&nbsp;Debug&nbsp;接口。 | 
|  | int&nbsp;Error(const&nbsp;HiLogLabel&nbsp;&amp;label,&nbsp;const&nbsp;char&nbsp;\*fmt,&nbsp;...) | 功能：输出&nbsp;error&nbsp;级别日志。<br/>参数说明同&nbsp;Debug&nbsp;接口。 | 
|  | int&nbsp;Fatal(const&nbsp;HiLogLabel&nbsp;&amp;label,&nbsp;const&nbsp;char&nbsp;\*fmt,&nbsp;...) | 功能：输出&nbsp;fatal&nbsp;级别日志。<br/>参数说明同&nbsp;Debug&nbsp;接口。 | 
|  | boolean&nbsp;IsLoggable(unsigned&nbsp;int&nbsp;domain,&nbsp;const&nbsp;char&nbsp;\*tag,&nbsp;LogLevel&nbsp;level) | 功能：检查指定业务领域、TAG、级别的日志是否可以打印。<br/>输入参数：<br/>-&nbsp;domain：指定日志业务领域。<br/>-&nbsp;tag:&nbsp;指定日志TAG。<br/>-&nbsp;level:&nbsp;指定日志level。<br/>输出参数：无。<br/>返回值：如果指定domain、tag、level日志可以打印则返回true；否则返回false。 | 
| HiLogLabel | struct&nbsp;HiLogLabel | 功能：初始化日志标签参数。<br/>成员参数：<br/>-&nbsp;type:&nbsp;指定日志type。<br/>-&nbsp;domain：指定日志业务领域。<br/>-&nbsp;tag:&nbsp;指定日志TAG。 | 


## 开发实例


### C使用示例

1. 在.c源文件中，包含hilog头文件：
     
   ```
   #include "hilog/log.h"
   ```

     定义domain、tag：
     
   ```
   #undef LOG_DOMAIN
   #undef LOG_TAG
   #define LOG_DOMAIN 0xD003200  // 标识业务领域，范围0xD000000~0xD0FFFFF
   #define LOG_TAG "MY_TAG"
   ```

     打印日志：
     
   ```
   HILOG_INFO(LOG_CORE, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
   ```

2. 编译设置，在BUILD.gn里增加子系统SDK依赖：
     
   ```
   external_deps = [ "hilog:libhilog" ]
   ```


### C++使用示例

1. 在.h类定义头文件中，包含hilog头文件：
     
   ```
   #include "hilog/log.h"
   ```

     如果类头文件中需要日志打印，在头文件中类定义起始处 定义 LABEL：
     
   ```
   class MyClass {
   static constexpr OHOS::HiviewDFX::HiLogLabel LABEL = {LOG_CORE, 0xD003200, "MY_TAG"}; 
   ......
   }
   ```

     如果类头文件中没有日志打印，在类实现文件中 定义 LABEL：
     
   ```
   using namespace OHOS::HiviewDFX;
   static constexpr HiLogLabel LABEL = {LOG_CORE, 0xD003200, "MY_TAG"}; 
   ```

     打印日志：
     
   ```
   HiLog::Info(LABEL, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
   ```

2. 编译设置，在BUILD.gn里增加子系统SDK依赖：
     
   ```
   external_deps = [ "hiviewdfx:libhilog" ]
   ```
