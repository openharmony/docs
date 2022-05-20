# Semaphore


## Basic Concepts<a name="section1577111168131"></a>

Semaphore is a mechanism for implementing inter-task communication. It implements synchronization between tasks or exclusive access to shared resources.

In the data structure of a semaphore, there is a value indicating the number of shared resources available. The value can be:

-   **0**: The semaphore is unavailable. Tasks waiting for the semaphore may exist.
-   Positive number: The semaphore is available.

The semaphore for exclusive access is different from the semaphore for synchronization:

-   Semaphore used for exclusive access: The initial semaphore counter value \(non-zero\) indicates the number of shared resources available. The semaphore counter value must be acquired before a shared resource is used, and released when the resource is no longer required. When all shared resources are used, the semaphore counter is reduced to 0 and the tasks that need to obtain the semaphores will be blocked. This ensures exclusive access to shared resources. In addition, when the number of shared resources is 1, a binary semaphore \(similar to the mutex mechanism\) is recommended.
-   Semaphore used for synchronization: The initial semaphore counter value is  **0**. Task 1 cannot acquire the semaphore and is blocked. Task 1 enters Ready or Running state only when the semaphore is released by task 2 or an interrupt. In this way, task synchronization is implemented.

## Working Principles<a name="section118423019134"></a>

**Semaphore Control Block**

```
/**
 * Data structure of the semaphore control block
 */
typedef struct {
    UINT16            semStat;          /* Semaphore status */
    UINT16            semType;          /* Semaphore type*/
    UINT16            semCount;         /* Semaphore count*/
    UINT16            semId;            /* Semaphore index*/
    LOS_DL_LIST       semList;          /* Mount the task blocked by the semaphore.*/
} LosSemCB;
```

**Working Principles**

Semaphore allows only a specified number of tasks to access a shared resource at a time. When the number of tasks accessing the resource reaches the limit, other tasks will be blocked until the semaphore is released.

-   Semaphore initialization

    The system allocates memory for the semaphores configured \(you can configure the number of semaphores using the  **LOSCFG\_BASE\_IPC\_SEM\_LIMIT**  macro\), initializes all semaphores to be unused semaphores, and adds them to a linked list for the system to use.

-   Semaphore creation

    The system obtains a semaphore from the linked list of unused semaphores and assigns an initial value to the semaphore.

-   Semaphore request

    If the counter value is greater than 0, the system allocates a semaphore, decreases the value by 1, and returns a success message. Otherwise, the system blocks the task and moves the task to the end of a task queue waiting for semaphores. The wait timeout period can be set.

-   Semaphore release

    When a semaphore is released, if there is no task waiting for it, the counter value is increased by 1. Otherwise, the first task in the wait queue is woken up.

-   Semaphore deletion

    The system sets a semaphore in use to unused state and inserts it to the linked list of unused semaphores.


The following figure illustrates the semaphore working mechanism.

**Figure  1**  Semaphore working mechanism for small systems<a name="fig467314634214"></a>  
![](figures/semaphore-working-mechanism-for-small-systems.png "semaphore-working-mechanism-for-small-systems")

## Development Guidelines<a name="section01419503131"></a>

### Available APIs<a name="section1232345431312"></a>

**Table  1**  Semaphore module APIs

<a name="table1415203765610"></a>
<table><thead align="left"><tr id="row134151837125611"><th class="cellrowborder" valign="top" width="12.85128512851285%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="29.8029802980298%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0415737175610"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p8866127195914"><a name="p8866127195914"></a><a name="p8866127195914"></a>Creating or deleting a semaphore</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p58621910185914"><a name="p58621910185914"></a><a name="p58621910185914"></a>LOS_SemCreate</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p48623102592"><a name="p48623102592"></a><a name="p48623102592"></a>Creates a semaphore and returns the semaphore ID.</p>
</td>
</tr>
<tr id="row1213865218584"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p20862510115911"><a name="p20862510115911"></a><a name="p20862510115911"></a>LOS_BinarySemCreate</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1886211011599"><a name="p1886211011599"></a><a name="p1886211011599"></a>Creates a binary semaphore. The maximum counter value is <strong id="b4125169919"><a name="b4125169919"></a><a name="b4125169919"></a>1</strong>.</p>
</td>
</tr>
<tr id="row3231257145813"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p38621410205919"><a name="p38621410205919"></a><a name="p38621410205919"></a>LOS_SemDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p586261085913"><a name="p586261085913"></a><a name="p586261085913"></a>Deletes a semaphore.</p>
</td>
</tr>
<tr id="row73651459105815"><td class="cellrowborder" rowspan="2" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p16927183515593"><a name="p16927183515593"></a><a name="p16927183515593"></a>Requesting or releasing a semaphore</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p955271555916"><a name="p955271555916"></a><a name="p955271555916"></a>LOS_SemPend</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p555221518598"><a name="p555221518598"></a><a name="p555221518598"></a>Requests a specified semaphore and sets the timeout period.</p>
</td>
</tr>
<tr id="row178321454145812"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17552101519596"><a name="p17552101519596"></a><a name="p17552101519596"></a>LOS_SemPost</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1555261595915"><a name="p1555261595915"></a><a name="p1555261595915"></a>Posts (releases) a semaphore.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section154261711141419"></a>

1.  Call  **LOS\_SemCreate**  to create a semaphore. To create a binary semaphore, call  **LOS\_BinarySemCreate**.
2.  Call  **LOS\_SemPend**  to request a semaphore.
3.  Call  **LOS\_SemPost**  to release a semaphore.
4.  Call  **LOS\_SemDelete**  to delete a semaphore.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>As interrupts cannot be blocked, semaphores cannot be requested in block mode for interrupts.

### Development Example<a name="section658135571417"></a>

