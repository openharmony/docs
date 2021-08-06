# 开发指导<a name="ZH-CN_TOPIC_0000001078876452"></a>

-   [接口说明](#section158501652121514)
-   [开发流程](#section783435801510)
-   [编程实例](#section460018317164)
    -   [实例描述](#section22061718111412)
    -   [示例代码](#section1775922321416)
    -   [结果验证](#section160404016213)


## 接口说明<a name="section158501652121514"></a>

<a name="table1078714915105"></a>
<table><thead align="left"><tr id="row1280518971010"><th class="cellrowborder" valign="top" width="20.1%" id="mcps1.1.4.1.1"><p id="p1380510912104"><a name="p1380510912104"></a><a name="p1380510912104"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="20.52%" id="mcps1.1.4.1.2"><p id="p08051291106"><a name="p08051291106"></a><a name="p08051291106"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="59.38%" id="mcps1.1.4.1.3"><p id="p12805149151012"><a name="p12805149151012"></a><a name="p12805149151012"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row168052913104"><td class="cellrowborder" rowspan="3" valign="top" width="20.1%" headers="mcps1.1.4.1.1 "><p id="p180618915101"><a name="p180618915101"></a><a name="p180618915101"></a>创建/删除信号量</p>
</td>
<td class="cellrowborder" valign="top" width="20.52%" headers="mcps1.1.4.1.2 "><p id="p198061196105"><a name="p198061196105"></a><a name="p198061196105"></a>LOS_SemCreate</p>
</td>
<td class="cellrowborder" valign="top" width="59.38%" headers="mcps1.1.4.1.3 "><p id="p1980609121010"><a name="p1980609121010"></a><a name="p1980609121010"></a>创建信号量，返回信号量ID</p>
</td>
</tr>
<tr id="row4806990105"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p280620917109"><a name="p280620917109"></a><a name="p280620917109"></a>LOS_BinarySemCreate</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p780614919107"><a name="p780614919107"></a><a name="p780614919107"></a>创建二值信号量，其计数值最大为1</p>
</td>
</tr>
<tr id="row17806159151018"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p38067931012"><a name="p38067931012"></a><a name="p38067931012"></a>LOS_SemDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p168063941015"><a name="p168063941015"></a><a name="p168063941015"></a>删除指定的信号量</p>
</td>
</tr>
<tr id="row188061098102"><td class="cellrowborder" rowspan="2" valign="top" width="20.1%" headers="mcps1.1.4.1.1 "><p id="p5806179161014"><a name="p5806179161014"></a><a name="p5806179161014"></a>申请/释放信号量</p>
</td>
<td class="cellrowborder" valign="top" width="20.52%" headers="mcps1.1.4.1.2 "><p id="p16806159201015"><a name="p16806159201015"></a><a name="p16806159201015"></a>LOS_SemPend</p>
</td>
<td class="cellrowborder" valign="top" width="59.38%" headers="mcps1.1.4.1.3 "><p id="p4806149191011"><a name="p4806149191011"></a><a name="p4806149191011"></a>申请指定的信号量，并设置超时时间</p>
</td>
</tr>
<tr id="row4806199141019"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p280618913105"><a name="p280618913105"></a><a name="p280618913105"></a>LOS_SemPost</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p178061917109"><a name="p178061917109"></a><a name="p178061917109"></a>释放指定的信号量</p>
</td>
</tr>
</tbody>
</table>

## 开发流程<a name="section783435801510"></a>

1.  创建信号量LOS\_SemCreate，若要创建二值信号量则调用LOS\_BinarySemCreate。
2.  申请信号量LOS\_SemPend。
3.  释放信号量LOS\_SemPost。
4.  删除信号量LOS\_SemDelete。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>由于中断不能被阻塞，因此不能在中断中使用阻塞模式申请信号量。

## 编程实例<a name="section460018317164"></a>

### 实例描述<a name="section22061718111412"></a>

本实例实现如下功能：

1.  测试任务ExampleSem创建一个信号量，锁任务调度，创建两个任务ExampleSemTask1、ExampleSemTask2, ExampleSemTask2优先级高于ExampleSemTask1，两个任务中申请同一信号量，解锁任务调度后两任务阻塞，测试任务ExampleSem释放信号量。
2.  ExampleSemTask2得到信号量，被调度，然后任务休眠20Tick，ExampleSemTask2延迟，ExampleSemTask1被唤醒。
3.  ExampleSemTask1定时阻塞模式申请信号量，等待时间为10Tick，因信号量仍被ExampleSemTask2持有，ExampleSemTask1挂起，10Tick后仍未得到信号量，ExampleSemTask1被唤醒，试图以永久阻塞模式申请信号量，ExampleSemTask1挂起。
4.  20Tick后ExampleSemTask2唤醒， 释放信号量后，ExampleSemTask1得到信号量被调度运行，最后释放信号量。
5.  ExampleSemTask1执行完，400Tick后任务ExampleSem被唤醒，执行删除信号量。

### 示例代码<a name="section1775922321416"></a>

示例代码如下：

```
#include "los_sem.h"
#include "securec.h"

/* 任务ID */
static UINT32 g_testTaskId01;
static UINT32 g_testTaskId02;

/* 测试任务优先级 */
#define TASK_PRIO_TEST  5

/* 信号量结构体id */
static UINT32 g_semId;

VOID ExampleSemTask1(VOID)
{
    UINT32 ret;

    printf("ExampleSemTask1 try get sem g_semId, timeout 10 ticks.\n");

    /* 定时阻塞模式申请信号量，定时时间为10ticks */
    ret = LOS_SemPend(g_semId, 10);

    /* 申请到信号量 */
    if (ret == LOS_OK) {
         LOS_SemPost(g_semId);
         return;
    }
    /* 定时时间到，未申请到信号量 */
    if (ret == LOS_ERRNO_SEM_TIMEOUT) {
        printf("ExampleSemTask1 timeout and try get sem g_semId wait forever.\n");

        /*永久阻塞模式申请信号量*/
        ret = LOS_SemPend(g_semId, LOS_WAIT_FOREVER);
        printf("ExampleSemTask1 wait_forever and get sem g_semId.\n");
        if (ret == LOS_OK) {
            LOS_SemPost(g_semId);
            return;
        }
    }
}

VOID ExampleSemTask2(VOID)
{
    UINT32 ret;
    printf("ExampleSemTask2 try get sem g_semId wait forever.\n");

    /* 永久阻塞模式申请信号量 */
    ret = LOS_SemPend(g_semId, LOS_WAIT_FOREVER);

    if (ret == LOS_OK) {
        printf("ExampleSemTask2 get sem g_semId and then delay 20 ticks.\n");
    }

    /* 任务休眠20 ticks */
    LOS_TaskDelay(20);

    printf("ExampleSemTask2 post sem g_semId.\n");
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
    task1.usTaskPrio   = TASK_PRIO_TEST;
    ret = LOS_TaskCreate(&g_testTaskId01, &task1);
    if (ret != LOS_OK) {
        printf("task1 create failed.\n");
        return LOS_NOK;
    }

    /* 创建任务2 */
    (VOID)memset_s(&task2, sizeof(TSK_INIT_PARAM_S), 0, sizeof(TSK_INIT_PARAM_S));
    task2.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleSemTask2;
    task2.pcName       = "TestTask2";
    task2.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task2.usTaskPrio   = (TASK_PRIO_TEST - 1);
    ret = LOS_TaskCreate(&g_testTaskId02, &task2);
    if (ret != LOS_OK) {
        printf("task2 create failed.\n");
        return LOS_NOK;
    }

    /* 解锁任务调度 */
    LOS_TaskUnlock();

    ret = LOS_SemPost(g_semId);

    /* 任务休眠400 ticks */
    LOS_TaskDelay(400);

    /* 删除信号量 */
    LOS_SemDelete(g_semId);
    return LOS_OK;
}
```

### 结果验证<a name="section160404016213"></a>

编译运行得到的结果为：

```
ExampleSemTask2 try get sem g_semId wait forever.
ExampleSemTask2 get sem g_semId and then delay 20 ticks.
ExampleSemTask1 try get sem g_semId, timeout 10 ticks.

ExampleSemTask1 timeout and try get sem g_semId wait forever.
ExampleSemTask2 post sem g_semId.
ExampleSemTask1 wait_forever and get sem g_semId.
```

