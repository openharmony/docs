# Cpp Crash（进程崩溃）检测

## 简介

进程发生崩溃后，系统首先感知到崩溃，然后抓取崩溃相关的信息、最后生成崩溃日志并上报崩溃事件，为开发者提供详细的维测日志以辅助故障定位。本文分为基本概念、实现原理、约束与限制、日志获取、日志规格五个小节介绍系统提供的CppCrash检测方法。开发者如果想进一步了解如何分析CppCrash问题，请参见[CppCrash类问题分析方法](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-app-crash-cpp-way)。

## 基本概念

- **信号**
  信号是兼容posix的操作系统中进程间通讯的一种方式。一种异步的通知机制，当一个信号发送给一个进程，操作系统中断进程正常的控制流程。

- **信号处理函数**
  定义了进程在接收到信号之后进行一系列处理操作的函数，信号处理函数需要定义清楚需要处理哪些信号。

- **pc**
  全称Program Counter（程序计数器），储存当前程序正在执行指令的地址。

- **调用栈**
  记录每个线程从开始到执行当前现场（如崩溃现场）整个过程中函数调用顺序。

- **寄存器**
  CPU中高速存储单元，用于存储计算机程序执行过程中所需要的数据、指令地址或状态信息。本文中寄存器信息是指崩溃时高速存储单元中保存的数据、指令地址或状态信息。

## 实现原理

系统检测进程崩溃的流程如下：

1. 进程运行时崩溃后收到来自内核发送的崩溃信号，由进程在启动时注册的信号处理模块进行处理。

2. 进程接收到崩溃信号后，保存当前进程上下文，fork出子进程执行ProcessDump二进制抓取崩溃信息。

3. ProcessDump进程将崩溃日志数据写入到临时目录下进行存储。

4. ProcessDump进程收集完崩溃日志后，上报给Hiview进程，Hiview将崩溃日志存储到 /data/log/faultlog/faultlogger目录下并生成故障事件。

### 系统处理的崩溃信号

系统的进程崩溃检测能力主要基于posix信号机制，目前支持对以下崩溃信号的处理：

| 信号值(signo) | 信号 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 4 | SIGILL | 非法指令。 | 进程执行了非法、格式错误、未知或特权指令。 |
| 5 | SIGTRAP | 断点或陷阱异常。 | 异常或trap指令发生。 |
| 6 | SIGABRT | 进程终止。 | 进程异常终止，通常为进程自身调用标准函数库的abort()函数。 |
| 7 | SIGBUS | 非法内存访问。 | 进程访问了对齐或者不存在的物理地址。 |
| 8 | SIGFPE | 浮点异常。 | 进程执行了错误的算术运算，如除数为0、浮点溢出、整数溢出等。 |
| 11 | SIGSEGV | 无效内存访问。 | 进程访问了无效内存引用。 |
| 16 | SIGSTKFLT | 栈错误。 | 处理器执行了错误的栈操作，如栈空时弹出、栈满时压入。 |
| 31 | SIGSYS | 错误的系统调用。 | 系统调用时使用了错误或非法参数。 |

以上系统处理的崩溃信号，根据错误码（code）还有二级分类，二级分类如下：

### SIGILL崩溃类型

SIGILL是一个在Unix和类Unix操作系统中的信号，它表示非法指令异常。SIGILL信号通常由以下几种类型的问题场景引起：

| 错误码（code） | 信号字符串 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 1 | ILL_ILLOPC | 非法操作码异常。 | 发生在执行不被CPU支持的指令时，或者在尝试执行特权指令时。 |
| 2 | ILL_ILLOPN | 非法操作数异常。 | 发生在指令使用了不正确的操作数，或者是操作数的类型不正确时。 |
| 3 | ILL_ILLADR | 非法地址异常。 | 发生在程序尝试访问无效的内存地址时，或者是在尝试执行未对齐的内存访问时。 |
| 4 | ILL_ILLTRP | 非法陷阱异常。 | 发生在程序尝试执行一个非法的陷阱指令时，或者是在尝试执行一个未定义的操作时。 |
| 5 | ILL_PRVOPC | 特权操作码异常。 | 发生在普通用户尝试执行特权指令时。 |
| 6 | ILL_PRVREG | 特权寄存器异常。 | 发生在普通用户尝试访问特权寄存器时。 |
| 7 | ILL_COPROC | 协处理器异常。 | 发生在程序尝试使用未定义的协处理器指令时。 |
| 8 | ILL_BADSTK | 无效的堆栈异常。 | 发生在程序尝试在无效的堆栈地址上执行操作时，或者是在堆栈溢出时。 |
| 0xacac | ILL_ILLPACCFI | 指针校验异常。 | 发生在程序校验指针失败时。 |

### SIGTRAP崩溃类型

SIGTRAP信号通常用于调试和跟踪程序的执行。下面是SIGTRAP信号类别的问题场景介绍：

