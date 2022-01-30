# Basic Concepts<a name="EN-US_TOPIC_0000001124074751"></a>

The software timer is a software-simulated timer based on system tick interrupts. When the preset tick counter value has elapsed, the user-defined callback will be invoked. The timing precision is related to the cycle of the system tick clock.

Due to the limitation in hardware, the number of hardware timers cannot meet users' requirements. Therefore, the OpenHarmony LiteOS-M kernel provides the software timer function. The software timer allows more timing services to be created, increasing the number of timers.

The software timer supports the following functions:

-   Disabling the software timer using a macro
-   Creating a software timer
-   Starting a software timer
-   Stopping a software timer
-   Deleting a software timer
-   Obtaining the number of remaining ticks of a software timer

## Working Principles<a name="section070665816719"></a>

The software timer is a system resource. When modules are initialized, a contiguous section of memory is allocated for software timers. The maximum number of timers supported by the system is configured by the  **LOSCFG\_BASE\_CORE\_SWTMR\_LIMIT**  macro in  **los\_config.h**.

Software timers use a queue and a task resource of the system. The software timers are triggered based on the First In First Out \(FIFO\) rule. A timer with a shorter value is always closer to the queue head than a timer with a longer value, and is preferentially triggered.

The software timer counts time in ticks. When a software timer is created and started, the OpenHarmony LiteOS-M kernel determines the timer expiry time based on the current system time \(in ticks\) and the timing interval set by the user, and adds the timer control structure to the global timing list.

When a tick interrupt occurs, the tick interrupt handler scans the global timing list for expired timers. If such timers are found, the timers are recorded.

When the tick interrupt handling function is complete, the software timer task \(with the highest priority\) is woken up. In this task, the timeout callback function for the recorded timer is called.

### Timer States<a name="section115453813506"></a>

-   OS\_SWTMR\_STATUS\_UNUSED

The timer is not in use. When the timer module is initialized, all timer resources in the system are set to this state.

-   OS\_SWTMR\_STATUS\_CREATED

The timer is created but not started or the timer is stopped. When  **LOS\_SwtmrCreate**  is called for a timer that is not in use or  **LOS\_SwtmrStop**  is called for a newly started timer, the timer changes to this state.

-   OS\_SWTMR\_STATUS\_TICKING

The timer is running \(counting\). When  **LOS\_SwtmrStart**  is called for a newly created timer, the timer enters this state.

### Timer Modes<a name="section137521353175010"></a>

The OpenHarmony LiteOS-M kernel provides three types of software timers:

-   One-shot timer: Once started, the timer is automatically deleted after triggering only one timer event.
-   Periodic timer: This type of timer periodically triggers timer events until it is manually stopped.
-   One-shot timer deleted by calling an API

