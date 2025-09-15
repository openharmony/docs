# Persistent Worker Threads Handling Concurrent Tasks via TaskPool
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

In ArkTS application development, you can choose between TaskPool and Worker threads for concurrent task processing, or you utilize both capabilities.

This section describes how to execute concurrent tasks through TaskPool within a Worker thread.

1. Create a Worker thread in the main thread and send a message.

   ```ts
   // Index.ets
   import { MessageEvents, worker } from '@kit.ArkTS';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
   
     build() {
       RelativeContainer() {
         Text(this.message)
           .id('HelloWorld')
           .fontSize($r('app.float.page_text_font_size'))
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: '__container__', align: VerticalAlign.Center },
             middle: { anchor: '__container__', align: HorizontalAlign.Center }
           })
           .onClick(() => {
             // 1. Create a Worker instance.
             const myWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets');
   
             // 2. Handle results from the Worker instance.
             myWorker.onmessage = (e: MessageEvents) => {
               console.info('Main thread receives the final result:', e.data.result);
               myWorker.terminate(); // Destroy the Worker instance at an appropriate time.
             };
   
             // 3. Send a startup instruction to the Worker instance.
             myWorker.postMessage({ type: 'start', data: 10 });
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

2. Call TaskPool to execute concurrent tasks in the Worker thread.

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   import { taskpool } from '@kit.ArkTS';
   
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   workerPort.onmessage = async (e: MessageEvents) => {
     if (e.data.type === 'start') {
       // Simulate data processing by the Worker instance.
       const processedData = heavyComputation(e.data.data);
   
       // Call TaskPool to execute concurrent tasks.
       const task = new taskpool.Task(parallelTask, processedData);
       const result = await taskpool.execute(task);
       console.info('Worker thread returns result: ', result);
   
       // Return the final result to the main thread.
       workerPort.postMessage({
         status: 'success',
         result: result
       });
     }
   }
   
   function heavyComputation(base: number): number {
     let sum = 0;
     for (let i = 0; i < base * 10; i++) {
       sum += Math.sqrt(i);
     }
     return sum;
   }
   
   @Concurrent
   function parallelTask(base: number): number {
     let total = 0;
     for (let i = 0; i < base; i++) {
       total += i % 2 === 0 ? i : -i;
     }
     console.info('TaskPool thread calculation result: ', total);
     return total;
   }
   ```
