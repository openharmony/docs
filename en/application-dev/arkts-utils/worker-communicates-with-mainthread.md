# Real-Time Communication Between the Worker Thread and Host Thread


In ArkTS, Worker differ from TaskPool in that it has a limited number of threads but can run for extended periods. A [Worker](worker-introduction.md) can execute multiple tasks, each with varying execution times and results. The host thread needs to call different methods in the Worker based on the situation, and the Worker must promptly return the results to the host thread.


The following example demonstrates how a Worker can respond to a "hello world" request.


1. Create a Worker that executes multiple tasks.

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   // The Worker receives messages from the host thread and processes them accordingly.
   workerPort.onmessage = (e: MessageEvents): void => {
     if (e.data === 'hello world') {
       workerPort.postMessage('success');
     }
   }
   ```

2. In the host thread (UI main thread), create a Worker object. Use the **postmessage** method to send a message to the Worker when a button is clicked, and use the **onmessage** method of Worker to receive the response.

   ```ts
   // Index.ets
   import { worker } from '@kit.ArkTS';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   function promiseCase() {
     let p: Promise<void> = new Promise<void>((resolve: Function, reject: Function) => {
       setTimeout(() => {
         resolve(1);
       }, 100)
     }).then(undefined, (error: BusinessError) => {
     })
     return p;
   }
   
   async function postMessageTest() {
     let ss = new worker.ThreadWorker("entry/ets/workers/Worker.ets");
     let res = undefined;
     let flag = false;
     let isTerminate = false;
     ss.onexit = () => {
       isTerminate = true;
     }
     // Receive messages sent by the Worker thread.
     ss.onmessage = (e) => {
       res = e.data;
       flag = true;
       console.info("worker:: res is  " + res);
     }
     // Send a message to the Worker thread.
     ss.postMessage("hello world");
     while (!flag) {
       await promiseCase();
     }
   
     ss.terminate();
     while (!isTerminate) {
       await promiseCase();
     }
   }
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               postMessageTest();
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```


In this example, the Worker thread receives a message from the host thread, processes it, and sends a response back. This enables real-time communication between the host thread and the Worker thread, allowing the host thread to conveniently use the execution results of the Worker.
