# Semaphore


## Basic Concepts

Semaphore is a mechanism for implementing communication between tasks. It implements synchronization between tasks or exclusive access to shared resources.

In the data structure of a semaphore, there is usually a counter value indicating the available resources. The counter value can be:

- **0**: The semaphore is unavailable. In this case, tasks waiting for the semaphore may exist.

- Positive number: The semaphore is available.

Semaphores can be used to solve a problem of mutual exclusion or process synchronization. The usage of the counter value varies with the function of the semaphore.

- If the semaphore is used to solve a problem of mutual exclusion, the counter value indicates the number of units of the shared resources available and its initial value cannot be **0**. The semaphore must be acquired before the shared resource is used, and released after the resource is used. When all shared resources are used, the semaphore counter is reduced to **0** and the tasks that need to obtain the semaphores will be blocked. This ensures exclusive access to shared resources. In addition, when the number of shared resources is **1**, a binary semaphore (similar to the mutex mechanism) is recommended.

- If the semaphore is used to solve a problem of process synchronization, the initial semaphore counter value is **0**. Task 1 cannot acquire the semaphore and is blocked. Task 1 enters Ready or Running state only when the semaphore is released by task 2 or an interrupt. In this way, task synchronization is implemented.


## Working Principles


### Semaphore Control Block


```
/**
  * Data structure of the semaphore control block
 */
typedef struct {
    UINT16            semStat;          /* Semaphore status */
    UINT16            semType;          /* Semaphore type */
    UINT16            semCount;         /* Semaphore count */
    UINT16            semId;            /* Semaphore index */
    LOS_DL_LIST       semList;          /* Insert the task blocked by the semaphore to the DL list. */
} LosSemCB;
```


### Working Principles

Initializing semaphores: Request memory for the semaphores configured (the number of semaphores can be configured in the **LOSCFG_BASE_IPC_SEM_LIMIT** macro), set all semaphores to the unused state, and add them to the linked list for unused semaphores.

Creating a semaphore: Obtain a semaphore from the linked list for unused semaphores and set its initial value.

Semaphore request: If the counter value is greater than 0, the system allocates a semaphore, decreases the value by 1, and returns a success message. Otherwise, the system blocks the task and adds the task to the end of a task queue waiting for semaphores. The wait timeout period can be set.

When a semaphore is released, if there is no task waiting for it, the counter is increased by 1. Otherwise, the first task in the wait queue is woken up.

Semaphore deletion: The system sets a semaphore in use to the unused state and inserts it to the linked list of unused semaphores.

A semaphore places a limit on the number of tasks accessing the shared resource concurrently. When the number of tasks accessing the shared resource reaches the maximum, other tasks that attempt to obtain the resource are blocked until a semaphore is released.

**Figure 1** Semaphore working mechanism for the mini system
![](figures/semaphore-working-mechanism-for-mini-systems.png "semaphore-working-mechanism-for-mini-systems")


## Available APIs

| Category| Description|
| -------- | -------- |
| Creating or deleting a semaphore| **LOS_SemCreate**: creates a semaphore and returns the semaphore ID.<br>**LOS_BinarySemCreate**: creates a binary semaphore. The maximum count value is **1**.<br>**LOS_SemDelete**: deletes a semaphore.|
| Requesting or releasing a semaphore| **LOS_SemPend**: requests a semaphore and sets the timeout period.<br>**LOS_SemPost**: releases a semaphore.|


## How to Develop

1. Call **LOS_SemCreate** to create a semaphore. To create a binary semaphore, call **LOS_BinarySemCreate**.

2. Call **LOS_SemPend** to request a semaphore.

3. Call **LOS_SemPost** to release a semaphore.

4. Call **LOS_SemDelete** to delete a semaphore.


> **NOTE**<br>
> As interrupts cannot be blocked, semaphores cannot be requested in block mode for interrupts.


## Development Example


### Example Description

This example implements the following:

1. Create a semaphore for the **ExampleSem** task, and lock task scheduling. Create two tasks **ExampleSemTask1** and **ExampleSemTask2**. The priority of **ExampleSemTask2** is higher than that of **ExampleSemTask1**. **ExampleSemTask1** and **ExampleSemTask2** apply for the same semaphore. Make **ExampleSemTask2** sleep for 20 ticks after acquiring the semaphore. Make **ExampleSemTask1** to apply for the semaphore with a timeout period of 10 ticks. If **ExampleSemTask1** still fails to acquire the semaphore after 10 ticks, **ExampleSemTask1** will wait until a semaphore is acquired. Unlock task scheduling. **ExampleSemTask1** and **ExampleSemTask2** are blocked and attempt to acquire a semaphore. The **ExampleSem** task releases the semaphore.

