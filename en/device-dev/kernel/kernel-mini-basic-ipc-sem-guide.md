# Development Guidelines<a name="EN-US_TOPIC_0000001078876452"></a>

-   [Available APIs](#section158501652121514)
-   [How to Develop](#section783435801510)
-   [Development Example](#section460018317164)
    -   [Example Description](#section22061718111412)
    -   [Sample Code](#section1775922321416)
    -   [Verification](#section160404016213)


## Available APIs<a name="section158501652121514"></a>

<a name="table1078714915105"></a>
<table><thead align="left"><tr id="row1280518971010"><th class="cellrowborder" valign="top" width="20.1%" id="mcps1.1.4.1.1"><p id="p1380510912104"><a name="p1380510912104"></a><a name="p1380510912104"></a>Category</p>
</th>
<th class="cellrowborder" valign="top" width="20.52%" id="mcps1.1.4.1.2"><p id="p08051291106"><a name="p08051291106"></a><a name="p08051291106"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="59.38%" id="mcps1.1.4.1.3"><p id="p12805149151012"><a name="p12805149151012"></a><a name="p12805149151012"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row168052913104"><td class="cellrowborder" rowspan="3" valign="top" width="20.1%" headers="mcps1.1.4.1.1 "><p id="p180618915101"><a name="p180618915101"></a><a name="p180618915101"></a>Creating or deleting a semaphore</p>
</td>
<td class="cellrowborder" valign="top" width="20.52%" headers="mcps1.1.4.1.2 "><p id="p198061196105"><a name="p198061196105"></a><a name="p198061196105"></a>LOS_SemCreate</p>
</td>
<td class="cellrowborder" valign="top" width="59.38%" headers="mcps1.1.4.1.3 "><p id="p1980609121010"><a name="p1980609121010"></a><a name="p1980609121010"></a>Creates a semaphore and returns the semaphore ID.</p>
</td>
</tr>
<tr id="row4806990105"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p280620917109"><a name="p280620917109"></a><a name="p280620917109"></a>LOS_BinarySemCreate</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p780614919107"><a name="p780614919107"></a><a name="p780614919107"></a>Creates a binary semaphore. The maximum counter value is <strong id="b1669151163313"><a name="b1669151163313"></a><a name="b1669151163313"></a>1</strong>.</p>
</td>
</tr>
<tr id="row17806159151018"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p38067931012"><a name="p38067931012"></a><a name="p38067931012"></a>LOS_SemDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p168063941015"><a name="p168063941015"></a><a name="p168063941015"></a>Deletes a semaphore.</p>
</td>
</tr>
<tr id="row188061098102"><td class="cellrowborder" rowspan="2" valign="top" width="20.1%" headers="mcps1.1.4.1.1 "><p id="p5806179161014"><a name="p5806179161014"></a><a name="p5806179161014"></a>Requesting or releasing a semaphore</p>
</td>
<td class="cellrowborder" valign="top" width="20.52%" headers="mcps1.1.4.1.2 "><p id="p16806159201015"><a name="p16806159201015"></a><a name="p16806159201015"></a>LOS_SemPend</p>
</td>
<td class="cellrowborder" valign="top" width="59.38%" headers="mcps1.1.4.1.3 "><p id="p4806149191011"><a name="p4806149191011"></a><a name="p4806149191011"></a>Requests a specified semaphore and sets the timeout period.</p>
</td>
</tr>
<tr id="row4806199141019"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p280618913105"><a name="p280618913105"></a><a name="p280618913105"></a>LOS_SemPost</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p178061917109"><a name="p178061917109"></a><a name="p178061917109"></a>Posts (releases) a semaphore.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section783435801510"></a>

1.  Call  **LOS\_SemCreate**  to create a semaphore. To create a binary semaphore, call  **LOS\_BinarySemCreate**.
2.  Call  **LOS\_SemPend**  to request a semaphore.
3.  Call  **LOS\_SemPost**  to release a semaphore.
4.  Call  **LOS\_SemDelete**  to delete a semaphore.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>As interrupts cannot be blocked, semaphores cannot be requested in block mode for interrupts.

## Development Example<a name="section460018317164"></a>

### Example Description<a name="section22061718111412"></a>

This example implements the following:

1.  Create a semaphore in task  **ExampleSem**  and lock task scheduling. Create two tasks  **ExampleSemTask1**  and  **ExampleSemTask2**  \(with higher priority\). Enable the two tasks to request the same semaphore. Unlock task scheduling. Enable task  **ExampleSem**  to enter sleep mode for 400 ticks. Release the semaphore in task  **ExampleSem**.
2.  Enable** ExampleSemTask2**  to enter sleep mode for 20 ticks after acquiring the semaphore. \(When  **ExampleSemTask2**  is delayed,  **ExampleSemTask1**  is woken up.\)
3.  Enable  **ExampleSemTask1**  to request the semaphore in scheduled block mode, with a wait timeout period of 10 ticks. \(Because the semaphore is still held by  **ExampleSemTask2**,  **ExampleSemTask1**  is suspended.  **ExampleSemTask1**  is woken up after 10 ticks.\) Enable  **ExampleSemTask1**  to request the semaphore in permanent block mode after it is woken up 10 ticks later. \(Because the semaphore is still held by  **ExampleSemTask2**,  **ExampleSemTask1**  is suspended.\)** **
4.  After 20 ticks,  **ExampleSemTask2**  is woken up and releases the semaphore.  **ExampleSemTask1**  acquires the semaphore and is scheduled to run. When  **ExampleSemTask1**  is complete, it releases the semaphore.
5.  Task  **ExampleSem**  is woken up after 400 ticks and deletes the semaphore.

### Sample Code<a name="section1775922321416"></a>

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
        printf("task1 create failed.\n");
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

### Verification<a name="section160404016213"></a>

The development is successful if the return result is as follows:

```
ExampleSemTask2 try get sem g_semId wait forever.
ExampleSemTask2 get sem g_semId and then delay 20 ticks.
ExampleSemTask1 try get sem g_semId, timeout 10 ticks.

ExampleSemTask1 timeout and try get sem g_semId wait forever.
ExampleSemTask2 post sem g_semId.
ExampleSemTask1 wait_forever and get sem g_semId.
```

