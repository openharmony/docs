# Task Management

## Basic Concepts

From the perspective of the operating system, tasks are the minimum running units that compete for system resources. They can use or wait for CPUs, use system resources such as memory, and run independently.

The task module of the OpenHarmony LiteOS-M provides multiple tasks and supports switching between tasks, helping users manage business process procedures. The task module has the following features:

-   Multiple tasks are supported.
-   A task represents a thread.
-   The preemptive scheduling mechanism is used for tasks. High-priority tasks can interrupt low-priority tasks. Low-priority tasks can be scheduled only after high-priority tasks are blocked or complete.
-   Time slice round-robin is used to schedule tasks with the same priority.
-   A total of 32 \(**0** to **31**\) priorities are defined. **0** is the highest priority, and **31** is the lowest.

### Task-related Concepts

**Task States**

A task has multiple states. After the system initialization is complete, the created tasks can compete for certain resources in the system according to the scheduling procedure regulated by the kernel.

A task can be in any of the following states:

-   Ready: The task is in the ready queue, waiting for execution by a CPU.
-   Running: The task is being executed.
-   Blocked: The task is not in the ready queue. The task may be suspended, delayed, waiting for a semaphore, waiting to read from or write into a queue, or reading from or writing into an event.
-   Dead: The task execution is complete and waiting for the system to reclaim resources.

**Task State Transitions**

**Figure 1** Task state transitions<a name="fig186971918162613"></a>  
![](figures/task-state-transitions.png "task-state-transitions")

The task transition process is as follows:

-   Ready → Running

    A task enters Ready state once created. When task switching occurs, the task with the highest priority in the Ready queue will be executed. The task being executed enters the Running state and is removed from the Ready queue.

-   Running → Blocked

    When a running task is blocked \(suspended, delayed, or reading semaphores\), it will be inserted to the blocked task queue and changes from the Running state to the Blocked state. Then, task switching is triggered to run the task with the highest priority in the Ready queue.

-   Blocked → Ready \(Blocked → Running\)

    When a blocked task is recovered \(for example, the task is resumed, the delay period or semaphore read period times out, or the task successfully reads a semaphore\), the task will be added to the Ready queue and change from the Blocked state to the Ready state. If the priority of the recovered task is higher than that of the running task, task switching will be triggered to run the recovered task. Then, the task changes from the Ready state to the Running state.

-   Ready → Blocked

    When a task in the Ready state is blocked \(suspended\), the task changes to the Blocked state and is deleted from the Ready queue. The blocked task will not be scheduled until it is recovered.

-   Running → Ready

    When a task with a higher priority is created or recovered, tasks will be scheduled. The task with the highest priority in the Ready queue changes to the Running state. The originally running task changes to the Ready state and remains in the Ready queue.

-   Running → Dead

    When a running task is complete, it changes to the Dead state. The Dead state includes normal exit state as the task is complete and the Invalid state. For example, if a task is complete but is not automatically deleted, the task is in the Invalid state.

-   Blocked → Dead

    If an API is called to delete a blocked task, the task state change from Blocked to Dead.


**Task ID**

You will receive a task ID after successfully creating a task. The task IDs are unique in the operating system. You can suspend, restore, or query tasks by task ID.

**Task Priority**

Tasks are executed based on their priority. When task switching occurs, the task with the highest priority in the Ready queue will be executed.

**Task Entry Function**

Function to be executed when a task is scheduled. This function is implemented by users and set in the task creation structure when a task is created.

**Task Stack**

An independent memory space for each task. The stack stores information such as local variables, registers, function parameters, and function return addresses.

**Task Context**

Resources, such as registers, used during the running of a task. When a task is suspended, other running tasks might modify the register values of the suspended task. If the original task context is not saved when task switching occurs, an unknown error may occur when the task is recovered. The context information of switched-out tasks is saved into their own task stacks so that the context information can be resumed along with tasks and the system can start from the interrupted code after the tasks are resumed.

**Task Control Block**

Each task has a task control block \(TCB\). A TCB contains task information, such as context stack pointer, state, priority, ID, name, and stack size. The TCB reflects the running status of a task.

**Task Switching**

Task switching involves actions, such as obtaining the task with the highest priority in the Ready queue, saving the context of the switched-out task, and restoring the context of the switched-in task.

### Task Running Mechanism<a name="section123321315152219"></a>

When a task is created, the system initializes the task stack and presets the context. The system places the task entry function in the corresponding position so that the function is executed when the task enters the running state for the first time.

## Available APIs

The following table describes APIs available for the OpenHarmony LiteOS-M task module. For more details about the APIs, see the API reference.

