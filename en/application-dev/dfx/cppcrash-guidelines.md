# C++ Crash (Process Crash) Detection
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @chenshi51-->
<!--Designer: @Maplestory91-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## Overview

After a process crashes, the system detects the crash, captures crash information, generates crash logs, and reports crash events, providing detailed maintenance and debugging logs for you to locate faults. This topic describes the CppCrash detection methods provided by the system in terms of basic concepts, implementation principles, restrictions, log obtaining, and log specifications.  

## Basic Concepts

- **Signal**

  A mechanism for inter-process communication in POSIX-compliant operating systems. It provides asynchronous notifications that interrupt the target process's normal control flow.

- **Signal handler**

  Contains functions executed by a process after it receives a particular signal. It must be registered for the specific signals it is intended to handle.

- **pc**

  Program Counter (PC) stores the address of the instruction that is being executed by the program.

- **Call stack**

  Records the sequence of function calls for each thread, from its start up to the current point (such as the crash site).

- **Register**

  High-speed storage unit in the CPU, which are used to store data, instruction addresses, or status information required during the execution of computer programs. In this topic, register information refers to the data, instruction addresses, or status information stored in the register when a crash occurs.

## Implementation Principles

The system detects a process crash as follows:

- After a process crashes, it receives a crash signal from the kernel, which is processed by the signal handling module registered by the process during startup.

- After receiving the crash signal, the process saves the current process context and forks a child process to execute the **ProcessDump** command to capture crash information.

3. The **ProcessDump** process writes the crash log data to a temporary directory for storage.

4. After collecting crash logs, the **ProcessDump** process reports the logs to the HiView process, supplements some information (such as the system memory status and application page switching history) that can be obtained only by HiView, stores the crash logs in the **/data/log/faultlog/faultlogger** directory, and generates a fault event.

### Crash Signals

Based on the POSIX signal mechanism, the system's process crash detection capability supports the following crash signals.

| Signo| Signal| Description| Trigger Cause|
| -------- | -------- | -------- | -------- |
| 4 | SIGILL | Invalid instruction| An invalid, incorrectly formatted, unknown, or privileged instruction is executed.|
| 5 | SIGTRAP | Breakpoint or trap| An exception occurs or a trap instruction is executed.|
| 6 | SIGABRT | Process abort| The process is aborted abnormally. Generally, this exception occurs when the process calls **abort()** in the Standard Function Library.|
| 7 | SIGBUS | Illegal memory access| The process accesses an unaligned or nonexistent physical address.|
| 8 | SIGFPE | Floating-point exception| An incorrect arithmetic operation is executed, for example, a 0 divisor, floating point overflow, or integer overflow.|
| 11 | SIGSEGV | Invalid memory access| The process accesses an invalid memory region.|
| 16 | SIGSTKFLT | Stack error| The processor performs an incorrect stack operation, such as a pop when the stack is empty or a push when the stack is full.|
| 31 | SIGSYS | Incorrect system call| An incorrect or invalid parameter is used in a system call.|

Crash signals are classified by error code (**code**) as follows:

### SIGILL

**SIGILL** indicates an invalid instruction exception in Unix and Unix-like operating systems. The trigger causes of **SIGILL** are as follows.

| Error Code (**code**)| Value| Description| Trigger Cause|
| -------- | -------- | -------- | -------- |
| 1 | ILL_ILLOPC | Illegal operation code| An instruction not supported by the CPU or an invalid instruction is executed.|
| 2 | ILL_ILLOPN | Illegal operand| An incorrect operand or improper operand type is used.|
| 3 | ILL_ILLADR | Illegal address| The program accesses an invalid memory address or an unaligned memory address.|
| 4 | ILL_ILLTRP | Illegal trap| The program performs an illegal trap instruction or an undefined operation.|
| 5 | ILL_PRVOPC | Illegal privileged operation code| A common user executes a privileged instruction.|
| 6 | ILL_PRVREG | Illegal privileged register|  A common user accesses a privileged register.|
| 7 | ILL_COPROC | Illegal coprocessor| The program performs an undefined coprocessor instruction.|
| 8 | ILL_BADSTK | Illegal stack| The program performs an operation at an invalid stack address, or when the stack overflows.|
| 0xacac | ILL_ILLPACCFI | Illegal pointer authentication| The program fails to verify a pointer.|

### SIGTRAP

**SIGTRAP** usually occurs in debugging and tracking. The trigger causes of **SIGTRAP** are as follows.

| Error Code (**code**)| Value| Description| Trigger Cause|
| -------- | -------- | -------- | -------- |
| 1 | TRAP_BRKPT | Software breakpoint| The program reaches the software breakpoint. When debugging a program, a software breakpoint at the key position can be used to pause the program execution and check information such as variable values.|
| 2 | TRAP_TRACE | Single-step debugging| The program executes a single instruction. Single instruction can be used to check the execution result of each instruction.|
| 3 | TRAP_BRANCH | Branch tracing| The program executes a branch instruction. Branch instruction can be used to control the execution process of a program, such as if statements and loop statements.|
| 4 | TRAP_HWBKPT | Hardware breakpoint| The program reaches the hardware breakpoint. When debugging a program, a hardware breakpoint at the key position can be used to pause the program execution and check information such as variable values. Unlike a software breakpoint, a hardware breakpoint is implemented in CPU hardware. Therefore, whether a hardware breakpoint is triggered can be detected in real time during program execution.|

