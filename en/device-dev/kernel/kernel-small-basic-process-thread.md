# Task

## Basic Concepts<a name="section138411646175417"></a>

Tasks are the minimum running units that compete for system resources. They can use or wait to use CPUs and use system resources such as memory. They run independently from one another.

In the OpenHarmony kernel, a task represents a thread.

Tasks in the processes of the same priority in the OpenHarmony kernel are scheduled and run in a unified manner.

The tasks in the kernel use the preemptive scheduling mechanism, either round-robin \(RR\) scheduling or First In First Out \(FIFO\) scheduling.

Tasks are assigned 32 priorities, ranging from  **0**  \(highest\) to  **31**  \(lowest\).

In the same process, a higher-priority task can preempt resources of a lower-priority task. The lower-priority task can be scheduled only after the higher-priority task is blocked or terminated.

**Task Status Description**

-   Init: The task is being created.
-   Ready: The task is in the Ready queue and waits for scheduling by the CPU.
-   Running: The task is running.
-   Blocked: The task is blocked and suspended. The Blocked states include pending \(blocked due to lock, event, or semaphore issues\), suspended \(active pending\), delay \(blocked due to delays\), and pendtime \(blocked by waiting timeout of locks, events, or semaphores\).
-   Exit: The task is complete and waits for the parent task to reclaim its control block resources.

**Figure  1**  Task state transition<a name="fig5251243193113"></a>  
![](figures/task-state-transition.png "task-state-transition")

**Task State Transition**

-   Init→Ready:

    When a task is created, the task obtains the control block and enters the Init state \(initialization\). After the initialization is complete, the task is inserted into the scheduling queue and enters the Ready state.

-   Ready→Running:

    When a task switching is triggered, the task with the highest priority in the Ready queue is executed and enters the Running state. Then, this task is deleted from the Ready queue.

-   Running→Blocked:

    When a running task is blocked \(for example, is pended, delayed, or reading semaphores\), its state changes from Running to Blocked. Then, a task switching is triggered to run the task with the highest priority in the Ready queue.

-   Blocked→Ready:

    After the blocked task is restored \(the task is restored, the delay times out, the semaphore reading times out, or the semaphore is read\), the task is added to the Ready queue and will change from the Blocked state to the Ready state.

-   Ready→Blocked:

    When a task in the Ready state is blocked \(suspended\), the task changes to the Blocked state and is deleted from the Ready queue. The blocked task will not be scheduled until it is recovered.

-   Running→Ready:

    When a task with a higher priority is created or recovered, tasks will be scheduled. The task with the highest priority in the Ready queue changes to the Running state. The originally running task changes to the Ready state and is added to the Ready queue.

-   Running→Exit:

    When a running task is complete, it changes to the Exit state. If the task is set with a detach attribute \(**LOS\_TASK\_STATUS\_DETACHED**\), it will be directly destroyed after being terminated.


## Working Principles<a name="section1381918945512"></a>

The OpenHarmony task management module provides the following functions: creating, delaying, suspending, and restoring tasks, locking and unlocking task scheduling, and querying task control block information by ID.

When a task is created, the system initializes the task stack and presets the context. The system also places the task entry function in the corresponding position so that the function can be executed when the task enters the running state for the first time.

## Development Guidelines<a name="section10649727135519"></a>

### Available APIs<a name="section78333315555"></a>

