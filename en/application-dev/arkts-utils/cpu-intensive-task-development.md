# CPU Intensive Task Development


CPU intensive tasks occupy lots of system computing resources for a long period of time, during which other events of the thread are blocked. Example CPU intensive tasks are image processing, video encoding, and data analysis.


OpenHarmony uses multithread concurrency to process CPU intensive tasks. This improves CPU utilization and application response speed.


**Worker** is recommended for a series of synchronous tasks. When there are independent tasks with a huge number or scattered scheduling points, it is inconvenient to use eight worker threads to manage load. In this case, **TaskPool** is recommended. The following uses histogram processing and a time-consuming model prediction task in the background as examples.


## Using TaskPool to Process Histograms

1. Implement the logic of image processing.

2. Segment the data, and use one task to process a data segment.

   Create a [task](../reference/apis/js-apis-taskpool.md#task), and call [execute()](../reference/apis/js-apis-taskpool.md#taskpoolexecute-1) to execute the task. After the task is complete, the histogram processing result is returned simultaneously.

3. Process the result.


```ts
import taskpool from '@ohos.taskpool';

@Concurrent
function imageProcessing(dataSlice: ArrayBuffer) {
  // Step 1: Perform specific image processing operations and other time-consuming operations.
  return dataSlice;
}

function histogramStatistic(pixelBuffer: ArrayBuffer) {
  // Step 2: Perform concurrent scheduling for data in three segments.
  let number = pixelBuffer.byteLength / 3;
  let buffer1 = pixelBuffer.slice(0, number);
  let buffer2 = pixelBuffer.slice(number, number * 2);
  let buffer3 = pixelBuffer.slice(number * 2);

  let task1 = new taskpool.Task(imageProcessing, buffer1);
  let task2 = new taskpool.Task(imageProcessing, buffer2);
  let task3 = new taskpool.Task(imageProcessing, buffer3);

  taskpool.execute(task1).then((ret: ArrayBuffer[]) => {
    // Step 3: Process the result.
  });
  taskpool.execute(task2).then((ret: ArrayBuffer[]) => {
    // Step 3: Process the result.
  });
  taskpool.execute(task3).then((ret: ArrayBuffer[]) => {
    // Step 3: Process the result.
  });
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            let data: ArrayBuffer;
            histogramStatistic(data);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```


## Using Worker for Time-Consuming Data Analysis

The following uses the training of a region-specific house price prediction model as an example. This model can be used to predict house prices in the region based on the house area and number of rooms. The model needs to run for a long time, and the prediction will use the previous running result. Due to these considerations, **Worker** is used for the development.

1. Add the worker creation template provided on DevEco Studio to your project, and name it **MyWorker**.

   ![newWorker](figures/newWorker.png)

2. In the main thread, call [ThreadWorker()](../reference/apis/js-apis-worker.md#threadworker9) to create a **Worker** object. The calling thread is the host thread.

   ```js
   import worker from '@ohos.worker';

   const workerInstance = new worker.ThreadWorker('entry/ets/workers/MyWorker.ts');
   ```

3. In the host thread, call [onmessage()](../reference/apis/js-apis-worker.md#onmessage9) to receive messages from the worker thread, and call [postMessage()](../reference/apis/js-apis-worker.md#postmessage9) to send messages to the worker thread.

   For example, the host thread sends training and prediction messages to the worker thread, and receives messages sent back by the worker thread.

   ```js
   // Receive the result of the worker thread.
   workerInstance.onmessage = function(e) {
     // data carries the information sent by the main thread.
     let data = e.data;
     console.info('MyWorker.ts onmessage');
     // Perform time-consuming operations in the worker thread.
   }

   workerInstance.onerror = function (d) {
     // Receive error information of the worker thread.
   }

   // Send a training message to the worker thread.
   workerInstance.postMessage({ 'type': 0 });
   // Send a prediction message to the worker thread.
   workerInstance.postMessage({ 'type': 1, 'value': [90, 5] });
   ```

4. Bind the **Worker** object in the **MyWorker.ts** file. The calling thread is the worker thread.

   ```js
   import worker, { ThreadWorkerGlobalScope, MessageEvents, ErrorEvent } from '@ohos.worker';
   
   let workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   ```

5. In the worker thread, call [onmessage()](../reference/apis/js-apis-worker.md#onmessage9-1) to receive messages sent by the host thread, and call [postMessage()](../reference/apis/js-apis-worker.md#postmessage9-2) to send messages to the host thread.

   For example, the prediction model and its training process are defined in the worker thread, and messages are exchanged with the main thread.

   ```js
   import worker, { ThreadWorkerGlobalScope, MessageEvents, ErrorEvent } from '@ohos.worker';

   let workerPort: ThreadWorkerGlobalScope = worker.workerPort;

   // Define the training model and result.
   let result;

   // Define the prediction function.
   function predict(x) {
     return result[x];
   }

   // Define the optimizer training process.
   function optimize() {
     result = {};
   }

   // onmessage logic of the worker thread.
   workerPort.onmessage = function (e: MessageEvents) {
     let data = e.data
     // Perform operations based on the type of data to transmit.
     switch (data.type) {
       case 0:
       // Perform training.
         optimize();
       // Send a training success message to the main thread after training is complete.
         workerPort.postMessage({ type: 'message', value: 'train success.' });
         break;
       case 1:
       // Execute the prediction.
         const output = predict(data.value);
       // Send the prediction result to the main thread.
         workerPort.postMessage({ type: 'predict', value: output });
         break;
       default:
         workerPort.postMessage({ type: 'message', value: 'send message is invalid' });
         break;
     }
   }
   ```

6. After the task is completed in the worker thread, destroy the worker thread. The worker thread can be destroyed by itself or the host thread. Then, call [onexit()](../reference/apis/js-apis-worker.md#onexit9) in the host thread to define the processing logic after the worker thread is destroyed.

      ```js
      // After the worker thread is destroyed, execute the onexit() callback.
      workerInstance.onexit = function() {
        console.info("main thread terminate");
      }
      ```

   In the host thread, call [terminate()](../reference/apis/js-apis-worker.md#terminate9) to destroy the worker thread and stop the worker thread from receiving messages.

   ```js
   // Destroy the worker thread.
   workerInstance.terminate();
   ```

   In the worker thread, call [close()](../reference/apis/js-apis-worker.md#close9) to destroy the worker thread and stop the worker thread from receiving messages.

   ```js
   // Destroy the worker thread.
   workerPort.close();
   ```