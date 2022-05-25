# Mutex

## Basic Concepts

A mutual exclusion \(mutex\) is a special binary semaphore used for exclusive access to shared resources.

A mutex can be unlocked or locked. When a mutex is held by a task, the mutex is locked and the task obtains the ownership of the mutex. When the task releases the mutex, the mutex is unlocked and the task will lose the ownership of the mutex. When a task holds a mutex, other tasks cannot unlock or hold the mutex.

In an environment where multiple tasks compete for shared resources, the mutex can protect the shared resources via exclusive access. In addition, the mutex can prevent semaphore priority inversion, which occurs when a low-priority task holds a semaphore but a high-priority task has to wait until the low-priority task releases it.

## Working Principles<a name="section115161649726"></a>

In a multi-task environment, multiple tasks may access the same shared resources. However, certain shared resources are not shared, and can only be accessed exclusively by tasks. A mutex can be used to address this issue.

When non-shared resources are accessed by a task, the mutex is locked. Other tasks will be blocked until the mutex is released by the task. The mutex allows only one task to access the shared resources at a time, ensuring integrity of operations on the shared resources.

**Figure  1**  Mutex working mechanism for mini systems
![](figures/mutex-working-mechanism-for-mini-systems.png "mutex-working-mechanism-for-mini-systems")

## Available APIs

**Table  1**  APIs of the mutex module

<a name="table37108292611"></a>
<table><thead align="left"><tr id="row8711112919610"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p3711102912617"><a name="p3711102912617"></a><a name="p3711102912617"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1671110293610"><a name="p1671110293610"></a><a name="p1671110293610"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p87114292617"><a name="p87114292617"></a><a name="p87114292617"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row37115291166"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1795312108911"><a name="p1795312108911"></a><a name="p1795312108911"></a>Creating or deleting a mutex</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1671120293611"><a name="p1671120293611"></a><a name="p1671120293611"></a>LOS_MuxCreate</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p171112291967"><a name="p171112291967"></a><a name="p171112291967"></a>Creates a mutex.</p>
</td>
</tr>
<tr id="row17711329268"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p071114291864"><a name="p071114291864"></a><a name="p071114291864"></a>LOS_MuxDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p137111129965"><a name="p137111129965"></a><a name="p137111129965"></a>Deletes the specified mutex.</p>
</td>
</tr>
<tr id="row5711192912616"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p86087143910"><a name="p86087143910"></a><a name="p86087143910"></a>Requesting or releasing a mutex</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1171112295614"><a name="p1171112295614"></a><a name="p1171112295614"></a>LOS_MuxPend</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1271110291969"><a name="p1271110291969"></a><a name="p1271110291969"></a>Requests the specified mutex.</p>
</td>
</tr>
<tr id="row1571162918615"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p57111229967"><a name="p57111229967"></a><a name="p57111229967"></a>LOS_MuxPost</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107118291660"><a name="p107118291660"></a><a name="p107118291660"></a>Releases the specified mutex.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop

The typical mutex development process is as follows: 

1.  Call  **LOS\_MuxCreate**  to create a mutex.
2.  Call  **LOS\_MuxPend**  to request a mutex.

    The following modes are available:

    -   Non-block mode: A task acquires the mutex if the requested mutex is not held by any task or the task holding the mutex is the same as the task requesting the mutex.
    -   Permanent block mode: A task acquires the mutex if the requested mutex is not occupied. If the mutex is occupied, the task will be blocked and the task with the highest priority in the ready queue will be executed. The blocked task can be unlocked and executed only when the mutex is released.
    -   Scheduled block mode: A task acquires the mutex if the requested mutex is not occupied. If the mutex is occupied, the task will be blocked and the task with the highest priority in the ready queue will be executed. The blocked task can be executed only when the mutex is released within the specified timeout period or when the specified timeout period expires.

3.  Call  **LOS\_MuxPost**  to release a mutex.
    -   If tasks are blocked by the specified mutex, the task with a higher priority will be unblocked when the mutex is released. The unblocked task changes to the Ready state and is scheduled.
    -   If no task is blocked by the specified mutex, the mutex is released successfully.

