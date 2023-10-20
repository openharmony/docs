# 并发概述

并发是指在同一时间段内，能够处理多个任务的能力。为了提升应用的响应速度与帧率，以及防止耗时任务对主线程的干扰，OpenHarmony系统提供了异步并发和多线程并发两种处理策略。

- 异步并发是指异步代码在执行到一定程度后会被暂停，以便在未来某个时间点继续执行，这种情况下，同一时间只有一段代码在执行。

- 多线程并发允许在同一时间段内同时执行多段代码。在主线程继续响应用户操作和更新UI的同时，后台也能执行耗时操作，从而避免应用出现卡顿。

并发能力在多种场景中都有应用，其中包括[单次I/O任务](single-io-development.md)、[CPU密集型任务](cpu-intensive-task-development.md)、[I/O密集型任务](io-intensive-task-development.md)和[同步任务](sync-task-development.md)等。开发者可以根据不同的场景，选择相应的并发策略进行优化和开发。

ArkTS支持异步并发和多线程并发。

- Promise和async/await提供异步并发能力，适用于单次I/O任务的开发场景。详细请参见[异步并发概述](async-concurrency-overview.md)。

- TaskPool和Worker提供多线程并发能力，适用于CPU密集型任务、I/O密集型任务和同步任务等并发场景。详细请参见[多线程并发概述](multi-thread-concurrency-overview.md)。
