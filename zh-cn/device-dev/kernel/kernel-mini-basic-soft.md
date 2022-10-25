# 软件定时器


## 基本概念

软件定时器，是基于系统Tick时钟中断且由软件来模拟的定时器，当经过设定的Tick时钟计数值后会触发用户定义的回调函数。定时精度与系统Tick时钟的周期有关。

硬件定时器受硬件的限制，数量上不足以满足用户的实际需求，因此为了满足用户需求，提供更多的定时器，OpenHarmony LiteOS-M内核提供软件定时器功能。软件定时器扩展了定时器的数量，允许创建更多的定时业务。

软件定时器功能上支持：

- 静态裁剪：能通过宏关闭软件定时器功能。

- 软件定时器创建。

- 软件定时器启动。

- 软件定时器停止。

- 软件定时器删除。

- 软件定时器剩余Tick数获取。


## 运行机制

软件定时器是系统资源，在模块初始化的时候已经分配了一块连续的内存，系统支持的最大定时器个数由los_config.h中的LOSCFG_BASE_CORE_SWTMR_LIMIT宏配置，该值按产品实际需要设定。

软件定时器使用了系统的一个队列和一个任务资源，软件定时器的触发遵循队列规则，先进先出。定时时间短的定时器总是比定时时间长的靠近队列头，满足优先被触发的准则。

软件定时器以Tick为基本计时单位，当用户创建并启动一个软件定时器时，OpenHarmony LiteOS-M内核会根据当前系统Tick时间及用户设置的定时间隔确定该定时器的到期Tick时间，并将该定时器控制结构挂入计时全局链表。

当Tick中断到来时，在Tick中断处理函数中扫描软件定时器的计时全局链表，看是否有定时器超时，若有则将超时的定时器记录下来。

Tick中断处理函数结束后，软件定时器任务（优先级为最高）被唤醒，在该任务中调用之前记录下来的定时器的超时回调函数。


### 定时器状态

- OS_SWTMR_STATUS_UNUSED（未使用）
  系统在定时器模块初始化的时候将系统中所有定时器资源初始化成该状态。

- OS_SWTMR_STATUS_CREATED（创建未启动/停止）
  在未使用状态下调用LOS_SwtmrCreate接口或者启动后调用LOS_SwtmrStop接口后，定时器将变成该状态。

- OS_SWTMR_STATUS_TICKING（计数）
  在定时器创建后调用LOS_SwtmrStart接口，定时器将变成该状态，表示定时器运行时的状态。


### 定时器模式

OpenHarmony LiteOS-M内核的软件定时器提供三类定时器机制：

- 第一类是单次触发定时器，这类定时器在启动后只会触发一次定时器事件，然后定时器自动删除。

- 第二类是周期触发定时器，这类定时器会周期性的触发定时器事件，直到用户手动地停止定时器，否则将永远持续执行下去。

- 第三类也是单次触发定时器，但与第一类不同之处在于这类定时器超时后不会自动删除，需要调用定时器删除接口删除定时器。


## 接口说明

OpenHarmony LiteOS-M内核的软件定时器模块提供下面几种功能，接口详细信息可以查看API参考。

  **表1** 软件定时器接口

| 功能分类 | 接口描述 |
| -------- | -------- |
| 创建、删除定时器 | -&nbsp;LOS_SwtmrCreate：创建定时器。<br/>-&nbsp;LOS_SwtmrDelete：删除定时器。 |
| 启动、停止定时器 | -&nbsp;LOS_SwtmrStart：启动定时器。<br/>-&nbsp;LOS_SwtmrStop：停止定时器。 |
| 获得软件定时器剩余Tick数 | LOS_SwtmrTimeGet：获得软件定时器剩余Tick数。 |


## 开发流程

软件定时器的典型开发流程：

1. 配置软件定时器。
   - 确认配置项LOSCFG_BASE_CORE_SWTMR和LOSCFG_BASE_IPC_QUEUE为1打开状态；
   - 配置LOSCFG_BASE_CORE_SWTMR_LIMIT最大支持的软件定时器数；
   - 配置OS_SWTMR_HANDLE_QUEUE_SIZE软件定时器队列最大长度；

2. 创建定时器LOS_SwtmrCreate。
   - 创建一个指定计时时长、指定超时处理函数、指定触发模式的软件定时器；
   - 返回函数运行结果，成功或失败；

3. 启动定时器LOS_SwtmrStart。

4. 获得软件定时器剩余Tick数LOS_SwtmrTimeGet。

5. 停止定时器LOS_SwtmrStop。

6. 删除定时器LOS_SwtmrDelete。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 软件定时器的回调函数中不要做过多操作，不要使用可能引起任务挂起或者阻塞的接口或操作。
> 
> - 软件定时器使用了系统的一个队列和一个任务资源，软件定时器任务的优先级设定为0，且不允许修改  。
> 
> - 系统可配置的软件定时器资源个数是指：整个系统可使用的软件定时器资源总个数，而并非是用户可使用的软件定时器资源个数。例如：系统软件定时器多占用一个软件定时器资源数，那么用户能使用的软件定时器资源就会减少一个。
> 
> - 创建单次软件定时器，该定时器超时执行完回调函数后，系统会自动删除该软件定时器，并回收资源。
> 
> - 创建单次不自删除属性的定时器，用户需要调用定时器删除接口删除定时器，回收定时器资源，避免资源泄露。


## 编程实例


### 实例描述

在下面的例子中，演示如下功能：

1. 软件定时器创建、启动、删除、暂停、重启操作。

