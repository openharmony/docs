# @ohos.taskpool (Starting the Task Pool)

The task pool provides a multi-thread running environment for applications. It helps reduce resource consumption and improve system performance. It also frees you from caring about the lifecycle of thread instances. You can use the **TaskPool** APIs to create background tasks and perform operations on them, for example, executing or canceling a task. Theoretically, you can create an unlimited number of tasks, but this is not recommended for memory considerations. In addition, you are not advised performing blocking operations in a task, especially indefinite blocking. Long-time blocking operations occupy worker threads and may block other task scheduling, adversely affecting your application performance.

You can determine the execution sequence of tasks with the same priority. They are executed in the same sequence as you call the task execution APIs. The default task priority is **MEDIUM**.

If the number of tasks to be executed is greater than the number of worker threads in the task pool, the task pool scales out based on load balancing to minimize the waiting duration. Similarly, when the number of tasks to be executed falls below the number of worker threads, the task pool scales in to reduce the number of worker threads.

The **TaskPool** APIs return error codes in numeric format. For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

For details about the precautions for using **TaskPool**, see [Precautions for TaskPool](../../arkts-utils/taskpool-introduction.md#precautions-for-taskpool).

> **NOTE**<br>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import taskpool from '@ohos.taskpool';
```
## taskpool.execute

execute(func: Function, ...args: Object[]): Promise\<Object>

Places a function to be executed in the internal queue of the task pool. The function will be distributed to the worker thread for execution. In this mode, the function cannot be canceled.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type     | Mandatory| Description                                                                  |
| ------ | --------- | ---- | ---------------------------------------------------------------------- |
| func   | Function  | Yes  | Function to be executed. The function must be decorated using [@Concurrent decorator](../../arkts-utils/arkts-concurrent.md). For details about the supported return value types of the function, see [Sequenceable Data Types](#sequenceable-data-types).    |
| args   | Object[] | No  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types). The default value is **undefined**.|

**Return value**

| Type             | Description                                |
| ----------------- | ------------------------------------ |
| Promise\<Object>  | Promise used to return an object that carries the function execution result.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                     |
| -------- | -------------------------------------------- |
| 10200003 | Worker initialization failure.               |
| 10200006 | An exception occurred during serialization.  |
| 10200014 | The function is not mark as concurrent.      |

**Example**

```ts
@Concurrent
function printArgs(args: number): number {
    console.info("printArgs: " + args);
    return args;
}

taskpool.execute(printArgs, 100).then((value: Object) => { // 100: test number
  console.info("taskpool result: " + value);
});
```

## taskpool.execute

execute(task: Task, priority?: Priority): Promise\<Object>

Places a task in the internal queue of the task pool. The task will be distributed to the worker thread for execution. In this mode, you can set the task priority and call **cancel()** to cancel the task. The task cannot be a task in a task group or queue. It can be executed by calling **execute()** for multiple times.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                 | Mandatory| Description                                      |
| -------- | --------------------- | ---- | ---------------------------------------- |
| task     | [Task](#task)         | Yes  | Task to be executed.                 |
| priority | [Priority](#priority) | No  | Priority of the task. The default value is **taskpool.Priority.MEDIUM**.|

**Return value**

| Type             | Description             |
| ----------------  | ---------------- |
| Promise\<Object> | Promise used to return an object that carries the function execution result.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                    |
| -------- | ------------------------------------------- |
| 10200003 | Worker initialization failure.              |
| 10200006 | An exception occurred during serialization. |
| 10200014 | The function is not mark as concurrent.     |

**Example**

```ts
@Concurrent
function printArgs(args: number): number {
    console.info("printArgs: " + args);
    return args;
}

let task1: taskpool.Task = new taskpool.Task(printArgs, 100); // 100: test number
let task2: taskpool.Task = new taskpool.Task(printArgs, 200); // 200: test number
let task3: taskpool.Task = new taskpool.Task(printArgs, 300); // 300: test number
taskpool.execute(task1, taskpool.Priority.LOW).then((value: Object) => {
  console.info("taskpool result1: " + value);
});
taskpool.execute(task2, taskpool.Priority.MEDIUM).then((value: Object) => {
  console.info("taskpool result2: " + value);
});
taskpool.execute(task3, taskpool.Priority.HIGH).then((value: Object) => {
  console.info("taskpool result3: " + value);
});
```

## taskpool.execute<sup>10+</sup>

execute(group: TaskGroup, priority?: Priority): Promise<Object[]>

Places a task group in the internal queue of the task pool. The task group will be distributed to the worker thread for execution. After all tasks in the task group are executed, a result array is returned. This API applies when you want to execute a group of associated tasks.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                       | Mandatory| Description                                                          |
| --------- | --------------------------- | ---- | -------------------------------------------------------------- |
| group     | [TaskGroup](#taskgroup10)     | Yes  | Task group to be executed.                                     |
| priority  | [Priority](#priority)       | No  | Priority of the task group. The default value is **taskpool.Priority.MEDIUM**.|

**Return value**

| Type                | Description                              |
| ----------------    | ---------------------------------- |
| Promise\<Object[]>  | Promise used to return an object array that carries the function execution result.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                    |
| -------- | ------------------------------------------- |
| 10200006 | An exception occurred during serialization. |

**Example**

```ts
@Concurrent
function printArgs(args: number): number {
    console.info("printArgs: " + args);
    return args;
}

let taskGroup1: taskpool.TaskGroup = new taskpool.TaskGroup();
taskGroup1.addTask(printArgs, 10); // 10: test number
taskGroup1.addTask(printArgs, 20); // 20: test number
taskGroup1.addTask(printArgs, 30); // 30: test number

let taskGroup2: taskpool.TaskGroup = new taskpool.TaskGroup();
let task1: taskpool.Task = new taskpool.Task(printArgs, 100); // 100: test number
let task2: taskpool.Task = new taskpool.Task(printArgs, 200); // 200: test number
let task3: taskpool.Task = new taskpool.Task(printArgs, 300); // 300: test number
taskGroup2.addTask(task1);
taskGroup2.addTask(task2);
taskGroup2.addTask(task3);
taskpool.execute(taskGroup1).then((res: Array<Object>) => {
  console.info("taskpool execute res is:" + res);
});
taskpool.execute(taskGroup2).then((res: Array<Object>) => {
  console.info("taskpool execute res is:" + res);
});
```

## taskpool.executeDelayed<sup>11+</sup>

executeDelayed(delayTime: number, task: Task, priority?: Priority): Promise\<Object>

Executes a task after a given delay. In this mode, you can set the task priority and call **cancel()** to cancel the task. The task cannot be a task in a task group or queue. It can be executed by calling **executeDelayed()** for multiple times.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name      | Type         | Mandatory| Description                |
| ----------- | ------------- | ---- | -------------------- |
| delayTime   | number        | Yes  | Delay, in ms. |
| task        | [Task](#task) | Yes  | Task to be executed with a delay.|
| priority    | [Priority](#priority)       | No  | Priority of the task. The default value is **taskpool.Priority.MEDIUM**.|

**Return value**

| Type                | Description                              |
| ----------------    | ---------------------------------- |
| Promise\<Object>  | Promise used to return an object array that carries the function execution result.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID  | Error Message                        |
| --------- | -------------------------------- |
| 10200028 | The delayTime is less than zero. |

**Example**

```ts
@Concurrent
// import BusinessError
import { BusinessError } from '@ohos.base'

function printArgs(args: number): void {
    console.info("printArgs: " + args);
}

let t: number = Date.now();
console.info("taskpool start time is: " + t);
let task: taskpool.Task = new taskpool.Task(printArgs, 100); // 100: test number
taskpool.executeDelayed(1000, task).then(() => { // 1000:delayTime is 1000ms
  console.info("taskpool execute success");
}).catch((e: BusinessError) => {
  console.error(`taskpool execute: Code: ${e.code}, message: ${e.message}`);
})
```


## taskpool.cancel

cancel(task: Task): void

Cancels a task in the task pool. If the task is in the internal queue of the task pool, the task will not be executed after being canceled, and **undefined** is returned. If the task has been distributed to the worker thread of the task pool, canceling the task does not affect the task execution, and the execution result is returned in the catch branch. You can use **isCanceled()** to check the task cancellation status. In other words, **taskpool.cancel** takes effect before **taskpool.execute** or **taskpool.executeDelayed** is called.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| task   | [Task](#task) | Yes  | Task to cancel.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                     |
| -------- | -------------------------------------------- |
| 10200015 | The task does not exist when it is canceled. |
| 10200016 | The task is executing when it is canceled.   |

Since API version 10, error code 10200016 is not reported when this API is called.

**Example of canceling an ongoing task**

```ts
@Concurrent
function inspectStatus(arg: number): number {
  // Check whether the task has been canceled and respond accordingly.
  if (taskpool.Task.isCanceled()) {
    console.info("task has been canceled before 2s sleep.");
    return arg + 2;
  }
  // 2s sleep
  let t: number = Date.now();
  while (Date.now() - t < 2000) {
    continue;
  }
  // Check again whether the task has been canceled and respond accordingly.
  if (taskpool.Task.isCanceled()) {
    console.info("task has been canceled after 2s sleep.");
    return arg + 3;
  }
  return arg + 1;
}

function concurrntFunc() {
  let task1: taskpool.Task = new taskpool.Task(inspectStatus, 100); // 100: test number
  let task2: taskpool.Task = new taskpool.Task(inspectStatus, 200); // 200: test number
  let task3: taskpool.Task = new taskpool.Task(inspectStatus, 300); // 300: test number
  let task4: taskpool.Task = new taskpool.Task(inspectStatus, 400); // 400: test number
  let task5: taskpool.Task = new taskpool.Task(inspectStatus, 500); // 500: test number
  let task6: taskpool.Task = new taskpool.Task(inspectStatus, 600); // 600: test number
  taskpool.execute(task1).then((res: Object)=>{
    console.info("taskpool test result: " + res);
  });
  taskpool.execute(task2);
  taskpool.execute(task3);
  taskpool.execute(task4);
  taskpool.execute(task5);
  taskpool.execute(task6);
  // Cancel the task 1s later.
  setTimeout(()=>{
    try {
      taskpool.cancel(task1);
    } catch (e) {
      console.error(`taskpool: cancel error code: ${e.code}, info: ${e.message}`);
    }
  }, 1000);
}

concurrntFunc();
```

## taskpool.cancel<sup>10+</sup>

cancel(group: TaskGroup): void

Cancels a task group in the task pool. If a task group is canceled before all the tasks in it are finished, **undefined** is returned.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                   | Mandatory| Description                |
| ------- | ----------------------- | ---- | -------------------- |
| group   | [TaskGroup](#taskgroup10) | Yes  | Task group to cancel.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                |
| -------- | ------------------------------------------------------- |
| 10200018 | The task group does not exist when it is canceled.      |

**Example**

```ts
@Concurrent
function printArgs(args: number): number {
  let t: number = Date.now();
  while (Date.now() - t < 2000) {
    continue;
  }
  console.info("printArgs: " + args);
  return args;
}

function concurrntFunc() {
  let taskGroup1: taskpool.TaskGroup = new taskpool.TaskGroup();
  taskGroup1.addTask(printArgs, 10); // 10: test number
  let taskGroup2: taskpool.TaskGroup = new taskpool.TaskGroup();
  taskGroup2.addTask(printArgs, 100); // 100: test number
  taskpool.execute(taskGroup1).then((res: Array<Object>)=>{
    console.info("taskGroup1 res is:" + res);
  });
  taskpool.execute(taskGroup2).then((res: Array<Object>)=>{
    console.info("taskGroup2 res is:" + res);
  });
  setTimeout(()=>{
    try {
      taskpool.cancel(taskGroup2);
    } catch (e) {
      console.error(`taskpool: cancel error code: ${e.code}, info: ${e.message}`);
    }
  }, 1000);
}

concurrntFunc();
```


## taskpool.getTaskPoolInfo<sup>10+</sup>

getTaskPoolInfo(): TaskPoolInfo

Obtains internal information about this task pool, including thread information and task information.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                               | Description               |
| ----------------------------------- | ------------------ |
| [TaskPoolInfo](#taskpoolinfo10)   | Internal information about the task pool.  |

**Example**

```ts
let taskpoolInfo: taskpool.TaskPoolInfo = taskpool.getTaskPoolInfo();
```

## Priority

Enumerates the priorities available for created tasks. The task priority applies during task execution.

**System capability**: SystemCapability.Utils.Lang

| Name| Value| Description|
| -------- | -------- | -------- |
| HIGH   | 0    | The task has a high priority.|
| MEDIUM | 1 | The task has a medium priority.|
| LOW | 2 | The task has a low priority.|

**Example**

```ts
@Concurrent
function printArgs(args: number): number {
  let t: number = Date.now();
  while (Date.now() - t < 1000) { // 1000: delay 1s
    continue;
  }
  console.info("printArgs: " + args);
  return args;
}

let allCount = 100; // 100: test number
let taskArray: Array<taskpool.Task> = [];
// Create 300 tasks and add them to taskArray.
for (let i: number = 1; i < allCount; i++) {
  let task1: taskpool.Task = new taskpool.Task(printArgs, i);
  taskArray.push(task1);
  let task2: taskpool.Task = new taskpool.Task(printArgs, i * 10); // 10: test number
  taskArray.push(task2);
  let task3: taskpool.Task = new taskpool.Task(printArgs, i * 100); // 100: test number
  taskArray.push(task3);
}

// Obtain different tasks from taskArray and specify different priorities for execution.
for (let i: number = 0; i < allCount; i+=3) { // 3: Three tasks are executed each time. When obtaining tasks cyclically, obtain the three items following the last batch to ensure that different tasks are obtained each time.
  taskpool.execute(taskArray[i], taskpool.Priority.HIGH);
  taskpool.execute(taskArray[i + 1], taskpool.Priority.LOW);
  taskpool.execute(taskArray[i + 2], taskpool.Priority.MEDIUM);
}
```

## Task

Implements a task. Before calling any APIs in **Task**, you must use [constructor](#constructor) to create a **Task** instance. A task can be executed for multiple times, placed in a task group or queue for execution, or added with dependencies for execution.

### constructor

constructor(func: Function, ...args: Object[])

A constructor used to create a **Task** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type     | Mandatory| Description                                                                 |
| ------ | --------- | ---- | -------------------------------------------------------------------- |
| func   | Function  | Yes  | Function to be executed. The function must be decorated using [@Concurrent decorator](../../arkts-utils/arkts-concurrent.md). For details about the supported return value types of the function, see [Sequenceable Data Types](#sequenceable-data-types).    |
| args   | Object[] | No  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types). The default value is **undefined**.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                |
| -------- | --------------------------------------- |
| 10200014 | The function is not mark as concurrent. |

**Example**

```ts
@Concurrent
function printArgs(args: number): number {
  console.info("printArgs: " + args);
  return args;
}

let task: taskpool.Task = new taskpool.Task(printArgs, "this is my first Task");
```

### constructor<sup>11+</sup>

constructor(name: string, func: Function, ...args: Object[])

A constructor used to create a **Task** instance, with the task name specified.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type    | Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| name   | string   | Yes  | Task name.                                                  |
| func   | Function  | Yes  | Function to be executed. The function must be decorated using [@Concurrent decorator](../../arkts-utils/arkts-concurrent.md). For details about the supported return value types of the function, see [Sequenceable Data Types](#sequenceable-data-types).    |
| args   | Object[] | No  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types). The default value is **undefined**.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 10200014 | The function is not mark as concurrent. |

**Example**

```ts
@Concurrent
function printArgs(args: string): string {
  console.info("printArgs: " + args);
  return args;
}

let taskName: string = "taskName";
let task: taskpool.Task = new taskpool.Task(taskName, printArgs, "this is my first Task");
let name: string = task.name;
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
function inspectStatus(arg: number): number {
    // do something
    if (taskpool.Task.isCanceled()) {
      console.info("task has been canceled.");
      // do something
      return arg + 1;
    }
    // do something
    return arg;
}
```

> **NOTE**<br>
> **isCanceled** must be used together with **taskpool.cancel**. If **cancel** is not called, **isCanceled** returns **false** by default.

**Example**

```ts
@Concurrent
function inspectStatus(arg: number): number {
  // Check whether the task has been canceled and respond accordingly.
  if (taskpool.Task.isCanceled()) {
    console.info("task has been canceled before 2s sleep.");
    return arg + 2;
  }
  // Wait for 2s.
  let t: number = Date.now();
  while (Date.now() - t < 2000) {
    continue;
  }
  // Check again whether the task has been canceled and respond accordingly.
  if (taskpool.Task.isCanceled()) {
    console.info("task has been canceled after 2s sleep.");
    return arg + 3;
  }
  return arg + 1;
}

let task: taskpool.Task = new taskpool.Task(inspectStatus, 100); // 100: test number
taskpool.execute(task).then((res: Object)=>{
  console.info("taskpool test result: " + res);
}).catch((err: string) => {
  console.error("taskpool test occur error: " + err);
});
// If cancel is not called, isCanceled() returns false by default, and the task execution result is 101.
```

### setTransferList<sup>10+</sup>

setTransferList(transfer?: ArrayBuffer[]): void

Sets the task transfer list. Before using this API, you must create a **Task** instance. If this API is not called, the ArrayBuffer in the data is transferred by default.

> **NOTE**<br>
> This API is used to set the task transfer list in the form of **ArrayBuffer** in the task pool. The **ArrayBuffer** instance does not copy the content in the task to the worker thread during transfer. Instead, it transfers the buffer control right to the worker thread. After the transfer, the **ArrayBuffer** instance becomes invalid. An empty **ArrayBuffer** will not be transferred.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type          | Mandatory| Description                                         |
| -------- | ------------- | ---- | --------------------------------------------- |
| transfer | ArrayBuffer[] | No  | **ArrayBuffer** instance holding the objects to transfer. The default value is an empty array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                       |
| -------- | -------------------------------------------------------------- |
| 10200029 | Can not set an arraybuffer to both transferList and cloneList. |

**Example**

```ts
@Concurrent
function testTransfer(arg1: ArrayBuffer, arg2: ArrayBuffer): number {
  console.info("testTransfer arg1 byteLength: " + arg1.byteLength);
  console.info("testTransfer arg2 byteLength: " + arg2.byteLength);
  return 100;
}

let buffer: ArrayBuffer = new ArrayBuffer(8);
let view: Uint8Array = new Uint8Array(buffer);
let buffer1: ArrayBuffer = new ArrayBuffer(16);
let view1: Uint8Array = new Uint8Array(buffer1);

console.info("testTransfer view byteLength: " + view.byteLength);
console.info("testTransfer view1 byteLength: " + view1.byteLength);
// The execution result is as follows:
// testTransfer view byteLength: 8
// testTransfer view1 byteLength: 16

let task: taskpool.Task = new taskpool.Task(testTransfer, view, view1);
task.setTransferList([view.buffer, view1.buffer]);
taskpool.execute(task).then((res: Object)=>{
  console.info("test result: " + res);
}).catch((e: string)=>{
  console.error("test catch: " + e);
})
console.info("testTransfer view2 byteLength: " + view.byteLength);
console.info("testTransfer view3 byteLength: " + view1.byteLength);
// The value is 0 after transfer. The execution result is as follows:
// testTransfer view2 byteLength: 0
// testTransfer view3 byteLength: 0
```


### setCloneList<sup>11+</sup>

setCloneList(cloneList: Object[] | ArrayBuffer[]): void

Sets the task clone list. Before using this API, you must create a **Task** instance.

> **NOTE**<br>
> Currently, only clone is supported. This API must be used together with [@Sendable decorator](../../arkts-utils/arkts-sendable.md). Otherwise, an exception is thrown.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                     | Mandatory| Description                                         |
| --------- | ------------------------ | ---- | --------------------------------------------- |
| cloneList | Object[] \| ArrayBuffer[]  | Yes| - The type of the passed-in array must be [SendableClass](../../arkts-utils/arkts-sendable.md#basic-concepts) or ArrayBuffer.<br>- For **SendableClass** instances or **ArrayBuffer** objects held by all objects passed in to the clone list, the inter-thread transmission behavior changes to the clone operation. This means that any modification to the transmitted objects does not affect the original objects.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                       |
| -------- | -------------------------------------------------------------- |
| 10200029 | Can not set an arraybuffer to both transferList and cloneList. |

**Example**

```ts
import taskpool from '@ohos.taskpool'
import { BusinessError } from '@ohos.base'

@Sendable
class BaseClass {
  private str: string = "sendable: BaseClass";
  static num :number = 10;
  str1: string = "sendable: this is BaseClass's string";
  num1: number = 5;
  isDone1: boolean = false;

  private fibonacciRecursive(n: number): number {
    if (n <= 1) {
      return n;
    } else {
      return this.fibonacciRecursive(n - 1) + this.fibonacciRecursive(n - 2);
    }
  }

  private privateFunc(num: number): number{
    let res: number = this.fibonacciRecursive(num);
    console.info("sendable: BaseClass privateFunc res is: " + res);
    return res;
  }

  publicFunc(num: number): number {
    return this.privateFunc(num);
  }

  get GetNum(): number {
    return this.num1;
  }
  set SetNum(num: number) {
    this.num1 = num;
  }

  constructor(){
    console.info(this.str);
    this.isDone1 = true;
  }
}

@Sendable
class DeriveClass extends BaseClass {
  name: string = "sendable: this is DeriveClass";
  printName() {
    console.info(this.name);
  }
  constructor() {
    super();
  }
}

@Concurrent
function testFunc(arr: Array<BaseClass>, num: number): number {
  let baseInstance1 = arr[0];
  console.info("sendable: str1 is: " + baseInstance1.str1);
  baseInstance1.SetNum = 100;
  console.info("sendable: num1 is: " + baseInstance1.GetNum);
  console.info("sendable: isDone1 is: " + baseInstance1.isDone1);
  // Obtain the result of the item specified by num from Fibonacci sequence.
  let res: number = baseInstance1.publicFunc(num);
  return res;
}

@Concurrent
function printLog(arr: Array<DeriveClass>): void {
  let deriveInstance = arr[0];
  deriveInstance.printName();
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button() {
          Text("TaskPool Test")
        }.onClick(() => {
          // task1 calls BaseClass.str1/BaseClass.SetNum/BaseClass.GetNum/BaseClass.isDone1/BaseClass.publicFunc.
          let baseInstance1: BaseClass = new BaseClass();
          let array1 = new Array<BaseClass>();
          array1.push(baseInstance1);
          let task1 = new taskpool.Task(testFunc, array1, 10);
          task1.setCloneList(array1);
          taskpool.execute(task1).then((res: Object) => {
            console.info("sendable: task1 res is: " + res);
          }).catch((e:BusinessError) => {
            console.error(`sendable: task1 execute Code is ${e.code}, message is ${e.message}`);
          })

          // task2 calls DeriveClass.printName.
          let deriveInstance: DeriveClass = new DeriveClass();
          let array2 = new Array<DeriveClass>();
          array2.push(deriveInstance);
          let task2 = new taskpool.Task(printLog, array2);
          task2.setCloneList(array2);
          taskpool.execute(task2).then(() => {
            console.info("sendable: task2 execute success");
          }).catch((e:BusinessError) => {
            console.error(`sendable: task2 execute Code is ${e.code}, message is ${e.message}`);
          })
        })
        .height('15%')
        .width('30%')
      }
      .width('100%')
    }
    .height('100%')
  }
}
```


### sendData<sup>11+</sup>

static sendData(...args: Object[]): void

Sends data to the host thread and triggers the registered callback. Before using this API, you must create a **Task** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type         | Mandatory| Description                                             |
| -------- | ------------- | ---- | ------------------------------------------------- |
| args     | Object[]      | Yes  | Data to be used as the input parameter of the registered callback. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                |
| -------- | --------------------------------------- |
| 10200006  | An exception occurred during serialization. |
| 10200022  | The function is not called in the taskpool thread. |
| 10200023  | The function is not called in the concurrent function. |
| 10200024  | The callback is not registered on the host side. |

**Example**

```ts
@Concurrent
function ConcurrentFunc(num: number): number {
  let res: number = num * 10;
  taskpool.Task.sendData(res);
  return num;
}
```

### onReceiveData<sup>11+</sup>

onReceiveData(callback?: Function): void

Registers a callback for a task to receive and process data from the worker thread. Before using this API, you must create a **Task** instance.

> **NOTE**<br>
> If multiple callbacks are registered for the same task, only the last registration takes effect.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| callback | Function | No  | Callback function for processing the data received. The data sent to the host thread is transferred to the callback as an input parameter. If no value is passed in, all the registered callbacks are canceled.|

**Example**

```ts
@Concurrent
function ConcurrentFunc(num: number): number {
  let res: number = num * 10;
  taskpool.Task.sendData(res);
  return num;
}

