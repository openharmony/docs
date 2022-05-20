# Atomic Operation


## Basic Concepts

In an OS that supports multiple tasks, modifying data in a memory area requires three steps: read data, modify data, and write data. However, data in a memory area may be simultaneously accessed by multiple tasks. If the data modification is interrupted by another task, the execution result of the operation is unpredictable.

Although you can enable or disable interrupts to ensure that the multi-task execution results meet expectations, the system performance is affected.

The ARMv6 architecture has introduced the  **LDREX**  and  **STREX**  instructions to support more discreet non-blocking synchronization of the shared memory. The atomic operations implemented thereby can ensure that the "read-modify-write" operations on the same data will not be interrupted, that is, the operation atomicity is ensured.

## Working Principles

The OpenHarmony system has encapsulated the  **LDREX**  and  **STREX**  in the ARMv6 architecture to provide a set of atomic operation APIs.

-   LDREX Rx, \[Ry\]

    Reads the value in the memory and marks the exclusive access to the memory segment.

    -   Reads the 4-byte memory data pointed by the register  **Ry**  and saves the data to the  **Rx**  register.
    -   Adds an exclusive access flag to the memory area pointed by  **Ry**.

-   STREX Rf, Rx, \[Ry\]

    Checks whether the memory has an exclusive access flag. If yes, the system updates the memory value and clears the flag. If no, the memory is not updated.

    -   If there is an exclusive access flag, the system:
        -   Updates the  **Rx**  register value to the memory pointed to by the  **Ry**  register.
        -   Sets the  **Rf**  register to  **0**.

    -   If there is no exclusive access flag:
        -   The memory is not updated.
        -   The system sets the  **Rf**  register to  **1**.


-   Flag register
    -   If the flag register is  **0**, the system exits the loop and the atomic operation is complete.
    -   If the flag register is  **1**, the system continues the loop and performs the atomic operation again.


## Development Guidelines

### Available APIs

The following table describes the APIs available for the OpenHarmony LiteOS-A kernel atomic operation module. For more details about the APIs, see the API reference.

**Table  1**  Atomic operation APIs