2. 单次软件定时器，周期软件定时器使用方法。


### 示例代码

前提条件：

- 在los_config.h中，将LOSCFG_BASE_CORE_SWTMR配置项打开。

- 在los_config.h中，将LOSCFG_BASE_CORE_SWTMR_ALIGN配置项关闭，示例代码中演示代码不涉及定时器对齐。

- 配置好LOSCFG_BASE_CORE_SWTMR_LIMIT最大支持的软件定时器数。

- 配置好OS_SWTMR_HANDLE_QUEUE_SIZE软件定时器队列最大长度。

代码实现如下：

本演示代码在 ./kernel/liteos_m/testsuites/src/osTest.c 中编译验证，在TestTaskEntry中调用验证入口函数ExampleSwtmr。


```
#include "los_swtmr.h"

/* 定时器间隔时间 */
#define SWTMR_INTERVAL_LONG      1000
#define SWTMR_INTERVAL_SHORT     100

/* 定时器触发次数计数 */
UINT32 g_timerCount1 = 0;
UINT32 g_timerCount2 = 0;

/* 回调函数1，单次触发定时器的回调函数 */
void Timer1Callback(UINT32 arg)
{
    g_timerCount1++;
    printf("g_timerCount1=%d\n", g_timerCount1);
}

/* 回调函数2，多次触发定时器的回调函数 */
void Timer2Callback(UINT32 arg)
{
    g_timerCount2++;
    printf("g_timerCount2=%d\n", g_timerCount2);
}

void SwtmrTest(void)
{
    UINT32 ret;
    UINT32 id1; // 定时器id1，单次触发定时器
    UINT32 id2; // 定时器id2，周期触发定时器
    UINT32 tickCount;

#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == 1)
    /* 创建单次软件定时器，Tick数为1000，启动到1000Tick数时执行回调函数1 */
    LOS_SwtmrCreate(SWTMR_INTERVAL_LONG, LOS_SWTMR_MODE_ONCE, Timer1Callback, &id1, 0,
                    OS_SWTMR_ROUSES_IGNORE, OS_SWTMR_ALIGN_SENSITIVE);

    /* 创建周期性软件定时器，每100Tick数执行回调函数2 */
    LOS_SwtmrCreate(SWTMR_INTERVAL_SHORT, LOS_SWTMR_MODE_PERIOD, Timer2Callback, &id2, 0,
                    OS_SWTMR_ROUSES_IGNORE, OS_SWTMR_ALIGN_SENSITIVE);
#else
    /* 创建单次软件定时器，Tick数为1000，启动到1000Tick数时执行回调函数1 */
    LOS_SwtmrCreate(SWTMR_INTERVAL_LONG, LOS_SWTMR_MODE_ONCE, Timer1Callback, &id1, 0);

    /* 创建周期性软件定时器，每100Tick数执行回调函数2 */
    LOS_SwtmrCreate(SWTMR_INTERVAL_SHORT, LOS_SWTMR_MODE_PERIOD, Timer2Callback, &id2, 0);
#endif

    /* 启动单次软件定时器 */
    ret = LOS_SwtmrStart(id1);
    printf("start Timer1 %s\n", (ret == LOS_OK) ? "success" : "failed");

    /* 短时间延时，定时器还未触发 */
    LOS_TaskDelay(SWTMR_INTERVAL_SHORT);

    /* 单次定时器还未到时间触发，此时停止应该成功 */
    ret = LOS_SwtmrStop(id1);
    printf("stop timer1 %s\n", (ret == LOS_OK) ? "success" : "failed");

    LOS_SwtmrStart(id1);
    
    /* 长时间延时，定时器触发 */
    LOS_TaskDelay(SWTMR_INTERVAL_LONG);

    /* 单次定时器触发后自删除，此时停止失败才是正常 */
    ret = LOS_SwtmrStop(id1);
    printf("timer1 self delete test %s\n", (ret != LOS_OK) ? "success" : "failed");

    /* 启动周期性软件定时器 */
    ret = LOS_SwtmrStart(id2);
    printf("start Timer2 %s\n", (ret == LOS_OK) ? "success" : "failed");

    /* 长时间延时，定时器周期触发 */
    LOS_TaskDelay(SWTMR_INTERVAL_LONG);

    LOS_SwtmrStop(id2);

    ret = LOS_SwtmrDelete(id2);
    if (ret == LOS_OK) {
        printf("delete Timer2 success\n");
    }
}

UINT32 ExampleSwtmr(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S taskParam = { 0 };
    UINT32 taskId;

    /* 锁任务调度 */
    LOS_TaskLock();

    /* 创建任务 */
    taskParam.pfnTaskEntry = (TSK_ENTRY_FUNC)SwtmrTest;
    taskParam.pcName       = "TimerTsk";
    taskParam.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    taskParam.usTaskPrio   = 5;
    ret = LOS_TaskCreate(&taskId, &taskParam);
    if (ret != LOS_OK) {
        printf("TimerTsk create failed.\n");
        return LOS_NOK;
    }

    /* 解锁任务调度 */
    LOS_TaskUnlock();
    return LOS_OK;
}
```


### 结果验证

编译烧录运行，输出结果如下：


```
start Timer1 success
stop timer1 success
g_timerCount1=1
timer1 self delete test success
start Timer2 success
g_timerCount2=1
g_timerCount2=2
g_timerCount2=3
g_timerCount2=4
g_timerCount2=5
g_timerCount2=6
g_timerCount2=7
g_timerCount2=8
g_timerCount2=9
g_timerCount2=10
delete Timer2 success
```