**Table 1** APIs of the task management module

| Category| API| Description|
| -------- | -------- | -------- |
| Creating or deleting a task| LOS_TaskCreateOnly | Creates a task and suspends the task to disable scheduling of the task. To enable scheduling of the task, call **LOS_TaskResume** to make the task enter the Ready state.|
|  | LOS_TaskCreate | Creates a task and places the task in the Ready state. If there is no task with a higher priority in the Ready queue, the task will be executed.|
|  | LOS_TaskDelete | Deletes a task.|
| Controlling task status| LOS_TaskResume | Resumes a suspended task to place it in the Ready state.|
|  | LOS_TaskSuspend | Suspends the specified task and performs task switching.|
|  | LOS_TaskJoin | Suspends this task till the specified task is complete and the task control block resources are reclaimed.|
| | LOS_TaskDetach | Changes the task attribute from **joinable** to **detach**. After the task of the **detach** attribute is complete, the task control block resources will be automatically reclaimed.|
|  | LOS_TaskDelay | Makes a task wait for a period of time (in ticks) and releases CPU resources. When the delay time expires, the task enters the Ready state again. The input parameter is the number of ticks.|
|  | LOS_Msleep | Converts the input number of milliseconds into number of ticks, and use the result to call **LOS_TaskDelay**.|
|  | LOS_TaskYield | Sets the time slice of the current task to **0** to release CPU resources and schedule the task with the highest priority in the Ready queue to run.|
| Controlling task scheduling| LOS_TaskLock | Locks task scheduling. However, tasks can still be interrupted.|
|  | LOS_TaskUnlock | Unlocks task scheduling.|
|  | LOS_Schedule | Triggers task scheduling|
| Controlling task priority| LOS_CurTaskPriSet | Sets the priority for the current task.|
|  | LOS_TaskPriSet | Sets the priority for a specified task.|
|  | LOS_TaskPriGet | Obtains the priority of a specified task.|
| Obtaining Job information| LOS_CurTaskIDGet | Obtains the ID of the current task.|
|  | LOS_NextTaskIDGet | Obtains the ID of the task with the highest priority in the Ready queue.|
|  | LOS_NewTaskIDGet | Same as **LOS_NextTaskIDGet**.|
|  | LOS_CurTaskNameGet | Obtains the name of the current task.|
|  | LOS_TaskNameGet | Obtains the name of a specified task.|
|  | LOS_TaskStatusGet | Obtains the state of a specified task.|
|  | LOS_TaskInfoGet | Obtains information about a specified task, including the task state, priority, stack size, stack pointer (SP), task entry function, and used stack space.|
|  | LOS_TaskIsRunning | Checks whether the task module has started scheduling.|
| Updating task information| LOS_TaskSwitchInfoGet | Obtains task switching information. The macro **LOSCFG_BASE_CORE_EXC_TSK_SWITCH** must be enabled.|
| Reclaiming task stack resources| LOS_TaskResRecycle | Reclaims all task stack resources.|


## How to Develop

The typical development process of the task module is as follows:

1.  Use **LOS\_TaskLock** to lock task scheduling and prevent high-priority tasks from being scheduled.
2.  Use **LOS\_TaskCreate** to create a task.
3.  Use **LOS\_TaskUnlock** to unlock task scheduling so that tasks can be scheduled by priority.
4.  Use **LOS\_TaskDelay** to delay a task.
5.  Use **LOS\_TaskSuspend** to suspend a task.
6.  Use **LOS\_TaskResume** to resume the suspended task.

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/> 
>-   Running idle tasks reclaims the TCBs and stacks in the to-be-recycled linked list.
>-   The task name is a pointer without memory space allocated. When setting the task name, do not assign the local variable address to the task name pointer.
>-   The task stack size is 8-byte aligned. Follow the "nothing more and nothing less" principle while determining the task stack size.
>-   A running task cannot be suspended if task scheduling is locked.
>-   Idle tasks and software timer tasks cannot be suspended or deleted.
>-   In an interrupt handler or when a task is locked, the operation of calling **LOS\_TaskDelay** fails.
>-   Locking task scheduling does not disable interrupts. Tasks can still be interrupted while task scheduling is locked.
>-   Locking task scheduling must be used together with unlocking task scheduling.
>-   Task scheduling may occur while a task priority is being set.
>-   The maximum number of tasks that can be set for the operating system is the total number of tasks of the operating system, not the number of tasks available to users. For example, if the system software timer occupies one more task resource, the number of task resources available to users decreases by one.
>-   **LOS\_CurTaskPriSet** and **LOS\_TaskPriSet** cannot be used in interrupts or used to modify the priorities of software timer tasks.
>-   If the task corresponding to the task ID sent to **LOS\_TaskPriGet** has not been created or the task ID exceeds the maximum number of tasks, **-1** will be returned.
>-   Resources such as a mutex or a semaphore allocated to a task must have been released before the task is deleted.

