# 开发指导<a name="ZH-CN_TOPIC_0000001123763635"></a>

-   [接口说明](#section158501652121514)
-   [开发流程](#section783435801510)
-   [编程实例](#section460018317164)
    -   [实例描述](#section2148236125814)
    -   [示例代码](#section121451047155716)
    -   [结果验证](#section2742182082117)


## 接口说明<a name="section158501652121514"></a>

<a name="table10903105695114"></a>
<table><thead align="left"><tr id="row1293645645110"><th class="cellrowborder" valign="top" width="23.56%" id="mcps1.1.4.1.1"><p id="p59361562512"><a name="p59361562512"></a><a name="p59361562512"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="24.29%" id="mcps1.1.4.1.2"><p id="p1393665645118"><a name="p1393665645118"></a><a name="p1393665645118"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="52.15%" id="mcps1.1.4.1.3"><p id="p119363564516"><a name="p119363564516"></a><a name="p119363564516"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1693665613516"><td class="cellrowborder" rowspan="2" valign="top" width="23.56%" headers="mcps1.1.4.1.1 "><p id="p193675615514"><a name="p193675615514"></a><a name="p193675615514"></a>创建/删除消息队列</p>
</td>
<td class="cellrowborder" valign="top" width="24.29%" headers="mcps1.1.4.1.2 "><p id="p11936115612514"><a name="p11936115612514"></a><a name="p11936115612514"></a>LOS_QueueCreate</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.1.4.1.3 "><p id="p1593620562517"><a name="p1593620562517"></a><a name="p1593620562517"></a>创建一个消息队列，由系统动态申请队列空间。</p>
</td>
</tr>
<tr id="row79361156175113"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p893615567517"><a name="p893615567517"></a><a name="p893615567517"></a>LOS_QueueDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p4936155695111"><a name="p4936155695111"></a><a name="p4936155695111"></a>根据队列ID删除一个指定队列。</p>
</td>
</tr>
<tr id="row093614566519"><td class="cellrowborder" rowspan="3" valign="top" width="23.56%" headers="mcps1.1.4.1.1 "><p id="p1593685614513"><a name="p1593685614513"></a><a name="p1593685614513"></a>读/写队列（不带拷贝）</p>
</td>
<td class="cellrowborder" valign="top" width="24.29%" headers="mcps1.1.4.1.2 "><p id="p6936556155118"><a name="p6936556155118"></a><a name="p6936556155118"></a>LOS_QueueRead</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.1.4.1.3 "><p id="p11936556155118"><a name="p11936556155118"></a><a name="p11936556155118"></a>读取指定队列头节点中的数据（队列节点中的数据实际上是一个地址）。</p>
</td>
</tr>
<tr id="row199369565518"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p393655620513"><a name="p393655620513"></a><a name="p393655620513"></a>LOS_QueueWrite</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p12936256175120"><a name="p12936256175120"></a><a name="p12936256175120"></a>向指定队列尾节点中写入入参bufferAddr的值（即buffer的地址）。</p>
</td>
</tr>
<tr id="row1293615635114"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p893625665119"><a name="p893625665119"></a><a name="p893625665119"></a>LOS_QueueWriteHead</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p193620566515"><a name="p193620566515"></a><a name="p193620566515"></a>向指定队列头节点中写入入参bufferAddr的值（即buffer的地址）。</p>
</td>
</tr>
<tr id="row593675635117"><td class="cellrowborder" rowspan="3" valign="top" width="23.56%" headers="mcps1.1.4.1.1 "><p id="p293675615111"><a name="p293675615111"></a><a name="p293675615111"></a>读/写队列（带拷贝）</p>
</td>
<td class="cellrowborder" valign="top" width="24.29%" headers="mcps1.1.4.1.2 "><p id="p14936356155113"><a name="p14936356155113"></a><a name="p14936356155113"></a>LOS_QueueReadCopy</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.1.4.1.3 "><p id="p11936155616510"><a name="p11936155616510"></a><a name="p11936155616510"></a>读取指定队列头节点中的数据。</p>
</td>
</tr>
<tr id="row093619569510"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p179361256175117"><a name="p179361256175117"></a><a name="p179361256175117"></a>LOS_QueueWriteCopy</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p6936155616515"><a name="p6936155616515"></a><a name="p6936155616515"></a>向指定队列尾节点中写入入参bufferAddr中保存的数据。</p>
</td>
</tr>
<tr id="row16936856185111"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p49361156195113"><a name="p49361156195113"></a><a name="p49361156195113"></a>LOS_QueueWriteHeadCopy</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1193625675116"><a name="p1193625675116"></a><a name="p1193625675116"></a>向指定队列头节点中<em id="i1183903561620"><a name="i1183903561620"></a><a name="i1183903561620"></a>写入入参</em>bufferAddr中保存的数据。</p>
</td>
</tr>
<tr id="row1936756155114"><td class="cellrowborder" valign="top" width="23.56%" headers="mcps1.1.4.1.1 "><p id="p149371956105114"><a name="p149371956105114"></a><a name="p149371956105114"></a>获取队列信息</p>
</td>
<td class="cellrowborder" valign="top" width="24.29%" headers="mcps1.1.4.1.2 "><p id="p7937145613516"><a name="p7937145613516"></a><a name="p7937145613516"></a>LOS_QueueInfoGet</p>
</td>
<td class="cellrowborder" valign="top" width="52.15%" headers="mcps1.1.4.1.3 "><p id="p19371356175110"><a name="p19371356175110"></a><a name="p19371356175110"></a>获取指定队列的信息，包括队列ID、队列长度、消息节点大小、头节点、尾节点、可读节点数量、可写节点数量、等待读操作的任务、等待写操作的任务。</p>
</td>
</tr>
</tbody>
</table>

## 开发流程<a name="section783435801510"></a>

1.  用LOS\_QueueCreate创建队列。创建成功后，可以得到队列ID。
2.  通过LOS\_QueueWrite或者LOS\_QueueWriteCopy写队列。
3.  通过LOS\_QueueRead或者LOS\_QueueReadCopy读队列。
4.  通过LOS\_QueueInfoGet获取队列信息。
5.  通过LOS\_QueueDelete删除队列。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   系统支持的最大队列数是指：整个系统的队列资源总个数，而非用户能使用的个数。例如：系统软件定时器多占用一个队列资源，那么用户能使用的队列资源就会减少一个。
>-   创建队列时传入的队列名和flags暂时未使用，作为以后的预留参数。
>-   队列接口函数中的入参timeOut是相对时间。
>-   LOS\_QueueReadCopy和LOS\_QueueWriteCopy及LOS\_QueueWriteHeadCopy是一组接口，LOS\_QueueRead和LOS\_QueueWrite及LOS\_QueueWriteHead是一组接口，每组接口需要配套使用。
>-   鉴于LOS\_QueueWrite和LOS\_QueueWriteHead和LOS\_QueueRead这组接口实际操作的是数据地址，用户必须保证调用LOS\_QueueRead获取到的指针所指向的内存区域在读队列期间没有被异常修改或释放，否则可能导致不可预知的后果。
>-   鉴于LOS\_QueueWrite和LOS\_QueueWriteHead和LOS\_QueueRead这组接口实际操作的是数据地址，也就意味着实际写和读的消息长度仅仅是一个指针数据，因此用户使用这组接口之前，需确保创建队列时的消息节点大小，为一个指针的长度，避免不必要的浪费和读取失败。

## 编程实例<a name="section460018317164"></a>

### 实例描述<a name="section2148236125814"></a>

创建一个队列，两个任务。任务1调用写队列接口发送消息，任务2通过读队列接口接收消息。

1.  通过LOS\_TaskCreate创建任务1和任务2。
2.  通过LOS\_QueueCreate创建一个消息队列。
3.  在任务1 SendEntry中发送消息。
4.  在任务2 RecvEntry中接收消息。
5.  通过LOS\_QueueDelete删除队列。

### 示例代码<a name="section121451047155716"></a>

示例代码如下：

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

### 结果验证<a name="section2742182082117"></a>

编译运行得到的结果为：

```
Start queue example.
Queue created.
Message received: test message.
Queue deleted.
```

