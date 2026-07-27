# 多线程取消TaskPool任务场景
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @huanghello-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

由于任务池[TaskPool](../reference/apis-arkts/js-apis-taskpool.md)的任务对象[Task](../reference/apis-arkts/js-apis-taskpool.md#task)不支持跨线程传递，无法在子线程中直接取消任务。从 API version 18 开始，Task新增了任务ID[属性](../reference/apis-arkts/js-apis-taskpool.md#属性)，支持通过任务ID在子线程中取消任务。开发者可将已创建任务的任务ID存储在[Sendable对象](./arkts-sendable.md)中，需要取消任务时，通过Sendable对象在子线程中取消任务。详情可参考以下示例。

1. 定义一个Sendable类，在类属性中存储任务ID。

   <!-- @[define_sendable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCasesSecond/entry/src/main/ets/utils/Sendable.ets) --> 
   
   ``` TypeScript
   // sendable.ets
   @Sendable
   export class SendableTest {
     // 存储任务ID
     private taskId: number = 0;
   
     constructor(id: number) {
       this.taskId = id;
     }
   
     public getTaskId(): number {
       return this.taskId;
     }
   }
   ```

2. 在UI主线程向TaskPool提交一个延时任务，并在子线程取消该任务。

   <!-- @[taskpool_cancel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCasesSecond/entry/src/main/ets/pages/TaskpoolCancel.ets) -->
   
   ``` TypeScript
   // TaskpoolCancel.ets
   import { taskpool } from '@kit.ArkTS';
   import { SendableTest } from '../utils/Sendable';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { PromptAction } from '@kit.ArkUI';
   
   @Concurrent
   function cancel(send: SendableTest) {
     // 在多线程中通过任务ID取消任务
     taskpool.cancel(send.getTaskId());
     console.info('cancel task finished');
   }
   
   @Concurrent
   function delayed() {
     console.info('delayed task finished');
   }
   
   @Entry
   @Component
   struct TaskpoolCancel {
     @State message: string = 'CancelTaskpool';
     @State returnMessage: string = 'return...';
     @State promptAction: PromptAction = this.getUIContext().getPromptAction();
   
     build() {
       Row() {
         Column() {
           Button(this.message)
             .fontSize(25)
             .fontWeight(FontWeight.Bold)
             .onClick(async () => {
               let task = new taskpool.Task(delayed);
               taskpool.executeDelayed(2000, task).catch((e: BusinessError) => {
                 console.error(`taskpool execute error, message is: ${e.message}`);
                 // taskpool execute error, message is: taskpool:: task has been canceled.
               });
               let send = new SendableTest(task.taskId);
               taskpool.execute(cancel, send).then(() => {
                 this.returnMessage = 'Taskpool canceled!';
                 this.promptAction.showToast({ message: this.returnMessage });
               });
             })
           // ...
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
