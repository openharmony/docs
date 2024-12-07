# TaskPool Introduction

TaskPool provides a multithreaded environment for applications. It helps reduce resource consumption and improve system performance. It also frees you from caring about the lifecycle of thread instances. For details about the APIs and their usage, see [TaskPool](../reference/apis-arkts/js-apis-taskpool.md).

## TaskPool Operating Mechanism

TaskPool operating mechanism

![image_0000001964858368](figures/image_0000001964858368.png)

With TaskPool, you can encapsulate tasks in the main thread and throw the tasks to the task queue. The system selects proper worker threads to distribute and execute the tasks, and then returns the result to the main thread. TaskPool provides APIs to execute and cancel tasks, and set the task priority. It minimizes system resource usage through unified thread management, dynamic scheduling, and load balancing. By default, the system starts a worker thread and increases the thread quantity as the number of tasks increases. The maximum number of worker threads that can be created depends on the number of physical cores of the device. The actual number is managed internally to ensure optimal scheduling and execution efficiency. If no task is distributed for a long period of time, the system reduces the number of worker threads.

## Precautions for TaskPool

- A task function must be decorated with [\@Concurrent](#concurrent-decorator) and can be used only in .ets files.

- Since API version 11, when an instance object with a method is passed across concurrent instances, the class must be annotated with the decorator [@Sendable](arkts-sendable.md#sendable) and can be used only in .ets files.

- A task function in the TaskPool worker thread must finish the execution within 3 minutes (excluding the time used for Promise or async/await asynchronous call, for example, the duration of I/O tasks such as network download and file read/write). Otherwise, it forcibly exits.

- The input parameters of the function for implementing the task must meet the types supported by serialization. For details, see [Inter-Thread Communication Object](interthread-communication-overview.md).

- Parameters of the ArrayBuffer type are transferred in TaskPool by default. You can set the transfer list by calling [setTransferList()](../reference/apis-arkts/js-apis-taskpool.md#settransferlist10).

- The context objects in different threads are different. Therefore, **TaskPool** worker threads can use only thread-safe libraries, rather than UI-related non-thread-safe libraries.

- A maximum of 16 MB data can be serialized.

- Among all the values of [Priority](../reference/apis-arkts/js-apis-taskpool.md#priority), **IDLE** is used to mark time-consuming tasks (such as data synchronization and backup) that need to run in the background Tasks marked with **IDLE** are executed only when all threads are idle and occupy only one thread for execution.

- Promises cannot be transferred across threads. If the TaskPool returns a promise in the pending or rejected state, a failure message is returned. For a promise in the fulfilled state, the TaskPool parses the returned result. If the result can be transferred across threads, a success message is returned.

- [AppStorage](../quick-start/arkts-appstorage.md) cannot be used in the TaskPool worker thread.

## \@Concurrent Decorator

To pass function verification, the concurrent functions executed in a [TaskPool](../reference/apis-arkts/js-apis-taskpool.md) must be decorated using \@Concurrent.

> **NOTE**
>
> Since API version 9, the @Concurrent decorator can be used to declare and verify concurrent functions.

### Decorator Description

| \@Concurrent Decorator| Description|
| -------- | -------- |
| Decorator parameters| None.|
| Use Scenario| The decorator can be used only in projects of the stage model. It can be used only in .ets files.|
| Decorated function types| This decorator can be used for asynchronous functions and common functions. It cannot be used for generators, arrow functions, or methods. It does not support class member functions or anonymous functions.|
| Variable types in decorated functions| Local variables, input parameters, and variables imported through **import** are supported. Closure variables are not allowed.|
| Return value types in decorated functions| For details about the supported types, see [Inter-Thread Communication Object](interthread-communication-overview.md).|

> **Note**
>
> Functions marked by \@Concurrent cannot access closures. Therefore, functions marked by \@Concurrent cannot call other functions of the current file. For example:
>
> ```ts
> function bar() {
> }
> 
> @Concurrent
> function foo() {
> bar (); // The closure principle is violated. An error is reported.
> }
> ```

### Decorator Example

#### Commonly used by concurrent functions

A concurrent function is a common function that calculates the sum of two numbers. The taskpool executes the function and returns the result.

Example:

```ts
import { taskpool } from '@kit.ArkTS';

@Concurrent
function add(num1: number, num2: number): number {
  return num1 + num2;
}

async function ConcurrentFunc(): Promise<void> {
  try {
    let task: taskpool.Task = new taskpool.Task(add, 1, 2);
    console.info("taskpool res is: " + await taskpool.execute(task));
  } catch (e) {
    console.error("taskpool execute error is: " + e);
  }
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
          .onClick(() => {
            ConcurrentFunc();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

#### Promise returned by concurrent functions

Pay attention to the performance of returning Promise in the concurrent function. The concurrent synchronous function processes and returns Promise with the result.

Example:

```ts
import { taskpool } from '@kit.ArkTS';

@Concurrent
function testPromise(args1: number, args2: number): Promise<number> {
  return new Promise<number>((testFuncA, testFuncB)=>{
    testFuncA(args1 + args2);
  });
}

@Concurrent
async function testPromise1(args1: number, args2: number): Promise<number> {
  return new Promise<number>((testFuncA, testFuncB)=>{
    testFuncA(args1 + args2);
  });
}

@Concurrent
async function testPromise2(args1: number, args2: number): Promise<number> {
  return await new Promise<number>((testFuncA, testFuncB)=>{
    testFuncA(args1 + args2);
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
    setTimeout(()=>{
      resolve("Promise setTimeout after resolve");
    }, 1000)
  });
}

async function testConcurrentFunc() {
  let task1: taskpool.Task = new taskpool.Task(testPromise, 1, 2);
  let task2: taskpool.Task = new taskpool.Task(testPromise1, 1, 2);
  let task3: taskpool.Task = new taskpool.Task(testPromise2, 1, 2);
  let task4: taskpool.Task = new taskpool.Task(testPromise3);
  let task5: taskpool.Task = new taskpool.Task(testPromise4);
  let task6: taskpool.Task = new taskpool.Task(testPromise5);

  taskpool.execute(task1).then((d:object)=>{
    console.info("task1 res is: " + d);
  }).catch((e:object)=>{
    console.info("task1 catch e: " + e);
  })
  taskpool.execute(task2).then((d:object)=>{
    console.info("task2 res is: " + d);
  }).catch((e:object)=>{
    console.info("task2 catch e: " + e);
  })
  taskpool.execute(task3).then((d:object)=>{
    console.info("task3 res is: " + d);
  }).catch((e:object)=>{
    console.info("task3 catch e: " + e);
  })
  taskpool.execute(task4).then((d:object)=>{
    console.info("task4 res is: " + d);
  }).catch((e:object)=>{
    console.info("task4 catch e: " + e);
  })
  taskpool.execute(task5).then((d:object)=>{
    console.info("task5 res is: " + d);
  }).catch((e:object)=>{
    console.info("task5 catch e: " + e);
  })
  taskpool.execute(task6).then((d:object)=>{
    console.info("task6 res is: " + d);
  }).catch((e:object)=>{
    console.info("task6 catch e: " + e);
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

#### Using a User-Defined Class or Function in a Concurrent Function

User-defined classes or functions used in concurrent functions must be defined in different files. Otherwise, they will be considered as closures, as shown in the following example.

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
  // Case 1: Directly call a class or function defined in the same file in a concurrent function.

  // Directly call the add () function defined in the same file. The error message "Only imported variables and local variables can be used in @Concurrent decorated functions. <ArkTSCheck>" is displayed in red.
  // add(1);
  // Use the TestA defined in the same file. The error message "Only imported variables and local variables can be used in @Concurrent decorated functions. <ArkTSCheck>" is displayed.
  // let a = new TestA("aaa");
  // Directly access the nameStr member of TestB defined in the same file. The error message "Only imported variables and local variables can be used in @Concurrent decorated functions. <ArkTSCheck>" is displayed in red.
  // console.info("TestB name is: " + TestB.nameStr);

  // Case 2: In the concurrent function, call the class or function defined in the Test.ets file and import the current file.

  // Output result: res1 is: 2
  console.info("res1 is: " + testAdd(1));
  let tmpStr = new MyTestA("TEST A");
  // Output result: res2 is: TEST A
  console.info("res2 is: " + tmpStr.name);
  // Output: res3 is: MyTestB
  console.info("res3 is: " + MyTestB.nameStr);
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
          let task = new taskpool.Task(TestFunc);
          taskpool.execute(task).then(() => {
            console.info("taskpool: execute task success!");
          }).catch((e:BusinessError) => {
            console.error(`taskpool: execute: Code: ${e.code}, message: ${e.message}`);
          })
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

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

#### Using Promise in a Concurrent Asynchronous Function

If Promise is used in the concurrent asynchronous function, you are advised to use await to capture exceptions that may occur in Promise. A recommended example is provided below.

Example:

```ts
import { taskpool } from '@kit.ArkTS'

@Concurrent
async function testPromiseError() {
  await new Promise<number>((resolve, reject) => {
    resolve(1);
  }).then(()=>{
    throw new Error("testPromise Error");
  })
}

@Concurrent
async function testPromiseError1() {
  await new Promise<string>((resolve, reject) => {
    reject("testPromiseError1 Error msg");
  })
}

@Concurrent
function testPromiseError2() {
  return new Promise<string>((resolve, reject) => {
    reject("testPromiseError2 Error msg");
  })
}

async function testConcurrentFunc() {
  let task1: taskpool.Task = new taskpool.Task(testPromiseError);
  let task2: taskpool.Task = new taskpool.Task(testPromiseError1);
  let task3: taskpool.Task = new taskpool.Task(testPromiseError2);

  taskpool.execute(task1).then((d:object)=>{
    console.info("task1 res is: " + d);
  }).catch((e:object)=>{
    console.info("task1 catch e: " + e);
  })
  taskpool.execute(task2).then((d:object)=>{
    console.info("task2 res is: " + d);
  }).catch((e:object)=>{
    console.info("task2 catch e: " + e);
  })
  taskpool.execute(task3).then((d:object)=>{
    console.info("task3 res is: " + d);
  }).catch((e:object)=>{
    console.info("task3 catch e: " + e);
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
