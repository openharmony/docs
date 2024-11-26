# Resident Task Development (Worker)

This section describes how to use a worker to execute a resident task. The worker continuously executes the task until the host thread sends a termination instruction.

The development process and example are as follows:

1. DevEco Studio supports one-click Worker generation. Right-click any position in the {moduleName} directory and choose > New > Worker from the shortcut menu to automatically generate the Worker template file and configuration information. This section uses Worker as an example.

   In addition, you can manually create a worker file. For details, see [Precautions for Worker](worker-introduction.md#precautions-for-worker).

2. Import the Worker module.

   ```ts
   // Index.ets
   import { worker } from '@kit.ArkTS';
   ```

3. In the host thread, call [constructor()](../reference/apis-arkts/js-apis-worker.md#constructor9) of **ThreadWorker** to create a **Worker** object. The calling thread is the host thread.

   ```ts
   // Index.ets
   const workerInstance: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets');
   ```

4. The host thread is the UI main thread. The host thread sends'start' to execute a long-running task and receive related messages returned by the sub-thread. When the task does not need to be executed, send'stop' to stop the task. In this example, the task is stopped 10 seconds later.

   ```ts
   // Index.ets
   
   @Entry
   @Component
   struct Index {
     build() {
       Column() {
         Text("Listener task")
           .id('HelloWorld')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .onClick(() => {
             workerInstance.postMessage({type: 'start'})
             workerInstance.onmessage = (event) => {
               console.info ('The UI main thread receives a message:', event.data);
             }
             // Stop the worker after 10 seconds.
             setTimeout(() => {
               workerInstance.postMessage({ type: 'stop' });
             }, 10000);
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

5. When the Worker thread receives a start message from the host thread, the Worker thread starts to execute a task that runs irregularly for a long time and returns a message to the host thread in real time. When the received message is "stop," the task execution is ended and a corresponding message is returned to the host thread.

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   let isRunning = false;
   workerPort.onmessage = (e: MessageEvents) => {
     const type = e.data.type as string;
     if (type === 'start') {
       if (!isRunning) {
         isRunning = true;
         // Start a resident task.
         performTask();
       }
     } else if (type === 'stop') {
       isRunning = false;
       workerPort.close (); // Close the worker.
     }
   }
   // Simulate a resident task.
   function performTask() {
     if (isRunning) {
       // Simulate a long-term task.
       workerPort.postMessage('Worker is performing a task');
       // Execute the task again 1 second later.
       setTimeout(performTask, 1000);
     }
     workerPort.postMessage('Worker is stop performing a task');
   }
   ```