### SIGBUS

The **SIGBUS** signal is sent by the operating system to a process. It usually indicates a memory access error. The trigger causes of **SIGBUS** are as follows.

| Error Code (**code**)| Value| Description| Trigger Cause|
| -------- | -------- | -------- | -------- |
| 1 | BUS_ADRALN | Unaligned memory address| The program accesses an unaligned memory address, for example, a non-even address of a 4-byte integer.|
| 2 | BUS_ADRERR | Invalid memory address| The program accesses a memory address that does not exist in the process address space, such as a null pointer.|
| 3 | BUS_OBJERR | Invalid object access| The program accesses a deleted or uninitialized object.|
| 4 | BUS_MCEERR_AR | Hardware memory error requiring immediate handling| The program accesses memory and encountered a hardware memory error requiring immediate handling.|
| 5 | BUS_MCEERR_AO | Hardware memory error requiring waiting or delayed handling| The program accesses memory and encountered a hardware memory error requiring waiting or delayed handling.|

### SIGFPE

The **SIGFPE** signal indicates a floating-point exception or an arithmetic exception. The trigger causes of **SIGFPE** are as follows.

| Error Code (**code**)| Value| Description| Trigger Cause|
| -------- | -------- | -------- | -------- |
| 1 | FPE_INTDIV | Invalid integer division|  The program performs an integer division operation while the divisor is zero.|
| 2 | FPE_INTOVF | Integer overflow|  The program performs an integer operation and the result exceeds the integer range.|
| 3 | FPE_FLTDIV | Invalid floating-point division|  The program performs a floating-point division operation while the divisor is zero.|
| 4 | FPE_FLTOVF | Floating-point overflow|  The program performs a floating-point operation and the result exceeds the upper limit of the floating-point number.|
| 5 | FPE_FLTUND | Floating-point underflow|  The program performs a floating-point operation and the result is less than the lower limit of the floating-point number.|
| 6 | FPE_FLTRES | Invalid floating-point result|  The program performs a floating-point operation and the result is undefined.|
| 7 | FPE_FLTINV | Invalid floating-point operation|  The program performs an invalid floating-point operation.|
| 8 | FPE_FLTSUB | Invalid floating-point operation result|  The program attempts to perform a floating-point operation and the floating-point result is out of range.|

### SIGSEGV

**SIGSEGV** occurs when a process accesses a non-existent memory address or an inaccessible address. The trigger causes of the **SIGSEGV** signal are described as follows:

| Error Code (**code**)| Value| Description| Trigger Cause|
| -------- | -------- | -------- | -------- |
| 1 | SEGV_MAPERR | Non-existent memory address| The process accesses a memory address that does not exist or that is not mapped to the process address space. This exception is usually caused by pointer errors or memory leaks.|
| 2 | SEGV_ACCERR | Inaccessible memory address| The process accesses an inaccessible memory address marked by the operating system, for example, writing data to read-only memory or executing memory without execution permission. This exception is usually caused by buffer overflow or modifying read-only memory.|

### Signal Causes

In addition to the preceding classification by **signo**, signals can also be classified by causes as follows.

| Error Code (**code**)| Value| Description| Trigger Cause|
| -------- | -------- | -------- | -------- |
| 0 | SI_USER | User space signal| Sent from a process in user space to another process, usually using **kill()**. For example, when a user presses **Ctrl+C** on the terminal, a **SIGINT** signal is sent to all foreground processes.|
| 0x80 | SI_KERNEL | Kernel signal| Sent from the kernel to a process when the kernel detects an error or exception. For example, when a process accesses an invalid memory address or executes an invalid instruction, the kernel sends a **SIGSEGV** signal to the process.|
| -1 | SI_QUEUE | **sigqueue()** signal| Sent from **sigqueue()**, with an additional integer value and a pointer can be carried. It is usually used for advanced communication between processes, such as transferring data or notifying a process that an event occurs.|
| -2 | SI_TIMER | Timer signal| Sent from a timer for executing scheduled tasks or periodic tasks. For example, when a timer expires, the kernel sends a **SIGALRM** signal to the process.|
| -3 | SI_MESGQ | Message queue signal| Sent from a message queue for inter-process communication. For example, when a process sends a message to a message queue, the kernel sends a **MESGQ** signal to the receiving process.|
| -4 | SI_ASYNCIO | Asynchronous I/O signal| Sent from an asynchronous I/O operation for non-blocking I/O operations. For example, when an I/O operation on a file descriptor is complete, the kernel sends an **ASYNCIO** signal to the process.|
| -5 | SI_SIGIO | Synchronous I/O signal| Sent from a synchronous I/O operation for blocking I/O operations. For example, when an I/O operation on a file descriptor is complete, the kernel sends a **SIGIO** signal to the process.|
| -6 | SI_TKILL | **tkill()** signal| Sent from the function **tkill()**, which is similar to the function **kill()**. Moreover, you can specify the ID of the thread that sends the signal using **tkill()**. It is usually used to send a signal to a specified thread in a multithreaded program.|

