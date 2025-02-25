# Overview of Concurrency

Concurrency refers to the situation where multiple tasks are executed at the same time. On multi-core devices, these tasks can run in parallel across different CPUs. On single-core devices, while multiple tasks cannot run in parallel at the exact same moment, the CPU can switch between tasks when one is idle or performing I/O operations, thereby optimizing CPU resource utilization.

To improve the response speed and frame rate of applications and mitigate the impact of time-consuming tasks on the UI main thread, ArkTS provides two concurrency strategies: asynchronous concurrency and multithreaded concurrency.

- Asynchronous concurrency involves pausing asynchronous code at a certain point and resuming its execution later, ensuring that only one piece of code is running at any given moment. ArkTS supports asynchronous concurrency through Promises and async/await, which are well-suited for scenarios involving single I/O operations. For details, see [Asynchronous Concurrency](async-concurrency-overview.md).

- Multithreaded concurrency allows multiple segments of code to run simultaneously. While the UI main thread continues to handle user interactions and update the UI, background threads can perform time-consuming operations, thereby preventing application lag. ArkTS supports multithreaded concurrency through TaskPool and Worker, which are ideal for scenarios involving [time-consuming tasks](time-consuming-task-overview.md). For details, see [Multithreaded Concurrency](multi-thread-concurrency-overview.md).


In multithreaded concurrency scenarios, data communication between different threads is necessary, and the transfer methods for different types of objects can vary, including copy or memory sharing. 

Concurrency capabilities are used in various scenarios, including [asynchronous tasks](async-concurrency-overview.md), [time-consuming tasks](time-consuming-task-overview.md) ([CPU intensive tasks](cpu-intensive-task-development.md), [I/O intensive tasks](io-intensive-task-development.md), and [synchronous tasks](sync-task-development.md)), [continuous tasks](long-time-task-overview.md), and [resident tasks](resident-task-overview.md). You can select the appropriate concurrency strategy based on the specific task requirements and scenarios for optimization and development. You can also refer to [Multithreaded Development Practice Cases](batch-database-operations-guide.md).
