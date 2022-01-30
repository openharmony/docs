# Development Guidelines<a name="EN-US_TOPIC_0000001123763635"></a>

## Available APIs<a name="section158501652121514"></a>

<a name="table10903105695114"></a>
<table><thead align="left"><tr id="row1293645645110"><th class="cellrowborder" valign="top" width="23.56%" id="mcps1.1.4.1.1"><p id="p59361562512"><a name="p59361562512"></a><a name="p59361562512"></a>Category</p>
</th>
<th class="cellrowborder" valign="top" width="24.29%" id="mcps1.1.4.1.2"><p id="p1393665645118"><a name="p1393665645118"></a><a name="p1393665645118"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="52.15%" id="mcps1.1.4.1.3"><p id="p119363564516"><a name="p119363564516"></a><a name="p119363564516"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1693665613516"><td class="cellrowborder" rowspan="2" valign="top" width="23.56%" headers="mcps1.1.4.1.1 "><p id="p193675615514"><a name="p193675615514"></a><a name="p193675615514"></a>Creating or deleting a message queue</p>
</td>
<td class="cellrowborder" valign="top" width="24.29%" headers="mcps1.1.4.1.2 "><p id="p11936115612514"><a name="p11936115612514"></a><a name="p11936115612514"></a>LOS_QueueCreate</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.1.4.1.3 "><p id="p1593620562517"><a name="p1593620562517"></a><a name="p1593620562517"></a>Creates a message queue. The system dynamically allocates the queue space.</p>
</td>
</tr>
<tr id="row79361156175113"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p893615567517"><a name="p893615567517"></a><a name="p893615567517"></a>LOS_QueueDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p4936155695111"><a name="p4936155695111"></a><a name="p4936155695111"></a>Deletes the specified queue based on the queue ID. </p>
</td>
</tr>
<tr id="row093614566519"><td class="cellrowborder" rowspan="3" valign="top" width="23.56%" headers="mcps1.1.4.1.1 "><p id="p1593685614513"><a name="p1593685614513"></a><a name="p1593685614513"></a>Reading or writing data in a queue (without the content contained in the address)</p>
</td>
<td class="cellrowborder" valign="top" width="24.29%" headers="mcps1.1.4.1.2 "><p id="p6936556155118"><a name="p6936556155118"></a><a name="p6936556155118"></a>LOS_QueueRead</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.1.4.1.3 "><p id="p11936556155118"><a name="p11936556155118"></a><a name="p11936556155118"></a>Reads data in the head node of the specified queue. The data in the queue node is an address.</p>
</td>
</tr>
<tr id="row199369565518"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p393655620513"><a name="p393655620513"></a><a name="p393655620513"></a>LOS_QueueWrite</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p12936256175120"><a name="p12936256175120"></a><a name="p12936256175120"></a>Writes the value of the input parameter <strong id="b13458132192018"><a name="b13458132192018"></a><a name="b13458132192018"></a>bufferAddr</strong> (buffer address) to the tail node of the specified queue.</p>
</td>
</tr>
<tr id="row1293615635114"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p893625665119"><a name="p893625665119"></a><a name="p893625665119"></a>LOS_QueueWriteHead</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p193620566515"><a name="p193620566515"></a><a name="p193620566515"></a>Writes the value of the input parameter <strong id="b20585155122116"><a name="b20585155122116"></a><a name="b20585155122116"></a>bufferAddr</strong> (buffer address) to the head node of the specified queue.</p>
</td>
</tr>
<tr id="row593675635117"><td class="cellrowborder" rowspan="3" valign="top" width="23.56%" headers="mcps1.1.4.1.1 "><p id="p293675615111"><a name="p293675615111"></a><a name="p293675615111"></a>Reading or writing in a queue (with the content contained in the address)</p>
</td>
<td class="cellrowborder" valign="top" width="24.29%" headers="mcps1.1.4.1.2 "><p id="p14936356155113"><a name="p14936356155113"></a><a name="p14936356155113"></a>LOS_QueueReadCopy</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.1.4.1.3 "><p id="p11936155616510"><a name="p11936155616510"></a><a name="p11936155616510"></a>Reads data from the head node of the specified queue.</p>
</td>
</tr>
<tr id="row093619569510"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p179361256175117"><a name="p179361256175117"></a><a name="p179361256175117"></a>LOS_QueueWriteCopy</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p6936155616515"><a name="p6936155616515"></a><a name="p6936155616515"></a>Writes the data saved in the input parameter <strong id="b9859038152517"><a name="b9859038152517"></a><a name="b9859038152517"></a>bufferAddr</strong> to the tail node of the specified queue.</p>
</td>
</tr>
<tr id="row16936856185111"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p49361156195113"><a name="p49361156195113"></a><a name="p49361156195113"></a>LOS_QueueWriteHeadCopy</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1193625675116"><a name="p1193625675116"></a><a name="p1193625675116"></a>Writes the data saved in the input parameter <strong id="b536221517269"><a name="b536221517269"></a><a name="b536221517269"></a>bufferAddr</strong> to the head node of the specified queue.</p>
</td>
</tr>
<tr id="row1936756155114"><td class="cellrowborder" valign="top" width="23.56%" headers="mcps1.1.4.1.1 "><p id="p149371956105114"><a name="p149371956105114"></a><a name="p149371956105114"></a>Obtaining queue information</p>
</td>
<td class="cellrowborder" valign="top" width="24.29%" headers="mcps1.1.4.1.2 "><p id="p7937145613516"><a name="p7937145613516"></a><a name="p7937145613516"></a>LOS_QueueInfoGet</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.1.4.1.3 "><p id="p19371356175110"><a name="p19371356175110"></a><a name="p19371356175110"></a>Obtains information about the specified queue, including the queue ID, queue length, message node size, head node, tail node, number of readable nodes, number of writable nodes, tasks waiting for read operations, and tasks waiting for write operations.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section783435801510"></a>

