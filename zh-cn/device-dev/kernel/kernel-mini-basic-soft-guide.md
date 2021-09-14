# 开发指导<a name="ZH-CN_TOPIC_0000001078718194"></a>

-   [接口说明](#section158501652121514)
-   [开发流程](#section783435801510)
-   [编程实例](#section460018317164)
    -   [实例描述](#section3741753191918)
    -   [示例代码](#section20760101182016)
    -   [结果验证](#section11244112818172)


## 接口说明<a name="section158501652121514"></a>

OpenHarmony LiteOS-M内核的软件定时器模块提供下面几种功能，接口详细信息可以查看API参考。

**表 1**  软件定时器接口

<a name="table14277123518139"></a>
<table><thead align="left"><tr id="row152771935131315"><th class="cellrowborder" valign="top" width="17.77177717771777%" id="mcps1.2.4.1.1"><p id="p1127733591316"><a name="p1127733591316"></a><a name="p1127733591316"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="23.782378237823785%" id="mcps1.2.4.1.2"><p id="p22771357138"><a name="p22771357138"></a><a name="p22771357138"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="58.44584458445845%" id="mcps1.2.4.1.3"><p id="p327714358130"><a name="p327714358130"></a><a name="p327714358130"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row159539510586"><td class="cellrowborder" rowspan="2" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="p1194410585810"><a name="p1194410585810"></a><a name="p1194410585810"></a>创建、删除定时器</p>
</td>
<td class="cellrowborder" valign="top" width="23.782378237823785%" headers="mcps1.2.4.1.2 "><p id="p10944105115814"><a name="p10944105115814"></a><a name="p10944105115814"></a>LOS_SwtmrCreate</p>
</td>
<td class="cellrowborder" valign="top" width="58.44584458445845%" headers="mcps1.2.4.1.3 "><p id="p9944105175818"><a name="p9944105175818"></a><a name="p9944105175818"></a>创建定时器</p>
</td>
</tr>
<tr id="row17953454580"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p094419505814"><a name="p094419505814"></a><a name="p094419505814"></a>LOS_SwtmrDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p39445585817"><a name="p39445585817"></a><a name="p39445585817"></a>删除定时器</p>
</td>
</tr>
<tr id="row79531357589"><td class="cellrowborder" rowspan="2" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="p139443595820"><a name="p139443595820"></a><a name="p139443595820"></a>启动、停止定时器</p>
</td>
<td class="cellrowborder" valign="top" width="23.782378237823785%" headers="mcps1.2.4.1.2 "><p id="p1894435175815"><a name="p1894435175815"></a><a name="p1894435175815"></a>LOS_SwtmrStart</p>
</td>
<td class="cellrowborder" valign="top" width="58.44584458445845%" headers="mcps1.2.4.1.3 "><p id="p1194415518581"><a name="p1194415518581"></a><a name="p1194415518581"></a>启动定时器</p>
</td>
</tr>
<tr id="row1095320545814"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p20944355589"><a name="p20944355589"></a><a name="p20944355589"></a>LOS_SwtmrStop</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p169441515816"><a name="p169441515816"></a><a name="p169441515816"></a>停止定时器</p>
</td>
</tr>
<tr id="row119525513581"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="p109442053586"><a name="p109442053586"></a><a name="p109442053586"></a>获得软件定时器剩余Tick数</p>
</td>
<td class="cellrowborder" valign="top" width="23.782378237823785%" headers="mcps1.2.4.1.2 "><p id="p9944354585"><a name="p9944354585"></a><a name="p9944354585"></a>LOS_SwtmrTimeGet</p>
</td>
<td class="cellrowborder" valign="top" width="58.44584458445845%" headers="mcps1.2.4.1.3 "><p id="p39441257586"><a name="p39441257586"></a><a name="p39441257586"></a>获得软件定时器剩余Tick数</p>
</td>
</tr>
</tbody>
</table>

## 开发流程<a name="section783435801510"></a>

软件定时器的典型开发流程：

1.  配置软件定时器。
    -   确认配置项LOSCFG\_BASE\_CORE\_SWTMR和LOSCFG\_BASE\_IPC\_QUEUE为1打开状态；
    -   配置LOSCFG\_BASE\_CORE\_SWTMR\_LIMIT最大支持的软件定时器数；
    -   配置OS\_SWTMR\_HANDLE\_QUEUE\_SIZE软件定时器队列最大长度；

2.  创建定时器LOS\_SwtmrCreate。
    -   创建一个指定计时时长、指定超时处理函数、指定触发模式的软件定时器；
    -   返回函数运行结果，成功或失败；

3.  启动定时器LOS\_SwtmrStart。
4.  获得软件定时器剩余Tick数LOS\_SwtmrTimeGet。
5.  停止定时器LOS\_SwtmrStop。
6.  删除定时器LOS\_SwtmrDelete。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   软件定时器的回调函数中不要做过多操作，不要使用可能引起任务挂起或者阻塞的接口或操作。
>-   软件定时器使用了系统的一个队列和一个任务资源，软件定时器任务的优先级设定为0，且不允许修改  。
>-   系统可配置的软件定时器资源个数是指：整个系统可使用的软件定时器资源总个数，而并非是用户可使用的软件定时器资源个数。例如：系统软件定时器多占用一个软件定时器资源数，那么用户能使用的软件定时器资源就会减少一个。
>-   创建单次软件定时器，该定时器超时执行完回调函数后，系统会自动删除该软件定时器，并回收资源。
>-   创建单次不自删除属性的定时器，用户需要调用定时器删除接口删除定时器，回收定时器资源，避免资源泄露。

## 编程实例<a name="section460018317164"></a>

### 实例描述<a name="section3741753191918"></a>

在下面的例子中，演示如下功能：

1.  软件定时器创建、启动、删除、暂停、重启操作。
2.  单次软件定时器，周期软件定时器使用方法。

### 示例代码<a name="section20760101182016"></a>

前提条件：

-   在los\_config.h中，将LOSCFG\_BASE\_CORE\_SWTMR配置项打开。
-   在los\_config.h中，将LOSCFG\_BASE\_CORE\_SWTMR\_ALIGN配置项关闭，示例代码中演示代码不涉及定时器对齐。
-   配置好LOSCFG\_BASE\_CORE\_SWTMR\_LIMIT最大支持的软件定时器数。
-   配置好OS\_SWTMR\_HANDLE\_QUEUE\_SIZE软件定时器队列最大长度。

代码实现如下：

```
#include "los_swtmr.h"

/* Timer count */
UINT32 g_timerCount1 = 0;   
UINT32 g_timerCount2 = 0;

/* 任务ID */
UINT32 g_testTaskId01;

void Timer1_Callback(UINT32 arg) // 回调函数1 
{
    UINT32 tick_last1;
    g_timerCount1++;
    tick_last1 = (UINT32)LOS_TickCountGet(); // 获取当前Tick数
    printf("g_timerCount1=%d, tick_last1=%d\n", g_timerCount1, tick_last1);
}  

void Timer2_Callback(UINT32 arg) // 回调函数2 
{
    UINT32 tick_last2;
    tick_last2 = (UINT32)LOS_TickCountGet();
    g_timerCount2++;
    printf("g_timerCount2=%d tick_last2=%d\n", g_timerCount2, tick_last2);
}  

void Timer_example(void)  
{
    UINT32 ret;
    UINT32 id1; // timer id1
    UINT32 id2; // timer id2
    UINT32 tickCount;

    /*创建单次软件定时器，Tick数为1000，启动到1000Tick数时执行回调函数1 */ 
    LOS_SwtmrCreate(1000, LOS_SWTMR_MODE_ONCE, Timer1_Callback, &id1, 1);

    /*创建周期性软件定时器，每100Tick数执行回调函数2 */
    LOS_SwtmrCreate(100, LOS_SWTMR_MODE_PERIOD, Timer2_Callback, &id2, 1);
    printf("Timer 1 created.\n");

    LOS_SwtmrStart(id1); //启动单次软件定时器 
    printf("Timer 1 started.\n");

    LOS_TaskDelay(200); //延时200Tick数
    LOS_SwtmrTimeGet(id1, &tickCount); // 获得单次软件定时器剩余Tick数
    printf("tickCount=%d\n", tickCount);

    LOS_SwtmrStop(id1); // 停止软件定时器
    printf("Timer 1 stopped.\n");

    LOS_SwtmrStart(id1);
    LOS_TaskDelay(1000);

    LOS_SwtmrStart(id2); // 启动周期性软件定时器
    printf("Timer 2 started.\n");

    LOS_TaskDelay(1000);
    LOS_SwtmrStop(id2);
    ret = LOS_SwtmrDelete(id2);  // 删除软件定时器
    if (ret == LOS_OK) {
        printf("Timer 2 deleted.\n");
    }
}

UINT32 Example_TaskEntry(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S task1;

    /* 锁任务调度 */
    LOS_TaskLock();

    /* 创建任务1 */
    (VOID)memset(&task1, 0, sizeof(TSK_INIT_PARAM_S));
    task1.pfnTaskEntry = (TSK_ENTRY_FUNC)Timer_example;
    task1.pcName       = "TimerTsk";
    task1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task1.usTaskPrio   = 5;
    ret = LOS_TaskCreate(&g_testTaskId01, &task1);
    if (ret != LOS_OK) {
        printf("Failed to create the timer task.\n");
        return LOS_NOK;
    }

    /* 解锁任务调度 */
    LOS_TaskUnlock();

    return LOS_OK;
}
```

### 结果验证<a name="section11244112818172"></a>

编译烧录运行，输出结果如下：

```
Timer 1 created.
Timer 1 started.
tickCount=798
Timer 1 stopped.
g_timerCount1=1, tick_last1=1208
Timer 2 started.
g_timerCount2=1 tick_last2=1313
g_timerCount2=2 tick_last2=1413
g_timerCount2=3 tick_last2=1513
g_timerCount2=4 tick_last2=1613
g_timerCount2=5 tick_last2=1713
g_timerCount2=6 tick_last2=1813
g_timerCount2=7 tick_last2=1913
g_timerCount2=8 tick_last2=2013
g_timerCount2=9 tick_last2=2113
g_timerCount2=10 tick_last2=2213
Timer 2 deleted.
```

