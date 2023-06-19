# Using Worker for Inter-Thread Communication


[Worker](../reference/apis/js-apis-worker.md) is an independent thread running in parallel with the main thread. The thread that creates the worker thread is referred to as the host thread. The script file passed in during worker creation is executed in the worker thread. Generally, time-consuming operations are processed in the worker thread. However, pages cannot be directly updated in the worker thread.


To develop the Worker mode, perform the following steps:


1. Configure the **buildOption** field in the [module-level build-profile.json5](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-building-configuration-0000001218440654#section6887184182020) file of the project.

   ```ts
   "buildOption": {
     "sourceOption": {
       "workers": [
         "./src/main/ets/workers/worker.ts"
       ]
     }
   }
   ```

2. Create the **worker.ts** file based on the configuration in **build-profile.json5**.

   ```ts
   import worker from '@ohos.worker';

   let parent = worker.workerPort;

   // Process messages from the main thread.
   parent.onmessage = function(message) {
     console.info("onmessage: " + message)
     // Send a message to the main thread.
     parent.postMessage("message from worker thread.")
   }
   ```

3. In the main thread, use the following method to initialize and use the worker thread.
   - Stage model:

      ```ts
      import worker from '@ohos.worker';

      let wk = new worker.ThreadWorker("entry/ets/workers/worker.ts");

      // Send a message to the worker thread.
      wk.postMessage("message from main thread.")

      // Process messages from the worker thread.
      wk.onmessage = function(message) {
        console.info("message from worker: " + message)

        // Stop the worker thread based on service requirements.
        wk.terminate();
      }
      ```

   - FA model:

      ```ts
      import worker from '@ohos.worker';
      
      let wk = new worker.ThreadWorker("../workers/worker.ts");
      
      // Send a message to the worker thread.
      wk.postMessage("message from main thread.")
      
      // Process messages from the worker thread.
      wk.onmessage = function(message) {
        console.info("message from worker: " + message)
      
        // Stop the worker thread based on service requirements.
        wk.terminate();
      }
      ```

> **NOTE**
>
> - If the relative path of **worker.ts** configured in **build-profile.json5** is **./src/main/ets/workers/worker.ts**, pass in the path **entry/ets/workers/worker.ts** when creating a worker thread in the stage model, and pass in the path **../workers/worker.ts** when creating a worker thread in the FA model.
> - For details about the data types supported between the main thread and worker thread, see [Sequenceable Data Types](../reference/apis/js-apis-worker.md#sequenceable-data-types).
