# Task


## Basic Concepts

Tasks are the minimum running units that compete for system resources. They can use or wait to use CPUs and use system resources such as memory. They run independently from one another.

In the OpenHarmony kernel, a task represents a thread.

Tasks for the processes of the same priority in the OpenHarmony kernel are scheduled and run in a unified manner.

The tasks in the kernel use the preemptive scheduling mechanism, either round-robin (RR) scheduling or First In First Out (FIFO) scheduling.

Tasks are assigned 32 priorities, ranging from **0** (highest) to **31** (lowest).

In the same process, a higher-priority task can preempt resources of a lower-priority task. The lower-priority task can be scheduled only after the higher-priority task is blocked or terminated.

**Task States**

- Init: The task is being created.

- Ready: The task is in the Ready queue and waits for scheduling by the CPU.

- Running: The task is running.

- Blocked: The task is blocked and suspended. The Blocked states include pending (blocked due to lock, event, or semaphore issues), suspended (active pending), delay (blocked due to delays), and pendtime (blocked by waiting timeout of locks, events, or semaphores).

- Exit: The task is complete and waits for the parent task to reclaim its control block resources.

  **Figure 1** Task state transition

  ![](figures/task-state-transition.png "task-state-transition")

**Task State Transition**

- Init→Ready:
  When a task is created, the task obtains the control block and enters the Init state (initialization). After the initialization is complete, the task is inserted into the scheduling queue and enters the Ready state.

- Ready→Running:
  When a task switching is triggered, the task with the highest priority in the Ready queue is executed and enters the Running state. Then, this task is deleted from the Ready queue.

- Running→Blocked:
  When a running task is blocked (for example, is pended, delayed, or reading semaphores), its state changes from Running to Blocked. Then, a task switching is triggered to run the task with the highest priority in the Ready queue.

- Blocked→Ready:
  After the blocked task is restored (the task is restored, the delay times out, the semaphore reading times out, or the semaphore is read), the task is added to the Ready queue and will change from the Blocked state to the Ready state.

- Ready→Blocked:
  When a task in the Ready state is blocked (suspended), the task changes to the Blocked state and is deleted from the Ready queue. The blocked task will not be scheduled until it is recovered.

- Running→Ready:
  When a task with a higher priority is created or recovered, tasks will be scheduled. The task with the highest priority in the Ready queue changes to the Running state. The originally running task changes to the Ready state and is added to the Ready queue.

- Running→Exit:
  When a running task is complete, it changes to the Exit state. If the task has a detach attribute (set by **LOS_TASK_STATUS_DETACHED** in **los_task.h**), it will be destroyed directly.


## Working Principles

The OpenHarmony task management module provides the following functions: creating, delaying, suspending, and restoring tasks, locking and unlocking task scheduling, and querying task control block information by ID.

When a user creates a task, the system initializes the task stack and presets the context. The system places the task entry function in the corresponding position so that the function can be executed when the task enters the running state for the first time.


## Development Guidelines


### Available APIs

**Table 1** APIs for creating and deleting a task

| API            | Description                                                    |
| ------------------ | ------------------------------------------------------------ |
| LOS_TaskCreate     | Creates a task. If the priority of the created task is higher than that of the task in running and task scheduling is not locked, the task will be scheduled to run. |
| LOS_TaskCreateOnly | Creates a task and blocks it. The task will not be added to the Ready queue unless it is resumed.            |
| LOS_TaskDelete     | Deletes a task and reclaims the resources consumed by the task control block and task stack.        |

**Table 2** APIs for controlling task status

| API         | Description                                                    |
| --------------- | ------------------------------------------------------------ |
| LOS_TaskResume  | Resumes a suspended task.                                              |
| LOS_TaskSuspend | Suspends a task. The suspended task will be removed from the Ready queue.                |
| LOS_TaskJoin    | Blocks the current task until the specified task is complete, and reclaims its resources.              |
| LOS_TaskDetach  | Changes the task attribute from **joinable** to **detach**. When a task of the **detach** attribute is complete, the task control block resources will be automatically reclaimed.|
| LOS_TaskDelay   | Delays the current task for the specified time (number of ticks).            |
| LOS_TaskYield   | Moves the current task from the queue of the tasks with the same priority to the end of the Ready queue.|

