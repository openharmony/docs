# Freezing Sendable Objects

Sendable objects can be frozen, making them read-only and preventing any additions, deletions, or modifications to their properties. Once frozen, these objects can be safely accessed across multiple concurrent instances without the need for locks. This is achieved using the [Object.freeze](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/freeze) method.

## Usage Example

1. Encapsulate the **Object.freeze** method in a TS file.

   ```ts
   // helper.ts
   export function freezeObj(obj: any) {
     Object.freeze(obj);
   }
   ```

2. Call the **freeze** method to freeze an object and send it to a child thread.

   ```ts
   // Index.ets
   import { freezeObj } from './helper';
   import { worker } from '@kit.ArkTS';
    
   @Sendable
   export class GlobalConfig {
     // Configuration properties and methods
     init() {
       // Initialization logic
       freezeObj(this) // Freeze the object after the initialization is complete.
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

3. Perform operations on the frozen object directly in the child thread without locking.

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