function pringLog(data: number): void {
  console.info("taskpool: data is: " + data);
}

async function testFunc(): Promise<void> {
  try {
    let task: taskpool.Task = new taskpool.Task(ConcurrentFunc, 1);
    task.onReceiveData(pringLog);
    await taskpool.execute(task);
  } catch (e) {
    console.error(`taskpool: error code: ${e.code}, info: ${e.message}`);
  }
}

testFunc();
```

### addDependency<sup>11+</sup>

addDependency(...tasks: Task[]): void

Adds dependent tasks for this task. Before using this API, you must create a **Task** instance. The task and its dependent tasks cannot be a task in a task group or queue, or a task that has been executed. A task with a dependency relationship (a task that depends on another task or a task that is depended on) cannot be executed multiple times.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| tasks  | [Task](#task)[] | Yes  | Array of tasks on which the current task depends.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                       |
| -------- | ------------------------------- |
| 10200026 | There is a circular dependency. |

**Example**

```ts
@Concurrent
function delay(args: number): number {
  let t: number = Date.now();
  while ((Date.now() - t) < 1000) {
	continue;
  }
  return args;
}

let task1:taskpool.Task = new taskpool.Task(delay, 100);
let task2:taskpool.Task = new taskpool.Task(delay, 200);
let task3:taskpool.Task = new taskpool.Task(delay, 200);

