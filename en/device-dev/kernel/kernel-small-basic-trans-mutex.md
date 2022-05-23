# Mutex



## Basic Concepts<a name="section85865329185"></a>

A mutual exclusion \(mutex\) is a special binary semaphore used for exclusive access to shared resources. When a task holds the mutex, the task obtains the ownership of the mutex. When the task releases the mutex, the task will lose the ownership of the mutex. When a task holds a mutex, other tasks cannot hold the mutex. In an environment where multiple tasks compete for shared resources, the mutex ensures exclusive access to the shared resources.

A mutex has three attributes: protocol attribute, priority upper limit attribute, and type attribute. The protocol attribute is used to handle a mutex requested by tasks of different priorities. The protocol attribute can be any of the following:

-   LOS\_MUX\_PRIO\_NONE

    Do not inherit or protect the priority of the task requesting the mutex.

-   LOS\_MUX\_PRIO\_INHERIT

    Inherits the priority of the task that requests the mutex. This is the default protocol attribute. When the mutex protocol attribute is set to this value: If a task with a higher priority is blocked because the mutex is already held by a task, the priority of the task holding the mutex will be backed up to the priority bitmap of the task control block, and then set to be the same as that of the task of a higher priority. When the task holding the mutex releases the mutex, its task priority is restored to its original value.

-   LOS\_MUX\_PRIO\_PROTECT

    Protects the priority of the task that requests the mutex. When the mutex protocol attribute is set to this value: If the priority of the task that requests the mutex is lower than the upper limit of the mutex priority, the task priority will be backed up to the priority bitmap of the task control block, and then set to the upper limit value of the mutex priority. When the mutex is released, the task priority is restored to its original value.


The type attribute of a mutex specifies whether to check for deadlocks and whether to support recursive holding of the mutex. The type attribute can be any of the following:

-   LOS\_MUX\_NORMAL

    Common mutex, which does not check for deadlocks. If a task repeatedly attempts to hold a mutex, the thread will be deadlocked. If the mutex type attribute is set to this value, a task cannot release a mutex held by another task or repeatedly release a mutex. Otherwise, unexpected results will be caused.

-   LOS\_MUX\_RECURSIVE

    Recursive mutex, which is the default attribute. If the type attribute of a mutex is set to this value, a task can hold the mutex for multiple times. Another task can hold this mutex only when the number of lock holding times is the same as the number of lock release times. However, any attempt to hold a mutex held by another task or attempt to release a mutex that has been released will return an error code.

-   LOS\_MUX\_ERRORCHECK

    Allows automatic check for deadlocks. When a mutex is set to this type, an error code will be returned if a task attempts to repeatedly hold the mutex, attempts to release the mutex held by another task, or attempts to release the mutex that has been released.


## Working Principles<a name="section8547454201819"></a>

In a multi-task environment, multiple tasks may access the same shared resource. However, certain shared resources are not shared, and can only be accessed exclusively by tasks. A mutex can be used to address this issue.

When non-shared resources are accessed by a task, the mutex is locked. Other tasks will be blocked until the mutex is released by the task. The mutex allows only one task to access the shared resources at a time, ensuring integrity of operations on the shared resources.

**Figure  1**  Mutex working mechanism for small systems<a name="fig16821181173811"></a>  
![](figures/mutex-working-mechanism-for-small-systems.png "mutex-working-mechanism-for-small-systems")

## Development Guidelines<a name="section2038861117194"></a>

### Available APIs<a name="section11168318131917"></a>

**Table  1**  Mutex module APIs

