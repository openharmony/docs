# Software Timer


## Basic Concepts

The software timer is a software-simulated timer based on system tick interrupts. When the preset tick counter value has elapsed, the user-defined callback will be invoked. The timing precision is related to the cycle of the system tick clock.

Due to the limitation in hardware, the number of hardware timers cannot meet users' requirements. Therefore, the OpenHarmony LiteOS-M kernel provides the software timer function. The software timer allows more timing services to be created, increasing the number of timers.

The software timer supports the following functions:

- Disabling the software timer using a macro

- Creating a software timer

- Starting a software timer

- Stopping a software timer

- Deleting a software timer

- Obtaining the number of remaining ticks of a software timer


## Working Principles

The software timer is a system resource. When modules are initialized, a contiguous section of memory is allocated for software timers. The maximum number of timers supported by the system is configured by the **LOSCFG_BASE_CORE_SWTMR_LIMIT** macro in **los_config.h**.

Software timers use a queue and a task resource of the system. The software timers are triggered based on the First In First Out (FIFO) rule. A timer with a shorter value is always closer to the queue head than a timer with a longer value, and is preferentially triggered.

The software timer counts time in ticks. When a software timer is created and started, the OpenHarmony LiteOS-M kernel determines the timer expiry time based on the current system time (in ticks) and the timing interval set by the user, and adds the timer control structure to the global timing list.

When a tick interrupt occurs, the tick interrupt handler scans the global timing list for expired timers. If such timers are found, the timers are recorded.

When the tick interrupt handling function is complete, the software timer task (with the highest priority) is woken up. In this task, the timeout callback function for the recorded timer is called.


### Timer States

- OS_SWTMR_STATUS_UNUSED
  
  The timer is not in use. When the timer module is initialized, all timer resources in the system are set to this state.
- OS_SWTMR_STATUS_CREATED
  
  The timer is created but not started or the timer is stopped. When **LOS_SwtmrCreate** is called for a timer that is not in use or **LOS_SwtmrStop** is called for a newly started timer, the timer changes to this state.
  
- OS_SWTMR_STATUS_TICKING
  
  The timer is running (counting). When **LOS_SwtmrStart** is called for a newly created timer, the timer enters this state.


### Timer Modes

The OpenHarmony LiteOS-M kernel provides the following types of software timers:

- One-shot timer: Once started, the timer is automatically deleted after triggering only one timer event.

- Periodic timer: This type of timer periodically triggers timer events until it is manually stopped.

- One-shot timer deleted by calling an API


## Available APIs

The following table describes APIs available for the OpenHarmony LiteOS-M software timer module. For more details about the APIs, see the API reference.

  **Table 1** Software timer APIs

| API| Description|
| -------- | -------- |
| LOS_SwtmrCreate| Creates a timer.|
| LOS_SwtmrDelete| Deletes a timer.|
| LOS_SwtmrStart| Starts a timer.|
| LOS_SwtmrStop| Stops a timer.|
| LOS_SwtmrTimeGet| Obtains the remaining ticks of a software timer.|


## How to Develop

The typical development process of software timers is as follows:

1. Configure the software timer.
   - Check that **LOSCFG_BASE_CORE_SWTMR** and **LOSCFG_BASE_IPC_QUEUE** are set to **1**.
   - Configure **LOSCFG_BASE_CORE_SWTMR_LIMIT** (maximum number of software timers supported by the system).
   - Configure **OS_SWTMR_HANDLE_QUEUE_SIZE** (maximum length of the software timer queue).

2. Call **LOS_SwtmrCreate** to create a software timer.
   - Create a software timer with the specified timing duration, timeout handling function, and triggering mode.
   - Return the function execution result (success or failure).

3. Call **LOS_SwtmrStart** to start the software timer.

4. Call **LOS_SwtmrTimeGet** to obtain the remaining number of ticks of the software timer.

5. Call **LOS_SwtmrStop** to stop the software timer.

6. Call **LOS_SwtmrDelete** to delete the software timer.