4.  Call  **LOS\_MuxDelete**  to delete a mutex.

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/> 
>-   Two tasks cannot lock the same mutex. If a task attempts to lock a mutex held by another task, the task will be blocked until the mutex is unclocked.
>-   Mutexes cannot be used in the interrupt service program.
>-   When using the LiteOS-M kernel, OpenHarmony must ensure real-time task scheduling and avoid long-time task blocking. Therefore, a mutex must be released as soon as possible after use.
>-   When a mutex is held by a task, the task priority cannot be changed by using APIs such as  **LOS\_TaskPriSet**.

## Development Example

### Example Description

This example implements the following:

1.  Create the  **Example\_TaskEntry**  task. In this task, create a mutex to lock task scheduling, and create two tasks  **Example\_MutexTask1**  \(with a lower priority\) and  **Example\_MutexTask2**  \(with a higher priority\) to unlock task scheduling.
2.  When being scheduled,  **Example\_MutexTask2**  requests a mutex in permanent block mode. After acquiring the mutex,  **Example\_MutexTask2**  enters the sleep mode for 100 ticks.  **Example\_MutexTask2**  is suspended, and  **Example\_MutexTask1**  is woken up.
3.  **Example\_MutexTask1**  requests a mutex in scheduled block mode, and waits for 10 ticks. Because the mutex is still held by  **Example\_MutexTask2**,  **Example\_MutexTask1**  is suspended. After 10 ticks,  **Example\_MutexTask1**  is woken up and attempts to request a mutex in permanent block mode.  **Example\_MutexTask1**  is suspended because the mutex is still held by  **Example\_MutexTask2**.
4.  After 100 ticks,  **Example\_MutexTask2**  is woken up and releases the mutex, and then  **Example\_MutexTask1**  is woken up.  **Example\_MutexTask1**  acquires the mutex and then releases the mutex. At last, the mutex is deleted.

### Sample Code

The sample code is as follows:

```
#include <string.h>
#include "los_mux.h"

/* Mutex handler ID*/
UINT32 g_testMux;
/* Task ID*/
UINT32 g_testTaskId01;
UINT32 g_testTaskId02;

VOID Example_MutexTask1(VOID)
{
    UINT32 ret;

    printf("task1 try to get  mutex, wait 10 ticks.\n");
    /* Request a mutex. */
    ret = LOS_MuxPend(g_testMux, 10);

    if (ret == LOS_OK) {
        printf("task1 get mutex g_testMux.\n");
         /*Release the mutex. */
        LOS_MuxPost(g_testMux);
        return;
    } 
    if (ret == LOS_ERRNO_MUX_TIMEOUT ) {
            printf("task1 timeout and try to get mutex, wait forever.\n");
            /* Request a mutex. */
            ret = LOS_MuxPend(g_testMux, LOS_WAIT_FOREVER);
            if (ret == LOS_OK) {
                printf("task1 wait forever, get mutex g_testMux.\n");
                /*Release the mutex. */
                LOS_MuxPost(g_testMux);
                /* Delete the mutex. */
                LOS_MuxDelete(g_testMux);
                printf("task1 post and delete mutex g_testMux.\n");
                return;
            }
    }
    return;
}

VOID Example_MutexTask2(VOID)
{
    printf("task2 try to get  mutex, wait forever.\n");
    /* Request a mutex. */
    (VOID)LOS_MuxPend(g_testMux, LOS_WAIT_FOREVER);

    printf("task2 get mutex g_testMux and suspend 100 ticks.\n");

     /* Enable the task to enter sleep mode for 100 ticks. */
    LOS_TaskDelay(100);

    printf("task2 resumed and post the g_testMux\n");
    /* Release the mutex. */
    LOS_MuxPost(g_testMux);
    return;
}

UINT32 Example_TaskEntry(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S task1;
    TSK_INIT_PARAM_S task2;

    /* Create a mutex. */
    LOS_MuxCreate(&g_testMux);

    /* Lock task scheduling. */
    LOS_TaskLock();

    /* Create task 1. */
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

    /* Create task 2. */
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

    /* Unlock task scheduling. */
    LOS_TaskUnlock();

    return LOS_OK;
}
```

### Verification

The development is successful if the return result is as follows:

```
task2 try to get  mutex, wait forever.
task2 get mutex g_testMux and suspend 100 ticks.
task1 try to get  mutex, wait 10 ticks.
task1 timeout and try to get mutex, wait forever.
task2 resumed and post the g_testMux
task1 wait forever, get mutex g_testMux.
task1 post and delete mutex g_testMux.
```

