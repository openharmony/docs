# @ohos.hiTraceMeter (HiTraceMeter)

The **HiTraceMeter** module provides the functions of tracing service processes and monitoring the system performance. It provides the data needed for HiTraceMeter to carry out performance analysis.
For details about the development process, see [Development of Performance Tracing](../../dfx/hitracemeter-guidelines-arkts.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import { hiTraceMeter } from '@kit.PerformanceAnalysisKit';
```


## hiTraceMeter.startTrace

startTrace(name: string, taskId: number): void

Marks the start of a trace task.

If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different task IDs must be specified in **OH_HiTrace_StartTrace**.

If the trace tasks with the same name are not performed at the same time, the same taskId can be used. For a specific example, refer to an example in [hiTraceMeter.finishTrace](#hitracemeterfinishtrace).

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| name | string | Yes | Name of the trace task to start. |
| taskId | number | Yes | Task ID. |

**Example**

```js
hiTraceMeter.startTrace("myTestFunc", 1);
```


## hiTraceMeter.finishTrace

finishTrace(name: string, taskId: number): void

Stops a trace task.

To stop a trace task, the values of name and task ID in **finishTrace** must be the same as those in [startTrace](#hitracemeterstarttrace).

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| name | string | Yes | Name of the trace task to start. |
| taskId | number | Yes | Task ID. |

**Example**

```js
hiTraceMeter.finishTrace("myTestFunc", 1);
```

```js
// Start trace tasks with the same name concurrently.
hiTraceMeter.startTrace("myTestFunc", 1);
// Service flow... 
hiTraceMeter.startTrace("myTestFunc", 2);  // Start the second trace task with the same name while the first task is still running. The tasks are running concurrently and therefore their taskId must be different.
// Service flow... 
hiTraceMeter.finishTrace("myTestFunc", 1);
// Service flow... 
hiTraceMeter.finishTrace("myTestFunc", 2);
```

```js
// Start trace tasks with the same name in serial mode.
hiTraceMeter.startTrace("myTestFunc", 1);
// Service flow... 
hiTraceMeter.finishTrace("myTestFunc", 1);  // End the first trace task.
// Service flow... 
hiTraceMeter.startTrace("myTestFunc", 1);   // Start the second trace task with the same name in serial mode.
// Service flow... 
hiTraceMeter.finishTrace("myTestFunc", 1);
```


## hiTraceMeter.traceByValue

traceByValue(name: string, count: number): void

Marks the value changes of a numeric variable in a trace task.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| name | string | Yes | Name of the variable. |
| count | number | Yes | Value of the variable. |

**Example**
```js
let traceCount = 3;
hiTraceMeter.traceByValue("myTestCount", traceCount);
traceCount = 4;
hiTraceMeter.traceByValue("myTestCount", traceCount);
// Service flow...
```
