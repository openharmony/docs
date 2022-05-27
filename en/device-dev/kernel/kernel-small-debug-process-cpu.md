# Process Debugging


## Basic Concepts

The central processing unit percent \(CPUP\) includes the system CPUP, process CPUP, task CPUP, and interrupt CPUP. With the system CPUP, you can determine whether the current system load exceeds the designed specifications. With the CPUP of each task/process/interrupt, you can determine whether their CPU usage meets expectations of the design.

-   System CPUP

    System CPUP is the CPU usage of the system within a period of time. It reflects the CPU load and the system running status \(idle or busy\) in the given period of time. The valid range of the system CPUP is 0 to 100 in percentage. The precision can be adjusted through configuration. The value  **100**  indicates that the system runs with full load.

-   Process CPUP

    Process CPUP refers to the CPU usage of a single process. It reflects the process status, busy or idle, in a period of time. The valid range of the process CPUP is 0 to 100 in percentage. The precision can be adjusted through configuration. The value  **100**  indicates that the process is being executed for a period of time.

-   Task CPUP

    Task CPUP refers to the CPU usage of a single task. It reflects the task status, busy or idle, in a period of time. The valid range of task CPUP is 0 to 100 in percentage. The precision can be adjusted through configuration. The value  **100**  indicates that the task is being executed for the given period of time.

-   Interrupt CPUP

    Interrupt CPUP refers to the CPU usage of a single interrupt. It reflects the interrupt status, busy or idle, in a period of time. The valid range of the interrupt CPUP is 0 to 100 in percentage. The precision can be adjusted through configuration. The value  **100**  indicates that the interrupt is being executed for a period of time.


## Working Principles<a name="section593718536227"></a>

The OpenHarmony LiteOS-A kernel CPUP module records the CPU usage by process, task, and interrupt. When a process or task is switched, the start time of the process or task is recorded. When the process or task is switched out or exits, the system accumulates the CPU time of the entire process or task. When an interrupt is executed, the system accumulates and records the execution time of each interrupt.

OpenHarmony provides the following types of CPUP information:

-   System CPUP
-   Process CPUP
-   Task CPUP
-   Interrupt CPUP

The CPUP is calculated as follows:

System CPUP = Total running time of all tasks except idle tasks/Total running time of the system

Process CPUP = Total running time of the process/Total running time of the system

Task CPUP = Total running time of the task/Total running time of the system

Interrupt CPUP = Total running time of the interrupt/Total running time of the system

## Development Guidelines<a name="section11284210152311"></a>

### Available APIs<a name="section3745151592312"></a>

**Table  1**  CPUP module APIs

<a name="table147491853163018"></a>
<table><thead align="left"><tr id="row10807205323013"><th class="cellrowborder" valign="top" width="28.3971602839716%" id="mcps1.2.4.1.1"><p id="p980714539304"><a name="p980714539304"></a><a name="p980714539304"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="36.47635236476353%" id="mcps1.2.4.1.2"><p id="p1780715533305"><a name="p1780715533305"></a><a name="p1780715533305"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="35.12648735126487%" id="mcps1.2.4.1.3"><p id="p18807185316301"><a name="p18807185316301"></a><a name="p18807185316301"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3807145310300"><td class="cellrowborder" valign="top" width="28.3971602839716%" headers="mcps1.2.4.1.1 "><p id="p174011140141013"><a name="p174011140141013"></a><a name="p174011140141013"></a>System CPUP</p>
</td>
<td class="cellrowborder" valign="top" width="36.47635236476353%" headers="mcps1.2.4.1.2 "><p id="p158071153133013"><a name="p158071153133013"></a><a name="p158071153133013"></a>LOS_HistorySysCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" width="35.12648735126487%" headers="mcps1.2.4.1.3 "><p id="p14808115353010"><a name="p14808115353010"></a><a name="p14808115353010"></a>Obtains the historical CPUP of the system.</p>
</td>
</tr>
<tr id="row147461859201016"><td class="cellrowborder" rowspan="2" valign="top" width="28.3971602839716%" headers="mcps1.2.4.1.1 "><p id="p374720596102"><a name="p374720596102"></a><a name="p374720596102"></a>Process CPUP</p>
</td>
<td class="cellrowborder" valign="top" width="36.47635236476353%" headers="mcps1.2.4.1.2 "><p id="p3747859101010"><a name="p3747859101010"></a><a name="p3747859101010"></a>LOS_HistoryProcessCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" width="35.12648735126487%" headers="mcps1.2.4.1.3 "><p id="p1747959131016"><a name="p1747959131016"></a><a name="p1747959131016"></a>Obtains the historical CPUP of a specified process.</p>
</td>
</tr>
<tr id="row2075434812116"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17541648171114"><a name="p17541648171114"></a><a name="p17541648171114"></a>LOS_GetAllProcessCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1575419483116"><a name="p1575419483116"></a><a name="p1575419483116"></a>Obtains the historical CPUP of all processes in the system.</p>
</td>
</tr>
<tr id="row1480855311301"><td class="cellrowborder" valign="top" width="28.3971602839716%" headers="mcps1.2.4.1.1 "><p id="p1618792981018"><a name="p1618792981018"></a><a name="p1618792981018"></a>Task CPUP</p>
</td>
<td class="cellrowborder" valign="top" width="36.47635236476353%" headers="mcps1.2.4.1.2 "><p id="p9808185353016"><a name="p9808185353016"></a><a name="p9808185353016"></a>LOS_HistoryTaskCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" width="35.12648735126487%" headers="mcps1.2.4.1.3 "><p id="p12808653183016"><a name="p12808653183016"></a><a name="p12808653183016"></a>Obtains the historical CPUP of a specified task.</p>
</td>
</tr>
<tr id="row680812535306"><td class="cellrowborder" valign="top" width="28.3971602839716%" headers="mcps1.2.4.1.1 "><p id="p13808125314307"><a name="p13808125314307"></a><a name="p13808125314307"></a>Interrupt CPUP</p>
</td>
<td class="cellrowborder" valign="top" width="36.47635236476353%" headers="mcps1.2.4.1.2 "><p id="p1480835316303"><a name="p1480835316303"></a><a name="p1480835316303"></a>LOS_GetAllIrqCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" width="35.12648735126487%" headers="mcps1.2.4.1.3 "><p id="p33741531163313"><a name="p33741531163313"></a><a name="p33741531163313"></a>Obtains the historical CPUP of all interrupts in the system.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section122901429182316"></a>