<a name="table37108292611"></a>
<table><thead align="left"><tr id="row8711112919610"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p3711102912617"><a name="p3711102912617"></a><a name="p3711102912617"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="33.31333133313331%" id="mcps1.2.4.1.2"><p id="p1671110293610"><a name="p1671110293610"></a><a name="p1671110293610"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.35333533353336%" id="mcps1.2.4.1.3"><p id="p87114292617"><a name="p87114292617"></a><a name="p87114292617"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row332716281313"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1795312108911"><a name="p1795312108911"></a><a name="p1795312108911"></a>Initializing or destroying a mutex</p>
</td>
<td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.2.4.1.2 "><p id="p1932716285312"><a name="p1932716285312"></a><a name="p1932716285312"></a>LOS_MuxInit</p>
</td>
<td class="cellrowborder" valign="top" width="33.35333533353336%" headers="mcps1.2.4.1.3 "><p id="p932762812319"><a name="p932762812319"></a><a name="p932762812319"></a>Initializes a mutex.</p>
</td>
</tr>
<tr id="row37115291166"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p127613211335"><a name="p127613211335"></a><a name="p127613211335"></a>LOS_MuxDestroy</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p137111129965"><a name="p137111129965"></a><a name="p137111129965"></a>Destroys the specified mutex.</p>
</td>
</tr>
<tr id="row17711329268"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p18125182815396"><a name="p18125182815396"></a><a name="p18125182815396"></a>Requesting or releasing a mutex</p>
</td>
<td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.2.4.1.2 "><p id="p215615953415"><a name="p215615953415"></a><a name="p215615953415"></a>LOS_MuxLock</p>
</td>
<td class="cellrowborder" valign="top" width="33.35333533353336%" headers="mcps1.2.4.1.3 "><p id="p20994162353515"><a name="p20994162353515"></a><a name="p20994162353515"></a>Requests the specified mutex.</p>
</td>
</tr>
<tr id="row5711192912616"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7974187183520"><a name="p7974187183520"></a><a name="p7974187183520"></a>LOS_MuxTrylock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1271110291969"><a name="p1271110291969"></a><a name="p1271110291969"></a>Attempts to request the specified mutex in non-block mode.</p>
</td>
</tr>
<tr id="row1571162918615"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p13021319143515"><a name="p13021319143515"></a><a name="p13021319143515"></a>LOS_MuxUnlock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107118291660"><a name="p107118291660"></a><a name="p107118291660"></a>Releases the specified mutex.</p>
</td>
</tr>
<tr id="row344193024114"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p16441730114110"><a name="p16441730114110"></a><a name="p16441730114110"></a>Verifying a mutex</p>
</td>
<td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.2.4.1.2 "><p id="p1544183074110"><a name="p1544183074110"></a><a name="p1544183074110"></a>LOS_MuxIsValid</p>
</td>
<td class="cellrowborder" valign="top" width="33.35333533353336%" headers="mcps1.2.4.1.3 "><p id="p3441193017416"><a name="p3441193017416"></a><a name="p3441193017416"></a>Checks whether the mutex release is valid.</p>
</td>
</tr>
<tr id="row1065116418421"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p2189182734211"><a name="p2189182734211"></a><a name="p2189182734211"></a>Initializing or destroying mutex attributes</p>
</td>
<td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.2.4.1.2 "><p id="p1565244144210"><a name="p1565244144210"></a><a name="p1565244144210"></a>LOS_MuxAttrInit</p>
</td>
<td class="cellrowborder" valign="top" width="33.35333533353336%" headers="mcps1.2.4.1.3 "><p id="p14652342426"><a name="p14652342426"></a><a name="p14652342426"></a>Initializes mutex attributes.</p>
</td>
</tr>
<tr id="row538718619427"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p538756104217"><a name="p538756104217"></a><a name="p538756104217"></a>LOS_MuxAttrDestroy</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p23875654210"><a name="p23875654210"></a><a name="p23875654210"></a>Destroys the specified mutex attributes.</p>
</td>
</tr>
<tr id="row8143848467"><td class="cellrowborder" rowspan="8" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p2926915154717"><a name="p2926915154717"></a><a name="p2926915154717"></a>Setting and obtaining mutex attributes</p>
</td>
<td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.2.4.1.2 "><p id="p171441842465"><a name="p171441842465"></a><a name="p171441842465"></a>LOS_MuxAttrGetType</p>
</td>
<td class="cellrowborder" valign="top" width="33.35333533353336%" headers="mcps1.2.4.1.3 "><p id="p151444418461"><a name="p151444418461"></a><a name="p151444418461"></a>Obtains the type attribute of a specified mutex.</p>
</td>
</tr>
<tr id="row99314413464"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p793218404613"><a name="p793218404613"></a><a name="p793218404613"></a>LOS_MuxAttrSetType</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p51371843194813"><a name="p51371843194813"></a><a name="p51371843194813"></a>Sets the type attribute of a specified mutex.</p>
</td>
</tr>
<tr id="row204470514615"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p13447115154614"><a name="p13447115154614"></a><a name="p13447115154614"></a>LOS_MuxAttrGetProtocol</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p20871044144720"><a name="p20871044144720"></a><a name="p20871044144720"></a>Obtains the protocol attribute of a specified mutex.</p>
</td>
</tr>
<tr id="row69051358465"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p10906165124617"><a name="p10906165124617"></a><a name="p10906165124617"></a>LOS_MuxAttrSetProtocol</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1690617554610"><a name="p1690617554610"></a><a name="p1690617554610"></a>Sets the protocol attribute of a specified mutex.</p>
</td>
</tr>
<tr id="row133571666467"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6357146154616"><a name="p6357146154616"></a><a name="p6357146154616"></a>LOS_MuxAttrGetPrioceiling</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p559511469478"><a name="p559511469478"></a><a name="p559511469478"></a>Obtains the priority upper limit attribute of a specified mutex.</p>
</td>
</tr>
<tr id="row5789065465"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1778916634614"><a name="p1778916634614"></a><a name="p1778916634614"></a>LOS_MuxAttrSetPrioceiling</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p16789126134614"><a name="p16789126134614"></a><a name="p16789126134614"></a>Sets the priority upper limit attribute of a specified mutex.</p>
</td>
</tr>
<tr id="row10251772469"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p199321752124718"><a name="p199321752124718"></a><a name="p199321752124718"></a>LOS_MuxGetPrioceiling</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1128349114718"><a name="p1128349114718"></a><a name="p1128349114718"></a>Obtains the mutex priority upper limit attribute.</p>
</td>
</tr>
<tr id="row197256714468"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p72518754614"><a name="p72518754614"></a><a name="p72518754614"></a>LOS_MuxSetPrioceiling</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p177254713460"><a name="p177254713460"></a><a name="p177254713460"></a>Sets the mutex priority upper limit attribute.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section4201191122116"></a>

