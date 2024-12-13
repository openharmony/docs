# Instant Communication Between the Worker Thread and Host Thread


In ArkTS, Worker provides a limited number of threads that exist for a longer time than TaskPool threads. A [Worker](worker-introduction.md) may execute multiple tasks. The execution duration or returned result of each task may be different. The host thread needs to call different methods in the Worker based on the site requirements, the worker needs to return the result to the host thread in a timely manner.


The following uses an example in which the worker responds to the "hello world" request for description.


1. First, create a Worker for executing multiple tasks.

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   // The worker receives the message from the host thread and performs corresponding processing.
   workerPort.onmessage = (e: MessageEvents): void => {
     if (e.data === 'hello world') {
       workerPort.postMessage('success');
     }
   }
   ```

2. The host thread is the UI main thread. The worker object is created in the host thread. When the button is clicked, the postmessage function is called to send a message to the worker. The onmessage method of the worker is used to receive the data returned by the worker.

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
     Receive messages sent by the worker thread.
     ss.onmessage = (e) => {
       res = e.data;
       flag = true;
       console.info("worker:: res is  " + res);
     }
     // Send a message to the worker thread.
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


In the preceding sample code, the worker receives a message from the host thread, processes the message, and sends the result back to the host thread. In this way, instant communication between the main thread and Worker thread can be implemented.