## Development Example

This example describes the priority-based task scheduling and use of task-related APIs, including creating, delaying, suspending, and resuming two tasks with different priorities, and locking/unlocking task scheduling. The sample code is as follows:

```
UINT32 g_taskHiId;
UINT32 g_taskLoId;
#define TSK_PRIOR_HI 4
#define TSK_PRIOR_LO 5

UINT32 Example_TaskHi(VOID)
{
    UINT32 ret;

    printf("Enter TaskHi Handler.\n");

    /* Delay the task for 100 ticks. The task is then suspended, and the remaining task with the highest priority (TaskLo) will be executed. */
    ret = LOS_TaskDelay(100);
    if (ret != LOS_OK) {
        printf("Delay TaskHi Failed.\n");
        return LOS_NOK;
    }

    /*After 100 ticks elapse, the task is resumed. */
    printf("TaskHi LOS_TaskDelay Done.\n");

    /* Suspend the task. */
    ret = LOS_TaskSuspend(g_taskHiId);
    if (ret != LOS_OK) {
        printf("Suspend TaskHi Failed.\n");
        return LOS_NOK;
    }
    printf("TaskHi LOS_TaskResume Success.\n");
    return ret;
}

/* Entry function of low-priority tasks */
UINT32 Example_TaskLo(VOID)
{
    UINT32 ret;

    printf("Enter TaskLo Handler.\n");

    /* Delay the task for 100 ticks. The task is then suspended, and the remaining task with the highest priority will be executed. */
    ret = LOS_TaskDelay(100);
    if (ret != LOS_OK) {
        printf("Delay TaskLo Failed.\n");
        return LOS_NOK;
    }

    printf("TaskHi LOS_TaskSuspend Success.\n");

    /* Resume the suspended task g_taskHiId. */
    ret = LOS_TaskResume(g_taskHiId);
    if (ret != LOS_OK) {
        printf("Resume TaskHi Failed.\n");
        return LOS_NOK;
    }
    return ret;
}

/* Task entry function used to create two tasks with different priorities */
UINT32 Example_TskCaseEntry(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S initParam;

    /* Lock task scheduling to prevent newly created tasks from being scheduled prior to this task due to higher priority. */
    LOS_TaskLock();

    printf("LOS_TaskLock() Success!\n");

    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_TaskHi;
    initParam.usTaskPrio = TSK_PRIOR_HI;
    initParam.pcName = "TaskHi";
    initParam.uwStackSize = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    initParam.uwResved = 0; /* Detach attributes. */

    /* Create a task with higher priority. The task will not be executed immediately after being created, because task scheduling is locked. */
    ret = LOS_TaskCreate(&g_taskHiId, &initParam);
    if (ret != LOS_OK) {
        LOS_TaskUnlock();

        printf("Example_TaskHi create Failed!\n");
        return LOS_NOK;
    }

    printf("Example_TaskHi create Success!\n");

    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_TaskLo;
    initParam.usTaskPrio = TSK_PRIOR_LO;
    initParam.pcName = "TaskLo";
    initParam.uwStackSize = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;

    /*Create a low-priority task. The task will not be executed immediately after being created, because task scheduling is locked. */
    ret = LOS_TaskCreate(&g_taskLoId, &initParam);
    if (ret != LOS_OK) {
        LOS_TaskUnlock();
        printf("Example_TaskLo create Failed!\n");
        return LOS_NOK;
    }

    printf("Example_TaskLo create Success!\n");

    /* Unlock task scheduling. The task with the highest priority in the Ready queue will be executed. */
    LOS_TaskUnlock();
    ret = LOS_TaskJoin(g_taskHiId, NULL);
    if (ret != LOS_OK) {
        printf("Join Example_TaskHi Failed!\n");
    } else {
        printf("Join Example_TaskHi Success!\n");
    }
    return LOS_OK;
}
```

### Verification

The development is successful if the return result is as follows:

```
LOS_TaskLock() Success!
Example_TaskHi create Success!
Example_TaskLo create Success!
Enter TaskHi Handler.
Enter TaskLo Handler.
TaskHi LOS_TaskDelay Done.
TaskHi LOS_TaskSuspend Success.
TaskHi LOS_TaskResume Success.
Join Example_TaskHi Success!
```