<a name="table687929113814"></a>
<table><thead align="left"><tr id="row513082983812"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p121309298384"><a name="p121309298384"></a><a name="p121309298384"></a><strong id="b1288394945813"><a name="b1288394945813"></a><a name="b1288394945813"></a>Function</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p713082933817"><a name="p713082933817"></a><a name="p713082933817"></a><strong id="b184372716456"><a name="b184372716456"></a><a name="b184372716456"></a>API</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p20130829123810"><a name="p20130829123810"></a><a name="p20130829123810"></a><strong id="b27211529174516"><a name="b27211529174516"></a><a name="b27211529174516"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row431611256303"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p0297202573015"><a name="p0297202573015"></a><a name="p0297202573015"></a>Task creation and deletion</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1229720252303"><a name="p1229720252303"></a><a name="p1229720252303"></a>LOS_TaskCreateOnly</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p12297825123016"><a name="p12297825123016"></a><a name="p12297825123016"></a>Creates a task and places the task in the Init state without scheduling.</p>
</td>
</tr>
<tr id="row19316182517304"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p1829732511308"><a name="p1829732511308"></a><a name="p1829732511308"></a>LOS_TaskCreate</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p19297122518303"><a name="p19297122518303"></a><a name="p19297122518303"></a>Creates a task and places it in the Init state for scheduling.</p>
</td>
</tr>
<tr id="row7316192593013"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p3297162583020"><a name="p3297162583020"></a><a name="p3297162583020"></a>LOS_TaskDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p3297162517308"><a name="p3297162517308"></a><a name="p3297162517308"></a>Deletes the specified task.</p>
</td>
</tr>
<tr id="row13316112533020"><td class="cellrowborder" rowspan="6" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p172979255306"><a name="p172979255306"></a><a name="p172979255306"></a>Task status control</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p14297425103016"><a name="p14297425103016"></a><a name="p14297425103016"></a>LOS_TaskResume</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1929732593018"><a name="p1929732593018"></a><a name="p1929732593018"></a>Resumes a suspended task.</p>
</td>
</tr>
<tr id="row1231632513012"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p5297132553014"><a name="p5297132553014"></a><a name="p5297132553014"></a>LOS_TaskSuspend</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p8297182563015"><a name="p8297182563015"></a><a name="p8297182563015"></a>Suspends the specified task.</p>
</td>
</tr>
<tr id="row1547201019421"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p5885913184219"><a name="p5885913184219"></a><a name="p5885913184219"></a>LOS_TaskJoin</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p28851313104213"><a name="p28851313104213"></a><a name="p28851313104213"></a>Suspends this task till the specified task is complete and the task control block resources are reclaimed.</p>
</td>
</tr>
<tr id="row69281012114217"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p68857132427"><a name="p68857132427"></a><a name="p68857132427"></a>LOS_TaskDetach</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p188851813184219"><a name="p188851813184219"></a><a name="p188851813184219"></a>Changes the task attribute from <strong id="b1986175411125"><a name="b1986175411125"></a><a name="b1986175411125"></a>joinable</strong> to <strong id="b18996959101215"><a name="b18996959101215"></a><a name="b18996959101215"></a>detach</strong>. After the task of the <strong id="b15851429171317"><a name="b15851429171317"></a><a name="b15851429171317"></a>detach</strong> attribute is complete, the task control block resources will be automatically reclaimed.</p>
</td>
</tr>
<tr id="row1231672512301"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p92979251305"><a name="p92979251305"></a><a name="p92979251305"></a>LOS_TaskDelay</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1297182517306"><a name="p1297182517306"></a><a name="p1297182517306"></a>Delays a task.</p>
</td>
</tr>
<tr id="row73161725163018"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p10297152573014"><a name="p10297152573014"></a><a name="p10297152573014"></a>LOS_TaskYield</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p2297325163019"><a name="p2297325163019"></a><a name="p2297325163019"></a>Adjusts the scheduling sequence of tasks that call the task priority.</p>
</td>
</tr>
<tr id="row1231520259306"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p9297142511307"><a name="p9297142511307"></a><a name="p9297142511307"></a>Task scheduling control</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p429719257307"><a name="p429719257307"></a><a name="p429719257307"></a>LOS_TaskLock</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p11297142510306"><a name="p11297142510306"></a><a name="p11297142510306"></a>Locks task scheduling.</p>
</td>
</tr>
<tr id="row431442573010"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p17297625193015"><a name="p17297625193015"></a><a name="p17297625193015"></a>LOS_TaskUnlock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p829715252308"><a name="p829715252308"></a><a name="p829715252308"></a>Unlocks task scheduling.</p>
</td>
</tr>
<tr id="row53141525123010"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p1729732593014"><a name="p1729732593014"></a><a name="p1729732593014"></a>Task priority control</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p629715254308"><a name="p629715254308"></a><a name="p629715254308"></a>LOS_CurTaskPriSet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p142981925183020"><a name="p142981925183020"></a><a name="p142981925183020"></a>Sets the priority for the current task.</p>
</td>
</tr>
<tr id="row18314102563015"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p11298202513303"><a name="p11298202513303"></a><a name="p11298202513303"></a>LOS_TaskPriSet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p629822563014"><a name="p629822563014"></a><a name="p629822563014"></a>Sets the priority for a specified task.</p>
</td>
</tr>
<tr id="row731442543011"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p1029892517302"><a name="p1029892517302"></a><a name="p1029892517302"></a>LOS_TaskPriGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p19298182563018"><a name="p19298182563018"></a><a name="p19298182563018"></a>Obtains the priority of a specified task.</p>
</td>
</tr>
<tr id="row18314172523011"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p17298225203011"><a name="p17298225203011"></a><a name="p17298225203011"></a>Obtaining task information</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p229811251307"><a name="p229811251307"></a><a name="p229811251307"></a>LOS_CurTaskIDGet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1029842519303"><a name="p1029842519303"></a><a name="p1029842519303"></a>Obtains the ID of the current task.</p>
</td>
</tr>
<tr id="row1331452516307"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p172984256301"><a name="p172984256301"></a><a name="p172984256301"></a>LOS_TaskInfoGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p122988259303"><a name="p122988259303"></a><a name="p122988259303"></a>Obtains information about the specified task.</p>
</td>
</tr>
<tr id="row93146250305"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p82986256300"><a name="p82986256300"></a><a name="p82986256300"></a>Binding tasks to CPU cores</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1929862583018"><a name="p1929862583018"></a><a name="p1929862583018"></a>LOS_TaskCpuAffiSet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p82981925163013"><a name="p82981925163013"></a><a name="p82981925163013"></a>Binds a specified task to the specified CPU. It is used only in multi-core scenarios.</p>
</td>
</tr>
<tr id="row5314192543014"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p02984251305"><a name="p02984251305"></a><a name="p02984251305"></a>LOS_TaskCpuAffiGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1729822513017"><a name="p1729822513017"></a><a name="p1729822513017"></a>Obtains the core binding information of the specified task. It is used only in multi-core scenarios.</p>
</td>
</tr>
<tr id="row43141525193013"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p16298152514308"><a name="p16298152514308"></a><a name="p16298152514308"></a>Task scheduling parameter control</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1529872563011"><a name="p1529872563011"></a><a name="p1529872563011"></a>LOS_GetTaskScheduler</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1298182513010"><a name="p1298182513010"></a><a name="p1298182513010"></a>Obtains the scheduling policy of the specified task.</p>
</td>
</tr>
<tr id="row1331472519305"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p15298152514301"><a name="p15298152514301"></a><a name="p15298152514301"></a>LOS_SetTaskScheduler</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p11298172553015"><a name="p11298172553015"></a><a name="p11298172553015"></a>Sets the scheduling parameters, including the priority and scheduling policy, for the specified task.</p>
</td>
</tr>
<tr id="row831492514307"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p12981250307"><a name="p12981250307"></a><a name="p12981250307"></a>Maximum number of tasks supported</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p112981425183019"><a name="p112981425183019"></a><a name="p112981425183019"></a>LOS_GetSystemTaskMaximum</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p6298525123017"><a name="p6298525123017"></a><a name="p6298525123017"></a>Obtains the maximum number of tasks supported by the system.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section16229657115514"></a>

