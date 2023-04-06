# User-Mode Memory Debugging
## Basic Concepts

The musl libc library of the debug version provides mechanisms, such as memory leak check, heap memory statistics, memory corruption check, and backtrace, to improve the efficiency in locating memory problems in user space.


Instrumentation is performed in the **malloc** and **free** APIs to log key node information. The memory node integrity is checked when memory is requested and released by an application. When the application ends, memory statistics are provided to help identifying memory leaks.

## Working Principles


### Memory Leak Check

The memory debugging module maintains 128 (that is the maximum number of threads supported in the system) linked lists for each process. The index of each linked list is the thread ID.

When memory is requested, key information is saved to the memory node control block, which is inserted to the corresponding linked list based on the thread ID.

When memory is released, the system matches the memory node control block based on the memory address to be released and deletes the control block.

**Figure 1** Heap memory node linked list

![](figures/heap-memory-node-linked-list.png "heap-memory-node-linked-list")

When memory is allocated, the returned address is saved in a link register (LR). During the process running, the system adds information, such as the LR corresponding to the suspected leak, to the memory node control block. The following figure shows the heap memory node information.

**Figure 2** Heap memory node information

![](figures/heap-memory-node-information.png "heap-memory-node-information")

**TID** indicates the thread ID; **PID** indicates the process ID; **ptr** indicates the address of the memory requested; **size** indicates the size of the requested memory; **lr[*n*]** indicates the address of the call stack, and *n* is configurable.

When memory is released, the input parameter pointer in the **free** API is used to match the **ptr** field of the memory node. If the pointer is the same as the **ptr** field of the memory node, the memory node control block will be deleted.

You can export the memory debugging information of each process through the serial port or file, and use the addr2line tool to convert the exported information into the code lines that cause memory leaks. In this way, the memory leakage problem can be solved.

**Figure 3** Process of locating the code line for a memory leak

![](figures/process-of-locating-the-code-lines-for-a-memory-leak.png "process-of-locating-the-code-lines-for-a-memory-leak")


### Heap Memory Statistics

You can collect statistics on the percentage of heap memory requested by each thread to provide data support for optimizing memory usage of user programs. The **malloc** and **free** APIs are involved in user-mode heap memory statistics. As shown in the figure above, each process maintains 128 linked lists, and the index of each linked list is a thread ID. When heap memory is requested, the **ptr** and **size** information is recorded in the memory node control block, which is inserted to a linked list with the thread ID as the header. When the heap memory is released, the corresponding heap memory block is removed from the linked list based on the **ptr**. In addition, the system calculates the total heap memory used by the current thread and updates its heap memory usage and peak heap memory usage.


### Memory Integrity Check

- Requested memory less than or equal to 0x1c000 bytes
  
  When the requested memory is less than or equal to 0x1c000 bytes, **malloc** uses the heap allocation algorithm to allocate memory.
  
  When a user program requests heap memory, information such as the check value is added to the heap memory node. If the check value is abnormal, it is probably that the previous heap memory block is overwritten. Currently, the scenario where the check value is damaged by a wild pointer cannot be identified. When memory is allocated or released, the memory node check value is verified. If the memory node is corrupted and the verification fails, the following information is output: TID, PID, and call stack information saved when the previous heap memory block of the corrupted node is allocated. You can use the addr2line tool to obtain the specific code line and rectify the fault.
  
  **Figure 4** Adding a check value to the node header information
  
  ![](figures/adding-a-check-value-to-the-node-header-information.png "adding-a-check-value-to-the-node-header-information")
  
  When heap memory is released by **free**, the memory block is not released immediately. Instead, the magic number 0xFE is written into the memory block, which is then placed in the free queue to prevent the memory block from being allocated by **malloc** within a certain period of time. When a wild pointer or **use-after-free** operation is performed to read the memory, an exception can be detected. However, this mechanism does not apply to write operations.
  
  **Figure 5** Process of releasing memory
  
  ![](figures/process-of-releasing-memory.png "process-of-releasing-memory")
  
  
  
