# Queue


## Basic Concepts

A queue, also called a message queue, is a data structure used for communication between tasks. The queue receives messages of unfixed length from tasks or interrupts, and determines whether to store the transferred messages in the queue based on different APIs.

Tasks can read messages from a queue. When the queue has no messages, the tasks are suspended. When the queue has a new message, the suspended tasks are woken up and process the new message. Tasks can also write messages to the queue. When the queue is full, the write task is suspended. When there is an available message node in the queue, the suspended write task is woken up and writes a message.

You can adjust the timeout period of the read queue and write queue to adjust the block mode of the read and write APIs. If the timeout period is set to **0** for the read queue and write queue, tasks will not be suspended and the API directly returns. This is the non-block mode. If the timeout period is greater than **0**, block mode is used.

An asynchronous processing mechanism is provided to allow messages in a queue not to be processed immediately. In addition, queues can be used to buffer messages and implement asynchronous task communication. Queues have the following features:

- Messages are queued in first-in-first-out (FIFO) mode and can be read and written asynchronously.

- Both the read queue and write queue support the timeout mechanism.

- Each time a message is read, the message node becomes available.

- The types of messages to be sent are determined by the parties involved in communication. Messages of different lengths (not exceeding the message node size of the queue) are allowed.

- A task can receive messages from and send messages to any message queue.

- Multiple tasks can receive messages from and send messages to the same queue.

- When a queue is created, the required dynamic memory space is automatically allocated in the queue API.


## Working Principles


### Queue Control Block


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

- **OS_QUEUE_UNUSED**: The queue is not in use.

- **OS_QUEUE_INUSED**: The queue is in use.


### Working Principles

- The queue ID is returned when a queue is created successfully.

- The queue control block contains **Head** and **Tail**, which indicate the storage status of messages in a queue. **Head** indicates the start position of occupied message nodes in the queue. **Tail** indicates the end position of the occupied message nodes and the start position of idle message nodes. When a queue is created, **Head** and **Tail** point to the start position of the queue.

- When data is to be written to a queue, **readWriteableCnt[1]** is used to determine whether data can be written to the queue. If **readWriteableCnt[1]** is **0**, the queue is full and data cannot be written to it. Data can be written to the head node or tail node of a queue. To write data to the tail node, locate the start idle message node based on **Tail** and write data to it. If **Tail** is pointing to the tail of the queue, the rewind mode is used. To write data to the head node, locate previous node based on **Head** and write data to it. If **Head** is pointing to the start position of the queue, the rewind mode is used.

- When a queue is to be read, **readWriteableCnt[0]** is used to determine whether the queue has messages to read. Reading an idle queue (**readWriteableCnt[0]** is** 0**) will cause task suspension. If the queue has messages to read, the system locates the first node to which data is written based on **Head** and read the message from the node. If **Head** is pointing to the tail of the queue, the rewind mode is used.

- When a queue is to be deleted, the system locates the queue based on the queue ID, sets the queue status to **OS_QUEUE_UNUSED**, sets the queue control block to the initial state, and releases the memory occupied by the queue.

  **Figure 1** Reading and writing data in a queue

  ![](figures/reading-and-writing-data-in-a-queue-3.png "reading-and-writing-data-in-a-queue-3")

The preceding figure illustrates how to write data to the tail node only. Writing data to the head node is similar.


## Development Guidelines


### Available APIs

| Category| API Description |
| -------- | -------- |
| Creating or deleting a message queue| - **LOS_QueueCreate**: creates a message queue. The system dynamically allocates the queue space.<br>- **LOS_QueueDelete**: deletes a queue.|
| Reading or writing data (address without the content) in a queue| - **LOS_QueueRead**: reads data in the head node of the specified queue. The data in the queue node is an address.<br>- **LOS_QueueWrite**: writes the value of **bufferAddr** (buffer address) to the tail node of a queue.<br>- **LOS_QueueWrite**: writes the value of **bufferAddr** (buffer address) to the head node of a queue.|
| Reading or writing data (data and address) in a queue| - **LOS_QueueReadCopy**: reads data from the head node of a queue.<br>- **LOS_QueueWriteCopy**: writes the data saved in **bufferAddr** to the tail node of a queue.<br>- **LOS_QueueWriteHeadCopy**: writes the data saved in **bufferAddr** to the head node of a queue.|
| Obtaining queue information| **LOS_QueueInfoGet**: obtains queue information, including the queue ID, queue length, message node size, head node, tail node, number of readable/writable nodes, and tasks waiting for read/write operations.|


### How to Develop

1. Call **LOS_QueueCreate** to create a queue. The queue ID is returned when the queue is created.

