# @ohos.taskpool (Starting the Task Pool)

The task pool provides a multi-thread running environment for applications. It helps reduce resource consumption and improve system performance. It also frees you from caring about the lifecycle of thread instances. You can use the **TaskPool** APIs to create background tasks and perform operations on them, for example, executing or canceling a task. Theoretically, you can create an unlimited number of tasks, but this is not recommended for memory considerations. In addition, you are not advised performing blocking operations in a task, especially indefinite blocking. Long-time blocking operations occupy worker threads and may block other task scheduling, adversely affecting your application performance.

You can determine the execution sequence of tasks with the same priority. They are executed in the same sequence as you call the task execution APIs. The default task priority is **MEDIUM**.

If the number of tasks to be executed is greater than the number of worker threads in the task pool, the task pool scales out based on load balancing to minimize the waiting duration. Similarly, when the number of tasks to be executed falls below the number of worker threads, the task pool scales in to reduce the number of worker threads.

The **TaskPool** APIs return error codes in numeric format. For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

> **NOTE**<br>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import taskpool from '@ohos.taskpool';
```

## Priority

Enumerates the priorities available for created tasks.

**System capability**: SystemCapability.Utils.Lang

| Name| Value| Description|
| -------- | -------- | -------- |
| HIGH   | 0    | The task has a high priority.|
| MEDIUM | 1 | The task has a medium priority.|
| LOW | 2 | The task has a low priority.|

**Example**

```ts
@Concurrent
function printArgs(args) {
    console.log("printArgs: " + args);
    return args;
}
async function taskpoolPriority() {
  let task = new taskpool.Task(printArgs, 100);

  let highCount = 0;
  let mediumCount = 0;
  let lowCount = 0;
  let allCount = 100;
  for (let i = 0; i < allCount; i++) {
    taskpool.execute(task, taskpool.Priority.LOW).then((res: number) => {
      lowCount++;
      console.log("taskpool lowCount is :" + lowCount);
    }).catch((e) => {
      console.error("low task error: " + e);
    })
    taskpool.execute(task, taskpool.Priority.MEDIUM).then((res: number) => {
      mediumCount++;
      console.log("taskpool mediumCount is :" + mediumCount);
    }).catch((e) => {
      console.error("medium task error: " + e);
    })
    taskpool.execute(task, taskpool.Priority.HIGH).then((res: number) => {
      highCount++;
      console.log("taskpool highCount is :" + highCount);
    }).catch((e) => {
      console.error("high task error: " + e);
    })
  }
}
taskpoolPriority();
```

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
| args   | unknown[] | No  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types). The default value is **undefined**.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 10200014 | The function is not mark as concurrent. |

**Example**

```ts
@Concurrent
function printArgs(args) {
    console.log("printArgs: " + args);
    return args;
}

let task = new taskpool.Task(printArgs, "this is my first Task");
```

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name     | Type     | Readable| Writable| Description                                                                      |
| --------- | --------- | ---- | ---- | ------------------------------------------------------------------------- |
| function  | Function  | Yes  | Yes  | Function to be passed in during task creation. For details about the supported return value types of the function, see [Sequenceable Data Types](#sequenceable-data-types).  |
| arguments | unknown[] | Yes  | Yes  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|

## taskpool.execute

execute(func: Function, ...args: unknown[]): Promise\<unknown>

Places the function to be executed in the internal task queue of the task pool. The function will be distributed to the worker thread for execution. The function to be executed in this mode cannot be canceled.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type     | Mandatory| Description                                                                  |
| ------ | --------- | ---- | ---------------------------------------------------------------------- |
| func   | Function  | Yes  | Function to be executed. For details about the supported return value types of the function, see [Sequenceable Data Types](#sequenceable-data-types).    |
| args   | unknown[] | No  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types). The default value is **undefined**.|

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
function printArgs(args) {
    console.log("printArgs: " + args);
    return args;
}

async function taskpoolExecute() {
  let value = await taskpool.execute(printArgs, 100);
  console.log("taskpool result: " + value);
}

taskpoolExecute();
```

## taskpool.execute

execute(task: Task, priority?: Priority): Promise\<unknown>

