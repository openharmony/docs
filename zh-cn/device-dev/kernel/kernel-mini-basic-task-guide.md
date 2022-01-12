# 开发指导<a name="ZH-CN_TOPIC_0000001123948079"></a>

-   [接口说明](#section158501652121514)
-   [开发流程](#section783435801510)
-   [编程实例](#section460018317164)
    -   [结果验证](#section189023104457)


任务创建后，内核可以执行锁任务调度，解锁任务调度，挂起，恢复，延时等操作，同时也可以设置任务优先级，获取任务优先级。

## 接口说明<a name="section158501652121514"></a>

OpenHarmony LiteOS-M内核的任务管理模块提供下面几种功能，接口详细信息可以查看API参考。

**表 1**  任务管理模块接口

<a name="table1415203765610"></a>
<table><thead align="left"><tr id="row134151837125611"><th class="cellrowborder" valign="top" width="12.85128512851285%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="29.8029802980298%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row0415737175610"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p88211552111218"><a name="p88211552111218"></a><a name="p88211552111218"></a>创建和删除任务</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p6347518151610"><a name="p6347518151610"></a><a name="p6347518151610"></a>LOS_TaskCreateOnly</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p5347161814167"><a name="p5347161814167"></a><a name="p5347161814167"></a>创建任务，并使该任务进入suspend状态，不对该任务进行调度。如果需要调度，可以调用LOS_TaskResume使该任务进入ready状态。</p>
</td>
</tr>
<tr id="row1841519376561"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4166128181614"><a name="p4166128181614"></a><a name="p4166128181614"></a>LOS_TaskCreate</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1516617282165"><a name="p1516617282165"></a><a name="p1516617282165"></a>创建任务，并使该任务进入ready状态，如果就绪队列中没有更高优先级的任务，则运行该任务。</p>
</td>
</tr>
<tr id="row1187514443616"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p9364362169"><a name="p9364362169"></a><a name="p9364362169"></a>LOS_TaskDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p106058831812"><a name="p106058831812"></a><a name="p106058831812"></a>删除指定的任务。</p>
</td>
</tr>
<tr id="row1141513373562"><td class="cellrowborder" rowspan="7" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p9438545181812"><a name="p9438545181812"></a><a name="p9438545181812"></a>控制任务状态</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p2871432206"><a name="p2871432206"></a><a name="p2871432206"></a>LOS_TaskResume</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p2871632201"><a name="p2871632201"></a><a name="p2871632201"></a>恢复挂起的任务，使该任务进入ready状态。</p>
</td>
</tr>
<tr id="row1541513745611"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p99679299202"><a name="p99679299202"></a><a name="p99679299202"></a>LOS_TaskSuspend</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p596712910200"><a name="p596712910200"></a><a name="p596712910200"></a>挂起指定的任务，然后切换任务。</p>
</td>
</tr>
<tr id="row1541513745621"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p99679299202"><a name="p99679299202"></a><a name="p99679299202"></a>LOS_TaskJoin</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p596712910200"><a name="p596712910200"></a><a name="p596712910200"></a>挂起当前任务，等待指定任务运行结束并回收其任务控制块资源。</p>
</td>
</tr>
<tr id="row1541513745341"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p99679299202"><a name="p99679299202"></a><a name="p99679299202"></a>LOS_TaskDetach</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p596712910200"><a name="p596712910200"></a><a name="p596712910200"></a>修改任务的joinable属性为detach属性，detach属性的任务运行结束会自动回收任务控制块资源。</p>
</td>
</tr>
<tr id="row14167379561"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1596722915207"><a name="p1596722915207"></a><a name="p1596722915207"></a>LOS_TaskDelay</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1496792972019"><a name="p1496792972019"></a><a name="p1496792972019"></a>任务延时等待，释放CPU，等待时间到期后该任务会重新进入ready状态。传入参数为Tick数目。</p>
</td>
</tr>
<tr id="row1018605142017"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p19186185119201"><a name="p19186185119201"></a><a name="p19186185119201"></a>LOS_Msleep</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p418612515207"><a name="p418612515207"></a><a name="p418612515207"></a>传入参数为毫秒数，转换为Tick数目，调用LOS_TaskDelay。</p>
</td>
</tr>
<tr id="row2832910132011"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1896722932020"><a name="p1896722932020"></a><a name="p1896722932020"></a>LOS_TaskYield</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p796702962016"><a name="p796702962016"></a><a name="p796702962016"></a>当前任务时间片设置为0，释放CPU，触发调度运行就绪任务队列中优先级最高的任务。</p>
</td>
</tr>
<tr id="row57041546104720"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p11344426483"><a name="p11344426483"></a><a name="p11344426483"></a>控制任务调度</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p83447211482"><a name="p83447211482"></a><a name="p83447211482"></a>LOS_TaskLock</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p4344721480"><a name="p4344721480"></a><a name="p4344721480"></a>锁任务调度，但任务仍可被中断打断。</p>
</td>
</tr>
<tr id="row8645184724712"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p133441025480"><a name="p133441025480"></a><a name="p133441025480"></a>LOS_TaskUnlock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p934418217482"><a name="p934418217482"></a><a name="p934418217482"></a>解锁任务调度。</p>
</td>
</tr>
<tr id="row16401849185317"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p54011249195317"><a name="p54011249195317"></a><a name="p54011249195317"></a>LOS_Schedule</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p640144919534"><a name="p640144919534"></a><a name="p640144919534"></a>触发任务调度。</p>
</td>
</tr>
<tr id="row955081314485"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p11466102734816"><a name="p11466102734816"></a><a name="p11466102734816"></a>控制任务优先级</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p154664278482"><a name="p154664278482"></a><a name="p154664278482"></a>LOS_CurTaskPriSet</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p1046632764812"><a name="p1046632764812"></a><a name="p1046632764812"></a>设置当前任务的优先级。</p>
</td>
</tr>
<tr id="row13909142489"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p5467927164811"><a name="p5467927164811"></a><a name="p5467927164811"></a>LOS_TaskPriSet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p446772704811"><a name="p446772704811"></a><a name="p446772704811"></a>设置指定任务的优先级。</p>
</td>
</tr>
<tr id="row355119149485"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p134671527134811"><a name="p134671527134811"></a><a name="p134671527134811"></a>LOS_TaskPriGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1946782717489"><a name="p1946782717489"></a><a name="p1946782717489"></a>获取指定任务的优先级。</p>
</td>
</tr>
<tr id="row4964232175514"><td class="cellrowborder" rowspan="8" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p1512125013144"><a name="p1512125013144"></a><a name="p1512125013144"></a>获取任务信息</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p0142259562"><a name="p0142259562"></a><a name="p0142259562"></a>LOS_CurTaskIDGet</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p91419257568"><a name="p91419257568"></a><a name="p91419257568"></a>获取当前任务的ID。</p>
</td>
</tr>
<tr id="row81994135812"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1620014131982"><a name="p1620014131982"></a><a name="p1620014131982"></a>LOS_NextTaskIDGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1297616371197"><a name="p1297616371197"></a><a name="p1297616371197"></a>获取任务就绪队列中优先级最高的任务的ID。</p>
</td>
</tr>
<tr id="row1742101318812"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p147422136816"><a name="p147422136816"></a><a name="p147422136816"></a>LOS_NewTaskIDGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p18742101318812"><a name="p18742101318812"></a><a name="p18742101318812"></a>等同LOS_NextTaskIDGet。</p>
</td>
</tr>
<tr id="row135511828165616"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1235774875616"><a name="p1235774875616"></a><a name="p1235774875616"></a>LOS_CurTaskNameGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p52858313568"><a name="p52858313568"></a><a name="p52858313568"></a>获取当前任务的名称。</p>
</td>
</tr>
<tr id="row1411710407583"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p81176407583"><a name="p81176407583"></a><a name="p81176407583"></a>LOS_TaskNameGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1635193815613"><a name="p1635193815613"></a><a name="p1635193815613"></a>获取指定任务的名称。</p>
</td>
</tr>
<tr id="row95431743121216"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p95431434127"><a name="p95431434127"></a><a name="p95431434127"></a>LOS_TaskStatusGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p57752481129"><a name="p57752481129"></a><a name="p57752481129"></a>获取指定任务的状态。</p>
</td>
</tr>
<tr id="row5810125105712"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p57171053135711"><a name="p57171053135711"></a><a name="p57171053135711"></a>LOS_TaskInfoGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p77173535571"><a name="p77173535571"></a><a name="p77173535571"></a>获取指定任务的信息，包括任务状态、优先级、任务栈大小、栈顶指针SP、任务入口函数、已使用的任务栈大小等。</p>
</td>
</tr>
<tr id="row3909121616111"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p490917165118"><a name="p490917165118"></a><a name="p490917165118"></a>LOS_TaskIsRunning</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p790991618113"><a name="p790991618113"></a><a name="p790991618113"></a>获取任务模块是否已经开始调度运行。</p>
</td>
</tr>
<tr id="row248964211159"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p194891428158"><a name="p194891428158"></a><a name="p194891428158"></a>任务信息维测</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p14891142171519"><a name="p14891142171519"></a><a name="p14891142171519"></a>LOS_TaskSwitchInfoGet</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p6490204221518"><a name="p6490204221518"></a><a name="p6490204221518"></a>获取任务切换信息，需要开启宏LOSCFG_BASE_CORE_EXC_TSK_SWITCH。</p>
</td>
</tr>
</tbody>
</table>

## 开发流程<a name="section783435801510"></a>

本节介绍任务模块的典型场景开发流程：

1.  锁任务调度LOS\_TaskLock，防止高优先级任务调度。
2.  创建任务LOS\_TaskCreate。
3.  解锁任务LOS\_TaskUnlock，让任务按照优先级进行调度。
4.  延时任务LOS\_TaskDelay，任务延时等待。
5.  挂起指定的任务LOS\_TaskSuspend，任务挂起等待恢复操作。
6.  恢复挂起的任务LOS\_TaskResume。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   执行Idle任务时，会对待回收链表中的任务控制块和任务栈进行回收。
>-   任务名是指针，并没有分配空间，在设置任务名时，禁止将局部变量的地址赋值给任务名指针。
>-   任务栈的大小按8字节大小对齐。确定任务栈大小的原则是，够用就行，多了浪费，少了任务栈溢出。
>-   挂起当前任务时，如果已经锁任务调度，则无法挂起。
>-   Idle任务及软件定时器任务不能被挂起或者删除。
>-   在中断处理函数中或者在锁任务的情况下，执行LOS\_TaskDelay会失败。
>-   锁任务调度，并不关中断，因此任务仍可被中断打断。
>-   锁任务调度必须和解锁任务调度配合使用。
>-   设置任务优先级时可能会发生任务调度。
>-   可配置的系统最大任务数是指：整个系统的任务总个数，而非用户能使用的任务个数。例如：系统软件定时器多占用一个任务资源，那么用户能使用的任务资源就会减少一个。
>-   LOS\_CurTaskPriSet和LOS\_TaskPriSet接口不能在中断中使用，也不能用于修改软件定时器任务的优先级。
>-   LOS\_TaskPriGet接口传入的task ID对应的任务未创建或者超过最大任务数，统一返回-1。
>-   在删除任务时要保证任务申请的资源（如互斥锁、信号量等）已被释放。

## 编程实例<a name="section460018317164"></a>

本实例介绍基本的任务操作方法，包含2个不同优先级任务的创建、任务延时、任务锁与解锁调度、挂起和恢复等操作，阐述任务优先级调度的机制以及各接口的应用。示例代码如下：

```
UINT32 g_taskHiId;
UINT32 g_taskLoId;
#define TSK_PRIOR_HI 4
#define TSK_PRIOR_LO 5

UINT32 Example_TaskHi(VOID)
{
    UINT32 ret;

    printf("Enter TaskHi Handler.\n");

    /* 延时100个Ticks，延时后该任务会挂起，执行剩余任务中最高优先级的任务(TaskLo任务) */
    ret = LOS_TaskDelay(100);
    if (ret != LOS_OK) {
        printf("Delay TaskHi Failed.\n");
        return LOS_NOK;
    }

    /* 100个Ticks时间到了后，该任务恢复，继续执行 */
    printf("TaskHi LOS_TaskDelay Done.\n");

    /* 挂起自身任务 */
    ret = LOS_TaskSuspend(g_taskHiId);
    if (ret != LOS_OK) {
        printf("Suspend TaskHi Failed.\n");
        return LOS_NOK;
    }
    printf("TaskHi LOS_TaskResume Success.\n");
    return ret;
}

/* 低优先级任务入口函数 */
UINT32 Example_TaskLo(VOID)
{
    UINT32 ret;

    printf("Enter TaskLo Handler.\n");

    /* 延时100个Ticks，延时后该任务会挂起，执行剩余任务中最高优先级的任务 */
    ret = LOS_TaskDelay(100);
    if (ret != LOS_OK) {
        printf("Delay TaskLo Failed.\n");
        return LOS_NOK;
    }

    printf("TaskHi LOS_TaskSuspend Success.\n");

    /* 恢复被挂起的任务g_taskHiId */
    ret = LOS_TaskResume(g_taskHiId);
    if (ret != LOS_OK) {
        printf("Resume TaskHi Failed.\n");
        return LOS_NOK;
    }
    return ret;
}

/* 任务测试入口函数，创建两个不同优先级的任务 */
UINT32 Example_TskCaseEntry(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S initParam = { 0 };

    /* 锁任务调度，防止新创建的任务比本任务高而发生调度 */
    LOS_TaskLock();

    printf("LOS_TaskLock() Success!\n");

    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_TaskHi;
    initParam.usTaskPrio = TSK_PRIOR_HI;
    initParam.pcName = "TaskHi";
    initParam.uwStackSize = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    initParam.uwResved = LOS_TASK_ATTR_JOINABLE;
    /* 创建高优先级任务，由于锁任务调度，任务创建成功后不会马上执行 */
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
    initParam.uwResved = 0; /* detach 属性 */

    /* 创建低优先级任务，由于锁任务调度，任务创建成功后不会马上执行 */
    ret = LOS_TaskCreate(&g_taskLoId, &initParam);
    if (ret != LOS_OK) {
        LOS_TaskUnlock();
        printf("Example_TaskLo create Failed!\n");
        return LOS_NOK;
    }

    printf("Example_TaskLo create Success!\n");

    /* 解锁任务调度，此时会发生任务调度，执行就绪队列中最高优先级任务 */
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

### 结果验证<a name="section189023104457"></a>

编译运行得到的结果为：

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

