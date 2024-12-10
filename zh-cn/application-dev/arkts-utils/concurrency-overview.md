# 并发概述

并发是指在同一时间内，存在多个任务同时执行的情况。对于多核设备，这些任务可能同时在不同CPU上并行执行。对于单核设备，多个并发任务不会在同一时刻并行执行，但是CPU会在某个任务休眠或进行I/O操作等状态下切换任务，调度执行其他任务，提升CPU的资源利用率。

为了提升应用的响应速度与帧率，避免耗时任务对UI主线程的影响，ArkTS提供了异步并发和多线程并发两种处理策略。

- 异步并发是指异步代码在执行到一定程度后会被暂停，以便在未来某个时间点继续执行，这种情况下，同一时间只有一段代码在执行。ArkTS通过Promise和async/await提供异步并发能力，适用于单次I/O任务的开发场景。详细请参见[使用异步并发能力](async-concurrency-overview.md)。

- 多线程并发允许在同一时间段内同时执行多段代码。在UI主线程继续响应用户操作和更新UI的同时，后台线程也能执行耗时操作，从而避免应用出现卡顿。ArkTS通过TaskPool和Worker提供多线程并发能力，适用于[耗时任务](time-consuming-task-overview.md)等并发场景。详细请参见[多线程并发概述](multi-thread-concurrency-overview.md)。


并发多线程场景下，不同并发线程间需要进行数据通信，不同类别对象的传输方式存在差异，包括拷贝或内存共享等。

并发能力在多种场景中都有应用，其中包括[异步并发任务](async-concurrency-overview.md)、[耗时任务](time-consuming-task-overview.md)（[CPU密集型任务](cpu-intensive-task-development.md)、[I/O密集型任务](io-intensive-task-development.md)和[同步任务](sync-task-development.md)等）、[长时任务](long-time-task-overview.md)、[常驻任务](resident-task-overview.md)等。开发者可以根据不同的任务诉求和场景，选择相应的并发策略进行优化和开发，也可以具体查看[应用多线程开发实践案例](batch-database-operations-guide.md)。
