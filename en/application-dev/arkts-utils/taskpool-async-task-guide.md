# Specifying Task Concurrency with TaskPool

This section describes how to use TaskPool to create [asynchronous queues](../reference/apis-arkts/js-apis-taskpool.md#asyncrunner18). It uses the operation of collection and processing of camera preview stream data as an example.
This operation is frequent and time consuming. If the camera captures data too quickly, earlier frames are discarded to ensure only the most recent frame is processed.

1. Import the required modules.

   ```ts
   // Index.ets
   import { taskpool } from '@kit.ArkTS';
   import { BusinessError, emitter } from '@kit.BasicServicesKit';
   ```

2. Define a continuous task.

   ```ts
   // Index.ets
   @Concurrent
   function collectFrame() {
      // Collect and process data.
      // Simulate the processing task, which is time consuming.
      let t = new Date().getTime()
      while (new Date().getTime() - t < 30000) {
        continue;
      }
   }
   ```

3. Create an asynchronous queue and execute the collection task.

   ```ts
   // Index.ets
   @Entry
   @Component
   struct Index {
     sensorTask?: taskpool.LongTask

     build() {
       Column() {
         Text("HELLO WORLD")
           .id('HelloWorld')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .onClick(() => {
             // Create an asynchronous queue with a concurrency level of 5 and a queue capacity of 5.
             let asyncRunner:taskpool.AsyncRunner = new taskpool.AsyncRunner("async", 5, 5);
             // Trigger the collection task every second.
             setTimeout(() => {
               let task:taskpool.Task = new taskpool.Task(collectFrame);
                asyncRunner.execute(task);
              }, 1000);
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```
