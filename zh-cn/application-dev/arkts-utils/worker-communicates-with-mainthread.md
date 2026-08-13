# Worker和宿主线程的即时消息通信
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @huanghello-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->


在ArkTS中，Worker相对于TaskPool存在一定的差异性，有数量限制但是可以长时间存在。一个[Worker](worker-introduction.md)中可能会执行多个不同的任务，每个任务的执行时长或返回结果可能都不同，宿主线程需要根据情况调用Worker中的不同方法，Worker则需要及时地将结果返回给宿主线程。


下面以Worker响应"hello world"请求为例说明。


1. 首先，创建一个执行任务的Worker。创建方法可参考[创建Worker的注意事项](worker-introduction.md#创建worker的注意事项)。

   <!-- @[create_worker_execute_multi_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/workers/Worker.ets) --> 
   
   ``` TypeScript
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   
   workerPort.onmessage = (e: MessageEvents) => {
     // ...
     if (e.data === 'hello world') {
       workerPort.postMessage('success');
     }
   }
   ```

2. 这里的宿主线程是UI主线程，在宿主线程中创建Worker对象，当点击Button时调用postMessage方法向Worker线程发送消息，Worker线程将通过注册的onmessage回调处理宿主线程发送的消息。

   <!-- @[respond_worker_instant_message](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/WorkerCommunicatesWithMainthread.ets) -->
   
   ``` TypeScript
   import { worker, ErrorEvent, MessageEvents } from '@kit.ArkTS';
   
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
               // 创建Worker线程实例
               const ss: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets');
   
               // 接收Worker线程发送的消息，收到后刷新成功并销毁Worker
               ss.onmessage = (e: MessageEvents): void => {
                 console.info('worker:: res is ' + e.data);
                 this.message = 'success';
                 // 在回调中销毁Worker线程，避免资源泄漏
                 ss.terminate();
               };
   
               // 捕获Worker线程生命周期内的全局异常，刷新失败状态（API version 18+）
               ss.onAllErrors = (err: ErrorEvent): void => {
                 console.error('worker:: error is ' + err.message);
                 this.message = 'failed';
               };
   
               // 给Worker线程发送消息
               ss.postMessage('hello world');
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

在示例代码中，Worker接收宿主线程的消息，并处理后将结果返回给宿主线程。实现了宿主线程与Worker之间的即时通信，使宿主线程能够方便地使用Worker的运行结果。
