# Event

## Basic Concepts<a name="section122115620816"></a>

An event is a mechanism for communication between tasks. It can be used to synchronize tasks.

In multi-task environment, synchronization is required between tasks. Events can be used for synchronization in the following cases:

-   One-to-many synchronization: A task waits for the triggering of multiple events. A task is woken up by one or multiple events.
-   Many-to-many synchronization: Multiple tasks wait for the triggering of multiple events.

The event mechanism provided by the OpenHarmony LiteOS-A event module has the following features:

-   A task triggers or waits for an event by creating an event control block.
-   Events are independent of each other. The internal implementation is a 32-bit unsigned integer, and each bit indicates an event type. The 25th bit is unavailable. Therefore, a maximum of 31 event types are supported.
-   Events are used only for synchronization between tasks, but not for data transmission.
-   Writing the same event type to the event control block for multiple times is equivalent to writing the event type only once before the event control block is cleared.
-   Multiple tasks can read and write the same event.
-   The event read/write timeout mechanism is supported.

## Working Principles<a name="section94611116593"></a>

### Event Control Block<a name="section1161415384467"></a>

```
/**
* Event control block data structure
  */
typedef struct tagEvent {
    UINT32 uwEventID;        /* Event set, which is a collection of events processed (written and cleared). */
    LOS_DL_LIST stEventList; /* List of tasks waiting for specific events */
} EVENT_CB_S, *PEVENT_CB_S;
```

### Working Principles<a name="section187761153144617"></a>

**Initializing an event**: An event control block is created to maintain a collection of processed events and a linked list of tasks waiting for specific events.

**Writing an event**: When a specified event is written to the event control block, the event control block updates the event set, traverses the task linked list, and determines whether to wake up related task based on the task conditions.

**Reading an event**: If the read event already exists, it is returned synchronously. In other cases, the return time is determined based on the timeout period and event triggering status. If the wait event condition is met before the timeout period expires, the blocked task will be directly woken up. Otherwise, the blocked task will be woken up only after the timeout period has expired.

The input parameters  **eventMask**  and  **mode**  determine whether the condition for reading an event is met.  **eventMask**  indicates the mask of the event.  **mode**  indicates the handling mode, which can be any of the following:

-   **LOS\_WAITMODE\_AND**: Event reading is successful only when all the events corresponding to  **eventMask**  occur. Otherwise, the task will be blocked, or an error code will be returned.
-   **LOS\_WAITMODE\_OR**: Event reading is successful when any of the events corresponding to  **eventMask**  occurs. Otherwise, the task will be blocked, or an error code will be returned.
-   **LOS\_WAITMODE\_CLR**: This mode must be used with  **LOS\_WAITMODE\_AND**  or  **LOS\_WAITMODE\_OR**  \(LOS\_WAITMODE\_AND | LOS\_WAITMODE\_CLR or LOS\_WAITMODE\_OR | LOS\_WAITMODE\_CLR\). In this mode, if  **LOS\_WAITMODE\_AND**  or  **LOS\_WAITMODE\_OR**  is successful, the corresponding event type bit in the event control block will be automatically cleared.

**Clearing events**: Clear the event set of the event control block based on the specified mask. If the mask is  **0**, the event set will be cleared. If the mask is  **0xffff**, no event will be cleared, and the event set remains unchanged.

**Destroying an event**: Destroy the specified event control block.

**Figure  1**  Event working mechanism for small systems<a name="fig17799175324612"></a>  
![](figures/event-working-mechanism-for-small-systems.png "event-working-mechanism-for-small-systems")

## Development Guidelines<a name="section44744471891"></a>

### Available APIs<a name="section172373513919"></a>

The following table describes APIs available for the OpenHarmony LiteOS-A event module.

**Table  1**  Event module APIs

<a name="table1415203765610"></a>
<table><thead align="left"><tr id="row134151837125611"><th class="cellrowborder" valign="top" width="12.85128512851285%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="29.8029802980298%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0415737175610"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p9598124913544"><a name="p9598124913544"></a><a name="p9598124913544"></a>Initializing events</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p77891354175812"><a name="p77891354175812"></a><a name="p77891354175812"></a>LOS_EventInit</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p2334141425515"><a name="p2334141425515"></a><a name="p2334141425515"></a>Initializes an event control block.</p>
</td>
</tr>
<tr id="row421753455514"><td class="cellrowborder" rowspan="2" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p13441112105813"><a name="p13441112105813"></a><a name="p13441112105813"></a>Reading/Writing events</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p17234205011559"><a name="p17234205011559"></a><a name="p17234205011559"></a>LOS_EventRead</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p1621275475517"><a name="p1621275475517"></a><a name="p1621275475517"></a>Reads a specified type of event, with the timeout period of a relative time period in ticks.</p>
</td>
</tr>
<tr id="row13129193718555"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17477615564"><a name="p17477615564"></a><a name="p17477615564"></a>LOS_EventWrite</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p10271958567"><a name="p10271958567"></a><a name="p10271958567"></a>Writes a specified type of event.</p>
</td>
</tr>
<tr id="row1831124035511"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p1313401559"><a name="p1313401559"></a><a name="p1313401559"></a>Clearing events</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p7788152419567"><a name="p7788152419567"></a><a name="p7788152419567"></a>LOS_EventClear</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p14862153525620"><a name="p14862153525620"></a><a name="p14862153525620"></a>Clears a specified type of event.</p>
</td>
</tr>
<tr id="row1525316428553"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p4253144265519"><a name="p4253144265519"></a><a name="p4253144265519"></a>Checking the event mask</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p768611115563"><a name="p768611115563"></a><a name="p768611115563"></a>LOS_EventPoll</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p13998115465617"><a name="p13998115465617"></a><a name="p13998115465617"></a>Returns whether the event input by the user meets the expectation based on the event ID, event mask, and read mode passed by the user.</p>
</td>
</tr>
<tr id="row6447135825614"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p104471658155615"><a name="p104471658155615"></a><a name="p104471658155615"></a>Destroying events</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p15259169573"><a name="p15259169573"></a><a name="p15259169573"></a>LOS_EventDestroy</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p32592615573"><a name="p32592615573"></a><a name="p32592615573"></a>Destroys a specified event control block.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section1118215161013"></a>

