# Sendable对象冻结

Sendable对象支持冻结操作，冻结后的对象变成只读对象，不能增删改属性，因此在多个并发实例间访问均不需要加锁，可以通过调用[Object.freeze](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Object/freeze)接口冻结对象。

## 使用示例

1. 提供ts文件封装Object.freeze方法。

   ```ts
   // helper.ts
   export function freezeObj(obj: any) {
     Object.freeze(obj);
   }
   ```

2. 调用freeze方法冻结对象，然后将对象发送到子线程。

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

3. 子线程不加锁直接操作对象。

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