**Table 3** APIs for task scheduling

| API              | Description                                                    |
| -------------------- | ------------------------------------------------------------ |
| LOS_TaskLock         | Locks task scheduling to prevent task switching.                                  |
| LOS_TaskUnlock       | Unlocks task scheduling. After that, the task lock count decrements by 1. If a task is locked multiple times, the task can be scheduled only when the number of locks is reduced to 0. |
| LOS_GetTaskScheduler | Obtains the scheduling policy of a task.                                      |
| LOS_SetTaskScheduler | Sets the scheduling parameters, including the priority and scheduling policy, for a task.                |
| LOS_Schedule         | Triggers active task scheduling.                                          |

**Table 4** APIs for obtaining task information

| API                  | Description                |
| ------------------------ | ------------------------ |
| LOS_CurTaskIDGet         | Obtains the ID of the current task.        |
| LOS_TaskInfoGet          | Obtains task information.      |
| LOS_GetSystemTaskMaximum | Obtains the maximum number of tasks supported by the system.|

**Table 5** APIs for managing task priorities

| API           | Description                      |
| ----------------- | ------------------------------ |
| LOS_CurTaskPriSet | Sets a priority for the current task.|
| LOS_TaskPriSet    | Sets a priority for a task.          |
| LOS_TaskPriGet    | Obtains the priority of a task.          |

**Table 6** APIs for setting CPU pinning

| API            | Description                                   |
| ------------------ | ------------------------------------------- |
| LOS_TaskCpuAffiSet | Binds a task to the specified CPU core. This API is used only in multi-core CPUs.|
| LOS_TaskCpuAffiGet | Obtains information about the core binding of a task. This API is used only in multi-core CPUs.     |



### How to Develop

The typical task development process is as follows:

1. Call **LOS_TaskCreate** to create a task.
   - Specify the execution entry function for the task.
   - Specifies the task name.
   - Specify the task stack size.
   - Specify the priority of the task.
   - Specify the task attribute, which can be **LOS_TASK_ATTR_JOINABLE** or **LOS_TASK_STATUS_DETACHED**.
   - Specify the task-core binding attribute for multi-core environment.

2. Run the service code to implement task scheduling.

3. Reclaim resources when the task is complete. If the task attribute is **LOS_TASK_STATUS_DETACHED**, the task resources are automatically reclaimed. If the task attribute is **LOS_TASK_ATTR_JOINABLE**, call **LOS_TaskJoin** to reclaim task resources. The default task attribute is **LOS_TASK_STATUS_DETACHED**.

> **NOTE**
> 
> - The kernel mode has the highest permission and can operate tasks in any process.
>
> - If a task is created after a user-mode process enters the kernel mode by a system call, the task belongs to a KProcess not a user-mode process.


### Development Example

The sample code is as follows. You can add the test function of the sample code to **TestTaskEntry** in **kernel/liteos_a/testsuites/kernel/src /osTest.c** for testing


