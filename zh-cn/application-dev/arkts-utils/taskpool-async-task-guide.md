# TaskPool指定任务并发度场景
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @huanghello-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

TaskPool支持使用异步队列来控制任务的并发度，能有效避免资源过载，减少任务阻塞，适用于网络请求、视频流处理和数据库操作等场景。

此处提供使用TaskPool创建[异步队列](../reference/apis-arkts/js-apis-taskpool.md#asyncrunner18)的开发指导，以相机预览流采集数据处理的功能为例。

由于处理过程是一个频繁且耗时的任务，当相机采集速度过快时，将丢弃之前的采集数据，仅保留最新的一帧数据进行处理。

1. 导入需要用到的模块。
   <!-- @[taskpool_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCasesSecond/entry/src/main/ets/pages/TaskpoolAsyncLevel.ets) -->   
   
   ``` TypeScript
   // TaskpoolAsyncLevel.ets
   import { taskpool } from '@kit.ArkTS';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { PromptAction } from '@kit.ArkUI';
   ```

2. 定义耗时任务。

   <!-- @[collect_frame](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCasesSecond/entry/src/main/ets/pages/TaskpoolAsyncLevel.ets) -->
   
   ``` TypeScript
   // TaskpoolAsyncLevel.ets
   @Concurrent
   function collectFrame() {
     // 采集数据，并且进行处理
     // 模拟处理过程，这里是个耗时任务，持续时间为30秒
     let t = new Date().getTime()
     while (new Date().getTime() - t < 30000) {
       continue;
     }
     console.info('collectFrame finished');
   }
   ```

3. 创建异步队列并执行采集任务。

   <!-- @[trigger_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCasesSecond/entry/src/main/ets/pages/TaskpoolAsyncLevel.ets) --> 
   
   ``` TypeScript
   // TaskpoolAsyncLevel.ets
   @Entry
   @Component
   struct TaskpoolAsyncLevel {
     @State message: string = '触发采集任务';
     @State returnMessage: string = 'return...';
     @State promptAction: PromptAction = this.getUIContext().getPromptAction();
     
     build() {
       Row() {
         Column() {
           Button(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(async () => {
               // 创建并发度为5的异步队列，等待队列个数为5，当加入的任务数量超过5时，等待列表中处于队头的任务会被丢弃
               let asyncRunner: taskpool.AsyncRunner = new taskpool.AsyncRunner('async', 5, 5);
               // 触发采集任务
               let promises: Promise<void>[] = [];
               for (let i = 0; i < 20; i++) {
                 let task: taskpool.Task = new taskpool.Task(`async${i}`, collectFrame);
                 let p: Promise<void> = asyncRunner.execute(task).then(() => {
                   console.info('the current task name is ' + task.name);
                 }).catch((e: BusinessError) => {
                   console.error('async: error is ' + e);
                 });
                 promises.push(p);
               }
               // 等待所有任务完成后再执行后续语句
               await Promise.allSettled(promises);
               console.info('asyncRunner tasks submitted');
               this.returnMessage = 'asyncRunner task finished';
               this.promptAction.showToast({ message: this.returnMessage });
             })
           // ...
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