2. Call **LOS_QueueWrite** or **LOS_QueueWriteCopy** to write data to the queue.

3. Call **LOS_QueueRead** or **LOS_QueueReadCopy** to read data from the queue.

4. Call **LOS_QueueInfoGet** to obtain queue information.

5. Call **LOS_QueueDelete** to delete a queue.

> **NOTE**<br>
> - The maximum number of queues supported by the system is the total number of queue resources of the system, not the number of queue resources available to users. For example, if the system software timer occupies one more queue resource, the number of queue resources available to users decreases by one.
> 
> - The queue name and flags passed in when a queue is created are reserved for future use.
> 
> - The parameter **timeOut** in the queue function is relative time.
> 
> - **LOS_QueueReadCopy**, **LOS_QueueWriteCopy**, and **LOS_QueueWriteHeadCopy** are a group of APIs that must be used together. **LOS_QueueRead**, **LOS_QueueWrite**, and **LOS_QueueWriteHead** are a group of APIs that must be used together.
> 
> - As **LOS_QueueWrite**, **LOS_QueueWriteHead**, and **LOS_QueueRead** are used to manage data addresses, you must ensure that the memory directed by the pointer obtained by calling **LOS_QueueRead** is not modified or released abnormally when the queue is being read. Otherwise, unpredictable results may occur.
> 
> - If the length of the data to read in **LOS_QueueRead** or **LOS_QueueReadCopy** is less than the actual message length, the message will be truncated.
> 
> - **LOS_QueueWrite**, **LOS_QueueWriteHead**, and **LOS_QueueRead** are called to manage data addresses, which means that the actual data read or written is pointer data. Therefore, before using these APIs, ensure that the message node size is the pointer length during queue creation, to avoid waste and read failures.


## Development Example


### Example Description

Create a queue and two tasks. Enable task 1 to write data to the queue, and task 2 to read data from the queue.

1. Call **LOS_TaskCreate** to create task 1 and task 2.

2. Call **LOS_QueueCreate** to create a message queue.

3. Task 1 sends a message in **SendEntry**.

4. Task 2 receives message in **RecvEntry**.

5. Call **LOS_QueueDelete** to delete the queue.


### Sample Code

The sample code can be compiled and verified in **./kernel/liteos_a/testsuites/kernel/src/osTest.c**. The **ExampleQueue** function is called in **TestTaskEntry**.

To avoid excessive printing, call **LOS_Msleep(5000)** to cause a short delay before calling **ExampleQueue**. 

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
        dprintf("send message failure, error: %x\n", ret);
    }
}

VOID RecvEntry(VOID)
{
    UINT32 ret = 0;
    CHAR readBuf[BUFFER_LEN] = {0};
    UINT32 readLen = BUFFER_LEN;

    LOS_Msleep(1000);
    ret = LOS_QueueReadCopy(g_queue, readBuf, &readLen, 0);
    if(ret != LOS_OK) {
        dprintf("recv message failure, error: %x\n", ret);
    }

    dprintf("recv message: %s\n", readBuf);

    ret = LOS_QueueDelete(g_queue);
    if(ret != LOS_OK) {
        dprintf("delete the queue failure, error: %x\n", ret);
    }

    dprintf("delete the queue success!\n");
}

UINT32 ExampleQueue(VOID)
{
    dprintf("start queue example\n");
    UINT32 ret = 0;
    UINT32 task1, task2;
    TSK_INIT_PARAM_S initParam = {0};

    ret = LOS_QueueCreate("queue", 5, &g_queue, 0, 50);
    if(ret != LOS_OK) {
        dprintf("create queue failure, error: %x\n", ret);
    }

    dprintf("create the queue success!\n");

    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)SendEntry;
    initParam.usTaskPrio = 9;
    initParam.uwStackSize = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    initParam.pcName = "SendQueue";

    LOS_TaskLock();
    ret = LOS_TaskCreate(&task1, &initParam);
    if(ret != LOS_OK) {
        dprintf("create task1 failed, error: %x\n", ret);
        LOS_QueueDelete(g_queue);
        return ret;
    }

    initParam.pcName = "RecvQueue";
    initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)RecvEntry;
    ret = LOS_TaskCreate(&task2, &initParam);
    if(ret != LOS_OK) {
        dprintf("create task2 failed, error: %x\n", ret);
        LOS_QueueDelete(g_queue);
        return ret;
    }

    LOS_TaskUnlock();
    LOS_Msleep(5000);
    return ret;
}
```


### Verification

The development is successful if the return result is as follows:


```
start queue example
create the queue success!
recv message: test message
delete the queue success!
```