console.info("dependency: add dependency start");
task1.addDependency(task2);
task2.addDependency(task3);
console.info("dependency: add dependency end");

console.info("dependency: start execute second")
taskpool.execute(task1).then(() => {
  console.info("dependency: second task1 success");
})
taskpool.execute(task2).then(() => {
  console.info("dependency: second task2 success");
})
taskpool.execute(task3).then(() => {
  console.info("dependency: second task3 success");
})
```

### removeDependency<sup>11+</sup>

removeDependency(...tasks: Task[]): void

Removes dependent tasks for this task. Before using this API, you must create a **Task** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| tasks  | [Task](#task)[] | Yes  | Array of tasks on which the current task depends.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 10200027 | The dependency does not exist. |

**Example**

```ts
@Concurrent
function delay(args: number): number {
  let t: number = Date.now();
  while ((Date.now() - t) < 1000) {
	continue;
  }
  return args;
}

let task1:taskpool.Task = new taskpool.Task(delay, 100);
let task2:taskpool.Task = new taskpool.Task(delay, 200);
let task3:taskpool.Task = new taskpool.Task(delay, 200);

console.info("dependency: add dependency start");
task1.addDependency(task2);
task2.addDependency(task3);
console.info("dependency: add dependency end");
console.info("dependency: remove dependency start");
task1.removeDependency(task2);
task2.removeDependency(task3);
console.info("dependency: remove dependency end");

