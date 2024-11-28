# Concurrent Resident Task Scenarios

During application service implementation, for some resident task scenarios that take a long time (more than 3 minutes) and have a small number of concurrent tasks, use **Worker** to run the time-consuming logic in the background thread, so as not to block the main thread or cause frame loss and lag that affect user experience.

A resident task refers to a task that takes a longer time than a transient task. The lifecycle of a resident task may be the same as that of the UI main thread. Compared with long-term tasks, resident tasks tend to be bound to threads and run for a longer time (for example, more than 3 minutes).

Common service scenarios of resident tasks are as follows:

| Common Service Scenario| Description|
| -------- | -------- |
| Game platform scenario| Enables the child thread as the main logic thread of the game service. The UI thread is only responsible for rendering.|
| Time-consuming task scenario| Long-time model prediction tasks or hardware tests in the background|