- Requested memory greater than 0x1c000 bytes

  When the requested memory is greater than 0x1c000 bytes, **malloc** uses **mmap** to allocate memory.

  When **mmap** is used to allocate a large memory block, one more page is allocated at the start and end of the memory region. The current **PAGE_SIZE** of each page is **0x1000**. The permissions of the two pages are set to **PROT_NONE** (no read or write permission) by using the **mprotect** API to prevent out-of-bounds read and write of memory. If out-of-bounds read and write of memory occurs, the user program becomes abnormal because the user does not have the read or write permission. The code logic can be identified based on the abnormal call stack information.

  **Figure 6** Layout of the memory allocated by using the **mmap** mechanism of **malloc**

  ![](figures/layout-of-the-memory-allocated-by-using-the-mmap-mechanism-of-malloc.png "layout-of-the-memory-allocated-by-using-the-mmap-mechanism-of-malloc")

### Usage Guide
#### Available APIs


  **Table 1** Memory debugging APIs

| API| Description|
| -------- | -------- |
| mem_check_init | Initializes the memory check module.|
| watch_mem | Obtains the thread-level heap memory usage.|
| check_leak | Checks for heap memory leaks.|
| check_heap_integrity | Checks the heap memory integrity.|
| backtrace | Obtains the address information of the call stack.|
| backtrace_symbols | Obtains symbol information based on address information.|
| print_trace | Prints call stack information.|


  **Table 2** Call stack backtracking APIs

| API| Description|
| -------- | -------- |
| backtrace | Obtains the address information of the call stack.|
| backtrace_symbols | Obtains symbol information based on address information.|
| print_trace | Prints call stack information.|

### How to Use


By default, the OpenHarmony debug version is compiled when a project is built. The libc library of the debug version has integrated the APIs for memory debugging. You can enable memory debugging as required.


You can perform heap memory debugging by using either of the following:


- API: By calling APIs, you can accurately check the heap memory information of a specific code logic segment. However, you have to modify user code.

- CLI: By using the CLI, you do not need to modify user code. However, you cannot accurately check the heap memory information of a specific logic segment.


> **NOTE**<br>
> After memory debugging is enabled, a heap memory leak check and a heap memory integrity check will be performed by default when a process exits. If memory debugging is disabled, the heap memory statistics, heap memory leak check, and heap memory integrity check cannot be enabled, and there is no response to the calling of any debug API.




#### Calling APIs


##### Sample Code

The sample code explicitly calls the related APIs of the memory debugging module to check the memory.


```c
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <debug.h> // Header file that includes the declaration of the memory debugging APIs

#define MALLOC_LEAK_SIZE  0x300

void func(void)
{
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


##### Compilation


```
$ clang -o mem_check mem_check.c -funwind-tables -rdynamic -g -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4 -target arm-liteos --sysroot=/home/<user-name>/directory/out/hispark_taurus/ipcamera_hispark_taurus/sysroot $(clang -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4 -target arm-liteos -print-file-name=libunwind.a)
```


> **NOTE**
>
> - In this example, the compiler path is written into an environment variable in the **.bashrc** file.
>
> - When compiling user programs and required libraries, add the option **-funwind-tables -rdynamic -g** for stack backtracking.
>
> - The **-mfloat-abi=softfp**, **-mcpu=cortex-a7**, and **-mfpu=neon-vfpv4** options specify the floating-point calculation optimization, chip architecture, and FPU, which must be the same as the compilation options used by the libc library. Otherwise, the libc library file cannot be found during the link time.
>
> - **-target arm-liteos** specifies the path of the library files related to the compiler.
>
> - **--sysroot=/home/<user-name>/harmony/out/hispark_taurus/ipcamera_hispark_taurus/sysroot** specifies the root directory of the compiler library files. In this example, the OpenHarmony project code is stored in **/home/<user-name>/harmony**. The **out/hispark_taurus/ipcamera_hispark_taurus** directory indicates the product specified by the **hb set** command during compilation. In this example, **ipcamera_hispark_taurus** is the product specified.
>
> - **$(clang -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4 -target arm-liteos -print-file-name=libunwind.a)** specifies the path of the unwind library.


##### Debugging Information


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


##### Call Stack Parsing

The **parse_mem_info.sh** script in **kernel/liteos_a/tools/scripts/parse_memory/** can be used to parse the call stack. You can use the script to convert the debug information into specific source code line number. In the following command, **mem_debug.txt** stores the memory debugging information, and **elf1** and **elf2** are the executable and linkable format (ELF) files to parse.


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

#### Using the CLI


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


##### Sample Code

The sample code constructs a memory problem and uses the command line to perform memory debugging.


```c
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_LEAK_SIZE  0x300

