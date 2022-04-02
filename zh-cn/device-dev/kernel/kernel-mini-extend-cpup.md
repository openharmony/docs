# CPU占用率


## 基本概念

CPU（中央处理器，Central Processing Unit）占用率分为系统CPU占用率和任务CPU占用率。

系统CPU占用率（CPU  Percent）是指周期时间内系统的CPU占用率，用于表示系统一段时间内的闲忙程度，也表示CPU的负载情况。系统CPU占用率的有效表示范围为0～100，其精度（可通过配置调整）为百分比。100表示系统满负荷运转。

任务CPU占用率指单个任务的CPU占用率，用于表示单个任务在一段时间内的闲忙程度。任务CPU占用率的有效表示范围为0～100，其精度（可通过配置调整）为百分比。100表示在一段时间内系统一直在运行该任务。

用户通过系统级的CPU占用率，判断当前系统负载是否超出设计规格。

通过系统中各个任务的CPU占用情况，判断各个任务的CPU占用率是否符合设计的预期。


## 运行机制

OpenHarmony LiteOS-M的CPUP（CPU  Percent，系统CPU占用率）采用任务级记录的方式，在任务切换时，记录任务启动时间，任务切出或者退出时间，每次当任务退出时，系统会累加整个任务的占用时间。

可以在target_config.h的中对该功能进行选配。

OpenHarmony  LiteOS-M提供以下两种CPU占用率的信息查询：

- 系统CPU占用率。

- 任务CPU占用率。

**CPU占用率的计算方法：**

系统CPU占用率=系统中除idle任务外其他任务运行总时间/系统运行总时间

任务CPU占用率=任务运行总时间/系统运行总时间


## 接口说明

  **表1** 功能列表

| 功能分类 | 接口描述 | 
| -------- | -------- |
| 获取系统CPU占用率 | -&nbsp;LOS_SysCpuUsage：获取当前系统CPU占用率<br/>-&nbsp;LOS_HistorySysCpuUsage：获取系统历史CPU占用率 | 
| 获取任务CPU占用率 | -&nbsp;LOS_TaskCpuUsage：获取指定任务CPU占用率<br/>-&nbsp;LOS_HistoryTaskCpuUsage：获取指定任务历史CPU占用率<br/>-&nbsp;LOS_HistoryTaskCpuUsage：获取指定任务历史CPU占用率 | 
| 输出任务CPU占用率 | LOS_CpupUsageMonitor:输出任务历史CPU占用率 | 


## 开发流程

CPU占用率的典型开发流程：

1. 调用获取系统CPU使用率函数LOS_SysCpuUsage。

2. 调用获取系统历史CPU使用率函数LOS_HistorySysCpuUsage。

3. 调用获取指定任务CPU使用率函数LOS_TaskCpuUsage。
   - 若任务已创建，则关中断，正常获取，恢复中断；
   - 若任务未创建，则返回错误码；

4. 调用获取指定任务历史CPU使用率函数LOS_HistoryTaskCpuUsage。
   - 若任务已创建，则关中断，根据不同模式正常获取，恢复中断；
   - 若任务未创建，则返回错误码；

5. 调用获取所有任务CPU使用率函数LOS_AllCpuUsage。
   - 若CPUP已初始化，则关中断，根据不同模式正常获取，恢复中断；
   - 若CPUP未初始化或有非法入参，则返回错误码；


## 编程实例


### 实例描述

本实例实现如下功能：

1. 创建一个用于CPUP测试的任务。

2. 获取当前系统CPUP。

3. 以不同模式获取历史系统CPUP。

4. 获取创建的测试任务的CPUP。

5. 以不同模式获取创建的测试任务的CPUP


### 示例代码

前提条件：

在target_config.h中将LOSCFG_BASE_CORE_CPUP配置项打开。

代码实现如下：

  
```
#include "los_task.h"
#include "los_cpup.h" 
#define  MODE  4
UINT32 g_cpuTestTaskID;  
VOID ExampleCpup(VOID) 
{      
    printf("entry cpup test example\n");
    while(1) {
        usleep(100);
    }
}
UINT32 ItCpupTest(VOID) 
{     
    UINT32 ret;
    UINT32 cpupUse;
    TSK_INIT_PARAM_S cpupTestTask = { 0 };
    memset(&cpupTestTask, 0, sizeof(TSK_INIT_PARAM_S));
    cpupTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleCpup;
    cpupTestTask.pcName       = "TestCpupTsk"; 
    cpupTestTask.uwStackSize  = 0x800;
    cpupTestTask.usTaskPrio   = 5;
    ret = LOS_TaskCreate(&g_cpuTestTaskID, &cpupTestTask);
    if(ret != LOS_OK) {
        printf("cpupTestTask create failed .\n");
        return LOS_NOK;
    }

    usleep(100);

    /* 获取当前系统cpu占用率 */
    cpupUse = LOS_SysCpuUsage();
    printf("the current system cpu usage is: %u.%u\n",
            cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT); 

    cpupUse = LOS_HistorySysCpuUsage(CPU_LESS_THAN_1S);
    /* 获取指定任务的cpu占用率，该测试例程中指定的任务为以上创建的cpup测试任务 */    
    printf("the history system cpu usage in all time：%u.%u\n",
           cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);
    cpupUse = LOS_TaskCpuUsage(g_cpuTestTaskID);    
    /* 获取指定历史任务在系统启动到现在的cpu占用率，该测试例程中指定的任务为以上创建的cpup测试任务 */    
    printf("cpu usage of the cpupTestTask:\n TaskID: %d\n usage: %u.%u\n",
           g_cpuTestTaskID, cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT); 
    cpupUse = LOS_HistoryTaskCpuUsage(g_cpuTestTaskID, CPU_LESS_THAN_1S);   
    printf("cpu usage of the cpupTestTask in all time:\n TaskID: %d\n usage: %u.%u\n",
           g_cpuTestTaskID, cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);   
    return LOS_OK; 
}
```


### 结果验证

  编译运行得到的结果为：
  
```
entry cpup test example 
the current system cpu usage is : 1.5
 the history system cpu usage in all time: 3.0
 cpu usage of the cpupTestTask: TaskID:10 usage: 0.0
 cpu usage of the cpupTestTask&nbsp;in all time: TaskID:10 usage: 0.0
```
