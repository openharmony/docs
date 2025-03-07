# Overview of Multithreaded Development

During ArkTS application development, the concurrency capability is required in many service scenarios. Different service scenarios demand different types of concurrency and corresponding task types.

For common service scenarios, there are mainly three types of concurrent tasks:

- [Time-consuming tasks](time-consuming-task-overview.md): These involve significant computation or multiple I/O operations and take a long time to execute.
- [Continuous tasks](long-time-task-overview.md): These include tasks like listening or periodically collecting data that need to run continuously over extended periods.

- [Resident tasks](resident-task-overview.md): These are bound to the lifecycle of the main thread or closely integrated with it.


Each task type can be further divided. For example, time-consuming tasks can be CPU intensive, I/O intensive, or synchronous, each corresponding to different service scenarios. You should select the appropriate concurrency capabilities based on the specific scenario and task type.

In the following sections, we will explore some case studies for common scenarios encountered during multithreaded application development.
