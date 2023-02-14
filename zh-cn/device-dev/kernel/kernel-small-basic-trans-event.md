# 事件


## 基本概念

事件（Event）是一种任务间通信的机制，可用于任务间的同步。

多任务环境下，任务之间往往需要同步操作，一个等待即是一个同步。事件可以提供一对多、多对多的同步操作。

- 一对多同步模型：一个任务等待多个事件的触发。可以是任意一个事件发生时唤醒任务处理事件，也可以是几个事件都发生后才唤醒任务处理事件。

- 多对多同步模型：多个任务等待多个事件的触发。

OpenHarmony LiteOS-A的事件模块提供的事件，具有如下特点：

- 任务通过创建事件控制块来触发事件或等待事件。

- 事件间相互独立，内部实现为一个32位无符号整型，每一位标识一种事件类型。（0表示该时间类型未发生，1表示该事件类型已经发生，一共31种事件类型，第25bit位(`0x02U << 24`)系统保留）

- 事件仅用于任务间的同步，不提供数据传输功能。

- 多次向事件控制块写入同一事件类型，在被清零前等效于只写入一次。

- 多个任务可以对同一事件进行读写操作。

- 支持事件读写超时机制。


## 运行机制


### 事件控制块


```
/**
  * 事件控制块数据结构
  */
typedef struct tagEvent {
    UINT32 uwEventID;        /* 事件集合，表示已经处理（写入和清零）的事件集合 */
    LOS_DL_LIST stEventList; /* 等待特定事件的任务链表 */
} EVENT_CB_S, *PEVENT_CB_S;
```


### 事件运作原理

**事件初始化**：会创建一个事件控制块，该控制块维护一个已处理的事件集合，以及等待特定事件的任务链表。

**写事件**：会向事件控制块写入指定的事件，事件控制块更新事件集合，并遍历任务链表，根据任务等待具体条件满足情况决定是否唤醒相关任务。

**读事件**：如果读取的事件已存在时，会直接同步返回。其他情况会根据超时时间以及事件触发情况，来决定返回时机：等待的事件条件在超时时间耗尽之前到达，阻塞任务会被直接唤醒，否则超时时间耗尽该任务才会被唤醒。

读事件条件满足与否取决于入参eventMask和mode，eventMask即需要关注的事件类型掩码。mode是具体处理方式，分以下三种情况：

- LOS_WAITMODE_AND：逻辑与，基于接口传入的事件类型掩码eventMask，只有这些事件都已经发生才能读取成功，否则该任务将阻塞等待或者返回错误码。

- LOS_WAITMODE_OR：逻辑或，基于接口传入的事件类型掩码eventMask，只要这些事件中有任一种事件发生就可以读取成功，否则该任务将阻塞等待或者返回错误码。

- LOS_WAITMODE_CLR：这是一种附加读取模式，需要与所有事件模式或任一事件模式结合使用（LOS_WAITMODE_AND | LOS_WAITMODE_CLR或 LOS_WAITMODE_OR | LOS_WAITMODE_CLR）。在这种模式下，当设置的所有事件模式或任一事件模式读取成功后，会自动清除事件控制块中对应的事件类型位。

**事件清零**：根据指定掩码，去对事件控制块的事件集合进行清零操作。当掩码为0时，表示将事件集合全部清零。当掩码为0xffff时，表示不清除任何事件，保持事件集合原状。

**事件销毁**：销毁指定的事件控制块。

  **图1** 小型系统事件运作原理图

  ![zh-cn_image_0000001180952545](figures/zh-cn_image_0000001180952545.png)


## 开发指导


### 接口说明

OpenHarmony LiteOS-A内核的事件模块提供下面几种功能。

  **表1** 事件模块接口

| 功能分类 | 接口描述 | 
| -------- | -------- |
| 初始化事件 | LOS_EventInit:初始化一个事件控制块 | 
| 读/写事件 | -&nbsp;LOS_EventRead：读取指定事件类型，超时时间为相对时间：单位为Tick<br/>-&nbsp;LOS_EventWrite：写指定的事件类型 | 
| 清除事件 | LOS_EventClear:清除指定的事件类型 | 
| 校验事件掩码 | -&nbsp;LOS_EventPoll：根据用户传入的事件ID、事件掩码及读取模式，返回用户传入的事件是否符合预期<br/>-&nbsp;LOS_EventDestroy:销毁指定的事件控制块 | 
| 销毁事件 | LOS_EventDestroy：销毁指定的事件控制块 | 


### 开发流程

事件的典型开发流程：

1. 初始化事件控制块

2. 阻塞读事件控制块

3. 写入相关事件

4. 阻塞任务被唤醒，读取事件并检查是否满足要求

5. 处理事件控制块

6. 事件控制块销毁

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 进行事件读写操作时，事件的第25bit(`0x02U << 24`)为保留bit位，不可以进行位设置。
> 
> - 对同一事件反复写入，算作一次写入。


## 编程实例


### 实例描述

示例中，任务Example_TaskEntry创建一个任务Example_Event，Example_Event读事件阻塞，Example_TaskEntry向该任务写事件。可以通过示例日志中打印的先后顺序理解事件操作时伴随的任务切换。

1. 在任务Example_TaskEntry创建任务Example_Event，其中任务Example_Event优先级高于Example_TaskEntry。

2. 在任务Example_Event中读事件0x00000001，阻塞，发生任务切换，执行任务Example_TaskEntry。

3. 在任务Example_TaskEntry向任务Example_Event写事件0x00000001，发生任务切换，执行任务Example_Event。

4. Example_Event得以执行，直到任务结束。

5. Example_TaskEntry得以执行，直到任务结束。


### 编程示例

本演示代码在./kernel/liteos_a/testsuites/kernel/src/osTest.c中编译验证，在TestTaskEntry中调用验证入口函数Example_EventEntry。

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
#define EVENT_WAIT      0x00000001
#define EVENT_TIMEOUT   500
/* 用例任务入口函数 */
VOID Example_Event(VOID)
{
     UINT32 event;

    /* 超时等待方式读事件,超时时间为100 ticks, 若100 ticks后未读取到指定事件，读事件超时，任务直接唤醒 */
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

    /* 事件初始化 */
    ret = LOS_EventInit(&g_exampleEvent);
    if (ret != LOS_OK) {
        dprintf("init event failed .\n");
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
        dprintf("task create failed.\n");
        return LOS_NOK;
    }

    /* 写g_testTaskId 等待事件 */
    dprintf("Example_TaskEntry write event.\n");

    ret = LOS_EventWrite(&g_exampleEvent, EVENT_WAIT);
    if (ret != LOS_OK) {
        dprintf("event write failed.\n");
        return LOS_NOK;
    }

    /* 清标志位 */
    dprintf("EventMask:%d\n", g_exampleEvent.uwEventID);
    LOS_EventClear(&g_exampleEvent, ~g_exampleEvent.uwEventID);
    dprintf("EventMask:%d\n", g_exampleEvent.uwEventID);

    return LOS_OK;
}
```


### 结果验证

编译运行得到的结果为：


```
Example_Event wait event 0x1 
Example_TaskEntry write event.
Example_Event,read event :0x1
EventMask:1
EventMask:0
```
