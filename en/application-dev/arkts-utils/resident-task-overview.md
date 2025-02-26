# Overview of Concurrency in Resident Tasks

During the development of application services, certain tasks that are time-consuming (lasting longer than 3 minutes) and have low concurrency are best handled by running them in background threads using Worker. This approach prevents these tasks from blocking the UI main thread, which could otherwise lead to performance issues such as frame loss and freezing, ultimately degrading user experience.

Persistent tasks are those that last significantly longer than transient tasks and may share the same lifecycle as the UI main thread. Unlike continuous tasks, persistent tasks are more tightly bound to their threads and typically have longer single-run durations (for example, over 3 minutes).

The following describes typical service scenarios for resident tasks.

| Service Scenario| Description|
| -------- | -------- |
| Game platform scenario| A child thread is launched to serve as the main logic thread for gaming services, whereas the UI thread is only responsible for rendering.|
| Long-duration task scenario| Tasks that require extended periods of time in the background, such as model predictions or hardware testing.|
