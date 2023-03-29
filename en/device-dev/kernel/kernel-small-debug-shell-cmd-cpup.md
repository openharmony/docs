# cpup


## Command Function

This command is used to query the CPU percent (CPUP) of the system.


## Syntax

cpup [_mode_] [_taskID_]


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range|
| -------- | -------- | -------- |
| mode | Displays the CPUP of the system within the last 10 seconds by default.<br>- **0**: displays the CPUP within the last 10 seconds.<br>- **1**: displays the CPUP within the last 1 second.<br>- Other numbers: display the total CPUP since the system starts.| [0, 0xFFFFFFFF] |
| taskID | Specifies the task ID.| [0, 0xFFFFFFFF] |


## Usage Guidelines

- If no parameter is specified, the CPU usage of the system within the last 10 seconds is displayed.

- If only **mode** is specified, the CPU usage within the specified period is displayed.

- If both **mode** and **taskID** are specified, the CPU usage of the specified task within the given period is displayed.


## Example

Run **cpup 1 5**.


## Output

CPU usage of task 5 in the last one second:

```
OHOS # cpup 1 5pid 5 

CpuUsage in 1s: 0.0
```
