# 时间管理


## 基本概念

时间管理以系统时钟为基础，给应用程序提供所有和时间有关的服务。

系统时钟是由定时器/计数器产生的输出脉冲触发中断产生的，一般定义为整数或长整数。输出脉冲的周期叫做一个“时钟滴答”。系统时钟也称为时标或者Tick。

用户以秒、毫秒为单位计时，而操作系统以Tick为单位计时，当用户需要对系统进行操作时，例如任务挂起、延时等，此时需要时间管理模块对Tick和秒/毫秒进行转换。

OpenHarmony LiteOS-M内核时间管理模块提供时间转换、统计功能。


## 时间单位

- Cycle
  系统最小的计时单位。Cycle的时长由系统主时钟频率决定，系统主时钟频率就是每秒钟的Cycle数。

- Tick
  Tick是操作系统的基本时间单位，由用户配置的每秒Tick数决定。


## 接口说明

OpenHarmony LiteOS-M内核的时间管理提供下面几种功能，接口详细信息可以查看API参考。

​    **表1** 时间转换

| 接口名 | 描述 |
| -------- | -------- |
| LOS_MS2Tick | 毫秒转换成Tick。 |
| LOS_Tick2MS | Tick转化为毫秒。 |
| OsCpuTick2MS | Cycle数目转化为毫秒，使用2个UINT32类型的数值分别表示结果数值的高、低32位。 |
| OsCpuTick2US | Cycle数目转化为微秒，使用2个UINT32类型的数值分别表示结果数值的高、低32位。 |

  **表2** 时间统计

| 接口名 | 描述 |
| -------- | -------- |
| LOS_SysClockGet | 获取系统时钟。 |
| LOS_TickCountGet    | 获取自系统启动以来的Tick数。 |
| LOS_CyclePerTickGet | 获取每个Tick多少Cycle数。   |
| LOS_CurrNanosec     | 获取当前的时间，单位纳秒。  |

 **表3** 时间注册

| 接口名                | 描述                                           |
| --------------------- | ---------------------------------------------- |
| LOS_TickTimerRegister | 重新注册系统时钟的定时器和对应的中断处理函数。 |

 **表4** 延时

| 接口名     | 描述                     |
| ---------- | ------------------------ |
| LOS_MDelay | 延时函数，延时单位毫秒。 |
| LOS_UDelay | 延时函数，延时单位微秒。 |

## 开发流程

时间管理的典型开发流程：

1. 根据实际需求，完成板级配置适配，并配置系统主时钟频率OS_SYS_CLOCK（单位Hz）和LOSCFG_BASE_CORE_TICK_PER_SECOND。OS_SYS_CLOCK的默认值基于硬件平台配置。

2. 调用时钟转换/统计接口。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 时间管理不是单独的功能模块，依赖于OS_SYS_CLOCK和LOSCFG_BASE_CORE_TICK_PER_SECOND两个配置选项。
> 
> - 系统的Tick数在关中断的情况下不进行计数，故系统Tick数不能作为准确时间使用。
> 
> - 上文描述的配置选项维护在开发板工程 target_config.h 中，部分配置项未定义的缺省值定义在内核 los_config.h中。


## 编程实例


### 实例描述

在下面的例子中，介绍了时间管理的基本方法，包括：

1. 时间转换：将毫秒数转换为Tick数，或将Tick数转换为毫秒数。

2. 时间统计：每Tick的Cycle数、自系统启动以来的Tick数和延迟后的Tick数。


### 示例代码

前提条件：

- 使用每秒的Tick数LOSCFG_BASE_CORE_TICK_PER_SECOND的默认值100。

- 配好OS_SYS_CLOCK系统主时钟频率。

时间转换：

本演示代码在 ./kernel/liteos_m/testsuites/src/osTest.c 中编译验证，在TestTaskEntry中调用验证入口函数ExampleTransformTime和ExampleGetTime。


```
VOID ExampleTransformTime(VOID)
{
    UINT32 ms;
    UINT32 tick;

    /* 10000ms转换为tick */
    tick = LOS_MS2Tick(10000);
    printf("tick = %d \n", tick);

    /* 100tick转换为ms */
    ms = LOS_Tick2MS(100);
    printf("ms = %d \n", ms);
}
```

时间统计和时间延迟：


```
VOID ExampleGetTime(VOID)
{
    UINT32 cyclePerTick;
    UINT64 tickCountBefore;
    UINT64 tickCountAfter;

    cyclePerTick  = LOS_CyclePerTickGet();
    if (0 != cyclePerTick) {
        printf("LOS_CyclePerTickGet = %d \n", cyclePerTick);
    }

    tickCountBefore = LOS_TickCountGet();
    LOS_TaskDelay(200);
    tickCountAfter = LOS_TickCountGet();
    printf("LOS_TickCountGet after delay rising = %d \n", (UINT32)(tickCountAfter - tickCountBefore));
}
```


### 结果验证

编译运行得到的结果为：

时间转换：


```
tick = 1000
ms = 1000
```

时间统计和时间延迟：


``` 
LOS_CyclePerTickGet = 250000 (根据实际运行环境，数据会有差异)
LOS_TickCountGet after delay rising = 200
```
