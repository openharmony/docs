# Basic Concepts<a name="EN-US_TOPIC_0000001123948105"></a>

-   [Working Principles](#section96644177124)

The central processing unit percent \(CPUP\) includes the system CPUP and task CPUP.

The system CPUP is the CPU usage of the system within a period of time. It reflects the CPU load and the system running status \(idle or busy\) in the given period of time. The valid range of the system CPUP is 0 to 100 in percentage. The precision can be adjusted through configuration. The value  **100**  indicates that the system runs with full load.

Task CPUP refers to the CPU usage of a single task. It reflects the task status, busy or idle, in a period of time. The valid range of task CPUP is 0 to 100 in percentage. The precision can be adjusted through configuration. The value  **100**  indicates that the task is being executed for the given period of time.

With the system CPUP, you can determine whether the current system load exceeds the designed specifications.

With the CPUP of each task, you can determine whether the CPU usage of each task meets expectations of the design.

## Working Principles<a name="section96644177124"></a>

The OpenHarmony LiteOS-M CPUP records the system CPU usage on a task basis. When task switching occurs, the task start time and task switch-out or exit time are recorded. Each time when a task exits, the system accumulates the CPU time used by the task.

You can configure this function in  **target\_config.h**.

The OpenHarmony LiteOS-M provides the following types of CPUP information:

-   System CPUP
-   Task CPUP

The CPUP is calculated as follows:

System CPUP = Total running time of all tasks except idle tasks/Total running time of the system

Task CPUP = Total running time of the task/Total running time of the system

