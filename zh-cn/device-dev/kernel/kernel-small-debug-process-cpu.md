# 进程调测


## 基本概念

CPU（中央处理器，Central Processing  Unit）占用率分为系统CPU占用率、进程CPU占用率、任务CPU占用率和中断CPU占用率。用户通过系统级的CPU占用率，判断当前系统负载是否超出设计规格。通过系统中各个进程/任务/中断的CPU占用情况，判断各个进程/任务/中断的CPU占用率是否符合设计的预期。

- 系统CPU占用率（CPU  Percent）
  指周期时间内系统的CPU占用率，用于表示系统一段时间内的闲忙程度，也表示CPU的负载情况。系统CPU占用率的有效表示范围为0～100，其精度（可通过配置调整）为百分之一。100表示系统满负荷运转。

- 进程CPU占用率
  指单个进程的CPU占用率，用于表示单个进程在一段时间内的闲忙程度。进程CPU占用率的有效表示范围为0～100，其精度（可通过配置调整）为百分之一。100表示在一段时间内系统一直在运行该进程。

- 任务CPU占用率
  指单个任务的CPU占用率，用于表示单个任务在一段时间内的闲忙程度。任务CPU占用率的有效表示范围为0～100，其精度（可通过配置调整）为百分之一。100表示在一段时间内系统一直在运行该任务。

- 中断CPU占用率
  指单个中断的CPU占用率，用于表示单个中断在一段时间内的闲忙程度。中断CPU占用率的有效表示范围为0～100，其精度（可通过配置调整）为百分之一。100表示在一段时间内系统一直在运行该中断。


## 运行机制

OpenHarmony LiteOS-A内核CPUP（CPU  Percent，CPU占用率）模块采用进程、任务和中断级记录的方式，在进程/任务切换时，记录进程/任务启动时间，进程/任务切出或者退出时，系统会累加整个进程/任务的占用时间; 在执行中断时系统会累加记录每个中断的执行时间。

OpenHarmony 提供以下四种CPU占用率的信息查询：

- 系统CPU占用率

- 进程CPU占用率

- 任务CPU占用率

- 中断CPU占用率

**CPU占用率的计算方法：**

系统CPU占用率=系统中除idle任务外其他任务运行总时间/系统运行总时间

进程CPU占用率=进程运行总时间/系统运行总时间

任务CPU占用率=任务运行总时间/系统运行总时间

中断CPU占用率=中断运行总时间/系统运行总时间


## 开发指导


### 接口说明

  **表1** CPUP模块接口

| 功能分类 | 接口**名称** | 描述 |
| -------- | -------- | -------- |
| 系统CPU占用率 | LOS_HistorySysCpuUsage | 获取系统历史CPU占用率 |
| 进程CPU占用率 | LOS_HistoryProcessCpuUsage | 获取指定进程历史CPU占用率 |
| 进程CPU占用率 | LOS_GetAllProcessCpuUsage | 获取系统所有进程的历史CPU占用率 |
| 任务CPU占用率 | LOS_HistoryTaskCpuUsage | 获取指定任务历史CPU占用率 |
| 中断CPU占用率 | LOS_GetAllIrqCpuUsage | 获取系统所有中断的历史CPU占用率 |
| 重置 | LOS_CpupReset | 重置CPU 占用率相关数据 |


### 开发流程

CPU占用率的典型开发流程：

1. 调用获取系统历史CPU占用率函数LOS_HistorySysCpuUsage。

2. 调用获取指定进程历史CPU占用率函数LOS_HistoryProcessCpuUsage。
   - 若进程已创建，则关中断，根据不同模式正常获取，恢复中断；
   - 若进程未创建，则返回错误码；

3. 调用获取所有进程CPU占用率函数LOS_GetAllProcessCpuUsage。
   - 若CPUP已初始化，则关中断，根据不同模式正常获取，恢复中断；
   - 若CPUP未初始化或有非法入参，则返回错误码；

4. 调用获取指定任务历史CPU占用率函数LOS_HistoryTaskCpuUsage。
   - 若任务已创建，则关中断，根据不同模式正常获取，恢复中断；
   - 若任务未创建，则返回错误码；

5. 调用获取所有中断CPU占用率函数LOS_GetAllIrqCpuUsage。
   - 若CPUP已初始化，则关中断，根据不同模式正常获取，恢复中断；
   - 若CPUP未初始化或有非法入参，则返回错误码；


### 编程实例

本实例实现如下功能：

1. 创建一个用于CPUP测试的任务。

2. 获取当前系统CPUP。

3. 以不同模式获取历史系统CPUP。

4. 获取创建的测试任务的CPUP。

5. 以不同模式获取创建的测试任务的CPUP。

前提条件：

在menuconfig 配置中打开cpup控制开关。

**示例代码**

本演示代码在 . kernel /liteos_a/testsuites /kernel /src /osTest.c中编译验证，在TestTaskEntry中调用验证入口函数CpupTest。
代码实现如下：


```c
#include "los_task.h"
#include "los_cpup.h"
#define  MODE  4
UINT32 g_cpuTestTaskID;
VOID ExampleCpup(VOID)
{
    int i = 0;
    dprintf("entry cpup test example\n");
    for (i = 0; i < 10; i++) {
        usleep(100); // 100: delay for 100ms
    }
}
UINT32 CpupTest(VOID)
{
    UINT32 ret;
    UINT32 cpupUse;
    TSK_INIT_PARAM_S cpupTestTask = {0};
    memset(&cpupTestTask, 0, sizeof(TSK_INIT_PARAM_S));
    cpupTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleCpup;
    cpupTestTask.pcName       = "TestCpupTsk";
    cpupTestTask.uwStackSize  = 0x800; // 0x800: cpup test task stack size
    cpupTestTask.usTaskPrio   = 5; // 5: cpup test task priority
    ret = LOS_TaskCreate(&g_cpuTestTaskID, &cpupTestTask);
    if (ret != LOS_OK) {
        printf("cpupTestTask create failed .\n");
        return LOS_NOK;
    }

    usleep(100); // 100: delay for 100ms

    /* 获取当前系统历史CPU占用率 */
    cpupUse = LOS_HistorySysCpuUsage(CPUP_LAST_ONE_SECONDS);
    dprintf("the history system cpu usage in all time：%u.%u\n",
           cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);
    /* 获取指定任务的CPU占用率，该测试例程中指定的任务为以上创建的cpup测试任务 */
    cpupUse = LOS_HistoryTaskCpuUsage(g_cpuTestTaskID, CPUP_LAST_ONE_SECONDS);
    dprintf("cpu usage of the cpupTestTask in all time:\n TaskID: %d\n usage: %u.%u\n",
           g_cpuTestTaskID, cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);
    return LOS_OK;
}
```

**结果验证**

编译运行得到的结果为：


```
entry cpup test example
the history system cpu usage in all time: 3.0
cpu usage of the cpupTestTask in all time: TaskID:10 usage: 0.0

根据实际运行环境，打印会有差异
```
