# Performance Analysis Kit Terminology

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @mzyan-->
<!--Designer: @liyueric-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## General

### Log Version

Log version refers to the system version where the logging feature is enabled. It records various system running information, including the running status of applications, system error information, and debugging information. You can use hdc or a third-party application to view and analyze the information for debugging and optimization.

On the device, you can go to **Settings** > **About phone** > **Software version** to check the version. The log version ends with **log**. For example, **BRA-AL00 5.0.0.36(C00E15R4P92log)** is a log version.

### Nolog Version

Nolog version refers to the system version where the logging feature is disabled. It does not record system running information, so it is more lightweight and runs faster. However, it is difficult for debugging and optimization due to the lack of logging.

On the device, you can go to **Settings** > **About phone** > **Software version** to check the version. The nolog version does not end with **log**. For example, **BRA-AL00 5.0.0.36 (C00E15R4P92)** is a nolog version.

### Applications of the Debug Version

An application of the debug version is built in [debug mode](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916).

### Applications of the Release Version

An application of the release version is built in [release mode](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916).

## Stability

### AppFreeze

AppFreeze (application freeze) means that an application does not respond to user operations (for example, clicking) for a specified period of time.

### Asan

Address Sanitizer (ASan) is a memory address sanitizer that detects invalid address access.

### CPP Crash

Cpp crash refers to the abnormal exit that occurs when the C++ code of the process does not process the POSIX signals, which are as follows.

| Signo| Signal| Description| Trigger Cause|
| -------- | -------- | -------- | -------- |
| 4 | SIGILL | Invalid instruction.| An invalid, incorrectly formatted, unknown, or privileged instruction is executed.|
| 5 | SIGTRAP | Breakpoint or trap.| An exception occurs or a trap instruction is executed.|
| 6 | SIGABRT | Process abort.| The process is aborted abnormally. Generally, this exception occurs when the process calls **abort()** in the standard function library.|
| 7 | SIGBUS | Illegal memory access.| The process accesses an aligned or nonexistent physical address.|
| 8 | SIGFPE | Floating-point exception.| An incorrect arithmetic operation is executed, for example, a 0 divisor, floating point overflow, or integer overflow.|
| 11 | SIGSEGV | Invalid memory access.| The process accesses an invalid memory reference.|
| 16 | SIGSTKFLT | Stack error.| The processor performs an incorrect stack operation, such as a pop when the stack is empty or a push when the stack is full.|
| 31 | SIGSYS | Incorrect system call.| An incorrect or invalid parameter is used in a system call.|

### GWP-ASan

GWP-ASan is a native memory allocator that supports detection for use-after-free and heap buffer overflow issues.

### HWASan

Hardware-Assisted Address Sanitizer (HWASan) is a memory error detection system provided by Clang LLVM. It is used to detect common memory access errors in C/C++. Moreover, it has much better performance and memory overhead than Asan.

### JS Crash

A JS crash occurs when an application exits due to an uncaught exception or error in its JS/ArkTS code.

### TSan

ThreadSanitizer (TSan) is a tool for detecting data races.

### UBSan

Undefined Behavior Sanitizer (UBSan) detects undefined behavior in code, enabling developers to locate and fix the underlying defects at runtime.

## Performance

### Frame Loss

Frame loss refers to the issue that the frame rate is lower than expected due to insufficient system performance, hardware limitations, or software problems during video playback, game rendering, or image collection, resulting in frame freezing or data loss. From a technical perspective, frame loss indicates that the device cannot draw frames at the refresh rate because the drawing duration of a single frame exceeds 1000 ms/refresh rate. When the single-frame drawing duration exceeds the refresh cycle of the display device (for example, 16.7 ms per frame), frame loss occurs.

## Power Consumption

### HWC

Hardware Composer (HWC) is a dedicated hardware-assisted system used for overlaying multiple graphics layers for display.

### Foreground Tasks

A foreground task is an application or service that is being used, visible on the UI, and preferentially occupies system resources.

### Background Tasks

A background task is an operation or service that an application performs in the background while its UI is not operated, such as downloading, synchronizing, or playing music.

### Frame Rate

Frame rate refers to the number of image frames displayed or processed per second.

### LTPO

Low Temperature Polycrystalline Oxide (LTPO) is a driving technology for OLED backplanes. The LTPO display supports an adaptive refresh rate of 1 Hz–120 Hz, delivering smoother visuals for applications that demand high refresh rates. In scenarios such as video playback or displaying static images, an LTPO panel can lower its refresh rate to reduce display power consumption and extend battery life. Generally, **LTPO** is used to refer to an adaptive refresh rate technology.

### Redundant Drawing

Redundant drawing indicates that a layer is blocked or repeatedly rendered on the UI. As a result, the system performs invalid drawing on the same pixel for multiple times, wasting GPU resources and causing frame freeze.

### Invisible Animation

Invisible animation indicates an animation that is not directly visible to users but is used to enhance interaction feedback or state transition, such as a swiping animation during page switching.

## Memory

### VSS

Virtual Set Size (VSS) indicates the size of the virtual memory of a process, including all memory areas mapped to the address space of the process, regardless of whether these areas actually exist in the physical memory.

### PSS

Proportional Set Size (PSS) is a more accurate method of measuring memory usage. It allocates the memory consumed by shared libraries among all processes using them in proportion to their actual share.

### RSS

Resident Set Size (RSS) denotes the size of physical memory that is currently resident for a process.

### Dirty Pages

Dirty pages are cache pages that are modified but not written to disks.

### Clean Pages

Clean pages are those that are not modified or are already in sync with their corresponding data on disk.

### Anonymous Pages

Anonymous pages are memory pages that do not correspond to any specific file and are typically created through stack or heap allocations.

### File-Backed Pages

File-backed pages are data pages mapped from specific files, such as program texts and shared libraries.

### NMD

Native Malloc Detail (NMD) indicates the jemalloc snapshot details of a process.