console.info("dependency: start execute")
taskpool.execute(task1).then(() => {
  console.info("dependency: task1 success");
})
taskpool.execute(task2).then(() => {
  console.info("dependency: task2 success");
})
taskpool.execute(task3).then(() => {
  console.info("dependency: task3 success");
})
```

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name                | Type      | Readable| Writable| Description                                                        |
| -------------------- | --------- | ---- | ---- | ------------------------------------------------------------ |
| function             | Function  | Yes  | Yes  | Function to be passed in during task creation. For details about the supported return value types of the function, see [Sequenceable Data Types](#sequenceable-data-types).|
| arguments            | Object[]  | Yes  | Yes  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|
| name<sup>11+</sup>   | string    | Yes  | No  | Name of the task specified when the task is created.                                   |
| totalDuration<sup>11+</sup>  | number    | Yes  | No  | Total execution time of the task.                                   |
| ioDuration<sup>11+</sup>     | number    | Yes  | No  | Asynchronous I/O time of the task.                                   |
| cpuDuration<sup>11+</sup>    | number    | Yes  | No  | CPU time of the task.                                   |

## TaskGroup<sup>10+</sup>

Implements a task group, in which tasks are associated with each other and all tasks are executed at a time. If all the tasks are executed normally, an array of task results is returned asynchronously, and the sequence of elements in the array is the same as the sequence of tasks added by calling [addTask](#addtask10-1). If any task fails, the corresponding exception is thrown. A task group can be executed for multiple times, but no task can be added after the task group is executed. Before calling any APIs in **TaskGroup**, you must use [constructor](#constructor10) to create a **TaskGroup** instance.

### constructor<sup>10+</sup>

constructor()

Constructor used to create a **TaskGroup** instance.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let taskGroup = new taskpool.TaskGroup();
```

