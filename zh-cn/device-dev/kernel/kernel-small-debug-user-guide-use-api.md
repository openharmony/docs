# 接口调用方式

- [示例代码](#示例代码)
- [编译](#编译)
- [调测信息](#调测信息)
- [调用栈解析](#调用栈解析)

## 示例代码

代码功能：显式调用调测模块的相关接口对用户代码进行内存校验。

```
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <debug.h> // 包含提供内存调测接口声明的头文件

#define MALLOC_LEAK_SIZE  0x300

void func(void) {
    char *ptr = malloc(MALLOC_LEAK_SIZE);
    memset(ptr, '3', MALLOC_LEAK_SIZE);
}

int main()
{
    mem_check_init(NULL); // 通过串口输出内存调测信息，必须在用户程序第一次申请堆内存之前调用（一般在main函数入口调用），否则调测信息不准确。
    // mem_check_init("/storage/mem_debug.txt"); // 内存调测信息输出到/storage/mem_debug.txt文件中，如果该文件创建失败，则信息通过串口输出。
    char *ptr = malloc(MALLOC_LEAK_SIZE);
    memset(ptr, '1', MALLOC_LEAK_SIZE);

    watch_mem(); // 在当前代码逻辑处查看线程级内存统计信息。
    func();
    check_heap_integrity(); // 检查堆内存节点完整性。
    check_leak(); // 在当前代码逻辑处检查堆内存是否泄漏（一般在程序退出之前校验比较准确，若在malloc和free调用逻辑之间做校验，则结果不准确）。
    return 0;
}
```


## 编译

```
$ clang -o mem_check mem_check.c -funwind-tables -rdynamic -g -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4 -target arm-liteos --sysroot=/home/<user-name>/directory/out/hispark_taurus/ipcamera_hispark_taurus/sysroot $(clang -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4 -target arm-liteos -print-file-name=libunwind.a)
```


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 本编译示例基于将编译器的路径写入环境变量中，即.bashrc文件中。
> 
> - 编译用户程序及所需的lib库时，需要添加编译选项-funwind-tables，-rdynamic，-g，用于栈回溯。
> 
> - -mfloat-abi=softfp，-mcpu=cortex-a7，-mfpu=neon-vfpv4编译选项用于指定具体的芯片架构、浮点数计算优化、fpu，与具体的libc库使用的编译选项保持一致，否则链接时可能出现找不到libc库文件。
> 
> - -target arm-liteos用于指定编译器相关库文件路径。
> 
> - --sysroot=/home/&lt;user-name&gt;/directory/out/hispark_taurus/ipcamera_hispark_taurus/sysroot用于指定编译器库文件搜索根目录，假设OpenHarmony工程代码存放路径为/home/&lt;user-name&gt;/directory。其中out/hispark_taurus/ipcamera_hispark_taurus路径为在编译时，hb set命令指定的具体产品，本示例选择的是ipcamera_hispark_taurus产品。
> 
> - $(clang -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4 -target arm-liteos -print-file-name=libunwind.a)用于指定相应的unwind库的路径。


## 调测信息

```
OHOS # ./mem_check
OHOS # 
==PID:4== Heap memory statistics(bytes): // 堆内存统计信息
    [Check point]: // check点调用栈
        #00: <main+0x38>[0x86c] -> mem_check
        #01: <(null)+0x24baf9dc>[0x219dc] -> /lib/libc.so

    [TID: 18, Used: 0x320] // 18号线程堆内存占用，当前进程仅一个线程

==PID:4== Total heap: 0x320 byte(s), Peak: 0x320 byte(s)

Check heap integrity ok! // 堆内存完整性检查

==PID:4== Detected memory leak(s): // 内存泄漏信息及调用栈
    [Check point]:
        #00: <check_leak+0x1c4>[0x2da4c] -> /lib/libc.so
        #01: <main+0x44>[0x878] -> mem_check

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <main+0x1c>[0x850] -> mem_check
        #01: <(null)+0x24baf9dc>[0x219dc] -> /lib/libc.so

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <func+0x14>[0x810] -> mem_check
        #01: <main+0x3c>[0x870] -> mem_check
        #02: <(null)+0x24baf9dc>[0x219dc] -> /lib/libc.so

==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).

==PID:4== Detected memory leak(s):
    [Check point]:
        #00: <check_leak+0x1c4>[0x2da4c] -> /lib/libc.so
        #01: <exit+0x28>[0x111ec] -> /lib/libc.so

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <main+0x1c>[0x850] -> mem_check
        #01: <(null)+0x24baf9dc>[0x219dc] -> /lib/libc.so

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <func+0x14>[0x810] -> mem_check
        #01: <main+0x3c>[0x870] -> mem_check
        #02: <(null)+0x24baf9dc>[0x219dc] -> /lib/libc.so

==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).

Check heap integrity ok!
```


## 调用栈解析

提供parse_mem_info.sh脚本可以对调用栈进行解析，解析脚本存放的路径：kernel/liteos_a/tools/scripts/parse_memory/parse_mem_info.sh。利用脚本可以将相应的调测信息转换成具体的源码行号，如下命令所示，mem_debug.txt保存的是内存调测信息，elf1、elf2等文件是需要解析的elf文件。

```
$ ./parse_mem_info.sh mem_debug.txt elf1 elf2 elf3 ...
```

例如：

```
$ ./parse_mem_info.sh mem_debug.txt mem_check
Compiler is [gcc/llvm]: llvm
Now using addr2line ...

==PID:4== Heap memory statistics(bytes):
    [Check point]:
        #00: <main+0x38>[0x86c] at /usr1/xxx/TEST_ELF/mem_check.c:22
        #01: <(null)+0x24baf9dc>[0x219dc] -> /lib/libc.so

    [TID: 18, Used: 0x320]

==PID:4== Total heap: 0x320 byte(s), Peak: 0x320 byte(s)

Check heap integrity ok!

==PID:4== Detected memory leak(s):
    [Check point]:
        #00: <check_leak+0x1c4>[0x2da4c] -> /lib/libc.so
        #01: <main+0x44>[0x878] at /usr1/xxx/TEST_ELF/mem_check.c:28

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <main+0x1c>[0x850] at /usr1/xxx/TEST_ELF/mem_check.c:17
        #01: <(null)+0x24baf9dc>[0x219dc] -> /lib/libc.so

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <func+0x14>[0x810] at /usr1/xxx/TEST_ELF/mem_check.c:9
        #01: <main+0x3c>[0x870] at /usr1/xxx/TEST_ELF/mem_check.c:24
        #02: <(null)+0x24baf9dc>[0x219dc] -> /lib/libc.so

==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).
```
