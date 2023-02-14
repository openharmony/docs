# LMS


## Basic Concepts

Lite Memory Sanitizer (LMS) is a tool used to detect memory errors on a real-time basis. LMS can detect buffer overflow, Use-After-Free (UAF), and double free errors in real time, and notify the operating system immediately. Together with locating methods such as Backtrace, LMS can locate the code line that causes the memory error. It greatly improves the efficiency of locating memory errors.

The LMS module of the OpenHarmony LiteOS-A kernel provides the following functions:

- Supports check of multiple memory pools.

- Checks the memory allocated by **LOS_MemAlloc**, **LOS_MemAllocAlign**, and **LOS_MemRealloc**.

- Checks the memory when bounds-checking functions are called (enabled by default).

- Checks the memory when libc frequently accessed functions, including **memset**, **memcpy**, **memmove**, **strcat**, **strcpy**, **strncat** and **strncpy**, are called.


## Working Principles

LMS uses shadow memory mapping to mark the system memory state. There are three states: **Accessible**, **RedZone**, and **Freed**. The shadow memory is located in the tail of the memory pool.

- After memory is allocated from the heap, the shadow memory in the data area is set to the **Accessible** state, and the shadow memory in the head node area is set to the **RedZone** state.

- When memory is released from the heap, the shadow memory of the released memory is set to the **Freed** state.

- During code compilation, a function is inserted before the read/write instructions in the code to check the address validity. The tool checks the state value of the shadow memory that accesses the memory. If the shadow memory is in the **RedZone** statue, an overflow error will be reported. If the shadow memory is in the **Freed** state, a UAF error will be reported.

- When memory is released, the tool checks the state value of the shadow memory at the released address. If the shadow memory is in the **RedZone** state, a double free error will be reported.


## Available APIs


### Kernel Mode

