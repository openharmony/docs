# perf


## Basic Concepts

perf is a performance analysis tool. It uses the performance monitoring unit (PMU) to count sampling events and collect context information and provides hot spot distribution and hot paths.


## Working Principles

When a performance event occurs, the corresponding event counter overflows and triggers an interrupt. The interrupt handler records the event information, including the current PC, task ID, and call stack.

perf provides two working modes: counting mode and sampling mode.

In counting mode, perf collects only the number of event occurrences and duration. In sampling mode, perf also collects context data and stores the data in a circular buffer. The IDE then analyzes the data and provides information about hotspot functions and paths.


## Available APIs


### Kernel Mode

The Perf module of the OpenHarmony LiteOS-A kernel provides the following functions. For details about the interfaces, see the [API reference](https://gitee.com/openharmony/kernel_liteos_a/blob/master/kernel/include/los_perf.h).

  **Table 1** APIs of the perf module

| API| Description|
| -------- | -------- |
| LOS_PerfStart| Starts sampling.|
| LOS_PerfStop| Stops sampling.|
| LOS_PerfConfig| Sets the event type and sampling interval.|
| LOS_PerfDataRead| Reads the sampling data.|
| LOS_PerfNotifyHookReg| Registers the hook to be called when the buffer waterline is reached.|
| LOS_PerfFlushHookReg| Registers the hook for flushing the cache in the buffer.|

- The structure of the perf sampling event is **PerfConfigAttr**. For details, see **kernel\include\los_perf.h**.

- The sampling data buffer is a circular buffer, and only the region that has been read in the buffer can be overwritten.

- The buffer has limited space. You can register a hook to provide a buffer overflow notification or perform buffer read operation when the buffer waterline is reached. The default buffer waterline is 1/2 of the buffer size. 

   Example:

   ```
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

- If the buffer sampled by perf involves caches across CPUs, you can register a hook for flushing the cache to ensure cache consistency. 

   Example:

   ```
   VOID Example_PerfFlushHook(VOID *addr, UINT32 size)
   {
       OsCacheFlush(addr, size); /* platform interface */
   }
   LOS_PerfNotifyHookReg(Example_PerfFlushHook);
   ```

   The API for flushing the cache is configured based on the platform.


### User Mode


The perf character device is located in **/dev/perf**. You can read, write, and control the user-mode perf by running the following commands on the device node:


- **read**: reads perf data in user mode.

- **write**: writes user-mode sampling events.

- **ioctl**: controls the user-mode perf, which includes the following:
  
  ```
  #define PERF_IOC_MAGIC     'T'
  #define PERF_START         _IO(PERF_IOC_MAGIC, 1)
  #define PERF_STOP          _IO(PERF_IOC_MAGIC, 2)
  ```

  The operations correspond to **LOS_PerfStart** and **LOS_PerfStop**.


For details, see [User-Mode Development Example](#user-mode-development-example).


## How to Develop


### Kernel-Mode Development Process

The typical process of enabling perf is as follows:

1. Configure the macros related to the perf module.
   
   Configure the perf control macro **LOSCFG_KERNEL_PERF**, which is disabled by default. In the **kernel/liteos_a** directory, run the **make update_config** command, choose **Kernel**, and select **Enable Perf Feature**.

  | Item| menuconfig Option| Description| Value|
  | -------- | -------- | -------- | -------- |
  | LOSCFG_KERNEL_PERF | Enable Perf Feature | Whether to enable perf.| YES/NO |
  | LOSCFG_PERF_CALC_TIME_BY_TICK | Time-consuming Calc Methods-&gt;By Tick | Whether to use tick as the perf timing unit.| YES/NO |
  | LOSCFG_PERF_CALC_TIME_BY_CYCLE | Time-consuming Calc Methods-&gt;By Cpu Cycle | Whether to use cycle as the perf timing unit.| YES/NO |
  | LOSCFG_PERF_BUFFER_SIZE | Perf Sampling Buffer Size | Size of the buffer used for perf sampling.| INT |
  | LOSCFG_PERF_HW_PMU | Enable Hardware Pmu Events for Sampling | Whether to enable hardware PMU events. The target platform must support the hardware PMU.| YES/NO |
  | LOSCFG_PERF_TIMED_PMU | Enable Hrtimer Period Events for Sampling | Whether to enable high-precision periodical events. The target platform must support the high precision event timer (HPET).| YES/NO |
  | LOSCFG_PERF_SW_PMU | Enable Software Events for Sampling | Whether to enable software events. **LOSCFG_KERNEL_HOOK** must also be enabled.| YES/NO |

2. Call **LOS_PerfConfig** to configure the events to be sampled.

   perf provides two working modes and three types of events.

   Working modes: counting mode (counts only the number of event occurrences) and sampling mode (collects context information such as task IDs, PC, and backtrace)

   Events: CPU hardware events (such as cycle, branch, icache, and dcache), high-precision periodical events (such as CPU clock), and OS software events (such as task switch, mux pend, and IRQ)

3. Call **LOS_PerfStart(UINT32 sectionId)** at the start of the code to be sampled. The input parameter **sectionId** specifies different sampling session IDs.

4. Call **LOS_PerfStop** at the end of the code to be sampled.

5. Call **LOS_PerfDataRead** to read the sampling data and use IDE to analyze the collected data.


####  Kernel-Mode Development Example

This example implements the following:

1. Create a perf task.

2. Configure sampling events.

3. Start perf.

4. Execute algorithms for statistics.

5. Stop perf.

6. Export the result. 


####  Kernel-Mode Sample Code

Prerequisites: The perf module configuration is complete in **menuconfig**.

The sample code is as follows:

```
#include "los_perf.h"
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
    PerfConfigAttr attr = {
        .eventsCfg = {
            .type        = PERF_EVENT_TYPE_HW,
            .events = {
                [0]      = {PERF_COUNT_HW_CPU_CYCLES, 0xFFFF},
                [1]      = {PERF_COUNT_HW_BRANCH_INSTRUCTIONS, 0xFFFFFF00},
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
    LOS_PerfStart(2);
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
UINT32 Example_Perf_test(VOID){
    UINT32 ret;    
    TSK_INIT_PARAM_S perfTestTask;    
    /* Create a perf task. */   
    memset(&perfTestTask, 0, sizeof(TSK_INIT_PARAM_S));    
    perfTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)perfTestHwEvent;    
    perfTestTask.pcName = "TestPerfTsk";    /* Test task name. */   				     
    perfTestTask.uwStackSize  = 0x800;    
    perfTestTask.usTaskPrio   = 5;    
    perfTestTask.uwResved   = LOS_TASK_STATUS_DETACHED;    
    ret = LOS_TaskCreate(&g_perfTestTaskId, &perfTestTask);    
    if(ret != LOS_OK){        
        PRINT_ERR("PerfTestTask create failed.\n");        
        return LOS_NOK;    
    }
    return LOS_OK;
}
LOS_MODULE_INIT(perfTestHwEvent, LOS_INIT_LEVEL_KMOD_EXTENDED);
```


#### Kernel-Mode Verification

  The output is as follows:

```
--------count mode----------
[EMG] [cycles] eventType: 0xff: 5466989440
[EMG] [branches] eventType: 0xc: 602166445
------- sample mode----------
[EMG] dump section data, addr: 0x8000000 length: 0x800000
num:  00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 ...
hex:  00 ef ef ef 00 00 00 00 14 00 00 00 60 00 00 00 00 00 00 00 70 88 36 40 08 00 00 00 6b 65 72 6e 65 6c 00 00 01 00 00 00 cc 55 30 40 08 00 00 00 6b 65 72 6e 65 6c 00 00
```

- For the counting mode, the following information is displayed after perf is stopped:
  Event name (cycles), event type (0xff), and number of event occurrences (5466989440)

  For hardware PMU events, the displayed event type is the hardware event ID, not the abstract type defined in **enum PmuHWId**.

- For the sampling mode, the address and length of the sampled data will be displayed after perf is stopped:
  dump section data, addr: (0x8000000) length: (0x5000)

  You can export the data using the JTAG interface and then use the IDE offline tool to analyze the data.

  You can also call **LOS_PerfDataRead** to read data to a specified address for further analysis. In the example, **OsPrintBuff** is a test API, which prints the sampled data by byte. **num** indicates the sequence number of the byte, and **hex** indicates the value in the byte.


### User-Mode Development Process

Choose **Driver** > **Enable PERF DRIVER** in **menuconfig** to enable the perf driver. This option is available in **Driver** only after **Enable Perf Feature** is selected in the kernel.

1. Open the **/dev/perf** file and perform read, write, and ioctl operations.

2. Run the **perf** commands in user mode in the **/bin** directory. 
   
   After running **cd bin**, you can use the following commands:
   
   - **./perf start [*id*]**: starts perf sampling. *id* is optional and is **0** by default.
   - **./perf stop**: stops perf sampling.
   - **./perf read <*nBytes*>**: reads n-byte data from the sampling buffer and displays the data.
   - **./perf list**: lists the events supported by **-e**.
   - **./perf stat/record [*option*] <*command*>**: sets counting or sampling parameters.
      - The [*option*] can be any of the following:
         - -**-e**: sets sampling events. Events of the same type listed in **./perf list** can be used.
         - -**-p**: sets the event sampling interval.
         - -**-o**: specifies the path of the file for saving the perf sampling data.
         - -**-t**: specifies the task IDs for data collection. Only the contexts of the specified tasks are collected. If this parameter is not specified, all tasks are collected by default.
         - -**-s**: specifies the context type for sampling. For details, see **PerfSampleType** defined in **los_perf.h**.
         - -**-P**: specifies the process IDs for data collection. Only the contexts of the specified processes are collected. If this parameter is not specified, all processes are collected by default.
         - -**-d**: specifies whether to divide the frequency (the value is incremented by 1 each time an event occurs 64 times). This option is valid only for hardware cycle events.
      - *command* specifies the program to be checked by perf.

Examples:

Run the **./perf list** command to display available events. 

The output is as follows:


```
cycles                                 [Hardware event]
instruction                            [Hardware event]
dcache                                 [Hardware event]
dcache-miss                            [Hardware event]
icache                                 [Hardware event]
icache-miss                            [Hardware event]
branch                                 [Hardware event]
branch-miss                            [Hardware event]
clock                                     [Timed event]
task-switch                            [Software event]
irq-in                                 [Software event]
mem-alloc                              [Software event]
mux-pend                               [Software event]
```

Run **./perf stat -e cycles os_dump**. 

The output is as follows:


```
type: 0
events[0]: 255, 0xffff
predivided: 0
sampleType: 0x0
needSample: 0
usage os_dump [--help | -l | SERVICE]
         --help: shows this help
         -l: only list services, do not dump them
         SERVICE: dumps only service SERVICE
time used: 0.058000(s)
[cycles] eventType: 0xff [core 0]: 21720647
[cycles] eventType: 0xff [core 1]: 13583830
```

Run **./perf record -e cycles os_dump**. 

The output is as follows:


```
type: 0
events[0]: 255, 0xffff
predivided: 0
sampleType: 0x60
needSample: 1
usage os_dump [--help | -l | SERVICE]
         --help: shows this help
         -l: only list services, do not dump them
         SERVICE: dumps only service SERVICE
dump perf data, addr: 0x408643d8 length: 0x5000
time used: 0.059000(s)
save perf data success at /storage/data/perf.data
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> After running the **./perf stat/record** command, you can run the **./perf start** and **./perf stop** commands multiple times. The sampling event configuration is as per the parameters set in the latest **./perfstat/record** command.


#### User-Mode Development Example

This example implements the following:

1. Open the perf character device.

2. Write the perf events.

3. Start perf.

4. Stop perf.

5. Read the perf sampling data.


#### User-Mode Sample Code

  The code is as follows:

```
#include "fcntl.h"
#include "user_copy.h"
#include "sys/ioctl.h"
#include "fs/driver.h"
#include "los_dev_perf.h"
#include "los_perf.h"
#include "los_init.h"
/* perf ioctl */
#define PERF_IOC_MAGIC     'T'
#define PERF_START         _IO(PERF_IOC_MAGIC, 1)
#define PERF_STOP          _IO(PERF_IOC_MAGIC, 2)
int main(int argc, char **argv)
{
    char *buf = NULL;
    ssize_t len;
    int fd = open("/dev/perf", O_RDWR);
    if (fd == -1) {
        printf("Perf open failed.\n");
        exit(EXIT_FAILURE);
    }
    PerfConfigAttr attr = {
        .eventsCfg = {
#ifdef LOSCFG_PERF_HW_PMU
            .type = PERF_EVENT_TYPE_HW,
            .events = {
                [0] = {PERF_COUNT_HW_CPU_CYCLES, 0xFFFF},
            },
#elif defined LOSCFG_PERF_TIMED_PMU
            .type = PERF_EVENT_TYPE_TIMED,
            .events = {
                [0] = {PERF_COUNT_CPU_CLOCK, 100},
            },
#elif defined LOSCFG_PERF_SW_PMU
            .type = PERF_EVENT_TYPE_SW,
            .events = {
                [0] = {PERF_COUNT_SW_TASK_SWITCH, 1},
            },
#endif
            .eventsNr = 1, /* 1 event */
            .predivided = 0,
        },
        .taskIds = {0},
        .taskIdsNr = 0,
        .processIds = {0},
        .processIdsNr = 0,
        .needSample = 1,
        .sampleType = PERF_RECORD_IP | PERF_RECORD_CALLCHAIN,
    };
    (void)write(fd, &attr, sizeof(PerfConfigAttr)); /* perf config */
    ioctl(fd, PERF_START, NULL); /* perf start */
    test();
    ioctl(fd, PERF_STOP, NULL); /* perf stop */
    buf = (char *)malloc(LOSCFG_PERF_BUFFER_SIZE);
    if (buf == NULL) {
        printf("no memory for read perf 0x%x\n", LOSCFG_PERF_BUFFER_SIZE);
        return -1;
    }
    len = read(fd, buf, LOSCFG_PERF_BUFFER_SIZE);
    OsPrintBuff(buf, len); /* print data */
    free(buf);
    close(fd);
    return 0;
}
```


#### User-Mode Verification

  The output is as follows:

```
[EMG] dump section data, addr: 0x8000000 length: 0x800000
num:  00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 ...
hex:  00 ef ef ef 00 00 00 00 14 00 00 00 60 00 00 00 00 00 00 00 70 88 36 40 08 00 00 00 6b 65 72 6e 65 6c 00 00 01 00 00 00 cc 55 30 40 08 00 00 00 6b 65 72 6e 65 6c 00 00
```
