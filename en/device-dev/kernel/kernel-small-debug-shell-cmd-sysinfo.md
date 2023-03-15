# systeminfo


## Command Function

This command is used to display the resource usage of the current operating system, including tasks, semaphores, mutexes, queues, and software timers.


## Syntax

systeminfo


## Parameters

None.


## Usage Guidelines

None.


## Example

Run **systeminfo**.


## Output

Usage of system resources:

```
OHOS:/$ systeminfo
   Module    Used      Total     Enabled
--------------------------------------------
   Task      96        256       YES
   Sem       435       1024      YES
   Queue     13        1024      YES
   SwTmr     20        1024      YES
```

**Table 1** Output description

| Parameter   | Description          |
| ------- | -------------- |
| Module  | Module name.    |
| Used    | Used resources.  |
| Total   | Total resources.  |
| Enabled | Whether the module is enabled.|
| Task    | Task.        |
| Sem     | Semaphore.      |
| Queue   | Using queues.        |
| SwTmr   | Software timer.      |
