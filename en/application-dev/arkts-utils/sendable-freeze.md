# Freezing Sendable Objects
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

Sendable objects can be frozen, making them read-only and preventing any modifications to their properties. Once frozen, these objects can be safely accessed across multiple concurrent instances without the need for locks. This is achieved using the [Object.freeze](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/freeze) method.

> **NOTE**
> 
> The **Object.freeze** API cannot be used in .ets files.

## Usage Example

1. Encapsulate the **Object.freeze** method in a TS file.

   ```ts
   // helper.ts
   export function freezeObj(obj: any) {
     Object.freeze(obj);
   }
   ```
   <!-- @[provide_encapsulate_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableObjectRelated/entry/src/main/ets/managers/helper.ts) -->

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
             let gConfig = new GlobalConfig();
             gConfig.init();
             const workerInstance = new worker.ThreadWorker('entry/ets/workers/Worker.ets', { name: "Worker1" });
             workerInstance.postMessage(gConfig);
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```
   <!-- @[freeze_obj_send_child_thread](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableObjectRelated/entry/src/main/ets/managers/SendableFreeze.ets) -->

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
   <!-- @[directly_operate_obj](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableObjectRelated/entry/src/main/ets/workers/Worker.ets) -->
