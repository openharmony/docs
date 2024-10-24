# 高效并发编程

并发是指在同一时间段内，能够处理多个任务的能力。为了提升应用的响应速度与帧率，以及防止耗时任务对主线程的干扰，系统提供了异步并发和多线程并发两种处理策略。

异步并发是指异步代码在执行到一定程度后会被暂停，以便在未来某个时间点继续执行，这种情况下，同一时间只有一段代码在执行。

多线程并发允许在同一时间段内同时执行多段代码。在主线程继续响应用户操作和更新UI的同时，后台也能执行耗时操作，从而避免应用出现卡顿。

并发能力在多种场景中都有应用，其中包括单次I/O任务、CPU密集型任务、I/O密集型任务和同步任务等。开发者可以根据不同的场景，选择相应的并发策略进行优化和开发。

ArkTS支持异步并发和多线程并发。

- 使用异步并发能力进行开发
    - [异步并发概述](../arkts-utils/async-concurrency-overview.md)
    - [单次I/O任务开发指导](../arkts-utils/single-io-development.md)
- 使用多线程并发能力进行开发
    - [多线程并发概述](../arkts-utils/multi-thread-concurrency-overview.md)
    - [Actor并发模型对比内存共享并发模型](../arkts-utils/actor-model-development-samples.md)
    - [TaskPool和Worker的对比](../arkts-utils/taskpool-vs-worker.md)
    - [CPU密集型任务开发指导](../arkts-utils/cpu-intensive-task-development.md)
    - [I/O密集型任务开发指导](../arkts-utils/io-intensive-task-development.md)
    - [同步任务开发指导](../arkts-utils/sync-task-development.md)
