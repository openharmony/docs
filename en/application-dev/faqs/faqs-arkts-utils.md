# ArkTS Common Library Development


## Is memory isolation available between TaskPool, Worker, and ArkTS engine instances?

**TaskPool** and **Worker** implement concurrency based on the actor model, which features memory isolation. As such, memory isolation is implemented between **TaskPool**, **Worker**, and ArkTS engine instances.


## When will a TaskPool thread be destroyed in the task pool lifecycle?

You do not need to manually manage the lifecycle of a task pool. If no task is executed for a certain period of time or no listening task is executed on the **TaskPool** thread, the thread may be destroyed.


## Does TaskPool have restrictions on the task duration?

The maximum task duration is 3 minutes (excluding the time used for Promise or async/await asynchronous call).


## Which is recommended for scenarios with a large number of preloading tasks?

A maximum of eight worker threads can co-exist. As such, **TaskPool** is recommended in this case. For details about the implementation features and use cases of **TaskPool** and **Worker**, see [Comparison Between Worker and TaskPool](../arkts-utils/taskpool-vs-worker.md).


## Which is recommended in concurrent scenarios where threads need to be reused?

A worker cannot execute different tasks. As such, **TaskPool** is recommended in this case.

## Can I dynamically load modules (HAR, HSP, and .so modules) in TaskPool? (API version 10)

Yes. **TaskPool** provides the same dynamic loading capability as the main thread. However, after a **TaskPool** thread is loaded, it cannot be reused by the main thread due to modular thread isolation.

## How do I implement multithreaded data sharing? (API version 10)

ArkTS uses a single-thread model and features memory isolation. Therefore, most common objects use serialization mode to implement cross-thread sharing.

An object can be shared by transferring an ArrayBuffer or using a SharedArrayBuffer.

**References**

[Multithreaded Concurrency Overview (TaskPool and Worker)](../arkts-utils/multi-thread-concurrency-overview.md)

## Cross-thread communication of JS objects depends on serialization. Is there any performance problem? (API version 10)

Cross-thread object communication depends on serialization and deserialization, and the time required is related to the data volume. Therefore, you need to control the data volume to be transmitted, or use an ArrayBuffer or SharedArrayBuffer for transfer or sharing.


## Some applications have more than 200 threads. Neither TaskPool nor Worker supports so many threads. How do I design a concurrent scheme? (API version 10)

The underlying thread model interconnects with libuv. Therefore, after an application process starts, multiple I/O threads are used for I/O operations. For a JS thread, its asynchronous I/O operations are executed in the I/O threads, and it can handle other operations simultaneously. As such, this does not cause blocking and waiting issues.

In addition, ArkTS provides TaskPool concurrent APIs, which are similar to the thread pool of GCD. Tasks can be executed without thread lifecycle management.

To address the problem that a large number of threads are required, you are advised to:

- Convert multi-thread tasks into concurrent tasks and distribute them through the task pool.
- Execute I/O tasks in the calling thread (which can be the **TaskPool** thread), rather than starting new threads for them.
- Use worker threads (no more than 8) for resident CPU intensive tasks (which is of a small number).

**References**

[Comparison Between TaskPool and Worker](../arkts-utils/taskpool-vs-worker.md)

## How do I set task priorities, what are the differences between scheduling policies for these priorities, and what are the recommended scenarios for them? (API version 10)

You can set different priorities for different tasks.

**Sample Code**

```ts
@Concurrent
function printArgs(args: number): number {
  console.log("printArgs: " + args);
  return args;
}

let task: taskpool.Task = new taskpool.Task(printArgs, 100); // 100: test number
let highCount = 0;
let mediumCount = 0;
let lowCount = 0;
let allCount = 100;
for (let i: number = 0; i < allCount; i++) {
  taskpool.execute(task, taskpool.Priority.LOW).then((res: number) => {
    lowCount++;
    console.log("taskpool lowCount is :" + lowCount);
  });
  taskpool.execute(task, taskpool.Priority.MEDIUM).then((res: number) => {
    mediumCount++;
    console.log("taskpool mediumCount is :" + mediumCount);
  });
  taskpool.execute(task, taskpool.Priority.HIGH).then((res: number) => {
    highCount++;
    console.log("taskpool highCount is :" + highCount);
  });
}
```

**References**

[Priority](../reference/apis/js-apis-taskpool.md)

## How do I convert the implementation in the Java-like thread model (memory sharing) to the implementation in the ArkTS thread model (memory isolation)? (API version 10)

Use **TaskPool** APIs for conversion in the following scenarios:

Scenario 1: Execute independent time-consuming tasks in a subthread, rather than the main thread. 

Sample code for memory sharing

