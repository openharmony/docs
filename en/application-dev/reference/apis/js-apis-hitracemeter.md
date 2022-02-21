# Performance Tracing

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import hiTraceMeter from '@ohos.hiTraceMeter';
```


## System Capabilities

SystemCapability.HiviewDFX.HiTrace


## hiTraceMeter.startTrace

startTrace(name: string, taskId: number, expectedTime?: number): void

Starts a trace task. **expectedTime** is an optional parameter, which specifies the expected duration of the trace.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | name | string | Yes| Name of the trace task to start.|
  | taskId | number | Yes| Task ID.|
  | expectedTime | number | No| Expected duration of the trace, in ms.|

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
  > If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different task IDs must be specified in **startTrace**. If the trace tasks with the same name are not performed at the same time, the same task ID can be used. For details, see the **hiTraceMeter.finishTrace** example.

- Example
  ```
  hiTraceMeter.startTrace("myTestFunc", 1);
  hiTraceMeter.startTrace("myTestFunc", 1, 5); // The expected duration of the trace task is 5 ms.
  ```


## hiTraceMeter.finishTrace

finishTrace(name: string, taskId: number): void

Stops a trace task.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | name | string | Yes| Name of the trace task to start.|
  | taskId | number | Yes| Task ID.|

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
  > To stop a trace task, the values of name and task ID in **finishTrace** must be the same as those in **startTrace**.

- Example
  ```
  hiTraceMeter.finishTrace("myTestFunc", 1);
  ```

  ```
  // Start track tasks with the same name concurrently.
  hiTraceMeter.startTrace("myTestFunc", 1);
  // Service flow
  hiTraceMeter.startTrace("myTestFunc", 2);  // The second trace task starts while the first task is still running. The first and second tasks have the same name but different task IDs.
  // Service flow
  hiTraceMeter.finishTrace("myTestFunc", 1);
  // Service flow
  hiTraceMeter.finishTrace("myTestFunc", 2);
  ```

  ```
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

traceByValue(name: string, value: number): void

Traces the value changes of a variable.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | name | string | Yes| Name of the variable.|
  | value | number | Yes| Value of the variable.|

- Example
  ```
  let traceCount = 3;
  hiTraceMeter.traceByValue("myTestCount", traceCount);
  traceCount = 4;
  hiTraceMeter.traceByValue("myTestCount", traceCount);
  // Service flow
  ```
