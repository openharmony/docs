# Queue<a name="EN-US_TOPIC_0000001078912736"></a>


## Basic Concepts<a name="section81171363232"></a>

A queue, also called a message queue, is a data structure used for communication between tasks. The queue receives messages of unfixed length from tasks or interrupts, and determines whether to store the transferred messages in the queue based on different APIs.

Tasks can read messages from a queue. When the queue has no messages, the tasks are suspended. When the queue has a new message, the suspended tasks are woken up and process the new message. Tasks can also write messages to the queue. When the queue is full, the write task is suspended. When there is an available message node in the queue, the suspended write task is woken up and writes a message.

You can adjust the timeout period of the read queue and write queue to adjust the block mode of the read and write APIs. If the timeout period is set to **0** for the read queue and write queue, tasks will not be suspended and the API directly returns. This is the non-block mode. If the timeout period is greater than **0**, block mode is used.

An asynchronous processing mechanism is provided to allow messages in a queue not to be processed immediately. In addition, queues can be used to buffer messages and implement asynchronous task communication. Queues have the following features:

-   Messages are queued in FIFO mode and can be read and written asynchronously.
-   Both the read queue and write queue support the timeout mechanism.
-   Each time a message is read, the message node becomes available.
-   The types of messages to be sent are determined by the parties involved in communication. Messages of different lengths \(not exceeding the message node size of the queue\) are allowed.
-   A task can receive messages from and send messages to any message queue.
-   Multiple tasks can receive messages from and send messages to the same queue.
-   When a queue is created, the required dynamic memory space is automatically allocated in the queue API.

## Working Principles<a name="section1074515132316"></a>

### Queue Control Block<a name="section194431851201315"></a>

```
/**
 * Data structure of the queue control block
  */
typedef struct {
    UINT8 *queueHandle; /**< Pointer to a queue handle */
    UINT16 queueState;  /**< Queue state */
    UINT16 queueLen;    /**< Queue length */
    UINT16 queueSize;   /**< Node size */
    UINT32 queueID;     /**< queueID */
    UINT16 queueHead;   /**< Node head */
    UINT16 queueTail;   /**< Node tail */
    UINT16 readWriteableCnt[OS_QUEUE_N_RW];   /**< Count of readable or writable resources, 0:readable, 1:writable */
    LOS_DL_LIST readWriteList[OS_QUEUE_N_RW]; /**< the linked list to be read or written, 0:readlist, 1:writelist */
    LOS_DL_LIST memList;                      /**< Pointer to the memory linked list */
} LosQueueCB;
```

Each queue control block contains information about the queue status.

-   **OS\_QUEUE\_UNUSED**: The queue is not in use.
-   **OS\_QUEUE\_INUSED**: The queue is in use.

### Working Principles<a name="section89875741418"></a>

-   The queue ID is returned if a queue is created successfully.
-   The queue control block contains **Head** and **Tail**, which indicate the storage status of messages in a queue. **Head** indicates the start position of occupied message nodes in the queue. **Tail** indicates the end position of the occupied message nodes and the start position of idle message nodes. When a queue is created, **Head** and **Tail** point to the start position of the queue.
-   When data is to be written to a queue, **readWriteableCnt\[1\]** is used to determine whether data can be written to the queue. If **readWriteableCnt\[1\]** is **0**, the queue is full and data cannot be written to it. Data can be written to the head node or tail node of a queue. To write data to the tail node, locate the start idle message node based on **Tail** and write data to it. If **Tail** is pointing to the tail of the queue, the rewind mode is used. To write data to the head node, locate previous node based on **Head** and write data to it. If **Head** is pointing to the start position of the queue, the rewind mode is used.
-   When a queue is to be read, **readWriteableCnt\[0\]** is used to determine whether the queue has messages to read. Reading an idle queue \(**readWriteableCnt\[0\]** is** 0**\) will cause task suspension. If the queue has messages to read, the system locates the first node to which data is written based on **Head** and read the message from the node. If **Head** is pointing to the tail of the queue, the rewind mode is used.
-   When a queue is to be deleted, the system locates the queue based on the queue ID, sets the queue status to **OS\_QUEUE\_UNUSED**, sets the queue control block to the initial state, and releases the memory occupied by the queue.

**Figure 1** Reading and writing data in a queue<a name="fig139854471119"></a> 
![](figures/reading-and-writing-data-in-a-queue-3.png "reading-and-writing-data-in-a-queue-3")

The preceding figure illustrates how to write data to the tail node only. Writing data to the head node is similar.

## Development Guidelines<a name="section827981242419"></a>

### Available APIs<a name="section19327151642413"></a>

