# Concurrent Continuous Task Scenarios

During the implementation of application services, tasks that need to run for a long time and irregularly are called long-term tasks. If a long-duration task is executed in the UI main thread, the UI service of the UI main thread is blocked, and problems such as frame freezing and frame loss occur, affecting user experience. You can execute the independent continuous task in an independent child thread.

Typical scenarios of continuous tasks are as follows.


| Common Service Scenario| Description| 
| -------- | -------- |
| Periodically collects sensor data.| Periodically collects sensor information (such as location information and speed sensor information), and runs continuously for a long time during application running.| 
| Listening to Socket Port Information| Listens for socket data for a long time and responds irregularly.| 

The preceding table lists independent continuous tasks with long task execution period and simple interaction with external systems. After these tasks are distributed to the background thread, you need to respond irregularly to obtain results. Therefore, using **TaskPool** can reduce development workload, and avoid complex lifecycle management and too many threads. You only need to place the preceding independent continuous tasks in the **TaskPool** queue and wait for the result.
