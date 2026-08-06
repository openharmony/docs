# JS Crash (Process Crash) Detection

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @wanghuan2025-->
<!--Designer: @Maplestory91-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=deda4f19015dd8c61f2e0d855c3c53292d681c7b translatedAt=2026-07-31T01:35:29.798Z pushedAt=2026-07-31T08:25:40.850Z -->

## Overview

Crash detection is an important monitoring capability in ArkTS applications, which helps you detect and fix problems in applications in a timely manner.

## Detection Principles

ArkCompiler runtime captures process exceptions. The fault log generation process is as follows:

1. During code execution, if the application crashes due to uncaptured exceptions or errors, ArkCompiler runtime will capture these exceptions.

2. ArkCompiler runtime collects fault information and reports it to HiView.

3. The HiView DFX process supplements information that only it has permission to obtain (such as the overall memory status of the device and the app page switching trace), generates the corresponding crash log file, and stores it in the `/data/log/faultlog/faultlogger` directory.

4. To report a crash event, you can use HiAppEvent to subscribe to the [crash event](hiappevent-watcher-crash-events.md).  

## Constraints

Throwing an exception in an asynchronous function modified by **async** does not cause a JS crash that leads to an app crash. You can observe the exception through [errorManager.on('error')](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror). For sample code, see [Exception Handling in Async Functions](../arkts-utils/arkts-runtime-faq.md#exception-handling-in-async-functions). Starting from **API version 26.0.0**, when the app has registered ErrorManager to observe exceptions, exceptions other than non-catchable types (currently only OutOfMemoryError) will not generate HiAppEvent events for reporting.

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

The fault log file name format is **jscrash-Process name-Process UID-Millisecond-level time.log**.

## Log Specifications

|Field|Description|Initial API Version|Mandatory|Optional|
|---|---|---|---|---|
| Device info | Device information.| 8 | Yes| - |
| Build info | Version information.| 8 | Yes| - |
| DeviceDebuggable | Whether the system version of the device can be debugged, which is irrelevant to **Developer options**.| 23 | Yes| - |
| Fingerprint | Fault feature, which is a hash value for faults of the same type.| 8 | Yes| - |
| Timestamp | Timestamp.| 8 | Yes| - |
| Module name | Bundle name. | 8 | Yes | - |
| ReleaseType | Application version type. The value **release** indicates that the application is a [release-type application](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916), and the value **debug** indicates that the application is a [debug-type application](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916).| 23 | Yes| - |
| CpuAbi | ABI type.| 23 | Yes| - |
| Version | HAP version.| 8 | Yes| - |
| VersionCode | Version code.| 8 | Yes| - |
| IsSystemApp | Whether the application is a system application.| 23 | Yes| - |
| Pid | ID of the faulty process.| 8 | Yes| - |
| Uid | User ID.| 8 | Yes| - |
| Process name | Name of the faulty process. | 26 | Yes | - |
| App running unique id | Unique ID associated with the app at runtime. | 26.0.0 | Yes | - |
| Process life time | Lifetime of the faulty process.| 22 | Yes| - |
| Process Memory(kB) | Process memory usage.| 20 | Yes| - |
| Device Memory(kB) | Device memory information.| 20 | No| This field depends on the maintenance and debugging service process. If the maintenance and debugging service process stops or the device restarts when a fault occurs, this field does not exist. For details, see [Detection Principles](#detection-principles).|
| Page switch history | Page switching history.| 20 | No| If the maintenance and debugging service process is faulty or the switching history is not cached, this field is not displayed.|
| Reason | Fault cause.| 8 | Yes| - |
| Error name | Fault type.| 8 | Yes| - |
| Error message | Error message.| 8 | Yes| - |
| Stacktrace | Fault stack.| 8 | Yes| - |
| HybridStack | Cross-language fault stack between C++ and JS.| 22 | No| In the ARM 64-bit system, if the stacktrace is a JS stack, this field is displayed. A maximum of 256 layers can be displayed.|
| SubmitterStacktrace | Submitter thread stack.| 20 | No| By default, the asynchronous thread stack tracing functionality is enabled only in the ARM 64-bit system.<br>For versions earlier than API version 22, the functionality of submitting asynchronous tasks by third-party and system applications through [libuv](../reference/native-lib/libuv.md) and [ffrt](../reference/apis-ffrt-kit/capi-ffrt.md) is enabled only in the debug version by default.<br>Since API version 22, the functionality of submitting asynchronous tasks by third-party applications through **libuv** is enabled by default in both debug and release versions. The functionality of submitting asynchronous tasks by third-party and system applications through **ffrt** is enabled by default only in the debug version.|
| HiLog | HiLog logs printed before the fault occurs. A maximum of 1000 lines can be printed.| 20 | Yes| - |
| AsyncStack | Promise stack.| 23 | No| In ARM64, if the promise stack is enabled, this field is contained.|
| ModuleImportStack | Module loading chain. | 26.0.0 | No | On ARM 64-bit systems, this field is included if the [module loading chain debug switch](../arkts-utils/arkts-module-debug.md) is enabled. |

Example of the JS crash log specifications:

```text
Device info:XXX <- Device information
Build info:XXX-XXXX X.X.X.XX(XXXXXXXX) <- Build information
DeviceDebuggable:No <- Whether the system version of the device can be debugged.
Fingerprint:ed1811f3f5ae13c7262b51aab73ddd01df95b2c64466a204e0d70e6461cf1697 <- Fault features
Timestamp:XXXX-XX-XX XX:XX:XX.XXX <- Timestamp
Module name:com.example.myapplication <- Package name
ReleaseType:release <- Application version type.
CpuAbi:arm64-v8a <- ABI type.
Version:1.0.0 <- HAP version
VersionCode:1000000 <- Version code
IsSystemApp:No <- Whether the application is a system application.
Pid:579 <- Faulty process ID
Uid:0 <- User ID
Process name:com.example.myapplication <- Process name
App running unique id:124500628566978194 <- Unique ID associated with the app runtime
Process life time:1s  <- Process life time
Process Memory(kB): 1897(Rss) <- Process memory usage
Device Memory(kB): Total 1935820, Free 482136, Available 1204216  <- Device memory information (optional)
Page switch history: <- Page switch history
  14:08:30:327 /ets/pages/Index:JsError
  14:08:28:986 /ets/pages/Index
  14:08:07:606 :leaves foreground
  14:08:06:246 /ets/pages/Index:AppFreeze
  14:08:01:955 :enters foreground
Reason:TypeError <- Fault cause
Error name:TypeError <- Fault type
Error message:Cannot read property c of undefined <- Error message
Cannot get SourceMap info, dump raw stack: <- The release package does not contain the SourceMap file, and the JS stack fails to parse it.
Stacktrace:
    at onPageShow entry (entry/src/main/ets/pages/Index.ets:7:13)  <- Call stack of the exception code
           ^        ^                              ^
         Function name Module package name The row and column numbers in the file
HybridStack: <- Cross-language call stack between C++ and JS
#00 pc 00000000004a814c /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#01 pc 00000000004a6460 /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#02 pc 00000000006a94e0 /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#03 pc 0000000000334d38 /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#04 pc 0000000000253da8 /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::ObjectFactory::GetJSError(panda::ecmascript::base::ErrorType const&, char const*, panda::ecmascript::StackCheck)+292)(173710293c3751dc676d24264bfac393)
#05 pc 00000000005c25d4 /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#06 pc 0000000000de3efc /system/lib64/module/arkcompiler/stub.an(RTStub_PushCallArgsAndDispatchNative+44)
#07 pc 000000000044843c /system/lib64/module/arkcompiler/stub.an(BCStub_HandleCallarg1Imm8V8StwCopy+340)
#08 at onPageShow entry (entry/src/main/ets/pages/Index.ets:7:13) <- JS code executed when an exception occurs
#09 pc 00000000001e620c /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#10 pc 00000000009ad560 /system/lib64/platformsdk/libark_jsruntime.so(panda::FunctionRef::Call(panda::ecmascript::EcmaVM const*, panda::Local<panda::JSValueRef>, panda::Local<panda::JSValueRef> const*, int)+456)(173710293c3751dc676d24264bfac393)
#11 pc 0000000000a63f14 /system/lib64/platformsdk/libace_compatible.z.so(e236e26a38ac303814f43a3c8fc9b0a6)
#12 pc 0000000000d836bc /system/lib64/platformsdk/libace_compatible.z.so(e236e26a38ac303814f43a3c8fc9b0a6)
#13 pc 000000000111f338 /system/lib64/platformsdk/libace_compatible.z.so(e236e26a38ac303814f43a3c8fc9b0a6)
...

HiLog:
 ^
 HiLog logs generated before the fault occurs are added to the generated crash log file. A maximum of 1000 lines are supported.

```

### Log Specifications for Asynchronous Thread Stack Tracing Faults

When an asynchronous thread crashes, the stack of the thread that submits the asynchronous task is also printed to locate the fault. The call stack of the crash thread and that of the submission thread are separated by **SubmitterStacktrace**. The following is an example process crash log archived by DevEco Studio in FaultLog:

> **NOTE**
>
> By default, the asynchronous thread stack tracing functionality is enabled only in the ARM 64-bit system, which can be used to print native stacks for JS crashes.
>
> For versions earlier than API version 22, the functionality of submitting asynchronous tasks by third-party and system applications through **libuv** and **ffrt** is enabled only in the debug version by default.
>
> Since API version 22, the functionality of submitting asynchronous tasks by third-party applications through **libuv** is enabled by default in both debug and release versions. The functionality of submitting asynchronous tasks by third-party and system applications through **ffrt** is enabled by default only in the debug version.
The specifications of the **Stacktrace** field are as follows:

```text
Stacktrace:
#00 pc 00000000004d9d4c /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::Backtrace(std::__h::basic_ostringstream<char, std::__h::char_traits<char>, std::__h::allocator<char>>&, bool)+92)(723d1618fe2567539bed3038ccfe92d8)
#01 pc 000000000038ddcc /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::JsStackInfo::BuildJsStackTrace(panda::ecmascript::JSThread*, bool, panda::ecmascript::JSHandle<panda::ecmascript::JSObject> const&, bool, unsigned int)+2952)(723d1618fe2567539bed3038ccfe92d8)
#02 pc 000000000038c70c /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::base::ErrorHelper::ErrorCommonConstructor(panda::ecmascript::EcmaRuntimeCallInfo*, panda::ecmascript::base::ErrorType const&)+1704)(723d1618fe2567539bed3038ccfe92d8)
#03 pc 000000000038c03c /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::builtins::BuiltinsError::ErrorConstructor(panda::ecmascript::EcmaRuntimeCallInfo*)+40)(723d1618fe2567539bed3038ccfe92d8)
#04 pc 00000000001b5d90 /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::ObjectFactory::NewJSError(panda::ecmascript::JSHandle<panda::ecmascript::GlobalEnv> const&, panda::ecmascript::base::ErrorType const&, panda::ecmascript::JSHandle<panda::ecmascript::EcmaString> const&, panda::ecmascript::StackCheck)+984)(723d1618fe2567539bed3038ccfe92d8)
#05 pc 000000000093274c /system/lib64/platformsdk/libark_jsruntime.so(panda::Exception::Error(panda::ecmascript::EcmaVM const*, panda::Local<panda::StringRef>)+244)(723d1618fe2567539bed3038ccfe92d8)
#06 pc 0000000000066398 /system/lib64/platformsdk/libace_napi.z.so(napi_throw_error+152)(c91850afe3629242ed12712b76be08f1)
#07 pc 00000000000020fc /data/storage/el1/bundle/libs/arm64/libentry.so(02cecfd8fd280aeaa1af7b9d1227afeac0ec4356)   <- Exception is thrown
#08 pc 00000000000890c0 /system/lib64/platformsdk/libruntime.z.so(std::__h::__function::__func<OHOS::AbilityRuntime::OHOSJsEnvironmentImpl::PostTaskToHandler(char const*, void (*)(void*, int), void*, int, int)::$_0, std::__h::allocator<OHOS::AbilityRuntime::OHOSJsEnvironmentImpl::PostTaskToHandler(char const*, void (*)(void*, int), void*, int, int)::$_0>, void ()>::operator()() (.3ec3b6b3a88f13b2aa6c613a7afa022b)+128)(50df26f49d9c067da9cf79b804f136ec)
========SubmitterStacktrace========    <- After an asynchronous thread crashes, the stack of the thread that submits the asynchronous task is also printed.
#00 pc 0000000000012cd0 /system/lib64/platformsdk/libuv.so(uv_queue_work+456)(e077582fac1bf7463ca5539c0a2b678a)
#01 pc 0000000000001fd0 /data/storage/el1/bundle/libs/arm64/libentry.so(02cecfd8fd280aeaa1af7b9d1227afeac0ec4356)
#02 pc 000000000004d69c /system/lib64/platformsdk/libace_napi.z.so(panda::JSValueRef ArkNativeFunctionCallBack<true>(panda::JsiRuntimeCallInfo*)+220)(c91850afe3629242ed12712b76be08f1)
#03 pc 0000000000d08e90 /system/lib64/module/arkcompiler/stub.an(RTStub_PushCallArgsAndDispatchNative+44)
#04 pc 000000000036ae70 /system/lib64/module/arkcompiler/stub.an(BCStub_HandleCallthis2Imm8V8V8V8StwCopy+436)
#05 at anonymous (entry|entry|1.0.0|src/main/ets/pages/Index.ts:57:79)
#06 pc 000000000029e144 /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::InterpreterAssembly::Execute(panda::ecmascript::EcmaRuntimeCallInfo*)+540)(723d1618fe2567539bed3038ccfe92d8)
#07 pc 0000000000327eac /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::JSFunction::Call(panda::ecmascript::EcmaRuntimeCallInfo*) (.419.extracted)+452)(723d1618fe2567539bed3038ccfe92d8)
#08 pc 0000000000940c18 /system/lib64/platformsdk/libark_jsruntime.so(panda::FunctionRef::Call(panda::ecmascript::EcmaVM const*, panda::Local<panda::JSValueRef>, panda::Local<panda::JSValueRef> const*, int)+1988)(723d1618fe2567539bed3038ccfe92d8)
#09 pc 00000000009ce8d8 /system/lib64/platformsdk/libace_compatible.z.so(OHOS::Ace::Framework::JsiFunction::Call(OHOS::Ace::Framework::JsiRef<OHOS::Ace::Framework::JsiValue>, int, OHOS::Ace::Framework::JsiRef<OHOS::Ace::Framework::JsiValue>*, bool) const+700)(cdb4712f9d1d7fda83faae9d393a244e)
#10 pc 0000000000972a38 /system/lib64/platformsdk/libace_compatible.z.so(OHOS::Ace::Framework::JsFunction::ExecuteJS(int, OHOS::Ace::Framework::JsiRef<OHOS::Ace::Framework::JsiValue>*, bool)+384)(cdb4712f9d1d7fda83faae9d393a244e)
#11 pc 0000000000e1f590 /system/lib64/platformsdk/libace_compatible.z.so(OHOS::Ace::Framework::JsClickFunction::Execute(OHOS::Ace::GestureEvent&)+3396)(cdb4712f9d1d7fda83faae9d393a244e)
#12 pc 0000000001079384 /system/lib64/platformsdk/libace_compatible.z.so(cdb4712f9d1d7fda83faae9d393a244e)
#13 pc 00000000026e1b28 /system/lib64/platformsdk/libace_compatible.z.so(cdb4712f9d1d7fda83faae9d393a244e)
#14 pc 0000000000f435a8 /system/lib64/platformsdk/libace_compatible.z.so(OHOS::Ace::NG::TextPattern::ActTextOnClick(OHOS::Ace::GestureEvent&)+164)(cdb4712f9d1d7fda83faae9d393a244e)
#15 pc 0000000002751134 /system/lib64/platformsdk/libace_compatible.z.so(cdb4712f9d1d7fda83faae9d393a244e)
```

### Page switch history

Since API version 20, the **Page switch history** field is used to record the page switch history. A maximum of 10 latest history records can be recorded in the fault log. The format of a record is as follows:

```text
  14:08:30:327 /ets/pages/Index:JsError
       ^             ^            ^
    Switching time   Page URL   Page name
```

> **NOTE**
>
> The child page's name is available only when it is navigated to through **Navigation**. The page name is defined in the [system routing table](../ui/arkts-navigation-cross-package.md#system-routing-table).
>
> When the application switches between the foreground and background, the corresponding page URL is empty, but **enters foreground** and **leaves foreground** are displayed as special page names.
>
> **enters foreground**: The application runs in the foreground.
>
> **leaves foreground**: The application runs in the background.

### Reason

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

```text
at onPageShow (entry|har1|1.0.0|src/main/ets/pages/Index.ts:7:13)
```

Format description:

1. **at**: fixed start identifier of the stack call chain.

2. Execution method name: **onPageShow** indicates the name of the calling method that triggers an exception.

3. The structure of the compilation product is as follows:

   - Path: For details, see the key field in [Exception Stack Trace Analysis: Sourcemap Format](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-exception-stack-parsing-principle#section1145914292713).

   - File type: The file name extension is **.ts**. (For .js files, the exception can be located directly without SourceMap mapping.)

4. Row and column number: Colons (:\) are used to separate row and column numbers of the exception.

**Debug mode**

In an application built in debug mode or a release application whose exception stack is translated using source map, the standard exception stack information format is as follows:

at \<Execution method name> \<Dependent module name> (\<Source code path>:\<Line number>:\<Column number>)

The following is an example:

```text
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

### HybridStack Format

Since API version 22, the cross-language call stack between C++ and JS can be printed in the **HybridStack** of the ARM 64-bit system.

For details about the C++ code stack, see [C++ Exception Code Stack Formats](cppcrash-guidelines.md#common-faults).

For details about the JS call stack, see [JS Exception Code Call Stack Formats](#exception-code-call-stack-formats)

### Promise Stack

The promise stack is disabled by default. Since API version 23, you can run the following command to enable it in ARM64. The setting takes effect for the entire device.

```cmd
hdc shell param set persist.ark.properties 0x80105c
hdc shell reboot
```

Run the following command to disable the promise stack.

```cmd
hdc shell param set persist.ark.properties 0x105c
hdc shell reboot
```

Exceptions thrown in promise asynchronous tasks do not cause a JS crash by default. However, after capturing a rejected promise through [on('unhandledRejection')](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronunhandledrejection12), you can actively throw the exception to trigger a JS crash.

When the promise stack is enabled, if an exception is thrown in a promise task and a JS crash occurs, the JS crash log displays the stack information about the promise task creation.

The format of the promise stack in the JS crash log is as follows:

```text
...
Stacktrace:
    at onPageShow entry (entry/src/main/ets/pages/Index.ets:7:13)
HybridStack:
...
AsyncStack: <- After the promise stack is enabled, the stack information when the promise task is created is displayed.
    submitter#00: <- Each promise task corresponds to a submitter. The stack of a submitter supports a maximum of 48 backtracing layers.
    #00 pc 0000000000266a0c /system/lib64/platformsdk/libark_jsruntime.so(e0c4624849e028140f5bff13122863b7)
    #01 pc 000000000020ba3c /system/lib64/platformsdk/libark_jsruntime.so(e0c4624849e028140f5bff13122863b7)
    #02 pc 0000000000dfd330 /system/lib64/module/arkcompiler/stub.an(RTStub_PushCallArgsAndDispatchNative+44)
    #03 pc 00000000004533d8 /system/lib64/module/arkcompiler/stub.an(BCStub_HandleCallthis1Imm8V8V8StwCopy+388)
    #04 at bar entry (entry/src/main/ets/pages/Index.ets:36:29)
    #05 at foo entry (entry/src/main/ets/pages/Index.ets:33:3)
    #06 pc 000000000083bf64 /system/lib64/platformsdk/libark_jsruntime.so(e0c4624849e028140f5bff13122863b7)
    #07 pc 00000000007f42f8 /system/lib64/platformsdk/libark_jsruntime.so(e0c4624849e028140f5bff13122863b7)
    #08 pc 00000000007e8e88 /system/lib64/platformsdk/libark_jsruntime.so(e0c4624849e028140f5bff13122863b7)
    #09 pc 0000000000dfcebc /system/lib64/module/arkcompiler/stub.an(RTStub_AsmInterpreterEntry+484)
    #10 pc 0000000000dfcd18 /system/lib64/module/arkcompiler/stub.an(RTStub_AsmInterpreterEntry+64)
    ...
    submitter#01: <- Multiple submitters indicate that asynchronous nesting exists. A maximum of eight submitters are supported.
    #00 pc 0000000000266a0c /system/lib64/platformsdk/libark_jsruntime.so(e0c4624849e028140f5bff13122863b7)
    #01 pc 0000000000ad9e4c /system/lib64/platformsdk/libark_jsruntime.so(e0c4624849e028140f5bff13122863b7)
    #02 pc 0000000000dfaa8c /system/lib64/module/arkcompiler/stub.an(RTStub_CallRuntime+44)
    #03 pc 0000000000518bcc /system/lib64/module/arkcompiler/stub.an(BCStub_HandleAsyncfunctionawaituncaughtV8StwCopy+68)
    #04 at foo entry (entry/src/main/ets/pages/Index.ets:32:3)
    #05 at anonymous entry (entry/src/main/ets/pages/Index.ets:23:11)
    #06 pc 0000000000801f5c /system/lib64/platformsdk/libark_jsruntime.so(e0c4624849e028140f5bff13122863b7)
    #07 pc 0000000000803470 /system/lib64/platformsdk/libark_jsruntime.so(panda::FunctionRef::Call(panda::ecmascript::EcmaVM const*, panda::Local<panda::JSValueRef>, panda::Local<panda::JSValueRef> const*, int)+548)(e0c4624849e028140f5bff13122863b7)
    #08 pc 0000000000ad79e8 /system/lib64/platformsdk/libace_compatible.z.so(aab90c413ff8b440b9a25a47964950ee)
    #09 pc 0000000000e98440 /system/lib64/platformsdk/libace_compatible.z.so(aab90c413ff8b440b9a25a47964950ee)
    #10 pc 00000000013208a0 /system/lib64/platformsdk/libace_compatible.z.so(aab90c413ff8b440b9a25a47964950ee)
    ...

HiLog:
...
```

## JsCrash Clustering

JsCrash clustering information starts with the `Stacktrace:` field and includes the call stack of `HybridStack:` on ARM 64-bit systems.

```text
...
Stacktrace:
    at onPageShow entry (entry/src/main/ets/pages/Index.ets:7:13)
HybridStack:
#00 pc 00000000004a814c /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#01 pc 00000000004a6460 /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#02 pc 00000000006a94e0 /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#03 pc 0000000000334d38 /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#04 pc 0000000000253da8 /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::ObjectFactory::GetJSError(panda::ecmascript::base::ErrorType const&, char const*, panda::ecmascript::StackCheck)+292)(173710293c3751dc676d24264bfac393)
#05 pc 00000000005c25d4 /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#06 pc 0000000000de3efc /system/lib64/module/arkcompiler/stub.an(RTStub_PushCallArgsAndDispatchNative+44)
#07 pc 000000000044843c /system/lib64/module/arkcompiler/stub.an(BCStub_HandleCallarg1Imm8V8StwCopy+340)
#08 at onPageShow entry (entry/src/main/ets/pages/Index.ets:7:13)
#09 pc 00000000001e620c /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#10 pc 00000000009ad560 /system/lib64/platformsdk/libark_jsruntime.so(panda::FunctionRef::Call(panda::ecmascript::EcmaVM const*, panda::Local<panda::JSValueRef>, panda::Local<panda::JSValueRef> const*, int)+456)(173710293c3751dc676d24264bfac393)
#11 pc 0000000000a63f14 /system/lib64/platformsdk/libace_compatible.z.so(e236e26a38ac303814f43a3c8fc9b0a6)
#12 pc 0000000000d836bc /system/lib64/platformsdk/libace_compatible.z.so(e236e26a38ac303814f43a3c8fc9b0a6)
#13 pc 000000000111f338 /system/lib64/platformsdk/libace_compatible.z.so(e236e26a38ac303814f43a3c8fc9b0a6)
...
```

The clustering method is the same as that for Cpp Crash. For details, see [CppCrash Clustering](cppcrash-guidelines.md#cppcrash-clustering).

<!--no_check-->