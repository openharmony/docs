# Development Guidelines<a name="EN-US_TOPIC_0000001079036450"></a>

-   [Available APIs](#section158501652121514)
-   [How to Develop](#section783435801510)
-   [Development Example](#section460018317164)
    -   [Example Description](#section51413507517)
    -   [Sample Code](#section17617965523)
    -   [Verification](#section1968771515188)


## Available APIs<a name="section158501652121514"></a>

**Table  1**  Functions

<a name="table18293928155615"></a>
<table><thead align="left"><tr id="row129362875613"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p19444103765618"><a name="p19444103765618"></a><a name="p19444103765618"></a>Category</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p944473716569"><a name="p944473716569"></a><a name="p944473716569"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p144445378565"><a name="p144445378565"></a><a name="p144445378565"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1143613475615"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p942993405610"><a name="p942993405610"></a><a name="p942993405610"></a>Obtaining the system CPU usage</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p242973419563"><a name="p242973419563"></a><a name="p242973419563"></a>LOS_SysCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7429163416565"><a name="p7429163416565"></a><a name="p7429163416565"></a>Obtains the current system CPUP.</p>
</td>
</tr>
<tr id="row15436163435611"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p20429183410563"><a name="p20429183410563"></a><a name="p20429183410563"></a>LOS_HistorySysCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p542953465617"><a name="p542953465617"></a><a name="p542953465617"></a>Obtains the historical CPUP of the system.</p>
</td>
</tr>
<tr id="row143610342562"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p174295347568"><a name="p174295347568"></a><a name="p174295347568"></a>Obtaining the task CPUP</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p124291734155614"><a name="p124291734155614"></a><a name="p124291734155614"></a>LOS_TaskCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1042963410568"><a name="p1042963410568"></a><a name="p1042963410568"></a>Obtains the CPUP of a specified task.</p>
</td>
</tr>
<tr id="row12436143414561"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6429834185613"><a name="p6429834185613"></a><a name="p6429834185613"></a>LOS_HistoryTaskCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p74302034175614"><a name="p74302034175614"></a><a name="p74302034175614"></a>Obtains the historical CPUP of a specified task.</p>
</td>
</tr>
<tr id="row2435834135618"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p843073420563"><a name="p843073420563"></a><a name="p843073420563"></a>LOS_AllCpuUsage</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4430134185614"><a name="p4430134185614"></a><a name="p4430134185614"></a>Obtains the CPUP of all tasks.</p>
</td>
</tr>
<tr id="row15435934155618"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1543033435615"><a name="p1543033435615"></a><a name="p1543033435615"></a>Outputting the task CPUP</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1643016342562"><a name="p1643016342562"></a><a name="p1643016342562"></a>LOS_CpupUsageMonitor</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p84301234115617"><a name="p84301234115617"></a><a name="p84301234115617"></a>Outputs the historical CPUP of a task.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section783435801510"></a>

The typical CPUP development process is as follows.

1.  Call  **LOS\_SysCpuUsage**  to obtain the system CPUP.
2.  Call  **LOS\_HistorySysCpuUsage**  to obtain the historical CPUP of the system.
3.  Call  **LOS\_TaskCpuUsage**  to obtain the CPUP of a specified task.
    -   If the task has been created, disable interrupt, obtain the CPUP, and then enable interrupt.
    -   If the task is not created, return an error code.

4.  Call  **LOS\_HistoryTaskCpuUsage**  to obtain the historical CPUP of a specified task.
    -   If the task has been created, disable interrupt, obtain the CPUP in different modes, and then enable interrupt.
    -   If the task is not created, return an error code.

5.  Call  **LOS\_AllCpuUsage**  to obtain the CPUP of all tasks.
    -   If the CPUP is initialized, disable interrupt, obtain the CPUP in different modes, and then enable interrupt.
    -   If CPUP is not initialized or has invalid input parameters, return an error code.


## Development Example<a name="section460018317164"></a>

### Example Description<a name="section51413507517"></a>

This example implements the following:

1.  Create a task for the CPUP test.
2.  Obtain the CPUP of the current system.
3.  Obtain the historical system CPUP in different modes.
4.  Obtain the CPUP of the created test task.
5.  Obtain the CPUP of the created test task in different modes.

### Sample Code<a name="section17617965523"></a>

Prerequisites

In  **target\_config.h**, the  **LOSCFG\_BASE\_CORE\_CPUP**  parameter is enabled.

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

 /* Obtain the current CPUP of the system. */
    cpupUse = LOS_SysCpuUsage();
    printf("the current system cpu usage is: %u.%u\n",
            cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT); 

    cpupUse = LOS_HistorySysCpuUsage(CPU_LESS_THAN_1S);
 /* Obtain the CPUP of the specified task (cpupTestTask in this example).*/
    printf("the history system CPUP in all time: %u.%u\n",
           cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);
    cpupUse = LOS_TaskCpuUsage(g_cpuTestTaskID);    
 /* Obtain the CPUP of the specified historical task (cpupTestTask in this example) since the system startup. */
    printf("cpu usage of the cpupTestTask:\n TaskID: %d\n usage: %u.%u\n",
           g_cpuTestTaskID, cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT); 
    cpupUse = LOS_HistoryTaskCpuUsage(g_cpuTestTaskID, CPU_LESS_THAN_1S);   
    printf("cpu usage of the cpupTestTask in all time:\n TaskID: %d\n usage: %u.%u\n",
           g_cpuTestTaskID, cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);   
    return LOS_OK; 
}
```

### Verification<a name="section1968771515188"></a>

The development is successful if the return result is as follows:

```
entry cpup test example 
the current system cpu usage is : 1.5
 the history system cpu usage in all time: 3.0
 cpu usage of the cpupTestTask: TaskID:10 usage: 0.0
 cpu usage of the cpupTestTask&nbsp;in all time: TaskID:10 usage: 0.0
```

