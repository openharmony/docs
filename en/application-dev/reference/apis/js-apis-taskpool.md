# @ohos.taskpool (Using the Task Pool)

The task pool provides a multi-thread running environment for applications. It helps reduce resource consumption and improve system performance. It also frees you from caring about the lifecycle of thread instances. You can use the **TaskPool** APIs to create background tasks and perform operations on them, for example, executing or canceling a task. Theoretically, you can create an unlimited number of tasks, but this is not recommended for memory considerations. In addition, you are not advised performing blocking operations in a task, especially indefinite blocking. Long-time blocking operations occupy worker threads and may block other task scheduling, adversely affecting your application performance.

You can determine the execution sequence of tasks with the same priority. They are executed in the same sequence as you call the task execution APIs. The default task priority is **MEDIUM**. (The task priority mechanism is not supported yet.)

If the number of tasks to be executed is greater than the number of worker threads in the task pool, the task pool scales out based on load balancing to minimize the waiting duration. Similarly, when the number of tasks to be executed falls below the number of worker threads, the task pool scales in to reduce the number of worker threads. (The load balancing mechanism is not supported yet.)

The **TaskPool** APIs return error codes in numeric format. For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

> **NOTE**<br>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import taskpool from '@ohos.taskpool';
```

## Priority

Enumerates the priorities available for created tasks. (This enum is not supported yet.)

**System capability**: SystemCapability.Utils.Lang

| Name| Value| Description|
| -------- | -------- | -------- |
| HIGH   | 0    | The task has a high priority.|
| MEDIUM | 1 | The task has a medium priority.|
| LOW | 2 | The task has a low priority.|

## Task

Implements a task. Before using any of the following APIs, you must create a **Task** instance.

### constructor

constructor(func: Function, ...args: unknown[])

A constructor used to create a **Task** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type     | Mandatory| Description                                                                 |
| ------ | --------- | ---- | -------------------------------------------------------------------- |
| func   | Function  | Yes  | Function to be passed in for task execution. For details about the supported return value types of the function, see [Sequenceable Data Types](#sequenceable-data-types).  |
| args   | unknown[] | No  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 10200014 | The function is not mark as concurrent. |

**Example**

```js
function func(args) {
    "use concurrent"
    console.log("func: " + args);
    return args;
}
let task = new taskpool.Task(func, "this is my first Task");
```

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name     | Type     | Readable| Writable| Description                                                                      |
| --------- | --------- | ---- | ---- | ------------------------------------------------------------------------- |
| function  | Function  | Yes  | Yes  | Function to be passed in during task creation. For details about the supported return value types of the function, see [Sequenceable Data Types](#sequenceable-data-types).  |
| arguments | unknown[] | Yes  | Yes  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|

## taskpool.execute

execute(func: Function, ...args: unknown[]): Promise\<unknown>

Executes a task in the task pool. You must pass in a function and arguments to execute the task, and the task executed in this mode cannot be canceled.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type     | Mandatory| Description                                                                  |
| ------ | --------- | ---- | ---------------------------------------------------------------------- |
| func   | Function  | Yes  | Function used to execute the task. For details about the supported return value types of the function, see [Sequenceable Data Types](#sequenceable-data-types).    |
| args   | unknown[] | No  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|

**Return value**

| Type             | Description                                |
| ----------------- | ------------------------------------ |
| Promise\<unknown> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 10200003 | Worker initialization failure.            |
| 10200006 | Serializing an uncaught exception failed. |
| 10200014 | The function is not mark as concurrent.   |

**Example**

```js
function func(args) {
    "use concurrent"
    console.log("func: " + args);
    return args;
}

let value = taskpool.execute(func, 100);
```

## taskpool.execute

execute(task: Task, priority?: Priority): Promise\<unknown>

Executes a task in the task pool. You must pass in a created task, and the task executed in this mode can be canceled.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                 | Mandatory| Description                                |
| -------- | --------------------- | ---- | ------------------------------------ |
| task     | [Task](#task)         | Yes  | Task to be executed.          |
| priority | [Priority](#priority) | No  | Priority of the task (not supported yet).|

**Return value**

| Type            | Description                          |
| ---------------- | ------------------------------ |
| Promise\<unknown> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 10200003 | Worker initialization failure.            |
| 10200006 | Serializing an uncaught exception failed. |
| 10200014 | The function is not mark as concurrent.   |

**Example**

```js
function func(args) {
    "use concurrent"
    console.log("func: " + args);
    return args;
}
let task = new taskpool.Task(func, "this is my first Task");
let value = taskpool.execute(task);
```

## taskpool.cancel

cancel(task: Task): void

Cancels a task in the task pool.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| task   | [Task](#task) | Yes  | Task to cancel.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message                 |
| -------- | ------------------------- |
| 10200015 | If the task is not exist. |
| 10200016 | If the task is running.   |

**Example**

```js
function func(args) {
    "use concurrent"
    console.log("func: " + args);
    return args;
}
let task = new taskpool.Task(func, "this is first Task");
let value = taskpool.execute(task);
taskpool.cancel(task);
```

## Additional Information

### Sequenceable Data Types
The following sequenceable data types are supported: All Primitive Type (excluding symbol), Date, String, RegExp, Array, Map, Set, Object, ArrayBuffer, and TypedArray.

### Precautions
A task in the task pool can reference only variables passed in by input parameters or imported variables. It does not support closure variables.

```js
// 1. Reference a variable passed in by the input parameter.
function func(args) {
    "use concurrent"
    console.log("func: " + args);
    return args;
}

let task = new taskpool.Task(func, "create task, then execute");
let val1 = taskpool.execute(task);

let val2 = taskpool.execute(func, "execute task by func");
```

```js
// 2. Reference an imported variable.

// b.ts
export var c = 2000;

// a.ts
import { c } from './b'

function test(a) {
    "use concurrent"
    console.log(a);
    console.log(c);
    return a;
}

let task = new taskpool.Task(test, "create task, then execute");
let val1 = taskpool.execute(task);

let val2 = taskpool.execute(test, "execute task by func");
```