| 错误码（code） | 信号字符串 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 1 | TRAP_BRKPT | 软件断点。 | 由软件断点引起的，当程序执行到设置的断点时会触发该信号。软件断点通常用于调试程序，可以在程序的关键位置设置断点，以便在调试时暂停程序的执行并检查变量值等信息。 |
| 2 | TRAP_TRACE | 单步调试。 | 由单步执行引起的，当程序执行单个指令时会触发该信号。单步执行通常用于调试程序，可以逐步执行程序并检查每个指令的执行结果。 |
| 3 | TRAP_BRANCH | 分支跟踪。 | 由分支指令引起的，当程序执行分支指令时会触发该信号。分支指令通常用于控制程序的执行流程，例如if语句和循环语句等。 |
| 4 | TRAP_HWBKPT | 硬件断点。 | 由硬件断点引起的，当程序执行到设置的硬件断点时会触发该信号。硬件断点通常用于调试程序，可以在程序的关键位置设置断点，以便在调试时暂停程序的执行并检查变量值等信息。与软件断点不同的是，硬件断点是由CPU硬件实现的，因此可以在程序执行过程中实时检测断点是否被触发。 |

### SIGBUS崩溃类型

SIGBUS是一种由操作系统向进程发送的信号，通常表示内存访问错误。其中，不同的信号类别表示不同的错误场景：

| 错误码（code） | 信号字符串 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 1 | BUS_ADRALN | 内存地址对齐错误。 | 发生在尝试访问未对齐的内存地址时，例如尝试访问一个4字节整数的非偶数地址。 |
| 2 | BUS_ADRERR | 非法内存地址错误。 | 发生在尝试访问不属于进程地址空间的内存地址时，例如尝试访问一个空指针。 |
| 3 | BUS_OBJERR | 对象访问错误。 | 发生在尝试访问一个已经被删除或未初始化的对象时。 |
| 4 | BUS_MCEERR_AR | 硬件内存校验错误。 | 发生在访问内存时检测到校验和错误。 |
| 5 | BUS_MCEERR_AO | 硬件内存校验错误。 | 发生在访问内存时检测到地址和校验和错误。 |

### SIGFPE崩溃类型

SIGFPE是一个信号，它表示浮点异常或算术异常。下面是这些SIGFPE信号类别的问题场景：

| 错误码（code） | 信号字符串 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 1 | FPE_INTDIV | 整数除法错误。 | 表示整数除法中的除数为零的情况。当一个程序尝试进行整数除法，但除数为零时，会发出这个信号。 |
| 2 | FPE_INTOVF | 整数溢出错误。 | 表示整数溢出错误。当一个程序尝试进行整数运算，结果超出整数范围时，会发出这个信号。 |
| 3 | FPE_FLTDIV | 浮点除法错误。 | 表示浮点数除法中的除数为零的情况。当一个程序尝试进行浮点数除法，但除数为零时，会发出这个信号。 |
| 4 | FPE_FLTOVF | 浮点上溢错误。 | 表示浮点溢出错误。当一个程序尝试进行浮点数运算，结果超出浮点数上限范围时，会发出这个信号。 |
| 5 | FPE_FLTUND | 浮点下溢错误。 | 表示浮点下溢错误。当一个程序尝试进行浮点数运算，结果小于浮点数下限范围时，会发出这个信号。 |
| 6 | FPE_FLTRES | 浮点结果未定义错误。 | 表示浮点结果未定义错误。当一个程序尝试进行浮点数运算，结果未定义时，会发出这个信号。 |
| 7 | FPE_FLTINV | 无效浮点操作错误。 | 表示无效浮点操作错误。当一个程序尝试进行无效的浮点数运算时，会发出这个信号。 |
| 8 | FPE_FLTSUB | 浮点运算结果越界错误。 | 表示浮点运算结果越界错误。当一个程序尝试进行浮点数运算，浮点数结果越界，会发出这个信号。 |

### SIGSEGV崩溃类型

SIGSEGV是一种信号，它表示进程试图访问一个不属于它的内存地址，或者试图访问一个已被操作系统标记为不可访问的内存地址。SIGSEGV信号通常是由以下两种情况引起的：

| 错误码（code） | 信号字符串 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 1 | SEGV_MAPERR | 不存在的内存地址。 | 进程试图访问一个不存在的内存地址，或者试图访问一个没有映射到进程地址空间的内存地址。这种情况通常是由于程序中的指针错误或内存泄漏引起的。 |
| 2 | SEGV_ACCERR | 不可访问的内存地址。 | 进程试图访问一个已被操作系统标记为不可访问的内存地址，例如只读内存或没有执行权限的内存。这种情况通常是由于程序中的缓冲区溢出或者试图修改只读内存等错误引起的。 |

### 信号产生原因分类类型

