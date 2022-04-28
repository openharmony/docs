# HiChecker开发指导


## 概述

HiChecker是OpenHarmony提供的用于检测代码错误使用方式和运行结果的一种检测框架，可在应用和系统开发阶段用于运行时的缺陷扫描。本章节内容适用于标准系统。


## 开发指导


### 场景介绍

HiChecker的主要作用是给基于OpenHarmony的应用（包含系统和三方应用）开发者提供一套检测工具，用来检测应用程序开发过程中容易被人忽略的部分问题，包括应用关键线程调用耗时函数、应用进程中事件出现分发、执行超时以及应用进程中元能力资源泄露等，检测到的问题以日志记录或进程崩溃等形式展现出来以便开发者发现并修改相关问题。


### 接口说明

HiChecker提供的主要接口及功能如下：

  **表1** HiChecker函数接口

| **类** | **方法（包括返回值、方法名、参数列表）** | **描述** | 
| -------- | -------- | -------- |
| HiChecker | uint_64_t&nbsp;RULE_CAUTION_PRINT_LOG<br/>=&nbsp;1&lt;&lt;63; | 告警规则，当有告警时记录日志。 | 
|| uint_64_t&nbsp;RULE_CAUTION_TRIGGER_CRASH&nbsp;=&nbsp;1&lt;&lt;62; | 告警规则，当有告警时让应用退出。 | 
|| uint_64_t&nbsp;RULE_THREAD_CHECK_SLOW_PROCESS&nbsp;=&nbsp;1; | 检测规则，检测是否有耗时函数被调用。 | 
|| uint_64_t&nbsp;RULE_CHECK_SLOW_EVENT&nbsp;=&nbsp;1&lt;&lt;32; | 检测规则，检测有事件分发或处理超过规定的时间阈值。 | 
|| uint_64_t&nbsp;RULE_CHECK_ABILITY_CONNECTION_LEAK&nbsp;=&nbsp;1&lt;&lt;33; | 检测规则，检测ability泄露。 | 
|| AddRule(uint_64_t&nbsp;rule)&nbsp;:&nbsp;void | 添加一条或者多条规则到系统，系统根据添加的规则进行检测或反馈。 | 
|| RemoveRule(uint_64_t&nbsp;rule)&nbsp;:&nbsp;void | 删除一组规则，删除的规则后续将不再生效。 | 
|| GetRule()&nbsp;:&nbsp;uint_64_t | 获取当前线程规则、进程规则、告警规则的合集。 | 
|| Contains(uint_64_t&nbsp;rule)&nbsp;:&nbsp;bool | 当前已添加的规则集中是否包含了某一个特定的规则,&nbsp;如果传入的rule是线程级别的rule，仅查询当前线程中是否包含。 | 
|| NotifySlowProcess(std::string&nbsp;tag)&nbsp;:&nbsp;void | 通知有慢处理，通知系统当前代码调用了耗时较长的慢处理流程，以告知应用重要线程中尽量避开直接调用。 | 
|| NotifySlowEvent(std::string&nbsp;tag)&nbsp;:&nbsp;void | 通知发生事件分发超时或执行超时。 | 
|| NotifyAbilityConnectionLeak(Caution&nbsp;caution)&nbsp;:&nbsp;void | 通知发生AbilityConnection泄露。 | 
| Caution | GetTriggerRule()&nbsp;:&nbsp;uint_64_t | 获取触发当前告警的检测规则。 | 
|| GetCautionMsg()&nbsp;:&nbsp;std::string | 获取更多辅助信息。 | 
|| GetStackTrace()&nbsp;:&nbsp;std::string | 获取告警触发时的堆栈信息。 | 


### 开发实例

C++使用示例

1. 在使用hichecker功能相关的代码文件中，包含hichecker头文件：
     
   ```
   #include "hichecker.h"
   ```

   如果非DFX子系统，需要加上HiviewDFX域。

     
   ```
   using namespace OHOS::HiviewDFX;
   ```

   通过静态调用使用相关接口。

     
   ```
   HiChecker::AddRule(Rule::RULE_THREAD_CHECK_SLOW_PROCESS); //添加一条规则
   HiChecker::AddRule(Rule::RULE_CHECK_SLOW_EVENT | Rule::RULE_CAUTION_PRINT_LOG); //添加多条规则
   HiChecker::Contains(Rule::RULE_CAUTION_PRINT_LOG); // true
   HiChecker::GetRule(); //RULE_THREAD_CHECK_SLOW_PROCESS | RULE_CHECK_SLOW_EVENT | RULE_CAUTION_PRINT_LOG
   ```

   当规则被触发时，根据添加的告警规则执行告警(默认为写日志)。

   - RULE_CAUTION_PRINT_LOG
      日志输出触发告警的规则、线程ID、线程名、堆栈等信息。

   - RULE_CAUTION_TRIGGER_CRASH
      进程直接退出,日志输出退出提示以及辅助信息。

   通知接口的使用：

   - NotifySlowProcess(std::string tag)
      通知系统当前代码调用了耗时较长的慢处理流程，入参示例：

        
      ```
      “threadId：xx,threadName:xx,actualTime:xx,delayTime:xx“
      ```

   - NotifySlowEvent(std::string tag)
      通知发生事件分发超时或执行超时，入参示例：

        
      ```
      “threadId：xx,threadName:xx,eventName:xx,actualTime:xx,delayTime:xx“
      ```

   - NotifyAbilityConnectionLeak(Caution caution)
      通知发生AbilityConnection泄露，入参示例：传入一个Caution实例。

        
      ```
      Caution caution(Rule::RULE_CHECK_ABILITY_CONNECTION_LEAK , cautionMessage, stackTrace)
      // cautionMessage与其它通知接口类似
      // stackTrace为发生泄露时的堆栈信息
      ```

2. 编译设置，在引入hichecker相关模块的BUILD.gn里增加子系统依赖：
     
   ```
   include_dirs = [ "//base/hiviewdfx/interfaces/innerkits/libhichecker/include" ]
   external_deps = [ "hichecker_native:libhichecker" ]
   ```
