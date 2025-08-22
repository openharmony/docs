# JS Crash（进程崩溃）检测
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @wanghuan2025-->
<!--Designer: @Maplestory-->
<!--Tester: @yufeifei-->
<!--Adviser: @foryourself-->

## 简介

在ArkTS应用中，Crash（崩溃）检测是一项重要的监控能力，它可以帮助开发者及时发现和修复应用中的问题。


## 检测原理

方舟运行时捕获进程异常。生成故障日志的流程如下：

1. 当代码执行时，未捕获的异常或错误导致应用崩溃，方舟运行时将捕获这些异常。

2. 方舟运行时收集故障信息，并将其上报给维测进程Hiview。

3. 维测进程Hiview补充仅其有权限获取的信息(如整机内存状态、应用页面切换轨迹)，生成对应的崩溃日志文件, 存储在“/data/log/faultlog/faultlogger”目录下。

4. 上报崩溃事件，开发者可通过HiAppEvent订阅[崩溃事件](hiappevent-watcher-crash-events.md)。如需了解JS Crash问题分析方法，请参见[JS Crash类问题分析方法](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-app-crash-js-way)。


## 约束与限制

在async修饰的异步函数中主动抛出异常，不会产生JS Crash导致应用崩溃，开发者可以通过[ErrorManager](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror)观测该异常，样例代码参考[Async函数内部异常的处理机制](../arkts-utils/arkts-runtime-faq.md#async函数内部异常的处理机制)。


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
| Fingerprint | 故障特征，聚类同类问题的哈希值 | 8 | 是 | - |
| Timestamp | 时间戳 | 8 | 是 | - |
| Module name | 包名/进程名 | 8 | 是 | - |
| Version | hap版本 | 8 | 是 | - |
| Version Code | 版本编码 | 8 | 是 | - |
| Pid | 故障进程号 | 8 | 是 | - |
| Uid | 用户ID | 8 | 是 | - |
| Process Memory(kB) | 进程占用内存 | 20 | 是 | - |
| Device Memory(kB) | 整机内存信息 | 20 | 否 | 依赖维测服务进程，若发生故障时维测服务进程停止或设备重启则无此字段，详见[检测原理](#检测原理)。 |
| Page switch history | 页面切换轨迹 | 21 | 否 | 如果维测服务进程出现故障或未缓存切换轨迹，则不包含此字段。 |
| Reason | 故障原因 | 8 | 是 | - |
| Error name | 故障类型 | 8 | 是 | - |
| Error message | 异常信息 | 8 | 是 | - |
| Stacktrace | 故障堆栈 | 8 | 是 | - |
| HiLog | 故障之前打印的流水日志，最多1000行 | 20 | 是 | - |

以下是JS Crash崩溃日志规格。
```text
Device info:XXX <- 设备信息
Build info:XXX-XXXX X.X.X.XX(XXXXXXXX) <- 版本信息
Fingerprint:ed1811f3f5ae13c7262b51aab73ddd01df95b2c64466a204e0d70e6461cf1697 <- 故障特征
Timestamp:XXXX-XX-XX XX:XX:XX.XXX <- 时间戳
Module name:com.example.myapplication <- 包名/进程名
Version:1.0.0 <- hap版本
VersionCode:1000000 <- 版本编码
Pid:579 <- 故障进程号
Uid:0 <- 用户ID
Process Memory(kB): 1897(Rss) <- 进程占用内存
Device Memory(kB): Total 1935820, Free 482136, Available 1204216  <- 整机内存信息
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

HiLog:
 ^
 在生成的崩溃日志文件中追加异常相关1000行hilog日志

```


### Page switch history

从API 21起，使用Page switch history段记录页面切换的历史，故障日日志最多记录最新的10条历史轨迹。单条记录的格式如下：
```text
  14:08:30:327 /ets/pages/Index:JsError
       ^             ^            ^
    切换时间      页面URL       页面名
```

> **注意：**
>
> 仅在通过Navigation跳转到子页面时才会有页面名，页面名在[系统路由表](../ui/arkts-navigation-navigation.md#系统路由表)中定义。
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


```
at onPageShow (entry|har1|1.0.0|src/main/ets/pages/Index.ts:7:13)
```


格式解析：


1. at：堆栈调用链的固定起始标识符。

2. 执行方法名：onPageShow表示触发该异常的调用方法名称。

3. 编译产物结构如下：
   - 编译产物路径：详见[异常堆栈解析原理 sourcemap结构：key字段介绍](https://gitee.com/link?target=https%3A%2F%2Fdeveloper.huawei.com%2Fconsumer%2Fcn%2Fdoc%2Fharmonyos-guides%2Fide-exception-stack-parsing-principle%23section1145914292713)。
   - 文件类型：文件扩展名为.ts文件后缀（.js文件无需 SourceMap 映射可直接定位异常）。

4. 行列号：发生异常的具体行数和这一行的列数，以“:”为分隔符分隔。


**Debug模式**


使用 Source Map 转译 Release 模式构建应用的异常堆栈或使用Debug模式构建的应用中，异常堆栈信息遵循以下标准化格式：


at &lt;执行方法名&gt; &lt;源码依赖的模块名&gt; (&lt;源码路径&gt;:&lt;行号&gt;:&lt;列号&gt;)


示例如下：


```
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
