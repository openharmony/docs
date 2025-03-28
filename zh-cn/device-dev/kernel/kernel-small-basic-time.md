# 时间管理


## 基本概念

时间管理以系统时钟为基础。时间管理提供给应用程序所有和时间有关的服务。系统时钟是由定时/计数器产生的输出脉冲触发中断而产生的，一般定义为整数或长整数。输出脉冲的周期叫做一个“时钟滴答”。

系统时钟也称为时标或者Tick。一个Tick的时长可以静态配置。用户是以秒、毫秒为单位计时，而操作系统时钟计时是以Tick为单位的，当用户需要对系统操作时，例如任务挂起、延时等，输入秒为单位的数值，此时需要时间管理模块对二者进行转换。

**Tick与秒之间的对应关系可以配置。**

- **Cycle**
  系统最小的计时单位。Cycle的时长由系统主频决定，系统主频就是每秒钟的Cycle数。

- **Tick**
  Tick是操作系统的基本时间单位，对应的时长由系统主频及每秒Tick数决定，由用户配置。

**OpenHarmony系统的时间管理模块提供时间转换、统计、延迟功能以满足用户对时间相关需求的实现。**


## 开发指导

用户需要了解当前系统运行的时间以及Tick与秒、毫秒之间的转换关系，以及需要使用到时间管理模块的接口。


### 接口说明

OpenHarmony LiteOS-A内核的时间管理提供以下几种功能，接口详细信息可查看[API参考](https://gitee.com/openharmony/kernel_liteos_m/blob/master/kernel/include/los_tick.h)。

  **表1** 时间管理相关接口说明：

| 功能分类 | 接口描述                                                     |
| -------- | ------------------------------------------------------------ |
| 时间转换 | LOS_MS2Tick：毫秒转换成Tick<br/>LOS_Tick2MS：Tick转换成毫秒  |
| 时间统计 | LOS_TickCountGet：获取当前Tick数<br/>LOS_CyclePerTickGet：每个Tick的cycle数 |


### 开发流程

1. 调用时间转换接口；

2. 获取系统Tick数完成时间统计等。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
>  - 获取系统Tick数需要在系统时钟使能之后。
>
>  - 时间管理不是单独的功能模块，依赖于los_config.h中的OS_SYS_CLOCK和LOSCFG_BASE_CORE_TICK_PER_SECOND两个配置选项。
>
>  - 系统的Tick数在关中断的情况下不进行计数，故系统Tick数不能作为准确时间计算。


### 编程实例

前置条件：

- 配置好LOSCFG_BASE_CORE_TICK_PER_SECOND，即系统每秒的Tick数，范围(0, 1000）。

- 配置好OS_SYS_CLOCK 系统时钟频率，单位：Hz。

**示例代码**

  时间转换：

```
VOID Example_TransformTime(VOID)
{
    UINT32 uwMs;
    UINT32 uwTick;
    uwTick = LOS_MS2Tick(10000); //10000 ms数转换为Tick数
    PRINTK("uwTick = %d \n",uwTick);
    uwMs= LOS_Tick2MS(100); //100 Tick数转换为ms数
    PRINTK("uwMs = %d \n",uwMs);
}
```

时间统计和时间延迟：


```
VOID Example_GetTime(VOID)
{
    UINT32 uwcyclePerTick;
    UINT64 uwTickCount;

    uwcyclePerTick = LOS_CyclePerTickGet(); //每个Tick多少Cycle数
    if(0 != uwcyclePerTick)
    {
        PRINTK("LOS_CyclePerTickGet = %d \n", uwcyclePerTick);
    }

    uwTickCount = LOS_TickCountGet(); //获取Tick数
    if(0 != uwTickCount)
    {
        PRINTK("LOS_TickCountGet = %d \n", (UINT32)uwTickCount);
    }
    LOS_TaskDelay(200);//延迟200 Tick
    uwTickCount = LOS_TickCountGet();
    if(0 != uwTickCount)
    {
        PRINTK("LOS_TickCountGet after delay = %d \n", (UINT32)uwTickCount);
    }
}
```

**结果验证**

编译运行的结果如下：

时间转换：


```
uwTick = 10000 
uwMs = 100
```

时间统计和时间延迟：


```
LOS_CyclePerTickGet = 49500 
LOS_TickCountGet = 347931
LOS_TickCountGet after delay = 348134
```