# Performance Tracing

> **NOTE**
> - The APIs of this module are no longer maintained since API version 8. It is recommended that you use the APIs of [hiTraceMeter](js-apis-hitracemeter.md) instead.
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import bytrace from '@ohos.bytrace';
```



## bytrace.startTrace

startTrace(name: string, taskId: number, expectedTime?: number): void

Marks the start of a timeslice trace task.

**System capability**: SystemCapability.Developtools.Bytrace

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of a timeslice trace task.|
| taskId | number | Yes| ID of a timeslice trace task.|
| expectedTime | number | No| Expected duration of the trace, in ms.|

> **NOTE**
> 
> If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different task IDs must be specified in **startTrace**. If the trace tasks with the same name are not performed at the same time, the same taskId can be used. For details, see the bytrace.finishTrace example.

**Example**

```
bytrace.startTrace("myTestFunc", 1);
bytrace.startTrace("myTestFunc", 1, 5); // The expected duration of the trace is 5 ms.
```


## bytrace.finishTrace

finishTrace(name: string, taskId: number): void

Marks the end of a timeslice trace task.

**System capability**: SystemCapability.Developtools.Bytrace

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of a timeslice trace task.|
| taskId | number | Yes| ID of a timeslice trace task.|

> **NOTE**
> 
> To stop a trace task, the values of name and task ID in **finishTrace** must be the same as those in **startTrace**.

**Example**

```
bytrace.finishTrace("myTestFunc", 1);
```

```
// Start track tasks with the same name concurrently.
bytrace.startTrace("myTestFunc", 1);
// Service flow
bytrace.startTrace("myTestFunc", 2); // The second trace task starts while the first task is still running. The first and second tasks have the same name but different task IDs.
// Service flow
bytrace.finishTrace("myTestFunc", 1);
// Service flow
bytrace.finishTrace("myTestFunc", 2);
```

```
// Start track tasks with the same name at different times.
bytrace.startTrace("myTestFunc", 1);
// Service flow
bytrace.finishTrace("myTestFunc", 1); // The first trace task ends.
// Service flow
bytrace.startTrace("myTestFunc", 1); // The second trace task starts after the first task ends. The two tasks have the same name and task ID. 
// Service flow
bytrace.finishTrace("myTestFunc", 1);
```


## bytrace.traceByValue

traceByValue(name: string, count: number): void

Defines the variable that indicates the number of timeslice trace tasks.

**System capability**: SystemCapability.Developtools.Bytrace

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the variable.|
| count | number | Yes| Value of the variable.|

**Example**

```
let traceCount = 3;
bytrace.traceByValue("myTestCount", traceCount);
traceCount = 4;
bytrace.traceByValue("myTestCount", traceCount);
// Service flow
```