The LMS module of the OpenHarmony LiteOS-A kernel provides the following APIs. For more details, see [API reference](https://gitee.com/openharmony/kernel_liteos_a/blob/master/kernel/include/los_lms.h).

  **Table 1** APIs of the LMS module

| Category| API| Description|
| -------- | -------- | -------- |
| Adding a memory pool to be checked| LOS_LmsCheckPoolAdd | Adds the address range of a memory pool to the LMS check linked list. LMS performs a validity check when the accessed address is within the linked list. In addition, **LOS_MemInit** calls this API to add the initialized memory pool to the LMS check linked list by default.|
| Deleting a memory pool from the LMS check linked list| LOS_LmsCheckPoolDel | Cancels the validity check on the specified memory pool.|
| Protecting a specified memory chunk| LOS_LmsAddrProtect | Locks a memory chunk to prevent it from being read or written. Once the locked memory chunk is accessed, an error will be reported.|
| Disabling protection of a specified memory chunk| LOS_LmsAddrDisableProtect | Unlocks a memory chunk to make it readable and writable.|


### User Mode

The user mode provides only the LMS check library. It does not provide external APIs.


## Development Guidelines


### Kernel-Mode Development Process

The typical process for enabling LMS is as follows:

1. Configure the macros related to the LMS module.
   Configure the LMS macro **LOSCFG_KERNEL_LMS**, which is disabled by default. Run the **make update_config** command in the **kernel/liteos_a** directory, choose **Kernel**, and select **Enable Lite Memory Sanitizer**.

   | Macro| menuconfig Option| Description| Value |
   | -------- | -------- | -------- | -------- |
   | LOSCFG_KERNEL_LMS | Enable Lms Feature | Whether to enable LMS.| YES/NO |
   | LOSCFG_LMS_MAX_RECORD_POOL_NUM | Lms check pool max num | Maximum number of memory pools that can be checked by LMS.| INT |
   | LOSCFG_LMS_LOAD_CHECK | Enable lms read check | Whether to enable LMS read check.| YES/NO |
   | LOSCFG_LMS_STORE_CHECK | Enable lms write check | Whether to enable LMS write check.| YES/NO |
   | LOSCFG_LMS_CHECK_STRICT | Enable lms strict check, byte-by-byte | Whether to enable LMS byte-by-byte check.| YES/NO |

2. Modify the build script of the target module.
   Add **-fsanitize=kernel-address** to insert memory access checks, and add the  **-O0**  option to disable optimization performed by the compiler.

     The modifications vary depending on the compiler (GCC or Clang) used. The following is an example:

   ```
   if ("$ohos_build_compiler_specified" == "gcc") {
       cflags_c = [
       "-O0",
       "-fsanitize=kernel-address",
       ]
   } else {
       cflags_c = [
       "-O0",
       "-fsanitize=kernel-address",
       "-mllvm",
       "-asan-instrumentation-with-call-threshold=0",
       "-mllvm",
       "-asan-stack=0",
       "-mllvm",
       "-asan-globals=0",
       ]
   }
   ```

3. Recompile the code and check the serial port output. The memory problem detected will be displayed.


#### Kernel-Mode Development Example

This example implements the following:

1. Create a task for LMS.

2. Construct a buffer overflow error and a UAF error.

3. Add "-fsanitize=kernel-address", execute the compilation, and check the output.


#### Kernel-Mode Sample Code

The functions of the sample code can be added to **TestTaskEntry** in **kernel /liteos_a/testsuites /kernel /src /osTest.c** for testing.
The sample code is as follows:

```c
#define PAGE_SIZE       (0x1000U)
#define INDEX_MAX       20
UINT32 g_lmsTestTaskId;
char g_testLmsPool[2 * PAGE_SIZE];
STATIC VOID testPoolInit(void)
{
    UINT32 ret = LOS_MemInit(g_testLmsPool, 2 * PAGE_SIZE);
    if (ret != 0) {
        PRINT_ERR("%s failed, ret = 0x%x\n", __FUNCTION__, ret);
        return;
    }
}
static VOID LmsTestOsmallocOverflow(VOID)
{
    PRINTK("\n######%s start ######\n", __FUNCTION__);
    UINT32 i;
    CHAR *str = (CHAR *)LOS_MemAlloc(g_testLmsPool, INDEX_MAX);
    PRINTK("str[%2d]=0x%2x ", INDEX_MAX, str[INDEX_MAX]); /* trigger heap overflow at str[INDEX_MAX] */
    PRINTK("\n######%s stop ######\n", __FUNCTION__);
}
static VOID LmsTestUseAfterFree(VOID)
{
    PRINTK("\n######%s start ######\n", __FUNCTION__);
    UINT32 i;
    CHAR *str = (CHAR *)LOS_MemAlloc(g_testLmsPool, INDEX_MAX);
    (VOID)LOS_MemFree(g_testLmsPool, str);
    PRINTK("str[%2d]=0x%2x ", 0, str[0]); /* trigger use after free at str[0] */
    PRINTK("\n######%s stop ######\n", __FUNCTION__);
}
VOID LmsTestCaseTask(VOID)
{
    testPoolInit();
    LmsTestOsmallocOverflow();
    LmsTestUseAfterFree();
}
UINT32 Example_Lms_test(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S lmsTestTask;
    /* Create a task for LMS. */
    memset(&lmsTestTask, 0, sizeof(TSK_INIT_PARAM_S));
    lmsTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)LmsTestCaseTask;
    lmsTestTask.pcName       = "TestLmsTsk";  /* Test task name. */
    lmsTestTask.uwStackSize  = 0x800; // 0x800: LMS test task stack size
    lmsTestTask.usTaskPrio   = 5; // 5: LMS test task priority
    lmsTestTask.uwResved   = LOS_TASK_STATUS_DETACHED;
    ret = LOS_TaskCreate(&g_lmsTestTaskId, &lmsTestTask);
    if (ret != LOS_OK) {
        PRINT_ERR("LmsTestTask create failed .\n");
        return LOS_NOK;
    }
    return LOS_OK;
}
LOS_MODULE_INIT(Example_Lms_test, LOS_INIT_LEVEL_KMOD_EXTENDED);
```


#### Kernel-Mode Verification

  The output is as follows:

```
######LmsTestOsmallocOverflow start ######
[ERR][KProcess:LmsTestCaseTask]*  Kernel Address Sanitizer Error Detected Start *
[ERR][KProcess:LmsTestCaseTask]Heap buffer overflow error detected
[ERR][KProcess:LmsTestCaseTask]Illegal READ address at: [0x4157a3c8]
[ERR][KProcess:LmsTestCaseTask]Shadow memory address: [0x4157be3c : 4]  Shadow memory value: [2]
OsBackTrace fp = 0x402c0f88
runTask->taskName = LmsTestCaseTask
runTask->taskID = 2
***backtrace begin***
traceback fp fixed, trace using   fp = 0x402c0fd0
traceback 0 -- lr = 0x400655a4    fp = 0x402c0ff8
traceback 1 -- lr = 0x40065754    fp = 0x402c1010
traceback 2 -- lr = 0x40044bd0    fp = 0x402c1038
traceback 3 -- lr = 0x40004e14    fp = 0xcacacaca
[LMS] Dump info around address [0x4157a3c8]:
        [0x4157a3a0]:  00  00  00  00  00  00  00  00 | [0x4157be3a |  0]:  1  1
        [0x4157a3a8]:  ba  dc  cd  ab  00  00  00  00 | [0x4157be3a |  4]:  2  2
        [0x4157a3b0]:  20  00  00  80  00  00  00  00 | [0x4157be3b |  0]:  2  0
        [0x4157a3b8]:  00  00  00  00  00  00  00  00 | [0x4157be3b |  4]:  0  0
        [0x4157a3c0]:  00  00  00  00  00  00  00  00 | [0x4157be3c |  0]:  0  0
        [0x4157a3c8]: [ba] dc  cd  ab  a8  a3  57  41 | [0x4157be3c |  4]: [2] 2
        [0x4157a3d0]:  2c  1a  00  00  00  00  00  00 | [0x4157be3d |  0]:  2  3
        [0x4157a3d8]:  00  00  00  00  00  00  00  00 | [0x4157be3d |  4]:  3  3
        [0x4157a3e0]:  00  00  00  00  00  00  00  00 | [0x4157be3e |  0]:  3  3
        [0x4157a3e8]:  00  00  00  00  00  00  00  00 | [0x4157be3e |  4]:  3  3
        [0x4157a3f0]:  00  00  00  00  00  00  00  00 | [0x4157be3f |  0]:  3  3
[ERR][KProcess:LmsTestCaseTask]*  Kernel Address Sanitizer Error Detected End *
str[20]=0xffffffba
######LmsTestOsmallocOverflow stop ######
###### LmsTestUseAfterFree start ######
[ERR][KProcess:LmsTestCaseTask]*  Kernel Address Sanitizer Error Detected Start *
[ERR][KProcess:LmsTestCaseTask]Use after free error detected
[ERR][KProcess:LmsTestCaseTask]Illegal READ address at: [0x4157a3d4]
[ERR][KProcess:LmsTestCaseTask]Shadow memory address: [0x4157be3d : 2]  Shadow memory value: [3]
OsBackTrace fp = 0x402c0f90
runTask->taskName = LmsTestCaseTask
runTask->taskID = 2
***backtrace begin***
traceback fp fixed, trace using   fp = 0x402c0fd8
traceback 0 -- lr = 0x40065680    fp = 0x402c0ff8
traceback 1 -- lr = 0x40065758    fp = 0x402c1010
traceback 2 -- lr = 0x40044bd0    fp = 0x402c1038
traceback 3 -- lr = 0x40004e14    fp = 0xcacacaca
[LMS] Dump info around address [0x4157a3d4]:
        [0x4157a3a8]:  ba  dc  cd  ab  00  00  00  00 | [0x4157be3a |  4]:  2  2
        [0x4157a3b0]:  20  00  00  80  00  00  00  00 | [0x4157be3b |  0]:  2  0
        [0x4157a3b8]:  00  00  00  00  00  00  00  00 | [0x4157be3b |  4]:  0  0
        [0x4157a3c0]:  00  00  00  00  00  00  00  00 | [0x4157be3c |  0]:  0  0
        [0x4157a3c8]:  ba  dc  cd  ab  a8  a3  57  41 | [0x4157be3c |  4]:  2  2
        [0x4157a3d0]:  2c  1a  00  00 [00] 00  00  00 | [0x4157be3d |  0]:  2 [3]
        [0x4157a3d8]:  00  00  00  00  00  00  00  00 | [0x4157be3d |  4]:  3  3
        [0x4157a3e0]:  00  00  00  00  00  00  00  00 | [0x4157be3e |  0]:  3  3
        [0x4157a3e8]:  ba  dc  cd  ab  c8  a3  57  41 | [0x4157be3e |  4]:  2  2
        [0x4157a3f0]:  0c  1a  00  00  00  00  00  00 | [0x4157be3f |  0]:  2  3
        [0x4157a3f8]:  00  00  00  00  00  00  00  00 | [0x4157be3f |  4]:  3  3
[ERR][KProcess:LmsTestCaseTask]*  Kernel Address Sanitizer Error Detected End *
str[ 0]=0x 0
######LmsTestUseAfterFree stop ######
```

The key output information is as follows:

- Error type:
  - Heap buffer overflow
  - UAF

- Incorrect operations:
  - Illegal read
  - Illegal write
  - Illegal double free

- Context:
  - Task information (**taskName** and **taskId**)
  - Backtrace

- Memory information of the error addresses:
  - Memory value and the value of the corresponding shadow memory
  - Memory address: memory value|[shadow memory address|shadow memory byte offset]: shadow memory value
  - Shadow memory value. **0** (Accessible), **3** (Freed), **2** (RedZone), and **1** (filled value)


### User-Mode Development Process

Add the following to the app build script to be checked. For details about the sample code, see [/kernel/liteos_a/apps/lms/BUILD.gn](https://gitee.com/openharmony/kernel_liteos_a/blob/master/apps/lms/BUILD.gn).


```
if ("$ohos_build_compiler_specified" == "gcc") {
        cflags_c = [
        "-O0",
        "-fsanitize=kernel-address",
        "-funwind-tables",
        "-fasynchronous-unwind-tables",
        ]
    } else {
        cflags_c = [
            "-O0",
            "-fsanitize=kernel-address",
            "-mllvm",
            "-asan-instrumentation-with-call-threshold=0",
            "-mllvm",
            "-asan-stack=0",
            "-mllvm",
            "-asan-globals=0",
            "-funwind-tables",
            "-fasynchronous-unwind-tables",
        ]
  }
  ldflags = [
    "-rdynamic",
    "-lunwind",
    "-lusrlms",
    "-Wl,--wrap=realloc",
    "-Wl,--wrap=calloc",
    "-Wl,--wrap=malloc",
    "-Wl,--wrap=free",
    "-Wl,--wrap=valloc",
    "-Wl,--wrap=aligned_alloc",
    "-Wl,--wrap=memset",
    "-Wl,--wrap=memcpy",
    "-Wl,--wrap=memmove",
    "-Wl,--wrap=strcpy",
    "-Wl,--wrap=strcat",
  ]
  deps = [ "//kernel/liteos_a/kernel/extended/lms/usr:usrlmslib" ]
```


#### User-Mode Development Example

This example implements the following:

1. Construct a buffer overflow error and a UAF error.

2. Modify the build script and perform the build again.


#### User-Mode Sample Code

  The code is as follows:

```c
static void BufWriteTest(void *buf, int start, int end)
{
    for (int i = start; i <= end; i++) {
        ((char *)buf)[i] = 'a';
    }
}
static void BufReadTest(void *buf, int start, int end)
{
    char tmp;
    for (int i = start; i <= end; i++) {
        tmp = ((char *)buf)[i];
    }
}
static void LmsMallocTest(void)
{
    printf("\n-------- LmsMallocTest Start --------\n");
    char *buf = (char *)malloc(16); // 16: buffer size for test
    BufReadTest(buf, -1, 16);
    free(buf);
    printf("\n-------- LmsMallocTest End --------\n");
}
static void LmsFreeTest(void)
{
    printf("\n-------- LmsFreeTest Start --------\n");
    char *buf = (char *)malloc(16); // 16: buffer size for test
    free(buf);
    BufReadTest(buf, 1, 1);
    free(buf);
    printf("\n-------- LmsFreeTest End --------\n");
}
int main(int argc, char * const * argv)
{
    printf("\n############### Lms Test start ###############\n");
    char *tmp = (char *)malloc(5000); // 5000: temp buffer size
    LmsMallocTest();
    LmsFreeTest();
    printf("\n############### Lms Test End ###############\n");
}
```


#### User-Mode Verification

  The output is as follows:

```
*  Lite Memory Sanitizer Error Detected  *
Heap buffer overflow error detected!
Illegal READ address at: [0x1f8b3edf]
Shadow memory address: [0x3d34d3ed : 6]  Shadow memory value: [2]
Accessible heap addr     0
Heap red zone            2
Heap freed buffer        3
Dump info around address [0x1f8b3edf]:
        [0x1f8b3eb8]:  74  55  8b  1f  74  55  8b  1f | [0x3d34d3eb |  4]:  0  0
        [0x1f8b3ec0]:  f8  9c  8b  1f  00  00  00  00 | [0x3d34d3ec |  0]:  0  0
        [0x1f8b3ec8]:  00  00  00  00  9c  fc  fc  fc | [0x3d34d3ec |  4]:  0  0
        [0x1f8b3ed0]:  21  00  00  00  41  00  00  00 | [0x3d34d3ed |  0]:  0  0
        [0x1f8b3ed8]:  60  55  8b  1f  60  55  8b [1f]| [0x3d34d3ed |  4]:  2 [2]
        [0x1f8b3ee0]:  50  4e  0b  00  00  00  00  00 | [0x3d34d3ee |  0]:  0  0
        [0x1f8b3ee8]:  09  00  00  00  00  00  00  00 | [0x3d34d3ee |  4]:  0  0
        [0x1f8b3ef0]:  00  00  00  00  08  03  09  00 | [0x3d34d3ef |  0]:  2  2
        [0x1f8b3ef8]:  00  00  00  00  00  00  00  00 | [0x3d34d3ef |  4]:  2  2
*  Lite Memory Sanitizer Error Detected End *
Backtrace() returned 5 addresses
    #01: <LMS_ReportError+0x284>[0x4d6c] -> ./sample_usr_lms
    #02: <(null)+0x2004074>[0x4074] -> ./sample_usr_lms
    #03: <(null)+0x2003714>[0x3714] -> ./sample_usr_lms
    #04: <main+0x40>[0x363c] -> ./sample_usr_lms
    #05: <(null)+0x1f856f30>[0x56f30] -> /lib/libc.so
-------- LMS_malloc_test End --------
*  Lite Memory Sanitizer Error Detected  *
Use after free error detected!
Illegal Double free address at: [0x1f8b3ee0]
Shadow memory address: [0x3d34d3ee : 0]  Shadow memory value: [3]
Accessible heap addr     0
Heap red zone            2
Heap freed buffer        3
Dump info around address [0x1f8b3ee0]:
        [0x1f8b3ec0]:  f8  9c  8b  1f  00  00  00  00 | [0x3d34d3ec |  0]:  0  0
        [0x1f8b3ec8]:  00  00  00  00  fc  fd  fc  fc | [0x3d34d3ec |  4]:  0  0
        [0x1f8b3ed0]:  21  00  00  00  20  01  00  00 | [0x3d34d3ed |  0]:  0  0
        [0x1f8b3ed8]:  60  55  8b  1f  60  55  8b  1f | [0x3d34d3ed |  4]:  2  2
        [0x1f8b3ee0]: [20] 60  9a  1f  40  61  9a  1f | [0x3d34d3ee |  0]: [3] 3
        [0x1f8b3ee8]:  60  62  9a  1f  80  63  9a  1f | [0x3d34d3ee |  4]:  3  3
        [0x1f8b3ef0]:  20  40  8b  1f  20  20  8b  1f | [0x3d34d3ef |  0]:  3  3
        [0x1f8b3ef8]:  00  00  00  00  00  00  00  00 | [0x3d34d3ef |  4]:  3  3
        [0x1f8b3f00]:  00  00  00  00  00  00  00  00 | [0x3d34d3f0 |  0]:  3  3
*  Lite Memory Sanitizer Error Detected End *
Backtrace() returned 5 addresses
    #01: <LMS_ReportError+0x284>[0x4d6c] -> ./sample_usr_lms
    #02: <LMS_free+0xcc>[0x5548] -> ./sample_usr_lms
    #03: <(null)+0x2003fc4>[0x3fc4] -> ./sample_usr_lms
    #04: <main+0x68>[0x3664] -> ./sample_usr_lms
    #05: <(null)+0x1f856f30>[0x56f30] -> /lib/libc.so
-------- LMS_free_test End --------
```

The Backtrace output contains the names of the files where the addresses are located. You can locate the code line corresponding to the address in the related file.
