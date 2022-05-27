# LMS

## Basic Concepts

Lite Memory Sanitizer \(LMS\) is a tool used to detect memory errors on a real-time basis. LMS can detect buffer overflow, Use-After-Free \(UAF\), and double free errors in real time, and notify the operating system immediately. Together with locating methods such as Backtrace, LMS can locate the code line that causes the memory error. It greatly improves the efficiency of locating memory errors.

The LMS module of the OpenHarmony LiteOS-M kernel provides the following functions:

-   Supports check of multiple memory pools.
-   Checks the memory allocated by  **LOS\_MemAlloc**,  **LOS\_MemAllocAlign**, and  **LOS\_MemRealloc**.
-   Checks the memory when bounds-checking functions are called \(enabled by default\).
-   Checks the memory when libc frequently accessed functions, including  **memset**,  **memcpy**,  **memmove**,  **strcat**,  **strcpy**,  **strncat**  and  **strncpy**, are called.

## Working Principles

LMS uses shadow memory mapping to mark the system memory state. There are three states:  **Accessible**,  **RedZone**, and  **Freed**. The shadow memory is located in the tail of the memory pool.

-   After memory is allocated from the heap, the shadow memory in the data area is set to the  **Accessible**  state, and the shadow memory in the head node area is set to the  **RedZone**  state.
-   When memory is released from the heap, the shadow memory of the released memory is set to the  **Freed**  state.
-   During code compilation, a function is inserted before the read/write instructions in the code to check the address validity. The tool checks the state value of the shadow memory that accesses the memory. If the shadow memory is in the  **RedZone**  statue, an overflow error will be reported. If the shadow memory is in the  **Freed**  state, a UAF error will be reported.
-   When memory is released, the tool checks the state value of the shadow memory at the released address. If the shadow memory is in the  **RedZone**  state, a double free error will be reported.

## Available APIs

