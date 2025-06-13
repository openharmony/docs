# taskpool (启动任务池)

任务池（taskpool）作用是为应用程序提供一个多线程的运行环境，降低整体资源的消耗、提高系统的整体性能，且您无需关心线程实例的生命周期。您可以使用任务池API创建后台任务（Task），并对所创建的任务进行如任务执行、任务取消的操作。此外，不建议您在任务中执行阻塞操作，特别是无限期阻塞操作，长时间的阻塞操作占据工作线程，可能会阻塞其他任务调度，影响您的应用性能。

您所创建的同一优先级任务的执行顺序可以由您决定，任务真实执行的顺序与您调用任务池API提供的任务执行接口顺序一致。任务默认优先级是MEDIUM。

ArkTS1.2内存天然共享，无需使用 `@Sendable` 装饰器。

文档中涉及到的各种任务概念：
- 任务组任务：对应为[TaskGroup](#taskgroup)任务。
- 串行队列任务：对应为[SequenceRunner](#sequencerunner)任务。
- 周期任务：被[executePeriodically](#taskpoolexecuteperiodically)执行过的任务。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## taskpool.execute

execute(func: Function, ...args: NullishType[]): Promise\<NullishType>

将待执行的函数放入taskpool内部任务队列，函数不会立即执行，而是等待分发到工作线程执行。当前执行模式不可取消任务。使用Promise异步回调。

**参数：**

| 参数名  | 类型      | 必填 | 说明                           |
| ------ | --------- | ---- | ----------------------------- |
| func   | Function  | 是   | 执行的逻辑需要传入参数。     |
| args   | NullishType[] | 否   | 执行逻辑的函数所需要的入参。默认值为undefined。 |

**返回值：**

| 类型                    | 说明                                |
| ---------------------- | ----------------------------------- |
| Promise\<NullishType>  | Promise对象，返回任务函数的执行结果。  |

**示例：**

```ts
import hilog from '@ohos.hilog';

function printArgs(args: number): number {
    hilog.info(0x0000, "testTag", "printArgs: " + args);
    return args;
}

taskpool.execute(printArgs, 100.0).then((value: NullishType) => {
  hilog.info(0x0000, "testTag", "taskpool result: " + value);
});
```

## taskpool.execute

execute(task: Task, priority?: Priority): Promise\<NullishType>

将创建好的任务放入taskpool内部任务队列，任务不会立即执行，而是等待分发到工作线程执行。当前执行模式可以设置任务优先级和尝试调用cancel进行任务取消。该任务不可以是任务组任务、串行队列任务和已执行的任务。该任务仅支持执行一次。使用Promise异步回调。

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                       |
| -------- | --------------------- | ---- | ---------------------------------------- |
| task     | [Task](#task)         | 是   | 需要在任务池中执行的任务。                  |
| priority | [Priority](#priority) | 否   | 等待执行的任务的优先级，该参数默认值为taskpool.Priority.MEDIUM。 |

**返回值：**

| 类型              | 说明              |
| ----------------  | ---------------- |
| Promise\<NullishType> | Promise对象，返回任务函数的执行结果。 |

**错误信息：**

| 错误信息                                     | 说明                                     |
| ------------------------------------------- | ---------------------------------------- |
| groupTask cannot execute outside. | 不能执行任务组任务。<br>可能原因：执行的任务是任务组任务。<br>处理步骤：调用时，确保任务不是任务组任务。无法保证时，需捕获异常。 |
| seqRunnerTask cannot execute outside. | 不能执行串行队列任务。<br>可能原因：执行的任务是串行队列任务。<br>处理步骤：调用时，确保任务不是串行队列任务。无法保证时，需捕获异常。 |
| executedTask with dependency cannot execute again. | 有依赖关系的已执行任务不能被再次执行。<br>可能原因：执行的任务是有依赖关系的已执行任务。<br>处理步骤：调用时，确保任务不是已执行的任务。无法保证时，需捕获异常。 |
| task has been executed. | 任务已被执行。<br>可能原因：该任务已被执行过。<br>处理步骤：执行任务前确保任务未被执行过。无法保证时，需捕获异常。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function printArgs(args: number): number {
    hilog.info(0x0000, "testTag", "printArgs: " + args);
    return args;
}

let task1: taskpool.Task = new taskpool.Task(printArgs, 100.0);
let task2: taskpool.Task = new taskpool.Task(printArgs, 200.0);
let task3: taskpool.Task = new taskpool.Task(printArgs, 300.0);
taskpool.execute(task1, taskpool.Priority.LOW).then((value: NullishType) => {
  hilog.info(0x0000, "testTag", "taskpool result1: " + value);
});
taskpool.execute(task2, taskpool.Priority.MEDIUM).then((value: NullishType) => {
  hilog.info(0x0000, "testTag", "taskpool result2: " + value);
});
taskpool.execute(task3, taskpool.Priority.HIGH).then((value: NullishType) => {
  hilog.info(0x0000, "testTag", "taskpool result3: " + value);
});
```

## taskpool.execute

execute(group: TaskGroup, priority?: Priority): Promise\<Array\<NullishType>>

将创建好的任务组放入taskpool内部任务队列，任务组中的任务不会立即执行，而是等待分发到工作线程执行。任务组中任务全部执行完成后，结果数组统一返回。当前执行模式适用于执行一组有关联的任务。该任务组仅支持执行一次。使用Promise异步回调。

**参数：**

| 参数名     | 类型                        | 必填 | 说明                                                           |
| --------- | --------------------------- | ---- | -------------------------------------------------------------- |
| group     | [TaskGroup](#taskgroup)     | 是   | 需要在任务池中执行的任务组。                                      |
| priority  | [Priority](#priority)       | 否   | 等待执行的任务组的优先级，该参数默认值为taskpool.Priority.MEDIUM。 |

**返回值：**

| 类型                            | 说明                               |
| ---------------------------    | ---------------------------------- |
| Promise\<Array\<NullishType>>  | Promise对象数组，返回任务函数的执行结果。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function printArgs(args: number): number {
    hilog.info(0x0000, "testTag", "printArgs: " + args);
    return args;
}

let taskGroup1: taskpool.TaskGroup = new taskpool.TaskGroup();
taskGroup1.addTask(printArgs, 10.0);
taskGroup1.addTask(printArgs, 20.0);
taskGroup1.addTask(printArgs, 30.0);

let taskGroup2: taskpool.TaskGroup = new taskpool.TaskGroup();
let task1: taskpool.Task = new taskpool.Task(printArgs, 100.0);
let task2: taskpool.Task = new taskpool.Task(printArgs, 200.0);
let task3: taskpool.Task = new taskpool.Task(printArgs, 300.0);
taskGroup2.addTask(task1);
taskGroup2.addTask(task2);
taskGroup2.addTask(task3);
taskpool.execute(taskGroup1).then((res: Array<NullishType>) => {
  hilog.info(0x0000, "testTag", "taskpool execute res is:" + res);
});
taskpool.execute(taskGroup2).then((res: Array<NullishType>) => {
  hilog.info(0x0000, "testTag", "taskpool execute res is:" + res);
});
```

## taskpool.executeDelayed

executeDelayed(delayTime: number, task: Task, priority?: Priority): Promise\<NullishType>

延时执行任务。当前执行模式可以设置任务优先级和尝试调用cancel进行任务取消。该任务不可以是任务组任务、串行队列任务、周期任务和已执行的任务。该任务仅支持执行一次。使用Promise异步回调。

**参数：**

| 参数名       | 类型          | 必填  | 说明                 |
| ----------- | ------------- | ---- | -------------------- |
| delayTime   | number        | 是   | 延时时间。单位为ms。不可以为负值。 |
| task        | [Task](#task) | 是   | 需要延时执行的任务。 |
| priority    | [Priority](#priority)  | 否  | 延时执行的任务的优先级，该参数默认值为taskpool.Priority.MEDIUM。|

**返回值：**

| 类型                 | 说明                               |
| ------------------- | ---------------------------------- |
| Promise\<NullishType>  | Promise对象，返回任务函数的执行结果。 |

**错误信息：**

| 错误信息                         | 说明                                      |
| -------------------------------- | ---------------------------------------- |
| The delayTime is less than zero. | 延时时间小于零。<br>可能原因：给定参数delayTime的值小于零。<br>处理步骤：调用时，确保给定参数delayTime的值大于等于零。无法保证时，需要捕获异常。  |
| groupTask cannot executeDelayed outside. | 不能延时执行任务组任务。<br>可能原因：执行的任务是任务组任务。<br>处理步骤：调用时，确保任务不是任务组任务。无法保证时，需捕获异常。 |
| seqRunnerTask cannot executeDelayed outside. | 不能延时执行串行队列任务。<br>可能原因：执行的任务是串行队列任务。<br>处理步骤：调用时，确保任务不是串行队列任务。无法保证时，需捕获异常。 |
| executedTask with dependency cannot execute again. | 有依赖关系的已执行任务不能再次执行。<br>可能原因：执行的任务是有依赖关系且已执行的。<br>处理步骤：执行任务前确保任务未被执行过。无法保证时，需捕获异常。 |
| the periodicTask cannot executeDelayed. | 周期任务不能延时执行。<br>可能原因：该任务是周期任务。<br>处理步骤：执行任务前确保不是周期任务。无法保证时，需捕获异常。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function printArgs(args: number): void {
    hilog.info(0x0000, "testTag", "printArgs: " + args);
}

let task: taskpool.Task = new taskpool.Task(printArgs, 100.0);
taskpool.executeDelayed(1000.0, task).then((res: NullishType) => {
  hilog.info(0x0000, "testTag", "taskpool execute success");
}).catch((e) => {
  hilog.info(0x0000, "testTag", "taskpool execute occur error: " + e);
})
```

## taskpool.executePeriodically

executePeriodically(period: number, task: Task, priority?: Priority): void

周期执行任务，每隔period时长执行一次任务。当前执行模式支持设置任务优先级和调用cancel取消任务周期执行。周期任务不可以是任务组任务、串行队列任务和已执行的任务，不可以再次调用执行接口，不可以拥有依赖关系。

**参数：**

| 参数名        | 类型          | 必填  | 说明                 |
| -----------  | ------------- | ----- | -------------------- |
| period       | number        | 是    | 周期时长。单位为ms。不可以为负值。  |
| task         | [Task](#task) | 是    | 需要周期执行的任务。 |
| priority     | [Priority](#priority) | 否   | 周期执行的任务的优先级，该参数默认值为taskpool.Priority.MEDIUM。 |

**错误信息：**

| 错误信息                       | 说明                                    |
| ----------------------------- | --------------------------------------- |
| The period value is less than zero. | 周期执行间隔时间小于零。<br>可能原因：给定参数period的值小于零。<br>处理步骤：调用时，确保给定参数period的值大于等于零。无法保证时，需要捕获异常。   |
| The concurrent task has been executed and cannot be executed periodically. | 已执行的任务不能再周期执行。<br>可能原因：调用该接口时，传入已执行的任务。<br>处理步骤：执行任务前确保任务未被执行过。无法保证时，需捕获异常。 |
| the task with dependency cannot executePeriodically. | 有依赖关系的任务不能周期执行。<br>可能原因：调用该接口时，传入有依赖关系的任务。<br>处理步骤：执行任务前确保任务无依赖关系。无法保证时，需捕获异常。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function printArgs(args: number): void {
  hilog.info(0x0000, "testTag", "printArgs: " + args);
}

function testExecutePeriodically(args: number): void {
  let t = Date.now();
  while ((Date.now() - t) < args) {}
  taskpool.Task.sendData(args); // 向宿主线程发送消息
}

function printResult(data: number): void {
  hilog.info(0x0000, "testTag", "taskpool: data is: " + data);
}

function taskpoolTest() {
  try {
    let task: taskpool.Task = new taskpool.Task(printArgs, 100.0);
    taskpool.executePeriodically(1000.0, task);
  } catch (e) {
    hilog.info(0x0000, "testTag", "taskpool execute-1: error: " + e);
  }

  try {
    let periodicTask: taskpool.Task = new taskpool.Task(testExecutePeriodically, 200.0);
    periodicTask.onReceiveData(printResult);
    taskpool.executePeriodically(1000.0, periodicTask);
  } catch (e) {
    hilog.info(0x0000, "testTag", "taskpool execute-2: error: " + e);
  }
}

taskpoolTest();
```

## taskpool.cancel

cancel(task: Task): void

取消任务池中的任务。当任务在taskpool等待队列中，取消该任务后该任务将不再执行，并返回任务被取消的异常；当任务已经在taskpool工作线程执行，取消该任务并不影响任务继续执行，执行结果在catch分支返回，搭配isCanceled使用可以对任务取消行为作出响应。taskpool.cancel对其之前的taskpool.execute/taskpool.executeDelayed生效。

**参数：**

| 参数名  | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| task   | [Task](#task) | 是   | 需要取消执行的任务。 |

**错误信息：**

| 错误信息                            | 说明                               |
| ---------------------------------- | ---------------------------------- |
| sequenceRunner task has been executed. | 串行队列任务已执行完成。<br>可能原因：取消已执行完成的串行队列任务。<br>处理步骤：取消任务前，确保任务不是已执行完成的串行队列任务。无法保证时，需要捕获异常。  |
| task is not executed or has been executed. | 任务未通过调用taskpool.execute等接口开始执行或已执行完。<br>可能原因：取消的任务未通过调用taskpool.execute等接口开始执行或者已执行完成。<br>：取消任务前，确保任务已执行且未执行结束。无法保证时，需要捕获异常。 |

**正在执行的任务取消示例：**

```ts
import hilog from '@ohos.hilog';

function inspectStatus(arg: number): number {
  // 第一次检查任务是否已经取消并作出响应
  if (taskpool.Task.isCanceled()) {
    hilog.info(0x0000, "testTag", "task has been canceled before 2s sleep.");
    return arg + 2;
  }
  // 2s sleep
  let t = Date.now();
  while (Date.now() - t < 2000) {}
  // 第二次检查任务是否已经取消并作出响应
  if (taskpool.Task.isCanceled()) {
    hilog.info(0x0000, "testTag", "task has been canceled after 2s sleep.");
    return arg + 3;
  }
  return arg + 1;
}

function concurrentFunc() {
  let task1: taskpool.Task = new taskpool.Task(inspectStatus, 100.0);
  let task2: taskpool.Task = new taskpool.Task(inspectStatus, 200.0);
  let task3: taskpool.Task = new taskpool.Task(inspectStatus, 300.0);
  let task4: taskpool.Task = new taskpool.Task(inspectStatus, 400.0);
  let task5: taskpool.Task = new taskpool.Task(inspectStatus, 500.0);
  let task6: taskpool.Task = new taskpool.Task(inspectStatus, 600.0);
  taskpool.execute(task1).then((res: NullishType) => {
    hilog.info(0x0000, "testTag", "taskpool test result: " + res);
  });
  taskpool.execute(task2);
  taskpool.execute(task3);
  taskpool.execute(task4);
  taskpool.execute(task5);
  taskpool.execute(task6);
  // 1s后取消task
  setTimeout(() => {
    try {
      taskpool.cancel(task1);
    } catch (e) {
      hilog.info(0x0000, "testTag", "taskpool: cancel error: " + e);
    }
  }, 1000);
}

concurrentFunc();
```

## taskpool.cancel

cancel(group: TaskGroup): void

取消任务池中的任务组。当一个任务组的任务未全部执行结束时取消任务组，返回undefined作为任务组结果。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                 |
| ------- | ----------------------- | ---- | -------------------- |
| group   | [TaskGroup](#taskgroup) | 是   | 需要取消执行的任务组。 |

**错误信息：**

| 错误信息                                           | 说明                                 |
| ------------------------------------------------- | ------------------------------------ |
| taskGroup is not executed or has been executed.   | 取消一个未通过调用taskpool.execute开始执行或已执行完的任务组。<br>可能原因：取消任务组时，该任务组并不存在于任务池中。<br>处理步骤：取消任务组前，确保任务组已被taskpool.execute调用进入任务池且任务组内存在任务未执行完成。无法保证时，需要捕获异常。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function printArgs(args: number): number {
  let t = Date.now();
  while ((Date.now() - t) < 2000) {}
  hilog.info(0x0000, "testTag", "printArgs: " + args);
  return args;
}

function concurrentFunc() {
  let taskGroup1: taskpool.TaskGroup = new taskpool.TaskGroup();
  taskGroup1.addTask(printArgs, 10.0);
  let taskGroup2: taskpool.TaskGroup = new taskpool.TaskGroup();
  taskGroup2.addTask(printArgs, 100.0);
  taskpool.execute(taskGroup1).then((res: Array<NullishType>) => {
    hilog.info(0x0000, "testTag", "taskGroup1 res is:" + res);
  });
  taskpool.execute(taskGroup2).then((res: Array<NullishType>) => {
    hilog.info(0x0000, "testTag", "taskGroup2 res is:" + res);
  });
  setTimeout(() => {
    try {
      taskpool.cancel(taskGroup2);
    } catch (e) {
      hilog.info(0x0000, "testTag", "taskpool: cancel error: " + e);
    }
  }, 1000);
}

concurrentFunc();
```

## taskpool.getTaskPoolInfo

getTaskPoolInfo(): TaskPoolInfo

获取任务池内部信息，包含线程信息和任务信息。

**返回值：**

| 类型                             | 说明               |
| ------------------------------- | ------------------ |
| [TaskPoolInfo](#taskpoolinfo)   | 任务池的内部信息。   |

**示例：**

```ts
let taskpoolInfo: taskpool.TaskPoolInfo = taskpool.getTaskPoolInfo();
```

## Priority

表示所创建任务(Task)执行时的优先级。

| 名称      | 值       | 说明     |
| -------- | -------- | -------- |
| HIGH     | 0        | 任务为高优先级。 |
| MEDIUM   | 1        | 任务为中优先级。 |
| LOW      | 2        | 任务为低优先级。 |
| IDLE     | 3        | 任务为后台任务。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function printArgs(args: number): number {
  let t = Date.now();
  // 延时1s
  while (Date.now() - t < 1000) {}
  hilog.info(0x0000, "testTag", "printArgs: " + args);
  return args;
}

let allCount = 100; // 100: test number
let taskArray: Array<taskpool.Task> = [];
// 创建400个任务并添加至taskArray
for (let i = 0; i < allCount; i++) {
  let task1: taskpool.Task = new taskpool.Task(printArgs, i * 1.0);
  taskArray.push(task1);
  let task2: taskpool.Task = new taskpool.Task(printArgs, i * 10.0);
  taskArray.push(task2);
  let task3: taskpool.Task = new taskpool.Task(printArgs, i * 100.0);
  taskArray.push(task3);
  let task4: taskpool.Task = new taskpool.Task(printArgs, i * 1000.0);
  taskArray.push(task4);
}

// 从taskArray中获取不同的任务并给定不同优先级执行
for (let i = 0; i < taskArray.length; i+=4) { // 4: 每次执行4个任务，循环取任务时需后移4项，确保执行的是不同的任务
  taskpool.execute(taskArray[i], taskpool.Priority.HIGH);
  taskpool.execute(taskArray[i + 1], taskpool.Priority.LOW);
  taskpool.execute(taskArray[i + 2], taskpool.Priority.MEDIUM);
  taskpool.execute(taskArray[i + 3], taskpool.Priority.IDLE);
}
```

## Task

表示任务。使用[constructor](#constructor)方法构造Task。任务可以单次执行或放入任务组执行或放入串行队列执行或添加依赖关系执行。

### 属性

| 名称              | 类型           | 只读 | 可选 | 说明                                                         |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| f                | () => NullishType  | 否   | 否   | 创建任务时需要传入的函数。 |
| arguments        | NullishType[]  | 否   | 是   | 创建任务传入函数所需的参数。默认值为undefined。 |
| name             | string         | 否   | 否   | 创建任务时指定的任务名称。无长度限制和其他格式要求。 |
| totalDuration    | number         | 否   | 否   | 执行任务总耗时。单位为ms。当任务未执行时值为0，当任务执行后为任务执行的实际总耗时。 |
| ioDuration       | number         | 否   | 否   | 执行任务异步IO耗时。单位为ms。当任务未执行时值为0，当任务执行后为任务执行的实际异步IO耗时。 |
| cpuDuration      | number         | 否   | 否   | 执行任务CPU耗时。单位为ms。当任务未执行时值为0，当任务执行后为任务执行的实际异步CPU耗时。 |

### constructor

constructor(func: Function, ...args: NullishType[])

Task的构造函数。

**参数：**

| 参数名  | 类型      | 必填 | 说明                                                                  |
| ------ | --------- | ---- | -------------------------------------------------------------------- |
| func   | Function  | 是   | 执行的逻辑需要传入函数。     |
| args   | NullishType[] | 否   | 任务执行传入函数的入参。默认值为undefined。  |

**示例：**

```ts
import hilog from '@ohos.hilog';

function printArgs(args: number): number {
  hilog.info(0x0000, "testTag", "printArgs: " + args);
  return args;
}

let task: taskpool.Task = new taskpool.Task(printArgs, 100.0);
```

### constructor

constructor(name: string, func: Function, ...args: NullishType[])

Task的构造函数，可以指定任务名称。

**参数：**

| 参数名  | 类型          | 必填 | 说明                                           |
| ------ | ------------- | ---- | --------------------------------------------- |
| name   | string        | 是   | 任务名称。无长度限制和其他格式要求。             |
| func   | Function      | 是   | 执行的逻辑需要传入函数。     |
| args   | NullishType[] | 否   | 任务执行传入函数的入参。默认值为undefined。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function printArgs(args: number): number {
  hilog.info(0x0000, "testTag", "printArgs: " + args);
  return args;
}

let taskName: string = "taskName";
let task: taskpool.Task = new taskpool.Task(taskName, printArgs, 100.0);
let name: string = task.name;
```

### isCanceled

static isCanceled(): boolean

检查当前正在运行的任务是否已取消。使用该方法前需要先构造Task。

**返回值：**

| 类型    | 说明                                 |
| ------- | ------------------------------------ |
| boolean | 如果当前正在运行的任务被取消返回true，未被取消返回false。|

**示例：**

```ts
function inspectStatus(arg: number): number {
    if (taskpool.Task.isCanceled()) {
      return arg + 1;
    }
    return arg;
}
```

> **说明：**
>
> isCanceled方法需要和taskpool.cancel方法搭配使用，如果不调用cancel方法，isCanceled方法默认返回false。

**示例：**

```ts
import hilog from '@ohos.hilog';

function inspectStatus(arg: number): number {
  // 第一次检查任务是否已经取消并作出响应
  if (taskpool.Task.isCanceled()) {
    hilog.info(0x0000, "testTag", "task has been canceled before 2s sleep.");
    return arg + 2;
  }
  // 延时2s
  let t = Date.now();
  while (Date.now() - t < 2000) {}
  // 第二次检查任务是否已经取消并作出响应
  if (taskpool.Task.isCanceled()) {
    hilog.info(0x0000, "testTag", "task has been canceled after 2s sleep.");
    return arg + 3;
  }
  return arg + 1;
}

let task: taskpool.Task = new taskpool.Task(inspectStatus, 100.0);
taskpool.execute(task).then((res: NullishType) => {
  hilog.info(0x0000, "testTag", "taskpool test result: " + res);
}).catch((err) => {
  hilog.info(0x0000, "testTag", "taskpool test occur error: " + err);
});
// 不调用cancel，isCanceled()默认返回false，task执行的结果为101
```

### sendData

static sendData(...args: Object[]): void

在任务执行过程中向宿主线程发送消息并触发回调。使用该方法前需要先构造Task。

> **说明：**
>
> - 该接口在taskpool的线程中调用。
> - 避免在回调函数中使用该方法。
> - 调用该接口时确保处理数据的回调函数在宿主线程已注册。

**参数：**

| 参数名    | 类型          | 必填 | 说明                              |
| -------- | ------------- | ---- | --------------------------------- |
| args     | Object[]      | 否   | 回调函数的参数。默认值为undefined。 |

**错误信息：**

| 错误信息                                 | 说明                                       |
| --------------------------------------- | ---------------------------------------    |
| The function is not called in the TaskPool thread. | 该函数未在任务池的线程中调用。<br>可能原因：在UI主线程中或在非taskpool的其他线程中调用该函数。<br>处理步骤：调用时，确保并发函数执行在taskpool线程中。无法保证时，需要捕获异常。 |
| The callback is not registered on the host side. | 该函数使用时未在宿主线程注册回调函数。<br>可能原因：该函数使用时未在宿主线程注册回调函数。<br>处理步骤：调用时，确保函数在宿主线程已注册。无法保证时，需要捕获异常。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function sendDataTest(num: number): number {
  let res = num * 10;
  taskpool.Task.sendData(res);
  return num;
}

function printLog(data: number): void {
  hilog.info(0x0000, "testTag", "taskpool: data is: " + data);
}

async function taskpoolTest(): Promise<void> {
  try {
    let task: taskpool.Task = new taskpool.Task(sendDataTest, 1.0);
    task.onReceiveData(printLog);
    await taskpool.execute(task);
  } catch (e) {
    hilog.info(0x0000, "testTag", "taskpool error: " + e);
  }
}

taskpoolTest();
```

### onReceiveData

onReceiveData(callback?: Function): void

为任务注册回调函数，以接收和处理来自任务池工作线程的数据。使用该方法前需要先构造Task。

> **说明：**
>
> 不支持给同一个任务定义多种回调函数，如果重复赋值只有最后一个会生效。

**参数：**

| 参数名    | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| callback | Function | 否   | 处理数据的回调函数，发送到宿主线程的数据将会作为入参传入该回调函数。不传参可以取消注册的回调函数。默认值为undefined。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function ConcurrentFunc(num: number): number {
  let res = num * 10;
  taskpool.Task.sendData(res);
  return num;
}

function printLog(data: number): void {
  hilog.info(0x0000, "testTag", "taskpool: data is: " + data);
}

async function testFunc(): Promise<void> {
  try {
    let task: taskpool.Task = new taskpool.Task(ConcurrentFunc, 1.0);
    task.onReceiveData(printLog);
    await taskpool.execute(task);
  } catch (e) {
    hilog.info(0x0000, "testTag", "taskpool error: " + e);
  }
}

testFunc();
```

### addDependency

addDependency(...tasks: Task[]): void

为当前任务添加对其他任务的依赖。使用该方法前需要先构造Task。该任务和被依赖的任务不可以是任务组任务、串行队列任务、已执行的任务和周期任务。存在依赖关系的任务(依赖其他任务的任务或被依赖的任务)执行后不可以再次执行。

**参数：**

| 参数名 | 类型             | 必填 | 说明               |
| ------ | --------------- | ---- | ------------------ |
| tasks  | [Task](#task)[] | 否   | 被依赖的任务数组。默认值为undefined。 |

**错误信息：**

| 错误信息                         | 说明                                      |
| ------------------------------- | ---------------------------------------- |
| There is a circular dependency. | 当前任务存在循环依赖关系。<br>可能原因：当前任务存在循环依赖关系。<br>处理步骤：排查找到循环依赖关系的相关任务，根据实际情况使用removeDependency()删除不需要的依赖关系，确保所有任务中不存在循环依赖关系。无法保证时，需要捕获异常。 |
| addDependency has no params. | 调用该函数未传参。<br>可能原因：调用该函数未传需要被依赖的任务。<br>处理步骤：调用时，确保传入任务。无法保证时，需要捕获异常。 |
| seqRunnerTask or executedTask cannot addDependency. | 串行队列任务或者已执行的任务不能增加依赖关系。<br>可能原因：串行队列任务或者已执行的任务调用该函数。<br>处理步骤：调用时，确保任务不是串行队列任务或者已执行的任务。无法保证时，需要捕获异常。 |
| groupTask cannot addDependency. | 任务组任务增加依赖关系。<br>可能原因：任务组任务调用该函数。<br>处理步骤：调用时，确保任务不是任务组任务。无法保证时，需要捕获异常。 |
| seqRunnerTask or executedTask cannot be relied on. | 串行队列任务或者已执行的任务不能被依赖。<br>可能原因：调用该函数，传参是串行队列任务或者已执行的任务。<br>处理步骤：调用时，确保传参不是串行队列任务或者已执行的任务。无法保证时，需要捕获异常。 |
| groupTask cannot be relied on. | 任务组任务不能被依赖。<br>可能原因：调用该函数，传参是任务组任务。<br>处理步骤：调用时，确保传参不是任务组任务。无法保证时，需要捕获异常。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function delay(args: number): number {
  let t = Date.now();
  while ((Date.now() - t) < 1000) {}
  return args;
}

let task1:taskpool.Task = new taskpool.Task(delay, 100.0);
let task2:taskpool.Task = new taskpool.Task(delay, 200.0);
let task3:taskpool.Task = new taskpool.Task(delay, 200.0);
task1.addDependency(task2);
task2.addDependency(task3);

taskpool.execute(task1).then((res: NullishType) => {
  hilog.info(0x0000, "testTag", "dependency: second task1 success");
})
taskpool.execute(task2).then((res: NullishType) => {
  hilog.info(0x0000, "testTag", "dependency: second task2 success");
})
taskpool.execute(task3).then((res: NullishType) => {
  hilog.info(0x0000, "testTag", "dependency: second task3 success");
})
```

### removeDependency

removeDependency(...tasks: Task[]): void

删除当前任务对其他任务的依赖。使用该方法前需要先构造Task。

**参数：**

| 参数名  | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| tasks  | [Task](#task)[] | 否   | 被依赖的任务数组。默认值为undefined。 |

**错误信息：**

| 错误信息                       | 说明                            |
| ------------------------------ | ------------------------------ |
| The dependency does not exist. | 依赖关系不存在。<br>可能原因：使用removeDependency()删除任务依赖时，依赖关系不存在。<br>处理步骤：调用时，确保在删除依赖之前，已经使用addDependency()成功添加依赖。无法保证时，需要捕获异常。  |
| task has no dependency. | 依赖关系不存在。<br>可能原因：使用removeDependency()删除任务依赖时，依赖关系不存在。<br>处理步骤：调用时，确保在删除依赖之前，已经使用addDependency()成功添加依赖。无法保证时，需要捕获异常。  |
| removeDependency has no params. | 调用该函数未传参。<br>可能原因：调用该函数未传需要被依赖的任务。<br>处理步骤：调用时，确保传入任务。无法保证时，需要捕获异常。 |
| executedTask cannot addDependency. | 已执行的任务不能移除依赖关系。<br>可能原因：已执行的任务调用该函数。<br>处理步骤：调用时，确保任务不是已执行的任务。无法保证时，需要捕获异常。 |
| cannot removeDependency on a dependent and executed task. | 已执行的任务不能移除依赖。<br>可能原因：调用该函数。传参是已执行的任务。<br>处理步骤：调用时，确保传参不是已执行的任务。无法保证时，需要捕获异常。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function delay(args: number): number {
  let t = Date.now();
  while ((Date.now() - t) < 1000) {}
  return args;
}

let task1:taskpool.Task = new taskpool.Task(delay, 100.0);
let task2:taskpool.Task = new taskpool.Task(delay, 200.0);
let task3:taskpool.Task = new taskpool.Task(delay, 200.0);
task1.addDependency(task2);
task2.addDependency(task3);
task1.removeDependency(task2);
task2.removeDependency(task3);
taskpool.execute(task1).then((res: NullishType) => {
  hilog.info(0x0000, "testTag", "dependency: task1 success");
})
taskpool.execute(task2).then((res: NullishType) => {
  hilog.info(0x0000, "testTag", "dependency: task2 success");
})
taskpool.execute(task3).then((res: NullishType) => {
  hilog.info(0x0000, "testTag", "dependency: task3 success");
})
```

### onEnqueued

onEnqueued(callback: CallbackFunction): void

注册一个回调函数，并在任务入队时调用它。需在任务执行前注册，否则会抛异常。

**参数：**

| 参数名  | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| callback  | [CallbackFunction](#callbackfunction) | 是   | 需注册的回调函数。 |

**错误信息：**

| 错误信息                       | 说明                              |
| ----------------------------- | --------------------------------- |
| The executed task does not support the registration of listeners. | 执行的任务不支持注册监听器。<br>可能原因：未注册回调函数或在执行任务之后注册回调函数。<br>处理步骤：确保在任务执行之前注册回调函数。无法保证时，需要捕获异常。  |

**示例：**

```ts
import hilog from '@ohos.hilog';

function delay(args: number): number {
  let t = Date.now();
  while ((Date.now() - t) < 1000) {}
  return args;
}

let task: taskpool.Task = new taskpool.Task(delay, 1.0);
task.onEnqueued(() => {
  hilog.info(0x0000, "testTag", "taskpool: onEnqueued")
});
taskpool.execute(task).then((res: NullishType)=> {
  hilog.info(0x0000, "testTag", "taskpool: execute task success")
});
```

### onStartExecution

onStartExecution(callback: CallbackFunction): void

注册一个回调函数，并在执行任务前调用它。需在任务执行前注册，否则会抛异常。

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| callback  | [CallbackFunction](#callbackfunction)  | 是   | 需注册的回调函数。 |

**错误信息：**

| 错误信息                       | 说明                               |
| ----------------------------- | ---------------------------------- |
| The executed task does not support the registration of listeners. | 执行的任务不支持注册监听器。<br>可能原因：未注册回调函数或在执行任务之后注册回调函数。<br>处理步骤：确保在任务执行之前注册回调函数。无法保证时，需要捕获异常。  |

**示例：**

```ts
import hilog from '@ohos.hilog';

function delay(args: number): number {
  let t = Date.now();
  while ((Date.now() - t) < 1000) {}
  return args;
}

let task: taskpool.Task = new taskpool.Task(delay, 1.0);
task.onStartExecution(() => {
  hilog.info(0x0000, "testTag", "taskpool: onStartExecution")
});
taskpool.execute(task).then((res: NullishType) => {
  hilog.info(0x0000, "testTag", "taskpool: execute task success")
});
```

### onExecutionFailed

onExecutionFailed(callback: CallbackFunctionWithError): void

注册一个回调函数，并在任务执行失败时调用它。需在任务执行前注册，否则会抛异常。

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| callback  | [CallbackFunctionWithError](#callbackfunctionwitherror)  | 是   | 需注册的回调函数。 |

**错误信息：**

| 错误信息                       | 说明                               |
| ----------------------------- | ---------------------------------- |
| The executed task does not support the registration of listeners. | 执行的任务不支持注册监听器。<br>可能原因：未注册回调函数或在执行任务之后注册回调函数。<br>处理步骤：确保在任务执行之前注册回调函数。无法保证时，需要捕获异常。  |

**示例：**

```ts
import hilog from '@ohos.hilog';

function test(args: number) {
  let t = Date.now()
  while ((Date.now() - t) < 100) {}
}

let task2 = new taskpool.Task(test, 1.0);
task2.onExecutionFailed((e:Error) => {
  hilog.info(0x0000, "testTag", "taskpool: onExecutionFailed error is " + e);
})
taskpool.execute(task2).then((res: NullishType) => {
  hilog.info(0x0000, "testTag", "taskpool: execute task success");
}).catch((e) => {
  hilog.info(0x0000, "testTag", "taskpool error: " + e);
})
```

### onExecutionSucceeded

onExecutionSucceeded(callback: CallbackFunction): void

注册一个回调函数，并在任务执行成功时调用它。需在任务执行前注册，否则会抛异常。

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| callback  | [CallbackFunction](#callbackfunction)  | 是   | 需注册的回调函数。 |

**错误信息：**

| 错误信息                       | 说明                               |
| ----------------------------- | ---------------------------------- |
| The executed task does not support the registration of listeners. | 执行的任务不支持注册监听器。<br>可能原因：未注册回调函数或在执行任务之后注册回调函数。<br>处理步骤：确保在任务执行之前注册回调函数。无法保证时，需要捕获异常。  |

**示例：**

```ts
import hilog from '@ohos.hilog';

function delay(args: number): number {
  let t = Date.now();
  while ((Date.now() - t) < 1000) {}
  return args;
}

let task: taskpool.Task = new taskpool.Task(delay, 1.0);
task.onExecutionSucceeded(() => {
  hilog.info(0x0000, "testTag", "taskpool: onExecutionSucceeded")
});
taskpool.execute(task).then((res: NullishType) => {
  hilog.info(0x0000, "testTag", "taskpool: execute task success")
});
```

### isDone

isDone(): boolean

检查任务是否已完成。

**返回值：**

| 类型    | 说明                                 |
| ------- | ------------------------------------ |
| boolean | 任务执行完成返回true，任务未执行完成返回false。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function inspectStatus(arg: number): number {
  let t = Date.now();
  while (Date.now() - t < 1000) {}
  return arg + 1;
}

async function taskpoolCancel(): Promise<void> {
  let task: taskpool.Task = new taskpool.Task(inspectStatus, 100.0);
  taskpool.execute(task).then((res: NullishType) => {
    hilog.info(0x0000, "testTag", "taskpool test result: " + res);
  }).catch((err) => {
    hilog.info(0x0000, "testTag", "taskpool test occur error: " + err);
  });

  setTimeout(() => {
    if (!task.isDone()) {
      taskpool.cancel(task);
    }
  }, 3000); // 延时3s，确保任务已执行
}

taskpoolCancel();
```

## CallbackFunction

type CallbackFunction = () => void

注册的回调函数类型。

## CallbackFunctionWithError

type CallbackFunctionWithError = (e: Error) => void

注册带有错误信息的回调函数类型。

**参数：**

| 参数名  | 类型   | 必填  | 说明               |
| ------ | ------ | ---- | ------------------ |
| e      | Error  | 是   | 错误信息。 |

## TaskGroup

表示任务组，一次执行一组任务，适用于执行一组有关联的任务。如果所有任务正常执行，异步执行完毕后返回所有任务结果的数组，数组中元素的顺序与[addTask](#addtask)的顺序相同；如果任意任务失败，则会抛出对应异常。如果任务组中存在多个任务失败的情况，则会抛出第一个失败任务的异常。使用[constructor](#constructor)方法构造TaskGroup。该任务组仅支持单次执行。

### constructor

constructor()

TaskGroup的构造函数。

**示例：**

```ts
let taskGroup = new taskpool.TaskGroup();
```

### constructor

constructor(name: string)

TaskGroup的构造函数，可以指定任务组名称。

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| name   | string | 是   | 任务组名称。无长度限制和其他格式要求。 |

**示例：**

```ts
let taskGroupName: string = "groupName";
let taskGroup: taskpool.TaskGroup = new taskpool.TaskGroup(taskGroupName);
let name: string = taskGroup.name;
```

### addTask

addTask(func: Function, ...args: NullishType[]): void

将待执行的函数添加到任务组中。使用该方法前需要先构造TaskGroup。

**参数：**

| 参数名  | 类型      | 必填 | 说明                                                                   |
| ------ | --------- | ---- | ---------------------------------------------------------------------- |
| func   | Function  | 是   | 执行的逻辑需要传入函数。     |
| args   | NullishType[] | 否   | 任务执行函数所需要的入参。默认值为undefined。 |

**示例：**

```ts
import hilog from '@ohos.hilog';

function printArgs(args: number): number {
  hilog.info(0x0000, "testTag", "printArgs: " + args);
  return args;
}

let taskGroup: taskpool.TaskGroup = new taskpool.TaskGroup();
taskGroup.addTask(printArgs, 100.0);
```

### addTask

addTask(task: Task): void

将创建好的任务添加到任务组中。使用该方法前需要先构造TaskGroup。任务组不可以添加其他任务组任务、串行队列任务、有依赖关系的任务、周期任务和已执行的任务。

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                       |
| -------- | --------------------- | ---- | ---------------------------------------- |
| task     | [Task](#task)         | 是   | 需要添加到任务组中的任务。                  |

**错误信息：**

| 错误信息                                     | 说明                                        |
| ------------------------------------------- | ------------------------------------------- |
| taskGroup cannot add groupTask. | 任务组不能添加任务组任务。<br>可能原因：添加的任务是任务组任务。<br>处理步骤：添加任务需确保任务不是任务组任务。无法保证时，需捕获异常。 |
| The interface does not support the periodicTask. | 周期任务不能再次执行。<br>可能原因：周期任务已被执行过。<br>处理步骤：执行任务前确保任务未被执行过。无法保证时，需捕获异常。  |
| taskGroup cannot add seqRunnerTask or executedTask. | 任务组不能添加串行队列任务或已执行任务。<br>可能原因：添加的任务是串行队列任务或已执行任务。<br>处理步骤：确保添加的任务不是串行队列任务或已执行任务。无法保证时，需捕获异常。 |
| dependent task not allowed. | 不允许有依赖关系的任务。<br>可能原因：添加的任务有依赖关系。<br>处理步骤：确保添加的任务没有依赖关系。无法保证时，需捕获异常。 |
| task has been executed.  | 添加已执行的任务。<br>可能原因：添加已执行的任务。<br>处理步骤：添加任务前确保任务未执行。无法保证时，需捕获异常。  |

**示例：**

```ts
import hilog from '@ohos.hilog';

function printArgs(args: number): number {
  hilog.info(0x0000, "testTag", "printArgs: " + args);
  return args;
}

let taskGroup: taskpool.TaskGroup = new taskpool.TaskGroup();
let task: taskpool.Task = new taskpool.Task(printArgs, 200.0);
taskGroup.addTask(task);
```

### 属性

| 名称  | 类型   | 只读 | 可选  | 说明                         |
| ---- | ------ | ---- | ---- | ---------------------------- |
| name | string | 否   | 否   | 创建任务组时指定的任务组名称。无长度限制和其他格式要求。 |

## SequenceRunner

表示串行队列的任务，用于执行一组需要串行执行的任务。使用[constructor](#constructor)方法构造SequenceRunner。

### constructor

constructor(priority?: Priority)

SequenceRunner的构造函数。

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                       |
| -------- | --------------------- | ---- | ---------------------------------------------------------- |
| priority | [Priority](#priority) | 否   | 指定任务的优先级，该参数默认值为taskpool.Priority.MEDIUM。 |

**示例：**

```ts
let runner: taskpool.SequenceRunner = new taskpool.SequenceRunner();
```

### constructor

constructor(name: string, priority?: Priority)

SequenceRunner的构造函数。构造一个全局串行队列，如果名字相同，将返回同一个串行队列。

> **说明：**
>
> - 底层通过单例模式保证了：创建同名串行队列时，获取到同一个实例。
> - 不支持修改串行队列的优先级。

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                     |
| -------- | --------------------- | ---- | ------------------------------------------------------- |
| name     | string                | 是   | 串行队列的名字。无长度限制和其他格式要求。 |
| priority | [Priority](#priority) | 否   | 指定任务的优先级，该参数默认值为taskpool.Priority.MEDIUM。 |

**示例：**

```ts
let runner:taskpool.SequenceRunner = new taskpool.SequenceRunner("runner1", taskpool.Priority.LOW);
```

### execute

execute(task: Task): Promise\<NullishType>

执行串行任务。使用该方法前需要先构造SequenceRunner。串行队列不可以执行任务组任务、其他串行队列任务、有依赖关系的任务和已执行的任务。使用Promise异步回调。

> **说明：**
>
> - 不支持加入存在依赖的任务。
> - 前面的任务执行失败或取消不影响后续任务执行。

**参数：**

| 参数名 | 类型          | 必填 | 说明                             |
| ------ | ------------- | ---- | -------------------------------- |
| task   | [Task](#task) | 是   | 需要添加到串行任务队列中的任务。 |

**返回值：**

| 类型             | 说明                              |
| ---------------- | --------------------------------- |
| Promise\<NullishType> | Promise对象，返回任务执行的结果。 |

**错误信息：**

| 错误信息                                     | 说明                                        |
| ------------------------------------------- | ------------------------------------------- |
| SequenceRunner cannot execute groupTask. | 串行队列不能执行任务组任务。<br>可能原因：串行队列执行了任务组任务。<br>处理步骤：调用时，确保串行队列不执行任务组任务。无法保证时，需捕获异常。 |
| SequenceRunner cannot execute seqRunnerTask or executedTask. | 串行队列不能执行串行队列任务或已经执行过的任务。<br>可能原因：串行队列执行已经执行过的任务。<br>处理步骤：调用时，确保串行队列不执行已经执行过的任务。无法保证时，需捕获异常。 |
| dependent task not allowed.  | 串行队列执行有依赖关系的任务。<br>可能原因：串行队列执行有依赖关系的任务。<br>处理步骤：排查找到串行队列里使用addDependency()添加依赖的任务，使用removeDependency()删除此任务的依赖。无法保证时，需捕获异常。  |
| SequenceRunner cannot execute the periodicTask. | 周期任务不能再次执行。<br>可能原因：串行队列执行周期任务。<br>处理步骤：执行任务前确保任务未被执行过。无法保证时，需捕获异常。  |
| task has been executed.  | 任务已经被执行过。<br>可能原因：串行队列执行已经执行过的任务。<br>处理步骤：执行任务前确保任务未被执行过。无法保证时，需捕获异常。  |

**示例：**

```ts
import hilog from '@ohos.hilog';

function additionDelay(delay: number): void {
  let start = new Date().getTime();
  while ((new Date().getTime() - start) < delay) {}
}

function waitForRunner(finalString: string): string {
  return finalString;
}

async function seqRunner() {
  let finalString:string = "";
  let task1:taskpool.Task = new taskpool.Task(additionDelay, 3000.0);
  let task2:taskpool.Task = new taskpool.Task(additionDelay, 2000.0);
  let task3:taskpool.Task = new taskpool.Task(additionDelay, 1000.0);
  let task4:taskpool.Task = new taskpool.Task(waitForRunner, finalString);

  let runner:taskpool.SequenceRunner = new taskpool.SequenceRunner();
  runner.execute(task1).then((res: NullishType) => {
    finalString += 'a';
    hilog.info(0x0000, "testTag", "seqrunner: task1 done.");
  });
  runner.execute(task2).then((res: NullishType) => {
    finalString += 'b';
    hilog.info(0x0000, "testTag", "seqrunner: task2 done");
  });
  runner.execute(task3).then((res: NullishType) => {
    finalString += 'c';
    hilog.info(0x0000, "testTag", "seqrunner: task3 done");
  });
  await runner.execute(task4);
  hilog.info(0x0000, "testTag", "seqrunner: task4 done, finalString is " + finalString);
}
```

## State

表示任务（Task）状态的枚举。当任务创建成功后，调用execute，任务进入taskpool等待队列，状态设置为WAITING；任务从等待队列出来进入taskpool工作线程中，任务状态更新为RUNNING；当任务执行完成，返回结果后任务状态重置为WAITING；当主动cancel任务时，将任务状态更新为CANCELED。

| 名称       | 值       | 说明          |
| --------- | -------- | ------------- |
| WAITING   | 1        | 任务正在等待。 |
| RUNNING   | 2        | 任务正在执行。 |
| CANCELED  | 3        | 任务已被取消。 |

## TaskInfo

任务的内部信息。

### 属性

| 名称      | 类型               | 只读 | 可选 | 说明                                                           |
| -------- | ------------------ | ---- | ---- | ------------------------------------------------------------- |
| taskId   | number             | 否   | 否   | 任务的标识符。无单位。值为标识任务的一个正值。 |
| state    | [State](#state)    | 否   | 否   | 任务的状态。 |
| duration | number             | 否   | 是   | 任务执行至当前所用的时间，单位为ms。当返回为0时，表示任务未执行；返回为空时，表示没有任务执行。默认值为0。  |
| name     | string             | 否   | 否   | 任务的名字。无长度限制和其他格式要求。 |

## ThreadInfo

工作线程的内部信息。

### 属性

| 名称     | 类型                    | 只读 | 可选 | 说明                                                      |
| -------- | ---------------------- | ---- | ---- | -------------------------------------------------------- |
| tid      | number                 | 否   | 否   | 工作线程的标识符。无单位。值为标识工作线程的一个正值。返回为空时，代表没有任务执行。   |
| taskIds  | number[]               | 否   | 是   | 在当前线程上运行的任务ID列表。无单位。值为运行任务ID的一个正值数组。返回为空时，代表没有任务执行。默认值为undefined。   |
| priority | [Priority](#priority)  | 否   | 是   | 当前线程的优先级。返回为空时，代表没有任务执行。默认值为taskpool.Priority.MEDIUM。   |

## TaskPoolInfo

任务池的内部信息。

### 属性

| 名称          | 类型                            | 只读 | 可选 | 说明                  |
| ------------- | ------------------------------ | ---- | ---- | -------------------- |
| threadInfos   | [ThreadInfo[]](#threadinfo)    | 否   | 否   | 工作线程的内部信息。   |
| taskInfos     | [TaskInfo[]](#taskinfo)        | 否   | 否   | 任务的内部信息。       |

## 其他说明

### 简单使用

**示例一**
```ts
import hilog from '@ohos.hilog';

function printArgs(args: string): string {
  hilog.info(0x0000, "testTag", "func: " + args);
  return args;
}

async function taskpoolExecute(): Promise<void> {
  let task: taskpool.Task = new taskpool.Task(printArgs, "create task, then execute");
  hilog.info(0x0000, "testTag", "taskpool.execute(task) result: " + await taskpool.execute(task));
  hilog.info(0x0000, "testTag", "taskpool.execute(function) result: " + await taskpool.execute(printArgs, "execute task by func"));
}

taskpoolExecute();
```

**示例二**
```ts
import hilog from '@ohos.hilog';

// c.ets
function strSort(inPutArr: Array<string>): Array<string> {
  let newArr = inPutArr.sort();
  return newArr;
}

export async function func1(): Promise<void> {
  let strArray: Array<string> = ['c test string', 'b test string', 'a test string'];
  let task: taskpool.Task = new taskpool.Task(strSort, strArray);
  hilog.info(0x0000, "testTag", "func1 result:" + await taskpool.execute(task));
}

export async function func2(): Promise<void> {
  let strArray: Array<string> = ['c test string', 'b test string', 'a test string'];
  taskpool.execute(strSort, strArray).then((result: NullishType) => {
    hilog.info(0x0000, "testTag", "func2 result: " + result);
  }).catch((err) => {
    hilog.info(0x0000, "testTag", "taskpool test occur error: " + err);
  });
}
```
<!--code_no_check-->
```ts
// index.ets
import { func1, func2 } from "./c";

func1();
func2();
```

**示例三**
```ts
import hilog from '@ohos.hilog';

// 任务取消成功
function inspectStatus(arg: number): number {
  // 第一次检查任务是否已经取消并作出响应
  if (taskpool.Task.isCanceled()) {
    hilog.info(0x0000, "testTag", "task has been canceled before 2s sleep.");
    return arg + 2;
  }
  // 2s sleep
  let t = Date.now();
  while (Date.now() - t < 2000) {}
  // 第二次检查任务是否已经取消并作出响应
  if (taskpool.Task.isCanceled()) {
    hilog.info(0x0000, "testTag", "task has been canceled after 2s sleep.");
    return arg + 3;
  }
  return arg + 1;
}

async function taskpoolCancel(): Promise<void> {
  let task: taskpool.Task = new taskpool.Task(inspectStatus, 100.0);
  taskpool.execute(task).then((res: NullishType) => {
    hilog.info(0x0000, "testTag", "taskpool test result: " + res);
  }).catch((err) => {
    hilog.info(0x0000, "testTag", "taskpool test occur error: " + err);
  });
  // 1s后取消task
  setTimeout(() => {
    try {
      taskpool.cancel(task);
    } catch (e) {
      hilog.info(0x0000, "testTag", "taskpool: cancel error: " + e);
    }
  }, 1000);
}

taskpoolCancel();
```

**示例四**
```ts
import hilog from '@ohos.hilog';

// 已执行的任务取消失败
function inspectStatus(arg: number): number {
  // 第一次检查任务是否已经取消并作出响应
  if (taskpool.Task.isCanceled()) {
    return arg + 2;
  }
  // 延时500ms
  let t = Date.now();
  while (Date.now() - t < 500) {}
  // 第二次检查任务是否已经取消并作出响应
  if (taskpool.Task.isCanceled()) {
    return arg + 3;
  }
  return arg + 1;
}

async function taskpoolCancel(): Promise<void> {
  let task: taskpool.Task = new taskpool.Task(inspectStatus, 100.0);
  taskpool.execute(task).then((res: NullishType) => {
    hilog.info(0x0000, "testTag", "taskpool test result: " + res);
  }).catch((err) => {
    hilog.info(0x0000, "testTag", "taskpool test occur error: " + err);
  });

  setTimeout(() => {
    try {
      taskpool.cancel(task); // 任务已执行,取消失败
    } catch (e) {
      hilog.info(0x0000, "testTag", "taskpool: cancel error: " + e);
    }
  }, 3000); // 延时3s，确保任务已执行
}

taskpoolCancel();
```

**示例五**
```ts
import hilog from '@ohos.hilog';

// 待执行的任务组取消成功
function printArgs(args: number): number {
  let t = Date.now();
  while (Date.now() - t < 1000) {}
  hilog.info(0x0000, "testTag", "printArgs: " + args);
  return args;
}

async function taskpoolGroupCancelTest(): Promise<void> {
  let taskGroup1: taskpool.TaskGroup = new taskpool.TaskGroup();
  taskGroup1.addTask(printArgs, 10.0);
  taskGroup1.addTask(printArgs, 20.0);
  taskGroup1.addTask(printArgs, 30.0);
  let taskGroup2: taskpool.TaskGroup = new taskpool.TaskGroup();
  let task1: taskpool.Task = new taskpool.Task(printArgs, 100.0);
  let task2: taskpool.Task = new taskpool.Task(printArgs, 200.0);
  let task3: taskpool.Task = new taskpool.Task(printArgs, 300.0);
  taskGroup2.addTask(task1);
  taskGroup2.addTask(task2);
  taskGroup2.addTask(task3);
  taskpool.execute(taskGroup1).then((res: Array<Object>) => {
    hilog.info(0x0000, "testTag", "taskpool execute res is:" + res);
  }).catch((e) => {
    hilog.info(0x0000, "testTag", "taskpool execute error is:" + e);
  });
  taskpool.execute(taskGroup2).then((res: Array<Object>) => {
    hilog.info(0x0000, "testTag", "taskpool execute res is:" + res);
  }).catch((e) => {
    hilog.info(0x0000, "testTag", "taskpool execute error is:" + e);
  });

  try {
    taskpool.cancel(taskGroup2);
  } catch (e) {
    hilog.info(0x0000, "testTag", "taskpool: cancel error: " + e);
  }
}

taskpoolGroupCancelTest()
```

**示例六**
```ts
import hilog from '@ohos.hilog';

// 分别创建执行100个高、中、低优先级的任务，查看其各项信息
function delay(): void {
  let start = new Date().getTime();
  while (new Date().getTime() - start < 500) {}
}

let highCount: int = 0;
let mediumCount: int = 0;
let lowCount: int = 0;
let allCount: int = 100;
for (let i = 0; i < allCount; i++) {
  let task1: taskpool.Task = new taskpool.Task(delay);
  let task2: taskpool.Task = new taskpool.Task(delay);
  let task3: taskpool.Task = new taskpool.Task(delay);
  taskpool.execute(task1, taskpool.Priority.LOW).then((res: NullishType) => {
    lowCount++;
  }).catch((e) => {
    hilog.info(0x0000, "testTag", "low task error: " + e);
  })
  taskpool.execute(task2, taskpool.Priority.MEDIUM).then((res: NullishType) => {
    mediumCount++;
  }).catch((e) => {
    hilog.info(0x0000, "testTag", "medium task error: " + e);
  })
  taskpool.execute(task3, taskpool.Priority.HIGH).then((res: NullishType) => {
    highCount++;
  }).catch((e) => {
    hilog.info(0x0000, "testTag", "high task error: " + e);
  })
}
let start = new Date().getTime();
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
for (let threadInfo of threadIS) {
  tid = threadInfo.tid;
  if (threadInfo.taskIds != undefined && threadInfo.priority != undefined) {
    taskIds.length = threadInfo.taskIds.length;
    priority = threadInfo.priority;
  }
  hilog.info(0x0000, "testTag", "taskpool---tid is:" + tid + ", taskIds is:" + taskIds + ", priority is:" + priority);
}
let taskIS = Array.from(taskpoolInfo.taskInfos)
for (let taskInfo of taskIS) {
  taskId = taskInfo.taskId;
  state = taskInfo.state;
  if (taskInfo.duration != undefined) {
    duration = taskInfo.duration;
    name = taskInfo.name;
  }
  hilog.info(0x0000, "testTag", "taskpool---taskId is:" + taskId + ", state is:" + state + ", duration is:" + duration + ", name is:" + name);
}
```