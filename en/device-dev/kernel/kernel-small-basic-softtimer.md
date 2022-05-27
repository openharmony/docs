# Software Timer


## Basic Concepts<a name="section4118241563"></a>

The software timer is a software-simulated timer based on system tick interrupts. When the preset tick counter value has elapsed, the user-defined callback will be invoked. The timing precision is related to the cycle of the system tick clock. Due to the limitation in hardware, the number of hardware timers cannot meet users' requirements. Therefore, the OpenHarmony LiteOS-A kernel provides the software timer function. The software timer allows more timing services to be created, increasing the number of timers.

The software timer supports the following functions:

-   Disabling the software timer using a macro
-   Creating a software timer
-   Starting a software timer
-   Stopping a software timer
-   Deleting a software timer
-   Obtaining the number of remaining ticks of a software timer

## Working Principles<a name="section31079397569"></a>

The software timer is a system resource. When modules are initialized, a contiguous section of memory is allocated for software timers. The maximum number of timers supported by the system is configured by the  **LOSCFG\_BASE\_CORE\_SWTMR\_LIMIT**  macro in  **los\_config.h**. Software timers use a queue and a task resource of the system. The software timers are triggered based on the First In First Out \(FIFO\) rule. For the timers set at the same time, the timer with a shorter value is always closer to the queue head than the timer with a longer value, and is preferentially triggered. The software timer counts time in ticks. When a software timer is created and started, the OpenHarmony system determines the timer expiry time based on the current system time \(in ticks\) and the timing interval set by the user, and adds the timer control structure to the global timing list.

When a tick interrupt occurs, the tick interrupt handler scans the global timing list for expired timers. If such timers are found, the timers are recorded.

When the tick interrupt handling function is complete, the software timer task \(with the highest priority\) is woken up. In this task, the timeout callback function for the recorded timer is called.

Timer States

-   OS\_SWTMR\_STATUS\_UNUSED

    The timer is not in use. When the timer module is initialized, all timer resources in the system are set to this state.

-   OS\_SWTMR\_STATUS\_CREATED

    The timer is created but not started or the timer is stopped. When  **LOS\_SwtmrCreate**  is called for a timer that is not in use or  **LOS\_SwtmrStop**  is called for a newly started timer, the timer changes to this state.

-   OS\_SWTMR\_STATUS\_TICKING

    The timer is running \(counting\). When  **LOS\_SwtmrStart**  is called for a newly created timer, the timer enters this state.


Timer Modes

The OpenHarmony provides three types of software timers:

-   One-shot timer: Once started, the timer is automatically deleted after triggering only one timer event.
-   Periodic timer: This type of timer periodically triggers timer events until it is manually stopped.
-   One-shot timer deleted by calling an API

## Development Guidelines<a name="section18576131520577"></a>

### Available APIs<a name="section3138019145719"></a>

The following table describes APIs available for the OpenHarmony LiteOS-A software timer module. For more details about the APIs, see the API reference.

**Table  1**  Software timer APIs

<a name="table107038227425"></a>
<table><thead align="left"><tr id="row2704122217420"><th class="cellrowborder" valign="top" width="20.6020602060206%" id="mcps1.2.4.1.1"><p id="p57041622144212"><a name="p57041622144212"></a><a name="p57041622144212"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="29.542954295429542%" id="mcps1.2.4.1.2"><p id="p19704142216424"><a name="p19704142216424"></a><a name="p19704142216424"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="49.85498549854985%" id="mcps1.2.4.1.3"><p id="p670412224217"><a name="p670412224217"></a><a name="p670412224217"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1470413222429"><td class="cellrowborder" rowspan="2" valign="top" width="20.6020602060206%" headers="mcps1.2.4.1.1 "><p id="p8284115918428"><a name="p8284115918428"></a><a name="p8284115918428"></a>Creating or deleting timers</p>
</td>
<td class="cellrowborder" valign="top" width="29.542954295429542%" headers="mcps1.2.4.1.2 "><p id="p117045225428"><a name="p117045225428"></a><a name="p117045225428"></a>LOS_SwtmrCreate</p>
</td>
<td class="cellrowborder" valign="top" width="49.85498549854985%" headers="mcps1.2.4.1.3 "><p id="p170422234213"><a name="p170422234213"></a><a name="p170422234213"></a>Creates a software timer.</p>
</td>
</tr>
<tr id="row11704102217425"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1970492213426"><a name="p1970492213426"></a><a name="p1970492213426"></a>LOS_SwtmrDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p870442211421"><a name="p870442211421"></a><a name="p870442211421"></a>Deletes a software timer.</p>
</td>
</tr>
<tr id="row57041422184215"><td class="cellrowborder" rowspan="2" valign="top" width="20.6020602060206%" headers="mcps1.2.4.1.1 "><p id="p1476172124318"><a name="p1476172124318"></a><a name="p1476172124318"></a>Starting or stopping timers</p>
</td>
<td class="cellrowborder" valign="top" width="29.542954295429542%" headers="mcps1.2.4.1.2 "><p id="p167040225423"><a name="p167040225423"></a><a name="p167040225423"></a>LOS_SwtmrStart</p>
</td>
<td class="cellrowborder" valign="top" width="49.85498549854985%" headers="mcps1.2.4.1.3 "><p id="p1570412229421"><a name="p1570412229421"></a><a name="p1570412229421"></a>Starts a software timer.</p>
</td>
</tr>
<tr id="row15704172224219"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1170422214216"><a name="p1170422214216"></a><a name="p1170422214216"></a>LOS_SwtmrStop</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17705122211426"><a name="p17705122211426"></a><a name="p17705122211426"></a>Stops a software timer.</p>
</td>
</tr>
<tr id="row12705222154214"><td class="cellrowborder" valign="top" width="20.6020602060206%" headers="mcps1.2.4.1.1 "><p id="p0705622134214"><a name="p0705622134214"></a><a name="p0705622134214"></a>Obtaining remaining ticks of a software timer</p>
</td>
<td class="cellrowborder" valign="top" width="29.542954295429542%" headers="mcps1.2.4.1.2 "><p id="p177052220424"><a name="p177052220424"></a><a name="p177052220424"></a>LOS_SwtmrTimeGet</p>
</td>
<td class="cellrowborder" valign="top" width="49.85498549854985%" headers="mcps1.2.4.1.3 "><p id="p3705122264210"><a name="p3705122264210"></a><a name="p3705122264210"></a>Obtains the number of remaining ticks of a software timer.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section1344817403575"></a>

