# Overview of Concurrency in Continuous Tasks

During the implementation of application service logic, tasks that require extended and irregular execution periods are known as continuous tasks. Executing these continuous tasks in the UI main thread may block the UI operations of the main thread, leading to issues such as lag and frame drops, which negatively impact user experience. Therefore, it is common practice to run these independent continuous tasks in separate child threads.

The following describes typical service scenarios for continuous tasks.


| Service Scenario| Description| 
| -------- | -------- |
| Periodic sensor data collection| Regularly collecting data of sensors (such as location and speed) that run continuously throughout the application's operation without interruption.| 
| Listening for socket port information| Continuously monitoring socket data and responding to it at irregular intervals.| 

These service scenarios are all independent continuous tasks with long execution cycles and simple external interactions. After being dispatched to background threads, these tasks need to respond periodically to obtain results. Using TaskPool can simplify development efforts for these types of tasks, avoiding the need to manage complex lifecycles and preventing thread proliferation. You simply need to place these independent continuous tasks into the TaskPool queue and then wait for the results.
