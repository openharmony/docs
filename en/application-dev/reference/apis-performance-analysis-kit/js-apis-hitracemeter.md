# @ohos.hiTraceMeter (Performance Tracing)

The **HiTraceMeter** module provides the functions of tracing service processes and monitoring the system performance. It provides the data needed for hiTraceMeter to carry out performance analysis.
For details about the development process, see [Development of Performance Tracing](../../dfx/hitracemeter-guidelines-arkts.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> You are advised to use trace APIs of API version 18. The [startTrace](#hitracemeterstarttrace), [finishTrace](#hitracemeterfinishtrace) and [traceByValue](#hitracemetertracebyvalue) will be gradually deprecated.
>
> The trace output level cannot be specified in the [startTrace](#hitracemeterstarttrace), [finishTrace](#hitracemeterfinishtrace) and [traceByValue](#hitracemetertracebyvalue) APIs. By default, the trace output level is **COMMERCIAL**.

## Modules to Import

```js
import { hiTraceMeter } from '@kit.PerformanceAnalysisKit';
```

## hiTraceMeter.startTrace

startTrace(name: string, taskId: number): void

Starts an asynchronous trace.

If multiple traces with the same name need to be performed at the same time or a trace needs to be performed multiple times concurrently, different task IDs must be specified in **startTrace**.

If the trace tasks with the same name are not performed at the same time, the same taskId can be used. For a specific example, see [finishTrace](#hitracemeterfinishtrace).

Since API version 18, you are advised to use [startAsyncTrace](#hitracemeterstartasynctrace18), which must be used together with [finishAsyncTrace](#hitracemeterfinishasynctrace18). In this way, you can specify the trace level and category.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| name   | string | Yes  | Name of the trace to start.|
| taskId | number | Yes  | Task ID.          |

**Example**

```js
hiTraceMeter.startTrace("myTestFunc", 1);
```

## hiTraceMeter.finishTrace

finishTrace(name: string, taskId: number): void

Stops an asynchronous trace.

To stop a trace, the values of name and task ID in **finishTrace** must be the same as those in [startTrace](#hitracemeterstarttrace).

Since API version 18, you are advised to use [finishAsyncTrace](#hitracemeterfinishasynctrace18) with [startAsyncTrace](#hitracemeterstartasynctrace18).

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| name   | string | Yes  | Name of the trace to stop.|
| taskId | number | Yes  | Task ID.          |

**Example**

```js
hiTraceMeter.finishTrace("myTestFunc", 1);
```

```js
// Start trace tasks with the same name concurrently.
hiTraceMeter.startTrace("myTestFunc", 1);
// Service flow...
hiTraceMeter.startTrace("myTestFunc", 2);  // Start the second trace with the same name while the first task is still running. The tasks are running concurrently and therefore their taskId must be different.
// Service flow...
hiTraceMeter.finishTrace("myTestFunc", 1);
// Service flow...
hiTraceMeter.finishTrace("myTestFunc", 2);
```

```js
// Start trace tasks with the same name in serial mode.
hiTraceMeter.startTrace("myTestFunc", 1);
// Service flow...
hiTraceMeter.finishTrace("myTestFunc", 1);  // End the first trace.
// Service flow...
hiTraceMeter.startTrace("myTestFunc", 1);   // Start the second trace with the same name in serial mode.
// Service flow...
hiTraceMeter.finishTrace("myTestFunc", 1);
```

## hiTraceMeter.traceByValue

traceByValue(name: string, count: number): void

Traces the value changes of an integer variable.

Since API version 18, you are advised to use the [traceByValue<sup>18+</sup>](#hitracemetertracebyvalue18) API to specify the trace output level.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| name   | string | Yes  | Name of the integer variable to trace.|
| count  | number | Yes  | Value of an integer variable.        |

**Example**

```js
let traceCount = 3;
hiTraceMeter.traceByValue("myTestCount", traceCount);
traceCount = 4;
hiTraceMeter.traceByValue("myTestCount", traceCount);
// Service flow...
```

## HiTraceOutputLevel<sup>18+</sup>

Enumerates trace output levels.

The trace output level lower than the threshold does not take effect. The log version threshold is **INFO**, and the nolog version threshold is **COMMERCIAL**.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.HiviewDFX.HiTrace

| Level      | Value  | Description                                   |
| ---------- | ---- | --------------------------------------- |
| DEBUG      | 0    | Level used only for debugging, which has the lowest priority.     |
| INFO       | 1    | Level for the log version.                |
| CRITICAL   | 2    | Level for the log version, which has a higher priority than **INFO**.|
| COMMERCIAL | 3    | Level for the nolog version, which has the highest priority.  |
| MAX        | 3    | Maximum trace output level: **COMMERCIAL**.   |

## hiTraceMeter.startAsyncTrace<sup>18+</sup>

startAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number, customCategory: string, customArgs?: string): void

Starts an asynchronous trace with the trace output level specified.

If multiple trace tasks with the same name need to be performed at the same time or a trace needs to be performed multiple times concurrently, different task IDs must be specified in **startAsyncTrace**.

If the trace tasks with the same name are not performed at the same time, the same taskId can be used. For details, see [finishAsyncTrace](#hitracemeterfinishasynctrace18).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name        | Type                                       | Mandatory| Description                                                        |
| -------------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| level          | [HiTraceOutputLevel](#hitraceoutputlevel18) | Yes  | Trace output level.                                              |
| name           | string                                      | Yes  | Name of the trace to start. The value contains a maximum of 320 characters. If the value length exceeds this limit, excess content will be truncated.|
| taskId         | number                                      | Yes  | Task ID.                                                    |
| customCategory | string                                      | Yes  | Custom category name, which is used to collect asynchronous trace data of the same type. The value contains a maximum of 64 characters. If the value length exceeds this limit, excess content will be truncated.|
| customArgs     | string                                      | No  | Custom key-value pair. The format is **key=value**. Use commas (,) to separate multiple key-value pairs.<br>If this parameter is not passed in, an empty string is passed in.<br>A maximum of 512 characters are output. If the **name** and **customCategory** parameters occupy too many characters, the value of **customArgs** may be truncated.|

**Example**

```js
// If the customCategory parameter is not required, pass in an empty string.
// If the customArgs parameter is not required, do not pass in this parameter or pass in an empty string.
const COMMERCIAL = hiTraceMeter.HiTraceOutPutLevel.COMMERCIAL;
hiTraceMeter.startAsyncTrace(COMMERCIAL, "myTestFunc", 1, "", "");
hiTraceMeter.startAsyncTrace(COMMERCIAL, "myTestFunc", 2, "");
// Use commas (,) to separate multiple key-value pairs.
hiTraceMeter.startAsyncTrace(COMMERCIAL, "myTestFunc", 3, "categoryTest", "key1=value");
hiTraceMeter.startAsyncTrace(COMMERCIAL, "myTestFunc", 4, "categoryTest", "key1=value1,key2=value2");
```

## hiTraceMeter.finishAsyncTrace<sup>18+</sup>

finishAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number): void

Stops an asynchronous trace with the trace output level specified.

The **level**, **name**, and **taskId** used in **finishAsyncTrace** must be the same as those of [startAsyncTrace](#hitracemeterstartasynctrace18).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name| Type                                       | Mandatory| Description                                                        |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| level  | [HiTraceOutputLevel](#hitraceoutputlevel18) | Yes  | Trace output level.                                              |
| name   | string                                      | Yes  | Name of the trace to stop. The value contains a maximum of 320 characters. If the value length exceeds this limit, excess content will be truncated.|
| taskId | number                                      | Yes  | Task ID.                                                    |

**Example**

```js
const COMMERCIAL = hiTraceMeter.HiTraceOutPutLevel.COMMERCIAL;
hiTraceMeter.finishAsyncTrace(COMMERCIAL, "myTestFunc", 1);
```

```js
const COMMERCIAL = hiTraceMeter.HiTraceOutPutLevel.COMMERCIAL;
// Start trace tasks with the same name concurrently.
// Start the first trace.
hiTraceMeter.startAsyncTrace(COMMERCIAL, "myTestFunc", 1, "categoryTest", "key=value");
// Service flow...
// Start the second trace with the same name while the first trace is still running. The traces are running concurrently and therefore their taskId must be different.
hiTraceMeter.startAsyncTrace(COMMERCIAL, "myTestFunc", 2, "categoryTest", "key=value");
// Service flow...
// Stop the first trace.
hiTraceMeter.finishAsyncTrace(COMMERCIAL, "myTestFunc", 1);
// Service flow...
// Stop the second trace.
hiTraceMeter.finishAsyncTrace(COMMERCIAL, "myTestFunc", 2);
```

```js
const COMMERCIAL = hiTraceMeter.HiTraceOutPutLevel.COMMERCIAL;
// Start trace tasks with the same name in serial mode.
// Start the first trace.
hiTraceMeter.startTrace(COMMERCIAL, "myTestFunc", 1, "categoryTest", "key=value");
// Service flow...
// Stop the first trace.
hiTraceMeter.finishAsyncTrace(COMMERCIAL, "myTestFunc", 1);
// Service flow...
// Start the second trace with the same name. The traces with the same name are executed in serial mode.
hiTraceMeter.startTrace(COMMERCIAL, "myTestFunc", 1, "categoryTest", "key=value");
// Service flow...
// Stop the second trace with the same name.
hiTraceMeter.finishAsyncTrace(COMMERCIAL, "myTestFunc", 1);
```

## hiTraceMeter.startSyncTrace<sup>18+</sup>

startSyncTrace(level: HiTraceOutputLevel, name: string, customArgs?: string): void

Starts a synchronous trace with the trace output level specified. For details, see [finishSyncTrace](#hitracemeterfinishsynctrace18).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                        |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| level      | [HiTraceOutputLevel](#hitraceoutputlevel18) | Yes  | Trace output level.                                              |
| name       | string                                      | Yes  | Name of the trace to start. The value contains a maximum of 320 characters. If the value length exceeds this limit, excess content will be truncated.|
| customArgs | string                                      | No  | Custom key-value pair. The format is **key=value**. Use commas (,) to separate multiple key-value pairs.<br>If this parameter is not passed in, an empty string is passed in.<br>A maximum of 512 characters are output. If the **name** parameter occupies too many characters, the value of **customArgs** may be truncated.|

**Example**

```js
const COMMERCIAL = hiTraceMeter.HiTraceOutPutLevel.COMMERCIAL;
// If the customArgs parameter is not required, do not pass in this parameter or pass in an empty string.
hiTraceMeter.startSyncTrace(COMMERCIAL, "myTestFunc");
hiTraceMeter.startSyncTrace(COMMERCIAL, "myTestFunc", "");
// Use commas (,) to separate multiple key-value pairs.
hiTraceMeter.startSyncTrace(COMMERCIAL, "myTestFunc", "key=value");
hiTraceMeter.startSyncTrace(COMMERCIAL, "myTestFunc", "key1=value1,key2=value2");
```

## hiTraceMeter.finishSyncTrace<sup>18+</sup>

finishSyncTrace(level: HiTraceOutputLevel): void

Stops a synchronous trace with the trace output level specified.

The **level** used in **finishSyncTrace** must be the same as that of [startSyncTrace](#hitracemeterstartsynctrace18).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name| Type                                       | Mandatory| Description          |
| ------ | ------------------------------------------- | ---- | -------------- |
| level  | [HiTraceOutputLevel](#hitraceoutputlevel18) | Yes  | Trace output level.|

**Example**

```js
const COMMERCIAL = hiTraceMeter.HiTraceOutPutLevel.COMMERCIAL;
hiTraceMeter.finishSyncTrace(COMMERCIAL);
```

```js
const COMMERCIAL = hiTraceMeter.HiTraceOutPutLevel.COMMERCIAL;
// The startSyncTrace and finishSyncTrace APIs can be nested and they matched each other based on proximity.
// Start the first trace.
hiTraceMeter.startSyncTrace(COMMERCIAL, "myTestFunc1", "key=value");
// Service flow...
// Start the second trace.
hiTraceMeter.startSyncTrace(COMMERCIAL, "myTestFunc2", "key=value");
// Service flow...
// Stop the second trace.
hiTraceMeter.finishSyncTrace(COMMERCIAL);
// Service flow...
// Stop the first trace.
hiTraceMeter.finishSyncTrace(COMMERCIAL);
```

## hiTraceMeter.traceByValue<sup>18+</sup>

traceByValue(level: HiTraceOutputLevel, name: string, count: number): void

Traces an integer with the trace output level specified. **name** and **count** are used to identify the name and value of an integer variable to be traced.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name| Type                                       | Mandatory| Description                                                        |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| level  | [HiTraceOutputLevel](#hitraceoutputlevel18) | Yes  | Trace output level.                                              |
| name   | string                                      | Yes  | Name of the integer variable to trace. The value contains a maximum of 320 characters. If the value length exceeds this limit, excess content will be truncated.|
| count  | number                                      | Yes  | Value of an integer variable.                                              |

**Example**

```js
const COMMERCIAL = hiTraceMeter.HiTraceOutPutLevel.COMMERCIAL;
let traceCount = 3;
hiTraceMeter.traceByValue(COMMERCIAL, "myTestCount", traceCount);
traceCount = 4;
hiTraceMeter.traceByValue(COMMERCIAL, "myTestCount", traceCount);
// Service flow...
```

## hiTraceMeter.isTraceEnabled<sup>18+</sup>

isTraceEnabled(): boolean

Checks whether application trace capture is enabled.

You can use [HiTrace](../../dfx/hitrace.md) commands to enable or disable trace capture.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Returns**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the application trace capture is enabled and the HiTraceMeter performance tracing takes effect;<br>returns **false** otherwise.|

**Example**

```js
if (hiTraceMeter.isTraceEnabled()) {
    // Service flow...
} else {
    // Service flow...
}
```
