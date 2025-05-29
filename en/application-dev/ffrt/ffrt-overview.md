# Introduction to Function Flow Runtime Kit

## Introduction

Function Flow Runtime (FFRT) is a concurrent programming framework designed to simplify concurrent programming and task scheduling. You only need to pay attention to tasks and their dependencies in task scheduling without processing underlying threads and computing resources. In addition, FFRT leverages coroutine-based task execution to enhance task parallelism, improve thread utilization, and fully utilizes the computing resources of the multi-core platform to ensure centralized management and optimized scheduling of all system resources.

## Basic Concepts

The following describes the basic concepts in FFRT development:

- **Task**: a combination of programming clues and runtime execution objects. It usually includes a group of instruction sequences and their operation data context.
- **Task dependency**: dependency among tasks. It determines whether a task can be executed only after other tasks are complete, and allows you to define the execution sequence of complex tasks.
- **Quality of Service (QoS)**: quality of service of a task. It is used to indicate task priority and resource allocation.
- **Primitive**: a basic operation or construction used to implement synchronization and mutual exclusion. For example, a mutex or a condition variable.
- **Worker**: a worker thread that executes a task. Each worker can execute multiple tasks. Generally, the scheduler is responsible for managing and allocating tasks.
- **Scheduling**: a process that determines when and which worker executes a task. The scheduler schedules tasks based on factors such as task dependencies and QoS levels.

### Programming Models

|                | Thread Programming Model                                                                      | Task Programming Model                                                                                                                |
| -------------- | ---------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------- |
| Degree of Parallelism (DOP) mining mode| Programmers create multiple threads and assign tasks to them for parallel execution to achieve the optimal runtime performance.            | Programmers, with the help of compilers or programming language features, decompose the application into tasks and describe their data dependencies during static programming. The scheduler allocates tasks to worker threads for execution.          |
| Owner for creating threads| Programmers are responsible for creating threads. The maximum number of threads that can be created is not under control.  | The scheduler is responsible for creating and managing worker threads. Programmers cannot directly create threads.                                                  |
| Load balancing      | Programmers map tasks to threads during static programming. Improper mapping or uncertain task execution time will cause a load imbalance among threads.| A ready task is automatically scheduled to an idle thread for execution, reducing the load imbalance among threads.                                              |
| Scheduling overhead      | Thread scheduling is implemented by a kernel-mode scheduler, resulting in high scheduling overhead.                                          | Thread scheduling is implemented by a user-mode coroutine scheduler, requiring less scheduling overhead. In addition, FFRT can further reduce the scheduling overhead through hardware-based scheduling offload.|
| Dependency expression      | A thread is in the executable state once it is created, and it is executed parallelly with other threads, causing frequent thread switching.              | FFRT determines whether a task can be executed based on the input and output dependencies explicitly expressed during task creation. If the input dependencies do not meet the requirements, the task is not scheduled.          |

### FFRT Programming Model

The FFRT programming model allows you to develop applications by describing tasks and their dependencies. Its main features include `Task-Based`, `Queue-Enabled`, and `Graph-Driven`.

#### Task-Based

The `Task-Based` feature means that you can use tasks to express an application and schedule the tasks at runtime.

The tasks in the FFRT programming model have the following features:

- Task dependencies can be directly specified, or expressed using data objects.
- Tasks can be nested. That is, when a task is being executed, a new task can be generated and delivered to that task to form a parent-child relationship.
- Simultaneous operations, such as wait, lock, and condition variables, are supported.

> **NOTE**
>
> The task granularity determines the number of concurrent tasks and therefore affects the application execution performance. A small granularity increases the scheduling overhead, whereas a large granularity decreases the DOP. The minimum task granularity allowed in the FFRT programming model is 100 μs.

#### Queue-Enabled

The `Queue-Enabled` feature means that you can use task queues to restrict task execution sequence and concurrency at runtime. Task queues include serial queues and concurrent queues, which are used in different scenarios.

- The serial queue ensures that tasks are executed in sequence according to the submission sequence. It is applicable to the task flow that maintains a specific execution sequence.
- The concurrent queue allows multiple tasks to be executed at the same time, improving concurrency performance. It is applicable to parallel computing and efficient use of multi-core processors.
- The concurrent queue can also restrict the overall concurrency of a task unit to ensure that system resources are properly allocated and avoid performance bottlenecks or system instability caused by excessive concurrency.

The `Queue-Enabled` feature provides you with flexible task scheduling modes. You can select a proper task execution policy based on your requirements to optimize the performance of your applications.

#### Graph-Driven

The `Graph-Driven` feature means that you can use dependency graphs to manage task dependencies and implement efficient scheduling of complex task flows.

The FFRT programming model supports two methods to build task dependency graphs:

- **Task dependency**: Task dependencies are directly described.
- **Data flow**: Task dependencies are described based on the relationship between data producers and consumers.

You can select a proper method described above based on service characteristics to simplify service models and development.
