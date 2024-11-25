# Using TaskPool for Multiple Time-Consuming Tasks

If multiple tasks are executed simultaneously, their execution time and result return time vary according to the task complexity. If the main thread requires the execution results of all tasks, you can use the following code snippet:

In addition, if a task needs to process a large amount of data (for example, a list contains 10,000 data records), it is time-consuming to process all the data in one task. In this case, you can split the data into multiple sublists, allocate one task for each sublist, and combine the results of all the tasks. This pattern reduces the processing time and improves user experience.

The following uses image loading of a plurality of tasks as an example for description.

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

2. In this scenario, all the tasks to be executed are placed in a task group. After all the tasks in the task group are executed, the execution result of each task is placed in an array and returned to the main thread. The main thread can obtain all task execution results at a time.

   ```ts
   // MultiTask.ets
   import { taskpool } from '@kit.ArkTS';
   import { IconItemSource } from './IconItemSource';
   import { loadPicture } from './IndependentTask';
    
   let iconItemSourceList: IconItemSource[][];
    
   let taskGroup: taskpool.TaskGroup = new taskpool.TaskGroup();
   taskGroup.addTask(new taskpool.Task(loadPicture, 30));
   taskGroup.addTask(new taskpool.Task(loadPicture, 20));
   taskGroup.addTask(new taskpool.Task(loadPicture, 10));
   taskpool.execute(taskGroup).then((ret: object) => {
     let tmpLength = (ret as IconItemSource[][]).length
     for (let i = 0; i < tmpLength; i++) {
       for (let j = 0; j < ret[i].length; j++) {
         iconItemSourceList.push(ret[i][j]);
       }
     }
   })
   ```
