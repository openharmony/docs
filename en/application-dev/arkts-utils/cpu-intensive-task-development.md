# CPU Intensive Task Development (TaskPool and Worker)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->


CPU intensive tasks are those that require significant computational resources and can run for extended periods. If executed in the UI main thread, these tasks can block other events. Examples include image processing, video encoding, and data analysis.


To improve CPU utilization and enhance application responsiveness, you can use multithreaded concurrency in processing CPU intensive tasks.


When tasks are discrete and do not need to occupy a background thread for an extended period (3 minutes), TaskPool is recommended. For tasks that require long-running background processing, Worker is more suitable.

The following examples illustrate how to handle image histogram processing using TaskPool and long-running model prediction tasks using Worker.


## Using TaskPool for Image Histogram Processing

1. Implement the logic of image processing.

2. Segment the data, and schedule related tasks using a task group.
   Create a [task group](../reference/apis-arkts/js-apis-taskpool.md#taskgroup10), call [addTask()](../reference/apis-arkts/js-apis-taskpool.md#addtask10) to add tasks, and call [execute()](../reference/apis-arkts/js-apis-taskpool.md#taskpoolexecute10) to execute the tasks in the task group, specifying [high priority](../reference/apis-arkts/js-apis-taskpool.md#priority). After all the tasks in the group are complete, the histogram processing result is returned collectively.

3. Aggregate and process the result arrays.

```ts
// Index.ets
import { taskpool } from '@kit.ArkTS';

@Concurrent
function imageProcessing(dataSlice: ArrayBuffer): ArrayBuffer {
  // Step 1: Perform specific image processing operations and other time-consuming operations.
  return dataSlice;
}

function histogramStatistic(pixelBuffer: ArrayBuffer): void {
  // Step 2: Segment the data and schedule tasks concurrently.
  let number: number = pixelBuffer.byteLength / 3;
  let buffer1: ArrayBuffer = pixelBuffer.slice(0, number);
  let buffer2: ArrayBuffer = pixelBuffer.slice(number, number * 2);
  let buffer3: ArrayBuffer = pixelBuffer.slice(number * 2);

  let group: taskpool.TaskGroup = new taskpool.TaskGroup();
  group.addTask(imageProcessing, buffer1);
  group.addTask(imageProcessing, buffer2);
  group.addTask(imageProcessing, buffer3);

  taskpool.execute(group, taskpool.Priority.HIGH).then((ret: Object) => {
    // Step 3: Aggregate and process the result arrays.
    console.info('execute group success');
  })
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
            let buffer: ArrayBuffer = new ArrayBuffer(24);
            histogramStatistic(buffer);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
<!-- @[process_image_histogram](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/managers/CpuIntensiveTaskDevelopment.ets) -->


## Using Worker for Time-Consuming Data Analysis

This example demonstrates training a simple housing price prediction model using housing data from a specific region. The model supports predicting housing prices based on input parameters like house size and number of rooms. Since the model requires long-running execution and the prediction relies on the model's previous results, Worker is the appropriate choice.

1. In DevEco Studio, add a Worker thread named **MyWorker** to your project.

   ![newWorker](figures/newWorker.png)

2. In the host thread, call the [constructor()](../reference/apis-arkts/js-apis-worker.md#constructor9) method of **ThreadWorker** to create a Worker object, register the [onmessage()](../reference/apis-arkts/js-apis-worker.md#properties-1) callback to receive messages from the Worker thread, and call the [postMessage()](../reference/apis-arkts/js-apis-worker.md#postmessage9) method to send messages to the Worker thread.
  For example, the host thread sends training and prediction messages to the Worker thread and receive responses.

    ```ts
    // Index.ets
    import { ErrorEvent, MessageEvents, worker } from '@kit.ArkTS';

    const workerInstance: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/MyWorker.ets');

    let done = false;

    // Receive results from the Worker thread.
    workerInstance.onmessage = (event: MessageEvents) => {
      console.info('MyWorker.ets onmessage');
      if (!done) {
        workerInstance.postMessage({ 'type': 1, 'value': 0 });
        done = true;
      }
    }

    workerInstance.onAllErrors = (err: ErrorEvent) => {
      // Receive error messages from the Worker thread.
    }

    // Send a training message to the Worker thread.
    workerInstance.postMessage({ 'type': 0 });
    ```
    <!-- @[call_worker_message](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/managers/CpuIntensiveTaskDevelopment.ets) -->

3. Bind the Worker object in the **MyWorker.ets** file. The calling thread is the Worker thread. In the Worker thread, register the [onmessage()](../reference/apis-arkts/js-apis-worker.md#properties-2) callback to receive messages sent by the host thread, and call [postMessage()](../reference/apis-arkts/js-apis-worker.md#postmessage9-2) to send messages to the host thread.
    For example, define the prediction model and training process in the Worker thread and interact with the host thread.

    ```ts
    // MyWorker.ets
    import { worker, ThreadWorkerGlobalScope, MessageEvents, ErrorEvent } from '@kit.ArkTS';

    let workerPort: ThreadWorkerGlobalScope = worker.workerPort;

    // Define the training model and results.
    let result: Array<number>;
    // Define the prediction function.
    function predict(x: number): number {
     return result[x];
    }
    // Define the optimizer training process.
    function optimize(): void {
     result = [0];
    }
    // onmessage logic of the Worker thread.
    workerPort.onmessage = (e: MessageEvents): void => {
     // Perform operations based on the type of data to transmit.
     switch (e.data.type as number) {
      case 0:
      // Perform training.
       optimize();
      // Send a training success message to the host thread after training.
       workerPort.postMessage({ type: 'message', value: 'train success.' });
       break;
      case 1:
      // Perform prediction.
       const output: number = predict(e.data.value as number);
      // Send the prediction result to the host thread.
       workerPort.postMessage({ type: 'predict', value: output });
       break;
      default:
       workerPort.postMessage({ type: 'message', value: 'send message is invalid' });
       break;
     }
    }
    ```
    <!-- @[interact_main_thread](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/workers/MyWorker1.ts) -->

4. After the task is completed, destroy the Worker thread. The Worker thread can be destroyed by the host thread or by itself.

    After the Worker thread is destroyed, call [onexit()](../reference/apis-arkts/js-apis-worker.md#properties-1) in the host thread to define the logic for handling the destruction.

    ```ts
    // Index.ets
    // After the Worker thread is destroyed, execute the onexit callback.
    workerInstance.onexit = (): void => {
     console.info("main thread terminate");
    }
    ```

    Method 1: In the host thread, call [terminate()](../reference/apis-arkts/js-apis-worker.md#terminate9) to destroy the Worker thread and stop it from receiving messages.

    ```ts
    // Index.ets
    // Destroy the Worker thread.
    workerInstance.terminate();
    ```

    Method 2: In the Worker thread, call [close()](../reference/apis-arkts/js-apis-worker.md#close9) to destroy the Worker thread and stop it from receiving messages.

    ```ts
    // MyWorker.ets
    // Destroy the Worker thread.
    workerPort.close();
    ```
    <!-- @[after_destroy_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/managers/CpuIntensiveTaskDevelopment.ets) -->