```ts
class Task {
  static run(args) {
    // Do some independent task
  }
}

let thread = new Thread(() => {
  let result = Task.run(args)
  // deal with result
})
```

ArkTS sample code

```ts
import taskpool from '@ohos.taskpool'
@Concurrent
function run(args: string) {
  // Do some independent task
}

let args: string = '';
let task = new taskpool.Task(run, args)
taskpool.execute(task).then((ret: string) => {
  // Return result
})
```

Scenario 2: Use the created class instance in a subthread, rather than the main thread. 

Sample code for memory sharing 

```ts
class Material {
  action(args) {
    // Do some independent task
  }
}

let material = new Material()
let thread = new Thread(() => {
  let result = material.action(args)
  // deal with result
})
```

ArkTS sample code

```ts
import taskpool from '@ohos.taskpool'
@Concurrent
function runner(material: Material, args: string): void {
  return material.action(args);
}

class Material {
  action(args: string) {
    // Do some independent task
  }
}

let material = new Material()
taskpool.execute(runner, material).then((ret: string) => {
  // Return result
})
```

Scenario 3: Execute independent time-consuming tasks in a subthread, rather than the main thread. 
Sample code for memory sharing

```ts
class Task {
  run(args) {
    // Do some independent task
    task.result = true
  }
}

let task = new Task()
let thread = new Thread(() => {
  let result = task.run(args)
  // deal with result
})
```

ArkTS sample code

```ts
import taskpool from '@ohos.taskpool'
@Concurrent
function runner(task: Task) {
  let args: string = '';
  task.run(args);
}

class Task {
  result: string = '';

  run(args: string) {
    // Do some independent task
    return true;
  }
}

let task = new Task();
taskpool.execute(runner, task).then((ret: string) => {
  task.result = ret;
})
```


**References**

[Concurrency Overview](../arkts-utils/concurrency-overview.md)

## What are the differences between TaskPool and Worker? What are their recommended scenarios? (API version 10)

**TaskPool** and **Worker** are concurrent APIs of different granularities. **TaskPool** provides APIs at the level of tasks, whereas **Worker** provides APIs at the level of threads or services. 

**TaskPool** simplifies concurrent program development, supports priority setting and cancellation, and saves system resources and optimizes scheduling through unified management. 

Similarities: In terms of interaction with JS-related threads, both of them feature memory isolation. They pose the same restrictions on parameters and value ranges, and they also have overhead. (Pay attention to the granularity of concurrent tasks.)

**References**

[Comparison Between TaskPool and Worker](../arkts-utils/taskpool-vs-worker.md)

## Do Worker and TaskPool limit the number of threads? What will happen if the maximum number is reached? Will the task pool be affected when the number of worker threads reaches the upper limit? (API version 10)

**TaskPool** dynamically adjusts the number of threads based on hardware conditions and task loads. It does not support setting a number. Tasks are added to the thread pool, and high-priority tasks are executed first.

A maximum of eight worker threads can be created. No more worker threads can be created when the maximum number is reached.

**TaskPool** and **Worker** are independent of each other.  

**References**

[Comparison Between TaskPool and Worker](../arkts-utils/taskpool-vs-worker.md)

## Is there a thread-safe container class? (API version 10)

Objects are not directly shared, and therefore all containers are thread-safe.

**References**

[Asynchronous Concurrency Overview (Promise and Async/Await)](../arkts-utils/async-concurrency-overview.md)

## What is the task scheduling mechanism in TaskPool and Worker? Do they provide the same event loop mechanism as the JS single thread?  (API version 10)

**TaskPool** and **Worker** use the event loop to receive messages exchanged between threads.
**Worker** does not support the setting of the message priority, but **TaskPool** does.

## What is the multithreading model of the system? (API version 10)

**TaskPool** APIs are provided to support multithreading development. Resident time-consuming tasks can use worker threads, with the maximum number limited to eight.

It is recommended that the FFRT thread pool be used on the native side. There is no restriction on pthread.

## Can context be transferred across threads? (API version 10)

Yes. Context can be directly transferred as a parameter.

**References**

[Shared Objects](../arkts-utils/serialization-support-types.md)

## How do I implement secure access to the same shared memory in multithreaded concurrency scenarios? (API version 10)

You can use SharedArrayBuffer. If multiple operations are simultaneously performed to modify data stored in an object of the SharedArrayBuffer type, you must use atomic operations to ensure data synchronization. The atomic operations ensure that the current operation is complete before the next operation starts.

**Sample Code**

