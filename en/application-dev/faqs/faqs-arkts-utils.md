# ArkTS Common Library Development


## Is memory isolation available between TaskPool, Worker, and ArkTS engine instances?

**TaskPool** and **Worker** implement concurrency based on the actor model, which features memory isolation. As such, memory isolation is implemented between **TaskPool**, **Worker**, and ArkTS engine instances.


## When will a TaskPool thread be destroyed in the TaskPool lifecycle?

You do not need to manually manage the lifecycle of a task pool. If no task is executed for a certain period of time or no listening task is executed on the **TaskPool** thread, the thread may be destroyed.


## Does TaskPool have restrictions on the task duration?

The maximum task duration is 3 minutes (excluding the time used for Promise or async/await asynchronous call).


## Which is recommended for scenarios with a large number of preloading tasks?

A maximum of eight worker threads can co-exist. As such, **TaskPool** is recommended in this case. For details about the implementation features and use cases of **TaskPool** and **Worker**, see [Comparison Between Worker and TaskPool](../arkts-utils/taskpool-vs-worker.md).


## Which is recommended in concurrent scenarios where threads need to be reused?

A worker cannot execute different tasks. As such, **TaskPool** is recommended in this case.