## Restrictions

- It is not recommended that the process register the signal handler; otherwise, if the process exit is delayed beyond 5s, the process freeze event may be reported.

- The **/data/log/faultlog/faultlogger** directory stores a maximum of 10 CppCrash logs for a process or application. If the upper limit is reached, the earliest CppCrash logs of the process or application will be deleted. It is recommended that you view the CppCrash logs in a timely manner during development and debugging to prevent crash information loss due to log deletion.

- The system has registered signal handlers for the preceding crash signals and signals **35**, **38**, and **42**. It is recommended that you do not register signal handlers for these signals in applications. Otherwise, the system detection capability may fail.

- The asynchronous thread stack tracing and maintenance functionality is enabled only in the ARM 64-bit system in debug mode. For details about the crash log specifications, see [Asynchronous Thread Stack Tracing Faults](#asynchronous-thread-stack-tracing-faults).

## Obtaining Logs

Process crash logs are a type of fault logs. You can obtain them in any of the following ways:

**Method 1: DevEco Studio**

DevEco Studio collects process crash logs from **/data/log/faultlog/faultlogger/** to FaultLog, where logs are displayed by process name and fault type. For details about how to obtain logs, see [DevEco Studio User Guide-Fault Log](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-fault-log).

**Method 2: HiAppEvent APIs**

HiAppEvent provides APIs for subscribing to faults. For details, see [Introduction to HiAppEvent](hiappevent-intro.md). You can subscribe to the crash event by referring to [Subscribing to Crash Events (ArkTS)](hiappevent-watcher-crash-events-arkts.md) or [Subscribing to Crash Events (C/C++)](hiappevent-watcher-crash-events-ndk.md), and read the fault log file content based on the [external_log](hiappevent-watcher-crash-events.md#fields) field of the event.

**Method 3: hdc**

Enable **Developer options** and run the hdc file recv /data/log/faultlog/faultlogger D:\ command to export fault logs to the local device. The fault log file name is in the format of **cppcrash-process name-process UID-millisecond-level timestamp.log**.

## Log Specifications

The following table describes the fields in a fault log.
|Field|Description|Initial API Version|Mandatory|Optional|
|---|---|---|---|---|
| Device info | Device information.| 8 | Yes| - |
| Build info | Build information.| 8 | Yes| - |
| Fingerprint | Fault feature, which is a hash value for faults of the same type.| 8 | Yes| - |
| Enabled app log configs | List of enabled configuration parameters.| 20 | No| This field is displayed when only when it is configured by users. For details, see [Application Crash Log Configured by HiAppEvent](application-crash-log-configured-by-hiappevent).|
| Module name | Module name.| 8 | Yes| - |
| Version | Application version (in dotted format).| 8 | No| This field is displayed only for application processes.|
| Version Code | Application version (in integer format).| 8 | No| This field is displayed only for application processes.|
| PreInstalled | Whether the application is pre-installed.| 8 | No| This field is displayed only for application processes.|
| Foreground | Foreground/Background status.| 8 | No| This field is displayed only for application processes.|
| Page switch history | Page switching history.| 21 | No| If the maintenance and debugging service process is faulty or the switching history is not cached, this field is not displayed. For details, see [Implementation Principles](#implementation-principles).|
| Timestamp | Fault occurrence timestamp.| 8 | Yes| - |
| Pid | Process ID.| 8 | Yes| - |
| Uid | User ID.| 8 | Yes| - |
| HiTraceId | HiTraceChain ID.| 20 | No| This field is displayed when the HiTraceChain functionality is enabled for the process. For details, see [HiTraceId](../reference/apis-performance-analysis-kit/capi-trace-h.md).|
| Process name | Name of the faulty process.| 8 | Yes| - |
| Process life time | Lifetime of the faulty process.| 8 | Yes| - |
| Process Memory(kB) | Memory usage of the faulty process.| 20 | Yes| - |
| Device Memory(kB) | System memory status.| 20 | No| This field depends on the maintenance and debugging service process. If the maintenance and debugging service process stops or the device restarts when a fault occurs, this field does not exist. For details, see [Implementation Principles](#implementation-principles).|
| Reason | Fault cause.| 8 | Yes| - |
| LastFatalMessage | Last **Fatal** log recorded by the application.| 8 | No| This field is displayed when the process is aborted and the last **Fatal** log is printed in HiLog.|
| Fault thread info | Fault thread information.| 8 | Yes| - |
| SubmitterStacktrace | Submitter thread stack.| 12 | No| The asynchronous thread stack tracing functionality is enabled only for debug-type applications in the ARM 64-bit system.|
| Register | Fault register.| 8 | Yes| - |
| Other thread info | Other thread information.| 8 | Yes| - |
| Memory near registers | Memory value near the fault register.| 8 | Yes| - |
| FaultStack | Fault thread stack memory information.| 8 | Yes| - |
| Maps | Memory space of the process when the fault occurs.| 8 | Yes| - |
| OpenFiles | File handle information held by the process when the fault occurs.| 12 | Yes| - |
| HiLog | HiLog logs printed before the fault occurs. A maximum of 1000 lines can be printed.| 8 | Yes| - |
| [truncated] | Fault log truncation flag.| 20 | No| This field is displayed when the fault log truncation size is configured and truncation occurs.|

The log specifications vary slightly according to different fault scenarios. The following lists log specifications of seven scenarios:

- [Common Faults](cppcrash-guidelines.md#common-faults)

- [Null Pointer Dereference](cppcrash-guidelines.md#null-pointer-dereference)

- [Stack Overflow](cppcrash-guidelines.md#stack-overflow)

- [Stack Corruptions](cppcrash-guidelines.md#stack-corruptions)

- [Asynchronous Thread Stack Tracing Faults](#asynchronous-thread-stack-tracing-faults)

- [Application Crash Log Configured by HiAppEvent](application-crash-log-configured-by-hiappevent)

- [Faults with Page Switching History](#faults-with-page-switching-history)

> **NOTE**
>
> In the following crash log examples, the text on the right of **<-** is used to explain the log format.

### Common Faults

The following describes the common crash log specifications and other log specifications in special scenarios. This example is the core content of a process crash log archived by DevEco Studio in FaultLog.

```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:HarmonyOS 3.2   <- Device information
Build info:HarmonyOS 5.1.0.101 <- Version information
Fingerprint:a27608aa3ce72b14c242ff04332a122b7bb629b85771a051f25fb1af8c90b613 <- Fault identification
Module name:crasher_cpp <- Module name
Timestamp:2017-08-06 21:52:51.000 <- Fault occurrence timestamp
Pid:10208 <- Process ID
Uid:0     <- User ID
HiTraceId:a92ab1c7eae68fa  <- HiTrace ID (Optional. If the process does not have HiTraceId, it is not printed.)
Process name:./crasher_cpp <- Process name
Process life time:1s  <- Process life time
Process Memory(kB): 11902(Rss)     <- Memory used by the process
Device Memory(kB): Total 1935820, Free 516244, Available 1205608 <- Device memory status (optional)
Reason:Signal:SIGSEGV(SI_TKILL)@0x000027e0 from:10208:0 <- Fault cause. For details, see the signal value description.
Fault thread info:           <- Faulty thread information
Tid:10208, Name:crasher_cpp  <- ID and name of the faulty thread
#00 pc 000e8400 /system/lib/ld-musl-arm.so.1(raise+176)(a40044d0acb68107cfc4adb5049c0725) <- Call stack. The call sequence is #06->#05->...->#00, and the crash occurs in the functions of #00.
#01 pc 00006e95 /data/crasher_cpp(DfxCrasher::RaiseSegmentFaultException()+92)(d6cead5be17c9bb7eee2a9b4df4b7626)
#02 pc 00008909 /data/crasher_cpp(DfxCrasher::ParseAndDoCrash(char const*) const+612)(d6cead5be17c9bb7eee2a9b4df4b7626)
#03 pc 00008bed /data/crasher_cpp(main+104)(d6cead5be17c9bb7eee2a9b4df4b7626)
#04 pc 00073370 /system/lib/ld-musl-arm.so.1(libc_start_main_stage2+72)(a40044d0acb68107cfc4adb5049c0725)
#05 pc 00005ad8 /data/crasher_cpp(_start_c+84)(d6cead5be17c9bb7eee2a9b4df4b7626)
#06 pc 00005a7c /data/crasher_cpp(d6cead5be17c9bb7eee2a9b4df4b7626)
Registers:  <- Fault registers
r0:00000000 r1:ffc09854 r2:00000000 r3:00000008
r4:00000000 r5:fffff000 r6:0000000a r7:000000af
r8:ffc09919 r9:ffc09930 r10:00000000
fp:ffc098e8 ip:005b76e4 sp:ffc09850 lr:005ade99 pc:f7bb0400
cpsr:20870010           <-  Value of status register (cpsr for the ARM32 architecture and pstate and esr for the AArch64 architecture)
Other thread info:      <- Other thread information
Tid:10209, Name:crasher_cpp <- Thread ID, thread name
#00 pc 00116974 /system/lib/ld-musl-arm.so.1(sleep+132)(a40044d0acb68107cfc4adb5049c0725) <- Call stack
#01 pc 0000a137 /data/crasher_cpp(void* std::__h::__thread_proxy[abi:v15004]<std::__h::tuple<std::__h::unique_ptr<std::__h::__thread_struct, std::__h::default_delete<std::__h::__thread_struct>>, DfxCrasher::MultiThreadCrash()::$_1>>(void*)+122)(d6cead5be17c9bb7eee2a9b4df4b7626)
#02 pc 00109104 /system/lib/ld-musl-arm.so.1(start+248)(a40044d0acb68107cfc4adb5049c0725)
#03 pc 00074134 /system/lib/ld-musl-arm.so.1(a40044d0acb68107cfc4adb5049c0725)
Memory near registers:  <-  Memory values near the address (which must be in valid memory) of the register at the fault site. The content in the brackets indicates the memory segment where the address in the register is located.
r1([stack]):          <- Memory value near the address of the r1 register at the fault site
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
FaultStack: <- Stack of the crashed thread
    ffc09810 00000001 
    ffc09814 00000001
    ...
sp0:ffc09850 7467a186 <- #00 stack
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

Maps: <- Memory space of the process when the fault occurs
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
OpenFiles: <- Information about the file handles held by the process when the fault occurs
0->/dev/pts/0 native object of unknown type 0
1->/dev/pts/0 native object of unknown type 0
2->/dev/pts/0 native object of unknown type 0
3->socket:[102975] native object of unknown type 0
9->socket:[13080] native object of unknown type 0
14->/dev/console native object of unknown type 0

HiLog: <- HiLog logs of the process before the fault occurs
08-06 21:52:51.212 10208 10208 E C03f00/MUSL-SIGCHAIN: signal_chain_handler call 2 rd sigchain action for signal: 11 sca_sigaction=f7b3e638 noreturn=0 FREEZE_signo_11 thread_list_lock_status:-1 tl_lock_count=0 tl_lock_waiters=0 tl_lock_tid_fail=-1 tl_lock_count_tid=-1 tl_lock_count_fail=-10000 tl_lock_count_tid_sub=-1 thread_list_lock_after_lock=-1 thread_list_lock_pre_unlock=-1 thread_list_lock_pthread_exit=-1 thread_list_lock_tid_overlimit=-1 tl_lock_unlock_count=0 __pthread_gettid_np_tl_lock=0 __pthread_exit_tl_lock=0 __pthread_create_tl_lock=0 __pthread_key_delete_tl_lock=0 __synccall_tl_lock=0 __membarrier_tl_lock=0 install_new_tls_tl_lock=0 set_syscall_hooks_tl_lock=0 set_syscall_hooks_linux_tl_lock=0 fork_tl_lock=0
08-06 21:52:51.212 10208 10208 I C02d11/DfxSignalHandler: DFX_SigchainHandler :: signo(11), si_code(-6), pid(10208), tid(10208).
08-06 21:52:51.212 10208 10208 I C02d11/DfxSignalHandler: DFX_SigchainHandler :: signo(11), pid(10208), processName(./crasher_cpp),         threadName(crasher_cpp).
```

**HiTraceId**

Trace ID provided by HiTraceChain. For details, see [HiTraceId](../reference/apis-performance-analysis-kit/capi-trace-h.md).

**Call stack frame**

The following describes the content of a three-layer call stack in detail:

```text
#00 pc 000e8400 /system/lib/ld-musl-arm.so.1(raise+176)(a40044d0acb68107cfc4adb5049c0725)
#01 pc 00006e95 /data/crasher_cpp(DfxCrasher::RaiseSegmentFaultException()+92)(d6cead5be17c9bb7eee2a9b4df4b7626)
#02 pc 00008909 /data/crasher_cpp(DfxCrasher::ParseAndDoCrash(char const*) const+612)(d6cead5be17c9bb7eee2a9b4df4b7626)
```

| Frame| Number of Offset Bytes of PC in the File| File Name of the Memory Segment to Which PC Belongs| Function| Number of Offset Bytes in the Function| BuildID |
| -------- | -------- | -------- | -------- | -------- | -------- |
| \#00 | 000e8400 | /system/lib/ld-musl-arm.so.1 | raise | 176 | a40044d0acb68107cfc4adb5049c0725 |
| \#01 | 00006e95 | /data/crasher_cpp | DfxCrasher::RaiseSegmentFaultException() | 92 | d6cead5be17c9bb7eee2a9b4df4b7626 |
| \#02 | 00008909 | /data/crasher_cpp | DfxCrasher::ParseAndDoCrash(char const\*) const | 612 | d6cead5be17c9bb7eee2a9b4df4b7626 |

> **NOTE**
>
> - The file name may also be an anonymous memory mapping, for example, **[heap]** or **[stack]**.
>
> - The possible causes for the failure to print function names in logs are as follows:
>   - The function name is not saved in the binary file.
>
>   - The length of the function name saved in the binary file exceeds 256 bytes.
>
> - If **BuildID** is not printed, you can run the **readelf -n xxx.so** command to check whether the binary file has **BuildID**. If not, add the compilation parameter **--enable-linker-build-id** to the compilation options. Do not add **--build-id=none**.

**JS hybrid stack frame**

The 64-bit ARM system can capture cross-language call stacks between C++ and JS. Therefore, if the function call chain contains JS code, the crash log also records the JS call stack in the following format:

```text
#00 at onPageShow (entry|har1|1.0.0|src/main/ets/pages/Index.ts:7:13)
```

For details, see [Exception Code Call Stack Formats](jscrash-guidelines.md#exception-code-call-stack-formats).

### Null Pointer Dereference

Null pointer dereference often  occurs in the following scenarios:

1. When a crash is in format of **SIGSEGV(SEGV_MAPERR)\@0x00000000** or the values of the registers such as **r0** and **r1** in the **Register** field are **0**, a null pointer may be passed in when the function is called.

2. When a crash is in format of **SIGSEGV(SEGV_MAPERR)\@0x0000000c** (smaller than the size of a memory page) or the value of the registers such as **r1** in the **Register** field is small, a null pointer may be passed in when the struct member of the input parameter is called.

In this scenario, a message is printed in the log, indicating that the fault may be caused by a null pointer dereference. The following is an example process crash log archived by DevEco Studio in FaultLog:

```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:HarmonyOS 3.2        <- Device information
Build info:HarmonyOS 5.0.0.23    <- Build information
Fingerprint:cdf52fd0cc328fc432459928f3ed8edfe8a72a92ee7316445143bed179138073 <- Fingerprint
Module name:crasher_cpp            <- Module name
Timestamp:2024-05-06 20:10:51.000  <- Timestamp when the fault occurs
Pid:9623   <- Process ID
Uid:0         <- User ID
HiTraceId:a92ab1c7eae68fa  <- HiTrace ID (Optional. If the process does not have HiTraceId, it is not printed.)
Process name:./crasher_cpp         <- Process name
Process life time:1s               <- Process life time
Process Memory(kB): 11902(Rss)     <- Memory used by the process
Device Memory(kB): Total 1935820, Free 516244, Available 1205608 <- Device memory status (optional)
Reason:Signal:SIGSEGV(SEGV_MAPERR)@0x00000004 probably caused by NULL pointer dereference  <- Fault cause and null pointer prompt
Fault thread info:
Tid:9623, Name:crasher_cpp         <- Thread ID, thread name
#00 pc 00008d22 /system/bin/crasher_cpp(TestNullPointerDereferenceCrash0()+22)(adfc673300571d2da1e47d1d12f48b44)  <- Call stack
#01 pc 000064d1 /system/bin/crasher_cpp(DfxCrasher::ParseAndDoCrash(char const*) const+160)(adfc673300571d2da1e47d1d12f48b44)
#02 pc 00006569 /system/bin/crasher_cpp(main+92)(adfc673300571d2da1e47d1d12f48b44)
#03 pc 00072b98 /system/lib/ld-musl-arm.so.1(libc_start_main_stage2+56)(d820b1827e57855d4f9ed03ba5dfea83)
#04 pc 00004e28 /system/bin/crasher_cpp(_start_c+84)(adfc673300571d2da1e47d1d12f48b44)
#05 pc 00004dcc /system/bin/crasher_cpp(adfc673300571d2da1e47d1d12f48b44)
Registers:   <- Fault registers
r0:ffffafd2 r1:00000004 r2:00000001 r3:00000000
r4:ffd27e39 r5:0096e000 r6:00000a40 r7:0096fdfc
r8:f7ba58d5 r9:f7baea86 r10:f7cadd38
fp:ffd27308 ip:f7cb2078 sp:ffd272a0 lr:f7c7ab98 pc:0096ad22
cpsr:20870010           <-  Value of status register (cpsr for the ARM32 architecture and pstate and esr for the AArch64 architecture)
...
```

### Stack Overflow

Stack overflow may occur in the following scenarios:

- The stack memory is used up because the recursive termination condition is not set during recursive call.

- The stack memory is used up because local variables occupy too much stack memory.

- The stack memory used in the signal stack exceeds the system limit.

The following example shows that the stack memory is used up because the recursive termination condition is not set during recursive call.

```c++
static void *DoStackOverflow(void * inputArg) __attribute__((optnone))
{
    int b[10] = {1};
    if (b[0] == 0) {
        return static_cast<void*>(b + 9); // 9: last element of array
    }
    DoStackOverflow(inputArg); // Recursive calls are made multiple times. As a result, the stack memory is used up, and memory is read and written outside the stack, causing a crash.
    return static_cast<void*>(b + 9); // 9: last element of array
}
```

In this scenario, a message is recorded in the log, indicating that the fault may be caused by stack overflow. The following is an example process crash log archived by DevEco Studio in FaultLog:

```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:HarmonyOS 3.2            <- Device information
Build info:HarmonyOS 5.0.0.23        <- Build information
Fingerprint:8bc3343f50024204e258b8dce86f41f8fcc50c4d25d56b24e71fe26c0a23e321  <- Fingerprint
Module name:crasher_cpp                <- Module name
Timestamp:2024-05-06 20:18:24.000      <- Timestamp when the fault occurs
Pid:9838                               <- Process ID
Uid:0                                  <- User ID
HiTraceId:a92ab1c7eae68fa  <- HiTrace ID (Optional. If the process does not have HiTraceId, it is not printed.)
Process name:./crasher_cpp             <- Process name
Process life time:2s                   <- Process life time
Process Memory(kB): 11902(Rss)     <- Memory used by the process
Device Memory(kB): Total 1935820, Free 516244, Available 1205608 <- Device memory status (optional)
Reason:Signal:SIGSEGV(SEGV_ACCERR)@0xf76b7ffc current thread stack low address = 0xf76b8000, probably caused by stack-buffer-overflow <- Fault cause and stack overflow prompt
Tid:10343, Name:crasher_cpp
#00 pc 000072e6 /data/crasher_cpp(DoStackOverflow(void*)+30)(d6cead5be17c9bb7eee2a9b4df4b7626)
#01 pc 00007305 /data/crasher_cpp(DoStackOverflow(void*)+60)(d6cead5be17c9bb7eee2a9b4df4b7626)
#02 pc 00007305 /data/crasher_cpp(DoStackOverflow(void*)+60)(d6cead5be17c9bb7eee2a9b4df4b7626)
#03 pc 00007305 /data/crasher_cpp(DoStackOverflow(void*)+60)(d6cead5be17c9bb7eee2a9b4df4b7626)
#04 pc 00007305 /data/crasher_cpp(DoStackOverflow(void*)+60)(d6cead5be17c9bb7eee2a9b4df4b7626)
#05 pc 00007305 /data/crasher_cpp(DoStackOverflow(void*)+60)(d6cead5be17c9bb7eee2a9b4df4b7626)
...
```

### Stack Corruptions

Stack corruptions occur when the stack memory that stores function call information is overwritten during service code running. As a result, the call stack cannot be traced. In this scenario, the system displays a message in the log, indicating that you need to parse the unreliable call stack in the thread stack memory from **\#xx**. The call stack is unreliable because it may not be a complete function call chain. From level **\#xx** downward, adjacent frames do not necessarily reflect a true call relationship. You must deduce the actual sequence from the service source. In the following example, the correct call relationship is **\#05** -> **\#04** -> **\#03** -> **\#01**. The following is an example process crash log archived by DevEco Studio in FaultLog:

```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:HarmonyOS 3.2               <- Device information
Build info:HarmonyOS 5.0.0.23           <- Build information
Fingerprint:79b6d47b87495edf27135a83dda8b1b4f9b13d37bda2560d43f2cf65358cd528    <- Fingerprint
Module name:crasher_cpp                   <- Module name
Timestamp:2024-05-06 20:27:23.2035266415  <- Timestamp when the fault occurs
Pid:10026                                 <- Process ID
Uid:0                                     <- User ID
HiTraceId:a92ab1c7eae68fa  <- HiTrace ID (Optional. If the process does not have HiTraceId, it is not printed.)
Process name:./crasher_cpp                <- Process name
Process life time:1s                      <- Process life time
Process Memory(kB): 11902(Rss)            <- Memory used by the process
Device Memory(kB): Total 1935820, Free 516244, Available 1205608 <- Device memory status (optional)
Reason:Signal:SIGSEGV(SEGV_MAPERR)@0000000000 probably caused by NULL pointer dereference  <- Fault cause
LastFatalMessage:Failed to unwind stack, try to get unreliable call stack from #02 by reparsing thread stack <- #00 and #01 are generally considered reliable. You need to parse unreliable call stacks in the thread stack memory from #02.
Fault thread info:
Tid:10026, Name:crasher_cpp               <- Thread ID, thread name
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

### Asynchronous Thread Stack Tracing Faults

When an asynchronous thread crashes, the stack of the thread that submits the asynchronous task is also printed to locate the fault. The call stack of the crash thread and that of the submission thread are separated by **SubmitterStacktrace**. The following is an example process crash log archived by DevEco Studio in FaultLog:

> **NOTE**
>
> The asynchronous thread stack tracing functionality is enabled only for debug-type applications in the ARM 64-bit system.

```text
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:HarmonyOS 3.2                 <- Device information
Build info:HarmonyOS 5.0.0.23             <- Build information
Fingerprint:8bc3343f50024204e258b8dce86f41f8fcc50c4d25d56b24e71fe26c0a23e321  <- Fingerprint
Module name:crasher_cpp                     <- Module name
Timestamp:2024-05-06 20:28:24.000           <- Timestamp when the fault occurs
Pid:9838                                    <- Process ID
Uid:0                                       <- User ID
HiTraceId:a92ab1c7eae68fa  <- HiTrace ID (Optional. If the process does not have HiTraceId, it is not printed.)
Process name:./crasher_cpp                  <- Process name
Process life time:2s                        <- Process life time
Process Memory(kB): 11902(Rss)            <- Memory used by the process
Device Memory(kB): Total 1935820, Free 516244, Available 1205608 <- Device memory status (optional)
Reason:Signal:SIGSEGV(SI_TKILL)@0x000000000004750 from:18256:0   <- Fault Cause
Fault thread info:
Tid:18257, Name:crasher_cpp                 <- Thread ID, thread name
#00 pc 000054e6 /system/bin/ld-musl-aarch64.so.l(raise+228)(adfc673300571d2da1e47d1d12f48b44) <- Call stack
#01 pc 000054f9 /system/bin/crasher_cpp(CrashInSubThread(void*)+56)(adfc673300571d2da1e47d1d12f48b50)
#02 pc 000054f9 /system/bin/ld-musl-aarch64.so.l(start+236)(adfc673300571d2da1e47d1d12f48b44)
========SubmitterStacktrace========       <- The call stack used to print submitting thread
#00 pc 000094dc /system/bin/crasher_cpp(DfxCrasher::AsyncStacktrace()+36)(adfc673300571d2da1e47d1d12f48b50)
#01 pc 00009a58 /system/bin/crasher_cpp(DfxCrasher::ParseAndDoCrash(char const*) const+232)(adfc673300571d2da1e47d1d12f48b50)
#02 pc 00009b40 /system/bin/crasher_cpp(main+140)(adfc673300571d2da1e47d1d12f48b50)
#03 pc 0000a4e1c /system/bin/ld-musl-aarch64.so.l(libc_start_main_stage2+68)(adfc673300571d2da1e47d1d12f48b44)
...
```

### Application Crash Log Configured by HiAppEvent

The system provides a common crash log generation functionality. To meet personalized requirements of some applications on the crash log content, HiAppEvent provides the [setEventConfig](hiappevent-watcher-crash-events.md#customizing-crash-log-specifications) API to set crash log configuration parameters. The following is the core content of a 32-bit system crash log archived by DevEco Studio in FaultLog:

```text
...
Build info:OpenHarmony 6.0.0.33
Enabled app log configs:    <- List of enabled configuration parameters. Only the configuration parameters that are not set to the default values are printed.
Extend pc lr printing:true  <- Set extend_pc_lr_printing to true.
Log cut off size:102400B    <- Truncate the crash log size to 100 KB. (This field is valid only for crash logs obtained through the HiAppEvent API.)
Simplify maps printing:true <- Set simplify vma_printing to true.
Timestamp:2025-05-17 19:17:07.000
...
Registers:  <- Fault registers
r0:00000000 r1:ff87d48c r2:00000000 r3:00000008
r4:00000000 r5:fffff000 r6:00000000 r7:000000af
r8:00c0b4f0 r9:00c0bdc0 r10:00c0bdc0
fp:ff87d520 ip:00c0a6e4 sp:ff87d488 lr:f7ecc044 pc:f7f19940
cpsr:00800010
Memory near registers:
...
lr(/system/lib/ld-musl-arm.so.1): <- Memory value near the LR.
    f7ecbfc8 e0824000 <- When extend_pc_lr_printing is set to true, the memory value is printed forward to this point.
    ...
    f7ecc03c e3a00006 <- When extend_pc_lr_printing is set to false, the memory value is printed forward to this point.
    f7ecc040 eb013612
    f7ecc044 e59f10b0 <- Memory value (e59f10b0) of the LR (f7ecc044)
    ...
    f7ecc0b8 e58d4004 <- When extend_pc_lr_printing is set to false, the memory value is printed backward to this point.
    f7ecc0bc e1a0100d
    f7ecc0c0 e3a00020
    f7ecc0c4 e3a070af <- When extend_pc_lr_printing is set to true, the memory value is printed backward to this point.
pc(/system/lib/ld-musl-arm.so.1): <- Memory value near the PC.
    f7f198c4 e5900000 <- When extend_pc_lr_printing is set to true, the memory value is printed forward to this point.
    ...
    f7f19938 e3a03008 <- When extend_pc_lr_printing is set to false, the memory value is printed forward to this point.
    f7f1993c ef000000
    f7f19940 e51b0014 <- Memory value (e51b0014) of the PC (f7f19940).
    ... 
    f7f199b4 e2b52000 <- When extend_pc_lr_printing is set to false, the memory value is printed backward to this point.
    f7f199b8 03530000
    f7f199bc 0a000003
    f7f199c0 ebfec957 <- When extend_pc_lr_printing is set to true, the memory value is printed backward to this point.
...
Maps:       <- When simplify _vma_printing is set to true, the number of maps to be printed is reduced. Only the maps to which the addresses in the crash log belong are retained.
ba0000-ba9000 r--p 00000000 /data/test/test_signalhandler
ba9000-bd8000 r-xp 00008000 /data/test/test_signalhandler
bd8000-bdb000 r--p 00036000 /data/test/test_signalhandler
bdb000-bdc000 rw-p 00038000 /data/test/test_signalhandler
... <- Maps to which the addresses in the crash logs belong, which are not displayed here.
OpenFiles:
...
[truncated] <- Log truncation flag, indicating that the log is truncated.
```

### Faults with Page Switching History

Since API version 21, the maintenance and debugging process records the application switching history for applications that involve page switching. After an application fault occurs, the generated fault file contains the page switching history.

A maximum of 10 latest history records can be recorded in a fault log file.

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

The format of a record is as follows:
```text
  14:08:30:327 /ets/pages/Index:JsError
       ^             ^            ^
    Switching time   Page URL   Page name
```

> **NOTE**
>
> The child page's name is available only when it is navigated to through **Navigation**. The page name is defined in the [system routing table](../ui/arkts-navigation-navigation.md#system-routing-table).
>
> When the application switches between the foreground and background, the corresponding page URL is empty, but **enters foreground** and **leaves foreground** are displayed as special page names.
>
> **enters foreground**: The application runs in the foreground.
>
> **leaves foreground**: The application runs in the background.
