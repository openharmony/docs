# Worker同步调用宿主线程的接口
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @huanghello-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

如果一个接口已在宿主线程中实现，Worker可以通过以下方式调用该接口。

以下示例展示了Worker同步调用宿主线程接口的方法，创建Worker的方法可参考[创建Worker的注意事项](worker-introduction.md#创建worker的注意事项)。

1. 首先，在宿主线程实现需要调用的接口，并创建Worker对象，在Worker对象上注册需要调用的对象。

   <!-- @[create_worker_obj](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/WorkerCallGlobalUsage.ets) -->
   
   ``` TypeScript
   import { MessageEvents, worker } from '@kit.ArkTS';
      
      class TestObj {
        public getMessage(): string {
          return 'this is a message from TestObj';
        }
      
        public static testObj: TestObj = new TestObj();
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
                  workerInstance.registerGlobalCallObject('testObj', TestObj.testObj);
                  workerInstance.onmessage = (e: MessageEvents): void => {
                    // 接收Worker子线程的结果
                    console.info('mainThread: ' + e.data);
                    // 销毁Worker
                    workerInstance.terminate();
                  }
                  workerInstance.postMessage('start');
                })
            }
            .width('100%')
          }
          .height('100%')
        }
      }
   ```

2. 然后，在Worker中通过[callGlobalCallObjectMethod](../reference/apis-arkts/js-apis-worker.md#callglobalcallobjectmethod11)接口可以调用宿主线程中的getMessage()方法。

   <!-- @[call_main_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/workers/Worker.ets) -->
   
   ``` TypeScript
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   
   workerPort.onmessage = (e: MessageEvents) => {
     if (e.data === 'start') {
       try {
         // 调用方法
         let res: string = workerPort.callGlobalCallObjectMethod('testObj', 'getMessage', 0) as string;
         if (res === 'this is a message from TestObj') {
           workerPort.postMessage('run function success.');
         }
       } catch (error) {
         // 异常处理
         console.error('worker: error code is ' + error.code + ' error message is ' + error.message);
       }
     }
   
     // ...
   }
   ```
