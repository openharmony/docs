# Worker同步调用宿主线程的接口
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--SE: @weng-changcheng-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

如果一个接口已在宿主线程中实现，Worker可以通过以下方式调用该接口。

以下示例展示了Worker同步调用宿主线程接口的方法，创建worker的方法可参考[创建worker的注意事项](worker-introduction.md#创建worker的注意事项)。

1. 首先，在宿主线程实现需要调用的接口，并创建Worker对象，在Worker对象上注册需要调用的对象。

   ```ts
   // Index.ets
   import { MessageEvents, worker } from '@kit.ArkTS';
   
   class TestObj {
     public getMessage(): string {
       return "this is a message from TestObj";
     }
   
     static testObj: TestObj = new TestObj();
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
               // 创建Worker对象
               const workerInstance: worker.ThreadWorker = new worker.ThreadWorker("entry/ets/workers/Worker.ets");
               // 在Worker上注册需要调用的对象
               workerInstance.registerGlobalCallObject("testObj", TestObj.testObj);
               workerInstance.postMessage("start");
               workerInstance.onmessage = (e: MessageEvents): void => {
                 // 接收Worker子线程的结果
                 console.info("mainthread: " + e.data);
                 // 销毁Worker
                 workerInstance.terminate();
               }
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
   <!-- @[create_worker_obj](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/WorkerCallGlobalUsage.ets) -->

2. 然后，在Worker中通过callGlobalCallObjectMethod接口可以调用宿主线程中的getMessage()方法。

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   
   workerPort.onmessage = async (e: MessageEvents) => {
     if (e.data === 'start') {
       try {
         // 调用方法
         let res: string = workerPort.callGlobalCallObjectMethod("testObj", "getMessage", 0) as string;
         console.info("worker: ", res);
         if (res === "this is a message from TestObj") {
           workerPort.postMessage("run function success.");
         }
       } catch (error) {
         // 异常处理
         console.error("worker: error code is " + error.code + " error message is " + error.message);
       }
     }
   }
   ```
   <!-- @[call_main_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/workers/Worker.ets) -->
