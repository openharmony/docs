# High-Performance Communication Between Multi-Level Workers

It is a common requirement for communication between multi-level [Workers](worker-introduction.md) (where child Workers are created by parent Workers, forming a hierarchy). Since you are responsible for managing the lifecycles of Worker threads, it is crucial to properly manage the lifecycles of multi-level Workers. You should ensure that all child Workers are destroyed before the parent Worker is destroyed.

This topic describes how to implement high-performance communication between multi-level Workers. The key is using [Sendable objects](arkts-sendable.md) with the Worker's [postMessageWithSharedSendable](../reference/apis-arkts/js-apis-worker.md#postmessagewithsharedsendable12) interface for high-performance object passing between threads. For example, in a data cloning scenario with three Workers (one parent and two children), the parent Worker creates the child Workers, sends cloning tasks to them, and receives the results back.

1. Prepare a Sendable class **CopyEntry** to encapsulate the cloning task data.
   
   ```ts
   // CopyEntry.ets
   @Sendable
   export class CopyEntry {
     // Clone type.
     type: string;
     // File path.
     filePath: string;
     constructor(type: string, filePath: string) {
       this.type = type;
       this.filePath = filePath;
     }
   }
   ```

2. Prepare two Worker files: **ParentWorker.ets** for the parent Worker and **ChildWorker.ets** for the child Workers. The parent Worker distributes tasks and closes the child and parent Workers once all tasks are complete. The child Workers receive tasks, perform cloning, and notify the parent Worker when the tasks are complete.
  
   ```ts
   // ParentWorker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker, collections, ArkTSUtils } from '@kit.ArkTS'
   import { CopyEntry } from './CopyEntry'

   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

   // Calculate the number of tasks of worker1.
   let count1 = 0;
   // Calculate the number of tasks of worker2.
   let count2 = 0;
   // Calculate the total number of tasks.
   let sum = 0;
   // Asynchronous lock.
   const asyncLock = new ArkTSUtils.locks.AsyncLock();
   // Create a child Worker.
   const copyWorker1 = new worker.ThreadWorker('entry/ets/pages/ChildWorker');
   const copyWorker2 = new worker.ThreadWorker('entry/ets/pages/ChildWorker');

   workerPort.onmessage = (e : MessageEvents) => {
     let array = e.data as collections.Array<CopyEntry>;
     sum = array.length;
     for (let i = 0; i < array.length; i++) {
       let entry = array[i];
       if (entry.type === 'copy1') {
         count1++;
         // If the data type is copy1, transfer the data to copyWorker1.
         copyWorker1.postMessageWithSharedSendable(entry);
       } else if (entry.type === 'copy2') {
         count2++;
         // If the data type is copy2, transfer the data to copyWorker2.
         copyWorker2.postMessageWithSharedSendable(entry);
       }
     }
   }

   copyWorker1.onmessage = async (e : MessageEvents) => {
     console.info('copyWorker1 onmessage:' + e.data);
     await asyncLock.lockAsync(() => {
       count1--;
       if (count1 == 0) {
         // If all tasks of copyWorker1 are complete, close copyWorker1.
         console.info('copyWorker1 close');
         copyWorker1.terminate();
       }
       sum--;
       if (sum == 0) {
         // If all tasks are complete, close the parent Worker.
         workerPort.close();
       }
     })
   }

   copyWorker2.onmessage = async (e : MessageEvents) => {
     console.info('copyWorker2 onmessage:' + e.data);
     await asyncLock.lockAsync(() => {
       count2--;
       sum--;
       if (count2 == 0) {
         // If all tasks of copyWorker2 are complete, close copyWorker2.
         console.info('copyWorker2 close')
         copyWorker2.terminate();
       }
       if (sum == 0) {
         // If all tasks are complete, close the parent Worker.
         workerPort.close();
       }
     })
   }

   workerPort.onmessageerror = (e : MessageEvents) => {
     console.info('onmessageerror:' + e.data);
   }

   workerPort.onerror = (e : ErrorEvent) => {
     console.info('onerror:' + e.message);
   }
   ```
   ```ts
   // ChildWorker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker} from '@kit.ArkTS'
   import { CopyEntry } from './CopyEntry'

   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

   workerPort.onmessage = (e : MessageEvents) => {
     let data = e.data as CopyEntry;
     // The copy operation is omitted.
     console.info(data.filePath);
     workerPort.postMessageWithSharedSendable("done");
   }

   workerPort.onmessageerror = (e : MessageEvents) => {
     console.info('onmessageerror:' + e.data);
   }

   workerPort.onerror = (e : ErrorEvent) => {
     console.info('onerror:' + e.message);
   }
   ```

3. On the main process page of the UI, create a parent Worker, prepare the data required for the cloning task, and send the data to the parent Worker.

   ```ts
   // Index.ets
   import { worker, collections } from '@kit.ArkTS';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { CopyEntry } from './CopyEntry'

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
     let ss = new worker.ThreadWorker("entry/ets/pages/ParentWorker");
     let isTerminate = false;
     ss.onexit = () => {
       isTerminate = true;
     }
     let array = new collections.Array<CopyEntry>();
     // Prepare data.
     for (let i = 0; i < 4; i++) {
       if (i % 2 == 0) {
         array.push(new CopyEntry("copy1", "file://copy1.txt"));
       } else {
         array.push(new CopyEntry("copy2", "file://copy2.txt"));
       }
     }
     // Send a message to the Worker thread.
     ss.postMessageWithSharedSendable(array);
     while (!isTerminate) {
       await promiseCase();
     }
     console.info("Worker thread has exited");
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