The typical event development process is as follows:

1.  Initialize an event control block.
2.  Block a read event control block.
3.  Write related events.
4.  Wake up a blocked task, read the event, and check whether the event meets conditions.
5.  Handle the event control block.
6.  Destroy an event control block.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   When an event is read or written, the 25th bit of the event is reserved and cannot be set.
>-   Repeated writes of the same event are treated as one write.

## Development Example<a name="section5837165132911"></a>

### Example Description<a name="section128221510145718"></a>

In this example, run the  **Example\_TaskEntry**  task to create the  **Example\_Event**  task, run the  **Example\_Event**  task to read an event to trigger task switching, and run the  **Example\_TaskEntry**  task to write an event. You can understand the task switching during event operations based on the sequence in which logs are recorded.

1.  Create the  **Example\_Event**  task in the  **Example\_TaskEntry**  task with a higher priority than the  **Example\_TaskEntry**  task.
2.  Run the  **Example\_Event**  task to read event  **0x00000001**. Task switching is triggered to execute the  **Example\_TaskEntry**  task.
3.  Run the  **Example\_TaskEntry**  task to write event  **0x00000001**. Task switching is triggered to execute the  **Example\_Event**  task.
4.  The  **Example\_Event**  task is executed.
5.  The  **Example\_TaskEntry**  task is executed.

### Sample Code<a name="section71507479577"></a>

The sample code is as follows:

```
#include "los_event.h"
#include "los_task.h"
#include "securec.h"

/* Task ID*/
UINT32 g_testTaskId;

/* Event control structure*/ 
EVENT_CB_S g_exampleEvent;

/* Type of the wait event*/
#define EVENT_WAIT 0x00000001

/* Example task entry function*/
VOID Example_Event(VOID)
{
     UINT32 event;

    /* Set a timeout period for event reading to 100 ticks. If the specified event is not read within 100 ticks, the read operation times out and the task is woken up.*/
    printf("Example_Event wait event 0x%x \n", EVENT_WAIT);

    event = LOS_EventRead(&g_exampleEvent, EVENT_WAIT, LOS_WAITMODE_AND, 100);
    if (event == EVENT_WAIT) {
        printf("Example_Event,read event :0x%x\n", event);
    } else {
        printf("Example_Event,read event timeout\n");
    }
}

UINT32 Example_EventEntry(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S task1;

    /* Initialize the event.*/ 
    ret = LOS_EventInit(&g_exampleEvent);
    if (ret != LOS_OK) {
        printf("init event failed .\n");
        return -1;
    }

    /* Create a task.*/ 
    (VOID)memset_s(&task1, sizeof(TSK_INIT_PARAM_S), 0, sizeof(TSK_INIT_PARAM_S));
    task1.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Event;
    task1.pcName       = "EventTsk1";
    task1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task1.usTaskPrio   = 5;
    ret = LOS_TaskCreate(&g_testTaskId, &task1);
    if (ret != LOS_OK) {
        printf("task create failed.\n");
        return LOS_NOK;
    }

    /* Write the task wait event (g_testTaskId). */
    printf("Example_TaskEntry write event.\n");

    ret = LOS_EventWrite(&g_exampleEvent, EVENT_WAIT);
    if (ret != LOS_OK) {
        printf("event write failed.\n");
        return LOS_NOK;
    }

    /* Clear the flag.*/ 
    printf("EventMask:%d\n", g_exampleEvent.uwEventID);
    LOS_EventClear(&g_exampleEvent, ~g_exampleEvent.uwEventID);
    printf("EventMask:%d\n", g_exampleEvent.uwEventID);

    /* Delete the task.*/ 
    ret = LOS_TaskDelete(g_testTaskId);
    if (ret != LOS_OK) {
        printf("task delete failed.\n");
        return LOS_NOK;
    }

    return LOS_OK;
}
```

### Verification<a name="section16570171645813"></a>

The development is successful if the return result is as follows:

```
Example_Event wait event 0x1 
Example_TaskEntry write event.
Example_Event,read event :0x1
EventMask:1
EventMask:0
```

