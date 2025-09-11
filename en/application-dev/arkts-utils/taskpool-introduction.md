# TaskPool
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

TaskPool is designed to provide a multithreaded runtime environment for applications. It helps reduce overall resource consumption and improve system performance. You do not need to manage the thread lifecycle. For details about the APIs and their usage, see [TaskPool](../reference/apis-arkts/js-apis-taskpool.md).

## TaskPool Operating Mechanism

The figure below illustrates the operating mechanism of TaskPool.

![image_0000001964858368](figures/image_0000001964858368.png)

With TaskPool, you can submit tasks in the host thread to the task queue. The system selects appropriate worker threads to execute the tasks, and then returns the result to the host thread. TaskPool provides APIs to execute and cancel tasks, and set the task priority. It minimizes system resource usage through unified thread management, dynamic scheduling, and load balancing. By default, the system starts a worker thread and increases the thread quantity as the number of tasks increases. The maximum number of worker threads that can be created depends on the number of physical cores of the device. The actual number is managed internally to ensure optimal scheduling and execution efficiency. If no task is distributed for an extended period, the system reduces the number of worker threads. For details, see [TaskPool Scaling Mechanism](taskpool-introduction.md#taskpool-scaling-mechanism).

## Precautions for TaskPool

- Functions implementing tasks must be decorated with [\@Concurrent](#concurrent-decorator) and are supported only in .ets files.

- Starting from API version 11, when passing instances with methods across concurrent instances, the class must be decorated with [@Sendable](arkts-sendable.md#sendable-decorator) and are supported only in .ets files.

- A task function (except [LongTask](../reference/apis-arkts/js-apis-taskpool.md#longtask12)) must finish the execution in a TaskPool's worker thread within 3 minutes. Otherwise, it is forcibly terminated. Note that the 3-minute limit only applies to the synchronous running duration of the TaskPool thread, excluding the waiting duration of asynchronous operations (such as Promise or async/await calls). For example, when database insert, delete, and update operations are asynchronous, only the actual CPU processing time (such as SQL parsing) is counted, excluding network transmission or disk I/O waiting time. For synchronous database insert, delete, and update operations, the entire operation duration (including I/O blocking time) is counted. You can obtain the asynchronous I/O duration and CPU duration of the current task through the **ioDuration** and **cpuDuration** properties of [Task](../reference/apis-arkts/js-apis-taskpool.md#task).

- Parameters of functions implementing tasks must be of types supported by serialization. For details, see [Inter-Thread Communication](interthread-communication-overview.md). Currently, complex types decorated with [@State](../ui/state-management/arkts-state.md), [@Prop](../ui/state-management/arkts-prop.md), and [@Link](../ui/state-management/arkts-link.md) are not supported.

- Parameters of the ArrayBuffer type are transferred in TaskPool by default. You can set the transfer list by calling [setTransferList()](../reference/apis-arkts/js-apis-taskpool.md#settransferlist10). If you need to call a task that uses ArrayBuffer as a parameter multiple times, call [setCloneList()](../reference/apis-arkts/js-apis-taskpool.md#setclonelist11) to change the transfer behavior of ArrayBuffer in the thread to pass-by-copy, avoiding affecting the original object.

In addition to the preceding precautions, pay attention to [concurrency precautions](multi-thread-concurrency-overview.md#concurrency-precautions).

  ```ts
  import { taskpool } from '@kit.ArkTS';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  @Concurrent
  function printArrayBuffer(buffer: ArrayBuffer) {
    return buffer;
  }
  
  function testArrayBuffer() {
    const buffer = new ArrayBuffer(1);
    const group = new taskpool.TaskGroup();
    const task = new taskpool.Task(printArrayBuffer, buffer);
    group.addTask(task);
    task.setCloneList([buffer]);
    for (let i = 0; i < 5; i++) {
      taskpool.execute(group).then(() => {
        console.info('execute group success');
      }).catch((e: BusinessError) => {
        console.error(`execute group error: ${e.message}`);
      })
    }
  }
  ```

- The context objects in different threads are different. Therefore, TaskPool worker threads can use only thread-safe libraries. For example, non-thread-safe UI-related libraries cannot be used.

- A maximum of 16 MB data can be serialized.

- Among all the values of [Priority](../reference/apis-arkts/js-apis-taskpool.md#priority), **IDLE** is used to mark time-consuming tasks that need to run in the background (such as data synchronization and backup), and it has the lowest priority. Tasks marked with this priority are executed only when all threads are idle. Only one task with this priority can be executed at a time.

- Promises cannot be transferred across threads. If TaskPool returns a Promise in the pending or rejected state, a failure message is returned. For a Promise in the fulfilled state, TaskPool parses the returned result. If the result can be transferred across threads, a success message is returned.

- [AppStorage](../ui/state-management/arkts-appstorage.md) cannot be used in the TaskPool's worker threads.

- TaskPool allows you to package tasks in the host thread and submit them to the task queue. While it can theoretically handle an unlimited number of tasks, the actual task execution efficiency is influenced by the task priority and system resources. Once the worker threads reach their maximum capacity, the efficiency of task execution might be compromised.

- TaskPool does not allow you to specify the thread where a task runs. Instead, tasks are assigned to run in available threads. If you want to specify the thread for running a task, using [Worker](worker-introduction.md) is a better approach.

## \@Concurrent Decorator

To pass function verification, concurrent functions executed in a [TaskPool](../reference/apis-arkts/js-apis-taskpool.md) must be decorated using @Concurrent.

> **NOTE**
>
> Since API version 9, the @Concurrent decorator can be used to declare and verify concurrent functions.

| \@Concurrent Decorator| Description|
| -------- | -------- |
| Decorator parameters| None.|
| Use scenario| Used only in projects of the stage model and only in .ets files.|
| Decorated function types| Used for async functions or regular functions. It cannot be used for generators, arrow functions, or class methods. It does not support class member functions or anonymous functions.|
| Variable types in decorated functions| Local variables, parameters, and variables imported through **import** are allowed. Closure variables cannot be used.|
| Return value types in decorated functions| Supported types are listed in [Inter-Thread Communication](interthread-communication-overview.md).|

> **NOTE**
>
> Functions decorated with \@Concurrent cannot access closures. Therefore, they cannot call other functions within the same file. The following provides an example.
>
> ```ts
> function bar() {
> }
> 
> @Concurrent
> function foo() {
>   bar(); // This violates the closure principle. An error is reported.
> }
> ```

## Decorator Usage Examples

### General Use of Concurrent Functions

A concurrent function that calculates the sum of two numbers is executed by TaskPool and returns the result.

Example:

```ts
import { taskpool } from '@kit.ArkTS';

@Concurrent
function add(num1: number, num2: number): number {
  return num1 + num2;
}

async function concurrentFunc(): Promise<void> {
  try {
    const task: taskpool.Task = new taskpool.Task(add, 1, 2);
    console.info(`taskpool res is: ${await taskpool.execute(task)}`); // Output: taskpool res is: 3
  } catch (e) {
    console.error(`taskpool execute error is: ${e}`);
  }
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            concurrentFunc();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
<!-- @[concurrent_taskpool_common_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/generaluse.ets) -->

### Concurrent Functions Returning Promises

Pay attention to Promises returned by concurrent functions. In the following example, **testPromise** and **testPromise1** handle these Promises and return results.

Example:

```ts
import { taskpool } from '@kit.ArkTS';

@Concurrent
function testPromise(args1: number, args2: number): Promise<number> {
  return new Promise<number>((resolve, reject) => {
    resolve(args1 + args2);
  });
}

@Concurrent
async function testPromise1(args1: number, args2: number): Promise<number> {
  return new Promise<number>((resolve, reject) => {
    resolve(args1 + args2);
  });
}

@Concurrent
async function testPromise2(args1: number, args2: number): Promise<number> {
  return await new Promise<number>((resolve, reject) => {
    resolve(args1 + args2);
  });
}

@Concurrent
function testPromise3() {
  return Promise.resolve(1);
}

@Concurrent
async function testPromise4(): Promise<number> {
  return 1;
}

@Concurrent
async function testPromise5(): Promise<string> {
  return await new Promise((resolve) => {
    setTimeout(() => {
      resolve('Promise setTimeout after resolve');
    }, 1000)
  });
}

async function testConcurrentFunc() {
  const task1: taskpool.Task = new taskpool.Task(testPromise, 1, 2);
  const task2: taskpool.Task = new taskpool.Task(testPromise1, 1, 2);
  const task3: taskpool.Task = new taskpool.Task(testPromise2, 1, 2);
  const task4: taskpool.Task = new taskpool.Task(testPromise3);
  const task5: taskpool.Task = new taskpool.Task(testPromise4);
  const task6: taskpool.Task = new taskpool.Task(testPromise5);

  taskpool.execute(task1).then((d: object) => {
    console.info(`task1 res is: ${d}`); // Output: task1 res is: 3
  }).catch((e: object) => {
    console.error(`task1 catch e: ${e}`);
  })
  taskpool.execute(task2).then((d: object) => {
    console.info(`task2 res is: ${d}`);
  }).catch((e: object) => {
    console.error(`task2 catch e: ${e}`); // Output: task2 catch e: Error: Can't return Promise in pending state
  })
  taskpool.execute(task3).then((d: object) => {
    console.info(`task3 res is: ${d}`); // Output: task3 res is: 3
  }).catch((e: object) => {
    console.error(`task3 catch e: ${e}`);
  })
  taskpool.execute(task4).then((d: object) => {
    console.info(`task4 res is: ${d}`); // Output: task4 res is: 1
  }).catch((e: object) => {
    console.error(`task4 catch e: ${e}`);
  })
  taskpool.execute(task5).then((d: object) => {
    console.info(`task5 res is: ${d}`); // Output: task5 res is: 1
  }).catch((e: object) => {
    console.error(`task5 catch e: ${e}`);
  })
  taskpool.execute(task6).then((d: object) => {
    console.info(`task6 res is: ${d}`); // Output: task6 res is: Promise setTimeout after resolve
  }).catch((e: object) => {
    console.error(`task6 catch e: ${e}`);
  })
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Button(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            testConcurrentFunc();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
<!-- @[concurrent_taskpool_promise_return](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/returnpromise.ets) -->

### Using Custom Classes or Functions in Concurrent Functions

Custom classes or functions used in concurrent functions must be defined in separate files. Otherwise, they may be considered as closures. The following is an example.

Example:

```ts
// Index.ets
import { taskpool } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';
import { testAdd, MyTestA, MyTestB } from './Test';

function add(arg: number) {
  return ++arg;
}

class TestA {
  constructor(name: string) {
    this.name = name;
  }

  name: string = 'ClassA';
}

class TestB {
  static nameStr: string = 'ClassB';
}

@Concurrent
function TestFunc() {
  // Case 1: Directly call a class or function defined in the same file within a concurrent function.

  // Directly call the add() function defined in the same file. The following error message is displayed: "Only imported variables and local variables can be used in @Concurrent decorated functions. <ArkTSCheck>"
  // add(1);
  // Directly use the TestA constructor defined in the same file. The following error message is displayed: "Only imported variables and local variables can be used in @Concurrent decorated functions. <ArkTSCheck>"
  // const a = new TestA('aaa');
  // Directly access the nameStr member of TestB defined in the same file. The following error message is displayed: "Only imported variables and local variables can be used in @Concurrent decorated functions. <ArkTSCheck>"
  // console.info(`TestB name is: ${TestB.nameStr}`);

  // Case 2: In the concurrent function, call classes or functions defined in the Test.ets file and imported into the current file.

  // Output: res1 is: 2
  console.info(`res1 is: ${testAdd(1)}`);
  const tmpStr = new MyTestA('TEST A');
  // Output: res2 is: TEST A
  console.info(`res2 is: ${tmpStr.name}`);
  // Output: res3 is: MyTestB
  console.info(`res3 is: ${MyTestB.nameStr}`);
}


@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          const task = new taskpool.Task(TestFunc);
          taskpool.execute(task).then(() => {
            console.info('taskpool: execute task success!');
          }).catch((e: BusinessError) => {
            console.error(`taskpool: execute: Code: ${e.code}, message: ${e.message}`);
          })
        })
    }
    .height('100%')
    .width('100%')
  }
}
```
<!-- @[concurrent_taskpool_custom_class_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/customclasses.ets) -->

```ts
// Test.ets
export function testAdd(arg: number) {
  return ++arg;
}

@Sendable
export class MyTestA {
  constructor(name: string) {
    this.name = name;
  }
  name: string = 'MyTestA';
}

export class MyTestB {
  static nameStr:string = 'MyTestB';
}
```
<!-- @[concurrent_taskpool_test_resources](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/Test.ets) -->

### Using Promises in Concurrent Asynchronous Functions

If Promise is used in concurrent asynchronous functions, you are advised to use **await**. In this way, TaskPool can capture exceptions in Promise. The recommended usage is shown in the following example.

Example:

```ts
import { taskpool } from '@kit.ArkTS';

@Concurrent
async function testPromiseError() {
  await new Promise<number>((resolve, reject) => {
    resolve(1);
  }).then(() => {
    throw new Error('testPromise error');
  })
}

@Concurrent
async function testPromiseError1() {
  await new Promise<string>((resolve, reject) => {
    reject('testPromiseError1 error msg');
  })
}

@Concurrent
function testPromiseError2() {
  return new Promise<string>((resolve, reject) => {
    reject('testPromiseError2 error msg');
  })
}

async function testConcurrentFunc() {
  const task1: taskpool.Task = new taskpool.Task(testPromiseError);
  const task2: taskpool.Task = new taskpool.Task(testPromiseError1);
  const task3: taskpool.Task = new taskpool.Task(testPromiseError2);

  taskpool.execute(task1).then((d: object) => {
    console.info(`task1 res is: ${d}`);
  }).catch((e: object) => {
    console.error(`task1 catch e: ${e}`); // task1 catch e: Error: testPromise error
  })
  taskpool.execute(task2).then((d: object) => {
    console.info(`task2 res is: ${d}`);
  }).catch((e: object) => {
    console.error(`task2 catch e: ${e}`); // task2 catch e: testPromiseError1 error msg
  })
  taskpool.execute(task3).then((d: object) => {
    console.info(`task3 res is: ${d}`);
  }).catch((e: object) => {
    console.error(`task3 catch e: ${e}`); // task3 catch e: testPromiseError2 error msg
  })
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Button(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            testConcurrentFunc();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
<!-- @[concurrent_taskpool_async_promise_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/asynchronousfunctions.ets) -->

## TaskPool Scaling Mechanism

### Expansion Mechanism

Generally, when you submit tasks to the task queue, an expansion check is triggered. The expansion check first determines whether the number of idle worker threads is greater than the number of tasks. If it is, there are idle worker threads in the thread pool, and no expansion is needed. Otherwise, the required number of worker threads is calculated based on the load, and new threads are created accordingly.

### Contraction Mechanism

After expansion, TaskPool creates multiple worker threads. However, when the number of tasks decreases, these threads become idle, leading to resource wastage. Therefore, TaskPool provides a contraction mechanism. TaskPool uses a timer to detect the current load every 30 seconds and attempts to release idle worker threads. A thread can be released if it meets the following conditions:

- The thread has been idle for at least 30 seconds.

- The thread has not executed any [long tasks](../reference/apis-arkts/js-apis-taskpool.md#longtask12).

- There are no service requests or unreleased handles on the thread, such as [Timers](../reference/common/js-apis-timer.md).

- The thread is not in a debugging or optimization phase.

- There are no created but not yet destroyed child Worker thread in the thread.
