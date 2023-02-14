# LMS


## Basic Concepts

Lite Memory Sanitizer (LMS) is a tool used to detect memory errors on a real-time basis. It can detect buffer overflow, Use-After-Free (UAF), and double free errors in real time, and notify the operating system immediately. Together with Backtrace, the LMS can locate the code line that causes the memory error. It greatly improves the efficiency of locating memory errors.

The LMS module of the OpenHarmony LiteOS-M kernel provides the following functions:

- Supports check of multiple memory pools.

- Checks the memory allocated by **LOS_MemAlloc**, **LOS_MemAllocAlign**, and **LOS_MemRealloc**.

- Checks the memory when bounds-checking functions are called (enabled by default).

- Checks the memory when libc frequently accessed functions, including **memset**, **memcpy**, **memmove**, **strcat**, **strcpy**, **strncat** and **strncpy**, are called.


## Working Principles

The LMS uses shadow memory mapping to mark the system memory state. There are three states: **Accessible**, **RedZone**, and **Freed**. The shadow memory is located in the tail of the memory pool.

- After memory is allocated from the heap, the shadow memory in the data area is set to the **Accessible** state, and the shadow memory in the head node area is set to the **RedZone** state.

- When memory is released from the heap, the shadow memory of the released memory is set to the **Freed** state.

- During code compilation, a function is inserted before the read/write instructions in the code to check the address validity. The tool checks the state value of the shadow memory that accesses the memory. If the shadow memory is in the **RedZone** statue, an overflow error will be reported. If the shadow memory is in the **Freed** state, a UAF error will be reported.

- When memory is released, the tool checks the state value of the shadow memory at the released address. If the shadow memory is in the **RedZone** state, a double free error will be reported.


## Available APIs

