# Using TaskPool for Independent Time-Consuming Tasks

For a time-consuming task that runs independently, you only need to return the result to the host thread after the task is executed. There is no context dependency. You can implement the task in the following way:

The following uses image loading as an example.

1. Implement the task to be executed by the sub-thread.

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
   // IndependentTask.ets
   import { IconItemSource } from './IconItemSource';
    
   @Concurrent // Methods executed in the task must be decorated by @Concurrent. Otherwise, they cannot be called.
   @Concurrent
   export function loadPicture(count: number): IconItemSource[] {
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
     }
     return iconItemSourceList;
   }
   ```

2. The execute method in TaskPool is used to execute the preceding task, that is, load images.

   ```ts
   // Index.ets
   import { taskpool } from '@kit.ArkTS';
   import { IconItemSource } from './IconItemSource';
   import { loadPicture } from './IndependentTask';
   
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
               let iconItemSourceList: IconItemSource[] = [];
               // Create a task.
               let lodePictureTask: taskpool.Task = new taskpool.Task(loadPicture, 30);
               // Execute the task and return the result.
               taskpool.execute(lodePictureTask).then((res: object) => {
                 // Execution result of the loadPicture API.
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