The typical development process of software timers is as follows:

1.  Configure the software timer.
    -   Check that  **LOSCFG\_BASE\_CORE\_SWTMR**  and  **LOSCFG\_BASE\_IPC\_QUEUE**  are enabled.
    -   Configure  **LOSCFG\_BASE\_CORE\_SWTMR\_LIMIT**  \(maximum number of software timers supported by the system\).
    -   Configure  **OS\_SWTMR\_HANDLE\_QUEUE\_SIZE**  \(maximum length of the software timer queue\).

2.  Call  **LOS\_SwtmrCreate**  to create a software timer.
    -   Create a software timer with the specified timing duration, timeout handling function, and triggering mode.
    -   Return the function execution result \(success or failure\).

3.  Call  **LOS\_SwtmrStart**  to start the software timer.
4.  Call  **LOS\_SwtmrTimeGet**  to obtain the remaining number of ticks of the software timer.
5.  Call  **LOS\_SwtmrStop**  to stop the software timer.
6.  Call  **LOS\_SwtmrDelete**  to delete the software timer.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Avoid too many operations in the callback function of the software timer. Do not use APIs or perform operations that may cause task suspension or blocking.
>-   The software timers use a queue and a task resource of the system. The priority of the software timer tasks is set to  **0**  and cannot be changed.
>-   The number of software timer resources that can be configured in the system is the total number of software timer resources available to the entire system, not the number of software timer resources available to users. For example, if the system software timer occupies one more resource, the number of software timer resources available to users decreases by one.
>-   If a one-shot software timer is created, the system automatically deletes the timer and reclaims resources after the timer times out and the callback function is executed.
>-   For a one-shot software timer that will not be automatically deleted after expiration, you need to call  **LOS\_SwtmrDelete**  to delete it and reclaim the timer resource to prevent resource leakage.

### Development Example<a name="section114416313585"></a>

Prerequisites:

-   In  **los\_config.h**,  **LOSCFG\_BASE\_CORE\_SWTMR**  is enabled.
-   The maximum number of software timers supported by the system \(**LOSCFG\_BASE\_CORE\_SWTMR\_LIMIT**\) is configured.
-   The maximum length of the software timer queue \(**OS\_SWTMR\_HANDLE\_QUEUE\_SIZE**\) is configured.

**Sample Code**

```
#include "los_swtmr.h"

void Timer1_Callback(uint32_t arg);
void Timer2_Callback(uint32_t arg);

UINT32 g_timercount1 = 0;
UINT32 g_timercount2 = 0;

void Timer1_Callback(uint32_t arg) // Callback function 1
{
    unsigned long tick_last1;
    g_timercount1++;
    tick_last1=(UINT32)LOS_TickCountGet(); // Obtain the current number of ticks.
    PRINTK("g_timercount1=%d\n",g_timercount1);
    PRINTK("tick_last1=%d\n",tick_last1);
}

void Timer2_Callback(uint32_t arg) // Callback function 2
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

    /* Create a one-shot software timer, with the number of ticks set to 1000. When the number of ticks reaches 1000, callback function 1 is executed. */
    LOS_SwtmrCreate (1000, LOS_SWTMR_MODE_ONCE, Timer1_Callback, &id1, 1);

    /* Create a periodic software timer and execute callback function 2 every 100 ticks. */
    LOS_SwtmrCreate(100, LOS_SWTMR_MODE_PERIOD, Timer2_Callback, &id2, 1);
    PRINTK("create Timer1 success\n");

    LOS_SwtmrStart (id1); // Start the one-shot software timer.
    dprintf("start Timer1 success\n");
    LOS_TaskDelay(200); // Delay 200 ticks.
    LOS_SwtmrTimeGet(id1, &uwTick); // Obtain the number of remaining ticks of the one-short software timer.
    PRINTK("uwTick =%d\n", uwTick);

    LOS_SwtmrStop(id1); // Stop the software timer.
    PRINTK("stop Timer1 success\n");

    LOS_SwtmrStart(id1);
    LOS_TaskDelay(1000);
    LOS_SwtmrDelete(id1); // Delete the software timer.
    PRINTK("delete Timer1 success\n");

    LOS_SwtmrStart(id2); // Start the periodic software timer.
    PRINTK("start Timer2\n");

    LOS_TaskDelay(1000);
    LOS_SwtmrStop(id2);
    LOS_SwtmrDelete(id2);
}
```

**Output**

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

