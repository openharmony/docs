# Glossary

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung-->
<!--Designer: @zhanglu161-->
<!--Tester: @lotsof-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=109b87675eac01414d50f334b6b9f35783816b39 translatedAt=2026-08-03T08:18:15.457Z pushedAt=2026-08-03T10:56:14.611Z -->

## C

### Concurrent Queue

A task queue in FFRT that allows multiple tasks to execute simultaneously, supporting task priority and queue concurrency settings. By constraining the maximum concurrency, it controls the number of tasks executing at the same time, preventing excessive task concurrency from impacting system resources. It is used in scenarios involving parallel computing and efficient utilization of multi-core processors. In contrast to serial queues, tasks in a concurrent queue are assigned by the scheduler to multiple worker threads for parallel execution based on priority.

## D

### Data Dependency

A dependency relationship expressed between tasks through the producer-consumer relationship of data in FFRT graph-based concurrency, also known as data flow. When a data identifier appears in a task's input dependency, the task is a consumer task; when it appears in the output dependency, the task is a producer task. At runtime, three types of dependency relationships — producer-consumer, consumer-producer, and producer-producer — are dynamically constructed based on the order of task submission, and tasks are scheduled accordingly. This is applicable to scenarios where task execution is triggered by data production and consumption relationships, as opposed to the task dependency approach where task handles are directly specified.

## F

### Function Flow Runtime (FFRT)

A task- and data-driven concurrent programming framework that adopts a task-based scheduling model. It enables developers to focus on tasks and their dependencies without managing underlying threads or computing resources. FFRT is designed to simplify concurrent programming and task scheduling while addressing the overuse of system thread resources.

### Fiber

A lightweight user-mode thread mechanism provided by FFRT, designed for efficient context switching in user space. As a fiber storage entity type, it saves and restores execution contexts without managing any memory; the lifecycle of the stack is managed by the caller. Developers can manually create, initialize, and switch fibers through APIs such as **ffrt_fiber_init** and **ffrt_fiber_switch**, making it suitable for advanced application scenarios that require fine-grained execution flow control and coroutine simulation.

## I

### Input Dependency

Part of the FFRT task dependency mechanism that specifies the dependencies that must be resolved before a task can execute. Input dependencies are typically expressed using data addresses or task handles. An input dependency specified by a data address indicates that the task consumes the corresponding data, whereas an input dependency specified by a task handle indicates that the task must wait for the preceding task referenced by the handle to complete. A task is not scheduled until all its input dependencies are satisfied, ensuring that the required data or preceding tasks are ready before execution begins. Input dependencies are specified through the **in_deps** parameter when submitting a task to FFRT.

## J

### Job Partner

A concurrency paradigm in FFRT that designates the original thread as the master thread and supports dynamic management of partner threads for cross-thread collaborative execution. It is designed for scenarios where specific code segments must run on a designated thread and tasks are fine-grained but numerous. By dynamically combining fine-grained tasks, it amortizes scheduling overhead, reducing the cost of cross-thread collaboration and thread wake-ups. It is suitable for batch scheduling of microsecond-level tasks.

## O

### Output Dependency

Part of the FFRT task dependency mechanism that specifies the dependencies resolved when a task completes. Output dependencies are typically expressed using data addresses or task handles. An output dependency specified by a data address indicates that the task produces or modifies the corresponding data. When the task completes, its output dependencies are resolved, allowing subsequent tasks that depend on the outputs to be scheduled. The same data address cannot be used simultaneously as an input dependency of one task and an output dependency of another task. Output dependencies are used to express data modification relationships and write-after-read (WAR) and write-after-write (WAW) dependencies. They are specified through the **out_deps** parameter when submitting a task to FFRT.

## S

### Serial Queue

A task queue in FFRT that ensures tasks are executed in strict serial order based on their submission sequence. Tasks within the same queue are arranged in ascending order of uptime (the submission time plus the delay time). Functionally equivalent to a single thread, it is implemented based on a coroutine scheduling model and is suitable for scenarios that require maintaining a specific execution order, ensuring data safety, coordinating tasks, and simplifying development. Tasks in the queue execute asynchronously with respect to the user thread.

## T

### Task

The fundamental programming abstraction for developers and the execution unit for the FFRT runtime. A task consists of a sequence of instructions and the data context on which they operate, and serves as the basic scheduling unit in FFRT. Tasks support explicitly defined dependencies as well as data-driven dependencies, can be nested to form parent-child relationships, and support synchronization primitives such as waiting, locks, and condition variables. The recommended minimum task granularity is approximately 100 microseconds. Finer-grained tasks increase scheduling overhead, whereas coarser-grained tasks reduce parallelism.

### Task Dependency

A dependency relationship explicitly defined between tasks in FFRT using task handles. It determines whether a task must wait for other tasks to complete before it can begin execution. A task handle appearing in an input dependency represents a predecessor task, whereas one appearing in an output dependency represents a successor task. Task dependencies are used to define execution order for tasks with explicit sequencing or workflow requirements, as opposed to data dependencies, which are expressed through data production and consumption relationships.

## W

### Worker

A worker thread in FFRT that executes tasks. Each worker can execute multiple tasks, with task assignment and lifecycle managed by the scheduler according to the configured QoS level. Unlike ordinary threads, workers are managed entirely by the FFRT runtime. Developers cannot create or destroy workers directly, which helps prevent the overuse of thread resources.