2. **ExampleSemTask2** (which has the higher priority) acquires the semaphore and starts to sleep for 20 ticks. In this case, **ExampleSemTask1** is woken up.

3. **ExampleSemTask1** requests a semaphore with a timeout period of 10 ticks. During this period, the semaphore is still held by **ExampleSemTask2**, therefore, **ExampleSemTask1** is suspended. After 10 ticks, **ExampleSemTask1** is woken up and waits permanently to acquire a semaphore. **ExampleSemTask1** is suspended.

4. After 20 ticks, **ExampleSemTask2** is woken up and releases the semaphore. **ExampleSemTask1** acquires the semaphore and is scheduled to run. When **ExampleSemTask1** is complete, it releases the semaphore.

5. After 400 ticks, **ExampleSem** is woken up and deletes the semaphore.


### Sample Code

The sample code is as follows:

The sample code is compiled and verified in **./kernel/liteos_m/testsuites/src/osTest.c**. Call **ExampleSem** in **TestTaskEntry**.


```
#include "los_sem.h"

/* Semaphore structure ID */
static UINT32 g_semId;

VOID ExampleSemTask1(VOID)
{
    UINT32 ret;

    printf("ExampleSemTask1 try get sem g_semId, timeout 10 ticks.\n");
    /* Request the semaphore in scheduled block mode, with a wait timeout period of 10 ticks. */
    ret = LOS_SemPend(g_semId, 10);
    /* The semaphore is acquired. */
    if (ret == LOS_OK) {
         LOS_SemPost(g_semId);
         return;
    }
    
    /* The semaphore is not acquired when the timeout period has expired. */
    if (ret == LOS_ERRNO_SEM_TIMEOUT) {
        printf("ExampleSemTask1 timeout and try get sem g_semId wait forever.\n");
        /* Request the semaphore in permanent block mode. */
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

    /* Request the semaphore in permanent block mode. */
    ret = LOS_SemPend(g_semId, LOS_WAIT_FOREVER);
    if (ret == LOS_OK) {
        printf("ExampleSemTask2 get sem g_semId and then delay 20 ticks.\n");
    }

    /* Enable the task to enter sleep mode for 20 ticks. */
    LOS_TaskDelay(20);
    printf("ExampleSemTask2 post sem g_semId.\n");

    /* Release the semaphore. */
    LOS_SemPost(g_semId);
    return;
}

UINT32 ExampleSem(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S task1 = { 0 };
    TSK_INIT_PARAM_S task2 = { 0 };
    UINT32 taskId1;
    UINT32 taskId2;

   /* Create a semaphore. */
    LOS_SemCreate(0, &g_semId);

    /* Lock task scheduling. */
    LOS_TaskLock();

    /* Create task 1. */
    task1.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleSemTask1;
    task1.pcName       = "TestTask1";
    task1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task1.usTaskPrio   = 5;
    ret = LOS_TaskCreate(&taskId1, &task1);
    if (ret != LOS_OK) {
        printf("task1 create failed.\n");
        return LOS_NOK;
    }

    /* Create task 2. */
    task2.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleSemTask2;
    task2.pcName       = "TestTask2";
    task2.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task2.usTaskPrio   = 4;
    ret = LOS_TaskCreate(&taskId2, &task2);
    if (ret != LOS_OK) {
        printf("task2 create failed.\n");
        return LOS_NOK;
    }

    /* Unlock task scheduling. */
    LOS_TaskUnlock();

    ret = LOS_SemPost(g_semId);

     /* Enable the task to enter sleep mode for 400 ticks. */
    LOS_TaskDelay(400);

    /* Delete the semaphore. */
    LOS_SemDelete(g_semId);
    return LOS_OK;
}
```


### Verification

The development is successful if the return result is as follows:



```
ExampleSemTask2 try get sem g_semId wait forever.
ExampleSemTask1 try get sem g_semId, timeout 10 ticks.
ExampleSemTask2 get sem g_semId and then delay 20 ticks.
ExampleSemTask1 timeout and try get sem g_semId wait forever.
ExampleSemTask2 post sem g_semId.
ExampleSemTask1 wait_forever and get sem g_semId.
```
