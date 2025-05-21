# Worker常驻线程通过TaskPool进行多任务并发处理

ArkTS应用开发过程中，可以选择TaskPool或Worker线程进行多任务并发处理，也可以两种线程都选择。

本示例将说明在Worker线程中通过TaskPool线程执行并发任务。

1. 在主线程中创建Worker线程并发送消息。

   ```ts
   // Index.ets
   import { worker } from '@kit.ArkTS';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
   
     build() {
       RelativeContainer() {
         Text(this.message)
           .id('HelloWorld')
           .fontSize($r('app.float.page_text_font_size'))
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: '__container__', align: VerticalAlign.Center },
             middle: { anchor: '__container__', align: HorizontalAlign.Center }
           })
           .onClick(() => {
             // 1. 创建Worker实例
             const myWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets');
   
             // 2. 接收Worker返回的结果
             myWorker.onmessage = (e) => {
               console.log('主线程收到最终结果:', e.data.result);
               myWorker.terminate(); // 销毁Worker
             };
   
             // 3. 向Worker发送启动指令
             myWorker.postMessage({ type: 'start', data: 10 });
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

2. 在Worker线程中创建TaskPool线程，并在TaskPool线程中执行并发任务。

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   import { taskpool } from '@kit.ArkTS';
   
   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
   workerPort.onmessage = async (e: MessageEvents) => {
     if (e.data.type === 'start') {
       // 模拟Worker数据处理
       const processedData = heavyComputation(e.data.data);
   
       // 调用TaskPool执行并发任务
       const task = new taskpool.Task(parallelTask, processedData);
       const result = await taskpool.execute(task);
       console.log('Worker线程返回结果: ', result);
   
       // 将最终结果返回主线程
       workerPort.postMessage({
         status: 'success',
         result: result
       });
     }
   }
   
   function heavyComputation(base: number): number {
     let sum = 0;
     for (let i = 0; i < base * 10; i++) {
       sum += Math.sqrt(i);
     }
     return sum;
   }
   
   @Concurrent
   function parallelTask(base: number): number {
     let total = 0;
     for (let i = 0; i < base; i++) {
       total += i % 2 === 0 ? i : -i;
     }
     console.log('TaskPool线程计算结果: ', total);
     return total;
   }
   ```