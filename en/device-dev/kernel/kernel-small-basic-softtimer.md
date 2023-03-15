# Software Timer


## Basic Concepts

The software timer is a software-simulated timer based on system tick interrupts. When the preset tick counter value has elapsed, the user-defined callback will be invoked. The timing precision is related to the cycle of the system tick clock.

Due to the limitation in hardware, the number of hardware timers cannot meet users' requirements. The OpenHarmony LiteOS-A kernel provides the software timer function.

The software timer allows more timing services to be created, increasing the number of timers.

The software timer supports the following functions:

- Disabling the software timer using a macro

- Creating a software timer

- Starting a software timer

- Stopping a software timer

- Deleting a software timer

- Obtaining the number of remaining ticks of a software timer


## Working Principles

The software timer is a system resource. When modules are initialized, a contiguous section of memory is allocated for software timers. The maximum number of timers supported by the system is configured by the **LOSCFG_BASE_CORE_SWTMR_LIMIT** macro in **los_config.h**.

Software timers use a queue and a task resource of the system. The software timers are triggered based on the First In First Out (FIFO) rule. For the timers set at the same time, the timer with a shorter value is always closer to the queue head than the timer with a longer value, and is preferentially triggered.

The software timer counts time in ticks. When a software timer is created and started, the OpenHarmony system determines the timer expiry time based on the current system time (in ticks) and the timing interval set by the user, and adds the timer control structure to the global timing list.

When a tick interrupt occurs, the tick interrupt handler scans the global timing list for expired timers. If such timers are found, the timers are recorded.

When the tick interrupt handler is complete, the software timer task (with the highest priority) will be woken up. In this task, the timeout callback for the recorded timer is called.

A software timer can be in any of the following states:

- OS_SWTMR_STATUS_UNUSED
  
  The timer is not in use. When the timer module is initialized, all timer resources in the system are set to this state.
  
- OS_SWTMR_STATUS_CREATED

  The timer is created but not started or the timer is stopped. When **LOS_SwtmrCreate** is called for a timer that is not in use or **LOS_SwtmrStop** is called for a newly started timer, the timer changes to this state.

- OS_SWTMR_STATUS_TICKING

  The timer is running (counting). When **LOS_SwtmrStart** is called for a newly created timer, the timer enters this state.

OpenHarmony provides three types of software timers:

-   One-shot timer: Once started, the timer is automatically deleted after triggering only one timer event.
-   Periodic timer: This type of timer periodically triggers timer events until it is manually stopped.
-   One-shot timer deleted by calling an API


## Development Guidelines


### Available APIs

The following table describes the APIs of the software timer module of the OpenHarmony LiteOS-A kernel.

**Table 1** APIs for software timers

| Category              | Description                                                    |
| ---------------------- | ------------------------------------------------------------ |
| Creating or deleting a timer      | **LOS_SwtmrCreate**: creates a software timer.<br>**LOS_SwtmrDelete**: deletes a software timer.|
| Starting or stopping a timer      | **LOS_SwtmrStart**: starts a software timer.<br>**LOS_SwtmrStop**: stops a software timer.|
| Obtaining remaining ticks of a software timer| **LOS_SwtmrTimeGet**: obtains the remaining ticks of a software timer.                  |


### How to Develop

The typical development process of software timers is as follows:

1. Configure the software timer.
   - Check that **LOSCFG_BASE_CORE_SWTMR** and **LOSCFG_BASE_IPC_QUEUE** are enabled.
   - Configure **LOSCFG_BASE_CORE_SWTMR_LIMIT** (maximum number of software timers supported by the system).
   - Configure **OS_SWTMR_HANDLE_QUEUE_SIZE** (maximum length of the software timer queue).

2. Call **LOS_SwtmrCreate** to create a software timer.
   - Create a software timer with the specified timing duration, timeout handling function, and triggering mode.
   - Return the function execution result (success or failure).

3. Call **LOS_SwtmrStart** to start the software timer.

4. Call **LOS_SwtmrTimeGet** to obtain the remaining number of ticks of the software timer.

5. Call **LOS_SwtmrStop** to stop the software timer.

6. Call **LOS_SwtmrDelete** to delete the software timer.

> **NOTE**<br>
>
> - Avoid too many operations in the callback of the software timer. Do not use APIs or perform operations that may cause task suspension or blocking.
>
> - The software timers use a queue and a task resource of the system. The priority of the software timer tasks is set to **0** and cannot be changed.
>
> - The number of software timer resources that can be configured in the system is the total number of software timer resources available to the entire system, not the number of software timer resources available to users. For example, if the system software timer occupies one more resource, the number of software timer resources available to users decreases by one.
>
> - If a one-shot software timer is created, the system automatically deletes the timer and reclaims resources after the timer times out and the callback is invoked.
>
> - For a one-shot software timer that will not be automatically deleted after expiration, you need to call **LOS_SwtmrDelete** to delete it and reclaim the timer resource to prevent resource leakage.


### Development Example

**Prerequisites**

- In **los_config.h**, **LOSCFG_BASE_CORE_SWTMR** is enabled.
- The maximum number of software timers supported by the system (**LOSCFG_BASE_CORE_SWTMR_LIMIT**) is configured.
- The maximum length of the software timer queue (**OS_SWTMR_HANDLE_QUEUE_SIZE**) is configured.

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

    /* Create a one-shot software timer, with the number of ticks set to 1000. Callback 1 will be invoked when the number of ticks reaches 1000. */
    LOS_SwtmrCreate (1000, LOS_SWTMR_MODE_ONCE, Timer1_Callback, &id1, 1);
    
    /* Create a periodic software timer and invoke callback 2 every 100 ticks. */
    LOS_SwtmrCreate(100, LOS_SWTMR_MODE_PERIOD, Timer2_Callback, &id2, 1);
    PRINTK("create Timer1 success\n");

    LOS_SwtmrStart(id1); // Start the one-shot software timer.
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
