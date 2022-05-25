# Using the CLI

In addition to calling APIs to check the memory used by user-mode processes, you can run CLI commands to collect memory statistics, check for memory leaks, and check memory integrity.

```
--mwatch: initializes memory debugging, registers signals, and outputs memory debugging information through the serial port.
--mrecord <f_path>: initializes memory debugging, registers signals, and saves the memory debugging information to the f_path file. If the f_path file fails to be created, output the memory debugging information through the serial port.
```

If the process to debug does not exit, you can use the signal mechanism to obtain the corresponding information:

```
kill -35 <pid> # Check the thread-level heap memory usage.
kill -36 <pid> # Check for heap memory leaks.
kill -37 <pid> # Check whether the head node of the heap memory is complete.
```

## Sample Code<a name="section13793104782316"></a>

The sample code constructs a memory problem and uses the command line to perform memory debugging.

```
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_LEAK_SIZE  0x300

void func(void) {
    char *ptr = malloc(MALLOC_LEAK_SIZE);
    memset(ptr, '3', MALLOC_LEAK_SIZE);
}

int main()
{
    char *ptr = malloc(MALLOC_LEAK_SIZE);
    memset(ptr, '1', MALLOC_LEAK_SIZE);
    func();
    while (1);
}
```

## Compilation

For details, see  [Calling APIs](kernel-small-debug-user-guide-use-api.md#compilation).

## Running the mwatch Command

```
OHOS # ./mem_check --mwatch // Run the task command to obtain the mem_check process PID, which is 4.
OHOS # 
OHOS # kill -35 4 // Check heap memory statistics.
OHOS # 
==PID:4== Heap memory statistics(bytes):
    [Check point]:
        #00: <arm_signal_process+0x5c>[0x58dfc] -> /lib/libc.so

    [TID: 18, Used: 0x640]

==PID:4== Total heap: 0x640 byte(s), Peak: 0x640 byte(s)

OHOS # kill -36 4 // Check for heap memory leaks.
OHOS # 
==PID:4== Detected memory leak(s):
    [Check point]:
        #00: <check_leak+0x1c4>[0x2da4c] -> /lib/libc.so
        #01: <arm_signal_process+0x5c>[0x58dfc] -> /lib/libc.so

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <main+0x14>[0x724] -> mem_check
        #01: <(null)+0x2555a9dc>[0x219dc] -> /lib/libc.so

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <func+0x14>[0x6ec] -> mem_check
        #01: <main+0x30>[0x740] -> mem_check
        #02: <(null)+0x2555a9dc>[0x219dc] -> /lib/libc.so

==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).

OHOS # kill -37 4 // Check the integrity of the head node of the heap memory.
OHOS # 
Check heap integrity ok!
```

## Call Stack Parsing<a name="section1880675510221"></a>

Save the debugging information to the  **test.txt**  file and use the script to parse the information to obtain the number of line where the memory leak occurs.

```
$ ./parse_mem_info.sh test.txt mem_check
Compiler is [gcc/llvm]: llvm
Now using addr2line ...

==PID:4== Detected memory leak(s):
    [Check point]:
        #00: <check_leak+0x1c4>[0x2da4c] -> /lib/libc.so
        #01: <arm_signal_process+0x5c>[0x58dfc] -> /lib/libc.so

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <main+0x14>[0x724] at /usr1/xxx/TEST_ELF/mem_check.c:14
        #01: <(null)+0x2555a9dc>[0x219dc] -> /lib/libc.so

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <func+0x14>[0x6ec] at /usr1/xxx/TEST_ELF/mem_check.c:8
        #01: <main+0x30>[0x740] at /usr1/xxx/TEST_ELF/mem_check.c:19
        #02: <(null)+0x2555a9dc>[0x219dc] -> /lib/libc.so

==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).
```

## Running the mrecord Command

1.  Run the user program and specify the path of the file that stores the memory debugging information.

    ```
    OHOS # ./mem_check --mrecord /storage/check.txt
    ```

2.  Run the  **kill -35 <_pid_\>**  command to collect statistics on the memory information. The information is exported to a file. Run the  **cat**  command to view the information.

    ```
    OHOS # kill -35 4
    OHOS # Memory statistics information saved in /storage/pid(4)_check.txt
    
    OHOS # cat /storage/pid(4)_check.txt
    
    ==PID:4== Heap memory statistics(bytes):
        [Check point]:
            #00: <arm_signal_process+0x5c>[0x5973c] -> /lib/libc.so
    
        [TID: 18, Used: 0x640]
    
    ==PID:4== Total heap: 0x640 byte(s), Peak: 0x640 byte(s)
    ```

3.  Run the  **kill -36 <_pid_\>**  command to check memory integrity. The information is exported to a file. Run the  **cat**  command to view the information.

    ```
    OHOS # kill -36 4
    OHOS # Leak check information saved in /storage/pid(4)_check.txt
    
    OHOS # cat /storage/pid(4)_check.txt
    
    ==PID:4== Heap memory statistics(bytes):
        [Check point]:
            #00: <arm_signal_process+0x5c>[0x5973c] -> /lib/libc.so
    
        [TID: 18, Used: 0x640]
    
    ==PID:4== Total heap: 0x640 byte(s), Peak: 0x640 byte(s)
    
    ==PID:4== Detected memory leak(s):
        [Check point]:
            #00: <check_leak+0x1c4>[0x2e38c] -> /lib/libc.so
            #01: <arm_signal_process+0x5c>[0x5973c] -> /lib/libc.so
    
        [TID:18 Leak:0x320 byte(s)] Allocated from:
            #00: <main+0x14>[0x724] -> mem_check
            #01: <(null)+0x1fdd231c>[0x2231c] -> /lib/libc.so
    
        [TID:18 Leak:0x320 byte(s)] Allocated from:
            #00: <func+0x14>[0x6ec] -> mem_check
            #01: <main+0x30>[0x740] -> mem_check
            #02: <(null)+0x1fdd231c>[0x2231c] -> /lib/libc.so
    
    ==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).
    ```

4.  Run the  **kill -9 <_pid_\>**  command to kill the current process. After the process exits, a memory integrity check is performed by default. The check result is output to a file. You can run the  **cat**  command to view it.

    ```
    OHOS # kill -9 4
    OHOS # Leak check information saved in /storage/pid(4)_check.txt
    
    Check heap integrity ok!
    
    OHOS # cat /storage/pid(4)_check.txt
    OHOS # 
    ==PID:4== Heap memory statistics(bytes):
        [Check point]:
            #00: <arm_signal_process+0x5c>[0x5973c] -> /lib/libc.so
    
        [TID: 18, Used: 0x640]
    
    ==PID:4== Total heap: 0x640 byte(s), Peak: 0x640 byte(s)
    
    ==PID:4== Detected memory leak(s):
        [Check point]:
            #00: <check_leak+0x1c4>[0x2e38c] -> /lib/libc.so
            #01: <arm_signal_process+0x5c>[0x5973c] -> /lib/libc.so
    
        [TID:18 Leak:0x320 byte(s)] Allocated from:
            #00: <main+0x14>[0x724] -> mem_check
            #01: <(null)+0x1fdd231c>[0x2231c] -> /lib/libc.so
    
        [TID:18 Leak:0x320 byte(s)] Allocated from:
            #00: <func+0x14>[0x6ec] -> mem_check
            #01: <main+0x30>[0x740] -> mem_check
            #02: <(null)+0x1fdd231c>[0x2231c] -> /lib/libc.so
    
    ==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).
    
    ==PID:4== Detected memory leak(s):
        [Check point]:
            #00: <check_leak+0x1c4>[0x2e38c] -> /lib/libc.so
            #01: <exit+0x28>[0x11b2c] -> /lib/libc.so
    
        [TID:18 Leak:0x320 byte(s)] Allocated from:
            #00: <main+0x14>[0x724] -> mem_check
            #01: <(null)+0x1fdd231c>[0x2231c] -> /lib/libc.so
    
        [TID:18 Leak:0x320 byte(s)] Allocated from:
            #00: <func+0x14>[0x6ec] -> mem_check
            #01: <main+0x30>[0x740] -> mem_check
            #02: <(null)+0x1fdd231c>[0x2231c] -> /lib/libc.so
    
    ==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).
    ```


>![](../public_sys-resources/icon-note.gif) **NOTE**<br/> 
>The preceding information recorded gradually is added to the file specified during initialization. Therefore, running the  **cat**  command can also display the historical information in the file.

