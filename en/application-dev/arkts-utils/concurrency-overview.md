# Concurrency Overview

Concurrency refers to the capability of processing multiple tasks in the same period. To improve the response speed and frame rate of applications and prevent time-consuming tasks from blocking the main thread, OpenHarmony provides two policies: asynchronous concurrency and multithread concurrency.

- Asynchronous concurrency means that an action in asynchronous code is suspended and will continue later. Only one segment of code is being executed at a time.

- Multithread concurrency allows multiple segments of code to be executed at a time. When the main thread continues to respond to user operations and update the UI, time-consuming operations are performed in the background to avoid application freezing.

Concurrency is used in a variety of scenarios, including a single I/O task, CPU intensive task, I/O intensive task, synchronous task, and the like. You can select a concurrency policy based on your scenario.

ArkTS provides the following mechanisms to support asynchronous concurrency and multithread concurrency:

- Promise and async/await: provide asynchronous concurrency and apply to the development of a single I/O task. For details, see [Asynchronous Concurrency Overview](async-concurrency-overview.md).

- **TaskPool** and **Worker**: provide multithread concurrency and apply to the development of CPU intensive tasks, I/O intensive tasks, and synchronous tasks. For details, see [Multithread Concurrency Overview](multi-thread-concurrency-overview.md).
