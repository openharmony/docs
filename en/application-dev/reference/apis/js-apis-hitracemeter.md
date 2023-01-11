# @ohos.hiTraceMeter (Performance Tracing)

The **hiTraceMeter** module provides the functions of tracing service processes and monitoring the system performance. It provides the data needed for hiTraceMeter to carry out performance analysis.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import hiTraceMeter from '@ohos.hiTraceMeter';
```


## hiTraceMeter.startTrace

startTrace(name: string, taskId: number): void

Starts a trace task.

If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different task IDs must be specified in **startTrace**.

If the trace tasks with the same name are not performed at the same time, the same taskId can be used. For a specific example, refer to an example in [hiTraceMeter.finishTrace](#hitracemeterfinishtrace).

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name| Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| name | string | Yes | Name of the trace task to start. |
| taskId | number | Yes| Task ID. |

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

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the trace task to start. |
| taskId | number | Yes| Task ID. |

**Example**

```js
hiTraceMeter.finishTrace("myTestFunc", 1);
```

```js
// Start track tasks with the same name concurrently.
hiTraceMeter.startTrace("myTestFunc", 1);
// Service flow
hiTraceMeter.startTrace("myTestFunc", 2);  // The second trace task starts while the first task is still running. The first and second tasks have the same name but different task IDs.
// Service flow
hiTraceMeter.finishTrace("myTestFunc", 1);
// Service flow
hiTraceMeter.finishTrace("myTestFunc", 2);
```

```js
// Start track tasks with the same name at different times.
hiTraceMeter.startTrace("myTestFunc", 1);
// Service flow
hiTraceMeter.finishTrace("myTestFunc", 1);  // The first trace task ends.
// Service flow
hiTraceMeter.startTrace("myTestFunc", 1);   // The second trace task starts after the first task ends. The two tasks have the same name and task ID. 
// Service flow
hiTraceMeter.finishTrace("myTestFunc", 1);
```


## hiTraceMeter.traceByValue

traceByValue(name: string, count: number): void

Traces the value changes of a variable.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes | Name of the variable. |
| count | number | Yes | Value of the variable. |

**Example**
```js
let traceCount = 3;
hiTraceMeter.traceByValue("myTestCount", traceCount);
traceCount = 4;
hiTraceMeter.traceByValue("myTestCount", traceCount);
// Service flow
```
