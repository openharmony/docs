# 开发指导<a name="ZH-CN_TOPIC_0000001078588414"></a>

-   [接口说明](#section158501652121514)
-   [开发流程](#section783435801510)
-   [编程实例](#section1426719434114)
    -   [实例描述](#section896412438910)
    -   [示例代码](#section149077554912)
    -   [结果验证](#section2059413981311)


## 接口说明<a name="section158501652121514"></a>

**表 1**  互斥锁模块接口

<a name="table37108292611"></a>
<table><thead align="left"><tr id="row8711112919610"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p3711102912617"><a name="p3711102912617"></a><a name="p3711102912617"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1671110293610"><a name="p1671110293610"></a><a name="p1671110293610"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p87114292617"><a name="p87114292617"></a><a name="p87114292617"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row37115291166"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1795312108911"><a name="p1795312108911"></a><a name="p1795312108911"></a>互斥锁的创建和删除</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1671120293611"><a name="p1671120293611"></a><a name="p1671120293611"></a>LOS_MuxCreate</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p171112291967"><a name="p171112291967"></a><a name="p171112291967"></a>创建互斥锁</p>
</td>
</tr>
<tr id="row17711329268"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p071114291864"><a name="p071114291864"></a><a name="p071114291864"></a>LOS_MuxDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p137111129965"><a name="p137111129965"></a><a name="p137111129965"></a>删除指定的互斥锁</p>
</td>
</tr>
<tr id="row5711192912616"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p86087143910"><a name="p86087143910"></a><a name="p86087143910"></a>互斥锁的申请和释放</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1171112295614"><a name="p1171112295614"></a><a name="p1171112295614"></a>LOS_MuxPend</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1271110291969"><a name="p1271110291969"></a><a name="p1271110291969"></a>申请指定的互斥锁</p>
</td>
</tr>
<tr id="row1571162918615"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p57111229967"><a name="p57111229967"></a><a name="p57111229967"></a>LOS_MuxPost</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107118291660"><a name="p107118291660"></a><a name="p107118291660"></a>释放指定的互斥锁</p>
</td>
</tr>
</tbody>
</table>

## 开发流程<a name="section783435801510"></a>

互斥锁典型场景的开发流程：

1.  创建互斥锁LOS\_MuxCreate。
2.  申请互斥锁LOS\_MuxPend。

    申请模式有三种：无阻塞模式、永久阻塞模式、定时阻塞模式。

    -   无阻塞模式：任务需要申请互斥锁，若该互斥锁当前没有任务持有，或者持有该互斥锁的任务和申请该互斥锁的任务为同一个任务，则申请成功。
    -   永久阻塞模式：任务需要申请互斥锁，若该互斥锁当前没有被占用，则申请成功。否则，该任务进入阻塞态，系统切换到就绪任务中优先级高者继续执行。任务进入阻塞态后，直到有其他任务释放该互斥锁，阻塞任务才会重新得以执行。
    -   定时阻塞模式：任务需要申请互斥锁，若该互斥锁当前没有被占用，则申请成功。否则该任务进入阻塞态，系统切换到就绪任务中优先级高者继续执行。任务进入阻塞态后，指定时间超时前有其他任务释放该互斥锁，或者用户指定时间超时后，阻塞任务才会重新得以执行。

3.  释放互斥锁LOS\_MuxPost。
    -   如果有任务阻塞于指定互斥锁，则唤醒被阻塞任务中优先级高的，该任务进入就绪态，并进行任务调度；
    -   如果没有任务阻塞于指定互斥锁，则互斥锁释放成功。

4.  删除互斥锁LOS\_MuxDelete。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   两个任务不能对同一把互斥锁加锁。如果某任务对已被持有的互斥锁加锁，则该任务会被挂起，直到持有该锁的任务对互斥锁解锁，才能执行对这把互斥锁的加锁操作。
>-   互斥锁不能在中断服务程序中使用。
>-   LiteOS-M内核作为实时操作系统需要保证任务调度的实时性，尽量避免任务的长时间阻塞，因此在获得互斥锁之后，应该尽快释放互斥锁。
>-   持有互斥锁的过程中，不得再调用LOS\_TaskPriSet等接口更改持有互斥锁任务的优先级。

## 编程实例<a name="section1426719434114"></a>

### 实例描述<a name="section896412438910"></a>

本实例实现如下流程。

1.  任务Example\_TaskEntry创建一个互斥锁，锁任务调度，创建两个任务Example\_MutexTask1、Example\_MutexTask2。Example\_MutexTask2优先级高于Example\_MutexTask1，解锁任务调度。
2.  Example\_MutexTask2被调度，以永久阻塞模式申请互斥锁，并成功获取到该互斥锁，然后任务休眠100Tick，Example\_MutexTask2挂起，Example\_MutexTask1被唤醒。
3.  Example\_MutexTask1以定时阻塞模式申请互斥锁，等待时间为10Tick，因互斥锁仍被Example\_MutexTask2持有，Example\_MutexTask1挂起。10Tick超时时间到达后，Example\_MutexTask1被唤醒，以永久阻塞模式申请互斥锁，因互斥锁仍被Example\_MutexTask2持有，Example\_MutexTask1挂起。
4.  100Tick休眠时间到达后，Example\_MutexTask2被唤醒， 释放互斥锁，唤醒Example\_MutexTask1。Example\_MutexTask1成功获取到互斥锁后，释放，删除互斥锁。

### 示例代码<a name="section149077554912"></a>

示例代码如下：

```
#include <string.h>
#include "los_mux.h"

/* 互斥锁句柄id */
UINT32 g_testMux;
/* 任务ID */
UINT32 g_testTaskId01;
UINT32 g_testTaskId02;

VOID Example_MutexTask1(VOID)
{
    UINT32 ret;

    printf("task1 try to get  mutex, wait 10 ticks.\n");
    /* 申请互斥锁 */
    ret = LOS_MuxPend(g_testMux, 10);

    if (ret == LOS_OK) {
        printf("task1 get mutex g_testMux.\n");
        /* 释放互斥锁 */
        LOS_MuxPost(g_testMux);
        return;
    } 
    if (ret == LOS_ERRNO_MUX_TIMEOUT ) {
            printf("task1 timeout and try to get mutex, wait forever.\n");
            /* 申请互斥锁 */
            ret = LOS_MuxPend(g_testMux, LOS_WAIT_FOREVER);
            if (ret == LOS_OK) {
                printf("task1 wait forever, get mutex g_testMux.\n");
                /* 释放互斥锁 */
                LOS_MuxPost(g_testMux);
                /* 删除互斥锁 */
                LOS_MuxDelete(g_testMux);
                printf("task1 post and delete mutex g_testMux.\n");
                return;
            }
    }
    return;
}

VOID Example_MutexTask2(VOID)
{
    printf("task2 try to get  mutex, wait forever.\n");
    /* 申请互斥锁 */
    (VOID)LOS_MuxPend(g_testMux, LOS_WAIT_FOREVER);

    printf("task2 get mutex g_testMux and suspend 100 ticks.\n");

    /* 任务休眠100Ticks */
    LOS_TaskDelay(100);

    printf("task2 resumed and post the g_testMux\n");
    /* 释放互斥锁 */
    LOS_MuxPost(g_testMux);
    return;
}

UINT32 Example_TaskEntry(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S task1;
    TSK_INIT_PARAM_S task2;

    /* 创建互斥锁 */
    LOS_MuxCreate(&g_testMux);

    /* 锁任务调度 */
    LOS_TaskLock();

    /* 创建任务1 */
    memset(&task1, 0, sizeof(TSK_INIT_PARAM_S));
    task1.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_MutexTask1;
    task1.pcName       = "MutexTsk1";
    task1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task1.usTaskPrio   = 5;
    ret = LOS_TaskCreate(&g_testTaskId01, &task1);
    if (ret != LOS_OK) {
        printf("task1 create failed.\n");
        return LOS_NOK;
    }

    /* 创建任务2 */
    memset(&task2, 0, sizeof(TSK_INIT_PARAM_S));
    task2.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_MutexTask2;
    task2.pcName       = "MutexTsk2";
    task2.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    task2.usTaskPrio   = 4;
    ret = LOS_TaskCreate(&g_testTaskId02, &task2);
    if (ret != LOS_OK) {
        printf("task2 create failed.\n");
        return LOS_NOK;
    }

    /* 解锁任务调度 */
    LOS_TaskUnlock();

    return LOS_OK;
}
```

### 结果验证<a name="section2059413981311"></a>

编译运行得到的结果为：

```
task2 try to get  mutex, wait forever.
task2 get mutex g_testMux and suspend 100 ticks.
task1 try to get  mutex, wait 10 ticks.
task1 timeout and try to get mutex, wait forever.
task2 resumed and post the g_testMux
task1 wait forever, get mutex g_testMux.
task1 post and delete mutex g_testMux.
```

