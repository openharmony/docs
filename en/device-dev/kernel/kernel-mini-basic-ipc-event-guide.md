# Development Guidelines<a name="EN-US_TOPIC_0000001078876508"></a>

-   [Available APIs](#section158501652121514)
-   [How to Develop](#section783435801510)
-   [Development Example](#section460018317164)
    -   [Example Description](#section896412438910)
    -   [Sample Code](#section149077554912)
    -   [Verification](#section4461439172017)


## Available APIs<a name="section158501652121514"></a>

<a name="table14277123518139"></a>
<table><thead align="left"><tr id="row152771935131315"><th class="cellrowborder" valign="top" width="17.77177717771777%" id="mcps1.1.4.1.1"><p id="p1127733591316"><a name="p1127733591316"></a><a name="p1127733591316"></a>Category</p>
</th>
<th class="cellrowborder" valign="top" width="22.932293229322934%" id="mcps1.1.4.1.2"><p id="p22771357138"><a name="p22771357138"></a><a name="p22771357138"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="59.2959295929593%" id="mcps1.1.4.1.3"><p id="p327714358130"><a name="p327714358130"></a><a name="p327714358130"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1627793517136"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.1.4.1.1 "><p id="p10525141151410"><a name="p10525141151410"></a><a name="p10525141151410"></a>Checking events</p>
</td>
<td class="cellrowborder" valign="top" width="22.932293229322934%" headers="mcps1.1.4.1.2 "><p id="p1027783551315"><a name="p1027783551315"></a><a name="p1027783551315"></a>LOS_EventPoll</p>
</td>
<td class="cellrowborder" valign="top" width="59.2959295929593%" headers="mcps1.1.4.1.3 "><p id="p1717215119159"><a name="p1717215119159"></a><a name="p1717215119159"></a>Checks whether the expected event occurs based on <strong id="b1698610296113"><a name="b1698610296113"></a><a name="b1698610296113"></a>eventID</strong>, <strong id="b11901203414114"><a name="b11901203414114"></a><a name="b11901203414114"></a>eventMask</strong>, and <strong id="b1198339016"><a name="b1198339016"></a><a name="b1198339016"></a>mode</strong>.</p>
<div class="notice" id="note29631113132915"><a name="note29631113132915"></a><a name="note29631113132915"></a><span class="noticetitle"> NOTICE: </span><div class="noticebody"><p id="p886616817302"><a name="p886616817302"></a><a name="p886616817302"></a>If <strong id="b172231736214"><a name="b172231736214"></a><a name="b172231736214"></a>mode</strong> contains <strong id="b166781764215"><a name="b166781764215"></a><a name="b166781764215"></a>LOS_WAITMODE_CLR</strong> and the expected event occurs, the event that meets the requirements in <strong id="b194063713315"><a name="b194063713315"></a><a name="b194063713315"></a>eventID</strong> will be cleared. In this case, <strong id="b53278201333"><a name="b53278201333"></a><a name="b53278201333"></a>eventID</strong> is an input parameter and an output parameter. In other cases, <strong id="b1163116507319"><a name="b1163116507319"></a><a name="b1163116507319"></a>eventID</strong> is used only as an input parameter.</p>
</div></div>
</td>
</tr>
<tr id="row20278035131316"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.1.4.1.1 "><p id="p135816209511"><a name="p135816209511"></a><a name="p135816209511"></a>Initializing events</p>
</td>
<td class="cellrowborder" valign="top" width="22.932293229322934%" headers="mcps1.1.4.1.2 "><p id="p5361103903417"><a name="p5361103903417"></a><a name="p5361103903417"></a>LOS_EventInit</p>
</td>
<td class="cellrowborder" valign="top" width="59.2959295929593%" headers="mcps1.1.4.1.3 "><p id="p1936143993419"><a name="p1936143993419"></a><a name="p1936143993419"></a>Initializes an event control block.</p>
</td>
</tr>
<tr id="row1736713145208"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.1.4.1.1 "><p id="p65802020512"><a name="p65802020512"></a><a name="p65802020512"></a>Reading events</p>
</td>
<td class="cellrowborder" valign="top" width="22.932293229322934%" headers="mcps1.1.4.1.2 "><p id="p1436015394341"><a name="p1436015394341"></a><a name="p1436015394341"></a>LOS_EventRead</p>
</td>
<td class="cellrowborder" valign="top" width="59.2959295929593%" headers="mcps1.1.4.1.3 "><p id="p1935911398345"><a name="p1935911398345"></a><a name="p1935911398345"></a>Reads an event (wait event). The task is blocked to wait based on the timeout period (in ticks).</p>
<p id="p624360131813"><a name="p624360131813"></a><a name="p624360131813"></a>If no event is read, <strong id="b8113141912912"><a name="b8113141912912"></a><a name="b8113141912912"></a>0</strong> is returned.</p>
<p id="p825491321911"><a name="p825491321911"></a><a name="p825491321911"></a>If an event is successfully read, a positive value (event set) is returned.</p>
<p id="p262373895217"><a name="p262373895217"></a><a name="p262373895217"></a>In other cases, a specific error code is returned.</p>
</td>
</tr>
<tr id="row19475718122016"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.1.4.1.1 "><p id="p18580201754"><a name="p18580201754"></a><a name="p18580201754"></a>Writing events</p>
</td>
<td class="cellrowborder" valign="top" width="22.932293229322934%" headers="mcps1.1.4.1.2 "><p id="p1135843933412"><a name="p1135843933412"></a><a name="p1135843933412"></a>LOS_EventWrite</p>
</td>
<td class="cellrowborder" valign="top" width="59.2959295929593%" headers="mcps1.1.4.1.3 "><p id="p526932914325"><a name="p526932914325"></a><a name="p526932914325"></a>Writes a specific event to the event control block.</p>
</td>
</tr>
<tr id="row913918371962"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.1.4.1.1 "><p id="p13581201655"><a name="p13581201655"></a><a name="p13581201655"></a>Clearing events</p>
</td>
<td class="cellrowborder" valign="top" width="22.932293229322934%" headers="mcps1.1.4.1.2 "><p id="p12140137165"><a name="p12140137165"></a><a name="p12140137165"></a>LOS_EventClear</p>
</td>
<td class="cellrowborder" valign="top" width="59.2959295929593%" headers="mcps1.1.4.1.3 "><p id="p19140637968"><a name="p19140637968"></a><a name="p19140637968"></a>Clears an event in the event control block based on the event mask.</p>
</td>
</tr>
<tr id="row1173017715"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.1.4.1.1 "><p id="p1458102010519"><a name="p1458102010519"></a><a name="p1458102010519"></a>Destroying events</p>
</td>
<td class="cellrowborder" valign="top" width="22.932293229322934%" headers="mcps1.1.4.1.2 "><p id="p31740171"><a name="p31740171"></a><a name="p31740171"></a>LOS_EventDestroy</p>
</td>
<td class="cellrowborder" valign="top" width="59.2959295929593%" headers="mcps1.1.4.1.3 "><p id="p17171501971"><a name="p17171501971"></a><a name="p17171501971"></a>Destroys an event control block.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section783435801510"></a>

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

## Development Example<a name="section460018317164"></a>

### Example Description<a name="section896412438910"></a>

In this example, run the  **Example\_TaskEntry**  task to create the  **Example\_Event**  task. Run the  **Example\_Event**  task to read an event to trigger task switching. Run the  **Example\_TaskEntry**  task to write an event. You can understand the task switching during event operations based on the sequence in which logs are recorded.

1.  Create the  **Example\_Event**  task in the  **Example\_TaskEntry**  task with a higher priority than the  **Example\_TaskEntry**  task.
2.  Run the  **Example\_Event**  task to read event  **0x00000001**. Task switching occurs to execute the  **Example\_TaskEntry**  task.
3.  Run the  **Example\_TaskEntry**  task to write event  **0x00000001**. Task switching occurs to execute the  **Example\_Event**  task.
4.  The  **Example\_Event**  task is executed.
5.  The  **Example\_TaskEntry**  task is executed.

### Sample Code<a name="section149077554912"></a>

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
    UINT32 ret;
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

UINT32 Example_TaskEntry(VOID)
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
    task1.uwStackSize  = OS_TSK_DEFAULT_STACK_SIZE;
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

### Verification<a name="section4461439172017"></a>

The development is successful if the return result is as follows:

```
Example_Event wait event 0x1 
Example_TaskEntry write event.
Example_Event,read event :0x1
EventMask:1
EventMask:0
```