The LMS module of the OpenHarmony LiteOS-A kernel provides the following APIs. For more details, see [API reference](https://gitee.com/openharmony/kernel_liteos_m/blob/master/components/lms/los_lms.h).

**Table 1** APIs of the LMS module

| Category| API | Description|
| -------- | -------- | -------- |
| Adding a memory pool to be checked| LOS_LmsCheckPoolAdd | Adds the address range of a memory pool to the LMS check linked list. LMS performs a validity check when the accessed address is within the linked list. In addition, **LOS_MemInit** calls this API to add the initialized memory pool to the LMS check linked list by default.|
| Deleting a memory pool from the LMS check linked list| LOS_LmsCheckPoolDel | Cancels the validity check on the specified memory pool.|
| Protecting a specified memory chunk| LOS_LmsAddrProtect | Locks a memory chunk to prevent it from being read or written. Once the locked memory chunk is accessed, an error will be reported.|
| Disabling protection of a specified memory chunk| LOS_LmsAddrDisableProtect | Unlocks a memory chunk to make it readable and writable.|


## Development Guidelines


### How to Develop

The typical process for enabling LMS is as follows:

1. Configure the macros related to the LMS module.
   Configure the LMS macro **LOSCFG_KERNEL_LMS**, which is disabled by default. 

   Run the **make menuconfig** command in the **kernel/liteos_m** directory, and set **Kernel-&gt;Enable Lite Memory Sanitizer** to **YES**. If this option is unavailable, select **Enable Backtrace**.
   
   | Macro| menuconfig Option| Description| Value|
   | -------- | -------- | -------- | -------- |
   | LOSCFG_KERNEL_LMS | Enable&nbsp;Lms&nbsp;Feature | Whether to enable LMS.| YES/NO |
   | LOSCFG_LMS_MAX_RECORD_POOL_NUM | Lms&nbsp;check&nbsp;pool&nbsp;max&nbsp;num | Maximum number of memory pools that can be checked by LMS.| INT |
   | LOSCFG_LMS_LOAD_CHECK | Enable&nbsp;lms&nbsp;read&nbsp;check | Whether to enable LMS read check.| YES/NO |
   | LOSCFG_LMS_STORE_CHECK | Enable&nbsp;lms&nbsp;write&nbsp;check | Whether to enable LMS write check.| YES/NO |
   | LOSCFG_LMS_CHECK_STRICT | Enable&nbsp;lms&nbsp;strict&nbsp;check,&nbsp;byte-by-byte | Whether to enable LMS byte-by-byte check.| YES/NO |
   
2. Modify the build script of the target module.
   Add **-fsanitize=kernel-address** to insert memory access checks, and add **-O0** to disable optimization performed by the compiler.

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

3. Recompile the code and check the serial port output. 

   The memory problem detected will be displayed.


### Development Example

This example implements the following:

1. Create a task for LMS.

2. Construct a buffer overflow error and a UAF error.

3. Add "-fsanitize=kernel-address", execute the compilation, and check the output.


### Sample Code

The code is as follows:

The sample code can be compiled and verified in **./kernel/liteos_m/testsuites/src/osTest.c**. The **Example_Lms_test** function is called in **TestTaskEntry**.

Modify **./kernel/liteos_m/testsuites/BUILD.gn** corresponding to **osTest.c**.

```
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
    LOS_MemFree(g_testLmsPool, str);
    PRINTK("str[%2d]=0x%2x ", 0, str[0]); /* trigger use after free at str[0] */
    PRINTK("\n######%s stop ######\n", __FUNCTION__);
}
VOID LmsTestCaseTask(VOID)
{ 
    testPoolInit();
    LmsTestOsmallocOverflow();
    LmsTestUseAfterFree();
}
UINT32 Example_Lms_test(VOID){
    UINT32 ret;    
    TSK_INIT_PARAM_S lmsTestTask;    
    /* Create a task for LMS. */   
    memset(&lmsTestTask, 0, sizeof(TSK_INIT_PARAM_S));    
    lmsTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)LmsTestCaseTask;
    lmsTestTask.pcName       = "TestLmsTsk";  /* Test task name. */   				     
    lmsTestTask.uwStackSize  = 0x800;    
    lmsTestTask.usTaskPrio   = 5;    
    lmsTestTask.uwResved   = LOS_TASK_STATUS_DETACHED;    
    ret = LOS_TaskCreate(&g_lmsTestTaskId, &lmsTestTask);    
    if(ret != LOS_OK){        
        PRINT_ERR("LmsTestTask create failed .\n");        
        return LOS_NOK;    
    } 
    return LOS_OK;
}
```


### Verification

  The following is an example of the command output. The data may vary depending on the running environment.

```
######LmsTestOsmallocOverflow start ######
[ERR][TestLmsTsk]*****  Kernel Address Sanitizer Error Detected Start *****
[ERR][TestLmsTsk]Heap buffer overflow error detected
[ERR][TestLmsTsk]Illegal READ address at: [0x21040414]
[ERR][TestLmsTsk]Shadow memory address: [0x21041e84 : 6]  Shadow memory value: [2]
psp, start = 21057d88, end = 21057e80
taskName = TestLmsTsk
taskID   = 5
----- traceback start -----
traceback 0 -- lr = 0x210099f4
traceback 1 -- lr = 0x2101da6e
traceback 2 -- lr = 0x2101db38
traceback 3 -- lr = 0x2101c494
----- traceback end -----

[LMS] Dump info around address [0x21040414]:

        [0x21040390]:  00  00  00  00  00  00  00  00 | [0x21041e7c |  4]:  1  1
        [0x21040398]:  00  00  00  00  00  00  00  00 | [0x21041e7d |  0]:  1  1
        [0x210403a0]:  00  00  00  00  00  00  00  00 | [0x21041e7d |  4]:  1  1
        [0x210403a8]:  00  00  00  00  00  00  00  00 | [0x21041e7e |  0]:  1  1
        [0x210403b0]:  00  00  00  00  00  00  00  00 | [0x21041e7e |  4]:  1  1
        [0x210403b8]:  00  00  00  00  00  00  00  00 | [0x21041e7f |  0]:  1  1
        [0x210403c0]:  00  00  00  00  00  00  00  00 | [0x21041e7f |  4]:  1  1
        [0x210403c8]:  00  00  00  00  00  00  00  00 | [0x21041e80 |  0]:  1  1
        [0x210403d0]:  00  00  00  00  00  00  00  00 | [0x21041e80 |  4]:  1  1
        [0x210403d8]:  00  00  00  00  00  00  00  00 | [0x21041e81 |  0]:  1  1
        [0x210403e0]:  00  00  00  00  00  00  00  00 | [0x21041e81 |  4]:  1  1
        [0x210403e8]:  00  00  00  00  00  00  00  00 | [0x21041e82 |  0]:  1  1
        [0x210403f0]:  00  00  00  00  00  00  00  00 | [0x21041e82 |  4]:  1  1
        [0x210403f8]:  40  1e  04  21  05  07  00  80 | [0x21041e83 |  0]:  2  2
        [0x21040400]:  00  00  00  00  00  00  00  00 | [0x21041e83 |  4]:  0  0
        [0x21040408]:  00  00  00  00  00  00  00  00 | [0x21041e84 |  0]:  0  0
        [0x21040410]:  00  00  00  00 [f8] 03  04  21 | [0x21041e84 |  4]:  0 [2]
        [0x21040418]:  00  8b  06  00  00  00  00  00 | [0x21041e85 |  0]:  2  3
        [0x21040420]:  00  00  00  00  00  00  00  00 | [0x21041e85 |  4]:  3  3
        [0x21040428]:  00  00  00  00  00  00  00  00 | [0x21041e86 |  0]:  3  3
        [0x21040430]:  00  00  00  00  00  00  00  00 | [0x21041e86 |  4]:  3  3
        [0x21040438]:  00  00  00  00  00  00  00  00 | [0x21041e87 |  0]:  3  3
        [0x21040440]:  00  00  00  00  00  00  00  00 | [0x21041e87 |  4]:  3  3
        [0x21040448]:  00  00  00  00  00  00  00  00 | [0x21041e88 |  0]:  3  3
        [0x21040450]:  00  00  00  00  00  00  00  00 | [0x21041e88 |  4]:  3  3
        [0x21040458]:  00  00  00  00  00  00  00  00 | [0x21041e89 |  0]:  3  3
        [0x21040460]:  00  00  00  00  00  00  00  00 | [0x21041e89 |  4]:  3  3
        [0x21040468]:  00  00  00  00  00  00  00  00 | [0x21041e8a |  0]:  3  3
        [0x21040470]:  00  00  00  00  00  00  00  00 | [0x21041e8a |  4]:  3  3
        [0x21040478]:  00  00  00  00  00  00  00  00 | [0x21041e8b |  0]:  3  3
        [0x21040480]:  00  00  00  00  00  00  00  00 | [0x21041e8b |  4]:  3  3
        [0x21040488]:  00  00  00  00  00  00  00  00 | [0x21041e8c |  0]:  3  3
        [0x21040490]:  00  00  00  00  00  00  00  00 | [0x21041e8c |  4]:  3  3
[ERR][TestLmsTsk]*****  Kernel Address Sanitizer Error Detected End *****
str[20]=0xfffffff8
######LmsTestOsmallocOverflow stop ######

######LmsTestUseAfterFree start ######
[ERR][TestLmsTsk]*****  Kernel Address Sanitizer Error Detected Start *****
[ERR][TestLmsTsk]Use after free error detected
[ERR][TestLmsTsk]Illegal READ address at: [0x2104041c]
[ERR][TestLmsTsk]Shadow memory address: [0x21041e85 : 2]  Shadow memory value: [3]
psp, start = 21057d90, end = 21057e80
taskName = TestLmsTsk
taskID   = 5
----- traceback start -----
traceback 0 -- lr = 0x210099f4
traceback 1 -- lr = 0x2101daec
traceback 2 -- lr = 0x2101db3c
traceback 3 -- lr = 0x2101c494
----- traceback end -----

[LMS] Dump info around address [0x2104041c]:

        [0x21040398]:  00  00  00  00  00  00  00  00 | [0x21041e7d |  0]:  1  1
        [0x210403a0]:  00  00  00  00  00  00  00  00 | [0x21041e7d |  4]:  1  1
        [0x210403a8]:  00  00  00  00  00  00  00  00 | [0x21041e7e |  0]:  1  1
        [0x210403b0]:  00  00  00  00  00  00  00  00 | [0x21041e7e |  4]:  1  1
        [0x210403b8]:  00  00  00  00  00  00  00  00 | [0x21041e7f |  0]:  1  1
        [0x210403c0]:  00  00  00  00  00  00  00  00 | [0x21041e7f |  4]:  1  1
        [0x210403c8]:  00  00  00  00  00  00  00  00 | [0x21041e80 |  0]:  1  1
        [0x210403d0]:  00  00  00  00  00  00  00  00 | [0x21041e80 |  4]:  1  1
        [0x210403d8]:  00  00  00  00  00  00  00  00 | [0x21041e81 |  0]:  1  1
        [0x210403e0]:  00  00  00  00  00  00  00  00 | [0x21041e81 |  4]:  1  1
        [0x210403e8]:  00  00  00  00  00  00  00  00 | [0x21041e82 |  0]:  1  1
        [0x210403f0]:  00  00  00  00  00  00  00  00 | [0x21041e82 |  4]:  1  1
        [0x210403f8]:  40  1e  04  21  05  07  00  80 | [0x21041e83 |  0]:  2  2
        [0x21040400]:  00  00  00  00  00  00  00  00 | [0x21041e83 |  4]:  0  0
        [0x21040408]:  00  00  00  00  00  00  00  00 | [0x21041e84 |  0]:  0  0
        [0x21040410]:  00  00  00  00  f8  03  04  21 | [0x21041e84 |  4]:  0  2
        [0x21040418]:  05  8b  06  00 [00] 00  00  00 | [0x21041e85 |  0]:  2 [3]
        [0x21040420]:  00  00  00  00  00  00  00  00 | [0x21041e85 |  4]:  3  3
        [0x21040428]:  00  00  00  00  00  00  00  00 | [0x21041e86 |  0]:  3  3
        [0x21040430]:  14  04  04  21  00  84  06  00 | [0x21041e86 |  4]:  2  2
        [0x21040438]:  00  00  00  00  00  00  00  00 | [0x21041e87 |  0]:  3  3
        [0x21040440]:  00  00  00  00  00  00  00  00 | [0x21041e87 |  4]:  3  3
        [0x21040448]:  00  00  00  00  00  00  00  00 | [0x21041e88 |  0]:  3  3
        [0x21040450]:  00  00  00  00  00  00  00  00 | [0x21041e88 |  4]:  3  3
        [0x21040458]:  00  00  00  00  00  00  00  00 | [0x21041e89 |  0]:  3  3
        [0x21040460]:  00  00  00  00  00  00  00  00 | [0x21041e89 |  4]:  3  3
        [0x21040468]:  00  00  00  00  00  00  00  00 | [0x21041e8a |  0]:  3  3
        [0x21040470]:  00  00  00  00  00  00  00  00 | [0x21041e8a |  4]:  3  3
        [0x21040478]:  00  00  00  00  00  00  00  00 | [0x21041e8b |  0]:  3  3
        [0x21040480]:  00  00  00  00  00  00  00  00 | [0x21041e8b |  4]:  3  3
        [0x21040488]:  00  00  00  00  00  00  00  00 | [0x21041e8c |  0]:  3  3
        [0x21040490]:  00  00  00  00  00  00  00  00 | [0x21041e8c |  4]:  3  3
        [0x21040498]:  00  00  00  00  00  00  00  00 | [0x21041e8d |  0]:  3  3
[ERR][TestLmsTsk]*****  Kernel Address Sanitizer Error Detected End *****
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
