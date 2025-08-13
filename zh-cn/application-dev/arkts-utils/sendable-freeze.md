# Sendable对象冻结
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--SE: @weng-changcheng-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

Sendable对象支持冻结操作。冻结后，对象变为只读，不能增删改属性。因此，多个并发实例间访问时无需加锁。可以通过调用[Object.freeze](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Object/freeze)接口冻结对象。

> **说明：**
> 
> 不支持在.ets文件中使用Object.freeze接口。

## 使用示例

1. 提供ts文件封装Object.freeze方法。

   ```ts
   // helper.ts
   export function freezeObj(obj: any) {
     Object.freeze(obj);
   }
   ```
   <!-- @[provide_encapsulate_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableObjectRelated/entry/src/main/ets/managers/helper.ts) -->

2. 调用freeze方法冻结对象，然后将其发送到子线程。

   ```ts
   // Index.ets
   import { freezeObj } from './helper';
   import { worker } from '@kit.ArkTS';
    
   @Sendable
   export class GlobalConfig {
     // 一些配置属性与方法
     init() {
       // 初始化相关逻辑
       freezeObj(this); // 初始化完成后冻结当前对象
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

3. 子线程直接操作对象，不加锁。

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   import { GlobalConfig } from '../pages/Index';
   
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   workerPort.onmessage = (e: MessageEvents) => {
     let gConfig: GlobalConfig = e.data;
     // 使用gConfig对象
   }
   ```
   <!-- @[directly_operate_obj](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableObjectRelated/entry/src/main/ets/workers/Worker.ets) -->
