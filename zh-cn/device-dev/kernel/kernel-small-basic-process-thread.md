# 任务<a name="ZH-CN_TOPIC_0000001078641280"></a>

-   [基本概念](#section138411646175417)
-   [运行机制](#section1381918945512)
-   [开发指导](#section10649727135519)
    -   [接口说明](#section78333315555)
    -   [开发流程](#section16229657115514)
    -   [编程实例](#section2809723165612)


## 基本概念<a name="section138411646175417"></a>

从系统的角度看，任务Task是竞争系统资源的最小运行单元。任务可以使用或等待CPU、使用内存空间等系统资源，并独立于其它任务运行。

OpenHarmony 内核中使用一个任务表示一个线程。

OpenHarmony 内核中同优先级进程内的任务统一调度、运行。

OpenHarmony 内核中的任务采用抢占式调度机制，同时支持时间片轮转调度和FIFO调度方式。

OpenHarmony 内核的任务一共有32个优先级\(0-31\)，最高优先级为0，最低优先级为31。

当前进程内, 高优先级的任务可抢占低优先级任务，低优先级任务必须在高优先级任务阻塞或结束后才能得到调度。

**任务状态说明**：

-   初始化（Init）：任务正在被创建。

-   就绪（Ready）：任务在就绪列表中，等待CPU调度。
-   运行（Running）：任务正在运行。
-   阻塞（Blocked）：任务被阻塞挂起。Blocked状态包括：pending\(因为锁、事件、信号量等阻塞\)、suspended（主动pend）、delay\(延时阻塞\)、pendtime\(因为锁、事件、信号量时间等超时等待\)。
-   退出（Exit）：任务运行结束，等待父任务回收其控制块资源。

**图 1**  任务状态迁移示意图<a name="fig5251243193113"></a>  
![](figure/任务状态迁移示意图.png "任务状态迁移示意图")

**任务状态迁移说明：**

-   Init→Ready：

    任务创建拿到控制块后为初始化阶段\(Init状态\)，当任务初始化完成将任务插入调度队列，此时任务进入就绪状态。

-   Ready→Running：

    任务创建后进入就绪态，发生任务切换时，就绪列表中最高优先级的任务被执行，从而进入运行态，此刻该任务从就绪列表中删除。

-   Running→Blocked：

    正在运行的任务发生阻塞（挂起、延时、读信号量等）时，任务状态由运行态变成阻塞态，然后发生任务切换，运行就绪列表中剩余最高优先级任务。

-   Blocked→Ready ：

    阻塞的任务被恢复后（任务恢复、延时时间超时、读信号量超时或读到信号量等），此时被恢复的任务会被加入就绪列表，从而由阻塞态变成就绪态。

-   Ready→Blocked：

    任务也有可能在就绪态时被阻塞（挂起），此时任务状态会由就绪态转变为阻塞态，该任务从就绪列表中删除，不会参与任务调度，直到该任务被恢复。

-   Running→Ready：

    有更高优先级任务创建或者恢复后，会发生任务调度，此刻就绪列表中最高优先级任务变为运行态，那么原先运行的任务由运行态变为就绪态，并加入就绪列表中。

-   Running→Exit：

    运行中的任务运行结束，任务状态由运行态变为退出态。若为设置了分离属性（LOS\_TASK\_STATUS\_DETACHED）的任务，运行结束后将直接销毁。


## 运行机制<a name="section1381918945512"></a>

OpenHarmony 任务管理模块提供任务创建、任务延时、任务挂起和任务恢复、锁任务调度和解锁任务调度、根据ID查询任务控制块信息功能。

用户创建任务时，系统会将任务栈进行初始化，预置上下文。此外，系统还会将“任务入口函数”地址放在相应位置。这样在任务第一次启动进入运行态时，将会执行任务入口函数。

## 开发指导<a name="section10649727135519"></a>

### 接口说明<a name="section78333315555"></a>

<a name="table687929113814"></a>
<table><thead align="left"><tr id="row513082983812"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p121309298384"><a name="p121309298384"></a><a name="p121309298384"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p713082933817"><a name="p713082933817"></a><a name="p713082933817"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p20130829123810"><a name="p20130829123810"></a><a name="p20130829123810"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row713032973813"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p0130429133818"><a name="p0130429133818"></a><a name="p0130429133818"></a>任务的创建和删除</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p6130102911384"><a name="p6130102911384"></a><a name="p6130102911384"></a>LOS_TaskCreateOnly</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p181303297387"><a name="p181303297387"></a><a name="p181303297387"></a>创建任务，并使该任务进入Init状态，不执行任务调度</p>
</td>
</tr>
<tr id="row51301329123813"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p41301293386"><a name="p41301293386"></a><a name="p41301293386"></a>LOS_TaskCreate</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p513092983812"><a name="p513092983812"></a><a name="p513092983812"></a>创建任务，并使该任务进入Ready状态，并调度</p>
</td>
</tr>
<tr id="row14130729193816"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p7130152993810"><a name="p7130152993810"></a><a name="p7130152993810"></a>LOS_TaskDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p11130122910387"><a name="p11130122910387"></a><a name="p11130122910387"></a>删除指定的任务</p>
</td>
</tr>
<tr id="row1513118292383"><td class="cellrowborder" rowspan="4" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p1813114299384"><a name="p1813114299384"></a><a name="p1813114299384"></a>任务状态控制</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1713113291382"><a name="p1713113291382"></a><a name="p1713113291382"></a>LOS_TaskResume</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p16131229173819"><a name="p16131229173819"></a><a name="p16131229173819"></a>恢复挂起的任务</p>
</td>
</tr>
<tr id="row9131729173817"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p131311929123810"><a name="p131311929123810"></a><a name="p131311929123810"></a>LOS_TaskSuspend</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1813192919384"><a name="p1813192919384"></a><a name="p1813192919384"></a>挂起指定的任务</p>
</td>
</tr>
<tr id="row151311929193818"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p213114299387"><a name="p213114299387"></a><a name="p213114299387"></a>LOS_TaskDelay</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p141311729183817"><a name="p141311729183817"></a><a name="p141311729183817"></a>任务延时等待</p>
</td>
</tr>
<tr id="row18131182910384"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p15131122923810"><a name="p15131122923810"></a><a name="p15131122923810"></a>LOS_TaskYield</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1713122953816"><a name="p1713122953816"></a><a name="p1713122953816"></a>显式放权，调整调用任务优先级的任务调度顺序</p>
</td>
</tr>
<tr id="row9131829123812"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p1313115299387"><a name="p1313115299387"></a><a name="p1313115299387"></a>任务调度的控制</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p101312029113815"><a name="p101312029113815"></a><a name="p101312029113815"></a>LOS_TaskLock</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p0131629183812"><a name="p0131629183812"></a><a name="p0131629183812"></a>锁任务调度</p>
</td>
</tr>
<tr id="row5131829193813"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p1313182910388"><a name="p1313182910388"></a><a name="p1313182910388"></a>LOS_TaskUnlock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1131122913812"><a name="p1131122913812"></a><a name="p1131122913812"></a>解锁任务调度</p>
</td>
</tr>
<tr id="row213115292389"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p41312295381"><a name="p41312295381"></a><a name="p41312295381"></a>任务优先级的控制</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1131829103815"><a name="p1131829103815"></a><a name="p1131829103815"></a>LOS_CurTaskPriSet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p6131729163810"><a name="p6131729163810"></a><a name="p6131729163810"></a>设置当前任务的优先级</p>
</td>
</tr>
<tr id="row913142917389"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p10131172913819"><a name="p10131172913819"></a><a name="p10131172913819"></a>LOS_TaskPriSet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p113162912387"><a name="p113162912387"></a><a name="p113162912387"></a>设置指定任务的优先级</p>
</td>
</tr>
<tr id="row7131192913812"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p713142923817"><a name="p713142923817"></a><a name="p713142923817"></a>LOS_TaskPriGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p14131162923818"><a name="p14131162923818"></a><a name="p14131162923818"></a>获取指定任务的优先级</p>
</td>
</tr>
<tr id="row14132329133817"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p81323295380"><a name="p81323295380"></a><a name="p81323295380"></a>任务信息获取</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p31324294389"><a name="p31324294389"></a><a name="p31324294389"></a>LOS_CurTaskIDGet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p14132929193814"><a name="p14132929193814"></a><a name="p14132929193814"></a>获取当前任务的ID</p>
</td>
</tr>
<tr id="row4132182920383"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p15133172923815"><a name="p15133172923815"></a><a name="p15133172923815"></a>LOS_TaskInfoGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p5133329123814"><a name="p5133329123814"></a><a name="p5133329123814"></a>获取指定任务的信息</p>
</td>
</tr>
<tr id="row855810357401"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p9682331164117"><a name="p9682331164117"></a><a name="p9682331164117"></a>任务绑核操作</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p205581835144010"><a name="p205581835144010"></a><a name="p205581835144010"></a>LOS_TaskCpuAffiSet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p115582035154014"><a name="p115582035154014"></a><a name="p115582035154014"></a>绑定指定任务到指定cpu上运行，仅在多核下使用</p>
</td>
</tr>
<tr id="row5866193714018"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p8867133744011"><a name="p8867133744011"></a><a name="p8867133744011"></a>LOS_TaskCpuAffiGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p10867173718404"><a name="p10867173718404"></a><a name="p10867173718404"></a>获取指定任务的绑核信息，仅在多核下使用</p>
</td>
</tr>
<tr id="row197312218434"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p20362114474318"><a name="p20362114474318"></a><a name="p20362114474318"></a>任务调度参数的控制</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p5974192215434"><a name="p5974192215434"></a><a name="p5974192215434"></a>LOS_GetTaskScheduler</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p2974922164317"><a name="p2974922164317"></a><a name="p2974922164317"></a>获取指定任务的调度策略</p>
</td>
</tr>
<tr id="row141414214436"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p9141202144319"><a name="p9141202144319"></a><a name="p9141202144319"></a>LOS_SetTaskScheduler</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p3141221154319"><a name="p3141221154319"></a><a name="p3141221154319"></a>设置指定任务的调度参数，包括优先级和调度策略</p>
</td>
</tr>
<tr id="row617914918441"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p17180184911445"><a name="p17180184911445"></a><a name="p17180184911445"></a>系统支持的最大任务数</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p151807498449"><a name="p151807498449"></a><a name="p151807498449"></a>LOS_GetSystemTaskMaximum</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p81801249124417"><a name="p81801249124417"></a><a name="p81801249124417"></a>获取系统支持的最大任务数目</p>
</td>
</tr>
</tbody>
</table>

### 开发流程<a name="section16229657115514"></a>

任务的典型开发流程：

1.  通过LOS\_TaskCreate创建一个任务。
    -   指定任务的执行入口函数

    -   指定任务名
    -   指定任务的栈大小
    -   指定任务的优先级
    -   指定任务的属性，是否支持LOS\_TASK\_STATUS\_DETACHED属性
    -   多核运行时，可以选择设置任务的绑核属性

2.  任务参与调度运行，执行用户指定的业务代码。
3.  任务执行结束，如果任务设置了LOS\_TASK\_STATUS\_DETACHED属性，则任务运行结束后自动回收任务资源，如果未设置LOS\_TASK\_STATUS\_DETACHED属性，则需要调用LOS\_TaskDelete接口回收任务资源。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   内核态具有最高权限，可以操作任意进程内的任务。
>-   用户态进程通过系统调用进入内核态后创建的任务属于KProcess, 不属于当前用户态进程。

### 编程实例<a name="section2809723165612"></a>

代码实现如下：

```
UINT32 g_taskLoID;
UINT32 g_taskHiID; 
#define TSK_PRIOR_HI 4 
#define TSK_PRIOR_LO 5  
UINT32 ExampleTaskHi(VOID) 
{     
    UINT32 ret;
    PRINTK("Enter TaskHi Handler.\n"); 
    /* 延时2个Tick，延时后该任务会挂起，执行剩余任务中最高优先级的任务(g_taskLoID任务) */ 
    ret = LOS_TaskDelay(2);
    if (ret != LOS_OK) { 
        PRINTK("Delay Task Failed.\n");
        return LOS_NOK;     
    }      
    /* 2个Tick时间到了后，该任务恢复，继续执行 */ 
    PRINTK("TaskHi LOS_TaskDelay Done.\n"); 
    /* 挂起自身任务 */     
    ret = LOS_TaskSuspend(g_taskHiID); 
    if (ret != LOS_OK) {
        PRINTK("Suspend TaskHi Failed.\n"); 
        return LOS_NOK;
    }     
    PRINTK("TaskHi LOS_TaskResume Success.\n"); 
    return LOS_OK;
}

/* 低优先级任务入口函数 */ 
UINT32 ExampleTaskLo(VOID)
{     
    UINT32 ret;         
    PRINTK("Enter TaskLo Handler.\n");      
    /* 延时2个Tick，延时后该任务会挂起，执行剩余任务中就高优先级的任务(背景任务) */
    ret = LOS_TaskDelay(2);     
    if (ret != LOS_OK) {         
        PRINTK("Delay TaskLo Failed.\n");         
        return LOS_NOK;     
    }      
    PRINTK("TaskHi LOS_TaskSuspend Success.\n");
    /* 恢复被挂起的任务g_taskHiID */
    ret = LOS_TaskResume(g_taskHiID);
    if (ret != LOS_OK) {
        PRINTK("Resume TaskHi Failed.\n");
        return LOS_NOK;
    }      
    PRINTK("TaskHi LOS_TaskDelete Success.\n"); 
    return LOS_OK;
}  
/* 任务测试入口函数，在里面创建优先级不一样的两个任务 */ 
UINT32 ExampleTaskCaseEntry(VOID) 
{     
    UINT32 ret;     
    TSK_INIT_PARAM_S initParam = {0};

    /* 锁任务调度 */
    LOS_TaskLock();
    PRINTK("LOS_TaskLock() Success!\n");
    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleTaskHi;
    initParam.usTaskPrio = TSK_PRIOR_HI; 
    initParam.pcName = "HIGH_NAME";
    initParam.uwStackSize = LOS_TASK_MIN_STACK_SIZE;
    initParam.uwResved   = LOS_TASK_STATUS_DETACHED;

    /* 创建高优先级任务，由于锁任务调度，任务创建成功后不会马上执行 */
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

    /* 创建低优先级任务，由于锁任务调度，任务创建成功后不会马上执行 */     
    ret = LOS_TaskCreate(&g_taskLoID, &initParam);
    if (ret!= LOS_OK) {         
        LOS_TaskUnlock();          
        PRINTK("ExampleTaskLo create Failed!\n");
        return LOS_NOK;     
    }      
    PRINTK("ExampleTaskLo create Success!\n");  

    /* 解锁任务调度，此时会发生任务调度，执行就绪列表中最高优先级任务 */
    LOS_TaskUnlock();

    while(1){};
    return LOS_OK;
}  
```

编译运行得到的结果为：

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