The typical CPUP development process is as follows.

1.  Call  **LOS\_HistorySysCpuUsage**  to obtain the historical CPUP of the system.
2.  Call  **LOS\_HistoryProcessCpuUsage**  to obtain the historical CPUP of a specified process.
    -   If the process has been created, disable interrupt, obtain the CPUP in different modes, and then enable interrupt.
    -   If the process is not created, return an error code.

3.  Call  **LOS\_GetAllProcessCpuUsage**  to obtain the CPUP of all processes.
    -   If the CPUP has been initialized, disable interrupt, obtain the CPUP in different modes, and then enable interrupt.
    -   If CPUP is not initialized or has invalid input parameters, return an error code.

4.  Call  **LOS\_HistoryTaskCpuUsage**  to obtain the historical CPUP of a specified task.
    -   If the task has been created, disable interrupt, obtain the CPUP in different modes, and then enable interrupt.
    -   If the task is not created, return an error code.

5.  Call  **LOS\_GetAllIrqCpuUsage**  to obtain the CPUP of all interrupts.
    -   If the CPUP has been initialized, disable interrupt, obtain the CPUP in different modes, and then enable interrupt.
    -   If CPUP has not been initialized or has invalid input parameters, return an error code.


### Development Example<a name="section1765785212310"></a>

This example implements the following:

1.  Create a task for the CPUP test.
2.  Obtain the CPUP of the current system.
3.  Obtain the historical system CPUP in different modes.
4.  Obtain the CPUP of the created test task.
5.  Obtain the CPUP of the created test task in different modes.

Prerequisites

The CPUP control is enabled in the  **menuconfig**  configuration.

**Sample Code**

The sample code is as follows:

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
    TSK_INIT_PARAM_S cpupTestTask = { 0 };
    memset(&cpupTestTask, 0, sizeof(TSK_INIT_PARAM_S));
    cpupTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleCpup;
    cpupTestTask.pcName       = "TestCpupTsk"; 
    cpupTestTask.uwStackSize  = 0x800;
    cpupTestTask.usTaskPrio   = 5;
    ret = LOS_TaskCreate(&g_cpuTestTaskID, &cpupTestTask);
    if(ret != LOS_OK) {
        printf("cpupTestTask create failed .\n");
        return LOS_NOK;
    }

    usleep(100);

 /* Obtain the historical CPUP of the system. */
    cpupUse = LOS_HistorySysCpuUsage(CPU_LESS_THAN_1S); 
    printf("the history system cpu usage in all time: %u.%u\n",
           cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);
 /* Obtain the CPUP of the specified task (cpupTestTask in this example).*/
    cpupUse = LOS_HistoryTaskCpuUsage(g_cpuTestTaskID, CPU_LESS_THAN_1S);   
    printf("cpu usage of the cpupTestTask in all time:\n TaskID: %d\n usage: %u.%u\n",
           g_cpuTestTaskID, cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);   
    return LOS_OK; 
}
```

**Verification**

The development is successful if the return result is as follows:

```
entry cpup test example
the history system cpu usage in all time: 3.0
cpu usage of the cpupTestTask in all time: TaskID:10 usage: 0.0
```

