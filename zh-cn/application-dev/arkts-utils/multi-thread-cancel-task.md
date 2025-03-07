# 多线程取消TaskPool任务场景

因为任务池[TaskPool](../reference/apis-arkts/js-apis-taskpool.md)的任务对象[Task](../reference/apis-arkts/js-apis-taskpool.md#task)不支持传递到子线程，因此在API version 18之前无法在子线程中取消任务。在API version 18及以后，Task新增了[任务ID](../reference/apis-arkts/js-apis-taskpool.md#属性)属性，支持通过任务ID在子线程中取消任务。以下示例提供多线程取消已提交给TaskPool中的任务的开发指导，用户可将已创建任务的任务ID存储在[Sendable对象](./arkts-sendable.md)中，在需要取消任务时，通过Sendable对象来多线程取消任务。

1. 定义一个Sendable类，在类属性中存储任务ID。

   ```ts
   // Mock.ets

   @Sendable
   export class SendableTest {
    // 储存任务ID
     private taskId: number = 0;

     constructor(id: number) {
       this.taskId = id;
     }

     public getTaskId(): number {
       return this.taskId;
     }
   }
   ```

2. 在UI主线程向TaskPool提交一个延时任务，并在子线程取消该延时任务。

   ```ts
   // Index.ets

   import { taskpool } from '@kit.ArkTS';
   import { SendableTest } from './Mock'

   @Concurrent
   function cancel(send: SendableTest) {
     console.info("cancel task finished");
     // 通过任务ID多线程取消任务
     taskpool.cancel(send.getTaskId());
   }

   @Concurrent
   function delayed() {
     console.info("delayed task finished");
   }

   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World!';
     @State books: string[] = [];

     build() {
       Column({ space: 1 }) {
         Button(this.books[3])
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .onClick(async () => {
             let task = new taskpool.Task(delayed);
             taskpool.executeDelayed(2000, task);
             let send = new SendableTest(task.taskId);
             taskpool.execute(cancel, send);
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```