```ts
// index.ets
let sab = new SharedArrayBuffer(32);
// int32 buffer view for sab
let i32a = new Int32Array(sab);
i32a[0] = 0;

let producer = new worker.ThreadWorker("entry/ets/workers/worker_producer.ts");
producer.postMessage(sab);

function consumection(e: MessageEvents) {
  let sab: SharedArrayBuffer = e.data;
  let i32a = new Int32Array(sab);
  console.info("Customer: received sab");
  while (true) {
    Atomics.wait(i32a, 0, 0); //blocked here until be waked.
    let length = i32a.length;
    for (let i = length - 1; i > 0; i--) {
      console.info("arraybuffer " + i + " value is " + i32a[i]);
      i32a[i] = i;
    }
  }
}
```

## Which has a higher priority, the main thread or subthread? What are their task execution policies? (API version 10)

As the UI thread, the main thread has the highest priority. When the load is high, a thread with a higher priority is executed faster. When the load is low, the execution pace is similar for threads with different priorities.

Subthreads support priority setting, and the priority affects their scheduling.

## Are there ArkTS APIs for forcibly switching thread execution and scheduling globally? (API version 10)

**Worker** can throw tasks to the parent thread through **PostMessage**. **TaskPool** can send messages to the parent thread to trigger tasks.

**References**

1. [@ohos.taskpool (Using the Task Pool)](../reference/apis/js-apis-taskpool.md)
2. [@ohos.worker (Worker Startup)](../reference/apis/js-apis-worker.md)

## Does ArkTS support multithreading development using a Java-like shared memory model? (API version 10)

Multiple threads cannot perform operations on the same memory object simultaneously by locking the memory object. ArkTS is an actor model that supports cross-thread memory isolation. Currently, only SharedArrayBuffer or native-layer objects can be shared.

**References**

[Multithreaded Concurrency Overview (TaskPool and Worker)](../arkts-utils/multi-thread-concurrency-overview.md)


## Do ArkTS APIs support overloading? How do I implement overloading in them? (API version 10)

ArkTS supports overloading in TS, that is, multiple overload signatures + implementation signature + function bodies. Function signatures are used only for type check during build. They are not retained at runtime.

ArkTS does not support overloading of multiple function bodies.

**Sample Code**

```ts
class User {
  age: number

  constructor(age: number) {
    this.age = age
  }
}

// Declaration
function test(param: User): number;

function test(param: number, flag: boolean): number;

// Implementation
function test(param: User | number, flag?: boolean) {
  if (typeof param === 'number') {
    return param + (flag ? 1 : 0)
  } else {
    return param.age
  }
}
```

##  What is the thread mechanism? Is each thread a separate JS engine? If a thread has relatively low overhead, why is the number of threads limited? (API version 10)

A device has a limited number of cores. Too many threads cause high scheduling overhead and memory overhead.

The system provides the ArkTS task pool and FFRT task pool to support unified scheduling.

The JS part of the ArkTS thread is implemented based on the actor model. Each thread has an independent JS environment instance. Therefore, starting a thread consumes a large amount of memory.

In other operating systems, the large number of application threads is caused by the synchronization lock and synchronization I/O programming.

In OpenHarmony, asynchronous I/O calls are distributed to the I/O thread pool and do not block application threads. Therefore, the number of threads required is far less than that in other operating systems. 

##  How does the task pool communicate with the main thread during task execution? How do I implement simultaneous access to the same memory variable? (API version 10)

Tasks in the task pool can trigger the **onReceiveData** callback of the main thread through **sendData**. 
Multiple threads can use SharedArrayBuffer to operate the memory block.

##  Are multithreading operations on the preferences and databases thread safe? (API version 10)

They are thread safe.

##  If most background tasks (computing, tracing, and storage) in ArkTS use asynchronous concurrency mode, will the main thread become slower and finally cause frame freezing and frame loss? (API version 10)

If I/O operations are not involved, asynchronous tasks of ArkTS APIs are triggered at the microtask execution time of the main thread and still occupy the main thread. You are advised to use **TaskPool** to distribute the tasks to the background task pool.

##  How do I implement synchronous function calls in ArkTS as easily as using **synchronized** in Java methods? (API version 10)

Currently, the use of **synchronized** is not supported. In the future, the AsyncLock synchronization mechanism will be supported, where code blocks to be synchronized can be placed in asynchronous code blocks.

##  Will the main thread be blocked if await is used in the main thread of ArkTS? (API version 10)

**Description**

If the following code is executed in the main thread, will the main thread be blocked?

`const response = await reqeust.buildCall().execute<string>();`  

**Answer**

It will not block the main thread. await suspends the current asynchronous task and wakes up the task until the conditions are met. The main thread can process other tasks.

##  In C/C++ code, how do I directly call ArkTS APIs in the subthread instead of posting messages to the main thread? (API version 10)

Direct calls are not supported yet.