```c
UINT32 g_taskLoID;
UINT32 g_taskHiID;
#define TSK_PRIOR_HI 4
#define TSK_PRIOR_LO 5
UINT32 ExampleTaskHi(VOID)
{
    UINT32 ret;
    PRINTK("Enter TaskHi Handler.\n");
    /* Delay the task for 2 ticks. The task is suspended, and the remaining task with the highest priority (g_taskLoID) will be executed. */
    ret = LOS_TaskDelay(2);
    if (ret != LOS_OK) {
        PRINTK("Delay Task Failed.\n");
        return LOS_NOK;
    }
    /* After 2 ticks elapse, the task is resumed and executed. */
    PRINTK("TaskHi LOS_TaskDelay Done.\n");
    /* Suspend the task. */
    ret = LOS_TaskSuspend(g_taskHiID);
    if (ret != LOS_OK) {
        PRINTK("Suspend TaskHi Failed.\n");
        return LOS_NOK;
    }
    PRINTK("TaskHi LOS_TaskResume Success.\n");
    return LOS_OK;
}

/* Entry function of the low-priority task. */
UINT32 ExampleTaskLo(VOID)
{
    UINT32 ret;
    PRINTK("Enter TaskLo Handler.\n");
    /* Delay the task for 2 ticks. The task is suspended, and the remaining task with the highest priority (background task) will be executed. */
    ret = LOS_TaskDelay(2);
    if (ret != LOS_OK) {
        PRINTK("Delay TaskLo Failed.\n");
        return LOS_NOK;
    }
    PRINTK("TaskHi LOS_TaskSuspend Success.\n");
    /* Resume the suspended task g_taskHiID. */
    ret = LOS_TaskResume(g_taskHiID);
    if (ret != LOS_OK) {
        PRINTK("Resume TaskHi Failed.\n");
        return LOS_NOK;
    }
    PRINTK("TaskHi LOS_TaskDelete Success.\n");
    return LOS_OK;
}
/* Create two tasks with different priorities in the task test entry function. */
UINT32 ExampleTaskCaseEntry(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S initParam = {0};

    /* Lock task scheduling. */
    LOS_TaskLock();
    PRINTK("LOS_TaskLock() Success!\n");
    /* Parameters used to initialize the high-priority task, the resources of which can be reclaimed by LOS_TaskJoin. */
    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleTaskHi;
    initParam.usTaskPrio = TSK_PRIOR_HI;
    initParam.pcName = "HIGH_NAME";
    initParam.uwStackSize = LOS_TASK_MIN_STACK_SIZE;
    initParam.uwResved   = LOS_TASK_ATTR_JOINABLE;

    /* Create a task with higher priority. The task will not be executed immediately after being created, because task scheduling is locked. */
    ret = LOS_TaskCreate(&g_taskHiID, &initParam);
    if (ret != LOS_OK) {
        LOS_TaskUnlock();
        PRINTK("ExampleTaskHi create Failed! ret=%d\n", ret);
        return LOS_NOK;
    }
    PRINTK("ExampleTaskHi create Success!\n");

    /* Parameters used to initialize the low-priority task, which will be automatically destroyed after the task is complete. */
    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleTaskLo;
    initParam.usTaskPrio = TSK_PRIOR_LO;
    initParam.pcName = "LOW_NAME";
    initParam.uwStackSize = LOS_TASK_MIN_STACK_SIZE;
    initParam.uwResved   = LOS_TASK_STATUS_DETACHED;

    /* Create a low-priority task. The task will not be executed immediately after being created, because task scheduling is locked. */
    ret = LOS_TaskCreate(&g_taskLoID, &initParam);
    if (ret!= LOS_OK) {
        LOS_TaskUnlock();
        PRINTK("ExampleTaskLo create Failed!\n");
        return LOS_NOK;
    }
    PRINTK("ExampleTaskLo create Success!\n");

    /* Unlock task scheduling. The task with the highest priority in the Ready queue will be executed. */
    LOS_TaskUnlock();
    ret = LOS_TaskJoin(g_taskHiID, NULL);
    if (ret != LOS_OK) {
        PRINTK("Join ExampleTaskHi Failed!\n");
    } else {
        PRINTK("Join ExampleTaskHi Success!\n");
    }
    while(1){};
    return LOS_OK;
}
```

The development is successful if the return result is as follows:


```
LOS_TaskLock() Success!
ExampleTaskHi create Success!
ExampleTaskLo create Success!
Enter TaskHi Handler.
Enter TaskLo Handler.
TaskHi LOS_TaskDelay Done.
TaskHi LOS_TaskSuspend Success.
TaskHi LOS_TaskResume Success.
TaskHi LOS_TaskDelete Success.
Join ExampleTaskHi Success!
```
