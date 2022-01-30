# Task<a name="EN-US_TOPIC_0000001078641280"></a>

## Basic Concepts<a name="section138411646175417"></a>

Tasks are the minimum running units that compete for system resources. They can use or wait to use CPUs and use system resources such as memory. They run independently from one another. 

A task represents a thread in the OpenHarmony kernel, and tasks in the processes of the same priority are scheduled and run in a unified manner.

Tasks in the OpenHarmony kernel use the preemptive scheduling mechanism, either round-robin \(RR\) scheduling or First In First Out \(FIFO\) scheduling.

Tasks in the OpenHarmony kernel are assigned 32 priorities, ranging from  **0**  \(highest\) to  **31**  \(lowest\).

In the same process, a higher-priority process can preempt resources of a lower-priority process. The lower-priority process can be scheduled only after the higher-priority process is blocked or terminated.

**Task States:**

-   Init: The task is being created.

-   Ready: The task is in the Ready queue and waits for being scheduled by the CPU.
-   Running: The task is running.
-   Blocked: The task is blocked and suspended. The Blocked states include pending \(blocked due to lock, event, or semaphore issues\), suspended \(active pending\), delay \(blocked due to delays\), and pendtime \(blocked by waiting timeout of locks, events, or semaphores\).
-   Exit: The task stops running and waits for the parent task to reclaim its control block resources.

**Figure  1**  Task state transition<a name="fig5251243193113"></a>  
![](figure/task-state-transition.png "task-state-transition")

**Task State Transition:**

-   Init→Ready:

    When a task is created, the task obtains the control block and enters the Init state \(initialization\). After the initialization is complete, the task is inserted into the scheduling queue and enters the Ready state.

-   Ready→Running:

    When a task switching is triggered, the task with the highest priority in the Ready queue is executed and enters the Running state. Then, this task is deleted from the Ready queue.

-   Running→Blocked:

    When a running task is blocked \(for example, is pended, delayed, or reading semaphores\), its state changes from Running to Blocked. Then, a task switching is triggered to run the task with the highest priority in the Ready queue.

-   Blocked→Ready:

    After the blocked task is restored \(the task is restored, the delay times out, the semaphore reading times out, or the semaphore is read\), the task is added to the Ready queue and changes from the Blocked state to the Ready state.

-   Ready→Blocked:

    A task may also be blocked \(suspended\) in the Ready state. The blocked task will change from the Ready state to the Blocked state and is deleted from the Ready queue. The task will not be scheduled until it is restored.

-   Running→Ready:

    After a task with a higher priority is created or restored, tasks will be scheduled. The task with the highest priority in the Ready queue will change to the Running state. The originally running task will change from the Running state to the Ready state and be added to the Ready queue.

-   Running→Exit:

    When a running task is terminated, its state changes from Running to Exit. If the task is set with a detach attribute \(**LOS\_TASK\_STATUS\_DETACHED**\), it will be directly destroyed after the running is complete.


## Working Principles<a name="section1381918945512"></a>

The OpenHarmony task management module provides the following functions: creating, delaying, suspending, and restoring tasks, locking and unlocking task scheduling, and querying task control block information by ID.

When a task is created, the system initializes the task stack and presets the context. The system places the task entry function in the corresponding position so that the function will be executed when the task enters the Running state for the first time.

## Development Guidelines<a name="section10649727135519"></a>

### Available APIs<a name="section78333315555"></a>

