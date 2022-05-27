# LMS


## Basic Concepts<a name="section531482192018"></a>

Lite Memory Sanitizer \(LMS\) is a tool used to detect memory errors on a real-time basis. LMS can detect buffer overflow, Use-After-Free \(UAF\), and double free errors in real time, and notify the operating system immediately. Together with locating methods such as Backtrace, LMS can locate the code line that causes the memory error. It greatly improves the efficiency of locating memory errors.

The LMS module of the OpenHarmony LiteOS-A kernel provides the following functions:

-   Supports check of multiple memory pools.
-   Checks the memory allocated by  **LOS\_MemAlloc**,  **LOS\_MemAllocAlign**, and  **LOS\_MemRealloc**.
-   Checks the memory when bounds-checking functions are called \(enabled by default\).
-   Checks the memory when libc frequently accessed functions, including  **memset**,  **memcpy**,  **memmove**,  **strcat**,  **strcpy**,  **strncat**  and  **strncpy**, are called.

## Working Principles<a name="section5125124532010"></a>

LMS uses shadow memory mapping to mark the system memory state. There are three states:  **Accessible**,  **RedZone**, and  **Freed**. The shadow memory is located in the tail of the memory pool.

-   After memory is allocated from the heap, the shadow memory in the data area is set to the  **Accessible**  state, and the shadow memory in the head node area is set to the  **RedZone**  state.
-   When memory is released from the heap, the shadow memory of the released memory is set to the  **Freed**  state.
-   During code compilation, a function is inserted before the read/write instructions in the code to check the address validity. The tool checks the state value of the shadow memory that accesses the memory. If the shadow memory is in the  **RedZone**  statue, an overflow error will be reported. If the shadow memory is in the  **Freed**  state, a UAF error will be reported.
-   When memory is released, the tool checks the state value of the shadow memory at the released address. If the shadow memory is in the  **RedZone**  state, a double free error will be reported.

## Available APIs<a name="section17747184017458"></a>

### Kernel Mode<a name="section104473014465"></a>

