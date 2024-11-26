# Communication Between the TaskPool Task and Host Thread

If a subthread needs to periodically notify the main thread of the task status and data changes, or needs to return a large amount of data by segment (for example, a large amount of data read from the database), you can perform the following operations:

The following uses an example in which results of a plurality of image loading tasks are returned in real time.

1. First, implement a method to receive messages sent by the task.

   ```ts
   // TaskSendDataUsage.ets
   function notice(data: number): void {
     console.info("The subthread task has been executed. Total images loaded:", data)
   }
   ```

2. Then, add **sendData()** to the task to enable the subthread to send messages to the main thread.

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
   // TaskSendDataUsage.ets
   import { taskpool } from '@kit.ArkTS';
   import { IconItemSource } from './IconItemSource';
   
   // Use sendData to notify the main thread of information in real time.
   @Concurrent
   export function loadPictureSendData(count: number): IconItemSource[] {
     let iconItemSourceList: IconItemSource[] = [];
     // Traverse and add six IconItem data records.
     for (let index = 0; index < count; index++) {
       const numStart: number = index * 6;
       // Six images are used cyclically.
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

3. Finally, use **onReceiveData()** to enable the main thread to receive messages.
   In this way, the main thread can receive the data sent by the task through **notice()**.

   ```ts
   // TaskSendDataUsage.ets
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
             .onClick(() => {
               let iconItemSourceList: IconItemSource[];
               let lodePictureTask: taskpool.Task = new taskpool.Task(loadPictureSendData, 30);
               // Use notice to receive messages sent by the task.
               lodePictureTask.onReceiveData(notice);
               taskpool.execute(lodePictureTask).then((res: object) => {
                 iconItemSourceList = res as IconItemSource[];
               })
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
