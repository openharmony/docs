# Worker和主线程的即时消息通信


在ArkTS中，Worker相对于Taskpool存在一定的差异性，有数量限制但是可以长时间存在。一个[Worker](worker-introduction.md)中可能会执行多个不同的任务，每个任务执行的时长或者返回的结果可能都不相同，主线程需要根据情况调用Worker中的不同方法，Worker则需要及时地将结果返回给主线程。


下面以Worker响应"hello world"请求为例进行说明。


1. 首先，创建一个执行多个任务Worker。

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   // Worker接收主线程的消息，做相应的处理
   workerPort.onmessage = (e: MessageEvents): void => {
     if (e.data === 'hello world') {
       workerPort.postMessage('success');
     }
   }
   ```

2. 然后在主线程中创建这个Worker的对象，在点击Button的时候调用postmessage向Worker发送消息，通过Worker的onmessage方法接收Worker返回的数据。

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


在上文这段示例代码中，Worker接收来自主线程的消息，并做了相应处理后把结果发回给主线程。这样就可以实现主线程和Worker间的即时通信，方便主线程使用Worker的运行结果。
