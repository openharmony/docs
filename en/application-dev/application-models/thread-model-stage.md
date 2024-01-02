# Thread Model Overview (Stage Model)

There are three types of threads in the stage model:
- Main thread
  - Draws the UI.
  - Manages the ArkTS engine instance of the main thread so that multiple UIAbility components can run on it.
  - Manages ArkTS engine instances of other threads, for example, using **TaskPool** to create or cancel tasks, and starting and terminating **Worker** threads.
  - Distributes interaction events.
  - Processes application code callbacks (event processing and lifecycle management).
  - Receives messages sent by the **TaskPool** and **Worker** threads.
- [TaskPool Worker Thread](../reference/apis/js-apis-taskpool.md)

  Used for time-consuming operations and provides APIs for setting the scheduling priority and load balancing. It is recommended.
- [Worker Thread](../reference/apis/js-apis-worker.md)

  Used for time-consuming operations and supports inter-thread communication.
For details about the operation mechanism, communication method, and usage of **TaskPool** and **Worker**, see [Comparison Between TaskPool and Worker](../arkts-utils/taskpool-vs-worker.md).

![thread-model-stage](figures/thread-model-stage.png)

> **NOTE**
>
> - **TaskPool** manages the number of threads that can be created and their lifecycle. A maximum of eight **Worker** threads can be created, and you need to manage their lifecycle.
> - Multiple components can exist in the same thread. For example, both UIAbility and UI components exist in the main thread. In the stage model, [EventHub](itc-with-eventHub.md) is used for data communication.
> - To view thread information about an application process, run the **hdc shell** command to enter the shell CLI of the device, and then run the **ps -p *\<pid>* -T command**, where *\<pid>* indicates the [process ID](process-model-stage.md) of the application.