The LMS module of the OpenHarmony LiteOS-A kernel provides the following APIs. For more details about the APIs, see the  [API](https://gitee.com/openharmony/kernel_liteos_a/blob/master/kernel/include/los_lms.h)  reference.

**Table  1**  LMS module APIs

<a name="table209384411409"></a>
<table><thead align="left"><tr id="row49387411909"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p142345517111"><a name="p142345517111"></a><a name="p142345517111"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p16234751114"><a name="p16234751114"></a><a name="p16234751114"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p1823555614"><a name="p1823555614"></a><a name="p1823555614"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row8853204717245"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1363682115251"><a name="p1363682115251"></a><a name="p1363682115251"></a>Adding a memory pool to be checked</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p363617214253"><a name="p363617214253"></a><a name="p363617214253"></a>LOS_LmsCheckPoolAdd</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1163632113259"><a name="p1163632113259"></a><a name="p1163632113259"></a>Adds the address range of a memory pool to the LMS check linked list. LMS performs a validity check when the accessed address is within the linked list. In addition, <strong id="b126321851183511"><a name="b126321851183511"></a><a name="b126321851183511"></a>LOS_MemInit</strong> calls this API to add the initialized memory pool to the LMS check linked list by default.</p>
</td>
</tr>
<tr id="row1094914508245"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p13104133062514"><a name="p13104133062514"></a><a name="p13104133062514"></a>Deleting a memory pool from the LMS check linked list</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p161042030142516"><a name="p161042030142516"></a><a name="p161042030142516"></a>LOS_LmsCheckPoolDel</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p17104430102517"><a name="p17104430102517"></a><a name="p17104430102517"></a>Cancels the validity check on the specified memory pool.</p>
</td>
</tr>
<tr id="row749355410241"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p178831422252"><a name="p178831422252"></a><a name="p178831422252"></a>Protecting a specified memory chunk</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1688315421254"><a name="p1688315421254"></a><a name="p1688315421254"></a>LOS_LmsAddrProtect</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p128831842152520"><a name="p128831842152520"></a><a name="p128831842152520"></a>Locks a memory chunk to prevent it from being read or written. Once the locked memory chunk is accessed, an error will be reported.</p>
</td>
</tr>
<tr id="row1018195932414"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p11243144917257"><a name="p11243144917257"></a><a name="p11243144917257"></a>Disabling protection of a specified memory chunk</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1324354932516"><a name="p1324354932516"></a><a name="p1324354932516"></a>LOS_LmsAddrDisableProtect</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p12243184922515"><a name="p12243184922515"></a><a name="p12243184922515"></a>Unlocks a memory chunk to make it readable and writable.</p>
</td>
</tr>
</tbody>
</table>

### User Mode<a name="section58151229172811"></a>

The user mode provides only the LMS check library. It does not provide external APIs.

## Development Guidelines<a name="section10302175017543"></a>

### Kernel-mode Development Process<a name="section04021008552"></a>

The typical process for enabling LMS is as follows:

1.  Configure the macros related to the LMS module.

    Configure the LMS macro  **LOSCFG\_KERNEL\_LMS**, which is disabled by default. Run the  **make update\_config**  command in the  **kernel/liteos\_a**  directory, choose  **Kernel**, and select  **Enable Lite Memory Sanitizer**.

    <a name="table06964569614"></a>
    <table><thead align="left"><tr id="row1697105618610"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p669715610619"><a name="p669715610619"></a><a name="p669715610619"></a>Macro</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p0697105612614"><a name="p0697105612614"></a><a name="p0697105612614"></a>menuconfig Option</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p5697175610610"><a name="p5697175610610"></a><a name="p5697175610610"></a>Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p1269712561866"><a name="p1269712561866"></a><a name="p1269712561866"></a>Value</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row92613334297"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p4252633102917"><a name="p4252633102917"></a><a name="p4252633102917"></a>LOSCFG_KERNEL_LMS</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p92528337293"><a name="p92528337293"></a><a name="p92528337293"></a>Enable Lms Feature</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p13252133362915"><a name="p13252133362915"></a><a name="p13252133362915"></a>Whether to enable LMS.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p42521833172917"><a name="p42521833172917"></a><a name="p42521833172917"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row19261173310297"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p02529337299"><a name="p02529337299"></a><a name="p02529337299"></a>LOSCFG_LMS_MAX_RECORD_POOL_NUM</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p4252203372913"><a name="p4252203372913"></a><a name="p4252203372913"></a>Lms check pool max num</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p15253153322912"><a name="p15253153322912"></a><a name="p15253153322912"></a>Maximum number of memory pools that can be checked by LMS.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p11253123319293"><a name="p11253123319293"></a><a name="p11253123319293"></a>INT</p>
    </td>
    </tr>
    <tr id="row22611332293"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p325363316297"><a name="p325363316297"></a><a name="p325363316297"></a>LOSCFG_LMS_LOAD_CHECK</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p162531334294"><a name="p162531334294"></a><a name="p162531334294"></a>Enable lms read check</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p7253633112915"><a name="p7253633112915"></a><a name="p7253633112915"></a>Whether to enable LMS read check.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p02531733132910"><a name="p02531733132910"></a><a name="p02531733132910"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row1826153311290"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1025383314293"><a name="p1025383314293"></a><a name="p1025383314293"></a>LOSCFG_LMS_STORE_CHECK</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p125383322920"><a name="p125383322920"></a><a name="p125383322920"></a>Enable lms write check</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p52531933192917"><a name="p52531933192917"></a><a name="p52531933192917"></a>Whether to enable LMS write check.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p225313335292"><a name="p225313335292"></a><a name="p225313335292"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row15261333142915"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p825310333293"><a name="p825310333293"></a><a name="p825310333293"></a>LOSCFG_LMS_CHECK_STRICT</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p142538338292"><a name="p142538338292"></a><a name="p142538338292"></a>Enable lms strict check, byte-by-byte</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p1325333352920"><a name="p1325333352920"></a><a name="p1325333352920"></a>Whether to enable LMS byte-by-byte check.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p32541333292"><a name="p32541333292"></a><a name="p32541333292"></a>YES/NO</p>
    </td>
    </tr>
    </tbody>
    </table>

2.  Modify the compile script of the target module.

    Add "-fsanitize=kernel-address" to insert memory access checks, and add the  **-O0**  option to disable optimization performed by the compiler.

    The modifications vary depending on the compiler \(GCC or Clang\) used. The following is an example:

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

3.  Recompile the code and check the serial port output. The memory problem detected will be displayed.

## Kernel-mode Development Example<a name="section112034213583"></a>

This example implements the following:

1.  Create a task for LMS.
2.  Construct a buffer overflow error and a UAF error.
3.  Add "-fsanitize=kernel-address", execute the compilation, and check the output.

## Kernel-mode Sample Code<a name="section10348549155812"></a>

The code is as follows:

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
    lmsTestTask.pcName       = "TestLmsTsk";    /* Task name. */
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
LOS_MODULE_INIT(Example_Lms_test, LOS_INIT_LEVEL_KMOD_EXTENDED);
```

### Kernel-mode Verification<a name="section61719481795"></a>

The output is as follows:

```
######LmsTestOsmallocOverflow start ######
[ERR][KProcess:LmsTestCaseTask]*****  Kernel Address Sanitizer Error Detected Start *****
[ERR][KProcess:LmsTestCaseTask]Heap buffer overflow error detected
[ERR][KProcess:LmsTestCaseTask]Illegal READ address at: [0x4157a3c8]
[ERR][KProcess:LmsTestCaseTask]Shadow memory address: [0x4157be3c : 4]  Shadow memory value: [2]
OsBackTrace fp = 0x402c0f88
runTask->taskName = LmsTestCaseTask
runTask->taskID = 2
*******backtrace begin*******
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
[ERR][KProcess:LmsTestCaseTask]*****  Kernel Address Sanitizer Error Detected End *****
str[20]=0xffffffba
######LmsTestOsmallocOverflow stop ######
###### LmsTestUseAfterFree start ######
[ERR][KProcess:LmsTestCaseTask]*****  Kernel Address Sanitizer Error Detected Start *****
[ERR][KProcess:LmsTestCaseTask]Use after free error detected
[ERR][KProcess:LmsTestCaseTask]Illegal READ address at: [0x4157a3d4]
[ERR][KProcess:LmsTestCaseTask]Shadow memory address: [0x4157be3d : 2]  Shadow memory value: [3]
OsBackTrace fp = 0x402c0f90
runTask->taskName = LmsTestCaseTask
runTask->taskID = 2
*******backtrace begin*******
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
[ERR][KProcess:LmsTestCaseTask]*****  Kernel Address Sanitizer Error Detected End *****
str[ 0]=0x 0
######LmsTestUseAfterFree stop ######
```

The key output information is as follows:

-   Error type:
    -   Heap buffer overflow
    -   UAF

-   Incorrect operations:
    -   Illegal read
    -   Illegal write
    -   Illegal double free

-   Context:
    -   Task information \(**taskName**  and  **taskId**\)
    -   Backtrace

-   Memory information of the error addresses:
    -   Memory value and the value of the corresponding shadow memory
    -   Memory address: memory value|\[shadow memory address|shadow memory byte offset\]: shadow memory value
    -   Shadow memory value.  **0**  \(Accessible\),  **3**  \(Freed\),  **2**  \(RedZone\), and  **1**  \(filled value\)


### User-mode Development Process<a name="section1425821711114"></a>

Add the following to the build script of the app to be checked. For details about the complete code, see  **/kernel/liteos\_a/apps/lms/BUILD.gn**.

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

### User-mode Development Example<a name="section3470546163"></a>

This example implements the following:

1.  Construct a buffer overflow error and a UAF error.
2.  Modify the build script and perform the build again.

### User-Mode Sample Code<a name="section183253286161"></a>

The code is as follows:

```
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
    char *buf = (char *)malloc(16);
    BufReadTest(buf, -1, 16);
    free(buf);
    printf("\n-------- LmsMallocTest End --------\n");
}
static void LmsFreeTest(void)
{
    printf("\n-------- LmsFreeTest Start --------\n");
    char *buf = (char *)malloc(16);
    free(buf);
    BufReadTest(buf, 1, 1);
    free(buf);
    printf("\n-------- LmsFreeTest End --------\n");
}
int main(int argc, char * const * argv)
{
    printf("\n############### Lms Test start ###############\n");
    char *tmp = (char *)malloc(5000);
    LmsMallocTest();
    LmsFreeTest();
    printf("\n############### Lms Test End ###############\n");
}
```

### User-mode Verification<a name="section5665123516214"></a>

The output is as follows:

```
*****  Lite Memory Sanitizer Error Detected  *****
Heap buffer overflow error detected!
Illegal READ address at: [0x1f8b3edf]
Shadow memory address: [0x3d34d3ed : 6]  Shadow memory value: [2]
Accessable heap addr     0
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
*****  Lite Memory Sanitizer Error Detected End *****
Backtrace() returned 5 addresses
    #01: <LMS_ReportError+0x284>[0x4d6c] -> ./sample_usr_lms
    #02: <(null)+0x2004074>[0x4074] -> ./sample_usr_lms
    #03: <(null)+0x2003714>[0x3714] -> ./sample_usr_lms
    #04: <main+0x40>[0x363c] -> ./sample_usr_lms
    #05: <(null)+0x1f856f30>[0x56f30] -> /lib/libc.so
-------- LMS_malloc_test End --------
*****  Lite Memory Sanitizer Error Detected  *****
Use after free error detected!
Illegal Double free address at: [0x1f8b3ee0]
Shadow memory address: [0x3d34d3ee : 0]  Shadow memory value: [3]
Accessable heap addr     0
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
*****  Lite Memory Sanitizer Error Detected End *****
Backtrace() returned 5 addresses
    #01: <LMS_ReportError+0x284>[0x4d6c] -> ./sample_usr_lms
    #02: <LMS_free+0xcc>[0x5548] -> ./sample_usr_lms
    #03: <(null)+0x2003fc4>[0x3fc4] -> ./sample_usr_lms
    #04: <main+0x68>[0x3664] -> ./sample_usr_lms
    #05: <(null)+0x1f856f30>[0x56f30] -> /lib/libc.so
-------- LMS_free_test End --------
```

The Backtrace output contains the names of the files where the addresses are located. You can locate the code line corresponding to the address in the related file.