void func(void)
{
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


##### Compilation

For details, see [Compilation](#compilation).


##### Running the mwatch Command


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


##### Call Stack Parsing

Save the debugging information to the **test.txt** file and use the script to parse the information to obtain the number of the line where the memory leak occurs.


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


##### Running the mrecord Command

1. Run the user program and specify the path of the file that stores the memory debugging information.

   ```
   OHOS # ./mem_check --mrecord /storage/check.txt
   ```

2. Run the **kill -35 <*pid*>** command to collect statistics on the memory information. The information is exported to a file. Run the **cat** command to view the information.

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

3. Run the **kill -36 <*pid*>** command to check memory integrity. The information is exported to a file. Run the **cat** command to view the information.

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

4. Run the **kill -9 <*pid*>** command to kill the current process. After the process exits, a memory integrity check is performed by default. The check result is output to a file. You can run the **cat** command to view it.

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

> **NOTE**<br>
> The preceding information recorded gradually is added to the file specified during initialization. Therefore, running the **cat** command can also display the historical information in the file.
## Common Problems


### Use After Free (UAF)

- Requested memory less than or equal to 0x1c000 bytes:
  
  Read operation: If the magic number (0xFEFEFEFE) is read from the memory block released, UAF occurs.
  
  > **NOTE**
  >
  > After **free** is called, the heap memory will not be released to the heap memory pool immediately. Instead, the heap memory is placed in a queue with a fixed length and filled with the magic number 0xFE. When the queue is full, the memory block first placed in the queue is released to the heap memory pool first.
  
  Write operation: The memory debugging module cannot detect UAF errors from write operations.


- Requested memory block greater than 0x1c000 bytes:
  
  The heap memory greater than 0x1c000 bytes must be requested by calling the **mmap** API via **malloc**. If the heap memory is accessed after being released, the user program will become abnormal (because the memory region has been unmapped).


### Double Free

Double free errors occur when **free()** is called more than once with the same memory address as an argument. When a double free error occurs, the user program exits unexpectedly.


### Heap Memory Node Corrupted

- Requested memory block less than or equal to 0x1c000 bytes:

  When a heap memory node is corrupted, the user program exits unexpectedly, and the call stack that requests the heap memory of the node corrupted is output. The memory debugging module, however, cannot debug the memory corrupted by a wild pointer. For example, if the user program mem_check has heap memory overwriting, you can use the command line to obtain the possible location of the memory corruption.


  ```
  OHOS # ./mem_check --mwatch
  OHOS #
  ==PID:6== Memory integrity information:
      [TID:28 allocated addr: 0x272e1ea0, size: 0x120] The possible attacker was allocated from:
          #00: <malloc+0x808>[0x640e8] -> /lib/libc.so
          #01: <threadFunc1+0x7c>[0x21d0] -> mem_check
  ```

  You can use the call stack parsing script to parse the call stack information.

- Requested memory block greater than 0x1c000 bytes:

  When a large memory block (greater than 0x1c000 bytes) is requested by calling the **mmap** API via **malloc**, one more page of **PAGE_SIZE** is allocated at the start and end of the memory region. The two pages are neither readable nor writeable. Any read or write operation to the pages may cause an exception of the user program.
