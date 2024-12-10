# Concurrency Overview

Concurrency refers to the situation where multiple tasks are executed at the same time. For a multi-core device, these tasks may be executed on different CPUs concurrently. For a single-core device, multiple concurrent tasks are not executed at the same time. However, the CPU switches tasks when a task is in the sleep state or is performing I/O operations, and schedules and executes other tasks to improve CPU resource utilization.

To improve the response speed and frame rate of applications and prevent time-consuming tasks from blocking the main thread, the system provides two policies: asynchronous concurrency and multithread concurrency.

- Asynchronous concurrency means that an action in asynchronous code is suspended and will resume later. Only one segment of code is executed at a time. Promise and async/await: implement asynchronous concurrency and apply to the development of a single I/O task. For details, see [Asynchronous Concurrency Overview](async-concurrency-overview.md).

- Multithreaded concurrency allows multiple segments of code to be executed at a time. When the main thread responds to user operations and updates the UI, time-consuming operations are performed in the background, avoiding application freezing. ArkTS uses TaskPool and Worker to provide the multi-thread concurrency capability, which is applicable to concurrency scenarios such as [time-consuming tasks](time-consuming-task-overview.md). For details, see [Multithreaded Concurrency Overview](multi-thread-concurrency-overview.md).


In a concurrent multi-thread scenario, data communication needs to be performed between different concurrent threads, and transmission modes of different types of objects are different, including copy or memory sharing.

The concurrency capability is used in multiple scenarios, including []asynchronous concurrent tasks (async-concurrency-overview.md) and [time-consuming tasks](time-consuming-task-overview.md) ([CPU-intensive tasks](cpu-intensive-task-development.md), [I/O-intensive tasks](io-intensive-task-development.md), [synchronization tasks](sync-task-development.md)), [continuous tasks](long-time-task-overview.md), and [resident tasks](resident-task-overview.md) You can select a concurrency policy for optimization and development based on different task requirements and scenarios. For details, see [Multithreaded Development Practice Cases](batch-database-operations-guide.md).
