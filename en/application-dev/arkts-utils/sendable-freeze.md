# Freezing a Sendable Object

Sendable objects can be frozen. Frozen objects become read-only objects and cannot be added, deleted, or modified. Therefore, no lock is required for concurrent access between multiple instances. You can call the [Object.freeze](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/freeze) API to freeze objects.

## Samples

1. Provides the Object.freeze method encapsulated in TS files.

   ```ts
   // helper.ts
   export function freezeObj(obj: any) {
     Object.freeze(obj);
   }
   ```

2. Call the freeze method to freeze the object and send the object to the subthread.

   ```ts
   // Index.ets
   import { freezeObj } from './helper';
   import { worker } from '@kit.ArkTS';
    
   @Sendable
   export class GlobalConfig {
       // Configuration attributes and methods.
     init() {
           // Initialize the logic.
           freezeObj(this) // Freeze this object after the initialization is complete.
     }
   }
    
   @Entry
   @Component
   struct Index {
     build() {
       Column() {
         Text("Sendable freezeObj Test")
           .id('HelloWorld')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .onClick(() => {
             let gConifg = new GlobalConfig();
             gConifg.init();
             const workerInstance = new worker.ThreadWorker('entry/ets/workers/Worker.ets', { name: "Worker1" });
             workerInstance.postMessage(gConifg);
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

3. Subthreads directly operate objects without locking them.

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   import { GlobalConfig } from '../pages/Index';
   
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   workerPort.onmessage = (e: MessageEvents) => {
     let gConfig: GlobalConfig = e.data;
     // Use the gConfig object.
   }
   ```