The LMS module of the OpenHarmony LiteOS-M kernel provides the following APIs. For more details about the APIs, see the  [API](https://gitee.com/openharmony/kernel_liteos_m/blob/master/components/lms/los_lms.h)  reference.

**Table  1**  LMS module APIs

<a name="table15483333125018"></a>
<table><thead align="left"><tr id="row04831333145018"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p2968123815504"><a name="p2968123815504"></a><a name="p2968123815504"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p896843825020"><a name="p896843825020"></a><a name="p896843825020"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p10968123865011"><a name="p10968123865011"></a><a name="p10968123865011"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row12671943185014"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p926044310503"><a name="p926044310503"></a><a name="p926044310503"></a>Adding a memory pool to be checked</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1226094375013"><a name="p1226094375013"></a><a name="p1226094375013"></a>LOS_LmsCheckPoolAdd</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1226024365018"><a name="p1226024365018"></a><a name="p1226024365018"></a>Adds the address range of a memory pool to the LMS check linked list. LMS performs a validity check when the accessed address is within the linked list. In addition, <strong id="b126321851183511"><a name="b126321851183511"></a><a name="b126321851183511"></a>LOS_MemInit</strong> calls this API to add the initialized memory pool to the LMS check linked list by default.</p>
</td>
</tr>
<tr id="row4267104318501"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p926164395017"><a name="p926164395017"></a><a name="p926164395017"></a>Deleting a memory pool from the LMS check linked list</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p13261134310503"><a name="p13261134310503"></a><a name="p13261134310503"></a>LOS_LmsCheckPoolDel</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p62611438504"><a name="p62611438504"></a><a name="p62611438504"></a>Cancels the validity check on the specified memory pool.</p>
</td>
</tr>
<tr id="row1226794310500"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p2026154317502"><a name="p2026154317502"></a><a name="p2026154317502"></a>Protecting a specified memory chunk</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p5261643145019"><a name="p5261643145019"></a><a name="p5261643145019"></a>LOS_LmsAddrProtect</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p9261134365018"><a name="p9261134365018"></a><a name="p9261134365018"></a>Locks a memory chunk to prevent it from being read or written. Once the locked memory chunk is accessed, an error will be reported.</p>
</td>
</tr>
<tr id="row32662437507"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1261164325018"><a name="p1261164325018"></a><a name="p1261164325018"></a>Disabling protection of a specified memory chunk</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1426115437506"><a name="p1426115437506"></a><a name="p1426115437506"></a>LOS_LmsAddrDisableProtect</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p426194395019"><a name="p426194395019"></a><a name="p426194395019"></a>Unlocks a memory chunk to make it readable and writable.</p>
</td>
</tr>
</tbody>
</table>

## Development Guidelines

### How to Develop

The typical process for enabling LMS is as follows:

1.  Configure the macros related to the LMS module.

    Configure the LMS macro  **LOSCFG\_KERNEL\_LMS**, which is disabled by default. Run the  **make update\_config**  command in the  **kernel/liteos\_m**  directory, choose  **Kernel**, and set  **Enable Lite Memory Sanitizer**  to  **Yes**.

    <a name="table1475284717333"></a>
    <table><thead align="left"><tr id="row10752747163310"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p3575105253315"><a name="p3575105253315"></a><a name="p3575105253315"></a>Macro</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p1957565253310"><a name="p1957565253310"></a><a name="p1957565253310"></a>menuconfig Option</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p657510523332"><a name="p657510523332"></a><a name="p657510523332"></a>Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p157520521332"><a name="p157520521332"></a><a name="p157520521332"></a>Value</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row446814582334"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p645995893313"><a name="p645995893313"></a><a name="p645995893313"></a>LOSCFG_KERNEL_LMS</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p645916586337"><a name="p645916586337"></a><a name="p645916586337"></a>Enable Lms Feature</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p7459165883314"><a name="p7459165883314"></a><a name="p7459165883314"></a>Whether to enable LMS.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p1345916584332"><a name="p1345916584332"></a><a name="p1345916584332"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row846815810336"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p945915812332"><a name="p945915812332"></a><a name="p945915812332"></a>LOSCFG_LMS_MAX_RECORD_POOL_NUM</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p12459135823316"><a name="p12459135823316"></a><a name="p12459135823316"></a>Lms check pool max num</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p445975819335"><a name="p445975819335"></a><a name="p445975819335"></a>Maximum number of memory pools that can be checked by LMS.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p7459165812336"><a name="p7459165812336"></a><a name="p7459165812336"></a>INT</p>
    </td>
    </tr>
    <tr id="row74689584332"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p145913583333"><a name="p145913583333"></a><a name="p145913583333"></a>LOSCFG_LMS_LOAD_CHECK</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p1045985863318"><a name="p1045985863318"></a><a name="p1045985863318"></a>Enable lms read check</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p74591158183311"><a name="p74591158183311"></a><a name="p74591158183311"></a>Whether to enable LMS read check.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p144590588332"><a name="p144590588332"></a><a name="p144590588332"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row1146755819337"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p54591258163318"><a name="p54591258163318"></a><a name="p54591258163318"></a>LOSCFG_LMS_STORE_CHECK</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p645925814331"><a name="p645925814331"></a><a name="p645925814331"></a>Enable lms write check</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p1045918585334"><a name="p1045918585334"></a><a name="p1045918585334"></a>Whether to enable LMS write check.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p1745920587338"><a name="p1745920587338"></a><a name="p1745920587338"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row17467185818337"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p134594582336"><a name="p134594582336"></a><a name="p134594582336"></a>LOSCFG_LMS_CHECK_STRICT</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p1645925893319"><a name="p1645925893319"></a><a name="p1645925893319"></a>Enable lms strict check, byte-by-byte</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p7459258103311"><a name="p7459258103311"></a><a name="p7459258103311"></a>Whether to enable LMS byte-by-byte check.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p1745985814336"><a name="p1745985814336"></a><a name="p1745985814336"></a>YES/NO</p>
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

### Development Example

This example implements the following:

1.  Create a task for LMS.
2.  Construct a buffer overflow error and a UAF error.
3.  Add "-fsanitize=kernel-address", execute the compilation, and check the output.

### Sample Code

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
```

### Verification

The output is as follows:

```
######LmsTestOsmallocOverflow start ######
[ERR]*****  Kernel Address Sanitizer Error Detected Start *****
[ERR]Heap buffer overflow error detected
[ERR]Illegal READ address at: [0x4157a3c8]
[ERR]Shadow memory address: [0x4157be3c : 4]  Shadow memory value: [2]
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
[ERR]*****  Kernel Address Sanitizer Error Detected End *****
str[20]=0xffffffba
######LmsTestOsmallocOverflow stop ######
###### LmsTestUseAfterFree start ######
[ERR]*****  Kernel Address Sanitizer Error Detected Start *****
[ERR]Use after free error detected
[ERR]Illegal READ address at: [0x4157a3d4]
[ERR]Shadow memory address: [0x4157be3d : 2]  Shadow memory value: [3]
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
[ERR]*****  Kernel Address Sanitizer Error Detected End *****
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


