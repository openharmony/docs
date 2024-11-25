# Worker同步调用宿主线程的接口

如果一个接口在主线程中已经实现了，Worker需要调用该接口，那么可以使用下面这种方式实现。

下面以Worker同步调用宿主线程接口为例进行说明。

1. 首先，在宿主线程实现需要调用的接口，并且创建Worker对象，在Worker上注册需要调用的接口。

   ```ts
   // IconItemSource.ets
   export class IconItemSource {
     image: string | Resource = '';
     text: string | Resource = '';
   
     constructor(image: string | Resource = '', text: string | Resource = '') {
       this.image = image;
       this.text = text;
     }
   }
   ```

   ```ts
   // WorkerCallGlobalUsage.ets
   import worker from '@ohos.worker';
   import { IconItemSource } from './IconItemSource';
   
   // 创建Worker对象
   const workerInstance: worker.ThreadWorker = new worker.ThreadWorker("entry/ets/pages/workers/Worker.ts");
   
   class PicData {
     public iconItemSourceList: IconItemSource[] = [];
   
     public setUp(): string {
       for (let index = 0; index < 20; index++) {
         const numStart: number = index * 6;
         // 此处循环使用6张图片资源
         this.iconItemSourceList.push(new IconItemSource('$media:startIcon', `item${numStart + 1}`));
         this.iconItemSourceList.push(new IconItemSource('$media:background', `item${numStart + 2}`));
         this.iconItemSourceList.push(new IconItemSource('$media:foreground', `item${numStart + 3}`));
         this.iconItemSourceList.push(new IconItemSource('$media:startIcon', `item${numStart + 4}`));
         this.iconItemSourceList.push(new IconItemSource('$media:background', `item${numStart + 5}`));
         this.iconItemSourceList.push(new IconItemSource('$media:foreground', `item${numStart + 6}`));
   
       }
       return "setUpIconItemSourceList success!";
     }
   }
   
   let picData = new PicData();
   // 在Worker上注册需要调用的对象
   workerInstance.registerGlobalCallObject("picData", picData);
   workerInstance.postMessage("run setUp in picData");
   ```

2. 然后，在Worker中通过callGlobalCallObjectMethod接口就可以调用宿主线程中的setUp()方法了。

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   try {
     // 调用方法无入参
     let res: string = workerPort.callGlobalCallObjectMethod("picData", "setUp", 0) as string;
     console.error("worker: ", res);
   } catch (error) {
     // 异常处理
     console.error("worker: error code is " + error.code + " error message is " + error.message);
   }
   ```
