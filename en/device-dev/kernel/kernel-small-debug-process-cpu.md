# Process Debugging


## Basic Concepts

The central processing unit percent (CPUP) includes the system CPUP, process CPUP, task CPUP, and interrupt CPUP. With the system CPUP, you can determine whether the current system load exceeds the designed specifications. With the CPUP of each task/process/interrupt, you can determine whether their CPU usage meets expectations of the design.

- System CPUP
  System CPUP is the CPU usage of the system within a period of time. It reflects the CPU load and the system running status (idle or busy) in the given period of time. The valid range of the system CPUP is 0 to 100 in percentage. The precision can be adjusted through configuration. The value **100** indicates that the system runs with full load.

- Process CPUP
  Process CPUP refers to the CPU usage of a single process. It reflects the process status, busy or idle, in a period of time. The valid range of the process CPUP is 0 to 100 in percentage. The precision can be adjusted through configuration. The value **100** indicates that the process is being executed for a period of time.

- Task CPUP
  Task CPUP refers to the CPU usage of a single task. It reflects the task status, busy or idle, in a period of time. The valid range of task CPUP is 0 to 100 in percentage. The precision can be adjusted through configuration. The value **100** indicates that the task is being executed for the given period of time.

- Interrupt CPUP
  Interrupt CPUP refers to the CPU usage of a single interrupt. It reflects the interrupt status, busy or idle, in a period of time. The valid range of the interrupt CPUP is 0 to 100 in percentage. The precision can be adjusted through configuration. The value **100** indicates that the interrupt is being executed for a period of time.


## Working Principles

The OpenHarmony LiteOS-A kernel CPUP module records the CPU usage by process, task, and interrupt. When a process or task is switched, the start time of the process or task is recorded. When the process or task is switched out or exits, the system accumulates the CPU time of the entire process or task. When an interrupt is executed, the system accumulates and records the execution time of each interrupt.

OpenHarmony provides the following types of CPUP information:

- System CPUP

- Process CPUP

- Task CPUP

- Interrupt CPUP

The CPUP is calculated as follows:

System CPUP = Total running time of all tasks except idle tasks/Total running time of the system

Process CPUP = Total running time of the process/Total running time of the system

Task CPUP = Total running time of the task/Total running time of the system

Interrupt CPUP = Total running time of the interrupt/Total running time of the system


## Development Guidelines


### Available APIs

  **Table 1** CPUP module APIs

| Category| API| Description|
| -------- | -------- | -------- |
| System CPUP| LOS_HistorySysCpuUsage | Obtains the historical CPUP of the system.|
| Process CPUP| LOS_HistoryProcessCpuUsage | Obtains the historical CPUP of a specified process.|
| Process CPUP| LOS_GetAllProcessCpuUsage | Obtains the historical CPUP of all processes in the system.|
| Task CPUP| LOS_HistoryTaskCpuUsage | Obtains the historical CPUP of a specified task.|
| Interrupt CPUP| LOS_GetAllIrqCpuUsage | Obtains the historical CPUP of all interrupts in the system.|
| Reset| LOS_CpupReset | Resets CPUP data.|


### How to Develop

The typical CPUP development process is as follows:

1. Call **LOS_HistorySysCpuUsage** to obtain the historical CPUP of the system.

2. Call **LOS_HistoryProcessCpuUsage** to obtain the historical CPUP of a specified process.
   - If the process has been created, disable interrupt, obtain the CPUP in different modes, and then enable interrupt.
   - If the process is not created, return an error code.

3. Call **LOS_GetAllProcessCpuUsage** to obtain the CPUP of all processes.
   - If the CPUP is initialized, disable interrupt, obtain the CPUP in different modes, and then enable interrupt.
   - If CPUP is not initialized or has invalid input parameters, return an error code.

4. Call **LOS_HistoryTaskCpuUsage** to obtain the historical CPUP of a specified task.
   - If the task has been created, disable interrupt, obtain the CPUP in different modes, and then enable interrupt.
   - If the task is not created, return an error code.

5. Call **LOS_GetAllIrqCpuUsage** to obtain the CPUP of all interrupts.
   - If the CPUP has been initialized, disable interrupt, obtain the CPUP in different modes, and then enable interrupt.
   - If CPUP is not initialized or has invalid input parameters, return an error code.


### Development Example

This example implements the following:

1. Create a task for the CPUP test.

2. Obtain the CPUP of the current system.

3. Obtain the historical system CPUP in different modes.

4. Obtain the CPUP of the created test task.

5. Obtain the CPUP of the created test task in different modes.

Prerequisites:

The CPUP control is enabled in the **menuconfig** configuration.

**Sample Code**

You can compile and verify the sample code in **kernel/liteos_a/testsuites /kernel/src /osTest.c**. The **CpupTest** function is called in **TestTaskEntry**.
The sample code is as follows:


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
    TSK_INIT_PARAM_S cpupTestTask = {0};
    memset(&cpupTestTask, 0, sizeof(TSK_INIT_PARAM_S));
    cpupTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)ExampleCpup;
    cpupTestTask.pcName       = "TestCpupTsk";
    cpupTestTask.uwStackSize  = 0x800; // 0x800: cpup test task stack size
    cpupTestTask.usTaskPrio   = 5; // 5: cpup test task priority
    ret = LOS_TaskCreate(&g_cpuTestTaskID, &cpupTestTask);
    if (ret != LOS_OK) {
        printf("cpupTestTask create failed .\n");
        return LOS_NOK;
    }

    usleep(100); // 100: delay for 100ms

    /* Obtain the historical CPUP of the system. */
    cpupUse = LOS_HistorySysCpuUsage(CPUP_LAST_ONE_SECONDS);
    dprintf("the history system cpu usage in all time: %u.%u\n",
           cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);
     /* Obtain the CPUP of the specified task (cpupTestTask in this example). */
    cpupUse = LOS_HistoryTaskCpuUsage(g_cpuTestTaskID, CPUP_LAST_ONE_SECONDS);
    dprintf("cpu usage of the cpupTestTask in all time:\n TaskID: %d\n usage: %u.%u\n",
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

The print information may vary depending on the running environment.
```

