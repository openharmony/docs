# Efficient Concurrent Programming

Concurrency refers to the capability of processing multiple tasks in the same period. To improve the response speed and frame rate of applications and prevent time-consuming tasks from blocking the main thread, the system provides two policies: asynchronous concurrency and multithread concurrency.

Asynchronous concurrency means that an action in asynchronous code is suspended and will continue later. Only one segment of code is being executed at a time.

Multithread concurrency allows multiple segments of code to be executed at a time. When the main thread continues to respond to user operations and update the UI, time-consuming operations are performed in the background to avoid application freezing.

Concurrency is used in a variety of scenarios, including a single I/O task, CPU intensive task, I/O intensive task, synchronous task, and the like. You can select a concurrency policy based on your scenario.

ArkTS provides the following mechanisms to support asynchronous concurrency and multithread concurrency:

- Using asynchronous concurrency for development
    - [Asynchronous Concurrency Overview](../arkts-utils/async-concurrency-overview.md)
    - [Single I/O Task Development](../arkts-utils/single-io-development.md)
- Using multithread concurrency for development
    - [Multithread Concurrency Overview](../arkts-utils/multi-thread-concurrency-overview.md)
    - [Comparison Between the Actor and Memory Sharing Models](../arkts-utils/actor-model-development-samples.md)
    - [Comparison Between TaskPool and Worker](../arkts-utils/taskpool-vs-worker.md)
    - [CPU Intensive Task Development](../arkts-utils/cpu-intensive-task-development.md)
    - [I/O Intensive Task Development](../arkts-utils/io-intensive-task-development.md)
    - [Synchronous Task Development](../arkts-utils/sync-task-development.md)
