# 信号量

## 基本概念

信号量（Semaphore）是一种实现任务间通信的机制，可以实现任务间同步或共享资源的互斥访问。

一个信号量的数据结构中，通常有一个计数值，用于对有效资源数的计数，表示剩下的可被使用的共享资源数，其值的含义分两种情况：

- 0，表示该信号量当前不可获取，因此可能存在正在等待该信号量的任务。

- 正值，表示该信号量当前可被获取。

以同步为目的的信号量和以互斥为目的的信号量在使用上有如下不同：

- 用作互斥时，初始信号量计数值不为0，表示可用的共享资源个数。在需要使用共享资源前，先获取信号量，然后使用一个共享资源，使用完毕后释放信号量。这样在共享资源被取完，即信号量计数减至0时，其他需要获取信号量的任务将被阻塞，从而保证了共享资源的互斥访问。另外，当共享资源数为1时，建议使用二值信号量，一种类似于互斥锁的机制。

- 用作同步时，初始信号量计数值为0。任务1因获取不到信号量而阻塞，直到任务2或者某中断释放信号量，任务1才得以进入Ready或Running态，从而达到了任务间的同步。

## 运行机制

**信号量控制块**

```
/**
 * 信号量控制块数据结构
 */
typedef struct {
    UINT16            semStat;          /* 信号量状态 */
    UINT16            semType;          /* 信号量类型 */
    UINT16            semCount;         /* 信号量计数 */
    UINT16            semId;            /* 信号量索引号 */
    LOS_DL_LIST       semList;          /* 用于插入阻塞于信号量的任务 */
} LosSemCB;
```

**信号量运作原理**

信号量允许多个任务在同一时刻访问共享资源，但会限制同一时刻访问此资源的最大任务数目。当访问资源的任务数达到该资源允许的最大数量时，会阻塞其他试图获取该资源的任务，直到有任务释放该信号量。

- 信号量初始化
  初始化时为配置的N个信号量申请内存（N值可以由用户自行配置，通过LOSCFG_BASE_IPC_SEM_LIMIT宏实现），并把所有信号量初始化成未使用，加入到未使用链表中供系统使用。

- 信号量创建
  从未使用的信号量链表中获取一个信号量，并设定初值。

- 信号量申请
  若其计数器值大于0，则直接减1返回成功。否则任务阻塞，等待其它任务释放该信号量，等待的超时时间可设定。当任务被一个信号量阻塞时，将该任务挂到信号量等待任务队列的队尾。

- 信号量释放
  若没有任务等待该信号量，则直接将计数器加1返回。否则唤醒该信号量等待任务队列上的第一个任务。

- 信号量删除
  将正在使用的信号量置为未使用信号量，并挂回到未使用链表。

运行示意图如下图所示:

  **图1** 小型系统信号量运作示意图
  ![zh-cn_image_0000001132774752](figures/zh-cn_image_0000001132774752.png)

## 开发指导

### 接口说明

  **表1** 创建/删除信号量

| 接口**名称** | 描述 | 
| -------- | -------- |
| LOS_SemCreate | 创建信号量，返回信号量ID。 | 
| LOS_BinarySemCreate | 创建二值信号量，其计数值最大为1。 | 
| LOS_SemDelete | 删除指定的信号量。 | 

  **表2** 申请/释放信号量

| 接口**名称** | 描述 | 
| -------- | -------- |
| LOS_SemPend | 申请指定的信号量，并设置超时时间。 | 
| LOS_SemPost | 释放指定的信号量。 | 

### 开发流程

1. 创建信号量LOS_SemCreate，若要创建二值信号量则调用LOS_BinarySemCreate。

2. 申请信号量LOS_SemPend。

3. 释放信号量LOS_SemPost。

4. 删除信号量LOS_SemDelete。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 由于中断不能被阻塞，因此不能在中断中使用阻塞模式申请信号量。

### 编程实例

### 实例描述

本实例实现如下功能：

1. 测试任务ExampleSem创建一个信号量，锁任务调度，创建两个任务ExampleSemTask1、ExampleSemTask2, ExampleSemTask2优先级高于ExampleSemTask1，两个任务中申请同一信号量，解锁任务调度后两任务阻塞，测试任务ExampleSem释放信号量。

2. ExampleSemTask2得到信号量，被调度，然后任务休眠20Ticks，ExampleSemTask2延迟，ExampleSemTask1被唤醒。

3. ExampleSemTask1定时阻塞模式申请信号量，等待时间为10Ticks，因信号量仍被ExampleSemTask2持有，ExampleSemTask1挂起，10Ticks后仍未得到信号量，ExampleSemTask1被唤醒，试图以永久阻塞模式申请信号量，ExampleSemTask1挂起。

