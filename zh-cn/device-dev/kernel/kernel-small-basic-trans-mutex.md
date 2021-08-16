# 互斥锁<a name="ZH-CN_TOPIC_0000001078912734"></a>

-   [基本概念](#section85865329185)
-   [运行机制](#section8547454201819)
-   [开发指导](#section2038861117194)
    -   [接口说明](#section11168318131917)
    -   [开发流程](#section4201191122116)
    -   [编程实例](#section10679328202117)


## 基本概念<a name="section85865329185"></a>

互斥锁又称互斥型信号量，用于实现对共享资源的独占式处理。当有任务持有时，这个任务获得该互斥锁的所有权。当该任务释放它时，任务失去该互斥锁的所有权。当一个任务持有互斥锁时，其他任务将不能再持有该互斥锁。多任务环境下往往存在多个任务竞争同一共享资源的应用场景，互斥锁可被用于对共享资源的保护从而实现独占式访问。

互斥锁属性包含3个属性：协议属性、优先级上限属性和类型属性。协议属性用于处理不同优先级的任务申请互斥锁，协议属性包含如下三种：

-   LOS\_MUX\_PRIO\_NONE

    不对申请互斥锁的任务的优先级进行继承或保护操作。

-   LOS\_MUX\_PRIO\_INHERIT

    优先级继承属性，默认设置为该属性，对申请互斥锁的任务的优先级进行继承。在互斥锁设置为本协议属性情况下，申请互斥锁时，如果高优先级任务阻塞于互斥锁，则把持有互斥锁任务的优先级备份到任务控制块的优先级位图中，然后把任务优先级设置为和高优先级任务相同的优先级；持有互斥锁的任务释放互斥锁时，从任务控制块的优先级位图恢复任务优先级。

-   LOS\_MUX\_PRIO\_PROTECT

    优先级保护属性，对申请互斥锁的任务的优先级进行保护。在互斥锁设置为本协议属性情况下，申请互斥锁时，如果任务优先级小于互斥锁优先级上限，则把任务优先级备份到任务控制块的优先级位图中，然后把任务优先级设置为互斥锁优先级上限属性值；释放互斥锁时，从任务控制块的优先级位图恢复任务优先级。


互斥锁的类型属性用于标记是否检测死锁，是否支持递归持有，类型属性包含如下三种：

-   LOS\_MUX\_NORMAL

    普通互斥锁，不会检测死锁。如果任务试图对一个互斥锁重复持有，将会引起这个线程的死锁。如果试图释放一个由别的任务持有的互斥锁，或者如果一个任务试图重复释放互斥锁都会引发不可预料的结果。

-   LOS\_MUX\_RECURSIVE

    递归互斥锁，默认设置为该属性。在互斥锁设置为本类型属性情况下，允许同一个任务对互斥锁进行多次持有锁，持有锁次数和释放锁次数相同，其他任务才能持有该互斥锁。如果试图持有已经被其他任务持有的互斥锁，或者如果试图释放已经被释放的互斥锁，会返回错误码。

-   LOS\_MUX\_ERRORCHECK

    错误检测互斥锁，会自动检测死锁。在互斥锁设置为本类型属性情况下，如果任务试图对一个互斥锁重复持有，或者试图释放一个由别的任务持有的互斥锁，或者如果一个任务试图释放已经被释放的互斥锁，都会返回错误码。


## 运行机制<a name="section8547454201819"></a>

多任务环境下会存在多个任务访问同一公共资源的场景，而有些公共资源是非共享的，需要任务进行独占式处理。互斥锁怎样来避免这种冲突呢？

用互斥锁处理非共享资源的同步访问时，如果有任务访问该资源，则互斥锁为加锁状态。此时其他任务如果想访问这个公共资源则会被阻塞，直到互斥锁被持有该锁的任务释放后，其他任务才能重新访问该公共资源，此时互斥锁再次上锁，如此确保同一时刻只有一个任务正在访问这个公共资源，保证了公共资源操作的完整性。

**图 1**  互斥锁运作示意图<a name="fig16821181173811"></a>  
![](figure/互斥锁运作示意图-23.png "互斥锁运作示意图-23")

## 开发指导<a name="section2038861117194"></a>

### 接口说明<a name="section11168318131917"></a>

**表 1**  互斥锁模块接口

<a name="table37108292611"></a>
<table><thead align="left"><tr id="row8711112919610"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p3711102912617"><a name="p3711102912617"></a><a name="p3711102912617"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="33.31333133313331%" id="mcps1.2.4.1.2"><p id="p1671110293610"><a name="p1671110293610"></a><a name="p1671110293610"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.35333533353336%" id="mcps1.2.4.1.3"><p id="p87114292617"><a name="p87114292617"></a><a name="p87114292617"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row332716281313"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1795312108911"><a name="p1795312108911"></a><a name="p1795312108911"></a>初始化和销毁互斥锁</p>
</td>
<td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.2.4.1.2 "><p id="p1932716285312"><a name="p1932716285312"></a><a name="p1932716285312"></a>LOS_MuxInit</p>
</td>
<td class="cellrowborder" valign="top" width="33.35333533353336%" headers="mcps1.2.4.1.3 "><p id="p932762812319"><a name="p932762812319"></a><a name="p932762812319"></a>互斥锁初始化</p>
</td>
</tr>
<tr id="row37115291166"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p127613211335"><a name="p127613211335"></a><a name="p127613211335"></a>LOS_MuxDestroy</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p137111129965"><a name="p137111129965"></a><a name="p137111129965"></a>销毁指定的互斥锁</p>
</td>
</tr>
<tr id="row17711329268"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p18125182815396"><a name="p18125182815396"></a><a name="p18125182815396"></a>互斥锁的申请和释放</p>
</td>
<td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.2.4.1.2 "><p id="p215615953415"><a name="p215615953415"></a><a name="p215615953415"></a>LOS_MuxLock</p>
</td>
<td class="cellrowborder" valign="top" width="33.35333533353336%" headers="mcps1.2.4.1.3 "><p id="p20994162353515"><a name="p20994162353515"></a><a name="p20994162353515"></a>申请指定的互斥锁</p>
</td>
</tr>
<tr id="row5711192912616"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7974187183520"><a name="p7974187183520"></a><a name="p7974187183520"></a>LOS_MuxTrylock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1271110291969"><a name="p1271110291969"></a><a name="p1271110291969"></a>尝试申请指定的互斥锁，不阻塞</p>
</td>
</tr>
<tr id="row1571162918615"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p13021319143515"><a name="p13021319143515"></a><a name="p13021319143515"></a>LOS_MuxUnlock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107118291660"><a name="p107118291660"></a><a name="p107118291660"></a>释放指定的互斥锁</p>
</td>
</tr>
<tr id="row344193024114"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p16441730114110"><a name="p16441730114110"></a><a name="p16441730114110"></a>校验互斥锁</p>
</td>
<td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.2.4.1.2 "><p id="p1544183074110"><a name="p1544183074110"></a><a name="p1544183074110"></a>LOS_MuxIsValid</p>
</td>
<td class="cellrowborder" valign="top" width="33.35333533353336%" headers="mcps1.2.4.1.3 "><p id="p3441193017416"><a name="p3441193017416"></a><a name="p3441193017416"></a>判断互斥锁释放有效</p>
</td>
</tr>
<tr id="row1065116418421"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p2189182734211"><a name="p2189182734211"></a><a name="p2189182734211"></a>初始化和销毁互斥锁属性</p>
</td>
<td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.2.4.1.2 "><p id="p1565244144210"><a name="p1565244144210"></a><a name="p1565244144210"></a>LOS_MuxAttrInit</p>
</td>
<td class="cellrowborder" valign="top" width="33.35333533353336%" headers="mcps1.2.4.1.3 "><p id="p14652342426"><a name="p14652342426"></a><a name="p14652342426"></a>互斥锁属性初始化</p>
</td>
</tr>
<tr id="row538718619427"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p538756104217"><a name="p538756104217"></a><a name="p538756104217"></a>LOS_MuxAttrDestroy</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p23875654210"><a name="p23875654210"></a><a name="p23875654210"></a>销毁指定的互斥锁属性</p>
</td>
</tr>
<tr id="row8143848467"><td class="cellrowborder" rowspan="8" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p2926915154717"><a name="p2926915154717"></a><a name="p2926915154717"></a>设置和获取互斥锁属性</p>
</td>
<td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.2.4.1.2 "><p id="p171441842465"><a name="p171441842465"></a><a name="p171441842465"></a>LOS_MuxAttrGetType</p>
</td>
<td class="cellrowborder" valign="top" width="33.35333533353336%" headers="mcps1.2.4.1.3 "><p id="p151444418461"><a name="p151444418461"></a><a name="p151444418461"></a>获取指定互斥锁属性的类型属性</p>
</td>
</tr>
<tr id="row99314413464"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p793218404613"><a name="p793218404613"></a><a name="p793218404613"></a>LOS_MuxAttrSetType</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p51371843194813"><a name="p51371843194813"></a><a name="p51371843194813"></a>设置指定互斥锁属性的类型属性</p>
</td>
</tr>
<tr id="row204470514615"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p13447115154614"><a name="p13447115154614"></a><a name="p13447115154614"></a>LOS_MuxAttrGetProtocol</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p20871044144720"><a name="p20871044144720"></a><a name="p20871044144720"></a>获取指定互斥锁属性的协议属性</p>
</td>
</tr>
<tr id="row69051358465"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p10906165124617"><a name="p10906165124617"></a><a name="p10906165124617"></a>LOS_MuxAttrSetProtocol</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1690617554610"><a name="p1690617554610"></a><a name="p1690617554610"></a>设置指定互斥锁属性的协议属性</p>
</td>
</tr>
<tr id="row133571666467"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6357146154616"><a name="p6357146154616"></a><a name="p6357146154616"></a>LOS_MuxAttrGetPrioceiling</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p559511469478"><a name="p559511469478"></a><a name="p559511469478"></a>获取指定互斥锁属性的优先级上限属性</p>
</td>
</tr>
<tr id="row5789065465"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1778916634614"><a name="p1778916634614"></a><a name="p1778916634614"></a>LOS_MuxAttrSetPrioceiling</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p16789126134614"><a name="p16789126134614"></a><a name="p16789126134614"></a>设置指定互斥锁属性的优先级上限属性</p>
</td>
</tr>
<tr id="row10251772469"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p199321752124718"><a name="p199321752124718"></a><a name="p199321752124718"></a>LOS_MuxGetPrioceiling</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1128349114718"><a name="p1128349114718"></a><a name="p1128349114718"></a>获取互斥锁优先级上限属性</p>
</td>
</tr>
<tr id="row197256714468"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p72518754614"><a name="p72518754614"></a><a name="p72518754614"></a>LOS_MuxSetPrioceiling</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p177254713460"><a name="p177254713460"></a><a name="p177254713460"></a>设置互斥锁优先级上限属性</p>
</td>
</tr>
</tbody>
</table>

### 开发流程<a name="section4201191122116"></a>

互斥锁典型场景的开发流程：

1. 初始化互斥锁LOS\_MuxInit。

2. 申请互斥锁LOS\_MuxLock。

申请模式有三种：无阻塞模式、永久阻塞模式、定时阻塞模式。

-   无阻塞模式：任务需要申请互斥锁，若该互斥锁当前没有任务持有，或者持有该互斥锁的任务和申请该互斥锁的任务为同一个任务，则申请成功；
-   永久阻塞模式：任务需要申请互斥锁，若该互斥锁当前没有被占用，则申请成功。否则，该任务进入阻塞态，系统切换到就绪任务中优先级高者继续执行。任务进入阻塞态后，直到有其他任务释放该互斥锁，阻塞任务才会重新得以执行；
-   定时阻塞模式：任务需要申请互斥锁，若该互斥锁当前没有被占用，则申请成功。否则该任务进入阻塞态，系统切换到就绪任务中优先级高者继续执行。任务进入阻塞态后，指定时间超时前有其他任务释放该互斥锁，或者用 户指定时间超时后，阻塞任务才会重新得以执行。

3. 释放互斥锁LOS\_MuxUnlock。

-   如果有任务阻塞于指定互斥锁，则唤醒被阻塞任务中优先级高的，该任务进入就绪态，并进行任务调度；
-   如果没有任务阻塞于指定互斥锁，则互斥锁释放成功。

4. 销毁互斥锁LOS\_MuxDestroy。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   两个任务不能对同一把互斥锁加锁。如果某任务对已被持有的互斥锁加锁，则该任务会被挂起，直到持有该锁的任务对互斥锁解锁，才能执行对这把互斥锁的加锁操作。
>-   互斥锁不能在中断服务程序中使用。
>-   LiteOS-A内核作为实时操作系统需要保证任务调度的实时性，尽量避免任务的长时间阻塞，因此在获得互斥锁之后，应该尽快释放互斥锁。

### 编程实例<a name="section10679328202117"></a>

**实例描述**

本实例实现如下流程：

1.  任务Example\_TaskEntry创建一个互斥锁，锁任务调度，创建两个任务Example\_MutexTask1、Example\_MutexTask2。Example\_MutexTask2优先级高于Example\_MutexTask1，解锁任务调度。
2.  Example\_MutexTask2被调度，以永久阻塞模式申请互斥锁，并成功获取到该互斥锁，然后任务休眠100Tick，Example\_MutexTask2挂起，Example\_MutexTask1被唤醒。
3.  Example\_MutexTask1以定时阻塞模式申请互斥锁，等待时间为10Tick，因互斥锁仍被Example\_MutexTask2持有，Example\_MutexTask1挂起。10Tick超时时间到达后，Example\_MutexTask1被唤醒，以永久阻塞模式申请互斥锁，因互斥锁仍被Example\_MutexTask2持有，Example\_MutexTask1挂起。
4.  100Tick休眠时间到达后，Example\_MutexTask2被唤醒， 释放互斥锁，唤醒Example\_MutexTask1。Example\_MutexTask1成功获取到互斥锁后，释放，删除互斥锁。

**示例代码**

示例代码如下：

```
#include <string.h>
#include "los_mux.h"

/* 互斥锁 */
LosMux g_testMux;
/* 任务ID */
UINT32 g_testTaskId01;
UINT32 g_testTaskId02;

VOID Example_MutexTask1(VOID)
{
    UINT32 ret;

    printf("task1 try to get mutex, wait 10 ticks.\n");
    /* 申请互斥锁 */
    ret = LOS_MuxLock(&g_testMux, 10);

    if (ret == LOS_OK) {
        printf("task1 get mutex g_testMux.\n");
        /* 释放互斥锁 */
        LOS_MuxUnlock(&g_testMux);
        return;
    } 
    if (ret == LOS_ETIMEDOUT ) {
            printf("task1 timeout and try to get mutex, wait forever.\n");
            /* 申请互斥锁 */
            ret = LOS_MuxLock(&g_testMux, LOS_WAIT_FOREVER);
            if (ret == LOS_OK) {
                printf("task1 wait forever, get mutex g_testMux.\n");
                /* 释放互斥锁 */
                LOS_MuxUnlock(&g_testMux);
                /* 删除互斥锁 */
                LOS_MuxDestroy(&g_testMux);
                printf("task1 post and delete mutex g_testMux.\n");
                return;
            }
    }
    return;
}

VOID Example_MutexTask2(VOID)
{
    printf("task2 try to get mutex, wait forever.\n");
    /* 申请互斥锁 */
    (VOID)LOS_MuxLock(&g_testMux, LOS_WAIT_FOREVER);

    printf("task2 get mutex g_testMux and suspend 100 ticks.\n");

    /* 任务休眠100Ticks */
    LOS_TaskDelay(100);

    printf("task2 resumed and post the g_testMux\n");
    /* 释放互斥锁 */
    LOS_MuxUnlock(&g_testMux);
    return;
}

UINT32 Example_MutexEntry(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S task1;
    TSK_INIT_PARAM_S task2;

    /* 初始化互斥锁 */
    LOS_MuxInit(&g_testMux, NULL);

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

**结果验证**

编译运行得到的结果为：

```
task1 try to get mutex, wait 10 ticks.
task2 try to get mutex, wait forever.
task2 get mutex g_testMux and suspend 100 ticks.
task1 timeout and try to get mutex, wait forever.
task2 resumed and post the g_testMux
task1 wait forever, get mutex g_testMux.
task1 post and delete mutex g_testMux.
```

