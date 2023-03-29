# CPUP


## Basic Concepts

The central processing unit percent (CPUP) includes the system CPUP and task CPUP.

**System CPUP**

The system CPUP is the CPU usage of the system within a period of time. It reflects the CPU load and the system running status (idle or busy) in the given period of time. The CPUP ranges from 0 to 100, in percentage. The value **100** indicates that the system runs with full load.

With the system CPUP, you can determine whether the current system load exceeds the designed specifications.

**Task CPUP**

Task CPUP refers to the CPU usage of a single task. It reflects the task status, busy or idle, in a period of time. The task CPUP ranges from 0 to 100, in percentage. The value **100** indicates that the task is being executed for the given period of time.

With the CPUP of each task, you can determine whether the CPU usage of each task meets expectations of the design.

**Interrupt CPUP**

In addition, you can enable the interrupt usage statistics function after the CPUP function is enabled.

Interrupt CPUP indicates the CPU usage of a single interrupt out of the total interrupt duration. The interrupt CPUP ranges from 0 to 100. The value **100** indicates that only the interrupt is triggered within a period of time.


## Working Principles

The OpenHarmony LiteOS-M CPUP records the system CPU usage on a task basis. When task switching occurs, the task start time and task switch-out or exit time are recorded. Each time when a task exits, the system accumulates the CPU time used by the task.

You can configure this function in **target_config.h**.

The OpenHarmony LiteOS-M provides the following types of CPUP information:

- System CPUP
- Task CPUP

In addition, the system provides the capability of querying the interrupt CPUP (the CPUP and timer must be enabled).

The CPUP is calculated as follows:

System CPUP = Total running time of all tasks except idle tasks/Total running time of the system

Task CPUP = Total running time of the task/Total running time of the system

Interrupt CPUP = Running time of a single interrupt/Total running time of all interrupts


## Available APIs

  **Table 1** APIs for CPUP

| Category| Description|
| -------- | -------- |
| Obtaining the system CPUP| **LOS_SysCpuUsage**: obtains the current system CPUP.<br>**LOS_HistorySysCpuUsage**: obtains the historical CPUP of the system.|
| Obtaining the task CPUP| **LOS_TaskCpuUsage**: obtains the CPUP of a task.<br>**LOS_HistoryTaskCpuUsage**: obtains the historical CPUP of a task.<br>**LOS_AllTaskCpuUsage**: obtains the CPUP of all tasks.|
| Outputting the task CPUP| **LOS_CpupUsageMonitor**: outputs the historical CPUP of a task.|
| Obtaining the interrupt CPUP| **LOS_GetAllIrqCpuUsage**: obtains the CPUP of all interrupts.|

## How to Develop

In the **kernel/liteos_m** directory, run the **make menuconfig** command and choose **Kernel > Enable Cpup** to enable CPUP.

Choose **Enable Cpup include irq** to enable interrupt CPUP.

The typical CPUP development process is as follows:

1. Call **LOS_SysCpuUsage** to obtain the system CPUP.

2. Call **LOS_HistorySysCpuUsage** to obtain the historical CPUP of the system.

3. Call **LOS_TaskCpuUsage** to obtain the CPUP of a task.
   - If the task has been created, disable interrupt, obtain the CPUP, and then enable interrupt.
   - If the task is not created, return an error code.

4. Call **LOS_HistoryTaskCpuUsage** to obtain the historical CPUP of a task.
   - If the task has been created, disable interrupt, obtain the CPUP in different modes, and then enable interrupt.
   - If the task is not created, return an error code.

5. Call **LOS_AllCpuUsage** to obtain the CPUP of all tasks.
   - If CPUP has been initialized, disable interrupt, obtain the CPUP in different modes, and then enable interrupt.
   - If CPUP is not initialized or has invalid input parameters, return an error code.


## Development Example


### Example Description

This example implements the following:

1. Create a task for the CPUP test.

2. Obtain the CPUP of the current system.

3. Obtain the historical system CPUP in different modes.

4. Obtain the CPUP of the created task.

5. Obtain the CPUP of the created task in different modes.


### Sample Code

**Prerequisites**

CPUP is enabled.<br>To enable CPUP, run **make menuconfig** in the **kernel/liteos_m** directory and choose **Kernel->Enable Cpup** to enable CPUP.

The sample code is as follows:

The sample code can be compiled and verified in **./kernel/liteos_m/testsuites/src/osTest.c**. The **ExampleCpup** function is called in **TestTaskEntry**.


```
#include "los_task.h"
#include "los_cpup.h"

#define TEST_TASK_PRIO  5
#define TASK_DELAY_TIME 100
VOID CpupTask(VOID)
{
    printf("entry cpup test example\n");
    usleep(TASK_DELAY_TIME);
    usleep(TASK_DELAY_TIME);
    printf("exit cpup test example\n");
}

UINT32 ExampleCpup(VOID)
{
    UINT32 ret;
    UINT32 cpupUse;
    UINT32 taskID;
    TSK_INIT_PARAM_S cpupTestTask = { 0 };

    cpupTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)CpupTask;
    cpupTestTask.pcName       = "TestCpupTsk";
    cpupTestTask.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    cpupTestTask.usTaskPrio   = TEST_TASK_PRIO;
    ret = LOS_TaskCreate(&taskID, &cpupTestTask);
    if(ret != LOS_OK) {
        printf("cpupTestTask create failed .\n");
        return LOS_NOK;
    }

    usleep(TASK_DELAY_TIME);

    /* Obtain the current system CPUP. */
    cpupUse = LOS_SysCpuUsage();
    printf("the current system cpu usage is: %u.%u\n",
            cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);

    /* Obtain the historical CPUP of the system. */
    cpupUse = LOS_HistorySysCpuUsage(CPUP_LESS_THAN_1S);
    printf("the history system cpu usage in all time: %u.%u\n",
           cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);

    /* Obtain the CPUP of a specified task. */
    cpupUse = LOS_TaskCpuUsage(taskID);
    printf("cpu usage of the cpupTestTask:\n TaskID: %d\n usage: %u.%u\n",
           taskID, cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);

    /* Obtain the CPUP of a specified task since the system starts. */
    cpupUse = LOS_HistoryTaskCpuUsage(taskID, CPUP_LESS_THAN_1S);
    printf("cpu usage of the cpupTestTask in all time:\n TaskID: %d\n usage: %u.%u\n",
           taskID, cpupUse / LOS_CPUP_PRECISION_MULT, cpupUse % LOS_CPUP_PRECISION_MULT);

    return LOS_OK;
}
```


### Verification

  The development is successful if the return result is as follows:

```
entry cpup test example
the current system cpu usage is: 8.2
the history system cpu usage in all time: 8.9
cpu usage of the cpupTestTask:
 TaskID: 5
 usage: 0.5
cpu usage of the cpupTestTask in all time:
 TaskID: 5
 usage: 0.5

exit cpup test example

The preceding data may vary depending on the running environment.
```
