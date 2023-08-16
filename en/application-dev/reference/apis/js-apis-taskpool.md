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

| ID| Error Message                                     |
| -------- | -------------------------------------------- |
| 10200003 | Worker initialization failure.               |
| 10200006 | An exception occurred during serialization.  |
| 10200014 | The function is not mark as concurrent.      |

**Example**

```ts
@Concurrent
function printArgs(args) {
    console.log("printArgs: " + args);
    return args;
}

taskpool.execute(printArgs, 100).then((value) => { // 100: test number
  console.log("taskpool result: " + value);
});
```

## taskpool.execute

execute(task: Task, priority?: Priority): Promise\<unknown>

Places a task in the internal task queue of the task pool. The task will be distributed to the worker thread for execution. The task to be executed in this mode can be canceled.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                 | Mandatory| Description                                      |
| -------- | --------------------- | ---- | ---------------------------------------- |
| task     | [Task](#task)         | Yes  | Task to be executed.                 |
| priority | [Priority](#priority) | No  | Priority of the task. The default value is **taskpool.Priority.MEDIUM**.|

**Return value**

| Type             | Description             |
| ----------------  | ---------------- |
| Promise\<unknown> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message                                    |
| -------- | ------------------------------------------- |
| 10200003 | Worker initialization failure.              |
| 10200006 | An exception occurred during serialization. |
| 10200014 | The function is not mark as concurrent.     |

**Example**

```ts
@Concurrent
function printArgs(args) {
    console.log("printArgs: " + args);
    return args;
}

let task = new taskpool.Task(printArgs, 100); // 100: test number
taskpool.execute(task).then((value) => {
  console.log("taskpool result: " + value);
});
```

## taskpool.execute<sup>10+</sup>

execute(group: TaskGroup, priority?: Priority): Promise<unknown[]>

Places a task group in the internal task queue of the task pool. The task group will be distributed to the worker thread for execution.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                       | Mandatory| Description                                                          |
| --------- | --------------------------- | ---- | -------------------------------------------------------------- |
| group     | [TaskGroup](#taskgroup)     | Yes  | Task group to be executed.                                     |
| priority  | [Priority](#priority)       | No  | Priority of the task group. The default value is **taskpool.Priority.MEDIUM**.|

**Return value**

| Type                | Description                              |
| ----------------    | ---------------------------------- |
| Promise\<unknown[]> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message                                    |
| -------- | ------------------------------------------- |
| 10200006 | An exception occurred during serialization. |

**Example**

```ts
@Concurrent
function printArgs(args) {
    console.log("printArgs: " + args);
    return args;
}

let taskGroup1 = new taskpool.TaskGroup();
taskGroup1.addTask(printArgs, 10); // 10: test number
taskGroup1.addTask(printArgs, 20); // 20: test number
taskGroup1.addTask(printArgs, 30); // 30: test number

let taskGroup2 = new taskpool.TaskGroup();
let task1 = new taskpool.Task(printArgs, 100); // 100: test number
let task2 = new taskpool.Task(printArgs, 200); // 200: test number
let task3 = new taskpool.Task(printArgs, 300); // 300: test number
taskGroup2.addTask(task1);
taskGroup2.addTask(task2);
taskGroup2.addTask(task3);
taskpool.execute(taskGroup1).then((res) => {
  console.info("taskpool execute res is:" + res);
}).catch((e) => {
  console.error("taskpool execute error is:" + e);
});
taskpool.execute(taskGroup2).then((res) => {
  console.info("taskpool execute res is:" + res);
}).catch((e) => {
  console.error("taskpool execute error is:" + e);
});
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

| ID| Error Message                                     |
| -------- | -------------------------------------------- |
| 10200015 | The task does not exist when it is canceled. |
| 10200016 | The task is executing when it is canceled.   |

Since API version 10, error code 10200016 is not reported when this API is called.

**Example of canceling an ongoing task**

```ts
@Concurrent
function inspectStatus(arg) {
    // Check the cancellation status and return the result.
    if (taskpool.Task.isCanceled()) {
      console.log("task has been canceled before 2s sleep.");
      return arg + 2;
    }
    // 2s sleep
    let t = Date.now();
    while (Date.now() - t < 2000) {
      continue;
    }
    // Check the cancellation status again and return the result.
    if (taskpool.Task.isCanceled()) {
      console.log("task has been canceled after 2s sleep.");
      return arg + 3;
    }
    return arg + 1;
}

let task1 = new taskpool.Task(inspectStatus, 100); // 100: test number
let task2 = new taskpool.Task(inspectStatus, 200); // 200: test number
let task3 = new taskpool.Task(inspectStatus, 300); // 300: test number
let task4 = new taskpool.Task(inspectStatus, 400); // 400: test number
let task5 = new taskpool.Task(inspectStatus, 500); // 500: test number
let task6 = new taskpool.Task(inspectStatus, 600); // 600: test number
taskpool.execute(task1).then((res)=>{
  console.log("taskpool test result: " + res);
}).catch((err) => {
  console.log("taskpool test occur error: " + err);
});
let res2 = taskpool.execute(task2);
let res3 = taskpool.execute(task3);
let res4 = taskpool.execute(task4);
let res5 = taskpool.execute(task5);
let res6 = taskpool.execute(task6);
// Cancel the task 1s later.
setTimeout(()=>{
  taskpool.cancel(task1);}, 1000);
```

## taskpool.cancel<sup>10+</sup>

cancel(group: TaskGroup): void

Cancels a task group in the task pool.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                   | Mandatory| Description                |
| ------- | ----------------------- | ---- | -------------------- |
| group   | [TaskGroup](#taskgroup) | Yes  | Task group to cancel.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message                                                |
| -------- | ------------------------------------------------------- |
| 10200018 | The task group does not exist when it is canceled.      |

**Example**

```ts
@Concurrent
function printArgs(args) {
    let t = Date.now();
    while (Date.now() - t < 2000) {
      continue;
    }
    console.log("printArgs: " + args);
    return args;
}

let taskGroup1 = new taskpool.TaskGroup();
taskGroup1.addTask(printArgs, 10); // 10: test number
let taskGroup2 = new taskpool.TaskGroup();
taskGroup2.addTask(printArgs, 100); // 100: test number
taskpool.execute(taskGroup1).then((res)=>{
  console.info("taskGroup1 res is:" + res)
});
taskpool.execute(taskGroup2).then((res)=>{
  console.info("taskGroup2 res is:" + res)
});
setTimeout(()=>{
  try {
    taskpool.cancel(taskGroup2);
  } catch (e) {
    console.log("taskGroup.cancel occur error:" + e);
  }
}, 1000);
```


## taskpool.getTaskPoolInfo<sup>10+</sup>

getTaskPoolInfo(): TaskPoolInfo

Obtains the internal information about this task pool.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                               | Description               |
| ----------------------------------- | ------------------ |
| [TaskPoolInfo](#taskpoolinfo10)   | Internal information about the task pool.  |

**Example**

```ts
let taskpoolInfo = taskpool.getTaskPoolInfo();
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

let task = new taskpool.Task(printArgs, 100); // 100: test number
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
```

## Task

Implements a task. Before calling any APIs in **Task**, you must use [constructor](#constructor) to create a **Task** instance.

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

| ID| Error Message                                |
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

### isCanceled<sup>10+</sup>

static isCanceled(): boolean

Checks whether the running task is canceled. Before using this API, you must create a **Task** instance.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                |
| ------- | ------------------------------------ |
| boolean | Returns **true** if the running task is canceled; returns **false** otherwise.|

**Example**

```ts
@Concurrent
function inspectStatus(arg) {
    // do something
    if (taskpool.Task.isCanceled()) {
      console.log("task has been canceled.");
      // do something
      return arg + 1;
    }
    // do something
    return arg;
}
```

> **NOTE**
> 
> **isCanceled** must be used together with **taskpool.cancel**. If **cancel** is not called, **isCanceled** returns **false** by default.

**Example**

```ts
@Concurrent
function inspectStatus(arg) {
    // Check the cancellation status and return the result.
    if (taskpool.Task.isCanceled()) {
      console.log("task has been canceled before 2s sleep.");
      return arg + 2;
    }
    // Wait for 2s.
    let t = Date.now();
    while (Date.now() - t < 2000) {
      continue;
    }
    // Check the cancellation status again and return the result.
    if (taskpool.Task.isCanceled()) {
      console.log("task has been canceled after 2s sleep.");
      return arg + 3;
    }
  return arg + 1;
}

let task = new taskpool.Task(inspectStatus, 100); // 100: test number
taskpool.execute(task).then((res)=>{
  console.log("taskpool test result: " + res);
}).catch((err) => {
  console.log("taskpool test occur error: " + err);
});
// If cancel is not called, isCanceled() returns false by default, and the task execution result is 101.
```

### setTransferList<sup>10+</sup>

setTransferList(transfer?: ArrayBuffer[]): void

Sets the task transfer list. Before using this API, you must create a **Task** instance.

> **NOTE**
> 
> This API is used to set the task transfer list in the form of **ArrayBuffer** in the task pool. The **ArrayBuffer** instance does not copy the content in the task to the worker thread during transfer. Instead, it transfers the buffer control right to the worker thread. After the transfer, the **ArrayBuffer** instance becomes invalid.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type          | Mandatory| Description                                         |
| -------- | ------------- | ---- | --------------------------------------------- |
| transfer | ArrayBuffer[] | No  | **ArrayBuffer** instance holding the objects to transfer. The default value is an empty array.|

**Example**

```ts
let buffer = new ArrayBuffer(8);
let view = new Uint8Array(buffer);
let buffer1 = new ArrayBuffer(16);
let view1 = new Uint8Array(buffer1);

console.info("testTransfer view byteLength: " + view.byteLength);
console.info("testTransfer view1 byteLength: " + view1.byteLength);
@Concurrent
function testTransfer(arg1, arg2) {
  console.info("testTransfer arg1 byteLength: " + arg1.byteLength);
  console.info("testTransfer arg2 byteLength: " + arg2.byteLength);
  return 100;
}
let task = new taskpool.Task(testTransfer, view, view1);
task.setTransferList([view.buffer, view1.buffer]);
taskpool.execute(task).then((res)=>{
  console.info("test result: " + res);
}).catch((e)=>{
  console.error("test catch: " + e);
})
console.info("testTransfer view byteLength: " + view.byteLength);
console.info("testTransfer view1 byteLength: " + view1.byteLength);
```

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name     | Type     | Readable| Writable| Description                                                                      |
| --------- | --------- | ---- | ---- | ------------------------------------------------------------------------- |
| function  | Function  | Yes  | Yes  | Function to be passed in during task creation. For details about the supported return value types of the function, see [Sequenceable Data Types](#sequenceable-data-types).  |
| arguments | unknown[] | Yes  | Yes  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|

## TaskGroup<sup>10+</sup>

Implements a task group. Before calling any APIs in **TaskGroup**, you must use [constructor](#constructor10) to create a **TaskGroup** instance.

### constructor<sup>10+</sup>

constructor()

Constructor used to create a **TaskGroup** instance.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let taskGroup = new taskpool.TaskGroup();
```

### addTask<sup>10+</sup>

addTask(func: Function, ...args: unknown[]): void

Adds the function to be executed to this task group. Before using this API, you must create a **TaskGroup** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type     | Mandatory| Description                                                                  |
| ------ | --------- | ---- | ---------------------------------------------------------------------- |
| func   | Function  | Yes  | Function to be passed in for task execution. For details about the supported return value types of the function, see [Sequenceable Data Types](#sequenceable-data-types).    |
| args   | unknown[] | No  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types). The default value is **undefined**.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message                                |
| -------- | --------------------------------------- |
| 10200014 | The function is not mark as concurrent. |

**Example**

```ts
@Concurrent
function printArgs(args) {
    console.log("printArgs: " + args);
    return args;
}

let taskGroup = new taskpool.TaskGroup();
taskGroup.addTask(printArgs, 100); // 100: test number
```

### addTask<sup>10+</sup>

addTask(task: Task): void

Adds a created task to this task group. Before using this API, you must create a **TaskGroup** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                 | Mandatory| Description                                      |
| -------- | --------------------- | ---- | ---------------------------------------- |
| task     | [Task](#task)         | Yes  | Task to be added to the task group.                 |

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message                                |
| -------- | --------------------------------------- |
| 10200014 | The function is not mark as concurrent. |

**Example**

```ts
@Concurrent
function printArgs(args) {
    console.log("printArgs: " + args);
    return args;
}

let taskGroup = new taskpool.TaskGroup();
let task = new taskpool.Task(printArgs, 200); // 200: test number
taskGroup.addTask(task);
```


## State<sup>10+</sup>

Enumerates the task states.

**System capability**: SystemCapability.Utils.Lang

| Name     | Value       | Description         |
| --------- | -------- | ------------- |
| WAITING   | 1        | The task is waiting.|
| RUNNING   | 2        | The task is running.|
| CANCELED  | 3        | The task is canceled.|


## TaskInfo<sup>10+</sup>

Describes the internal information about a task.

**System capability**: SystemCapability.Utils.Lang

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name    | Type               | Readable| Writable| Description                                                          |
| -------- | ------------------ | ---- | ---- | ------------------------------------------------------------- |
| taskId   | number             | Yes  | No  | Task ID.                                                    |
| state    | [State](#state10)  | Yes  | No  | Task state.                                                   |
| duration | number             | Yes  | No  | Duration that the task has been executed, in ms. If the return value is **0**, the task is not running. If the return value is empty, no task is running. |

## ThreadInfo<sup>10+</sup>

Describes the internal information about a worker thread.

**System capability**: SystemCapability.Utils.Lang

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name    | Type                   | Readable| Writable| Description                                                     |
| -------- | ---------------------- | ---- | ---- | -------------------------------------------------------- |
| tid      | number                 | Yes  | No  | ID of the worker thread. If the return value is empty, no task is running.             |
| taskIds  | number[]               | Yes  | No  | IDs of tasks running on the calling thread. If the return value is empty, no task is running.  |
| priority | [Priority](#priority)  | Yes  | No  | Priority of the calling thread. If the return value is empty, no task is running.             |

## TaskPoolInfo<sup>10+</sup>

Describes the internal information about a task pool.

**System capability**: SystemCapability.Utils.Lang

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name         | Type                             | Readable| Writable| Description                 |
| ------------- | -------------------------------- | ---- | ---- | -------------------- |
| threadInfos   | [ThreadInfo[]](#threadinfo10)    | Yes  | No  | Internal information about the worker threads.  |
| taskInfos     | [TaskInfo[]](#taskinfo10)        | Yes  | No  | Internal information about the tasks.      |


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
export let c = 2000;
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
    let task = new taskpool.Task(strSort, strArray);
    let result = await taskpool.execute(task);
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
// a.ets (in the same directory as c.ets)
import { taskpoolTest1, taskpoolTest2 } from "./c";

func1();
func2();
```

**Example 5**

```ts
// Success in canceling a task
@Concurrent
function inspectStatus(arg) {
    // Check the cancellation status and return the result.
    if (taskpool.Task.isCanceled()) {
      console.log("task has been canceled before 2s sleep.");
      return arg + 2;
    }
    // Wait for 2s.
    let t = Date.now();
    while (Date.now() - t < 2000) {
      continue;
    }
    // Check the cancellation status again and return the result.
    if (taskpool.Task.isCanceled()) {
      console.log("task has been canceled after 2s sleep.");
      return arg + 3;
    }
    return arg + 1;
}

async function taskpoolCancel() {
    let task = new taskpool.Task(inspectStatus, 100); // 100: test number
    taskpool.execute(task).then((res)=>{
      console.log("taskpool test result: " + res);
    }).catch((err) => {
      console.log("taskpool test occur error: " + err);
    });
    // Cancel the task 1s later.
    setTimeout(()=>{
      taskpool.cancel(task);}, 1000);
}

taskpoolCancel();
```

**Example 6**

```ts
// Failure to cancel a task that has been executed
@Concurrent
function inspectStatus(arg) {
    // Check the cancellation status and return the result.
    if (taskpool.Task.isCanceled()) {
      return arg + 2;
    }
    // Wait for 2s.
    let t = Date.now();
    while (Date.now() - t < 2000) {
      continue;
    }
    // Check the cancellation status again and return the result.
    if (taskpool.Task.isCanceled()) {
      return arg + 3;
    }
    return arg + 1;
}

async function taskpoolCancel() {
    let task = new taskpool.Task(inspectStatus, 100); // 100: test number
    taskpool.execute(task).then((res)=>{
      console.log("taskpool test result: " + res);
    }).catch((err) => {
      console.log("taskpool test occur error: " + err);
    });
    setTimeout(()=>{
      try {
        taskpool.cancel(task); // The task has been executed and fails to be canceled.
      } catch (e) {
        console.log("taskpool.cancel occur error:" + e);
      }
    }, 3000); // Wait for 3s to ensure that the task has been executed.
}

taskpoolCancel();
```

**Example 7**

```ts
// Success of canceling a task group to be executed
@Concurrent
function printArgs(args) {
  let t = Date.now();
  while (Date.now() - t < 1000) {
    continue;
  }
  console.log("printArgs: " + args);
  return args;
}

async function taskpoolGroupCancelTest() {
  let taskGroup1 = new taskpool.TaskGroup();
  taskGroup1.addTask(printArgs, 10); // 10: test number
  taskGroup1.addTask(printArgs, 20); // 20: test number
  taskGroup1.addTask(printArgs, 30); // 30: test number
  let taskGroup2 = new taskpool.TaskGroup();
  let task1 = new taskpool.Task(printArgs, 100); // 100: test number
  let task2 = new taskpool.Task(printArgs, 200); // 200: test number
  let task3 = new taskpool.Task(printArgs, 300); // 300: test number
  taskGroup2.addTask(task1);
  taskGroup2.addTask(task2);
  taskGroup2.addTask(task3);
  taskpool.execute(taskGroup1).then((res) => {
    console.info("taskpool execute res is:" + res);
  }).catch((e) => {
    console.error("taskpool execute error is:" + e);
  });
  taskpool.execute(taskGroup2).then((res) => {
    console.info("taskpool execute res is:" + res);
  }).catch((e) => {
    console.error("taskpool execute error is:" + e);
  });

  taskpool.cancel(taskGroup2);
}

taskpoolGroupCancelTest()
```

**Example 8**

```ts
// Create and execute 100 tasks with different priorities, and view their information.
@Concurrent
function delay() {
  let start = new Date().getTime();
  while (new Date().getTime() - start < 500) {
    continue;
  }
}

let highCount = 0;
let mediumCount = 0;
let lowCount = 0;
let allCount = 100;
for (let i = 0; i < allCount; i++) {
  let task1 = new taskpool.Task(delay);
  let task2 = new taskpool.Task(delay);
  let task3 = new taskpool.Task(delay);
  taskpool.execute(task1, taskpool.Priority.LOW).then(() => {
    lowCount++;
  }).catch((e) => {
    console.error("low task error: " + e);
  })
  taskpool.execute(task2, taskpool.Priority.MEDIUM).then(() => {
    mediumCount++;
  }).catch((e) => {
    console.error("medium task error: " + e);
  })
  taskpool.execute(task3, taskpool.Priority.HIGH).then(() => {
    highCount++;
  }).catch((e) => {
    console.error("high task error: " + e);
  })
}
let start = new Date().getTime();
while (new Date().getTime() - start < 1000) {
    continue;
}
let taskpoolInfo = taskpool.getTaskPoolInfo();
let tid = 0;
let taskIds = [];
let priority = 0;
let taskId = 0;
let state = 0;
let duration = 0;
for(let threadInfo of taskpoolInfo.threadInfos) {
  tid = threadInfo.tid;
  taskIds.length = threadInfo.taskIds.length;
  priority = threadInfo.priority;
  console.info("taskpool---tid is:" + tid + ", taskIds is:" + taskIds + ", priority is:" + priority);
}
for(let taskInfo of taskpoolInfo.taskInfos) {
  taskId = taskInfo.taskId;
  state = taskInfo.state;
  duration = taskInfo.duration;
  console.info("taskpool---taskId is:" + taskId + ", state is:" + state + ", duration is:" + duration);
}
```
