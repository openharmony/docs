# Cpp Crash（进程崩溃）检测
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @chenshi51-->
<!--Designer: @Maplestory91-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## 简介

进程发生崩溃后，系统首先感知到崩溃，然后抓取崩溃相关的信息，最后生成崩溃日志并上报崩溃事件，为开发者提供详细的维测日志以辅助故障定位。本文分为基本概念、实现原理、约束与限制、日志获取、日志规格五个小节介绍系统提供的CppCrash检测方法。开发者如果想进一步了解如何分析CppCrash问题，请参见[CppCrash类问题分析方法](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-app-crash-cpp-way)。

## 基本概念

- **信号**

  信号是兼容POSIX的操作系统中进程间通讯的一种方式。

- **信号处理函数**

  定义了进程在接收到信号之后进行一系列处理操作的函数，信号处理函数明确需要处理的信号。

- **pc**

  全称Program Counter（程序计数器），存储当前程序正在执行指令的地址。

- **lr**

  全称Link Register（链接寄存器），存储子程序的返回地址。

- **sp**

  全称Stack Pointer（堆栈指针寄存器），存储当前函数栈帧的栈顶地址。

- **fp**

  全称Frame Pointer（栈帧指针寄存器），存储当前函数栈帧的栈底地址。

- **调用栈**

  记录每个线程从开始到执行当前现场（如崩溃现场）整个过程中函数调用顺序。

- **寄存器**

  CPU中高速存储单元用于存储计算机程序执行过程中所需的数据、指令地址或状态信息。本文中，寄存器信息是指崩溃时保存在高速存储单元中的数据、指令地址或状态信息。

## 实现原理

系统检测进程崩溃的流程如下：

1. 进程在运行时发生崩溃，会收到来自内核发送的崩溃信号，由进程在启动时注册的信号处理模块进行处理。

2. 进程接收到崩溃信号后，保存当前进程上下文，并fork出子进程执行ProcessDump二进制抓取崩溃信息。

3. ProcessDump进程将崩溃日志数据写入到临时目录下进行存储。

4. ProcessDump进程收集完崩溃日志后，上报给维测进程Hiview，并补充仅Hiview有权限获取的部分信息（如整机内存状态、应用页面切换轨迹），然后将崩溃日志存储到“/data/log/faultlog/faultlogger”目录下并生成故障事件。

### 系统处理的崩溃信号

系统的进程崩溃检测能力主要基于POSIX信号机制，目前支持对以下崩溃信号的处理：

| 信号值(signo) | 信号 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 4 | SIGILL | 非法指令 | 进程执行了非法、格式错误、未知或特权指令。 |
| 5 | SIGTRAP | 断点或陷阱异常 | 异常或trap指令发生。 |
| 6 | SIGABRT | 进程终止 | 进程异常终止，通常为进程自身调用标准函数库的abort()函数。 |
| 7 | SIGBUS | 非法内存访问 | 进程访问了未对齐或者不存在的物理地址。 |
| 8 | SIGFPE | 浮点异常 | 进程执行了错误的算术运算，如除数为0、浮点溢出、整数溢出等。 |
| 11 | SIGSEGV | 无效内存访问 | 进程访问了无效内存。 |
| 16 | SIGSTKFLT | 栈错误 | 处理器执行了错误的栈操作，如栈空时弹出、栈满时压入。<br>SIGSTKFLT信号不支持生成minidump。 |
| 31 | SIGSYS | 错误系统调用 | 系统调用时使用了错误或非法参数。 |

以上系统处理的崩溃信号，根据错误码（code）还有二级分类，二级分类如下：

### SIGILL崩溃类型

SIGILL是一个在Unix和类Unix操作系统中的信号，它表示非法指令异常。SIGILL信号通常由以下几种类型的问题场景引起：

| 错误码（code） | 信号字符串 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 1 | ILL_ILLOPC | 非法操作码异常 | 发生在执行不被CPU支持的指令或者无效指令时。 |
| 2 | ILL_ILLOPN | 非法操作数异常 | 发生在指令使用了不正确的操作数，或者是操作数的类型不正确时。 |
| 3 | ILL_ILLADR | 非法地址异常 | 发生在程序尝试访问无效的内存地址时，或者是在尝试执行未对齐的内存访问时。 |
| 4 | ILL_ILLTRP | 非法陷阱异常 | 发生在程序尝试执行一个非法的陷阱指令时，或者是在尝试执行一个未定义的操作时。 |
| 5 | ILL_PRVOPC | 特权操作码异常 | 发生在普通用户尝试执行特权指令时。 |
| 6 | ILL_PRVREG | 特权寄存器异常 | 发生在普通用户尝试访问特权寄存器时。 |
| 7 | ILL_COPROC | 协处理器异常 | 发生在程序尝试使用未定义的协处理器指令时。 |
| 8 | ILL_BADSTK | 无效的堆栈异常 | 发生在程序尝试在无效的堆栈地址上执行操作时，或者是在堆栈溢出时。 |
| 0xacac | ILL_ILLPACCFI | 指针校验异常 | 发生在程序校验指针失败时。 |

### SIGTRAP崩溃类型

SIGTRAP信号通常用于调试和跟踪程序的执行。下面是SIGTRAP信号类别的问题场景介绍：

| 错误码（code） | 信号字符串 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 1 | TRAP_BRKPT | 软件断点 | 由软件断点引起的，当程序执行到设置的断点时会触发该信号。软件断点通常用于调试程序，可以在程序的关键位置设置断点，以便在调试时暂停程序的执行并检查变量值等信息。 |
| 2 | TRAP_TRACE | 单步调试 | 由单步执行引起的，当程序执行单个指令时会触发该信号。单步执行通常用于调试程序，可以逐步执行程序并检查每个指令的执行结果。 |
| 3 | TRAP_BRANCH | 分支跟踪 | 由分支指令引起的，当程序执行分支指令时会触发该信号。分支指令通常用于控制程序的执行流程，例如if语句和循环语句等。 |
| 4 | TRAP_HWBKPT | 硬件断点 | 由硬件断点引起的，当程序执行到设置的硬件断点时会触发该信号。硬件断点通常用于调试程序，可以在程序的关键位置设置断点，以便在调试时暂停程序的执行并检查变量值等信息。与软件断点不同的是，硬件断点是由CPU硬件实现的，因此可以在程序执行过程中实时检测断点是否被触发。 |

### SIGBUS崩溃类型

SIGBUS是一种由操作系统向进程发送的信号，通常表示内存访问错误。其中，不同的信号类别表示不同的错误场景：

| 错误码（code） | 信号字符串 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 1 | BUS_ADRALN | 内存地址对齐错误 | 发生在尝试访问未对齐的内存地址时，例如尝试访问一个4字节整数的非偶数地址。 |
| 2 | BUS_ADRERR | 非法内存地址错误 | 发生在尝试访问不属于进程地址空间的内存地址时，例如尝试访问一个空指针。 |
| 3 | BUS_OBJERR | 对象访问错误 | 发生在尝试访问一个已经被删除或未初始化的对象时。 |
| 4 | BUS_MCEERR_AR | 需立即处理的硬件内存校验错误 | 发生在访问内存时检测到需要立即处理的硬件内存错误。 |
| 5 | BUS_MCEERR_AO | 可等待或延迟处理的硬件内存校验错误 | 发生在访问内存时检测到可等待或延迟处理的硬件内存错误。 |

### SIGFPE崩溃类型

SIGFPE是一个信号，它表示浮点异常或算术异常。下面是这些SIGFPE信号类别的问题场景：

| 错误码（code） | 信号字符串 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 1 | FPE_INTDIV | 整数除法错误 | 表示整数除法中的除数为零的情况。当一个程序尝试进行整数除法，但除数为零时，会发出这个信号。 |
| 2 | FPE_INTOVF | 整数溢出错误 | 表示整数溢出错误。当一个程序尝试进行整数运算，结果超出整数范围时，会发出这个信号。 |
| 3 | FPE_FLTDIV | 浮点除法错误 | 表示浮点数除法中的除数为零的情况。当一个程序尝试进行浮点数除法，但除数为零时，会发出这个信号。 |
| 4 | FPE_FLTOVF | 浮点上溢错误 | 表示浮点溢出错误。当一个程序尝试进行浮点数运算，结果超出浮点数上限范围时，会发出这个信号。 |
| 5 | FPE_FLTUND | 浮点下溢错误 | 表示浮点下溢错误。当一个程序尝试进行浮点数运算，结果小于浮点数下限范围时，会发出这个信号。 |
| 6 | FPE_FLTRES | 浮点结果未定义错误 | 表示浮点结果未定义错误。当一个程序尝试进行浮点数运算，结果未定义时，会发出这个信号。 |
| 7 | FPE_FLTINV | 无效浮点操作错误 | 表示无效浮点操作错误。当一个程序尝试进行无效的浮点数运算时，会发出这个信号。 |
| 8 | FPE_FLTSUB | 浮点运算结果越界错误 | 表示浮点运算结果越界错误。当一个程序尝试进行浮点数运算，浮点数结果越界，会发出这个信号。 |

### SIGSEGV崩溃类型

SIGSEGV是一种信号，它表示进程试图访问一个不属于它的内存地址，或者试图访问一个已被操作系统标记为不可访问的内存地址。SIGSEGV信号通常是由以下两种情况引起的：