### constructor<sup>11+</sup>

constructor(name: string)

A constructor used to create a **TaskGroup** instance, with the task group name specified.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| name   | string | Yes  | Task group name.|

**Example**

```ts
let taskGroupName: string = "groupName";
let taskGroup: taskpool.TaskGroup = new taskpool.TaskGroup(taskGroupName);
let name: string = taskGroup.name;
```

### addTask<sup>10+</sup>

addTask(func: Function, ...args: Object[]): void

Adds the function to be executed to this task group. Before using this API, you must create a **TaskGroup** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type     | Mandatory| Description                                                                  |
| ------ | --------- | ---- | ---------------------------------------------------------------------- |
| func   | Function  | Yes  | Function to be executed. The function must be decorated using [@Concurrent decorator](../../arkts-utils/arkts-concurrent.md). For details about the supported return value types of the function, see [Sequenceable Data Types](#sequenceable-data-types).    |
| args   | Object[] | No  | Arguments of the function. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types). The default value is **undefined**.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                |
| -------- | --------------------------------------- |
| 10200014 | The function is not mark as concurrent. |

**Example**

```ts
@Concurrent
function printArgs(args: number): number {
  console.info("printArgs: " + args);
  return args;
}

let taskGroup: taskpool.TaskGroup = new taskpool.TaskGroup();
taskGroup.addTask(printArgs, 100); // 100: test number
```