### Example Description<a name="section125244411653"></a>

This example implements the following:

1.  Create a semaphore in task  **ExampleSem**  and lock task scheduling. Create two tasks  **ExampleSemTask1**  and  **ExampleSemTask2**  \(with higher priority\). Enable the two tasks to request the same semaphore. Unlock task scheduling. Enable task  **ExampleSem**  to enter sleep mode for 400 ticks. Release the semaphore in task  **ExampleSem**.
2.  Enable** ExampleSemTask2**  to enter sleep mode for 20 ticks after acquiring the semaphore. \(When  **ExampleSemTask2**  is delayed,  **ExampleSemTask1**  is woken up.\)
3.  Enable  **ExampleSemTask1**  to request the semaphore in scheduled block mode, with a wait timeout period of 10 ticks. \(Because the semaphore is still held by  **ExampleSemTask2**,  **ExampleSemTask1**  is suspended.  **ExampleSemTask1**  is woken up after 10 ticks.\) Enable  **ExampleSemTask1**  to request the semaphore in permanent block mode after it is woken up 10 ticks later. \(Because the semaphore is still held by  **ExampleSemTask2**,  **ExampleSemTask1**  is suspended.\)
4.  After 20 ticks,  **ExampleSemTask2**  is woken up and releases the semaphore.  **ExampleSemTask1**  acquires the semaphore and is scheduled to run. When  **ExampleSemTask1**  is complete, it releases the semaphore.
5.  Task  **ExampleSem**  is woken up after 400 ticks and deletes the semaphore.

### Sample Code<a name="section1742105514512"></a>

The sample code is as follows:

```
#include "los_sem.h"
#include "securec.h"

/* Task ID*/
static UINT32 g_testTaskId01;
static UINT32 g_testTaskId02;

/* Task priority */
#define TASK_PRIO_TEST  5

/* Semaphore structure ID*/ 
static UINT32 g_semId;

VOID ExampleSemTask1(VOID)
{
    UINT32 ret;

    printf("ExampleSemTask1 try get sem g_semId, timeout 10 ticks.\n");

    /* Request the semaphore in scheduled block mode, with a wait timeout period of 10 ticks.*/ 
    ret = LOS_SemPend(g_semId, 10);

    /* The semaphore is acquired.*/ 
    if (ret == LOS_OK) {
         LOS_SemPost(g_semId);
         return;
    }
    /* The semaphore is not acquired when the timeout period has expired.*/ 
    if (ret == LOS_ERRNO_SEM_TIMEOUT) {
        printf("ExampleSemTask1 timeout and try get sem g_semId wait forever.\n");

        /* Request the semaphore in permanent block mode.*/ 
        ret = LOS_SemPend(g_semId, LOS_WAIT_FOREVER);
        printf("ExampleSemTask1 wait_forever and get sem g_semId.\n");
        if (ret == LOS_OK) {
            LOS_SemPost(g_semId);
            return;
        }
    }
}

VOID ExampleSemTask2(VOID)
{
    UINT32 ret;
    printf("ExampleSemTask2 try get sem g_semId wait forever.\n");

    /* Request the semaphore in permanent block mode.*/ 
    ret = LOS_SemPend(g_semId, LOS_WAIT_FOREVER);

    if (ret == LOS_OK) {
        printf("ExampleSemTask2 get sem g_semId and then delay 20 ticks.\n");
    }

  /* Enable the task to enter sleep mode for 20 ticks.*/ 
    LOS_TaskDelay(20);

    printf("ExampleSemTask2 post sem g_semId.\n");
    /* Release the semaphore.*/ 
    LOS_SemPost(g_semId);
    return;
}

UINT32 ExampleSem(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S task1;
    TSK_INIT_PARAM_S task2;

   /* Create a semaphore.*/ 
    LOS_SemCreate(0, &g_semId);

    /* Lock task scheduling.*/
    LOS_TaskLock();

    /* Create task 1.*/
    (VOID)memset_s(&task1, sizeof(TSK_INIT_PARAM_S), 0, sizeof(TSK_INIT_PARAM_S));
    task1.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleSemTask1;
    task1.pcName       = "TestTask1";
    task1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task1.usTaskPrio   = TASK_PRIO_TEST;
    ret = LOS_TaskCreate(&g_testTaskId01, &task1);
    if (ret != LOS_OK) {
        printf("task1 create failed .\n");
        return LOS_NOK;
    }

    /* Create task 2.*/ 
    (VOID)memset_s(&task2, sizeof(TSK_INIT_PARAM_S), 0, sizeof(TSK_INIT_PARAM_S));
    task2.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleSemTask2;
    task2.pcName       = "TestTask2";
    task2.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task2.usTaskPrio   = (TASK_PRIO_TEST - 1);
    ret = LOS_TaskCreate(&g_testTaskId02, &task2);
    if (ret != LOS_OK) {
        printf("task2 create failed.\n");
        return LOS_NOK;
    }

    /* Unlock task scheduling.*/
    LOS_TaskUnlock();

    ret = LOS_SemPost(g_semId);

 /* Enable the task to enter sleep mode for 400 ticks.*/
    LOS_TaskDelay(400);

 /* Delete the semaphore. */
    LOS_SemDelete(g_semId);
    return LOS_OK;
}
```

### Verification<a name="section11297301617"></a>

The development is successful if the return result is as follows:

```
ExampleSemTask2 try get sem g_semId wait forever.
ExampleSemTask2 get sem g_semId and then delay 20 ticks.
ExampleSemTask1 try get sem g_semId, timeout 10 ticks.
ExampleSemTask1 timeout and try get sem g_semId wait forever.
ExampleSemTask2 post sem g_semId.
ExampleSemTask1 wait_forever and get sem g_semId.
```