| 错误码（code） | 信号字符串 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 1 | SEGV_MAPERR | 不存在的内存地址 | 进程试图访问一个不存在的内存地址，或者试图访问一个没有映射到进程地址空间的内存地址。这种情况通常是由于程序中的指针错误或内存泄漏引起的。 |
| 2 | SEGV_ACCERR | 不可访问的内存地址 | 进程试图访问一个已被操作系统标记为不可访问的内存地址，例如向只读内存写入数据或执行没有执行权限的内存。这种情况通常是由于程序中的缓冲区溢出或者试图修改只读内存等错误引起的。 |

### 信号产生原因分类

除了以上根据信号值维度分类，还可以根据信号产生的原因维度分类。所有信号值都可以按照信号产生的原因分类，当前已有信号产生原因分类的code值如下：

| 错误码（code） | 信号字符串 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 0 | SI_USER | 用户空间信号 | 由用户空间的进程发送给进程的，通常是通过kill()系统调用发送的。例如，当用户在终端中按下Ctrl+C时，会发送一个SIGINT信号给前台进程组中的所有进程。 |
| 0x80 | SI_KERNEL | 内核信号 | 由内核发送给进程的，通常是由内核检测到某些错误或异常情况时发出的。例如，当进程访问无效的内存地址或者执行非法指令时，内核会发送一个SIGSEGV信号给进程。 |
| -1 | SI_QUEUE | sigqueue()函数信号 | 由sigqueue()系统调用发送的，可以携带一个附加的整数值和一个指针。通常用于进程间高级通信，例如传递数据或者通知进程某个事件已经发生。 |
| -2 | SI_TIMER | 定时器信号 | 由定时器发送的，通常用于定时任务或者周期性任务的执行。例如，当一个定时器到期时，内核会向进程发送一个SIGALRM信号。 |
| -3 | SI_MESGQ | 消息队列信号 | 由消息队列发送的，通常用于进程间通信。例如，当一个进程向一个消息队列发送消息时，内核会向接收进程发送一个MESGQ信号。 |
| -4 | SI_ASYNCIO | 异步I/O信号 | 由异步I/O操作发送的，通常用于非阻塞I/O操作。例如，当一个文件描述符上的I/O操作完成时，内核会向进程发送一个ASYNCIO信号。 |
| -5 | SI_SIGIO | 同步I/O信号 | 由同步I/O操作发送的，通常用于阻塞I/O操作。例如，当一个文件描述符上的I/O操作完成时，内核会向进程发送一个SIGIO信号。 |
| -6 | SI_TKILL | tkill()函数信号 | 由tkill()系统调用发送的，与kill()系统调用类似，但是可以指定发送信号的线程ID。通常用于多线程程序中，向指定线程发送信号。 |

## 约束与限制

- 不建议进程自己注册信号处理函数，进程崩溃后可能会延迟退出，当处理时间超过5s可能会导致进程无响应问题上报。

- “/data/log/faultlog/faultlogger”目录下同一进程/应用最多保存10份cppcrash日志，日志数量超限时会从最早生成该进程/应用的cppcrash日志开始删除直至数量不超限。建议开发者在开发调试阶段及时查看cppcrash日志，避免因cppcrash日志被删除而无法获取崩溃信息。

- 上述崩溃信号和35、38、42信号已经被系统注册信号处理函数，建议应用不要对这些信号注册信号处理函数，如果应用注册了可能会造成系统检测能力失效。

