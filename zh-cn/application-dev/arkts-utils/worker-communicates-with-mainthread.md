# Worker和宿主线程的即时消息通信


在ArkTS中，Worker相对于Taskpool存在一定的差异性，有数量限制但是可以长时间存在。一个[Worker](worker-introduction.md)中可能会执行多个不同的任务，每个任务的执行时长或返回结果可能都不同，宿主线程需要根据情况调用Worker中的不同方法，Worker则需要及时地将结果返回给宿主线程。


下面以Worker响应"hello world"请求为例说明。


1. 首先，创建一个执行任务的Worker。创建方法可参考[创建worker的注意事项](worker-introduction.md#创建worker的注意事项)。

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   // Worker接收宿主线程的消息，做相应的处理
   workerPort.onmessage = (e: MessageEvents): void => {
     if (e.data === 'hello world') {
       workerPort.postMessage('success');
     }
   }
   ```
   <!-- @[create_worker_execute_multi_task](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/workers/Worker.ets) -->

2. 这里的宿主线程是UI主线程，在宿主线程中创建Worker对象，当点击Button时调用postMessage方法向Worker线程发送消息，通过Worker的onmessage方法接收Worker线程返回的数据。

   ```ts
   // Index.ets
   import { worker } from '@kit.ArkTS';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   function promiseCase() {
     let p: Promise<void> = new Promise<void>((resolve: Function, reject: Function) => {
       setTimeout(() => {
         resolve();
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
     // 接收Worker线程发送的消息
     ss.onmessage = (e) => {
       res = e.data;
       flag = true;
       console.info("worker:: res is  " + res);
     }
     // 给Worker线程发送消息
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
   <!-- @[respond_worker_instant_message](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/WorkerCommunicatesWithMainthread.ets) -->


在示例代码中，Worker接收宿主线程的消息，并进行处理后将结果返回给宿主线程。实现了宿主线程与Worker之间的即时通信，使宿主线程能够方便地使用Worker的运行结果。