### addTask<sup>10+</sup>

addTask(task: Task): void

Adds a created task to this task group. Before using this API, you must create a **TaskGroup** instance. Tasks in another task group or queue, dependent tasks, and tasks that have been executed cannot be added to the task group.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                 | Mandatory| Description                                      |
| -------- | --------------------- | ---- | ---------------------------------------- |
| task     | [Task](#task)         | Yes  | Task to be added to the task group.                 |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                |
| -------- | --------------------------------------- |
| 10200014 | The function is not mark as concurrent. |

**Example**

```ts
@Concurrent
function printArgs(args: number): number {
  console.info("printArgs: " + args);
  return args;
}

let taskGroup: taskpool.TaskGroup = new taskpool.TaskGroup();
let task: taskpool.Task = new taskpool.Task(printArgs, 200); // 200: test number
taskGroup.addTask(task);
```

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type  | Readable| Writable| Description                        |
| ---- | ------ | ---- | ---- | ---------------------------- |
| name<sup>11+</sup> | string | Yes  | Yes  | Name of the task group specified when the task group is created.|

## SequenceRunner <sup>11+</sup>

Implements a queue, in which all tasks are executed in sequence. Before calling any APIs in **SequenceRunner**, you must use [constructor](#constructor11-3) to create a **SequenceRunner** instance.

### constructor<sup>11+</sup>

constructor(priority?: Priority)

A constructor used to create a **SequenceRunner** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                 | Mandatory| Description                                                      |
| -------- | --------------------- | ---- | ---------------------------------------------------------- |
| priority | [Priority](#priority) | No  | Priority of the task. The default value is **taskpool.Priority.MEDIUM**.|

**Example**

```ts
let runner: taskpool.SequenceRunner = new taskpool.SequenceRunner();
```

### execute<sup>11+</sup>

execute(task: Task): Promise\<Object>

Adds a task to the queue for execution. Before using this API, you must create a **SequenceRunner** instance. Tasks in another task group or queue, dependent tasks, and tasks that have been executed cannot be added to the queue.

> **NOTE**
>
> - Tasks that depend others cannot be added to the queue.
> - The failure or cancellation of a task does not affect the execution of subsequent tasks in the queue.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type         | Mandatory| Description                            |
| ------ | ------------- | ---- | -------------------------------- |
| task   | [Task](#task) | Yes  | Task to be added to the queue.|

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise\<Object> | Promise used to return the task execution result.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 10200003 | Worker initialization failure.              |
| 10200006 | An exception occurred during serialization. |
| 10200025 | Add dependent task to SequenceRunner.       |

**Example**

```ts
@Concurrent
function additionDelay(delay:number): void {
  let start: number = new Date().getTime();
  while (new Date().getTime() - start < delay) {
    continue;
  }
}
@Concurrent
function waitForRunner(finalString: string): string {
  return finalString;
}
async function seqRunner()
{
  let finalString:string = "";
  let task1:taskpool.Task = new taskpool.Task(additionDelay, 3000);
  let task2:taskpool.Task = new taskpool.Task(additionDelay, 2000);
  let task3:taskpool.Task = new taskpool.Task(additionDelay, 1000);
  let task4:taskpool.Task = new taskpool.Task(waitForRunner, finalString);

  let runner:taskpool.SequenceRunner = new taskpool.SequenceRunner();
  runner.execute(task1).then(() => {
    finalString += 'a';
    console.info("seqrunner: task1 done.");
  });
  runner.execute(task2).then(() => {
    finalString += 'b';
    console.info("seqrunner: task2 done");
  });
  runner.execute(task3).then(() => {
    finalString += 'c';
    console.info("seqrunner: task3 done");
  });
  await runner.execute(task4);
  console.info("seqrunner: task4 done, finalString is " + finalString);
}
```

## State<sup>10+</sup>

Enumerates the task states. After a task is created and **execute()** is called, the task is placed in the internal queue of the task pool and the state is **WAITING**. When the task is being executed by the worker thread of the task pool, the state changes to **RUNNING**. After the task is executed and the result is returned, the state is reset to **WAITING**. When the task is proactively canceled, the state changes to **CANCELED**.

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
| name<sup>12+</sup> | string             | Yes  | No  | Task name.                                                    |
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
The following sequenceable data types are supported: All Primitive Type (excluding symbol), Date, String, RegExp, Array, Map, Set, Object, ArrayBuffer, and TypedArray. [Serialization Types Supported by TaskPool and Worker](../../arkts-utils/serialization-support-types.md)

### Using the Task Pool in Simple Mode

**Example 1**

```ts
// Common functions are supported, and variables passed in by input parameters are also supported.
@Concurrent
function printArgs(args: number): number {
  console.info("func: " + args);
  return args;
}
async function taskpoolExecute(): Promise<void> {
  // taskpool.execute(task)
  let task: taskpool.Task = new taskpool.Task(printArgs, "create task, then execute");
  console.info("taskpool.execute(task) result: " + await taskpool.execute(task));
  // taskpool.execute(function)
  console.info("taskpool.execute(function) result: " + await taskpool.execute(printArgs, "execute task by func"));
}
taskpoolExecute();
```

**Example 2**

```ts
// b.ets
export let c: string = "hello";
```
```ts
// Reference an imported variable.
// a.ets (in the same directory as b.ets)
import { c } from "./b";

@Concurrent
function printArgs(a: string): string {
    console.info(a);
    console.info(c);
    return a;
}

async function taskpoolExecute(): Promise<void> {
  // taskpool.execute(task)
  let task: taskpool.Task = new taskpool.Task(printArgs, "create task, then execute");
  console.info("taskpool.execute(task) result: " + await taskpool.execute(task));

  // taskpool.execute(function)
  console.info("taskpool.execute(function) result: " + await taskpool.execute(printArgs, "execute task by func"));
}

taskpoolExecute();
```

**Example 3**

```ts
// The async functions are supported.
@Concurrent
async function delayExcute(): Promise<Object> {
  let ret = await Promise.all<Object>([
    new Promise<Object>(resolve => setTimeout(resolve, 1000, "resolved"))
  ]);
  return ret;
}

async function taskpoolExecute(): Promise<void> {
  taskpool.execute(delayExcute).then((result: Object) => {
    console.info("taskPoolTest task result: " + result);
  }).catch((err: string) => {
    console.error("taskpool test occur error: " + err);
  });
}

taskpoolExecute();
```

**Example 4**

```ts
// c.ets
import taskpool from '@ohos.taskpool';

@Concurrent
function strSort(inPutArr: Array<string>): Array<string> {
  let newArr = inPutArr.sort();
  return newArr;
}
export async function func1(): Promise<void> {
  console.info("taskpoolTest start");
  let strArray: Array<string> = ['c test string', 'b test string', 'a test string'];
  let task: taskpool.Task = new taskpool.Task(strSort, strArray);
  console.info("func1 result:" + await taskpool.execute(task));
}

export async function func2(): Promise<void> {
  console.info("taskpoolTest2 start");
  let strArray: Array<string> = ['c test string', 'b test string', 'a test string'];
  taskpool.execute(strSort, strArray).then((result: Object) => {
    console.info("func2 result: " + result);
  }).catch((err: string) => {
    console.error("taskpool test occur error: " + err);
  });
}
```

```ts
// index.ets
import { func1, func2 } from "./c";

func1();
func2();
```

**Example 5**

```ts
// Success in canceling a task
@Concurrent
function inspectStatus(arg: number): number {
  // Check whether the task has been canceled and respond accordingly.
  if (taskpool.Task.isCanceled()) {
    console.info("task has been canceled before 2s sleep.");
    return arg + 2;
  }
  // 2s sleep
  let t: number = Date.now();
  while (Date.now() - t < 2000) {
    continue;
  }
  // Check again whether the task has been canceled and respond accordingly.
  if (taskpool.Task.isCanceled()) {
    console.info("task has been canceled after 2s sleep.");
    return arg + 3;
  }
  return arg + 1;
}

async function taskpoolCancel(): Promise<void> {
  let task: taskpool.Task = new taskpool.Task(inspectStatus, 100); // 100: test number
  taskpool.execute(task).then((res: Object)=>{
    console.info("taskpool test result: " + res);
  }).catch((err: string) => {
    console.error("taskpool test occur error: " + err);
  });
  // Cancel the task 1s later.
  setTimeout(()=>{
    try {
      taskpool.cancel(task);
    } catch (e) {
      console.error(`taskpool: cancel error code: ${e.code}, info: ${e.message}`);
    }
  }, 1000);
}

taskpoolCancel();
```

**Example 6**

```ts
// Failure to cancel a task that has been executed
@Concurrent
function inspectStatus(arg: number): number {
  // Check whether the task has been canceled and respond accordingly.
  if (taskpool.Task.isCanceled()) {
    return arg + 2;
  }
  // Wait for 2s.
  let t: number = Date.now();
  while (Date.now() - t < 500) {
    continue;
  }
  // Check again whether the task has been canceled and respond accordingly.
  if (taskpool.Task.isCanceled()) {
    return arg + 3;
  }
  return arg + 1;
}

async function taskpoolCancel(): Promise<void> {
  let task: taskpool.Task = new taskpool.Task(inspectStatus, 100); // 100: test number
  taskpool.execute(task).then((res: Object)=>{
    console.info("taskpool test result: " + res);
  }).catch((err: string) => {
    console.error("taskpool test occur error: " + err);
  });

  setTimeout(()=>{
    try {
      taskpool.cancel(task); // The task has been executed and fails to be canceled.
    } catch (e) {
      console.error(`taskpool: cancel error code: ${e.code}, info: ${e.message}`);
    }
  }, 3000); // Wait for 3s to ensure that the task has been executed.
}

taskpoolCancel();
```

**Example 7**

```ts
// Success of canceling a task group to be executed
@Concurrent
function printArgs(args: number): number {
  let t: number = Date.now();
  while (Date.now() - t < 1000) {
    continue;
  }
  console.info("printArgs: " + args);
  return args;
}

async function taskpoolGroupCancelTest(): Promise<void> {
  let taskGroup1: taskpool.TaskGroup = new taskpool.TaskGroup();
  taskGroup1.addTask(printArgs, 10); // 10: test number
  taskGroup1.addTask(printArgs, 20); // 20: test number
  taskGroup1.addTask(printArgs, 30); // 30: test number
  let taskGroup2: taskpool.TaskGroup = new taskpool.TaskGroup();
  let task1: taskpool.Task = new taskpool.Task(printArgs, 100); // 100: test number
  let task2: taskpool.Task = new taskpool.Task(printArgs, 200); // 200: test number
  let task3: taskpool.Task = new taskpool.Task(printArgs, 300); // 300: test number
  taskGroup2.addTask(task1);
  taskGroup2.addTask(task2);
  taskGroup2.addTask(task3);
  taskpool.execute(taskGroup1).then((res: Array<Object>) => {
    console.info("taskpool execute res is:" + res);
  }).catch((e: string) => {
    console.error("taskpool execute error is:" + e);
  });
  taskpool.execute(taskGroup2).then((res: Array<Object>) => {
    console.info("taskpool execute res is:" + res);
  }).catch((e: string) => {
    console.error("taskpool execute error is:" + e);
  });

  try {
    taskpool.cancel(taskGroup2);
  } catch (e) {
    console.error(`taskpool: cancel error code: ${e.code}, info: ${e.message}`);
  }
}

taskpoolGroupCancelTest()
```

**Example 8**

```ts
// Create and execute 100 tasks with different priorities, and view their information.
@Concurrent
function delay(): void {
  let start: number = new Date().getTime();
  while (new Date().getTime() - start < 500) {
    continue;
  }
}

let highCount: number = 0;
let mediumCount: number = 0;
let lowCount: number = 0;
let allCount: number = 100;
for (let i = 0; i < allCount; i++) {
  let task1: taskpool.Task = new taskpool.Task(delay);
  let task2: taskpool.Task = new taskpool.Task(delay);
  let task3: taskpool.Task = new taskpool.Task(delay);
  taskpool.execute(task1, taskpool.Priority.LOW).then(() => {
    lowCount++;
  }).catch((e: string) => {
    console.error("low task error: " + e);
  })
  taskpool.execute(task2, taskpool.Priority.MEDIUM).then(() => {
    mediumCount++;
  }).catch((e: string) => {
    console.error("medium task error: " + e);
  })
  taskpool.execute(task3, taskpool.Priority.HIGH).then(() => {
    highCount++;
  }).catch((e: string) => {
    console.error("high task error: " + e);
  })
}
let start: number = new Date().getTime();
while (new Date().getTime() - start < 1000) {
  continue;
}
let taskpoolInfo: taskpool.TaskPoolInfo = taskpool.getTaskPoolInfo();
let tid: number = 0;
let taskIds: Array<number> = [];
let priority: number = 0;
let taskId: number = 0;
let state: number = 0;
let duration: number = 0;
let name: string = "";
let threadIS = Array.from(taskpoolInfo.threadInfos)
for(let threadInfo of threadIS) {
  tid = threadInfo.tid;
  if (threadInfo.taskIds != undefined && threadInfo.priority != undefined )
  {
    taskIds.length = threadInfo.taskIds.length;
    priority = threadInfo.priority;
  }
  console.info("taskpool---tid is:" + tid + ", taskIds is:" + taskIds + ", priority is:" + priority);
}
let taskIS = Array.from(taskpoolInfo.taskInfos)
for(let taskInfo of taskIS) {
  taskId = taskInfo.taskId;
  state = taskInfo.state;
  if (taskInfo.duration != undefined )
  {
    duration = taskInfo.duration;
    name = taskInfo.name;
  }
  console.info("taskpool---taskId is:" + taskId + ", state is:" + state + ", duration is:" + duration + ", name is:" + name);
}
```