The typical task development process is as follows:

1.  Call  **LOS\_TaskCreate**  to create a task.
    -   Specify the execution entry function for the task.
    -   Specifies the task name.
    -   Specify the task stack size.
    -   Specify the priority of the task.
    -   Specify the task attribute, which can be  **LOS\_TASK\_ATTR\_JOINABLE**  or  **LOS\_TASK\_STATUS\_DETACHED**.
    -   Specify the task-core binding attribute for multi-core environment.

2.  Run the service code to implement task scheduling.
3.  Reclaim resources when the task is complete. If the task attribute is  **LOS\_TASK\_STATUS\_DETACHED**, the task resources are automatically reclaimed. If the task attribute is  **LOS\_TASK\_ATTR\_JOINABLE**, call  **LOS\_TaskJoin**  to reclaim task resources. The default task attribute is  **LOS\_TASK\_STATUS\_DETACHED**.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The kernel mode has the highest permission and can operate tasks in any process.
>-   If a task is created after a user-mode process enters the kernel mode by a system call, the task belongs to a KProcess not a user-mode process.

### Development Example<a name="section2809723165612"></a>

The sample code is as follows:

```
UINT32 g_taskLoID;
UINT32 g_taskHiID; 
#define TSK_PRIOR_HI 4 
#define TSK_PRIOR_LO 5  
UINT32 ExampleTaskHi(VOID) 
{     
    UINT32 ret;
    PRINTK("Enter TaskHi Handler.\n"); 
    /* Delay the task for 2 ticks. The task is then suspended, and the remaining task with the highest priority (g_taskLoID) will be executed.*/
    ret = LOS_TaskDelay(2);
    if (ret != LOS_OK) { 
        PRINTK("Delay Task Failed.\n");
        return LOS_NOK;     
    }      
    /* After 2 ticks elapse, the task is resumed and executed.*/
    PRINTK("TaskHi LOS_TaskDelay Done.\n"); 
    /* Suspend the task.*/
    ret = LOS_TaskSuspend(g_taskHiID); 
    if (ret != LOS_OK) {
        PRINTK("Suspend TaskHi Failed.\n"); 
        return LOS_NOK;
    }     
    PRINTK("TaskHi LOS_TaskResume Success.\n"); 
    return LOS_OK;
}

/* Entry function of the lower-priority task */
UINT32 ExampleTaskLo(VOID)
{     
    UINT32 ret;         
    PRINTK("Enter TaskLo Handler.\n");      
    /* Delay the task for 2 ticks. The task is then suspended, and the remaining task with the highest priority (background task) will be executed.*/
    ret = LOS_TaskDelay(2);     
    if (ret != LOS_OK) {         
        PRINTK("Delay TaskLo Failed.\n");         
        return LOS_NOK;     
    }      
    PRINTK("TaskHi LOS_TaskSuspend Success.\n");
    /* Resume the suspended task g_taskHiID.*/
    ret = LOS_TaskResume(g_taskHiID);
    if (ret != LOS_OK) {
        PRINTK("Resume TaskHi Failed.\n");
        return LOS_NOK;
    }      
    PRINTK("TaskHi LOS_TaskDelete Success.\n"); 
    return LOS_OK;
}  
/* Task test entry function, which is used to create two tasks with different priorities.*/
UINT32 ExampleTaskCaseEntry(VOID) 
{     
    UINT32 ret;     
    TSK_INIT_PARAM_S initParam = {0};

    /* Lock task scheduling.*/
    LOS_TaskLock();
    PRINTK("LOS_TaskLock() Success!\n");
    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleTaskHi;
    initParam.usTaskPrio = TSK_PRIOR_HI; 
    initParam.pcName = "HIGH_NAME";
    initParam.uwStackSize = LOS_TASK_MIN_STACK_SIZE;
    initParam.uwResved   = LOS_TASK_ATTR_JOINABLE;

    /* Create a task with a higher priority. The task will not be executed immediately after being created, because task scheduling is locked.*/
    ret = LOS_TaskCreate(&g_taskHiID, &initParam);
    if (ret != LOS_OK) {
        LOS_TaskUnlock();
        PRINTK("ExampleTaskHi create Failed! ret=%d\n", ret);
        return LOS_NOK;
    }      
    PRINTK("ExampleTaskHi create Success!\n");

    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleTaskLo;
    initParam.usTaskPrio = TSK_PRIOR_LO;
    initParam.pcName = "LOW_NAME";
    initParam.uwStackSize = LOS_TASK_MIN_STACK_SIZE;
    initParam.uwResved   = LOS_TASK_STATUS_DETACHED;

    /* Create a task with a lower priority. The task will not be executed immediately after being created, because task scheduling is locked.*/
    ret = LOS_TaskCreate(&g_taskLoID, &initParam);
    if (ret!= LOS_OK) {         
        LOS_TaskUnlock();          
        PRINTK("ExampleTaskLo create Failed!\n");
        return LOS_NOK;     
    }      
    PRINTK("ExampleTaskLo create Success!\n");  

    /* Unlock task scheduling. The task with the highest priority in the Ready queue will be executed.*/
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