- 异步线程栈跟踪维测功能默认仅在ARM 64位系统中开启。对于**API version 22**之前版本，**三方和系统应用**通过[libuv](../reference/native-lib/libuv.md)和[ffrt](../reference/apis-ffrt-kit/capi-ffrt.md)提交异步任务仅debug版本默认开启。对于**API version 22**及之后版本，**三方应用**通过libuv提交异步任务debug和release版本均默认开启，**三方和系统应用**通过ffrt提交异步任务仅debug版本默认开启。崩溃日志规格请参见[异步线程栈跟踪故障场景日志规格](#异步线程栈跟踪故障场景日志规格)。

## 日志获取

进程崩溃日志是故障日志中的一种，可通过以下方式获取：

**方式一：通过DevEco Studio获取日志**

DevEco Studio会收集设备“/data/log/faultlog/faultlogger/”路径下的进程崩溃故障日志到FaultLog下，根据进程名和故障类型分类显示。获取日志的方法参见：[DevEco Studio使用指南-FaultLog](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-fault-log)。

**方式二：通过HiAppEvent接口订阅**

HiAppEvent给开发者提供了故障订阅接口，详见[HiAppEvent介绍](hiappevent-intro.md)。参考[订阅崩溃事件（ArkTS）](hiappevent-watcher-crash-events-arkts.md)或[订阅崩溃事件（C/C++）](hiappevent-watcher-crash-events-ndk.md)完成崩溃事件订阅，并通过事件的[external_log](hiappevent-watcher-crash-events.md#事件字段说明)字段读取故障日志文件内容。

**方式三：通过hdc获取日志，需打开开发者选项**

在开发者选项打开的情况下，开发者可以通过“hdc file recv /data/log/faultlog/faultlogger D:\”命令导出故障日志到本地，故障日志文件名格式为：cppcrash-进程名-进程UID-毫秒级时间.log。

## 日志规格

故障日志的字段信息表如下：
|字段|描述|起始API版本|是否必选项|非必选说明|
|---|---|---|---|---|
| Device info | 设备信息 | 8 | 是 | - |
| Build info | 版本信息 | 8 | 是 | - |
| DeviceDebuggable | 设备的系统版本是否可调试 | 23 | 是 | - |
| Fingerprint | 故障特征，聚类同类问题的哈希值，哈希值相同即判定为同一故障原因。 | 8 | 是 | - |
| Enabled app log configs | 使能的配置参数列表 | 20 | 否 | 仅用户配置时打印，详见[应用通过HiAppEvent设置崩溃日志配置参数场景日志规格](#应用通过hiappevent设置崩溃日志配置参数场景日志规格)。 |
| Module name | 模块名 | 8 | 是 | - |
| ReleaseType | 应用的版本类型 | 23 | 否 | 仅在应用进程提供，release表示应用为[release版本应用](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916)，debug表示应用为[debug版本应用](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916)。 |
| CpuAbi | 二进制接口类型 | 23 | 否 | 仅在应用进程提供。 |
| Version | 应用版本号（点分格式） | 8 | 否 | 仅在应用进程提供。 |
| VersionCode | 应用版本号（整数格式） | 8 | 否 | 仅在应用进程提供。 |
| IsSystemApp | 应用是否为系统应用 | 23 | 否 | 仅在应用进程提供。 |
| PreInstalled | 是否预置应用 | 8 | 否 | 仅在应用进程提供。 |
| Foreground | 前后台状态 | 8 | 否 | 仅在应用进程提供。 |
| Page switch history | 页面切换轨迹 | 20 | 否 | 如果维测服务进程出现故障或未缓存切换轨迹，则不包含此字段，详见[实现原理](#实现原理)。 |
| Timestamp | 故障发生时间戳 | 8 | 是 | - |
| Pid | 进程号 | 8 | 是 | - |
| Uid | 用户ID | 8 | 是 | - |
| HiTraceId | HiTraceChain唯一跟踪标识 | 20 | 否 | 仅故障线程开启HiTraceChain功能时提供，详见[HiTraceChain介绍](hitracechain-intro.md)。 |
| Process name | 故障进程名 | 8 | 是 | - |
| App running unique id | 应用运行时唯一关联的ID | 26.0.0 | 是 | - |
| Process life time | 故障进程存活时间 | 8 | 是 | - |
| Process Memory(kB) | 故障进程内存占用 | 20 | 是 | - |
| Device Memory(kB) | 整机内存信息 | 20 | 否 | 依赖维测服务进程，若发生故障时维测服务进程停止或设备重启则无此字段，详见[实现原理](#实现原理)。 |
| Log source | 用于标识采集日志的方式，目前有以下几种方式： <br> **processdump：** 由用户态生成<br> **pdump：** 用户态生成cppcrash日志失败时由内核补偿生成<br> **liteprocessdump：** render/cpu等低权限进程崩溃时由用户态生成<br> 不同方式下生成日志规格会有差异，详见[不同采集方式下日志规格差异](#不同采集方式下日志规格差异)。 | 26.0.0 | 是 | - |
| Reason | 故障原因 | 8 | 是 | - |
| LastFatalMessage | Fatal消息 | 8 | 否 | 以下几种情况共用此字段：<br> 解析到不可靠的栈帧地址时输出的提示信息。<br> 因ABORT信号崩溃退出时保存最后一条FATAL级Hilog日志。<br>系统内部的维测信息。<br>应用通过[OH_HiDebug_SetCrashObj](hidebug-guidelines.md#添加维测信息到崩溃日志中)设置的字符串信息。<br>从API版本26.0.0开始，应用若开启[模块加载链路调试开关](../arkts-utils/arkts-module-debug.md)，则此字段包含模块加载链路。|
| Fault thread info | 故障线程信息 | 8 | 是 | - |
| SubmitterStacktrace | 提交者线程栈 | 12 | 否 | 异步线程栈跟踪维测功能默认仅在ARM 64位系统中开启。<br>对于**API version 22**之前版本，**三方和系统应用**通过libuv和ffrt提交异步任务仅debug版本默认开启。<br>对于**API version 22**及之后版本，**三方应用**通过libuv提交异步任务debug和release版本均默认开启；**三方和系统应用**通过ffrt提交异步任务仅debug版本默认开启。 |
| Registers | 故障现场寄存器 | 8 | 是 | - |
| Other thread info | 其他线程信息 | 8 | 是 | - |
| Memory near registers | 故障现场寄存器附近内存值 | 8 | 是 | - |
| FaultStack | 故障线程栈内存信息 | 8 | 是 | - |
| Maps | 故障时进程的内存空间 | 8 | 是 | - |
| OpenFiles | 故障时进程持有的文件句柄信息 | 12 | 是 | - |
| HiLog | 故障之前打印的流水日志，最多1000行 | 8 | 是 | - |
| [truncated] | 故障日志截断标志 | 20 | 否 | 配置故障日志截断大小并发生截断时。 |
| MergeLog | 三方应用拼接日志标识 | 24 | 否 | 配置三方应用日志标识，用于拼接应用日志。 |

> **说明：**
>
> 从**API version 20**开始，<!--Del-->arm32架构故障现场寄存器中新增状态寄存器cpsr，aarch64架构<!--DelEnd-->故障现场寄存器中新增状态寄存器pstate和esr。

不同的故障场景中日志规格略有不同，分以下七个场景的日志规格，示例如下：

- [一般故障场景日志规格](#一般故障场景日志规格)

- [空指针解引用故障场景日志规格](#空指针解引用故障场景日志规格)

- [栈溢出故障场景日志规格](#栈溢出故障场景日志规格)

- [栈覆盖故障场景日志规格](#栈覆盖故障场景日志规格)

- [异步线程栈跟踪故障场景日志规格](#异步线程栈跟踪故障场景日志规格)

- [应用通过HiAppEvent设置崩溃日志配置参数场景日志规格](#应用通过hiappevent设置崩溃日志配置参数场景日志规格)

- [有页面切换轨迹的故障场景日志规格](#有页面切换轨迹的故障场景日志规格)

> **说明：**
>
> 以下崩溃日志示例中"&lt;-"右边的文字不是日志内容，是用来解释日志格式的说明文字。

### 一般故障场景日志规格

本节主要介绍崩溃日志的一般日志规格，其余节介绍特殊场景下日志规格，以下是一份DevEco Studio归档在FaultLog的进程崩溃日志的核心内容。

<!--RP1-->
```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:OpenHarmony 3.2   <- 设备信息
Build info:OpenHarmony 6.1.0.22 <- 版本信息
DeviceDebuggable:No <- 设备的系统版本是否可调试
Fingerprint:b2b57ac77e71434d32e015e2efd464f1ce4bbadfacf5309986d2acc12b744f53 <- 标识故障特征
Module name:com.example.myapplication <- 模块名
ReleaseType:debug <- 应用的版本类型
CpuAbi:armeabi-v7a <- 二进制接口类型
Version:1.0.0 <- 应用版本号(点分格式)
VersionCode:1000000 <- 应用版本号(整数格式)
IsSystemApp:No <- 应用是否为系统应用
PreInstalled:No <- 是否预置应用
Foreground:Yes <- 前后台状态
Page switch history: <- 页面切换轨迹
  10:09:06.006 :leaves foreground
  10:08:37.066 :enters foreground
Timestamp:2026-01-08 10:09:21.000 <- 故障发生时间戳
Pid:6946 <- 进程号
Uid:20010044 <- 用户ID
HiTraceId:a92ab1c7eae68fa <- HiTraceChain唯一跟踪标识(非必选，故障线程无HiTraceId不打印)
Process name:com.example.myapplication <- 故障进程名
App running unique id:124500628566978194 <- 应用运行时唯一关联的id
Process life time:255s <- 故障进程存活时间
Process Memory(kB): 177672(Rss) <- 故障进程内存占用
Device Memory(kB): Total 2001936, Free 509212, Available 1115804 <- 整机内存信息（非必选）
Log source:processdump <- 用于标识采集日志的方式，processdump表示由用户态生成
Reason:Signal:SIGSEGV(SI_USER)@0x00001e99 from:7833:0 <- 故障原因，详见信号值说明
Fault thread info:           <- 故障线程信息
Tid:6946, Name:e.myapplication  <- 故障线程号，线程名
#00 pc 000a8a94 /system/lib/ld-musl-arm.so.1(3753ef9108517347d1a03e903b3a5dbf) <- 调用栈，调用顺序#06->#05->...->#00，最终在#00的函数中发生崩溃
#01 pc 000122a3 /system/lib/chipset-sdk-sp/libeventhandler.z.so(OHOS::AppExecFwk::EpollIoWaiter::WaitFor(std::__h::unique_lock<std::__h::mutex>&, long long, bool)+270)(0f294f85c5048f81662d7365e2b2fe45)
#02 pc 000184e9 /system/lib/chipset-sdk-sp/libeventhandler.z.so(OHOS::AppExecFwk::EventQueue::WaitUntilLocked(std::__h::chrono::time_point<std::__h::chrono::steady_clock, std::__h::chrono::duration<long long, std::__h::ratio<1ll, 1000000000ll>>> const&, std::__h::unique_lock<std::__h::mutex>&, bool)+140)(0f294f85c5048f81662d7365e2b2fe45)
#03 pc 0001aac7 /system/lib/chipset-sdk-sp/libeventhandler.z.so(OHOS::AppExecFwk::EventQueueBase::GetEvent()+174)(0f294f85c5048f81662d7365e2b2fe45)
#04 pc 00022629 /system/lib/chipset-sdk-sp/libeventhandler.z.so(OHOS::AppExecFwk::(anonymous namespace)::EventRunnerImpl::Run()+588)(0f294f85c5048f81662d7365e2b2fe45)
#05 pc 00025095 /system/lib/chipset-sdk-sp/libeventhandler.z.so(OHOS::AppExecFwk::EventRunner::Run()+304)(0f294f85c5048f81662d7365e2b2fe45)
#06 pc 000a1885 /system/lib/platformsdk/libappkit_native.z.so(OHOS::AppExecFwk::MainThread::Start()+292)(48dda5ffd26759d107cd3de59b7785fd)
Registers:  <- 故障现场寄存器
r0:fffffffc r1:ffdc65f8 r2:00000008 r3:7fffffff
r4:00000000 r5:00000008 r6:00000000 r7:0000015a
r8:d55ab241 r9:0000001b r10:ef676200
fp:ffdc65c0 ip:0000001b sp:ffdc65b0 lr:f5b122a7 pc:f7a8ea94
cpsr:288f0010           <-  状态寄存器值（arm32架构为cpsr，aarch64架构为pstate和esr）
Other thread info:      <- 其他线程信息
Tid:7724, Name:OS_IPC_0_7724 <- 线程号，线程名
#00 pc 000c41f4 /system/lib/ld-musl-arm.so.1(3753ef9108517347d1a03e903b3a5dbf)
#01 pc 0000d52f /system/lib/chipset-sdk-sp/libipc_common.z.so(OHOS::BinderConnector::WriteBinder(unsigned long, void*)+78)(9cb3631153d569a9552279529ba408d9)
#02 pc 000404f1 /system/lib/chipset-sdk-sp/libipc_single.z.so(OHOS::BinderInvoker::TransactWithDriver(bool)+196)(3e3dad353c8aedf2616c7000733c675b)
#03 pc 000407bf /system/lib/chipset-sdk-sp/libipc_single.z.so(OHOS::BinderInvoker::StartWorkLoop()+82)(3e3dad353c8aedf2616c7000733c675b)
Memory near registers:  <-  故障现场寄存器的地址（地址必须在有效内存中）附近内存值，括号表示寄存器里的地址是在哪一段内存中
r1([stack]):          <- 故障现场r1寄存器的地址附近内存值
    ffdc65f0 ffdc66f8
    ffdc65f4 00000000
    ffdc65f8 00000000
    ffdc65fc 00000000
    ...
r10([anon:native_heap:brk]):
    ef6761f8 00000008
    ef6761fc 002aa600
    ef676200 f5b2ee84
    ef676204 00000001
    ef676208 00000000
    ...
fp([stack]):
    ffdc65b8 ef676250
    ffdc65bc ef676200
    ffdc65c0 ef676210
    ffdc65c4 f5b122a7
    ...
sp([stack]):
    ffdc65a8 ef676210
    ffdc65ac f5b0e144
    ffdc65b0 ffdc65f8
    ffdc65b4 00000863
    ...
lr(/system/lib/chipset-sdk-sp/libeventhandler.z.so):
    f5b1229c 22084648
    f5b122a0 f01a4621
    f5b122a4 f3bfee4e
    f5b122a8 46808f5b
    ...
pc(/system/lib/ld-musl-arm.so.1):
    f7a8ea8c e3a05008
    f7a8ea90 ef000000
    f7a8ea94 e3700026
    f7a8ea98 0a000002
    ...
FaultStack: <- 崩溃线程的栈地址空间
    ffdc6530 ffdc65b0
    ffdc6534 00000000
    ffdc6538 ffdc65b0
    ffdc653c fe9922e2
    ...
sp0:ffdc65b0 ffdc65f8 <- #00层栈帧顶部位置
    ffdc65b4 00000863
    ...
sp1:ffdc65c8 f79e3038
    ffdc65cc 00000001
    ...
sp2:ffdc6738 00000000
    ffdc673c 00000000
    ...
sp3:ffdc6770 00000000
    ffdc6774 ffdc67e8
    ...

Maps: <- 故障时进程的内存空间
9b5000-9be000 r--p 00000000 /system/bin/appspawn
9be000-9cc000 r-xp 00008000 /system/bin/appspawn
9cc000-9cd000 r--p 00015000 /system/bin/appspawn
9cd000-9ce000 rw-p 00015000 /system/bin/appspawn
276e000-276f000 ---p 00000000 [heap]
276f000-283a000 rw-p 00000000 [heap]
...
f79e2000-f79e3000 r-xp 00000000 [sigpage]
f79e3000-f79e5000 r--p 00000000 [vvar]
f79e5000-f79e6000 r-xp 00000000 [vdso]
f79e6000-f7a41000 r--p 00000000 /system/lib/ld-musl-arm.so.1
f7a41000-f7b0b000 r-xp 0005a000 /system/lib/ld-musl-arm.so.1
f7b0b000-f7b0d000 r--p 00123000 /system/lib/ld-musl-arm.so.1
f7b0d000-f7b0f000 rw-p 00124000 /system/lib/ld-musl-arm.so.1
f7b0f000-f7b1a000 rw-p 00000000 [anon:ld-musl-arm.so.1.bss]
ffda7000-ffdc8000 rw-p 00000000 [stack]
ffff0000-ffff1000 r-xp 00000000 [vectors]
OpenFiles: <- 故障时进程持有文件句柄信息
0->/dev/null native object of unknown type 0
1->/dev/null native object of unknown type 0
2->/dev/null native object of unknown type 0
3->socket:[765] native object of unknown type 0
7->socket:[860] native object of unknown type 0
40->/dev/mali0 native object of unknown type 0

HiLog: <- 故障之前进程打印的流水日志
09-22 22:02:24.298   541   541 I C02d11/DfxSignalHandler: DFX_SigchainHandler :: signo(11), si_code(0), pid(541), tid(541).
09-22 22:02:24.298   541   541 I C02d11/DfxSignalHandler: DFX_SigchainHandler :: signo(11), pid(541), processName(foundation), threadName(foundation).

MergeLog: <- 应用提供的拼接日志
Last Modified: 2026-03-18 10:10:10 <- 应用提供的拼接日志的最后修改时间戳
app crash log. <- 应用生成用于拼接的日志
```
<!--RP1End-->

**HiTraceId说明**

HiTraceId：HiTraceChain提供的唯一跟踪标识，参考[HiTraceChain介绍](hitracechain-intro.md)。

**调用栈帧内容说明**

以三层调用栈为例，详细解释调用栈帧内容：

```text
#00 pc 000e8400 /system/lib/ld-musl-arm.so.1(raise+176)(a40044d0acb68107cfc4adb5049c0725)
#01 pc 00006e95 /data/crasher_cpp(DfxCrasher::RaiseSegmentFaultException()+92)(d6cead5be17c9bb7eee2a9b4df4b7626)
#02 pc 00008909 /data/crasher_cpp(DfxCrasher::ParseAndDoCrash(char const*) const+612)(d6cead5be17c9bb7eee2a9b4df4b7626)
```

| 序号 | pc在文件内的偏移字节数 | pc属于内存段的文件名 | 函数名 | 函数内偏移的字节数 | BuildID |
| -------- | -------- | -------- | -------- | -------- | -------- |
| \#00 | 000e8400 | /system/lib/ld-musl-arm.so.1 | raise | 176 | a40044d0acb68107cfc4adb5049c0725 |
| \#01 | 00006e95 | /data/crasher_cpp | DfxCrasher::RaiseSegmentFaultException() | 92 | d6cead5be17c9bb7eee2a9b4df4b7626 |
| \#02 | 00008909 | /data/crasher_cpp | DfxCrasher::ParseAndDoCrash(char const\*) const | 612 | d6cead5be17c9bb7eee2a9b4df4b7626 |

> **说明：**
>
> - 文件名也有可能是匿名内存映射，比如[heap]、[stack]等。
>
> - 日志没有打印函数名可能是由于以下两种原因：
>   1. 二进制文件中没有保存该函数名信息。
>
>   2. 二进制文件中保存的函数名长度超过256字节。
>
> - 函数名是通过解析二进制符号表和[MiniDebugInfo](https://sourceware.org/gdb/current/onlinedocs/gdb.html/MiniDebugInfo.html)得来，**可能会随版本函数名变更、编译优化等原因而改变**。
>
> - 如果没打印BuildID，可以通过readelf -n xxx.so确认二进制是否有BuildID。如果没有则尝试在编译选项里增加编译参数--enable-linker-build-id，同时注意编译选项中不要加编译参数--build-id=none。

**JS混合栈帧内容说明**

ARM 64位系统支持抓取CPP和JS之间跨语言的调用栈，因此如果在函数调用链上有JS代码，崩溃日志还会打印如下格式的JS代码调用栈：

```text
#00 at onPageShow (entry|har1|1.0.0|src/main/ets/pages/Index.ts:7:13)
```

详细说明[JS异常代码调用栈格式规范](jscrash-guidelines.md#异常代码调用栈格式)。

### 空指针解引用故障场景日志规格

空指针解引用通常有以下两个常见的场景：

1.形如SIGSEGV(SEGV_MAPERR)\@0x00000000或cppcrash日志的Register中打印的r0，r1等传参寄存器的值为0，应首先考虑调用时是否传入了空指针。

2.形如SIGSEGV(SEGV_MAPERR)\@0x0000000c（小于一个内存页大小）或cppcrash日志Register中打印的r1等传参寄存器的值为一个很小的值时应考虑调用入参的结构体成员是否包含空指针。

该场景会在日志中打印出提示信息，表明故障很有可能是因为空指针解引用导致。以下是一份DevEco Studio归档在FaultLog的进程崩溃日志的核心内容。

<!--RP2-->
```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:OpenHarmony 3.2       <- 设备信息
Build info:OpenHarmony 6.1.0.22    <- 版本信息
DeviceDebuggable:No <- 设备的系统版本是否可调试
Fingerprint:64ededf12a18ff56e730603cd61a5c9fe7240811fdf747994184e558ecaf3f4d <- 标识故障特征
Module name:crasher_cpp            <- 模块名
Timestamp:2026-01-08 11:25:46.000  <- 故障发生时间戳
Pid:18763   <- 进程号
Uid:0         <- 用户ID
HiTraceId:a92ab123ba26e5d  <-HiTraceChain唯一跟踪标识(非必选，故障线程无HiTraceId不打印)
Process name:./crasher_cpp         <- 故障进程名
App running unique id:124500628566978194 <- 应用运行时唯一关联的id
Process life time:1s               <- 故障进程存活时间
Process Memory(kB): 5357(Rss)     <- 故障进程内存占用
Device Memory(kB): Total 2001936, Free 583336, Available 1194164 <- 整机内存信息（非必选）
Log source:processdump <- 用于标识采集日志的方式，processdump表示由用户态生成
Reason:Signal:SIGSEGV(SEGV_MAPERR)@0x00000004  probably caused by NULL pointer dereference   <- 故障原因和空指针提示
Fault thread info:
Tid:9623, Name:crasher_cpp         <- 故障线程号，线程名
#00 pc 0000ce32 /data/crasher_cpp(TestNullPointerDereferenceCrash0()+22)(67ebf2a4243173fa96de3cc069348567)
#01 pc 00009431 /data/crasher_cpp(DfxCrasher::ParseAndDoCrash(char const*) const+432)(67ebf2a4243173fa96de3cc069348567)
#02 pc 0000976d /data/crasher_cpp(67ebf2a4243173fa96de3cc069348567)
#03 pc 00076060 /system/lib/ld-musl-arm.so.1(3753ef9108517347d1a03e903b3a5dbf)
#04 pc 000060f0 /data/crasher_cpp(_start_c+84)(67ebf2a4243173fa96de3cc069348567)
#05 pc 00006094 /data/crasher_cpp(67ebf2a4243173fa96de3cc069348567)
Registers:   <- 故障现场寄存器
r0:ffff813b r1:00000004 r2:00000001 r3:00000000
r4:ffa30394 r5:00000cd0 r6:f6dd2290 r7:009f5b4c
r8:ffa30360 r9:009f41e4 r10:009f41ac
fp:009f4198 ip:f787de48 sp:ffa30340 lr:f7848518 pc:009f1e32
cpsr:208f0030          <-  状态寄存器值（arm32架构为cpsr，aarch64架构为pstate和esr）
...
```
<!--RP2End-->

### 栈溢出故障场景日志规格

以下三种场景可能出现栈溢出：

- 递归调用时未设置递归终止条件导致栈内存耗尽。

- 局部变量占用过多栈内存导致栈内存耗尽。

- 在信号栈中使用超过系统限制的栈内存。

以递归调用时未设置递归终止条件导致栈内存耗尽为例，示例代码如下：

```c++
static void *DoStackOverflow(void * inputArg) __attribute__((optnone))
{
    int b[10] = {1};
    if (b[0] == 0) {
        return static_cast<void*>(b + 9); // 9: last element of array
    }
    DoStackOverflow(inputArg); // 多次递归调用，导致栈内存耗尽后在栈的范围外进行内存的读写，产生崩溃。
    return static_cast<void*>(b + 9); // 9: last element of array
}
```

该场景会在日志中打印出提示信息，表明故障很有可能是由于栈溢出导致。以下是一份DevEco Studio归档在FaultLog的进程崩溃日志的核心内容。

<!--RP3-->
```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:OpenHarmony 3.2       <- 设备信息
Build info:OpenHarmony 6.1.0.22    <- 版本信息
DeviceDebuggable:No <- 设备的系统版本是否可调试
Fingerprint:5cfaa587e3b55eecebac32df5b7154fc2e231ad065e308ed01e625293182b0a0  <- 标识故障特征
Module name:crasher_cpp                <- 模块名
Timestamp:2026-01-08 11:25:46.000      <- 故障发生时间戳
Pid:15413                            <- 进程号
Uid:0                                  <- 用户ID
HiTraceId:a92ab1c7eae68fa  <- HiTraceChain唯一跟踪标识(非必选，故障线程无HiTraceId不打印)
Process name:./crasher_cpp             <- 故障进程名
App running unique id:124500628566978194 <- 应用运行时唯一关联的id
Process life time:1s                  <- 故障进程存活时间
Process Memory(kB): 5279(Rss)     <- 故障进程内存占用
Device Memory(kB): Total 2001936, Free 311000, Available 1181132 <- 整机内存信息（非必选）
Log source:processdump <- 用于标识采集日志的方式，processdump表示由用户态生成
Reason:Signal:SIGSEGV(SEGV_ACCERR)@0xf740efe0  current thread stack low address = 0xf740f000, probably caused by stack-buffer-overflow    <- 故障原因和栈溢出提示
Fault thread info:
Tid:15414, Name:crasher_cpp
#00 pc 00007c3e /data/crasher_cpp(DoStackOverflow(void*)+14)(8f6fb18b02e0a23b5f43cdf3cba52f0c)
#01 pc 00007c6f /data/crasher_cpp(DoStackOverflow(void*)+62)(8f6fb18b02e0a23b5f43cdf3cba52f0c)
#02 pc 00007c6f /data/crasher_cpp(DoStackOverflow(void*)+62)(8f6fb18b02e0a23b5f43cdf3cba52f0c)
#03 pc 00007c6f /data/crasher_cpp(DoStackOverflow(void*)+62)(8f6fb18b02e0a23b5f43cdf3cba52f0c)
#04 pc 00007c6f /data/crasher_cpp(DoStackOverflow(void*)+62)(8f6fb18b02e0a23b5f43cdf3cba52f0c)
#05 pc 00007c6f /data/crasher_cpp(DoStackOverflow(void*)+62)(8f6fb18b02e0a23b5f43cdf3cba52f0c)
...
```
<!--RP3End-->

### 栈覆盖故障场景日志规格

栈覆盖故障场景是指业务代码运行时改写了原本保存函数调用信息的栈内存，导致无法成功回溯调用栈。系统在回栈失败后尽可能提供开发者信息以分析问题，该场景会在日志中打印信息提示从\#xx开始尝试从线程栈内存里解析不可靠的调用栈。之所以说不可靠的调用栈，是因为调用栈可能不是一个完整的函数调用链路，从\#xx层往下的调用栈是不可靠的，意味着从\#xx层开始相邻两层栈之间可能不存在调用关系，需要开发者结合业务代码分析其中的调用链路，比如下例中正确的调用关系是\#05->\#04->\#03->\#01。以下是一份DevEco Studio归档在FaultLog的进程崩溃日志的核心内容。

<!--RP4-->
```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:OpenHarmony 3.2       <- 设备信息
Build info:OpenHarmony 6.1.0.22    <- 版本信息
DeviceDebuggable:No <- 设备的系统版本是否可调试
Fingerprint:c4d7fbc17066a8c167afb29a53e8e4ccbc3545af0178a21854f964e758e543ad    <- 标识故障特征
Module name:crasher_cpp                   <- 模块名
Timestamp:2026-01-08 11:25:46.000  <- 故障发生时间戳
Pid:16051                                 <- 进程号
Uid:0                                     <- 用户ID
HiTraceId:a92ab13e65d617d  <- HiTraceChain唯一跟踪标识(非必选，故障线程无HiTraceId不打印)
Process name:./crasher_cpp                <- 故障进程名
App running unique id:124500628566978194 <- 应用运行时唯一关联的id
Process life time:1s                      <- 故障进程存活时间
Process Memory(kB): 5271(Rss)            <- 故障进程内存占用
Device Memory(kB): Total 2001936, Free 311220, Available 1181516 <- 整机内存信息（非必选）
Log source:processdump <- 用于标识采集日志的方式，processdump表示由用户态生成
Reason:Signal:SIGSEGV(SEGV_MAPERR)@0000000000  probably caused by NULL pointer dereference      <- 故障原因
LastFatalMessage:Failed to unwind stack, try to get unreliable call stack from #02 by reparsing thread stack. <- #00和#01一般认为是可信的，从#02开始尝试从线程栈内存里解析不可靠的调用栈
Fault thread info:
Tid:16051, Name:crasher_cpp               <- 故障线程号，线程名
#00 pc 00000000 Not mapped
#01 pc 00004e8f /system/lib/chipset-sdk-sp/libsec_shared.z.so(memset_s+24)(9601785452ecc6429983cafa05397974)
#02 pc 000f48ec /system/lib/ld-musl-arm.so.1(printf+72)(1bc45fae28785321b04fb5ea5cba92f9)
#03 pc 00007353 /data/crasher_cpp(RecursiveHelperFunction(int, int, int)+54)(8f6fb18b02e0a23b5f43cdf3cba52f0c)
#04 pc 00007373 /data/crasher_cpp(RecursiveHelperFunction(int, int, int)+86)(8f6fb18b02e0a23b5f43cdf3cba52f0c)
#05 pc 00007373 /data/crasher_cpp(RecursiveHelperFunction(int, int, int)+86)(8f6fb18b02e0a23b5f43cdf3cba52f0c)
...
Registers:
r0:00000000 r1:efc658a8 r2:00000000 r3:ffaa58c8
r4:0000003f r5:00000000 r6:f714aa70 r7:00000000
r8:ffaa5dd0 r9:004171e4 r10:004171ac
fp:00417198 ip:f73912dc sp:ffaa57d0 lr:f7384e93 pc:00000000
cpsr:608f0010
...
```
<!--RP4End-->

### 异步线程栈跟踪故障场景日志规格

当异步线程发生崩溃后，把提交该异步任务的线程栈也打印出来，帮助定位由于异步任务提交者造成的崩溃问题。崩溃线程的调用栈和其提交线程的调用栈通过SubmitterStacktrace字符串分隔。

**异步线程栈生成原理**

原理示意图如下：

![工作机制说明](figures/submitter_stacktrace.png)

1. 提交线程搜集自身的调用栈信息，保存至进程特定区域内存的异步栈表中。

2. 记录保存后，异步栈表返回唯一标识stackId。

3. 提交线程提交异步任务，并传递标识stackId。

4. 执行线程在执行任务前保存stackId至线程局部存储区中。

5. 执行线程开始执行异步任务。

6. 执行线程在执行异步任务过程中发生崩溃，产生崩溃信号。

7. 信号处理函数通过GetStackId函数获取保存在线程局部存储区中的stackId。

8. 信号处理函数将stackId传递给回栈进程processdump。

9. processdump跨进程读取异步栈表，根据stackId值查询获取提交线程的调用栈信息，填充至故障日志对应的SubmitterStacktrace字段。

以下是一份DevEco Studio归档在FaultLog的进程崩溃日志的核心内容。

> **注意：**
>
> 异步线程栈跟踪维测功能默认仅在ARM 64位系统中开启。
>
> 对于**API version 22**之前版本，**三方和系统应用**通过libuv和ffrt提交异步任务仅debug版本默认开启。
>
> 对于**API version 22**及之后版本，**三方应用**通过libuv提交异步任务debug和release版本均默认开启，**三方和系统应用**通过ffrt提交异步任务仅debug版本默认开启。

<!--RP5-->
```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:OpenHarmony 3.2       <- 设备信息
Build info:OpenHarmony 6.1.0.22    <- 版本信息
DeviceDebuggable:No <- 设备的系统版本是否可调试
Fingerprint:8bc3343f50024204e258b8dce86f41f8fcc50c4d25d56b24e71fe26c0a23e321  <- 标识故障特征
Module name:com.example.uv001      <- 模块名
ReleaseType:release <- 应用的版本类型
CpuAbi:armeabi-v7a <- 二进制接口类型
Version:1.0.0 <- 应用版本号(点分格式)
VersionCode:1000000 <- 应用版本号(整数格式)
IsSystemApp:No <- 应用是否为系统应用
PreInstalled:No <- 是否预置应用
Foreground:Yes <- 前后台状态
Page switch history: <- 页面切换轨迹
  10:09:06.006 :enters foreground
Timestamp:2026-01-08 11:25:46.000  <- 故障发生时间戳
Pid:28421                                   <- 进程号
Uid:20020214                                <- 用户ID
HiTraceId:a92ab1c7eae68fa  <- HiTraceChain唯一跟踪标识(非必选，故障线程无HiTraceId不打印)
Process name:com.example.uv001              <- 故障进程名
App running unique id:124500628566978194    <- 应用运行时唯一关联的id
Process life time:42s                        <- 故障进程存活时间
Process Memory(kB): 151736(Rss)            <- 故障进程内存占用
Device Memory(kB): Total 11712088, Free 2500232, Available 5275648 <- 整机内存信息（非必选）
Log source:processdump <- 用于标识采集日志的方式，processdump表示由用户态生成
Reason:Signal:SIGABRT(SI_TKILL)@0x01317bf600006f05  from:28421:20020214  <- 故障原因
Fault thread info:
Tid:29192, Name:OS_FFRT_2_0                 <- 故障线程号，线程名
#00 pc 00000000001bfa74 /system/lib/ld-musl-aarch64.so.1(raise+216)(2f1b32d70ef466b15265fd08a0eca91e)  <- 调用栈
#01 pc 0000000000001ff8 /data/storage/el1/bundle/libs/arm64/libentry.so(7869adbb6ed8ae9fed544fa0eb2883f9a22d3bc5)
#02 pc 0000000000013694 /system/lib64/platformsdk/libuv.so(uv__queue_work+60)(f78cf9546cece23d7b088a751ff98497)
#03 pc 0000000000093224 /system/lib64/ndk/libffrt.so(ffrt::UVTask::Execute()+744)(4f907cee9caa17cf5d72826c09f13f10)
#04 pc 000000000008e784 /system/lib64/ndk/libffrt.so(ffrt::ExecuteTask(ffrt::TaskBase*)+248)(4f907cee9caa17cf5d72826c09f13f10)
#05 pc 000000000002ed3c /system/lib64/ndk/libffrt.so(ffrt::CPUWorker::RunTask(ffrt::TaskBase*,ffrt::CPUWorker*)+84)(4f907cee9caa17cf5d72826c09f13f10)
#06 pc 00000000000c87b0 /system/lib64/ndk/libffrt.so(4f907cee9caa17cf5d72826c09f13f10)
#07 pc 00000000001dfbf0 /system/lib/ld-musl-aarch64.so.1(start+240)(2f1b32d70ef466b15265fd08a0eca91e)
========SubmitterStacktrace========       <- 任务异常时打印任务提交者调用栈
#00 pc 0000000000013590 /system/lib64/platformsdk/libuv.so(uv_queue_work+304)(f78cf9546cece23d7b088a751ff98497)
#01 pc 0000000000001f74 /data/storage/el1/bundle/libs/arm64/libentry.so(7869adbb6ed8ae9fed544fa0eb2883f9a22d3bc5)
#02 pc 000000000006a258 /system/lib64/platformsdk/libace_napi.z.so(panda::JSValueRefArkNativeFunctionCallBack<true>(panda::JsiRuntimeCallInfo*)+296)(23225c16f1721ec4629f9788305fc487)
#03 pc 0000000000e7f46c /system/lib64/module/arkcompiler/stub.an(RTStub_PushCallArgsAndDispatchNative+44)
#04 pc 00000000004854c0 /system/lib64/module/arkcompiler/stub.an(BCStub_HandleCallthis2Imm8V8V8V8StwCopy+440)
#05 at func_main_0 (entry|entry|1.0.0|src/main/ets/pages/Index.ts:72:10)
#06 pc 0000000000366444 /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::EcmaInterpreter::Execute(panda::ecmascript::EcmaRuntimeCallInfo*)+800)(6e93189f3a9e33adb9455beb7c675df6)
#07 pc 0000000000803fcc /system/lib64/platformsdk/libark_jsruntime.so(6e93189f3a9e33adb9455beb7c675df6)
#08 pc 0000000000804da4 /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::EcmaVM::InvokeEcmaEntrypoint(panda::ecmascript::JSPandaFile const*,std::__h::basic_string<char,std::__h::char_traits<char>,panda::ecmascript::CAddressAllocator<char>> const&,panda::ecmascript::ExecuteTypes const&)+776)(6e93189f3a9e33adb9455beb7c675df6)
#09 pc 000000000049d0f4 /system/lib64/platformsdk/libark_jsruntime.so(6e93189f3a9e33adb9455beb7c675df6)
#10 pc 000000000039735c /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::SourceTextModule::ModuleExecution(panda::ecmascript::JSThread*,panda::ecmascript::JSHandle<panda::ecmascript::SourceTextModule> const&,void const*,unsigned long, panda::ecmascript::ExecuteTypes const&)+1108)(6e93189f3a9e33adb9455beb7c675df6)
#11 pc 00000000003db718 /system/lib64/platformsdk/libark_jsruntime.so(6e93189f3a9e33adb9455beb7c675df6)
#12 pc 00000000003dacc0 /system/lib64/platformsdk/libark_jsruntime.so(panda::ecmascript::SourceTextModule::Evaluate(panda::ecmascript::JSThread*,panda::ecmascript::JSHandle<panda::ecmascript::SourceTextModule> const&,void const*,unsigned long,panda::ecmascript::ExecuteTypes const&)+736)(6e93189f3a9e33adb9455beb7c675df6)
#13 pc 00000000005ac534 /system/lib64/platformsdk/libark_jsruntime.so(6e93189f3a9e33adb9455beb7c675df6)
#14 pc 00000000005abbec /system/lib64/platformsdk/libark_jsruntime.so(6e93189f3a9e33adb9455beb7c675df6)
#15 pc 0000000000644acc /system/lib64/platformsdk/libark_jsruntime.so(6e93189f3a9e33adb9455beb7c675df6)
...
```
<!--RP5End-->

### 应用通过HiAppEvent设置崩溃日志配置参数场景日志规格

系统提供了通用的崩溃日志生成功能，但部分应用有自定义日志内容的需求。因此从**API version 20**开始，可通过设置[setEventConfig](hiappevent-watcher-crash-events.md#seteventconfig接口说明)接口配置自定义日志内容。

以下是一份DevEco Studio归档在FaultLog的系统崩溃日志的核心内容：

<!--RP6-->
```text
...
Build info:OpenHarmony 6.1.0.22
...
Enabled app log configs:    <- 使能的配置参数列表，只打印不是默认值的配置参数
Extend pc lr printing:true  <- extend_pc_lr_printing参数设置为true
Log cut off size:102400B    <- 崩溃日志大小截断到100KB（仅通过HiAppEvent接口订阅获取的崩溃日志生效）
Simplify maps printing:true <- simplify_vma_printing参数设置为true
Timestamp:2026-01-08 11:25:46.000
...
Registers: <- 故障现场寄存器
x0:fffffffffffffffc x1:0000007e5420ad60 x2:0000000000000008 x3:000000007fffffff
x4:0000000000000000 x5:0000000000000008 x6:575f45524f464542 x7:474e49544941575f
x8:0000000000000016 x9:0000000000000008 x10:0000007e5420ad60 x11:e18b0e5877a00005
x12:000000003b9ac9ff x13:007070632e72656e x14:2f72656c646e6168 x15:8f94b1d6208ca9b4
x16:0000005afeafe7d0 x17:0000005afb7f83a0 x18:000000000000000d x19:0000005b1b4d4d50
x20:0000005b0c5fcf20 x21:0000005b1b4d4ce0 x22:7fffa71517841b1d x23:0000005b1b4d4ce0
x24:0000007e5420af40 x25:0000000000000000 x26:0000000000000000 x27:00000055a511d354
x28:0000005b1a937bc8 x29:0000007e5420ad20
lr:0000005afeae1b78 sp:0000007e5420ad20 pc:0000005afb7f83f0
pstate:0000000020001000 esr:0000000000000000
Memory near registers:
...
lr(/system/lib64/chipset-sdk-sp/libeventhandler.z.so): <- lr寄存器地址附近的内存值
    0000005afeae1a80 2a1f03e0940067e8 <- extend_pc_lr_printing设置为true时，向前打印内存值到此
    ...
    0000005afeae1b68 910083e19a89b103 <- extend_pc_lr_printing设置为false时，向前打印内存值到此
    0000005afeae1b70 9400680b52800102
    0000005afeae1b78 885ffe682a0003f7 <- lr寄存器地址（0000005afeae1b78）的内存值（885ffe682a0003f7）
    ...
    0000005afeae1c60 52801002d10243a1 <- extend_pc_lr_printing设置为false时，向后打印内存值到此
    0000005afeae1c68 ad3c83a0ad3b83a0
    0000005afeae1c70 ad3e83a0ad3d83a0
    0000005afeae1c78 94006799b9400000 <- extend_pc_lr_printing设置为true时，向后打印内存值到此
pc(/system/lib/ld-musl-aarch64.so.1): <- pc寄存器地址附近的内存值
    0000005afb7f82f8 f9000bf3a9be7bfd <- extend_pc_lr_printing设置为true时，向前打印内存值到此
    ...
    0000005afb7f83e0 aa1f03e4aa0403e3 <- extend_pc_lr_printing设置为false时，向前打印内存值到此
    0000005afb7f83e8 d400000152800105
    0000005afb7f83f0 eb00811fb25453e8 <- pc寄存器地址（0000005afb7f83f0）的内存值（eb00811fb25453e8）
    ...
    0000005afb7f84d8 aa0903e152800260 <- extend_pc_lr_printing设置为false时，向后打印内存值到此
    0000005afb7f84e0 d63f0100f9439508
    0000005afb7f84e8 a9be7bfd17ffffe6
    0000005afb7f84f0 910003fdf9000bf3 <- extend_pc_lr_printing设置为true时，向后打印内存值到此
...
Maps:       <- simplify_vma_printing设置为true，打印Maps数量减少，只保留崩溃日志中出现的地址所属的Maps
55a511d000-55a5128000 r--p 00000000 /system/bin/appspawn
55a5128000-55a513b000 r-xp 0000a000 /system/bin/appspawn
55a513b000-55a513c000 r--p 0001c000 /system/bin/appspawn
55a513c000-55a513e000 rw-p 0001c000 /system/bin/appspawn
... <- 继续打印崩溃日志中出现的地址所属的Maps，此处省略不展示
OpenFiles:
...
[truncated]  <- 日志截断的标志符，如果有打印说明日志被截断了
```
<!--RP6End-->

### 有页面切换轨迹的故障场景日志规格

针对包含页面切换的应用，自API version 20起，维测进程会记录应用切换历史。应用发生故障后，生成的故障文件将包含页面切换历史轨迹。

故障日志文件最多记录最新的10条历史轨迹。

```text
...
Foreground:Yes
Page switch history:
  14:08:30:327 /ets/pages/Index:JsError
  14:08:28:986 /ets/pages/Index
  14:08:07:606 :leaves foreground
  14:08:06:246 /ets/pages/Index:AppFreeze
  14:08:01:955 :enters foreground
Timestamp:2025-08-20 14:08:30:327
Pid:10208
Uid:0
...
```

单条记录的格式如下：
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

## CppCrash聚类

### 聚类简介

应用程序在不同版本或同一版本的不同时间产生的Cpp Crash可能为同一原因，但在Cpp crash故障日志中生成的大部分信息会随版本、时间等因素变化，无法快速确定是否为重复问题；

Cpp Crash故障信息包含系统侧和应用侧的调用栈，不利于应用开发者快速排查应用侧的问题。

因此，为避免重复分析多份故障信息，提高应用故障问题的分析效率，需要对Cpp Crash故障信息进行聚类；

同时，聚类也能帮助开发者对不同原因问题进行分类统计。

### 聚类信息范围

Cpp Crash故障日志信息中的故障线程信息表示业务线程发生故障时代码调用信息，相同的故障线程调用栈信息必然表示相同的故障原因。

因此，将故障线程信息作为聚类范围是最为准确的，开发者可根据业务聚类的需求调整增加其他故障日志的信息。

故障线程信息在Cpp Crash故障日志中从“Fault thread info:”开始，到“Registers:”结束，示例如下：

```text
...
Fault thread info:
Tid:10208, Name:crasher_cpp
#00 pc 000e8400 /system/lib/ld-musl-arm.so.1(raise+176)(a40044d0acb68107cfc4adb5049c0725)
#01 pc 00008cdc /data/storage/el1bundle/libs/arm64/libsample.so(8b74cdc906ea6b2eba95d891bc91c72a)
#02 pc 0005ae00 /system/lib/platformsdk/libace_napi.z.so(panda::JSValueRef ArkNativeFunctionCallBack<true>(panda::JsiRuntimeCallInfo*)+272)(bc1c64aabbe5c7d4db2282a6137443e1)
#03 pc 00de3efc /system/lib/module/arkcompiler/stub.an(RTStub_PushCallArgsAndDispatchNative+44)
#04 pc 00448dd4 /system/lib/module/arkcompiler/stub.an(BCStub_HandleCallthis0Imm8V8StwCopy+372)
#05 at triggerCrash (sample|sample|1.0.0|src/main/ets/pages/CppCrash.ts:49:25)
#06 at onPageShow (sample|sample|1.0.0|src/main/ets/pages/Index.ts:381:36)
#07 pc 001e5c8c /system/lib/platformsdk/libark_jsruntime.so(ce0b05d90b9fae02e7abf8e9f1e5a0f3)
...
Registers:
...
```

### 提取聚类信息

故障线程信息，除线程名和线程号外，主要为调用栈信息，可以通过正则匹配筛选堆栈内容。

由于系统或应用的版本不同，调用栈中会存在一些易变的信息（如行号、字节偏移、BuildID），因此需要对信息做提取和过滤操作。

建议对每一帧栈帧，执行以下操作：

**Native栈帧标准化：**

| 原始栈帧内容 | 标准化后栈帧内容 |
| ------------- | ---------------- |
| #02 pc 0005ae00 /system/lib/platformsdk/libace_napi.z.so(panda::JSValueRef ArkNativeFunctionCallBack\<true\>(panda::JsiRuntimeCallInfo*)+272)(bc1c64aabbe5c7d4db2282a6137443e1) | /system/lib/platformsdk/libace_napi.z.so(panda::JSValueRef ArkNativeFunctionCallBack\<true\>(panda::JsiRuntimeCallInfo*)+272) |

按以下步骤处理：

a. 去除行号；

b. 去除PC偏移和BuildID；

c. 保留文件路径（如 `/system/lib/platformsdk/libace_napi.z.so`）；

d. 保留函数完整签名（如 `panda::JSValueRef ArkNativeFunctionCallBack<true>(panda::JsiRuntimeCallInfo*)+272)`，括号内的内容，含类名、函数名、参数，包括 `const`、参数类型等）。

若Native栈帧存在仅有二进制文件名而没有函数名时，可选择保留PC的偏移值与文件路径：

| 原始栈帧内容 | 标准化后栈帧内容 |
| ------------- | ---------------- |
| #01 pc 00008cdc /data/storage/el1bundle/libs/arm64/libsample.so(8b74cdc906ea6b2eba95d891bc91c72a) | 00008cdc /data/storage/el1bundle/libs/arm64/libsample.so |

**JS栈帧标准化：**

| 原始栈帧内容 | 标准化后栈帧内容 |
| ------------- | ---------------- |
| #06 at onPageShow (sample\|sample\|1.0.0\|src/main/ets/pages/Index.ts:381:36) | onPageShow (sample\|sample\|1.0.0\|src/main/ets/pages/Index.ts:381:36) |

按以下步骤处理：

a. 去除行号；

b. 保留函数名（如 `onPageShow`）；

c. 保留文件路径、代码行号和列号（如 `src/main/ets/pages/Index.ts:381:36`）；

d. 保留模块名、依赖模块名、版本号信息（如`sample|sample|1.0.0|`）。

### 提取聚类特征

经过标准化的栈帧可能仍然存在栈帧较多，不利于聚类后存储以及查询的情况，因此开发者需要根据业务情况制定聚类特征提取方法，将栈帧信息进一步简化为聚类特征。

以下为推荐的聚类特征提取方法：

**1. 过滤基础库与异常栈帧**

即栈帧包含如下字段之一：

```text
libc.so
libc++.so
ld-musl-aarch64.so
libc_fdleak_debug.so
unknown
watchdog
kthread
rdr_system_error
libart.so
__switch_to
dump_backtrace
show_stack
dump_stack
panic
libace_napi.z.so
libarkjs_runtime.z.so
```

**2. 过滤系统栈帧，筛选业务栈帧**

系统库栈帧以“/system/lib”或“/system/lib64”为起始字符，系统栈帧格式示例：

```text
/system/lib/platformsdk/libace_napi.z.so(panda::JSValueRef ArkNativeFunctionCallBack\<true\>(panda::JsiRuntimeCallInfo*)+272)
```

业务栈帧以“at”为起始字符，或包含“/data”、“/data/storage”子串。业务栈帧格式示例：

JS栈帧默认为业务栈帧：

```text
at onPageShow (sample|sample|1.0.0|src/main/ets/pages/Index.ts:381:36)
```

应用的Native栈帧：

```text
00008cdc /data/storage/el1bundle/libs/arm64/libsample.so
```

**3. 筛选部分关键栈帧**

按照栈帧的顺序提取少量信息作为聚类特征，例如仅保留第一帧、第二帧和最后一帧信息作为特征信息。

开发者可根据业务需求制定相应的筛选条件，保证特征信息在同一故障问题上一致即可。

### 生成聚类特征

最终生成的聚类特征是一个包含少量标准化栈帧的业务调用栈序列。

| 原始故障线程栈 | 最终聚类特征（调用顺序从上到下）|
| ----------- | ------------------- |
| #00 pc 000e8400 /system/lib/ld-musl-arm.so.1<br>(raise+176)(a40044d0acb68107cfc4adb5049c0725)<br> #01 pc 00008cdc /data/storage/el1bundle/libs/arm64/libsample.so<br>(8b74cdc906ea6b2eba95d891bc91c72a)<br> #02 pc 0005ae00 /system/lib/platformsdk/libace_napi.z.so<br>(panda::JSValueRef ArkNativeFunctionCallBack\<true\>(panda::JsiRuntimeCallInfo*)+272)(bc1c64aabbe5c7d4db2282a6137443e1)<br> #03 pc 00de3efc /system/lib/module/arkcompiler/stub.an(RTStub_PushCallArgsAndDispatchNative+44)<br> #04 pc 00448dd4 /system/lib/module/arkcompiler/stub.an(BCStub_HandleCallthis0Imm8V8StwCopy+372)<br> #05 at triggerCrash (sample\|sample\|1.0.0\|src/main/ets/pages/CppCrash.ts:49:25)<br> #06 at onPageShow (sample\|sample\|1.0.0\|src/main/ets/pages/Index.ts:381:36)<br> #07 pc 001e5c8c /system/lib/platformsdk/libark_jsruntime.so(ce0b05d90b9fae02e7abf8e9f1e5a0f3) | 00008cdc /data/storage/el1bundle/libs/arm64/libsample.so<br> triggerCrash (sample\|sample\|1.0.0\|src/main/ets/pages/CppCrash.ts:49:25)<br> onPageShow (sample\|sample\|1.0.0\|src/main/ets/pages/Index.ts:381:36) |

开发者通过比对多份故障日志提取出的聚类特征，对Cpp Crash故障问题进行分类统计。

也可以参考当前故障日志中的Fingerprint字段，对聚类特征内容进行哈希运算生成故障特征标识值，再根据故障特征标识值对Cpp Crash故障问题进行分类统计。

## 不同采集方式下日志规格差异
|字段|描述| processdump | pdump | liteprocessdump |
|---|---|---|---|---|
| Device info | 设备信息 | 有 | 有 | 有 |
| Build info | 版本信息 | 有 | 有 | 有 |
| DeviceDebuggable | 设备的系统版本是否可调试 | 有 | 有 | 有 |
| Fingerprint | 故障特征，聚类同类问题的哈希值，哈希值相同即判定为同一故障原因。 | 有 | 有 | 有 |
| Enabled app log configs | 使能的配置参数列表 | 有 | 无 | 无 |
| Module name | 模块名 | 有 | 有 | 有 |
| ReleaseType | 应用的版本类型 | 有 | 有 | 有 |
| CpuAbi | 二进制接口类型 | 有 | 有 | 有 |
| Version | 应用版本号(点分格式) | 有 | 有 | 有 |
| VersionCode | 应用版本号(整数格式) | 有 | 有 | 有 |
| IsSystemApp | 应用是否为系统应用 | 有 | 有 | 有 |
| PreInstalled | 是否预置应用 | 有 | 有 | 有 |
| Foreground | 前后台状态 | 有 | 有 | 有 |
| Page switch history | 页面切换轨迹 | 有 | 有 | 有 |
| Timestamp | 故障发生时间戳 | 有 | 有 | 有 |
| Pid | 进程号 | 有 | 有 | 有 |
| Uid | 用户ID | 有 | 有 | 有 |
| HiTraceId | HiTraceChain唯一跟踪标识 | 有 | 无 | 无 |
| Process name | 故障进程名 | 有 | 有 | 有 |
| App running unique id | 应用运行时唯一关联的ID | 有 | 无 | 有 |
| Process life time | 故障进程存活时间 | 有 | 有 | 有 |
| Process Memory(kB) | 故障进程内存占用 | 有 | 有 | 有 |
| Device Memory(kB) | 整机内存状态 | 有 | 有 | 有 |
| Log source | 用于标识采集日志的方式 | 有 | 有 | 有 |
| Reason | 故障原因 | 有 | 有 | 有 |
| LastFatalMessage | Fatal消息 | 有 | 无 | 无 |
| Fault thread info | 故障线程信息 | 有 | 有 | 有 |
| SubmitterStacktrace | 提交者线程栈 | 有 | 无 | 无 |
| Registers | 故障现场寄存器 | 有 | 有 | 有 |
| ExtraCrashInfo | 额外的内存信息 | 有 | 无 | 无 |
| Other thread info | 其他线程信息 | 有 | 有 | 有 |
| Memory near registers | 故障现场寄存器附近内存值 | 有 | 有 | 有 |
| FaultStack | 故障线程栈内存信息 | 有 | 有 | 有 |
| Maps | 故障时进程的内存空间 | 有 | 有 | 有 |
| OpenFiles | 故障时进程持有的文件句柄信息 | 有 | 无 | 有 |
| HiLog | 故障之前打印的流水日志，最多1000行 | 有 | 有 | 有 |
| [truncated] | 故障日志截断标志 | 有 | 有 | 有 |
| MergeLog | 三方应用拼接日志标识 | 有 | 无 | 无 |

## 常见问题

### 故障日志中调用栈出现中断

在OpenHarmony系统中，调用栈获取依赖回栈表（记录调用栈信息的表）和frame pointer（栈帧指针）两种机制，需要保证以下两个编译选项开启：

- **-funwind-tables**

  该选项指示编译器在二进制中生成回栈表，用于异常处理和调用栈回溯。

- **-fno-omit-frame-pointer**

  该选项指示编译器将栈帧指针存储在一个寄存器中，用于异常处理和调用栈回溯。

**编译选项开启方法**

以Cmake为例，在CMakeList.txt中添加`set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -funwind-tables")`。

### 应用发生SIGPIPE异常退出

从**API version 24**开始，当应用发生SIGPIPE异常退出时，可开启SIGPIPE信号打印调用栈功能，重启应用后，开发者复现问题场景，可以抓取调用栈信息并输出到HILOG。

> **注意：**
>
> 此功能只能在[debug版本应用](performance-analysis-kit-terminology.md#debug版本应用)开启。

SIGPIPE异常退出时关键日志如下所示：
```text
应用包名 with pid xxxx exit with signal:13
```

- **SIGPIPE信号说明**

  | 信号值(signo) | 信号 | 解释 | 触发原因 |
  | -------- | -------- | -------- | -------- |
  | 13 | SIGPIPE | 非法操作管道或套接字 | - 管道（pipe）或命名管道（FIFO）：写端向管道写入，但读端已经关闭。<br>- 套接字（socket）：客户端断开连接后，服务端仍尝试往已关闭的连接写数据。 |

- **打开SIGPIPE调试开关**

  在“DevEco Studio”终端中运行命令：hdc shell param set hilog.signal.stack.on SIGPIPE，完成之后需要重新打开应用。设备重启后会失效。

- **验证是否成功开启**

  在HILOG中使用关键字`C02D11`过滤日志，根据筛选日志能够获取异常发生所在行相应信息，则表示调用栈功能成功开启。

  以通过testSIGPIPE()函数来实现SIGPIPE的异常场景为例：

  ```c++
  #include <unistd.h>
  #include <signal.h>

  int testSIGPIPE()
  {
      sigset_t set, oldset;
      // 初始化信号集，加入要临时解除阻塞的信号
      sigemptyset(&set);
      sigaddset(&set, SIGPIPE);
      // 先保存当前的信号屏蔽集
      if (sigprocmask(SIG_SETMASK, NULL, &oldset) != 0) {
          return -1;
      }
      // 临时解除阻塞
      if (sigprocmask(SIG_UNBLOCK, &set, NULL) != 0) {
          return -1;
      }
      // 创建pipe后，先关闭读端pipe，然后写端继续写，构建SIGPIPE的异常场景
      int pipe[2]{-1};
      if (pipe2(pipe, 0) != 0) {
          return -1;
      }
      close(pipe[0]);
      int src = 1;
      write(pipe[1], reinterpret_cast<const void*>(&src), sizeof(int));
      close(pipe[1]);
    
      // 最后恢复原来的屏蔽集
      if (sigprocmask(SIG_SETMASK, &oldset, NULL) != 0) {
          return -1;
      }
      return 0;
  }
  ```

  过滤日志信息，根据调用栈信息，成功定位到异常发生在testSIGPIPE()函数中，表示功能开启成功。

  ```text
  ...
  03-06 13:55:25.876   20440-20440   C02D11/process...fxFaultLogger  pid-20440             I     Timestamp:2026-03-06 13:55:25.382
  03-06 13:55:25.876   20440-20440   C02D11/process...fxFaultLogger  pid-20440             I     Pid:19787
  03-06 13:55:25.876   20440-20440   C02D11/process...fxFaultLogger  pid-20440             I     Uid:20020208
  03-06 13:55:25.876   20440-20440   C02D11/process...fxFaultLogger  pid-20440             I     Process name:com.example.myapplication
  03-06 13:55:25.876   20440-20440   C02D11/process...fxFaultLogger  pid-20440             I     Process life time:12s
  03-06 13:55:25.876   20440-20440   C02D11/process...fxFaultLogger  pid-20440             I     Process Memory(kB): 172773(Rss)
  03-06 13:55:25.876   20440-20440   C02D11/process...fxFaultLogger  pid-20440             I     Reason:Signal:SIGPIPE(SI_USER)from:19787:20020208
  03-06 13:55:25.876   20440-20440   C02D11/process...fxFaultLogger  pid-20440             I     Fault thread info:
  03-06 13:55:25.876   20440-20440   C02D11/process...fxFaultLogger  pid-20440             I     Tid:19787, Name:e.myapplication
  03-06 13:55:25.876   20440-20440   C02D11/process...fxFaultLogger  pid-20440             I     #00 pc 00000000001e8150 /system/lib/ld-musl-aarch64.so.1(write+68)(90776dcdb3f38042fc78b97d93138bde)
  03-06 13:55:25.876   20440-20440   C02D11/process...fxFaultLogger  pid-20440             I     #01 pc 0000000000001cf8 /data/storage/el1/bundle/libs/arm64/libentry.so(testSIGPIPE()+228)(d6af99a8111f4c2761800cb1432bea140f5176e4)
  03-06 13:55:25.876   20440-20440   C02D11/process...fxFaultLogger  pid-20440             I     #02 pc 0000000000001e34 /data/storage/el1/bundle/libs/arm64/libentry.so(d6af99a8111f4c2761800cb1432bea140f5176e4)
  ...
  ```

<!--RP10-->
<!--RP10End-->
