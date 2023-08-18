# Comparison Between TaskPool and Worker


**TaskPool** and **Worker** provide a multithread running environment for applications to process time-consuming computing tasks or resource intensive tasks, preventing these tasks from blocking the main thread. This maximizes system utilization, reduces overall resource consumption, and improves overall system performance.


This topic compares **TaskPool** with **Worker** from two aspects: [implementation features](#implementation-feature-comparison) and [use cases](#use-case-comparison). It also describes their operating mechanisms and precautions.


## Implementation Feature Comparison

**Table 1** Comparison between TaskPool and Worker in implementation features

| Item| TaskPool | Worker |
| -------- | -------- | -------- |
| Memory model| Threads are isolated from each other, and memory is not shared.| Threads are isolated from each other, and memory is not shared.|
| Parameter passing mechanism| The structured clone algorithm is used for serialization and deserialization.<br>ArrayBuffer and SharedArrayBuffer are used for parameter passing and sharing.| The structured clone algorithm is used for serialization and deserialization.<br>ArrayBuffer and SharedArrayBuffer are used for parameter passing and sharing.|
| Parameter passing| Parameters are directly passed in, without being encapsulated.| Only one parameter can be carried in a message object. Therefore, you must encapsulate excess parameters.|
| Method invocation| Methods are directly passed in and called.| Messages are passed in the worker thread and the corresponding methods are called.|
| Return value| A value is returned by default after asynchronous calling.| Messages proactively sent must be parsed and assigned by calling **onmessage()**.|
| Lifecycle| The task pool manages its own lifecycle, without considering the load.| You are required to manage the number and lifecycle of worker threads.|
| Maximum number of task pools| The number is automatically managed, rather than being manually configured.| A maximum of eight worker threads are supported.|
| Maximum task execution duration| There is no restriction.| There is no restriction.|
| Task priority setting| Setting the task priority is not supported.| Setting the task priority is not supported.|
| Task cancellation| Tasks waiting in the task queue can be canceled.| Tasks waiting in the task queue cannot be canceled.|


## Use Case Comparison

Both **TaskPool** and **Worker** support multithread concurrency. **TaskPool** is oriented to thread-level independent tasks. **Worker** is oriented to threads and supports thread execution for a long time.

Common use cases are as follows:

- Use **Worker** for a series of associated synchronous tasks. For example, use **Worker** for a series of database operations, since the same handle is required.

- Use **TaskPool** for a task that needs to be canceled frequently. For example, in the large image browsing scenario in Gallery, both images on the left and right sides of the current image are cached. When the user slides to the next image, a cache task on one side needs to be canceled. In this case, use **TaskPool**.

- Use **TaskPool** for a large number of tasks or tasks with scattered scheduling points. For example, a large-scale application with multiple modules has multiple time-consuming tasks, and it is inconvenient to use eight worker threads to manage load. In this case, **TaskPool** is recommended.


## TaskPool Operating Mechanism

**Figure 1** TaskPool operating mechanism

![taskpool](figures/taskpool.png)

With **TaskPool**, you can encapsulate tasks in the main thread and throw the tasks to the task queue. The system selects proper worker threads to distribute and execute the tasks, and then returns the result to the main thread. **TaskPool** provides APIs to execute and cancel tasks. A maximum of 4 **TaskPool** worker threads are supported.


## Worker Operating Mechanism

**Figure 2** Worker operating mechanism

![worker](figures/worker.png)

The thread that creates the worker thread is referred to as the host thread (not necessarily the main thread, since a worker thread can also create a worker subthread). A worker thread is also named an actor thread. Each worker thread has an independent instance from the host thread, including the infrastructure, object, and code segment. The worker thread communicates with the host thread by means of message exchange. They use the serialization technique to exchange commands and data.


## Precautions for TaskPool

- A task function must be decorated with **\@Concurrent** and can be used only in .ets files.

- A task function must be a common function or async function, but not a class member function or anonymous function.

- A task function can use imported variables and input parameter variables only in a project created on the stage model. In a project created on the FA model, it can use input parameter variables only.

- Input parameter types in a task function must be those supported by serialization. For details, see [Common Objects](multi-thread-concurrency-overview.md#common-objects).

- The context objects in different threads are different. Therefore, **TaskPool** worker threads can use only thread-safe libraries, rather than UI-related non-thread-safe libraries.

- A maximum of 16 MB data can be serialized at a time.


## Precautions for Worker

- The rules for passing in the **Worker.ts** path during the worker creation vary in different API versions. For details, see [Precautions for File Paths](#precautions-for-file-paths).

- After a worker thread is created, you must manually manage its lifecycle. A maximum of eight worker threads can run simultaneously. For details, see [Lifecycle Precautions](#lifecycle-precautions).

- Modules of the [ability type](../quick-start/application-package-structure-stage.md) support **Worker**, but modules of the [library type](../quick-start/application-package-structure-stage.md) do not support **Worker**.

- When creating a worker thread, the **Worker.ts** file of another module cannot be used. This means that a worker cannot be called across modules.

- The context objects in different threads are different. Therefore, **Worker** threads can use only thread-safe libraries, rather than UI-related non-thread-safe libraries.

- A maximum of 16 MB data can be serialized.


### Precautions for File Paths

  Before calling an API of the **Worker** module, you must create a **Worker** instance. The constructor function varies in different API versions.

```js
// Use the following function in API version 9 and later versions:
const worker1 = new worker.ThreadWorker(scriptURL);
// Use the following function in API version 8 and earlier versions:
const worker1 = new worker.Worker(scriptURL);
```

The **Worker.ts** file path (specified by **scriptURL**) must be passed in the constructor function. By default, the **workers** directory (upper-level directory of the **Worker.ts** file) is at the same level as the **pages** directory.

**Stage Model**


The following is an example of **scriptURL** in the constructor function:

```js
// Method 1
// In the stage model, the workers directory is at the same level as the pages directory in the entry module.
const worker1 = new worker.ThreadWorker('entry/ets/workers/MyWorker.ts', {name:"first worker in Stage model"});
// In the stage model, the workers directory is a child directory of the pages directory in the entry module.
const worker2 = new worker.ThreadWorker('entry/ets/pages/workers/MyWorker.ts');

// Method 2
// In the stage model, the workers directory is at the same level as the pages directory in the entry module, and bundlename is com.example.workerdemo.
const worker3 = new worker.ThreadWorker('@bundle:com.example.workerdemo/entry/ets/workers/worker');
// In the stage model, the workers directory is a child directory of the pages directory in the entry module, and bundlename is com.example.workerdemo.
const worker4 = new worker.ThreadWorker('@bundle:com.example.workerdemo/entry/ets/pages/workers/worker');
```


- Based on the directory structure of the stage model project, the field meanings in method 1 are as follows:
  - **entry**: value of the **name** attribute under **module** in the **module.json5** file.
  - **ets**: directory for storing the ArkTS source code. It is fixed.
  - **workers/MyWorker.ts**: path of the worker source file in the **ets** directory.

- Based on the directory structure of the stage model project, the field meanings in method 2 are as follows:
  - **\@bundle**: fixed label.
  - **bundlename**: bundle name of the current application.
  - **entryname**: value of the **name** attribute under **module** in the **module.json5** file.
  - **ets**: directory for storing the ArkTS source code. It is fixed.
  - **workerdir/workerfile**: path of the worker source file in the **ets** directory.


**FA Model**


The following is an example of **scriptURL** in the constructor function:

```js
// In the FA model, the workers directory is at the same level as the pages directory in the entry module.
const worker1 = new worker.ThreadWorker('workers/worker.js', {name:'first worker in FA model'});
// In the FA model, the workers directory is at the same level as the parent directory of the pages directory in the entry module.
const worker2 = new worker.ThreadWorker('../workers/worker.js');
```


### Lifecycle Precautions

- Creating and terminating worker threads consume performance. Therefore, you are advised to manage available workers and reuse them. The worker threads keep running even when they are idle. Therefore, when a worker thread is not required, call [terminate()](../reference/apis/js-apis-worker.md#terminate9) interface or [parentPort.close()](../reference/apis/js-apis-worker.md#close9) to destroy it. If a worker thread is destroyed or being destroyed, an error is thrown when it is called.


- A maximum of eight worker threads can co-exist.
  - In API version 8 and earlier versions, when the number of worker threads exceeds the upper limit, the error "Too many workers, the number of workers exceeds the maximum." is thrown.
  - Since API version 9, when the number of worker threads exceeds the upper limit, the error "Worker initialization failure, the number of workers exceeds the maximum." is thrown.
