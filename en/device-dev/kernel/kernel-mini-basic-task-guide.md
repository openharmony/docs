# Development Guidelines<a name="EN-US_TOPIC_0000001123948079"></a>

When a task is created, the OpenHarmony LiteOS-M kernel can perform operations, such as locking or unlocking task scheduling, suspending, restoring, and delaying the task, and setting or obtaining the task priority.

## Available APIs<a name="section158501652121514"></a>

The following table describes APIs available for the OpenHarmony LiteOS-M task module. For more details about the APIs, see the API reference.

**Table  1**  APIs of the task management module

<a name="table1415203765610"></a>
<table><thead align="left"><tr id="row134151837125611"><th class="cellrowborder" valign="top" width="12.85128512851285%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>Category</p>
</th>
<th class="cellrowborder" valign="top" width="29.8029802980298%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0415737175610"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p88211552111218"><a name="p88211552111218"></a><a name="p88211552111218"></a>Creating or deleting a task</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p6347518151610"><a name="p6347518151610"></a><a name="p6347518151610"></a>LOS_TaskCreateOnly</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p5347161814167"><a name="p5347161814167"></a><a name="p5347161814167"></a>Creates a task and suspends the task to disable scheduling of the task. To enable scheduling of the task, call <strong id="b16759181135816"><a name="b16759181135816"></a><a name="b16759181135816"></a>LOS_TaskResume</strong> to make the task enter the Ready state.</p>
</td>
</tr>
<tr id="row1841519376561"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4166128181614"><a name="p4166128181614"></a><a name="p4166128181614"></a>LOS_TaskCreate</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1516617282165"><a name="p1516617282165"></a><a name="p1516617282165"></a>Creates a task and places the task in the Ready state. If there is no task with a higher priority in the Ready queue, the task will be executed.</p>
</td>
</tr>
<tr id="row1187514443616"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p9364362169"><a name="p9364362169"></a><a name="p9364362169"></a>LOS_TaskDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p106058831812"><a name="p106058831812"></a><a name="p106058831812"></a>Deletes the specified task.</p>
</td>
</tr>
<tr id="row1141513373562"><td class="cellrowborder" rowspan="5" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p9438545181812"><a name="p9438545181812"></a><a name="p9438545181812"></a>Controlling task status</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p2871432206"><a name="p2871432206"></a><a name="p2871432206"></a>LOS_TaskResume</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p2871632201"><a name="p2871632201"></a><a name="p2871632201"></a>Resumes a suspended task to place the task in the Ready state.</p>
</td>
</tr>
<tr id="row1541513745611"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p99679299202"><a name="p99679299202"></a><a name="p99679299202"></a>LOS_TaskSuspend</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p596712910200"><a name="p596712910200"></a><a name="p596712910200"></a>Suspends the specified task and performs task switching.</p>
</td>
</tr>
<tr id="row14167379561"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1596722915207"><a name="p1596722915207"></a><a name="p1596722915207"></a>LOS_TaskDelay</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1496792972019"><a name="p1496792972019"></a><a name="p1496792972019"></a>Makes a task wait for a period of time (in ticks) and releases CPU resources. When the delay time expires, the task enters the Ready state again. The input parameter is the number of ticks.</p>
</td>
</tr>
<tr id="row1018605142017"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p19186185119201"><a name="p19186185119201"></a><a name="p19186185119201"></a>LOS_Msleep</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p418612515207"><a name="p418612515207"></a><a name="p418612515207"></a>Converts the input parameter number of milliseconds into number of ticks, and use the result to calls <strong id="b13541401095"><a name="b13541401095"></a><a name="b13541401095"></a>LOS_TaskDelay</strong>.</p>
</td>
</tr>
<tr id="row2832910132011"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1896722932020"><a name="p1896722932020"></a><a name="p1896722932020"></a>LOS_TaskYield</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p796702962016"><a name="p796702962016"></a><a name="p796702962016"></a>Sets the time slice of the current task to <strong id="b1226164119919"><a name="b1226164119919"></a><a name="b1226164119919"></a>0</strong> to release CPU resources and schedule the task with the highest priority in the Ready queue to run.</p>
</td>
</tr>
<tr id="row57041546104720"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p11344426483"><a name="p11344426483"></a><a name="p11344426483"></a>Control task scheduling</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p83447211482"><a name="p83447211482"></a><a name="p83447211482"></a>LOS_TaskLock</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p4344721480"><a name="p4344721480"></a><a name="p4344721480"></a>Locks task scheduling. However, tasks can still be interrupted.</p>
</td>
</tr>
<tr id="row8645184724712"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p133441025480"><a name="p133441025480"></a><a name="p133441025480"></a>LOS_TaskUnlock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p934418217482"><a name="p934418217482"></a><a name="p934418217482"></a>Unlocks task scheduling.</p>
</td>
</tr>
<tr id="row16401849185317"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p54011249195317"><a name="p54011249195317"></a><a name="p54011249195317"></a>LOS_Schedule</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p640144919534"><a name="p640144919534"></a><a name="p640144919534"></a>Triggers task scheduling</p>
</td>
</tr>
<tr id="row955081314485"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p11466102734816"><a name="p11466102734816"></a><a name="p11466102734816"></a>Controlling task priority</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p154664278482"><a name="p154664278482"></a><a name="p154664278482"></a>LOS_CurTaskPriSet</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p1046632764812"><a name="p1046632764812"></a><a name="p1046632764812"></a>Sets the priority for the current task.</p>
</td>
</tr>
<tr id="row13909142489"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p5467927164811"><a name="p5467927164811"></a><a name="p5467927164811"></a>LOS_TaskPriSet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p446772704811"><a name="p446772704811"></a><a name="p446772704811"></a>Sets the priority for a specified task.</p>
</td>
</tr>
<tr id="row355119149485"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p134671527134811"><a name="p134671527134811"></a><a name="p134671527134811"></a>LOS_TaskPriGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1946782717489"><a name="p1946782717489"></a><a name="p1946782717489"></a>Obtains the priority of a specified task.</p>
</td>
</tr>
<tr id="row4964232175514"><td class="cellrowborder" rowspan="8" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p1512125013144"><a name="p1512125013144"></a><a name="p1512125013144"></a>Obtaining task information</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p0142259562"><a name="p0142259562"></a><a name="p0142259562"></a>LOS_CurTaskIDGet</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p91419257568"><a name="p91419257568"></a><a name="p91419257568"></a>Obtains the ID of the current task.</p>
</td>
</tr>
<tr id="row81994135812"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1620014131982"><a name="p1620014131982"></a><a name="p1620014131982"></a>LOS_NextTaskIDGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1297616371197"><a name="p1297616371197"></a><a name="p1297616371197"></a>Obtains the ID of the task with the highest priority in the Ready queue.</p>
</td>
</tr>
<tr id="row1742101318812"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p147422136816"><a name="p147422136816"></a><a name="p147422136816"></a>LOS_NewTaskIDGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p18742101318812"><a name="p18742101318812"></a><a name="p18742101318812"></a>Same as <strong id="b151555352161"><a name="b151555352161"></a><a name="b151555352161"></a>LOS_NextTaskIDGet</strong>.</p>
</td>
</tr>
<tr id="row135511828165616"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1235774875616"><a name="p1235774875616"></a><a name="p1235774875616"></a>LOS_CurTaskNameGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p52858313568"><a name="p52858313568"></a><a name="p52858313568"></a>Obtains the name of the current task.</p>
</td>
</tr>
<tr id="row1411710407583"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p81176407583"><a name="p81176407583"></a><a name="p81176407583"></a>LOS_TaskNameGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1635193815613"><a name="p1635193815613"></a><a name="p1635193815613"></a>Obtains the name of a specified task.</p>
</td>
</tr>
<tr id="row95431743121216"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p95431434127"><a name="p95431434127"></a><a name="p95431434127"></a>LOS_TaskStatusGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p57752481129"><a name="p57752481129"></a><a name="p57752481129"></a>Obtains the state of a specified task.</p>
</td>
</tr>
<tr id="row5810125105712"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p57171053135711"><a name="p57171053135711"></a><a name="p57171053135711"></a>LOS_TaskInfoGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p77173535571"><a name="p77173535571"></a><a name="p77173535571"></a>Obtains information about a specified task, including the task state, priority, stack size, stack pointer (SP), task entry function, and used stack space.</p>
</td>
</tr>
<tr id="row3909121616111"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p490917165118"><a name="p490917165118"></a><a name="p490917165118"></a>LOS_TaskIsRunning</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p790991618113"><a name="p790991618113"></a><a name="p790991618113"></a>Checks whether the task module has started scheduling.</p>
</td>
</tr>
<tr id="row248964211159"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p194891428158"><a name="p194891428158"></a><a name="p194891428158"></a>Maintaining and testing task information</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p14891142171519"><a name="p14891142171519"></a><a name="p14891142171519"></a>LOS_TaskSwitchInfoGet</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p6490204221518"><a name="p6490204221518"></a><a name="p6490204221518"></a>Obtains task switching information. The macro <strong id="b164011668388"><a name="b164011668388"></a><a name="b164011668388"></a>LOSCFG_BASE_CORE_EXC_TSK_SWITCH</strong> must be enabled.</p>
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

    /* Delay the task for 100 ticks. The task is then suspended, and the remaining task with the highest priority (TaskLo) will be executed.*/
    ret = LOS_TaskDelay(100);
    if (ret != LOS_OK) {
        printf("Delay TaskHi Failed.\n");
        return LOS_NOK;
    }

    /*After 100 ticks elapse, the task is resumed.*/
    printf("TaskHi LOS_TaskDelay Done.\n");

    /* Suspend the task.*/
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

    /* Delay the task for 100 ticks. The task is then suspended, and the remaining task with the highest priority will be executed.*/
    ret = LOS_TaskDelay(100);
    if (ret != LOS_OK) {
        printf("Delay TaskLo Failed.\n");
        return LOS_NOK;
    }

    printf("TaskHi LOS_TaskSuspend Success.\n");

    /* Resume the suspended task g_taskHiId.*/
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

    /* Lock task scheduling to prevent newly created tasks from being scheduled prior to this task due to higher priority.*/
    LOS_TaskLock();

    printf("LOS_TaskLock() Success!\n");

    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_TaskHi;
    initParam.usTaskPrio = TSK_PRIOR_HI;
    initParam.pcName = "TaskHi";
    initParam.uwStackSize = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;

    /* Create a high-priority task. The task will not be executed immediately after being created, because task scheduling is locked.*/
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

    /*Create a low-priority task. The task will not be executed immediately after being created, because task scheduling is locked.*/
    ret = LOS_TaskCreate(&g_taskLoId, &initParam);
    if (ret != LOS_OK) {
        LOS_TaskUnlock();
        printf("Example_TaskLo create Failed!\n");
        return LOS_NOK;
    }

    printf("Example_TaskLo create Success!\n");

    /* Unlock task scheduling. The task with the highest priority in the Ready queue will be executed.*/
    LOS_TaskUnlock();

    return LOS_OK;
}
```

### Verification<a name="section189023104457"></a>

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
```

