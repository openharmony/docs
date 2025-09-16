# Communication Between the TaskPool Task and Host Thread
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

When a task needs to do more than just return a final result—such as periodically updating the host thread on its status, reporting data changes, or returning large volumes of data in segments (for example, fetching large datasets from a database)—you can use the approach described in this topic.

The following example uses multiple image loading tasks that provide real-time updates to illustrate the process.

1. Implement a method to receive messages sent by the task.

   ```ts
   // TaskSendDataUsage.ets
   export function notice(data: number): void {
     console.info("Child thread task completed. Total images loaded:", data)
   }
   ```
   <!-- @[receive_task_message](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/TaskSendDataUsage.ets) -->

2. Add **sendData()** to the task to enable the child thread to send messages to the host thread.

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
   <!-- @[implement_child_thread_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/IconItemSource.ets) -->

   ```ts
   // TaskSendDataUsage.ets
   import { taskpool } from '@kit.ArkTS';
   import { IconItemSource } from './IconItemSource';
   
   // Use sendData to notify the host thread of information in real time.
   @Concurrent
   export function loadPictureSendData(count: number): IconItemSource[] {
     let iconItemSourceList: IconItemSource[] = [];
     // Add six IconItem data records.
     for (let index = 0; index < count; index++) {
       const numStart: number = index * 6;
       // Use six images in the loop.
       iconItemSourceList.push(new IconItemSource('$media:startIcon', `item${numStart + 1}`));
       iconItemSourceList.push(new IconItemSource('$media:background', `item${numStart + 2}`));
       iconItemSourceList.push(new IconItemSource('$media:foreground', `item${numStart + 3}`));
       iconItemSourceList.push(new IconItemSource('$media:startIcon', `item${numStart + 4}`));
       iconItemSourceList.push(new IconItemSource('$media:background', `item${numStart + 5}`));
       iconItemSourceList.push(new IconItemSource('$media:foreground', `item${numStart + 6}`));
   
       taskpool.Task.sendData(iconItemSourceList.length);
     }
     return iconItemSourceList;
   }
   ```
   <!-- @[implement_child_thread_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/TaskSendDataUsage.ets) -->

3. In the host thread, use **onReceiveData()** to receive messages.
   This allows the host thread to receive data sent by the task through **notice()**.

   ```ts
   // Index.ets
   import { taskpool } from '@kit.ArkTS';
   import { IconItemSource } from './IconItemSource';
   import { loadPictureSendData, notice } from './TaskSendDataUsage';
   
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
             .onClick(async () => {
               let iconItemSourceList: IconItemSource[] = [];
               let loadPictureTask: taskpool.Task = new taskpool.Task(loadPictureSendData, 30);
               // Use notice to receive messages from the task.
               loadPictureTask.onReceiveData(notice);
               iconItemSourceList = await taskpool.execute(loadPictureTask) as IconItemSource[];
               console.info("The length of iconItemSourceList is " + iconItemSourceList.length);
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
   <!-- @[receive_task_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationScenario/entry/src/main/ets/managers/TaskSendDataUsage.ets) -->
