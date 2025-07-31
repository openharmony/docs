# 并发概述

并发指在同一时间内，多个任务同时执行。在多核设备上，任务可以在不同CPU上并行执行。对于单核设备，尽管多个任务不会同时并行，但CPU会在某个任务休眠或进行I/O操作时切换任务，调度其他任务，提高CPU的资源利用率。

为了提升应用的响应速度和帧率，避免耗时任务影响UI主线程，ArkTS提供了异步并发和多线程并发两种处理策略。

- 异步并发是指异步代码在执行到一定程度后暂停，并在未来某个时间点继续执行，同一时间只有一段代码执行。ArkTS通过Promise和async/await提供异步并发能力，适用于单次I/O任务。详细请参见[使用异步并发能力](async-concurrency-overview.md)。

- 多线程并发允许同时执行多段代码。UI主线程继续响应用户操作和更新UI，后台线程执行耗时操作，避免应用卡顿。ArkTS通过TaskPool和Worker提供多线程并发能力，适用于[耗时任务](time-consuming-task-overview.md)等并发场景。详细请参见[多线程并发概述](multi-thread-concurrency-overview.md)。


在并发多线程场景下，不同线程间需要进行数据通信。不同类别的对象采用不同的传输方式，如拷贝或内存共享。

并发能力广泛应用于多种场景，包括[异步并发任务](async-concurrency-overview.md)、[耗时任务](time-consuming-task-overview.md)（如[CPU密集型任务](cpu-intensive-task-development.md)、[I/O密集型任务](io-intensive-task-development.md)和[同步任务](sync-task-development.md)等）、[长时任务](long-time-task-overview.md)、[常驻任务](resident-task-overview.md)等。开发者可以根据不同的任务诉求和场景，选择相应的并发策略进行优化和开发，具体案例可以参见[应用多线程开发实践案例](batch-database-operations-guide.md)。