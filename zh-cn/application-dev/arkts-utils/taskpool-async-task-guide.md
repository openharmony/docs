# TaskPool指定任务并发度场景

此处提供使用TaskPool创建[异步队列](../reference/apis-arkts/js-apis-taskpool.md#asyncrunner18)的开发指导，以相机预览流采集数据处理的功能为例。
由于处理过程是个频繁耗时任务，如果相机采集过快，就丢弃之前的采集数据，缓存最新的一帧数据处理。

1. 导入需要用到的模块。

   ```ts
   // Index.ets
   import { taskpool } from '@kit.ArkTS';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 定义耗时任务。

   ```ts
   // Index.ets
   @Concurrent
   function collectFrame() {
      // 采集数据，并且进行处理
      // 模拟处理过程，这里是个耗时任务
      let t = new Date().getTime()
      while (new Date().getTime() - t < 30000) {
        continue;
      }
      console.info("collectFrame finished");
   }
   ```

3. 创建异步队列并执行采集任务。

   ```ts
   // Index.ets
   @Entry
   @Component
   struct Index {
   
     build() {
       Column() {
         Text("HELLO WORLD")
           .id('HelloWorld')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .onClick(async () => {
             // 创建并发度为5的异步队列，等待队列个数为5。
             let asyncRunner:taskpool.AsyncRunner = new taskpool.AsyncRunner("async", 5, 5);
             // 触发采集任务
             for (let i = 0; i < 20; i++) {
               let task:taskpool.Task = new taskpool.Task(`async${i}`,collectFrame);
               asyncRunner.execute(task).then(() => {
                 console.info("the current task name is " + task.name);
               }).catch((e:BusinessError) => {
                 console.error("async: error is " + e);
               });
             }
             console.info("asyncRunner task finished");
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```


