# Comparison Between TaskPool and Worker


**TaskPool** and **Worker** provide a multithread running environment for applications to process time-consuming computing tasks or resource intensive tasks, preventing these tasks from blocking the main thread. This maximizes system utilization, reduces overall resource consumption, and improves overall system performance.


This topic compares **TaskPool** with **Worker** from two aspects: [implementation features](#implementation-feature-comparison) and [use cases](#use-case-comparison). It also describes their operating mechanisms and precautions.


## Implementation Feature Comparison

**Table 1** Comparison between TaskPool and Worker in implementation features

| Item| TaskPool | Worker |
| -------- | -------- | -------- |
| Memory model| Threads are isolated from each other, and memory is not shared.| Threads are isolated from each other, and memory is not shared.|
| Parameter passing mechanism| The structured clone algorithm is used for serialization and deserialization.<br>ArrayBuffer and SharedArrayBuffer are used for parameter passing and sharing.| The structured clone algorithm is used for serialization and deserialization.<br>ArrayBuffer and SharedArrayBuffer are used for parameter passing and sharing.|
| Parameter passing| Parameters are passed in without being encapsulated.| Only one parameter can be carried in a message object. Therefore, you must encapsulate excess parameters.|
| Method invocation| Methods are directly passed in and called.| Methods are called after corresponding messages have been passed in and parsed in the worker thread.|
| Return value| A value is returned by default after asynchronous calling.| Messages proactively sent must be parsed and assigned by calling **onmessage()**.|
| Lifecycle| The task pool manages its own lifecycle, without considering the load.| You are required to manage the number and lifecycle of worker threads.|
| Maximum number of tasks| The number is automatically managed, rather than being manually configured.| A maximum of eight worker threads can run simultaneously in the same process.|
| Maximum task execution duration| 3 minutes (excluding the time used for Promise or async/await asynchronous call, for example, the time consumed by I/O tasks such as network download and file read/write)| There is no restriction.|
| Task priority setting| Supported.| Not supported.|
| Task cancellation| Supported.| Not supported.|


## Use Case Comparison

Both **TaskPool** and **Worker** support multithread concurrency. **TaskPool** worker threads are bound to the system scheduling priority and support load balancing (automatic scaling). **Worker** threads are manually created and do not support scheduling priority setting. Therefore, **TaskPool** provides better performance than **Worker** and is recommended in most scenarios.

**TaskPool** is oriented to independent tasks. These tasks are executed in threads and automatically reclaimed by the system if they are running for more than 3 minutes. Therefore, you do not need to care about the thread lifecycle. On the contrary, **Worker** is oriented to threads and supports thread execution for a long time. You need to manage the thread lifecycle.

Common use cases are as follows:

- Use **Worker** for a task that runs for more than 3 minutes (excluding the time used for Promise or async/await asynchronous call, for example, I/O tasks such as network download and file read/write). For example, use **Worker** for a 1-hour prediction algorithm training job in the background.

- Use **Worker** for a series of associated synchronous tasks. For example, in scenarios where handles are used, if different handles are created each time and they must be stored permanently for subsequent operation, use **Worker**.

- Use **TaskPool** for a task for which the priority needs to be set. For example, in the histogram rendering scenario in Gallery, histogram data calculated in the background is used for UI display on the foreground. Therefore, histogram data calculation must be treated with high priority. In this case, use **TaskPool**.

- Use **TaskPool** for a task that is subject to cancellation at any time. For example, in the large image browsing scenario in Gallery, two images before and after the current image are cached. When the user swipes one side, the image cache task on the other side needs to be canceled. In this case, use **TaskPool**.

- Use **TaskPool** for a large number of tasks or tasks with scattered scheduling points. For example, a large application with multiple modules may have multiple time-consuming tasks, and it is inconvenient to use multiple worker threads to manage load. In this case, **TaskPool** is recommended.


## TaskPool Operating Mechanism

**Figure 1** TaskPool operating mechanism

![taskpool](figures/taskpool.png)

With **TaskPool**, you can encapsulate tasks in the main thread and throw the tasks to the task queue. The system selects proper worker threads to distribute and execute the tasks, and then returns the result to the main thread. **TaskPool** provides APIs to execute and cancel tasks, and set the task priority. It minimizes system resource usage through unified thread management, dynamic scheduling, and load balancing algorithms. By default, the system starts a worker thread and increases the thread quantity as the number of tasks increases. The maximum number of worker threads that can be created depends on the number of physical cores of the device. The actual number is managed internally to ensure optimal scheduling and execution efficiency. If no task is distributed for a long period of time, the system reduces the number of worker threads.


## Worker Operating Mechanism

**Figure 2** Worker operating mechanism

![worker](figures/worker.png)

The thread that creates the worker thread is referred to as the host thread (not necessarily the main thread, since a worker thread can also create a worker subthread). A worker thread is also named an actor thread. Each worker thread has an independent instance from the host thread, including the infrastructure, object, and code segment. The worker thread communicates with the host thread by means of message exchange. They use the serialization technique to exchange commands and data.


## Precautions for TaskPool

- A task function must be decorated with [\@Concurrent](arkts-concurrent.md) and can be used only in .ets files.

- A task function in the **TaskPool** worker thread must finish the execution within 3 minutes (excluding the time used for Promise or async/await asynchronous call, for example, the duration of I/O tasks such as network download and file read/write). Otherwise, it forcibly exits.

- Input parameter types in a task function must be those supported by serialization. For details, see [Data Transfer Objects](multi-thread-concurrency-overview.md#data-transfer-objects).

- Parameters of the ArrayBuffer type are transferred in **TaskPool** by default. You can set the transfer list by calling [setTransferList()](../reference/apis/js-apis-taskpool.md#settransferlist10).

- The context objects in different threads are different. Therefore, **TaskPool** worker threads can use only thread-safe libraries, rather than UI-related non-thread-safe libraries.

- A maximum of 16 MB data can be serialized.


## Precautions for Worker

- The rules for passing in the **Worker.ts** path during the worker thread creation vary in different API versions. For details, see [Precautions for File Paths](#precautions-for-file-paths).

- After a worker thread is created, you must manually manage its lifecycle. A maximum of eight worker threads can run simultaneously. For details, see [Lifecycle Precautions](#lifecycle-precautions).

- Modules of the [ability type](../quick-start/application-package-structure-stage.md) support **Worker**, but modules of the [library type](../quick-start/application-package-structure-stage.md) do not.

- When creating a worker thread, the **Worker.ts** file of another module cannot be used. This means that a worker cannot be called across modules.

- The context objects in different threads are different. Therefore, **Worker** threads can use only thread-safe libraries, rather than UI-related non-thread-safe libraries.

- A maximum of 16 MB data can be serialized.

- You must register the **onerror** API in the main thread to listen for worker thread errors, which might cause a JavaScript crash.


### Precautions for File Paths

  Before calling an API of the **Worker** module, you must create a **Worker** instance. The constructor function varies in different API versions.

```ts
// Import the module.
import worker form '@ohos.worker';

// Use the following function in API version 9 and later versions:
const worker1: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/MyWorker.ts');
// Use the following function in API version 8 and earlier versions:
const worker2: worker.Worker = new worker.Worker('entry/ets/workers/MyWorker.ts');
```

The **Worker.ts** file path (specified by **scriptURL**) must be passed in the constructor function. By default, the **workers** directory (upper-level directory of the **Worker.ts** file) is at the same level as the **pages** directory.

**Stage Model**

The following is an example of **scriptURL** in the constructor function:


```ts
// Import the module.
import worker form '@ohos.worker';

// Method 1
// In the stage model, the workers directory is at the same level as the pages directory in the entry module.
const worker1: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/MyWorker.ts', {name:"first worker in Stage model"});
// In the stage model, the workers directory is a child directory of the pages directory in the entry module.
const worker2: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/pages/workers/MyWorker.ts');

// Method 2
// In the stage model, the workers directory is at the same level as the pages directory in the entry module, and bundlename is com.example.workerdemo.
const worker3: worker.ThreadWorker = new worker.ThreadWorker('@bundle:com.example.workerdemo/entry/ets/workers/worker');
// In the stage model, the workers directory is a child directory of the pages directory in the entry module, and bundlename is com.example.workerdemo.
const worker4: worker.ThreadWorker = new worker.ThreadWorker('@bundle:com.example.workerdemo/entry/ets/pages/workers/worker');
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

```ts
// Import the module.
import worker form '@ohos.worker';

// In the FA model, the workers directory is at the same level as the pages directory in the entry module.
const worker1: worker.ThreadWorker = new worker.ThreadWorker('workers/worker.js', {name:'first worker in FA model'});
// In the FA model, the workers directory is at the same level as the parent directory of the pages directory in the entry module.
const worker2: worker.ThreadWorker = new worker.ThreadWorker('../workers/worker.js');
```


### Lifecycle Precautions

- Creating and terminating worker threads consume performance. Therefore, you are advised to manage available workers and reuse them. The worker threads keep running even when they are idle. Therefore, when a worker thread is not required, call [terminate()](../reference/apis/js-apis-worker.md#terminate9) or [parentPort.close()](../reference/apis/js-apis-worker.md#close9) to terminate it. If a worker thread is terminated or being terminated, an error is thrown when it is called.


- A maximum of eight worker threads can co-exist.
  - In API version 8 and earlier versions, when the number of worker threads exceeds the limit, the error "Too many workers, the number of workers exceeds the maximum." is thrown.
  - Since API version 9, when the number of worker threads exceeds the limit, the error "Worker initialization failure, the number of workers exceeds the maximum." is thrown.
