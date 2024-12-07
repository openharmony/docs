# Comparison Between TaskPool and Worker


**TaskPool** and **Worker** provide a multithreaded environment for applications to process time-consuming computing tasks or resource intensive tasks, preventing these tasks from blocking the host thread. This maximizes system utilization, reduces overall resource consumption, and improves overall system performance.


 


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
| Maximum number of tasks| The number is automatically managed, rather than being manually configured.| A maximum of 64 worker threads can run simultaneously in the same process. The actual number is determined by the process memory.|
| Maximum task execution duration| 3 minutes (excluding the time used for Promise or async/await asynchronous call, for example, the time consumed by I/O tasks such as network download and file read/write). There is no upper limit on the execution duration of continuous tasks. | There is no restriction.|
| Task priority setting| Supported.| Not supported.|
| Task cancellation| Supported.| Not supported.|
| Thread reuse| Supported.| Not supported.|
| Delayed task execution| Supported.| Not supported.|
| Setting task dependencies| Supported.| Not supported.|
| Queue| Supported.| Not supported.|
| Task group| Supported.| Not supported.|


## Use Case Comparison

Both **TaskPool** and **Worker** support multithreaded concurrency. **TaskPool** worker threads are bound to the system scheduling priority and support load balancing (automatic scaling). **Worker** threads are manually created and do not support scheduling priority setting. Therefore, **TaskPool** provides better performance than **Worker** and is recommended in most scenarios.

**TaskPool** is oriented to independent tasks, which are executed in threads. You do not need to care about the thread lifecycle, because non-continuous tasks are automatically reclaimed by the system if they are running for more than 3 minutes. On the contrary, **Worker** is oriented to threads and supports thread execution for a long time. You need to manage the thread lifecycle.

Common use cases are as follows:

- Use **Worker** for a task that runs for more than 3 minutes (excluding the time used for Promise or async/await asynchronous call, for example, I/O tasks such as network download and file read/write). For example, use **Worker** for a 1-hour prediction algorithm training job in the background. For details about the scenario example, see [Resident Task Development](./resident-task-guide.md).

- Use **Worker** for a series of associated synchronous tasks. For example, in scenarios where handles are used, if different handles are created each time and they must be stored permanently for subsequent operation, use **Worker**. For details, see [Using Worker to Process Associated Synchronous Tasks](./sync-task-development.md#using-worker-to-process-associated-synchronous-tasks).

- Use **TaskPool** for a task for which the priority needs to be set. For example, in the histogram rendering scenario in Gallery, histogram data calculated in the background is used for UI display on the foreground. Therefore, histogram data calculation must be treated with high priority. In this case, use **TaskPool**.

- Use **TaskPool** for a task that is subject to cancellation at any time. For example, in the large image browsing scenario in Gallery, two images before and after the current image are cached. When the user swipes one side, the image cache task on the other side needs to be canceled. In this case, use **TaskPool**.

- Use **TaskPool** for a large number of tasks or tasks with scattered scheduling points. For example, a large application with multiple modules may have multiple time-consuming tasks, and it is inconvenient to use worker threads to manage load. In this case, **TaskPool** is recommended. For details about the scenario example, see [Batch Data Writing to the Database](./batch-database-operations-guide.md).
