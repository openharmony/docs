# Worker Thread Synchronously Calling Methods of the Host Thread

If the Worker thread needs to call the method that has been implemented in the main thread, you can perform the following operations:

The following uses an example in which the worker synchronously calls the host thread interface for description.

1. First, implement the method in the host thread, create a **Worker** object, and register the method on the **Worker** object.

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
         // Six images are used cyclically.
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
   // Register the method on the Worker object.
   workerInstance.registerGlobalCallObject("picData", picData);
   workerInstance.postMessage("run setUp in picData");
   ```

2. Then, the setUp () method in the host thread can be called through the callGlobalCallObjectMethod interface in the worker.

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   try {
     // The method to call does not carry an input parameter.
     let res: string = workerPort.callGlobalCallObjectMethod("picData", "setUp", 0) as string;
     console.error("worker: ", res);
   } catch (error) {
     // Exception handling.
     console.error("worker: error code is " + error.code + " error message is " + error.message);
   }
   ```
