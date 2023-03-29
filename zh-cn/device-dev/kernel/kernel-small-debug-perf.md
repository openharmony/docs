# Perf调测


## 基本概念

Perf为性能分析工具，依赖PMU（Performance Monitoring Unit）对采样事件进行计数和上下文采集，统计出热点分布（hot spot）和热路径（hot path）。


## 运行机制

基于事件采样原理，以性能事件为基础，当事件发生时，相应的事件计数器溢出发生中断，在中断处理函数中记录事件信息，包括当前的pc、当前运行的任务ID以及调用栈等信息。

Perf提供2种工作模式，计数模式和采样模式。

计数模式仅统计事件发生的次数和耗时，采样模式会收集上下文数据到环形buffer中，需要IDE进行数据解析生成热点函数与热点路径。


## 接口说明

OpenHarmony LiteOS-A内核的Perf模块提供下面几种功能，接口详细信息可以查看[API](https://gitee.com/openharmony/kernel_liteos_a/blob/master/kernel/include/los_perf.h)参考。

  **表1** Perf模块接口说明

| 功能分类 | 接口描述 |
| -------- | -------- |
| 开启/停止Perf采样 | LOS_PerfInit : 初始化Perf<br/>LOS_PerfStart：开启采样<br/>LOS_PerfStop：停止采样 |
| 配置Perf采样事件 | LOS_PerfConfig：配置采样事件的类型、周期等 |
| 读取采样数据 | LOS_PerfDataRead：读取采样数据到指定地址 |
| 注册采样数据缓冲区的钩子函数 | LOS_PerfNotifyHookReg：注册缓冲区水线到达的处理钩子<br/>LOS_PerfFlushHookReg：注册缓冲区刷cache的钩子 |


1. Perf采样事件的结构体为PerfConfigAttr，详细字段含义及取值详见 [kernel\include\los_perf.h](https://gitee.com/openharmony/kernel_liteos_a/blob/master/kernel/include/los_perf.h) 。

2. 采样数据缓冲区为环形buffer，buffer中读过的区域可以覆盖写，未被读过的区域不能被覆盖写。

3. 缓冲区有限，用户可通过注册水线到达的钩子进行buffer溢出提醒或buffer读操作。默认水线值为buffer总大小的1/2。 示例如下：

   ```c
   VOID Example_PerfNotifyHook(VOID)
   {
       CHAR buf[LOSCFG_PERF_BUFFER_SIZE] = {0};
       UINT32 len;
       PRINT_DEBUG("perf buffer reach the waterline!\n");
       len = LOS_PerfDataRead(buf, LOSCFG_PERF_BUFFER_SIZE);
       OsPrintBuff(buf, len); /* print data */
   }
   LOS_PerfNotifyHookReg(Example_PerfNotifyHook);
   ```

4. 若perf采样的buffer涉及到CPU跨cache，则用户可通过注册刷cache的钩子，进行cache同步。 示例如下：

   ```c
   VOID Example_PerfFlushHook(VOID *addr, UINT32 size)
   {
       OsCacheFlush(addr, size); /* platform interface */
   }
   LOS_PerfNotifyHookReg(Example_PerfFlushHook);
   ```

   刷cache接口视具体的平台自行配置。


## 开发指导


### 内核态开发流程

开启Perf调测的典型流程如下：

1. 配置Perf模块相关宏。
   配置Perf控制宏LOSCFG_KERNEL_PERF，默认关，在kernel/liteos_a目录下执行 make update_config命令配置"Kernel-&gt;Enable Perf Feature"中打开：

     | 配置项 | menuconfig选项 | 含义 | 设置值 |
   | -------- | -------- | -------- | -------- |
   | LOSCFG_KERNEL_PERF | Enable&nbsp;Perf&nbsp;Feature | Perf模块的裁剪开关 | YES/NO |
   | LOSCFG_PERF_CALC_TIME_BY_TICK | Time-consuming&nbsp;Calc&nbsp;Methods-&gt;By&nbsp;Tick | Perf计时单位为tick | YES/NO |
   | LOSCFG_PERF_CALC_TIME_BY_CYCLE | Time-consuming&nbsp;Calc&nbsp;Methods-&gt;By&nbsp;Cpu&nbsp;Cycle | Perf计时单位为cycle | YES/NO |
   | LOSCFG_PERF_BUFFER_SIZE | Perf&nbsp;Sampling&nbsp;Buffer&nbsp;Size | Perf采样buffer的大小 | INT |
   | LOSCFG_PERF_HW_PMU | Enable&nbsp;Hardware&nbsp;Pmu&nbsp;Events&nbsp;for&nbsp;Sampling | 使能硬件PMU事件，需要目标平台支持硬件PMU | YES/NO |
   | LOSCFG_PERF_TIMED_PMU | Enable&nbsp;Hrtimer&nbsp;Period&nbsp;Events&nbsp;for&nbsp;Sampling | 使能高精度周期事件，需要目标平台支持高精度定时器 | YES/NO |
   | LOSCFG_PERF_SW_PMU | Enable&nbsp;Software&nbsp;Events&nbsp;for&nbsp;Sampling | 使能软件事件，需要开启LOSCFG_KERNEL_HOOK | YES/NO |

2. 调用LOS_PerfConfig配置需要采样的事件。
   Perf提供2种模式的配置，及3大类型的事件配置：

   2种模式：计数模式（仅统计事件发生次数）、采样模式（收集上下文如任务ID、pc、backtrace等）。

   3种事件类型：CPU硬件事件（cycle、branch、icache、dcache等）、高精度周期事件（cpu clock)、OS软件事件（task switch、mux pend、irq等）。

3. 在需要采样的代码起始点调用LOS_PerfStart(UINT32 sectionId), 入参sectionId标记不同的采样回话id。

4. 在需要采样的代码结束点调用LOS_PerfStop。

5. 调用输出缓冲区数据的接口LOS_PerfDataRead读取采样数据，并使用IDE工具进行解析。


####  内核态编程实例

本实例实现如下功能：

1. 创建perf测试任务。

2. 配置采样事件。

3. 启动perf。

4. 执行需要统计的算法。

5. 停止perf。

6. 输出统计结果。


####  内核态示例代码

前提条件：在menuconfig菜单中完成perf模块的配置， 并勾选Enable Hook Feature，Enable Software Events for Sampling。

为方便学习，本演示代码直接在 . kernel /liteos_a/testsuites /kernel /src /osTest.c中编译验证即可。

实例代码如下：

```c
#include "los_perf.h"
#define TEST_MALLOC_SIZE 200
#define TEST_TIME        5

/* 验证函数中进行malloc和free */
VOID test(VOID)
{
    VOID *p = NULL;
    int i;
    for (i = 0; i < TEST_TIME; i++) {
        p = LOS_MemAlloc(m_aucSysMem1, TEST_MALLOC_SIZE);
        if (p == NULL) {
            PRINT_ERR("test alloc failed\n");
            return;
        }

        (VOID)LOS_MemFree(m_aucSysMem1, p);
    }
}

STATIC VOID OsPrintBuff(const CHAR *buf, UINT32 num)
{
    UINT32 i = 0;
    PRINTK("num: ");
    for (i = 0; i < num; i++) {
        PRINTK(" %02d", i);
    }
    PRINTK("\n");
    PRINTK("hex: ");
    for (i = 0; i < num; i++) {
        PRINTK(" %02x", buf[i]);
    }
    PRINTK("\n");
}
STATIC VOID perfTestHwEvent(VOID)
{
    UINT32 ret;
    CHAR *buf = NULL;
    UINT32 len;

    //LOS_PerfInit(NULL, 0);


    PerfConfigAttr attr = {
        .eventsCfg = {
            .type        = PERF_EVENT_TYPE_SW,
            .events = {
                [0]      = {PERF_COUNT_SW_TASK_SWITCH, 0xff}, /* 抓取调度 */
                [1]      = {PERF_COUNT_SW_MEM_ALLOC, 0xff},   /* 抓取内存分配 */

                PERF_COUNT_SW_TASK_SWITCH
            },
            .eventsNr    = 2,
            .predivided  = 1,             /* cycle counter increase every 64 cycles */
        },
        .taskIds         = {0},
        .taskIdsNr       = 0,
        .needSample      = 0,
        .sampleType      = PERF_RECORD_IP | PERF_RECORD_CALLCHAIN,
    };
    ret = LOS_PerfConfig(&attr);
    if (ret != LOS_OK) {
        PRINT_ERR("perf config error %u\n", ret);
        return;
    }
    PRINTK("------count mode------\n");
    LOS_PerfStart(0);
    test(); /* this is any test function*/
    LOS_PerfStop();
    PRINTK("--------sample mode------ \n");
    attr.needSample = 1;
    LOS_PerfConfig(&attr);
    LOS_PerfStart(2); // 2: set the section id to 2.
    test(); /* this is any test function*/
    LOS_PerfStop();
    buf = LOS_MemAlloc(m_aucSysMem1, LOSCFG_PERF_BUFFER_SIZE);
    if (buf == NULL) {
        PRINT_ERR("buffer alloc failed\n");
        return;
    }
    /* get sample data */
    len = LOS_PerfDataRead(buf, LOSCFG_PERF_BUFFER_SIZE);
    OsPrintBuff(buf, len); /* print data */
    (VOID)LOS_MemFree(m_aucSysMem1, buf);
}

UINT32 Example_Perf_test(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S perfTestTask = {0};
    UINT32 taskID;
    /* 创建用于perf测试的任务 */
    perfTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)perfTestHwEvent;
    perfTestTask.pcName       = "TestPerfTsk";    /* 测试任务名称 */
    perfTestTask.uwStackSize  = 0x1000; // 0x8000: perf test task stack size
    perfTestTask.usTaskPrio   = 5; // 5: perf test task priority
    ret = LOS_TaskCreate(&taskID, &perfTestTask);
    if (ret != LOS_OK) {
        PRINT_ERR("PerfTestTask create failed. 0x%x\n", ret);
        return LOS_NOK;
    }
    return LOS_OK;
}
LOS_MODULE_INIT(perfTestHwEvent, LOS_INIT_LEVEL_KMOD_EXTENDED);
```


#### 内核态结果验证

  输出结果如下：

```
type: 2
events[0]: 1, 0xff
events[1]: 3, 0xff
predivided: 1
sampleType: 0x60
needSample: 0
------count mode------
[task switch] eventType: 0x1 [core 0]: 0
[mem alloc] eventType: 0x3 [core 0]: 5
time used: 0.005000(s)
--------sample mode------
type: 2
events[0]: 1, 0xff
events[1]: 3, 0xff
predivided: 1
sampleType: 0x60
needSample: 1
dump perf data, addr: 0x402c3e6c length: 0x5000
time used: 0.000000(s)
num:  00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19
hex:  00 ffffffef ffffffef ffffffef 02 00 00 00 14 00 00 00 60 00 00 00 02 00 00 00

根据实际运行环境，过程打印会有差异
```

- 针对计数模式，系统在perf stop后会打印：
  事件名称（cycles)、事件类型（0xff)、事件发生的次数（5466989440）。

  当采样事件为硬件PMU事件时，打印的事件类型为实际的硬件事件id，非enum PmuHWId中定义的抽象类型。

- 针对采样模式，系统在perf stop后会打印采样数据的地址和长度：
  dump section data, addr: （0x8000000） length: （0x5000）

  用户可以通过JTAG口导出该片内存，再使用IDE线下工具解析。

  或者通过LOS_PerfDataRead将数据读到指定地址，进行查看或进一步处理。示例中OsPrintBuff为测试接口，其按字节打印Read到的采样数据，num表示第几个字节，hex表示该字节中的数值。