>![](../public_sys-resources/icon-note.gif) **NOTE**
> - Avoid too many operations in the callback function of the software timer. Do not use APIs or perform operations that may cause task suspension or blocking.
> 
> - The software timers use a queue and a task resource of the system. The priority of the software timer tasks is set to **0** and cannot be changed.
> 
> - The number of software timer resources that can be configured in the system is the total number of software timer resources available to the entire system, not the number of software timer resources available to users. For example, if the system software timer occupies one more resource, the number of software timer resources available to users decreases by one.
> 
> - If a one-shot software timer is created, the system automatically deletes the timer and reclaims resources after the timer times out and the callback function is executed.
> 
> - For a one-shot software timer that will not be automatically deleted after expiration, you need to call **LOS_SwtmrDelete** to delete it and reclaim the timer resource to prevent resource leakage.


## Development Example


### Example Description

The following programming example demonstrates how to:

1. Create, start, delete, pause, and restart a software timer.

2. Use a one-shot software timer and a periodic software timer


### Sample Code

Prerequisites

- In **los_config.h**, **LOSCFG_BASE_CORE_SWTMR** is enabled.

- In **los_config.h**, **LOSCFG_BASE_CORE_SWTMR_ALIGN** is disabled. The sample code does not involve timer alignment.

- The maximum number of software timers supported by the system (**LOSCFG_BASE_CORE_SWTMR_LIMIT**) is configured.

- The maximum length of the software timer queue (OS_SWTMR_HANDLE_QUEUE_SIZE) is configured.

The sample code is as follows:


```
#include "los_swtmr.h"

/* Timer count */
UINT32 g_timerCount1 = 0;   
UINT32 g_timerCount2 = 0;

/* Task ID*/
UINT32 g_testTaskId01;

void Timer1_Callback(UINT32 arg) //Callback 1
{
    UINT32 tick_last1;
    g_timerCount1++;
    tick_last1 = (UINT32)LOS_TickCountGet(); // Obtain the current number of ticks.
    printf("g_timerCount1=%d, tick_last1=%d\n", g_timerCount1, tick_last1);
}  

void Timer2_Callback(UINT32 arg) //Callback 2
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

    /* Create a one-shot software timer, with the number of ticks set to 1000. When the number of ticks reaches 1000, callback function 1 is executed. */
    LOS_SwtmrCreate(1000, LOS_SWTMR_MODE_ONCE, Timer1_Callback, &id1, 1);

    /* Create a periodic software timer and execute callback function 2 every 100 ticks. */
    LOS_SwtmrCreate(100, LOS_SWTMR_MODE_PERIOD, Timer2_Callback, &id2, 1);
    printf("create Timer1 success\n");

    LOS_SwtmrStart(id1); // Start the one-shot software timer.
    printf("start Timer1 success\n");

    LOS_TaskDelay(200); // Delay 200 ticks.
    LOS_SwtmrTimeGet(id1, &tickCount);  // Obtain the number of remaining ticks of the one-short software timer.
    printf("tickCount=%d\n", tickCount);

    LOS_SwtmrStop(id1); // Stop the software timer.
    printf("stop Timer1 success\n");

    LOS_SwtmrStart(id1);
    LOS_TaskDelay(1000);

    LOS_SwtmrStart(id2); // Start the periodic software timer.
    printf("start Timer2\n");

    LOS_TaskDelay(1000);
    LOS_SwtmrStop(id2);
    ret = LOS_SwtmrDelete(id2);  // Delete the software timer.
    if (ret == LOS_OK) {
        printf("delete Timer2 success\n");
    }
}

UINT32 Example_TaskEntry(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S task1;

    /* Lock task scheduling. */
    LOS_TaskLock();

    /* Create task 1. */
    (VOID)memset(&task1, 0, sizeof(TSK_INIT_PARAM_S));
    task1.pfnTaskEntry = (TSK_ENTRY_FUNC)Timer_example;
    task1.pcName       = "TimerTsk";
    task1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task1.usTaskPrio   = 5;
    ret = LOS_TaskCreate(&g_testTaskId01, &task1);
    if (ret != LOS_OK) {
        printf("TimerTsk create failed.\n");
        return LOS_NOK;
    }

    /* Unlock task scheduling. */
    LOS_TaskUnlock();

    return LOS_OK;
}
```


### Verification

The output is as follows:


```
create Timer1 success
start Timer1 success
tickCount=798
stop Timer1 success
g_timerCount1=1, tick_last1=1208
delete Timer1 success
start Timer2
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
delete Timer2 success
```