<a name="table10903105695114"></a>
<table><thead align="left"><tr id="row1293645645110"><th class="cellrowborder" valign="top" width="23.56%" id="mcps1.1.4.1.1"><p id="p59361562512"><a name="p59361562512"></a><a name="p59361562512"></a>Function</p>
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
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p12936256175120"><a name="p12936256175120"></a><a name="p12936256175120"></a>Writes the value of the input parameter <strong id="b9518118105313"><a name="b9518118105313"></a><a name="b9518118105313"></a>bufferAddr</strong> (buffer address) to the tail node of the specified queue.</p>
</td>
</tr>
<tr id="row1293615635114"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p893625665119"><a name="p893625665119"></a><a name="p893625665119"></a>LOS_QueueWriteHead</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p193620566515"><a name="p193620566515"></a><a name="p193620566515"></a>Writes the value of the input parameter <strong id="b16808172214534"><a name="b16808172214534"></a><a name="b16808172214534"></a>bufferAddr</strong> (buffer address) to the head node of the specified queue.</p>
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
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p6936155616515"><a name="p6936155616515"></a><a name="p6936155616515"></a>Writes the data saved in the input parameter <strong id="b14415194615537"><a name="b14415194615537"></a><a name="b14415194615537"></a>bufferAddr</strong> to the tail node of the specified queue.</p>
</td>
</tr>
<tr id="row16936856185111"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p49361156195113"><a name="p49361156195113"></a><a name="p49361156195113"></a>LOS_QueueWriteHeadCopy</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1193625675116"><a name="p1193625675116"></a><a name="p1193625675116"></a>Writes the data saved in the input parameter <strong id="b1030118493534"><a name="b1030118493534"></a><a name="b1030118493534"></a>bufferAddr</strong> to the head node of the specified queue.</p>
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

### How to Develop<a name="section1390154210243"></a>

1.  Call **LOS\_QueueCreate** to create a queue. The queue ID is returned when the queue is created.
2.  Call **LOS\_QueueWrite** or **LOS\_QueueWriteCopy** to write messages to the queue.
3.  Call **LOS\_QueueRead** or **LOS\_QueueReadCopy** to read messages from the queue.
4.  Call **LOS\_QueueInfoGet** to obtain queue information.
5.  Call **LOS\_QueueDelete** to delete a queue.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The maximum number of queues supported by the system is the total number of queue resources of the system, not the number of queue resources available to users. For example, if the system software timer occupies one more queue resource, the number of queue resources available to users decreases by one.
>-   The input parameters queue name and flags passed when a queue is created are reserved for future use.
>-   The input parameter **timeOut** in the queue interface function is relative time.
>-   **LOS\_QueueReadCopy**, **LOS\_QueueWriteCopy**, and **LOS\_QueueWriteHeadCopy** are a group of APIs that must be used together. **LOS\_QueueRead**, **LOS\_QueueWrite**, and **LOS\_QueueWriteHead** are a group of APIs that must be used together.
>-   As **LOS\_QueueWrite**, **LOS\_QueueWriteHead**, and **LOS\_QueueRead** are used to manage data addresses, you must ensure that the memory directed by the pointer obtained by calling **LOS\_QueueRead** is not modified or released abnormally when the queue is being read. Otherwise, unpredictable results may occur.
>-   If the input parameter **bufferSize** in **LOS\_QueueRead** and **LOS\_QueueReadCopy** is less than the length of the message, the message will be truncated.
>-   **LOS\_QueueWrite**, **LOS\_QueueWriteHead**, and **LOS\_QueueRead** are called to manage data addresses, which means that the actual data read or written is pointer data. Therefore, before using these APIs, ensure that the message node size is the pointer length during queue creation, to avoid waste and read failures.

## Development Example<a name="section27132341285"></a>

### Example Description<a name="section197311443141017"></a>

Create a queue and two tasks. Enable task 1 to call the queue write API to send messages, and enable task 2 to receive messages by calling the queue read API.

1.  Create task 1 and task 2 by calling **LOS\_TaskCreate**.
2.  Create a message queue by calling **LOS\_QueueCreate**.
3.  Enable messages to be sent in task 1 by calling **SendEntry**.
4.  Enable messages to be received in task 2 by calling **RecvEntry**.
5.  Call **LOS\_QueueDelete** to delete a queue.

### Sample Code<a name="section972214490107"></a>

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
        printf("send message failure, error: %x\n", ret);
    }
}

VOID RecvEntry(VOID)
{
    UINT32 ret = 0;
    CHAR readBuf[BUFFER_LEN] = {0};
    UINT32 readLen = BUFFER_LEN;

   // Sleep for 1s.
    usleep(1000000);
    ret = LOS_QueueReadCopy(g_queue, readBuf, &readLen, 0);
    if(ret != LOS_OK) {
        printf("recv message failure, error: %x\n", ret);
    }

    printf("recv message: %s\n", readBuf);

    ret = LOS_QueueDelete(g_queue);
    if(ret != LOS_OK) {
        printf("delete the queue failure, error: %x\n", ret);
    }

    printf("delete the queue success!\n");
}

UINT32 ExampleQueue(VOID)
{
    printf("start queue example\n");
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
        printf("create task1 failed, error: %x\n", ret);
        return ret;
    }

    initParam.pcName = "RecvQueue";
    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)RecvEntry;
    ret = LOS_TaskCreate(&task2, &initParam);
    if(ret != LOS_OK) {
        printf("create task2 failed, error: %x\n", ret);
        return ret;
    }

    ret = LOS_QueueCreate("queue", 5, &g_queue, 0, 50);
    if(ret != LOS_OK) {
        printf("create queue failure, error: %x\n", ret);
    }

    printf("create the queue success!\n");
    LOS_TaskUnlock();
    return ret;
}
```

### Verification<a name="section19287165416106"></a>

The development is successful if the return result is as follows:

```
start test example
create the queue success!
recv message: test message
delete the queue success!
```

