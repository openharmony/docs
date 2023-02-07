# 原子操作


## 基本概念

在支持多任务的操作系统中，修改一块内存区域的数据需要“读取-修改-写入”三个步骤。然而同一内存区域的数据可能同时被多个任务访问，如果在修改数据的过程中被其他任务打断，就会造成该操作的执行结果无法预知。

使用开关中断的方法固然可以保证多任务执行结果符合预期，但是显然这种方法会影响系统性能。

ARMv6架构引入了LDREX和STREX指令，以支持对共享存储器更缜密的非阻塞同步。由此实现的原子操作能确保对同一数据的“读取-修改-写入”操作在它的执行期间不会被打断，即操作的原子性。


## 运行机制

OpenHarmony系统通过对ARMv6架构中的LDREX和STREX进行封装，向用户提供了一套原子性的操作接口。

- LDREX Rx, [Ry]
  读取内存中的值，并标记对该段内存的独占访问：
  - 读取寄存器Ry指向的4字节内存数据，保存到Rx寄存器中。
  - 对Ry指向的内存区域添加独占访问标记。

- STREX Rf, Rx, [Ry]
  检查内存是否有独占访问标记，如果有则更新内存值并清空标记，否则不更新内存：
  - 有独占访问标记
    - 将寄存器Rx中的值更新到寄存器Ry指向的内存。
    - 标志寄存器Rf置为0。
  - 没有独占访问标记
    - 不更新内存。
    - 标志寄存器Rf置为1。

- 判断标志寄存器
  - 标志寄存器为0时，退出循环，原子操作结束。
  - 标志寄存器为1时，继续循环，重新进行原子操作。


## 开发指导


### 接口说明

OpenHarmony LiteOS-A内核的原子操作模块提供以下几种功能。

  **表1** 原子操作接口说明

| 功能分类     | 接口**名称**            | 描述                        |
| ------------ | ----------------------- | --------------------------- |
| 读           | LOS_AtomicRead          | 读取32bit原子数据           |
| 读           | LOS_Atomic64Read        | 读取64bit原子数据           |
| 写           | LOS_AtomicSet           | 设置32bit原子数据           |
| 写           | LOS_Atomic64Set         | 设置64bit原子数据           |
| 加           | LOS_AtomicAdd           | 对32bit原子数据做加法       |
| 加           | LOS_Atomic64Add         | 对64bit原子数据做加法       |
| 加           | LOS_AtomicInc           | 对32bit原子数据做加1        |
| 加           | LOS_Atomic64Inc         | 对64bit原子数据做加1        |
| 加           | LOS_AtomicIncRet        | 对32bit原子数据做加1并返回  |
| 加           | LOS_Atomic64IncRet      | 对64bit原子数据做加1并返回  |
| 减           | LOS_AtomicSub           | 对32bit原子数据做减法       |
| 减           | LOS_Atomic64Sub         | 对64bit原子数据做减法       |
| 减           | LOS_AtomicDec           | 对32bit原子数据做减1        |
| 减           | LOS_Atomic64Dec         | 对64bit原子数据做减1        |
| 减           | LOS_AtomicDecRet        | 对32bit原子数据做减1并返回  |
| 减           | LOS_Atomic64DecRet      | 对64bit原子数据做减1并返回  |
| 交换         | LOS_AtomicXchgByte      | 交换8bit内存数据            |
| 交换         | LOS_AtomicXchg16bits    | 交换16bit内存数据           |
| 交换         | LOS_AtomicXchg32bits    | 交换32bit内存数据           |
| 交换         | LOS_AtomicXchg64bits    | 交换64bit内存数据           |
| 先比较后交换 | LOS_AtomicCmpXchgByte   | 比较相同后交换8bit内存数据  |
| 先比较后交换 | LOS_AtomicCmpXchg16bits | 比较相同后交换16bit内存数据 |
| 先比较后交换 | LOS_AtomicCmpXchg32bits | 比较相同后交换32bit内存数据 |
| 先比较后交换 | LOS_AtomicCmpXchg64bits | 比较相同后交换64bit内存数据 |


### 开发流程

有多个任务对同一个内存数据进行加减或交换等操作时，使用原子操作保证结果的可预知性。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>  原子操作接口仅支持整型数据。


### 编程实例

**实例描述**

调用原子操作相关接口，观察结果：

1. 创建两个任务
   - 任务一用LOS_AtomicInc对全局变量加100次。
   - 任务二用LOS_AtomicDec对全局变量减100次。

2. 子任务结束后在主任务中打印全局变量的值。

**示例代码**

示例代码如下：


```
#include "los_hwi.h"
#include "los_atomic.h"
#include "los_task.h"

UINT32 g_testTaskId01;
UINT32 g_testTaskId02;
Atomic g_sum;
Atomic g_count;

UINT32 Example_Atomic01(VOID)
{
    int i = 0;
    for(i = 0; i < 100; ++i) {
        LOS_AtomicInc(&g_sum);
    }

    LOS_AtomicInc(&g_count);
    return LOS_OK;
}

UINT32 Example_Atomic02(VOID)
{
    int i = 0;
    for(i = 0; i < 100; ++i) {
        LOS_AtomicDec(&g_sum);
    }

    LOS_AtomicInc(&g_count);
    return LOS_OK;
}

UINT32 Example_AtomicTaskEntry(VOID)
{
    TSK_INIT_PARAM_S stTask1={0};
    stTask1.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Atomic01;
    stTask1.pcName       = "TestAtomicTsk1";
    stTask1.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    stTask1.usTaskPrio   = 4;
    stTask1.uwResved     = LOS_TASK_STATUS_DETACHED;

    TSK_INIT_PARAM_S stTask2={0};
    stTask2.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Atomic02;
    stTask2.pcName       = "TestAtomicTsk2";
    stTask2.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    stTask2.usTaskPrio   = 4;
    stTask2.uwResved     = LOS_TASK_STATUS_DETACHED;

    LOS_TaskLock();
    LOS_TaskCreate(&g_testTaskId01, &stTask1);
    LOS_TaskCreate(&g_testTaskId02, &stTask2);
    LOS_TaskUnlock();

    while(LOS_AtomicRead(&g_count) != 2);
    PRINTK("g_sum = %d\n", g_sum);

    return LOS_OK;
}
```

**结果验证**


```
g_sum = 0
```