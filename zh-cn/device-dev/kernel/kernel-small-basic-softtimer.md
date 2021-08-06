# 软件定时器<a name="ZH-CN_TOPIC_0000001078575728"></a>

-   [基本概念](#section4118241563)
-   [运行机制](#section31079397569)
-   [开发指导](#section18576131520577)
    -   [接口说明](#section3138019145719)
    -   [开发流程](#section1344817403575)
    -   [编程实例](#section114416313585)


## 基本概念<a name="section4118241563"></a>

软件定时器，是基于系统Tick时钟中断且由软件来模拟的定时器，当经过设定的Tick时钟计数值后会触发用户定义的回调函数。定时精度与系统Tick时钟的周期有关。硬件定时器受硬件的限制，数量上不足以满足用户的实际需求，因此为了满足用户需求，提供更多的定时器，Huawei LiteOS操作系统提供软件定时器功能。软件定时器扩展了定时器的数量，允许创建更多的定时业务。

软件定时器功能上支持：

-   静态裁剪：能通过宏关闭软件定时器功能。
-   软件定时器创建。
-   软件定时器启动。
-   软件定时器停止。
-   软件定时器删除。
-   软件定时器剩余Tick数获取。

## 运行机制<a name="section31079397569"></a>

软件定时器是系统资源，在模块初始化的时候已经分配了一块连续的内存，系统支持的最大定时器个数由los\_config.h中的LOSCFG\_BASE\_CORE\_SWTMR\_LIMIT宏配置。软件定时器使用了系统的一个队列和一个任务资源，软件定时器的触发遵循队列规则，先进先出。同一时刻设置的定时时间短的定时器总是比定时时间长的靠近队列头，满足优先被触发的准则。软件定时器以Tick为基本计时单位，当用户创建并启动一个软件定时器时，OpenHarmony系统会根据当前系统Tick时间及用户设置的定时间隔确定该定时器的到期Tick时间，并将该定时器控制结构挂入计时全局链表。

当Tick中断到来时，在Tick中断处理函数中扫描软件定时器的计时全局链表，看是否有定时器超时，若有则将超时的定时器记录下来。

Tick中断处理函数结束后，软件定时器任务（优先级为最高）被唤醒，在该任务中调用之前记录下来的定时器的超时回调函数。

定时器状态

-   OS\_SWTMR\_STATUS\_UNUSED（未使用）

    系统在定时器模块初始化的时候将系统中所有定时器资源初始化成该状态。

-   OS\_SWTMR\_STATUS\_CREATED（创建未启动/停止）

    在未使用状态下调用LOS\_SwtmrCreate接口或者启动后调用LOS\_SwtmrStop接口后，定时器将变成该状态。

-   OS\_SWTMR\_STATUS\_TICKING（计数）

    在定时器创建后调用LOS\_SwtmrStart接口，定时器将变成该状态，表示定时器运行时的状态。


定时器模式

OpenHarmony系统的软件定时器提供三类定时器机制：

-   第一类是单次触发定时器，这类定时器在启动后只会触发一次定时器事件，然后定时器自动删除。
-   第二类是周期触发定时器，这类定时器会周期性的触发定时器事件，直到用户手动停止定时器，否则将永远持续执行下去。
-   第三类也是单次触发定时器，但与第一类不同之处在于这类定时器超时后不会自动删除，需要调用定时器删除接口删除定时器。

## 开发指导<a name="section18576131520577"></a>

### 接口说明<a name="section3138019145719"></a>

OpenHarmony LiteOS-A内核的软件定时器模块提供下面几种功能，接口详细信息可以查看API参考。

**表 1**  软件定时器接口说明

<a name="table107038227425"></a>
<table><thead align="left"><tr id="row2704122217420"><th class="cellrowborder" valign="top" width="20.6020602060206%" id="mcps1.2.4.1.1"><p id="p57041622144212"><a name="p57041622144212"></a><a name="p57041622144212"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="29.542954295429542%" id="mcps1.2.4.1.2"><p id="p19704142216424"><a name="p19704142216424"></a><a name="p19704142216424"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="49.85498549854985%" id="mcps1.2.4.1.3"><p id="p670412224217"><a name="p670412224217"></a><a name="p670412224217"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1470413222429"><td class="cellrowborder" rowspan="2" valign="top" width="20.6020602060206%" headers="mcps1.2.4.1.1 "><p id="p8284115918428"><a name="p8284115918428"></a><a name="p8284115918428"></a>创建、删除定时器</p>
</td>
<td class="cellrowborder" valign="top" width="29.542954295429542%" headers="mcps1.2.4.1.2 "><p id="p117045225428"><a name="p117045225428"></a><a name="p117045225428"></a>LOS_SwtmrCreate</p>
</td>
<td class="cellrowborder" valign="top" width="49.85498549854985%" headers="mcps1.2.4.1.3 "><p id="p170422234213"><a name="p170422234213"></a><a name="p170422234213"></a>创建软件定时器</p>
</td>
</tr>
<tr id="row11704102217425"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1970492213426"><a name="p1970492213426"></a><a name="p1970492213426"></a>LOS_SwtmrDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p870442211421"><a name="p870442211421"></a><a name="p870442211421"></a>删除软件定时器</p>
</td>
</tr>
<tr id="row57041422184215"><td class="cellrowborder" rowspan="2" valign="top" width="20.6020602060206%" headers="mcps1.2.4.1.1 "><p id="p1476172124318"><a name="p1476172124318"></a><a name="p1476172124318"></a>启动、停止定时器</p>
</td>
<td class="cellrowborder" valign="top" width="29.542954295429542%" headers="mcps1.2.4.1.2 "><p id="p167040225423"><a name="p167040225423"></a><a name="p167040225423"></a>LOS_SwtmrStart</p>
</td>
<td class="cellrowborder" valign="top" width="49.85498549854985%" headers="mcps1.2.4.1.3 "><p id="p1570412229421"><a name="p1570412229421"></a><a name="p1570412229421"></a>启动软件定时器</p>
</td>
</tr>
<tr id="row15704172224219"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1170422214216"><a name="p1170422214216"></a><a name="p1170422214216"></a>LOS_SwtmrStop</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17705122211426"><a name="p17705122211426"></a><a name="p17705122211426"></a>停止软件定时器</p>
</td>
</tr>
<tr id="row12705222154214"><td class="cellrowborder" valign="top" width="20.6020602060206%" headers="mcps1.2.4.1.1 "><p id="p0705622134214"><a name="p0705622134214"></a><a name="p0705622134214"></a>获得软件定时剩余Tick数</p>
</td>
<td class="cellrowborder" valign="top" width="29.542954295429542%" headers="mcps1.2.4.1.2 "><p id="p177052220424"><a name="p177052220424"></a><a name="p177052220424"></a>LOS_SwtmrTimeGet</p>
</td>
<td class="cellrowborder" valign="top" width="49.85498549854985%" headers="mcps1.2.4.1.3 "><p id="p3705122264210"><a name="p3705122264210"></a><a name="p3705122264210"></a>获得软件定时器剩余Tick数</p>
</td>
</tr>
</tbody>
</table>

### 开发流程<a name="section1344817403575"></a>

软件定时器的典型开发流程：

1.  配置软件定时器。
    -   确认配置项LOSCFG\_BASE\_CORE\_SWTMR和LOSCFG\_BASE\_IPC\_QUEUE为打开状态；
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
>-   软件定时器使用了系统的一个队列和一个任务资源，软件定时器任务的优先级设定为0，且不允许修改 。
>-   系统可配置的软件定时器资源个数是指：整个系统可使用的软件定时器资源总个数，而并非是用户可使用的软件定时器资源个数。例如：系统软件定时器多占用一个软件定时器资源数，那么用户能使用的软件定时器资源就会减少一个。
>-   创建单次软件定时器，该定时器超时执行完回调函数后，系统会自动删除该软件定时器，并回收资源。
>-   创建单次不自删除属性的定时器，用户需要调用定时器删除接口删除定时器，回收定时器资源，避免资源泄露。

### 编程实例<a name="section114416313585"></a>

**前置条件**

-   在los\_config.h中，将LOSCFG\_BASE\_CORE\_SWTMR配置项打开。
-   配置好LOSCFG\_BASE\_CORE\_SWTMR\_LIMIT最大支持的软件定时器数。
-   配置好OS\_SWTMR\_HANDLE\_QUEUE\_SIZE软件定时器队列最大长度。

**编程示例**

```
#include "los_swtmr.h"

void Timer1_Callback(uint32_t arg);
void Timer2_Callback(uint32_t arg);

UINT32 g_timercount1 = 0;
UINT32 g_timercount2 = 0;

void Timer1_Callback(uint32_t arg) // 回调函数1
{
    unsigned long tick_last1;
    g_timercount1++;
    tick_last1=(UINT32)LOS_TickCountGet(); // 获取当前Tick数
    PRINTK("g_timercount1=%d\n",g_timercount1);
    PRINTK("tick_last1=%d\n",tick_last1);
}

void Timer2_Callback(uint32_t arg) // 回调函数2
{
    unsigned long tick_last2;
    tick_last2=(UINT32)LOS_TickCountGet();
    g_timercount2 ++;
    PRINTK("g_timercount2=%d\n",g_timercount2);
    PRINTK("tick_last2=%d\n",tick_last2);
}

void Timer_example(void)
{
    UINT16 id1;
    UINT16 id2; // timer id
    UINT32 uwTick;

    /* 创建单次软件定时器，Tick数为1000，启动到1000Tick数时执行回调函数1 */
    LOS_SwtmrCreate (1000, LOS_SWTMR_MODE_ONCE, Timer1_Callback, &id1, 1);
    
    /* 创建周期性软件定时器，每100Tick数执行回调函数2 */
    LOS_SwtmrCreate(100, LOS_SWTMR_MODE_PERIOD, Timer2_Callback, &id2, 1);
    PRINTK("create Timer1 success\n");

    LOS_SwtmrStart (id1); //启动单次软件定时器
    dprintf("start Timer1 success\n");
    LOS_TaskDelay(200); // 延时200Tick数
    LOS_SwtmrTimeGet(id1, &uwTick); // 获得单次软件定时器剩余Tick数
    PRINTK("uwTick =%d\n", uwTick);

    LOS_SwtmrStop(id1); // 停止软件定时器
    PRINTK("stop Timer1 success\n");

    LOS_SwtmrStart(id1);
    LOS_TaskDelay(1000);
    LOS_SwtmrDelete(id1); // 删除软件定时器
    PRINTK("delete Timer1 success\n");

    LOS_SwtmrStart(id2); // 启动周期性软件定时器
    PRINTK("start Timer2\n");

    LOS_TaskDelay(1000);
    LOS_SwtmrStop(id2);
    LOS_SwtmrDelete(id2);
}
```

**运行结果**

```
create Timer1 success
start Timer1 success
uwTick =800
stop Timer1 success
g_timercount1=1
tick_last1=1201
delete Timer1 success
start Timer2
g_timercount2 =1
tick_last1=1301
g_timercount2 =2
tick_last1=1401
g_timercount2 =3
tick_last1=1501
g_timercount2 =4
tick_last1=1601
g_timercount2 =5
tick_last1=1701
g_timercount2 =6
tick_last1=1801
g_timercount2 =7
tick_last1=1901
g_timercount2 =8
tick_last1=2001
g_timercount2 =9
tick_last1=2101
g_timercount2 =10
tick_last1=2201
```