<a name="table687929113814"></a>
<table><thead align="left"><tr id="row513082983812"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p121309298384"><a name="p121309298384"></a><a name="p121309298384"></a><strong id="b77131925204513"><a name="b77131925204513"></a><a name="b77131925204513"></a>Category</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p713082933817"><a name="p713082933817"></a><a name="p713082933817"></a><strong id="b184372716456"><a name="b184372716456"></a><a name="b184372716456"></a>API</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p20130829123810"><a name="p20130829123810"></a><a name="p20130829123810"></a><strong id="b27211529174516"><a name="b27211529174516"></a><a name="b27211529174516"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row713032973813"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p0130429133818"><a name="p0130429133818"></a><a name="p0130429133818"></a>Task creation and deletion</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p6130102911384"><a name="p6130102911384"></a><a name="p6130102911384"></a>LOS_TaskCreateOnly</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p181303297387"><a name="p181303297387"></a><a name="p181303297387"></a>Creates a task and places the task in the Init state but not be scheduled.</p>
</td>
</tr>
<tr id="row51301329123813"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p41301293386"><a name="p41301293386"></a><a name="p41301293386"></a>LOS_TaskCreate</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p513092983812"><a name="p513092983812"></a><a name="p513092983812"></a>Creates a task and places the task in the Init state and be scheduled.</p>
</td>
</tr>
<tr id="row14130729193816"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p7130152993810"><a name="p7130152993810"></a><a name="p7130152993810"></a>LOS_TaskDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p11130122910387"><a name="p11130122910387"></a><a name="p11130122910387"></a>Deletes the specified task.</p>
</td>
</tr>
<tr id="row1513118292383"><td class="cellrowborder" rowspan="4" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p1813114299384"><a name="p1813114299384"></a><a name="p1813114299384"></a>Task status control</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1713113291382"><a name="p1713113291382"></a><a name="p1713113291382"></a>LOS_TaskResume</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p16131229173819"><a name="p16131229173819"></a><a name="p16131229173819"></a>Resumes a suspended task.</p>
</td>
</tr>
<tr id="row9131729173817"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p131311929123810"><a name="p131311929123810"></a><a name="p131311929123810"></a>LOS_TaskSuspend</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1813192919384"><a name="p1813192919384"></a><a name="p1813192919384"></a>Suspends the specified task.</p>
</td>
</tr>
<tr id="row151311929193818"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p213114299387"><a name="p213114299387"></a><a name="p213114299387"></a>LOS_TaskDelay</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p141311729183817"><a name="p141311729183817"></a><a name="p141311729183817"></a>Delays a task.</p>
</td>
</tr>
<tr id="row18131182910384"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p15131122923810"><a name="p15131122923810"></a><a name="p15131122923810"></a>LOS_TaskYield</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1713122953816"><a name="p1713122953816"></a><a name="p1713122953816"></a>Adjusts the scheduling sequence of tasks that call the task priority.</p>
</td>
</tr>
<tr id="row9131829123812"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p1313115299387"><a name="p1313115299387"></a><a name="p1313115299387"></a>Task scheduling control</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p101312029113815"><a name="p101312029113815"></a><a name="p101312029113815"></a>LOS_TaskLock</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p0131629183812"><a name="p0131629183812"></a><a name="p0131629183812"></a>Locks task scheduling.</p>
</td>
</tr>
<tr id="row5131829193813"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p1313182910388"><a name="p1313182910388"></a><a name="p1313182910388"></a>LOS_TaskUnlock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1131122913812"><a name="p1131122913812"></a><a name="p1131122913812"></a>Unlocks task scheduling.</p>
</td>
</tr>
<tr id="row213115292389"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p41312295381"><a name="p41312295381"></a><a name="p41312295381"></a>Task priority control</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1131829103815"><a name="p1131829103815"></a><a name="p1131829103815"></a>LOS_CurTaskPriSet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p6131729163810"><a name="p6131729163810"></a><a name="p6131729163810"></a>Sets the priority for the current task.</p>
</td>
</tr>
<tr id="row913142917389"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p10131172913819"><a name="p10131172913819"></a><a name="p10131172913819"></a>LOS_TaskPriSet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p113162912387"><a name="p113162912387"></a><a name="p113162912387"></a>Sets the priority of the specified task.</p>
</td>
</tr>
<tr id="row7131192913812"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p713142923817"><a name="p713142923817"></a><a name="p713142923817"></a>LOS_TaskPriGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p14131162923818"><a name="p14131162923818"></a><a name="p14131162923818"></a>Obtains the priority of the specified task.</p>
</td>
</tr>
<tr id="row14132329133817"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p81323295380"><a name="p81323295380"></a><a name="p81323295380"></a>Obtaining task information</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p31324294389"><a name="p31324294389"></a><a name="p31324294389"></a>LOS_CurTaskIDGet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p14132929193814"><a name="p14132929193814"></a><a name="p14132929193814"></a>Obtains the ID of the current task.</p>
</td>
</tr>
<tr id="row4132182920383"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p15133172923815"><a name="p15133172923815"></a><a name="p15133172923815"></a>LOS_TaskInfoGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p5133329123814"><a name="p5133329123814"></a><a name="p5133329123814"></a>Obtains information about the specific task.</p>
</td>
</tr>
<tr id="row855810357401"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p9682331164117"><a name="p9682331164117"></a><a name="p9682331164117"></a>Binding tasks to CPU cores</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p205581835144010"><a name="p205581835144010"></a><a name="p205581835144010"></a>LOS_TaskCpuAffiSet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p115582035154014"><a name="p115582035154014"></a><a name="p115582035154014"></a>Binds a specified task to a specified CPU. It is used only in multi-core scenarios.</p>
</td>
</tr>
<tr id="row5866193714018"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p8867133744011"><a name="p8867133744011"></a><a name="p8867133744011"></a>LOS_TaskCpuAffiGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p10867173718404"><a name="p10867173718404"></a><a name="p10867173718404"></a>Obtains the core binding information of a specified task. It is used only in multi-core scenarios.</p>
</td>
</tr>
<tr id="row197312218434"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p20362114474318"><a name="p20362114474318"></a><a name="p20362114474318"></a>Task scheduling parameter control</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p5974192215434"><a name="p5974192215434"></a><a name="p5974192215434"></a>LOS_GetTaskScheduler</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p2974922164317"><a name="p2974922164317"></a><a name="p2974922164317"></a>Obtains the scheduling policy of the specified task.</p>
</td>
</tr>
<tr id="row141414214436"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p9141202144319"><a name="p9141202144319"></a><a name="p9141202144319"></a>LOS_SetTaskScheduler</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p3141221154319"><a name="p3141221154319"></a><a name="p3141221154319"></a>Sets the scheduling parameters, including the priority and scheduling policy, for the specified task.</p>
</td>
</tr>
<tr id="row617914918441"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p17180184911445"><a name="p17180184911445"></a><a name="p17180184911445"></a>Maximum number of tasks supported</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p151807498449"><a name="p151807498449"></a><a name="p151807498449"></a>LOS_GetSystemTaskMaximum</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p81801249124417"><a name="p81801249124417"></a><a name="p81801249124417"></a>Obtains the maximum number of tasks supported by the system.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section16229657115514"></a>

