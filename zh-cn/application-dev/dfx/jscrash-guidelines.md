# JS Crash（进程崩溃）检测
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @wanghuan2025-->
<!--Designer: @Maplestory91-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## 简介

在ArkTS应用中，Crash（崩溃）检测是一项重要的监控能力，它可以帮助开发者及时发现和修复应用中的问题。


## 检测原理

方舟运行时捕获进程异常。生成故障日志的流程如下：

1. 当代码执行时，未捕获的异常或错误导致应用崩溃，方舟运行时将捕获这些异常。

2. 方舟运行时收集故障信息，并将其上报给维测进程Hiview。

3. 维测进程Hiview补充仅其有权限获取的信息（如整机内存状态、应用页面切换轨迹），生成对应的崩溃日志文件，存储在“/data/log/faultlog/faultlogger”目录下。

4. 上报崩溃事件，开发者可通过HiAppEvent订阅[崩溃事件](hiappevent-watcher-crash-events.md)。如需了解JS Crash问题分析方法，请参见[JS Crash类问题分析方法](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-app-crash-js-way)。


## 约束与限制

在async修饰的异步函数中主动抛出异常，不会产生JS Crash导致应用崩溃，开发者可以通过[errorManager.on('error')](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror)观测该异常，样例代码参考[Async函数内部异常的处理机制](../arkts-utils/arkts-runtime-faq.md#async函数内部异常的处理机制)。从**API版本26.0.0**开始，当应用已注册ErrorManager观测异常，除异常为不可捕获类型（当前仅包含OutOfMemoryError）之外，其它类型异常将不会生成HiAppEvent事件上报。


## 日志获取

进程崩溃日志是一种故障日志，由FaultLogger模块进行管理，可通过以下方式获取：

**方式一：通过DevEco Studio获取日志**

DevEco Studio会收集设备/data/log/faultlog/faultlogger/路径下的进程崩溃故障日志到FaultLog中，根据进程名、故障和时间分类显示。获取日志的方法参见：[DevEco Studio使用指南-FaultLog](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-fault-log)。

**方式二：通过HiAppEvent接口订阅**

HiAppEvent给开发者提供了故障订阅接口，详见[HiAppEvent介绍](hiappevent-intro.md)。参考[订阅崩溃事件（ArkTS）](hiappevent-watcher-crash-events-arkts.md)或[订阅崩溃事件（C/C++）](hiappevent-watcher-crash-events-ndk.md)完成崩溃事件订阅，再通过事件的[external_log](hiappevent-watcher-crash-events.md#事件字段说明)字段读取故障日志文件内容。

**方式三：通过hdc获取日志，需打开开发者选项**

在开发者选项打开的情况下，开发者可以通过如下命令获取日志至本地。
```text
hdc file recv /data/log/faultlog/faultlogger 本地路径
```
故障日志文件名格式为：jscrash-进程名-进程UID-毫秒级时间.log。


## 日志规格


|字段|描述|起始API版本|是否必选项|非必选说明|
|---|---|---|---|---|
| Device info | 设备信息 | 8 | 是 | - |
| Build info | 版本信息 | 8 | 是 | - |
| DeviceDebuggable | 设备的系统版本是否可调试，和开发者选项无关 | 23 | 是 | - |
| Fingerprint | 故障特征，聚类同类问题的哈希值 | 8 | 是 | - |
| Timestamp | 时间戳 | 8 | 是 | - |
| Module name | 包名 | 8 | 是 | - |
| ReleaseType | 应用的版本类型。release表示应用为[release版本应用](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916)，debug表示应用为[debug版本应用](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916)。 | 23 | 是 | - |
| CpuAbi | 二进制接口类型 | 23 | 是 | - |
| Version | hap版本 | 8 | 是 | - |
| VersionCode | 版本编码 | 8 | 是 | - |
| IsSystemApp | 应用是否为系统应用 | 23 | 是 | - |
| Pid | 故障进程号 | 8 | 是 | - |
| Uid | 用户ID | 8 | 是 | - |
| Process name | 故障进程名 | 26 | 是 | - |
| App running unique id | 应用运行时唯一关联的id。 | 26.0.0 | 是 | - |
| Process life time | 故障进程存活时间 | 22 | 是 | - |
| Process Memory(kB) | 进程占用内存 | 20 | 是 | - |
| Device Memory(kB) | 整机内存信息 | 20 | 否 | 依赖维测服务进程，若发生故障时维测服务进程停止或设备重启则无此字段，详见[检测原理](#检测原理)。 |
| Page switch history | 页面切换轨迹 | 20 | 否 | 如果维测服务进程出现故障或未缓存切换轨迹，则不包含此字段。 |
| Reason | 故障原因 | 8 | 是 | - |
| Error name | 故障类型 | 8 | 是 | - |
| Error message | 异常信息 | 8 | 是 | - |
| Stacktrace | 故障堆栈 | 8 | 是 | - |
| HybridStack | CPP和JS之间跨语言的故障堆栈 | 22 | 否 | ARM 64位系统下，若Stacktrace为JS栈时，则包含此字段，至多显示256层。 |
| SubmitterStacktrace | 提交者线程栈 | 20 | 否 | 异步线程栈跟踪维测功能默认仅在ARM 64位系统中开启。<br>对于**API version 22**之前版本，**三方和系统应用**[libuv](../reference/native-lib/libuv.md)和[ffrt](../reference/apis-ffrt-kit/capi-ffrt.md)提交异步任务仅debug版本默认开启。<br>对于**API version 22**及之后版本，**三方应用**通过libuv提交异步任务debug和release版本均默认开启；**三方和系统应用**通过ffrt提交异步任务仅debug版本默认开启。 |
| HiLog | 故障之前打印的流水日志，最多1000行 | 20 | 是 | - |
| AsyncStack | Promise异步栈 | 23 | 否 | ARM 64位系统下，若开启Promise异步栈开关，则包含此字段。 |
| ModuleImportStack | 模块加载链路 | 26.0.0 | 否 | ARM 64位系统下，若开启[模块加载链路调试开关](../arkts-utils/arkts-module-debug.md)，则包含此字段。 |
| NativeModuleErrorInfo | so加载失败信息，最多20个加载失败信息 | 26.0.0 | 是 | - |

以下是JS Crash崩溃日志规格。
```text
Device info:XXX <- 设备信息
Build info:XXX-XXXX X.X.X.XX(XXXXXXXX) <- 版本信息
DeviceDebuggable:No <- 设备的系统版本是否可调试
Fingerprint:ed1811f3f5ae13c7262b51aab73ddd01df95b2c64466a204e0d70e6461cf1697 <- 故障特征
Timestamp:XXXX-XX-XX XX:XX:XX.XXX <- 时间戳
Module name:com.example.myapplication <- 包名
ReleaseType:release <- 应用的版本类型
CpuAbi:arm64-v8a <- 二进制接口类型
Version:1.0.0 <- hap版本
VersionCode:1000000 <- 版本编码
IsSystemApp:No <- 应用是否为系统应用
Pid:579 <- 故障进程号
Uid:0 <- 用户ID
Process name:com.example.myapplication <- 进程名
App running unique id:124500628566978194 <- 应用运行时唯一关联的id
Process life time:1s  <- 进程存活时间
Process Memory(kB): 1897(Rss) <- 进程占用内存
Device Memory(kB): Total 1935820, Free 482136, Available 1204216  <- 整机内存信息（非必选）
Page switch history: <- 页面切换轨迹
  14:08:30:327 /ets/pages/Index:JsError
  14:08:28:986 /ets/pages/Index
  14:08:07:606 :leaves foreground
  14:08:06:246 /ets/pages/Index:AppFreeze
  14:08:01:955 :enters foreground
Reason:TypeError <- 故障原因
Error name:TypeError <- 故障类型
Error message:Cannot read property c of undefined <- 异常信息
Cannot get SourceMap info, dump raw stack: <- 应用安装包为release包安装时不包含sourcemap文件，JS栈通过sourcemap行列号解析会失败
Stacktrace:
    at onPageShow entry (entry/src/main/ets/pages/Index.ets:7:13)  <-异常代码调用堆栈
           ^        ^                              ^
         函数名   模块的包名                   文件行列号位置
HybridStack: <- CPP和JS之间跨语言的代码调用栈
#00 pc 00000000004a814c /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#01 pc 00000000004a6460 /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#02 pc 00000000006a94e0 /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#03 pc 0000000000334d38 /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#04 pc 0000000000253da8 /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::ObjectFactory::GetJSError(panda::ecmascript::base::ErrorType const&, char const*, panda::ecmascript::StackCheck)+292)(173710293c3751dc676d24264bfac393)
#05 pc 00000000005c25d4 /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#06 pc 0000000000de3efc /system/lib64/module/arkcompiler/stub.an(RTStub_PushCallArgsAndDispatchNative+44)
#07 pc 000000000044843c /system/lib64/module/arkcompiler/stub.an(BCStub_HandleCallarg1Imm8V8StwCopy+340)
#08 at onPageShow entry (entry/src/main/ets/pages/Index.ets:7:13) <- 异常发生时执行的JS代码
#09 pc 00000000001e620c /system/lib64/platformsdk/libark_jsruntime.so(173710293c3751dc676d24264bfac393)
#10 pc 00000000009ad560 /system/lib64/platformsdk/libark_jsruntime.so(panda::FunctionRef::Call(panda::ecmascript::EcmaVM const*, panda::Local<panda::JSValueRef>, panda::Local<panda::JSValueRef> const*, int)+456)(173710293c3751dc676d24264bfac393)
#11 pc 0000000000a63f14 /system/lib64/platformsdk/libace_compatible.z.so(e236e26a38ac303814f43a3c8fc9b0a6)
#12 pc 0000000000d836bc /system/lib64/platformsdk/libace_compatible.z.so(e236e26a38ac303814f43a3c8fc9b0a6)
#13 pc 000000000111f338 /system/lib64/platformsdk/libace_compatible.z.so(e236e26a38ac303814f43a3c8fc9b0a6)
...

HiLog:
 ^
 在生成的崩溃日志文件中追加产生故障之前的流水日志，最多1000行

```
### 异步线程栈跟踪故障场景日志规格

当异步线程发生崩溃后，把提交该异步任务的线程栈也打印出来，帮助定位由于异步任务提交者造成的崩溃问题。崩溃线程的调用栈和其提交线程的调用栈通过SubmitterStacktrace字符串分隔。以下是一份DevEco Studio归档在FaultLog的进程崩溃日志的核心内容。

> **注意：**
>
> 异步线程栈跟踪维测功能默认仅在ARM 64位系统中开启，在JSCrash崩溃打印Native堆栈时适用。
>
> 对于**API version 22**之前版本，**三方和系统应用**通过libuv和ffrt提交异步任务仅debug版本默认开启。
>
> 对于**API version 22**及之后版本，**三方应用**通过libuv提交异步任务debug和release版本均默认开启，**三方和系统应用**通过ffrt提交异步任务仅debug版本默认开启。
日志中Stacktrace字段规格如下：
```text
Stacktrace:
#00 pc 00000000004d9d4c /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::Backtrace(std::__h::basic_ostringstream<char, std::__h::char_traits<char>, std::__h::allocator<char>>&, bool)+92)(723d1618fe2567539bed3038ccfe92d8)
#01 pc 000000000038ddcc /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::JsStackInfo::BuildJsStackTrace(panda::ecmascript::JSThread*, bool, panda::ecmascript::JSHandle<panda::ecmascript::JSObject> const&, bool, unsigned int)+2952)(723d1618fe2567539bed3038ccfe92d8)
#02 pc 000000000038c70c /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::base::ErrorHelper::ErrorCommonConstructor(panda::ecmascript::EcmaRuntimeCallInfo*, panda::ecmascript::base::ErrorType const&)+1704)(723d1618fe2567539bed3038ccfe92d8)
#03 pc 000000000038c03c /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::builtins::BuiltinsError::ErrorConstructor(panda::ecmascript::EcmaRuntimeCallInfo*)+40)(723d1618fe2567539bed3038ccfe92d8)
#04 pc 00000000001b5d90 /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::ObjectFactory::NewJSError(panda::ecmascript::JSHandle<panda::ecmascript::GlobalEnv> const&, panda::ecmascript::base::ErrorType const&, panda::ecmascript::JSHandle<panda::ecmascript::EcmaString> const&, panda::ecmascript::StackCheck)+984)(723d1618fe2567539bed3038ccfe92d8)
#05 pc 000000000093274c /system/lib64/platformsdk/libark_jsruntime.so(panda::Exception::Error(panda::ecmascript::EcmaVM const*, panda::Local<panda::StringRef>)+244)(723d1618fe2567539bed3038ccfe92d8)
#06 pc 0000000000066398 /system/lib64/platformsdk/libace_napi.z.so(napi_throw_error+152)(c91850afe3629242ed12712b76be08f1)
#07 pc 00000000000020fc /data/storage/el1/bundle/libs/arm64/libentry.so(02cecfd8fd280aeaa1af7b9d1227afeac0ec4356)   <- 异常抛出位置
#08 pc 00000000000890c0 /system/lib64/platformsdk/libruntime.z.so(std::__h::__function::__func<OHOS::AbilityRuntime::OHOSJsEnvironmentImpl::PostTaskToHandler(char const*, void (*)(void*, int), void*, int, int)::$_0, std::__h::allocator<OHOS::AbilityRuntime::OHOSJsEnvironmentImpl::PostTaskToHandler(char const*, void (*)(void*, int), void*, int, int)::$_0>, void ()>::operator()() (.3ec3b6b3a88f13b2aa6c613a7afa022b)+128)(50df26f49d9c067da9cf79b804f136ec)
========SubmitterStacktrace========    <- 当异步线程发生崩溃后，把提交该异步任务的线程的栈也打印出来
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

从API 20起，使用Page switch history段记录页面切换的历史，故障日志最多记录最新的10条历史轨迹。单条记录的格式如下：
```text
  14:08:30:327 /ets/pages/Index:JsError
       ^             ^            ^
    切换时间      页面URL       页面名
```

> **注意：**
>
> 仅在通过Navigation跳转到子页面时才会有页面名，页面名在[系统路由表](../ui/arkts-navigation-cross-package.md#系统路由表)中定义。
>
> 当应用发生前后台切换时，对应的页面URL为空，但是会将enters foreground、leaves foreground作为特殊的页面名进行填充。
>
> enters foreground：应用进入前台运行。
>
> leaves foreground：应用在后台运行。

### Reason

JS Crash异常根据不同的异常场景，在Reason字段进行了分类，分为Error、TypeError、SyntaxError、RangeError等错误类型。


- Error（自定义）类：Error是最基本的错误类型，其他的错误类型都继承自该类型。Error对象有两个重要属性：Error message（异常信息）和Error name（错误类型）。程序运行过程中抛出的异常一般都有具体的类型，Error类型一般都是开发人员自己抛出的异常。

- TypeError（类型错误）类：这是运行时最常见的异常，表示变量或参数不是预期类型。

- SyntaxError（语法错误）类：语法错误也称为解析错误，表示不符合编程语言的语法规范。

- RangeError（边界错误）类：表示超出有效范围时发生的异常，具体包括以下几种情况：

  - 数组长度为负数或超过最大允许长度。
  - 数字类型的方法参数超出预定义的有效范围。
  - 函数堆栈调用深度超过最大限制。

- ReferenceError （引用错误）类：引用一个不存在的变量时发生的错误。创建变量时，变量名称都会被写入变量存储中心。变量存储中心类似于键值存储，引用变量时，会先在存储中心查找对应的键并返回值。如果未找到对应变量，就会抛出ReferenceError。

- URI Error（ URI错误）类：通常发生在处理 URL、URN 或其他资源标识符时，格式不正确或操作非法。主要包括encodeURI()、decodeURI()、encodeURIComponent()、decodeURIComponent()、escape()和unescape()这几个函数。

- OOMError（堆内存不够）类：表示应用程序已经耗尽了可用的堆内存，当无法为新对象分配更多堆内存时，就会抛出此错误。

- TerminationError（终止错误）类：通常是因为进程被强制终止了。例如，如果Taskpool线程中存在长时间执行或者死循环的任务，将会导致进程被强制终止并抛出此错误。

- AggregateError（多个错误）类：用于表示多个错误的集合。它通常在需要处理或报告多个错误（而不是单个错误）的场景中使用。

- EvalError（eval函数错误）类：用于表示与 eval() 函数执行相关的异常。然而，在实际开发中，这个错误类型已经很少被使用，更多情况下引擎会直接抛出 SyntaxError 或 TypeError。


JS Crash通常是应用问题，开发者可通过崩溃文件中的Error message和StackTrace来定位问题。


### 异常代码调用栈格式


异常代码调用栈内容在Release和Debug两种应用构建模式下存在差异：Debug构建模式会保留完整调试信息，Release构建模式会通过代码优化和混淆技术剥离调试信息。


**Release模式**


Release模式构建的应用中，异常堆栈信息遵循以下标准化格式：


at &lt;执行方法名&gt; (&lt;本模块名|依赖的模块名|版本号|编译产物路径&gt;:&lt;行号&gt;:&lt;列号&gt;)


示例如下：


```text
at onPageShow (entry|har1|1.0.0|src/main/ets/pages/Index.ts:7:13)
```


格式解析：


1. at：堆栈调用链的固定起始标识符。

2. 执行方法名：onPageShow表示触发该异常的调用方法名称。

3. 编译产物结构如下：
   - 编译产物路径：详见[异常堆栈解析原理 sourcemap结构：key字段介绍](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-exception-stack-parsing-principle#section1145914292713)。

   - 文件类型：文件扩展名为.ts文件后缀（.js文件无需 SourceMap 映射可直接定位异常）。

4. 行列号：发生异常的具体行数和这一行的列数，以“:”为分隔符分隔。


**Debug模式**


使用 Source Map 转译 Release 模式构建应用的异常堆栈或使用Debug模式构建的应用中，异常堆栈信息遵循以下标准化格式：


at &lt;执行方法名&gt; &lt;源码依赖的模块名&gt; (&lt;源码路径&gt;:&lt;行号&gt;:&lt;列号&gt;)


示例如下：


```text
at onPageShow har1 (har1/src/main/ets/pages/Index.ets:7:13)
```


格式解析：


1. at：堆栈调用链的固定起始标识符。

2. 执行方法名：onPageShow表示触发该异常的调用方法名称。

3. 源码依赖的模块名：har1表示源码路径所属模块名。

4. 源码路径结构如下：
   - 源码路径：基于工程目录的源码文件路径。
   - 文件类型：文件扩展名为.ets。

5. 行列号：发生异常的具体行数和这一行的列数，以“:”为分隔符分隔。


### HybridStack格式

从API 22起，在ARM 64位系统下，HybridStack中支持打印CPP和JS之间跨语言的代码调用栈。

CPP代码调用栈详细说明[CPP异常代码调用栈格式规范](cppcrash-guidelines.md#一般故障场景日志规格)。

JS代码调用栈详细说明[JS异常代码调用栈格式规范](#异常代码调用栈格式)。

### Promise异步栈

Promise异步栈功能默认关闭。从API version 23起，在ARM 64位系统下，可通过如下方式开启该功能，开启后整机生效：
```cmd
hdc shell param set persist.ark.properties 0x80105c
hdc shell reboot
```

关闭Promise异步栈功能：
```cmd
hdc shell param set persist.ark.properties 0x105c
hdc shell reboot
```

Promise异步任务中抛出的异常默认不会导致JS Crash，但可以通过[on('unhandledRejection')](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronunhandledrejection12)捕获Rejected Promise后，主动将异常抛出，从而触发JS Crash。

在启用Promise异步栈功能的情况下，当Promise任务中抛出异常并导致JS Crash时，JS Crash日志中会展示Promise异步任务创建时的栈信息。

JS Crash日志中的Promise异步栈格式如下：

```text
...
Stacktrace:
    at onPageShow entry (entry/src/main/ets/pages/Index.ets:7:13)
HybridStack:
...
AsyncStack: <- 功能开启后，展示Promise异步任务创建时的栈信息
    submitter#00: <- 每次异步任务创建都对应一个submitter，每个submitter中栈的最大回溯层数为48
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
    submitter#01: <- 多个submitter表示存在异步嵌套的场景，submitter的最大支持数量为8
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

### NativeModuleErrorInfo 
JS Crash日志中的NativeModuleErrorInfo可记录最早的20条so加载失败信息，如果总数超出20个，请在hilog根据'Load native module failed'关键字查找是否so加载失败。NativeModuleErrorInfo信息格式如下：

```text
...
Stacktrace:
...
HybridStack:
...
NativeModuleErrorInfo:
There are a total of 2 SO loading failure messages, and 2 of them are displayed here.
#1 ModuleName:module1 Reason:dlopen failed: load module default/module1 failed.
#2 ModuleName:module2 Reason:dlopen failed: load module default/module2 failed.
...
HiLog:
...
```
## JsCrash聚类

Js Crash聚类信息以“Stacktrace:”字段开始，包含ARM 64系统的“HybridStack:”的调用栈。

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

聚类方法同Cpp Crash一致，参考[CppCrash聚类](cppcrash-guidelines.md#cppcrash聚类)。