## Is the underlying running environment of ArkTS code self-developed or open-source? Is the same running environment used for React Native code? (API version 10)

- On the in-house ArkCompiler, the bytecode is run. The bytecode is generated after the ArkTS, TS, or JS source code is compiled using the ArkCompiler toolchain.
- For React Native, the JS source code is run on the V8 engine provided by the system.

## What data type conversion methods are used in ArkTS? Are they consistent with TS? (API version 10)

ArkTS supports as type conversion of TS, but not type conversion using the <> operator. Currently, the as type conversion can be used during build, but not at runtime.

ArkTS also supports built-in type conversion functions, such as **Number()**, **String()**, and **Boolean()**.

**References**

[TypeScript to ArkTS Cookbook](../quick-start/typescript-to-arkts-migration-guide.md)

## Can an application manage the background I/O task pool? Is any open API provided for management? (API version 10)

- The background TaskPool threads are determined by the load and hardware. No open API is provided. However, you can use the serial queue and task group for task management.
- The I/O task pool is scheduled at the bottom layer and cannot be managed by an application.

## Will the system continue to support .ts file development in the future? (API version 10)

**Description**

Will the basic libraries implemented based on TS be compatible in the future? For example, the .ts file supports **any** and dynamic type conversion at runtime, but the .ets file does not.

**Answer**

The system will continue to support the standard TS syntax and be compatible with the existing third-party libraries implemented on TS.

## Is dynamic module loading supported? How do I implement it? (API version 10)

Currently, the binary package on the device side cannot be dynamically loaded. You can use the dynamic import feature for asynchronous loading. This achieves the effect similar to the reflection API **Class.forName()**.

The following is an example. The HAP dynamically imports **harlibrary** and calls the static member function **staticAdd()**, instance member function **instanceAdd()**, and global method **addHarLibrary()**. 

```ts
/ / src/main/ets/utils/Calc.ets of harlibrary
export class Calc {
  public constructor() {}
  public static staticAdd(a: number, b: number): number {
    let c = a + b;
    console.log("DynamicImport I'm harLibrary in staticAdd, %d + %d = %d", a, b, c);
    return c;
  }
  public instanceAdd(a: number, b: number): number {
    let c = a + b;
    console.log("DynamicImport I'm harLibrary in instanseAdd, %d + %d = %d", a, b, c);
    return c;
  }
}

export function addHarLibrary(a: number, b: number): number {
  let c = a + b;
  console.log("DynamicImport I'm harLibrary in addHarLibrary, %d + %d = %d", a, b, c);
  return c;
}

// index.ets of harlibrary
export { Calc, addHarLibrary } from './src/main/ets/utils/Calc';

// index.ets of hap
let harLibrary = 'harlibrary';
import(harLibrary).then((ns: ESObject) => {  // Dynamic variable import is a new feature. Changing an input parameter to the string 'harlibrary' is supported in earlier versions. You can also use the await import mode.
  ns.Calc.staticAdd(7, 8);  // Call the static member function staticAdd() with reflection.
  let calc: ESObject = new ns.Calc();  // Instantiate the class Calc.
  calc.instanceAdd(8, 9);  // Call the instance member function instanceAdd().
  ns.addHarLibrary(6, 7);  // Call the global method addHarLibrary().
});
```



## Multithreading occupies a large amount of memory. Each thread requires an ArkTS engine, which means more memory is occupied. How do I fully utilize the device performance with a limited number of threads?

The ArkTS worker thread creates an ArkTS engine instance, which occupies extra memory.

In addition, ArkTS provides TaskPool concurrent APIs, which are similar to the thread pool of GCD. Tasks can be executed without thread lifecycle management. Tasks are scheduled to a limited number of worker threads for execution. Multiple tasks share these worker threads (ArkTS engine instances). The system scales in or out the number of worker threads based on the load to maximize the hard performance.

To address the problem that a large number of threads are required, you are advised to:

1. Convert multi-thread tasks into concurrent tasks and distribute them through the task pool.
2. Execute I/O tasks in the calling thread (which can be the TaskPool thread), rather than starting new threads for them.
3. Use worker threads (no more than 8) for resident CPU intensive tasks (which is of a small number).

**References**

[Comparison Between TaskPool and Worker](../arkts-utils/taskpool-vs-worker.md)

## Can long-time listening interfaces, such as **emitter.on**, be used in a TaskPool thread?

Not recommended.

**Principle Clarification**

1. Long-time listening may adversely affect thread recycling or reuse.
2. If a thread is reclaimed, the thread callback becomes invalid or an unexpected error occurs.
3. If a task function is executed for multiple times, listening may be generated in different threads. Consequently, the result may fail to meet your expectation.
