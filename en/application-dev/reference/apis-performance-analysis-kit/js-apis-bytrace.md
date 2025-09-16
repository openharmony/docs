# @ohos.bytrace (Performance Tracing)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--SE: @MontSaintMichel-->
<!--TSE: @gcw_KuLfPSbe-->

The **bytrace** module implements performance tracing for processes.

> **NOTE**
> - The APIs of this module are no longer maintained since API version 8. You are advised to use [`@ohos.hiTraceMeter`](js-apis-hitracemeter.md).
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { bytrace } from '@kit.PerformanceAnalysisKit';
```

## bytrace.startTrace

startTrace(name: string, taskId: number, expectedTime?: number): void

Marks the start of a timeslice trace task.

> **NOTE**
> If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different task IDs must be specified in **startTrace**. If the trace tasks with the same name are not performed at the same time, the same task ID can be used. For details, see the bytrace.finishTrace example.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters:**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of a timeslice trace task.|
| taskId | number | Yes| ID of a timeslice trace task.|
| expectedTime | number | No| Expected duration of the trace, in ms. Optional. By default, this parameter is left blank.|


**Example**

```js
bytrace.startTrace("myTestFunc", 1);
bytrace.startTrace("myTestFunc", 1, 5); // The expected duration of the trace is 5 ms.
```

## bytrace.finishTrace

finishTrace(name: string, taskId: number): void

Marks the end of a timeslice trace task.

> **NOTE**<br>
> To stop a trace task, the values of name and task ID in **finishTrace** must be the same as those in **startTrace**.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters:**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of a timeslice trace task.|
| taskId | number | Yes| ID of a timeslice trace task.|


**Example**

```js
bytrace.finishTrace("myTestFunc", 1);
```

```
// Start trace tasks with the same name concurrently.
bytrace.startTrace("myTestFunc", 1);
// Service flow...
bytrace.startTrace("myTestFunc", 2);  // The second trace task starts while the first task is still running. The first and second tasks have the same name but different task IDs.
// Service flow...
bytrace.finishTrace("myTestFunc", 1);
// Service flow...
bytrace.finishTrace("myTestFunc", 2);
```

```
// Start trace tasks with the same name in serial mode.
bytrace.startTrace("myTestFunc", 1);
// Service flow...
bytrace.finishTrace("myTestFunc", 1);  // The first trace task ends.
// Service flow...
bytrace.startTrace("myTestFunc", 1);   // The second trace task starts after the first task ends. The two tasks have the same name and task ID.
// Service flow...
bytrace.finishTrace("myTestFunc", 1);
```

## bytrace.traceByValue

traceByValue(name: string, count: number): void

Defines a numeric variable that indicates the number of timeslice trace tasks.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters:**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the numeric variable.|
| count | number | Yes| Value of the numeric variable.|

**Example**

```js
let traceCount = 3;
bytrace.traceByValue("myTestCount", traceCount);
traceCount = 4;
bytrace.traceByValue("myTestCount", traceCount);
// Service flow
```
