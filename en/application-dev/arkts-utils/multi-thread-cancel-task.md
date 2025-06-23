# Canceling Tasks in Multithreading with TaskPool

[Task](../reference/apis-arkts/js-apis-taskpool.md#task) objects of the [TaskPool](../reference/apis-arkts/js-apis-taskpool.md) cannot be passed across threads. Therefore, tasks cannot be canceled from child threads. Starting from API version 18, tasks have been enhanced with the [task ID](../reference/apis-arkts/js-apis-taskpool.md#properties), allowing tasks to be canceled in child threads using this ID. The following example describes how to cancel a task that has been submitted to the TaskPool in a multithreaded environment. You can store the task ID of a created task in a [Sendable object](./arkts-sendable.md) and use this object to cancel the task from a child thread.

1. Define a Sendable class and store the task ID in the class properties.

   ```ts
   // Mock.ets

   @Sendable
   export class SendableTest {
    // Store the task ID.
     private taskId: number = 0;

     constructor(id: number) {
       this.taskId = id;
     }

     public getTaskId(): number {
       return this.taskId;
     }
   }
   ```

2. Submit a delayed task to the TaskPool from the UI main thread and cancel it from a child thread.

   ```ts
   // Index.ets

   import { taskpool } from '@kit.ArkTS';
   import { SendableTest } from './Mock'

   @Concurrent
   function cancel(send: SendableTest) {
     console.info("cancel task finished");
     // Cancel the task in the child thread based on the task ID.
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
             taskpool.executeDelayed(2000, task).catch((e: BusinessError) => {
               console.error(`taskpool execute error, message is: ${e.message}`); // taskpool execute error, message is: taskpool:: task has been canceled
             });
             let send = new SendableTest(task.taskId);
             taskpool.execute(cancel, send);
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```