除了以上根据信号值维度分类，还可以根据信号产生的原因维度分类。所有信号值都可以按照信号产生的原因分类，当前已有信号产生原因分类的code值如下：

| 错误码（code） | 信号字符串 | 解释 | 触发原因 |
| -------- | -------- | -------- | -------- |
| 0 | SI_USER | 用户空间信号。 | 由用户空间的进程发送给进程的，通常是通过kill()系统调用发送的。例如，当用户在终端中按下Ctrl+C时，会发送一个SIGINT信号给前台进程组中的所有进程。 |
| 0x80 | SI_KERNEL | 内核信号。 | 由内核发送给进程的，通常是由内核检测到某些错误或异常情况时发出的。例如，当进程访问无效的内存地址或者执行非法指令时，内核会发送一个SIGSEGV信号给进程。 |
| -1 | SI_QUEUE | sigqueue()函数信号。 | 由sigqueue()系统调用发送的，可以携带一个附加的整数值和一个指针。通常用于进程间高级通信，例如传递数据或者通知进程某个事件已经发生。 |
| -2 | SI_TIMER | 定时器信号。 | 由定时器发送的，通常用于定时任务或者周期性任务的执行。例如，当一个定时器到期时，内核会向进程发送一个SIGALRM信号。 |
| -3 | SI_MESGQ | 消息队列信号。 | 由消息队列发送的，通常用于进程间通信。例如，当一个进程向一个消息队列发送消息时，内核会向接收进程发送一个MESGQ信号。 |
| -4 | SI_ASYNCIO | 异步I/O信号。 | 由异步I/O操作发送的，通常用于非阻塞I/O操作。例如，当一个文件描述符上的I/O操作完成时，内核会向进程发送一个ASYNCIO信号。 |
| -5 | SI_SIGIO | 同步I/O信号。 | 由同步I/O操作发送的，通常用于阻塞I/O操作。例如，当一个文件描述符上的I/O操作完成时，内核会向进程发送一个SIGIO信号。 |
| -6 | SI_TKILL | tkill()函数信号。 | 由tkill()系统调用发送的，与kill()系统调用类似，但是可以指定发送信号的线程ID。通常用于多线程程序中，向指定线程发送信号。 |

## 约束与限制

- 不建议进程自己注册信号处理函数，进程崩溃后可能会延迟退出，当处理时间超过5s可能会导致进程无响应问题上报

- /data/log/faultlog/faultlogger目录下同一进程/应用最多保存10份cppcrash日志，日志数量超限时会从最早生成该进程/应用的cppcrash日志开始删除直至数量不超限。建议开发者在开发调试阶段及时查看cppcrash日志，避免因cppcrash日志被删除而无法获取崩溃信息。

- 上述崩溃信号和35、38、42信号已经被系统注册信号处理函数，建议应用不要对这些信号注册信号处理函数，如果应用注册了可能会造成系统检测能力失效。

