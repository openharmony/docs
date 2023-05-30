# Thread Model Overview (Stage Model)

For an OpenHarmony application, each process has a main thread to provide the following functionalities:

- Draw the UI.
- Manage the ArkTS engine instance of the main thread so that multiple UIAbility components can run on it.
- Manage ArkTS engine instances of other threads (such as the worker thread), for example, starting and terminating other threads.
- Distribute interaction events.
- Process application code callbacks (event processing and lifecycle management).
- Receive messages sent by the worker thread.

In addition to the main thread, there is an independent thread, named worker. The worker thread is mainly used to perform time-consuming operations. The worker thread is created in the main thread and is independent from the main thread. It cannot directly operate the UI. A maximum of seven worker threads can be created. 

![thread-model-stage](figures/thread-model-stage.png)

Based on the OpenHarmony thread model, different services run on different threads. Service interaction requires inter-thread communication. In the same process, threads can communicate with each other in Emitter or Worker mode. Emitter is mainly used for event synchronization between threads, and Worker is mainly used to execute time-consuming tasks.

> **NOTE**
> 
> - The stage model provides only the main thread and worker thread. Emitter is mainly used for event synchronization within the worker thread or between the main thread and worker thread.
> - The UIAbility and UI are in the main thread. For details about data synchronization between them, see [Data Synchronization Between UIAbility and UI](uiability-data-sync-with-ui.md).
> - To view thread information about an application process, run the **hdc shell** command to enter the shell CLI of the device, and then run the **ps -p *<pid>* -T command**, where *<pid>* indicates the [process ID](process-model-stage.md) of the application.