4. 20Tick后ExampleSemTask2唤醒， 释放信号量后，ExampleSemTask1得到信号量被调度运行，最后释放信号量。

5. ExampleSemTask1执行完，400Ticks后任务ExampleSem被唤醒，执行删除信号量。

### 编程示例

本演示代码在./kernel/liteos_a/testsuites/kernel/src/osTest.c中编译验证，在TestTaskEntry中调用验证入口函数ExampleSem。

示例代码如下：

```
#include "los_sem.h"
#include "securec.h"

/* 任务ID */
static UINT32 g_testTaskId01;
static UINT32 g_testTaskId02;

/* 测试任务优先级 */
#define TASK_PRIO_LOW   5
#define TASK_PRIO_HI    4

/* 信号量结构体id */
static UINT32 g_semId;

VOID ExampleSemTask1(VOID)
{
    UINT32 ret;

    dprintf("ExampleSemTask1 try get sem g_semId, timeout 10 ticks.\n");

    /* 定时阻塞模式申请信号量，定时时间为10ticks */
    ret = LOS_SemPend(g_semId, 10);
    /* 申请到信号量 */
    if (ret == LOS_OK) {
         LOS_SemPost(g_semId);
         return;
    }
    /* 定时时间到，未申请到信号量 */
    if (ret == LOS_ERRNO_SEM_TIMEOUT) {
        dprintf("ExampleSemTask1 timeout and try get sem g_semId wait forever.\n");

        /*永久阻塞模式申请信号量*/
        ret = LOS_SemPend(g_semId, LOS_WAIT_FOREVER);
        dprintf("ExampleSemTask1 wait_forever and get sem g_semId.\n");
        if (ret == LOS_OK) {
            dprintf("ExampleSemTask1 post sem g_semId.\n");
            LOS_SemPost(g_semId);
            return;
        }
    }
}

VOID ExampleSemTask2(VOID)
{
    UINT32 ret;
    dprintf("ExampleSemTask2 try get sem g_semId wait forever.\n");

    /* 永久阻塞模式申请信号量 */
    ret = LOS_SemPend(g_semId, LOS_WAIT_FOREVER);
    if (ret == LOS_OK) {
        dprintf("ExampleSemTask2 get sem g_semId and then delay 20 ticks.\n");
    }

    /* 任务休眠20 ticks */
    LOS_TaskDelay(20);

    dprintf("ExampleSemTask2 post sem g_semId.\n");
    /* 释放信号量 */
    LOS_SemPost(g_semId);
    return;
}

UINT32 ExampleSem(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S task1;
    TSK_INIT_PARAM_S task2;

   /* 创建信号量 */
    LOS_SemCreate(0, &g_semId);

    /* 锁任务调度 */
    LOS_TaskLock();

    /* 创建任务1 */
    (VOID)memset_s(&task1, sizeof(TSK_INIT_PARAM_S), 0, sizeof(TSK_INIT_PARAM_S));
    task1.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleSemTask1;
    task1.pcName       = "TestTask1";
    task1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task1.usTaskPrio   = TASK_PRIO_LOW;
    ret = LOS_TaskCreate(&g_testTaskId01, &task1);
    if (ret != LOS_OK) {
        dprintf("task1 create failed .\n");
        return LOS_NOK;
    }

    /* 创建任务2 */
    (VOID)memset_s(&task2, sizeof(TSK_INIT_PARAM_S), 0, sizeof(TSK_INIT_PARAM_S));
    task2.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleSemTask2;
    task2.pcName       = "TestTask2";
    task2.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task2.usTaskPrio   = TASK_PRIO_HI;
    ret = LOS_TaskCreate(&g_testTaskId02, &task2);
    if (ret != LOS_OK) {
        dprintf("task2 create failed.\n");
        return LOS_NOK;
    }

    /* 解锁任务调度 */
    LOS_TaskUnlock();

    /* 任务休眠400 ticks */
    LOS_TaskDelay(400);

    ret = LOS_SemPost(g_semId);

    /* 任务休眠400 ticks */
    LOS_TaskDelay(400);

    /* 删除信号量 */
    LOS_SemDelete(g_semId);
    return LOS_OK;
}
```

### 结果验证

编译运行得到的结果为：

```
ExampleSemTask2 try get sem g_semId wait forever.
ExampleSemTask1 try get sem g_semId, timeout 10 ticks.
ExampleSemTask1 timeout and try get sem g_semId wait forever.
ExampleSemTask2 get sem g_semId and then delay 20 ticks.
ExampleSemTask2 post sem g_semId.
ExampleSemTask1 wait_forever and get sem g_semId.
ExampleSemTask1 post sem g_semId.
```
