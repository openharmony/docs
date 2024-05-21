# Concurrency Overview

Concurrency refers to the capability of processing multiple tasks in the same period. To improve the response speed and frame rate of applications and prevent time-consuming tasks from blocking the main thread, two policies are provided: asynchronous concurrency and multithreaded concurrency.

- Asynchronous concurrency means that an action in asynchronous code is suspended and will continue later. Only one segment of code is being executed at a time.

- Multithreaded concurrency allows multiple segments of code to be executed at a time. When the main thread responds to user operations and updates the UI, time-consuming operations are performed in the background, avoiding application freezing.

Concurrency is used in a variety of scenarios, including a [single I/O task](single-io-development.md), [CPU intensive task](cpu-intensive-task-development.md), [I/O intensive task](io-intensive-task-development.md), and [synchronous task](sync-task-development.md). You can select a concurrency policy based on your scenario.

ArkTS provides the following mechanisms to support asynchronous concurrency and multithreaded concurrency:

- Promise and async/await: implement asynchronous concurrency and apply to the development of a single I/O task. For details, see [Asynchronous Concurrency Overview](async-concurrency-overview.md).

- TaskPool and Worker: implement multithreaded concurrency and apply to the development of CPU intensive tasks, I/O intensive tasks, and synchronous tasks. For details, see [Multithreaded Concurrency Overview](multi-thread-concurrency-overview.md).