The typical mutex development process is as follows: 

1. Call  **LOS\_MuxInit**  to initialize a mutex.

2. Call  **LOS\_MuxLock**  to request a mutex.

The following modes are available:

-   Non-block mode: A task acquires the mutex if the requested mutex is not held by any task or the task holding the mutex is the same as the task requesting the mutex.
-   Permanent block mode: A task acquires the mutex if the requested mutex is not occupied. If the mutex is occupied, the task will be blocked and the task with the highest priority in the ready queue will be executed. The blocked task can be unlocked and executed only when the mutex is released.
-   Scheduled block mode: A task acquires the mutex if the requested mutex is not occupied. If the mutex is occupied, the task will be blocked and the task with the highest priority in the ready queue will be executed. The blocked task can be executed only when the mutex is released within the specified timeout period or when the specified timeout period expires.

3. Call  **LOS\_MuxUnlock**  to release a mutex.

-   If tasks are blocked by the specified mutex, the task with a higher priority will be unblocked when the mutex is released. The unblocked task changes to the Ready state and is scheduled.
-   If no task is blocked by the specified mutex, the mutex is released successfully.

4. Call  **LOS\_MuxDestroy**  to destroy a mutex.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Two tasks cannot lock the same mutex. If a task attempts to lock a mutex held by another task, the task will be blocked until the mutex is unlocked.
>-   Mutexes cannot be used in the interrupt service program.
>-   When using the LiteOS-A kernel, the OpenHarmony must ensure real-time task scheduling and avoid long-time task blocking. Therefore, a mutex must be released as soon as possible after use.

### Development Example<a name="section10679328202117"></a>

Example Description

This example implements the following:

