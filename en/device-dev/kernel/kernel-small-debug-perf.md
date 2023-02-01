# perf


## Basic Concepts

perf is a performance analysis tool. It uses the performance monitoring unit (PMU) to count sampling events and collect context information and provides hot spot distribution and hot paths.


## Working Principles

When a performance event occurs, the corresponding event counter overflows and triggers an interrupt. The interrupt handler records the event information, including the current PC, task ID, and call stack.

perf provides two working modes: counting mode and sampling mode.

In counting mode, perf collects only the number of event occurrences and duration. In sampling mode, perf also collects context data and stores the data in a circular buffer. The IDE then analyzes the data and provides information about hotspot functions and paths.


## Available APIs

The Perf module of the OpenHarmony LiteOS-A kernel provides the following APIs. For details, see the [API reference](https://gitee.com/openharmony/kernel_liteos_a/blob/master/kernel/include/los_perf.h).

  **Table 1** APIs of the perf module

| Category| Description|
| -------- | -------- |
| Starting or stopping sampling| **LOS_PerfInit**: initializes perf.<br>**LOS_PerfStart**: starts sampling.<br>**LOS_PerfStop**: stops sampling. |
| Configuring perf sampling events| **LOS_PerfConfig**: sets the event type and sampling period. |
| Reading sampling data| **LOS_PerfDataRead**: reads the sampling data. |
| Registering a hook for the sampling data buffer| **LOS_PerfNotifyHookReg**: registers the hook to be called when the buffer waterline is reached.<br>**LOS_PerfFlushHookReg**: registers the hook for flushing the cache in the buffer. |

**PerfConfigAttr** is the structure of the perf sampling event. For details, see [kernel\include\los_perf.h](https://gitee.com/openharmony/kernel_liteos_a/blob/master/kernel/include/los_perf.h).

The sampling data buffer is a circular buffer, and only the region that has been read in the buffer can be overwritten.

The buffer has limited space. You can register a hook to provide a buffer overflow notification or perform buffer read operation when the buffer waterline is reached. The default buffer waterline is 1/2 of the buffer size. The code snippet is as follows:

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

If the buffer sampled by perf involves caches across CPUs, you can register a hook for flushing the cache to ensure cache consistency. The code snippet is as follows:

```c
VOID Example_PerfFlushHook(VOID *addr, UINT32 size)
{
    OsCacheFlush(addr, size); /* platform interface */
}
LOS_PerfNotifyHookReg(Example_PerfFlushHook);
```

The API for flushing the cache is configured based on the platform.


## Development Guidelines


### Kernel-Mode Development Process

The typical process of enabling perf is as follows:

1. Configure the macros related to the perf module.
   Configure the perf control macro **LOSCFG_KERNEL_PERF**, which is disabled by default. In the **kernel/liteos_a** directory, run the **make update_config** command, choose **Kernel**, and select **Enable Perf Feature**.

   | Configuration Item| menuconfig Option| Description| Value|
   | -------- | -------- | -------- | -------- |
   | LOSCFG_KERNEL_PERF | Enable&nbsp;Perf&nbsp;Feature | Whether to enable perf.| YES/NO |
   | LOSCFG_PERF_CALC_TIME_BY_TICK | Time-consuming&nbsp;Calc&nbsp;Methods-&gt;By&nbsp;Tick | Whether to use tick as the perf timing unit.| YES/NO |
   | LOSCFG_PERF_CALC_TIME_BY_CYCLE | Time-consuming&nbsp;Calc&nbsp;Methods-&gt;By&nbsp;Cpu&nbsp;Cycle | Whether to use cycle as the perf timing unit.| YES/NO |
   | LOSCFG_PERF_BUFFER_SIZE | Perf&nbsp;Sampling&nbsp;Buffer&nbsp;Size | Size of the buffer used for perf sampling.| INT |
   | LOSCFG_PERF_HW_PMU | Enable&nbsp;Hardware&nbsp;Pmu&nbsp;Events&nbsp;for&nbsp;Sampling | Whether to enable hardware PMU events. The target platform must support the hardware PMU.| YES/NO |
   | LOSCFG_PERF_TIMED_PMU | Enable&nbsp;Hrtimer&nbsp;Period&nbsp;Events&nbsp;for&nbsp;Sampling | Whether to enable high-precision periodical events. The target platform must support the high precision event timer (HPET).| YES/NO |
   | LOSCFG_PERF_SW_PMU | Enable&nbsp;Software&nbsp;Events&nbsp;for&nbsp;Sampling | Whether to enable software events. **LOSCFG_KERNEL_HOOK** must also be enabled.| YES/NO |

2. Call **LOS_PerfConfig** to configure the events to be sampled.
   perf provides two working modes and three types of events.

   - Working modes: counting mode (counts only the number of event occurrences) and sampling mode (collects context information such as task IDs, PC, and backtrace)
   - Event types: CPU hardware events (such as cycle, branch, icache, and dcache), high-precision periodical events (such as CPU clock), and OS software events (such as task switch, mux pend, and IRQ)
3. Call **LOS_PerfStart(UINT32 sectionId)** at the start of the code to be sampled. The input parameter **sectionId** specifies different sampling session IDs.

4. Call **LOS_PerfStop** at the end of the code to be sampled.

5. Call **LOS_PerfDataRead** to read the sampling data and use IDE to analyze the collected data.


####  Development Example

This example implements the following:

1. Create a perf task.

2. Configure sampling events.

3. Start perf.

4. Execute algorithms for statistics.

5. Stop perf.

6. Export the result. 


####  Sample Code

Prerequisites: **Enable Hook Feature** and **Enable Software Events for Sampling** are selected for the perf module in **menuconfig**.

You can compile and verify the sample code in **kernel/liteos_a/testsuites/kernel/src/osTest.c**.

The code is as follows:

```c
#include "los_perf.h"
#define TEST_MALLOC_SIZE 200
#define TEST_TIME        5

/* Add malloc() and free() in the test() function. */
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
                [0]      = {PERF_COUNT_SW_TASK_SWITCH, 0xff}, /* Collect task scheduling information. */
                [1]      = {PERF_COUNT_SW_MEM_ALLOC, 0xff},   /* Collect memory allocation information. */

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
    /* Create a perf task. */
    perfTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)perfTestHwEvent;
    perfTestTask.pcName       = "TestPerfTsk";   /* Test task name. */
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


#### Verification

  The output is as follows:

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

The print information may vary depending on the running environment.
```

- For the counting mode, the following information is displayed after perf is stopped:
  Event name (cycles), event type (0xff), and number of event occurrences (5466989440)

  For hardware PMU events, the displayed event type is the hardware event ID, not the abstract type defined in **enum PmuHWId**.

- For the sampling mode, the address and length of the sampled data will be displayed after perf is stopped:
  dump section data, addr: (0x8000000) length: (0x5000)

  You can export the data using the JTAG interface and then use the IDE offline tool to analyze the data.

  You can also call **LOS_PerfDataRead** to read data to a specified address for further analysis. In the example, **OsPrintBuff** is a test API, which prints the sampled data by byte. **num** indicates the sequence number of the byte, and **hex** indicates the value in the byte.
