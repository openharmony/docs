# JS Crash (Process Crash) Detection
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @wanghuan2025-->
<!--Designer: @Maplestory-->
<!--Tester: @yufeifei-->
<!--Adviser: @foryourself-->

## Overview

Crash detection is an important monitoring capability in ArkTS applications, which helps you detect and fix problems in applications in a timely manner.


## Detection Principles

When an application exits unexpectedly due to an uncaught exception or error during code execution, it crashes at the point the unhandled exception is thrown, generates a corresponding JS crash log file, and reports the crash event. You can use HiAppEvent to subscribe to [crash events](hiappevent-watcher-crash-events.md). For details about how to analyze JS crash issues, see [Analyzing JS Crashes](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-app-crash-js-way) 


## Constraints

If an exception is thrown in an asynchronous function, no JS crash will occur. You can observe the exception through [ErrorManager](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror).


## Obtaining Logs

Process crash logs are fault logs managed by the FaultLogger module. You can obtain the logs in any of the following ways:

**Method 1: DevEco Studio**

DevEco Studio collects process crash logs from **/data/log/faultlog/faultlogger/** to FaultLog, where logs are displayed by process name, fault, and time. For details about how to obtain logs, see [Fault Log](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-fault-log).

**Method 2: HiAppEvent APIs**

HiAppEvent provides APIs for subscribing to faults. For details, see [Introduction to HiAppEvent](hiappevent-intro.md). You can subscribe to the crash event by referring to [Subscribing to Crash Events (ArkTS)](hiappevent-watcher-crash-events-arkts.md) or [Subscribing to Crash Events (C/C++)](hiappevent-watcher-crash-events-ndk.md), and then read the fault log file content based on the [external_log](hiappevent-watcher-crash-events.md#fields) field of the event.

**Method 3: hdc**

When **Developer options** is enabled, you can run the following command to obtain logs to the local host:
```text
hdc file recv /data/log/faultlog/faultlogger Local path.
```
The fault log file name format is **jscrash-Process name-Process UID-Millisecond-level time .log**.


## Log Specifications


Example of the JS crash log specifications:
```text
Device info:XXX <- Device information
Build info:XXX-XXXX X.X.X.XX(XXXXXXXX) <- Build information
Fingerprint:ed1811f3f5ae13c7262b51aab73ddd01df95b2c64466a204e0d70e6461cf1697 <- Fault features
Timestamp:XXXX-XX-XX XX:XX:XX.XXX <- Timestamp
Module name:com.example.myapplication <- Bundle name/Process name
Version:1.0.0 <- HAP version
VersionCode:1000000 <- Version code
Pid:579 <- Faulty process ID
Uid:0 <- User ID
Process Memory(kB): 1897(Rss) <- Process memory usage
Device Memory(kB): Total 1935820, Free 482136, Available 1204216  <- Device memory information
Reason:TypeError <- Fault cause
Error name:TypeError <- Fault type
Error message:Cannot read property c of undefined <- Error message
Cannot get SourceMap info, dump raw stack: <- The release package does not contain the **SourceMap** file, and the JS stack fails to parse it.
Stacktrace:
    at onPageShow entry (entry/src/main/ets/pages/Index.ets:7:13)  <- Call stack of the exception code
           ^        ^                              ^
         Function name Module package name The row and column numbers in the file

HiLog:
 ^
 Add 1000 lines of HiLog logs related to the exception to the generated crash log file.

```


JS crashes are classified into the following types in the **Reason** field based on exception scenarios:


- **Error**: The most basic error type. Other error types are inherited from this type. The **Error** object has two important attributes: **Error message** and **Error name**. Generally, exceptions of the **Error** type are thrown by developers.

- **TypeError**: The most common error type at runtime, indicating a variable or parameter that is not of the expected type.

- **SyntaxError**: Parsing error, indicating that the syntax does not comply with the syntax specifications of the programming language.

- **RangeError**: Exception thrown when a value exceeds the valid range. Common range errors include the following:

  - The length of an array is negative or exceeds the maximum length.
  - The numeric parameter exceeds the predefined range.
  - The function stack call depth exceeds the upper limit.

- **ReferenceError**: Error thrown when a variable that does not exist is referenced. Each time a variable is created, the variable name and its value are stored in the key-value format. When a variable is referenced, the value will be located based on the key and returned. If the variable referenced cannot be found, **ReferenceError** is thrown.

- **URI Error**: Error occurs when the format of a URL, URN, or other resource identifier is incorrect or the operation is invalid. The following functions are involved: **encodeURI()**, **decodeURI()**, **encodeURIComponent()**, **decodeURIComponent()**, **escape()**, and **unescape()**.

- **OOMError**: Error occurs when the heap memory is insufficient and cannot be allocated for new objects.

- **TerminationError**: Error occurs when the process is forcibly terminated. For example, if there are tasks that are executed for a long time or have an infinite loop in the Taskpool thread, the process is forcibly terminated and this error is reported.

- **AggregateError**: Error occurs when there are multiple errors. It is used in scenarios where multiple errors need to be processed or reported.

- **EvalError**: Error occurs when the **eval()** function execution is abnormal. However, in practice, this error type is rarely used. The engine usually throws **SyntaxError** or **TypeError**.


You can identify the cause of the JS crash, mostly application issues, based on **Error message** and **Stacktrace** in the logs.


### Exception Code Call Stack Formats


The exception code call stack content in release mode is different from that in debug mode. In debug mode, the complete debugging information is retained. In release mode, debugging information is stripped through code optimization and obfuscation.


**Release mode**


In an application built in release mode, the standard format of exception stack information is as follows:


at \<Execution method name> (\<Module name|Dependent module name|Version number|Compilation product path>:\<Line number>:\<Column number>)


The following is an example:


```
at onPageShow (entry|har1|1.0.0|src/main/ets/pages/Index.ts:7:13)
```


Format description:


1. **at**: fixed start identifier of the stack call chain.

2. Execution method name: **onPageShow** indicates the name of the calling method that triggers an exception.

3. The structure of the compilation product is as follows:
   - Compilation product path: For details, see [Sourcemap Format](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-exception-stack-parsing-principle#section1145914292713).
   - File type: The file name extension is **.ts**. (For .js files, the exception can be located directly without SourceMap mapping.)

4. Row and column number: Colons (:\) are used to separate row and column numbers of the exception.


**Debug mode**


In an application built in debug mode or a release application whose exception stack is translated using source map, the standard exception stack information format is as follows:


at \<Execution method name> \<Dependent module name> (\<Source code path>:\<Line number>:\<Column number>)


The following is an example:


```
at onPageShow har1 (har1/src/main/ets/pages/Index.ets:7:13)
```


Format description:


1. **at**: fixed start identifier of the stack call chain.

2. Execution method name: **onPageShow** indicates the name of the calling method that triggers an exception.

3. Dependent module name: **har1** indicates the name of the module to which the source code path belongs.

4. The source code path structure is as follows:
   - Source code path: Source code file path based on the project directory.
   - File type: The file name extension is **.ets**.

5. Row and column number: Colons (:\) are used to separate row and column numbers of the exception.