<a name="table29217519171"></a>
<table><thead align="left"><tr id="row79375119172"><th class="cellrowborder" valign="top" width="21.21212121212121%" id="mcps1.2.4.1.1"><p id="p159375113174"><a name="p159375113174"></a><a name="p159375113174"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="33.39333933393339%" id="mcps1.2.4.1.2"><p id="p199385118173"><a name="p199385118173"></a><a name="p199385118173"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="45.3945394539454%" id="mcps1.2.4.1.3"><p id="p18937511175"><a name="p18937511175"></a><a name="p18937511175"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row159315151712"><td class="cellrowborder" rowspan="2" valign="top" width="21.21212121212121%" headers="mcps1.2.4.1.1 "><p id="p593135115176"><a name="p593135115176"></a><a name="p593135115176"></a>Read</p>
</td>
<td class="cellrowborder" valign="top" width="33.39333933393339%" headers="mcps1.2.4.1.2 "><p id="p1193651181714"><a name="p1193651181714"></a><a name="p1193651181714"></a>LOS_AtomicRead</p>
</td>
<td class="cellrowborder" valign="top" width="45.3945394539454%" headers="mcps1.2.4.1.3 "><p id="p09316512178"><a name="p09316512178"></a><a name="p09316512178"></a>Reads 32-bit atomic data.</p>
</td>
</tr>
<tr id="row1493151161719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p119395111718"><a name="p119395111718"></a><a name="p119395111718"></a>LOS_Atomic64Read</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p49311514178"><a name="p49311514178"></a><a name="p49311514178"></a>Reads 64-bit atomic data.</p>
</td>
</tr>
<tr id="row69365111712"><td class="cellrowborder" rowspan="2" valign="top" width="21.21212121212121%" headers="mcps1.2.4.1.1 "><p id="p199355111175"><a name="p199355111175"></a><a name="p199355111175"></a>Write</p>
</td>
<td class="cellrowborder" valign="top" width="33.39333933393339%" headers="mcps1.2.4.1.2 "><p id="p1693175191714"><a name="p1693175191714"></a><a name="p1693175191714"></a>LOS_AtomicSet</p>
</td>
<td class="cellrowborder" valign="top" width="45.3945394539454%" headers="mcps1.2.4.1.3 "><p id="p129320516173"><a name="p129320516173"></a><a name="p129320516173"></a>Sets 32-bit atomic data.</p>
</td>
</tr>
<tr id="row1593651111718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7944510176"><a name="p7944510176"></a><a name="p7944510176"></a>LOS_Atomic64Set</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p294115191713"><a name="p294115191713"></a><a name="p294115191713"></a>Sets 64-bit atomic data.</p>
</td>
</tr>
<tr id="row149495114177"><td class="cellrowborder" rowspan="6" valign="top" width="21.21212121212121%" headers="mcps1.2.4.1.1 "><p id="p1394165151718"><a name="p1394165151718"></a><a name="p1394165151718"></a>Add</p>
</td>
<td class="cellrowborder" valign="top" width="33.39333933393339%" headers="mcps1.2.4.1.2 "><p id="p494115112179"><a name="p494115112179"></a><a name="p494115112179"></a>LOS_AtomicAdd</p>
</td>
<td class="cellrowborder" valign="top" width="45.3945394539454%" headers="mcps1.2.4.1.3 "><p id="p1694155120174"><a name="p1694155120174"></a><a name="p1694155120174"></a>Adds 32-bit atomic data.</p>
</td>
</tr>
<tr id="row394651101719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p179435113171"><a name="p179435113171"></a><a name="p179435113171"></a>LOS_Atomic64Add</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p594851181718"><a name="p594851181718"></a><a name="p594851181718"></a>Adds 64-bit atomic data.</p>
</td>
</tr>
<tr id="row294185110171"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1834102212615"><a name="p1834102212615"></a><a name="p1834102212615"></a>LOS_AtomicInc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p129413519173"><a name="p129413519173"></a><a name="p129413519173"></a>Adds 1 to 32-bit atomic data.</p>
</td>
</tr>
<tr id="row1894175101713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1981302213264"><a name="p1981302213264"></a><a name="p1981302213264"></a>LOS_Atomic64Inc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p167671640113316"><a name="p167671640113316"></a><a name="p167671640113316"></a>Adds 1 to 64-bit atomic data.</p>
</td>
</tr>
<tr id="row12946512178"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1994051181716"><a name="p1994051181716"></a><a name="p1994051181716"></a>LOS_AtomicIncRet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p59414511172"><a name="p59414511172"></a><a name="p59414511172"></a>Adds 1 to 32-bit atomic data and returns the data.</p>
</td>
</tr>
<tr id="row1994551101712"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p129414519173"><a name="p129414519173"></a><a name="p129414519173"></a>LOS_Atomic64IncRet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1194951111713"><a name="p1194951111713"></a><a name="p1194951111713"></a>Adds 1 to 64-bit atomic data and returns the data.</p>
</td>
</tr>
<tr id="row1794451121719"><td class="cellrowborder" rowspan="6" valign="top" width="21.21212121212121%" headers="mcps1.2.4.1.1 "><p id="p179412517173"><a name="p179412517173"></a><a name="p179412517173"></a>Subtract</p>
</td>
<td class="cellrowborder" valign="top" width="33.39333933393339%" headers="mcps1.2.4.1.2 "><p id="p89495115176"><a name="p89495115176"></a><a name="p89495115176"></a>LOS_AtomicSub</p>
</td>
<td class="cellrowborder" valign="top" width="45.3945394539454%" headers="mcps1.2.4.1.3 "><p id="p18220416345"><a name="p18220416345"></a><a name="p18220416345"></a>Performs subtraction on 32-bit atomic data.</p>
</td>
</tr>
<tr id="row139485131718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1894195116176"><a name="p1894195116176"></a><a name="p1894195116176"></a>LOS_Atomic64Sub</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p20822124173415"><a name="p20822124173415"></a><a name="p20822124173415"></a>Performs subtraction on 64-bit atomic data.</p>
</td>
</tr>
<tr id="row209505110175"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7951051141713"><a name="p7951051141713"></a><a name="p7951051141713"></a>LOS_AtomicDec</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p382234117340"><a name="p382234117340"></a><a name="p382234117340"></a>Subtracts 1 from 32-bit atomic data.</p>
</td>
</tr>
<tr id="row995151171711"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p395151131715"><a name="p395151131715"></a><a name="p395151131715"></a>LOS_Atomic64Dec</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1982244117340"><a name="p1982244117340"></a><a name="p1982244117340"></a>Subtracts 1 from 64-bit atomic data.</p>
</td>
</tr>
<tr id="row895155117179"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p395155151719"><a name="p395155151719"></a><a name="p395155151719"></a>LOS_AtomicDecRet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p198222414349"><a name="p198222414349"></a><a name="p198222414349"></a>Subtracts 1 from 32-bit atomic data and returns the result.</p>
</td>
</tr>
<tr id="row59511518170"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1495125119175"><a name="p1495125119175"></a><a name="p1495125119175"></a>LOS_Atomic64DecRet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p198221841103419"><a name="p198221841103419"></a><a name="p198221841103419"></a>Subtracts 1 from 64-bit atomic data and returns the result.</p>
</td>
</tr>
<tr id="row159575131714"><td class="cellrowborder" rowspan="4" valign="top" width="21.21212121212121%" headers="mcps1.2.4.1.1 "><p id="p159585110177"><a name="p159585110177"></a><a name="p159585110177"></a>Swap</p>
</td>
<td class="cellrowborder" valign="top" width="33.39333933393339%" headers="mcps1.2.4.1.2 "><p id="p29515114174"><a name="p29515114174"></a><a name="p29515114174"></a>LOS_AtomicXchgByte</p>
</td>
<td class="cellrowborder" valign="top" width="45.3945394539454%" headers="mcps1.2.4.1.3 "><p id="p6956510177"><a name="p6956510177"></a><a name="p6956510177"></a>Swaps 8-bit memory data.</p>
</td>
</tr>
<tr id="row14951451111710"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p8952514173"><a name="p8952514173"></a><a name="p8952514173"></a>LOS_AtomicXchg16bits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p12334173143919"><a name="p12334173143919"></a><a name="p12334173143919"></a>Swaps 16-bit memory data.</p>
</td>
</tr>
<tr id="row595251131716"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1495145117171"><a name="p1495145117171"></a><a name="p1495145117171"></a>LOS_AtomicXchg32bits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p9951513173"><a name="p9951513173"></a><a name="p9951513173"></a>Swaps 32-bit memory data.</p>
</td>
</tr>
<tr id="row195165131718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18951151141717"><a name="p18951151141717"></a><a name="p18951151141717"></a>LOS_AtomicXchg64bits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p169685115172"><a name="p169685115172"></a><a name="p169685115172"></a>Swaps 64-bit memory data.</p>
</td>
</tr>
<tr id="row149616511175"><td class="cellrowborder" rowspan="4" valign="top" width="21.21212121212121%" headers="mcps1.2.4.1.1 "><p id="p49615120172"><a name="p49615120172"></a><a name="p49615120172"></a>Compare and swap</p>
</td>
<td class="cellrowborder" valign="top" width="33.39333933393339%" headers="mcps1.2.4.1.2 "><p id="p129605112171"><a name="p129605112171"></a><a name="p129605112171"></a>LOS_AtomicCmpXchgByte</p>
</td>
<td class="cellrowborder" valign="top" width="45.3945394539454%" headers="mcps1.2.4.1.3 "><p id="p6965510178"><a name="p6965510178"></a><a name="p6965510178"></a>Compares and swaps 8-bit memory data.</p>
</td>
</tr>
<tr id="row99605171713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p109675131711"><a name="p109675131711"></a><a name="p109675131711"></a>LOS_AtomicCmpXchg16bits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17961951191719"><a name="p17961951191719"></a><a name="p17961951191719"></a>Compares and swaps 16-bit memory data.</p>
</td>
</tr>
<tr id="row169614513177"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p49645115172"><a name="p49645115172"></a><a name="p49645115172"></a>LOS_AtomicCmpXchg32bits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p129611512175"><a name="p129611512175"></a><a name="p129611512175"></a>Compares and swaps 32-bit memory data.</p>
</td>
</tr>
<tr id="row696175110179"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16961051161715"><a name="p16961051161715"></a><a name="p16961051161715"></a>LOS_AtomicCmpXchg64bits</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1296205118179"><a name="p1296205118179"></a><a name="p1296205118179"></a>Compares and swaps 64-bit memory data.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop

When multiple tasks perform addition, subtraction, and swap operations on the same memory data, use atomic operations to ensure predictability of results.

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/> 
>Atomic operation APIs support only integer data.

### Development Example<a name="section8538651511"></a>

Example Description

Call the atomic operation APIs and observe the result.

1.  Create two tasks.
    -   Task 1: Call  **LOS\_AtomicInc**  to add the global variables 100 times.
    -   Task 2: Call  **LOS\_AtomicDec**  to subtract the global variables 100 times.

2.  After the subtasks are complete, print the values of the global variables in the main task.

**Sample Code**

The sample code is as follows:

```
#include "los_hwi.h"
#include "los_atomic.h"
#include "los_task.h"

UINT32 g_testTaskId01;
UINT32 g_testTaskId02;
Atomic g_sum;
Atomic g_count;

UINT32 Example_Atomic01(VOID)
{
    int i = 0;
    for(i = 0; i < 100; ++i) {
        LOS_AtomicInc(&g_sum);
    }

    LOS_AtomicInc(&g_count);
    return LOS_OK;
}

UINT32 Example_Atomic02(VOID)
{
    int i = 0;
    for(i = 0; i < 100; ++i) {
        LOS_AtomicDec(&g_sum);
    }

    LOS_AtomicInc(&g_count);
    return LOS_OK;
}

UINT32 Example_AtomicTaskEntry(VOID)
{
    TSK_INIT_PARAM_S stTask1={0};
    stTask1.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Atomic01;
    stTask1.pcName       = "TestAtomicTsk1";
    stTask1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    stTask1.usTaskPrio   = 4;
    stTask1.uwResved     = LOS_TASK_STATUS_DETACHED;

    TSK_INIT_PARAM_S stTask2={0};
    stTask2.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Atomic02;
    stTask2.pcName       = "TestAtomicTsk2";
    stTask2.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    stTask2.usTaskPrio   = 4;
    stTask2.uwResved     = LOS_TASK_STATUS_DETACHED;

    LOS_TaskLock();
    LOS_TaskCreate(&g_testTaskId01, &stTask1);
    LOS_TaskCreate(&g_testTaskId02, &stTask2);
    LOS_TaskUnlock();

    while(LOS_AtomicRead(&g_count) != 2);
    PRINTK("g_sum = %d\n", g_sum);

    return LOS_OK;
}
```

**Verification**

```
g_sum = 0
```