1.  Call  **LOS\_QueueCreate**  to create a queue. The queue ID is returned when the queue is created.
2.  Call  **LOS\_QueueWrite**  or  **LOS\_QueueWriteCopy**  to write messages to the queue.
3.  Call  **LOS\_QueueRead**  or  **LOS\_QueueReadCopy**  to read messages from the queue.
4.  Call  **LOS\_QueueInfoGet**  to obtain queue information.
5.  Call  **LOS\_QueueDelete**  to delete the queue.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The maximum number of queues supported by the system is the total number of queue resources of the system, not the number of queue resources available to users. For example, if the system software timer occupies one more queue resource, the number of queue resources available to users decreases by one.
>-   The input parameters queue name and flags passed when a queue is created are reserved for future use.
>-   The input parameter  **timeOut**  in the queue interface function is relative time.
>-   **LOS\_QueueReadCopy**,  **LOS\_QueueWriteCopy**, and  **LOS\_QueueWriteHeadCopy**  are a group of APIs that must be used together.  **LOS\_QueueRead**,  **LOS\_QueueWrite**, and  **LOS\_QueueWriteHead**  are a group of APIs that must be used together.
>-   As  **LOS\_QueueWrite**,  **LOS\_QueueWriteHead**, and  **LOS\_QueueRead**  are used to manage data addresses, you must ensure that the memory directed by the pointer obtained by calling  **LOS\_QueueRead**  is not modified or released abnormally when the queue is being read. Otherwise, unpredictable results may occur.
>-   **LOS\_QueueWrite**,  **LOS\_QueueWriteHead**, and  **LOS\_QueueRead**  are called to manage data addresses, which means that the actual data read or written is pointer data. Therefore, before using these APIs, ensure that the message node size is the pointer length during queue creation, to avoid waste and read failures.

## Development Example<a name="section460018317164"></a>

### Example Description<a name="section2148236125814"></a>

Create a queue and two tasks. Enable task 1 to call the queue write API to send messages, and enable task 2 to receive messages by calling the queue read API.

1.  Create task 1 and task 2 by calling  **LOS\_TaskCreate**.
2.  Create a message queue by calling  **LOS\_QueueCreate**.
3.  Enable messages to be sent in task 1 by calling  **SendEntry**.
4.  Enable messages to be received in task 2 by calling  **RecvEntry**.
5.  Delete the queue by calling  **LOS\_QueueDelete**.

### Sample Code<a name="section121451047155716"></a>

The sample code is as follows:

```
#include "los_task.h"
#include "los_queue.h"
static UINT32 g_queue;
#define BUFFER_LEN 50

VOID SendEntry(VOID)
{
    UINT32 ret = 0;
    CHAR abuf[] = "test message";
    UINT32 len = sizeof(abuf);

    ret = LOS_QueueWriteCopy(g_queue, abuf, len, 0);
    if(ret != LOS_OK) {
        printf("Failed to send the message. Error: %x\n", ret);
    }
}

VOID RecvEntry(VOID)
{
    UINT32 ret = 0;
    CHAR readBuf[BUFFER_LEN] = {0};
    UINT32 readLen = BUFFER_LEN;

    ret = LOS_QueueReadCopy(g_queue, readBuf, &readLen, 0);
    if(ret != LOS_OK) {
        printf("Failed to receive the message. Error: %x\n", ret);
    }

    printf("Message received: %s\n", readBuf);

    ret = LOS_QueueDelete(g_queue);
    if(ret != LOS_OK) {
        printf("Failed to delete the queue. Error: %x\n", ret);
    }

    printf("Queue deleted.\n");
}

UINT32 ExampleQueue(VOID)
{
    printf("Start queue example.\n");
    UINT32 ret = 0;
    UINT32 task1, task2;
    TSK_INIT_PARAM_S initParam = {0};

    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)SendEntry;
    initParam.usTaskPrio = 9;
    initParam.uwStackSize = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    initParam.pcName = "SendQueue";

    LOS_TaskLock();
    ret = LOS_TaskCreate(&task1, &initParam);
    if(ret != LOS_OK) {
        printf("Failed to create task1. Error: %x\n", ret);
        return ret;
    }

    initParam.pcName = "RecvQueue";
    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)RecvEntry;
    initParam.usTaskPrio = 10;
    ret = LOS_TaskCreate(&task2, &initParam);
    if(ret != LOS_OK) {
        printf("Failed to create task2. Error: %x\n", ret);
        return ret;
    }

    ret = LOS_QueueCreate("queue", 5, &g_queue, 0, 50);
    if(ret != LOS_OK) {
        printf("Failed to create the queue. Error: %x\n", ret);
    }

    printf("Queue created.\n");
    LOS_TaskUnlock();
    return ret;
}
```

### Verification<a name="section2742182082117"></a>

The development is successful if the return result is as follows:

```
Start queue example.
Queue created.
Message received: test message.
Queue deleted.
```

