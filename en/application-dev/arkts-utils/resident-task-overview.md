# Overview of Concurrency in Resident Tasks
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

In application service development, time-consuming tasks (those lasting over 3 minutes) with low concurrency are best handled in background threads using Worker. This approach prevents such tasks from blocking the UI main thread, which could otherwise lead to performance issues such as frame loss and freezing, ultimately degrading user experience.

Persistent tasks are those that last significantly longer than transient tasks and may share the same lifecycle as the UI main thread. Unlike continuous tasks, persistent tasks are more tightly bound to their threads and typically have longer single-run durations (for example, over 3 minutes).

The following describes typical service scenarios for resident tasks.

| Service Scenario| Description|
| -------- | -------- |
| Game platform scenario| A child thread is launched to serve as the main logic thread for gaming services, whereas the UI thread is only responsible for rendering.|
| Long-duration task scenario| Tasks that require extended periods of time in the background, such as model predictions or hardware testing.|
