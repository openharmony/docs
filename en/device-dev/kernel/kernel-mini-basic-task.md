# Task Management<a name="EN-US_TOPIC_0000001124066565"></a>

-   [Basic Concepts](#section1524821422111)
    -   [Task-related Concepts](#section1124425582117)
    -   [Task Running Mechanism](#section123321315152219)

-   [Available APIs](#section158501652121514)
-   [How to Develop](#section783435801510)
-   [Development Example](#section460018317164)
    -   [Verification](#section62921315208)


## Basic Concepts<a name="section1524821422111"></a>

From the perspective of the operating system, tasks are the minimum running units that compete for system resources. They can use or wait for CPUs, use system resources such as memory, and run independently.

The task module of the OpenHarmony LiteOS-M provides multiple tasks and supports switching between tasks, helping users manage business process procedures. The task module has the following features:

-   Multiple tasks are supported.
-   A task represents a thread.
-   The preemptive scheduling mechanism is used for tasks. High-priority tasks can interrupt low-priority tasks. Low-priority tasks can be scheduled only after high-priority tasks are blocked or complete.
-   Time slice round-robin is used to schedule tasks with the same priority.
-   A total of 32 \(**0**  to  **31**\) priorities are defined.  **0**  is the highest priority, and  **31**  is the lowest.

### Task-related Concepts<a name="section1124425582117"></a>

**Task States**

A task has multiple states. After the system initialization is complete, the created tasks can compete for certain resources in the system according to the scheduling procedure regulated by the kernel.

A task can be in any of the following states:

-   Ready: The task is in the ready queue, waiting for execution by a CPU.
-   Running: The task is being executed.
-   Blocked: The task is not in the ready queue. The task may be suspended, delayed, waiting for a semaphore, waiting to read from or write into a queue, or reading from or writing into an event.
-   Dead: The task execution is complete and waiting for the system to reclaim resources.

**Task State Transitions**

**Figure  1**  Task state transitions<a name="fig186971918162613"></a>  
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

## Available APIs<a name="section158501652121514"></a>

The following table describes APIs available for the OpenHarmony LiteOS-M task module. For more details about the APIs, see the API reference.

**Table  1**  APIs of the task management module

<a name="table14287183117205"></a>
<table><thead align="left"><tr id="row2287133115203"><th class="cellrowborder" valign="top" width="12.85128512851285%" id="mcps1.2.4.1.1"><p id="p6287103142013"><a name="p6287103142013"></a><a name="p6287103142013"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="29.8029802980298%" id="mcps1.2.4.1.2"><p id="p62871931152011"><a name="p62871931152011"></a><a name="p62871931152011"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p1328733110202"><a name="p1328733110202"></a><a name="p1328733110202"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4287183182010"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p6287831122018"><a name="p6287831122018"></a><a name="p6287831122018"></a>Creating or deleting a task</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p11287193111207"><a name="p11287193111207"></a><a name="p11287193111207"></a>LOS_TaskCreateOnly</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p14287173112013"><a name="p14287173112013"></a><a name="p14287173112013"></a>Creates a task and suspends the task to disable scheduling of the task. To enable scheduling of the task, call <strong id="b129220316444426"><a name="b129220316444426"></a><a name="b129220316444426"></a>LOS_TaskResume</strong> to make the task enter the Ready state.</p>
</td>
</tr>
<tr id="row13288113122019"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15288131122016"><a name="p15288131122016"></a><a name="p15288131122016"></a>LOS_TaskCreate</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p12886315207"><a name="p12886315207"></a><a name="p12886315207"></a>Creates a task and places the task in the Ready state. If there is no task with a higher priority in the Ready queue, the task will be executed.</p>
</td>
</tr>
<tr id="row10288123152019"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2288193132015"><a name="p2288193132015"></a><a name="p2288193132015"></a>LOS_TaskDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17288133172017"><a name="p17288133172017"></a><a name="p17288133172017"></a>Deletes the specified task.</p>
</td>
</tr>
<tr id="row10288143112201"><td class="cellrowborder" rowspan="6" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p92883313201"><a name="p92883313201"></a><a name="p92883313201"></a>Controlling task status</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p1328833112015"><a name="p1328833112015"></a><a name="p1328833112015"></a>LOS_TaskResume</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p228823192011"><a name="p228823192011"></a><a name="p228823192011"></a>Resumes a suspended task to place the task in the Ready state.</p>
</td>
</tr>
<tr id="row92884314208"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1328815311204"><a name="p1328815311204"></a><a name="p1328815311204"></a>LOS_TaskSuspend</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p628816315207"><a name="p628816315207"></a><a name="p628816315207"></a>Suspends the specified task and performs task switching.</p>
</td>
</tr>
<tr id="row1928893112015"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4288193142010"><a name="p4288193142010"></a><a name="p4288193142010"></a>LOS_TaskJoin</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p20288123172015"><a name="p20288123172015"></a><a name="p20288123172015"></a>Suspends this task till the specified task is complete and the task control block resources are reclaimed.</p>
</td>
</tr>
<tr id="row928853152014"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1728863114208"><a name="p1728863114208"></a><a name="p1728863114208"></a>LOS_TaskDelay</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p202881831192011"><a name="p202881831192011"></a><a name="p202881831192011"></a>Makes a task wait for a period of time (in ticks) and releases CPU resources. When the delay time expires, the task enters the Ready state again. The input parameter is the number of ticks.</p>
</td>
</tr>
<tr id="row1628873122011"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p128873119204"><a name="p128873119204"></a><a name="p128873119204"></a>LOS_Msleep</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p128803112012"><a name="p128803112012"></a><a name="p128803112012"></a>Converts the input parameter number of milliseconds into number of ticks, and use the result to call <strong id="b56235690044426"><a name="b56235690044426"></a><a name="b56235690044426"></a>LOS_TaskDelay</strong>.</p>
</td>
</tr>
<tr id="row142888310203"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1328853115203"><a name="p1328853115203"></a><a name="p1328853115203"></a>LOS_TaskYield</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1728893192018"><a name="p1728893192018"></a><a name="p1728893192018"></a>Sets the time slice of the current task to <strong id="b5591310044426"><a name="b5591310044426"></a><a name="b5591310044426"></a>0</strong> to release CPU resources and schedule the task with the highest priority in the Ready queue to run.</p>
</td>
</tr>
<tr id="row1228813117202"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p128814312206"><a name="p128814312206"></a><a name="p128814312206"></a>Control task scheduling</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p1028813115207"><a name="p1028813115207"></a><a name="p1028813115207"></a>LOS_TaskLock</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p328863117203"><a name="p328863117203"></a><a name="p328863117203"></a>Locks task scheduling. However, tasks can still be interrupted.</p>
</td>
</tr>
<tr id="row1728815310206"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15288331132013"><a name="p15288331132013"></a><a name="p15288331132013"></a>LOS_TaskUnlock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p3288731142017"><a name="p3288731142017"></a><a name="p3288731142017"></a>Unlocks task scheduling.</p>
</td>
</tr>
<tr id="row328817319204"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1128916312201"><a name="p1128916312201"></a><a name="p1128916312201"></a>LOS_Schedule</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p20289173112017"><a name="p20289173112017"></a><a name="p20289173112017"></a>Triggers task scheduling</p>
</td>
</tr>
<tr id="row172891531202015"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p14289123182010"><a name="p14289123182010"></a><a name="p14289123182010"></a>Controlling task priority</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p228933114208"><a name="p228933114208"></a><a name="p228933114208"></a>LOS_CurTaskPriSet</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p728993182020"><a name="p728993182020"></a><a name="p728993182020"></a>Sets the priority for the current task.</p>
</td>
</tr>
<tr id="row152891331122017"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18289113110209"><a name="p18289113110209"></a><a name="p18289113110209"></a>LOS_TaskPriSet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p20289163122017"><a name="p20289163122017"></a><a name="p20289163122017"></a>Sets the priority for a specified task.</p>
</td>
</tr>
<tr id="row1928912314205"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1128973112014"><a name="p1128973112014"></a><a name="p1128973112014"></a>LOS_TaskPriGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p228933119206"><a name="p228933119206"></a><a name="p228933119206"></a>Obtains the priority of a specified task.</p>
</td>
</tr>
<tr id="row10289113192017"><td class="cellrowborder" rowspan="8" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p128923116206"><a name="p128923116206"></a><a name="p128923116206"></a>Obtaining task information</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p132897312209"><a name="p132897312209"></a><a name="p132897312209"></a>LOS_CurTaskIDGet</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p15289031122015"><a name="p15289031122015"></a><a name="p15289031122015"></a>Obtains the ID of the current task.</p>
</td>
</tr>
<tr id="row16289123117202"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p13289153115207"><a name="p13289153115207"></a><a name="p13289153115207"></a>LOS_NextTaskIDGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p16289133142013"><a name="p16289133142013"></a><a name="p16289133142013"></a>Obtains the ID of the task with the highest priority in the Ready queue.</p>
</td>
</tr>
<tr id="row1728933119202"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1428915312205"><a name="p1428915312205"></a><a name="p1428915312205"></a>LOS_NewTaskIDGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p18289163192018"><a name="p18289163192018"></a><a name="p18289163192018"></a>Same as <strong id="b59459526844426"><a name="b59459526844426"></a><a name="b59459526844426"></a>LOS_NextTaskIDGet</strong>.</p>
</td>
</tr>
<tr id="row828953110201"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p192891831112015"><a name="p192891831112015"></a><a name="p192891831112015"></a>LOS_CurTaskNameGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p10289631132012"><a name="p10289631132012"></a><a name="p10289631132012"></a>Obtains the name of the current task.</p>
</td>
</tr>
<tr id="row1028943115207"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p628911316201"><a name="p628911316201"></a><a name="p628911316201"></a>LOS_TaskNameGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4289331142014"><a name="p4289331142014"></a><a name="p4289331142014"></a>Obtains the name of a specified task.</p>
</td>
</tr>
<tr id="row14289153142017"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1128963122020"><a name="p1128963122020"></a><a name="p1128963122020"></a>LOS_TaskStatusGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p19289153142013"><a name="p19289153142013"></a><a name="p19289153142013"></a>Obtains the state of a specified task.</p>
</td>
</tr>
<tr id="row1728915310209"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1290143113205"><a name="p1290143113205"></a><a name="p1290143113205"></a>LOS_TaskInfoGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p62901231112010"><a name="p62901231112010"></a><a name="p62901231112010"></a>Obtains information about a specified task, including the task state, priority, stack size, stack pointer (SP), task entry function, and used stack space.</p>
</td>
</tr>
<tr id="row1029053162016"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p529053113209"><a name="p529053113209"></a><a name="p529053113209"></a>LOS_TaskIsRunning</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1290113114206"><a name="p1290113114206"></a><a name="p1290113114206"></a>Checks whether the task module has started scheduling.</p>
</td>
</tr>
<tr id="row1529017317206"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p14290143162014"><a name="p14290143162014"></a><a name="p14290143162014"></a>Maintaining and testing task information</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p18290831112013"><a name="p18290831112013"></a><a name="p18290831112013"></a>LOS_TaskSwitchInfoGet</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p17290153116200"><a name="p17290153116200"></a><a name="p17290153116200"></a>Obtains task switching information. The macro <strong id="b125259128644426"><a name="b125259128644426"></a><a name="b125259128644426"></a>LOSCFG_BASE_CORE_EXC_TSK_SWITCH</strong> must be enabled.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section783435801510"></a>

The typical development process of the task module is as follows:

1.  Use  **LOS\_TaskLock**  to lock task scheduling and prevent high-priority tasks from being scheduled.
2.  Use  **LOS\_TaskCreate**  to create a task.
3.  Use  **LOS\_TaskUnlock**  to unlock task scheduling so that tasks can be scheduled by priority.
4.  Use  **LOS\_TaskDelay**  to delay a task.
5.  Use  **LOS\_TaskSuspend**  to suspend a task.
6.  Use  **LOS\_TaskResume**  to resume the suspended task.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Running idle tasks reclaims the TCBs and stacks in the to-be-recycled linked list.
>-   The task name is a pointer without memory space allocated. When setting the task name, do not assign the local variable address to the task name pointer.
>-   The task stack size is 8-byte aligned. Follow the "nothing more and nothing less" principle while determining the task stack size.
>-   A running task cannot be suspended if task scheduling is locked.
>-   Idle tasks and software timer tasks cannot be suspended or deleted.
>-   In an interrupt handler or when a task is locked, the operation of calling  **LOS\_TaskDelay**  fails.
>-   Locking task scheduling does not disable interrupts. Tasks can still be interrupted while task scheduling is locked.
>-   Locking task scheduling must be used together with unlocking task scheduling.
>-   Task scheduling may occur while a task priority is being set.
>-   The maximum number of tasks that can be set for the operating system is the total number of tasks of the operating system, not the number of tasks available to users. For example, if the system software timer occupies one more task resource, the number of task resources available to users decreases by one.
>-   **LOS\_CurTaskPriSet**  and  **LOS\_TaskPriSet**  cannot be used in interrupts or used to modify the priorities of software timer tasks.
>-   If the task corresponding to the task ID sent to  **LOS\_TaskPriGet**  has not been created or the task ID exceeds the maximum number of tasks,  **-1**  will be returned.
>-   Resources such as a mutex or a semaphore allocated to a task must have been released before the task is deleted.

## Development Example<a name="section460018317164"></a>

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

### Verification<a name="section62921315208"></a>

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

