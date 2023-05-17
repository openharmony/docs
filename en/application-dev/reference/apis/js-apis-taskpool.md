# @ohos.taskpool (Using the Task Pool)

The task pool provides a multi-thread running environment for applications. It helps reduce resource consumption and improve system performance. It also frees you from caring about the lifecycle of thread instances. You can use the **TaskPool** APIs to create background tasks and perform operations on them, for example, executing or canceling a task. Theoretically, you can create an unlimited number of tasks, but this is not recommended for memory considerations. In addition, you are not advised performing blocking operations in a task, especially indefinite blocking. Long-time blocking operations occupy worker threads and may block other task scheduling, adversely affecting your application performance.

You can determine the execution sequence of tasks with the same priority. They are executed in the same sequence as you call the task execution APIs. The default task priority is **MEDIUM**. (The task priority mechanism is not supported yet.)

If the number of tasks to be executed is greater than the number of worker threads in the task pool, the task pool scales out based on load balancing to minimize the waiting duration. Similarly, when the number of tasks to be executed falls below the number of worker threads, the task pool scales in to reduce the number of worker threads. (The load balancing mechanism is not supported yet.)

The **TaskPool** APIs return error codes in numeric format. For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

> **NOTE**<br>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
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

```ts
@Concurrent
function func(args) {
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

```ts
@Concurrent
function func(args) {
    console.log("func: " + args);
    return args;
}

async function taskpoolTest() {
  let value = await taskpool.execute(func, 100);
  console.log("taskpool result: " + value);
}

taskpoolTest();
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

```ts
@Concurrent
function func(args) {
    console.log("func: " + args);
    return args;
}

async function taskpoolTest() {
  let task = new taskpool.Task(func, 100);
  let value = await taskpool.execute(task);
  console.log("taskpool result: " + value);
}

taskpoolTest();
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

```ts
@Concurrent
function func(args) {
    console.log("func: " + args);
    return args;
}

async function taskpoolTest() {
  let task = new taskpool.Task(func, 100);
  let value = await taskpool.execute(task);
  try {
    taskpool.cancel(task);
  } catch (e) {
    console.log("taskpool.cancel occur error:" + e);
  }
}

taskpoolTest();
```

## Additional Information

### Sequenceable Data Types
The following sequenceable data types are supported: All Primitive Type (excluding symbol), Date, String, RegExp, Array, Map, Set, Object, ArrayBuffer, and TypedArray.

### Precautions
- The task pool APIs can be used only in the module with **compileMode** set to **esmodule** in the stage model. To check the **compileMode** setting of a module, open the **build-profile.json5** file of the module and check for **"compileMode": "esmodule"** under **buildOption**.
- A task in the task pool can reference only variables passed in by input parameters or imported variables, rather than closure variables. The decorator **@Concurrent** is used to intercept unsupported variables.
- A task in the task pool supports only common functions or async functions, rather than class member functions or anonymous functions. The decorator **@Concurrent** is used to intercept unsupported functions.
- The decorator **@Concurrent** can be used only in the .ets file. To create a task in the task pool in the .ts file, use the statement **use concurrent**.

### Using the Task Pool in Simple Mode

**Example 1**

```ts
// Common functions are supported, and variables passed in by input parameters are also supported.
@Concurrent
function func(args) {
    console.log("func: " + args);
    return args;
}

async function taskpoolTest() {
  // taskpool.execute(task)
  let task = new taskpool.Task(func, "create task, then execute");
  let val1 = await taskpool.execute(task);
  console.log("taskpool.execute(task) result: " + val1);

  // taskpool.execute(function)
  let val2 = await taskpool.execute(func, "execute task by func");
  console.log("taskpool.execute(function) result: " + val2);
}

taskpoolTest();
```

**Example 2**

```ts
// b.ets
export var c = 2000;
```
```ts
// Reference an imported variable.
// a.ets (in the same directory as b.ets)
import { c } from "./b";

@Concurrent
function test(a) {
    console.log(a);
    console.log(c);
    return a;
}

async function taskpoolTest() {
  // taskpool.execute(task)
  let task = new taskpool.Task(test, "create task, then execute");
  let val1 = await taskpool.execute(task);
  console.log("taskpool.execute(task) result: " + val1);

  // taskpool.execute(function)
  let val2 = await taskpool.execute(test, "execute task by func");
  console.log("taskpool.execute(function) result: " + val2);
}

taskpoolTest();
```

**Example 3**

```ts
// The async functions are supported.
@Concurrent
async function task() {
  let ret = await Promise.all([
    new Promise(resolve => setTimeout(resolve, 1000, "resolved"))
  ]);
  return ret;
}

async function taskpoolTest() {
  taskpool.execute(task).then((result) => {
    console.log("TaskPoolTest task result: " + result);
  });
}

taskpoolTest();
```

**Example 4**

```ts
// Use use concurrent to create a task in the task pool in the .ts file.
// c.ts
function test1(n) {
    "use concurrent"
    return n;
}
export async function taskpoolTest1() {
    console.log("taskpoolTest1 start");
    var task = new taskpool.Task(test1, 100);
    var result = await taskpool.execute(task);
    console.log("taskpoolTest1 result:" + result);
}

async function test2() {
    "use concurrent"
    var ret = await Promise.all([
        new Promise(resolve => setTimeout(resolve, 1000, "resolved"))
    ]);
    return ret;
}
export async function taskpoolTest2() {
    console.log("taskpoolTest2 start");
    taskpool.execute(test2).then((result) => {
        console.log("TaskPoolTest2 result: " + result);
    });
}
```

```ts
/ / a.ets (in the same directory as c.ts)
import { taskpoolTest1, taskpoolTest2 } from "./c";

taskpoolTest1();
taskpoolTest2();
```
