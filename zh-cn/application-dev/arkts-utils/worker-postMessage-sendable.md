# 多级Worker间高性能消息通信
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

多级[Worker](worker-introduction.md)（即通过父Worker创建子Worker的机制形成层级线程关系）间通信是一种常见的需求，由于Worker线程生命周期由用户自行管理，因此需要注意多级Worker生命周期的正确管理，建议开发者确保销毁父Worker前先销毁所有子Worker。

本文介绍如何在多级Worker间实现高性能消息通信。高性能消息通信的关键在于[Sendable对象](arkts-sendable.md)，结合[postMessageWithSharedSendable接口](../reference/apis-arkts/js-apis-worker.md#postmessagewithsharedsendable12)，可以实现线程间高性能的对象传递。例如，在数据克隆场景中，假设有一个父Worker和两个子Worker。父Worker负责创建子Worker，并向子Worker发送数据克隆任务。子Worker接收任务并执行数据克隆操作，完成后将克隆结果返回给父Worker。

1. 在ets文件夹下新建文件夹Sendable，并准备一个Sendable类CopyEntry，封装克隆任务数据。
   
   ```ts
   // CopyEntry.ets
   @Sendable
   export class CopyEntry {
     // 克隆类型
     type: string;
     // 文件路径
     filePath: string;
     constructor(type: string, filePath: string) {
       this.type = type;
       this.filePath = filePath;
     }
   }
   ```

2. 创建两个Worker文件，DevEco Studio支持一键生成Worker，在对应的{moduleName}目录下任意位置，单击鼠标右键 &gt; New &gt; Worker，即可自动生成Worker的模板文件及配置信息。本文以创建“ParentWorker”（父Worker）和“ChildWorker”（子Worker）为例。父Worker负责分发克隆任务并判断任务全部完成后关闭子Worker与父Worker；子Worker负责接收任务并执行数据克隆操作，并在任务完成后通知父Worker。
  
   ```ts
   // ParentWorker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker, collections, ArkTSUtils } from '@kit.ArkTS'
   import { CopyEntry } from '../Sendable/CopyEntry'

   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

   // 计算worker1的任务数量
   let count1 = 0;
   // 计算worker2的任务数量
   let count2 = 0;
   // 计算总任务数量
   let sum = 0;
   // 异步锁
   const asyncLock = new ArkTSUtils.locks.AsyncLock();
   // 创建子Worker
   const copyWorker1 = new worker.ThreadWorker('entry/ets/workers/ChildWorker.ets');
   const copyWorker2 = new worker.ThreadWorker('entry/ets/workers/ChildWorker.ets');

   workerPort.onmessage = (e : MessageEvents) => {
     let array = e.data as collections.Array<CopyEntry>;
     sum = array.length;
     for (let i = 0; i < array.length; i++) {
       let entry = array[i];
       if (entry.type === 'copy1') {
         count1++;
         // 如果是copy1类型，则将数据传递给 copyWorker1
         copyWorker1.postMessageWithSharedSendable(entry);
       } else if (entry.type === 'copy2') {
         count2++;
         // 如果是copy2类型，则将数据传递给 copyWorker2
         copyWorker2.postMessageWithSharedSendable(entry);
       }
     }
   }

   copyWorker1.onmessage = async (e : MessageEvents) => {
     console.info('copyWorker1 onmessage:' + e.data);
     await asyncLock.lockAsync(() => {
       count1--;
       if (count1 == 0) {
         // 如果copyWorker1的任务全部完成，则关闭copyWorker1
         console.info('copyWorker1 close');
         copyWorker1.terminate();
       }
       sum--;
       if (sum == 0) {
         // 如果所有任务全部完成，则关闭父Worker
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
         // 如果copyWorker2的任务全部完成，则关闭copyWorker2
         console.info('copyWorker2 close')
         copyWorker2.terminate();
       }
       if (sum == 0) {
         // 如果所有任务全部完成，则关闭父Worker
         workerPort.close();
       }
     })
   }

   workerPort.onmessageerror = (e : MessageEvents) => {
     console.error('onmessageerror:' + e.data);
   }

   workerPort.onerror = (e : ErrorEvent) => {
     console.error('onerror:' + e.message);
   }
   ```
   ```ts
   // ChildWorker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker} from '@kit.ArkTS'
   import { CopyEntry } from '../Sendable/CopyEntry'

   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

   workerPort.onmessage = (e : MessageEvents) => {
     let data = e.data as CopyEntry;
     // 中间copy操作省略
     console.info(data.filePath);
     workerPort.postMessageWithSharedSendable("done");
   }

   workerPort.onmessageerror = (e : MessageEvents) => {
     console.error('onmessageerror:' + e.data);
   }

   workerPort.onerror = (e : ErrorEvent) => {
     console.error('onerror:' + e.message);
   }
   ```

3. 在UI主线程页面，创建父Worker并准备克隆任务所需的数据，准备完成后将数据发送给父Worker。

   ```ts
   // Index.ets
   import { worker, collections } from '@kit.ArkTS';
   import { CopyEntry } from '../Sendable/CopyEntry'
   
   function promiseCase() {
     let p: Promise<void> = new Promise<void>((resolve: Function, reject: Function) => {
       setTimeout(() => {
         resolve();
       }, 100);
     });
     return p;
   }

   async function postMessageTest() {
     let ss = new worker.ThreadWorker("entry/ets/workers/ParentWorker.ets");
     let isTerminate = false;
     ss.onexit = () => {
       isTerminate = true;
     }
     let array = new collections.Array<CopyEntry>();
     // 准备数据
     for (let i = 0; i < 4; i++) {
       if (i % 2 == 0) {
         array.push(new CopyEntry("copy1", "file://copy1.txt"));
       } else {
         array.push(new CopyEntry("copy2", "file://copy2.txt"));
       }
     }
     // 给Worker线程发送消息
     ss.postMessageWithSharedSendable(array);
     while (!isTerminate) {
       await promiseCase();
     }
     console.info("Worker线程已退出");
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