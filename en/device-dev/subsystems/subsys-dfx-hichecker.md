# HiChecker Development


## Overview

HiChecker is a framework provided by OpenHarmony for checking code errors and runtime results. It can be used for checking runtime errors during application and system development. This section applies only to the standard system.


## Development Guidelines


### Use Cases

HiChecker is provided for you to check issues that may be easily ignored during development of OpenHarmony applications (including system-built and third-party applications). Such issues include calling of time-consuming functions by key application threads, event distribution and execution timeout in application processes, and ability resource leakage in application processes. The issues are recorded in logs or lead to process crashes explicitly so that you can notice them and take correction measures.


### Available APIs

HiChecker provides the APIs listed in the following table.

  **Table 1** HiChecker APIs

| **API**| **Description**| 
| -------- | -------- |
| uint_64_t&nbsp;RULE_CAUTION_PRINT_LOG<br>=&nbsp;1&lt;&lt;63; | Defines an alarm rule, which is programmed to record a log when an alarm is generated.| 
| uint_64_t&nbsp;RULE_CAUTION_TRIGGER_CRASH&nbsp;=&nbsp;1&lt;&lt;62; | Defines an alarm rule, which is programmed to force the application to exit when an alarm is generated.| 
| uint_64_t&nbsp;RULE_THREAD_CHECK_SLOW_PROCESS&nbsp;=&nbsp;1; | Defines a check rule, which is programmed to check whether any time-consuming function is called.| 
| uint_64_t&nbsp;RULE_CHECK_SLOW_EVENT&nbsp;=&nbsp;1&lt;&lt;32; | Defines a check rule, which is programmed to check whether the event distribution or processing time has exceeded the specified time threshold.| 
| uint_64_t&nbsp;RULE_CHECK_ABILITY_CONNECTION_LEAK&nbsp;=&nbsp;1&lt;&lt;33; | Defines a check rule, which is programmed to check ability leakage.| 
| AddRule(uint_64_t&nbsp;rule)&nbsp;:&nbsp;void | Adds one or more rules. HiChecker detects unexpected operations or gives feedback based on the added rules.| 
| RemoveRule(uint_64_t&nbsp;rule)&nbsp;:&nbsp;void | Removes one or more rules. The removed rules will no longer take effect.| 
| GetRule()&nbsp;:&nbsp;uint_64_t | Obtains a collection of thread, process, and alarm rules that have been added.| 
| Contains(uint_64_t&nbsp;rule)&nbsp;:&nbsp;bool | Checks whether the collection of added rules contains a specific rule. If a thread-level rule is specified, the system only checks whether it is contained in the current thread.| 
| NotifySlowProcess(std::string&nbsp;tag)&nbsp;:&nbsp;void | Notifies your application of a slow process so that your application avoids calling it directly in key threads.| 
| NotifySlowEvent(std::string&nbsp;tag)&nbsp;:&nbsp;void | Notifies your application that event distribution or execution has timed out.| 
| NotifyAbilityConnectionLeak(Caution&nbsp;caution)&nbsp;:&nbsp;void | Notifies your application that AbilityConnection leakage has occurred.| 
| GetTriggerRule()&nbsp;:&nbsp;uint_64_t | Obtains the rule that triggers the current alarm.| 
| GetCautionMsg()&nbsp;:&nbsp;std::string | Obtains the alarm message.| 
| GetStackTrace()&nbsp;:&nbsp;std::string | Obtains the stack when an alarm is triggered.| 


### Development Example

C++

1. Include the following HiChecker header file in the code file:
     
   ```
   #include "hichecker.h"
   ```

   For a non-DFX subsystem, add the **HiviewDFX** field.

     
   ```
   using namespace OHOS::HiviewDFX;
   ```

   Use related APIs through static calls.

     
   ```
   HiChecker::AddRule(Rule::RULE_THREAD_CHECK_SLOW_PROCESS); // Add a rule.
   HiChecker::AddRule(Rule::RULE_CHECK_SLOW_EVENT | Rule::RULE_CAUTION_PRINT_LOG); // Add multiple rules.
   HiChecker::Contains(Rule::RULE_CAUTION_PRINT_LOG); // true
   HiChecker::GetRule(); //RULE_THREAD_CHECK_SLOW_PROCESS | RULE_CHECK_SLOW_EVENT | RULE_CAUTION_PRINT_LOG
   ```

   When a rule is triggered, an alarm is generated based on the rule, and a log is recorded by default.

   - RULE_CAUTION_PRINT_LOG
      The log prints information such as the rule, thread ID, thread name, and stack that triggers the alarm.

   - RULE_CAUTION_TRIGGER_CRASH
      The process exits directly, and the log prints the exit prompt and other auxiliary information.

   Usage of the **Notify** APIs:

   - NotifySlowProcess(std::string tag)
      Notifies your application that a slow process has been called. The following is an example of the input arguments:

        
      ```
      "threadId: xx,threadName:xx,actualTime:xx,delayTime:xx"
      ```

   - NotifySlowEvent(std::string tag)
      Notifies your application that event distribution or execution has timed out. The following is an example of the input arguments:

        
      ```
      "threadId: xx,threadName:xx,eventName:xx,actualTime:xx,delayTime:xx"
      ```

   - NotifyAbilityConnectionLeak(Caution caution)
      Notifies your application that AbilityConnection leakage has occurred. The following example shows that a **Caution** instance is passed into this API.

        
      ```
      Caution caution(Rule::RULE_CHECK_ABILITY_CONNECTION_LEAK , cautionMessage, stackTrace)
      // cautionMessage is similar to other Notify APIs.
      // stackTrace indicates the stack information when leakage occurs.
      ```

2. Add the subsystem dependency to the **BUILD.gn** file that has imported the HiChecker module.
     
   ```
   include_dirs = [ "//base/hiviewdfx/interfaces/innerkits/libhichecker/include" ]
   external_deps = [ "hichecker_native:libhichecker" ]
   ```