Places a task in the internal task queue of the task pool. The task will be distributed to the worker thread for execution. The task to be executed in this mode can be canceled.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                 | Mandatory| Description                                      |
| -------- | --------------------- | ---- | ---------------------------------------- |
| task     | [Task](#task)         | Yes  | Task to be executed.                 |
| priority | [Priority](#priority) | No  | Priority of the task. The default value is **MEDIUM**.|

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
function printArgs(args) {
    console.log("printArgs: " + args);
    return args;
}

async function taskpoolExecute() {
  let task = new taskpool.Task(printArgs, 100);
  let value = await taskpool.execute(task);
  console.log("taskpool result: " + value);
}

taskpoolExecute();
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

**Example of successful task cancellation**

```ts
@Concurrent
function printArgs(args) {
    console.log("printArgs: " + args);
    return args;
}

async function taskpoolCancel() {
  let task = new taskpool.Task(printArgs, 100);
  taskpool.execute(task);
  try {
    taskpool.cancel(task);
  } catch (e) {
    console.log("taskpool.cancel occur error:" + e);
  }
}

taskpoolCancel();
```

**Example of a failure to cancel a task that has been executed**

```ts
@Concurrent
function printArgs(args) {
    console.log("printArgs: " + args);
    return args;
}

async function taskpoolCancel() {
  let task = new taskpool.Task(printArgs, 100);
  let value = taskpool.execute(task);
  let start = new Date().getTime();
  while (new Date().getTime() - start < 1000) {// Wait for 1s to ensure that the task has been executed.
    continue;
  }

  try {
    taskpool.cancel(task); // The task has been executed and fails to be canceled.
  } catch (e) {
    console.log("taskpool.cancel occur error:" + e);
  }
}

taskpoolCancel();
```

**Example of a failure to cancel an ongoing task**

```ts
@Concurrent
function printArgs(args) {
    console.log("printArgs: " + args);
    return args;
}

async function taskpoolCancel() {
  let task1 = new taskpool.Task(printArgs, 100);
  let task2 = new taskpool.Task(printArgs, 200);
  let task3 = new taskpool.Task(printArgs, 300);
  let task4 = new taskpool.Task(printArgs, 400);
  let task5 = new taskpool.Task(printArgs, 500);
  let task6 = new taskpool.Task(printArgs, 600);

  let res1 = taskpool.execute(task1);
  let res2 = taskpool.execute(task2);
  let res3 = taskpool.execute(task3);
  let res4 = taskpool.execute(task4);
  let res5 = taskpool.execute(task5);
  let res6 = taskpool.execute(task6);
  try {
    taskpool.cancel(task1); // task1 is being executed and fails to be canceled.
  } catch (e) {
    console.log("taskpool.cancel occur error:" + e);
  }
}

taskpoolCancel();
```

## Additional Information

### Sequenceable Data Types
The following sequenceable data types are supported: All Primitive Type (excluding symbol), Date, String, RegExp, Array, Map, Set, Object, ArrayBuffer, and TypedArray.

### Precautions
- The task pool APIs can be used only in the module with **compileMode** set to **esmodule** in the stage model. To check the **compileMode** setting of a module, open the **build-profile.json5** file of the module and check for **"compileMode": "esmodule"** under **buildOption**.
- A task in the task pool can reference only variables passed in by input parameters or imported variables, rather than closure variables. The decorator **@Concurrent** is used to intercept unsupported variables.
- A task in the task pool supports only common functions or async functions, rather than class member functions or anonymous functions. The decorator **@Concurrent** is used to intercept unsupported functions.
- The decorator **@Concurrent** can be used only in .ets files.

### Using the Task Pool in Simple Mode

**Example 1**

```ts
// Common functions are supported, and variables passed in by input parameters are also supported.
@Concurrent
function printArgs(args) {
    console.log("func: " + args);
    return args;
}

async function taskpoolExecute() {
  // taskpool.execute(task)
  let task = new taskpool.Task(printArgs, "create task, then execute");
  let val1 = await taskpool.execute(task);
  console.log("taskpool.execute(task) result: " + val1);

  // taskpool.execute(function)
  let val2 = await taskpool.execute(printArgs, "execute task by func");
  console.log("taskpool.execute(function) result: " + val2);
}

taskpoolExecute();
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
function printArgs(a) {
    console.log(a);
    console.log(c);
    return a;
}

async function taskpoolExecute() {
  // taskpool.execute(task)
  let task = new taskpool.Task(printArgs, "create task, then execute");
  let val1 = await taskpool.execute(task);
  console.log("taskpool.execute(task) result: " + val1);

  // taskpool.execute(function)
  let val2 = await taskpool.execute(printArgs, "execute task by func");
  console.log("taskpool.execute(function) result: " + val2);
}

taskpoolExecute();
```

**Example 3**

```ts
// The async functions are supported.
@Concurrent
async function delayExcute() {
  let ret = await Promise.all([
    new Promise(resolve => setTimeout(resolve, 1000, "resolved"))
  ]);
  return ret;
}

async function taskpoolExecute() {
  taskpool.execute(delayExcute).then((result) => {
    console.log("TaskPoolTest task result: " + result);
  });
}

taskpoolExecute();
```

**Example 4**

```ts
// c.ets
@Concurrent
function strSort(inPutArr) {
  let newArr = inPutArr.sort();
  return newArr;
}
export async function func1() {
    console.log("taskpoolTest start");
    let strArray = ['c test string', 'b test string', 'a test string'];
    var task = new taskpool.Task(strSort, strArray);
    var result = await taskpool.execute(task);
    console.log("func1 result:" + result);
}

export async function func2() {
    console.log("taskpoolTest2 start");
    let strArray = ['c test string', 'b test string', 'a test string'];
    taskpool.execute(strSort, strArray).then((result) => {
        console.log("func2 result: " + result);
    });
}
```

```ts
/ / a.ets (in the same directory as c.ets)
import { taskpoolTest1, taskpoolTest2 } from "./c";

func1();
func2();
```