The typical task development process is as follows:

1.  Call  **LOS\_TaskCreate**  to create a task.
    -   Specify the execution entry function for the task.

    -   Specify the task name.
    -   Specify the task stack size.
    -   Specify the priority of the task.
    -   Specify the task attribute, that is, whether to support the  **LOS\_TASK\_STATUS\_DETACHED**  attribute.
    -   Specify the task-core binding attribute for multi-core environment.

2.  Run the service code to implement task scheduling.
3.  After the task execution is complete, the task resources are automatically reclaimed if the  **LOS\_TASK\_STATUS\_DETACHED**  attribute is set. If the  **LOS\_TASK\_STATUS\_DETACHED**  attribute is not set, call the  **LOS\_TaskDelete**  API to reclaim the task resources.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The kernel space has the highest permission and can operate tasks in any process.
>-   The task created by calling a user-space process in the kernel space is a KProcess, not a user-space process.

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
    /*After 2 ticks elapse, the task is resumed and executed.*/
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
    initParam.uwResved   = LOS_TASK_STATUS_DETACHED;

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

    /*Create a task with a lower priority. The task will not be executed immediately after being created, because task scheduling is locked.*/
    ret = LOS_TaskCreate(&g_taskLoID, &initParam);
    if (ret!= LOS_OK) {         
        LOS_TaskUnlock();          
        PRINTK("ExampleTaskLo create Failed!\n");
        return LOS_NOK;     
    }      
    PRINTK("ExampleTaskLo create Success!\n");  

    /* Unlock task scheduling. The task with the highest priority in the Ready queue will be executed.*/
    LOS_TaskUnlock();

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
```

