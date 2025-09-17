# Synchronous Calls to Host Thread Interfaces from Worker
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

This topic describes the approach that Worker uses to call an interface that is already implemented in the host thread.

The example below demonstrates how Worker can synchronously call an API from the host thread. For details about how to create a Worker, see [Precautions for Creating a Worker](worker-introduction.md#precautions-for-creating-a-worker).

1. Implement the interface in the host thread and create a Worker object. Register the interface to be called on the Worker object.

   ```ts
   // Index.ets
   import { MessageEvents, worker } from '@kit.ArkTS';
   
   class TestObj {
     public getMessage(): string {
       return "this is a message from TestObj";
     }
   
     static testObj: TestObj = new TestObj();
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
               // Create a Worker object.
               const workerInstance: worker.ThreadWorker = new worker.ThreadWorker("entry/ets/workers/Worker.ets");
               // Register the object to be called on the Worker object.
               workerInstance.registerGlobalCallObject("testObj", TestObj.testObj);
               workerInstance.postMessage("start");
               workerInstance.onmessage = (e: MessageEvents): void => {
                 // Receive results from the Worker thread.
                 console.info("mainthread: " + e.data);
                 // Destroy the Worker.
                 workerInstance.terminate();
               }
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
   <!-- @[create_worker_obj](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/WorkerCallGlobalUsage.ets) -->

2. In Worker, use **callGlobalCallObjectMethod** to call the **getMessage()** method implemented in the host thread.

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   
   workerPort.onmessage = async (e: MessageEvents) => {
     if (e.data === 'start') {
       try {
         // Call the method.
         let res: string = workerPort.callGlobalCallObjectMethod("testObj", "getMessage", 0) as string;
         console.info("worker: ", res);
         if (res === "this is a message from TestObj") {
           workerPort.postMessage("run function success.");
         }
       } catch (error) {
         // Handle exceptions.
         console.error("worker: error code is " + error.code + " error message is " + error.message);
       }
     }
   }
   ```
   <!-- @[call_main_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/workers/Worker.ets) -->
