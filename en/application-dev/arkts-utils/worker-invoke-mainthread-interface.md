# Synchronous Calls to Host Thread Interfaces from Worker

This topic describes the approach that Worker uses to call an interface that is already implemented in the host thread.

The example below demonstrates how Worker can synchronously call an interface from the host thread.

1. Implement the interface in the host thread and create a Worker object. Register the interface to be called on the Worker object.

   ```ts
   // IconItemSource.ets
   export class IconItemSource {
     image: string | Resource = '';
     text: string | Resource = '';
   
     constructor(image: string | Resource = '', text: string | Resource = '') {
       this.image = image;
       this.text = text;
     }
   }
   ```
   <!-- @[implement_child_thread_task](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/IconItemSource.ets) -->

   ```ts
   // WorkerCallGlobalUsage.ets
   import worker from '@ohos.worker';
   import { IconItemSource } from './IconItemSource';
   
   // Create a Worker object.
   const workerInstance: worker.ThreadWorker = new worker.ThreadWorker("entry/ets/pages/workers/Worker.ts");
   
   class PicData {
     public iconItemSourceList: IconItemSource[] = [];
   
     public setUp(): string {
       for (let index = 0; index < 20; index++) {
         const numStart: number = index * 6;
         // Use six images in the loop.
         this.iconItemSourceList.push(new IconItemSource('$media:startIcon', `item${numStart + 1}`));
         this.iconItemSourceList.push(new IconItemSource('$media:background', `item${numStart + 2}`));
         this.iconItemSourceList.push(new IconItemSource('$media:foreground', `item${numStart + 3}`));
         this.iconItemSourceList.push(new IconItemSource('$media:startIcon', `item${numStart + 4}`));
         this.iconItemSourceList.push(new IconItemSource('$media:background', `item${numStart + 5}`));
         this.iconItemSourceList.push(new IconItemSource('$media:foreground', `item${numStart + 6}`));
   
       }
       return "setUpIconItemSourceList success!";
     }
   }
   
   let picData = new PicData();
   // Register the object to be called on the Worker object.
   workerInstance.registerGlobalCallObject("picData", picData);
   workerInstance.postMessage("run setUp in picData");
   ```
   <!-- @[create_worker_obj](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/WorkerCallGlobalUsage.ets) -->

2. In Worker, use the **callGlobalCallObjectMethod** interface to call the **setUp()** method implemented in the host thread.

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   try {
     // Call the method without parameters.
     let res: string = workerPort.callGlobalCallObjectMethod("picData", "setUp", 0) as string;
     console.error("worker: ", res);
   } catch (error) {
     // Handle exceptions.
     console.error("worker: error code is " + error.code + " error message is " + error.message);
   }
   ```
   <!-- @[call_main_method](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/workers/Worker.ets) -->