1.  Create a mutex in the  **Example\_TaskEntry**  task, and lock task scheduling. Create two tasks  **Example\_MutexTask1**  and  **Example\_MutexTask2**. and unlock task scheduling.
2.  When being scheduled,  **Example\_MutexTask2**  requests a mutex in permanent block mode. After acquiring the mutex,  **Example\_MutexTask2**  enters the sleep mode for 100 ticks.  **Example\_MutexTask2**  is suspended, and  **Example\_MutexTask1**  is woken up.
3.  **Example\_MutexTask1**  requests a mutex in scheduled block mode, and waits for 10 ticks. Because the mutex is still held by  **Example\_MutexTask2**,  **Example\_MutexTask1**  is suspended. After 10 ticks,  **Example\_MutexTask1**  is woken up and attempts to request a mutex in permanent block mode.  **Example\_MutexTask1**  is suspended because the mutex is still held by  **Example\_MutexTask2**.
4.  After 100 ticks,  **Example\_MutexTask2**  is woken up and releases the mutex, and then  **Example\_MutexTask1**  is woken up.  **Example\_MutexTask1**  acquires the mutex and then releases the mutex. At last, the mutex is deleted.

**Sample Code**

The sample code is as follows:

```
#include <string.h>
#include "los_mux.h"

/* Mutex */
LosMux g_testMux;
/* Task ID*/
UINT32 g_testTaskId01;
UINT32 g_testTaskId02;

VOID Example_MutexTask1(VOID)
{
    UINT32 ret;

    printf("task1 try to get mutex, wait 10 ticks.\n");
    /* Request a mutex.*/
    ret = LOS_MuxLock(&g_testMux, 10);

    if (ret == LOS_OK) {
        printf("task1 get mutex g_testMux.\n");
         /* Release the mutex.*/
        LOS_MuxUnlock(&g_testMux);
        return;
    } 
    if (ret == LOS_ETIMEDOUT ) {
            printf("task1 timeout and try to get mutex, wait forever.\n");
            /* Request a mutex.*/
            ret = LOS_MuxLock(&g_testMux, LOS_WAIT_FOREVER);
            if (ret == LOS_OK) {
                printf("task1 wait forever, get mutex g_testMux.\n");
                /*Release the mutex.*/
                LOS_MuxUnlock(&g_testMux);
                /* Delete the mutex. */
                LOS_MuxDestroy(&g_testMux);
                printf("task1 post and delete mutex g_testMux.\n");
                return;
            }
    }
    return;
}

VOID Example_MutexTask2(VOID)
{
    printf("task2 try to get mutex, wait forever.\n");
    /* Request a mutex.*/
    (VOID)LOS_MuxLock(&g_testMux, LOS_WAIT_FOREVER);

    printf("task2 get mutex g_testMux and suspend 100 ticks.\n");

     /* Enable the task to enter sleep mode for 100 ticks.*/
    LOS_TaskDelay(100);

    printf("task2 resumed and post the g_testMux\n");
    /* Release the mutex.*/
    LOS_MuxUnlock(&g_testMux);
    return;
}

UINT32 Example_MutexEntry(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S task1;
    TSK_INIT_PARAM_S task2;

    /* Initializes the mutex./
    LOS_MuxInit(&g_testMux, NULL);

    /* Lock task scheduling.*/
    LOS_TaskLock();

    /* Create task 1.*/
    memset(&task1, 0, sizeof(TSK_INIT_PARAM_S));
    task1.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_MutexTask1;
    task1.pcName       = "MutexTsk1";
    task1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task1.usTaskPrio   = 5;
    ret = LOS_TaskCreate(&g_testTaskId01, &task1);
    if (ret != LOS_OK) {
        printf("task1 create failed.\n");
        return LOS_NOK;
    }

    /* Create task 2.*/
    memset(&task2, 0, sizeof(TSK_INIT_PARAM_S));
    task2.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_MutexTask2;
    task2.pcName       = "MutexTsk2";
    task2.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task2.usTaskPrio   = 4;
    ret = LOS_TaskCreate(&g_testTaskId02, &task2);
    if (ret != LOS_OK) {
        printf("task2 create failed.\n");
        return LOS_NOK;
    }

    /* Unlock task scheduling.*/
    LOS_TaskUnlock();

    return LOS_OK;
}
```

**Verification**

The development is successful if the return result is as follows:

```
task1 try to get mutex, wait 10 ticks.
task2 try to get mutex, wait forever.
task2 get mutex g_testMux and suspend 100 ticks.
task1 timeout and try to get mutex, wait forever.
task2 resumed and post the g_testMux
task1 wait forever, get mutex g_testMux.
task1 post and delete mutex g_testMux.
```

