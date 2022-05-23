# perf


## Basic Concepts

perf is a performance analysis tool. It uses the performance monitoring unit \(PMU\) to count sampling events and collect context information and provides hot spot distribution and hot paths.

## Working Principles

When a performance event occurs, the corresponding event counter overflows and triggers an interrupt. The interrupt handler records the event information, including the current PC, task ID, and call stack.

perf provides two working modes: counting mode and sampling mode.

In counting mode, perf collects only the number of event occurrences and duration. In sampling mode, perf also collects context data and stores the data in a circular buffer. The IDE then analyzes the data and provides information about hotspot functions and paths.

## Available APIs

### Kernel Mode

The perf module of the OpenHarmony LiteOS-A kernel provides the following APIs. For more details about the APIs, see the  [API](https://gitee.com/openharmony/kernel_liteos_a/blob/master/kernel/include/los_perf.h)  reference.

**Table  1**  perf module APIs

<a name="table209384411409"></a>
<table><thead align="left"><tr id="row49387411909"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p142345517111"><a name="p142345517111"></a><a name="p142345517111"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p16234751114"><a name="p16234751114"></a><a name="p16234751114"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p1823555614"><a name="p1823555614"></a><a name="p1823555614"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17146213111"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p3136111817"><a name="p3136111817"></a><a name="p3136111817"></a>Starting or stopping perf sampling</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p7136415111"><a name="p7136415111"></a><a name="p7136415111"></a>LOS_PerfStart</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p16136111512"><a name="p16136111512"></a><a name="p16136111512"></a>Starts sampling.</p>
</td>
</tr>
<tr id="row5146111214"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p201361616119"><a name="p201361616119"></a><a name="p201361616119"></a>LOS_PerfStop</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1313611114117"><a name="p1313611114117"></a><a name="p1313611114117"></a>Stops sampling.</p>
</td>
</tr>
<tr id="row61461611314"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p7136171816"><a name="p7136171816"></a><a name="p7136171816"></a>Configuring perf sampling events</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p161364119113"><a name="p161364119113"></a><a name="p161364119113"></a>LOS_PerfConfig</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p41361218111"><a name="p41361218111"></a><a name="p41361218111"></a>Sets the type and period of a sampling event.</p>
</td>
</tr>
<tr id="row19146619113"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p21362119112"><a name="p21362119112"></a><a name="p21362119112"></a>Reading sampling data</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p113618119118"><a name="p113618119118"></a><a name="p113618119118"></a>LOS_PerfDataRead</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1113711612"><a name="p1113711612"></a><a name="p1113711612"></a>Reads the sampling data to a specified address.</p>
</td>
</tr>
<tr id="row201465110113"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p121376114114"><a name="p121376114114"></a><a name="p121376114114"></a>Registering a hook for the sampling data buffer</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p71371011513"><a name="p71371011513"></a><a name="p71371011513"></a>LOS_PerfNotifyHookReg</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p16137618118"><a name="p16137618118"></a><a name="p16137618118"></a>Registers the hook to be called when the buffer waterline is reached.</p>
</td>
</tr>
<tr id="row13145911019"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6137317113"><a name="p6137317113"></a><a name="p6137317113"></a>LOS_PerfFlushHookReg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p613715120114"><a name="p613715120114"></a><a name="p613715120114"></a>Registers the hook for flushing the cache in the buffer.</p>
</td>
</tr>
</tbody>
</table>

1.  The structure of the perf sampling event is  **PerfConfigAttr**. For details, see  **kernel\\include\\los\_perf.h**.
2.  The sampling data buffer is a circular buffer, and only the region that has been read in the buffer can be overwritten.
3.  The buffer has limited space. You can register a hook to provide a buffer overflow notification or perform buffer read operation when the buffer waterline is reached. The default buffer waterline is 1/2 of the buffer size. The sample code is as follows:

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

4.  If the buffer sampled by perf involves caches across CPUs, you can register a hook for flushing the cache to ensure cache consistency. The sample code is as follows:

    ```
    VOID Example_PerfFlushHook(VOID *addr, UINT32 size)
    {
        OsCacheFlush(addr, size); /* platform interface */
    }
    LOS_PerfNotifyHookReg(Example_PerfFlushHook);
    ```

    The API for flushing the cache is configured based on the platform.


### User Mode

The perf character device is located in  **/dev/perf**. You can read, write, and control the user-mode perf by running the following commands on the device node:

-   **read**: reads perf data in user mode.
-   **write**: writes user-mode sampling events.
-   **ioctl**: controls the user-mode perf, which includes the following:

    ```
    #define PERF_IOC_MAGIC     'T'
    #define PERF_START         _IO(PERF_IOC_MAGIC, 1)
    #define PERF_STOP          _IO(PERF_IOC_MAGIC, 2)
    ```

    The operations correspond to  **LOS\_PerfStart**  and  **LOS\_PerfStop**.


For more details, see  [User-mode Development Example](#user-mode-development-example).

## Development Guidelines

### Kernel-mode Development Process

The typical process of enabling perf is as follows:

1.  Configure the macros related to the perf module.

    Configure the perf control macro  **LOSCFG\_KERNEL\_PERF**, which is disabled by default. In the  **kernel/liteos\_a**  directory, run the  **make update\_config**  command, choose  **Kernel**, and select  **Enable Perf Feature**.

    <a name="table06964569614"></a>
    <table><thead align="left"><tr id="row1697105618610"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p669715610619"><a name="p669715610619"></a><a name="p669715610619"></a>Macro</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p0697105612614"><a name="p0697105612614"></a><a name="p0697105612614"></a>menuconfig Option</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p5697175610610"><a name="p5697175610610"></a><a name="p5697175610610"></a>Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p1269712561866"><a name="p1269712561866"></a><a name="p1269712561866"></a>Value</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row48579520718"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p138411959715"><a name="p138411959715"></a><a name="p138411959715"></a>LOSCFG_KERNEL_PERF</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p6841151471"><a name="p6841151471"></a><a name="p6841151471"></a>Enable Perf Feature</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p128411551271"><a name="p128411551271"></a><a name="p128411551271"></a>Whether to enable perf.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p1584116513713"><a name="p1584116513713"></a><a name="p1584116513713"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row14856135172"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p10841145172"><a name="p10841145172"></a><a name="p10841145172"></a>LOSCFG_PERF_CALC_TIME_BY_TICK</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p6841751173"><a name="p6841751173"></a><a name="p6841751173"></a>Time-consuming Calc Methods-&gt;By Tick</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p188417515713"><a name="p188417515713"></a><a name="p188417515713"></a>Whether to use tick as the perf timing unit.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p28421251079"><a name="p28421251079"></a><a name="p28421251079"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row08561858720"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p2842195177"><a name="p2842195177"></a><a name="p2842195177"></a>LOSCFG_PERF_CALC_TIME_BY_CYCLE</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p148421551373"><a name="p148421551373"></a><a name="p148421551373"></a>Time-consuming Calc Methods-&gt;By Cpu Cycle</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p148421751575"><a name="p148421751575"></a><a name="p148421751575"></a>Whether to use cycle as the perf timing unit.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p7842551970"><a name="p7842551970"></a><a name="p7842551970"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row168562511717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p18842205871"><a name="p18842205871"></a><a name="p18842205871"></a>LOSCFG_PERF_BUFFER_SIZE</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p128421655716"><a name="p128421655716"></a><a name="p128421655716"></a>Perf Sampling Buffer Size</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p88424511719"><a name="p88424511719"></a><a name="p88424511719"></a>Size of the buffer used for perf sampling.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p28421455716"><a name="p28421455716"></a><a name="p28421455716"></a>INT</p>
    </td>
    </tr>
    <tr id="row685645671"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1084245472"><a name="p1084245472"></a><a name="p1084245472"></a>LOSCFG_PERF_HW_PMU</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p11842651976"><a name="p11842651976"></a><a name="p11842651976"></a>Enable Hardware Pmu Events for Sampling</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p5842651971"><a name="p5842651971"></a><a name="p5842651971"></a>Whether to enable hardware PMU events. The target platform must support the hardware PMU.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p17842350713"><a name="p17842350713"></a><a name="p17842350713"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row2085695779"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p148421951574"><a name="p148421951574"></a><a name="p148421951574"></a>LOSCFG_PERF_TIMED_PMU</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p16842115373"><a name="p16842115373"></a><a name="p16842115373"></a>Enable Hrtimer Period Events for Sampling</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p11842135973"><a name="p11842135973"></a><a name="p11842135973"></a>Whether to enable high-precision periodical events. The target platform must support the high precision event timer (HPET).</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p1784205875"><a name="p1784205875"></a><a name="p1784205875"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row108562511719"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p684218515717"><a name="p684218515717"></a><a name="p684218515717"></a>LOSCFG_PERF_SW_PMU</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p284275473"><a name="p284275473"></a><a name="p284275473"></a>Enable Software Events for Sampling</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p184214514715"><a name="p184214514715"></a><a name="p184214514715"></a>Whether to enable software events. <strong id="b947154317012"><a name="b947154317012"></a><a name="b947154317012"></a>LOSCFG_KERNEL_HOOK</strong> must also be enabled.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p16896951459"><a name="p16896951459"></a><a name="p16896951459"></a>YES/NO</p>
    </td>
    </tr>
    </tbody>
    </table>

2.  Call  **LOS\_PerfConfig**  to configure the events to be sampled.

    perf provides two working modes and three types of events.

    Two modes: counting mode \(counts only the number of event occurrences\) and sampling mode \(collects context information such as task IDs, PC, and backtrace\)

    Three types of events: CPU hardware events \(such as cycle, branch, icache, and dcache\), high-precision periodical events \(such as CPU clock\), and OS software events \(such as task switch, mux pend, and IRQ\)

3.  Call  **LOS\_PerfStart\(UINT32 sectionId\)**  at the start of the code to be sampled. The input parameter  **sectionId**  specifies different sampling session IDs.
4.  Call  **LOS\_PerfStop**  at the end of the code to be sampled.
5.  Call  **LOS\_PerfDataRead**  to read the sampling data and use IDE to analyze the collected data.

## Kernel-mode Development Example

This example implements the following:

1.  Create a perf task.
2.  Configure sampling events.
3.  Start perf.
4.  Execute algorithms for statistics.
5.  Stop perf.
6.  Export the result. 

## Kernel-mode Sample Code

Prerequisites: The perf module configuration is complete in  **menuconfig**.

The code is as follows:

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
    /* Create a perf task.*/
    memset(&perfTestTask, 0, sizeof(TSK_INIT_PARAM_S));    
    perfTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)perfTestHwEvent;    
    perfTestTask.pcName       = "TestPerfTsk";    /* Task name.*/
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

### Kernel-mode Verification

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

-   For the counting mode, the following information is displayed after perf is stopped:

    Event name \(cycles\), event type \(0xff\), and number of event occurrences \(5466989440\)

    For hardware PMU events, the displayed event type is the hardware event ID, not the abstract type defined in  **enum PmuHWId**.

-   For the sampling mode, the address and length of the sampled data will be displayed after perf is stopped:

    dump section data, addr: \(0x8000000\) length: \(0x5000\)

    You can export the data using the JTAG interface and then use the IDE offline tool to analyze the data.

    You can also call  **LOS\_PerfDataRead**  to read data to a specified address for further analysis. In the example,  **OsPrintBuff**  is a test API, which prints the sampled data by byte.  **num**  indicates the sequence number of the byte, and  **hex**  indicates the value in the byte.


### User-mode Development Process

Choose  **Driver**  \>  **Enable PERF DRIVER**  in  **menuconfig**  to enable the perf driver. This option is available in  **Driver**  only after  **Enable Perf Feature**  is selected in the kernel.

1.  Open the  **/dev/perf**  file and perform read, write, and ioctl operations.
2.  Run the  **perf**  commands in user mode in the  **/bin**  directory. After running  **cd bin**, you can use the following commands:
    -   **./perf start \[_id_\]**: starts perf sampling.  _id_  is optional and is  **0**  by default.
    -   **./perf stop**: stops perf sampling.
    -   **./perf read <_nBytes_\>**: reads n-byte data from the sampling buffer and displays the data.
    -   **./perf list**: lists the events supported by  **-e**.
    -   **./perf stat/record \[_option_\] <_command_\>**: sets counting or sampling parameters.
        -   The \[_option_\] can be any of the following:
            -   **-e**: sets sampling events. Events of the same type listed in  **./perf list**  can be used.
            -   **-p**: sets the event sampling interval.
            -   **-o**: specifies the path of the file for saving the perf sampling data.
            -   **-t**: specifies the task IDs for data collection. Only the contexts of the specified tasks are collected. If this parameter is not specified, all tasks are collected by default.
            -   **-s**: specifies the context type for sampling. For details, see  **PerfSampleType**  defined in  **los\_perf.h**.
            -   **-P**: specifies the process IDs for data collection. Only the contexts of the specified processes are collected. If this parameter is not specified, all processes are collected by default.
            -   **-d**: specifies whether to divide the frequency \(the value is incremented by 1 each time an event occurs 64 times\). This option is valid only for hardware cycle events.

        -   _command_  specifies the program to be checked by perf.



Examples:

Run the  **./perf list**  command to display available events. The output is as follows:

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

Run  **./perf stat -e cycles os\_dump**. The output is as follows:

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

Run  **./perf record -e cycles os\_dump**. The output is as follows:

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

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/> 
>After running the  **./perf stat/record**  command, you can run the  **./perf start**  and  **./perf stop**  commands multiple times. The sampling event configuration is as per the parameters set in the latest  **./perfstat/record**  command.

### User-mode Development Example

This example implements the following:

1.  Open the perf character device.
2.  Write the perf events.
3.  Start perf.
4.  Stop perf.
5.  Read the perf sampling data.

### User-Mode Sample Code

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

### User-mode Verification

The output is as follows:

```
[EMG] dump section data, addr: 0x8000000 length: 0x800000
num:  00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 ...
hex:  00 ef ef ef 00 00 00 00 14 00 00 00 60 00 00 00 00 00 00 00 70 88 36 40 08 00 00 00 6b 65 72 6e 65 6c 00 00 01 00 00 00 cc 55 30 40 08 00 00 00 6b 65 72 6e 65 6c 00 00
```

