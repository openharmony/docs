# Event


## Basic Concepts

An event is a communication mechanism used to synchronize tasks.

In multi-task environment, synchronization is required between tasks. Events can be used for synchronization in the following cases:

- One-to-many synchronization: A task waits for the triggering of multiple events. A task can be woken up by one or multiple events.

- Many-to-many synchronization: Multiple tasks wait for the triggering of multiple events.

The event mechanism provided by the OpenHarmony LiteOS-A event module has the following features:

- A task triggers or waits for an event by creating an event control block.

- Events are independent of each other. The internal implementation is a 32-bit unsigned integer, and each bit indicates an event type. The value **0** indicates that the event type does not occur, and the value **1** indicates that the event type has occurred. There are 31 event types in total. The 25th bit (`0x02U << 24`) is reserved.

- Events are used for task synchronization, but not for data transmission.

- Writing the same event type to an event control block multiple times is equivalent to writing the event type only once before the event control block is cleared.

- Multiple tasks can read and write the same event.

- The event read/write timeout mechanism is supported.


## Working Principles


### Event Control Block


```
/**
  * Event control block data structure
  */
typedef struct tagEvent {
    UINT32 uwEventID;        /* Event set, which is a collection of events processed (written and cleared). */
    LOS_DL_LIST stEventList; /* List of tasks waiting for specific events. */
} EVENT_CB_S, *PEVENT_CB_S;
```


### Working Principles

**Initializing an Event**

An event control block is created to maintain a set of processed events and a linked list of tasks waiting for specific events.

**Writing an Event**

When an event is written to the event control block, the event control block updates the event set, traverses the task linked list, and determines whether to wake up related task based on the specified conditions.

**Reading an Event**

If the event to read already exists, it is returned synchronously. In other cases, the event is returned based on the timeout period and event triggering conditions. If the wait condition is met before the timeout period expires, the blocked task will be directly woken up. Otherwise, the blocked task will be woken up only after the timeout period has expired.

The parameters **eventMask** and **mode** determine whether the condition for reading an event is met. **eventMask** specifies the event mask. **mode** specifies the handling mode, which can be any of the following:

- **LOS_WAITMODE_AND**: Read the event only when all the events corresponding to **eventMask** occur. Otherwise, the task will be blocked, or an error code will be returned.

- **LOS_WAITMODE_OR**: Read the event only when any of the events corresponding to **eventMask** occur. Otherwise, the task will be blocked, or an error code will be returned.

- **LOS_WAITMODE_CLR**: This mode must be used with one or all of the event modes (LOS_WAITMODE_AND | LOS_WAITMODE_CLR or LOS_WAITMODE_OR | LOS_WAITMODE_CLR). In this mode, if all event modes or any event mode is successful, the corresponding event type bit in the event control block will be automatically cleared.

**Clearing Events**

The events in the event set of the event control block can be cleared based on the specified mask. The mask **0** means to clear the event set; the mask **0xffff** means the opposite.

**Destroying Events**

The event control block can be destroyed to release resources.

**Figure 1** Event working mechanism for small systems

  ![](figures/event-working-mechanism-for-small-systems.png "event-working-mechanism-for-small-systems")


## Development Guidelines


### Available APIs

The following table describes APIs available for the OpenHarmony LiteOS-A event module.

**Table 1** APIs of the event module

| Category| API Description |
| -------- | -------- |
| Initializing an event| **LOS_EventInit**: initializes an event control block.|
| Reading/Writing an event| - **LOS_EventRead**: reads an event, with a relative timeout period in ticks.<br>- **LOS_EventWrite**: writes an event. |
| Clearing events| **LOS_EventClear**: clears a specified type of events.|
| Checking the event mask| **LOS_EventPoll**: checks whether the specified event occurs.|
| Destroying events | **LOS_EventDestroy**: destroys an event control block.|


### How to Develop

The typical event development process is as follows:

1. Initialize an event control block.

2. Block a read event.

3. Write related events.

4. Wake up a blocked task, read the event, and check whether the event meets conditions.

5. Handle the event control block.

6. Destroy an event control block.

> **NOTE**
>
> - For event read and write operations, the 25th bit (`0x02U << 24`) of the event is reserved and cannot be set.
>
> - Repeated writes of the same event are treated as one write.


## Development Example


### Example Description

In this example, run the **Example_TaskEntry** task to create the **Example_Event** task. Run the **Example_Event** task to read an event to trigger task switching. Run the **Example_TaskEntry** task to write an event. You can understand the task switching during event operations based on the sequence in which logs are recorded.

1. Create the **Example_Event** task in the **Example_TaskEntry** task with a higher priority than the **Example_TaskEntry** task.

2. Run the **Example_Event** task to read event **0x00000001**. Task switching is triggered to execute the **Example_TaskEntry** task.

3. Run the **Example_TaskEntry** task to write event **0x00000001**. Task switching is triggered to execute the **Example_Event** task.

4. The **Example_Event** task is executed.

5. The **Example_TaskEntry** task is executed.


### Sample Code

The sample code can be compiled and verified in **./kernel/liteos_a/testsuites/kernel/src/osTest.c**. The **Example_EventEntry** function is called in **TestTaskEntry**.

The sample code is as follows:

```
#include "los_event.h"
#include "los_task.h"
#include "securec.h"

/* Task ID */
UINT32 g_testTaskId;

/* Event control structure */ 
EVENT_CB_S g_exampleEvent;

/* Type of the wait event */
#define EVENT_WAIT      0x00000001
#define EVENT_TIMEOUT   500
/* Example task entry function */
VOID Example_Event(VOID)
{
     UINT32 event;

    /* Set a timeout period for event reading to 100 ticks. If the specified event is not read within 100 ticks, the read operation times out and the task is woken up. */
    dprintf("Example_Event wait event 0x%x \n", EVENT_WAIT);

    event = LOS_EventRead(&g_exampleEvent, EVENT_WAIT, LOS_WAITMODE_AND, EVENT_TIMEOUT);
    if (event == EVENT_WAIT) {
        dprintf("Example_Event,read event :0x%x\n", event);
    } else {
        dprintf("Example_Event,read event timeout\n");
    }
}

UINT32 Example_EventEntry(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S task1;

    /* Initialize the event. */
    ret = LOS_EventInit(&g_exampleEvent);
    if (ret != LOS_OK) {
        dprintf("init event failed .\n");
        return -1;
    }

    /* Create a task. */
    (VOID)memset_s(&task1, sizeof(TSK_INIT_PARAM_S), 0, sizeof(TSK_INIT_PARAM_S));
    task1.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Event;
    task1.pcName       = "EventTsk1";
    task1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task1.usTaskPrio   = 5;
    ret = LOS_TaskCreate(&g_testTaskId, &task1);
    if (ret != LOS_OK) {
        dprintf("task create failed.\n");
        return LOS_NOK;
    }

    /* Write the task wait event (g_testTaskId). */
    dprintf("Example_TaskEntry write event.\n");

    ret = LOS_EventWrite(&g_exampleEvent, EVENT_WAIT);
    if (ret != LOS_OK) {
        dprintf("event write failed.\n");
        return LOS_NOK;
    }

    /* Clear the flag. */
    dprintf("EventMask:%d\n", g_exampleEvent.uwEventID);
    LOS_EventClear(&g_exampleEvent, ~g_exampleEvent.uwEventID);
    dprintf("EventMask:%d\n", g_exampleEvent.uwEventID);

    return LOS_OK;
}
```


### Verification

The development is successful if the return result is as follows:


```
Example_Event wait event 0x1 
Example_TaskEntry write event.
Example_Event,read event :0x1
EventMask:1
EventMask:0
```
