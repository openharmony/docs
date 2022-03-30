# Calling APIs<a name="EN-US_TOPIC_0000001166036359"></a>

-   [Sample Code](#section5490173592518)
-   [Compilation](#section534302242515)
-   [Debugging Information](#section1017419992515)
-   [Call Stack Parsing](#section1485163282417)

## Sample Code<a name="section5490173592518"></a>

The sample code explicitly calls the related APIs of the memory debugging module to check the memory.

```
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <debug.h> // Header file that includes the declaration of the memory debugging APIs

#define MALLOC_LEAK_SIZE  0x300

void func(void) {
    char *ptr = malloc(MALLOC_LEAK_SIZE);
    memset(ptr, '3', MALLOC_LEAK_SIZE);
}

int main()
{
    mem_check_init(NULL); // Output the memory debugging information through the serial port. This function must be called before the user program requests the heap memory for the first time (generally called at the entry of the main function). Otherwise, the debugging information is inaccurate.
    // mem_check_init("/storage/mem_debug.txt"); // Output the memory debugging information to the /storage/mem_debug.txt file. If the file fails to be created, output the information through the serial port.
    char *ptr = malloc(MALLOC_LEAK_SIZE);
    memset(ptr, '1', MALLOC_LEAK_SIZE);

    watch_mem(); // Obtain the thread-level memory statistics in the current code.
    func();
    check_heap_integrity(); // Check the integrity of the heap memory nodes.
    check_leak(); // Check whether a heap memory leak occurs in the current code. (Generally, the check result is accurate before the application exits. If the check is performed after the calling of malloc and before the calling of free, the result is inaccurate.)
    return 0;
}
```

## Compilation<a name="section534302242515"></a>

```
$ clang -o mem_check mem_check.c -funwind-tables -rdynamic -g -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4 -target arm-liteos --sysroot=/home/<user-name>/directory/out/hispark_taurus/ipcamera_hispark_taurus/sysroot $(clang -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4 -target arm-liteos -print-file-name=libunwind.a)
```

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   In this example, the compiler path is written into an environment variable in the  **.bashrc**  file.
>-   When compiling user programs and required libraries, add the option  **-funwind-tables -rdynamic -g**  for stack backtracking.
>-   The  **-mfloat-abi=softfp**,  **-mcpu=cortex-a7**, and  **-mfpu=neon-vfpv4**  options specify the floating-point calculation optimization, chip architecture, and FPU, which must be the same as the compilation options used by the libc library. Otherwise, the libc library file cannot be found during the link time.
>-   **-target arm-liteos**  specifies the path of the library files related to the compiler.
>-   **--sysroot=/home/<user-name\>/directory/out/hispark\_taurus/ipcamera\_hispark\_taurus/sysroot**  specifies the root directory of the compiler library files. In this example, the OpenHarmony project code is stored in  **/home/<user-name\>/directory**. The  **out/hispark\_taurus/ipcamera\_hispark\_taurus**  directory indicates the product specified by the  **hb set**  command during compilation. In this example,  **ipcamera\_hispark\_taurus**  is the product specified.
>-   **$\(clang -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4 -target arm-liteos -print-file-name=libunwind.a\)**  specifies the path of the unwind library.

## Debugging Information<a name="section1017419992515"></a>

```
OHOS # ./mem_check
OHOS # 
==PID:4== Heap memory statistics(bytes): // Heap memory statistics
    [Check point]: // Call stack of the check point
        #00: <main+0x38>[0x86c] -> mem_check
        #01: <(null)+0x24baf9dc>[0x219dc] -> /lib/libc.so

    [TID: 18, Used: 0x320] // The heap memory is occupied by thread No. 18. The current process has only one thread.

==PID:4== Total heap: 0x320 byte(s), Peak: 0x320 byte(s)

Check heap integrity ok! // Heap memory integrity check

==PID:4== Detected memory leak(s): // Memory leak information and call stack
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

## Call Stack Parsing<a name="section1485163282417"></a>

The  **parse\_mem\_info.sh**  script in  **kernel/liteos\_a/tools/scripts/parse\_memory/**  can be used to parse the call stack. You can use the script to convert the debug information into specific source code line number. In the following command,  **mem\_debug.txt**  stores the memory debugging information, and  **elf1**  and  **elf2**  are the executable and linkable format \(ELF\) files to parse.

```
$ ./parse_mem_info.sh mem_debug.txt elf1 elf2 elf3 ...
```

Example:

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

