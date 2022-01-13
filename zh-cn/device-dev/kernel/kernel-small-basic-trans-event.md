# 事件<a name="ZH-CN_TOPIC_0000001078753124"></a>

-   [基本概念](#section122115620816)
-   [运行机制](#section94611116593)
    -   [事件控制块](#section1161415384467)
    -   [事件运作原理](#section187761153144617)

-   [开发指导](#section44744471891)
    -   [接口说明](#section172373513919)
    -   [开发流程](#section1118215161013)
    -   [编程实例](#section19986143311020)
    -   [实例描述](#section128221510145718)
    -   [编程示例](#section71507479577)
    -   [结果验证](#section16570171645813)


## 基本概念<a name="section122115620816"></a>

事件（Event）是一种任务间通信的机制，可用于任务间的同步。

多任务环境下，任务之间往往需要同步操作，一个等待即是一个同步。事件可以提供一对多、多对多的同步操作。

-   一对多同步模型：一个任务等待多个事件的触发。可以是任意一个事件发生时唤醒任务处理事件，也可以是几个事件都发生后才唤醒任务处理事件。
-   多对多同步模型：多个任务等待多个事件的触发。

OpenHarmony LiteOS-A的事件模块提供的事件，具有如下特点：

-   任务通过创建事件控制块来触发事件或等待事件。
-   事件间相互独立，内部实现为一个32位无符号整型，每一位标识一种事件类型。第25位不可用，因此最多可支持31种事件类型。
-   事件仅用于任务间的同步，不提供数据传输功能。
-   多次向事件控制块写入同一事件类型，在被清零前等效于只写入一次。
-   多个任务可以对同一事件进行读写操作。
-   支持事件读写超时机制。

## 运行机制<a name="section94611116593"></a>

### 事件控制块<a name="section1161415384467"></a>

```
/**
  * 事件控制块数据结构
  */
typedef struct tagEvent {
    UINT32 uwEventID;        /* 事件集合，表示已经处理（写入和清零）的事件集合 */
    LOS_DL_LIST stEventList; /* 等待特定事件的任务链表 */
} EVENT_CB_S, *PEVENT_CB_S;
```

### 事件运作原理<a name="section187761153144617"></a>

**事件初始化**会创建一个事件控制块，该控制块维护一个已处理的事件集合，以及等待特定事件的任务链表。

**写事件**会向事件控制块写入指定的事件，事件控制块更新事件集合，并遍历任务链表，根据任务等待具体条件满足情况决定是否唤醒相关任务。

**读事件**如果读取的事件已存在时，会直接同步返回。其他情况会根据超时时间以及事件触发情况，来决定返回时机：等待的事件条件在超时时间耗尽之前到达，阻塞任务会被直接唤醒，否则超时时间耗尽该任务才会被唤醒。

读事件条件满足与否取决于入参eventMask和mode，eventMask即需要关注的事件类型掩码。mode是具体处理方式，分以下三种情况：

-   LOS\_WAITMODE\_AND：逻辑与，基于接口传入的事件类型掩码eventMask，只有这些事件都已经发生才能读取成功，否则该任务将阻塞等待或者返回错误码。
-   LOS\_WAITMODE\_OR：逻辑或，基于接口传入的事件类型掩码eventMask，只要这些事件中有任一种事件发生就可以读取成功，否则该任务将阻塞等待或者返回错误码。
-   LOS\_WAITMODE\_CLR：这是一种附加读取模式，需要与所有事件模式或任一事件模式结合使用（LOS\_WAITMODE\_AND | LOS\_WAITMODE\_CLR或 LOS\_WAITMODE\_OR | LOS\_WAITMODE\_CLR）。在这种模式下，当设置的所有事件模式或任一事件模式读取成功后，会自动清除事件控制块中对应的事件类型位。

**事件清零**根据指定掩码，去对事件控制块的事件集合进行清零操作。当掩码为0时，表示将事件集合全部清零。当掩码为0xffff时，表示不清除任何事件，保持事件集合原状。

**事件销毁**销毁指定的事件控制块。

**图 1**  事件运作原理图<a name="fig17799175324612"></a>  
![](figure/事件运作原理图-21.png "事件运作原理图-21")

## 开发指导<a name="section44744471891"></a>

### 接口说明<a name="section172373513919"></a>

OpenHarmony LiteOS-A内核的事件模块提供下面几种功能。

**表 1**  事件模块接口

<a name="table1415203765610"></a>
<table><thead align="left"><tr id="row134151837125611"><th class="cellrowborder" valign="top" width="12.85128512851285%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="29.8029802980298%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row0415737175610"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p9598124913544"><a name="p9598124913544"></a><a name="p9598124913544"></a>初始化事件</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p77891354175812"><a name="p77891354175812"></a><a name="p77891354175812"></a>LOS_EventInit</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p2334141425515"><a name="p2334141425515"></a><a name="p2334141425515"></a>初始化一个事件控制块</p>
</td>
</tr>
<tr id="row421753455514"><td class="cellrowborder" rowspan="2" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p13441112105813"><a name="p13441112105813"></a><a name="p13441112105813"></a>读/写事件</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p17234205011559"><a name="p17234205011559"></a><a name="p17234205011559"></a>LOS_EventRead</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p1621275475517"><a name="p1621275475517"></a><a name="p1621275475517"></a>读取指定事件类型，超时时间为相对时间：单位为Tick</p>
</td>
</tr>
<tr id="row13129193718555"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17477615564"><a name="p17477615564"></a><a name="p17477615564"></a>LOS_EventWrite</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p10271958567"><a name="p10271958567"></a><a name="p10271958567"></a>写指定的事件类型</p>
</td>
</tr>
<tr id="row1831124035511"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p1313401559"><a name="p1313401559"></a><a name="p1313401559"></a>清除事件</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p7788152419567"><a name="p7788152419567"></a><a name="p7788152419567"></a>LOS_EventClear</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p14862153525620"><a name="p14862153525620"></a><a name="p14862153525620"></a>清除指定的事件类型</p>
</td>
</tr>
<tr id="row1525316428553"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p4253144265519"><a name="p4253144265519"></a><a name="p4253144265519"></a>校验事件掩码</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p768611115563"><a name="p768611115563"></a><a name="p768611115563"></a>LOS_EventPoll</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p13998115465617"><a name="p13998115465617"></a><a name="p13998115465617"></a>根据用户传入的事件ID、事件掩码及读取模式，返回用户传入的事件是否符合预期</p>
</td>
</tr>
<tr id="row6447135825614"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p104471658155615"><a name="p104471658155615"></a><a name="p104471658155615"></a>销毁事件</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p15259169573"><a name="p15259169573"></a><a name="p15259169573"></a>LOS_EventDestroy</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p32592615573"><a name="p32592615573"></a><a name="p32592615573"></a>销毁指定的事件控制块</p>
</td>
</tr>
</tbody>
</table>

### 开发流程<a name="section1118215161013"></a>

事件的典型开发流程：

1.  初始化事件控制块
2.  阻塞读事件控制块
3.  写入相关事件
4.  阻塞任务被唤醒，读取事件并检查是否满足要求
5.  处理事件控制块
6.  事件控制块销毁

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   进行事件读写操作时，事件的第25位为保留位，不可以进行位设置。
>-   对同一事件反复写入，算作一次写入。

### 编程实例<a name="section19986143311020"></a>

### 实例描述<a name="section128221510145718"></a>

示例中，任务Example\_TaskEntry创建一个任务Example\_Event，Example\_Event读事件阻塞，Example\_TaskEntry向该任务写事件。可以通过示例日志中打印的先后顺序理解事件操作时伴随的任务切换。

1.  在任务Example\_TaskEntry创建任务Example\_Event，其中任务Example\_Event优先级高于Example\_TaskEntry。
2.  在任务Example\_Event中读事件0x00000001，阻塞，发生任务切换，执行任务Example\_TaskEntry。
3.  在任务Example\_TaskEntry向任务Example\_Event写事件0x00000001，发生任务切换，执行任务Example\_Event。
4.  Example\_Event得以执行，直到任务结束。
5.  Example\_TaskEntry得以执行，直到任务结束。

### 编程示例<a name="section71507479577"></a>

示例代码如下：

```
#include "los_event.h"
#include "los_task.h"
#include "securec.h"

/* 任务ID */
UINT32 g_testTaskId;

/* 事件控制结构体 */
EVENT_CB_S g_exampleEvent;

/* 等待的事件类型 */
#define EVENT_WAIT 0x00000001

/* 用例任务入口函数 */
VOID Example_Event(VOID)
{
     UINT32 event;

    /* 超时等待方式读事件,超时时间为100 ticks, 若100 ticks后未读取到指定事件，读事件超时，任务直接唤醒 */
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

    /* 事件初始化 */
    ret = LOS_EventInit(&g_exampleEvent);
    if (ret != LOS_OK) {
        printf("init event failed .\n");
        return -1;
    }

    /* 创建任务 */
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

    /* 写g_testTaskId 等待事件 */
    printf("Example_TaskEntry write event.\n");

    ret = LOS_EventWrite(&g_exampleEvent, EVENT_WAIT);
    if (ret != LOS_OK) {
        printf("event write failed.\n");
        return LOS_NOK;
    }

    /* 清标志位 */
    printf("EventMask:%d\n", g_exampleEvent.uwEventID);
    LOS_EventClear(&g_exampleEvent, ~g_exampleEvent.uwEventID);
    printf("EventMask:%d\n", g_exampleEvent.uwEventID);

    /* 删除任务 */
    ret = LOS_TaskDelete(g_testTaskId);
    if (ret != LOS_OK) {
        printf("task delete failed.\n");
        return LOS_NOK;
    }

    return LOS_OK;
}
```

### 结果验证<a name="section16570171645813"></a>

编译运行得到的结果为：

```
Example_Event wait event 0x1 
Example_TaskEntry write event.
Example_Event,read event :0x1
EventMask:1
EventMask:0
```