- 异步线程栈跟踪维测功能仅在ARM 64位系统且应用在debug模式下开启，崩溃日志规格请参见[异步线程栈跟踪故障场景日志规格](#异步线程栈跟踪故障场景日志规格)。

## 日志获取

进程崩溃日志是故障日志中的一种，可通过以下方式获取：

**方式一：通过DevEco Studio获取日志**

DevEco Studio会收集设备/data/log/faultlog/faultlogger/路径下的进程崩溃故障日志到FaultLog下，根据进程名和故障类型分类显示。获取日志的方法参见：[DevEco Studio使用指南-FaultLog](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-fault-log)。

**方式二：通过HiAppEvent接口订阅**

HiAppEvent给开发者提供了故障订阅接口，详见[HiAppEvent介绍](hiappevent-intro.md)。参考[订阅崩溃事件（ArkTS）](hiappevent-watcher-crash-events-arkts.md)或[订阅崩溃事件（C/C++）](hiappevent-watcher-crash-events-ndk.md)完成崩溃事件订阅，并通过事件的[external_log](hiappevent-watcher-crash-events.md#事件字段说明)字段读取故障日志文件内容。

**方式三：通过hdc获取日志，需打开开发者选项**

在开发者选项打开的情况下，开发者可以通过hdc file recv /data/log/faultlog/faultlogger D:\命令导出故障日志到本地，故障日志文件名格式为：cppcrash-进程名-进程UID-毫秒级时间.log。

## 日志规格

不同的故障场景中日志规格略有不同，分以下六个场景分别介绍日志规格：

- [通常故障场景日志规格](#一般故障场景日志规格)

- [空指针解引用故障场景日志规格](#空指针解引用故障场景日志规格)

- [栈溢出故障场景日志规格](#栈溢出故障场景日志规格)

- [栈覆盖故障场景日志规格](#栈覆盖故障场景日志规格)

- [异步线程栈跟踪故障场景日志规格](#异步线程栈跟踪故障场景日志规格)

- [应用通过HiAppEvent设置崩溃日志配置参数场景日志规格](#应用通过hiappevent设置崩溃日志配置参数场景日志规格)

> **说明：**
>
> 以下崩溃日志示例中"&lt;-"右边的文字不是日志内容，是用来解释日志格式的说明文字。

### 一般故障场景日志规格

本节主要介绍崩溃日志的一般日志规格，其余节介绍特殊场景下日志规格，以下是一份DevEco Studio归档在FaultLog的进程崩溃日志的核心内容。

```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:HarmonyOS 3.2   <- 设备信息
Build info:HarmonyOS 5.1.0.101 <- 版本信息
Fingerprint:a27608aa3ce72b14c242ff04332a122b7bb629b85771a051f25fb1af8c90b613 <- 标识故障特征
Module name:crasher_cpp <- 模块名
Timestamp:2017-08-06 21:52:51.000 <- 故障发生时间戳
Pid:10208 <- 进程号
Uid:0     <- 用户ID
HiTraceId:a92ab1c7eae68fa  <- HiTraceId(非必选，进程无HiTraceId不打印)
Process name:./crasher_cpp <- 进程名称
Process life time:1s  <- 进程存活时间
Process Memory(kB): 11902(Rss)     <- 进程占用内存
Device Memory(kB): Total 1935820, Free 516244, Available 1205608 <- 整机内存状态（非必选）
Reason:Signal:SIGSEGV(SI_TKILL)@0x000027e0 from:10208:0 <- 故障原因，详见信号值说明
Fault thread info:
Tid:10208, Name:crasher_cpp  <- 故障线程号，线程名
#00 pc 000e8400 /system/lib/ld-musl-arm.so.1(raise+176)(a40044d0acb68107cfc4adb5049c0725) <- 调用栈，调用顺序#06->#05->...->#00，最终在#00的函数中发生崩溃
#01 pc 00006e95 /data/crasher_cpp(DfxCrasher::RaiseSegmentFaultException()+92)(d6cead5be17c9bb7eee2a9b4df4b7626)
#02 pc 00008909 /data/crasher_cpp(DfxCrasher::ParseAndDoCrash(char const*) const+612)(d6cead5be17c9bb7eee2a9b4df4b7626)
#03 pc 00008bed /data/crasher_cpp(main+104)(d6cead5be17c9bb7eee2a9b4df4b7626)
#04 pc 00073370 /system/lib/ld-musl-arm.so.1(libc_start_main_stage2+72)(a40044d0acb68107cfc4adb5049c0725)
#05 pc 00005ad8 /data/crasher_cpp(_start_c+84)(d6cead5be17c9bb7eee2a9b4df4b7626)
#06 pc 00005a7c /data/crasher_cpp(d6cead5be17c9bb7eee2a9b4df4b7626)
Registers:  <- 故障现场寄存器
r0:00000000 r1:ffc09854 r2:00000000 r3:00000008
r4:00000000 r5:fffff000 r6:0000000a r7:000000af
r8:ffc09919 r9:ffc09930 r10:00000000
fp:ffc098e8 ip:005b76e4 sp:ffc09850 lr:005ade99 pc:f7bb0400
cpsr:20870010           <-  状态寄存器值（arm32架构为cpsr，aarch64架构为pstate和esr）
Memory near registers:  <-  故障现场寄存器的地址（地址必须在有效内存中）附近内存值，括号表示寄存器里的地址是在哪一段内存中
r1([stack]):          <- 故障现场r1寄存器的地址附近内存值
    ffc0984c f7bd8348
    ffc09850 7467a186
    ffc09854 00000000
    ffc09858 00000000
    ...
r8([stack]):
    ffc09910 005b51b8
    ffc09914 ffc09964
    ffc09918 4749530e
    ffc0991c 56474553
    ffc09920 00000000
    ...
r9([stack]):
    ffc09928 005b51a4
    ffc0992c 00000000
    ffc09930 005b51f0
    ffc09934 f7756e08
    ...
fp([stack]):
    ffc098e0 0000000a
    ffc098e4 ffc09919
    ffc098e8 005b51a4
    ffc098ec 005ade99
    ...
r12(/data/crasher_cpp):
    005b76dc f76ee7f4
    005b76e0 f76ee7dc
    005b76e4 f7bb0350
    005b76e8 f75c83e5
    ...
sp([stack]):
    ffc09848 ffc09870
    ffc0984c f7bd8348
    ffc09850 7467a186
    ffc09854 00000000
    ...
lr(/data/crasher_cpp):
    005ade90 200befc0
    005ade94 ed8cf005
    005ade98 49099801
    005ade9c 68094479
    ...
pc(/system/lib/ld-musl-arm.so.1):
    f7bb03f8 e3a03008
    f7bb03fc ef000000
    f7bb0400 e51b0014
    f7bb0404 e59f1024
    ...
FaultStack: <- 崩溃线程的栈地址空间
    ffc09810 00000001 
    ffc09814 00000001
    ...
sp0:ffc09850 7467a186 <- #00层栈帧顶部位置
    ffc09854 00000000
    ...
sp1:ffc098f0 f7756e08
    ffc098f4 7467a186
    ...
sp2:ffc09908 00000000
    ffc0990c 005b51f0
    ...
sp3:ffc099f0 ffc09a44
    ffc099f4 7467a186
    ...
    ffc09a00 005afb85
    ffc09a04 f7b3b374
    ffc09a08 ffc09a44
    ffc09a0c 00000000
    ffc09a10 00000000
    ffc09a14 f7aeec24
    ffc09a18 ffc09a38
    ffc09a1c 005acadc
    ffc09a20 005b38d0
    ffc09a24 00000000
    ffc09a28 00000000
    ffc09a2c ffc09a44
    ffc09a30 00000002
    ffc09a34 ffc09a40
    ffc09a38 00000000
    ffc09a3c 005aca80
sp5:ffc09a40 00000002
    ffc09a44 ffc09e25
    ...

Maps: <- 故障时进程的内存空间
5a7000-5ac000 r--p 00000000 /data/crasher_cpp
5ac000-5b5000 r-xp 00004000 /data/crasher_cpp
5b5000-5b8000 r--p 0000c000 /data/crasher_cpp
5b8000-5b9000 rw-p 0000e000 /data/crasher_cpp
2290000-2291000 ---p 00000000 [heap]
2291000-2293000 rw-p 00000000 [heap]
...
f7ac4000-f7ac5000 r-xp 00000000 [sigpage]
f7ac5000-f7ac7000 r--p 00000000 [vvar]
f7ac7000-f7ac8000 r-xp 00000000 [vdso]
f7ac8000-f7b22000 r--p 00000000 /system/lib/ld-musl-arm.so.1
f7b22000-f7bec000 r-xp 00059000 /system/lib/ld-musl-arm.so.1
f7bec000-f7bee000 r--p 00122000 /system/lib/ld-musl-arm.so.1
f7bee000-f7bf0000 rw-p 00123000 /system/lib/ld-musl-arm.so.1
f7bf0000-f7c00000 rw-p 00000000 [anon:ld-musl-arm.so.1.bss]
ffbe9000-ffc0a000 rw-p 00000000 [stack]
ffff0000-ffff1000 r-xp 00000000 [vectors]
OpenFiles: <- 故障时进程持有文件句柄信息
0->/dev/pts/0 native object of unknown type 0
1->/dev/pts/0 native object of unknown type 0
2->/dev/pts/0 native object of unknown type 0
3->socket:[102975] native object of unknown type 0
9->socket:[13080] native object of unknown type 0
14->/dev/console native object of unknown type 0

HiLog: <- 故障之前进程打印的流水日志
08-06 21:52:51.212 10208 10208 E C03f00/MUSL-SIGCHAIN: signal_chain_handler call 2 rd sigchain action for signal: 11 sca_sigaction=f7b3e638 noreturn=0 FREEZE_signo_11 thread_list_lock_status:-1 tl_lock_count=0 tl_lock_waiters=0 tl_lock_tid_fail=-1 tl_lock_count_tid=-1 tl_lock_count_fail=-10000 tl_lock_count_tid_sub=-1 thread_list_lock_after_lock=-1 thread_list_lock_pre_unlock=-1 thread_list_lock_pthread_exit=-1 thread_list_lock_tid_overlimit=-1 tl_lock_unlock_count=0 __pthread_gettid_np_tl_lock=0 __pthread_exit_tl_lock=0 __pthread_create_tl_lock=0 __pthread_key_delete_tl_lock=0 __synccall_tl_lock=0 __membarrier_tl_lock=0 install_new_tls_tl_lock=0 set_syscall_hooks_tl_lock=0 set_syscall_hooks_linux_tl_lock=0 fork_tl_lock=0
08-06 21:52:51.212 10208 10208 I C02d11/DfxSignalHandler: DFX_SigchainHandler :: signo(11), si_code(-6), pid(10208), tid(10208).
08-06 21:52:51.212 10208 10208 I C02d11/DfxSignalHandler: DFX_SigchainHandler :: signo(11), pid(10208), processName(./crasher_cpp),         threadName(crasher_cpp).
```

**HiTraceId说明**

HiTraceId：HiTraceChain提供的唯一跟踪标识，参考[HiTraceId](../reference/apis-performance-analysis-kit/capi-trace-h.md)。

**栈帧内容说明**

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

```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:HarmonyOS 3.2        <- 设备信息
Build info:HarmonyOS 5.0.0.23    <- 版本信息
Fingerprint:cdf52fd0cc328fc432459928f3ed8edfe8a72a92ee7316445143bed179138073 <- 标识故障特征
Module name:crasher_cpp            <- 模块名
Timestamp:2024-05-06 20:10:51.000  <- 故障发生时间戳
Pid:9623   <- 进程号
Uid:0         <- 用户ID
HiTraceId:a92ab1c7eae68fa  <- HiTraceId(非必选，进程无HiTraceId不打印)
Process name:./crasher_cpp         <- 进程名称
Process life time:1s               <- 进程存活时间
Process Memory(kB): 11902(Rss)     <- 进程占用内存
Device Memory(kB): Total 1935820, Free 516244, Available 1205608 <- 整机内存状态（非必选）
Reason:Signal:SIGSEGV(SEGV_MAPERR)@0x00000004  probably caused by NULL pointer dereference   <- 故障原因和空指针提示
Fault thread info:
Tid:9623, Name:crasher_cpp         <- 故障线程号，线程名
#00 pc 00008d22 /system/bin/crasher_cpp(TestNullPointerDereferenceCrash0()+22)(adfc673300571d2da1e47d1d12f48b44)  <- 调用栈
#01 pc 000064d1 /system/bin/crasher_cpp(DfxCrasher::ParseAndDoCrash(char const*) const+160)(adfc673300571d2da1e47d1d12f48b44)
#02 pc 00006569 /system/bin/crasher_cpp(main+92)(adfc673300571d2da1e47d1d12f48b44)
#03 pc 00072b98 /system/lib/ld-musl-arm.so.1(libc_start_main_stage2+56)(d820b1827e57855d4f9ed03ba5dfea83)
#04 pc 00004e28 /system/bin/crasher_cpp(_start_c+84)(adfc673300571d2da1e47d1d12f48b44)
#05 pc 00004dcc /system/bin/crasher_cpp(adfc673300571d2da1e47d1d12f48b44)
Registers:   <- 故障现场寄存器
r0:ffffafd2 r1:00000004 r2:00000001 r3:00000000
r4:ffd27e39 r5:0096e000 r6:00000a40 r7:0096fdfc
r8:f7ba58d5 r9:f7baea86 r10:f7cadd38
fp:ffd27308 ip:f7cb2078 sp:ffd272a0 lr:f7c7ab98 pc:0096ad22
cpsr:20870010           <-  状态寄存器值（arm32架构为cpsr，aarch64架构为pstate和esr）
...
```

### 栈溢出故障场景日志规格

以下三种场景容易出现栈溢出：

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

```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:HarmonyOS 3.2            <- 设备信息
Build info:HarmonyOS 5.0.0.23        <- 版本信息
Fingerprint:8bc3343f50024204e258b8dce86f41f8fcc50c4d25d56b24e71fe26c0a23e321  <- 标识故障特征
Module name:crasher_cpp                <- 模块名
Timestamp:2024-05-06 20:18:24.000      <- 故障发生时间戳
Pid:9838                               <- 进程号
Uid:0                                  <- 用户ID
HiTraceId:a92ab1c7eae68fa  <- HiTraceId(非必选，进程无HiTraceId不打印)
Process name:./crasher_cpp             <- 进程名称
Process life time:2s                   <- 进程存活时间
Process Memory(kB): 11902(Rss)     <- 进程占用内存
Device Memory(kB): Total 1935820, Free 516244, Available 1205608 <- 整机内存状态（非必选）
Reason:Signal:SIGSEGV(SEGV_ACCERR)@0xf76b7ffc  current thread stack low address = 0xf76b8000, probably caused by stack-buffer-overflow    <- 故障原因和栈溢出提示
Tid:10343, Name:crasher_cpp
#00 pc 000072e6 /data/crasher_cpp(DoStackOverflow(void*)+30)(d6cead5be17c9bb7eee2a9b4df4b7626)
#01 pc 00007305 /data/crasher_cpp(DoStackOverflow(void*)+60)(d6cead5be17c9bb7eee2a9b4df4b7626)
#02 pc 00007305 /data/crasher_cpp(DoStackOverflow(void*)+60)(d6cead5be17c9bb7eee2a9b4df4b7626)
#03 pc 00007305 /data/crasher_cpp(DoStackOverflow(void*)+60)(d6cead5be17c9bb7eee2a9b4df4b7626)
#04 pc 00007305 /data/crasher_cpp(DoStackOverflow(void*)+60)(d6cead5be17c9bb7eee2a9b4df4b7626)
#05 pc 00007305 /data/crasher_cpp(DoStackOverflow(void*)+60)(d6cead5be17c9bb7eee2a9b4df4b7626)
...
```

### 栈覆盖故障场景日志规格

栈覆盖故障场景是指业务代码运行时改写了原本保存函数调用信息的栈内存，导致无法成功回溯调用栈。系统在回栈失败后尽可能提供开发者信息以分析问题，该场景会在日志中打印信息提示从\#xx开始尝试从线程栈内存里解析不可靠的调用栈。之所以说不可靠的调用栈，是因为调用栈可能不是一个完整的函数调用链路，从\#xx层往下的调用栈是不可靠的意味着从\#xx层开始相邻两层栈之间可能不存在调用关系，需要开发者结合业务代码分析其中的调用链路，比如下例中正确的调用关系是\#05->\#04->\#03->\#01。以下是一份DevEco Studio归档在FaultLog的进程崩溃日志的核心内容。

```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:HarmonyOS 3.2               <- 设备信息
Build info:HarmonyOS 5.0.0.23           <- 版本信息
Fingerprint:79b6d47b87495edf27135a83dda8b1b4f9b13d37bda2560d43f2cf65358cd528    <- 标识故障特征
Module name:crasher_cpp                   <- 模块名
Timestamp:2024-05-06 20:27:23.2035266415  <- 故障发生时间戳
Pid:10026                                 <- 进程号
Uid:0                                     <- 用户ID
HiTraceId:a92ab1c7eae68fa  <- HiTraceId(非必选，进程无HiTraceId不打印)
Process name:./crasher_cpp                <- 进程名称
Process life time:1s                      <- 进程存活时间
Process Memory(kB): 11902(Rss)            <- 进程占用内存
Device Memory(kB): Total 1935820, Free 516244, Available 1205608 <- 整机内存状态（非必选）
Reason:Signal:SIGSEGV(SEGV_MAPERR)@0000000000  probably caused by NULL pointer dereference      <- 故障原因
LastFatalMessage:Failed to unwind stack, try to get unreliable call stack from #02 by reparsing thread stack <- #00和#01一般认为是可信的，从#02开始尝试从线程栈内存里解析不可靠的调用栈
Fault thread info:
Tid:10026, Name:crasher_cpp               <- 故障线程号，线程名
#00 pc 00000000 Not mapped
#01 pc 0002bcdb /system/lib/chipset-pub-sdk/libutils.z.so(memset_s+24)(15f72d32d228b22e72a13b438c75599d)
#02 pc 000f14a8 /system/lib/ld-musl-arm.so.1(printf+72)(a40044d0acb68107cfc4adb5049c0725)
#03 pc 00006d3b /data/crasher_cpp(RecursiveHelperFunction(int, int, int)+54)(d6cead5be17c9bb7eee2a9b4df4b7626)
#04 pc 00006d5b /data/crasher_cpp(RecursiveHelperFunction(int, int, int)+86)(d6cead5be17c9bb7eee2a9b4df4b7626)
#05 pc 00006d5b /data/crasher_cpp(RecursiveHelperFunction(int, int, int)+86)(d6cead5be17c9bb7eee2a9b4df4b7626)
...
Registers:
r0:00000000 r1:c2085db0 r2:00000000 r3:ff8970c8
r4:0000003f r5:00000000 r6:f755c0e0 r7:00000000
r8:ff8975c9 r9:ff8975e0 r10:00000001
fp:008de1a4 ip:f76b5c48 sp:ff896fd0 lr:f76abcdf pc:00000000
cpsr:20870010
...
```

### 异步线程栈跟踪故障场景日志规格

当异步线程发生崩溃后，把提交该异步任务的线程的栈也打印出来，帮助定位由于异步任务提交者造成的崩溃问题。崩溃线程的调用栈和其提交线程的调用栈通过SubmitterStacktrace字符串分隔。以下是一份DevEco Studio归档在FaultLog的进程崩溃日志的核心内容。

> **注意：**
>
> 异步线程栈跟踪维测功能仅在ARM 64位系统且应用在debug模式下开启。

```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:HarmonyOS 3.2                 <- 设备信息
Build info:HarmonyOS 5.0.0.23             <- 版本信息
Fingerprint:8bc3343f50024204e258b8dce86f41f8fcc50c4d25d56b24e71fe26c0a23e321  <- 标识故障特征
Module name:crasher_cpp                     <- 模块名
Timestamp:2024-05-06 20:28:24.000           <- 故障发生时间戳
Pid:9838                                    <- 进程号
Uid:0                                       <- 用户ID
HiTraceId:a92ab1c7eae68fa  <- HiTraceId(非必选，进程无HiTraceId不打印)
Process name:./crasher_cpp                  <- 进程名称
Process life time:2s                        <- 进程存活时间
Process Memory(kB): 11902(Rss)            <- 进程占用内存
Device Memory(kB): Total 1935820, Free 516244, Available 1205608 <- 整机内存状态（非必选）
Reason:Signal:SIGSEGV(SI_TKILL)@0x000000000004750  from:18256:0  <- 故障原因
Fault thread info:
Tid:18257, Name:crasher_cpp                 <- 故障线程号，线程名
#00 pc 000054e6 /system/bin/ld-musl-aarch64.so.l(raise+228)(adfc673300571d2da1e47d1d12f48b44)  <- 调用栈
#01 pc 000054f9 /system/bin/crasher_cpp(CrashInSubThread(void*)+56)(adfc673300571d2da1e47d1d12f48b50)
#02 pc 000054f9 /system/bin/ld-musl-aarch64.so.l(start+236)(adfc673300571d2da1e47d1d12f48b44)
========SubmitterStacktrace========       <- 任务异常时打印任务提交者调用栈#00 pc 000094dc /system/bin/crasher_cpp(DfxCrasher::AsyncStacktrace()+36)(adfc673300571d2da1e47d1d12f48b50)#01 pc 00009a58 /system/bin/crasher_cpp(DfxCrasher::ParseAndDoCrash(char const*) const+232)(adfc673300571d2da1e47d1d12f48b50)#02 pc 00009b40 /system/bin/crasher_cpp(main+140)(adfc673300571d2da1e47d1d12f48b50)#03 pc 0000a4e1c /system/bin/ld-musl-aarch64.so.l(libc_start_main_stage2+68)(adfc673300571d2da1e47d1d12f48b44)
...
```

### 应用通过HiAppEvent设置崩溃日志配置参数场景日志规格

系统提供了通用的崩溃日志生成功能，但一些应用对崩溃日志打印内容有个性化的需求，因此从**API version 20**开始HiAppEvent的[setEventConfig](hiappevent-watcher-crash-events.md#崩溃日志规格自定义参数设置)接口支持设置崩溃日志配置参数。以下是一份DevEco Studio归档在FaultLog的32位系统崩溃日志的核心内容：

```text
...
Build info:OpenHarmony 6.0.0.33
Enabled app log configs:    <- 使能的配置参数列表，只打印不是默认值的配置参数
Extend pc lr printing:true  <- extend_pc_lr_printing参数设置为true
Log cut off size:102400B    <- 崩溃日志大小截断到100KB（仅通过HiAppEvent接口订阅获取的崩溃日志生效）
Simplify maps printing:true <- simplify_vma_printing参数设置为true
Timestamp:2025-05-17 19:17:07.000
...
Registers: <- 故障现场寄存器
r0:00000000 r1:ff87d48c r2:00000000 r3:00000008
r4:00000000 r5:fffff000 r6:00000000 r7:000000af
r8:00c0b4f0 r9:00c0bdc0 r10:00c0bdc0
fp:ff87d520 ip:00c0a6e4 sp:ff87d488 lr:f7ecc044 pc:f7f19940
cpsr:00800010
Memory near registers:
...
lr(/system/lib/ld-musl-arm.so.1): <- lr寄存器地址附近的内存值
    f7ecbfc8 e0824000 <- extend_pc_lr_printing设置为true时，向前打印内存值到此
    ...
    f7ecc03c e3a00006 <- extend_pc_lr_printing设置为false时，向前打印内存值到此
    f7ecc040 eb013612
    f7ecc044 e59f10b0 <- lr寄存器地址（f7ecc044）的内存值（e59f10b0）
    ...
    f7ecc0b8 e58d4004 <- extend_pc_lr_printing设置为false时，向后打印内存值到此
    f7ecc0bc e1a0100d
    f7ecc0c0 e3a00020
    f7ecc0c4 e3a070af <- extend_pc_lr_printing设置为true时，向后打印内存值到此
pc(/system/lib/ld-musl-arm.so.1): <- pc寄存器地址附近的内存值
    f7f198c4 e5900000 <- extend_pc_lr_printing设置为true时，向前打印内存值到此
    ...
    f7f19938 e3a03008 <- extend_pc_lr_printing设置为false时，向前打印内存值到此
    f7f1993c ef000000
    f7f19940 e51b0014 <- pc寄存器地址（f7f19940）的内存值（e51b0014）
    ... 
    f7f199b4 e2b52000 <- extend_pc_lr_printing设置为false时，向后打印内存值到此
    f7f199b8 03530000
    f7f199bc 0a000003
    f7f199c0 ebfec957 <- extend_pc_lr_printing设置为true时，向后打印内存值到此
...
Maps:       <- simplify_vma_printing设置为true，打印Maps数量减少，只保留崩溃日志中出现的地址所属的Maps
ba0000-ba9000 r--p 00000000 /data/test/test_signalhandler
ba9000-bd8000 r-xp 00008000 /data/test/test_signalhandler
bd8000-bdb000 r--p 00036000 /data/test/test_signalhandler
bdb000-bdc000 rw-p 00038000 /data/test/test_signalhandler
... <- 继续打印崩溃日志中出现的地址所属的Maps，此处省略不展示
OpenFiles:
...
[truncated]  <- 日志截断的标志符，如果有打印说明日志被截断了
```
