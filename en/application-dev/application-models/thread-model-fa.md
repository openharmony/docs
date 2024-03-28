# Thread Model (FA Model)


There are three types of threads in the FA model:


- Main thread

  Manages other threads.

- Ability thread
  - One ability thread for each ability.
  - Distributes input events.
  - Draws the UI.
  - Invokes application code callbacks (event processing and lifecycle callbacks).
  - Receives messages sent by the worker thread.

- Worker thread

  Performs time-consuming operations.

Based on the thread model, different services run on different threads. Service interaction requires inter-thread communication. Threads can communicate with each other in [Emitter](../basic-services/common-event/itc-with-emitter.md) or [Worker](../arkts-utils/worker-introduction.md) mode. Emitter is mainly used for event synchronization between threads, and Worker is mainly used to execute time-consuming tasks.

> **NOTE**
>
> The FA model provides an independent thread for each ability. Emitter is mainly used for event synchronization within the ability thread, between a pair of ability threads, or between the ability thread and worker thread.
